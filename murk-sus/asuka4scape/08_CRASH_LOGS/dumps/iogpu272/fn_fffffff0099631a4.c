// FUN_fffffff0099631a4 @ fffffff0099631a4 size=228

long * FUN_fffffff0099631a4(long param_1,ulong *param_2,int param_3)

{
  long *plVar1;
  long *plVar2;
  
  *param_2 = 0xffffffffffffffff;
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x160));
  plVar1 = *(long **)(param_1 + 0x168);
  if (plVar1 != (long *)0x0) {
    plVar2 = (long *)0x0;
    do {
      if (param_3 != 0) {
        (**(code **)(*plVar1 + 0x90))(plVar1);
      }
      if ((ulong)plVar1[0xf] < *param_2) {
        *param_2 = plVar1[0xf];
        plVar2 = plVar1;
      }
      plVar1 = (long *)plVar1[6];
    } while (plVar1 != (long *)0x0);
    if (plVar2 != (long *)0x0) {
      plVar1 = (long *)FUN_fffffff00995da74(plVar2);
      if (plVar1 != (long *)0x0) {
        (**(code **)(*plVar1 + 0x20))(plVar1);
      }
      goto LAB_fffffff009963268;
    }
  }
  plVar1 = (long *)0x0;
LAB_fffffff009963268:
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x160));
  return plVar1;
}

