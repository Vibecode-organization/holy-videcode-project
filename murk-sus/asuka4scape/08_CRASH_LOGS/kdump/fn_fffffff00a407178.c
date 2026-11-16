// FUN_fffffff00a407178 @ fffffff00a407178 size=544
// CALLERS:
//   fffffff00afba3e8 ?
//   fffffff00a6f95b0 FUN_fffffff00a6f9560@fffffff00a6f9560
//   fffffff00a4073b0 FUN_fffffff00a407398@fffffff00a407398
// CALLS:
//   fffffff00a6f0e50 FUN_fffffff00a6f0e50
//   fffffff00a6f8740 FUN_fffffff00a6f8740
//   fffffff00a3e8aa8 FUN_fffffff00a3e8aa8
//   fffffff00a738b50 FUN_fffffff00a738b50
//   fffffff00a6efa94 FUN_fffffff00a6efa94
//   fffffff00a407004 FUN_fffffff00a407004
//   fffffff00a7c094c FUN_fffffff00a7c094c
//   fffffff00a3ec1d8 FUN_fffffff00a3ec1d8
//   fffffff00a29b24c FUN_fffffff00a29b24c
//   fffffff00a7341bc FUN_fffffff00a7341bc

ulong FUN_fffffff00a407178
                (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
                undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,ulong param_7,
                uint param_8,ulong param_9,undefined8 *param_10,undefined4 **param_11)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  ulong uVar4;
  undefined **ppuVar5;
  undefined8 extraout_x1;
  undefined8 extraout_x1_00;
  undefined8 uVar6;
  undefined **ppuVar7;
  long lVar8;
  undefined8 *puVar9;
  long *plVar10;
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 extraout_q0_01 [16];
  undefined1 auVar11 [16];
  undefined1 extraout_q0_02 [16];
  undefined1 extraout_q0_03 [16];
  undefined *local_48;
  
  if ((long)param_9 < 0) {
    return 0x16;
  }
  uVar4 = FUN_fffffff00a7341bc(param_7,1);
  if (uVar4 < param_9) {
    FUN_fffffff00a738b50(param_7,0,(long *)0x0,(ulong *)0x0,0x19,(long **)0x0);
    return 0x1b;
  }
  local_48 = (undefined *)0x0;
  if (param_10 == (undefined8 *)0x0) {
    ppuVar7 = &local_48;
    ppuVar5 = (undefined **)0x0;
    uVar4 = FUN_fffffff00a6efa94(param_7,param_8,ppuVar7,0);
    iVar2 = (int)uVar4;
    auVar11 = extraout_q0_00;
  }
  else {
    ppuVar7 = (undefined **)*param_10;
    ppuVar5 = &local_48;
    param_11 = (undefined4 **)0x0;
    uVar4 = FUN_fffffff00a6f8740(param_7,param_8,(long)ppuVar7,ppuVar5,0);
    iVar2 = (int)uVar4;
    auVar11 = extraout_q0;
  }
  if (iVar2 != 0) {
    return uVar4;
  }
  plVar10 = (long *)(local_48 + 0x10);
  lVar8 = *plVar10;
  if (**(int **)(lVar8 + 0x28) == 1) {
    puVar9 = *(undefined8 **)(lVar8 + 0x38);
    if (puVar9 == (undefined8 *)0x0) {
      puVar9 = (undefined8 *)0x0;
      bVar1 = *(byte *)(lVar8 + 0x10);
    }
    else {
      bVar1 = *(byte *)(lVar8 + 0x10);
    }
    if ((bVar1 >> 1 & 1) != 0) {
      uVar3 = FUN_fffffff00a3ec1d8((ulong)puVar9);
      uVar4 = (ulong)uVar3;
      auVar11 = extraout_q0_02;
      if (uVar3 == 0) {
        uVar6 = extraout_x1;
        if (*(char *)((long)puVar9 + 0x71) == '\x05') {
          uVar4 = 0x16;
        }
        else if ((*(byte *)(puVar9 + 0xe) >> 3 & 1) == 0) {
          ppuVar7 = *(undefined ***)(*plVar10 + 0x20);
          if (ppuVar7 == (undefined **)0x0) {
            ppuVar7 = (undefined **)0x0;
          }
          ppuVar5 = (undefined **)FUN_fffffff00a29b24c();
          param_11 = (undefined4 **)0x0;
          uVar4 = FUN_fffffff00a407004((ulong)puVar9,param_9,ppuVar7,ppuVar5,0);
          uVar6 = extraout_x1_00;
          if ((int)uVar4 == 0) {
            *(uint *)(*plVar10 + 0x10) = *(uint *)(*plVar10 + 0x10) | 0x10000;
          }
        }
        else {
          uVar4 = 1;
        }
        FUN_fffffff00a3e8aa8(puVar9,uVar6,ppuVar7,ppuVar5,param_11);
        auVar11 = extraout_q0_03;
      }
      goto LAB_fffffff00a4072b4;
    }
  }
  else if (**(int **)(lVar8 + 0x28) == 3) {
    uVar3 = FUN_fffffff00a7c094c
                      (auVar11,param_2,param_3,param_4,param_5,param_6,uVar4,(long)local_48,ppuVar7,
                       param_9);
    uVar4 = (ulong)uVar3;
    auVar11 = extraout_q0_01;
    goto LAB_fffffff00a4072b4;
  }
  uVar4 = 0x16;
LAB_fffffff00a4072b4:
  FUN_fffffff00a6f0e50(auVar11,param_2,param_3,param_4,param_5,param_6,param_8);
  return uVar4;
}

