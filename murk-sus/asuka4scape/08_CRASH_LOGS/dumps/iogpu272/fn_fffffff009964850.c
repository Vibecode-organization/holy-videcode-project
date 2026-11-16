// FUN_fffffff009964850 @ fffffff009964850 size=124

undefined8 FUN_fffffff009964850(long param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = (*DAT_fffffff007feb260)();
  if (iVar1 != 0) {
    *(int *)(param_1 + 0x10) = (int)param_2;
    iVar1 = thunk_EXT_FUN_80110000034136ec(param_2,param_1 + 0x18);
    if (iVar1 == 0) {
      uVar2 = thunk_EXT_FUN_80110000038905f0(1,&DAT_fffffff00af220c0);
      *(undefined8 *)(param_1 + 0x20) = uVar2;
      return 1;
    }
  }
  return 0;
}

