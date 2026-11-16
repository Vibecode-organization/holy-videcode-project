// FUN_fffffff0099d50f8 @ fffffff0099d50f8 size=492 depth=1
// CALLERS:
//   fffffff00afe6fe0 ?
//   fffffff0099d2b90 FUN_fffffff0099d2b74
// CALLS:
//   fffffff0099d52e4 FUN_fffffff0099d52e4
//   fffffff009a4881c thunk_FUN_fffffff00a8df19c
//   fffffff009a487fc thunk_FUN_fffffff00a92d93c
//   fffffff0099cb890 FUN_fffffff0099cb890
//   fffffff009a483ac thunk_FUN_fffffff00a912bc0
//   fffffff009a4806c thunk_FUN_fffffff00a9025cc
//   fffffff009a47fdc thunk_FUN_fffffff00a9026b0

undefined8
FUN_fffffff0099d50f8
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long *param_7,int param_8,
          long *param_9,uint *param_10,undefined *param_11)

{
  undefined1 auVar1 [16];
  uint uVar2;
  undefined **extraout_x0;
  undefined8 uVar3;
  uint *puVar4;
  short *psVar5;
  undefined **ppuVar6;
  uint *puVar7;
  undefined8 uVar8;
  ulong *puVar9;
  uint *puVar10;
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 auVar11 [16];
  undefined1 extraout_q0_01 [16];
  undefined4 uVar12;
  undefined1 auVar13 [12];
  undefined4 uVar14;
  undefined1 auVar15 [12];
  uint local_64;
  
  uVar14 = param_4._0_4_;
  auVar15 = param_4._4_12_;
  uVar12 = param_3._0_4_;
  auVar13 = param_3._4_12_;
  uVar8 = 0xe00002d9;
  if ((param_7[0x1b] != 0) && (uVar2 = thunk_FUN_fffffff00a92d93c(param_7), (uVar2 & 1) == 0)) {
    uVar8 = (**(code **)(*param_9 + 0xd8))(param_9,0);
    if ((int)uVar8 == 0) {
      local_64 = (**(code **)(*param_9 + 0xb0))(param_9);
      uVar8 = 0xe00002c2;
      if (local_64 != 0) {
        puVar9 = (ulong *)(ulong)local_64;
        auVar11._4_12_ = auVar13;
        auVar11._0_4_ = uVar12;
        auVar1._4_12_ = auVar15;
        auVar1._0_4_ = uVar14;
        thunk_FUN_fffffff00a9025cc(extraout_q0,param_2,auVar11,auVar1,param_5,param_6,puVar9);
        if (extraout_x0 == (undefined **)0x0) {
          uVar8 = 0xe00002bd;
        }
        else {
          puVar7 = &local_64;
          ppuVar6 = extraout_x0;
          uVar3 = FUN_fffffff0099d52e4(param_7,param_8,extraout_x0,puVar7);
          puVar10 = (uint *)(ulong)local_64;
          if (param_10 != (uint *)0x0) {
            *param_10 = local_64;
          }
          puVar4 = (uint *)(**(code **)(*param_9 + 0xb0))(param_9);
          auVar11 = extraout_q0_00;
          if (puVar10 <= puVar4) {
            ppuVar6 = extraout_x0;
            auVar11 = (**(code **)(*param_9 + 0xd0))(param_9,0);
            puVar7 = puVar10;
            uVar8 = uVar3;
          }
          thunk_FUN_fffffff00a9026b0
                    (auVar11,param_2,uVar12,uVar14,param_5,param_6,extraout_x0,(undefined *)puVar9,
                     ppuVar6,puVar7,param_11);
        }
      }
      (**(code **)(*param_9 + 0xe0))(param_9,0);
      if ((int)uVar8 == 0) {
        return uVar8;
      }
    }
    psVar5 = (short *)FUN_fffffff0099cb890(0);
    (**(code **)(*param_7 + 0x1e8))(param_7,0);
    thunk_FUN_fffffff00a912bc0((long)param_7);
    thunk_FUN_fffffff00a8df19c
              (extraout_q0_01,param_2,uVar12,uVar14,param_5,param_6,&MACH_HEADER,psVar5,0x10,
               (byte *)"%s:0x%llx getElements failed: 0x%x\n\n");
  }
  return uVar8;
}

