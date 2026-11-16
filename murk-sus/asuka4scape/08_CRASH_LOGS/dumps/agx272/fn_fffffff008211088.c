// FUN_fffffff008211088 @ fffffff008211088 size=112

void FUN_fffffff008211088(long param_1)

{
  undefined8 *puVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 0xb0);
  if (uVar2 != 0xffffffff) {
    if (*(int *)(param_1 + 0xcc) == 0) {
      puVar1 = (undefined8 *)(**(long **)(param_1 + 0x10) + 0xcf0);
                    /* WARNING: Could not recover jumptable at 0xfffffff0082110ec. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)*puVar1)(*(long **)(param_1 + 0x10),(ulong)uVar2,0,0,puVar1);
      return;
    }
    if (*(int *)(param_1 + 0xd0) != 0) {
      SysOp_W(0,8,1,2,((ulong)uVar2 & 0x1ff) << 0x30);
      return;
    }
    SysOp_W(0,8,1,0,0);
  }
  return;
}

