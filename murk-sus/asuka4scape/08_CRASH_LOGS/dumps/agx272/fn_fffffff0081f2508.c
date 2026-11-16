// FUN_fffffff0081f2508 @ fffffff0081f2508 size=668

long * FUN_fffffff0081f2508(long param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  long *plVar4;
  long *plVar5;
  long *plVar6;
  ulong uVar7;
  long lVar8;
  ulong uVar9;
  long *local_68;
  
  plVar4 = (long *)thunk_EXT_FUN_80110000038961f4(*(undefined4 *)(*(long *)(param_1 + 0x18) + 0x48))
  ;
  if ((plVar4 != (long *)0x0) && (lVar8 = *(long *)(param_1 + 0x18), *(int *)(lVar8 + 0x48) != 0)) {
    uVar9 = 0;
    do {
      lVar8 = *(long *)(*(long *)(lVar8 + 0x40) + uVar9 * 8);
      plVar5 = (long *)thunk_EXT_FUN_801100000389d0d8(3);
      if (plVar5 == (long *)0x0) goto LAB_fffffff0081f275c;
      iVar3 = *(int *)(lVar8 + 4);
      iVar1 = *(int *)(lVar8 + 8);
      plVar6 = (long *)thunk_EXT_FUN_80110000038c6e24(uVar9,0x20);
      if (plVar6 == (long *)0x0) {
LAB_fffffff0081f2744:
        (**(code **)(*plVar5 + 0x28))(plVar5);
LAB_fffffff0081f275c:
        (**(code **)(*plVar4 + 0x28))(plVar4);
        return (long *)0x0;
      }
      iVar2 = (**(code **)(*plVar5 + 0x100))(plVar5,"index",plVar6);
      (**(code **)(*plVar6 + 0x28))(plVar6);
      if ((iVar2 == 0) ||
         (plVar6 = (long *)thunk_EXT_FUN_80110000038c6e24(iVar3 - iVar1,0x20), plVar6 == (long *)0x0
         )) goto LAB_fffffff0081f2744;
      iVar3 = (**(code **)(*plVar5 + 0x100))(plVar5,"free_num",plVar6);
      (**(code **)(*plVar6 + 0x28))(plVar6);
      if ((iVar3 == 0) ||
         (plVar6 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(lVar8 + 0x14),0x20),
         plVar6 == (long *)0x0)) goto LAB_fffffff0081f2744;
      iVar3 = (**(code **)(*plVar5 + 0x100))(plVar5,"source_mask",plVar6);
      (**(code **)(*plVar6 + 0x28))(plVar6);
      if (iVar3 == 0) goto LAB_fffffff0081f2744;
      local_68 = plVar5;
      (**(code **)(*plVar5 + 0x20))(plVar5);
      uVar7 = thunk_EXT_FUN_80110000038963f0(plVar4,&local_68);
      if (local_68 != (long *)0x0) {
        (**(code **)(*local_68 + 0x28))();
      }
      (**(code **)(*plVar5 + 0x28))(plVar5);
      if ((uVar7 & 1) == 0) goto LAB_fffffff0081f275c;
      uVar9 = uVar9 + 1;
      lVar8 = *(long *)(param_1 + 0x18);
    } while (uVar9 < *(uint *)(lVar8 + 0x48));
  }
  return plVar4;
}

