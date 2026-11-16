// FUN_fffffff009c2c18c @ fffffff009c2c18c size=1372
// CALLERS:
//   fffffff00afebe59 no-fn
//   fffffff009c3ae9c FUN_fffffff009c3ab8c@fffffff009c3ab8c
//   fffffff009c3b500 FUN_fffffff009c3b3ac@fffffff009c3b3ac
//   fffffff009c3b714 FUN_fffffff009c3b628@fffffff009c3b628
//   fffffff009c3b968 FUN_fffffff009c3b7b0@fffffff009c3b7b0
//   fffffff009c3bd84 FUN_fffffff009c3bb20@fffffff009c3bb20
//   fffffff009c3c1bc FUN_fffffff009c3bf44@fffffff009c3bf44
// CALLEES:
//   fffffff009c49b94 thunk_FUN_fffffff00aa65cc0
//   fffffff009c2c6e8 FUN_fffffff009c2c6e8
//   fffffff009c48f64 FUN_fffffff009c48f64
//   fffffff009c48f50 FUN_fffffff009c48f50
//   fffffff009c20364 FUN_fffffff009c20364
//   fffffff009c48f28 FUN_fffffff009c48f28
//   fffffff009c491c8 FUN_fffffff009c491c8

/* WARNING: Removing unreachable block (ram,0xfffffff009c2c264) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c2c1e0) */

void FUN_fffffff009c2c18c
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
               undefined8 *param_8)

