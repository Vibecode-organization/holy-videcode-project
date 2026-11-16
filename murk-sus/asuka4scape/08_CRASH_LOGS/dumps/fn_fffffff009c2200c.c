// FUN_fffffff009c2200c @ fffffff009c2200c size=308
// CALLERS:
//   fffffff00afebd17 no-fn
//   fffffff009c1e99c FUN_fffffff009c1e624@fffffff009c1e624
//   fffffff009c1ea10 FUN_fffffff009c1e624@fffffff009c1e624
// CALLEES:
//   fffffff009c49be4 thunk_FUN_fffffff00a29b7b0
//   fffffff009c49c64 thunk_FUN_fffffff00a344acc
//   fffffff009c49b64 thunk_FUN_fffffff00aa4c590

undefined8
FUN_fffffff009c2200c
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,ulong param_8,
          ulong param_9,undefined4 *param_10)

{
  undefined1 auVar1 [16];
  bool bVar2;
  ulong uVar3;
  undefined **ppuVar4;
  undefined8 uVar5;
  ulong uVar6;
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
  uint local_94;
  long local_90;
  ulong local_88;
  undefined8 local_80;
  undefined1 *puStack_78;
  undefined1 *puStack_70;
  undefined1 *puStack_68;
  undefined4 local_60;
  long local_58;
  
  uVar6 = 0;
  local_58 = *(long *)PTR_DAT_fffffff00806ca40;
  local_90 = 0;
  local_88 = param_8;
  do {
    local_94 = 9;
    local_60 = 0xaaaaaaaa;
    puStack_78 = &DAT_aaaaaaaaaaaaaaaa;
    local_80 = &DAT_aaaaaaaaaaaaaaaa;
    puStack_68 = &DAT_aaaaaaaaaaaaaaaa;
    puStack_70 = &DAT_aaaaaaaaaaaaaaaa;
    if (local_90 != 0) {
      uVar6 = local_88 + local_90;
      local_90 = 0;
      local_88 = uVar6;
    }
    uVar3 = thunk_FUN_fffffff00a29b7b0(param_7);
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
    ppuVar4 = thunk_FUN_fffffff00a344acc
                        (auVar1,param_2,param_3,param_4,param_5,param_6,uVar3,&local_88,&local_90,9,
                         (uint *)&local_80,&local_94,(undefined8 *)0x0);
    if ((int)ppuVar4 != 0) {
LAB_fffffff009c22100:
      uVar5 = 0xe00002c8;
      goto LAB_fffffff009c22108;
    }
    bVar2 = local_88 <= param_8;
    if (uVar6 != 0) {
      bVar2 = uVar6 == local_88;
    }
    if ((!bVar2) || (((byte)local_80 >> 2 & 1) != 0)) goto LAB_fffffff009c22100;
    if ((local_80._4_1_ >> 1 & 1) == 0) {
      *param_10 = 2;
    }
  } while (local_90 + local_88 < param_9);
  uVar5 = 0;
LAB_fffffff009c22108:
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_58) {
    return uVar5;
  }
                    /* WARNING: Subroutine does not return */
  thunk_FUN_fffffff00aa4c590();
}

