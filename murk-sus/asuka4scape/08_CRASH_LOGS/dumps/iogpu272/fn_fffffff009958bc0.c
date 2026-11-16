// FUN_fffffff009958bc0 @ fffffff009958bc0 size=136

int FUN_fffffff009958bc0(long param_1,long *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (*DAT_fffffff007feb260)();
  iVar1 = 0;
  if (param_2 != (long *)0x0) {
    iVar1 = iVar2;
  }
  if (iVar1 == 1) {
    *(long **)(param_1 + 0x10) = param_2;
    (**(code **)(*param_2 + 0x20))(param_2);
    *(undefined4 *)(param_1 + 0x28) = param_3;
  }
  return iVar1;
}

