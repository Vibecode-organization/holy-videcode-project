// FUN_fffffff0081ba5f0 @ fffffff0081ba5f0 size=752

/* WARNING: Removing unreachable block (ram,0xfffffff0081ba704) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081ba7d0) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081ba6c0) */

undefined8
FUN_fffffff0081ba5f0(long param_1,long *param_2,undefined8 param_3,code *param_4,ulong param_5)

{
  long *plVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  long *plVar5;
  long *plVar6;
  long *plVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  ulong uVar10;
  undefined8 uVar11;
  
  lVar2 = (**(code **)(*param_2 + 0x138))(param_2,param_3);
  if (lVar2 != 0) {
    lVar2 = thunk_EXT_FUN_8011000003890f30(lVar2,*(undefined8 *)PTR_DAT_fffffff007ca60c8);
    if (lVar2 == 0) {
      return 0xe00002c2;
    }
    lVar2 = (**(code **)(*param_2 + 0x138))(param_2,"ID");
    lVar3 = (**(code **)(*param_2 + 0x138))(*param_2 + 0x138,param_2,"ID2");
    lVar4 = (**(code **)(*param_2 + 0x138))(*param_2 + 0x138,param_2,"Value");
    if ((lVar2 == 0 || lVar3 == 0) || lVar4 == 0) {
      return 0xe00002c2;
    }
    uVar11 = *(undefined8 *)PTR_DAT_fffffff007ca60a8;
    plVar5 = (long *)thunk_EXT_FUN_8011000003890f30(lVar2,uVar11);
    plVar6 = (long *)thunk_EXT_FUN_8011000003890f30(lVar3,uVar11);
    plVar7 = (long *)thunk_EXT_FUN_8011000003890f30(lVar4,uVar11);
    if ((plVar5 == (long *)0x0 || plVar6 == (long *)0x0) || plVar7 == (long *)0x0) {
      return 0xe00002c2;
    }
    lVar2 = (long)param_5 >> 1;
    plVar1 = (long *)(param_1 + (int)lVar2);
    if (lVar2 != (int)lVar2) {
      plVar1 = (long *)(param_1 + lVar2 & 0xffffffffffffU | 0x2bad000000000000);
    }
    if ((param_5 & 1) != 0) {
      param_4 = *(code **)(*plVar1 + ((ulong)param_4 & 0xffffffff));
    }
    uVar11 = (**(code **)(*plVar5 + 0xa0))(plVar5);
    uVar8 = (**(code **)(*plVar6 + 0xa0))(plVar6);
    uVar9 = (**(code **)(*plVar7 + 0xb0))(plVar7);
    uVar10 = (*param_4)(plVar1,uVar11,uVar8,uVar9);
    if ((uVar10 & 1) == 0) {
      (**(code **)(*plVar5 + 0xa0))(plVar5);
      (**(code **)(*plVar6 + 0xa0))(plVar6);
      (**(code **)(*plVar7 + 0xa0))(plVar7);
      return 0xe00002c2;
    }
  }
  return 0;
}

