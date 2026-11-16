// FUN_fffffff0097907b4 @ fffffff0097907b4 size=72 depth=0
// CALLERS:
//   fffffff00afe264f ?
//   fffffff007f94fe0 ?
// CALLS:

void FUN_fffffff0097907b4(long param_1,undefined8 param_2,long param_3)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)(**(long **)(param_1 + 0x100) + 0x28);
                    /* WARNING: Could not recover jumptable at 0xfffffff0097907f8. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*puVar1)(*(long **)(param_1 + 0x100),**(undefined4 **)(param_3 + 0x20),
                     (*(undefined4 **)(param_3 + 0x20))[2],*(undefined8 *)(param_3 + 0x58),
                     *(undefined4 *)(param_3 + 0x60),puVar1);
  return;
}

