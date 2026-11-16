// FUN_fffffff00819a468 @ fffffff00819a468 size=88

void FUN_fffffff00819a468(undefined8 param_1,long param_2)

{
  long lVar1;
  
  (**(code **)(PTR_DAT_fffffff007ca6130 + 0x90))();
  if ((param_2 != 0) &&
     (lVar1 = thunk_EXT_FUN_8011000003890f30(param_2,&DAT_fffffff00ae22130), lVar1 != 0)) {
    *(undefined4 *)(param_2 + 0x68) = 0;
  }
  return;
}

