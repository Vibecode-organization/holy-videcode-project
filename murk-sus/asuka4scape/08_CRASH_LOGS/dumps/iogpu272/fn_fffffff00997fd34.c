// FUN_fffffff00997fd34 @ fffffff00997fd34 size=156

undefined8 FUN_fffffff00997fd34(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  long lVar2;
  long lVar3;
  
  uVar1 = (*DAT_fffffff007feb260)();
  if ((int)uVar1 != 0) {
    *(undefined8 *)(param_1 + 0x10) = param_2;
    *(undefined8 *)(param_1 + 0x38) = param_3;
    uVar1 = thunk_EXT_FUN_80110000038905f0(1,&DAT_fffffff00af220c0);
    *(undefined8 *)(param_1 + 0x288) = uVar1;
    lVar2 = thunk_EXT_FUN_80110000038ff010();
    *(long *)(param_1 + 0x18) = lVar2;
    uVar1 = 0;
    if (lVar2 != 0) {
      lVar2 = 0;
      lVar3 = 8;
      do {
        FUN_fffffff00994af14(param_1 + 0x88 + lVar2 * 0x40);
        lVar2 = lVar2 + 1;
        lVar3 = lVar3 + -1;
      } while (lVar3 != 0);
      uVar1 = 1;
    }
  }
  return uVar1;
}

