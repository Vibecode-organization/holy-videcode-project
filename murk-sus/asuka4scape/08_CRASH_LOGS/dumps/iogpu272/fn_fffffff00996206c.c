// FUN_fffffff00996206c @ fffffff00996206c size=124

undefined8 FUN_fffffff00996206c(long param_1)

{
  int iVar1;
  long lVar2;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  FUN_fffffff00997dff4(&local_38,*(long *)(param_1 + 0x20) + 0x1b8);
  lVar2 = FUN_fffffff00997e0b0(&local_38);
  while (lVar2 != 0) {
    iVar1 = FUN_fffffff009942bf8(lVar2);
    if (iVar1 == 0) {
      FUN_fffffff009942c08(lVar2);
    }
    lVar2 = FUN_fffffff00997e0b0(&local_38);
  }
  FUN_fffffff00997e060(&local_38);
  return 0;
}

