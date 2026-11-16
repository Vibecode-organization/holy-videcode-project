// FUN_fffffff009c5b768 @ fffffff009c5b768

undefined8
FUN_fffffff009c5b768
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long *param_7,long *param_8)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  code *pcVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  ulong unaff_x30;
  undefined1 extraout_q0 [16];
  undefined1 auVar8 [16];
  undefined4 uVar9;
  undefined1 auVar10 [12];
  undefined4 uVar11;
  undefined1 auVar12 [12];
  
  uVar11 = param_4._0_4_;
  auVar12 = param_4._4_12_;
  uVar9 = param_3._0_4_;
  auVar10 = param_3._4_12_;
  if (param_8 == (long *)0x0) {
    uVar5 = FUN_fffffff009c7ad50(param_1,param_2,uVar9,uVar11,param_5,param_6);
    return uVar5;
  }
  thunk_FUN_fffffff00a2262a8(param_7[0x1a]);
  if (((*(byte *)(param_7 + 0x21) & 1) == 0) || ((*(byte *)((long)param_7 + 0x109) & 1) != 0)) {
    thunk_FUN_fffffff00a226de0(param_7[0x1a]);
    *(int *)((long)param_7 + 0x194) = *(int *)((long)param_7 + 0x194) + 1;
    FUN_fffffff009c63f2c(param_8);
    *(int *)(param_7 + 0x33) = (int)param_7[0x33] + 1;
  }
  else {
    puVar4 = (undefined8 *)thunk_FUN_fffffff00a902074((long *)&DAT_fffffff00807a7a0);
    if (puVar4 == (undefined8 *)0x0) {
      uVar5 = FUN_fffffff009c7ace0
                        (extraout_q0,param_2,uVar9,uVar11,param_5,param_6,param_8,
                         (ulong *)(param_7 + 0x1a));
      return uVar5;
    }
    *puVar4 = 0;
    puVar4[1] = param_8;
    thunk_FUN_fffffff00a2262a8(param_7[0x2f]);
    *(int *)(param_7 + 0x32) = (int)param_7[0x32] + 1;
    puVar7 = (undefined8 *)param_7[0x2d];
    if ((undefined8 *)param_7[0x2d] == (undefined8 *)0x0) {
      param_7[0x2d] = (long)puVar4;
    }
    else {
      do {
        puVar6 = puVar7;
        puVar7 = (undefined8 *)*puVar6;
      } while (puVar7 != (undefined8 *)0x0);
      *puVar6 = puVar4;
    }
    auVar8 = thunk_FUN_fffffff00a226de0(param_7[0x2f]);
    auVar1._4_12_ = auVar10;
    auVar1._0_4_ = uVar9;
    auVar2._4_12_ = auVar12;
    auVar2._0_4_ = uVar11;
    thunk_FUN_fffffff00a25ae9c(auVar8,param_2,auVar1,auVar2,param_5,param_6,param_7[0x25]);
    thunk_FUN_fffffff00a226de0(param_7[0x1a]);
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c5b85c);
    (*pcVar3)();
  }
  if ((*(byte *)(param_7 + 0x30) & 1) != 1) {
    (**(code **)(*param_7 + 0xd8))(param_7,"gPTPPresent",1);
    (**(code **)(*param_7 + 0x2a0))(param_7,0);
    (**(code **)(*param_7 + 0x430))(param_7,0xe0000130,0,0);
    *(undefined1 *)(param_7 + 0x30) = 1;
  }
  return 0;
}

