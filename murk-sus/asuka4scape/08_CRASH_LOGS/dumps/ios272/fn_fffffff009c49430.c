// FUN_fffffff009c49430 @ fffffff009c49430 size=88

bool FUN_fffffff009c49430(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  do {
    iVar2 = iVar1;
    if (iVar2 == 0) goto LAB_fffffff009c49474;
    FUN_fffffff009c46fc8(param_1,iVar2);
    iVar1 = *param_1;
  } while (*param_1 != iVar2);
  *param_1 = iVar2 + 1;
LAB_fffffff009c49474:
  return iVar2 != 0;
}

