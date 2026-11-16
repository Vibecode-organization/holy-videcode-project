// FUN_fffffff00aa0a3b4 @ fffffff00aa0a3b4 size=232 depth=1
// CALLERS:
//   fffffff00afbfd64 ?
//   fffffff00a9e0428 FUN_fffffff00a9dfff0
// CALLS:

undefined8 FUN_fffffff00aa0a3b4(long param_1,ulong param_2)

{
  ulong uVar1;
  undefined8 uVar2;
  
  uVar1 = (**(code **)(*DAT_fffffff00add78a0 + 0x98))();
  if ((uVar1 & 1) != 0) {
    uVar2 = 0xe00002c2;
    if (*(long *)(param_1 + 0xd0) == 0) {
      uVar2 = 0xe00002f0;
    }
    else if (param_2 < 0x101) {
      uVar2 = 0;
      *(ulong *)(*(long *)(param_1 + 0xd0) + 0x3c78) = param_2;
    }
    return uVar2;
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff00aa0a484. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (**(code **)(*DAT_fffffff00add78a0 + 0x100))
                    (DAT_fffffff00add78a0,FUN_fffffff00aa0a3b4,param_1,param_2,0,0,0,
                     (undefined8 *)(*DAT_fffffff00add78a0 + 0x100));
  return uVar2;
}

