// FUN_fffffff00a298c00 @ fffffff00a298c00 size=9760

/* WARNING: Removing unreachable block (ram,0xfffffff00a29940c) */
/* WARNING: Removing unreachable block (ram,0xfffffff00a29aaa4) */
/* WARNING: Removing unreachable block (ram,0xfffffff00a2994c4) */
/* WARNING: Removing unreachable block (ram,0xfffffff00a29a94c) */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong FUN_fffffff00a298c00
                (undefined4 *param_1,ulong param_2,uint param_3,int param_4,int param_5,
                uint *param_6,ulong *param_7,ulong *param_8,int *param_9,undefined4 *param_10,
                int param_11,int *param_12,undefined8 *param_13)

{
  long *plVar1;
  ulong *puVar2;
  ushort uVar3;
  long *plVar4;
  uint uVar5;
  byte bVar6;
  ushort uVar7;
  long lVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  bool bVar12;
  long lVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  undefined8 uVar17;
  ulong uVar18;
  undefined8 uVar19;
  byte bVar20;
  uint uVar21;
  ulong uVar22;
  uint uVar23;
  uint uVar24;
  ulong uVar25;
  undefined4 *puVar26;
  undefined4 *puVar27;
  ulong uVar28;
  undefined4 in_wzr;
  undefined1 auVar29 [16];
  undefined8 local_128;
  int local_120;
  int local_e0;
  uint local_d4;
  ulong local_b8;
  ulong local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  undefined8 uStack_88;
  undefined8 local_80;
  int local_78;
  int local_74;
  long local_70 [2];
  
  local_128 = 0;
  local_120 = 0;
  bVar11 = false;
  local_b8 = 0;
  iVar16 = *param_12;
  lVar8 = tpidr_el1;
  uVar3 = *(ushort *)(lVar8 + 200) & 3;
  local_e0 = 4;
  *(ushort *)(lVar8 + 200) = *(ushort *)(lVar8 + 200) & 0xfffc | (ushort)iVar16 & 3;
  local_70[0] = 0;
  puVar27 = param_1;
  local_d4 = param_3;
  local_a8 = param_2;
LAB_fffffff00a298cac:
  uVar25 = local_a8 & 0xffffffffffffc000;
  do {
    uVar24 = puVar27[0x1d];
    if ((uVar24 >> 0xf & 1) == 0) {
      FUN_fffffff00a29b220(puVar27,local_b8);
      *(ushort *)(lVar8 + 200) = *(ushort *)(lVar8 + 200) & 0xfffc | uVar3;
      if (lVar8 == 0) {
        uVar17 = 0;
      }
      else {
        uVar17 = *(undefined8 *)(lVar8 + 0x4e0);
      }
      uVar25 = 0x1000040;
      goto LAB_fffffff00a29990c;
    }
    uVar21 = puVar27[0x2a];
    if ((uVar21 >> 6 & 1) == 0) {
      if (param_5 != 1) goto LAB_fffffff00a298e94;
      param_5 = 0;
      uVar28 = *param_7;
    }
    else {
      lVar13 = (ulong)(uint)puVar27[0x1c] + 1;
      puVar27[0x1c] = (int)lVar13;
      if (lVar13 != lVar13 * 0x80000000 >> 0x1f) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa0c4f8("vm_object_activity_begin(%p): overflow\n @%s:%d");
      }
      uVar7 = *(ushort *)(puVar27 + 0x1b);
      uVar23 = uVar7 - 1;
      *(short *)(puVar27 + 0x1b) = (short)uVar23;
      if (0xffff < uVar23) goto LAB_fffffff00a29b050;
      uVar23 = uVar23 & 0xffff;
      if (((uVar24 >> 0xc & 1) == 0) &&
         ((((uint)((uint)uVar7 == (uint)DAT_fffffff007bc0ab0) & uVar21 >> 8) != 0 ||
          (DAT_fffffff007bc0ab2 == uVar7)))) {
        if ((uVar24 >> 6 & 1) != 0) {
          plVar1 = (long *)(_DAT_fffffff00acce458 + (ulong)*(ushort *)(lVar8 + 0x1b0) * 0x4000);
          lVar13 = *plVar1;
          *plVar1 = lVar13 + 1;
          FUN_fffffff00a20dce4(lVar13,(long)puVar27 + 6,0,0);
          uVar24 = puVar27[0x1d];
          uVar23 = (uint)*(ushort *)(puVar27 + 0x1b);
        }
        uVar24 = uVar24 & 0xffffffbf;
        puVar27[0x1d] = uVar24;
      }
      if (uVar23 == 0) {
        if ((uVar24 >> 5 & 1) != 0) {
          FUN_fffffff00a20dce4((long)puVar27 + 5,0,0);
          uVar24 = puVar27[0x1d];
        }
        uVar23 = uVar24 & 0xffffffdf;
        puVar27[0x1d] = uVar23;
        if (puVar27[0x1c] == 0) {
          if ((uVar24 >> 2 & 1) != 0) {
            FUN_fffffff00a20dce4((long)puVar27 + 2,0,0);
            uVar23 = puVar27[0x1d];
          }
          puVar27[0x1d] = uVar23 & 0xfffffffb;
        }
      }
      if ((param_13 != (undefined8 *)0x0) && ((*(byte *)(param_13 + 5) >> 5 & 1) != 0)) {
        FUN_fffffff00a296ffc(param_13[2],&DAT_fffffff00acd8850,6,*param_13,param_13[1]);
      }
      while ((*(byte *)(puVar27 + 0x2a) >> 6 & 1) != 0) {
        *(undefined1 *)(lVar8 + 0x55d) = 0x1b;
        puVar27[0x1d] = puVar27[0x1d] | 0x10;
        auVar29 = FUN_fffffff00a2396e4(lVar8);
        FUN_fffffff00a2c82d4(puVar27 + 2,4,puVar27 + 1,0);
        FUN_fffffff00a239798(lVar8,auVar29._0_8_,auVar29._8_8_);
      }
      DAT_fffffff00ad05f90 = DAT_fffffff00ad05f90 + 1;
      uVar7 = *(ushort *)(puVar27 + 0x1b);
      *(short *)(puVar27 + 0x1b) = (short)(uVar7 + 1);
      if (uVar7 + 1 >> 0x10 != 0) goto LAB_fffffff00a29b044;
      iVar15 = puVar27[0x1c];
      puVar27[0x1c] = iVar15 + -1;
      if (iVar15 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa0c4f8("vm_object_activity_end(%p): underflow\n @%s:%d");
      }
      param_5 = 0;
LAB_fffffff00a298e94:
      uVar28 = FUN_fffffff00a2ef170(puVar27,uVar25);
    }
    if (uVar28 == 0) {
      uVar24 = uVar21 >> 1 & 0x10000;
      if (param_4 == 0) {
        uVar21 = puVar27[0x1d];
        if ((uVar21 >> 7 & 1) != 0) {
          if ((((uVar21 >> 0xc & 1) != 0) && ((uVar21 >> 0xf & 1) != 0)) &&
             (*(long *)(puVar27 + 0x14) != 0)) {
            iVar15 = FUN_fffffff00a28980c
                               (*(long *)(puVar27 + 0x14),*(long *)(puVar27 + 0x18) + local_a8);
            bVar10 = iVar15 != 3;
            goto LAB_fffffff00a299148;
          }
          bVar12 = puVar27 == param_1;
          if ((uVar21 >> 9 & 1) == 0) goto LAB_fffffff00a29a954;
LAB_fffffff00a299428:
          local_74 = 0;
          if (((uVar21 & 0x801000) == 0) &&
             (uVar7 = *(ushort *)(puVar27 + 0x1b), DAT_fffffff007bc0ab2 <= uVar7)) {
            uVar5 = *(uint *)(lVar8 + 0x214);
            uVar23 = *(uint *)(lVar8 + 0x4f8) >> 1 & 3;
            uVar21 = uVar23;
            if ((int)uVar5 <= (int)uVar23) {
              uVar21 = uVar5;
            }
            if (uVar5 != 0xffffffff) {
              uVar23 = uVar21;
            }
            lVar13 = (ulong)*(ushort *)(lVar8 + 0x1b0) * 0x4000;
            if ((((uint)puVar27[0x2a] >> 8 & 1) == 0) || (uVar23 != 0)) {
              plVar1 = (long *)&DAT_fffffff00acce410;
              if (uVar23 != 0) {
                plVar1 = (long *)&DAT_fffffff00acce418;
              }
              plVar4 = (long *)&DAT_fffffff00acce408;
              if ((puVar27[0x2a] & 0x100) == 0) {
                plVar4 = plVar1;
              }
              plVar1 = (long *)(lVar13 + *plVar4);
              *plVar1 = *plVar1 + 1;
            }
            else {
              bVar10 = DAT_fffffff007bc0ab0 <= uVar7;
              plVar1 = (long *)&DAT_fffffff00acce400;
              if (bVar10) {
                plVar1 = (long *)&DAT_fffffff00acce3f8;
              }
              plVar1 = (long *)(lVar13 + *plVar1);
              *plVar1 = *plVar1 + 1;
              if (!bVar10) {
                uVar21 = puVar27[0x1d];
                goto LAB_fffffff00a2994b4;
              }
            }
            local_74 = 0;
            if (puVar27[10] + 0xf0000001 < 0xf0000002) goto LAB_fffffff00a29b0d0;
            puVar27[10] = puVar27[10] + 1;
            FUN_fffffff00a29b220(puVar27,local_b8);
            FUN_fffffff00a2c987c(puVar27);
            if ((puVar27[0x1d] & 0x801000) == 0) {
              uVar21 = *(uint *)(lVar8 + 0x4f8) >> 1 & 3;
              uVar23 = *(uint *)(lVar8 + 0x214);
              uVar24 = uVar21;
              if ((int)uVar23 <= (int)uVar21) {
                uVar24 = uVar23;
              }
              if (uVar23 != 0xffffffff) {
                uVar21 = uVar24;
              }
              uVar7 = *(ushort *)(puVar27 + 0x1b);
              if (DAT_fffffff007bc0ab2 <= uVar7) {
                lVar13 = (ulong)*(ushort *)(lVar8 + 0x1b0) * 0x4000;
                if ((((uint)puVar27[0x2a] >> 8 & 1) == 0) || (uVar21 != 0)) {
                  plVar1 = (long *)&DAT_fffffff00acce410;
                  if (uVar21 != 0) {
                    plVar1 = (long *)&DAT_fffffff00acce418;
                  }
                  plVar4 = (long *)&DAT_fffffff00acce408;
                  if ((puVar27[0x2a] & 0x100) == 0) {
                    plVar4 = plVar1;
                  }
                  plVar1 = (long *)(lVar13 + *plVar4);
                  lVar13 = *plVar1;
                  *plVar1 = lVar13 + 1;
                }
                else {
                  bVar11 = uVar7 < DAT_fffffff007bc0ab0;
                  plVar1 = (long *)&DAT_fffffff00acce400;
                  if (!bVar11) {
                    plVar1 = (long *)&DAT_fffffff00acce3f8;
                  }
                  plVar1 = (long *)(lVar13 + *plVar1);
                  lVar13 = *plVar1;
                  *plVar1 = lVar13 + 1;
                  if (bVar11) goto LAB_fffffff00a29ab28;
                }
                iVar16 = FUN_fffffff00a2d3ae0(lVar13,puVar27,iVar16);
                FUN_fffffff00a1eec04(puVar27 + 2);
                goto LAB_fffffff00a299efc;
              }
            }
LAB_fffffff00a29ab28:
            FUN_fffffff00a1eec04(puVar27 + 2);
            goto LAB_fffffff00a29afb0;
          }
LAB_fffffff00a2994b4:
          if ((uVar21 >> 0xc & 1) == 0) {
            local_74 = 2;
            lVar13 = *(long *)(puVar27 + 0x14);
            if (lVar13 == 0) {
              FUN_fffffff00a29b220(puVar27,local_b8);
              *(ushort *)(lVar8 + 200) = *(ushort *)(lVar8 + 200) & 0xfffc | uVar3;
              if (lVar8 == 0) {
                uVar17 = 0;
              }
              else {
                uVar17 = *(undefined8 *)(lVar8 + 0x4e0);
              }
              uVar25 = ((ulong)*(uint *)(&DAT_fffffff007011470 +
                                        ((ulong)((uint)puVar27[0x1d] >> 0x19) & 7) * 4) & 0x3fff) <<
                       2 | 0x1000000;
              goto LAB_fffffff00a29990c;
            }
            if (((*(byte *)((long)puVar27 + 0xa9) & 1) == 0) &&
               (*(undefined **)(lVar13 + 8) != &DAT_fffffff007bbf438)) {
              bVar9 = false;
            }
            else {
              *(short *)(lVar8 + 0x20e) = *(short *)(lVar8 + 0x20e) + 1;
              bVar9 = true;
              local_70[0] = lVar8;
            }
            FUN_fffffff00a1eec04(puVar27 + 2);
            if (puVar27[0x1a] != 1) {
              bVar12 = true;
            }
            uVar24 = 0;
            if (!bVar12) {
              uVar24 = 0x10;
            }
            bVar10 = *(undefined4 **)(puVar27 + 0xe) == param_1;
            if (bVar10) {
              FUN_fffffff00a2c987c(param_1);
              FUN_fffffff00a2ed2a8(local_b8);
              FUN_fffffff00a29bd58(param_1);
              FUN_fffffff00a1eec04(param_1 + 2);
              local_b8 = 0;
              DAT_fffffff00ad05f94 = DAT_fffffff00ad05f94 + 1;
            }
            if (bVar11) {
              local_120 = param_12[4];
              local_128 = *(undefined8 *)(param_12 + 2);
              param_12[4] = 1;
              param_12[2] = 0x4000;
              param_12[3] = 0;
            }
            iVar15 = (**(code **)(*(long *)(lVar13 + 8) + 0x20))
                               (lVar13,*(long *)(puVar27 + 0x18) + uVar25,0x4000,uVar24 | local_d4,
                                param_12);
            if (bVar11) {
              param_12[4] = local_120;
              *(undefined8 *)(param_12 + 2) = local_128;
            }
            FUN_fffffff00a2c987c(puVar27);
            if (bVar9) {
              FUN_fffffff00a2381c0(local_70);
            }
            if (iVar15 != 0) {
              FUN_fffffff00a29b220(puVar27,local_b8);
              *(ushort *)(lVar8 + 200) = *(ushort *)(lVar8 + 200) & 0xfffc | uVar3;
              if (lVar8 == 0) {
                uVar17 = 0;
              }
              else {
                uVar17 = *(undefined8 *)(lVar8 + 0x4e0);
              }
              FUN_fffffff00a69c288(uVar17,0x1000004,0);
              uVar24 = 7;
              if (iVar15 != 0x1e) {
                uVar24 = 5;
              }
              uVar21 = 2;
              if (iVar15 != 0x10000007) {
                uVar21 = uVar24;
              }
              return (ulong)uVar21;
            }
            bVar11 = true;
          }
          else {
            local_78 = 0;
            uVar28 = FUN_fffffff00a2f01d8(uVar24);
            if (uVar28 == 0) goto LAB_fffffff00a299eb4;
            uVar24 = param_12[10];
            *(byte *)(uVar28 + 0x2c) = *(byte *)(uVar28 + 0x2c) | 8;
            uVar17 = FUN_fffffff00a2ecbf4(uVar28,puVar27,uVar25,0,uVar24 >> 4 & 4,0);
            *(byte *)(uVar28 + 0x2c) = *(byte *)(uVar28 + 0x2c) | 8;
            lVar13 = *(long *)(puVar27 + 0x14);
            local_80 = 0;
            uStack_98 = 0;
            local_a0 = 0;
            uStack_88 = 0;
            uStack_90 = 0;
            FUN_fffffff00a2c76a0(uVar17,uVar28,&local_a0);
            FUN_fffffff00a1eec04(puVar27 + 2);
            if ((uVar28 < DAT_fffffff007be4010) || (DAT_fffffff007be4008 <= uVar28)) {
              iVar15 = *(int *)(uVar28 + 0x3c);
            }
            else {
              iVar15 = DAT_fffffff007be4000 + (int)(uVar28 - DAT_fffffff007be4010 >> 6);
            }
            iVar15 = FUN_fffffff00a2894ec
                               (lVar13,*(long *)(puVar27 + 0x18) + local_a8,iVar15,&local_74,0,
                                &local_78);
            if (((param_9 == (int *)0x0) && (local_74 == 9)) &&
               (iVar14 = FUN_fffffff00a29b740(1), iVar14 != 0)) {
              FUN_fffffff00a29b9f0();
            }
            uVar17 = FUN_fffffff00a2c987c(puVar27);
            if (((lVar13 != 0) && (local_78 != 0)) &&
               (*(undefined **)(lVar13 + 8) == &DAT_fffffff007bbe018)) {
              *(int *)(lVar13 + 0x34) = *(int *)(lVar13 + 0x34) + local_78;
            }
            if (iVar15 != 10) {
              if (iVar15 == 9) {
                *(byte *)(uVar28 + 0x2c) = *(byte *)(uVar28 + 0x2c) & 0xf4 | 1;
              }
              else {
                if (iVar15 != 0) {
                    /* WARNING: Subroutine does not return */
                  FUN_fffffff00aa0c4f8
                            (
                            "vm_fault_page(): unexpected error %d from vm_compressor_pager_get()\n @%s:%d"
                            );
                }
                *(byte *)(uVar28 + 0x2c) = *(byte *)(uVar28 + 0x2c) & 0xf7;
                *(byte *)(uVar28 + 0x2d) = *(byte *)(uVar28 + 0x2d) | 1;
                if ((*(char *)((long)puVar27 + 0xa6) == '\x02') ||
                   (*(char *)((long)puVar27 + 0xa6) == -0x80)) {
                  *(ushort *)(uVar28 + 0x2e) = *(ushort *)(uVar28 + 0x2e) | 0x8000;
                }
                else {
                  DataSynchronizationBarrier(3,3,0);
                }
                if ((((((puVar27[0x1d] ^ 0xffffffff) & 0x30000) != 0) ||
                     ((*(byte *)((long)puVar27 + 0xaa) & 0x38) != 0)) &&
                    (*(long *)(puVar27 + 0x16) != 0)) && (local_78 != 0)) {
                  uVar17 = FUN_fffffff00a2e62f8(puVar27,0xffffffff);
                }
              }
            }
            FUN_fffffff00a2d3c38(uVar17,uVar28,&local_a0);
            bVar10 = false;
          }
          local_e0 = local_74;
          if (local_74 == 2) {
            FUN_fffffff00a35eec4(&local_a0,&local_78);
            *(undefined8 *)(lVar8 + 0x468) = local_a0;
            *(undefined4 *)(lVar8 + 0x470) = 0;
          }
          if ((iVar16 != 0) && ((*(byte *)(lVar8 + 0x200) >> 4 & 1) != 0)) {
            FUN_fffffff00a29b220(puVar27,local_b8);
            *(ushort *)(lVar8 + 200) = *(ushort *)(lVar8 + 200) & 0xfffc | uVar3;
            goto joined_r0xfffffff00a29a8d4;
          }
          if (bVar10) {
            FUN_fffffff00a29b220(puVar27,local_b8);
            goto LAB_fffffff00a29afb4;
          }
          if (((uVar21 >> 0xc & 1) != 0) || (-1 < *(char *)((long)puVar27 + 0x76)))
          goto LAB_fffffff00a298cac;
          *param_7 = 0;
          *param_8 = local_b8;
          goto LAB_fffffff00a29aea8;
        }
        bVar10 = false;
LAB_fffffff00a299148:
        bVar12 = puVar27 == param_1;
        if ((bVar12) && (!bVar10)) {
          if (-1 < *(char *)((long)puVar27 + 0x76)) {
            uVar28 = FUN_fffffff00a2f01d8(uVar24);
            if (uVar28 != 0) {
              FUN_fffffff00a2ecbf4(uVar28,puVar27,uVar25,0,(uint)param_12[10] >> 4 & 4,0);
              goto LAB_fffffff00a29926c;
            }
            goto LAB_fffffff00a299eb4;
          }
          bVar12 = true;
        }
        uVar28 = 0;
        if (bVar10) {
          uVar21 = puVar27[0x1d];
          if ((uVar21 >> 9 & 1) != 0) goto LAB_fffffff00a299428;
LAB_fffffff00a29a954:
          local_74 = 0;
          if (puVar27[10] + 0xf0000001 < 0xf0000002) goto LAB_fffffff00a29b0d0;
          puVar27[10] = puVar27[10] + 1;
          FUN_fffffff00a29b220(puVar27,local_b8);
          FUN_fffffff00a2c987c(puVar27);
          if ((*(byte *)((long)puVar27 + 0x75) >> 1 & 1) != 0) goto LAB_fffffff00a29ab28;
          if ((param_13 != (undefined8 *)0x0) && ((*(byte *)(param_13 + 5) >> 5 & 1) != 0)) {
            FUN_fffffff00a296ffc(param_13[2],&DAT_fffffff00acd8858,7,*param_13,param_13[1]);
          }
          iVar16 = FUN_fffffff00a2ca664(puVar27,1,iVar16,1);
          goto LAB_fffffff00a299efc;
        }
      }
      else {
        uVar28 = 0;
        if ((param_3 == 0) && (puVar27 == &DAT_fffffff00ad7b300)) {
          FUN_fffffff00a29b220(&DAT_fffffff00ad7b300,local_b8);
          *(ushort *)(lVar8 + 200) = *(ushort *)(lVar8 + 200) & 0xfffc | uVar3;
          return 5;
        }
      }
LAB_fffffff00a29926c:
      if (puVar27 != param_1) {
        uVar28 = local_b8;
      }
      puVar26 = *(undefined4 **)(puVar27 + 0x12);
      if (puVar26 != (undefined4 *)0x0) {
        if ((param_4 != 0) || (puVar27 != param_1)) {
          uVar7 = *(ushort *)(puVar27 + 0x1b);
          uVar24 = uVar7 - 1;
          *(short *)(puVar27 + 0x1b) = (short)uVar24;
          if (0xffff < uVar24) goto LAB_fffffff00a29b050;
          uVar24 = uVar24 & 0xffff;
          uVar21 = puVar27[0x1d];
          if (((uVar21 >> 0xc & 1) == 0) &&
             (((*(byte *)((long)puVar27 + 0xa9) & (uint)uVar7 == (uint)DAT_fffffff007bc0ab0) != 0 ||
              (DAT_fffffff007bc0ab2 == uVar7)))) {
            if ((uVar21 >> 6 & 1) != 0) {
              plVar1 = (long *)(_DAT_fffffff00acce458 + (ulong)*(ushort *)(lVar8 + 0x1b0) * 0x4000);
              lVar13 = *plVar1;
              *plVar1 = lVar13 + 1;
              FUN_fffffff00a20dce4(lVar13,(long)puVar27 + 6,0,0);
              uVar21 = puVar27[0x1d];
              uVar24 = (uint)*(ushort *)(puVar27 + 0x1b);
            }
            uVar21 = uVar21 & 0xffffffbf;
            puVar27[0x1d] = uVar21;
          }
          if (uVar24 == 0) {
            if ((uVar21 >> 5 & 1) != 0) {
              FUN_fffffff00a20dce4((long)puVar27 + 5,0,0);
              uVar21 = puVar27[0x1d];
            }
            uVar24 = uVar21 & 0xffffffdf;
            puVar27[0x1d] = uVar24;
            if (puVar27[0x1c] == 0) {
              if ((uVar21 >> 2 & 1) != 0) {
                FUN_fffffff00a20dce4((long)puVar27 + 2,0,0);
                uVar24 = puVar27[0x1d];
              }
              puVar27[0x1d] = uVar24 & 0xfffffffb;
            }
          }
        }
        lVar13 = *(long *)(puVar27 + 0x16);
        *(long *)(param_12 + 6) = *(long *)(param_12 + 6) + lVar13;
        *(long *)(param_12 + 8) = *(long *)(param_12 + 8) + *(long *)(puVar27 + 0x16);
        FUN_fffffff00a2c987c(puVar26);
        FUN_fffffff00a1eec04(puVar27 + 2);
        uVar24 = *(ushort *)(puVar26 + 0x1b) + 1;
        *(short *)(puVar26 + 0x1b) = (short)uVar24;
        local_b8 = uVar28;
        goto joined_r0xfffffff00a2993bc;
      }
      if (puVar27 != param_1) {
        uVar7 = *(ushort *)(puVar27 + 0x1b);
        uVar21 = uVar7 - 1;
        *(short *)(puVar27 + 0x1b) = (short)uVar21;
        if (0xffff < uVar21) goto LAB_fffffff00a29b050;
        uVar21 = uVar21 & 0xffff;
        if (((*(byte *)((long)puVar27 + 0x75) >> 4 & 1) == 0) &&
           (((*(byte *)((long)puVar27 + 0xa9) & (uint)uVar7 == (uint)DAT_fffffff007bc0ab0) != 0 ||
            (DAT_fffffff007bc0ab2 == uVar7)))) {
          FUN_fffffff00a2cfbfc(puVar27,6);
          uVar21 = (uint)*(ushort *)(puVar27 + 0x1b);
        }
        if ((uVar21 == 0) && (FUN_fffffff00a2cfbfc(puVar27,5), puVar27[0x1c] == 0)) {
          FUN_fffffff00a2cfbfc(puVar27,2);
        }
        FUN_fffffff00a1eec04(puVar27 + 2);
        FUN_fffffff00a2c987c(param_1);
        puVar27 = param_1;
        local_a8 = param_2;
      }
      uVar25 = FUN_fffffff00a29bc0c(puVar27,uVar28,0,uVar3,param_9 == (int *)0x0);
      if ((int)uVar25 != 0) {
        return uVar25;
      }
      if (uVar28 == 0) {
        uVar21 = 0x10;
        if (param_11 != 0) {
          uVar21 = 0;
        }
        uVar28 = FUN_fffffff00a2f01d8(uVar24 | uVar21);
        if (uVar28 == 0) {
          local_b8 = 0;
          goto LAB_fffffff00a29aa4c;
        }
        FUN_fffffff00a2ecbf4(uVar28,puVar27,local_a8 & 0xffffffffffffc000,0,0,0);
LAB_fffffff00a299d8c:
        bVar6 = 0;
        if (param_11 == 1) {
          bVar6 = *(byte *)(param_12 + 10) >> 5 & 1;
        }
        if (bVar6 == 1) {
          bVar20 = *(byte *)(uVar28 + 0x2c) | 8;
          *(byte *)(uVar28 + 0x2c) = bVar20;
          *(ushort *)(uVar28 + 0x2e) = *(ushort *)(uVar28 + 0x2e) & 0xf000;
          *(byte *)(uVar28 + 0x2d) = *(byte *)(uVar28 + 0x2d) | 0x10;
        }
        else {
          *(ushort *)(uVar28 + 0x2e) = *(ushort *)(uVar28 + 0x2e) & 0xf000;
          *(byte *)(uVar28 + 0x2d) = *(byte *)(uVar28 + 0x2d) | 0x10;
          if (param_11 == 0) {
            bVar6 = 0;
            goto LAB_fffffff00a299f70;
          }
          bVar20 = *(byte *)(uVar28 + 0x2c);
        }
        if (((bVar20 ^ 0xff) & 0xc) != 0) goto LAB_fffffff00a299f70;
      }
      else {
        if (param_11 != 0) goto LAB_fffffff00a299d8c;
        FUN_fffffff00a2f0f44(uVar28);
        bVar6 = 0;
        *(ushort *)(uVar28 + 0x2e) = *(ushort *)(uVar28 + 0x2e) & 0xf000;
        *(byte *)(uVar28 + 0x2d) = *(byte *)(uVar28 + 0x2d) | 0x10;
LAB_fffffff00a299f70:
        FUN_fffffff00a298680(puVar27,uVar28);
      }
      local_e0 = 5;
      if (param_11 == 0) {
        local_e0 = 1;
      }
      local_b8 = 0;
      goto LAB_fffffff00a299f94;
    }
    if ((*(byte *)(uVar28 + 0x2c) >> 2 & 1) == 0) break;
    if ((*(byte *)((long)param_12 + 0x29) >> 4 & 1) != 0) {
      FUN_fffffff00a29b220(puVar27,local_b8);
      *(ushort *)(lVar8 + 200) = *(ushort *)(lVar8 + 200) & 0xfffc | uVar3;
      return 7;
    }
    if ((param_13 != (undefined8 *)0x0) && ((*(byte *)(param_13 + 5) >> 5 & 1) != 0)) {
      FUN_fffffff00a296ffc(param_13[2],&DAT_fffffff00acd8838,3,*param_13,param_13[1]);
    }
    iVar15 = FUN_fffffff00a2c9108(puVar27,uVar28,iVar16,0);
    if (iVar15 != 0) {
      FUN_fffffff00a29b220(puVar27,local_b8);
      *(ushort *)(lVar8 + 200) = *(ushort *)(lVar8 + 200) & 0xfffc | uVar3;
      if (iVar15 == 3) {
        return 1;
      }
      if (lVar8 == 0) {
        uVar17 = 0;
      }
      else {
        uVar17 = *(undefined8 *)(lVar8 + 0x4e0);
      }
      uVar19 = 0x1000034;
      goto LAB_fffffff00a29992c;
    }
  } while( true );
  if (((*(byte *)(uVar28 + 0x2b) >> 1 & 1) != 0) &&
     (*(byte *)(uVar28 + 0x2d) = *(byte *)(uVar28 + 0x2d) & 0xfb,
     (*(byte *)(uVar28 + 0x2c) >> 5 & 1) == 0)) {
    FUN_fffffff00a2de438(uVar28,0);
  }
  if (((uVar28 < DAT_fffffff007be4010) || (DAT_fffffff007be4008 <= uVar28)) &&
     (*(int *)(uVar28 + 0x3c) == -2)) {
    if (param_3 == 0) {
      *(byte *)(uVar28 + 0x2c) = *(byte *)(uVar28 + 0x2c) | 4;
      *param_7 = uVar28;
      *param_8 = local_b8;
      if (param_9 != (int *)0x0) {
        *param_9 = 6;
      }
      *(ushort *)(lVar8 + 200) = *(ushort *)(lVar8 + 200) & 0xfffc | uVar3;
      return 0;
    }
    FUN_fffffff00a29b220(puVar27,local_b8);
    *(ushort *)(lVar8 + 200) = *(ushort *)(lVar8 + 200) & 0xfffc | uVar3;
    if (lVar8 == 0) {
      uVar17 = 0;
    }
    else {
      uVar17 = *(undefined8 *)(lVar8 + 0x4e0);
    }
    uVar25 = 0x100002c;
    goto LAB_fffffff00a29990c;
  }
  bVar20 = *(byte *)(uVar28 + 0x2c);
  if ((bVar20 & 3) != 0) {
    if ((bVar20 & 3) == 3) {
      uVar25 = 0;
    }
    else {
      if ((bVar20 & 3) == 2) {
        uVar17 = 0x1000060;
        uVar25 = 1;
      }
      else {
        uVar17 = 0x100005c;
        if (param_10 != (undefined4 *)0x0) {
          *param_10 = 10;
        }
        uVar25 = 5;
      }
      if (lVar8 == 0) {
        uVar19 = 0;
      }
      else {
        uVar19 = *(undefined8 *)(lVar8 + 0x4e0);
      }
      FUN_fffffff00a69c288(uVar19,uVar17,0);
    }
    FUN_fffffff00a2ed2a8(uVar28);
    FUN_fffffff00a29b220(puVar27,local_b8);
    *(ushort *)(lVar8 + 200) = *(ushort *)(lVar8 + 200) & 0xfffc | uVar3;
    return uVar25;
  }
  if ((bVar20 >> 3 & 1) == 0) {
    if ((bVar20 >> 5 & 1) != 0) {
      if (puVar27 == param_1) {
        if (((param_3 >> 1 & 1) != 0) && (*(long *)(puVar27 + 0xe) != 0)) goto LAB_fffffff00a299c58;
      }
      else if ((param_3 >> 1 & 1) != 0) {
LAB_fffffff00a299c58:
        if (puVar27[10] + 0xf0000001 < 0xf0000002) {
LAB_fffffff00a29b0d0:
                    /* WARNING: Subroutine does not return */
          FUN_fffffff00aa21104(puVar27 + 10);
        }
        puVar27[10] = puVar27[10] + 1;
        FUN_fffffff00a29b220(puVar27,local_b8);
        FUN_fffffff00a2c987c(puVar27);
        lVar13 = FUN_fffffff00a2ef170(puVar27,uVar25);
        if ((lVar13 == 0) || ((*(byte *)(lVar13 + 0x2c) >> 5 & 1) == 0)) {
          FUN_fffffff00a1eec04(puVar27 + 2);
          FUN_fffffff00a2c7010(puVar27);
          uVar7 = *(ushort *)(lVar8 + 200);
          goto LAB_fffffff00a29afc4;
        }
        FUN_fffffff00a29be80(param_13,&DAT_fffffff00acd8840,4);
        iVar16 = FUN_fffffff00a2c9108(puVar27,lVar13,iVar16,1);
LAB_fffffff00a299efc:
        FUN_fffffff00a2c7010(puVar27);
        goto LAB_fffffff00a299f04;
      }
    }
    uVar24 = uVar21 >> 1 & 0x10000;
    if (((param_9 == (int *)0x0) && ((*(byte *)(uVar28 + 0x2a) & 0xf) == 8)) &&
       ((*(byte *)(param_12 + 10) >> 1 & 1) == 0)) {
      FUN_fffffff00a1ea97c(&DAT_fffffff00ad2d0c0);
      if ((*(byte *)(uVar28 + 0x2a) & 0xf) == 8) {
        FUN_fffffff00a2ed744(uVar28,0);
      }
      if ((int)DAT_fffffff00ad2d0c8 == *(int *)(lVar8 + 0x4e8)) {
        DAT_fffffff00ad2d0c8 = CONCAT44(DAT_fffffff00ad2d0c8._4_4_,in_wzr);
      }
      else {
        FUN_fffffff00a1eab60(&DAT_fffffff00ad2d0c0,lVar8);
      }
      bVar20 = *(byte *)(uVar28 + 0x2c);
    }
    bVar6 = 0;
    *(byte *)(uVar28 + 0x2c) = bVar20 | 4;
LAB_fffffff00a299f94:
    puVar26 = puVar27;
    if (puVar27 == param_1) goto LAB_fffffff00a29a468;
    if ((param_3 >> 1 & 1) == 0) {
      *param_6 = *param_6 & 0xfffffffd;
      goto LAB_fffffff00a29a468;
    }
    uVar25 = FUN_fffffff00a2f01d8();
    if (uVar25 == 0) {
      FUN_fffffff00a2cdfcc(0,uVar28);
      if ((1L << (*(byte *)(uVar28 + 0x2a) & 0xf) & 0x3d60U) == 0) {
        FUN_fffffff00a1ea97c(&DAT_fffffff00ad2d0c0);
        if ((bVar6 != 0) && ((*(byte *)(uVar28 + 0x2c) >> 3 & 1) != 0)) {
          FUN_fffffff00a2f0f44(uVar28);
          *(byte *)(uVar28 + 0x2c) = *(byte *)(uVar28 + 0x2c) & 0xf7;
        }
        if ((1L << (*(byte *)(uVar28 + 0x2a) & 0xf) & 0x3d60U) == 0) {
          if (DAT_fffffff00ad55024 == 1) {
            FUN_fffffff00a2ed584(uVar28,1);
          }
          else {
            FUN_fffffff00a2ef580(uVar28);
          }
        }
        if ((int)DAT_fffffff00ad2d0c8 == *(int *)(lVar8 + 0x4e8)) {
          DAT_fffffff00ad2d0c8 = CONCAT44(DAT_fffffff00ad2d0c8._4_4_,in_wzr);
        }
        else {
          FUN_fffffff00a1eab60(&DAT_fffffff00ad2d0c0,lVar8);
        }
      }
LAB_fffffff00a29aa4c:
      FUN_fffffff00a29b220(puVar27,local_b8);
      uVar7 = *(ushort *)(lVar8 + 200);
      goto LAB_fffffff00a29aa5c;
    }
    uVar17 = FUN_fffffff00a2f2558(uVar28,uVar25);
    bVar20 = *(byte *)(uVar28 + 0x2d);
    if ((bVar20 >> 4 & 1) != 0) {
      if ((uVar28 < DAT_fffffff007be4010) || (DAT_fffffff007be4008 <= uVar28)) {
        iVar15 = *(int *)(uVar28 + 0x3c);
      }
      else {
        iVar15 = DAT_fffffff007be4000 + (int)(uVar28 - DAT_fffffff007be4010 >> 6);
      }
      uVar17 = FUN_fffffff00a33f500(iVar15);
      bVar20 = *(byte *)(uVar28 + 0x2d);
    }
    if ((bVar20 >> 3 & 1) != 0) {
      lVar13 = FUN_fffffff00a25f6f4(lVar8);
      plVar1 = (long *)(*(long *)(lVar13 + 0x388) + (ulong)*(ushort *)(lVar8 + 0x1b0) * 0x4000);
      *plVar1 = *plVar1 + 1;
      if ((uVar28 < DAT_fffffff007be4010) || (DAT_fffffff007be4008 <= uVar28)) {
        iVar15 = *(int *)(uVar28 + 0x3c);
      }
      else {
        iVar15 = DAT_fffffff007be4000 + (int)(uVar28 - DAT_fffffff007be4010 >> 6);
      }
      FUN_fffffff00a33f5d0(iVar15);
      uVar18 = (ulong)*(byte *)(uVar28 + 0x2d);
      if ((*(byte *)(uVar28 + 0x2d) >> 3 & 1) != 0) {
        lVar13 = 0;
        if (*(uint *)(uVar28 + 0x1c) != 0) {
          lVar13 = (ulong)*(uint *)(uVar28 + 0x1c) * 0x40 + -0x2400000000;
        }
        *(int *)(lVar13 + 0xa0) = *(int *)(lVar13 + 0xa0) + 1;
        *(byte *)(uVar28 + 0x2d) = *(byte *)(uVar28 + 0x2d) & 0xf7;
        puVar2 = (ulong *)(_DAT_fffffff00acd88c0 + (ulong)*(ushort *)(lVar8 + 0x1b0) * 0x4000);
        uVar18 = *puVar2;
        *puVar2 = uVar18 + 1;
      }
      uVar17 = FUN_fffffff00a33f77c(uVar18,iVar15);
    }
    FUN_fffffff00a2cdfcc(uVar17,uVar28);
    if ((1L << (*(byte *)(uVar28 + 0x2a) & 0xf) & 0x3d60U) == 0) {
      FUN_fffffff00a1ea97c(&DAT_fffffff00ad2d0c0);
      if ((bVar6 != 0) && ((*(byte *)(uVar28 + 0x2c) >> 3 & 1) != 0)) {
        FUN_fffffff00a2f0f44(uVar28);
        *(byte *)(uVar28 + 0x2c) = *(byte *)(uVar28 + 0x2c) & 0xf7;
      }
      if ((1L << (*(byte *)(uVar28 + 0x2a) & 0xf) & 0x3d60U) == 0) {
        if (DAT_fffffff00ad55024 == 1) {
          FUN_fffffff00a2ed584(uVar28,1);
        }
        else {
          FUN_fffffff00a2ef580(uVar28);
        }
      }
      if ((int)DAT_fffffff00ad2d0c8 == *(int *)(lVar8 + 0x4e8)) {
        DAT_fffffff00ad2d0c8 = CONCAT44(DAT_fffffff00ad2d0c8._4_4_,in_wzr);
        goto LAB_fffffff00a29a248;
      }
      FUN_fffffff00a1eab60(&DAT_fffffff00ad2d0c0,lVar8);
      bVar6 = *(byte *)((long)puVar27 + 0x75);
    }
    else {
LAB_fffffff00a29a248:
      bVar6 = *(byte *)((long)puVar27 + 0x75);
    }
    if ((bVar6 >> 4 & 1) == 0) {
      FUN_fffffff00a297548(puVar27,local_a8,param_12[4]);
    }
    uVar7 = *(ushort *)(puVar27 + 0x1b);
    uVar21 = uVar7 - 1;
    *(short *)(puVar27 + 0x1b) = (short)uVar21;
    if (0xffff < uVar21) {
LAB_fffffff00a29b050:
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa0c4f8("vm_object_paging_end(%p): underflow\n @%s:%d");
    }
    uVar21 = uVar21 & 0xffff;
    if (((*(byte *)((long)puVar27 + 0x75) >> 4 & 1) == 0) &&
       (((*(byte *)((long)puVar27 + 0xa9) & (uint)uVar7 == (uint)DAT_fffffff007bc0ab0) != 0 ||
        (DAT_fffffff007bc0ab2 == uVar7)))) {
      FUN_fffffff00a2cfbfc(puVar27,6);
      uVar21 = (uint)*(ushort *)(puVar27 + 0x1b);
    }
    if ((uVar21 == 0) && (FUN_fffffff00a2cfbfc(puVar27,5), puVar27[0x1c] == 0)) {
      FUN_fffffff00a2cfbfc(puVar27,2);
    }
    FUN_fffffff00a1eec04(puVar27 + 2);
    plVar1 = (long *)(_DAT_fffffff00acce4a0 + (ulong)*(ushort *)(lVar8 + 0x1b0) * 0x4000);
    lVar13 = *plVar1;
    *plVar1 = lVar13 + 1;
    lVar13 = FUN_fffffff00a25f6f4(lVar13,lVar8);
    plVar1 = (long *)(*(long *)(lVar13 + 0x390) + (ulong)*(ushort *)(lVar8 + 0x1b0) * 0x4000);
    lVar13 = *plVar1;
    *plVar1 = lVar13 + 1;
    FUN_fffffff00a2c987c(lVar13,param_1);
    FUN_fffffff00a2ed2a8(local_b8);
    FUN_fffffff00a2ecbf4(uVar25,param_1,param_2 & 0xffffffffffffc000,0,0,0);
    bVar6 = *(byte *)(uVar25 + 0x2d);
    if ((bVar6 & 0x51) == 0x50) {
      if ((uVar25 < DAT_fffffff007be4010) || (DAT_fffffff007be4008 <= uVar25)) {
        iVar15 = *(int *)(uVar25 + 0x3c);
      }
      else {
        iVar15 = DAT_fffffff007be4000 + (int)(uVar25 - DAT_fffffff007be4010 >> 6);
      }
      FUN_fffffff00a33c778(iVar15);
      bVar6 = *(byte *)(uVar25 + 0x2d);
    }
    *(byte *)(uVar25 + 0x2d) = bVar6 | 1;
    uVar7 = *(ushort *)(param_1 + 0x1b);
    uVar21 = uVar7 - 1;
    *(short *)(param_1 + 0x1b) = (short)uVar21;
    if (0xffff < uVar21) goto LAB_fffffff00a29b050;
    uVar21 = uVar21 & 0xffff;
    if (((*(byte *)((long)param_1 + 0x75) >> 4 & 1) == 0) &&
       (((*(byte *)((long)param_1 + 0xa9) & (uint)uVar7 == (uint)DAT_fffffff007bc0ab0) != 0 ||
        (DAT_fffffff007bc0ab2 == uVar7)))) {
      FUN_fffffff00a2cfbfc(param_1,6);
      uVar21 = (uint)*(ushort *)(param_1 + 0x1b);
    }
    if ((uVar21 == 0) && (FUN_fffffff00a2cfbfc(param_1,5), param_1[0x1c] == 0)) {
      FUN_fffffff00a2cfbfc(param_1,2);
    }
    FUN_fffffff00a2c79a8(param_1,param_2 & 0xffffffffffffc000,1);
    uVar7 = *(ushort *)(param_1 + 0x1b);
    *(short *)(param_1 + 0x1b) = (short)(uVar7 + 1);
    if (uVar7 + 1 >> 0x10 != 0) {
LAB_fffffff00a29b044:
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa0c4f8("vm_object_paging_begin(%p): overflow\n @%s:%d");
    }
    bVar6 = 0;
    local_b8 = 0;
    local_e0 = 3;
    puVar26 = param_1;
    uVar28 = uVar25;
    local_a8 = param_2;
    goto LAB_fffffff00a29a468;
  }
  puVar26 = *(undefined4 **)(puVar27 + 0x12);
  if (puVar26 != (undefined4 *)0x0) {
    if (param_4 == 0) {
      if (puVar27 == param_1) {
        *(byte *)(uVar28 + 0x2c) = bVar20 & 0xf7 | 4;
        *(int *)(lVar8 + 0x1c0) = *(int *)(lVar8 + 0x1c0) + 1;
        uVar25 = (ulong)*(uint *)(lVar8 + 0x4e8) | 0x30000000;
        if (DAT_fffffff00ad2d0c8 != 0) {
          FUN_fffffff00a1ea02c(&DAT_fffffff00ad2d0c0,lVar8,1);
          uVar25 = DAT_fffffff00ad2d0c8;
        }
        DAT_fffffff00ad2d0c8 = uVar25;
        FUN_fffffff00a2ed744(uVar28,0);
        local_b8 = uVar28;
        if ((int)DAT_fffffff00ad2d0c8 == *(int *)(lVar8 + 0x4e8)) {
          DAT_fffffff00ad2d0c8 = CONCAT44(DAT_fffffff00ad2d0c8._4_4_,in_wzr);
        }
        else {
          FUN_fffffff00a1eab60(&DAT_fffffff00ad2d0c0,lVar8);
        }
      }
      else {
        uVar7 = *(ushort *)(puVar27 + 0x1b);
        uVar24 = uVar7 - 1;
        *(short *)(puVar27 + 0x1b) = (short)uVar24;
        if (0xffff < uVar24) goto LAB_fffffff00a29b050;
        uVar24 = uVar24 & 0xffff;
        if (((*(byte *)((long)puVar27 + 0x75) >> 4 & 1) == 0) &&
           (((*(byte *)((long)puVar27 + 0xa9) & (uint)uVar7 == (uint)DAT_fffffff007bc0ab0) != 0 ||
            (DAT_fffffff007bc0ab2 == uVar7)))) {
          FUN_fffffff00a2cfbfc(puVar27,6);
          uVar24 = (uint)*(ushort *)(puVar27 + 0x1b);
        }
        if (uVar24 == 0) {
          uVar24 = puVar27[0x1d];
          if ((uVar24 >> 5 & 1) != 0) {
            FUN_fffffff00a20dce4((long)puVar27 + 5,0,0);
            uVar24 = puVar27[0x1d];
          }
          puVar27[0x1d] = uVar24 & 0xffffffdf;
          if (puVar27[0x1c] == 0) {
            FUN_fffffff00a2cfbfc(puVar27,2);
          }
        }
        FUN_fffffff00a2ed2a8(uVar28);
      }
    }
    else {
      uVar7 = *(ushort *)(puVar27 + 0x1b);
      uVar24 = uVar7 - 1;
      *(short *)(puVar27 + 0x1b) = (short)uVar24;
      if (0xffff < uVar24) goto LAB_fffffff00a29b050;
      uVar24 = uVar24 & 0xffff;
      uVar21 = puVar27[0x1d];
      if (((uVar21 >> 0xc & 1) == 0) &&
         (((*(byte *)((long)puVar27 + 0xa9) & (uint)uVar7 == (uint)DAT_fffffff007bc0ab0) != 0 ||
          (DAT_fffffff007bc0ab2 == uVar7)))) {
        if ((uVar21 >> 6 & 1) != 0) {
          plVar1 = (long *)(_DAT_fffffff00acce458 + (ulong)*(ushort *)(lVar8 + 0x1b0) * 0x4000);
          lVar13 = *plVar1;
          *plVar1 = lVar13 + 1;
          FUN_fffffff00a20dce4(lVar13,(long)puVar27 + 6,0,0);
          uVar21 = puVar27[0x1d];
          uVar24 = (uint)*(ushort *)(puVar27 + 0x1b);
        }
        uVar21 = uVar21 & 0xffffffbf;
        puVar27[0x1d] = uVar21;
      }
      if (uVar24 == 0) {
        if ((uVar21 >> 5 & 1) != 0) {
          FUN_fffffff00a20dce4((long)puVar27 + 5,0,0);
          uVar21 = puVar27[0x1d];
        }
        uVar24 = uVar21 & 0xffffffdf;
        puVar27[0x1d] = uVar24;
        if (puVar27[0x1c] == 0) {
          if ((uVar21 >> 2 & 1) != 0) {
            FUN_fffffff00a20dce4((long)puVar27 + 2,0,0);
            uVar24 = puVar27[0x1d];
          }
          puVar27[0x1d] = uVar24 & 0xfffffffb;
        }
      }
    }
    lVar13 = *(long *)(puVar27 + 0x16);
    *(long *)(param_12 + 6) = *(long *)(param_12 + 6) + lVar13;
    *(long *)(param_12 + 8) = *(long *)(param_12 + 8) + *(long *)(puVar27 + 0x16);
    FUN_fffffff00a2c987c(puVar26);
    FUN_fffffff00a1eec04(puVar27 + 2);
    uVar24 = *(ushort *)(puVar26 + 0x1b) + 1;
    *(short *)(puVar26 + 0x1b) = (short)uVar24;
    local_e0 = 4;
joined_r0xfffffff00a2993bc:
    local_d4 = 1;
    local_a8 = lVar13 + local_a8;
    puVar27 = puVar26;
    if (uVar24 >> 0x10 == 0) goto LAB_fffffff00a298cac;
    goto LAB_fffffff00a29b044;
  }
  uVar25 = FUN_fffffff00a29bc0c(puVar27,uVar28,local_b8,uVar3,param_9 == (int *)0x0);
  if ((int)uVar25 != 0) {
    return uVar25;
  }
  uVar24 = uVar21 >> 1 & 0x10000;
  if (puVar27 == param_1) {
    *(byte *)(uVar28 + 0x2c) = *(byte *)(uVar28 + 0x2c) & 0xf7 | 4;
  }
  else {
    FUN_fffffff00a2ed2a8(uVar28);
    FUN_fffffff00a29bd58(puVar27);
    FUN_fffffff00a1eec04(puVar27 + 2);
    FUN_fffffff00a2c987c(param_1);
    puVar27 = param_1;
    uVar28 = local_b8;
    local_b8 = 0;
    local_a8 = param_2;
  }
  bVar6 = 0;
  if (param_11 == 1) {
    bVar6 = *(byte *)(param_12 + 10) >> 5 & 1;
  }
  puVar26 = puVar27;
  if (bVar6 == 0) {
    if (param_11 != 0) {
      *(ushort *)(uVar28 + 0x2e) = *(ushort *)(uVar28 + 0x2e) & 0xf000;
      *(byte *)(uVar28 + 0x2d) = *(byte *)(uVar28 + 0x2d) | 0x10;
      bVar20 = *(byte *)(uVar28 + 0x2c);
      goto LAB_fffffff00a299e4c;
    }
    FUN_fffffff00a2f0f44(uVar28);
    *(ushort *)(uVar28 + 0x2e) = *(ushort *)(uVar28 + 0x2e) & 0xf000;
    *(byte *)(uVar28 + 0x2d) = *(byte *)(uVar28 + 0x2d) | 0x10;
    local_e0 = 1;
  }
  else {
    bVar20 = *(byte *)(uVar28 + 0x2c) | 8;
    *(byte *)(uVar28 + 0x2c) = bVar20;
    *(ushort *)(uVar28 + 0x2e) = *(ushort *)(uVar28 + 0x2e) & 0xf000;
    *(byte *)(uVar28 + 0x2d) = *(byte *)(uVar28 + 0x2d) | 0x10;
LAB_fffffff00a299e4c:
    local_e0 = 5;
    if (((bVar20 ^ 0xff) & 0xc) == 0) goto LAB_fffffff00a29a468;
  }
  FUN_fffffff00a298680(puVar27,uVar28);
