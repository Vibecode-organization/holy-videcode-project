// FUN_fffffff00994a758 @ fffffff00994a758 size=108

ulong FUN_fffffff00994a758(long param_1,undefined8 param_2)

{
  ulong uVar1;
  undefined8 uVar2;
  long lVar3;
  
  uVar1 = (*DAT_fffffff007feb260)();
  if ((int)uVar1 != 0) {
    *(undefined8 *)(param_1 + 0x18) = param_2;
    uVar2 = thunk_EXT_FUN_80110000038905f0(1,&DAT_fffffff00af220c0);
    *(undefined8 *)(param_1 + 0x20) = uVar2;
    lVar3 = thunk_EXT_FUN_80110000038ff010();
    *(long *)(param_1 + 0x10) = lVar3;
    uVar1 = (ulong)(lVar3 != 0);
  }
  return uVar1;
}

