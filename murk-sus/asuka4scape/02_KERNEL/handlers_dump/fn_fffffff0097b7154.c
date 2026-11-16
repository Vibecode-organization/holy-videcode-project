// FUN_fffffff0097b7154 @ fffffff0097b7154 size=4 depth=0
// CALLERS:
//   fffffff00afe2a88 ?
//   fffffff007f95088 ?
// CALLS:

undefined8 FUN_fffffff0097b7154(long param_1,undefined8 param_2,long param_3)

{
  bool bVar1;
  undefined8 uVar2;
  long *plVar3;
  undefined8 uVar4;
  long lVar5;
  mach_header *pmVar6;
  uint extraout_w1;
  undefined8 extraout_x1;
  long lVar7;
  undefined8 in_x5;
  undefined8 in_x6;
  byte *in_x7;
  long extraout_x16;
  long extraout_x16_00;
  long extraout_x16_01;
  long extraout_x16_02;
  long extraout_x16_03;
  long extraout_x16_04;
  long extraout_x16_05;
  undefined8 uVar8;
  undefined1 extraout_q0 [16];
  undefined1 in_q1 [16];
  undefined4 in_s2;
  undefined4 in_s3;
  undefined4 in_s4;
  undefined4 in_s5;
  undefined8 uStack_48;
  
  uStack_48 = 0;
  lVar7 = param_3;
  if (*(long *)(param_3 + 0x78) == 0) {
    uVar2 = 0xe00002c2;
  }
  else {
    uVar2 = FUN_fffffff00973d8cc();
    uVar2 = (**(code **)(extraout_x16 + 0x20))(uVar2,&uStack_48);
    if ((int)uVar2 == 0) {
      **(undefined8 **)(param_3 + 0x78) = uStack_48;
    }
  }
  uVar8 = *(undefined8 *)(param_1 + 0xf8);
  FUN_fffffff00976b640();
  FUN_fffffff0097908f8();
  plVar3 = (long *)(**(code **)(extraout_x16_00 + 0x10))(uVar8);
  uVar4 = FUN_fffffff0097908e0();
  bVar1 = FUN_fffffff009751ca0
                    ((uint)uVar4,extraout_w1,lVar7,plVar3,"_copyPhysicalAddress",in_x5,in_x6,in_x7);
  if (bVar1) {
    return uVar2;
  }
  FUN_fffffff009790920();
  lVar5 = (**(code **)(extraout_x16_01 + 0x10))(uVar8);
  if (lVar5 != 0) {
    FUN_fffffff00975f88c();
    lVar5 = (**(code **)(extraout_x16_02 + 0x10))(uVar8);
    lVar5 = thunk_FUN_fffffff00a912bc0(lVar5);
    if (lVar5 != 0) {
      FUN_fffffff00975f88c();
      plVar3 = (long *)(**(code **)(extraout_x16_03 + 0x10))(uVar8);
      (**(code **)(*plVar3 + 0x1e8))(plVar3,0);
      goto LAB_fffffff0097b72d4;
    }
  }
  FUN_fffffff00975f88c();
  lVar5 = (**(code **)(extraout_x16_04 + 0x10))(uVar8);
  if (lVar5 == 0) {
    FUN_fffffff009790940();
  }
  else {
    FUN_fffffff00975f88c();
    plVar3 = (long *)(**(code **)(extraout_x16_05 + 0x10))(uVar8);
    lVar5 = (**(code **)(*plVar3 + 0x38))();
    thunk_FUN_fffffff00a895b28(lVar5);
    FUN_fffffff0097909cc();
  }
LAB_fffffff0097b72d4:
  FUN_fffffff00976b640();
  pmVar6 = FUN_fffffff00979090c();
  FUN_fffffff009751d58
            (extraout_q0,in_q1,in_s2,in_s3,in_s4,in_s5,pmVar6,extraout_x1,lVar7,
             (byte *)"IOAV[%d] %s<0x%llx>::%s: ret = 0x%08x\n");
  return uVar2;
}

