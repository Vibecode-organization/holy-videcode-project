// FUN_fffffff0081ab1c8 @ fffffff0081ab1c8 size=844

undefined8 FUN_fffffff0081ab1c8(long *param_1,ulong param_2,long param_3)

{
  uint uVar1;
  ulong uVar2;
  int iVar3;
  long *plVar4;
  long *plVar5;
  undefined8 uVar6;
  long lVar7;
  ulong uVar8;
  long lVar9;
  
  *param_1 = param_3;
  lVar9 = param_1[4];
  uVar1 = *(uint *)PTR_DAT_fffffff007ca5f88;
  plVar4 = (long *)(**(code **)(DAT_fffffff00ae22f20 + 0x68))();
  if (plVar4 == (long *)0x0) {
    return 0;
  }
  lVar7 = (long)(1 << (ulong)(uVar1 & 0x1f));
  uVar8 = (lVar7 + lVar9 * (param_2 & 0xffffffff)) - 1 & -lVar7;
  uVar1 = *(uint *)(param_3 + 0x18b70);
  plVar4[2] = *(long *)PTR_DAT_fffffff007ca61d0;
  iVar3 = FUN_fffffff0081e07cc(plVar4,param_3,uVar8,uVar1 | 0x23);
  if (iVar3 != 0) {
    lVar9 = thunk_EXT_FUN_8011000002971b4c(param_3);
    plVar5 = (long *)plVar4[0xb];
    if (plVar5 == (long *)0x0) {
      plVar5 = (long *)(**(code **)(*(long *)plVar4[9] + 0x90))((long *)plVar4[9],lVar9,0x500000085)
      ;
      if (plVar5 == (long *)0x0) goto LAB_fffffff0081ab4c4;
      (**(code **)(*plVar5 + 0x20))();
      (**(code **)(*plVar5 + 0x28))(plVar5);
      plVar4[0xb] = (long)plVar5;
    }
    if (plVar5[4] != lVar9) {
      uVar6 = thunk_EXT_FUN_8011000003a49114
                        ("AGXk: %s:%d:%s: !!! Attempting to map into multiple GPU Contexts!\n");
      return uVar6;
    }
    lVar9 = (**(code **)(*plVar5 + 0x98))();
    if (lVar9 != 0) {
      plVar5 = (long *)plVar4[10];
      if (plVar5 == (long *)0x0) {
        plVar5 = (long *)(**(code **)(*(long *)plVar4[9] + 0x90))
                                   ((long *)plVar4[9],plVar4[3],0x20900000084);
        if (plVar5 == (long *)0x0) goto LAB_fffffff0081ab4c4;
        (**(code **)(*plVar5 + 0x20))();
        (**(code **)(*plVar5 + 0x28))(plVar5);
        plVar4[10] = (long)plVar5;
      }
      lVar9 = (**(code **)(*plVar5 + 0x98))();
      if (lVar9 != 0) {
        plVar5 = (long *)plVar4[0xc];
        if (plVar5 == (long *)0x0) {
          lVar9 = thunk_EXT_FUN_801100000297ea14(plVar4[9],0);
          plVar4[0xc] = lVar9;
          if (lVar9 == 0) goto LAB_fffffff0081ab4c4;
          LOAcquire();
          DAT_fffffff00ae22f48 = DAT_fffffff00ae22f48 + plVar4[6];
          LORelease();
          plVar5 = (long *)plVar4[0xc];
        }
        lVar9 = (**(code **)(*plVar5 + 0x78))();
        if (lVar9 != 0) {
          param_1[1] = (long)plVar4;
          lVar9 = (**(code **)(*(long *)plVar4[0xc] + 0x78))();
          param_1[2] = lVar9;
          if (lVar9 != 0) {
            uVar2 = 0;
            if (param_1[4] != 0) {
              uVar2 = uVar8 / (ulong)param_1[4];
            }
            *(int *)(param_1 + 5) = (int)uVar2;
            lVar9 = thunk_EXT_FUN_80110000038fe5cc(uVar2 & 0xffffffff);
            param_1[3] = lVar9;
            if (lVar9 != 0) {
              return 1;
            }
            param_1[2] = 0;
          }
          (**(code **)(*(long *)param_1[1] + 0x28))();
          param_1[1] = 0;
          return 0;
        }
      }
    }
  }
LAB_fffffff0081ab4c4:
  (**(code **)(*plVar4 + 0x28))(plVar4);
  return 0;
}

