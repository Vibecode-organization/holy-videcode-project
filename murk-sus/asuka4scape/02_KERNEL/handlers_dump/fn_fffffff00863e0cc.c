// FUN_fffffff00863e0cc @ fffffff00863e0cc size=100 depth=0
// CALLERS:
//   fffffff00afc6788 ?
//   fffffff007d24528 ?
// CALLS:

undefined8 FUN_fffffff00863e0cc(long *param_1,undefined8 param_2,long param_3)

{
  undefined8 uVar1;
  
  if ((*(long *)(param_3 + 8) == 0) && (*(long *)(param_3 + 0x68) == 0)) {
                    /* WARNING: Could not recover jumptable at 0xfffffff00863e12c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*param_1 + 0x630))
                      (param_1,**(undefined4 **)(param_3 + 0x20),*(undefined8 *)(param_3 + 0x58),
                       param_3 + 0x60,(undefined8 *)(*param_1 + 0x630));
    return uVar1;
  }
  return 0xe00002c7;
}

