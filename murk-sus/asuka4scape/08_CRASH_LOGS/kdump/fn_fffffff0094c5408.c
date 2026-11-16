// FUN_fffffff0094c5408 @ fffffff0094c5408 size=2428
// CALLERS:
//   fffffff00afb809c ?
//   fffffff0094c6b48 FUN_fffffff0094c6ac4@fffffff0094c6ac4
//   fffffff0094c172c FUN_fffffff0094c148c@fffffff0094c148c
// CALLS:
//   fffffff0094c5d84 FUN_fffffff0094c5d84
//   fffffff0094c6218 FUN_fffffff0094c6218
//   fffffff0094c602c FUN_fffffff0094c602c
//   fffffff0094c6150 FUN_fffffff0094c6150
//   fffffff0094c5e88 FUN_fffffff0094c5e88
//   fffffff0094c9a04 thunk_EXT_FUN_8011000003138628
//   fffffff0094c99e4 thunk_EXT_FUN_8011000003137b18
//   fffffff0094c9a14 thunk_EXT_FUN_80110000031387d4
//   fffffff0094c63b0 FUN_fffffff0094c63b0
//   fffffff0094c5218 FUN_fffffff0094c5218
//   fffffff0094c5f5c FUN_fffffff0094c5f5c
//   fffffff0094c6324 FUN_fffffff0094c6324
//   fffffff0094c99c4 thunk_EXT_FUN_8011000003a48590
//   fffffff0094c51c8 FUN_fffffff0094c51c8
//   fffffff0094c9bb4 thunk_EXT_FUN_80110000033502b4

