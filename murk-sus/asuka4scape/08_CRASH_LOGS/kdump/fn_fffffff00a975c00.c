// FUN_fffffff00a975c00 @ fffffff00a975c00 size=2564
// CALLERS:
//   fffffff00afbf149 ?
//   fffffff00a975ad4 FUN_fffffff00a9759a8@fffffff00a9759a8
// CALLS:
//   fffffff00a1d0934 FUN_fffffff00a1d0934
//   fffffff00aa4d114 FUN_fffffff00aa4d114
//   fffffff00a2f5290 FUN_fffffff00a2f5290
//   fffffff00a342370 FUN_fffffff00a342370
//   fffffff00a31b1b8 FUN_fffffff00a31b1b8
//   fffffff00a8947f8 FUN_fffffff00a8947f8
//   fffffff00a31924c FUN_fffffff00a31924c
//   fffffff00a302900 FUN_fffffff00a302900
//   fffffff00a33134c FUN_fffffff00a33134c
//   fffffff00a31912c FUN_fffffff00a31912c
//   fffffff00a2ceb5c FUN_fffffff00a2ceb5c
//   fffffff00a2217b4 FUN_fffffff00a2217b4
//   fffffff00a396010 FUN_fffffff00a396010
//   fffffff00a73e370 FUN_fffffff00a73e370
//   fffffff00a1d12d4 FUN_fffffff00a1d12d4
//   fffffff00a378f10 FUN_fffffff00a378f10

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_fffffff00a975c00
              (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
              undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long *param_7,
              uint param_8,undefined8 param_9,undefined8 param_10,undefined ***param_11,
              undefined8 param_12,ulong *param_13)

