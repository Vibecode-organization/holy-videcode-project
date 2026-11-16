// FUN_fffffff0081dcfd0 @ fffffff0081dcfd0 size=80

undefined8 FUN_fffffff0081dcfd0(long param_1)

{
  long *plVar1;
  undefined8 uVar2;
  
  plVar1 = *(long **)(param_1 + 0x11198);
  if (plVar1 != (long *)0x0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff0081dd00c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (**(code **)(*plVar1 + 0xa8))(plVar1,(undefined8 *)(*plVar1 + 0xa8));
    return uVar2;
  }
  return *(undefined8 *)(param_1 + 0x1ad00);
}

