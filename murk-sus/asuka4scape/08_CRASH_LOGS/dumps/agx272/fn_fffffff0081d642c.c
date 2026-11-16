// FUN_fffffff0081d642c @ fffffff0081d642c size=92

void FUN_fffffff0081d642c(long *param_1)

{
  long lVar1;
  
  lVar1 = (long)(1 << (ulong)(*(uint *)PTR_DAT_fffffff007ca5f88 & 0x1f));
                    /* WARNING: Could not recover jumptable at 0xfffffff0081d6484. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0xb60))
            (param_1,lVar1 + 0xfffU & -lVar1,1,(undefined8 *)(*param_1 + 0xb60));
  return;
}

