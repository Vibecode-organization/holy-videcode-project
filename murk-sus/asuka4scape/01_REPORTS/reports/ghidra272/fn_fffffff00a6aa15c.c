// FUN_fffffff00a6aa15c @ fffffff00a6aa15c size=300

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
FUN_fffffff00a6aa15c
          (long param_1,long param_2,undefined8 param_3,undefined8 *param_4,undefined4 *param_5)

{
  undefined8 *puVar1;
  long lVar2;
  ulong uVar3;
  code *pcVar4;
  int iVar5;
  undefined8 uVar6;
  long lVar7;
  
  uVar3 = DAT_fffffff00ad95818;
  if (param_1 == 0) {
    return 0;
  }
  if (param_2 == 0) {
    return 0;
  }
  if (param_4 == (undefined8 *)0x0) {
    return 0;
  }
  if (param_5 == (undefined4 *)0x0) {
    return 0;
  }
  FUN_fffffff00a228180(param_1 + 0x910);
  lVar7 = *(long *)(param_1 + 0x920);
  if ((lVar7 != 0) &&
     ((((*(int *)(lVar7 + 0x2f0) != 0 || (*(int *)(lVar7 + 0x2f4) != 0)) ||
       (*(int *)(lVar7 + 0x2f8) != 0)) || (*(int *)(lVar7 + 0x2fc) != 0)))) {
    puVar1 = (undefined8 *)(lVar7 + 0x2f0);
    if ((undefined8 *)(lVar7 + 0x310U) <= puVar1) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x5519,0xfffffff00a6aa288);
      (*pcVar4)();
    }
    iVar5 = FUN_fffffff00a6670b4
                      (puVar1,*(undefined2 *)(param_1 + 0xcc),param_2,
                       *(undefined2 *)(param_1 + 0xcc),param_3);
    if ((iVar5 != 0) && (uVar3 <= *(long *)(lVar7 + 0x308) - 1U)) {
      lVar2 = 0;
      if (*(ulong *)(lVar7 + 0x300) <= uVar3) {
        lVar2 = uVar3 - *(ulong *)(lVar7 + 0x300);
      }
      if ((ulong)(lVar2 + (long)DAT_fffffff00ad85b4c + (long)_DAT_fffffff00ad1472c) <
          (ulong)_DAT_fffffff00ad14724) {
        uVar6 = *puVar1;
        param_4[1] = *(undefined8 *)(lVar7 + 0x2f8);
        *param_4 = uVar6;
        *param_5 = (int)lVar2;
        uVar6 = 1;
        goto LAB_fffffff00a6aa260;
      }
    }
  }
  uVar6 = 0;
LAB_fffffff00a6aa260:
  FUN_fffffff00a228d30(param_1 + 0x910);
  return uVar6;
}

