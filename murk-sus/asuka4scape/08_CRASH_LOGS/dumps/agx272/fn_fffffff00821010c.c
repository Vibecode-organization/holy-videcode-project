// FUN_fffffff00821010c @ fffffff00821010c size=264

void FUN_fffffff00821010c(long param_1,uint param_2,ulong param_3,ulong param_4)

{
  ulong uVar1;
  bool bVar2;
  int iVar3;
  
  if (param_2 != 0xffffffff) {
    if (*(int *)(param_1 + 0xcc) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff008210180. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(**(long **)(param_1 + 0x10) + 0xcf0))();
      return;
    }
    if (*(int *)(param_1 + 0xd0) != 0) {
      if ((*(int *)(param_1 + 0xd0) == 2 || param_3 == 0) ||
          param_4 - 0x2000000 < 0xfffffffffe000001) {
        SysOp_W(0,8,1,2,((ulong)param_2 & 0x1ff) << 0x30);
        return;
      }
      if ((ulong)(long)(1 << (ulong)(*(uint *)PTR_DAT_fffffff007ca5f88 & 0x1f)) < param_4) {
        bVar2 = param_4 >> 0x14 == 0;
        iVar3 = 0x14;
        if (bVar2) {
          iVar3 = 0xf;
        }
        uVar1 = 0x100000000000;
        if (bVar2) {
          uVar1 = 0;
        }
        SysOp_W(0,8,5,1,((ulong)param_2 & 0x1ff) << 0x30 | param_3 >> 0xe & 0x3fffffffff | uVar1 |
                        ((ulong)((((int)param_4 + (1 << iVar3)) - 1U & -(1 << iVar3)) >> iVar3) <<
                        0x27) + 0x1f8000000000 & 0x1f8000000000 | 0x800000000000);
        return;
      }
      SysOp_W(0,8,1,1,param_3 >> 0xc & 0xfffffffffff | ((ulong)param_2 & 0x1ff) << 0x30);
      return;
    }
    SysOp_W(0,8,1,0,0);
  }
  return;
}

