// FUN_fffffff00a70f218 @ fffffff00a70f218 size=8924

/* WARNING: Removing unreachable block (ram,0xfffffff00a70fe0c) */
/* WARNING: Type propagation algorithm not settling */

ulong FUN_fffffff00a70f218(long param_1,ulong *param_2,int *param_3)

{
  ulong *puVar1;
  byte *pbVar2;
  undefined1 uVar3;
  ushort uVar4;
  uint uVar5;
  ushort uVar6;
  undefined2 uVar7;
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  long lVar10;
  bool bVar11;
  bool bVar12;
  long lVar13;
  undefined4 uVar14;
  bool bVar15;
  bool bVar16;
  int iVar17;
  uint uVar18;
  long lVar19;
  ulong *puVar20;
  ulong uVar21;
  ulong uVar22;
  long lVar23;
  long *plVar24;
  undefined8 uVar25;
  ulong extraout_x1;
  ulong extraout_x1_00;
  undefined4 uVar26;
  uint uVar27;
  ulong uVar28;
  ulong uVar29;
  byte bVar30;
  undefined8 uVar31;
  byte bVar32;
  int *piVar33;
  long lVar34;
  undefined8 *puVar35;
  int *piVar36;
  int iVar37;
  ulong uVar38;
  undefined8 uVar39;
  long lVar40;
  long lVar41;
  long lVar42;
  long lVar43;
  long lVar44;
  undefined8 *puVar45;
  ulong uVar46;
  ulong in_xzr;
  undefined1 auVar47 [16];
  undefined1 auVar48 [16];
  long local_328;
  undefined8 local_318;
  uint local_310;
  long local_308;
  undefined8 local_300;
  ulong uStack_2f8;
  ulong local_2f0;
  long local_2e8;
  long local_2e0 [8];
  undefined8 local_2a0;
  undefined8 uStack_298;
  undefined8 local_290;
  undefined8 uStack_288;
  undefined8 local_280;
  long local_278;
  long local_270;
  undefined8 uStack_268;
  undefined8 local_260;
  undefined8 local_258;
  undefined8 local_250;
  undefined8 uStack_248;
  undefined8 uStack_240;
  undefined8 uStack_238;
  undefined8 local_230;
  undefined8 uStack_228;
  undefined8 local_220;
  undefined8 uStack_218;
  undefined8 local_210;
  undefined8 uStack_208;
  undefined8 local_200;
  undefined8 uStack_1f8;
  undefined4 local_1f0;
  undefined4 uStack_1ec;
  undefined4 uStack_1e8;
  undefined4 uStack_1e4;
  undefined8 uStack_1e0;
  undefined8 uStack_1d8;
  undefined8 local_1d0;
  undefined8 uStack_1c8;
  undefined8 uStack_1c0;
  undefined8 uStack_1b8;
  undefined8 local_1b0;
  undefined8 uStack_1a8;
  ulong local_1a0;
  ulong uStack_198;
  ulong local_190;
  ulong uStack_188;
  ulong local_180;
  ulong uStack_178;
  ulong local_170;
  ulong uStack_168;
  ulong local_160;
  ulong uStack_158;
  ulong local_150;
  ulong uStack_148;
  ulong local_140;
  ulong uStack_138;
  ulong local_130;
  ulong uStack_128;
  ulong local_120;
  ulong uStack_118;
  ulong local_108;
  undefined8 local_100;
  undefined8 local_f8;
  undefined8 *local_f0;
  undefined8 *local_e8;
  uint local_e0;
  uint uStack_dc;
  uint uStack_d8;
  uint uStack_d4;
  ulong local_d0;
  ulong uStack_c8;
  ulong local_c0;
  ulong uStack_b8;
  ulong local_b0;
  ulong uStack_a8;
  ulong local_a0;
  long local_98;
  
  local_98 = DAT_fffffff00ad30000;
  if ((param_1 == 0) || ((*(byte *)(param_1 + 0x444) >> 2 & 1) == 0)) {
    bVar16 = true;
  }
  else {
    bVar16 = false;
  }
  uVar28 = *param_2;
  local_108 = 0;
  local_100 = 0;
  uStack_128 = 0;
  local_130 = 0;
  uStack_118 = 0;
  local_120 = 0;
  uStack_148 = 0;
  local_150 = 0;
  uStack_138 = 0;
  local_140 = 0;
  uStack_168 = 0;
  local_170 = 0;
  uStack_158 = 0;
  local_160 = 0;
  uStack_188 = 0;
  local_190 = 0;
  uStack_178 = 0;
  local_180 = 0;
  uStack_1a8 = 0;
  local_1b0 = 0;
  uStack_198 = 0;
  local_1a0 = 0;
  uStack_1c8 = 0;
  local_1d0 = 0;
  uStack_1b8 = 0;
  uStack_1c0 = 0;
  uStack_1e8 = 0;
  uStack_1e4 = 0;
  local_1f0 = 0;
  uStack_1ec = 0;
  uStack_1d8 = 0;
  uStack_1e0 = 0;
  uStack_208 = 0;
  local_210 = 0;
  uStack_1f8 = 0;
  local_200 = 0;
  uStack_228 = 0;
  local_230 = 0;
  uStack_218 = 0;
  local_220 = 0;
  uStack_248 = 0;
  local_250 = 0;
  uStack_238 = 0;
  uStack_240 = 0;
  uStack_268 = 0;
  local_270 = 0;
  local_258 = 0;
  local_260 = 0;
  uStack_288 = 0;
  local_290 = 0;
  local_278 = 0;
  local_280 = 0;
  uStack_298 = 0;
  local_2a0 = 0;
  local_2e0[4] = 0;
  local_2e0[5] = 0;
  local_2e0[6] = 0;
  local_2e0[1] = 0;
  local_2e0[0] = 0;
  local_2e0[3] = 0;
  local_2e0[2] = 0;
  lVar10 = tpidr_el1;
  uStack_2f8 = 0;
  local_300 = 0;
  local_2e8 = 0;
  local_2f0 = 0;
  lVar19 = FUN_fffffff00a29bafc(lVar10);
  local_308 = 0;
  puVar20 = (ulong *)FUN_fffffff00a2216c4(&DAT_fffffff007c78710,4);
  if (puVar20 == (ulong *)0x0) {
LAB_fffffff00a7104fc:
    uVar27 = 0;
    lVar44 = 0;
    lVar40 = 0;
    uVar22 = 0xc;
    goto LAB_fffffff00a710500;
  }
  *puVar20 = param_2[1];
  puVar20[1] = param_2[3];
  puVar20[2] = param_2[4];
  puVar20[5] = (ulong)(puVar20 + 0x6d);
  puVar20[6] = (ulong)(puVar20 + 0xa6);
  puVar20[0x55] = (ulong)&local_108;
  uVar26 = 0;
  if (!bVar16) {
    uVar26 = 4;
  }
  *(undefined4 *)(puVar20 + 9) = uVar26;
  uVar26 = 5;
  if (!bVar16) {
    uVar26 = 8;
  }
  *(undefined4 *)(puVar20 + 3) = uVar26;
  *(undefined4 *)((long)puVar20 + 0x2dc) = 0;
  puVar1 = puVar20 + 99;
  puVar20[100] = 0;
  *puVar1 = 0;
  puVar20[0x66] = 0;
  puVar20[0x65] = 0;
  *(undefined4 *)(puVar20 + 0x6c) = 0;
  puVar20[0x10] = 0;
  puVar20[0x6b] = 0;
  *(ulong **)(lVar10 + 0x5f0) = puVar20;
  uVar21 = param_2[2];
  if (uVar21 == 0) {
    lVar40 = 0;
    uVar21 = 0;
    goto LAB_fffffff00a70f3f8;
  }
  if (bVar16) {
    local_a0 = 0;
    uStack_b8 = 0;
    local_c0 = 0;
    uStack_a8 = 0;
    local_b0 = 0;
    uStack_d8 = 0;
    uStack_d4 = 0;
    local_e0 = 0;
    uStack_dc = 0;
    uStack_c8 = 0;
    local_d0 = 0;
    uVar22 = FUN_fffffff00a389b14(uVar21,&local_e0,0x48);
    local_1a0 = (ulong)local_e0;
    uStack_198 = (ulong)uStack_dc;
    local_190 = (ulong)uStack_d8;
    uStack_188 = (ulong)uStack_d4;
    local_180 = local_d0 & 0xffffffff;
    uStack_178 = local_d0 >> 0x20;
    local_170 = uStack_c8 & 0xffffffff;
    uStack_168 = uStack_c8 >> 0x20;
    local_160 = local_c0 & 0xffffffff;
    uStack_158 = local_c0 >> 0x20;
    local_150 = uStack_b8 & 0xffffffff;
    uStack_148 = uStack_b8 >> 0x20;
    local_140 = local_b0 & 0xffffffff;
    uStack_138 = local_b0 >> 0x20;
    local_130 = uStack_a8 & 0xffffffff;
    uStack_128 = uStack_a8 >> 0x20;
    local_120 = local_a0 & 0xffffffff;
    uStack_118 = local_a0 >> 0x20;
    if ((int)uVar22 != 0) goto LAB_fffffff00a70f478;
LAB_fffffff00a70f454:
    if (local_1a0 != 0) {
      uVar22 = FUN_fffffff00a389b14(uStack_198,&local_2a0,200);
      if ((int)uVar22 != 0) goto LAB_fffffff00a70f478;
      puVar20[0x5c] = (ulong)&local_2a0;
    }
    if (local_190 != 0) {
      iVar17 = FUN_fffffff00a73425c(param_1);
      uVar27 = 0;
      auVar47._8_8_ = 0;
      auVar47._0_8_ = (long)iVar17;
      bVar15 = SUB168(auVar47 * ZEXT816(0x410),8) != 0;
      uVar21 = 0;
      if (!bVar15) {
        uVar21 = (long)iVar17 * 0x410 | 8;
      }
      uVar22 = 0x16;
      if (((local_190 < 0x418) || (bVar15)) || (uVar21 < local_190)) {
        lVar40 = 0;
        lVar44 = 0;
      }
      else {
        uVar21 = FUN_fffffff00a220c30(&DAT_fffffff007c6afb0,local_190,0,0);
        if (uVar21 == 0) goto LAB_fffffff00a7104fc;
        puVar20[0x5d] = uVar21;
        uVar22 = FUN_fffffff00a389b14(uStack_188,uVar21,local_190);
        if ((int)uVar22 != 0) goto LAB_fffffff00a70f478;
        auVar8._8_8_ = 0;
        auVar8._0_8_ = (long)*(int *)(uVar21 + 4);
        if ((SUB168(auVar8 * ZEXT816(0x410),8) == 0) &&
           (((long)*(int *)(uVar21 + 4) * 0x410 | 8U) == local_190)) goto LAB_fffffff00a70f66c;
LAB_fffffff00a710068:
        uVar22 = 0x16;
        lVar40 = 0;
        lVar44 = 0;
        uVar27 = 0;
      }
      goto LAB_fffffff00a710500;
    }
LAB_fffffff00a70f66c:
    if (local_180 != 0) {
      if (0xffffffffffffc01e < local_180 - 0x4001) {
        uVar21 = FUN_fffffff00a220c30(&DAT_fffffff007c6afb0,local_180,0,0);
        if (uVar21 == 0) goto LAB_fffffff00a7104fc;
        puVar20[0x5e] = uVar21;
        uVar22 = FUN_fffffff00a389b14(uStack_178,uVar21,local_180);
        if ((int)uVar22 != 0) goto LAB_fffffff00a70f478;
        auVar9._8_8_ = 0;
        auVar9._0_8_ = (long)*(int *)(uVar21 + 4);
        uVar22 = (long)*(int *)(uVar21 + 4) * 0x18;
        uVar21 = 0;
        if (uVar22 < 0xfffffffffffffff8 && SUB168(auVar9 * ZEXT816(0x18),8) == 0) {
          uVar21 = uVar22 + 8;
        }
        if ((uVar21 == 0) || (uVar21 != local_180)) goto LAB_fffffff00a710068;
        goto LAB_fffffff00a70f918;
      }
LAB_fffffff00a70f688:
      lVar40 = 0;
      lVar44 = 0;
      uVar27 = 0;
      uVar22 = 0x16;
      goto LAB_fffffff00a710500;
    }
LAB_fffffff00a70f918:
    if ((local_150 != 0) && (uStack_148 != 0)) {
      if (local_150 == 0x58) {
        uVar21 = FUN_fffffff00a220c30(&DAT_fffffff007c6afb0,0x58,0,0);
        if (uVar21 == 0) goto LAB_fffffff00a7104fc;
        *puVar1 = uVar21;
        if (0x58 < local_150) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff00aa4d114
                    ("__copyin_chk object size check failed: uaddr %p, kaddr %p, (%zu < %zu) @%s:%d"
                    );
        }
        uVar22 = FUN_fffffff00a389b14(uStack_148,uVar21);
        if (((int)uVar22 != 0) || (uVar22 = FUN_fffffff00a7114f4(uVar21), (int)uVar22 != 0))
        goto LAB_fffffff00a70f478;
        goto LAB_fffffff00a70f97c;
      }
LAB_fffffff00a710054:
      lVar40 = 0;
      lVar44 = 0;
      uVar27 = 0;
      uVar22 = 0x22;
      goto LAB_fffffff00a710500;
    }
LAB_fffffff00a70f97c:
    uVar21 = 0;
    if ((local_140 != 0) && (uStack_138 != 0)) {
      if (local_140 != 0x154) goto LAB_fffffff00a710054;
      lVar40 = FUN_fffffff00a29b24c();
      if (*(int *)(*(long *)(lVar40 + 8) + 0x18) != 0) {
        lVar40 = 0;
        lVar44 = 0;
        uVar27 = 0;
        uVar22 = 1;
        goto LAB_fffffff00a710500;
      }
      uVar21 = FUN_fffffff00a220c30(&DAT_fffffff007c6afb0,0x154,0,0);
      if (uVar21 == 0) goto LAB_fffffff00a7104fc;
      puVar20[100] = uVar21;
      uVar22 = FUN_fffffff00a389b14(uStack_138,uVar21,local_140);
      if ((int)uVar22 != 0) goto LAB_fffffff00a70f478;
      if (((*(byte *)(uVar21 + 2) >> 2 & 1) != 0) && (0x10 < *(uint *)(uVar21 + 0xc)))
      goto LAB_fffffff00a70f688;
      *(undefined1 *)(uVar21 + 0x153) = 0;
    }
    if ((local_170 != 0) &&
       (uVar22 = FUN_fffffff00a711600(&local_1a0,puVar20 + 0x60), (int)uVar22 != 0))
    goto LAB_fffffff00a70f478;
    if ((local_130 - 1 < 0x400) &&
       (iVar17 = FUN_fffffff00a9dee48(lVar19,"com.apple.private.spawn-subsystem-root"), iVar17 != 0)
       ) {
      lVar40 = FUN_fffffff00a292e20(DAT_fffffff007c6af90,DAT_fffffff007c6af98,0x8004);
      uVar22 = FUN_fffffff00a389b14(uStack_128,lVar40,local_130);
      if ((int)uVar22 != 0) {
        lVar44 = 0;
        uVar27 = 0;
        goto LAB_fffffff00a710500;
      }
      *(undefined1 *)(lVar40 + (local_130 - 1)) = 0;
    }
    else {
      lVar40 = 0;
    }
LAB_fffffff00a70f3f8:
    iVar17 = FUN_fffffff00a9dee48(lVar19,"com.apple.private.spawn-panic-crash-behavior");
    uVar3 = 0;
    if (iVar17 != 0) {
      uVar3 = local_210._4_1_;
    }
    uVar25 = 0;
    if (iVar17 != 0) {
      uVar25 = local_200;
    }
    *(undefined2 *)(puVar20 + 0x68) = 0x102;
    lVar44 = FUN_fffffff00a332ff4(lVar19);
    if (lVar44 == 0) {
      uVar22 = 0;
    }
    else {
      uVar22 = *(ulong *)(lVar44 + 0xb0);
      FUN_fffffff00a334174();
    }
    puVar20[0x67] = uVar22;
    uVar22 = puVar20[0x5c];
    if (uVar22 == 0) {
      uVar27 = 0;
      bVar15 = false;
      goto LAB_fffffff00a70f4dc;
    }
    if ((*(byte *)(uVar22 + 0x80) & 1) != 0) {
      *(uint *)(puVar20 + 9) = (uint)puVar20[9] | 0x2000;
    }
    if ((*(uint *)(uVar22 + 0xac) & 0xffffe0fe) != 0) {
      uVar22 = 0x16;
LAB_fffffff00a70f5a0:
      lVar44 = 0;
      uVar27 = 0;
      goto LAB_fffffff00a710500;
    }
    if (((*(uint *)(uVar22 + 0x24) & 0xf00) == 0x700) &&
       (((lVar19 == DAT_fffffff007c68058 || (lVar44 = FUN_fffffff00a29b0b4(lVar19), lVar44 == 0)) ||
        (iVar17 = (**(code **)(DAT_fffffff007c64e38 + 0x1c8))
                            (lVar44,"com.apple.private.spawn-driver"), iVar17 != 0)))) {
      uVar22 = 1;
      goto LAB_fffffff00a70f5a0;
    }
    uVar27 = *(uint *)(uVar22 + 0x80);
    uVar18 = uVar27;
    if ((uVar27 & 0x2f0) != 0) {
      iVar17 = FUN_fffffff00a9dee48(lVar19,"com.apple.private.shared-region.config");
      uVar18 = *(uint *)(uVar22 + 0x80);
      if (iVar17 != 0) {
        if ((uVar18 >> 4 & 1) != 0) {
          *(undefined1 *)(puVar20 + 0x68) = 1;
          uVar18 = *(uint *)(uVar22 + 0x80);
        }
        if ((uVar18 >> 5 & 1) != 0) {
          *(undefined1 *)(puVar20 + 0x68) = 3;
          uVar18 = *(uint *)(uVar22 + 0x80);
        }
        if ((uVar18 >> 9 & 1) != 0) {
          *(undefined1 *)(puVar20 + 0x68) = 4;
          uVar18 = *(uint *)(uVar22 + 0x80);
        }
        if ((uVar18 >> 6 & 1) != 0) {
          *(undefined1 *)((long)puVar20 + 0x341) = 1;
          uVar18 = *(uint *)(uVar22 + 0x80);
        }
        if ((uVar18 >> 7 & 1) != 0) {
          *(undefined1 *)((long)puVar20 + 0x341) = 2;
          uVar18 = *(uint *)(uVar22 + 0x80);
        }
      }
    }
    uVar27 = uVar27 >> 3 & 1;
    if (((uVar18 >> 8 & 1) != 0) &&
       (iVar17 = FUN_fffffff00a9dee48(lVar19,"com.apple.private.shared-region.namespace"),
       iVar17 != 0)) {
      puVar20[0x67] = 0xffffffffffffffff;
    }
    if (puVar20[0x5c] == 0) {
      bVar15 = false;
LAB_fffffff00a70f4dc:
      puVar45 = (undefined8 *)0x0;
      local_f0 = (undefined8 *)0x0;
      local_e8 = (undefined8 *)0x0;
      uStack_c8 = 0;
      local_d0 = 0;
      uStack_b8 = 0;
      local_c0 = 0;
      uStack_d8 = 0;
      uStack_d4 = 0;
      local_e0 = 0;
      uStack_dc = 0;
      local_f8 = 0;
      if (bVar15) {
        puVar35 = (undefined8 *)0x0;
        if (uStack_158 == 0) goto LAB_fffffff00a70f6f4;
        uStack_c8 = 0;
        local_d0 = 0;
        uStack_b8 = 0;
        local_c0 = 0;
        uStack_d8 = 0;
        uStack_d4 = 0;
        local_e0 = 0;
        uStack_dc = 0;
        if (0x30 < local_160) {
          local_160 = 0x30;
        }
        uVar22 = FUN_fffffff00a389b14(uStack_158,&local_e0);
        if ((int)uVar22 != 0) {
          lVar44 = 0;
          uVar27 = 0;
          goto LAB_fffffff00a710500;
        }
        lVar44 = CONCAT44(uStack_dc,local_e0);
        bVar15 = lVar44 == 0;
        if (lVar44 == 0) {
          puVar35 = (undefined8 *)0x0;
LAB_fffffff00a710174:
          uVar22 = uStack_c8;
          if (uStack_c8 == 0) {
            puVar45 = (undefined8 *)0x0;
            bVar15 = true;
          }
          else {
            if ((*(long *)(param_1 + 0xd40) == 0) ||
               ((*(byte *)(*(long *)(param_1 + 0xd40) + 0x28) & 1) == 0)) {
              lVar44 = 0;
              if ((*(uint *)(param_1 + 0x448) & 2) != 0) {
                lVar44 = param_1 + 0x768;
              }
              iVar17 = FUN_fffffff00a9dee48(lVar44,"com.apple.private.coalition-spawn");
              if (iVar17 == 0) {
                if (puVar35 != (undefined8 *)0x0) {
                  FUN_fffffff00a20c70c(puVar35);
                  FUN_fffffff00a20bb60(local_f0);
                  if (local_e8 != (undefined8 *)0x0) {
                    FUN_fffffff00a20c70c();
                    FUN_fffffff00a20bb60(local_e8);
                  }
                }
                goto LAB_fffffff00a710290;
              }
            }
            puVar45 = (undefined8 *)FUN_fffffff00a20be1c(uVar22);
            local_e8 = puVar45;
            if (puVar45 == (undefined8 *)0x0) {
              if (puVar35 != (undefined8 *)0x0) {
                FUN_fffffff00a20c70c(puVar35);
                goto LAB_fffffff00a710234;
              }
LAB_fffffff00a710238:
              lVar44 = 0;
              uVar22 = 3;
              goto LAB_fffffff00a70f7e0;
            }
            if (*(int *)(puVar45 + 1) != 1) {
              if (puVar35 != (undefined8 *)0x0) goto LAB_fffffff00a70f86c;
              goto LAB_fffffff00a70f884;
            }
            local_f8 = CONCAT44((undefined4)local_c0,(int)local_f8);
          }
          if (uVar27 != 0) {
            FUN_fffffff00a3685e0(puVar45);
          }
          bVar15 = (bool)(bVar15 ^ 1);
          if (puVar35 != (undefined8 *)0x0) {
            bVar15 = true;
          }
          if (bVar15) goto LAB_fffffff00a70f6f4;
          FUN_fffffff00a711824(0,puVar45);
          lVar44 = 0;
          uVar22 = 0x16;
        }
        else if ((*(long *)(param_1 + 0xd38) == 0) ||
                ((*(byte *)(*(long *)(param_1 + 0xd38) + 0x28) & 1) == 0)) {
          lVar42 = 0;
          if ((*(uint *)(param_1 + 0x448) & 2) != 0) {
            lVar42 = param_1 + 0x768;
          }
          iVar17 = FUN_fffffff00a9dee48(lVar42,"com.apple.private.coalition-spawn");
          if (iVar17 != 0) goto LAB_fffffff00a70f850;
LAB_fffffff00a710290:
          lVar44 = 0;
          uVar22 = 1;
        }
        else {
LAB_fffffff00a70f850:
          puVar35 = (undefined8 *)FUN_fffffff00a20be1c(lVar44);
          local_f0 = puVar35;
          if (puVar35 != (undefined8 *)0x0) {
            if (*(int *)(puVar35 + 1) == 0) {
              local_f8 = CONCAT44(local_f8._4_4_,uStack_d8);
              goto LAB_fffffff00a710174;
            }
LAB_fffffff00a70f86c:
            FUN_fffffff00a20c70c(puVar35);
            FUN_fffffff00a20bb60(local_f0);
            if (local_e8 != (undefined8 *)0x0) {
LAB_fffffff00a70f884:
              FUN_fffffff00a20c70c(local_e8);
              puVar35 = local_e8;
LAB_fffffff00a710234:
              FUN_fffffff00a20bb60(puVar35);
            }
            goto LAB_fffffff00a710238;
          }
          lVar44 = 0;
          uVar22 = 3;
        }
      }
      else {
        puVar35 = (undefined8 *)0x0;
LAB_fffffff00a70f6f4:
        uVar22 = FUN_fffffff00a71e330(param_1,puVar20 + 0x57,1,&local_f0);
        if ((int)uVar22 == 0) {
          lVar44 = FUN_fffffff00a29bafc(puVar20[0x57]);
          iVar17 = FUN_fffffff00a20cf04(&local_f0,lVar44,&local_f8);
          uVar27 = 0;
          if (iVar17 != 0) {
            uVar27 = 0x16;
          }
          uVar22 = (ulong)uVar27;
          iVar17 = FUN_fffffff00a6e020c(0x1a70008);
          if (iVar17 != 0) {
            if ((puVar35 != (undefined8 *)0x0) && ((DAT_fffffff00ad98b00 & 0xfffffff7) != 0)) {
              uVar39 = *puVar35;
              uVar31 = FUN_fffffff00a29ce90(lVar44);
              FUN_fffffff00a6de494(0x1a70008,uVar39,uVar31,0,0);
            }
            if ((puVar45 != (undefined8 *)0x0) && ((DAT_fffffff00ad98b00 & 0xfffffff7) != 0)) {
              uVar39 = *puVar45;
              uVar31 = FUN_fffffff00a29ce90(lVar44);
              FUN_fffffff00a6de494(0x1a70008,uVar39,uVar31,0,0);
            }
          }
        }
        else {
          lVar44 = 0;
        }
        puVar45 = local_e8;
        if (puVar35 != (undefined8 *)0x0) {
          FUN_fffffff00a20c70c(puVar35);
          piVar36 = (int *)(local_f0 + 2);
          iVar17 = *piVar36;
          *piVar36 = iVar17 + -1;
          LORelease();
          if (iVar17 == 0) goto LAB_fffffff00a711064;
          puVar45 = local_e8;
          if (iVar17 == 1) {
            in_xzr = (ulong)*(uint *)(local_f0 + 2);
            FUN_fffffff00a20bb9c();
            puVar45 = local_e8;
          }
        }
        local_e8 = puVar45;
        if (puVar45 != (undefined8 *)0x0) {
          FUN_fffffff00a20c70c(puVar45);
          piVar36 = (int *)(puVar45 + 2);
          iVar17 = *piVar36;
          *piVar36 = iVar17 + -1;
          LORelease();
          if (iVar17 == 0) goto LAB_fffffff00a711064;
          if (iVar17 == 1) {
            in_xzr = (ulong)*(uint *)(puVar45 + 2);
            FUN_fffffff00a20bb9c(puVar45);
          }
        }
        if ((int)uVar22 == 0) {
          bVar15 = false;
          *(uint *)(puVar20 + 9) = (uint)puVar20[9] | 0x10;
          uVar22 = puVar20[0x57];
          uVar27 = 1;
          goto LAB_fffffff00a70facc;
        }
      }
LAB_fffffff00a70f7e0:
      uVar27 = 0;
      goto LAB_fffffff00a710500;
    }
    if (((ushort)local_2a0 >> 6 & 1) == 0) {
      bVar15 = true;
      goto LAB_fffffff00a70f4dc;
    }
    lVar44 = FUN_fffffff00a29b24c();
    FUN_fffffff00a723e4c(*(undefined4 *)(*(long *)(lVar44 + 8) + 0x1c),1);
    uVar22 = FUN_fffffff00a71e630(lVar19,0,param_1,4);
    puVar20[0x57] = uVar22;
    if (uVar22 == 0) {
      FUN_fffffff00a723e4c(*(undefined4 *)(*(long *)(lVar44 + 8) + 0x1c),0xffffffff);
      uVar22 = 0xc;
      goto LAB_fffffff00a70f5a0;
    }
    lVar44 = FUN_fffffff00a29bafc();
    uVar27 = 0;
    *(uint *)(puVar20 + 9) = (uint)puVar20[9] | 0x100;
    bVar15 = true;
LAB_fffffff00a70facc:
    param_1 = FUN_fffffff00a29b12c(uVar22);
    if ((lVar40 != 0) && (uVar22 = FUN_fffffff00a289574(lVar40,param_1 + 0x760), (int)uVar22 != 0))
    goto LAB_fffffff00a710500;
    *(undefined1 *)(param_1 + 0x6ca) = uVar3;
    *(undefined8 *)(param_1 + 0x748) = uVar25;
    *(ushort *)(param_1 + 0x6c8) = (ushort)local_2a0;
    *(ulong *)(param_1 + 0x750) = CONCAT44(uStack_1e8,uStack_1ec);
    local_108 = puVar20[0x57];
    local_100 = FUN_fffffff00a7272a0(param_1);
    if (puVar20[0x5d] != 0) {
      uVar46 = puVar20[0x5c];
      uVar4 = (ushort)local_2a0;
      lVar23 = FUN_fffffff00a41d4e0(puVar20[0x55]);
      lVar13 = DAT_fffffff00700e480;
      uVar25 = DAT_fffffff00700e458;
      lVar43 = DAT_fffffff00700dd10;
      lVar42 = DAT_fffffff00700dd00;
      uVar31 = *(undefined8 *)(puVar20[0x55] + 8);
      uVar29 = puVar20[0x5d];
      local_e0 = 0;
      uStack_dc = 0;
      if (0 < *(int *)(uVar29 + 4)) {
        lVar41 = 0;
        do {
          piVar36 = (int *)(uVar29 + 8 + lVar41 * 0x410);
          if (((uVar29 + 8 ^ (ulong)piVar36) & 0xffc0000000000000) != 0) {
            piVar36 = (int *)((ulong)piVar36 & 0xffffffffffff | 0xc8a2000000000000);
          }
          iVar17 = *piVar36;
          uVar22 = 0x16;
          if (iVar17 < 3) {
            if (iVar17 != 0) {
              if (iVar17 == 1) {
                uVar22 = FUN_fffffff00a6f6f44(lVar23,uVar31,piVar36[1]);
              }
              else {
                if (iVar17 != 2) goto LAB_fffffff00a710500;
                uVar22 = FUN_fffffff00a6f1b38(lVar23,uVar31,piVar36[1],piVar36[2],0,&local_e0);
              }
LAB_fffffff00a70fd34:
              iVar17 = (int)uVar22;
              goto joined_r0xfffffff00a70fe6c;
            }
            uVar6 = *(ushort *)(piVar36 + 3);
            local_f0 = (undefined8 *)((ulong)local_f0 & 0xffffffff00000000);
            puVar45 = (undefined8 *)FUN_fffffff00a2216c4(&DAT_fffffff007c788d0,4);
            if (puVar45 == (undefined8 *)0x0) {
              uVar22 = 0xc;
LAB_fffffff00a70ff30:
              iVar17 = (int)uVar22;
              goto joined_r0xfffffff00a70fe6c;
            }
            *puVar45 = 0;
            puVar45[1] = 0;
            *(undefined4 *)(puVar45 + 2) = 0;
            *(ushort *)((long)puVar45 + 0x4c) =
                 uVar6 & (*(ushort *)(lVar23 + 0xe2) ^ 0xffff) & 0x1ff;
            puVar45[1] = 0x200;
            puVar45[100] = lVar43;
            puVar45[0x3a] = uVar25;
            puVar45[0x39] = (long)piVar36 + 0xe;
            puVar45[0x65] = puVar20[0x55];
            *(undefined4 *)(puVar45 + 99) = 0;
            puVar45[0x66] = puVar45 + 0x39;
            puVar45[0x3b] = lVar42;
            uVar22 = FUN_fffffff00a3ff294
                               (puVar20[0x55],puVar45 + 0x39,piVar36[2],puVar45,0,0,&local_f0,
                                0xffffffff);
            FUN_fffffff00a29762c(&DAT_fffffff007c78910,puVar45);
            if ((int)uVar22 != 0) goto LAB_fffffff00a70ff30;
            uVar38 = (ulong)local_f0 & 0xffffffff;
            if ((int)local_f0 != piVar36[1]) {
              uVar22 = FUN_fffffff00a6f1b38(lVar23,uVar31,uVar38,piVar36[1],0,&local_e0);
              if ((int)uVar22 == 0) {
                uVar22 = FUN_fffffff00a6f6f44(lVar23,uVar31,uVar38);
                iVar17 = (int)uVar22;
                goto joined_r0xfffffff00a70fe6c;
              }
              goto LAB_fffffff00a70ff30;
            }
          }
          else {
            if (iVar17 < 5) {
              if (iVar17 != 3) {
                if (iVar17 == 4) {
                  local_f0 = (undefined8 *)0x0;
                  local_f8 = local_f8 & 0xffffffff00000000;
                  if (1 < piVar36[1] + 1U) {
                    lVar34 = *(long *)(lVar19 + 0x310);
                    if (lVar34 == 0) {
                      lVar34 = 0;
                    }
                    iVar17 = FUN_fffffff00a217ef4(lVar34,piVar36[1],0x1f,&local_f0);
                    puVar45 = local_f0;
                    if (iVar17 != 0) goto LAB_fffffff00a70ff30;
                    uVar22 = FUN_fffffff00a6f82f0(lVar23,local_f0,0,&local_f8);
                    if (puVar45 != (undefined8 *)0x0) {
                      FUN_fffffff00a21814c(puVar45,0x1f);
                    }
                    if ((int)uVar22 == 0) {
                      uVar38 = local_f8 & 0xffffffff;
                      if ((int)local_f8 == piVar36[2]) goto LAB_fffffff00a70ff3c;
                      uVar22 = FUN_fffffff00a6f1b38(lVar23,uVar31,uVar38,piVar36[2],0,&local_e0);
                      if ((int)uVar22 == 0) {
                        uVar22 = FUN_fffffff00a6f6f44(lVar23,uVar31,uVar38);
                      }
                    }
                  }
                  iVar17 = (int)uVar22;
                  goto joined_r0xfffffff00a70fe6c;
                }
                goto LAB_fffffff00a710500;
              }
              if (*(ulong *)(lVar23 + 0xd8) == 0) {
                *(ulong *)(lVar23 + 0xd8) = (ulong)*(uint *)(lVar10 + 0x4e8);
              }
              else {
                FUN_fffffff00a2262d4(lVar23 + 0xd0,lVar10,0);
              }
              lVar34 = FUN_fffffff00a6ef900(lVar23,piVar36[1]);
              if (lVar34 == 0) {
                uVar22 = 9;
              }
              else if (*(short *)(lVar34 + 10) == 0) {
                uVar22 = 0;
                *(ushort *)(lVar34 + 8) = *(ushort *)(lVar34 + 8) & 0xfffe;
              }
              else {
                FUN_fffffff00a6f8880(lVar23,piVar36[1],lVar34,4);
                uVar22 = 1;
              }
              if (*(int *)(lVar23 + 0xd8) == *(int *)(lVar10 + 0x4e8)) {
                *(int *)(lVar23 + 0xd8) = (int)in_xzr;
              }
              else {
                FUN_fffffff00a226e08(lVar23 + 0xd0,lVar10);
              }
            }
            else {
              if (iVar17 != 5) {
                if (iVar17 == 6) {
                  uVar22 = FUN_fffffff00a3fe638(lVar23,puVar20[0x55],piVar36[1],0);
                  goto LAB_fffffff00a70fd34;
                }
                goto LAB_fffffff00a710500;
              }
              plVar24 = (long *)FUN_fffffff00a2216c4(&DAT_fffffff007c78950,0x8004);
              plVar24[0x2b] = lVar43;
              plVar24[1] = lVar13;
              *plVar24 = (long)(piVar36 + 2);
              uVar22 = puVar20[0x55];
              *(undefined4 *)(plVar24 + 0x2a) = 0;
              plVar24[0x2c] = uVar22;
              plVar24[0x2d] = (long)plVar24;
              plVar24[2] = lVar42;
              uVar22 = FUN_fffffff00a3fe9e0(lVar23,puVar20[0x55],plVar24,0);
              FUN_fffffff00a29762c(&DAT_fffffff007c78990,plVar24);
            }
            iVar17 = (int)uVar22;
joined_r0xfffffff00a70fe6c:
            if (iVar17 != 0) goto LAB_fffffff00a710500;
          }
LAB_fffffff00a70ff3c:
          lVar41 = lVar41 + 1;
        } while (lVar41 < *(int *)(uVar29 + 4));
      }
      if ((uVar46 != 0) && ((uVar4 >> 0xe & 1) != 0)) {
        if (*(ulong *)(lVar23 + 0xd8) == 0) {
          *(ulong *)(lVar23 + 0xd8) = (ulong)*(uint *)(lVar10 + 0x4e8);
        }
        else {
          FUN_fffffff00a2262d4(lVar23 + 0xd0,lVar10,0);
        }
        iVar17 = *(int *)(uVar29 + 4);
        if (0 < iVar17) {
          lVar42 = 0;
          do {
            piVar36 = (int *)(uVar29 + 8 + lVar42 * 0x410);
            if (((uVar29 + 8 ^ (ulong)piVar36) & 0xffc0000000000000) != 0) {
              piVar36 = (int *)((ulong)piVar36 & 0xffffffffffff | 0xc8a2000000000000);
            }
            piVar33 = piVar36 + 1;
            iVar37 = *piVar36;
            if (iVar37 < 3) {
              if (iVar37 != 0) {
                if (iVar37 != 2) goto LAB_fffffff00a70fffc;
LAB_fffffff00a70ffdc:
                piVar33 = piVar36 + 2;
              }
LAB_fffffff00a70ffe0:
              pbVar2 = (byte *)(*(long *)(lVar23 + 0x100) + (long)*piVar33);
              *pbVar2 = *pbVar2 | 0x20;
              iVar17 = *(int *)(uVar29 + 4);
            }
            else {
              if (iVar37 == 3) goto LAB_fffffff00a70ffe0;
              if (iVar37 == 4) goto LAB_fffffff00a70ffdc;
            }
LAB_fffffff00a70fffc:
            lVar42 = lVar42 + 1;
          } while (lVar42 < iVar17);
        }
        if (*(int *)(lVar23 + 0xd8) == *(int *)(lVar10 + 0x4e8)) {
          *(int *)(lVar23 + 0xd8) = (int)in_xzr;
        }
        else {
          FUN_fffffff00a226e08(lVar23 + 0xd0,lVar10);
        }
      }
    }
    if ((puVar20[0x5e] != 0) &&
       ((uVar22 = FUN_fffffff00a7118bc(puVar20,&local_300), (int)uVar22 != 0 ||
        ((local_2e0[3] != 0 && (uVar22 = FUN_fffffff00a711bfc(param_1,lVar19), (int)uVar22 != 0)))))
       ) goto LAB_fffffff00a710500;
    uVar22 = 0;
    if (*(long *)(param_1 + 0x760) != 0) {
      uVar22 = *(ulong *)(*(long *)(param_1 + 0x760) + 0x30);
    }
    puVar20[0x10] = uVar22;
    if (puVar20[0x5c] != 0) {
      if ((local_2a0 & 1) != 0) {
        FUN_fffffff00a6ea8ac(param_1,0,&DAT_fffffff007c07970);
      }
      if (puVar20[100] == 0) {
        if (*puVar1 != 0) {
          if (bVar15) goto LAB_fffffff00a71025c;
LAB_fffffff00a7102a4:
          uVar22 = FUN_fffffff00a711de4(param_1);
          if ((int)uVar22 != 0) goto LAB_fffffff00a7102b0;
        }
      }
      else {
        if (bVar15) {
LAB_fffffff00a71025c:
          uVar27 = 0;
          uVar22 = 0x2d;
          goto LAB_fffffff00a710500;
        }
        uVar22 = FUN_fffffff00a711cb4(param_1);
        if ((int)uVar22 != 0) {
LAB_fffffff00a7102b0:
          uVar27 = 1;
          goto LAB_fffffff00a710500;
        }
        if (*puVar1 != 0) goto LAB_fffffff00a7102a4;
      }
      if ((short)(ushort)local_2a0 < 0) {
        *(uint *)(puVar20 + 9) = (uint)puVar20[9] | 0x200;
      }
      if ((local_2a0 & 0x800) == 0 || DAT_fffffff007c077ec == 0) {
        bVar16 = true;
      }
      if (!bVar16) {
        *(uint *)(puVar20 + 9) = (uint)puVar20[9] | 0x1000;
      }
      if ((local_280._4_4_ & 0xf00) == 0x700) {
        *(uint *)(puVar20 + 9) = (uint)puVar20[9] | 0x800;
      }
    }
    if ((*(byte *)(param_1 + 0x445) >> 4 & 1) != 0) {
      *(uint *)(puVar20 + 9) = (uint)puVar20[9] | 0x20;
    }
    FUN_fffffff00a72cf54(param_1,0);
    if (bVar15) {
      FUN_fffffff00a737e54(param_1,0);
    }
    uVar22 = FUN_fffffff00a711e8c(puVar20);
    uVar18 = (uint)puVar20[9];
    FUN_fffffff00a3969c4(lVar44,uVar18 >> 0x1f);
    *(byte *)(lVar44 + 0x358) = (byte)(uVar18 >> 0x1f);
    *(uint *)(puVar20[0x57] + 0x100) =
         *(uint *)(puVar20[0x57] + 0x100) & 0xfffffffe | uVar18 >> 0x1f;
    *(undefined8 *)(puVar20[0x57] + 0x1d0) = *(undefined8 *)(lVar44 + 0x350);
    iVar17 = (int)uVar22;
    if (iVar17 == 0 && uVar27 == 0) {
      lVar43 = FUN_fffffff00a29b24c();
      lVar42 = *(long *)(lVar43 + 0x18);
      if (*(long *)(lVar43 + 0x18) == 0) {
        lVar42 = DAT_fffffff007c6b250;
      }
      FUN_fffffff00a712670(lVar42,param_1,lVar19,lVar44,puVar20,&local_308);
      bVar12 = true;
      uVar46 = extraout_x1_00;
    }
    else {
      bVar12 = false;
      uVar46 = extraout_x1;
    }
    bVar16 = iVar17 == 0;
    if (iVar17 != 0) {
LAB_fffffff00a7103e0:
      local_328 = 0;
      if (bVar15) goto LAB_fffffff00a710524;
      goto LAB_fffffff00a710518;
    }
    if (puVar20[0x5c] == 0) {
LAB_fffffff00a711184:
      FUN_fffffff00a712c08(param_1,puVar20);
      lVar42 = *(long *)(lVar44 + 0x28);
      if (lVar42 == 0) {
        lVar42 = 0;
      }
      FUN_fffffff00a2ec05c(lVar42,lVar44);
      lVar42 = param_1 + 0x55c;
      if (*(char *)(param_1 + 0x56d) != '\0') {
        lVar42 = param_1 + 0x56d;
      }
      FUN_fffffff00a1d1550(lVar42);
      FUN_fffffff00a726898(param_1);
      FUN_fffffff00a7269d8(param_1);
      FUN_fffffff00a26acc4(lVar44);
      FUN_fffffff00a714c38(lVar44);
      lVar42 = FUN_fffffff00a29b0b4(lVar44);
      iVar17 = FUN_fffffff00a9dee48(lVar44,"com.apple.private.vfs.support-long-paths");
      if (iVar17 != 0) {
        *(ushort *)(lVar42 + 0x616) = *(ushort *)(lVar42 + 0x616) | 0x1000;
      }
      FUN_fffffff00a25fcec(lVar44,puVar20[0x57]);
      FUN_fffffff00a219f74(lVar44);
      if ((puVar20[0x5e] != 0) &&
         (uVar25 = FUN_fffffff00a29bafc(puVar20[0x57]), uVar21 = local_2f0,
         (*(byte *)((long)puVar20 + 0x4a) & 1) == 0)) {
        uVar22 = local_300 & 0xffffffff;
        if ((int)local_300 != 0) {
          lVar42 = 0;
          do {
            puVar45 = (undefined8 *)(uVar21 + lVar42 * 0x10);
            if (((uVar21 ^ (ulong)puVar45) & 0xffc0000000000000) != 0) {
              puVar45 = (undefined8 *)((ulong)puVar45 & 0xffffffffffff | 0xc8a2000000000000);
            }
            lVar43 = puVar45[1];
            iVar17 = FUN_fffffff00a21ed70
                               (uVar25,*(undefined4 *)(lVar43 + 4),*puVar45,
                                *(undefined4 *)(lVar43 + 0xc),*(undefined4 *)(lVar43 + 0x10));
            if (iVar17 != 0) {
              bVar11 = false;
              uVar22 = 0x16;
              goto LAB_fffffff00a7112b0;
            }
            *puVar45 = 0;
            lVar42 = lVar42 + 1;
            uVar22 = uVar22 - 1;
          } while (uVar22 != 0);
        }
      }
      uVar22 = 0;
      bVar11 = true;
LAB_fffffff00a7112b0:
      if (local_280._4_4_ == 0x700) {
        local_260 = CONCAT44(0x96,(undefined4)local_260);
      }
      uVar21 = puVar20[0x5c];
      if (uVar21 != 0) {
        uVar46 = (ulong)(short)(ushort)local_260;
        if ((short)(ushort)local_260 < 0) {
          uVar14 = local_258._4_4_;
          uVar26 = (undefined4)local_258;
          FUN_fffffff00a74eea0(param_1,local_260._4_4_,0,((int)(short)(ushort)local_260 & 1U) << 1);
          uVar4 = (ushort)local_260 >> 2 & 3;
          if ((local_260 & 2) != 0) {
            uVar4 = 1;
            uVar26 = 0xffffffff;
          }
          FUN_fffffff00a74f19c(param_1,uVar26,uVar14,uVar4);
          uVar21 = puVar20[0x5c];
          if (uVar21 == 0) goto LAB_fffffff00a711390;
          uVar46 = local_260 & 0xffff;
        }
        if ((uVar46 & 0x30) != 0) {
          *(undefined4 *)(param_1 + 0x724) =
               *(undefined4 *)(&DAT_fffffff0070104a0 + (ulong)(((uint)uVar46 & 0x30) >> 4) * 4);
          uVar21 = puVar20[0x5c];
        }
        if ((uVar21 != 0) && (0 < (int)uStack_248._4_4_)) {
          FUN_fffffff00a2699bc(lVar44,uStack_248._4_4_ & 0xffff);
          uVar21 = puVar20[0x5c];
        }
      }
LAB_fffffff00a711390:
      if (((bVar11) && (uVar22 = 0, uVar21 != 0)) && (uStack_1e0._4_4_ != 0)) {
        uVar22 = FUN_fffffff00a269a54(lVar44);
        uVar21 = puVar20[0x5c];
      }
      if ((uVar21 != 0) && (((ushort)local_260 >> 4 & 1) != 0)) {
        FUN_fffffff00a269664(lVar44,1);
      }
      goto LAB_fffffff00a7103e0;
    }
    uVar29 = puVar20[0x57];
    if (((ushort)local_2a0 >> 1 & 1) == 0) {
LAB_fffffff00a711048:
      uVar18 = (uint)(ushort)local_2a0;
      if (((ushort)local_2a0 >> 10 & 1) != 0) {
        auVar47 = FUN_fffffff00a72ff10(param_1);
        uVar46 = auVar47._8_8_;
        uVar22 = auVar47._0_8_;
        if (auVar47._0_4_ != 0) goto LAB_fffffff00a711104;
        uVar18 = (uint)local_2a0 & 0xffff;
      }
      if ((uVar18 >> 3 & 1) != 0) {
        *(uint *)(uVar29 + 0x68c) = (uint)uStack_298 & 0xfffefeff;
      }
      uVar22 = 0;
      auVar48._8_8_ = 0;
      auVar48._0_8_ = uVar46;
      auVar48 = auVar48 << 0x40;
      if ((uVar18 >> 2 & 1) != 0) {
        local_2e0[4] = 0;
        local_2e0[5] = 0;
        iVar17 = 1;
        local_2e0[6] = 0;
        do {
          if ((local_2a0._4_4_ >> (ulong)(iVar17 - 1U & 0x1f) & 1) != 0) {
            auVar48 = FUN_fffffff00a737918(param_1,auVar48._8_8_,iVar17,local_2e0 + 4,uVar27);
          }
          uVar22 = auVar48._0_8_;
          iVar17 = iVar17 + 1;
        } while (iVar17 != 0x20);
      }
      if (local_278 - 1U < 0xfe) {
        lVar42 = 0;
        if ((*(uint *)(param_1 + 0x448) & 2) != 0) {
          lVar42 = param_1 + 0x768;
        }
        uVar22 = FUN_fffffff00a26efe4(lVar42,5,local_278,local_270 * 1000000000,0,1);
      }
      if ((uVar21 != 0) && ((*(byte *)(uVar21 + 2) >> 3 & 1) != 0)) {
        FUN_fffffff00a731b2c(param_1,uVar21 + 0x54);
      }
      if ((int)uVar22 == 0) {
        if (puVar20[0x5c] != 0) {
          iVar17 = (int)local_280;
          if (2 < (int)local_280 - 1U) {
            iVar17 = 0;
          }
          *(int *)(param_1 + 0x594) = iVar17;
        }
        goto LAB_fffffff00a711184;
      }
    }
    else {
      uStack_d4 = 0;
      uStack_dc = 0;
      if (param_1 == DAT_fffffff007c6b250) {
        local_e0 = 0;
      }
      else {
        local_e0 = *(uint *)(param_1 + 0x60);
      }
      uStack_d8 = uStack_298._4_4_;
      auVar47 = FUN_fffffff00a7300cc(param_1,&local_e0);
      uVar46 = auVar47._8_8_;
      uVar22 = auVar47._0_8_;
      if (auVar47._0_4_ == 0) {
        goto LAB_fffffff00a711048;
      }
    }
LAB_fffffff00a711104:
    local_328 = FUN_fffffff00a7d19d4(9,0x13);
    if (!bVar15) goto LAB_fffffff00a710518;
  }
  else {
    uVar22 = FUN_fffffff00a389b14(uVar21,&local_1a0,0x90);
    if ((int)uVar22 == 0) goto LAB_fffffff00a70f454;
LAB_fffffff00a70f478:
    lVar40 = 0;
    lVar44 = 0;
    uVar27 = 0;
LAB_fffffff00a710500:
    FUN_fffffff00a72cf54(param_1,0);
    bVar16 = false;
    local_328 = 0;
    bVar12 = false;
LAB_fffffff00a710518:
    FUN_fffffff00a737e54(param_1,0);
  }
