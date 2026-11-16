// FUN_fffffff009c2302c @ fffffff009c2302c

/* WARNING: Removing unreachable block (ram,0xfffffff009c23090) */

void FUN_fffffff009c2302c
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
               uint param_8,undefined8 param_9,undefined8 param_10,undefined8 param_11,
               undefined8 param_12,ulong param_13)

{
  ulong *puVar1;
  ulong uVar2;
  ulong uVar3;
  int iVar4;
  undefined1 auVar5 [16];
  code *pcVar6;
  bool bVar7;
  bool bVar8;
  int iVar9;
  uint uVar10;
  ulong uVar11;
  ulong uVar12;
  ulong unaff_x30;
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 extraout_q0_01 [16];
  undefined1 auVar13 [16];
  undefined4 uVar14;
  undefined1 auVar15 [12];
  undefined4 uVar16;
  undefined1 auVar17 [12];
  
  uVar16 = param_4._0_4_;
  auVar17 = param_4._4_12_;
  uVar14 = param_3._0_4_;
  auVar15 = param_3._4_12_;
  if (param_8 < 2) {
    do {
      if ((*(byte *)(param_7 + 0x3d2) >> 5 & 1) != 0) {
        uVar11 = thunk_FUN_fffffff00a725814();
        if (uVar11 == 0) {
          iVar9 = -1;
          auVar13 = extraout_q0_00;
        }
        else {
          iVar9 = thunk_FUN_fffffff00a724f30(uVar11);
          thunk_FUN_fffffff00a724838(uVar11);
          auVar13 = extraout_q0_01;
        }
        iVar4 = *(int *)(param_7 + 0x3d4);
        bVar7 = iVar4 != DAT_fffffff00af48590;
        bVar8 = iVar9 != DAT_fffffff00af48594;
        if (bVar7 || bVar8) {
          DAT_fffffff00af48590 = iVar4;
          DAT_fffffff00af48594 = iVar9;
        }
        if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
          FUN_fffffff009c231e4(auVar13,param_2,uVar14,uVar16,param_5,param_6,(uint)(bVar7 || bVar8))
          ;
          return;
        }
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c231e0);
        (*pcVar6)();
      }
      do {
        uVar12 = *(ulong *)(*(long *)(param_7 + 0x178) + 0x18);
        uVar11 = 0;
        if (uVar12 >> 0x20 != 0) {
          uVar11 = (uVar12 & 0xffffffff00000000) - 0x100000000;
        }
        uVar10 = (int)uVar12 - 1;
        uVar2 = 0;
        if ((int)uVar12 != 0) {
          uVar2 = (ulong)uVar10;
        }
        uVar3 = 0xffffffff;
        bVar7 = (uVar12 & 0xffffffff00000000) == 0x100000000;
        if (param_8 == 0) {
          uVar3 = 0xffffffff00000000;
          bVar7 = uVar10 == 0;
          uVar11 = uVar2;
        }
        uVar11 = uVar11 | uVar3 & uVar12;
        puVar1 = (ulong *)(*(long *)(param_7 + 0x178) + 0x18);
      } while (*puVar1 != uVar12);
      *puVar1 = uVar11;
      bVar8 = false;
      if (uVar11 == 0) {
        bVar8 = bVar7;
      }
      if (bVar8) {
        uVar10 = *(uint *)(param_7 + 0x3d0);
        if ((uVar10 >> 6 & 1) != 0) {
          thunk_FUN_fffffff00a2262a8(*(ulong *)(param_7 + 0x50));
          *(uint *)(param_7 + 0x3d0) = *(uint *)(param_7 + 0x3d0) & 0xfffffff3;
          param_1 = thunk_FUN_fffffff00a226de0(*(ulong *)(param_7 + 0x50));
          uVar10 = *(uint *)(param_7 + 0x3d0);
        }
        if ((uVar10 >> 7 & 1) != 0) {
          param_1 = FUN_fffffff009c23234(param_7);
        }
        auVar13._4_12_ = auVar15;
        auVar13._0_4_ = uVar14;
        auVar5._4_12_ = auVar17;
        auVar5._0_4_ = uVar16;
        FUN_fffffff009c35a60
                  (param_1,param_2,auVar13,auVar5,param_5,param_6,DAT_fffffff00af483b0,0,param_7,
                   param_10,param_11,param_12,param_13);
        param_1 = extraout_q0;
      }
      param_7 = *(long *)(param_7 + 0x378);
    } while (param_7 != 0);
  }
  return;
}