{
  ulong *puVar1;
  undefined ***pppuVar2;
  int iVar3;
  uint uVar4;
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  undefined **ppuVar11;
  byte bVar12;
  bool bVar13;
  ushort uVar14;
  uint uVar15;
  int iVar16;
  undefined8 uVar17;
  undefined ******ppppppuVar18;
  undefined *******pppppppuVar19;
  long extraout_x1;
  long extraout_x1_00;
  undefined *******pppppppuVar20;
  undefined **ppuVar21;
  undefined **ppuVar22;
  uint *puVar23;
  undefined4 **ppuVar24;
  byte bVar25;
  uint uVar26;
  undefined ***pppuVar27;
  ulong uVar28;
  ulong uVar29;
  undefined ***pppuVar30;
  long *plVar31;
  undefined **ppuVar32;
  uint uVar33;
  uint uVar34;
  long *plVar35;
  long lVar36;
  undefined8 *puVar37;
  uint uVar38;
  ulong uVar39;
  undefined *******pppppppuVar40;
  uint uVar41;
  uint uVar42;
  ulong uVar43;
  undefined **ppuVar44;
  long lVar45;
  ulong uVar46;
  undefined4 *puVar47;
  undefined8 extraout_d0;
  undefined8 extraout_d0_00;
  undefined8 extraout_var;
  undefined8 extraout_var_00;
  undefined8 uVar48;
  undefined1 auVar49 [16];
  ulong local_d8;
  uint local_c8;
  ulong local_c0;
  undefined1 local_b8 [8];
  undefined4 *local_b0;
  ulong uStack_a8;
  ulong uStack_a0;
  undefined8 local_98;
  long local_90;
  undefined **local_80;
  ulong local_78;
  uint auStack_6c [3];
  
  uVar43 = param_2._8_8_;
  uVar46 = param_2._0_8_;
  uVar4 = *(uint *)(param_7 + 4);
  if ((param_8 & 3) == 0) {
    uVar15 = (**(code **)(*param_7 + 0xa8))(param_1._0_8_,param_7);
    param_8 = uVar15 | param_8;
  }
  if (*(long *)(param_7[0x12] + 0x18) == 0) {
    plVar35 = (long *)0x0;
  }
  else {
    plVar35 = *(long **)(param_7[0x12] + 0x10);
  }
  uVar15 = param_8 & 3;
  bVar25 = *(byte *)((long)plVar35 + 0x2d);
  bVar12 = bVar25 | 0xc0;
  if (uVar15 == 2) {
    bVar12 = bVar25 & 0x3f | 0x40;
  }
  bVar25 = bVar25 & 0x3f | 0x80;
  if (uVar15 != 1) {
    bVar25 = bVar12;
  }
  uVar28 = 0;
  if (uVar15 != 1) {
    uVar28 = (ulong)(uVar15 == 2);
  }
  *(byte *)((long)plVar35 + 0x2d) = bVar25;
  if ((int)param_7[0x11] == 0) {
    lVar45 = *plVar35;
    plVar35[2] = 0;
    *(byte *)((long)plVar35 + 0x2d) = bVar25 & 0xfd;
    uVar41 = (uint)*(ushort *)(param_7 + 6);
    if (*(ushort *)(param_7 + 6) == 0) {
      if ((*(undefined8 **)(DAT_fffffff007c678d8 + 0x58) == (undefined8 *)0x0) ||
         (*(undefined8 **)(DAT_fffffff007c678d8 + 0x58) != &DAT_fffffff00ad6cc50)) {
        uVar41 = 0x15;
      }
      else {
        uVar14 = FUN_fffffff00a33134c();
        uVar41 = 3;
        if (uVar14 != 0) {
          uVar41 = (uint)uVar14;
        }
      }
    }
    uVar29 = 0x1400;
    if ((param_8 & 8) != 0) {
      uVar29 = 0x20001400;
    }
    if (*(uint *)(plVar35 + 5) >> 0x1d != 0) {
      return -0x1ffffd43;
    }
    pppuVar27 = (undefined ***)((ulong)*(uint *)(plVar35 + 5) * 8);
    lVar36 = param_7[0x12];
    pppppppuVar19 = *(undefined ********)(lVar36 + 0x10);
    if ((pppppppuVar19 != (undefined *******)0x0) &&
       (bVar13 = CARRY8(*(ulong *)(lVar36 + 0x18),(ulong)pppuVar27),
       pppuVar27 = (undefined ***)(*(ulong *)(lVar36 + 0x18) + (long)pppuVar27), bVar13)) {
      return -0x1ffffd43;
    }
    if ((pppppppuVar19 == (undefined *******)0x0) || (*(undefined ****)(lVar36 + 0x20) < pppuVar27))
    {
      param_11 = (undefined ***)0x31004;
      auVar49 = FUN_fffffff00a2217b4
                          ((long *)&DAT_fffffff007c87ff1,pppppppuVar19,
                           *(undefined ****)(lVar36 + 0x20),pppuVar27,0x31004,0,(ulong)param_13);
      if (auVar49._0_8_ == 0) {
        return -0x1ffffd43;
      }
      *(long *)(lVar36 + 0x10) = auVar49._0_8_;
      *(undefined ****)(lVar36 + 0x20) = pppuVar27;
    }
    *(undefined ****)(lVar36 + 0x18) = pppuVar27;
    lVar36 = param_7[5];
    if (lVar36 == 0) {
      if (((param_7[0xe] == DAT_fffffff007c68058) &&
          ((*(byte *)((long)param_7 + 0x21) >> 2 & 1) != 0)) ||
         (local_d8 = *(ulong *)(param_7[0xe] + 0x28), local_d8 == 0)) {
        local_d8 = 0;
      }
      puVar37 = (undefined8 *)0x0;
      bVar25 = 1;
    }
    else {
      local_d8 = 0;
      puVar37 = (undefined8 *)(lVar36 + 0x18);
      bVar25 = *(byte *)(lVar36 + 6) >> 4 & 1;
    }
    if (param_7[10] != 0) {
      uVar39 = 0;
      uVar33 = 0;
      local_c0 = 0;
      uVar42 = 0;
      uVar28 = uVar29 | uVar28 | (ulong)((param_8 & 0x30) << 0x1a);
      plVar35 = (long *)param_7[0xc];
LAB_fffffff00a975f30:
      local_90 = 0;
      uStack_a8 = 0;
      local_b0 = (undefined4 *)0x0;
      local_98 = 0;
      uStack_a0 = 0;
      lVar36 = param_7[5];
      uVar38 = (uint)uVar39;
      if (lVar36 == 0) {
        if ((uVar4 & 0xf0) == 0x50) {
          local_80 = (undefined **)0x0;
          local_78 = 0;
          FUN_fffffff00a73e370(plVar35,uVar38,&local_80,&local_78);
          uVar29 = local_78;
          ppuVar44 = local_80;
        }
        else {
          puVar1 = (ulong *)(plVar35 + uVar39 * 2);
          ppuVar44 = (undefined **)*puVar1;
          uVar29 = puVar1[1];
        }
        if (bVar25 == 0) {
          uVar39 = (ulong)ppuVar44 & 0x3fff;
          ppuVar44 = (undefined **)((ulong)ppuVar44 & 0xffffffffffffc000);
        }
        else {
          uVar39 = 0;
        }
      }
      else {
        if (*(uint *)(lVar36 + 0xc) <= uVar38) {
          auVar49._8_8_ = uVar43;
          auVar49._0_8_ = uVar46;
                    /* WARNING: Subroutine does not return */
          FUN_fffffff00aa4d114
                    (ZEXT816(0),auVar49,param_3,param_4,param_5,param_6,(byte *)"memRefEntry @%s:%d"
                    );
        }
        puVar37 = (undefined8 *)(lVar36 + 0x18U + uVar39 * 0x20);
        if (((lVar36 + 0x18U ^ (ulong)puVar37) & 0xffc0000000000000) != 0) {
          puVar37 = (undefined8 *)((ulong)puVar37 & 0xffffffffffff | 0xc8a2000000000000);
        }
        uVar29 = puVar37[2];
        if (bVar25 == 0) {
          uVar39 = puVar37[3] & 0x3fff;
          ppuVar44 = (undefined **)0xffffffffffffffff;
        }
        else {
          uVar39 = 0;
          ppuVar44 = (undefined **)0xffffffffffffffff;
        }
      }
      uVar34 = 0;
      if (lVar45 != 0) {
        uVar34 = uVar42;
      }
      local_98 = CONCAT44((int)uVar39,uVar34);
      ppuVar22 = (undefined **)(uVar39 + uVar29);
      if (ppuVar22 != (undefined **)0x0) {
        uVar34 = 0;
        puVar47 = (undefined4 *)0x0;
        uVar29 = 0;
        local_c8 = uVar33;
        do {
          uVar39 = local_d8;
          if (local_d8 == 0) {
            if (param_7[5] == 0) {
              uVar39 = DAT_fffffff00ad966b8;
              if (ppuVar44 < DAT_fffffff00ad966c0 || DAT_fffffff00ad966c8 <= ppuVar44) {
                auVar5._8_8_ = uVar29;
                auVar5._0_8_ = puVar47;
                auVar8._8_8_ = uVar43;
                auVar8._0_8_ = uVar46;
                    /* WARNING: Subroutine does not return */
                FUN_fffffff00aa4d114
                          (auVar5,auVar8,param_3,param_4,param_5,param_6,
                           (byte *)"IOPageableMapForAddress: address out of range @%s:%d");
              }
            }
            else {
              uVar39 = 0;
            }
          }
          if (*(long *)(param_7[0x12] + 0x18) == 0) {
            lVar36 = 0;
          }
          else {
            lVar36 = *(long *)(param_7[0x12] + 0x10);
          }
          local_80 = (undefined **)0x0;
          local_b8 = (undefined1  [8])0x0;
          local_78 = uVar28;
          if (param_7[5] == 0) {
            pppuVar27 = &local_80;
            ppuVar21 = ppuVar22;
            uVar29 = FUN_fffffff00a2f5290(uVar39,(ulong)ppuVar44,ppuVar22,(ulong *)pppuVar27);
            iVar16 = (int)uVar29;
            uVar17 = extraout_d0_00;
            uVar48 = extraout_var_00;
            if (iVar16 == 0) goto LAB_fffffff00a9760c0;
LAB_fffffff00a97647c:
            lVar45 = param_7[0x12];
            pppppppuVar20 = *(undefined ********)(lVar45 + 0x10);
            pppppppuVar19 = (undefined *******)0x0;
            if (*(long *)(lVar45 + 0x18) != 0) {
              pppppppuVar19 = pppppppuVar20;
            }
            pppppppuVar40 = pppppppuVar19 + 6 + *(uint *)(pppppppuVar20 + 5);
            if ((((ulong)(pppppppuVar19 + 6) ^ (ulong)pppppppuVar40) & 0xffc0000000000000) != 0) {
              pppppppuVar40 =
                   (undefined *******)((ulong)pppppppuVar40 & 0xffffffffffff | 0xc8a2000000000000);
            }
            lVar36 = -0x30;
            if (pppppppuVar20 != (undefined *******)0x0) {
              lVar36 = *(long *)(lVar45 + 0x18) + -0x30;
            }
            uVar43 = (lVar36 + (ulong)*(uint *)(pppppppuVar20 + 5) * -8) / 0x28 & 0xffffffff;
            if (uVar43 != 0) {
              lVar45 = 0;
              do {
                pppppppuVar19 = pppppppuVar40 + lVar45 * 5;
                if ((((ulong)pppppppuVar40 ^ (ulong)pppppppuVar19) & 0xffc0000000000000) != 0) {
                  pppppppuVar19 =
                       (undefined *******)
                       ((ulong)pppppppuVar19 & 0xffffffffffff | 0xc8a2000000000000);
                }
                ppppppuVar18 = *pppppppuVar19;
                if (ppppppuVar18 != (undefined ******)0x0) {
                  ppuVar44 = (undefined **)(ulong)*(uint *)(ppppppuVar18 + 5);
                  ppuVar24 = &local_b0;
                  ppuVar22 = (undefined **)0x0;
                  FUN_fffffff00a342370
                            ((undefined4 *)ppppppuVar18,0,ppuVar44,(undefined **)0x0,
                             (uint *)ppuVar24);
                  FUN_fffffff00a31924c
                            ((undefined4 *)*pppppppuVar19,extraout_x1_00,ppuVar44,ppuVar22,ppuVar24)
                  ;
                }
                lVar45 = lVar45 + 1;
                uVar43 = uVar43 - 1;
              } while (uVar43 != 0);
              lVar45 = param_7[0x12];
              pppppppuVar20 = *(undefined ********)(lVar45 + 0x10);
            }
            if ((pppppppuVar20 == (undefined *******)0x0) ||
               (*(undefined ****)(lVar45 + 0x20) < &DAT_00000030)) {
              auVar49 = FUN_fffffff00a2217b4
                                  ((long *)&DAT_fffffff007c87ff1,pppppppuVar20,
                                   *(undefined ****)(lVar45 + 0x20),(undefined ***)&DAT_00000030,
                                   0x31004,0,(ulong)param_13);
              if (auVar49._0_8_ == 0) goto LAB_fffffff00a97657c;
              *(long *)(lVar45 + 0x10) = auVar49._0_8_;
              *(undefined8 *)(lVar45 + 0x20) = 0x30;
            }
            *(undefined8 *)(lVar45 + 0x18) = 0x30;
LAB_fffffff00a97657c:
            iVar3 = iVar16;
            if (iVar16 == 10) {
              iVar3 = -0x1ffffd42;
            }
            if (iVar16 == 5) {
              return -0x1ffffd22;
            }
            return iVar3;
          }
          pppuVar27 = (undefined ***)puVar37[2];
          param_11 = &local_80;
          ppuVar21 = (undefined **)0x0;
          auVar6._8_8_ = uVar29;
          auVar6._0_8_ = puVar47;
          auVar9._8_8_ = uVar43;
          auVar9._0_8_ = uVar46;
          uVar17 = FUN_fffffff00a302900
                             (auVar6,auVar9,param_3,param_4,param_5,param_6,(char *)*puVar37,
                              (undefined **)0x0,0,(undefined **)pppuVar27,(ulong *)param_11);
          iVar16 = (int)uVar17;
          uVar17 = extraout_d0;
          uVar48 = extraout_var;
          if (iVar16 != 0) goto LAB_fffffff00a97647c;
LAB_fffffff00a9760c0:
          pppuVar2 = (undefined ***)(lVar36 + 0x30 + (ulong)uVar42 * 8);
          if ((undefined **)0x3ffffff < local_80) {
            local_80 = (undefined **)0x4000000;
          }
          uVar33 = (uint)((ulong)local_80 >> 0xe);
          ppuVar32 = local_80;
          if (bVar25 == 0) {
            local_b8 = (undefined1  [8])(CONCAT44((int)local_80,uVar33) & 0xffffffff0003ffff);
            if (param_7[5] != 0) {
              lVar36 = puVar37[1] + (local_98 >> 0x20);
              goto LAB_fffffff00a976128;
            }
LAB_fffffff00a976170:
            if (((uVar39 != DAT_fffffff007c678d8) || (ppuVar44 < DAT_fffffff007c2f1b8)) ||
               (DAT_fffffff007c2f1c0 <= ppuVar44)) {
              param_13 = &local_78;
              param_11 = pppuVar2;
              uVar43 = FUN_fffffff00a31b1b8
                                 (uVar39,ppuVar44,(undefined **)(local_b8 + 4),
                                  (undefined **)&local_b0,(uint *)pppuVar2,(uint *)local_b8,param_13
                                  ,uVar41);
              iVar16 = (int)uVar43;
              goto joined_r0xfffffff00a976168;
            }
            uVar29 = (_DAT_fffffff00ad970e8 & (ulong)ppuVar44) + (long)ppuVar32;
            if (0xffffffffffffc000 < uVar29) {
              auVar7._8_8_ = uVar48;
              auVar7._0_8_ = uVar17;
              auVar10._8_8_ = uVar43;
              auVar10._0_8_ = uVar46;
                    /* WARNING: Subroutine does not return */
              FUN_fffffff00aa4d114
                        (auVar7,auVar10,param_3,param_4,param_5,param_6,
                         (byte *)"overflow detected @%s:%d");
            }
            uVar26 = (uint)(uVar29 + 0x3fff >> 0xe) & 0x3ffff;
            if ((uVar33 & 0x3ffff) <= uVar26) {
              uVar26 = uVar33 & 0x3ffff;
            }
            local_b8._4_4_ = uVar26 << 0xe;
            local_b0 = (undefined4 *)0x0;
            local_98 = CONCAT44((int)(_DAT_fffffff00ad970e8 & (ulong)ppuVar44),(undefined4)local_98)
            ;
            if (uVar26 != 0) {
              uVar43 = 0;
              ppuVar32 = ppuVar44;
              uVar33 = 0;
              do {
                plVar31 = (long *)FUN_fffffff00a1d0934((ulong)ppuVar32);
                if (plVar31 == (long *)0x0) {
                  plVar31 = FUN_fffffff00a378f10(&DAT_fffffff00ad6cc50,(ulong)ppuVar32);
                }
                uVar34 = (uint)((ulong)plVar31 >> 0xe);
                if (uVar34 == 0) {
                  iVar16 = -0x1ffffd38;
                  goto LAB_fffffff00a97647c;
                }
                *(uint *)((long)pppuVar2 +
                         (-(uVar43 >> 0x1f & 1) & 0xfffffff800000000 | (uVar43 & 0xffffffff) << 3))
                     = uVar34;
                pppuVar30 = pppuVar2 + uVar43;
                if ((((ulong)pppuVar2 ^ (ulong)pppuVar30) & 0xffc0000000000000) != 0) {
                  pppuVar30 = (undefined ***)
                              ((ulong)pppuVar30 & 0xffffffffffff | 0xc8a2000000000000);
                }
                *(uint *)((long)pppuVar30 + 4) = *(uint *)((long)pppuVar30 + 4) & 0xffffffe0;
                FUN_fffffff00a31912c
                          ((ulong)pppuVar2,uVar43,(int)ppuVar21,(ulong)pppuVar27,(byte)param_11);
                if (uVar34 <= uVar33) {
                  uVar34 = uVar33;
                }
                uVar43 = uVar43 + 1;
                ppuVar32 = ppuVar32 + 0x800;
                uVar33 = uVar34;
              } while (uVar26 != uVar43);
              goto LAB_fffffff00a976288;
            }
            uVar34 = 0;
          }
          else {
            ppuVar32 = ppuVar22;
            if (local_80 <= ppuVar22) {
              ppuVar32 = local_80;
            }
            local_b8 = (undefined1  [8])(CONCAT44((int)ppuVar32,uVar33) & 0xffffffff0003ffff);
            if (param_7[5] == 0) goto LAB_fffffff00a976170;
            lVar36 = puVar37[1];
LAB_fffffff00a976128:
            ppuVar21 = (undefined **)(puVar37[2] - (local_c0 - lVar36));
            if (ppuVar21 < ppuVar32) {
              local_b8._4_4_ = (int)ppuVar21;
            }
            param_13 = &local_78;
            param_11 = pppuVar2;
            iVar16 = FUN_fffffff00a2ceb5c
                               ((char *)*puVar37,local_c0 - lVar36,(uint *)(local_b8 + 4),
                                (undefined **)&local_b0,(uint *)pppuVar2,(uint *)local_b8,param_13,
                                uVar41);
joined_r0xfffffff00a976168:
            if (iVar16 != 0) goto LAB_fffffff00a97647c;
LAB_fffffff00a976288:
            if (local_b0 != (undefined4 *)0x0) {
              uVar34 = local_b0[0x16];
            }
          }
          puVar47 = local_b0;
          uVar33 = uVar34;
          if (uVar34 <= local_c8) {
            uVar33 = local_c8;
          }
          bVar13 = (*(byte *)((long)pppuVar2 + 4) >> 4 & 1) != 0;
          if (bVar13) {
            local_b8._0_4_ = 1;
          }
          local_90 = CONCAT44(local_90._4_4_,(uint)bVar13);
          ppuVar32 = ppuVar44;
          ppuVar21 = ppuVar22;
          if (bVar25 != 0) {
            if (local_b0 == (undefined4 *)0x0) {
              uVar43 = local_98 >> 0x20;
            }
            else {
              uVar43 = *(ulong *)(local_b0 + 8) & 0x3fff;
              local_98 = CONCAT44((int)uVar43,(undefined4)local_98);
            }
            ppuVar32 = (undefined **)((long)ppuVar44 - uVar43);
            if (ppuVar44 == (undefined **)0xffffffffffffffff) {
              ppuVar32 = (undefined **)0xffffffffffffffff;
            }
            local_b8._4_4_ = local_b8._0_4_ << 0xe;
            ppuVar21 = (undefined **)((long)ppuVar22 + uVar43);
          }
          uStack_a8 = (ulong)uVar42;
          uStack_a0 = local_c0;
          lVar36 = param_7[0x12];
          pppppppuVar19 = *(undefined ********)(lVar36 + 0x10);
          if (pppppppuVar19 != (undefined *******)0x0) {
            uVar46 = *(ulong *)(lVar36 + 0x18);
            pppuVar27 = (undefined ***)(uVar46 + 0x28);
            if (uVar46 < 0xffffffffffffffd8) goto LAB_fffffff00a976330;
LAB_fffffff00a976450:
            if (puVar47 != (undefined4 *)0x0) {
              ppuVar44 = (undefined **)(ulong)(uint)puVar47[10];
              puVar23 = auStack_6c;
              ppuVar22 = (undefined **)0x0;
              FUN_fffffff00a342370(puVar47,0,ppuVar44,(undefined **)0x0,puVar23);
              FUN_fffffff00a31924c(puVar47,extraout_x1,ppuVar44,ppuVar22,puVar23);
            }
            iVar16 = -0x1ffffd43;
            goto LAB_fffffff00a97647c;
          }
          uVar46 = 0;
          pppuVar27 = (undefined ***)&DAT_00000028;
LAB_fffffff00a976330:
          if ((pppppppuVar19 == (undefined *******)0x0) ||
             (*(undefined ****)(lVar36 + 0x20) < pppuVar27)) {
            param_11 = (undefined ***)0x31004;
            auVar49 = FUN_fffffff00a2217b4
                                ((long *)&DAT_fffffff007c87ff1,pppppppuVar19,
                                 *(undefined ****)(lVar36 + 0x20),pppuVar27,0x31004,0,
                                 (ulong)param_13);
            pppppppuVar19 = auVar49._0_8_;
            if (pppppppuVar19 == (undefined *******)0x0) goto LAB_fffffff00a976450;
            *(undefined ********)(lVar36 + 0x10) = pppppppuVar19;
            *(undefined ****)(lVar36 + 0x20) = pppuVar27;
          }
          uVar43 = local_98;
          *(undefined ****)(lVar36 + 0x18) = pppuVar27;
          plVar31 = (long *)((long)pppppppuVar19 + uVar46);
          if ((((ulong)pppppppuVar19 ^ (ulong)plVar31) & 0xffc0000000000000) != 0) {
            plVar31 = (long *)((ulong)plVar31 & 0xffffffffffff | 0xc8a2000000000000);
          }
          plVar31[1] = uStack_a8;
          *plVar31 = (long)local_b0;
          plVar31[3] = local_98;
          plVar31[2] = uStack_a0;
          plVar31[4] = local_90;
          ppuVar11 = (undefined **)((ulong)local_b8 >> 0x20);
          uVar42 = local_b8._0_4_ + uVar42;
          lVar36 = local_c0 - (local_98 >> 0x20);
          ppuVar22 = (undefined **)((long)ppuVar21 - (long)ppuVar11);
          uVar46 = uStack_a0;
          if (ppuVar21 < ppuVar11 || ppuVar22 == (undefined **)0x0) goto LAB_fffffff00a9763e4;
          ppuVar44 = (undefined **)((long)ppuVar32 + (long)ppuVar11);
          if (ppuVar32 == (undefined **)0xffffffffffffffff) {
            ppuVar44 = (undefined **)0xffffffffffffffff;
          }
          local_98 = local_98 & 0xffffffff;
          if (lVar45 != 0) {
            local_98 = (ulong)uVar42;
          }
          local_c0 = lVar36 + (long)ppuVar11;
          puVar47 = local_b0;
          uVar29 = uStack_a8;
          local_c8 = uVar33;
        } while( true );
      }
      goto LAB_fffffff00a976404;
    }
    uVar33 = 0;
LAB_fffffff00a976420:
    *(uint *)((long)param_7 + 0x9c) = uVar33;
    if (uVar15 == 2) {
      *(uint *)(param_7 + 4) = *(uint *)(param_7 + 4) | 0x8000;
      return 0;
    }
  }
  else if ((*(byte *)((long)param_7 + 0x21) & 0x80) != 0 && uVar15 != 2) {
    uVar43 = (ulong)param_7 & 0x7ffffffffff;
    if (((ulong)param_7 & 0x80000000000000) != 0) {
      uVar43 = (ulong)param_7 | 0xffffff8000000000;
    }
    if (((uVar43 < DAT_fffffff007c6a360 && DAT_fffffff007c6a358 <= uVar43) ||
        (DAT_fffffff007c6a378 <= uVar43 && uVar43 < DAT_fffffff007c6a380)) ||
       ((DAT_fffffff007c6a3a0 <= uVar43 && (uVar43 < DAT_fffffff007c6a3a8)))) {
      FUN_fffffff00a396010(uVar43);
    }
    else if (uVar43 + 0x2400000000 >> 0x25 == 0) {
      FUN_fffffff00a1d12d4(uVar43);
    }
    FUN_fffffff00a8947f8((byte *)"IOMemoryDescriptor 0x%zx prepared read only");
    return -0x1ffffd31;
  }
  return 0;
LAB_fffffff00a9763e4:
  local_c0 = lVar36 + (long)ppuVar21;
LAB_fffffff00a976404:
  uVar39 = (ulong)(uVar38 + 1);
  if ((ulong)param_7[10] <= local_c0) goto LAB_fffffff00a976420;
  goto LAB_fffffff00a975f30;
}

