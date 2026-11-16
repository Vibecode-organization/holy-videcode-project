// FUN_fffffff009c37d6c @ fffffff009c37d6c size=196

undefined8 * FUN_fffffff009c37d6c(long param_1,undefined8 param_2,long *param_3)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  long *plVar3;
  
  puVar1 = (undefined8 *)thunk_EXT_FUN_80110000038fe074(&DAT_fffffff00806b4b0);
  if (puVar1 != (undefined8 *)0x0) {
    plVar3 = (long *)puVar1[3];
    puVar1[2] = param_2;
    puVar1[3] = param_3;
    if (param_3 != (long *)0x0) {
      (**(code **)(*param_3 + 0x20))(param_3);
    }
    if (plVar3 != (long *)0x0) {
      (**(code **)(*plVar3 + 0x28))(plVar3);
    }
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x3b8));
    puVar2 = *(undefined8 **)(param_1 + 0x3e0);
    *puVar1 = 0;
    puVar1[1] = puVar2;
    *puVar2 = puVar1;
    *(undefined8 **)(param_1 + 0x3e0) = puVar1;
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x3b8));
  }
  return puVar1;
}

