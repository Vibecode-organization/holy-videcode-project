// FUN_fffffff00a8d8754 @ fffffff00a8d8754 size=192
// CALLERS:
//   fffffff00a9a8d8c FUN_fffffff00a9a8d08@fffffff00a9a8d08
//   fffffff00a9a8630 FUN_fffffff00a9a85b8@fffffff00a9a85b8
//   fffffff00a9a87e0 FUN_fffffff00a9a8794@fffffff00a9a8794
//   fffffff00a9a8b58 FUN_fffffff00a9a8b10@fffffff00a9a8b10
//   fffffff00a9a8a38 FUN_fffffff00a9a899c@fffffff00a9a899c
//   fffffff00a9b01b4 FUN_fffffff00a9aff58@fffffff00a9aff58
//   fffffff00a9abac8 FUN_fffffff00a9ab9f8@fffffff00a9ab9f8
//   fffffff00a9e06fc FUN_fffffff00a9e0640@fffffff00a9e0640

undefined8 FUN_fffffff00a8d8754(char *param_1,ulong param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  if ((param_1 != (char *)0x0) && (3 < param_2)) {
    iVar1 = FUN_fffffff00aa7451c(&DAT_fffffff007043a08,param_1);
    if ((iVar1 == 0) || (*param_1 == -0x2c)) {
      uVar2 = FUN_fffffff00a8d96f4(param_1,param_2,0,0,0,param_3);
      return uVar2;
    }
    if (param_1[param_2 - 1] == '\0') {
      uVar2 = FUN_fffffff00a8d846c(param_1,0,0,0,param_3);
      return uVar2;
    }
  }
  return 0;
}

