// FUN_fffffff009c3d908 @ fffffff009c3d908 size=112
// CALLERS:
//   fffffff00afec0f4 ?
//   fffffff009c39688 FUN_fffffff009c3967c@fffffff009c3967c
// CALLS:
//   fffffff009c3f1d0 FUN_fffffff009c3f1d0
//   fffffff009c23a14 FUN_fffffff009c23a14
//   fffffff009c237e8 FUN_fffffff009c237e8

undefined8
FUN_fffffff009c3d908
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,uint param_8)

{
  long *plVar1;
  undefined8 uVar2;
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar4 = param_4._0_4_;
  uVar3 = param_3._0_4_;
  plVar1 = FUN_fffffff009c3f1d0(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  if (plVar1 == (long *)0x0) {
    uVar2 = 0xe00002c2;
  }
  else {
    uVar2 = FUN_fffffff009c237e8(extraout_q0,param_2,uVar3,uVar4,param_5,param_6,(long)plVar1);
    if ((int)uVar2 == 0) {
      FUN_fffffff009c23a14(extraout_q0_00,param_2,uVar3,uVar4,param_5,param_6,(long)plVar1);
    }
    (**(code **)(*plVar1 + 0x28))(plVar1);
  }
  return uVar2;
}

