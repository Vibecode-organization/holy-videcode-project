// FUN_fffffff0097b8848 @ fffffff0097b8848 size=4 depth=0
// CALLERS:
//   fffffff00afe2a97 ?
//   fffffff007f95880 ?
// CALLS:

undefined8 FUN_fffffff0097b8848(void)

{
  bool bVar1;
  undefined8 uVar2;
  long *plVar3;
  undefined8 uVar4;
  long lVar5;
  mach_header *pmVar6;
  uint extraout_w1;
  undefined8 extraout_x1;
  undefined8 in_x2;
  long extraout_x8;
  long extraout_x16;
  long extraout_x16_00;
  long extraout_x16_01;
  long extraout_x16_02;
  long extraout_x16_03;
  long extraout_x16_04;
  long extraout_x16_05;
  long unaff_x20;
  undefined8 uVar7;
  undefined1 extraout_q0 [16];
  undefined1 in_q1 [16];
  undefined4 in_s2;
  undefined4 in_s3;
  undefined4 in_s4;
  undefined4 in_s5;
  undefined1 auStack_48 [8];
  
  FUN_fffffff009791db8();
  if (extraout_x8 == 0) {
    uVar2 = 0xe00002c2;
  }
  else {
    uVar2 = FUN_fffffff009791d68();
    uVar2 = (**(code **)(extraout_x16 + 0xb0))(uVar2,auStack_48);
    if ((int)uVar2 == 0) {
      FUN_fffffff009791dc8();
    }
  }
  uVar7 = *(undefined8 *)(unaff_x20 + 0xf8);
  FUN_fffffff00976b640();
  FUN_fffffff0097908f8();
  plVar3 = (long *)(**(code **)(extraout_x16_00 + 0x10))(uVar7);
  uVar4 = FUN_fffffff009791d14();
  bVar1 = FUN_fffffff009791d3c((uint)uVar4,extraout_w1,in_x2,plVar3);
  if (bVar1) {
    return uVar2;
  }
  FUN_fffffff009790920();
  lVar5 = (**(code **)(extraout_x16_01 + 0x10))(uVar7);
  if (lVar5 != 0) {
    FUN_fffffff00975f88c();
    lVar5 = (**(code **)(extraout_x16_02 + 0x10))(uVar7);
    lVar5 = thunk_FUN_fffffff00a912bc0(lVar5);
    if (lVar5 != 0) {
      FUN_fffffff00975f88c();
      plVar3 = (long *)(**(code **)(extraout_x16_03 + 0x10))(uVar7);
      (**(code **)(*plVar3 + 0x1e8))(plVar3,0);
      goto LAB_fffffff0097b89ac;
    }
  }
  FUN_fffffff00975f88c();
  lVar5 = (**(code **)(extraout_x16_04 + 0x10))(uVar7);
  if (lVar5 == 0) {
    FUN_fffffff009790940();
  }
  else {
    FUN_fffffff00975f88c();
    plVar3 = (long *)(**(code **)(extraout_x16_05 + 0x10))(uVar7);
    lVar5 = (**(code **)(*plVar3 + 0x38))();
    thunk_FUN_fffffff00a895b28(lVar5);
    FUN_fffffff0097909cc();
  }
LAB_fffffff0097b89ac:
  FUN_fffffff009751ba0();
  FUN_fffffff00976b640();
  pmVar6 = FUN_fffffff00979090c();
  FUN_fffffff009751d58
            (extraout_q0,in_q1,in_s2,in_s3,in_s4,in_s5,pmVar6,extraout_x1,in_x2,
             (byte *)"IOAV[%d] %s<0x%llx>::%s: ret = 0x%08x\n");
  return uVar2;
}

