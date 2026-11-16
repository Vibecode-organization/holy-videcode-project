# parse_iogpu — subagent K: IOGPUDeviceUserClient sel 52/53

- target: 27.2_24B115_kernelcache (67 239 936 bytes), verified size matches spec
- capstone 5.0.7 available
- mapped: 0x99491a0/0x9949330 -> __TEXT_EXEC off 0x29451a0/0x2945330 (va-BASE == file offset for TEXT_EXEC)
- dispatch table full 0x7fea200 (56 entries, 24 B) / restricted 0x7fea740 (28): sel52 scIn=2 stIn=0xffffffff; sel53 scIn=2 stIn=0xffffffff
- sel52 = s_group_add_resources, sel53 = s_group_remove_resources (__func__ strings 0x782b0bb3 / 0x782b0c2e)
- read [args+0x20] = scalarInput (sel28 scIn=0 also derefs it, no null check) -> w23=scalar0, w21=scalar1
- [args+0x30]=structureInput, [args+0x38]=size, [args+0x40]=structureInputDescriptor, [args+0x48]=scalarOutput
- sel52: 0x9949268 cmp size, count<<2 / b.lo -> kIOReturnBadArgument; sel53: 0x99493f8 cmp size, count<<3
- callee 0x9967e24 -> worker 0x9967bc0 reads u32 per element (ldr w1,[x23,x24,lsl #2]); lookup 0x9945214 checks id!=0 && id<[arr+0x28]
- sel53 callee 0x9967f2c -> 0x9569fc hashed lookup of u64 ids (ldr x9,[x26,x25,lsl #3]) -> matches 8*count check
- restricted table 0x7fea740 is 56 entries (0x540): stubs 0x9945520 at 21,27..34,36..54; live 0..20,22..26,35,55 -> 52/53 stubbed for entitled clients
- gate: [uc+0x103] = entitled("com.apple.private.graphics-restart-no-kill") ? 1 : entitled("com.apple.developer.gpu-restricted") (0x99658e8 -> 0x9964e38, AMFI obj 0x9965780)
- sel52 add: group lookup 0x9945040->0x9944fb8 (ref++ at +0xc), count<=0x80000, worker 0x9967bc0 reads u32 ids, bulk 0x9956c5c (retain vt+0x20/release vt+0x28 only)
- sel53 remove: 0x9967f2c -> 0x9569fc hash by u64 key, bucket mask, key compare; size check 8*count matches
- diff 52 vs 53: 8 words of 0x18c (lsl #2/#3, bl target, __func__/log strings, 2 pc-rel bls)
- VERDICT: no vuln (no OOB read/write, no leak, no DoS); report written
