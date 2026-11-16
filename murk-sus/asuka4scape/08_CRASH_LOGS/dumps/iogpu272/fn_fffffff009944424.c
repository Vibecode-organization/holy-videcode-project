// FUN_fffffff009944424 @ fffffff009944424 size=336

undefined8 FUN_fffffff009944424(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  uint uVar3;
  long lVar4;
  undefined8 uVar5;
  ulong uVar6;
  
  uVar3 = *(uint *)(param_1 + 0x28);
  if (uVar3 == 0) {
    uVar6 = 0x400;
  }
  else {
    if (uVar3 >> 0x16 != 0) {
      return 0;
    }
    uVar6 = (ulong)(uVar3 << 1);
  }
  lVar1 = *(long *)(param_1 + 0x10);
  uVar2 = *(undefined8 *)(param_1 + 0x18);
  lVar4 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ff1138,uVar6 << 3);
  *(long *)(param_1 + 0x10) = lVar4;
  if (lVar4 == 0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"IONewZero failed to alloc Handles\n");
    uVar5 = 0;
    *(long *)(param_1 + 0x10) = lVar1;
  }
  else {
    lVar4 = thunk_EXT_FUN_80110000038fe5cc(uVar6 >> 3);
    *(long *)(param_1 + 0x18) = lVar4;
    if (lVar4 == 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "IOMallocZeroData failed to alloc Handles Map\n");
      uVar5 = *(undefined8 *)(param_1 + 0x10);
      *(undefined8 *)(param_1 + 0x10) = 0;
      thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ff1188,uVar5,uVar6 << 3);
      uVar5 = 0;
      *(long *)(param_1 + 0x10) = lVar1;
      *(undefined8 *)(param_1 + 0x18) = uVar2;
    }
    else {
      *(int *)(param_1 + 0x28) = (int)uVar6;
      if (lVar1 != 0) {
        thunk_EXT_FUN_8011000003a61b10(*(undefined8 *)(param_1 + 0x10),lVar1,(ulong)uVar3 << 3);
        thunk_EXT_FUN_8011000003a61b10(*(undefined8 *)(param_1 + 0x18),uVar2,uVar3 >> 3);
        thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ff11d8,lVar1,(ulong)uVar3 << 3);
        thunk_EXT_FUN_80110000038fe6b0(uVar2,uVar3 >> 3);
      }
      uVar5 = 1;
    }
  }
  return uVar5;
}

