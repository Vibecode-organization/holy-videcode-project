// FUN_fffffff009caa418 @ fffffff009caa418

long FUN_fffffff009caa418
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,
               undefined4 param_4,undefined4 param_5,undefined4 param_6,long *param_7,int param_8,
               long *param_9,undefined8 param_10,undefined1 *param_11)

{
  undefined1 auVar1 [16];
  bool bVar2;
  int iVar3;
  long lVar4;
  undefined8 *puVar5;
  short *psVar6;
  undefined1 extraout_b0;
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
  undefined1 *local_50;
  undefined1 *puStack_48;
  undefined8 local_40;
  undefined4 local_34;
  
  if (param_8 - 2U < 4) {
    local_34 = 1;
    puStack_48 = &DAT_aaaaaaaaaaaaaaaa;
    local_50 = &DAT_aaaaaaaaaaaaaaaa;
    if (param_11 == (undefined1 *)0x0) {
      puStack_48 = (undefined1 *)0x0;
      local_50 = (undefined1 *)0x0;
    }
    else {
      local_40 = param_10;
      iVar3 = (**(code **)(*param_9 + 0xb8))(param_9,&local_40,&local_50,&local_34);
      if (iVar3 != 0) {
        if ((param_7 != (long *)0x0) && ((*(uint *)(param_7 + 9) & 1) != 0)) {
          if (((*(uint *)(param_7 + 9) >> 0x1e & 1) == 0) ||
             (bVar2 = thunk_FUN_fffffff00a394140(), !bVar2)) {
            psVar6 = *(short **)PTR_DAT_fffffff008081388;
            lVar4 = (**(code **)(*param_7 + 0x38))(param_7);
            thunk_FUN_fffffff00a895b28(lVar4);
            auVar1[1] = extraout_var;
            auVar1[0] = extraout_b0;
            auVar1[2] = extraout_var_00;
            auVar1[3] = extraout_var_01;
            auVar1[4] = extraout_var_02;
            auVar1[5] = extraout_var_03;
            auVar1[6] = extraout_var_04;
            auVar1[7] = extraout_var_05;
            auVar1[8] = extraout_var_06;
            auVar1[9] = extraout_var_07;
            auVar1[10] = extraout_var_08;
            auVar1[0xb] = extraout_var_09;
            auVar1[0xc] = extraout_var_10;
            auVar1[0xd] = extraout_var_11;
            auVar1[0xe] = extraout_var_12;
            auVar1[0xf] = extraout_var_13;
            thunk_FUN_fffffff00a8df19c
                      (auVar1,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,psVar6,0,
                       (byte *)"%s: %s::%s: failed to generate IOVM segments, result: 0x%x");
          }
          else {
            lVar4 = (**(code **)(*param_7 + 0x38))(param_7);
            thunk_FUN_fffffff00a895b28(lVar4);
            thunk_FUN_fffffff00a9029a0
                      ((byte *)"%s: %s::%s: failed to generate IOVM segments, result: 0x%x");
          }
        }
        goto LAB_fffffff009caa564;
      }
    }
    if (puStack_48 <= param_11) {
      param_11 = puStack_48;
    }
    puVar5 = (undefined8 *)param_7[3];
    *puVar5 = local_50;
    *(undefined1 **)param_7[6] = local_50;
    if ((undefined1 *)0xfffffe < param_11) {
      param_11 = (undefined1 *)0xffffff;
    }
    *(int *)(puVar5 + 1) = (int)param_11;
    DataMemoryBarrier(2,3);
    *(uint *)(param_7[3] + 0xc) = param_8 << 4 | 0xc03;
    DataMemoryBarrier(2,3);
    param_7[8] = (long)param_11;
    *(undefined4 *)((long)param_7 + 0x3c) = 1;
  }
LAB_fffffff009caa564:
  return param_7[8];
}

