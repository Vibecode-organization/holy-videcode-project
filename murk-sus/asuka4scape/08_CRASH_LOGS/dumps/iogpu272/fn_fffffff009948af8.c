// FUN_fffffff009948af8 @ fffffff009948af8 size=616

undefined8 FUN_fffffff009948af8(long param_1,undefined8 param_2,long param_3)

{
  long *plVar1;
  uint *puVar2;
  ulong uVar3;
  long *plVar4;
  undefined8 uVar5;
  code *pcVar6;
  
  plVar1 = *(long **)(param_3 + 0x40);
  if (plVar1 == (long *)0x0) {
    plVar1 = (long *)0x0;
    puVar2 = *(uint **)(param_3 + 0x30);
    uVar3 = (ulong)*(uint *)(param_3 + 0x38);
  }
  else {
    plVar1 = (long *)(**(code **)(*plVar1 + 0xe8))(plVar1,0x1000);
    if (plVar1 == (long *)0x0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s: input memory descriptor map failed\n");
      return 0xe00002c8;
    }
    puVar2 = (uint *)(**(code **)(*plVar1 + 0x78))();
    uVar3 = (**(code **)(**(long **)(param_3 + 0x40) + 0xb0))();
  }
  if ((uVar3 < 8) || ((uVar3 - 8) % 0x18 != 0)) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
               "%s: Insufficient input struct size (%llu)\n");
  }
  else if ((uVar3 - 8) / 0x18 == (ulong)*puVar2) {
    plVar4 = (long *)FUN_fffffff009967bb4
                               (*(undefined8 *)(param_1 + 0x120),**(undefined4 **)(param_3 + 0x20));
    if (plVar4 != (long *)0x0) {
      uVar5 = FUN_fffffff00995b364(plVar4,puVar2);
      if (plVar1 != (long *)0x0) {
        (**(code **)(*plVar1 + 0x28))(plVar1);
      }
      pcVar6 = *(code **)(*plVar4 + 0x28);
      goto LAB_fffffff009948c10;
    }
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: Invalid IO Queue ID (%u)\n");
  }
  else {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
               "%s: Command buffer count mismatch (%lld - %u)\n");
  }
  if (plVar1 == (long *)0x0) {
    return 0xe00002c2;
  }
  uVar5 = 0xe00002c2;
  pcVar6 = *(code **)(*plVar1 + 0x28);
  plVar4 = plVar1;
LAB_fffffff009948c10:
  (*pcVar6)(plVar4);
  return uVar5;
}

