// FUN_fffffff0081c3cac @ fffffff0081c3cac size=92

undefined8 FUN_fffffff0081c3cac(long *param_1,ulong param_2,int param_3)

{
  undefined8 uVar1;
  
  if ((param_3 != 3) && ((1L << (param_2 & 0x3f) & (ulong)*(byte *)(param_1[0x101] + 0x3e4)) == 0))
  {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff0081c3d04. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(*param_1 + 0x408))();
  return uVar1;
}

