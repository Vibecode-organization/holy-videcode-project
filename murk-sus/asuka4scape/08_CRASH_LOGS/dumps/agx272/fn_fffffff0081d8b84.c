// FUN_fffffff0081d8b84 @ fffffff0081d8b84 size=80

undefined8 FUN_fffffff0081d8b84(long param_1)

{
  long *plVar1;
  undefined8 uVar2;
  
  plVar1 = *(long **)(param_1 + 0x11198);
  if (plVar1 != (long *)0x0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff0081d8bc0. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (**(code **)(*plVar1 + 0xa8))(plVar1,(undefined8 *)(*plVar1 + 0xa8));
    return uVar2;
  }
  return *(undefined8 *)(param_1 + 0x1ad00);
}