LAB_fffffff00a29a468:
  uVar25 = (ulong)uVar24;
  puVar27 = *(undefined4 **)(param_1 + 0xe);
  if (puVar27 != (undefined4 *)0x0) {
    if ((param_3 >> 1 & 1) == 0) {
      *param_6 = *param_6 & 0xfffffffd;
    }
    else if (param_4 == 0) {
      uVar21 = 1;
      goto LAB_fffffff00a29a60c;
    }
  }
  *param_7 = uVar28;
  *param_8 = local_b8;
  goto LAB_fffffff00a29a4a8;
  while( true ) {
    FUN_fffffff00a1eec04(puVar26 + 2);
    uVar23 = uVar21;
    if (0x1e < uVar21) {
      uVar23 = 0x1f;
    }
    (&DAT_fffffff00acf3da0)[uVar23] = (&DAT_fffffff00acf3da0)[uVar23] + 1;
    uVar23 = uVar21;
    if (6 < uVar21) {
      uVar23 = 7;
    }
    FUN_fffffff00a20ab3c
              (FUN_fffffff00a1eaf38,0,*(undefined4 *)(&DAT_fffffff00accc410 + (ulong)uVar23 * 4),
               1000);
    FUN_fffffff00a20b730(0,0,0);
    uVar25 = FUN_fffffff00a2c987c(puVar26);
    puVar27 = *(undefined4 **)(param_1 + 0xe);
    uVar21 = uVar21 + 1;
    if (puVar27 == (undefined4 *)0x0) break;
LAB_fffffff00a29a60c:
    iVar15 = FUN_fffffff00a2cef38(puVar27);
    if (iVar15 != 0) {
      if (puVar27[10] + 0xf0000001 < 0xf0000002) {
LAB_fffffff00a29b0d8:
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa21104(puVar27 + 10);
      }
      puVar27[10] = puVar27[10] + 1;
      uVar25 = param_2 - *(long *)(puVar27 + 0x16) & 0xffffffffffffc000;
      if (uVar25 < *(ulong *)(puVar27 + 6)) {
        lVar13 = FUN_fffffff00a2ef170(puVar27,uVar25);
        if (lVar13 == 0) {
          iVar16 = FUN_fffffff00a2c984c(puVar27,uVar25);
          if (iVar16 != 1) {
            uVar18 = FUN_fffffff00a2f01d8(uVar24);
            if (uVar18 == 0) {
              FUN_fffffff00a2cdfcc(0,uVar28);
              if ((1L << (*(byte *)(uVar28 + 0x2a) & 0xf) & 0x3d60U) == 0) {
                FUN_fffffff00a1ea97c(&DAT_fffffff00ad2d0c0);
                if ((bVar6 != 0) && ((*(byte *)(uVar28 + 0x2c) >> 3 & 1) != 0)) {
                  FUN_fffffff00a2f0f44(uVar28);
                  *(byte *)(uVar28 + 0x2c) = *(byte *)(uVar28 + 0x2c) & 0xf7;
                }
                if ((1L << (*(byte *)(uVar28 + 0x2a) & 0xf) & 0x3d60U) == 0) {
                  if (DAT_fffffff00ad55024 == 1) {
                    FUN_fffffff00a2ed584(uVar28,1);
                  }
                  else {
                    FUN_fffffff00a2ef580(uVar28);
                  }
                }
                if ((int)DAT_fffffff00ad2d0c8 == *(int *)(lVar8 + 0x4e8)) {
                  DAT_fffffff00ad2d0c8 = CONCAT44(DAT_fffffff00ad2d0c8._4_4_,in_wzr);
                }
                else {
                  FUN_fffffff00a1eab60(&DAT_fffffff00ad2d0c0,lVar8);
                }
              }
              FUN_fffffff00a29bea4(puVar27 + 10);
              FUN_fffffff00a1eec04(puVar27 + 2);
              puVar27 = puVar26;
LAB_fffffff00a299eb4:
              FUN_fffffff00a29b220(puVar27,local_b8);
              uVar7 = *(ushort *)(lVar8 + 200);
LAB_fffffff00a29aa5c:
              *(ushort *)(lVar8 + 200) = uVar7 & 0xfffc | uVar3;
              return 3;
            }
            FUN_fffffff00a2ecbf4(uVar18,puVar27,uVar25,0,0,0);
            FUN_fffffff00a2f2558(uVar28,uVar18);
            if ((*(byte *)(uVar28 + 0x2d) >> 4 & 1) == 0) {
              if ((*(byte *)(uVar28 + 0x2d) >> 3 & 1) == 0) goto LAB_fffffff00a29a93c;
LAB_fffffff00a29accc:
              lVar13 = FUN_fffffff00a25f6f4(lVar8);
              plVar1 = (long *)(*(long *)(lVar13 + 0x388) +
                               (ulong)*(ushort *)(lVar8 + 0x1b0) * 0x4000);
              *plVar1 = *plVar1 + 1;
              if ((uVar28 < DAT_fffffff007be4010) || (DAT_fffffff007be4008 <= uVar28)) {
                iVar16 = *(int *)(uVar28 + 0x3c);
              }
              else {
                iVar16 = DAT_fffffff007be4000 + (int)(uVar28 - DAT_fffffff007be4010 >> 6);
              }
              FUN_fffffff00a33f5d0(iVar16);
              uVar22 = (ulong)*(byte *)(uVar28 + 0x2d);
              if ((*(byte *)(uVar28 + 0x2d) >> 3 & 1) != 0) {
                lVar13 = 0;
                if (*(uint *)(uVar28 + 0x1c) != 0) {
                  lVar13 = (ulong)*(uint *)(uVar28 + 0x1c) * 0x40 + -0x2400000000;
                }
                *(int *)(lVar13 + 0xa0) = *(int *)(lVar13 + 0xa0) + 1;
                *(byte *)(uVar28 + 0x2d) = *(byte *)(uVar28 + 0x2d) & 0xf7;
                puVar2 = (ulong *)(_DAT_fffffff00acd88c0 +
                                  (ulong)*(ushort *)(lVar8 + 0x1b0) * 0x4000);
                uVar22 = *puVar2;
                *puVar2 = uVar22 + 1;
              }
              FUN_fffffff00a33f77c(uVar22,iVar16);
              bVar6 = *(byte *)((long)puVar27 + 0x75);
            }
            else {
              if ((uVar28 < DAT_fffffff007be4010) || (DAT_fffffff007be4008 <= uVar28)) {
                iVar16 = *(int *)(uVar28 + 0x3c);
              }
              else {
                iVar16 = DAT_fffffff007be4000 + (int)(uVar28 - DAT_fffffff007be4010 >> 6);
              }
              FUN_fffffff00a33f500(iVar16);
              if ((*(byte *)(uVar28 + 0x2d) >> 3 & 1) != 0) goto LAB_fffffff00a29accc;
LAB_fffffff00a29a93c:
              bVar6 = *(byte *)((long)puVar27 + 0x75);
            }
            if (((bVar6 >> 1 & 1) != 0) &&
               (iVar16 = FUN_fffffff00a2c984c(puVar27,uVar25), iVar16 != 3)) {
                    /* WARNING: Subroutine does not return */
              FUN_fffffff00aa0c4f8
                        ("External objects are not implemented for CoW. %p %i %i %llx %llx @%s:%d");
            }
            FUN_fffffff00a1ea97c(&DAT_fffffff00ad2d0c0);
            uVar17 = FUN_fffffff00a2ef580(uVar18);
            if ((int)DAT_fffffff00ad2d0c8 == *(int *)(lVar8 + 0x4e8)) {
              DAT_fffffff00ad2d0c8 = CONCAT44(DAT_fffffff00ad2d0c8._4_4_,in_wzr);
            }
            else {
              uVar17 = FUN_fffffff00a1eab60(&DAT_fffffff00ad2d0c0,lVar8);
            }
            bVar6 = *(byte *)(uVar18 + 0x2d);
            if ((bVar6 & 0x51) == 0x50) {
              if ((uVar18 < DAT_fffffff007be4010) || (DAT_fffffff007be4008 <= uVar18)) {
                iVar16 = *(int *)(uVar18 + 0x3c);
              }
              else {
                iVar16 = DAT_fffffff007be4000 + (int)(uVar18 - DAT_fffffff007be4010 >> 6);
              }
              uVar17 = FUN_fffffff00a33c778(iVar16);
              bVar6 = *(byte *)(uVar18 + 0x2d);
            }
            *(byte *)(uVar18 + 0x2d) = bVar6 | 1;
            FUN_fffffff00a2cdfcc(uVar17,uVar18);
            if ((*(byte *)(uVar28 + 0x2c) >> 6 & 1) != 0) {
              *(byte *)(uVar28 + 0x2c) = *(byte *)(uVar28 + 0x2c) & 0xbf;
              FUN_fffffff00a20dce4(uVar28,0,3);
            }
          }
        }
        else if ((*(byte *)(lVar13 + 0x2c) >> 2 & 1) != 0) {
          FUN_fffffff00a2cdfcc(lVar13,uVar28);
          if ((1L << (*(byte *)(uVar28 + 0x2a) & 0xf) & 0x3d60U) == 0) {
            FUN_fffffff00a1ea97c(&DAT_fffffff00ad2d0c0);
            if ((bVar6 != 0) && ((*(byte *)(uVar28 + 0x2c) >> 3 & 1) != 0)) {
              FUN_fffffff00a2f0f44(uVar28);
              *(byte *)(uVar28 + 0x2c) = *(byte *)(uVar28 + 0x2c) & 0xf7;
            }
            if ((1L << (*(byte *)(uVar28 + 0x2a) & 0xf) & 0x3d60U) == 0) {
              if (DAT_fffffff00ad55024 == 1) {
                FUN_fffffff00a2ed584(uVar28,1);
              }
              else {
                FUN_fffffff00a2ef580(uVar28);
              }
            }
            if ((int)DAT_fffffff00ad2d0c8 == *(int *)(lVar8 + 0x4e8)) {
              DAT_fffffff00ad2d0c8 = CONCAT44(DAT_fffffff00ad2d0c8._4_4_,in_wzr);
            }
            else {
              FUN_fffffff00a1eab60(&DAT_fffffff00ad2d0c0,lVar8);
            }
          }
          if (0xf0000001 < puVar27[10] + 0xf0000001) {
            puVar27[10] = puVar27[10] + 1;
            FUN_fffffff00a1eec04(puVar27 + 2);
            FUN_fffffff00a29b220(puVar26,local_b8);
            FUN_fffffff00a2c987c(puVar27);
            FUN_fffffff00a29bea4(puVar27 + 10);
            lVar13 = FUN_fffffff00a2ef170(puVar27,uVar25);
            if ((lVar13 == 0) || ((*(byte *)(lVar13 + 0x2c) >> 2 & 1) == 0)) {
              FUN_fffffff00a1eec04(puVar27 + 2);
LAB_fffffff00a29afb0:
              FUN_fffffff00a2c7010(puVar27);
LAB_fffffff00a29afb4:
              uVar7 = *(ushort *)(lVar8 + 200);
LAB_fffffff00a29afc4:
              *(ushort *)(lVar8 + 200) = uVar7 & 0xfffc | uVar3;
              return 1;
            }
            FUN_fffffff00a29be80(param_13,&DAT_fffffff00acd8848,5);
            iVar16 = FUN_fffffff00a2c9108(puVar27,lVar13,iVar16,1);
            FUN_fffffff00a2c7010(puVar27);
LAB_fffffff00a299f04:
            *(ushort *)(lVar8 + 200) = *(ushort *)(lVar8 + 200) & 0xfffc | uVar3;
            if (iVar16 != 2) {
              return 1;
            }
joined_r0xfffffff00a29a8d4:
            if (lVar8 == 0) {
              uVar17 = 0;
            }
            else {
              uVar17 = *(undefined8 *)(lVar8 + 0x4e0);
            }
            uVar19 = 0x1000024;
LAB_fffffff00a29992c:
            FUN_fffffff00a69c288(uVar17,uVar19,0);
            return 2;
          }
          goto LAB_fffffff00a29b0d8;
        }
      }
      if (puVar27[10] == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa210d4(puVar27 + 10);
      }
      iVar16 = puVar27[10] + -1;
      puVar27[10] = iVar16;
      if (iVar16 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa21074(puVar27 + 10);
      }
      uVar25 = FUN_fffffff00a1eec04(puVar27 + 2);
      break;
    }
  }
  *param_7 = uVar28;
  *param_8 = local_b8;
  if (uVar28 == 0) {
LAB_fffffff00a29aea8:
    if (lVar8 == 0) {
      uVar17 = 0;
    }
    else {
      uVar17 = *(undefined8 *)(lVar8 + 0x4e0);
    }
    FUN_fffffff00a69c288(uVar17,0x1000028,0);
    uVar25 = 6;
    goto LAB_fffffff00a29a84c;
  }
