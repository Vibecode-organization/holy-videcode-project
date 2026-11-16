// FUN_fffffff0081681b8 @ fffffff0081681b8 size=4

undefined8 FUN_fffffff0081681b8(long param_1,long *param_2,undefined8 param_3)

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
  iVar2 = FUN_fffffff0081e07cc(plVar3,param_1,param_3,uVar1 | 0x23);
  if (iVar2 != 0) {
    lVar4 = thunk_EXT_FUN_8011000002971b4c(param_1);
    plVar5 = (long *)plVar3[0xb];
    if (plVar5 == (long *)0x0) {
      plVar5 = (long *)(**(code **)(*(long *)plVar3[9] + 0x90))((long *)plVar3[9],lVar4,0x500000087)
      ;
      if (plVar5 == (long *)0x0) goto LAB_fffffff0081683b4;
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
      plVar5 = (long *)plVar3[10];
      if (plVar5 == (long *)0x0) {
        plVar5 = (long *)(**(code **)(*(long *)plVar3[9] + 0x90))
                                   ((long *)plVar3[9],plVar3[3],0x20900000084);
        if (plVar5 == (long *)0x0) goto LAB_fffffff0081683b4;
        (**(code **)(*plVar5 + 0x20))();
        (**(code **)(*plVar5 + 0x28))(plVar5);
        plVar3[10] = (long)plVar5;
      }
      lVar4 = (**(code **)(*plVar5 + 0x98))();
      if (lVar4 != 0) {
        *param_2 = (long)plVar3;
        return 1;
      }
    }
  }
LAB_fffffff0081683b4:
  (**(code **)(*plVar3 + 0x28))(plVar3);
  return 0;
}

