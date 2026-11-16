// FUN_fffffff009196114 @ fffffff009196114 size=584 depth=1
// CALLERS:
//   fffffff00afdb4a6 ?
//   fffffff009183fb0 FUN_fffffff009183f7c
//   fffffff009184004 FUN_fffffff009183fc4
//   fffffff009184058 FUN_fffffff009184018
// CALLS:
//   fffffff0091b2c2c FUN_fffffff0091b2c2c
//   fffffff0091b8c50 thunk_FUN_fffffff00aa4c590
//   fffffff0091b8720 thunk_FUN_fffffff00a9029a0
//   fffffff00919635c FUN_fffffff00919635c
//   fffffff0091b2c64 FUN_fffffff0091b2c64
//   fffffff009182a64 FUN_fffffff009182a64
//   fffffff0091b8930 thunk_FUN_fffffff00a960120
//   fffffff009182858 FUN_fffffff009182858

undefined8
FUN_fffffff009196114
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long *param_7,long *param_8,
          undefined1 (*param_9) [16],long param_10,undefined8 param_11)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  int iVar4;
  undefined4 uVar5;
  long *plVar6;
  undefined8 *puVar7;
  undefined8 uVar8;
  long extraout_x0;
  long *plVar9;
  undefined8 extraout_d0;
  undefined8 extraout_d0_00;
  undefined8 extraout_d0_01;
  undefined8 extraout_d0_02;
  undefined8 uVar10;
  undefined8 extraout_var;
  undefined8 extraout_var_00;
  undefined8 extraout_var_01;
  undefined8 extraout_var_02;
  undefined8 uVar11;
  undefined *local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined *local_70;
  long *plStack_68;
  ulong local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  long local_48;
  
  local_48 = *(long *)PTR_DAT_fffffff007ed2e00;
  uVar8 = param_11;
  plVar6 = (long *)(**(code **)(*param_7 + 0x548))(param_1._0_8_);
  local_88 = PTR_DAT_fffffff007ed2d20;
  local_80 = DAT_fffffff0076d7f38;
  local_78 = 0xfffffff0091962c4;
  local_70 = &DAT_fffffff007ece570;
  plStack_68 = param_7;
  iVar4 = thunk_FUN_fffffff00a960120(plVar6,&local_88);
  if (iVar4 == 0) {
    if ((param_7[0x1c] == 0) && (*(int *)((long)param_7 + 0xdc) == 2)) {
      uStack_58 = *(undefined8 *)(*param_9 + 8);
      local_60 = *(ulong *)*param_9;
      local_50 = *(undefined8 *)param_9[1];
      puVar7 = FUN_fffffff009182858
                         (*param_9,param_2,param_3,param_4,param_5,param_6,param_8,&local_60,
                          param_7[0x30],(int)param_10);
      param_7[0x1c] = (long)puVar7;
      if (puVar7 == (undefined8 *)0x0) {
        auVar2._8_8_ = extraout_var_00;
        auVar2._0_8_ = extraout_d0_00;
        FUN_fffffff0091b2c64(auVar2,param_2,param_3,param_4,param_5,param_6);
        plVar6 = *(long **)(extraout_x0 + 0x20);
        iVar4 = *(int *)((long)plVar6 + 0xdc);
        while (iVar4 == 0) {
          plVar9 = (long *)(**(code **)(*plVar6 + 0x548))(plVar6);
          (**(code **)(*plVar9 + 0x100))(plVar9,(int *)((long)plVar6 + 0xdc),0);
          iVar4 = *(int *)((long)plVar6 + 0xdc);
        }
        return 0;
      }
      uVar5 = FUN_fffffff009182a64((long)puVar7);
      *(undefined4 *)((long)param_7 + 0x1c4) = uVar5;
      uVar10 = extraout_d0_01;
      uVar11 = extraout_var_01;
      if (((uint)*(undefined8 *)(param_9[1] + 8) & 0xff) != 0xff) {
        *(char *)(param_7 + 0x34) = (char)*(undefined8 *)(param_9[1] + 8);
        thunk_FUN_fffffff00a9029a0((byte *)"%s: %s set SEP slot id to %u\n\n");
        uVar10 = extraout_d0_02;
        uVar11 = extraout_var_02;
      }
      auVar3._8_8_ = uVar11;
      auVar3._0_8_ = uVar10;
      uVar8 = FUN_fffffff00919635c
                        (auVar3,param_2,param_3,param_4,param_5,param_6,param_7,(char)param_11,0,
                         param_10,uVar8);
    }
    else {
      thunk_FUN_fffffff00a9029a0((byte *)"AppleSEP:WARNING: SEP firmware reload attempted\n");
      uVar8 = 0xe00002d5;
    }
    if (*(long *)PTR_DAT_fffffff007ed2e00 == local_48) {
      return uVar8;
    }
  }
  else {
    auVar1._8_8_ = extraout_var;
    auVar1._0_8_ = extraout_d0;
    FUN_fffffff0091b2c2c(auVar1,param_2,param_3,param_4,param_5,param_6);
  }
                    /* WARNING: Subroutine does not return */
  thunk_FUN_fffffff00aa4c590();
}

