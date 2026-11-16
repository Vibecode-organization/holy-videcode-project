// FUN_fffffff00997a2b4 @ fffffff00997a2b4 size=180

long * FUN_fffffff00997a2b4(long param_1)

{
  undefined8 *puVar1;
  long *plVar2;
  
  plVar2 = (long *)thunk_EXT_FUN_801100000389d0d8(3);
  if (plVar2 != (long *)0x0) {
    puVar1 = &DAT_fffffff00af22838;
    if ((*(byte *)(param_1 + 0x439) & 1) == 0) {
      puVar1 = &DAT_fffffff00af22840;
    }
    (**(code **)(*plVar2 + 0xf0))(plVar2,DAT_fffffff00af22830,*puVar1);
    FUN_fffffff00997a368(plVar2,DAT_fffffff00af22820,*(undefined8 *)(param_1 + 0x558));
    FUN_fffffff00997a368(plVar2,DAT_fffffff00af22828,*(undefined8 *)(param_1 + 0x560));
  }
  return plVar2;
}

