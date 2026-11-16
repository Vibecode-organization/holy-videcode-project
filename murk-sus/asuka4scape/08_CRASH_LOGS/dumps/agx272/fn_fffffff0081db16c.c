// FUN_fffffff0081db16c @ fffffff0081db16c size=248

void FUN_fffffff0081db16c
               (long *param_1,undefined8 param_2,long param_3,ulong param_4,undefined8 param_5)

{
  ulong uVar1;
  bool bVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  uVar3 = 0xb0022;
  if (*(int *)(param_1[8] + 0x10954) == 0) {
    uVar3 = 0xb0028;
  }
  else {
    if (*(int *)(param_1[8] + 0x10954) == 2) {
      uVar5 = 0;
      uVar4 = 0;
      goto LAB_fffffff0081db23c;
    }
    uVar5 = 0;
    if (param_3 != 0) {
      uVar4 = 0;
      if (0xfffffffffe000000 < param_4 - 0x2000000) {
        bVar2 = param_4 >> 0x14 != 0;
        iVar6 = 0x14;
        if (!bVar2) {
          iVar6 = 0xf;
        }
        uVar1 = (ulong)(1 << (ulong)(*(uint *)PTR_DAT_fffffff007ca5f88 & 0x1f));
        uVar3 = 0xb0021;
        if (uVar1 < param_4) {
          uVar3 = 0xb0040;
        }
        uVar5 = 0;
        if (uVar1 < param_4) {
          uVar5 = (uint)bVar2;
        }
        uVar4 = 0;
        if (uVar1 < param_4) {
          uVar4 = ((((int)param_4 + (1 << iVar6)) - 1U & -(1 << iVar6)) >> iVar6) - 1;
        }
      }
      goto LAB_fffffff0081db23c;
    }
  }
  uVar5 = 0;
  uVar4 = uVar5;
LAB_fffffff0081db23c:
                    /* WARNING: Could not recover jumptable at 0xfffffff0081db260. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0xc0))(param_1,uVar3,param_2,param_3,param_4,uVar4,uVar5,param_5);
  return;
}

