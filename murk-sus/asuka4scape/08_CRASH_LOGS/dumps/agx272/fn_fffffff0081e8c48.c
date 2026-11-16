// FUN_fffffff0081e8c48 @ fffffff0081e8c48 size=92

undefined8 FUN_fffffff0081e8c48(long param_1,undefined8 param_2)

{
  undefined8 uVar1;
  long lVar2;
  
  uVar1 = (**(code **)(PTR_DAT_fffffff007ca6180 + 0x78))();
  if ((int)uVar1 != 0) {
    lVar2 = thunk_EXT_FUN_80110000038ff010();
    *(long *)(param_1 + 0x18) = lVar2;
    uVar1 = 0;
    if (lVar2 != 0) {
      *(undefined8 *)(param_1 + 0x10) = param_2;
      *(undefined4 *)(param_1 + 0x20) = 0;
      uVar1 = 1;
    }
  }
  return uVar1;
}

