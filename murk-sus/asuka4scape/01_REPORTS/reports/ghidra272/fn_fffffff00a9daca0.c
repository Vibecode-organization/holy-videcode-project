// FUN_fffffff00a9daca0 @ fffffff00a9daca0 size=856

undefined8 FUN_fffffff00a9daca0(long param_1,undefined8 param_2,long *param_3)

{
  ulong *puVar1;
  int *piVar2;
  long lVar3;
  long lVar4;
  undefined8 uVar5;
  long *plVar6;
  ulong uVar7;
  long *plVar8;
  long *plVar9;
  int in_wzr;
  undefined *local_80;
  undefined8 local_78;
  code *local_70;
  undefined *local_68;
  long *plStack_60;
  long *local_58;
  
  plVar9 = *(long **)(*(long *)(param_1 + 0x28) + 0x30);
  (**(code **)(*param_3 + 0x20))(param_3);
  lVar3 = tpidr_el1;
  puVar1 = (ulong *)(*plVar9 + 8);
  if (*puVar1 == 0) {
    *puVar1 = (ulong)*(uint *)(lVar3 + 0x4e8);
  }
  else {
    FUN_fffffff00a2262d4(*plVar9,lVar3,0);
  }
  lVar4 = (**(code **)(*(long *)plVar9[1] + 0x130))((long *)plVar9[1],param_2);
  if (lVar4 == 0) {
    (**(code **)(*param_3 + 0x28))(param_3);
    plVar6 = (long *)0x0;
    plVar8 = (long *)0x0;
    uVar5 = 0xe00002f0;
  }
  else {
    if (*(long **)(lVar4 + 0x10) != (long *)0x0) {
      (**(code **)(**(long **)(lVar4 + 0x10) + 0x28))();
    }
    *(long **)(lVar4 + 0x10) = param_3;
    uVar5 = (**(code **)(**(long **)(lVar4 + 0x18) + 0x90))();
    if ((int)uVar5 == 0) {
      plVar6 = (long *)0x0;
LAB_fffffff00a9daf38:
      uVar5 = 0;
      plVar8 = (long *)0x0;
    }
    else {
      plVar6 = (long *)(**(code **)(DAT_fffffff00ad95e68 + 0x68))(&DAT_fffffff00ad95e68);
      if ((plVar6 != (long *)0x0) &&
         (uVar7 = (**(code **)(*plVar6 + 0xd0))(plVar6,uVar5), (uVar7 & 1) == 0)) {
        (**(code **)(*plVar6 + 0x28))(plVar6);
        plVar6 = (long *)0x0;
      }
      plVar8 = (long *)(**(code **)(DAT_fffffff00ad95e68 + 0x68))(&DAT_fffffff00ad95e68);
      if (plVar8 != (long *)0x0) {
        uVar7 = (**(code **)(*plVar8 + 0xd0))(plVar8,uVar5);
        if ((uVar7 & 1) == 0) {
          (**(code **)(*plVar8 + 0x28))(plVar8);
          goto LAB_fffffff00a9daf38;
        }
        if (plVar6 != (long *)0x0) {
          local_80 = &DAT_fffffff00ad98dc0;
          local_78 = DAT_fffffff00700d9a0;
          local_70 = FUN_fffffff00a9daff8;
          local_68 = &DAT_fffffff007c64790;
          plStack_60 = plVar6;
          local_58 = plVar8;
          FUN_fffffff00a89b94c(&local_68,*(undefined8 *)(lVar4 + 0x18),&local_80);
        }
      }
      uVar5 = 0;
    }
  }
  piVar2 = (int *)(*plVar9 + 8);
  if (*piVar2 == *(int *)(lVar3 + 0x4e8)) {
    *piVar2 = in_wzr;
    if (plVar6 != (long *)0x0) goto LAB_fffffff00a9daf5c;
LAB_fffffff00a9daf90:
    if (plVar6 == (long *)0x0) goto LAB_fffffff00a9dafb4;
  }
  else {
    FUN_fffffff00a226e08(*plVar9,lVar3);
    if (plVar6 == (long *)0x0) goto LAB_fffffff00a9daf90;
LAB_fffffff00a9daf5c:
    if (plVar8 == (long *)0x0) goto LAB_fffffff00a9daf90;
    FUN_fffffff00a89b94c(plVar6,&DAT_fffffff007c647d0);
  }
  (**(code **)(*plVar6 + 0x28))(plVar6);
LAB_fffffff00a9dafb4:
  if (plVar8 != (long *)0x0) {
    (**(code **)(*plVar8 + 0x28))(plVar8);
  }
  return uVar5;
}

