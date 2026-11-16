// FUN_fffffff009947de8 @ fffffff009947de8 size=652

undefined8 FUN_fffffff009947de8(long param_1,undefined8 param_2,long param_3)

{
  ulong uVar1;
  ulong uVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  long *plVar5;
  undefined8 uVar6;
  ulong uVar7;
  long *plVar8;
  code *pcVar9;
  undefined4 *puVar10;
  undefined8 uVar11;
  uint local_54;
  
  uVar11 = 0xe00002c2;
  plVar5 = *(long **)(param_3 + 0x40);
  if (plVar5 == (long *)0x0) {
    if (*(int *)(param_3 + 0x28) != 4) {
      return 0xe00002c2;
    }
    plVar5 = (long *)0x0;
    uVar7 = (ulong)*(uint *)(param_3 + 0x38);
    uVar6 = *(undefined8 *)(param_3 + 0x30);
  }
  else {
    plVar5 = (long *)(**(code **)(*plVar5 + 0xe8))(plVar5,0x1000);
    if (plVar5 == (long *)0x0) {
      return 0xe00002c8;
    }
    uVar6 = (**(code **)(*plVar5 + 0x78))();
    uVar7 = (**(code **)(**(long **)(param_3 + 0x40) + 0xb0))();
    if (*(int *)(param_3 + 0x28) != 4) {
      pcVar9 = *(code **)(*plVar5 + 0x28);
      goto LAB_fffffff009947fdc;
    }
  }
  puVar10 = *(undefined4 **)(param_3 + 0x20);
  uVar1 = *(ulong *)(puVar10 + 4);
  uVar2 = *(ulong *)(puVar10 + 6);
  auVar3._8_8_ = 0;
  auVar3._0_8_ = uVar2;
  auVar4._8_8_ = 0;
  auVar4._0_8_ = uVar1;
  if (SUB168(auVar3 * auVar4,8) == 0) {
    if (uVar7 == uVar2 * uVar1) {
      plVar8 = (long *)FUN_fffffff009965da8(*(undefined8 *)(param_1 + 0x120),*puVar10);
      if (plVar8 != (long *)0x0) {
        if (uVar2 != *(uint *)(plVar8[0xa6] + 0x268)) {
          thunk_EXT_FUN_80110000038db19c
                    (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                     "%s: cmdBufArgSize does not match config (%llu != %u)\n");
          if (plVar5 != (long *)0x0) {
            (**(code **)(*plVar5 + 0x28))(plVar5);
          }
          pcVar9 = *(code **)(*plVar8 + 0x28);
          plVar5 = plVar8;
          goto LAB_fffffff009947fdc;
        }
        local_54 = 0;
        uVar11 = FUN_fffffff009976cf8(plVar8,uVar6,uVar1,uVar2,&local_54);
        **(ulong **)(param_3 + 0x48) = (ulong)local_54;
        (**(code **)(*plVar8 + 0x28))(plVar8);
      }
    }
    else {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s: bad structureInputSize (%lld != %llu)\n");
    }
  }
  else {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: total size overflow (%llu * %llu)\n")
    ;
  }
  if (plVar5 == (long *)0x0) {
    return uVar11;
  }
  pcVar9 = *(code **)(*plVar5 + 0x28);
LAB_fffffff009947fdc:
  (*pcVar9)(plVar5);
  return uVar11;
}

