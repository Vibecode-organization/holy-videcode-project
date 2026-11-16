// FUN_fffffff0099476c0 @ fffffff0099476c0 size=768

undefined8 FUN_fffffff0099476c0(long param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  int iVar2;
  long *plVar3;
  ulong uVar4;
  ulong uVar5;
  undefined8 uVar6;
  ulong *puVar7;
  
  uVar6 = *(undefined8 *)(param_3 + 0x30);
  puVar7 = *(ulong **)(param_3 + 0x58);
  uVar1 = *(uint *)(*(long *)(*(long *)(param_1 + 0x120) + 0x88) + 0x30);
  plVar3 = *(long **)(param_1 + 0xf8);
  if (*(uint *)(plVar3 + 0x49) < uVar1) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
               "%s: The number of queues (%d) exceeding limit (%d), failing IOGPUCommandQueue creation\n"
              );
    plVar3 = *(long **)(param_1 + 0xf8);
    if ((*(byte *)((long)plVar3 + 0x1fc) >> 3 & 1) != 0) {
      return 0xe0078001;
    }
  }
  else if (*(uint *)((long)plVar3 + 0x244) < uVar1) {
    iVar2 = *(int *)(param_1 + 0x11c);
    *(int *)(param_1 + 0x11c) = iVar2 + 1;
    if (((uint)(iVar2 * -0x33333333) >> 1 | iVar2 * -0x80000000) < 0x1999999a) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s: Too many queues (%d) created, possibly leaking?\n");
      plVar3 = *(long **)(param_1 + 0xf8);
    }
  }
  if (*(uint *)(param_3 + 0x38) < 0x408 || *(uint *)(param_3 + 0x38) != *(uint *)(plVar3 + 0x4f)) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
               "%s: Invalid newCommandQueueArgsSize (%u) expected (%u)\n");
    uVar6 = 0xe00002c2;
  }
  else {
    plVar3 = (long *)(**(code **)(*plVar3 + 0x698))();
    if (plVar3 == (long *)0x0) {
      uVar6 = 0xe00002bd;
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: newCommandQueue failed\n");
    }
    else {
      uVar4 = (**(code **)(*plVar3 + 0xd8))
                        (plVar3,*(undefined8 *)(param_1 + 0xf8),*(undefined8 *)(param_1 + 0x120),
                         uVar6);
      if ((uVar4 & 1) == 0) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: init failed\n");
        (**(code **)(*plVar3 + 0x28))(plVar3);
        uVar6 = 0xe00002be;
      }
      else {
        uVar4 = thunk_FUN_fffffff009944798
                          (*(undefined8 *)(*(long *)(param_1 + 0x120) + 0x88),plVar3);
        if ((int)uVar4 == 0) {
          thunk_EXT_FUN_80110000038db19c
                    (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                     "%s: failed to add into name space\n");
          (**(code **)(*plVar3 + 0x28))(plVar3);
          uVar6 = 0xe00002db;
        }
        else {
          FUN_fffffff00997a23c(plVar3,uVar4);
          FUN_fffffff009947080(param_1,1);
          uVar5 = plVar3[0xaa];
          *puVar7 = uVar4 & 0xffffffff;
          puVar7[1] = uVar5;
          (**(code **)(*plVar3 + 0x28))(plVar3);
          uVar6 = 0;
        }
      }
    }
  }
  return uVar6;
}

