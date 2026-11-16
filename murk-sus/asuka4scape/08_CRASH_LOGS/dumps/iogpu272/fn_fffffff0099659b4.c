// FUN_fffffff0099659b4 @ fffffff0099659b4 size=320

undefined8
FUN_fffffff0099659b4
          (long *param_1,uint param_2,undefined8 param_3,undefined8 *param_4,undefined4 *param_5,
          int *param_6)

{
  int iVar1;
  undefined4 uVar2;
  long *plVar3;
  long *plVar4;
  undefined8 uVar5;
  
  if (param_2 < 0x10000001) {
    plVar3 = (long *)(**(code **)(*param_1 + 0xa8))(param_1,param_1[10],param_2,param_3);
    if (plVar3 == (long *)0x0) {
      uVar5 = 0xe00002bd;
      *param_4 = 0;
      *param_5 = 0;
      *param_6 = 0;
    }
    else {
      iVar1 = thunk_FUN_fffffff009944798(param_1[0xf],plVar3);
      *param_6 = iVar1;
      if (iVar1 == 0) {
        uVar5 = 0xe00002bd;
        *param_4 = 0;
        *param_5 = 0;
        *param_6 = 0;
      }
      else {
        uVar5 = FUN_fffffff009952080(plVar3);
        *param_4 = uVar5;
        plVar4 = (long *)FUN_fffffff009952138(plVar3);
        uVar2 = (**(code **)(*plVar4 + 0x88))();
        uVar5 = 0;
        *param_5 = uVar2;
      }
      (**(code **)(*plVar3 + 0x28))(plVar3);
    }
  }
  else {
    *param_4 = 0;
    *param_5 = 0;
    *param_6 = 0;
    uVar5 = 0xe00002be;
  }
  return uVar5;
}