undefined8 FUN_fffffff0094c5408(undefined8 *param_1,undefined8 *param_2,long param_3,long param_4)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  char cVar7;
  code *pcVar8;
  int iVar9;
  ulong uVar10;
  undefined8 uVar11;
  bool bVar12;
  undefined1 *local_190;
  undefined1 *local_188;
  ulong local_180;
  byte local_171;
  undefined1 *local_170;
  undefined1 *local_168;
  undefined1 *local_160;
  undefined1 *local_158;
  undefined1 *local_150;
  undefined1 *local_148;
  undefined1 *local_140;
  undefined1 *local_138;
  undefined1 *local_130;
  undefined1 *local_128;
  undefined1 *local_120;
  ulong local_118;
  undefined1 *local_110;
  undefined1 *puStack_108;
  undefined8 uStack_100;
  undefined8 uStack_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 uStack_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 uStack_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  long local_70;
  
  local_70 = *(long *)PTR_DAT_fffffff007f5bb60;
  local_120 = (undefined1 *)0x0;
  local_118 = 0;
  puVar1 = (undefined1 *)*param_2;
  puVar2 = (undefined1 *)param_2[1];
  if (puVar2 < puVar1) goto LAB_fffffff0094c54d0;
  param_1[1] = 0;
  *param_1 = 0;
  param_1[3] = 0;
  param_1[2] = 0;
  param_1[5] = 0;
  param_1[4] = 0;
  param_1[7] = 0;
  param_1[6] = 0;
  param_1[9] = 0;
  param_1[8] = 0;
  param_1[0xb] = 0;
  param_1[10] = 0;
  param_1[0xd] = 0;
  param_1[0xc] = 0;
  param_1[0xf] = 0;
  param_1[0xe] = 0;
  param_1[0x11] = 0;
  param_1[0x10] = 0;
  param_1[0x13] = 0;
  param_1[0x12] = 0;
  param_1[0x15] = 0;
  param_1[0x14] = 0;
  param_1[0x17] = 0;
  param_1[0x16] = 0;
  param_1[0x19] = 0;
  param_1[0x18] = 0;
  param_1[0x1b] = 0;
  param_1[0x1a] = 0;
  param_1[0x1d] = 0;
  param_1[0x1c] = 0;
  param_1[0x1f] = 0;
  param_1[0x1e] = 0;
  param_1[0x21] = 0;
  param_1[0x20] = 0;
  param_1[0x23] = 0;
  param_1[0x22] = 0;
  param_1[0x25] = 0;
  param_1[0x24] = 0;
  local_130 = puVar1;
  local_128 = puVar2;
  iVar9 = thunk_EXT_FUN_8011000003138628(&local_130,0x2000000000000010,&local_118);
  uVar11 = 0xb0013;
  if (iVar9 == 0) goto LAB_fffffff0094c5758;
  uVar10 = local_118 + ((long)local_130 - (long)puVar1);
  if (CARRY8(local_118,(long)local_130 - (long)puVar1)) {
                    /* WARNING: Does not return */
    pcVar8 = (code *)SoftwareBreakpoint(0x5500,0xfffffff0094c5c48);
    (*pcVar8)();
  }
  if ((ulong)((long)puVar2 - (long)puVar1) < uVar10) goto LAB_fffffff0094c54d0;
  param_1[2] = puVar1;
  param_1[3] = uVar10;
  if (CARRY8((ulong)local_130,local_118)) goto LAB_fffffff0094c5d3c;
  puVar1 = local_130 + local_118;
  if ((puVar1 < local_130) || (local_128 < puVar1)) goto LAB_fffffff0094c54d0;
  local_140 = local_130;
  local_150 = local_130;
  local_148 = puVar1;
  local_138 = puVar1;
  iVar9 = thunk_EXT_FUN_8011000003138628(&local_150,0xa000000000000000,&local_120);
  puVar2 = local_120;
  puVar1 = local_150;
  if (iVar9 != 0) {
    if (CARRY8((ulong)local_150,(ulong)local_120)) goto LAB_fffffff0094c5d3c;
    if (param_1 + 5 < param_1 + 4) goto LAB_fffffff0094c54d0;
    iVar9 = thunk_EXT_FUN_80110000031387d4(&local_150);
    uVar11 = 0xb0014;
    if ((iVar9 == 0) || (local_150 != puVar1 + (long)puVar2)) goto LAB_fffffff0094c5758;
    if (local_148 < puVar1 + (long)puVar2) goto LAB_fffffff0094c54d0;
    local_140 = local_150;
    local_138 = local_148;
  }
  iVar9 = thunk_EXT_FUN_8011000003138628(&local_140,2,&local_120);
  if (iVar9 == 0) {
    uVar11 = 0xb0015;
    goto LAB_fffffff0094c5758;
  }
  if ((local_138 < local_140) || (local_138 + -(long)local_140 < local_120))
  goto LAB_fffffff0094c54d0;
  param_1[0x11] = local_140;
  param_1[0x12] = local_120;
  if (CARRY8((ulong)local_140,(ulong)local_120)) goto LAB_fffffff0094c5d3c;
  puVar1 = local_140 + (long)local_120;
  if (((local_138 < puVar1) || (puVar1 < local_140)) ||
     (local_140 = puVar1, param_1 + 0x15 < param_1 + 0x13)) goto LAB_fffffff0094c54d0;
  iVar9 = FUN_fffffff0094c5218(&local_140);
  if (iVar9 == 0) {
    uVar11 = 0xb0016;
    goto LAB_fffffff0094c5758;
  }
  iVar9 = thunk_EXT_FUN_8011000003138628(&local_140,0x2000000000000010,&local_120);
  if (iVar9 == 0) {
    uVar11 = 0xb0017;
    goto LAB_fffffff0094c5758;
  }
  if ((local_138 < local_140) || (local_138 + -(long)local_140 < local_120))
  goto LAB_fffffff0094c54d0;
  param_1[0xf] = local_140;
  param_1[0x10] = local_120;
  if (CARRY8((ulong)local_140,(ulong)local_120)) goto LAB_fffffff0094c5d3c;
  puVar1 = local_140 + (long)local_120;
  if ((local_138 < puVar1) || (puVar1 < local_140)) goto LAB_fffffff0094c54d0;
  local_140 = puVar1;
  iVar9 = thunk_EXT_FUN_8011000003138628(&local_140,0x2000000000000010,&local_120);
  if (iVar9 == 0) {
    uVar11 = 0xb0018;
    goto LAB_fffffff0094c5758;
  }
  if ((local_138 < local_140) || (local_138 + -(long)local_140 < local_120))
  goto LAB_fffffff0094c54d0;
  param_1[9] = local_140;
  param_1[10] = local_120;
  if (CARRY8((ulong)local_140,(ulong)local_120)) goto LAB_fffffff0094c5d3c;
  puVar1 = local_140 + (long)local_120;
  if ((local_138 < puVar1) || (puVar1 < local_140)) goto LAB_fffffff0094c54d0;
  local_140 = puVar1;
  iVar9 = thunk_EXT_FUN_8011000003138628(&local_140,0x2000000000000010,&local_120);
  puVar1 = local_138;
  if (iVar9 == 0) {
    uVar11 = 0xb0019;
    goto LAB_fffffff0094c5758;
  }
  if ((local_138 < local_140) || (local_138 + -(long)local_140 < local_120))
  goto LAB_fffffff0094c54d0;
  param_1[0xd] = local_140;
  param_1[0xe] = local_120;
  if (CARRY8((ulong)local_140,(ulong)local_120)) goto LAB_fffffff0094c5d3c;
  puVar2 = local_140 + (long)local_120;
  if ((local_138 < puVar2) || (puVar2 < local_140)) goto LAB_fffffff0094c54d0;
  local_140 = puVar2;
  iVar9 = thunk_EXT_FUN_8011000003138628(&local_140,0x2000000000000010,&local_120);
  if (iVar9 == 0) {
    uVar11 = 0xb001a;
    goto LAB_fffffff0094c5758;
  }
  if (CARRY8((long)local_140 - (long)puVar2,(ulong)local_120)) {
                    /* WARNING: Does not return */
    pcVar8 = (code *)SoftwareBreakpoint(0x5500,0xfffffff0094c5d7c);
    (*pcVar8)();
  }
  if (puVar1 + -(long)puVar2 < local_120 + ((long)local_140 - (long)puVar2))
  goto LAB_fffffff0094c54d0;
  param_1[0xb] = puVar2;
  param_1[0xc] = local_120 + ((long)local_140 - (long)puVar2);
  if (CARRY8((ulong)local_140,(ulong)local_120)) goto LAB_fffffff0094c5d3c;
  puVar1 = local_140 + (long)local_120;
  if ((puVar1 < local_140) || (local_138 < puVar1)) goto LAB_fffffff0094c54d0;
  local_148 = local_138;
  local_150 = puVar1;
  local_140 = puVar1;
  uVar10 = thunk_EXT_FUN_8011000003138628(&local_150,0x8000000000000001,&local_120);
  if ((uVar10 & 1) != 0) {
    uVar11 = 0xb001b;
    goto LAB_fffffff0094c5758;
  }
  if (local_138 < local_140) goto LAB_fffffff0094c54d0;
  local_150 = local_140;
  local_148 = local_138;
  uVar10 = thunk_EXT_FUN_8011000003138628(&local_150,0x8000000000000002,&local_120);
  if ((uVar10 & 1) != 0) {
    uVar11 = 0xb001c;
    goto LAB_fffffff0094c5758;
  }
  if (local_138 < local_140) goto LAB_fffffff0094c54d0;
  local_150 = local_140;
  local_148 = local_138;
  iVar9 = thunk_EXT_FUN_8011000003138628(&local_150,0xa000000000000003,&local_120);
  puVar1 = local_140;
  if (iVar9 != 0) {
    if (CARRY8((ulong)local_150,(ulong)local_120)) goto LAB_fffffff0094c5d3c;
    puVar1 = local_150 + (long)local_120;
    if ((puVar1 < local_150) || (local_148 < puVar1)) goto LAB_fffffff0094c54d0;
    local_160 = local_150;
    local_158 = puVar1;
    iVar9 = thunk_EXT_FUN_8011000003138628(&local_160,0x2000000000000010,&local_120);
    if ((iVar9 != 0) && (local_120 != (undefined1 *)0x0)) {
      if (CARRY8((ulong)local_160,(ulong)local_120)) goto LAB_fffffff0094c5d3c;
      puVar1 = local_160 + (long)local_120;
      if ((puVar1 < local_160) || (local_158 < puVar1)) goto LAB_fffffff0094c54d0;
      *(undefined1 *)((long)param_1 + 0x10a) = 0;
      uStack_88 = 0;
      local_90 = 0;
      uStack_78 = 0;
      uStack_80 = 0;
      uStack_a8 = 0;
      local_b0 = 0;
      uStack_98 = 0;
      uStack_a0 = 0;
      uStack_c8 = 0;
      local_d0 = 0;
      uStack_b8 = 0;
      uStack_c0 = 0;
      uStack_e8 = 0;
      local_f0 = 0;
      uStack_d8 = 0;
      uStack_e0 = 0;
      puStack_108 = (undefined1 *)0x0;
      local_110 = (undefined1 *)0x0;
      uStack_f8 = 0;
      uStack_100 = 0;
      local_158 = puVar1;
      if (local_160 < puVar1) {
        cVar7 = '\0';
        bVar12 = false;
        bVar6 = false;
        bVar5 = false;
        bVar4 = false;
        bVar3 = false;
        do {
          local_170 = &DAT_aaaaaaaaaaaaaaaa;
          local_168 = &DAT_aaaaaaaaaaaaaaaa;
          local_171 = 0;
          local_180 = 0;
          iVar9 = thunk_EXT_FUN_8011000003138628(&local_160,0x2000000000000010,&local_180);
          if (iVar9 == 0) {
LAB_fffffff0094c5d50:
            uVar11 = 0xb001e;
            goto LAB_fffffff0094c5758;
          }
          if (CARRY8((ulong)local_160,local_180)) goto LAB_fffffff0094c5d3c;
          puVar1 = local_160 + local_180;
          if (puVar1 < local_160 || local_158 < puVar1) goto LAB_fffffff0094c54d0;
          local_190 = local_160;
          local_188 = puVar1;
          iVar9 = thunk_EXT_FUN_8011000003138628(&local_190,6,&local_120);
          if (iVar9 == 0) {
            uVar11 = 0xb001f;
            goto LAB_fffffff0094c5758;
          }
          if ((local_188 < local_190) || (local_188 + -(long)local_190 < local_120))
          goto LAB_fffffff0094c54d0;
          local_170 = local_190;
          local_168 = local_120;
          if (CARRY8((ulong)local_190,(ulong)local_120)) goto LAB_fffffff0094c5d3c;
          puVar1 = local_190 + (long)local_120;
          if ((local_188 < puVar1) || (puVar1 < local_190)) goto LAB_fffffff0094c54d0;
          local_190 = puVar1;
          iVar9 = FUN_fffffff0094c5d84(&local_190,&local_171);
          if (iVar9 == 0) {
            uVar11 = 0xb0020;
            goto LAB_fffffff0094c5758;
          }
          iVar9 = thunk_EXT_FUN_8011000003138628(&local_190,4,&local_120);
          if (iVar9 == 0) {
LAB_fffffff0094c5d60:
            uVar11 = 0xb0021;
            goto LAB_fffffff0094c5758;
          }
          if (CARRY8((ulong)local_190,(ulong)local_120)) goto LAB_fffffff0094c5d3c;
          if (local_188 != local_190 + (long)local_120) goto LAB_fffffff0094c5d60;
          if ((param_3 != 0 && param_4 != 0) &&
             (iVar9 = FUN_fffffff0094c51c8(&local_170,param_3,param_4), iVar9 == 0)) {
            if ((local_188 < local_190) || (local_188 + -(long)local_190 < local_120))
            goto LAB_fffffff0094c54d0;
            param_1[0x1f] = local_190;
            param_1[0x20] = local_120;
          }
          if (local_168 == (undefined1 *)0x3) {
            iVar9 = thunk_EXT_FUN_80110000033502b4(local_170,&DAT_fffffff007770833,3);
            if (iVar9 == 0) {
              uVar11 = 0xb0022;
              if ((bVar12) ||
                 (uVar10 = FUN_fffffff0094c5e88(&local_190,param_1 + 0x21), (uVar10 & 1) == 0))
              goto LAB_fffffff0094c5758;
              bVar12 = true;
            }
            else {
              if (local_168 != (undefined1 *)0x3) goto LAB_fffffff0094c5a94;
              iVar9 = thunk_EXT_FUN_80110000033502b4(local_170,&DAT_fffffff007770836,3);
              if (iVar9 == 0) {
                uVar11 = 0xb0023;
                if ((bVar3) ||
                   (uVar10 = FUN_fffffff0094c5f5c(&local_190,param_1 + 0x19,(long)param_1 + 0x109),
                   (uVar10 & 1) == 0)) goto LAB_fffffff0094c5758;
                bVar3 = true;
              }
              else {
                if (local_168 != (undefined1 *)0x3) goto LAB_fffffff0094c5a94;
                iVar9 = thunk_EXT_FUN_80110000033502b4(local_170,&DAT_fffffff007770839,3);
                if (iVar9 == 0) {
                  uVar11 = 0xb0024;
                  if ((bVar4) ||
                     (uVar10 = FUN_fffffff0094c602c(&local_190,param_1 + 0x15,param_1 + 0x16),
                     (uVar10 & 1) == 0)) goto LAB_fffffff0094c5758;
                  bVar4 = true;
                }
                else {
                  if (local_168 != (undefined1 *)0x3) goto LAB_fffffff0094c5a94;
                  iVar9 = thunk_EXT_FUN_80110000033502b4(local_170,&DAT_fffffff00777083c,3);
                  if (iVar9 == 0) {
                    uVar11 = 0xb0025;
                    if ((bVar5) ||
                       (uVar10 = FUN_fffffff0094c6150(&local_190,param_1 + 0x17,param_1 + 0x18),
                       (uVar10 & 1) == 0)) goto LAB_fffffff0094c5758;
                    bVar5 = true;
                  }
                  else {
                    if ((local_168 != (undefined1 *)0x3) ||
                       (iVar9 = thunk_EXT_FUN_80110000033502b4(local_170,&DAT_fffffff00777083f,3),
                       iVar9 != 0)) goto LAB_fffffff0094c5a94;
                    uVar11 = 0xb0026;
                    if ((bVar6) ||
                       (uVar10 = FUN_fffffff0094c6218(&local_190,param_1 + 0x1a,param_1 + 0x1b),
                       (uVar10 & 1) == 0)) goto LAB_fffffff0094c5758;
                    bVar6 = true;
                  }
                }
              }
            }
          }
          else {
LAB_fffffff0094c5a94:
            if ((local_168 < (undefined1 *)0x8) ||
               (iVar9 = thunk_EXT_FUN_80110000033502b4(local_170,&DAT_fffffff007770842,7),
               iVar9 != 0)) {
              if (CARRY8((ulong)local_190,(ulong)local_120)) goto LAB_fffffff0094c5d3c;
              puVar1 = local_190 + (long)local_120;
              if ((puVar1 < local_190) || (local_188 < puVar1)) goto LAB_fffffff0094c54d0;
              local_190 = puVar1;
              if ((local_171 & 1) != 0) {
                *(undefined1 *)((long)param_1 + 0x10a) = 1;
              }
            }
            else {
              iVar9 = FUN_fffffff0094c6324(&local_170,&local_110,cVar7);
              uVar11 = 0xb0028;
              if ((iVar9 == 0) ||
                 (iVar9 = FUN_fffffff0094c63b0
                                    (&local_190,local_170,local_168,param_1 + 0x1e,param_1 + 0x1f,
                                     param_3 != 0 && param_4 != 0), iVar9 == 0))
              goto LAB_fffffff0094c5758;
              if (cVar7 == -1) {
                    /* WARNING: Does not return */
                pcVar8 = (code *)SoftwareBreakpoint(0x5507,0xfffffff0094c5d84);
                (*pcVar8)();
              }
              cVar7 = cVar7 + '\x01';
            }
          }
          if (local_190 != local_188) goto LAB_fffffff0094c5d50;
          if (CARRY8((ulong)local_160,local_180)) goto LAB_fffffff0094c5d3c;
          puVar1 = local_160 + local_180;
          if ((puVar1 < local_160) || (local_158 < puVar1)) goto LAB_fffffff0094c54d0;
          local_160 = puVar1;
        } while (puVar1 < local_158);
      }
      if (local_160 == local_158) {
        if ((local_138 < local_160) || (puVar1 = local_158, local_160 < local_140))
        goto LAB_fffffff0094c54d0;
        goto LAB_fffffff0094c5c64;
      }
    }
    uVar11 = 0xb001d;
    goto LAB_fffffff0094c5758;
  }
