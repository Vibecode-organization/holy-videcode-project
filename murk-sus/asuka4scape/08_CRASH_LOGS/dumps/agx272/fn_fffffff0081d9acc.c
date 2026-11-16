// FUN_fffffff0081d9acc @ fffffff0081d9acc size=72

void FUN_fffffff0081d9acc(long param_1)

{
  if ((DAT_fffffff00ae25928 & 1) != 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff0081d9b08. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(long **)(*(long *)(param_1 + 0x2d0) + 0x10) + 0x88))();
    return;
  }
  FUN_fffffff0082102cc(*(undefined8 *)(*(long *)(param_1 + 0x2d0) + 0x18));
  return;
}

