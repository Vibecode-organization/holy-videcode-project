// FUN_fffffff009c15480 @ fffffff009c15480 size=764

/* WARNING: Removing unreachable block (ram,0xfffffff009c157cc) */

ulong FUN_fffffff009c15480
                (long param_1,undefined8 param_2,long *param_3,int param_4,undefined8 param_5,
                undefined8 param_6,undefined8 param_7,undefined8 param_8)

{
  int iVar1;
  long lVar2;
  long *plVar3;
  long *plVar4;
  long *plVar5;
  long *plVar6;
  long *plVar7;
  undefined8 uVar8;
  ulong uVar9;
  
  iVar1 = (**(code **)(PTR_DAT_fffffff00806ca30 + 0x78))();
  if (iVar1 == 0) {
    return 0;
  }
  *(char *)(param_1 + 0x40) = (char)param_4;
  *(undefined8 *)(param_1 + 0x48) = param_5;
  if (param_4 == 0) {
    return 1;
  }
  lVar2 = thunk_EXT_FUN_80110000038ff010();
  *(long *)(param_1 + 0x10) = lVar2;
  if (lVar2 == 0) {
    return 0;
  }
  *(undefined8 *)(param_1 + 0x18) = 0;
  *(undefined8 **)(param_1 + 0x20) = (undefined8 *)(param_1 + 0x18);
  plVar3 = (long *)FUN_fffffff009c31464();
  if (plVar3 == (long *)0x0) {
    if (param_3 != (long *)0x0) goto LAB_fffffff009c15560;
LAB_fffffff009c155b4:
    plVar5 = (long *)thunk_EXT_FUN_801100000392f2f0("IOCoreSurfaceRoot",0);
    plVar6 = (long *)thunk_EXT_FUN_801100000392ece0(plVar5,0xffffffffffffffff);
    plVar7 = (long *)thunk_EXT_FUN_8011000003890f30(plVar6,DAT_fffffff008067d90);
    plVar4 = plVar6;
    if (plVar7 != (long *)0x0) {
      plVar4 = (long *)0x0;
    }
    if (plVar3 != (long *)0x0) {
      (**(code **)(*plVar3 + 0x28))(plVar3);
    }
    if (plVar4 != (long *)0x0) {
      (**(code **)(*plVar6 + 0x28))(plVar6);
    }
    if (plVar5 != (long *)0x0) {
      (**(code **)(*plVar5 + 0x28))(plVar5);
    }
    plVar3 = plVar7;
    if (plVar7 == (long *)0x0) goto LAB_fffffff009c15694;
  }
  else {
    (**(code **)(*plVar3 + 0x20))(plVar3);
    if (param_3 != (long *)0x0) {
LAB_fffffff009c15560:
      plVar4 = *(long **)(param_1 + 0x30);
      *(long **)(param_1 + 0x30) = param_3;
      (**(code **)(*param_3 + 0x20))(param_3);
      if (plVar4 != (long *)0x0) {
        (**(code **)(*plVar4 + 0x28))(plVar4);
      }
      goto LAB_fffffff009c15694;
    }
    plVar4 = (long *)FUN_fffffff009c3826c(plVar3);
    if (plVar4 == (long *)0x0) goto LAB_fffffff009c155b4;
    (**(code **)(*plVar4 + 0x28))();
    plVar7 = plVar3;
  }
  uVar8 = FUN_fffffff009c3826c(plVar7);
  if (*(long **)(param_1 + 0x30) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x30) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x30) = uVar8;
  plVar3 = plVar7;
LAB_fffffff009c15694:
  if (*(long *)(param_1 + 0x30) == 0) {
    uVar8 = FUN_fffffff009c48de4();
    thunk_EXT_FUN_80110000036da494
              (0x85210030,1,0,0,0,0,param_7,param_8,plVar3,param_1,&stack0xfffffffffffffff0);
    uVar9 = FUN_fffffff009c159b4(uVar8);
    return uVar9;
  }
  lVar2 = thunk_EXT_FUN_801100000395abd8(param_1,FUN_fffffff009c1577c,0,0);
  if (*(long **)(param_1 + 0x38) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x38) + 0x28))();
  }
  *(long *)(param_1 + 0x38) = lVar2;
  if (lVar2 != 0) {
    (**(code **)(**(long **)(param_1 + 0x30) + 0xa0))(*(long **)(param_1 + 0x30),lVar2);
    (**(code **)(**(long **)(param_1 + 0x38) + 0xb0))();
  }
  if (plVar3 != (long *)0x0) {
    (**(code **)(*plVar3 + 0x28))(plVar3);
    return (ulong)(lVar2 != 0);
  }
  return (ulong)(lVar2 != 0);
}

