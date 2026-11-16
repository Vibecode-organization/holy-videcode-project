// FUN_fffffff009954bfc @ fffffff009954bfc size=140

undefined8 FUN_fffffff009954bfc(long param_1,undefined8 param_2,long param_3)

{
  undefined8 uVar1;
  uint uVar2;
  
  if (param_3 != 0) {
    *(undefined4 *)(param_1 + 0x80) = *(undefined4 *)(param_3 + 8);
    *(undefined1 *)(param_1 + 0x84) = *(undefined1 *)(param_3 + 0x13);
    uVar2 = *(uint *)(param_3 + 0x14);
    if ((uVar2 >> 0xc & 1) != 0) {
      *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 0x20000;
      uVar1 = thunk_EXT_FUN_80110000038fe074(&DAT_fffffff007ff04a8);
      *(undefined8 *)(param_1 + 0x58) = uVar1;
      FUN_fffffff00994af14();
      FUN_fffffff00994af14(*(long *)(param_1 + 0x58) + 0x40);
      uVar2 = *(uint *)(param_3 + 0x14);
    }
    if ((uVar2 >> 0x16 & 1) != 0) {
      *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 0x800000;
    }
  }
  return 1;
}

