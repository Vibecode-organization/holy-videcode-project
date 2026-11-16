// FUN_fffffff009cc7118 @ fffffff009cc7118

/* WARNING: Removing unreachable block (ram,0xfffffff009cc7394) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cc73e4) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cc7348) */

undefined8
FUN_fffffff009cc7118
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,long *param_7)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  undefined4 uVar3;
  bool bVar4;
  long lVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  short *psVar8;
  undefined1 extraout_b0;
  undefined1 extraout_b0_00;
  undefined1 extraout_var;
  undefined1 extraout_var_00;
  undefined1 extraout_var_01;
  undefined1 extraout_var_02;
  undefined1 extraout_var_03;
  undefined1 extraout_var_04;
  undefined1 extraout_var_05;
  undefined1 extraout_var_06;
  undefined1 extraout_var_07;
  undefined1 extraout_var_08;
  undefined1 extraout_var_09;
  undefined1 extraout_var_10;
  undefined1 extraout_var_11;
  undefined1 extraout_var_12;
  undefined1 extraout_var_13;
  undefined1 extraout_var_14;
  undefined1 extraout_var_15;
  undefined1 extraout_var_16;
  undefined1 extraout_var_17;
  undefined1 extraout_var_18;
  undefined1 extraout_var_19;
  undefined1 extraout_var_20;
  undefined1 extraout_var_21;
  undefined1 extraout_var_22;
  undefined1 extraout_var_23;
  undefined1 extraout_var_24;
  undefined1 extraout_var_25;
  undefined1 extraout_var_26;
  undefined1 extraout_var_27;
  undefined1 extraout_var_28;
  undefined8 local_50;
  undefined1 *puStack_48;
  undefined4 local_3c;
  undefined8 local_38;
  
  if ((param_7 != (long *)0x0) && ((*(uint *)((long)param_7 + 0x44) >> 2 & 1) != 0)) {
    if (((*(uint *)((long)param_7 + 0x44) >> 0x1e & 1) == 0) ||
       (bVar4 = thunk_FUN_fffffff00a394140(), !bVar4)) {
      psVar8 = *(short **)PTR_DAT_fffffff008081388;
      lVar5 = (**(code **)(*param_7 + 0x38))(param_7);
      thunk_FUN_fffffff00a895b28(lVar5);
      auVar1[1] = extraout_var;
      auVar1[0] = extraout_b0;
      auVar1[2] = extraout_var_01;
      auVar1[3] = extraout_var_03;
      auVar1[4] = extraout_var_05;
      auVar1[5] = extraout_var_07;
      auVar1[6] = extraout_var_09;
      auVar1[7] = extraout_var_11;
      auVar1[8] = extraout_var_13;
      auVar1[9] = extraout_var_15;
      auVar1[10] = extraout_var_17;
      auVar1[0xb] = extraout_var_19;
      auVar1[0xc] = extraout_var_21;
      auVar1[0xd] = extraout_var_23;
      auVar1[0xe] = extraout_var_25;
      auVar1[0xf] = extraout_var_27;
      thunk_FUN_fffffff00a8df19c
                (auVar1,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,psVar8,0,
                 (byte *)"%s: %s::%s: \n");
    }
    else {
      lVar5 = (**(code **)(*param_7 + 0x38))(param_7);
      thunk_FUN_fffffff00a895b28(lVar5);
      thunk_FUN_fffffff00a9029a0((byte *)"%s: %s::%s: \n");
    }
  }
  puVar6 = (undefined8 *)(**(code **)(*(long *)param_7[5] + 0x148))();
  thunk_FUN_fffffff00aa65cc0(puVar6,0x800);
  *(undefined4 *)(param_7 + 8) = 0;
  local_38 = 0;
  local_3c = 1;
  puStack_48 = &DAT_aaaaaaaaaaaaaaaa;
  local_50 = &DAT_aaaaaaaaaaaaaaaa;
  uVar7 = (**(code **)(*(long *)param_7[6] + 0xb8))
                    ((long *)param_7[6],&local_38,&local_50,&local_3c);
  if ((int)uVar7 == 0) {
    uVar3 = local_50._4_4_;
    (**(code **)(*(long *)param_7[4] + 0x7f8))
              ((long *)param_7[4],(int)param_7[3] * 0x10 + 0x400,(ulong)local_50 & 0xffffffff);
    (**(code **)(*(long *)param_7[4] + 0x7f8))
              ((long *)param_7[4],(int)param_7[3] * 0x10 + 0x404,uVar3);
    (**(code **)(*(long *)param_7[4] + 0x7f8))
              ((long *)param_7[4],(int)param_7[3] * 0x10 + 0x408,0x80000800);
    (**(code **)(*(long *)param_7[4] + 0x7f8))((long *)param_7[4],(int)param_7[3] * 0x10 + 0x40c,0);
  }
  else if ((*(uint *)((long)param_7 + 0x44) & 1) != 0) {
    if (((*(uint *)((long)param_7 + 0x44) >> 0x1e & 1) == 0) ||
       (bVar4 = thunk_FUN_fffffff00a394140(), !bVar4)) {
      psVar8 = *(short **)PTR_DAT_fffffff008081388;
      lVar5 = (**(code **)(*param_7 + 0x38))(param_7);
      thunk_FUN_fffffff00a895b28(lVar5);
      auVar2[1] = extraout_var_00;
      auVar2[0] = extraout_b0_00;
      auVar2[2] = extraout_var_02;
      auVar2[3] = extraout_var_04;
      auVar2[4] = extraout_var_06;
      auVar2[5] = extraout_var_08;
      auVar2[6] = extraout_var_10;
      auVar2[7] = extraout_var_12;
      auVar2[8] = extraout_var_14;
      auVar2[9] = extraout_var_16;
      auVar2[10] = extraout_var_18;
      auVar2[0xb] = extraout_var_20;
      auVar2[0xc] = extraout_var_22;
      auVar2[0xd] = extraout_var_24;
      auVar2[0xe] = extraout_var_26;
      auVar2[0xf] = extraout_var_28;
      thunk_FUN_fffffff00a8df19c
                (auVar2,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,psVar8,0,
                 (byte *)"%s: %s::%s: failed to generation IOVM segments, result: 0x%x\n");
    }
    else {
      lVar5 = (**(code **)(*param_7 + 0x38))(param_7);
      thunk_FUN_fffffff00a895b28(lVar5);
      thunk_FUN_fffffff00a9029a0
                ((byte *)"%s: %s::%s: failed to generation IOVM segments, result: 0x%x\n");
    }
  }
  return uVar7;
}