LAB_fffffff0094c5c64:
  local_140 = puVar1;
  if ((ulong)param_1[4] < 3) {
    uVar11 = 0xb0013;
    if (local_140 != local_138) goto LAB_fffffff0094c5758;
  }
  else {
    if (((undefined1 *)param_2[1] < local_138) || (local_138 < (undefined1 *)*param_2))
    goto LAB_fffffff0094c54d0;
    *param_2 = local_138;
  }
  if (CARRY8((ulong)local_130,local_118)) {
LAB_fffffff0094c5d3c:
                    /* WARNING: Does not return */
    pcVar8 = (code *)SoftwareBreakpoint(0x5513,0xfffffff0094c5d40);
    (*pcVar8)();
  }
  puVar1 = local_130 + local_118;
  if ((puVar1 < local_130) || (local_128 < puVar1)) goto LAB_fffffff0094c54d0;
  local_130 = puVar1;
  iVar9 = FUN_fffffff0094c5218(&local_130,param_1 + 5);
  if (iVar9 == 0) {
    uVar11 = 0xb0029;
  }
  else {
    local_110 = &DAT_aaaaaaaaaaaaaaaa;
    puStack_108 = &DAT_aaaaaaaaaaaaaaaa;
    local_160 = (undefined1 *)0x0;
    iVar9 = thunk_EXT_FUN_8011000003137b18(&local_130,&local_110,&local_160);
    if (iVar9 != 0) {
      if ((undefined1 *)0xfffffffffffffff8 < local_160) {
                    /* WARNING: Does not return */
        pcVar8 = (code *)SoftwareBreakpoint(0x5500,0xfffffff0094c5d80);
        (*pcVar8)();
      }
      if ((local_110 <= puStack_108) &&
         ((ulong)(local_160 + 7) >> 3 <= (ulong)((long)puStack_108 - (long)local_110))) {
        param_1[7] = local_110;
        param_1[8] = (ulong)(local_160 + 7) >> 3;
        if (local_130 <= local_128) {
          *param_2 = local_130;
          param_2[1] = local_128;
          uVar11 = 0;
          goto LAB_fffffff0094c5758;
        }
      }
LAB_fffffff0094c54d0:
                    /* WARNING: Does not return */
      pcVar8 = (code *)SoftwareBreakpoint(0x5519,0xfffffff0094c54d4);
      (*pcVar8)();
    }
    uVar11 = 0xb002a;
  }
LAB_fffffff0094c5758:
  if (*(long *)PTR_DAT_fffffff007f5bb60 == local_70) {
    return uVar11;
  }
  uVar11 = thunk_EXT_FUN_8011000003a48590();
  return uVar11;
}

