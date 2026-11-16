// FUN_fffffff009a1ed60 @ fffffff009a1ed60 size=624 depth=1
// CALLERS:
//   fffffff00afe78a3 ?
//   fffffff009a1df08 FUN_fffffff009a1df00
// CALLS:
//   fffffff009a4881c thunk_FUN_fffffff00a8df19c
//   fffffff0099cb890 FUN_fffffff0099cb890
//   fffffff009a4885c thunk_FUN_fffffff00a209048
//   fffffff009a4805c thunk_FUN_fffffff00a902074
//   fffffff009a47fec thunk_FUN_fffffff00a22170c
//   fffffff009a1e974 FUN_fffffff009a1e974

/* WARNING: Removing unreachable block (ram,0xfffffff009a1eec4) */

undefined8
FUN_fffffff009a1ed60
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,long *param_7,long param_8)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 *puVar5;
  long *plVar6;
  short *psVar7;
  undefined8 *puVar8;
  undefined8 uVar9;
  undefined8 *puVar10;
  code *pcVar11;
  long lVar12;
  undefined8 extraout_d0;
  undefined8 extraout_d0_00;
  undefined8 uVar13;
  undefined8 extraout_var;
  undefined8 extraout_var_00;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  long *local_60;
  code *pcStack_58;
  undefined8 *local_50;
  undefined1 *local_48;
  
  uVar14 = param_2._8_8_;
  uVar13 = param_2._0_8_;
  if (param_7[0x1d] == 0) {
    psVar7 = (short *)FUN_fffffff0099cb890(0);
    auVar1._8_8_ = extraout_var;
    auVar1._0_8_ = extraout_d0;
    auVar3._8_8_ = uVar14;
    auVar3._0_8_ = uVar13;
    thunk_FUN_fffffff00a8df19c
              (auVar1,auVar3,param_3,param_4,param_5,param_6,&MACH_HEADER,psVar7,0x10,
               (byte *)"failed : device is NULL\n");
    uVar9 = 0xe00002cd;
  }
  else {
    plVar6 = FUN_fffffff009a1e974(param_7,param_8);
    if (plVar6 == (long *)0x0) {
      uVar9 = 0xe00002bd;
      psVar7 = (short *)FUN_fffffff0099cb890(0);
      auVar2._8_8_ = extraout_var_00;
      auVar2._0_8_ = extraout_d0_00;
      auVar4._8_8_ = uVar14;
      auVar4._0_8_ = uVar13;
      thunk_FUN_fffffff00a8df19c
                (auVar2,auVar4,param_3,param_4,param_5,param_6,&MACH_HEADER,psVar7,0x10,
                 (byte *)"failed : could not create descriptor\n");
    }
    else {
      local_48 = &DAT_aaaaaaaaaaaaaaaa;
      puVar5 = (undefined1 *)**(undefined8 **)(param_8 + 0x20);
      if ((undefined1 *)**(undefined8 **)(param_8 + 0x20) == (undefined1 *)0x0) {
        thunk_FUN_fffffff00a209048((long *)&local_48);
        puVar5 = local_48;
      }
      local_48 = puVar5;
      *(int *)((long)param_7 + 0x164) = *(int *)((long)param_7 + 0x164) + 1;
      if (*(long *)(param_8 + 8) == 0) {
        uVar9 = (**(code **)(*(long *)param_7[0x1d] + 0x628))
                          ((long *)param_7[0x1d],local_48,plVar6,0,0);
        pcVar11 = *(code **)(*plVar6 + 0x28);
      }
      else {
        puVar8 = (undefined8 *)thunk_FUN_fffffff00a902074((long *)&DAT_fffffff008015fd0);
        if (puVar8 == (undefined8 *)0x0) {
          uVar9 = 0xe00002bd;
        }
        else {
          (**(code **)(*param_7 + 0x20))(param_7);
          puVar10 = *(undefined8 **)(param_8 + 0x10);
          uVar14 = puVar10[1];
          uVar13 = *puVar10;
          uVar15 = puVar10[3];
          uVar9 = puVar10[2];
          uVar16 = puVar10[4];
          uVar18 = puVar10[7];
          uVar17 = puVar10[6];
          puVar8[5] = puVar10[5];
          puVar8[4] = uVar16;
          puVar8[7] = uVar18;
          puVar8[6] = uVar17;
          puVar8[1] = uVar14;
          *puVar8 = uVar13;
          puVar8[3] = uVar15;
          puVar8[2] = uVar9;
          *(undefined4 *)(puVar8 + 8) = *(undefined4 *)(param_8 + 0x18);
          pcStack_58 = FUN_fffffff009a1ecb8;
          lVar12 = *(long *)param_7[0x1d];
          local_60 = param_7;
          local_50 = puVar8;
          uVar9 = (**(code **)(lVar12 + 0x638))
                            (lVar12 + 0x638,(long *)param_7[0x1d],local_48,plVar6,0,0,0,&local_60);
          (**(code **)(*plVar6 + 0x28))(plVar6);
          if ((int)uVar9 == 0) {
            return uVar9;
          }
          thunk_FUN_fffffff00a22170c((long *)&DAT_fffffff008016010,puVar8);
          plVar6 = param_7;
        }
        pcVar11 = *(code **)(*plVar6 + 0x28);
      }
      (*pcVar11)(plVar6);
    }
  }
  return uVar9;
}

