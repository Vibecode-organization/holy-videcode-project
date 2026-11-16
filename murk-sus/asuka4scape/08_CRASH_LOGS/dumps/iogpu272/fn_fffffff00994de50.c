// FUN_fffffff00994de50 @ fffffff00994de50 size=140

undefined8 FUN_fffffff00994de50(long param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  
  uVar1 = (*DAT_fffffff007feb260)();
  if ((int)uVar1 != 0) {
    *(undefined8 *)(param_1 + 0x10) = param_2;
    uVar2 = thunk_EXT_FUN_80110000038905f0(1,&DAT_fffffff00af220c0);
    lVar3 = 0;
    *(undefined8 *)(param_1 + 0x118) = uVar2;
    lVar4 = 4;
    do {
      FUN_fffffff00994af14(param_1 + 0x18 + lVar3 * 0x40);
      lVar3 = lVar3 + 1;
      lVar4 = lVar4 + -1;
    } while (lVar4 != 0);
  }
  return uVar1;
}

