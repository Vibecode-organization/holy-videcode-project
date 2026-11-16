// FUN_fffffff008210410 @ fffffff008210410 size=352

void FUN_fffffff008210410(long *param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  uint uVar2;
  int iVar3;
  code *pcVar4;
  ulong unaff_x30;
  
  if ((int)param_1[0x16] != -1) {
    (**(code **)(*param_1 + 0xd0))(param_1,(int)param_1[0x16]);
  }
  *(int *)(param_1 + 0x16) = (int)param_2;
  (**(code **)(*param_1 + 200))(param_1,param_2,0);
  uVar2 = *(uint *)(param_1 + 0x16);
  if (uVar2 != 0xffffffff) {
    if (*(int *)((long)param_1 + 0xcc) != 0) {
      if ((int)param_1[0x1a] == 0) {
        SysOp_W(0,8,1,0,0);
        iVar3 = *(int *)((long)param_1 + 0xcc);
      }
      else {
        SysOp_W(0,8,1,2,((ulong)uVar2 & 0x1ff) << 0x30);
        iVar3 = *(int *)((long)param_1 + 0xcc);
      }
      goto joined_r0xfffffff0082104c0;
    }
    (**(code **)(*(long *)param_1[2] + 0xcf0))((long *)param_1[2],(ulong)uVar2,0,0);
  }
  iVar3 = *(int *)((long)param_1 + 0xcc);
joined_r0xfffffff0082104c0:
  if (iVar3 != 0) {
    DataSynchronizationBarrier(3,3,0);
    return;
  }
  puVar1 = (undefined8 *)(*(long *)param_1[2] + 0xcf8);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0xc471,0xfffffff008210564);
    (*pcVar4)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff00821056c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*puVar1)((long *)param_1[2],puVar1);
  return;
}

