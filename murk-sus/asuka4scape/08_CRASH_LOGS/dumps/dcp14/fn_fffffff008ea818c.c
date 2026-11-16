// FUN_fffffff008ea818c @ fffffff008ea818c size=3792
// CALLERS:
//   fffffff00afb870d no-fn
// CALLEES:
//   fffffff008eb93f0 thunk_EXT_FUN_8011000002c24af0
//   fffffff008ea2734 FUN_fffffff008ea2734
//   fffffff008eb9480 thunk_EXT_FUN_8011000003a48590
//   fffffff008ea80b4 FUN_fffffff008ea80b4
//   fffffff008eb93e0 thunk_EXT_FUN_8011000002c1eb48
//   fffffff008ea7e28 FUN_fffffff008ea7e28
//   fffffff008eb9350 thunk_EXT_FUN_8011000002c1e3bc
//   fffffff008eb8920 thunk_EXT_FUN_80110000038ff2e0
//   fffffff008eb9340 thunk_EXT_FUN_8011000002c1e35c
//   fffffff008eb88a0 thunk_EXT_FUN_80110000038fe9a0
//   fffffff008eb8b80 thunk_EXT_FUN_8011000002a7c804
//   fffffff008eb9370 thunk_EXT_FUN_8011000002c1e350
//   fffffff008eb8910 thunk_EXT_FUN_80110000038ff214
//   fffffff008eb8b00 thunk_EXT_FUN_8011000002aa3eec
//   fffffff008ea905c FUN_fffffff008ea905c

/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined8 FUN_fffffff008ea818c(long *param_1,long param_2,undefined8 param_3,undefined1 **param_4)

