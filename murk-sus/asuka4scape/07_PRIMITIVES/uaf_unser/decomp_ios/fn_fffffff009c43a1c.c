// FUN_fffffff009c43a1c @ fffffff009c43a1c size=1200
// CALLERS:
//   fffffff009c4395c FUN_fffffff009c43898@fffffff009c43898

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
FUN_fffffff009c43a1c(long param_1,undefined8 param_2,long *param_3,long param_4,long *param_5)

{
  undefined1 uVar1;
  undefined8 uVar2;
  long lVar3;
  ulong uVar4;
  long *plVar5;
  long *plVar6;
  undefined8 uVar7;
  long *plVar8;
  undefined8 *puVar9;
  long *plVar10;
  long lVar11;
  long lVar12;
  
  (**(code **)(_DAT_fffffff00806ca30 + 0x78))();
  plVar8 = *(long **)(param_1 + 0x38);
  *(long **)(param_1 + 0x38) = param_5;
  if (param_5 != (long *)0x0) {
    (**(code **)(*param_5 + 0x20))(param_5);
  }
  if (plVar8 != (long *)0x0) {
    (**(code **)(*plVar8 + 0x28))(plVar8);
  }
  FUN_fffffff009c46f98(param_1 + 0x20,1);
  puVar9 = (undefined8 *)(param_1 + 0x48);
  *(undefined8 *)(param_1 + 0x50) = 0;
  *puVar9 = 0;
  *(undefined8 *)(param_1 + 0x80) = 0;
  *(undefined8 *)(param_1 + 0x78) = 0;
  *(undefined8 *)(param_1 + 0x90) = 0;
  *(undefined8 *)(param_1 + 0x88) = 0;
  *(undefined8 *)(param_1 + 0x60) = 0;
  *(undefined8 *)(param_1 + 0x58) = 0;
  *(undefined8 *)(param_1 + 0x70) = 0;
  *(undefined8 *)(param_1 + 0x68) = 0;
  if (param_4 == 0) {
    param_4 = 0;
  }
  *(undefined8 *)(param_1 + 0x28) = param_2;
  *(long *)(param_1 + 0x30) = param_4;
  uVar2 = FUN_fffffff009c49594();
  *(undefined8 *)(param_1 + 0x40) = uVar2;
  plVar8 = *(long **)(param_1 + 0x98);
  *(long **)(param_1 + 0x98) = param_3;
  if (param_3 != (long *)0x0) {
    (**(code **)(*param_3 + 0x20))(param_3);
  }
  if (plVar8 != (long *)0x0) {
    (**(code **)(*plVar8 + 0x28))(plVar8);
  }
  *(undefined2 *)(param_1 + 0xa0) = 0x100;
  if (*(long **)(param_1 + 0xa8) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0xa8) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0xa8) = 0;
  if (*(long *)(param_1 + 0x40) == 0) {
LAB_fffffff009c43e60:
    uVar2 = 0;
  }
  else {
    lVar11 = 0;
    lVar12 = 10;
    do {
      lVar3 = FUN_fffffff009c49a54(1);
      if ((long *)puVar9[lVar11] != (long *)0x0) {
        (**(code **)(*(long *)puVar9[lVar11] + 0x28))();
      }
      puVar9[lVar11] = lVar3;
      if (lVar3 == 0) goto LAB_fffffff009c43e60;
      lVar11 = lVar11 + 1;
      lVar12 = lVar12 + -1;
    } while (lVar12 != 0);
    plVar8 = *(long **)(param_1 + 0x98);
    if (plVar8 != (long *)0x0) {
      lVar11 = (**(code **)(*plVar8 + 0x138))(plVar8,_DAT_fffffff008066fd0);
      if (lVar11 != 0) {
        if (param_3 != (long *)0x0) {
          (**(code **)(*param_3 + 0x20))(param_3);
        }
        uVar4 = FUN_fffffff009c45b34(param_1,param_3);
        if ((uVar4 & 1) == 0) {
          FUN_fffffff009c495f4(0xfffffff00789d6e3);
        }
      }
      uVar2 = (**(code **)(*param_3 + 0x138))(param_3,_DAT_fffffff008066fd8);
      uVar7 = *_DAT_fffffff00806ca20;
      plVar8 = (long *)FUN_fffffff009c498d4(uVar2,uVar7);
      if (plVar8 != (long *)0x0) {
        (**(code **)(*plVar8 + 0x20))(plVar8);
        uVar1 = (**(code **)(*plVar8 + 0x88))(plVar8);
        *(undefined1 *)(param_1 + 0xa0) = uVar1;
      }
      uVar2 = (**(code **)(*param_3 + 0x138))(param_3,_DAT_fffffff008066fe0);
      plVar5 = (long *)FUN_fffffff009c498d4(uVar2,uVar7);
      if (plVar5 != (long *)0x0) {
        (**(code **)(*plVar5 + 0x20))(plVar5);
        uVar1 = (**(code **)(*plVar5 + 0x88))(plVar5);
        *(undefined1 *)(param_1 + 0xa1) = uVar1;
      }
      uVar2 = (**(code **)(*param_3 + 0x138))(param_3,_DAT_fffffff008066fe8);
      plVar6 = (long *)FUN_fffffff009c498d4(uVar2,*_DAT_fffffff00806ca10);
      plVar10 = *(long **)(param_1 + 0xa8);
      *(long **)(param_1 + 0xa8) = plVar6;
      if (plVar6 != (long *)0x0) {
        (**(code **)(*plVar6 + 0x20))();
      }
      if (plVar10 != (long *)0x0) {
        (**(code **)(*plVar10 + 0x28))(plVar10);
      }
      if (plVar5 != (long *)0x0) {
        (**(code **)(*plVar5 + 0x28))(plVar5);
      }
      if (plVar8 != (long *)0x0) {
        (**(code **)(*plVar8 + 0x28))(plVar8);
      }
    }
    uVar2 = 1;
  }
  if (param_5 != (long *)0x0) {
    (**(code **)(*param_5 + 0x28))(param_5);
  }
  if (param_3 != (long *)0x0) {
    (**(code **)(*param_3 + 0x28))(param_3);
  }
  return uVar2;
}

