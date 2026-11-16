// FUN_fffffff0081a3264 @ fffffff0081a3264 size=4216

void FUN_fffffff0081a3264(long *param_1)

{
  long *plVar1;
  byte bVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  undefined8 uVar15;
  long *plVar16;
  ulong uVar17;
  ulong uVar18;
  undefined8 in_x6;
  undefined8 in_x7;
  long lVar19;
  long lVar20;
  undefined1 uVar21;
  long lVar22;
  uint uVar23;
  uint uVar24;
  undefined8 *puVar25;
  long *plVar26;
  undefined8 uVar27;
  uint uVar28;
  undefined8 uVar29;
  undefined8 uVar30;
  undefined8 uVar31;
  undefined8 uVar32;
  undefined8 uVar33;
  int local_150;
  uint uStack_14c;
  uint uStack_148;
  uint uStack_144;
  uint uStack_140;
  ushort local_13c;
  undefined2 uStack_13a;
  undefined4 uStack_138;
  undefined4 uStack_134;
  undefined8 local_130;
  undefined8 uStack_128;
  undefined8 uStack_120;
  undefined8 uStack_118;
  undefined8 local_110;
  uint local_100;
  uint uStack_fc;
  undefined8 local_f8;
  ulong local_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 uStack_d0;
  undefined8 uStack_c8;
  undefined *local_c0;
  undefined8 local_b8;
  code *local_b0;
  undefined *local_a8;
  long lStack_a0;
  uint local_98;
  undefined4 local_90;
  undefined4 local_8c [3];
  
  lVar19 = param_1[0xf8];
  if (lVar19 == 0) {
LAB_fffffff0081a4138:
    thunk_EXT_FUN_8011000003a49114("AGXk: %s:%d:%s: !!! Using uninitialized validator class\n");
    return;
  }
  uVar4 = *(uint *)param_1[0xf7];
  *(uint *)(param_1 + 0xf9) = uVar4;
  uVar5 = ((uint *)param_1[0xf7])[8];
  *(uint *)((long)param_1 + 0x7cc) = uVar5;
  uVar11 = DAT_fffffff007113ee0;
  uVar10 = DAT_fffffff007113e50;
  if (((ulong)param_1[0xfb] <= (ulong)uVar4) || ((ulong)param_1[0xfb] <= (ulong)uVar5)) {
    thunk_EXT_FUN_8011000003a49114("AGXk: %s:%d:%s: !!! read_index out of bounds\n");
    return;
  }
  bVar9 = false;
  plVar1 = param_1 + 0xf6;
LAB_fffffff0081a3328:
  if (lVar19 == 0) goto LAB_fffffff0081a4138;
  if ((int)param_1[0xf9] == *(int *)((long)param_1 + 0x7cc)) {
    if (bVar9) {
      lVar19 = param_1[0x50];
      thunk_EXT_FUN_801100000294cf74(*(undefined8 *)(lVar19 + 0x158));
      thunk_EXT_FUN_8011000002970f9c(lVar19);
      iVar14 = thunk_EXT_FUN_80110000029477a8(*(undefined8 *)(lVar19 + 0x148));
      if (iVar14 != 0) {
        if ((*(byte *)(lVar19 + 0x520) & 1) == 0) {
          *(undefined1 *)(lVar19 + 0x520) = 1;
          (**(code **)(**(long **)(lVar19 + 0x518) + 0xf0))
                    (*(long **)(lVar19 + 0x518),*(undefined1 *)(lVar19 + 0x654));
        }
        if (((*(byte *)(lVar19 + 0x531) & 1) != 0) && ((*(byte *)(lVar19 + 0x530) & 1) == 0)) {
          *(undefined1 *)(lVar19 + 0x530) = 1;
          (**(code **)(**(long **)(lVar19 + 0x528) + 0xf0))
                    (*(long **)(lVar19 + 0x528),*(undefined1 *)(lVar19 + 0x658));
        }
        (**(code **)(**(long **)(lVar19 + 0x111b0) + 0xd8))();
      }
      lVar19 = param_1[0x50];
      if ((*(byte *)(lVar19 + 0x5b8) & 1) != 0) {
        uVar18 = thunk_EXT_FUN_801100000294780c(*(undefined8 *)(lVar19 + 0x148));
        if ((uVar18 & 1) == 0) {
          (**(code **)(**(long **)(lVar19 + 0x4b0) + 0x3b8))();
          thunk_EXT_FUN_8011000003204ed8(*(undefined4 *)(lVar19 + 0x23c),1000000000,lVar19 + 0x5c0);
          thunk_EXT_FUN_801100000295f33c
                    (*(undefined8 *)(lVar19 + 0x160),*(undefined8 *)(lVar19 + 0x5c0));
        }
        else {
          thunk_EXT_FUN_801100000295f3b0(*(undefined8 *)(lVar19 + 0x160));
          *(undefined1 *)(lVar19 + 0x5b8) = 0;
        }
      }
    }
    return;
  }
  local_110 = 0;
  uStack_128 = 0;
  local_130 = 0;
  uStack_118 = 0;
  uStack_120 = 0;
  uStack_148 = 0;
  uStack_144 = 0;
  local_150 = 0;
  uStack_14c = 0;
  uStack_138 = 0;
  uStack_134 = 0;
  uStack_140 = 0;
  local_13c = 0;
  uStack_13a = 0;
  uVar13 = FUN_fffffff0081b7c6c(plVar1,&local_150);
  uVar12 = uStack_140;
  uVar23 = uStack_144;
  uVar5 = uStack_148;
  uVar4 = uStack_14c;
  if (0xe < uVar13) goto code_r0xfffffff0081a3324;
  switch(uVar13) {
  default:
    if (local_150 != 0) goto LAB_fffffff0081a420c;
    (**(code **)(*param_1 + 0x7c8))(param_1,&local_150);
    lVar19 = param_1[0xf8];
    goto LAB_fffffff0081a3328;
  case 1:
    if (local_150 != 1) goto LAB_fffffff0081a420c;
    if (5 < local_13c) goto LAB_fffffff0081a4148;
    lVar19 = param_1[0x50];
    uVar15 = thunk_EXT_FUN_8011000003397c88();
    *(undefined8 *)(lVar19 + 0x1ac30) = uVar15;
    for (uVar13 = uVar4; uVar28 = uVar5, uVar13 != 0;
        uVar13 = uVar13 & (1 << (ulong)((uint)lVar20 & 0x1f) ^ 0xffffffffU)) {
      uVar28 = (uVar13 & 0xaaaaaaaa) >> 1 | (uVar13 & 0x55555555) << 1;
      uVar28 = (uVar28 & 0xcccccccc) >> 2 | (uVar28 & 0x33333333) << 2;
      uVar28 = (uVar28 & 0xf0f0f0f0) >> 4 | (uVar28 & 0xf0f0f0f) << 4;
      uVar28 = (uVar28 & 0xff00ff00) >> 8 | (uVar28 & 0xff00ff) << 8;
      lVar20 = LZCOUNT(uVar28 >> 0x10 | uVar28 << 0x10);
      thunk_EXT_FUN_8011000002946e48(*(undefined8 *)(lVar19 + 0x148),lVar20,0);
    }
    for (; uVar13 = uVar23, uVar28 != 0;
        uVar28 = uVar28 & (1 << (ulong)(uVar13 & 0x1f) ^ 0xffffffffU)) {
      uVar13 = (uVar28 & 0xaaaaaaaa) >> 1 | (uVar28 & 0x55555555) << 1;
      uVar13 = (uVar13 & 0xcccccccc) >> 2 | (uVar13 & 0x33333333) << 2;
      uVar13 = (uVar13 & 0xf0f0f0f0) >> 4 | (uVar13 & 0xf0f0f0f) << 4;
      uVar13 = (uVar13 & 0xff00ff00) >> 8 | (uVar13 & 0xff00ff) << 8;
      uVar13 = (uint)LZCOUNT(uVar13 >> 0x10 | uVar13 << 0x10);
      thunk_EXT_FUN_8011000002946e48(*(undefined8 *)(lVar19 + 0x148),uVar13 | 0x20,0);
    }
    for (; uVar28 = uVar12, uVar13 != 0;
        uVar13 = uVar13 & (1 << (ulong)(uVar28 & 0x1f) ^ 0xffffffffU)) {
      uVar28 = (uVar13 & 0xaaaaaaaa) >> 1 | (uVar13 & 0x55555555) << 1;
      uVar28 = (uVar28 & 0xcccccccc) >> 2 | (uVar28 & 0x33333333) << 2;
      uVar28 = (uVar28 & 0xf0f0f0f0) >> 4 | (uVar28 & 0xf0f0f0f) << 4;
      uVar28 = (uVar28 & 0xff00ff00) >> 8 | (uVar28 & 0xff00ff) << 8;
      uVar28 = (uint)LZCOUNT(uVar28 >> 0x10 | uVar28 << 0x10);
      thunk_EXT_FUN_8011000002946e48(*(undefined8 *)(lVar19 + 0x148),uVar28 | 0x40,0);
    }
    for (; uVar28 != 0; uVar28 = uVar28 & (1 << (ulong)(uVar13 & 0x1f) ^ 0xffffffffU)) {
      uVar13 = (uVar28 & 0xaaaaaaaa) >> 1 | (uVar28 & 0x55555555) << 1;
      uVar13 = (uVar13 & 0xcccccccc) >> 2 | (uVar13 & 0x33333333) << 2;
      uVar13 = (uVar13 & 0xf0f0f0f0) >> 4 | (uVar13 & 0xf0f0f0f) << 4;
      uVar13 = (uVar13 & 0xff00ff00) >> 8 | (uVar13 & 0xff00ff) << 8;
      uVar13 = (uint)LZCOUNT(uVar13 >> 0x10 | uVar13 << 0x10);
      thunk_EXT_FUN_8011000002946e48(*(undefined8 *)(lVar19 + 0x148),uVar13 | 0x60,0);
    }
    bVar9 = (bool)(bVar9 | ((uVar5 != 0 || uVar4 != 0) || (uVar12 != 0 || uVar23 != 0)));
    lVar19 = param_1[0xf8];
    goto LAB_fffffff0081a3328;
  case 2:
  case 3:
  case 5:
  case 9:
  case 0xd:
    break;
  case 4:
    if (local_150 != 4) goto LAB_fffffff0081a420c;
    iVar14 = thunk_EXT_FUN_8011000002946bb0(*(undefined8 *)(*plVar1 + 0x148));
    if ((uVar23 != 0xffffffff) && (iVar14 <= (int)uVar23 || 0x7fffffff < uVar23))
    goto LAB_fffffff0081a4148;
    iVar14 = (**(code **)(*param_1 + 0x108))(param_1,(ulong)&local_150 | 4);
    if (iVar14 != 0) {
      thunk_EXT_FUN_8011000003a49114
                (
                "AGXk: %s:%d:%s: !!! Stale recovery packet is received from firmware. Firmware should never send stale recovery packets.\n"
                );
      return;
    }
    lVar19 = param_1[0x122];
    uVar6 = *(undefined4 *)(lVar19 + 0x4b28);
    iVar14 = *(int *)(lVar19 + 0x4b2c);
    bVar2 = 0;
    if (*(int *)(lVar19 + 0x4b1c) != 0) {
      bVar2 = 8;
    }
    *(byte *)(param_1[0x50] + 0x18b68) = *(byte *)(param_1[0x50] + 0x18b68) & 0xf7 | bVar2;
    lVar20 = param_1[0x50];
    *(undefined8 *)(lVar20 + 0x18ab8) = *(undefined8 *)(lVar19 + 0x4b30);
    *(undefined4 *)(lVar20 + 0x18ac8) = *(undefined4 *)(lVar19 + 0x4b38);
    *(undefined8 *)(param_1[0x50] + 0x18ac0) = *(undefined8 *)(lVar19 + 0x4b3c);
    lVar20 = param_1[0x50];
    uVar15 = *(undefined8 *)(lVar19 + 0x4b44);
    uVar29 = *(undefined8 *)(lVar19 + 0x4b5c);
    uVar27 = *(undefined8 *)(lVar19 + 0x4b54);
    *(undefined8 *)(lVar20 + 0x18ad8) = *(undefined8 *)(lVar19 + 0x4b4c);
    *(undefined8 *)(lVar20 + 0x18ad0) = uVar15;
    *(undefined8 *)(lVar20 + 0x18ae8) = uVar29;
    *(undefined8 *)(lVar20 + 0x18ae0) = uVar27;
    uVar27 = *(undefined8 *)(lVar19 + 0x4b6c);
    uVar15 = *(undefined8 *)(lVar19 + 0x4b64);
    uVar30 = *(undefined8 *)(lVar19 + 0x4b7c);
    uVar29 = *(undefined8 *)(lVar19 + 0x4b74);
    uVar31 = *(undefined8 *)(lVar19 + 0x4b84);
    uVar33 = *(undefined8 *)(lVar19 + 0x4b9c);
    uVar32 = *(undefined8 *)(lVar19 + 0x4b94);
    *(undefined8 *)(lVar20 + 0x18b18) = *(undefined8 *)(lVar19 + 0x4b8c);
    *(undefined8 *)(lVar20 + 0x18b10) = uVar31;
    *(undefined8 *)(lVar20 + 0x18b28) = uVar33;
    *(undefined8 *)(lVar20 + 0x18b20) = uVar32;
    *(undefined8 *)(lVar20 + 0x18af8) = uVar27;
    *(undefined8 *)(lVar20 + 0x18af0) = uVar15;
    *(undefined8 *)(lVar20 + 0x18b08) = uVar30;
    *(undefined8 *)(lVar20 + 0x18b00) = uVar29;
    uVar27 = *(undefined8 *)(lVar19 + 0x4bac);
    uVar15 = *(undefined8 *)(lVar19 + 0x4ba4);
    uVar30 = *(undefined8 *)(lVar19 + 0x4bbc);
    uVar29 = *(undefined8 *)(lVar19 + 0x4bb4);
    uVar32 = *(undefined8 *)(lVar19 + 0x4bcc);
    uVar31 = *(undefined8 *)(lVar19 + 0x4bc4);
    *(undefined8 *)(lVar20 + 0x18b60) = *(undefined8 *)(lVar19 + 0x4bd4);
    *(undefined8 *)(lVar20 + 0x18b48) = uVar30;
    *(undefined8 *)(lVar20 + 0x18b40) = uVar29;
    *(undefined8 *)(lVar20 + 0x18b58) = uVar32;
    *(undefined8 *)(lVar20 + 0x18b50) = uVar31;
    *(undefined8 *)(lVar20 + 0x18b38) = uVar27;
    *(undefined8 *)(lVar20 + 0x18b30) = uVar15;
    lVar19 = param_1[0x50];
    if (iVar14 < 3) {
      if (iVar14 != 1) {
        if (iVar14 == 2) {
          uVar21 = 4;
        }
        else {
LAB_fffffff0081a3ce8:
          uVar21 = 2;
        }
        goto LAB_fffffff0081a3cec;
      }
    }
    else {
      if (iVar14 == 3) {
        uVar21 = 5;
      }
      else if (iVar14 == 5) {
        uVar21 = 7;
      }
      else {
        if (iVar14 != 4) goto LAB_fffffff0081a3ce8;
        uVar21 = 6;
      }
LAB_fffffff0081a3cec:
      *(undefined1 *)(lVar19 + 0x189e8) = uVar21;
    }
    *(undefined4 *)(lVar19 + 0x189e0) = uVar6;
    uVar4 = 0x80;
    if (uStack_144 != 0xffffffff) {
      uVar4 = uStack_144;
    }
    *(uint *)(lVar19 + 0x189e4) = uVar4;
    thunk_EXT_FUN_801100000295e8ec(*(undefined8 *)(lVar19 + 0x160),1);
    lVar19 = param_1[0xf8];
    goto LAB_fffffff0081a3328;
  case 6:
    if (*(char *)(param_1[0x50] + 0x189e8) == '\0') {
      if (local_150 != 6) goto LAB_fffffff0081a420c;
      iVar14 = (**(code **)(*(long *)*plVar1 + 0x778))();
      uVar13 = uStack_140;
      uVar12 = uStack_144;
      uVar23 = uStack_148;
      uVar5 = uStack_14c;
      if ((((uVar4 != 0xffffffff) && (iVar14 <= (int)uVar4 || 0x7fffffff < uVar4)) ||
          (0x7e < uStack_148)) || (3 < uStack_140)) goto LAB_fffffff0081a4148;
      uVar15 = CONCAT44(uStack_138,CONCAT22(uStack_13a,local_13c));
      lVar19 = param_1[0x50];
      while ((*(int *)(lVar19 + 0x182d4) + 1U & 7) == *(uint *)(lVar19 + 0x182d0)) {
        thunk_EXT_FUN_80110000038fe968(100);
      }
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar19 + 0x183a0));
      lVar20 = (ulong)*(uint *)(lVar19 + 0x182d4) * 0x20;
      puVar25 = (undefined8 *)(lVar19 + 0x181d0 + (long)(int)lVar20);
      if (lVar20 - (int)lVar20 != 0) {
        puVar25 = (undefined8 *)(lVar19 + 0x181d0 + lVar20 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar25 = 0;
      *(uint *)(puVar25 + 1) = uVar23;
      *(uint *)((long)puVar25 + 0xc) = uVar5;
      *(uint *)(puVar25 + 2) = uVar12;
      *(uint *)((long)puVar25 + 0x14) = uVar13;
      puVar25[3] = uVar15;
      *(uint *)(lVar19 + 0x182d4) = *(int *)(lVar19 + 0x182d4) + 1U & 7;
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar19 + 0x183a0));
      (**(code **)(**(long **)(param_1[0x50] + 0x398) + 0xf8))
                (*(long **)(param_1[0x50] + 0x398),0,0,0);
      lVar19 = param_1[0xf8];
      goto LAB_fffffff0081a3328;
    }
    break;
  case 7:
    if (local_150 != 7) goto LAB_fffffff0081a420c;
    if ((4 < uStack_14c) || (2 < uStack_148)) {
LAB_fffffff0081a4148:
      thunk_EXT_FUN_8011000003a49114("AGXk: %s:%d:%s: !!! Ring entry contains bad data\n");
      return;
    }
    iVar14 = thunk_EXT_FUN_8011000002946bb0(*(undefined8 *)(*plVar1 + 0x148));
    uVar13 = uStack_140;
    uVar12 = uStack_144;
    uVar5 = uStack_148;
    uVar4 = uStack_14c;
    if ((uVar23 != 0xffffffff) && (iVar14 <= (int)uVar23 || 0x7fffffff < uVar23))
    goto LAB_fffffff0081a4148;
    uVar18 = (ulong)uStack_14c;
    uVar17 = (ulong)uStack_148;
    uVar15 = thunk_EXT_FUN_8011000002949050(param_1[0x51],uStack_144);
    lVar19 = thunk_EXT_FUN_8011000003890f30(uVar15,&DAT_fffffff00ae255c0);
    if (lVar19 == 0) {
      thunk_EXT_FUN_8011000003a49114
                (
                "AGXk: %s:%d:%s: !!! handleChannelErrorEvent: Type confusion - invalid AGXChannel for firmware stamp_idx %u\n"
                );
      return;
    }
    if ((int)uVar4 < 2) {
      if (uVar4 == 0) {
        thunk_EXT_FUN_80110000039b5664
                  (*(undefined8 *)(*(long *)(param_1[0x50] + 0x1ac50) + 0xb0),0x4d454d4641494c,1);
        lVar20 = param_1[0x50];
        if ((*(byte *)(lVar20 + 0x1ac44) >> 3 & 1) != 0) {
          thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar20 + 0x1ac48));
          thunk_EXT_FUN_80110000036da494(0x85930c90,lVar19,uVar13,uVar12,0,0);
          thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar20 + 0x1ac48));
        }
        uVar18 = 0xd;
      }
      else {
        if (uVar4 != 1) {
LAB_fffffff0081a42b4:
          thunk_EXT_FUN_8011000003a49114("AGXk: %s:%d:%s: !!! ChannelError of unknown type! (%d)\n")
          ;
          return;
        }
        lVar20 = *(long *)(param_1[0x50] + 0x1ac50);
        if (uVar5 < 3) {
          lVar22 = uVar17 * 8;
          pcVar3 = "LLIKPTG" + (int)lVar22;
          if (lVar22 - (int)lVar22 != 0) {
            pcVar3 = (char *)((ulong)("LLIKPTG" + lVar22) & 0xffffffffffff | 0x2bad000000000000);
          }
          thunk_EXT_FUN_80110000039b5664(*(undefined8 *)(lVar20 + 0xb0),*(undefined8 *)pcVar3,1);
        }
        thunk_EXT_FUN_80110000039b5664(*(undefined8 *)(lVar20 + 0xb0),0x444d4b494c4c,1);
        lVar20 = param_1[0x50];
        if ((*(byte *)(lVar20 + 0x1ac44) >> 3 & 1) != 0) {
          thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar20 + 0x1ac48));
          thunk_EXT_FUN_80110000036da494(0x85930c4c,uVar17,lVar19,uVar13,uVar12,0);
          thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar20 + 0x1ac48));
        }
        uVar18 = 0xe;
      }
    }
    else if (uVar4 != 2) {
      if (uVar4 == 3) {
        lVar20 = param_1[0x50];
        if ((*(byte *)(lVar20 + 0x1ac44) >> 3 & 1) != 0) {
          thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar20 + 0x1ac48));
          thunk_EXT_FUN_80110000036da494(0x85930d1c,lVar19,uVar13,uVar12,0,0);
          thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar20 + 0x1ac48));
        }
      }
      else if (uVar4 != 4) goto LAB_fffffff0081a42b4;
      uVar18 = 8;
    }
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar19 + 0x170));
    if ((*(long *)(lVar19 + 0x168) == 0) ||
       (uVar17 = thunk_EXT_FUN_801100000294991c(), (uVar17 & 1) == 0)) {
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar19 + 0x170));
    }
    else {
      plVar16 = *(long **)(lVar19 + 0x168);
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar19 + 0x170));
      if (plVar16 != (long *)0x0) {
        uVar23 = *(uint *)((long)plVar16 + 0x4c);
        uVar28 = uVar23 - *(uint *)(plVar16 + 9);
        if (uVar23 != *(uint *)(plVar16 + 9)) {
          uVar7 = *(uint *)((long)plVar16 + 0x54);
          uVar24 = 1;
LAB_fffffff0081a3c6c:
          uVar23 = uVar23 - 1;
          uVar8 = 0;
          if (uVar7 != 0) {
            uVar8 = uVar23 / uVar7;
          }
          lVar20 = (ulong)(uVar23 - uVar8 * uVar7) * 8;
          plVar26 = (long *)(plVar16[0xb] + (long)(int)lVar20);
          if (lVar20 != (int)lVar20) {
            plVar26 = (long *)(plVar16[0xb] + lVar20 & 0xffffffffffffU | 0x2bad000000000000);
          }
          lVar20 = *plVar26;
          if (lVar20 != 0) {
            if ((*(uint *)(lVar20 + 0x84) & 0xffffff00) == uVar13 &&
                (int)(char)*(uint *)(lVar20 + 0x84) == uVar12) goto LAB_fffffff0081a3d20;
            if (*(int *)(lVar20 + 0x88) == 0xff) goto LAB_fffffff0081a3c58;
            if ((int)(char)*(uint *)(lVar20 + 0x88) == uVar12 &&
                (*(uint *)(lVar20 + 0x88) & 0xffffff00) == uVar13 || uVar28 <= uVar24)
            goto LAB_fffffff0081a3d20;
LAB_fffffff0081a3c60:
            uVar24 = uVar24 + 1;
            goto LAB_fffffff0081a3c6c;
          }
LAB_fffffff0081a3c58:
          if (uVar24 < uVar28) goto LAB_fffffff0081a3c60;
          if (lVar20 == 0) goto LAB_fffffff0081a3e28;
LAB_fffffff0081a3d20:
          plVar26 = *(long **)(lVar20 + 0x230);
          local_c0 = PTR_DAT_fffffff007ca5f90;
          local_b8 = uVar10;
          local_b0 = FUN_fffffff0081a4318;
          local_a8 = &DAT_fffffff007c95498;
          local_98 = uVar4;
          lStack_a0 = lVar20;
          if (plVar26 != (long *)0x0) {
            thunk_EXT_FUN_801100000294e120(&local_a8,plVar26);
            lVar22 = (**(code **)(*plVar26 + 0x80))(plVar26);
            uVar15 = (**(code **)(*plVar26 + 0x98))(plVar26);
            if (lVar22 != 0) {
              (*local_b0)(&local_c0,lVar22,uVar15);
              (**(code **)(*plVar26 + 0x88))(plVar26);
            }
            thunk_EXT_FUN_801100000294e12c(plVar26);
          }
          lVar20 = *(long *)(lVar20 + 0x68);
          if ((lVar20 != 0) && (*(int *)(lVar20 + 200) == 0)) {
            *(int *)(lVar20 + 200) = (int)uVar18;
          }
        }
LAB_fffffff0081a3e28:
        (**(code **)(*plVar16 + 0x28))(plVar16);
      }
    }
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ca61a8,0x10,"AGX: Channel error %u");
    uStack_d8 = 0;
    local_e0 = 0;
    uStack_c8 = 0;
    uStack_d0 = 0;
    uStack_e8 = 0;
    local_100 = 9;
    uStack_fc = uVar5;
    local_f8 = *(undefined8 *)(lVar19 + 0x98);
    local_f0 = (ulong)uVar13;
    local_8c[0] = 1;
    uVar15 = (**(code **)(param_1[0x109] + 0x30))(param_1 + 0x109);
    local_90 = 0;
    puVar25 = (undefined8 *)(**(long **)(param_1[0x50] + 0x310) + 0xe8);
    iVar14 = (*(code *)*puVar25)(puVar25,*(long **)(param_1[0x50] + 0x310),FUN_fffffff00817ea94,
                                 &local_100,local_8c,&local_90,0,in_x6,in_x7,uVar18);
    if ((iVar14 == 0) && (((byte)local_8c[0] >> 1 & 1) != 0)) {
      FUN_fffffff0081a43cc(param_1,uVar15,local_90);
      lVar19 = param_1[0xf8];
      goto LAB_fffffff0081a3328;
    }
    break;
  case 8:
    if (local_150 != 8) goto LAB_fffffff0081a420c;
    local_100 = uStack_14c;
    plVar16 = (long *)param_1[0x17d];
    if (plVar16 != (long *)0x0) {
      local_c0 = (undefined *)CONCAT71(local_c0._1_7_,2);
      (**(code **)(*plVar16 + 0x80))(plVar16,&local_c0,&local_100,0);
      lVar19 = param_1[0xf8];
      goto LAB_fffffff0081a3328;
    }
    break;
  case 10:
    if (local_150 != 10) goto LAB_fffffff0081a420c;
    if (CONCAT44(uStack_148,uStack_14c) == 0) goto LAB_fffffff0081a4148;
    if (CONCAT22(uStack_13a,local_13c) != 0) {
      *(undefined1 *)(*(long *)(param_1[0x50] + 0x11d98) + 0xc) = 1;
    }
    thunk_EXT_FUN_8011000002c32664(*(undefined8 *)(param_1[0x50] + 0xf8));
    lVar19 = param_1[0xf8];
    goto LAB_fffffff0081a3328;
  case 0xb:
    if (local_150 != 0xb) {
LAB_fffffff0081a420c:
      thunk_EXT_FUN_8011000003a49114
                ("AGXk: %s:%d:%s: !!! Ring is processing event of incorrect type\n");
      return;
    }
    iVar14 = (**(code **)(*(long *)*plVar1 + 0x778))();
    if (((uVar4 != 0xffffffff) && (iVar14 <= (int)uVar4 || 0x7fffffff < uVar4)) ||
       (lVar19 = CONCAT44(uStack_140,uStack_144), lVar19 == 0)) goto LAB_fffffff0081a4148;
    uVar15 = CONCAT44(uStack_148,uStack_14c);
    lVar20 = param_1[0x50];
    uVar27 = *(undefined8 *)(lVar20 + 0x588);
    while ((*(int *)(lVar20 + 0x182d4) + 1U & 7) == *(uint *)(lVar20 + 0x182d0)) {
      thunk_EXT_FUN_80110000038fe968(100);
    }
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar20 + 0x183a0));
    lVar22 = (ulong)*(uint *)(lVar20 + 0x182d4) * 0x20;
    puVar25 = (undefined8 *)(lVar20 + 0x181d0 + (long)(int)lVar22);
    if (lVar22 - (int)lVar22 != 0) {
      puVar25 = (undefined8 *)(lVar20 + 0x181d0 + lVar22 & 0xffffffffffffU | 0x2bad000000000000);
    }
    *puVar25 = uVar11;
    puVar25[1] = uVar15;
    puVar25[2] = lVar19;
    puVar25[3] = uVar27;
    *(uint *)(lVar20 + 0x182d4) = *(int *)(lVar20 + 0x182d4) + 1U & 7;
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar20 + 0x183a0));
    (**(code **)(**(long **)(param_1[0x50] + 0x398) + 0xf8))
              (*(long **)(param_1[0x50] + 0x398),0,0,0);
    lVar19 = param_1[0xf8];
    goto LAB_fffffff0081a3328;
  case 0xc:
    if (local_150 != 0xc) goto LAB_fffffff0081a420c;
    if (*(long *)(param_1[0x50] + 0x1acb0) == 0) break;
    lVar19 = CONCAT44(uStack_148,uStack_14c);
    plVar16 = (long *)thunk_EXT_FUN_801100000294082c(*(long *)(param_1[0x50] + 0x1acb0),lVar19);
    thunk_EXT_FUN_8011000002940a04(*(undefined8 *)(param_1[0x50] + 0x1acb0),lVar19);
    if ((plVar16 == (long *)0x0) || (plVar16[0x128] != lVar19)) break;
    lVar20 = param_1[0x50];
    if ((*(byte *)(lVar20 + 0x1ac44) >> 3 & 1) != 0) {
      iVar14 = (**(code **)(*plVar16 + 0x18))(plVar16);
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar20 + 0x1ac48));
      thunk_EXT_FUN_80110000036da494(0x85930d30,plVar16,lVar19,(long)iVar14,0,0);
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar20 + 0x1ac48));
    }
    (**(code **)(*plVar16 + 0x28))(plVar16);
    lVar19 = param_1[0xf8];
    goto LAB_fffffff0081a3328;
  case 0xe:
    if (local_150 != 0xe) goto LAB_fffffff0081a420c;
    thunk_EXT_FUN_801100000294ce50
              (*(undefined8 *)(param_1[0x50] + 0x158),CONCAT44(uStack_148,uStack_14c));
  }
code_r0xfffffff0081a3324:
  lVar19 = param_1[0xf8];
  goto LAB_fffffff0081a3328;
}

