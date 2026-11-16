// FUN_fffffff009c3d564 @ fffffff009c3d564 size=508
// CALLERS:

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_fffffff009c3d564(undefined8 param_1,undefined4 *param_2,ulong param_3)

{
  undefined8 *puVar1;
  long *plVar2;
  long *plVar3;
  long *plVar4;
  long lVar5;
  long lVar6;
  long *plVar7;
  long *plVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  
  uVar10 = 0xe00002c2;
  plVar2 = (long *)FUN_fffffff009c3f1d0(param_1,*param_2);
  if (plVar2 != (long *)0x0) {
    plVar3 = (long *)FUN_fffffff009c49764
                               (param_2 + 4,
                                (long)param_2 + ((param_3 & 0xffffffff) - (long)(param_2 + 4)),0);
    if (plVar3 != (long *)0x0) {
      plVar4 = (long *)FUN_fffffff009c498d4(plVar3,*_DAT_fffffff00806c9f0);
      if (plVar4 != (long *)0x0) {
        lVar5 = (**(code **)(*plVar4 + 0x118))(plVar4,0);
        lVar6 = (**(code **)(*plVar4 + 0x118))(plVar4,1);
        puVar1 = _DAT_fffffff00806ca10;
        if (lVar5 == 0) {
          plVar4 = (long *)0x0;
        }
        else {
          plVar4 = (long *)FUN_fffffff009c498d4(lVar5,*_DAT_fffffff00806ca10);
        }
        if ((((lVar6 != 0) &&
             (plVar7 = (long *)FUN_fffffff009c498d4(lVar6,*puVar1), plVar4 != (long *)0x0)) &&
            (plVar7 != (long *)0x0)) &&
           (plVar8 = (long *)FUN_fffffff009c49a84(*(undefined8 *)(param_2 + 2),0x40),
           plVar8 != (long *)0x0)) {
          uVar10 = (**(code **)(*plVar4 + 0xa8))(plVar4);
          uVar9 = (**(code **)(*plVar7 + 0xa8))(plVar7);
          uVar10 = FUN_fffffff009c25af4(plVar2,uVar10,uVar9,plVar8);
          (**(code **)(*plVar8 + 0x28))(plVar8);
        }
      }
      (**(code **)(*plVar3 + 0x28))(plVar3);
    }
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  return uVar10;
}

