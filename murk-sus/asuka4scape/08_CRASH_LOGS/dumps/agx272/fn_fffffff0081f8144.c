// FUN_fffffff0081f8144 @ fffffff0081f8144 size=84

undefined8 FUN_fffffff0081f8144(long param_1,ulong param_2,undefined8 *param_3,undefined8 param_4)

{
  ulong uVar1;
  ulong uVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  
  if (param_2 < *(ulong *)(param_1 + 0x50)) {
    uVar1 = *(ulong *)(param_1 + 0x68);
    uVar2 = 0;
    if (uVar1 != 0) {
      uVar2 = param_2 / uVar1;
    }
    puVar4 = (undefined8 *)(**(long **)(param_1 + 0x60) + 0x98);
                    /* WARNING: Could not recover jumptable at 0xfffffff0081f8184. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    uVar3 = (*(code *)*puVar4)(*(long **)(param_1 + 0x60),param_2 - uVar2 * uVar1,param_3,param_4,
                               puVar4);
    return uVar3;
  }
  if (param_3 != (undefined8 *)0x0) {
    *param_3 = 0;
  }
  return 0;
}

