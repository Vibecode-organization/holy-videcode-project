// FUN_fffffff0081686b8 @ fffffff0081686b8 size=684

undefined8 FUN_fffffff0081686b8(long param_1,undefined8 param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  long *plVar3;
  long lVar4;
  long *plVar5;
  undefined8 uVar6;
  
  plVar3 = (long *)(**(code **)(DAT_fffffff00ae22f20 + 0x68))();
  if (plVar3 == (long *)0x0) {
    return 0;
  }
  uVar1 = *(uint *)(param_1 + 0x18b70);
  plVar3[2] = *(long *)PTR_DAT_fffffff007ca61d0;
  iVar2 = FUN_fffffff0081e07cc(plVar3,param_1,param_2,uVar1 | 0x23);
  if (iVar2 != 0) {
    lVar4 = thunk_EXT_FUN_8011000002971b4c(param_1);
    plVar5 = (long *)plVar3[0xb];
    if (plVar5 == (long *)0x0) {
      plVar5 = (long *)(**(code **)(*(long *)plVar3[9] + 0x90))((long *)plVar3[9],lVar4,0x500000087)
      ;
      if (plVar5 == (long *)0x0) goto LAB_fffffff008168914;
      (**(code **)(*plVar5 + 0x20))();
      (**(code **)(*plVar5 + 0x28))(plVar5);
      plVar3[0xb] = (long)plVar5;
    }
    if (plVar5[4] != lVar4) {
      uVar6 = thunk_EXT_FUN_8011000003a49114
                        ("AGXk: %s:%d:%s: !!! Attempting to map into multiple GPU Contexts!\n");
      return uVar6;
    }
    lVar4 = (**(code **)(*plVar5 + 0x98))();
    if (lVar4 != 0) {
      if (param_3 != 0) {
        plVar5 = (long *)plVar3[10];
        if (plVar5 == (long *)0x0) {
          plVar5 = (long *)(**(code **)(*(long *)plVar3[9] + 0x90))
                                     ((long *)plVar3[9],plVar3[3],0x800000084);
          if (plVar5 == (long *)0x0) goto LAB_fffffff008168914;
          (**(code **)(*plVar5 + 0x20))();
          (**(code **)(*plVar5 + 0x28))(plVar5);
          plVar3[10] = (long)plVar5;
        }
        lVar4 = (**(code **)(*plVar5 + 0x98))();
        if (lVar4 == 0) goto LAB_fffffff008168914;
      }
      plVar5 = (long *)plVar3[0xc];
      if (plVar5 == (long *)0x0) {
        lVar4 = thunk_EXT_FUN_801100000297ea14(plVar3[9],0);
        plVar3[0xc] = lVar4;
        if (lVar4 == 0) goto LAB_fffffff008168914;
        LOAcquire();
        DAT_fffffff00ae22f48 = DAT_fffffff00ae22f48 + plVar3[6];
        LORelease();
        plVar5 = (long *)plVar3[0xc];
      }
      lVar4 = (**(code **)(*plVar5 + 0x78))();
      if (lVar4 != 0) {
        *(long **)(param_1 + 0x115b0) = plVar3;
        return 1;
      }
    }
  }
LAB_fffffff008168914:
  (**(code **)(*plVar3 + 0x28))(plVar3);
  return 0;
}