LAB_fffffff00a710524:
  if ((int)uVar22 == 0) {
    uVar22 = FUN_fffffff00a72cd24(param_1,0,0);
    if ((int)uVar22 == 0) {
      if (*(long *)(lVar44 + 0x468) != 0) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa4d114
                  (
                  "Task bank init called with non null bank context for task: %p and bank_context: %p @%s:%d"
                  );
      }
      FUN_fffffff00a2ad4dc(lVar44);
      FUN_fffffff00a72cf54(param_1,0);
    }
    if (0xffffffffddbffffe < DAT_fffffff00ad970f0 - 0x80000001U) {
      lVar42 = 0;
      if ((*(uint *)(param_1 + 0x448) & 2) != 0) {
        lVar42 = param_1 + 0x768;
      }
      iVar17 = FUN_fffffff00a9dee48(lVar42,"com.apple.developer.memory.ios13extended_footprint");
      if (iVar17 != 0) {
        FUN_fffffff00a26ae68(lVar44);
      }
    }
    if ((DAT_fffffff00ad8a860 == 0) ||
       (iVar17 = FUN_fffffff00a9dee48
                           (lVar44,"com.apple.developer.kernel.increased-debugging-memory-limit"),
       iVar17 == 0)) {
      if ((DAT_fffffff00ad8e1a8 != 0) &&
         (iVar17 = FUN_fffffff00a9dee48(lVar44,"com.apple.developer.kernel.increased-memory-limit"),
         iVar17 != 0)) {
        FUN_fffffff00a747cd0(param_1);
      }
    }
    else {
      FUN_fffffff00a747ddc(param_1);
    }
    lVar42 = 0;
    if ((*(uint *)(param_1 + 0x448) & 2) != 0) {
      lVar42 = param_1 + 0x768;
    }
    iVar17 = FUN_fffffff00a9dee48(lVar42,"com.apple.private.internal-jetsam-range");
    if (iVar17 != 0) {
      *(uint *)(param_1 + 0x6d0) = *(uint *)(param_1 + 0x6d0) | 0x1000000;
    }
    lVar42 = 0;
    if ((*(uint *)(param_1 + 0x448) & 2) != 0) {
      lVar42 = param_1 + 0x768;
    }
    iVar17 = FUN_fffffff00a9dee48(lVar42,"com.apple.private.vfs.unmunged-access-time");
    if (iVar17 != 0) {
      *(uint *)(param_1 + 0x450) = *(uint *)(param_1 + 0x450) | 8;
    }
    FUN_fffffff00a26b850(lVar44);
    FUN_fffffff00a26ba84(lVar44);
    if ((int)uVar22 == 0 && uVar27 == 0) goto LAB_fffffff00a710670;
  }
  else if ((int)uVar22 == 0 && uVar27 == 0) {
LAB_fffffff00a710670:
    FUN_fffffff00a26ea94(lVar44,lVar19);
  }
  if ((puVar20 != (ulong *)0x0) && (puVar20[0x57] != 0)) {
    lVar42 = FUN_fffffff00a29bafc();
    uVar21 = lVar42 + 0x48;
    uVar46 = (uVar21 ^ uVar21 >> 0x1f) * 0x7fb5d329728ea185;
    lVar42 = (uVar46 ^ uVar46 >> 0x1b) * -0x7e25210b43d22bb3;
    uVar46 = DAT_fffffff007bc7040 +
             (ulong)(DAT_fffffff007bc7048 - 1U & ((uint)((ulong)lVar42 >> 0x21) ^ (uint)lVar42)) *
             0x18;
    if (((DAT_fffffff007bc7040 ^ uVar46) & 0xffc0000000000000) != 0) {
      uVar46 = uVar46 & 0xffffffffffff | 0xc8a2000000000000;
    }
    FUN_fffffff00a28c5d4(uVar46,uVar21,0,0,0xffffffff);
  }
  if ((int)uVar22 == 0) {
    uVar21 = puVar20[0x5c];
    if (uVar21 == 0) {
LAB_fffffff00a7108d0:
      uVar22 = 0;
      uVar18 = uVar27;
    }
    else {
      lVar42 = *(long *)(uVar21 + 0x50);
      uVar5 = *(uint *)(uVar21 + 0x58);
      uVar22 = (ulong)uVar5;
      uVar18 = *(uint *)(uVar21 + 0x24) & 0xf00;
      if (uVar18 == 0) {
LAB_fffffff00a7107f4:
        bVar32 = 0;
        uVar18 = 0;
      }
      else {
        uVar18 = uVar18 - 0x100 >> 8;
        if (uVar18 < 4) {
          if (uVar18 < 2) {
            if (uVar18 == 0) {
              uVar18 = 5;
              bVar32 = 1;
            }
            else {
              if (uVar18 != 1) goto LAB_fffffff00a7107f4;
              uVar18 = 6;
              bVar32 = 1;
            }
          }
          else {
            if (uVar18 == 2) goto LAB_fffffff00a7107d0;
            if (uVar18 != 3) goto LAB_fffffff00a7107f4;
            bVar32 = 1;
            uVar18 = 1;
          }
        }
        else if (uVar18 < 6) {
          if (uVar18 == 4) {
LAB_fffffff00a7107d0:
            bVar32 = 1;
          }
          else {
            if (uVar18 != 5) goto LAB_fffffff00a7107f4;
            uVar18 = 3;
            bVar32 = 1;
          }
        }
        else {
          if (uVar18 != 6) {
            if (uVar18 != 7) goto LAB_fffffff00a7107f4;
            uVar18 = 8;
            goto LAB_fffffff00a7107d0;
          }
          uVar18 = 7;
          bVar32 = 1;
        }
      }
      if (lVar42 == 3) {
        uVar25 = 1;
joined_r0xfffffff00a710858:
        bVar30 = 1;
joined_r0xfffffff00a710858:
        if (uVar5 != 0) goto LAB_fffffff00a710828;
LAB_fffffff00a71085c:
        iVar17 = 0;
      }
      else {
        if (lVar42 == 2) {
          uVar25 = 2;
          goto joined_r0xfffffff00a710858;
        }
        if (lVar42 != 1) {
          bVar30 = 0;
          uVar25 = 0;
          goto joined_r0xfffffff00a710858;
        }
        uVar25 = 3;
        bVar30 = 1;
        if (uVar5 == 0) {
          bVar30 = 1;
          goto LAB_fffffff00a71085c;
        }
LAB_fffffff00a710828:
        if (uVar5 < 8) {
          iVar17 = *(int *)(&DAT_fffffff0070109c4 + uVar22 * 4);
        }
        else {
          iVar17 = 0;
        }
        uVar22 = (ulong)(iVar17 != 0);
      }
      if ((((bool)(bVar32 | bVar30)) || ((uVar22 & 1) != 0)) || (local_300._4_4_ != 0)) {
        lVar42 = 0;
        if ((*(uint *)(param_1 + 0x448) & 2) != 0) {
          lVar42 = param_1 + 0x768;
        }
        FUN_fffffff00a26e3cc(lVar42,puVar20[0x57],uVar18,uVar25,iVar17,local_2e8);
      }
      else {
      }
      if ((int)uStack_2f8 == 0) goto LAB_fffffff00a7108d0;
      lVar42 = 0;
      if ((*(uint *)(param_1 + 0x448) & 2) != 0) {
        lVar42 = param_1 + 0x768;
      }
      iVar17 = FUN_fffffff00a21d008(lVar42,local_2e0[0],local_2e0[1],local_2e0[2]);
      if (iVar17 == 0) {
        uVar22 = 0;
        local_2e0[0] = 0;
        local_2e0[1] = 0;
        local_2e0[2] = 0;
        uStack_2f8 = uStack_2f8 & 0xffffffff00000000;
        if (uVar27 != 0) goto LAB_fffffff00a710718;
        goto LAB_fffffff00a7108dc;
      }
      uVar22 = 0x16;
      uVar18 = uVar27 | 0x16;
    }
    if (uVar18 == 0) goto LAB_fffffff00a7108dc;
LAB_fffffff00a710718:
    if ((int)uVar22 != 0) goto LAB_fffffff00a71071c;
LAB_fffffff00a7108f0:
    uVar21 = puVar20[0x5c];
    if (uVar21 == 0) {
      local_310 = 1;
      if ((*(ushort *)(param_1 + 0x616) & 4) != 0) {
        local_310 = 2;
      }
LAB_fffffff00a710938:
      local_318 = 0x300000000;
      uVar22 = FUN_fffffff00a734ba8(param_1,2,0,local_310 | 4,&local_318);
      if ((int)uVar22 != 0) {
        bVar15 = false;
        goto LAB_fffffff00a710974;
      }
    }
    else {
      local_310 = 0;
      local_318 = 0x300000000;
      if (((*(byte *)(uVar21 + 0x80) >> 2 & 1) != 0) &&
         (local_310 = *(uint *)(uVar21 + 0x98), local_310 != 0)) goto LAB_fffffff00a710938;
    }
    FUN_fffffff00a282648(lVar44,puVar20[0x57]);
    uVar22 = 0;
    bVar15 = true;
  }
  else {
    if ((int)uVar22 != 0 || uVar27 != 0) goto LAB_fffffff00a710718;
LAB_fffffff00a7108dc:
    FUN_fffffff00a265a14(lVar19,lVar44,puVar20[0x57]);
    if ((int)uVar22 == 0) goto LAB_fffffff00a7108f0;
LAB_fffffff00a71071c:
    bVar15 = false;
    local_310 = 0;
    local_318 = 0x300000000;
  }