LAB_fffffff00a29a4a8:
  if (local_e0 == 2) {
    lVar13 = FUN_fffffff00a25f6f4(lVar8);
    plVar1 = (long *)(*(long *)(lVar13 + 0x388) + (ulong)*(ushort *)(lVar8 + 0x1b0) * 0x4000);
    *plVar1 = *plVar1 + 1;
    local_e0 = 7;
    if ((puVar26[0x1d] & 0x1000) != 0) {
      local_e0 = 8;
    }
    param_12[10] = param_12[10] | 0x2000;
    FUN_fffffff00a297548(puVar26,local_a8,param_12[4]);
    uVar25 = FUN_fffffff00a29bed4(puVar26,local_a8,param_12);
LAB_fffffff00a29a514:
    if (param_9 != (int *)0x0) {
      *param_9 = local_e0;
    }
  }
  else {
    if ((param_9 != (int *)0x0) || (local_e0 != 4)) {
      if (local_e0 - 9U < 2) {
        plVar1 = (long *)(_DAT_fffffff00acce498 + (ulong)*(ushort *)(lVar8 + 0x1b0) * 0x4000);
        *plVar1 = *plVar1 + 1;
        *(int *)(lVar8 + 0x560) = *(int *)(lVar8 + 0x560) + 1;
      }
      goto LAB_fffffff00a29a514;
    }
    if ((*(byte *)(uVar28 + 0x2d) >> 3 & 1) != 0) {
      lVar13 = FUN_fffffff00a25f6f4(lVar8);
      plVar1 = (long *)(*(long *)(lVar13 + 0x388) + (ulong)*(ushort *)(lVar8 + 0x1b0) * 0x4000);
      *plVar1 = *plVar1 + 1;
      plVar1 = (long *)(_DAT_fffffff00acce428 + (ulong)*(ushort *)(lVar8 + 0x1b0) * 0x4000);
      *plVar1 = *plVar1 + 1;
      plVar1 = (long *)(*(long *)(lVar13 + 0x398) + (ulong)*(ushort *)(lVar8 + 0x1b0) * 0x4000);
      *plVar1 = *plVar1 + 1;
      if ((uVar28 < DAT_fffffff007be4010) || (DAT_fffffff007be4008 <= uVar28)) {
        iVar16 = *(int *)(uVar28 + 0x3c);
      }
      else {
        iVar16 = DAT_fffffff007be4000 + (int)(uVar28 - DAT_fffffff007be4010 >> 6);
      }
      FUN_fffffff00a33f5d0(iVar16);
      uVar25 = (ulong)*(byte *)(uVar28 + 0x2d);
      if ((*(byte *)(uVar28 + 0x2d) >> 3 & 1) != 0) {
        lVar13 = 0;
        if (*(uint *)(uVar28 + 0x1c) != 0) {
          lVar13 = (ulong)*(uint *)(uVar28 + 0x1c) * 0x40 + -0x2400000000;
        }
        *(int *)(lVar13 + 0xa0) = *(int *)(lVar13 + 0xa0) + 1;
        *(byte *)(uVar28 + 0x2d) = *(byte *)(uVar28 + 0x2d) & 0xf7;
        puVar2 = (ulong *)(_DAT_fffffff00acd88c0 + (ulong)*(ushort *)(lVar8 + 0x1b0) * 0x4000);
        uVar25 = *puVar2;
        *puVar2 = uVar25 + 1;
      }
      FUN_fffffff00a33f77c(uVar25,iVar16);
      param_12[10] = param_12[10] | 0x2000;
    }
    FUN_fffffff00a297548(puVar26,local_a8,param_12[4]);
    uVar25 = FUN_fffffff00a2eb9dc(uVar28);
    if ((uVar25 & 1) == 0) {
      uVar25 = FUN_fffffff00a29bed4(puVar26,local_a8,param_12);
    }
  }
  if ((*(byte *)((long)puVar26 + 0xab) >> 2 & 1) == 0) {
    uVar25 = 0;
  }
  else {
    if ((param_3 >> 1 & 1) != 0) {
      FUN_fffffff00a2cdfcc(uVar25,uVar28);
      FUN_fffffff00a29b220(puVar26,local_b8);
      *(ushort *)(lVar8 + 200) = *(ushort *)(lVar8 + 200) & 0xfffc | uVar3;
      DAT_fffffff00ad54d88 = DAT_fffffff00ad54d88 + 1;
      if (lVar8 == 0) {
        uVar17 = 0;
      }
      else {
        uVar17 = *(undefined8 *)(lVar8 + 0x4e0);
      }
      uVar25 = 0x1000108;
LAB_fffffff00a29990c:
      FUN_fffffff00a69c288(uVar17,uVar25,0);
      return 5;
    }
    uVar25 = 0;
    *param_6 = *param_6 & 0xfffffffd;
  }
LAB_fffffff00a29a84c:
  *(ushort *)(lVar8 + 200) = *(ushort *)(lVar8 + 200) & 0xfffc | uVar3;
  return uVar25;
}