{
  long lVar1;
  long lVar2;
  long lVar3;
  int *piVar4;
  uint *puVar5;
  int *piVar6;
  undefined2 *puVar7;
  undefined4 *puVar8;
  ushort *puVar9;
  int iVar10;
  undefined8 *puVar11;
  bool bVar12;
  byte bVar13;
  int iVar14;
  int iVar15;
  undefined4 uVar16;
  long *plVar17;
  long *plVar18;
  long lVar19;
  long *plVar20;
  undefined4 uVar21;
  int iVar22;
  undefined4 uVar23;
  long lVar24;
  ulong uVar25;
  uint uVar26;
  long lVar27;
  ulong uVar28;
  uint uVar29;
  uint uVar30;
  uint uVar31;
  long lVar32;
  long lVar33;
  undefined8 uVar34;
  undefined8 local_230;
  undefined8 uStack_228;
  undefined1 *local_220;
  undefined8 *puStack_218;
  undefined8 *local_210;
  undefined8 *puStack_208;
  undefined4 *local_200;
  undefined1 local_1f5;
  undefined4 local_1f4;
  undefined8 local_1f0;
  undefined8 uStack_1e8;
  undefined8 local_1e0;
  undefined8 auStack_1d8 [7];
  undefined8 local_1a0;
  undefined8 uStack_198;
  undefined8 local_190;
  undefined8 uStack_188;
  undefined8 local_180;
  undefined8 uStack_178;
  undefined8 uStack_170;
  undefined8 uStack_168;
  undefined8 uStack_160;
  undefined8 local_158;
  undefined8 local_150;
  undefined8 uStack_148;
  undefined8 uStack_140;
  undefined8 uStack_138;
  undefined8 local_130;
  undefined8 uStack_128;
  undefined8 uStack_120;
  undefined8 uStack_118;
  undefined8 local_110;
  undefined8 uStack_108;
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
  
  local_70 = *(long *)PTR_DAT_fffffff007e748e0;
  lVar33 = param_1[0xcbc];
  if (lVar33 != 0) {
    thunk_EXT_FUN_80110000038ff214(lVar33);
  }
  if (param_1[0xbc1] != 0) {
    FUN_fffffff008ea2734();
  }
  if (((*(byte *)(param_1 + 0x86) & 1) == 0) || (*(int *)((long)param_1 + 0x58f4) != 0)) {
    if ((param_2 != 0) &&
       ((((long *)param_1[0xbd2] != (long *)0x0 &&
         (iVar14 = (**(code **)(*(long *)param_1[0xbd2] + 800))(), iVar14 != 0)) &&
        ((*(byte *)(param_2 + 0x351) & 1) != 0)))) {
      if ((*(byte *)(param_1 + 0xbd7) & 1) == 0) {
        *(undefined2 *)(param_2 + 0x351) = 0x100;
      }
      else {
        *(undefined1 *)(param_2 + 0x352) = 0;
      }
    }
    plVar17 = (long *)param_1[0xc38];
    plVar20 = param_1;
    if ((plVar17 == (long *)0x0) || ((*(byte *)((long)plVar17 + 0x5df1) & 1) == 0)) {
      if (((*(byte *)((long)param_1 + 0x65bd) & 1) != 0) &&
         ((*(byte *)((long)param_1 + 0x65ae) & 1) != 0)) {
        local_1f4 = thunk_EXT_FUN_8011000002c1e35c(param_1[0x2e]);
        lVar24 = 0;
        uStack_178 = 0xaaaaaaaaaaaaaaaa;
        local_180 = 0xaaaaaaaaaaaaaaaa;
        uStack_168 = 0xaaaaaaaaaaaaaaaa;
        uStack_170 = 0xaaaaaaaaaaaaaaaa;
        uStack_198 = 0xaaaaaaaaaaaaaaaa;
        local_1a0 = 0xaaaaaaaaaaaaaaaa;
        uStack_188 = 0xaaaaaaaaaaaaaaaa;
        local_190 = 0xaaaaaaaaaaaaaaaa;
        auStack_1d8[4] = 0xaaaaaaaaaaaaaaaa;
        auStack_1d8[3] = 0xaaaaaaaaaaaaaaaa;
        auStack_1d8[6] = 0xaaaaaaaaaaaaaaaa;
        auStack_1d8[5] = 0xaaaaaaaaaaaaaaaa;
        auStack_1d8[0] = 0xaaaaaaaaaaaaaaaa;
        local_1e0 = 0xaaaaaaaaaaaaaaaa;
        auStack_1d8[2] = 0xaaaaaaaaaaaaaaaa;
        auStack_1d8[1] = 0xaaaaaaaaaaaaaaaa;
        uStack_1e8 = 0xaaaaaaaaaaaaaaaa;
        local_1f0 = 0xaaaaaaaaaaaaaaaa;
        uVar26 = *(uint *)(param_2 + 0x14c);
        do {
          if ((uVar26 >> (ulong)((uint)lVar24 & 0x1f) & 1) != 0) {
            puVar11 = (undefined8 *)(param_2 + 0xac + lVar24 * 0x10);
            uVar34 = *puVar11;
            (&uStack_198)[lVar24 * 2] = puVar11[1];
            (&local_1a0)[lVar24 * 2] = uVar34;
            puVar11 = (undefined8 *)(param_2 + 0x10c + lVar24 * 0x10);
            uVar34 = *puVar11;
            auStack_1d8[lVar24 * 2] = puVar11[1];
            auStack_1d8[lVar24 * 2 + -1] = uVar34;
            *(undefined4 *)((long)&local_1f0 + lVar24 * 4) =
                 *(undefined4 *)(param_2 + 0x9c + lVar24 * 4);
          }
          lVar24 = lVar24 + 1;
        } while (lVar24 != 4);
        local_1f5 = 0xaa;
        local_220 = &local_1f5;
        puStack_218 = &local_1a0;
        local_210 = &local_1e0;
        puStack_208 = &local_1f0;
        local_200 = &local_1f4;
        iVar14 = FUN_fffffff008ea7e28(param_1,param_2);
        if (iVar14 == -0x1ffffd38) goto LAB_fffffff008ea8ae0;
        local_230 = 0;
        uStack_228 = 0;
        (**(code **)(*param_1 + 0xc90))(param_1,&local_230);
        FUN_fffffff008ea905c(&local_220,param_2,&local_230);
        thunk_EXT_FUN_8011000002a7c804(param_1,param_2,param_3,0);
        if ((char)param_1[0xc3d] != '\0') {
          uVar25 = 0;
          do {
            local_230 = 0;
            uStack_228 = 0;
            (**(code **)(*(long *)param_1[uVar25 + 0xc39] + 0xc90))
                      ((long *)param_1[uVar25 + 0xc39],&local_230);
            FUN_fffffff008ea905c(&local_220,param_2,&local_230);
            thunk_EXT_FUN_8011000002a7c804(param_1[uVar25 + 0xc39],param_2,param_3,0);
            uVar25 = uVar25 + 1;
          } while (uVar25 < *(byte *)(param_1 + 0xc3d));
        }
        goto joined_r0xfffffff008ea8bd8;
      }
    }
    else {
      auStack_1d8[0] = 0xaaaaaaaaaaaaaaaa;
      local_1e0 = 0xaaaaaaaaaaaaaaaa;
      (**(code **)(*plVar17 + 0xc90))(plVar17,&local_1e0);
      lVar24 = 0;
      plVar17 = param_1;
      plVar20 = (long *)param_1[0xc38];
      if ((int)local_1e0 != 0) {
        plVar17 = (long *)param_1[0xc38];
        plVar20 = param_1;
      }
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
      uStack_108 = 0;
      local_110 = 0;
      uStack_f8 = 0;
      uStack_100 = 0;
      uStack_128 = 0;
      local_130 = 0;
      uStack_118 = 0;
      uStack_120 = 0;
      uStack_148 = 0;
      local_150 = 0;
      uStack_138 = 0;
      uStack_140 = 0;
      uStack_168 = 0;
      uStack_170 = 0;
      local_158 = 0;
      uStack_160 = 0;
      lVar1 = param_2 + 0x9c;
      uStack_188 = 0;
      local_190 = 0;
      uStack_178 = 0;
      local_180 = 0;
      lVar2 = param_2 + 0xac;
      lVar3 = param_2 + 0x10c;
      uStack_198 = 0;
      local_1a0 = 0;
      uVar26 = *(uint *)(param_2 + 0x14c);
      do {
        if (((uVar26 >> (ulong)((uint)lVar24 & 0x1f) & 1) != 0) &&
           (iVar14 = *(int *)(lVar1 + lVar24 * 4), iVar14 != 0)) {
          piVar4 = (int *)(lVar2 + lVar24 * 0x10);
          puVar5 = (uint *)(lVar3 + lVar24 * 0x10);
          lVar32 = lVar24 * 0x4c;
          piVar6 = (int *)((long)&local_1a0 + lVar32);
          iVar15 = *piVar4;
          iVar10 = piVar4[2];
          uVar31 = *puVar5;
          uVar29 = puVar5[2];
          uVar30 = 2;
          if (uVar29 + uVar31 <= (uint)auStack_1d8[0]) {
            uVar30 = 0;
          }
          if (uVar31 < (uint)auStack_1d8[0]) {
            uVar30 = uVar30 + 1;
          }
          if (uVar30 < 2) {
            if (uVar30 != 0) {
              *(uint *)((long)&uStack_188 + lVar32) = uVar31;
              *(uint *)((long)&local_180 + lVar32) = uVar29;
              *(int *)((long)&local_190 + lVar32) = iVar10;
              *(int *)((long)&uStack_198 + lVar32) = iVar15;
            }
          }
          else if (uVar30 == 2) {
            *(uint *)((long)&uStack_168 + lVar32) = uVar31 - (uint)auStack_1d8[0];
            *(uint *)((long)&uStack_160 + lVar32) = uVar29;
            *(int *)((long)&uStack_170 + lVar32) = iVar10;
            *(int *)((long)&uStack_178 + lVar32) = iVar15;
          }
          else {
            uVar30 = iVar10 + iVar15;
            *(uint *)((long)&uStack_188 + lVar32) = uVar31;
            *(uint *)((long)&local_180 + lVar32) = (uint)auStack_1d8[0] - uVar31;
            iVar15 = (uVar31 - (uint)auStack_1d8[0]) + uVar29;
            *(int *)((long)&uStack_160 + lVar32) = iVar15;
            iVar22 = (int)((float)(int)((uint)auStack_1d8[0] - uVar31) *
                           ((float)iVar10 / (float)(int)uVar29) + 0.5);
            *(int *)((long)&local_190 + lVar32) = iVar22;
            iVar15 = (int)((float)iVar15 * ((float)iVar10 / (float)(int)uVar29) + 0.5);
            *(int *)((long)&uStack_170 + lVar32) = iVar15;
            if (uVar30 < (uint)(*(int *)((long)&uStack_198 + lVar32) + iVar22)) {
              iVar22 = uVar30 - *(int *)((long)&uStack_198 + lVar32);
              *(int *)((long)&local_190 + lVar32) = iVar22;
            }
            *(int *)((long)&uStack_178 + lVar32) = iVar22;
            if (uVar30 < (uint)(iVar22 + iVar15)) {
              *(uint *)((long)&uStack_170 + lVar32) = uVar30 - iVar22;
            }
          }
          if ((uVar31 < (uint)auStack_1d8[0]) && (0 < *(int *)((long)&local_190 + lVar32))) {
            *(uint *)((long)&local_158 + lVar32) = *(uint *)((long)&local_158 + lVar32) | 1;
            *piVar6 = iVar14;
          }
          if ((uint)auStack_1d8[0] < uVar29 + uVar31) {
            iVar15 = *(int *)((long)&uStack_170 + lVar32);
            uVar30 = *(uint *)((long)&local_158 + lVar32);
            if (0 < iVar15) {
              uVar30 = uVar30 | 2;
              *(uint *)((long)&local_158 + lVar32) = uVar30;
              *(int *)((long)&local_1a0 + lVar32 + 4) = iVar14;
            }
            if ((lVar24 == 3) && (uVar30 != 3)) {
                    /* WARNING: Ignoring partial resolution of indirect */
              uStack_a8._4_4_ = uStack_88._4_4_;
                    /* WARNING: Ignoring partial resolution of indirect */
              uStack_a0._4_4_ = uStack_80._4_4_;
                    /* WARNING: Ignoring partial resolution of indirect */
              local_b0._4_4_ = iVar15;
              iVar14 = (int)uStack_b8;
                    /* WARNING: Ignoring partial resolution of indirect */
              uStack_b8._4_4_ = uStack_98._4_4_;
              *piVar6 = iVar14;
              uVar21 = uStack_88._4_4_;
              uVar16 = uStack_80._4_4_;
              uVar23 = uStack_98._4_4_;
              if (uVar31 < (uint)auStack_1d8[0]) goto LAB_fffffff008ea851c;
            }
          }
          else {
            uVar30 = *(uint *)((long)&local_158 + lVar32);
            if (((uVar31 < (uint)auStack_1d8[0]) && (lVar24 == 3)) && (uVar30 != 3)) {
              iVar14 = *piVar6;
              iVar15 = local_b0._4_4_;
              uVar21 = uStack_a8._4_4_;
              uVar16 = uStack_a0._4_4_;
              uVar23 = uStack_b8._4_4_;
LAB_fffffff008ea851c:
              *(undefined4 *)((long)&uStack_168 + lVar32) = uVar21;
              *(undefined4 *)((long)&uStack_160 + lVar32) = uVar16;
              *(int *)((long)&uStack_170 + lVar32) = iVar15;
              *(undefined4 *)((long)&uStack_178 + lVar32) = uVar23;
              *(int *)((long)&local_1a0 + lVar32 + 4) = iVar14;
            }
          }
          *(uint *)(param_2 + 0x442 + lVar24 * 4) = uVar30;
          puVar7 = (undefined2 *)(param_2 + 0x432 + lVar24 * 4);
          *puVar7 = (short)piVar4[2];
          puVar7[1] = (short)puVar5[2];
        }
        lVar24 = lVar24 + 1;
      } while (lVar24 != 4);
      local_220 = (undefined1 *)((ulong)local_220 & 0xffffffff00000000);
      iVar14 = FUN_fffffff008ea7e28(param_1,param_2);
      if (iVar14 == -0x1ffffd38) {
LAB_fffffff008ea8ae0:
        uVar34 = 0xe00002c8;
        if (lVar33 != 0) {
          thunk_EXT_FUN_80110000038ff2e0(param_1[0xcbc]);
        }
        goto LAB_fffffff008ea8ff0;
      }
      lVar24 = 0;
      do {
        if ((*(uint *)(param_2 + 0x14c) >> (ulong)((uint)lVar24 & 0x1f) & 1) != 0) {
          lVar32 = lVar24 * 0x4c;
          if ((lVar24 == 3) || ((*(uint *)((long)&local_158 + lVar32) & 1) != 0)) {
            puVar8 = (undefined4 *)(lVar2 + lVar24 * 0x10);
            *puVar8 = *(undefined4 *)((long)&uStack_198 + lVar32);
            puVar8[2] = *(undefined4 *)((long)&local_190 + lVar32);
            puVar8 = (undefined4 *)(lVar3 + lVar24 * 0x10);
            *puVar8 = *(undefined4 *)((long)&uStack_188 + lVar32);
            puVar8[2] = *(undefined4 *)((long)&local_180 + lVar32);
          }
          *(undefined4 *)(lVar1 + lVar24 * 4) = *(undefined4 *)((long)&local_1a0 + lVar32);
        }
        lVar24 = lVar24 + 1;
      } while (lVar24 != 4);
      uVar21 = *(undefined4 *)(param_2 + 0x150);
      plVar18 = (long *)thunk_EXT_FUN_8011000002aa3eec(param_3);
      if (plVar18 == (long *)0x0) {
        *(undefined1 *)(param_2 + 0x352) = 0;
        thunk_EXT_FUN_80110000038fe9a0
                  ("%s: async_swap_hw forced to false -> config mismatch - swap creation failed\n");
      }
      if ((*(byte *)(param_2 + 0x352) & 1) != 0) {
        *(undefined4 *)((long)plVar18 + 0x3d4) = *(undefined4 *)(param_2 + 0x98);
        FUN_fffffff008ea80b4(param_1,param_2,plVar18);
        lVar24 = 0;
        uVar26 = 0;
        DAT_fffffff00aec9d80 = 0;
        uVar30 = DAT_fffffff00aec9d7c;
        do {
          uVar31 = *(uint *)(param_2 + 0x14c);
          if (uVar30 != uVar31) {
            uVar26 = uVar26 | 0x80000000;
            DAT_fffffff00aec9d7c = uVar31;
          }
          uVar30 = uVar31;
          if ((uVar31 >> (ulong)((uint)lVar24 & 0x1f) & 1) != 0) {
            lVar32 = plVar18[lVar24 + 0x170];
            if (lVar32 == 0) {
              if (((&DAT_fffffff00aec9d78)[lVar24] & 1) != 0) {
                uVar26 = uVar26 | 0x10000;
                (&DAT_fffffff00aec9d78)[lVar24] = 0;
              }
            }
            else {
              if (((&DAT_fffffff00aec9d78)[lVar24] & 1) == 0) {
                uVar26 = uVar26 | 0x10000;
                (&DAT_fffffff00aec9d78)[lVar24] = 1;
              }
              iVar14 = thunk_EXT_FUN_8011000002c1eb48(lVar32,0);
              if ((iVar14 != 0) && (((&DAT_fffffff00aec9c18)[lVar24 * 0x58] & 1) == 0)) {
                uVar26 = uVar26 | 1;
                (&DAT_fffffff00aec9c18)[lVar24 * 0x58] = 1;
              }
              lVar19 = thunk_EXT_FUN_8011000002c24af0(lVar32,0);
              if (((lVar19 != 0) && (*(char *)(lVar19 + 0x20) != '\0')) &&
                 (((&DAT_fffffff00aec9c19)[lVar24 * 0x58] & 1) == 0)) {
                uVar26 = uVar26 | 2;
                (&DAT_fffffff00aec9c19)[lVar24 * 0x58] = 1;
              }
              iVar14 = (&DAT_fffffff00aec9c1c)[lVar24 * 0x16];
              iVar15 = thunk_EXT_FUN_8011000002c1e3bc(lVar32);
              if (iVar14 != iVar15) {
                uVar26 = uVar26 | 4;
                uVar16 = thunk_EXT_FUN_8011000002c1e3bc(lVar32);
                (&DAT_fffffff00aec9c1c)[lVar24 * 0x16] = uVar16;
              }
              lVar19 = lVar24 * 0x4c;
              if ((((&DAT_fffffff00aec9c2c)[lVar24 * 0x16] != *(int *)((long)&uStack_198 + lVar19))
                  || ((&DAT_fffffff00aec9c30)[lVar24 * 0x16] !=
                      *(int *)((long)&uStack_198 + lVar19 + 4))) ||
                 (((&DAT_fffffff00aec9c34)[lVar24 * 0x16] != *(int *)((long)&local_190 + lVar19) ||
                  ((&DAT_fffffff00aec9c38)[lVar24 * 0x16] != *(int *)((long)&local_190 + lVar19 + 4)
                  )))) {
                uVar26 = uVar26 | 8;
                uVar34 = *(undefined8 *)((long)&uStack_198 + lVar19);
                *(undefined8 *)(&DAT_fffffff00aec9c34 + lVar24 * 0x16) =
                     *(undefined8 *)((long)&local_190 + lVar19);
                *(undefined8 *)(&DAT_fffffff00aec9c2c + lVar24 * 0x16) = uVar34;
              }
              if ((((&DAT_fffffff00aec9c3c)[lVar24 * 0x16] != *(int *)((long)&uStack_188 + lVar19))
                  || ((&DAT_fffffff00aec9c40)[lVar24 * 0x16] !=
                      *(int *)((long)&uStack_188 + lVar19 + 4))) ||
                 (((&DAT_fffffff00aec9c44)[lVar24 * 0x16] != *(int *)((long)&local_180 + lVar19) ||
                  ((&DAT_fffffff00aec9c48)[lVar24 * 0x16] != *(int *)((long)&local_180 + lVar19 + 4)
                  )))) {
                uVar26 = uVar26 | 0x10;
                uVar34 = *(undefined8 *)((long)&uStack_188 + lVar19);
                *(undefined8 *)(&DAT_fffffff00aec9c44 + lVar24 * 0x16) =
                     *(undefined8 *)((long)&local_180 + lVar19);
                *(undefined8 *)(&DAT_fffffff00aec9c3c + lVar24 * 0x16) = uVar34;
              }
              if (((((&DAT_fffffff00aec9c4c)[lVar24 * 0x16] != *(int *)((long)&uStack_178 + lVar19))
                   || ((&DAT_fffffff00aec9c50)[lVar24 * 0x16] !=
                       *(int *)((long)&uStack_178 + lVar19 + 4))) ||
                  ((&DAT_fffffff00aec9c54)[lVar24 * 0x16] != *(int *)((long)&uStack_170 + lVar19)))
                 || ((&DAT_fffffff00aec9c58)[lVar24 * 0x16] !=
                     *(int *)((long)&uStack_170 + lVar19 + 4))) {
                uVar26 = uVar26 | 0x20;
                uVar34 = *(undefined8 *)((long)&uStack_178 + lVar19);
                *(undefined8 *)(&DAT_fffffff00aec9c54 + lVar24 * 0x16) =
                     *(undefined8 *)((long)&uStack_170 + lVar19);
                *(undefined8 *)(&DAT_fffffff00aec9c4c + lVar24 * 0x16) = uVar34;
              }
              if ((((&DAT_fffffff00aec9c5c)[lVar24 * 0x16] != *(int *)((long)&uStack_168 + lVar19))
                  || ((&DAT_fffffff00aec9c60)[lVar24 * 0x16] !=
                      *(int *)((long)&uStack_168 + lVar19 + 4))) ||
                 (((&DAT_fffffff00aec9c64)[lVar24 * 0x16] != *(int *)((long)&uStack_160 + lVar19) ||
                  ((&DAT_fffffff00aec9c68)[lVar24 * 0x16] !=
                   *(int *)((long)&uStack_160 + lVar19 + 4))))) {
                uVar26 = uVar26 | 0x40;
                uVar34 = *(undefined8 *)((long)&uStack_168 + lVar19);
                *(undefined8 *)(&DAT_fffffff00aec9c64 + lVar24 * 0x16) =
                     *(undefined8 *)((long)&uStack_160 + lVar19);
                *(undefined8 *)(&DAT_fffffff00aec9c5c + lVar24 * 0x16) = uVar34;
              }
              if ((&DAT_fffffff00aec9c6c)[lVar24 * 0x16] != *(int *)((long)&local_158 + lVar19)) {
                uVar26 = uVar26 | 0x80;
                (&DAT_fffffff00aec9c6c)[lVar24 * 0x16] = *(int *)((long)&local_158 + lVar19);
              }
              iVar14 = thunk_EXT_FUN_8011000002c1e350(lVar32);
              uVar30 = DAT_fffffff00aec9d7c;
              uVar31 = uVar26;
              if ((&DAT_fffffff00aec9c20)[lVar24 * 0x16] != iVar14) {
                uVar31 = uVar26 | 0x100;
                (&DAT_fffffff00aec9c20)[lVar24 * 0x16] = iVar14;
              }
              uVar26 = uVar31 | 0x100;
              if (lVar24 != 2) {
                uVar26 = uVar31;
              }
              DAT_fffffff00aec9d80 = DAT_fffffff00aec9d80 + 1;
            }
          }
          lVar24 = lVar24 + 1;
        } while (lVar24 != 4);
        if (uVar26 != 0) {
          *(undefined1 *)(param_2 + 0x352) = 0;
        }
      }
      if ((*(byte *)(param_2 + 0x34f) & 1) != 0) {
        lVar24 = (**(code **)(*plVar20 + 0x8a8))(plVar20);
        lVar32 = (**(code **)(*plVar17 + 0x8a8))(plVar17);
        if ((*(byte *)(param_2 + 0x34f) & 1) != 0) {
          uVar30 = *(uint *)(param_2 + 0x14c);
          uVar26 = uVar30 >> 1 & 1;
          if ((uVar30 & 8) != 0) {
            uVar26 = 3;
          }
          uVar25 = (ulong)uVar26;
          lVar27 = uVar25 * 0x4c;
          uVar26 = *(uint *)((long)&local_158 + lVar27);
          lVar19 = lVar24;
          if (*(ulong *)(lVar24 + 0x490 + uVar25 * 8) <= *(ulong *)(lVar32 + 0x490 + uVar25 * 8)) {
            lVar19 = lVar32;
          }
          if (((*(uint *)(lVar19 + 0x594 + uVar25 * 4) ^ 0xffffffff) & 3) == 0) {
            puVar9 = (ushort *)(lVar19 + 0x584 + uVar25 * 4);
            uVar31 = (uint)*puVar9;
            uVar29 = (uint)puVar9[1];
          }
          else {
            uVar28 = uVar25 << 4 | 8;
            uVar31 = *(uint *)(lVar19 + 1 + uVar28);
            uVar29 = *(uint *)(lVar19 + 0x41 + uVar28);
          }
          if (((uVar30 ^ 0xffffffff) & 3) != 0 && uVar30 != 0) {
            if (((uVar26 ^ 0xffffffff) & 3) == 0) {
              puVar9 = (ushort *)(param_2 + 0x432 + uVar25 * 4);
              if (((uint)*puVar9 == (uVar31 & 0xffff)) && ((uint)puVar9[1] == (uVar29 & 0xffff)))
              goto LAB_fffffff008ea8dc8;
            }
            else if ((uVar26 & 1) == 0) {
              if ((uVar26 >> 1 & 1) != 0) {
                if (*(int *)(lVar32 + 0x594 + uVar25 * 4) == 2) {
                  uVar28 = uVar25 << 4 | 8;
                  uVar26 = *(uint *)(lVar32 + 1 + uVar28);
                  uVar30 = *(uint *)(lVar32 + 0x41 + uVar28);
                }
                else {
                  puVar9 = (ushort *)(lVar32 + 0x584 + uVar25 * 4);
                  uVar26 = (uint)*puVar9;
                  uVar30 = (uint)puVar9[1];
                }
                if ((*(uint *)((long)&uStack_170 + lVar27) == (uVar26 & 0xffff)) &&
                   (uVar28 = uVar25 << 4 | 0xc,
                   *(int *)(lVar32 + 1 + uVar28) == *(int *)(lVar2 + uVar28))) {
                  bVar12 = false;
                }
                else {
                  bVar12 = true;
                }
                if ((*(uint *)((long)&uStack_160 + lVar27) == (uVar30 & 0xffff)) &&
                   (uVar25 = uVar25 << 4 | 0xc,
                   *(int *)(lVar32 + 0x41 + uVar25) == *(int *)(lVar3 + uVar25)))
                goto LAB_fffffff008ea8d98;
              }
            }
            else {
              if (*(int *)(lVar24 + 0x594 + uVar25 * 4) == 1) {
                uVar28 = uVar25 << 4 | 8;
                uVar26 = *(uint *)(lVar24 + 1 + uVar28);
                uVar30 = *(uint *)(lVar24 + 0x41 + uVar28);
              }
              else {
                puVar9 = (ushort *)(lVar24 + 0x584 + uVar25 * 4);
                uVar26 = (uint)*puVar9;
                uVar30 = (uint)puVar9[1];
              }
              if ((*(uint *)((long)&local_190 + lVar27) == (uVar26 & 0xffff)) &&
                 (uVar28 = uVar25 << 4 | 0xc,
                 *(int *)(lVar24 + 1 + uVar28) == *(int *)(lVar2 + uVar28))) {
                bVar12 = false;
              }
              else {
                bVar12 = true;
              }
              if ((*(uint *)((long)&local_180 + lVar27) == (uVar30 & 0xffff)) &&
                 (uVar25 = uVar25 << 4 | 0xc,
                 *(int *)(lVar24 + 0x41 + uVar25) == *(int *)(lVar3 + uVar25))) {
LAB_fffffff008ea8d98:
                if (!bVar12) goto LAB_fffffff008ea8dc8;
              }
            }
          }
          *(undefined1 *)(param_2 + 0x34f) = 0;
          thunk_EXT_FUN_80110000038fe9a0
                    ("%s: Force convert FU -> sync swap. SWID=%d Mismatch code=0x%x\n");
        }
      }
LAB_fffffff008ea8dc8:
      if (plVar18 != (long *)0x0) {
        (**(code **)(*plVar18 + 0x28))();
      }
      bVar13 = *(byte *)(param_2 + 0x352) & (int)local_1a0 == 0;
      if (bVar13 == 1 && local_1a0._4_4_ == 0) {
        *(undefined1 *)(param_2 + 0x352) = 0;
LAB_fffffff008ea8f34:
        thunk_EXT_FUN_8011000002a7c804(plVar20,param_2,param_3,&local_220);
        lVar24 = 0;
        *(undefined4 *)(param_2 + 0x150) = uVar21;
        do {
          if ((*(uint *)(param_2 + 0x14c) >> (ulong)((uint)lVar24 & 0x1f) & 1) != 0) {
            lVar32 = lVar24 * 0x4c;
            if ((lVar24 == 3) || ((*(uint *)((long)&local_158 + lVar32) >> 1 & 1) != 0)) {
              puVar8 = (undefined4 *)(lVar2 + lVar24 * 0x10);
              *puVar8 = *(undefined4 *)((long)&uStack_178 + lVar32);
              puVar8[2] = *(undefined4 *)((long)&uStack_170 + lVar32);
              puVar8 = (undefined4 *)(lVar3 + lVar24 * 0x10);
              *puVar8 = *(undefined4 *)((long)&uStack_168 + lVar32);
              puVar8[2] = *(undefined4 *)((long)&uStack_160 + lVar32);
            }
            *(undefined4 *)(lVar1 + lVar24 * 4) = *(undefined4 *)((long)&local_1a0 + lVar32 + 4);
          }
          lVar24 = lVar24 + 1;
        } while (lVar24 != 4);
        plVar20 = plVar17;
        if ((*(byte *)(param_2 + 0x352) & 1) != 0) {
          local_220 = (undefined1 *)CONCAT44(local_220._4_4_,0xff);
        }
      }
      else {
        if (bVar13 == 0) goto LAB_fffffff008ea8f34;
        if (local_1a0._4_4_ == 0) {
          thunk_EXT_FUN_80110000038fe9a0
                    ("%s: Should not be entering here - async_swap = %d, swapID = %d!!\n");
          goto joined_r0xfffffff008ea8bd8;
        }
        lVar24 = 0;
        do {
          if ((*(uint *)(param_2 + 0x14c) >> (ulong)((uint)lVar24 & 0x1f) & 1) != 0) {
            lVar32 = lVar24 * 0x4c;
            if ((lVar24 == 3) || ((*(uint *)((long)&local_158 + lVar32) >> 1 & 1) != 0)) {
              puVar8 = (undefined4 *)(lVar2 + lVar24 * 0x10);
              *puVar8 = *(undefined4 *)((long)&uStack_178 + lVar32);
              puVar8[2] = *(undefined4 *)((long)&uStack_170 + lVar32);
              puVar8 = (undefined4 *)(lVar3 + lVar24 * 0x10);
              *puVar8 = *(undefined4 *)((long)&uStack_168 + lVar32);
              puVar8[2] = *(undefined4 *)((long)&uStack_160 + lVar32);
            }
            *(undefined4 *)(lVar1 + lVar24 * 4) = *(undefined4 *)((long)&local_1a0 + lVar32 + 4);
          }
          lVar24 = lVar24 + 1;
        } while (lVar24 != 4);
        thunk_EXT_FUN_8011000002a7c804(plVar17,param_2,param_3,&local_220);
        lVar24 = 0;
        *(undefined4 *)(param_2 + 0x150) = uVar21;
        do {
          if ((*(uint *)(param_2 + 0x14c) >> (ulong)((uint)lVar24 & 0x1f) & 1) != 0) {
            lVar32 = lVar24 * 0x4c;
            if ((lVar24 == 3) || ((*(uint *)((long)&local_158 + lVar32) >> 1 & 1) != 0)) {
              puVar8 = (undefined4 *)(lVar2 + lVar24 * 0x10);
              *puVar8 = *(undefined4 *)((long)&uStack_198 + lVar32);
              puVar8[2] = *(undefined4 *)((long)&local_190 + lVar32);
              puVar8 = (undefined4 *)(lVar3 + lVar24 * 0x10);
              *puVar8 = *(undefined4 *)((long)&uStack_188 + lVar32);
              puVar8[2] = *(undefined4 *)((long)&local_180 + lVar32);
            }
            *(undefined4 *)(lVar1 + lVar24 * 4) = *(undefined4 *)((long)&local_1a0 + lVar32);
          }
          lVar24 = lVar24 + 1;
        } while (lVar24 != 4);
        if ((*(byte *)(param_2 + 0x352) & 1) != 0) {
          local_220 = (undefined1 *)CONCAT44(local_220._4_4_,0xff);
        }
      }
      param_4 = &local_220;
    }
    thunk_EXT_FUN_8011000002a7c804(plVar20,param_2,param_3,param_4);
  }
  else {
    thunk_EXT_FUN_80110000038fe9a0
              ("Submitting swap after power down at entry. Returning failure, cancelling swap\n");
    (**(code **)(*param_1 + 0x6e0))(param_1,*(undefined4 *)(param_2 + 0x98));
  }
joined_r0xfffffff008ea8bd8:
  if (lVar33 != 0) {
    thunk_EXT_FUN_80110000038ff2e0(param_1[0xcbc]);
  }
  uVar34 = 0;
LAB_fffffff008ea8ff0:
  if (*(long *)PTR_DAT_fffffff007e748e0 != local_70) {
    uVar34 = thunk_EXT_FUN_8011000003a48590();
    return uVar34;
  }
  return uVar34;
}