{
  undefined1 (*pauVar1) [16];
  undefined8 *puVar2;
  uint uVar3;
  uint uVar4;
  byte bVar5;
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  undefined1 auVar13 [16];
  undefined1 auVar14 [16];
  undefined1 auVar15 [16];
  undefined1 auVar16 [16];
  undefined1 auVar17 [16];
  undefined1 auVar18 [16];
  undefined1 auVar19 [16];
  undefined1 auVar20 [16];
  undefined1 auVar21 [16];
  undefined1 auVar22 [16];
  undefined1 auVar23 [16];
  undefined1 auVar24 [16];
  undefined1 auVar25 [16];
  undefined1 auVar26 [16];
  undefined1 auVar27 [16];
  undefined1 auVar28 [16];
  undefined1 auVar29 [16];
  undefined1 auVar30 [16];
  undefined1 auVar31 [16];
  undefined1 auVar32 [16];
  undefined1 auVar33 [16];
  undefined1 auVar34 [16];
  undefined1 auVar35 [16];
  undefined1 auVar36 [16];
  undefined1 auVar37 [16];
  undefined1 auVar38 [16];
  undefined1 auVar39 [16];
  undefined1 auVar40 [16];
  undefined1 auVar41 [16];
  undefined1 auVar42 [16];
  undefined1 auVar43 [16];
  undefined1 auVar44 [16];
  undefined1 auVar45 [16];
  undefined1 auVar46 [16];
  undefined1 auVar47 [16];
  undefined1 auVar48 [16];
  undefined1 auVar49 [16];
  undefined1 auVar50 [16];
  undefined1 auVar51 [16];
  undefined1 auVar52 [16];
  undefined1 auVar53 [16];
  undefined1 auVar54 [16];
  undefined1 auVar55 [16];
  undefined1 auVar56 [16];
  undefined1 auVar57 [16];
  undefined1 auVar58 [16];
  undefined1 auVar59 [16];
  undefined1 auVar60 [16];
  undefined1 auVar61 [16];
  undefined1 auVar62 [16];
  undefined1 auVar63 [16];
  undefined1 auVar64 [16];
  undefined1 auVar65 [16];
  undefined1 auVar66 [16];
  undefined1 auVar67 [16];
  undefined1 auVar68 [16];
  undefined1 auVar69 [16];
  undefined1 auVar70 [16];
  undefined1 auVar71 [16];
  undefined1 auVar72 [16];
  undefined1 auVar73 [16];
  undefined1 auVar74 [16];
  undefined1 auVar75 [16];
  undefined1 auVar76 [16];
  undefined1 auVar77 [16];
  undefined1 auVar78 [16];
  undefined1 auVar79 [16];
  undefined1 auVar80 [16];
  undefined1 auVar81 [16];
  undefined1 auVar82 [16];
  undefined1 auVar83 [16];
  undefined1 auVar84 [16];
  undefined1 auVar85 [16];
  undefined1 auVar86 [16];
  undefined1 auVar87 [16];
  undefined1 auVar88 [16];
  ulong uVar89;
  byte *pbVar90;
  undefined4 uVar91;
  undefined8 uVar92;
  ulong uVar93;
  undefined8 *puVar94;
  byte *pbVar95;
  ulong uVar96;
  ulong uVar97;
  undefined8 *puVar98;
  long lVar99;
  ulong uVar100;
  undefined8 extraout_d0;
  undefined8 uVar101;
  undefined8 extraout_d0_00;
  undefined8 extraout_d0_01;
  undefined8 extraout_var;
  undefined1 auVar102 [16];
  undefined8 uVar104;
  undefined1 auVar103 [16];
  undefined8 extraout_var_00;
  undefined8 extraout_var_01;
  undefined8 uVar105;
  undefined8 uVar106;
  undefined8 uVar107;
  undefined8 uVar108;
  undefined8 uVar109;
  
  uVar109 = param_4._8_8_;
  uVar108 = param_4._0_8_;
  uVar107 = param_3._8_8_;
  uVar106 = param_3._0_8_;
  uVar105 = param_2._8_8_;
  uVar101 = param_2._0_8_;
  lVar99 = *(long *)(param_7 + 0x40);
  if (lVar99 == 0) {
    lVar99 = 0;
  }
  uVar4 = *(uint *)(lVar99 + 0x98);
  thunk_FUN_fffffff00aa65cc0(param_8,0xc68);
  uVar3 = 0x14;
  if (*(uint *)(lVar99 + 0x98) < 0x15) {
    uVar3 = uVar4;
  }
  *(undefined4 *)(param_8 + 3) = *(undefined4 *)(param_7 + 0x38);
  uVar92 = *(undefined8 *)(lVar99 + 0x90);
  param_8[4] = uVar92;
  uVar104 = *(undefined8 *)(lVar99 + 0x58);
  param_8[6] = *(undefined8 *)(lVar99 + 0x60);
  param_8[5] = uVar104;
  *(undefined4 *)(param_8 + 9) = *(undefined4 *)(lVar99 + 0x80);
  param_8[7] = *(undefined8 *)(lVar99 + 0x68);
  *(undefined4 *)(param_8 + 0xc) = *(undefined4 *)(lVar99 + 0x70);
  param_8[10] = uVar92;
  uVar91 = *(undefined4 *)(*(long *)(lVar99 + 0x178) + 0xc);
  bVar5 = *(byte *)(*(long *)(lVar99 + 0x178) + 0x6e);
  *(undefined4 *)((long)param_8 + 100) = *(undefined4 *)(lVar99 + 0x9c);
  *(undefined4 *)(param_8 + 0xd) = uVar91;
  *(uint *)(param_8 + 0xb) = uVar3;
  *(uint *)((long)param_8 + 0x5c) = (uint)bVar5;
  uVar92 = *(undefined8 *)(param_7 + 0x50);
  param_8[1] = *(undefined8 *)(param_7 + 0x58);
  *param_8 = uVar92;
  param_8[2] = *(undefined8 *)(param_7 + 0x60);
  *(char *)((long)param_8 + 0x6c) = (char)*(undefined4 *)(lVar99 + 0x3ac);
  uVar91 = 0;
  if (*(long *)(lVar99 + 0x378) != 0) {
    uVar91 = *(undefined4 *)(*(long *)(lVar99 + 0x378) + 0x10);
  }
  *(undefined4 *)(param_8 + 0xe) = uVar91;
  param_8[0xf] = *(undefined8 *)(lVar99 + 0x380);
  *(byte *)((long)param_8 + 0x6d) = (byte)(*(uint *)(lVar99 + 0x3d0) >> 0x15) & 1;
  uVar92 = FUN_fffffff009c20364(lVar99);
  param_8[0x10] = uVar92;
  *(byte *)((long)param_8 + 0x6e) = (byte)((uint)*(undefined4 *)(lVar99 + 0x3d0) >> 0x19) & 1;
  param_8[8] = *(undefined8 *)(lVar99 + 0x78);
  puVar98 = param_8 + 0x11;
  if (uVar3 == 0) {
    pbVar90 = *(byte **)(lVar99 + 0x318);
    pbVar95 = pbVar90 + (ulong)*(uint *)(lVar99 + 800) * 0x18;
    if ((((ulong)pbVar90 ^ (ulong)pbVar95) & 0xffc0000000000000) != 0) {
      pbVar95 = (byte *)((ulong)pbVar95 & 0xffffffffffff | 0xc8a2000000000000);
    }
    uVar92 = extraout_d0;
    uVar104 = extraout_var;
    if ((pbVar95 < pbVar90) || ((ulong)((long)pbVar95 - (long)pbVar90) >> 0x20 != 0)) {
LAB_fffffff009c2c6d8:
      auVar17._8_8_ = uVar104;
      auVar17._0_8_ = uVar92;
      auVar41._8_8_ = uVar105;
      auVar41._0_8_ = uVar101;
      auVar65._8_8_ = uVar107;
      auVar65._0_8_ = uVar106;
      auVar88._8_8_ = uVar109;
      auVar88._0_8_ = uVar108;
                    /* WARNING: Subroutine does not return */
      FUN_fffffff009c48f64(auVar17,auVar41,auVar65,auVar88,param_5,param_6);
    }
    if ((ulong)((long)pbVar95 - (long)pbVar90) < 0x18) {
      auVar103._8_8_ = extraout_var;
      auVar103._0_8_ = extraout_d0;
      auVar18._8_8_ = uVar105;
      auVar18._0_8_ = uVar101;
      auVar42._8_8_ = uVar107;
      auVar42._0_8_ = uVar106;
      auVar102._8_8_ = uVar109;
      auVar102._0_8_ = uVar108;
                    /* WARNING: Subroutine does not return */
      FUN_fffffff009c48f28(auVar103,auVar18,auVar42,auVar102,param_5,param_6);
    }
    auVar103 = FUN_fffffff009c2c6e8((long)puVar98,(long)pbVar90,(uint)*pbVar90);
    puVar94 = *(undefined8 **)(lVar99 + 0x350);
    puVar98 = puVar94 + (ulong)*(uint *)(lVar99 + 0x358) * 4;
    if ((((ulong)puVar94 ^ (ulong)puVar98) & 0xffc0000000000000) != 0) {
      puVar98 = (undefined8 *)((ulong)puVar98 & 0xffffffffffff | 0xc8a2000000000000);
    }
    if ((puVar98 < puVar94) || ((ulong)((long)puVar98 - (long)puVar94) >> 0x20 != 0)) {
      auVar19._8_8_ = uVar105;
      auVar19._0_8_ = uVar101;
      auVar43._8_8_ = uVar107;
      auVar43._0_8_ = uVar106;
      auVar66._8_8_ = uVar109;
      auVar66._0_8_ = uVar108;
                    /* WARNING: Subroutine does not return */
      FUN_fffffff009c48f64(auVar103,auVar19,auVar43,auVar66,param_5,param_6);
    }
    if ((ulong)((long)puVar98 - (long)puVar94) < 0x20) {
      auVar20._8_8_ = uVar105;
      auVar20._0_8_ = uVar101;
      auVar44._8_8_ = uVar107;
      auVar44._0_8_ = uVar106;
      auVar67._8_8_ = uVar109;
      auVar67._0_8_ = uVar108;
                    /* WARNING: Subroutine does not return */
      FUN_fffffff009c48f28(auVar103,auVar20,auVar44,auVar67,param_5,param_6);
    }
    uVar101 = *puVar94;
    param_8[0x23] = puVar94[1];
    param_8[0x22] = uVar101;
  }
  else {
    uVar100 = 0;
    uVar92 = extraout_d0;
    uVar104 = extraout_var;
    do {
      uVar93 = *(ulong *)(lVar99 + 0x180);
      uVar96 = uVar93 + (ulong)*(uint *)(lVar99 + 0x188) * 0x38;
      if (((uVar93 ^ uVar96) & 0xffc0000000000000) != 0) {
        uVar96 = uVar96 & 0xffffffffffff | 0xc8a2000000000000;
      }
      if ((uVar96 < uVar93) || (uVar96 - uVar93 >> 0x20 != 0)) {
        auVar6._8_8_ = uVar104;
        auVar6._0_8_ = uVar92;
        auVar21._8_8_ = uVar105;
        auVar21._0_8_ = uVar101;
        auVar45._8_8_ = uVar107;
        auVar45._0_8_ = uVar106;
        auVar68._8_8_ = uVar109;
        auVar68._0_8_ = uVar108;
                    /* WARNING: Subroutine does not return */
        FUN_fffffff009c48f64(auVar6,auVar21,auVar45,auVar68,param_5,param_6);
      }
      uVar89 = uVar100 * 0x38;
      uVar4 = (int)uVar89 + 0x38;
      if ((uint)(uVar96 - uVar93) < uVar4) {
        auVar7._8_8_ = uVar104;
        auVar7._0_8_ = uVar92;
        auVar22._8_8_ = uVar105;
        auVar22._0_8_ = uVar101;
        auVar46._8_8_ = uVar107;
        auVar46._0_8_ = uVar106;
        auVar69._8_8_ = uVar109;
        auVar69._0_8_ = uVar108;
                    /* WARNING: Subroutine does not return */
        FUN_fffffff009c48f28(auVar7,auVar22,auVar46,auVar69,param_5,param_6);
      }
      puVar94 = (undefined8 *)(uVar93 + uVar89);
      uVar96 = -(ulong)CARRY8(uVar93,uVar89);
      if ((uVar96 != CARRY8(uVar93,uVar89)) || ((long)uVar96 < 0)) {
        auVar8._8_8_ = uVar104;
        auVar8._0_8_ = uVar92;
        auVar23._8_8_ = uVar105;
        auVar23._0_8_ = uVar101;
        auVar47._8_8_ = uVar107;
        auVar47._0_8_ = uVar106;
        auVar70._8_8_ = uVar109;
        auVar70._0_8_ = uVar108;
                    /* WARNING: Subroutine does not return */
        FUN_fffffff009c48f50(auVar8,auVar23,auVar47,auVar70,param_5,param_6);
      }
      if (param_8 + 0x18d < puVar98) {
        auVar9._8_8_ = uVar104;
        auVar9._0_8_ = uVar92;
        auVar24._8_8_ = uVar105;
        auVar24._0_8_ = uVar101;
        auVar48._8_8_ = uVar107;
        auVar48._0_8_ = uVar106;
        auVar71._8_8_ = uVar109;
        auVar71._0_8_ = uVar108;
                    /* WARNING: Subroutine does not return */
        FUN_fffffff009c48f64(auVar9,auVar24,auVar48,auVar71,param_5,param_6);
      }
      if (uVar100 == 0xd79436) {
        auVar10._8_8_ = uVar104;
        auVar10._0_8_ = uVar92;
        auVar25._8_8_ = uVar105;
        auVar25._0_8_ = uVar101;
        auVar49._8_8_ = uVar107;
        auVar49._0_8_ = uVar106;
        auVar72._8_8_ = uVar109;
        auVar72._0_8_ = uVar108;
        FUN_fffffff009c491c8(auVar10,auVar25,auVar49,auVar72,param_5,param_6);
        uVar92 = extraout_d0_00;
        uVar104 = extraout_var_00;
LAB_fffffff009c2c69c:
        auVar11._8_8_ = uVar104;
        auVar11._0_8_ = uVar92;
        auVar26._8_8_ = uVar105;
        auVar26._0_8_ = uVar101;
        auVar50._8_8_ = uVar107;
        auVar50._0_8_ = uVar106;
        auVar73._8_8_ = uVar109;
        auVar73._0_8_ = uVar108;
                    /* WARNING: Subroutine does not return */
        FUN_fffffff009c48f28(auVar11,auVar26,auVar50,auVar73,param_5,param_6);
      }
      uVar96 = uVar100 * 0x9800000000;
      if (((long)uVar96 < 0) ||
         ((uint)((int)(param_8 + 0x18d) - (int)puVar98) < (int)(uVar96 >> 0x20) + 0x98U))
      goto LAB_fffffff009c2c69c;
      puVar2 = (undefined8 *)((long)puVar98 + (uVar96 >> 0x20));
      uVar93 = (ulong)CARRY8((ulong)puVar98,uVar96 >> 0x20);
      uVar96 = -uVar93;
      if ((uVar96 != uVar93) || ((long)uVar96 < 0)) {
        auVar12._8_8_ = uVar104;
        auVar12._0_8_ = uVar92;
        auVar27._8_8_ = uVar105;
        auVar27._0_8_ = uVar101;
        auVar51._8_8_ = uVar107;
        auVar51._0_8_ = uVar106;
        auVar74._8_8_ = uVar109;
        auVar74._0_8_ = uVar108;
                    /* WARNING: Subroutine does not return */
        FUN_fffffff009c48f50(auVar12,auVar27,auVar51,auVar74,param_5,param_6);
      }
      *puVar2 = *puVar94;
      uVar92 = puVar94[1];
      puVar2[2] = puVar94[2];
      puVar2[1] = uVar92;
      pauVar1 = (undefined1 (*) [16])(puVar94 + 3);
      uVar92 = *(undefined8 *)*pauVar1;
      auVar102 = *pauVar1;
      auVar42 = *pauVar1;
      auVar18 = *pauVar1;
      auVar103 = *pauVar1;
      puVar2[4] = puVar94[4];
      puVar2[3] = uVar92;
      *(undefined2 *)(puVar2 + 6) = *(undefined2 *)(puVar94 + 6);
      *(undefined2 *)((long)puVar2 + 0x32) = *(undefined2 *)((long)puVar94 + 0x34);
      puVar2[5] = puVar94[5];
      *(undefined1 *)((long)puVar2 + 0x35) = 0;
      *(undefined2 *)((long)puVar2 + 0x36) = 0;
      if (uVar100 < *(ulong *)(lVar99 + 0x328)) {
        uVar93 = *(ulong *)(lVar99 + 0x318);
        uVar96 = uVar93 + (ulong)*(uint *)(lVar99 + 800) * 0x18;
        if (((uVar93 ^ uVar96) & 0xffc0000000000000) != 0) {
          uVar96 = uVar96 & 0xffffffffffff | 0xc8a2000000000000;
        }
        if ((uVar96 < uVar93) || (uVar96 - uVar93 >> 0x20 != 0)) {
          auVar28._8_8_ = uVar105;
          auVar28._0_8_ = uVar101;
          auVar52._8_8_ = uVar107;
          auVar52._0_8_ = uVar106;
          auVar75._8_8_ = uVar109;
          auVar75._0_8_ = uVar108;
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f64(auVar103,auVar28,auVar52,auVar75,param_5,param_6);
        }
        uVar97 = uVar100 * 0x18;
        if ((uint)(uVar96 - uVar93) < (int)uVar97 + 0x18U) {
          auVar29._8_8_ = uVar105;
          auVar29._0_8_ = uVar101;
          auVar53._8_8_ = uVar107;
          auVar53._0_8_ = uVar106;
          auVar76._8_8_ = uVar109;
          auVar76._0_8_ = uVar108;
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f28(auVar18,auVar29,auVar53,auVar76,param_5,param_6);
        }
        uVar96 = -(ulong)CARRY8(uVar93,uVar97);
        if ((uVar96 != CARRY8(uVar93,uVar97)) || ((long)uVar96 < 0)) {
          auVar30._8_8_ = uVar105;
          auVar30._0_8_ = uVar101;
          auVar54._8_8_ = uVar107;
          auVar54._0_8_ = uVar106;
          auVar77._8_8_ = uVar109;
          auVar77._0_8_ = uVar108;
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f50(auVar42,auVar30,auVar54,auVar77,param_5,param_6);
        }
        auVar102 = FUN_fffffff009c2c6e8
                             ((long)(puVar98 + uVar100 * 0x13),(long)(uVar93 + uVar97),
                              (uint)*(byte *)(uVar93 + uVar97));
      }
      uVar93 = *(ulong *)(lVar99 + 0x180);
      uVar96 = uVar93 + (ulong)*(uint *)(lVar99 + 0x188) * 0x38;
      if (((uVar93 ^ uVar96) & 0xffc0000000000000) != 0) {
        uVar96 = uVar96 & 0xffffffffffff | 0xc8a2000000000000;
      }
      if ((uVar96 < uVar93) || (uVar96 - uVar93 >> 0x20 != 0)) {
        auVar31._8_8_ = uVar105;
        auVar31._0_8_ = uVar101;
        auVar55._8_8_ = uVar107;
        auVar55._0_8_ = uVar106;
        auVar78._8_8_ = uVar109;
        auVar78._0_8_ = uVar108;
                    /* WARNING: Subroutine does not return */
        FUN_fffffff009c48f64(auVar102,auVar31,auVar55,auVar78,param_5,param_6);
      }
      if ((uint)(uVar96 - uVar93) < uVar4) {
        auVar32._8_8_ = uVar105;
        auVar32._0_8_ = uVar101;
        auVar56._8_8_ = uVar107;
        auVar56._0_8_ = uVar106;
        auVar79._8_8_ = uVar109;
        auVar79._0_8_ = uVar108;
                    /* WARNING: Subroutine does not return */
        FUN_fffffff009c48f28(auVar102,auVar32,auVar56,auVar79,param_5,param_6);
      }
      uVar96 = -(ulong)CARRY8(uVar93,uVar89);
      if ((uVar96 != CARRY8(uVar93,uVar89)) || ((long)uVar96 < 0)) {
        auVar33._8_8_ = uVar105;
        auVar33._0_8_ = uVar101;
        auVar57._8_8_ = uVar107;
        auVar57._0_8_ = uVar106;
        auVar80._8_8_ = uVar109;
        auVar80._0_8_ = uVar108;
                    /* WARNING: Subroutine does not return */
        FUN_fffffff009c48f50(auVar102,auVar33,auVar57,auVar80,param_5,param_6);
      }
      *(undefined1 *)((long)puVar2 + 0x35) = *(undefined1 *)(uVar93 + uVar89 + 0x36);
      uVar96 = *(ulong *)(lVar99 + 0x308);
      if (uVar96 == 0) {
        uVar92 = 0;
        uVar104 = 0;
        puVar2[0x10] = 0;
        puVar2[0xf] = 0;
        *(undefined8 *)((long)puVar2 + 0x74) = 0;
        *(undefined8 *)((long)puVar2 + 0x6c) = 0;
        *(undefined8 *)((long)puVar2 + 100) = 0;
        *(undefined8 *)((long)puVar2 + 0x5c) = 0;
        *(undefined8 *)((long)puVar2 + 0x54) = 0;
        *(undefined8 *)((long)puVar2 + 0x4c) = 0;
        uVar91 = 0;
      }
      else {
        uVar93 = uVar96 + (ulong)*(uint *)(lVar99 + 0x310) * 0x3c;
        if (((uVar96 ^ uVar93) & 0xffc0000000000000) != 0) {
          uVar93 = uVar93 & 0xffffffffffff | 0xc8a2000000000000;
        }
        if ((uVar93 < uVar96) || (uVar93 - uVar96 >> 0x20 != 0)) {
          auVar34._8_8_ = uVar105;
          auVar34._0_8_ = uVar101;
          auVar58._8_8_ = uVar107;
          auVar58._0_8_ = uVar106;
          auVar81._8_8_ = uVar109;
          auVar81._0_8_ = uVar108;
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f64(auVar102,auVar34,auVar58,auVar81,param_5,param_6);
        }
        uVar89 = uVar100 * 0x3c;
        if ((uint)(uVar93 - uVar96) < (int)uVar89 + 0x3cU) {
          auVar35._8_8_ = uVar105;
          auVar35._0_8_ = uVar101;
          auVar59._8_8_ = uVar107;
          auVar59._0_8_ = uVar106;
          auVar82._8_8_ = uVar109;
          auVar82._0_8_ = uVar108;
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f28(auVar102,auVar35,auVar59,auVar82,param_5,param_6);
        }
        puVar94 = (undefined8 *)(uVar96 + uVar89);
        uVar93 = -(ulong)CARRY8(uVar96,uVar89);
        if ((uVar93 != CARRY8(uVar96,uVar89)) || ((long)uVar93 < 0)) {
          auVar36._8_8_ = uVar105;
          auVar36._0_8_ = uVar101;
          auVar60._8_8_ = uVar107;
          auVar60._0_8_ = uVar106;
          auVar83._8_8_ = uVar109;
          auVar83._0_8_ = uVar108;
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f50(auVar102,auVar36,auVar60,auVar83,param_5,param_6);
        }
        uVar104 = puVar94[1];
        uVar92 = *puVar94;
        uVar105 = puVar94[3];
        uVar101 = puVar94[2];
        uVar107 = puVar94[5];
        uVar106 = puVar94[4];
        uVar109 = *(undefined8 *)((long)puVar94 + 0x34);
        uVar108 = *(undefined8 *)((long)puVar94 + 0x2c);
        puVar2[0x10] = uVar109;
        puVar2[0xf] = uVar108;
        *(undefined8 *)((long)puVar2 + 0x74) = uVar107;
        *(undefined8 *)((long)puVar2 + 0x6c) = uVar106;
        *(undefined8 *)((long)puVar2 + 100) = uVar105;
        *(undefined8 *)((long)puVar2 + 0x5c) = uVar101;
        *(undefined8 *)((long)puVar2 + 0x54) = uVar104;
        *(undefined8 *)((long)puVar2 + 0x4c) = uVar92;
        uVar91 = *(undefined4 *)(lVar99 + 0x3b8);
      }
      *(undefined4 *)((long)param_8 + 0x74) = uVar91;
      if (uVar100 < *(ulong *)(lVar99 + 0x348) >> 5) {
        uVar93 = *(ulong *)(lVar99 + 0x350);
        uVar96 = uVar93 + (ulong)*(uint *)(lVar99 + 0x358) * 0x20;
        if (((uVar93 ^ uVar96) & 0xffc0000000000000) != 0) {
          uVar96 = uVar96 & 0xffffffffffff | 0xc8a2000000000000;
        }
        if ((uVar96 < uVar93) || (uVar96 - uVar93 >> 0x20 != 0)) {
          auVar13._8_8_ = uVar104;
          auVar13._0_8_ = uVar92;
          auVar37._8_8_ = uVar105;
          auVar37._0_8_ = uVar101;
          auVar61._8_8_ = uVar107;
          auVar61._0_8_ = uVar106;
          auVar84._8_8_ = uVar109;
          auVar84._0_8_ = uVar108;
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f64(auVar13,auVar37,auVar61,auVar84,param_5,param_6);
        }
        if ((uint)(uVar96 - uVar93) < (int)(uVar100 << 5) + 0x20U) {
          auVar14._8_8_ = uVar104;
          auVar14._0_8_ = uVar92;
          auVar38._8_8_ = uVar105;
          auVar38._0_8_ = uVar101;
          auVar62._8_8_ = uVar107;
          auVar62._0_8_ = uVar106;
          auVar85._8_8_ = uVar109;
          auVar85._0_8_ = uVar108;
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f28(auVar14,auVar38,auVar62,auVar85,param_5,param_6);
        }
        uVar96 = uVar100 << 5 & 0xffffffe0;
        puVar94 = (undefined8 *)(uVar93 + uVar96);
        uVar93 = (ulong)CARRY8(uVar93,uVar96);
        uVar96 = -uVar93;
        if ((uVar96 != uVar93) || ((long)uVar96 < 0)) {
          auVar15._8_8_ = uVar104;
          auVar15._0_8_ = uVar92;
          auVar39._8_8_ = uVar105;
          auVar39._0_8_ = uVar101;
          auVar63._8_8_ = uVar107;
          auVar63._0_8_ = uVar106;
          auVar86._8_8_ = uVar109;
          auVar86._0_8_ = uVar108;
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f50(auVar15,auVar39,auVar63,auVar86,param_5,param_6);
        }
        if (uVar100 * 0x98 - (long)(int)(uVar100 * 0x98) != 0) {
          auVar16._8_8_ = uVar104;
          auVar16._0_8_ = uVar92;
          auVar40._8_8_ = uVar105;
          auVar40._0_8_ = uVar101;
          auVar64._8_8_ = uVar107;
          auVar64._0_8_ = uVar106;
          auVar87._8_8_ = uVar109;
          auVar87._0_8_ = uVar108;
          FUN_fffffff009c491c8(auVar16,auVar40,auVar64,auVar87,param_5,param_6);
          uVar92 = extraout_d0_01;
          uVar104 = extraout_var_01;
          goto LAB_fffffff009c2c6d8;
        }
        uVar104 = puVar94[1];
        uVar92 = *puVar94;
        puVar2[0x12] = uVar104;
        puVar2[0x11] = uVar92;
      }
      uVar100 = uVar100 + 1;
    } while (uVar100 != uVar3);
  }
  return;
}

