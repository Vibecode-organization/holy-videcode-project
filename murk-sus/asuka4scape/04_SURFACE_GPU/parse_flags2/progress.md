# progress — flags +0x122

## setup
- workdir /home/femboychik/work/parse_flags2 created
- kernelcache: /home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache
- target setters: 0xfffffff008fd1088 ([x0+0x122]), 0xfffffff008fd1700 ([x0+0x127])
- PAC: (q>>32)==0x8050bcad, VA=0xfffffff007004000+(q&0x0FFFFFFF)

## step1 (done) — pointer scan
- scanned __DATA_CONST/__DATA/__PRELINK_INFO/__DATA_SPTM for PAC ptrs to 0x8fd1088 / 0x8fd1700: **0 hits**
- reason: 0x8fd1088 is NOT a standalone function reached by pointer.
  It is a *case body* of a jump table (32-bit relative offsets) inside function 0x8fd0ee4
  (`bti c; sub w16,w1,#6; cmp w16,#0xf9; b.hi 0x8fd192c; adrp 0x8fd1000; add #0x964;
   ldrsw x16,[x17,x16,lsl#2]; adr x17,#0x8fd0f08; add x16,x17,x16; br x16`)
- userland-shaped setter: x0=object, w1=selector (6..0xfe), w2=value; body = cmp w2,#0; cset ne; strb [x0,#0x122]
- same dispatcher also has [x0,#0x127] at 0x8fd1700, [x0,#0x130], [x0,#0x133], [x0,#0x117] etc.
- that dispatcher is called from exactly ONE site: 0x8fcfae4, inside func 0x8fcf904(this, OSDictionary*)
  which walks a 210-entry table @ __DATA_CONST 0x7e9cd98 = {u32 selector, u32 pad, char* key}
  and applies dict keys -> selectors. keys are power/thermal names
  ("FullOperationModePowerFraction", "UseOverrideSystemCapability", "OverrideBatteryInputMeasuredPu" ...)
  => that whole region 0x8fcf.. is a POWER/SMC kext, NOT IOSurface. Dead end for +0x122 on the user client.

## ground truth (field scan __TEXT_EXEC, imm12 byte accesses)
accesses to +0x122: 78 sites; the only ones in the IOSurface client cluster (0x9c39..0x9c3a) are:
  0x9c396ac  ldrb w8,[x0,#0x122]
  0x9c3a350  strb w0,[x19,#0x122]   <-- store of a call result byte
  0x9c3a398  ldrb w8,[x19,#0x122]
accesses to +0x127:
  0x9c3a380  strb w0,[x19,#0x127]   <-- store of a call result byte
  0x9c3ee1c  ldrb w9,[x0,#0x127]    (externalMethod table select)
  0x9c3ee50  ldrb w8,[x0,#0x127]
=> the real writers are 0x9c3a350 / 0x9c3a380, next to gate 0x9c3a60c. step 4 is the answer.

## step4 (partial) — writers found, strings decoded
init routine @ 0x9c3a2d8 (pacibsp; x0=self, x1=?, x2=task(x20), x3=?)
  ...
  0x9c3a340 adrp x2,0x789c000 ; add #0xe3e   -> "com.apple.private.iosurfaceinfo"
  0x9c3a34c bl  0x9c3a60c
  0x9c3a350 strb w0,[x19,#0x122]        <-- +0x122 = entitlement(iosurfaceinfo)
  0x9c3a354 add x2,#0xe5e                 -> "com.apple.private.gpu-restricted"
  0x9c3a360 bl  0x9c3a60c
  0x9c3a364 tbz w0,#0 -> 0x9c3a370 ; else mov w0,#1 ; b 0x9c3a380
  0x9c3a370 add x2,#0xe7f                 -> "com.apple.developer.gpu-restricted"
  0x9c3a37c bl  0x9c3a60c
  0x9c3a380 strb w0,[x19,#0x127]        <-- +0x127 = gpu-restricted(private|developer)
  0x9c3a384 add x2,#0xea2                 -> "com.apple.private.IOSurface.protected-access"
  0x9c3a390 bl  0x9c3a60c
  0x9c3a394 strb wzr,[x19,#0x123]
  0x9c3a398 ldrb w8,[x19,#0x122]
  0x9c3a39c orr w8,w8,w0
  0x9c3a3a0 and w8,w8,#1
  0x9c3a3a4 strb w8,[x19,#0x126]        <-- +0x126 = +0x122 | protected-access

## gate 0x9c3a60c — disassembly (verified)
0x9c3a60c bti c; pacibsp
0x9c3a620 mov x0,x1        (task)
0x9c3a624 mov x1,x2        (key string)
0x9c3a628 bl  0x9c49804    (copyClientEntitlement(task,key) -> OSObject*)
0x9c3a62c mov x19,x0
0x9c3a630 ldr x8,[0x806ca60]; ldr x8,[x8]; ldr x20,[x8]   (x20 = kOSBooleanTrue)
0x9c3a640 cbz x0, .skip
0x9c3a644..0x9c3a660 vtable+0x28 = release(x19)
0x9c3a664 cmp x20,x19
0x9c3a668 cset w0, eq      <-- returns 1 ONLY if entitlement object IS kOSBooleanTrue
0x9c3a674 retab
=> entitlement must be boolean true; a string value ("1") does NOT satisfy it.

## caller of the gate = init 0x9c3a2d8 (pacibsp; x19=self, x21=x1, x20=x2=task, x3)
0x9c3a300..0x9c3a310 virtual call on global@0x806ca28+0xb8 (x1=x3), w0==0 -> fail 0x9c3a5fc
0x9c3a318 bl 0x9c49df4 (task retain-ish, x0=x20)
0x9c3a324..0x9c3a33c pacda task into [x19,#0xf8]
0x9c3a34c bl gate("com.apple.private.iosurfaceinfo")  -> strb w0,[x19,#0x122] @0x9c3a350
0x9c3a5fc..0x9c3a608 epilogue retab (fail path returns 0 without touching +0x122)

## cross-check: +0x122 reads in client cluster
0x9c396ac (func 0x9c39690): ldrb w8,[x0,#0x122]; tbz w8,#0 -> 0x9c3971c  (one of two behaviours)

## CORRECTION — real data-pointer encoding in this cache
- not all data pointers use 0x8050bcad. bulk form: **hi16 = 0x8011**, low 40 bits = VA-0x7004000
  e.g. 0x801100000 31fefec -> 0xfffffff00a204  3ec  (sanity: 0x7004000+0x31fefec = 0xa2043ec, inside __TEXT_EXEC)
- 426186 qwords in __DATA_CONST decode into __TEXT_EXEC under (BASE + low28); 20969 under hi16==0x8011
- step1 result stands for the 0x8fd1088 setter (it is a switch case, not a function), but vtable searches
  must use hi16==0x8011.

## externalMethod tables decoded (__DATA_CONST)
table A @0x8068b90 (60x0x28) entry = {u64 action_pac, u32 inScalar, u32 inStructSize, u32 outScalar, u32 outStructSize}
table B @0x80694f0 (60x0x28)
- sel 30: table A -> action 0x9c3968c (bti c; body starts 0x9c39690 = reads [+0x122])
          table B -> action 0x9c3a1dc (stub)
- table B replaces 20 selectors with stub 0x9c3a1dc: 4,5,6,7,8,16,17,18,19,21,22,24,25,26,28,29,30,33,43,46,47,48,49 (+59 n/a)
  i.e. gpu-restricted clients lose those 20 methods, incl. 30.

## identity proof for init 0x9c3a2d8
string refs inside 0x9c3a2d8..0x9c3a608:
  0x9c3a4f8 'provider not IOSurfaceRoot\n'
  0x9c3a520 'Cannot allocate IOSurfaceShared\n'
  0x9c3a548 'Cannot map graphics comm page\n'
  0x9c3a570 'Cannot allocate notification array\n'
  0x9c3a598 'Cannot allocate invalidated surface array\n'
  0x9c3a5c0 'Cannot allocate IOLock\n'
  0x9c3a5e8 'Cannot allocate IORWLock\n'
=> 0x9c3a2d8 == IOSurfaceRootUserClient::initWithTask(inOwningTask, inSecurityToken, inType, inProperties)

## gate callers (whole __TEXT_EXEC): only 4, all inside init
0x9c3a34c, 0x9c3a360, 0x9c3a37c, 0x9c3a390

## selector 30 body 0x9c39690
0x9c396a4/0x9c396a8 w19 = 0xE00002BD (kIOReturnNoMemory)
0x9c396ac ldrb w8,[x0,#0x122] ; 0x9c396b0 tbz w8,#0 -> 0x9c3971c
0x9c3971c add w19,w19,#4  => 0xE00002C1 (kIOReturnNotPrivileged) -> ret 0x9c39734
  (path taken when +0x122==0)
else: needs args->structureOutput ([x2+0x78]) != 0 (else 0xE00002C2 kIOReturnBadArgument),
  allocates 0x100000 bytes, calls 0x9c40430(this, [args+0x20]->[0], buf) = copy 1MB out,
  on success stores buf into *(args->structureOutput)

## DONE
- REPORT.md written
- final answer: +0x122 == 1 iff copyClientEntitlement(task,"com.apple.private.iosurfaceinfo")==gOSBooleanTrue
  writer 0x9c3a350 (only one in whole cache for this object), gate 0x9c3a60c, init 0x9c3a2d8
- selector 30 present only in table A (0x8069040 -> 0x9c3968c -> body 0x9c39690),
  table B (gpu-restricted) -> stub 0x9c3a1dc = 0xE00002E2
- open: no symtab (LINKEDIT bplist truncated); vtable refs to 0x9c3a2d8/0x9c3ee14 not found in any of 3 encodings
