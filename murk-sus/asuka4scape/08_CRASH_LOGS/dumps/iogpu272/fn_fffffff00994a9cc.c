// FUN_fffffff00994a9cc @ fffffff00994a9cc size=124

bool FUN_fffffff00994a9cc(long param_1,undefined8 param_2,undefined8 param_3,int param_4)

{
  bool bVar1;
  long lVar2;
  
  (**(code **)(PTR_DAT_fffffff007ff27f8 + 0x78))();
  if (param_4 < 0x81) {
    *(undefined8 *)(param_1 + 0x10) = param_2;
    *(int *)(param_1 + 0x28) = param_4;
    *(undefined1 *)(param_1 + 0x38) = 1;
    lVar2 = thunk_EXT_FUN_80110000038ff134();
    *(long *)(param_1 + 0x840) = lVar2;
    bVar1 = lVar2 != 0;
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}

