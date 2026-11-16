// FUN_fffffff00820dd08 @ fffffff00820dd08 size=544

undefined8 FUN_fffffff00820dd08(long param_1,undefined8 param_2,long *param_3)

{
  int iVar1;
  long *plVar2;
  undefined8 uVar3;
  long lVar4;
  
  iVar1 = (**(code **)(PTR_DAT_fffffff007ca6180 + 0x78))();
  if (iVar1 == 0) {
    return 0;
  }
  *(undefined8 *)(param_1 + 0x10) = param_2;
  *(undefined8 *)(param_1 + 0x38) = 0;
  *(undefined8 *)(param_1 + 0x40) = 0;
  (**(code **)(*param_3 + 0x20))(param_3);
  *(long **)(param_1 + 0x18) = param_3;
  plVar2 = (long *)thunk_EXT_FUN_801100000392ef4c("CoreAnalyticsHub",0);
  uVar3 = thunk_EXT_FUN_801100000392eb04
                    (*(undefined8 *)PTR_DAT_fffffff007ca61c8,plVar2,FUN_fffffff00820e654,param_1,0,0
                    );
  *(undefined8 *)(param_1 + 0x28) = uVar3;
  lVar4 = thunk_EXT_FUN_801100000396100c(2,param_1,FUN_fffffff00820df28);
  *(long *)(param_1 + 0x30) = lVar4;
  if (lVar4 == 0) {
    if (*(long **)(param_1 + 0x28) != (long *)0x0) {
      (**(code **)(**(long **)(param_1 + 0x28) + 0x78))();
      *(undefined8 *)(param_1 + 0x28) = 0;
    }
  }
  else {
    iVar1 = (**(code **)(**(long **)(param_1 + 0x18) + 0xa0))(*(long **)(param_1 + 0x18),lVar4);
    if (iVar1 == 0) {
      (**(code **)(**(long **)(param_1 + 0x30) + 0xf0))(*(long **)(param_1 + 0x30),60000);
      uVar3 = 1;
      goto joined_r0xfffffff00820df20;
    }
    if (*(long **)(param_1 + 0x28) != (long *)0x0) {
      (**(code **)(**(long **)(param_1 + 0x28) + 0x78))();
      *(undefined8 *)(param_1 + 0x28) = 0;
    }
    if (*(long **)(param_1 + 0x30) != (long *)0x0) {
      (**(code **)(**(long **)(param_1 + 0x30) + 0x28))();
    }
    *(undefined8 *)(param_1 + 0x30) = 0;
  }
  if (*(long **)(param_1 + 0x18) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x18) + 0x28))();
  }
  uVar3 = 0;
  *(undefined8 *)(param_1 + 0x18) = 0;
joined_r0xfffffff00820df20:
  if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  return uVar3;
}

