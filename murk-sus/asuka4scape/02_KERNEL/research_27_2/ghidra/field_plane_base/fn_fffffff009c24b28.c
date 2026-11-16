// FUN_fffffff009c24b28 @ fffffff009c24b28

/* WARNING: Removing unreachable block (ram,0xfffffff009c24ba8) */

byte FUN_fffffff009c24b28
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,
               undefined4 param_4,undefined4 param_5,undefined4 param_6,long param_7,long *param_8,
               long *param_9,int *param_10)

{
  byte bVar1;
  undefined1 auVar2 [16];
  undefined1 uVar3;
  int iVar4;
  long *plVar5;
  undefined8 extraout_d0;
  undefined8 extraout_d0_00;
  undefined8 extraout_d0_01;
  undefined8 extraout_d0_02;
  undefined8 extraout_d0_03;
  undefined8 uVar6;
  undefined8 extraout_var;
  undefined8 extraout_var_00;
  undefined8 extraout_var_01;
  undefined8 extraout_var_02;
  undefined8 extraout_var_03;
  undefined8 uVar7;
  undefined *local_b0;
  undefined8 local_a8;
  undefined1 *local_a0;
  undefined *local_98;
  undefined8 *puStack_90;
  undefined8 *local_88;
  long lStack_80;
  undefined8 local_78;
  undefined8 *local_70;
  undefined8 local_68;
  undefined1 local_60;
  undefined8 local_58;
  undefined8 *local_50;
  undefined8 local_48;
  undefined1 local_40;
  long local_38;
  
  local_38 = *(long *)PTR_DAT_fffffff00806ca40;
  local_50 = &local_58;
  local_58 = 0;
  local_48 = DAT_fffffff0078a1288;
  local_40 = 0;
  local_70 = &local_78;
  local_78 = 0;
  local_68 = DAT_fffffff0078a1288;
  local_60 = 0;
  iVar4 = (*(uint *)(*(long *)(param_7 + 0x178) + 0x20) | 1) + 2;
  *(int *)(*(long *)(param_7 + 0x178) + 0x20) = iVar4;
  *param_10 = iVar4;
  if ((*(long *)(param_7 + 0x1a8) == 0) &&
     (FUN_fffffff009c20460(param_7), *(long *)(param_7 + 0x1a8) == 0)) {
    *(undefined1 *)(local_50 + 3) = 0;
    uVar6 = extraout_d0;
    uVar7 = extraout_var;
  }
  else if (param_8 == (long *)0x0) {
    plVar5 = thunk_FUN_fffffff00a894f30(param_9,*(long *)PTR_PTR_fffffff00806c9c8);
    uVar6 = extraout_d0_01;
    uVar7 = extraout_var_01;
    if (plVar5 != (long *)0x0) {
      local_b0 = PTR_DAT_fffffff00806c9b8;
      local_a8 = DAT_fffffff0078a1290;
      local_a0 = &LAB_fffffff009c24dd4;
      puStack_90 = &local_58;
      local_98 = &DAT_fffffff008067268;
      local_88 = &local_78;
      lStack_80 = param_7;
      thunk_FUN_fffffff00a8a1600((long)plVar5,(long)&local_b0);
      uVar6 = extraout_d0_02;
      uVar7 = extraout_var_02;
    }
  }
  else {
    iVar4 = (**(code **)(*param_8 + 0xb8))(param_8,"CreationProperties");
    if (iVar4 == 0) {
      iVar4 = (**(code **)(*param_8 + 0xb8))(param_8,"IOSurfaceName");
      if (iVar4 != 0) {
        *(undefined1 *)(local_70 + 3) = 1;
      }
      uVar3 = (**(code **)(**(long **)(param_7 + 0x1a8) + 0xf0))
                        (*(long **)(param_7 + 0x1a8),param_8,param_9);
      *(undefined1 *)(local_50 + 3) = uVar3;
      uVar6 = extraout_d0_03;
      uVar7 = extraout_var_03;
    }
    else {
      *(undefined1 *)(local_50 + 3) = 1;
      uVar6 = extraout_d0_00;
      uVar7 = extraout_var_00;
    }
  }
  auVar2._8_8_ = uVar7;
  auVar2._0_8_ = uVar6;
  auVar2 = FUN_fffffff009c23c30(auVar2,param_2,param_3,param_4,param_5,param_6,param_7,0);
  FUN_fffffff009c23c94(auVar2,param_2,param_3,param_4,param_5,param_6,param_7);
  if ((((*(byte *)(local_70 + 3) & 1) != 0) && (*(long *)(param_7 + 0x30) != 0)) &&
     (*(long *)(param_7 + 0x378) == 0)) {
    plVar5 = FUN_fffffff009c2cf30(param_7);
    thunk_FUN_fffffff00a97ba94(*(long *)(param_7 + 0x30),(long)plVar5);
    if (plVar5 != (long *)0x0) {
      (**(code **)(*plVar5 + 0x28))(plVar5);
    }
  }
  bVar1 = *(byte *)(local_50 + 3);
  thunk_FUN_fffffff00a8eddac((long)&local_78,8);
  thunk_FUN_fffffff00a8eddac((long)&local_58,8);
  if (*(long *)PTR_DAT_fffffff00806ca40 != local_38) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_fffffff00aa4c590();
  }
  return bVar1 & 1;
}

