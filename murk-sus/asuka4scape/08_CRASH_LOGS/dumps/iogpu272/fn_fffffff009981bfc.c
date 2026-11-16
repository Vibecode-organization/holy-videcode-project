// FUN_fffffff009981bfc @ fffffff009981bfc size=204

undefined8 FUN_fffffff009981bfc(long param_1,undefined8 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined8 uVar2;
  undefined4 local_34;
  
  if (*(long *)(param_1 + 0x90) == 0) {
    return 0xe00002bd;
  }
  iVar1 = FUN_fffffff0099437e4();
  if (((int)param_2 - 3U < 2) && (iVar1 != 0)) {
    *(char *)(param_1 + 0x35) = (char)param_2;
    if (param_3 == (undefined4 *)0x0) {
      return 0;
    }
    local_34 = 2;
  }
  else {
    local_34 = 0;
    uVar2 = (**(code **)(**(long **)(param_1 + 0x90) + 0x80))
                      (*(long **)(param_1 + 0x90),param_2,&local_34);
    if ((int)uVar2 != 0) {
      return uVar2;
    }
    if ((int)param_2 != 1) {
      *(char *)(param_1 + 0x35) = (char)param_2;
    }
    if (param_3 == (undefined4 *)0x0) {
      return 0;
    }
  }
  *param_3 = local_34;
  return 0;
}

