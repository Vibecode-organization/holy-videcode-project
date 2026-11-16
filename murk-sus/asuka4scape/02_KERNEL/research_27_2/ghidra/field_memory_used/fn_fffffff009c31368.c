// FUN_fffffff009c31368 @ fffffff009c31368

undefined8
FUN_fffffff009c31368
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7)

{
  undefined8 uVar1;
  long lVar2;
  long *plVar3;
  undefined8 uVar4;
  undefined1 extraout_q0 [16];
  undefined1 auVar5 [16];
  
  uVar1 = (**(code **)(PTR_DAT_fffffff00806ca38 + 0xb8))();
  lVar2 = thunk_FUN_fffffff00a39bc88();
  *(long *)(param_7 + 0x438) = lVar2;
  DAT_fffffff00af48598 = 0x100000000000000;
  DAT_fffffff00af483b0 = param_7;
  plVar3 = thunk_FUN_fffffff00a89a1f4(4);
  if (*(long **)(param_7 + 0x220) != (long *)0x0) {
    (**(code **)(**(long **)(param_7 + 0x220) + 0x28))();
  }
  *(long **)(param_7 + 0x220) = plVar3;
  uVar4 = thunk_FUN_fffffff00a903010();
  *(undefined8 *)(param_7 + 0x228) = uVar4;
  uVar4 = thunk_FUN_fffffff00a903010();
  *(undefined8 *)(param_7 + 0x150) = uVar4;
  uVar4 = thunk_FUN_fffffff00a903010();
  *(undefined8 *)(param_7 + 0x230) = uVar4;
  uVar4 = thunk_FUN_fffffff00a903010();
  *(undefined8 *)(param_7 + 1000) = uVar4;
  auVar5 = thunk_FUN_fffffff00a744c44
                     (extraout_q0,param_2,param_3,param_4,param_5,param_6,&PTR_DAT_fffffff00af48060)
  ;
  auVar5 = thunk_FUN_fffffff00a744c44
                     (auVar5,param_2,param_3,param_4,param_5,param_6,&PTR_DAT_fffffff00af480b0);
  auVar5 = thunk_FUN_fffffff00a902750
                     (auVar5,param_2,param_3,param_4,param_5,param_6,0xfffffff00806c060,
                      (ulong *)0x200);
  *(long *)(param_7 + 0x428) = auVar5._0_8_;
  *(undefined8 *)(param_7 + 0x420) = 0x20;
  lVar2 = thunk_FUN_fffffff00a39bc88();
  *(long *)(param_7 + 0x440) = lVar2;
  return uVar1;
}

