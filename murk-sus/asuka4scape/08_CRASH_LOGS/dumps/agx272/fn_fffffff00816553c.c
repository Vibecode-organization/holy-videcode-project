// FUN_fffffff00816553c @ fffffff00816553c size=12

/* WARNING: Removing unreachable block (ram,0xfffffff008165bcc) */
/* WARNING: Removing unreachable block (ram,0xfffffff008166260) */
/* WARNING: Removing unreachable block (ram,0xfffffff008165dd0) */
/* WARNING: Removing unreachable block (ram,0xfffffff008165d38) */
/* WARNING: Removing unreachable block (ram,0xfffffff008165730) */
/* WARNING: Removing unreachable block (ram,0xfffffff008165d84) */
/* WARNING: Removing unreachable block (ram,0xfffffff008165e0c) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081662a4) */
/* WARNING: Removing unreachable block (ram,0xfffffff008165c10) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081656e4) */

void FUN_fffffff00816553c(long *param_1,long *param_2)

{
  uint *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  byte bVar5;
  bool bVar6;
  undefined4 uVar7;
  int *piVar8;
  long lVar9;
  ulong uVar10;
  ulong uVar11;
  uint *puVar12;
  long lVar13;
  undefined8 uVar14;
  uint uVar15;
  int iVar16;
  code *pcVar17;
  uint uVar18;
  long lVar19;
  long lVar20;
  long lVar21;
  long lVar22;
  long lVar23;
  ulong uVar24;
  undefined4 *puVar25;
  uint uVar26;
  long lVar27;
  uint uVar28;
  long lStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  
  if ((*(byte *)((long)param_2 + 0x4c) & 1) == 0) {
    *(undefined8 *)(*(long *)(param_1[2] + 0x4b0) + 0xbf0) = 0;
    bVar5 = *(byte *)(param_2 + 0xff);
    if ((bVar5 & 1) == 0) {
      uVar26 = *(uint *)(param_2 + 400);
    }
    else {
      uVar26 = 0x80;
    }
    piVar8 = (int *)(**(code **)(*param_2 + 0x108))(param_2);
    lVar21 = param_1[2];
    lVar9 = (**(code **)(**(long **)(*(long *)(lVar21 + 0x183a8) + 0x50) + 0x98))();
    uVar28 = *(uint *)(lVar21 + 0x4a0);
    lVar22 = param_1[2];
    lVar21 = (**(code **)(**(long **)(*(long *)(lVar22 + 0x183b0) + 0x50) + 0x98))();
    uVar15 = *(uint *)(lVar22 + 0x4a4);
    uVar10 = (**(code **)(**(long **)(param_1[2] + 0x148) + 0x88))
                       (*(long **)(param_1[2] + 0x148),piVar8[1]);
    uVar11 = (**(code **)(**(long **)(param_1[2] + 0x148) + 0x88))
                       (*(long **)(param_1[2] + 0x148),piVar8[1]);
    lVar21 = lVar21 + (ulong)uVar15 + (uVar11 & 0xffffffff);
    iVar3 = *piVar8;
    iVar4 = piVar8[1];
    lVar22 = param_1[7];
    uVar15 = (uint)((int)param_2[9] != 0);
    lStack_78 = 0;
    uStack_70 = 0;
    uStack_68 = 0;
    uVar7 = (**(code **)(*param_1 + 0x170))(param_1,param_2,bVar5 & 1,(long)&uStack_70 + 4);
    uStack_68 = CONCAT44(uStack_68._4_4_,uVar7);
    puVar12 = (uint *)(**(code **)(*param_2 + 0x110))(*param_2 + 0x110,param_2);
    if ((bVar5 & 1) == 0) {
      if (*puVar12 != 0) {
        uVar11 = 0;
        do {
          iVar16 = (int)(uVar11 * 0xc);
          puVar1 = (uint *)((long)puVar12 + (long)iVar16 + 4);
          if (uVar11 * 0xc - (long)iVar16 != 0) {
            puVar1 = (uint *)((ulong)(puVar12 + uVar11 * 3 + 1) & 0xffffffffffff |
                             0x2bad000000000000);
          }
          if (puVar1[1] == uVar26) {
            if (uVar11 != 0) {
              uVar14 = *(undefined8 *)(puVar12 + 1);
              puVar12[1] = *puVar1;
              puVar12[2] = uVar26;
              *(undefined8 *)puVar1 = uVar14;
            }
            break;
          }
          uVar11 = uVar11 + 1;
        } while (*puVar12 != uVar11);
      }
    }
    else if ((*(byte *)(param_2 + 0x101) & 1) != 0) {
      uStack_70 = CONCAT44(uStack_70._4_4_,iVar3 + -0x100);
      lStack_78 = lVar21;
    }
    lVar9 = lVar9 + (ulong)uVar28 + (uVar10 & 0xffffffff);
    lVar23 = param_1[2];
    lVar13 = (**(code **)(**(long **)(*(long *)(lVar23 + 0x183b0) + 0x50) + 0x98))();
    uVar26 = *(uint *)(lVar23 + 0x4a4);
    lVar27 = param_1[2];
    lVar23 = (**(code **)(**(long **)(*(long *)(lVar27 + 0x183a8) + 0x50) + 0x98))();
    if (*puVar12 != 0) {
      uVar10 = 0;
      uVar28 = *(uint *)(lVar27 + 0x4a0);
      do {
        puVar25 = (undefined4 *)param_2[uVar10 + 0x6b];
        iVar16 = (int)(uVar10 * 0xc);
        piVar8 = (int *)((long)puVar12 + (long)iVar16 + 4);
        if (uVar10 * 0xc - (long)iVar16 != 0) {
          piVar8 = (int *)((ulong)(puVar12 + uVar10 * 3 + 1) & 0xffffffffffff | 0x2bad000000000000);
        }
        iVar16 = piVar8[1];
        uVar11 = (**(code **)(**(long **)(param_1[2] + 0x148) + 0x88))
                           (*(long **)(param_1[2] + 0x148),iVar16);
        lVar27 = lVar13 + (ulong)uVar26 + (uVar11 & 0xffffffff);
        if ((lStack_78 == 0) && (iVar4 == piVar8[1])) {
          if (iVar3 == *piVar8 + 0x100) {
            uStack_70 = CONCAT44(uStack_70._4_4_,*piVar8);
            lStack_78 = lVar27;
          }
        }
        else {
          lVar20 = *(long *)(param_1[2] + 0x11e10);
          lVar19 = (long)iVar16 * 4;
          piVar2 = (int *)(lVar20 + (int)lVar19);
          if (lVar19 - (int)lVar19 != 0) {
            piVar2 = (int *)(lVar20 + lVar19 & 0xffffffffffffU | 0x2bad000000000000);
          }
          lVar19 = lVar27;
          if (*piVar2 == *(int *)((long)param_2 + 0x1dc)) {
            uVar18 = 0;
          }
          else {
            bVar6 = (*(byte *)(param_1[2] + 0x5c9) & 4) != 0;
            if (bVar6) {
              lVar19 = lVar23 + (ulong)uVar28 + (uVar11 & 0xffffffff);
            }
            uVar18 = (uint)bVar6;
          }
          *puVar25 = 4;
          *(long *)(puVar25 + 1) = lVar19;
          puVar25[5] = *piVar8;
          *(long *)(puVar25 + 10) = param_2[0x20];
          puVar25[0xc] = uVar18;
          puVar25[8] = iVar16;
          puVar25[9] = iVar3;
          *(long *)(puVar25 + 3) = lVar27;
          (**(code **)(*param_1 + 200))(param_1,param_2[uVar10 + 0x7a],puVar25,0);
        }
        uVar10 = uVar10 + 1;
      } while (uVar10 < *puVar12);
    }
    if ((bVar5 & 1) == 0) {
      puVar25 = (undefined4 *)param_2[0x90];
      *puVar25 = 1;
      lVar13 = thunk_EXT_FUN_8011000003890f30(param_2[0xc],&DAT_fffffff00ae21f50);
      lVar23 = *(long *)(lVar13 + 0x620);
      *(long *)(lVar13 + 0x620) = lVar23 + 1;
      *(long *)(puVar25 + 1) = lVar23;
      puVar25[3] = *(undefined4 *)((long)param_2 + 0x1dc);
      *(long *)(puVar25 + 0x25a) = param_2[0x3c];
      puVar25[0x244] = (int)param_2[0x3b];
      puVar25[0x245] = (uint)((char)param_2[0x11e] == '\x02');
      puVar25[0x226] = *(byte *)((long)param_2 + 0x83f) & 1;
      puVar25[0x224] = 0;
      *(undefined8 *)(puVar25 + 0x24a) = uStack_68;
      *(undefined8 *)(puVar25 + 0x248) = uStack_70;
      *(long *)(puVar25 + 0x246) = lStack_78;
      *(undefined8 *)(puVar25 + 0x266) = 0;
      *(undefined8 *)(puVar25 + 0x264) = 0;
      *(long *)(puVar25 + 0x268) = param_2[0x39];
      (**(code **)(*param_2 + 0xe0))(param_2,1);
      *(long *)(puVar25 + 8) = param_2[0x40];
      lVar13 = **(long **)(param_1[2] + 0x4b0);
      uVar14 = (**(code **)(lVar13 + 0x208))
                         (lVar13 + 0x208,*(long **)(param_1[2] + 0x4b0),param_2[0x116],0);
      *(undefined8 *)(puVar25 + 10) = uVar14;
      lVar13 = **(long **)(param_1[2] + 0x4b0);
      uVar14 = (**(code **)(lVar13 + 0x208))
                         (lVar13 + 0x208,*(long **)(param_1[2] + 0x4b0),param_2[0x117],0);
      *(undefined8 *)(puVar25 + 0xc) = uVar14;
      lVar13 = **(long **)(param_1[2] + 0x4b0);
      uVar14 = (**(code **)(lVar13 + 0x208))
                         (lVar13 + 0x208,*(long **)(param_1[2] + 0x4b0),param_2[0x119],0);
      *(undefined8 *)(puVar25 + 0xe) = uVar14;
      (**(code **)(*param_2 + 0x118))(*param_2 + 0x118,param_2);
      lVar23 = param_2[0x109];
      puVar25[0x16] = (int)param_2[0x10d];
      lVar13 = param_2[0x10e];
      lVar27 = param_2[0x10c];
      *(long *)(puVar25 + 0x10) = lVar23;
      *(long *)(puVar25 + 0x12) = lVar27;
      lVar23 = param_2[0x10f];
      puVar25[0x14] = (int)lVar13;
      puVar25[0x15] = (int)lVar23;
      lVar13 = param_2[0x110];
      *(long *)(puVar25 + 0x1a) = param_2[0x111];
      *(long *)(puVar25 + 0x18) = lVar13;
      *(long *)(puVar25 + 0x1c) = param_2[0x112];
      puVar25[0x1e] = (int)param_2[0x114];
      *(long *)(puVar25 + 0x132) = param_2[0x96];
      *(long *)(puVar25 + 0x12e) = param_2[0x95];
      *(long *)(puVar25 + 0x136) = param_2[0x97];
      *(long *)(puVar25 + 0x13c) = param_2[0x9c];
      *(long *)(puVar25 + 0x13e) = param_2[0x9d];
      *(long *)(puVar25 + 0x140) = param_2[0x9e];
      *(long *)(puVar25 + 0x142) = param_2[0x9f];
      *(long *)(puVar25 + 0x144) = param_2[0xa0];
      *(long *)(puVar25 + 0x146) = param_2[0xa1];
      *(long *)(puVar25 + 0x148) = param_2[0xa2];
      *(long *)(puVar25 + 0x14a) = param_2[0xa3];
      *(long *)(puVar25 + 0x14c) = param_2[0xa4];
      *(long *)(puVar25 + 0x14e) = param_2[0xa5];
      *(long *)(puVar25 + 0x150) = param_2[0xa6];
      *(long *)(puVar25 + 0x152) = param_2[0xa7];
      *(long *)(puVar25 + 0x154) = param_2[0xa8];
      *(long *)(puVar25 + 0x156) = param_2[0xa9];
      *(long *)(puVar25 + 0x158) = param_2[0xaa];
      *(long *)(puVar25 + 0x15a) = param_2[0xab];
      *(long *)(puVar25 + 0x15c) = param_2[0xac];
      *(long *)(puVar25 + 0x15e) = param_2[0xad];
      *(long *)(puVar25 + 0x160) = param_2[0xae];
      *(long *)(puVar25 + 0x162) = param_2[0xaf];
      *(long *)(puVar25 + 0x164) = param_2[0xb0];
      *(long *)(puVar25 + 0x166) = param_2[0xb1];
      *(long *)(puVar25 + 0x168) = param_2[0xb2];
      *(long *)(puVar25 + 0x16a) = param_2[0xb3];
      *(long *)(puVar25 + 0x16c) = param_2[0xb4];
      *(long *)(puVar25 + 0x16e) = param_2[0xb5];
      *(long *)(puVar25 + 0x170) = param_2[0xb6];
      *(long *)(puVar25 + 0x172) = param_2[0xb7];
      *(long *)(puVar25 + 0x174) = param_2[0xb8];
      *(long *)(puVar25 + 0x176) = param_2[0xb9];
      *(long *)(puVar25 + 0x178) = param_2[0xba];
      *(long *)(puVar25 + 0x17a) = param_2[0xbb];
      lVar13 = param_2[0xbc];
      *(long *)(puVar25 + 0x17e) = param_2[0xbd];
      *(long *)(puVar25 + 0x17c) = lVar13;
      lVar13 = param_2[0xbe];
      *(long *)(puVar25 + 0x182) = param_2[0xbf];
      *(long *)(puVar25 + 0x180) = lVar13;
      lVar13 = param_2[0xc0];
      *(long *)(puVar25 + 0x186) = param_2[0xc1];
      *(long *)(puVar25 + 0x184) = lVar13;
      lVar13 = param_2[0xc2];
      *(long *)(puVar25 + 0x18a) = param_2[0xc3];
      *(long *)(puVar25 + 0x188) = lVar13;
      lVar13 = param_2[0xc4];
      *(long *)(puVar25 + 0x18e) = param_2[0xc5];
      *(long *)(puVar25 + 0x18c) = lVar13;
      lVar13 = param_2[0xc6];
      *(long *)(puVar25 + 0x192) = param_2[199];
      *(long *)(puVar25 + 400) = lVar13;
      lVar13 = param_2[200];
      *(long *)(puVar25 + 0x196) = param_2[0xc9];
      *(long *)(puVar25 + 0x194) = lVar13;
      *(long *)(puVar25 + 0x198) = param_2[0xcc];
      *(long *)(puVar25 + 0x19a) = param_2[0xd8];
      *(long *)(puVar25 + 0x19c) = param_2[0xdf];
      *(long *)(puVar25 + 0x1b0) = param_2[0xd4];
      lVar13 = param_2[0xcd];
      *(long *)(puVar25 + 0x1a0) = param_2[0xce];
      *(long *)(puVar25 + 0x19e) = lVar13;
      *(long *)(puVar25 + 0x1a2) = param_2[0xde];
      *(long *)(puVar25 + 0x1a4) = param_2[0xcf];
      *(long *)(puVar25 + 0x1a6) = param_2[0xda];
      *(long *)(puVar25 + 0x1a8) = param_2[0xe4];
      *(long *)(puVar25 + 0x1b2) = param_2[0xd7];
      lVar13 = param_2[0xd0];
      *(long *)(puVar25 + 0x1ac) = param_2[0xd1];
      *(long *)(puVar25 + 0x1aa) = lVar13;
      *(long *)(puVar25 + 0x1ae) = param_2[0xe3];
      lVar13 = param_2[0xe9];
      *(long *)(puVar25 + 0x1ba) = param_2[0xea];
      *(long *)(puVar25 + 0x1b8) = lVar13;
      *(long *)(puVar25 + 0x1c0) = param_2[0xf1];
      puVar25[0x1c2] = (int)param_2[0xf2];
      lVar13 = param_2[0xeb];
      *(long *)(puVar25 + 0x1c5) = param_2[0xec];
      *(long *)(puVar25 + 0x1c3) = lVar13;
      *(undefined8 *)(puVar25 + 0x1c8) = *(undefined8 *)((long)param_2 + 0x794);
      puVar25[0x1ca] = *(undefined4 *)((long)param_2 + 0x79c);
      lVar13 = param_2[0xef];
      *(long *)(puVar25 + 0x1cd) = param_2[0xf0];
      *(long *)(puVar25 + 0x1cb) = lVar13;
      *(long *)(puVar25 + 0x1d0) = param_2[0xf4];
      puVar25[0x1d2] = (int)param_2[0x93];
      lVar13 = param_2[0xe7];
      *(long *)(puVar25 + 0x1b6) = param_2[0xe8];
      *(long *)(puVar25 + 0x1b4) = lVar13;
      *(long *)(puVar25 + 0x13a) = param_2[0x9b];
      *(long *)(puVar25 + 0x1d6) = param_2[0xf6];
      puVar25[0x1d8] = (int)param_2[0xf8];
      *(long *)(puVar25 + 0x1da) = param_2[0xcb];
      *(undefined8 *)(puVar25 + 0x1df) = 0;
      *(undefined8 *)(puVar25 + 0x1dd) = 0;
      *(undefined8 *)(puVar25 + 0x1e3) = 0;
      *(undefined8 *)(puVar25 + 0x1e1) = 0;
      *(undefined8 *)(puVar25 + 0x1e7) = 0;
      *(undefined8 *)(puVar25 + 0x1e5) = 0;
      *(undefined8 *)(puVar25 + 0x1eb) = 0;
      *(undefined8 *)(puVar25 + 0x1e9) = 0;
      *(undefined8 *)(puVar25 + 0x1ef) = 0;
      *(undefined8 *)(puVar25 + 0x1ed) = 0;
      *(undefined8 *)(puVar25 + 499) = 0;
      *(undefined8 *)(puVar25 + 0x1f1) = 0;
      *(undefined8 *)(puVar25 + 0x1f7) = 0;
      *(undefined8 *)(puVar25 + 0x1f5) = 0;
      *(undefined8 *)(puVar25 + 0x1fb) = 0;
      *(undefined8 *)(puVar25 + 0x1f9) = 0;
      *(undefined8 *)(puVar25 + 0x1ff) = 0;
      *(undefined8 *)(puVar25 + 0x1fd) = 0;
      *(undefined8 *)(puVar25 + 0x203) = 0;
      *(undefined8 *)(puVar25 + 0x201) = 0;
      *(undefined8 *)(puVar25 + 0x207) = 0;
      *(undefined8 *)(puVar25 + 0x205) = 0;
      *(undefined8 *)(puVar25 + 0x20b) = 0;
      *(undefined8 *)(puVar25 + 0x209) = 0;
      *(undefined8 *)(puVar25 + 0x20f) = 0;
      *(undefined8 *)(puVar25 + 0x20d) = 0;
      *(undefined8 *)(puVar25 + 0x213) = 0;
      *(undefined8 *)(puVar25 + 0x211) = 0;
      *(undefined8 *)(puVar25 + 0x217) = 0;
      *(undefined8 *)(puVar25 + 0x215) = 0;
      *(undefined8 *)(puVar25 + 0x21b) = 0;
      *(undefined8 *)(puVar25 + 0x219) = 0;
      puVar25[0x21d] = 0;
      *(undefined8 *)(puVar25 + 0x220) = 0;
      *(undefined8 *)(puVar25 + 0x21e) = 0;
      puVar25[0x1dc] = 0;
      *(undefined8 *)(puVar25 + 0x222) = 0;
      puVar25[0x225] = *(byte *)((long)param_2 + 0x834) & 1;
      puVar25[0x227] = *(byte *)(param_2 + 0x102) & 1;
      puVar25[0x228] = *(undefined4 *)((long)param_2 + 0x814);
      puVar25[0x229] = (int)param_2[0x103];
      puVar25[0x22a] = *(undefined4 *)((long)param_2 + 0x81c);
      *(undefined8 *)(puVar25 + 0x22d) = 0;
      *(undefined8 *)(puVar25 + 0x22b) = 0;
      lVar13 = param_2[0x146];
      *(long *)(puVar25 + 0x254) = param_2[0x147];
      *(long *)(puVar25 + 0x252) = lVar13;
      *(undefined8 *)(puVar25 + 0x25c) = 0;
      *(undefined8 *)(puVar25 + 0x262) = 0;
      *(long *)(puVar25 + 0x256) = param_2[0x148];
      *(long *)(puVar25 + 600) = param_2[0x149];
      if ((*(byte *)(param_1[2] + 0x5cd) >> 6 & 1) != 0) {
        *(long *)(puVar25 + 0x22f) = param_2[0x11c];
        *(long *)(puVar25 + 0x231) = param_2[0x11d];
      }
      uVar26 = 0;
      lVar23 = param_2[0x105];
      lVar13 = param_2[0x104];
      *(long *)(puVar25 + 0x23a) = lVar9;
      *(long *)(puVar25 + 0x250) = lVar23;
      *(long *)(puVar25 + 0x24e) = lVar13;
      *(long *)(puVar25 + 0x23c) = lVar21;
      puVar25[0x23e] = iVar3;
      puVar25[0x23f] = iVar4;
      puVar25[0x240] = (int)lVar22;
      puVar25[0x241] = uVar15;
      *(undefined8 *)(puVar25 + 0x24c) = 0;
      uVar28 = (uint)(CONCAT12((char)((ushort)*(undefined2 *)((long)param_2 + 0x835) >> 8),
                               *(undefined2 *)((long)param_2 + 0x835)) & 0xff00ff);
      uVar10 = (ulong)CONCAT16(*(undefined1 *)((long)param_2 + 0x83b),
                               (uint6)CONCAT14(*(undefined1 *)((long)param_2 + 0x837),uVar28)) &
               0x1000100010001;
      *(ulong *)(puVar25 + 0x235) =
           (ulong)CONCAT24((short)(uVar10 >> 0x30),(uint)(ushort)(uVar10 >> 0x20));
      *(ulong *)(puVar25 + 0x233) =
           (ulong)(CONCAT24((short)(uVar10 >> 0x10),uVar28) & 0xffff00000001);
      puVar25[0x237] = 0;
      if ((*(byte *)(param_1[2] + 0x109b0) & 1) != 0) {
        uVar26 = *(byte *)((long)param_2 + 0xac9) & 1;
      }
      puVar25[0x239] = uVar26;
      puVar25[0x238] = *(byte *)((long)param_2 + 0x83d) & 1;
      *(long *)(puVar25 + 0x264) = param_2[0x2a];
      *(long *)(puVar25 + 0x266) = param_2[0x2b];
      *(long *)(puVar25 + 0x242) = param_2[0x20];
      (**(code **)(*param_1 + 0x160))(*param_1 + 0x160,param_1,puVar25,param_2);
      (**(code **)(*param_1 + 0x180))
                (*param_1 + 0x180,param_1,puVar25,param_2,param_2[0x92],param_2 + 0x10);
      lVar21 = param_2[0x92];
      lVar22 = param_2[0x20];
      pcVar17 = *(code **)(*param_1 + 200);
    }
    else {
      puVar25 = (undefined4 *)param_2[0x8d];
      *puVar25 = 2;
      lVar13 = thunk_EXT_FUN_8011000003890f30(param_2[0xc],&DAT_fffffff00ae21f50);
      lVar23 = *(long *)(lVar13 + 0x620);
      *(long *)(lVar13 + 0x620) = lVar23 + 1;
      *(long *)(puVar25 + 1) = lVar23;
      puVar25[3] = *(undefined4 *)((long)param_2 + 0x1dc);
      *(long *)(puVar25 + 0x19c) = param_2[0x3c];
      puVar25[0x179] = (int)param_2[0x3b];
      puVar25[0x17a] = 0;
      *(undefined8 *)(puVar25 + 0x17f) = uStack_68;
      *(undefined8 *)(puVar25 + 0x17d) = uStack_70;
      *(long *)(puVar25 + 0x17b) = lStack_78;
      (**(code **)(*param_2 + 0xe0))(param_2,1);
      *(long *)(puVar25 + 4) = param_2[0x40];
      puVar25[0x120] = (int)param_2[0x10e];
      lVar13 = param_2[0xbc];
      *(long *)(puVar25 + 0x116) = param_2[0xbd];
      *(long *)(puVar25 + 0x114) = lVar13;
      lVar13 = param_2[0xbe];
      *(long *)(puVar25 + 0x11a) = param_2[0xbf];
      *(long *)(puVar25 + 0x118) = lVar13;
      lVar13 = param_2[0xc0];
      *(long *)(puVar25 + 0x11e) = param_2[0xc1];
      *(long *)(puVar25 + 0x11c) = lVar13;
      puVar25[0x121] = (int)param_2[0x93];
      *(long *)(puVar25 + 0x122) = param_2[0xf6];
      puVar25[0x124] = (int)param_2[0xf8];
      *(undefined8 *)(puVar25 + 0x12a) = 0;
      *(undefined8 *)(puVar25 + 0x12e) = 0;
      *(undefined8 *)(puVar25 + 300) = 0;
      *(undefined8 *)(puVar25 + 0x132) = 0;
      *(undefined8 *)(puVar25 + 0x130) = 0;
      *(undefined8 *)(puVar25 + 0x136) = 0;
      *(undefined8 *)(puVar25 + 0x134) = 0;
      *(undefined8 *)(puVar25 + 0x13a) = 0;
      *(undefined8 *)(puVar25 + 0x138) = 0;
      *(undefined8 *)(puVar25 + 0x13e) = 0;
      *(undefined8 *)(puVar25 + 0x13c) = 0;
      *(undefined8 *)(puVar25 + 0x142) = 0;
      *(undefined8 *)(puVar25 + 0x140) = 0;
      *(undefined8 *)(puVar25 + 0x146) = 0;
      *(undefined8 *)(puVar25 + 0x144) = 0;
      *(undefined8 *)(puVar25 + 0x14a) = 0;
      *(undefined8 *)(puVar25 + 0x148) = 0;
      *(undefined8 *)(puVar25 + 0x14e) = 0;
      *(undefined8 *)(puVar25 + 0x14c) = 0;
      *(undefined8 *)(puVar25 + 0x152) = 0;
      *(undefined8 *)(puVar25 + 0x150) = 0;
      *(undefined8 *)(puVar25 + 0x156) = 0;
      *(undefined8 *)(puVar25 + 0x154) = 0;
      *(undefined8 *)(puVar25 + 0x15a) = 0;
      *(undefined8 *)(puVar25 + 0x158) = 0;
      *(undefined8 *)(puVar25 + 0x15e) = 0;
      *(undefined8 *)(puVar25 + 0x15c) = 0;
      *(undefined8 *)(puVar25 + 0x162) = 0;
      *(undefined8 *)(puVar25 + 0x160) = 0;
      *(undefined8 *)(puVar25 + 0x166) = 0;
      *(undefined8 *)(puVar25 + 0x164) = 0;
      *(undefined8 *)(puVar25 + 0x168) = 0;
      puVar25[0x16a] = 0;
      *(undefined8 *)(puVar25 + 0x16d) = 0;
      *(undefined8 *)(puVar25 + 0x16b) = 0;
      puVar25[0x129] = 0;
      *(undefined8 *)(puVar25 + 0x18d) = 0;
      puVar25[0x181] = *(byte *)(param_2 + 0x102) & 1;
      puVar25[0x182] = *(undefined4 *)((long)param_2 + 0x814);
      puVar25[0x183] = (int)param_2[0x103];
      puVar25[0x184] = *(undefined4 *)((long)param_2 + 0x81c);
      *(undefined8 *)(puVar25 + 0x187) = 0;
      *(undefined8 *)(puVar25 + 0x185) = 0;
      lVar13 = param_2[0x146];
      *(long *)(puVar25 + 0x196) = param_2[0x147];
      *(long *)(puVar25 + 0x194) = lVar13;
      *(undefined8 *)(puVar25 + 0x19e) = 0;
      *(undefined8 *)(puVar25 + 0x1a4) = 0;
      *(long *)(puVar25 + 0x198) = param_2[0x148];
      *(long *)(puVar25 + 0x19a) = param_2[0x149];
      if ((*(byte *)(param_1[2] + 0x5cd) >> 6 & 1) != 0) {
        *(long *)(puVar25 + 0x189) = param_2[0x11c];
        *(long *)(puVar25 + 0x18b) = param_2[0x11d];
      }
      puVar25[399] = *(byte *)((long)param_2 + 0x83b) & 1;
      lVar13 = param_2[0x104];
      *(long *)(puVar25 + 0x192) = param_2[0x105];
      *(long *)(puVar25 + 400) = lVar13;
      *(long *)(puVar25 + 0x16f) = lVar9;
      *(long *)(puVar25 + 0x171) = lVar21;
      puVar25[0x173] = iVar3;
      puVar25[0x174] = iVar4;
      puVar25[0x175] = (int)lVar22;
      puVar25[0x176] = uVar15;
      *(long *)(puVar25 + 0x177) = param_2[0x20];
      (**(code **)(*param_1 + 0x168))(*param_1 + 0x168,param_1,puVar25,param_2);
      (**(code **)(*param_1 + 0x188))
                (*param_1 + 0x188,param_1,puVar25,param_2,param_2[0x8f],param_2 + 0x10);
      lVar21 = param_2[0x8f];
      lVar22 = param_2[0x20];
      pcVar17 = *(code **)(*param_1 + 200);
    }
    (*pcVar17)(param_1,lVar21,puVar25,lVar22);
    if (param_1[0xc] != 0) {
      uVar24 = *(ulong *)(param_1[0xc] + 0x74);
      uVar11 = param_1[0x17];
      uVar10 = -uVar11;
      if (uVar24 < uVar11) {
        uVar10 = ~uVar11;
      }
      if (uVar24 + uVar10 != 0) {
        thunk_EXT_FUN_801100000320d864(1,0,0,((uVar24 + uVar10) * 0x7d) / 3,0);
        param_1[0x17] = uVar24;
      }
    }
    *(int *)(param_1 + 0x31) = iVar3;
  }
  return;
}

