// FUN_fffffff009a456d8 @ fffffff009a456d8 size=4 depth=0
// CALLERS:
//   fffffff00afe7cdd ?
//   fffffff0080120a8 ?
// CALLS:

undefined8 FUN_fffffff009a456d8(long *param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined8 uVar4;
  long *plVar5;
  long lVar6;
  ulong uVar7;
  ulong uVar8;
  short *psVar9;
  undefined8 in_x3;
  undefined *in_x4;
  long extraout_x16;
  long extraout_x16_00;
  long extraout_x16_01;
  long extraout_x16_02;
  long extraout_x16_03;
  long extraout_x16_04;
  long extraout_x16_05;
  long *plVar10;
  undefined8 uVar11;
  undefined1 in_q0 [16];
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 in_q1 [16];
  undefined4 in_s2;
  undefined1 in_register_00005044 [12];
  undefined4 in_s3;
  undefined1 in_register_00005064 [12];
  undefined4 in_s4;
  undefined4 in_s5;
  long *plStack_58;
  
  uVar11 = 0xe00002bd;
  plStack_58 = (long *)0x0;
  uVar1 = *(uint *)(param_3 + 0x38);
  if (uVar1 >> 0x11 != 0) {
    return 0xe00002bd;
  }
  plVar10 = (long *)0x0;
  if ((uVar1 != 0) && (*(long *)(param_3 + 0x30) != 0)) {
    auVar2._4_12_ = in_register_00005044;
    auVar2._0_4_ = in_s2;
    auVar3._4_12_ = in_register_00005064;
    auVar3._0_4_ = in_s3;
    plVar10 = FUN_fffffff009a15438
                        (in_q0,in_q1,auVar2,auVar3,in_s4,in_s5,*(long *)(param_3 + 0x30),
                         (ulong)uVar1,param_3,in_x3,in_x4);
  }
  if (*(long *)(param_3 + 0x68) == 0) {
    lVar6 = *(long *)(param_3 + 0x58);
    if (lVar6 == 0) {
      psVar9 = (short *)FUN_fffffff0099cb890(0);
      thunk_FUN_fffffff00a8df19c
                (extraout_q0_00,in_q1,in_s2,in_s3,in_s4,in_s5,&MACH_HEADER,psVar9,0x10,
                 (byte *)"_copyEvent: No output data\n");
      uVar4 = 0xe00002bc;
      goto LAB_fffffff009a45934;
    }
    plVar5 = (long *)0x0;
    uVar7 = (ulong)*(uint *)(param_3 + 0x60);
LAB_fffffff009a457d4:
    uVar11 = (**(code **)(*param_1 + 0x5e8))
                       (param_1,**(undefined4 **)(param_3 + 0x20),plVar10,&plStack_58,
                        (*(undefined4 **)(param_3 + 0x20))[2]);
    if ((int)uVar11 == 0) {
      FUN_fffffff0099cd400();
      uVar8 = (**(code **)(extraout_x16_03 + 0xe0))();
      if (uVar7 < uVar8) {
        psVar9 = (short *)FUN_fffffff0099cb890(0);
        thunk_FUN_fffffff00a8df19c
                  (extraout_q0,in_q1,in_s2,in_s3,in_s4,in_s5,&MACH_HEADER,psVar9,0x10,
                   (byte *)"event length:%d expected:%ld\n");
        uVar11 = 0xe00002c2;
      }
      else {
        uVar11 = FUN_fffffff0099cd400();
        (**(code **)(extraout_x16_04 + 0xe8))(uVar11,lVar6,uVar7);
        if (*(long *)(param_3 + 0x68) == 0) {
          uVar11 = 0;
          *(int *)(param_3 + 0x60) = (int)uVar8;
        }
        else {
          uVar11 = 0;
          *(int *)(param_3 + 0x70) = (int)uVar8;
        }
      }
    }
    uVar4 = uVar11;
    if (*(long *)(param_3 + 0x68) == 0) goto LAB_fffffff009a45934;
    if (plVar5 != (long *)0x0) {
      (**(code **)(*plVar5 + 0x28))(plVar5);
    }
  }
  else {
    uVar4 = FUN_fffffff0099cd400();
    uVar4 = (**(code **)(extraout_x16 + 0xd8))(uVar4,0);
    if ((int)uVar4 != 0) goto LAB_fffffff009a45934;
    uVar4 = FUN_fffffff0099cd400();
    plVar5 = (long *)(**(code **)(extraout_x16_00 + 0xe8))(uVar4,0);
    if (plVar5 != (long *)0x0) {
      FUN_fffffff0099cd400();
      lVar6 = (**(code **)(extraout_x16_01 + 0x78))();
      FUN_fffffff0099cd400();
      uVar7 = (**(code **)(extraout_x16_02 + 0xb0))();
      goto LAB_fffffff009a457d4;
    }
    uVar4 = uVar11;
    if (*(long *)(param_3 + 0x68) == 0) goto LAB_fffffff009a45934;
  }
  uVar4 = FUN_fffffff0099cd400();
  (**(code **)(extraout_x16_05 + 0xe0))(uVar4,0);
  uVar4 = uVar11;
LAB_fffffff009a45934:
  if (plVar10 != (long *)0x0) {
    (**(code **)(*plVar10 + 0x28))(plVar10);
  }
  if (plStack_58 != (long *)0x0) {
    (**(code **)(*plStack_58 + 0x28))();
  }
  return uVar4;
}

