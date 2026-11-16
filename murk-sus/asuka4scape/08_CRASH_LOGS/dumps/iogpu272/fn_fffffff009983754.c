// FUN_fffffff009983754 @ fffffff009983754 size=84

bool FUN_fffffff009983754(int *param_1)

{
  int iVar1;
  
  do {
    iVar1 = *param_1;
    if (iVar1 == 0) goto LAB_fffffff009983794;
    FUN_fffffff009952258(param_1,iVar1);
  } while (*param_1 != iVar1);
  *param_1 = iVar1 + 1;
LAB_fffffff009983794:
  return iVar1 != 0;
}