LAB_fffffff00a710974:
  uVar21 = local_2f0;
  iVar17 = (int)in_xzr;
  if (puVar20[0x5e] != 0) {
    if (local_2f0 != 0) {
      uVar46 = local_300 & 0xffffffff;
      if ((int)local_300 == 0) {
        lVar42 = 0;
      }
      else {
        lVar42 = 0;
        uVar29 = uVar46;
        do {
          if (*(long *)(uVar21 + lVar42 * 0x10) != 0) {
            FUN_fffffff00a1f4ae8();
          }
          lVar42 = lVar42 + 1;
          uVar29 = uVar29 - 1;
        } while (uVar29 != 0);
        lVar42 = uVar46 << 4;
      }
      local_2f0 = 0;
      FUN_fffffff00a2212a8(&DAT_fffffff007c85341,uVar21,lVar42);
    }
    lVar42 = local_2e8;
    if (local_2e8 != 0) {
      uVar21 = (ulong)local_300._4_4_;
      if (local_300._4_4_ == 0) {
        lVar43 = 0;
      }
      else {
        lVar43 = 0;
        uVar46 = uVar21;
        do {
          if (*(long *)(lVar42 + lVar43 * 8) != 0) {
            FUN_fffffff00a1f4ae8();
          }
          lVar43 = lVar43 + 1;
          uVar46 = uVar46 - 1;
        } while (uVar46 != 0);
        lVar43 = uVar21 << 3;
      }
      local_2e8 = 0;
      FUN_fffffff00a2212a8(&DAT_fffffff007c85391,lVar42,lVar43);
    }
    iVar17 = (int)in_xzr;
    uVar21 = uStack_2f8 & 0xffffffff;
    if ((int)uStack_2f8 != 0) {
      lVar42 = 0;
      do {
        if (local_2e0[lVar42] != 0) {
          FUN_fffffff00a1f4ae8();
        }
        iVar17 = (int)in_xzr;
        lVar42 = lVar42 + 1;
        uVar21 = uVar21 - 1;
      } while (uVar21 != 0);
    }
    uVar22 = uVar22 & 0xffffffff;
    if (local_2e0[3] != 0) {
      FUN_fffffff00a1f4ae8();
      local_2e0[3] = 0;
    }
  }
  bVar11 = false;
  if (!bVar16) {
    bVar11 = (bool)(bVar15 ^ 1);
  }
  if (bVar11) {
LAB_fffffff00a710b50:
    if (uVar27 != 0) goto LAB_fffffff00a710b54;
  }
  else {
    uVar18 = FUN_fffffff00a712d78(param_1,puVar20);
    if (!bVar15) {
      uVar18 = (uint)uVar22;
    }
    uVar22 = (ulong)uVar18;
    if (uVar18 == 0) {
      FUN_fffffff00a7135a8(puVar20,param_1,lVar44);
      if (uVar27 != 0) goto LAB_fffffff00a710b18;
      goto LAB_fffffff00a710b50;
    }
    if (uVar27 == 0) goto LAB_fffffff00a710b50;
LAB_fffffff00a710b18:
    if (puVar20 == (ulong *)0x0) goto LAB_fffffff00a710b50;
    if ((*(uint *)(param_1 + 0xe10) >> 7 & 1) != 0) {
      lVar42 = 0;
      if ((*(uint *)(param_1 + 0x448) & 2) != 0) {
        lVar42 = param_1 + 0x768;
      }
      FUN_fffffff00a738b50(param_1,lVar42,puVar20[0x57],2,5,0);
    }
LAB_fffffff00a710b54:
    lVar42 = *(long *)(param_1 + 0x10);
    if (lVar42 == 0) {
      lVar42 = 0;
    }
    if (param_1 == DAT_fffffff007c6b250) {
      uVar21 = 0x40000000;
    }
    else {
      uVar21 = (long)*(int *)(param_1 + 0x60) | 0x40000000;
    }
    FUN_fffffff00a72d078(lVar42,uVar21);
  }
  iVar37 = (int)uVar22;
  if ((iVar37 == 0) && ((*(byte *)(param_1 + 1099) >> 2 & 1) == 0)) {
    FUN_fffffff00a72d078(param_1,0x20000000);
  }
  if (puVar20 != (ulong *)0x0) {
    *(undefined8 *)(lVar10 + 0x5f0) = 0;
    if (puVar20[4] != 0) {
      FUN_fffffff00a3e8aa8();
    }
    if (puVar20[0x5a] != 0) {
      FUN_fffffff00a3e8aa8();
    }
    if (puVar20[0xe] != 0) {
      FUN_fffffff00a713818(puVar20);
    }
    if (puVar20[0x5f] != 0) {
      FUN_fffffff00a2e6e78();
    }
    uVar21 = puVar20[0x5d];
    puVar20[0x5d] = 0;
    FUN_fffffff00a2212a8(&DAT_fffffff007c6afb0,uVar21,local_190);
    uVar21 = puVar20[0x5e];
    puVar20[0x5e] = 0;
    FUN_fffffff00a2212a8(&DAT_fffffff007c6afb0,uVar21,local_180);
    uVar21 = puVar20[99];
    puVar20[99] = 0;
    FUN_fffffff00a2212a8(&DAT_fffffff007c6afb0,uVar21,local_150);
    uVar21 = puVar20[100];
    puVar20[100] = 0;
    FUN_fffffff00a2212a8(&DAT_fffffff007c6afb0,uVar21,local_140);
    uVar25 = DAT_fffffff007c6af98;
    lVar42 = DAT_fffffff007c6af90;
    if (lVar40 != 0) {
      uVar7 = *(undefined2 *)(DAT_fffffff007c6af90 + 0x34);
      FUN_fffffff00aa65cc0(lVar40,uVar7);
      FUN_fffffff00a29223c(lVar42,uVar25,lVar40,uVar7);
    }
    uVar21 = puVar20[0x60];
    puVar20[0x60] = 0;
    FUN_fffffff00a2212a8(&DAT_fffffff007c6afb0,uVar21,local_170);
    uVar21 = puVar20[0x61];
    puVar20[0x61] = 0;
    FUN_fffffff00a2212a8(&DAT_fffffff007c6afb0,uVar21,puVar20[0x62]);
    if (puVar20[0x58] != 0) {
      FUN_fffffff00aa1ca90();
      puVar20[0x58] = 0;
    }
    uVar21 = puVar20[0x59];
    if (uVar21 != 0) {
      FUN_fffffff00aa224c4(uVar21);
      uVar25 = DAT_fffffff00ad4c548;
      uVar26 = DAT_fffffff007bccf94;
      FUN_fffffff00a38107c(4,uVar21,0,DAT_fffffff007bccf94);
      FUN_fffffff00a29223c(&DAT_fffffff00ad4c540,uVar25,uVar21,uVar26);
      puVar20[0x59] = 0;
    }
    if (puVar20[0x65] != 0) {
      FUN_fffffff00a7d1d48();
      puVar20[0x65] = 0;
    }
    uVar21 = puVar20[0x66];
    if (uVar21 != 0) {
      lVar40 = FUN_fffffff00a1d1550(uVar21);
      puVar20[0x66] = 0;
      FUN_fffffff00a2212a8(&DAT_fffffff007c6afb0,uVar21,lVar40 + 1);
      puVar20[0x66] = 0;
    }
  }
  if ((lVar44 != 0) && ((*(uint *)(lVar44 + 0x6a8) >> 3 & 1) != 0)) {
    FUN_fffffff00a25d670(lVar44);
  }
  if ((local_328 == 0) || (uVar27 != 0)) {
    if ((uVar27 != 0) && (puVar20 != (ulong *)0x0)) {
      if ((iVar37 == 0) && (uVar28 != 0)) {
        if (param_1 == DAT_fffffff007c6b250) {
          uVar18 = 0;
          if ((uVar28 & 3) == 0) goto LAB_fffffff00a710fb8;
LAB_fffffff00a710ef0:
          local_e0 = uVar18;
          uStack_dc = (int)local_e0 >> 0x1f;
          FUN_fffffff00a38a690(&local_e0,uVar28,4);
        }
        else {
          uVar18 = *(uint *)(param_1 + 0x60);
          if ((uVar28 & 3) != 0) goto LAB_fffffff00a710ef0;
LAB_fffffff00a710fb8:
          FUN_fffffff00a38a16c(uVar18,uVar28);
        }
        *param_3 = 0;
      }
      else {
        *param_3 = iVar37;
        if (iVar37 != 0) {
          FUN_fffffff00a729120(param_1,0);
          if (*(ulong *)(param_1 + 0x58) == 0) {
            *(ulong *)(param_1 + 0x58) = (ulong)*(uint *)(lVar10 + 0x4e8);
          }
          else {
            FUN_fffffff00a2262d4(param_1 + 0x50,lVar10,0);
          }
          if ((*(char *)(param_1 + 0xe08) == '\x05') || (*(long *)(param_1 + 0x500) != 0)) {
            if (*(int *)(param_1 + 0x58) == *(int *)(lVar10 + 0x4e8)) {
              *(int *)(param_1 + 0x58) = iVar17;
            }
            else {
              FUN_fffffff00a226e08(param_1 + 0x50,lVar10);
            }
          }
          else {
            *(long *)(param_1 + 0x500) = lVar10;
            *(undefined1 *)(param_1 + 0x6cb) = 1;
            if (*(int *)(param_1 + 0x58) == *(int *)(lVar10 + 0x4e8)) {
              *(int *)(param_1 + 0x58) = iVar17;
            }
            else {
              FUN_fffffff00a226e08(param_1 + 0x50);
            }
            FUN_fffffff00a717828(param_1,1);
          }
        }
      }
    }
  }
  else {
    FUN_fffffff00a738b50(param_1,0,0,0,9);
  }
  if ((*(uint *)(lVar19 + 0x6a8) >> 2 & 1) != 0) {
    FUN_fffffff00a25d670(lVar19);
  }
  if ((puVar20 != (ulong *)0x0) && (puVar20[0x57] != 0)) {
    uVar26 = 6;
    if (iVar37 == 0 || (uVar27 != 0 || bVar16)) {
      uVar26 = 2;
    }
    uVar25 = FUN_fffffff00a29bafc();
    FUN_fffffff00a25fb10(uVar25,uVar26);
    if (puVar20[0x57] != 0) {
      piVar36 = (int *)(puVar20[0x57] + 0x218);
      iVar17 = *piVar36;
      *piVar36 = iVar17 + -1;
      LORelease();
      if (iVar17 == 0) goto LAB_fffffff00a711064;
      if (iVar17 == 1) {
        FUN_fffffff00a270c78();
      }
    }
    puVar20[0x57] = 0;
  }
  if (lVar44 != 0) {
    piVar36 = (int *)(lVar44 + 0x10);
    iVar17 = *piVar36;
    *piVar36 = iVar17 + -1;
    LORelease();
    if (iVar17 == 0) {
LAB_fffffff00a711064:
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa61ea0(piVar36);
    }
    FUN_fffffff00a2626e0(lVar44,iVar17 + -1);
  }
  if (bVar12) {
    FUN_fffffff00a724838(param_1);
  }
  FUN_fffffff00a29762c(&DAT_fffffff007c78750,puVar20);
  if (local_308 != 0) {
    FUN_fffffff00a1e3aa4();
  }
  if (DAT_fffffff00ad30000 == local_98) {
    return uVar22;
  }
                    /* WARNING: Subroutine does not return */
  FUN_fffffff00aa4c590();
}

