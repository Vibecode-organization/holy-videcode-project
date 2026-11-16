/* ==== _lookup_glyphs_by_cmap @ 183bf4b20 size=520 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _lookup_glyphs_by_cmap(undefined8 *param_1,long param_2,long param_3)

{
  code *pcVar1;
  undefined2 uVar2;
  int iVar3;
  long lVar4;
  undefined2 *puVar5;
  ulong uVar6;
  long lVar7;
  ulong unaff_x30;
  undefined8 uVar8;
  undefined8 uVar9;
  byte bVar10;
  byte bVar11;
  undefined8 local_248 [64];
  long local_48;
  
  local_48 = *_DAT_1e0186220;
  lVar4 = FUN_183bf2988(*param_1);
  if (((lVar4 != 0) && ((*(byte *)(lVar4 + 0x28) >> 5 & 1) != 0)) ||
     ((*(uint *)(param_1 + 1) & 0xfffffffe) == 2)) {
    if (*_DAT_1e0186220 == local_48) {
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
        _lookup_glyphs_by_cmap_nonsymbolic(param_1,param_2,param_3);
        return;
      }
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xc471,0x183bf4bc4);
      (*pcVar1)();
    }
    goto LAB_183bf4d24;
  }
  puVar5 = (undefined2 *)func_0x000188138460(1,0x208,0x1080040036ec52c);
  *puVar5 = 0;
  if (param_2 == 0) {
LAB_183bf4cdc:
    _lookup_glyphs_by_cmap_nonsymbolic(param_1,param_2,param_3);
  }
  else {
    iVar3 = (**(code **)(*(long *)(param_2 + 0x10) + 0x100))
                      (*(undefined8 *)(param_2 + 0x70),3,0,puVar5);
    if (iVar3 == 0) {
      iVar3 = (**(code **)(*(long *)(param_2 + 0x10) + 0x100))
                        (*(undefined8 *)(param_2 + 0x70),1,0,puVar5);
      if (iVar3 == 0) goto LAB_183bf4cdc;
      uVar6 = 0;
      do {
        if (puVar5 == (undefined2 *)0x0) {
          uVar2 = 0xffff;
        }
        else if (puVar5 == (undefined2 *)0xffffffffffffffff) {
          uVar2 = (undefined2)uVar6;
        }
        else if (*(long *)(puVar5 + (uVar6 >> 10 & 0x3f) * 4 + 4) == 0) {
          uVar2 = *puVar5;
        }
        else {
          uVar2 = *(undefined2 *)(*(long *)(puVar5 + (uVar6 >> 10 & 0x3f) * 4 + 4) + uVar6 * 2);
        }
        *(undefined2 *)(param_3 + uVar6 * 2) = uVar2;
        uVar6 = uVar6 + 1;
      } while (uVar6 != 0x100);
    }
    else {
      uVar2 = _get_3_0_cmap_prefix(puVar5);
      lVar4 = 0;
      uVar9 = 0x7000600050004;
      uVar8 = 0x3000200010000;
      lVar7 = 0x100;
      do {
        bVar10 = (byte)uVar2;
        bVar11 = (byte)((ushort)uVar2 >> 8);
        *(ulong *)((long)local_248 + lVar4 * 2 + 8) =
             CONCAT17(bVar11 | (byte)((ulong)uVar9 >> 0x38),
                      CONCAT16(bVar10 | (byte)((ulong)uVar9 >> 0x30),
                               CONCAT15(bVar11 | (byte)((ulong)uVar9 >> 0x28),
                                        CONCAT14(bVar10 | (byte)((ulong)uVar9 >> 0x20),
                                                 CONCAT13(bVar11 | (byte)((ulong)uVar9 >> 0x18),
                                                          CONCAT12(bVar10 | (byte)((ulong)uVar9 >>
                                                                                  0x10),
                                                                   CONCAT11(bVar11 | (byte)((ulong)
                                                  uVar9 >> 8),bVar10 | (byte)uVar9)))))));
        *(ulong *)((long)local_248 + lVar4 * 2) =
             CONCAT17(bVar11 | (byte)((ulong)uVar8 >> 0x38),
                      CONCAT16(bVar10 | (byte)((ulong)uVar8 >> 0x30),
                               CONCAT15(bVar11 | (byte)((ulong)uVar8 >> 0x28),
                                        CONCAT14(bVar10 | (byte)((ulong)uVar8 >> 0x20),
                                                 CONCAT13(bVar11 | (byte)((ulong)uVar8 >> 0x18),
                                                          CONCAT12(bVar10 | (byte)((ulong)uVar8 >>
                                                                                  0x10),
                                                                   CONCAT11(bVar11 | (byte)((ulong)
                                                  uVar8 >> 8),bVar10 | (byte)uVar8)))))));
        lVar4 = lVar4 + 8;
        uVar8 = CONCAT26((short)((ulong)uVar8 >> 0x30) + 8,
                         CONCAT24((short)((ulong)uVar8 >> 0x20) + 8,
                                  CONCAT22((short)((ulong)uVar8 >> 0x10) + 8,(short)uVar8 + 8)));
        uVar9 = CONCAT26((short)((ulong)uVar9 >> 0x30) + 8,
                         CONCAT24((short)((ulong)uVar9 >> 0x20) + 8,
                                  CONCAT22((short)((ulong)uVar9 >> 0x10) + 8,(short)uVar9 + 8)));
        lVar7 = lVar7 + -8;
      } while (lVar7 != 0);
      FUN_183fd7dc0(puVar5,local_248,0x100,param_3);
    }
  }
  FUN_183b7cf6c(puVar5);
  if (*_DAT_1e0186220 == local_48) {
    return;
  }
LAB_183bf4d24:
  func_0x000188138130();
  return;
}



/* ==== ___CGPDFCMapGetTypeID_block_invoke @ 183bf71bc size=40 ==== */

void ___CGPDFCMapGetTypeID_block_invoke(void)

{
  DAT_1eb056f28 = _pdf_register_cftype(&DAT_1e2238e48);
  return;
}



/* ==== _cmap_yyensure_buffer_stack @ 183bf71e4 size=156 ==== */

void _cmap_yyensure_buffer_stack(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  undefined8 *puVar2;
  long lVar3;
  undefined8 uVar4;
  undefined1 auVar5 [16];
  
  if (*(long *)(param_1 + 0x28) == 0) {
    puVar2 = (undefined8 *)func_0x000188138470(8,0x4adc8ba7);
    *(undefined8 **)(param_1 + 0x28) = puVar2;
    if (puVar2 == (undefined8 *)0x0) {
LAB_183bf727c:
      auVar5 = _fatal_scanner_error();
      if (*(long *)(auVar5._0_8_ + 0x10) != 0) {
        func_0x000188138390();
      }
      lVar3 = func_0x0001881386f0(auVar5._8_8_);
      lVar1 = func_0x0001881386f0(param_3);
      uVar4 = func_0x000188138470(lVar3 + lVar1 + 0x23,0xdc3e2c2);
      *(undefined8 *)(auVar5._0_8_ + 0x10) = uVar4;
      func_0x00018813bab0(uVar4,lVar3 + lVar1 + 0x23,0,"%s-%s-%u");
      return;
    }
    *puVar2 = 0;
    *(undefined8 *)(param_1 + 0x20) = 1;
    *(undefined8 *)(param_1 + 0x18) = 0;
  }
  else if (*(long *)(param_1 + 0x20) - 1U <= *(ulong *)(param_1 + 0x18)) {
    lVar3 = *(long *)(param_1 + 0x20) + 8;
    param_3 = 0xb6775a77;
    lVar1 = func_0x000188138490(*(long *)(param_1 + 0x28),lVar3 * 8);
    *(long *)(param_1 + 0x28) = lVar1;
    if (lVar1 == 0) goto LAB_183bf727c;
    puVar2 = (undefined8 *)(lVar1 + *(long *)(param_1 + 0x20) * 8);
    puVar2[5] = 0;
    puVar2[4] = 0;
    puVar2[7] = 0;
    puVar2[6] = 0;
    puVar2[1] = 0;
    *puVar2 = 0;
    puVar2[3] = 0;
    puVar2[2] = 0;
    *(long *)(param_1 + 0x20) = lVar3;
  }
  return;
}



/* ==== _cmap_set_ros @ 183bf7280 size=152 ==== */

void _cmap_set_ros(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  
  if (*(long *)(param_1 + 0x10) != 0) {
    func_0x000188138390();
  }
  lVar1 = func_0x0001881386f0(param_2);
  lVar2 = func_0x0001881386f0(param_3);
  uVar3 = func_0x000188138470(lVar1 + lVar2 + 0x23,0xdc3e2c2);
  *(undefined8 *)(param_1 + 0x10) = uVar3;
  func_0x00018813bab0(uVar3,lVar1 + lVar2 + 0x23,0,"%s-%s-%u");
  return;
}



/* ==== _cmap_set_name @ 183bf7318 size=140 ==== */

void _cmap_set_name(long param_1,undefined8 param_2)

{
  int iVar1;
  long lVar2;
  
  if (*(long *)(param_1 + 8) != 0) {
    func_0x000188138390();
    *(undefined1 *)(param_1 + 0x28) = 0;
  }
  lVar2 = func_0x0001881386f0(param_2);
  lVar2 = func_0x000188138470(lVar2 + 1,0xb2120583);
  *(long *)(param_1 + 8) = lVar2;
  if (lVar2 != 0) {
    func_0x00018814d5d0(lVar2,param_2);
    iVar1 = func_0x0001881386b0(param_2,"Identity-H");
    if ((iVar1 == 0) || (iVar1 = func_0x0001881386b0(param_2,"Identity-V"), iVar1 == 0)) {
      *(undefined1 *)(param_1 + 0x28) = 1;
    }
  }
  return;
}



/* ==== _cmap_csr_set_create @ 183bf73a4 size=112 ==== */

undefined2 * _cmap_csr_set_create(void)

{
  undefined2 *puVar1;
  long lVar2;
  
  puVar1 = (undefined2 *)func_0x000188138460(1,0x18,0x10200404be0e0e6);
  if (puVar1 != (undefined2 *)0x0) {
    *puVar1 = 8;
    lVar2 = func_0x0001881404d0(0,0,0);
    *(long *)(puVar1 + 4) = lVar2;
    if (lVar2 == 0) {
      _cmap_csr_set_release(puVar1);
      puVar1 = (undefined2 *)0x0;
    }
  }
  return puVar1;
}



/* ==== _cmap_csr_set_add_codespace_range @ 183bf7414 size=100 ==== */

void _cmap_csr_set_add_codespace_range
               (byte *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  
  lVar1 = _csr_create(param_2,param_3,param_4);
  if (lVar1 != 0) {
    func_0x0001881404a0(*(undefined8 *)(param_1 + 8),lVar1);
    if ((uint)param_2 < (uint)*param_1) {
      *param_1 = (byte)param_2;
    }
    if ((uint)param_1[1] < (uint)param_2) {
      param_1[1] = (byte)param_2;
    }
  }
  return;
}



/* ==== _cmap_bf_set_add_range @ 183bf77b4 size=1212 ==== */

void _cmap_bf_set_add_range
               (uint *param_1,uint param_2,undefined8 param_3,ulong param_4,ushort *param_5)

{
  undefined4 *puVar1;
  uint *puVar2;
  uint uVar3;
  ulong uVar4;
  long lVar5;
  undefined8 uVar6;
  int iVar7;
  ulong uVar8;
  ulong uVar9;
  undefined8 *puVar10;
  ulong uVar11;
  long *plVar12;
  uint uVar13;
  long *plVar14;
  long *plVar15;
  ulong uVar16;
  uint uVar17;
  long lVar18;
  ulong uVar19;
  long *plVar20;
  ulong unaff_x26;
  bool bVar21;
  uint uVar22;
  ulong uVar23;
  
  if (0x400 < param_4) {
    return;
  }
  if (*(ulong *)(param_1 + 10) < param_4) {
    *(ulong *)(param_1 + 10) = param_4;
  }
  uVar19 = *(ulong *)(param_1 + 4);
  lVar18 = *(long *)(param_1 + 6);
  uVar23 = param_4 + lVar18 + 1;
  if (uVar19 < uVar23) {
    do {
      uVar19 = uVar19 * 2 + 10;
    } while (uVar19 < uVar23);
    lVar5 = func_0x000188138490(*(undefined8 *)(param_1 + 8),uVar19 * 2,0x1000040bdfb0063);
    if (lVar5 == 0) {
      return;
    }
    *(long *)(param_1 + 8) = lVar5;
    *(ulong *)(param_1 + 4) = uVar19;
    lVar18 = *(long *)(param_1 + 6);
  }
  else {
    lVar5 = *(long *)(param_1 + 8);
  }
  *(long *)(param_1 + 6) = lVar18 + 1;
  *(short *)(lVar5 + lVar18 * 2) = (short)param_4;
  func_0x0001881384d0(lVar5 + (lVar18 + 1) * 2,param_5,param_4 << 1);
  *(ulong *)(param_1 + 6) = *(long *)(param_1 + 6) + param_4;
  uVar17 = (uint)param_3;
  if (uVar17 < *param_1) {
    if (uVar17 < param_2) goto LAB_183bf78d8;
  }
  else {
    uVar23 = __ZL13grow_code_mapP11cmap_bf_setj(param_1,param_3);
    if ((uVar17 < param_2) || ((uVar23 & 1) == 0)) goto LAB_183bf78d8;
  }
  iVar7 = 0;
  lVar5 = *(long *)(param_1 + 2);
  uVar13 = param_2;
  do {
    puVar1 = (undefined4 *)(lVar5 + (ulong)uVar13 * 8);
    *puVar1 = (int)lVar18;
    puVar1[1] = iVar7;
    uVar13 = uVar13 + 1;
    iVar7 = iVar7 + 1;
  } while (uVar13 <= uVar17);
LAB_183bf78d8:
  if ((param_4 == 1) && (param_2 <= uVar17)) {
    puVar2 = param_1 + 0x10;
    do {
      uVar19 = (ulong)*param_5;
      uVar23 = *(ulong *)(param_1 + 0xe);
      if (uVar23 != 0) {
        uVar8 = uVar23 - 1;
        uVar22 = (uint)uVar23;
        uVar13 = (uint)*param_5;
        if ((uVar23 & uVar8) == 0) {
          unaff_x26 = uVar22 - 1 & uVar19;
        }
        else {
          uVar3 = 0;
          if (uVar22 != 0) {
            uVar3 = uVar13 / uVar22;
          }
          unaff_x26 = uVar19;
          if (uVar23 <= uVar19) {
            unaff_x26 = (ulong)(uVar13 - uVar3 * uVar22);
          }
        }
        puVar10 = *(undefined8 **)(*(long *)(param_1 + 0xc) + unaff_x26 * 8);
        if (puVar10 != (undefined8 *)0x0) {
          for (plVar20 = (long *)*puVar10; plVar20 != (long *)0x0; plVar20 = (long *)*plVar20) {
            uVar11 = plVar20[1];
            if (uVar11 == uVar19) {
              if (*(ushort *)(plVar20 + 2) == uVar13) goto LAB_183bf7c40;
            }
            else {
              if ((uVar23 & uVar8) == 0) {
                uVar11 = uVar11 & uVar8;
              }
              else if (uVar23 <= uVar11) {
                uVar9 = 0;
                if (uVar23 != 0) {
                  uVar9 = uVar11 / uVar23;
                }
                uVar11 = uVar11 - uVar9 * uVar23;
              }
              if (uVar11 != unaff_x26) break;
            }
          }
        }
      }
      plVar20 = (long *)func_0x00018814d110(0x18,0x1020c005af6bdc9);
      *plVar20 = 0;
      plVar20[1] = uVar19;
      *(ushort *)(plVar20 + 2) = *param_5;
      lVar18 = *(long *)(param_1 + 0x12);
      *(undefined2 *)((long)plVar20 + 0x12) = 0;
      if ((float)param_1[0x14] * (float)uVar23 < (float)(lVar18 + 1)) {
        uVar8 = 1;
        if (2 < uVar23) {
          uVar8 = (ulong)((uVar23 & uVar23 - 1) != 0);
        }
        uVar8 = uVar8 | uVar23 << 1;
        uVar23 = (ulong)((float)(lVar18 + 1) / (float)param_1[0x14]);
        if (uVar8 <= uVar23) {
          uVar8 = uVar23;
        }
        if (uVar8 - 1 == 0) {
          uVar8 = 2;
        }
        else if ((uVar8 & uVar8 - 1) != 0) {
          uVar8 = func_0x0001881457f0(uVar8);
        }
        uVar23 = *(ulong *)(param_1 + 0xe);
        if (uVar23 < uVar8) {
LAB_183bf7a30:
          if (uVar8 >> 0x3d != 0) {
                    /* WARNING: Subroutine does not return */
            __ZSt28__throw_bad_array_new_lengthB9nqe220106v();
          }
          uVar6 = func_0x00018814d110(uVar8 << 3,0x20c0093837f09);
          bVar21 = false;
LAB_183bf7a54:
          lVar18 = *(long *)(param_1 + 0xc);
          *(undefined8 *)(param_1 + 0xc) = uVar6;
          if (lVar18 != 0) {
            func_0x00018814d0d0(lVar18);
          }
          *(ulong *)(param_1 + 0xe) = uVar8;
          uVar23 = uVar8;
          if (!bVar21) {
            lVar18 = *(long *)(param_1 + 0xc);
            func_0x0001881382e0(lVar18,uVar8 << 3);
            plVar12 = *(long **)(param_1 + 0x10);
            if (plVar12 != (long *)0x0) {
              uVar11 = plVar12[1];
              uVar9 = uVar8 - 1;
              if ((uVar8 & uVar9) == 0) {
                uVar11 = uVar11 & uVar9;
              }
              else if (uVar8 <= uVar11) {
                uVar16 = 0;
                if (uVar8 != 0) {
                  uVar16 = uVar11 / uVar8;
                }
                uVar11 = uVar11 - uVar16 * uVar8;
              }
              *(uint **)(lVar18 + uVar11 * 8) = puVar2;
              plVar14 = (long *)*plVar12;
              while (plVar14 != (long *)0x0) {
                uVar16 = plVar14[1];
                if ((uVar8 & uVar9) == 0) {
                  uVar16 = uVar16 & uVar9;
                }
                else if (uVar8 <= uVar16) {
                  uVar4 = 0;
                  if (uVar8 != 0) {
                    uVar4 = uVar16 / uVar8;
                  }
                  uVar16 = uVar16 - uVar4 * uVar8;
                }
                plVar15 = plVar14;
                if (uVar16 != uVar11) {
                  if (*(long *)(lVar18 + uVar16 * 8) == 0) {
                    *(long **)(lVar18 + uVar16 * 8) = plVar12;
                    uVar11 = uVar16;
                  }
                  else {
                    *plVar12 = *plVar14;
                    *plVar14 = **(undefined8 **)(lVar18 + uVar16 * 8);
                    **(long **)(lVar18 + uVar16 * 8) = (long)plVar14;
                    plVar15 = plVar12;
                  }
                }
                plVar12 = plVar15;
                plVar14 = (long *)*plVar15;
              }
            }
          }
        }
        else if (uVar8 < uVar23) {
          uVar11 = (ulong)((float)*(ulong *)(param_1 + 0x12) / (float)param_1[0x14]);
          if ((uVar23 < 3) || ((uVar23 & uVar23 - 1) != 0)) {
            uVar11 = func_0x0001881457f0();
          }
          else if (1 < uVar11) {
            uVar11 = 1L << (-LZCOUNT(uVar11 - 1) & 0x3fU);
          }
          if (uVar8 <= uVar11) {
            uVar8 = uVar11;
          }
          if (uVar8 < uVar23) {
            if (uVar8 != 0) goto LAB_183bf7a30;
            uVar6 = 0;
            bVar21 = true;
            goto LAB_183bf7a54;
          }
          uVar23 = *(ulong *)(param_1 + 0xe);
        }
        if ((uVar23 & uVar23 - 1) == 0) {
          unaff_x26 = (int)uVar23 - 1 & uVar19;
        }
        else {
          uVar8 = 0;
          if (uVar23 != 0) {
            uVar8 = uVar19 / uVar23;
          }
          unaff_x26 = uVar19;
          if (uVar23 <= uVar19) {
            unaff_x26 = uVar19 - uVar8 * uVar23;
          }
        }
      }
      lVar18 = *(long *)(param_1 + 0xc);
      plVar12 = *(long **)(lVar18 + unaff_x26 * 8);
      if (plVar12 == (long *)0x0) {
        *plVar20 = *(long *)puVar2;
        *(long **)puVar2 = plVar20;
        *(uint **)(lVar18 + unaff_x26 * 8) = puVar2;
        if (*plVar20 != 0) {
          uVar19 = *(ulong *)(*plVar20 + 8);
          if ((uVar23 & uVar23 - 1) == 0) {
            uVar19 = uVar19 & uVar23 - 1;
          }
          else if (uVar23 <= uVar19) {
            uVar8 = 0;
            if (uVar23 != 0) {
              uVar8 = uVar19 / uVar23;
            }
            uVar19 = uVar19 - uVar8 * uVar23;
          }
          *(long **)(lVar18 + uVar19 * 8) = plVar20;
        }
      }
      else {
        *plVar20 = *plVar12;
        *plVar12 = (long)plVar20;
      }
      *(long *)(param_1 + 0x12) = *(long *)(param_1 + 0x12) + 1;
LAB_183bf7c40:
      *(short *)((long)plVar20 + 0x12) = (short)param_2;
      param_2 = param_2 + 1;
    } while (param_2 <= uVar17);
  }
  return;
}



/* ==== __ZL13grow_code_mapP11cmap_bf_setj @ 183bf7c8c size=140 ==== */

undefined8 __ZL13grow_code_mapP11cmap_bf_setj(uint *param_1,uint param_2)

{
  uint uVar1;
  long lVar2;
  ulong uVar3;
  long lVar4;
  ulong uVar5;
  
  uVar5 = (ulong)*param_1;
  if (*param_1 <= param_2) {
    do {
      uVar1 = (int)uVar5 * 2 + 10;
      uVar5 = (ulong)uVar1;
    } while (uVar1 <= param_2);
    lVar2 = func_0x000188138490(*(undefined8 *)(param_1 + 2),uVar5 << 3,0x100004000313f17);
    if (lVar2 == 0) {
      return 0;
    }
    uVar3 = (ulong)*param_1;
    if (*param_1 < uVar1) {
      lVar4 = uVar5 - uVar3;
      do {
        *(undefined8 *)(lVar2 + uVar3 * 8) = 0xffffffff;
        uVar3 = uVar3 + 1;
        lVar4 = lVar4 + -1;
      } while (lVar4 != 0);
    }
    *(long *)(param_1 + 2) = lVar2;
    *param_1 = uVar1;
  }
  return 1;
}



/* ==== _cmap_yy_delete_buffer @ 183bf7d18 size=96 ==== */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Possible PIC construction at 0x000183bf7d54: Changing call to branch */

void _cmap_yy_delete_buffer(long param_1,long param_2)

{
  code *pcVar1;
  long lVar2;
  ulong unaff_x30;
  
  lVar2 = *(long *)(param_2 + 0x28);
  if ((lVar2 != 0) && (param_1 == *(long *)(lVar2 + *(long *)(param_2 + 0x18) * 8))) {
    *(undefined8 *)(lVar2 + *(long *)(param_2 + 0x18) * 8) = 0;
  }
  if ((*(int *)(param_1 + 0x28) == 0) && (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0)) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0x183bf7d74);
    (*pcVar1)();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* ==== _cmap_bf_set_get_unichars @ 183bf7ee8 size=208 ==== */

ulong _cmap_bf_set_get_unichars(uint *param_1,uint param_2,long param_3)

{
  uint uVar1;
  uint *puVar2;
  ushort *puVar3;
  ushort uVar4;
  ulong uVar5;
  ulong uVar6;
  uint uVar7;
  ulong uVar8;
  
  if ((param_1 != (uint *)0x0) && (param_2 < *param_1)) {
    puVar2 = (uint *)(*(long *)(param_1 + 2) + (ulong)param_2 * 8);
    uVar7 = *puVar2;
    if (uVar7 != 0xffffffff) {
      puVar3 = (ushort *)(*(long *)(param_1 + 8) + (ulong)uVar7 * 2);
      uVar4 = *puVar3;
      uVar5 = (ulong)uVar4;
      if ((param_3 != 0) && (uVar4 != 0)) {
        uVar6 = 0;
        uVar7 = puVar2[1];
        uVar8 = uVar5;
        do {
          uVar1 = uVar7 + puVar3[~uVar6 + uVar5 + 1];
          uVar7 = uVar1 >> 0x10;
          *(short *)(param_3 + (~uVar6 + uVar5) * 2) = (short)uVar1;
          uVar6 = uVar6 + 1;
          uVar8 = uVar8 - 1;
        } while (uVar8 != 0);
      }
      if (*(ulong *)(param_1 + 10) < uVar5) {
                    /* WARNING: Subroutine does not return */
        FUN_183c19214("cmap_bf_set_get_unichars",0xf2,
                      "/Library/Caches/com.apple.xbs/418A84E5-A935-45BB-BEF3-31726BD24C5D/TemporaryDirectory.myKecQ/Sources/CoreGraphics/CoreGraphicsRIP/CMaps/cmap-bf-set.cpp"
                      ,"n <= set->max_unichar_length","n (%lu) overflowed unichar length (%lu)");
      }
      return uVar5;
    }
  }
  return 0;
}



/* ==== _get_used_cmap @ 183c5c0fc size=4 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * _get_used_cmap(undefined8 param_1)

{
  bool bVar1;
  undefined1 uVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  long lVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined4 *puVar11;
  long lVar12;
  undefined1 *puVar13;
  undefined4 *puVar14;
  long lVar15;
  ushort *puVar16;
  uint uVar17;
  long lVar18;
  undefined8 uVar19;
  long lVar20;
  long *plVar21;
  ulong uVar22;
  uint uStack_64;
  
  lVar18 = 0;
  lVar20 = 5;
  while (lVar8 = func_0x00018813a700(param_1,(&DAT_1e05ac3c8)[lVar18 * 2],
                                     *(undefined8 *)(&DAT_1e05ac3d0)[lVar18 * 2],0x20,
                                     _CMapEntry_compare), lVar8 == 0) {
    lVar18 = lVar18 + 1;
    lVar20 = lVar20 + -1;
    if (lVar20 == 0) {
      return (undefined4 *)0x0;
    }
  }
  uVar19 = *_DAT_1e00fe6c0;
  lVar18 = func_0x000188140a90(0,*(undefined8 *)(lVar8 + 0x10),*(undefined8 *)(lVar8 + 0x18),uVar19)
  ;
  if (lVar18 != 0) {
    uVar9 = func_0x000188140aa0(lVar18);
    uVar10 = func_0x000188140ab0(lVar18);
    lVar20 = func_0x00018814c610(0,uVar9,uVar10,uVar19);
    if (lVar20 != 0) {
      func_0x0001881411e0();
      puVar11 = (undefined4 *)func_0x000188138460(1,0x38,0x10300405646078b);
      if (puVar11 != (undefined4 *)0x0) {
        *puVar11 = 1;
        *(undefined1 *)((long)puVar11 + 0x29) = 0;
        uVar19 = _read_string(lVar20);
        *(undefined8 *)(puVar11 + 2) = uVar19;
        uVar19 = _read_string(lVar20);
        *(undefined8 *)(puVar11 + 4) = uVar19;
        uStack_64 = uStack_64 & 0xffffff00;
        lVar12 = func_0x0001881411f0(lVar20,&uStack_64,1);
        uVar17 = 0;
        if (lVar12 != 0) {
          uVar17 = uStack_64 & 0xff;
        }
        puVar11[6] = uVar17;
        uStack_64 = uStack_64 & 0xffffff00;
        lVar12 = func_0x0001881411f0(lVar20,&uStack_64,1);
        *(bool *)(puVar11 + 10) = (char)uStack_64 != '\0' && lVar12 != 0;
        if ((char)uStack_64 == '\0' || lVar12 == 0) {
          uStack_64 = 0;
          lVar12 = func_0x0001881411f0(lVar20,&uStack_64,4);
          uVar17 = (uStack_64 & 0xff00ff00) >> 8 | (uStack_64 & 0xff00ff) << 8;
          uVar22 = 0;
          if (lVar12 != 0) {
            uVar22 = (ulong)(uVar17 >> 0x10 | uVar17 << 0x10);
          }
          puVar13 = (undefined1 *)func_0x000188138460(1,0x18,0x10200404be0e0e6);
          if (puVar13 != (undefined1 *)0x0) {
            uStack_64 = uStack_64 & 0xffffff00;
            lVar12 = func_0x0001881411f0(lVar20,&uStack_64,1);
            uVar2 = 0;
            if (lVar12 != 0) {
              uVar2 = (undefined1)uStack_64;
            }
            *puVar13 = uVar2;
            uStack_64 = uStack_64 & 0xffffff00;
            lVar12 = func_0x0001881411f0(lVar20,&uStack_64,1);
            uVar2 = 0;
            if (lVar12 != 0) {
              uVar2 = (undefined1)uStack_64;
            }
            puVar13[1] = uVar2;
            if (uVar22 != 0) {
              lVar12 = func_0x0001881404d0(0,uVar22,0);
              *(long *)(puVar13 + 8) = lVar12;
              if (lVar12 == 0) {
                _cmap_csr_set_release(puVar13);
                puVar13 = (undefined1 *)0x0;
              }
              else {
                do {
                  uStack_64 = uStack_64 & 0xffffff00;
                  lVar12 = func_0x0001881411f0(lVar20,&uStack_64,1);
                  uVar17 = 0;
                  if (lVar12 != 0) {
                    uVar17 = uStack_64 & 0xff;
                  }
                  uStack_64 = 0;
                  lVar12 = func_0x0001881411f0(lVar20,&uStack_64,4);
                  uVar4 = (uStack_64 & 0xff00ff00) >> 8 | (uStack_64 & 0xff00ff) << 8;
                  uVar6 = 0;
                  if (lVar12 != 0) {
                    uVar6 = uVar4 >> 0x10 | uVar4 << 0x10;
                  }
                  uStack_64 = 0;
                  lVar12 = func_0x0001881411f0(lVar20,&uStack_64,4);
                  uVar5 = (uStack_64 & 0xff00ff00) >> 8 | (uStack_64 & 0xff00ff) << 8;
                  uVar4 = 0;
                  if (lVar12 != 0) {
                    uVar4 = uVar5 >> 0x10 | uVar5 << 0x10;
                  }
                  lVar12 = _csr_create(uVar17,uVar6,uVar4);
                  uVar19 = _cmap_cid_set_create_with_stream(lVar20);
                  *(undefined8 *)(lVar12 + 0x18) = uVar19;
                  uVar19 = _cmap_cid_set_create_with_stream(lVar20);
                  *(undefined8 *)(lVar12 + 0x10) = uVar19;
                  func_0x0001881404a0(*(undefined8 *)(puVar13 + 8),lVar12);
                  uVar22 = uVar22 - 1;
                } while (uVar22 != 0);
                uStack_64 = 0;
                lVar12 = func_0x0001881411f0(lVar20,&uStack_64,4);
                uVar17 = uStack_64;
                puVar14 = (undefined4 *)0x0;
                if ((lVar12 != 0) && (uStack_64 != 0)) {
                  puVar14 = (undefined4 *)func_0x00018814d110(0x58,0x10b0c40a89e18dc);
                  *puVar14 = 0;
                  plVar21 = (long *)(puVar14 + 2);
                  *(undefined8 *)(puVar14 + 4) = 0;
                  *plVar21 = 0;
                  *(undefined8 *)(puVar14 + 8) = 0;
                  *(undefined8 *)(puVar14 + 6) = 0;
                  *(undefined8 *)(puVar14 + 0xc) = 0;
                  *(undefined8 *)(puVar14 + 10) = 0;
                  *(undefined8 *)(puVar14 + 0x10) = 0;
                  *(undefined8 *)(puVar14 + 0xe) = 0;
                  *(undefined8 *)(puVar14 + 0x12) = 0;
                  puVar14[0x14] = 0x3f800000;
                  uStack_64 = 0;
                  lVar12 = func_0x0001881411f0(lVar20,&uStack_64,4);
                  uVar6 = (uStack_64 & 0xff00ff00) >> 8 | (uStack_64 & 0xff00ff) << 8;
                  iVar7 = 1;
                  if (lVar12 != 0) {
                    iVar7 = (uVar6 >> 0x10 | uVar6 << 0x10) + 1;
                  }
                  iVar7 = __ZL13grow_code_mapP11cmap_bf_setj(puVar14,iVar7);
                  if (iVar7 == 0) {
LAB_183dc3368:
                    _cmap_bf_set_release(puVar14);
                    puVar14 = (undefined4 *)0x0;
                  }
                  else {
                    uVar17 = (uVar17 & 0xff00ff00) >> 8 | (uVar17 & 0xff00ff) << 8;
                    uVar17 = uVar17 >> 0x10 | uVar17 << 0x10;
                    if (uVar17 < 2) {
                      uVar17 = 1;
                    }
                    do {
                      uStack_64 = uStack_64 & 0xffff0000;
                      lVar12 = func_0x0001881411f0(lVar20,&uStack_64,2);
                      uVar5 = uStack_64 >> 8;
                      uVar4 = uStack_64 & 0xff;
                      uStack_64 = uStack_64 & 0xffff0000;
                      lVar15 = func_0x0001881411f0(lVar20,&uStack_64,2);
                      uVar6 = 0;
                      if (lVar15 != 0) {
                        uVar6 = uStack_64 >> 8 & 0xff | (uStack_64 & 0xff) << 8;
                      }
                      uVar22 = 0;
                      if (lVar12 != 0) {
                        uVar22 = (ulong)(uVar5 & 0xff | uVar4 << 8);
                      }
                      *(uint *)(*plVar21 + uVar22 * 8 + 4) = uVar6;
                      uStack_64 = 0;
                      lVar12 = func_0x0001881411f0(lVar20,&uStack_64,4);
                      uVar4 = (uStack_64 & 0xff00ff00) >> 8 | (uStack_64 & 0xff00ff) << 8;
                      uVar6 = 0;
                      if (lVar12 != 0) {
                        uVar6 = uVar4 >> 0x10 | uVar4 << 0x10;
                      }
                      *(uint *)(*plVar21 + uVar22 * 8) = uVar6;
                      uVar17 = uVar17 - 1;
                    } while (uVar17 != 0);
                    uStack_64 = uStack_64 & 0xffff0000;
                    lVar12 = func_0x0001881411f0(lVar20,&uStack_64,2);
                    uVar22 = 0;
                    if (lVar12 != 0) {
                      uVar22 = (ulong)(uStack_64 >> 8 & 0xff | (uStack_64 & 0xff) << 8);
                    }
                    *(ulong *)(puVar14 + 10) = uVar22;
                    uStack_64 = 0;
                    lVar12 = func_0x0001881411f0(lVar20,&uStack_64,4);
                    if ((lVar12 != 0) && (uStack_64 != 0)) {
                      uVar17 = (uStack_64 & 0xff00ff00) >> 8 | (uStack_64 & 0xff00ff) << 8;
                      uVar22 = (ulong)(uVar17 >> 0x10 | uVar17 << 0x10);
                      puVar16 = (ushort *)func_0x000188138470(uVar22 << 1,0x1000040bdfb0063);
                      *(ushort **)(puVar14 + 8) = puVar16;
                      if (puVar16 == (ushort *)0x0) goto LAB_183dc3368;
                      *(ulong *)(puVar14 + 4) = uVar22;
                      *(ulong *)(puVar14 + 6) = uVar22;
                      uVar22 = 1;
                      do {
                        uStack_64 = uStack_64 & 0xffff0000;
                        lVar12 = func_0x0001881411f0(lVar20,&uStack_64,2);
                        uVar3 = 0;
                        if (lVar12 != 0) {
                          uVar3 = (ushort)uStack_64 >> 8 | (ushort)uStack_64 << 8;
                        }
                        *puVar16 = uVar3;
                        bVar1 = uVar22 < *(ulong *)(puVar14 + 6);
                        puVar16 = puVar16 + 1;
                        uVar22 = (ulong)((int)uVar22 + 1);
                      } while (bVar1);
                    }
                  }
                }
                *(undefined4 **)(puVar13 + 0x10) = puVar14;
              }
            }
          }
          *(undefined1 **)(puVar11 + 0xc) = puVar13;
        }
      }
      func_0x000188141140(lVar20);
      func_0x000188141240(lVar20);
      goto LAB_183dc338c;
    }
  }
  puVar11 = (undefined4 *)0x0;
LAB_183dc338c:
  func_0x000188141240(lVar18);
  if (*(long *)(lVar8 + 8) != 0) {
    uVar19 = _cmap_create_with_name();
    _cmap_set_used_cmap(puVar11,uVar19);
    _cmap_release(uVar19);
  }
  return puVar11;
}



/* ==== _CGPDFShadingType5Init @ 183c5c88c size=980 ==== */

undefined8 _CGPDFShadingType5Init(long param_1,long *param_2,undefined8 *param_3)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  long lVar4;
  undefined8 *puVar5;
  char *pcVar6;
  ulong uVar7;
  undefined8 uVar8;
  long lVar9;
  long lVar10;
  int local_54;
  undefined8 local_50;
  ulong local_48;
  
  if (DAT_1eb0579e0 != -1) {
    func_0x00018813aad0(&DAT_1eb0579e0,&DAT_1e222f4e8);
  }
  lVar2 = _pdf_create_cftype(DAT_1eb0579d8,0x68);
  if (lVar2 == 0) {
    return 0;
  }
  local_50 = 0;
  local_48 = 0;
  local_54 = 0;
  *param_2 = lVar2;
  param_3[1] = 0x8010000003c5cd80;
  *param_3 = 0x8010000003c5cc60;
  if (param_1 == 0) {
    uVar8 = 0;
  }
  else {
    uVar8 = *(undefined8 *)(param_1 + 0x18);
  }
  uVar3 = FUN_183bd6c4c(uVar8,"BitsPerCoordinate",&local_48);
  if ((uVar3 & 1) == 0) {
    pcVar6 = "missing or invalid shading `BitsPerCoordinate\' value.";
    goto LAB_183c5cbec;
  }
  if ((0x20 < local_48) || ((1L << (local_48 & 0x3f) & 0x101011116U) == 0)) {
    pcVar6 = "invalid shading `BitsPerCoordinate\' value.";
    goto LAB_183c5cbec;
  }
  *(ulong *)(lVar2 + 0x18) = local_48;
  uVar3 = FUN_183bd6c4c(uVar8,"BitsPerComponent",&local_48);
  if ((uVar3 & 1) == 0) {
    pcVar6 = "missing or invalid shading `BitsPerComponent\' value.";
    goto LAB_183c5cbec;
  }
  if ((0x10 < local_48) || ((1L << (local_48 & 0x3f) & 0x11116U) == 0)) {
    pcVar6 = "invalid shading `BitsPerComponent\' value.";
    goto LAB_183c5cbec;
  }
  *(ulong *)(lVar2 + 0x20) = local_48;
  uVar3 = FUN_183bd6c4c(uVar8,"VerticesPerRow",&local_48);
  if ((uVar3 & 1) == 0) {
    pcVar6 = "missing or invalid shading `VerticesPerRow\' value.";
    goto LAB_183c5cbec;
  }
  if (local_48 + 0xffc0000000000000 < 0xffc0000000000002) {
    pcVar6 = "invalid shading `VerticesPerRow\' value.";
    goto LAB_183c5cbec;
  }
  *(ulong *)(lVar2 + 0x28) = local_48;
  *(undefined8 *)(lVar2 + 0x58) = 0;
  iVar1 = FUN_183bcf4b0(uVar8,"Function",&local_50);
  if (iVar1 != 0) {
    lVar4 = _CGPDFShadingCreateShadingFunction(local_50,1);
    *(long *)(lVar2 + 0x58) = lVar4;
    if (lVar4 == 0) {
      return 0;
    }
  }
  if (param_1 == 0) {
    lVar4 = *(long *)(lVar2 + 0x58);
    if (lVar4 != 0) {
      uVar3 = 0;
      lVar9 = 0;
      goto LAB_183c5cab4;
    }
    lVar10 = 0;
    *(undefined8 *)(lVar2 + 0x10) = 0;
  }
  else {
    lVar9 = *(long *)(param_1 + 0x28);
    lVar4 = *(long *)(lVar2 + 0x58);
    if (lVar4 != 0) {
      if (lVar9 == 0) {
        uVar3 = 0;
LAB_183c5cab4:
        uVar7 = *(ulong *)(lVar4 + 0x30);
      }
      else {
        lVar4 = func_0x000188140d60(lVar9);
        if (DAT_1edf367a0 != -1) {
          func_0x00018813aad0(&DAT_1edf367a0,&DAT_1e22309c8);
        }
        if ((lVar4 == DAT_1edf36a20) && (*(int *)(*(long *)(lVar9 + 0x18) + 0x18) == 7)) {
          pcVar6 = "invalid shading `ColorSpace\' value.";
          goto LAB_183c5cbec;
        }
        uVar3 = *(ulong *)(*(long *)(lVar9 + 0x18) + 0x30);
        lVar4 = *(long *)(lVar2 + 0x58);
        if (lVar4 != 0) goto LAB_183c5cab4;
        uVar7 = 0;
      }
      if ((4 < uVar3) || (uVar7 != uVar3)) {
        pcVar6 = 
        "CG-SEC-187882049: invalid function for type 5 shading (range dimension does not match color space)."
        ;
        goto LAB_183c5cbec;
      }
    }
    if (lVar9 == 0) {
      *(undefined8 *)(lVar2 + 0x10) = 0;
      lVar10 = 2;
      if (lVar4 == 0) {
        lVar10 = 0;
      }
    }
    else {
      func_0x000188141250(lVar9);
      *(long *)(lVar2 + 0x10) = lVar9;
      lVar10 = 2;
      if ((*(long *)(lVar2 + 0x58) == 0) && (lVar10 = 0, lVar9 != 0)) {
        lVar10 = *(long *)(*(long *)(lVar9 + 0x18) + 0x30) << 1;
      }
    }
  }
  puVar5 = (undefined8 *)func_0x000188138470((lVar10 + 4) * 8,0x100004000313f17);
  func_0x000188142e40(puVar5,"CGPDFNamedAlloc_Graphics");
  if (puVar5 == (undefined8 *)0x0) {
    return 0;
  }
  uVar3 = FUN_183bd5f94(uVar8,"Decode",puVar5,lVar10 + 4);
  if ((uVar3 & 1) == 0) {
    _pdf_error("missing or invalid shading `Decode\' value.");
    func_0x000188138390(puVar5);
    return 0;
  }
  *(undefined8 *)(lVar2 + 0x30) = *puVar5;
  *(undefined8 *)(lVar2 + 0x40) = puVar5[1];
  *(undefined8 *)(lVar2 + 0x38) = puVar5[2];
  *(undefined8 *)(lVar2 + 0x48) = puVar5[3];
  func_0x0001881384e0(puVar5,puVar5 + 4,lVar10 << 3);
  *(undefined8 **)(lVar2 + 0x50) = puVar5;
  if (param_1 == 0) {
    uVar8 = 0;
  }
  else {
    uVar8 = *(undefined8 *)(param_1 + 0x20);
  }
  lVar4 = FUN_183ca244c(uVar8,0,0,&local_54);
  *(long *)(lVar2 + 0x60) = lVar4;
  if (lVar4 == 0) {
    return 0;
  }
  if (local_54 == 0) {
    return 1;
  }
  pcVar6 = "invalid shading data format.";
LAB_183c5cbec:
  _pdf_error(pcVar6);
  return 0;
}



/* ==== _cmap_csr_set_release @ 183c78938 size=160 ==== */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Possible PIC construction at 0x000183c78990: Changing call to branch */
/* WARNING: Removing unreachable block (ram,0x000183c78994) */

void _cmap_csr_set_release(long param_1)

{
  code *pcVar1;
  long lVar2;
  ulong unaff_x30;
  
  if (param_1 == 0) {
    return;
  }
  if (*(long *)(param_1 + 8) != 0) {
    lVar2 = func_0x0001881404e0();
    if (lVar2 != 0) {
      lVar2 = func_0x000188140510(*(undefined8 *)(param_1 + 8),0);
      _cmap_cid_set_release(*(undefined8 *)(lVar2 + 0x10));
      _cmap_cid_set_release(*(undefined8 *)(lVar2 + 0x18));
      halt_baddata();
    }
    func_0x000188141240(*(undefined8 *)(param_1 + 8));
  }
  _cmap_bf_set_release(*(undefined8 *)(param_1 + 0x10));
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0xc471,0x183c789d0);
  (*pcVar1)();
}



/* ==== _cmap_bf_set_release @ 183ce7910 size=132 ==== */

/* WARNING: Control flow encountered bad instruction data */

void _cmap_bf_set_release(long param_1)

{
  code *pcVar1;
  long *plVar2;
  long lVar3;
  ulong unaff_x30;
  
  if (param_1 == 0) {
    return;
  }
  func_0x000188138390(*(undefined8 *)(param_1 + 8));
  func_0x000188138390(*(undefined8 *)(param_1 + 0x20));
  plVar2 = *(long **)(param_1 + 0x40);
  while (plVar2 != (long *)0x0) {
    plVar2 = (long *)*plVar2;
    func_0x00018814d0d0();
  }
  lVar3 = *(long *)(param_1 + 0x30);
  *(undefined8 *)(param_1 + 0x30) = 0;
  if (lVar3 != 0) {
    func_0x00018814d0d0();
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0xc471,0x183ce798c);
  (*pcVar1)();
}



/* ==== _cmap_create_with_name @ 183dc2e9c size=1344 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * _cmap_create_with_name(undefined8 param_1)

{
  bool bVar1;
  undefined1 uVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  long lVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined4 *puVar11;
  long lVar12;
  undefined1 *puVar13;
  undefined4 *puVar14;
  long lVar15;
  ushort *puVar16;
  uint uVar17;
  long lVar18;
  undefined8 uVar19;
  long lVar20;
  long *plVar21;
  ulong uVar22;
  uint local_64;
  
  lVar18 = 0;
  lVar20 = 5;
  while (lVar8 = func_0x00018813a700(param_1,(&DAT_1e05ac3c8)[lVar18 * 2],
                                     *(undefined8 *)(&DAT_1e05ac3d0)[lVar18 * 2],0x20,
                                     _CMapEntry_compare), lVar8 == 0) {
    lVar18 = lVar18 + 1;
    lVar20 = lVar20 + -1;
    if (lVar20 == 0) {
      return (undefined4 *)0x0;
    }
  }
  uVar19 = *_DAT_1e00fe6c0;
  lVar18 = func_0x000188140a90(0,*(undefined8 *)(lVar8 + 0x10),*(undefined8 *)(lVar8 + 0x18),uVar19)
  ;
  if (lVar18 != 0) {
    uVar9 = func_0x000188140aa0(lVar18);
    uVar10 = func_0x000188140ab0(lVar18);
    lVar20 = func_0x00018814c610(0,uVar9,uVar10,uVar19);
    if (lVar20 != 0) {
      func_0x0001881411e0();
      puVar11 = (undefined4 *)func_0x000188138460(1,0x38,0x10300405646078b);
      if (puVar11 != (undefined4 *)0x0) {
        *puVar11 = 1;
        *(undefined1 *)((long)puVar11 + 0x29) = 0;
        uVar19 = _read_string(lVar20);
        *(undefined8 *)(puVar11 + 2) = uVar19;
        uVar19 = _read_string(lVar20);
        *(undefined8 *)(puVar11 + 4) = uVar19;
        local_64 = local_64 & 0xffffff00;
        lVar12 = func_0x0001881411f0(lVar20,&local_64,1);
        uVar17 = 0;
        if (lVar12 != 0) {
          uVar17 = local_64 & 0xff;
        }
        puVar11[6] = uVar17;
        local_64 = local_64 & 0xffffff00;
        lVar12 = func_0x0001881411f0(lVar20,&local_64,1);
        *(bool *)(puVar11 + 10) = (char)local_64 != '\0' && lVar12 != 0;
        if ((char)local_64 == '\0' || lVar12 == 0) {
          local_64 = 0;
          lVar12 = func_0x0001881411f0(lVar20,&local_64,4);
          uVar17 = (local_64 & 0xff00ff00) >> 8 | (local_64 & 0xff00ff) << 8;
          uVar22 = 0;
          if (lVar12 != 0) {
            uVar22 = (ulong)(uVar17 >> 0x10 | uVar17 << 0x10);
          }
          puVar13 = (undefined1 *)func_0x000188138460(1,0x18,0x10200404be0e0e6);
          if (puVar13 != (undefined1 *)0x0) {
            local_64 = local_64 & 0xffffff00;
            lVar12 = func_0x0001881411f0(lVar20,&local_64,1);
            uVar2 = 0;
            if (lVar12 != 0) {
              uVar2 = (undefined1)local_64;
            }
            *puVar13 = uVar2;
            local_64 = local_64 & 0xffffff00;
            lVar12 = func_0x0001881411f0(lVar20,&local_64,1);
            uVar2 = 0;
            if (lVar12 != 0) {
              uVar2 = (undefined1)local_64;
            }
            puVar13[1] = uVar2;
            if (uVar22 != 0) {
              lVar12 = func_0x0001881404d0(0,uVar22,0);
              *(long *)(puVar13 + 8) = lVar12;
              if (lVar12 == 0) {
                _cmap_csr_set_release(puVar13);
                puVar13 = (undefined1 *)0x0;
              }
              else {
                do {
                  local_64 = local_64 & 0xffffff00;
                  lVar12 = func_0x0001881411f0(lVar20,&local_64,1);
                  uVar17 = 0;
                  if (lVar12 != 0) {
                    uVar17 = local_64 & 0xff;
                  }
                  local_64 = 0;
                  lVar12 = func_0x0001881411f0(lVar20,&local_64,4);
                  uVar4 = (local_64 & 0xff00ff00) >> 8 | (local_64 & 0xff00ff) << 8;
                  uVar6 = 0;
                  if (lVar12 != 0) {
                    uVar6 = uVar4 >> 0x10 | uVar4 << 0x10;
                  }
                  local_64 = 0;
                  lVar12 = func_0x0001881411f0(lVar20,&local_64,4);
                  uVar5 = (local_64 & 0xff00ff00) >> 8 | (local_64 & 0xff00ff) << 8;
                  uVar4 = 0;
                  if (lVar12 != 0) {
                    uVar4 = uVar5 >> 0x10 | uVar5 << 0x10;
                  }
                  lVar12 = _csr_create(uVar17,uVar6,uVar4);
                  uVar19 = _cmap_cid_set_create_with_stream(lVar20);
                  *(undefined8 *)(lVar12 + 0x18) = uVar19;
                  uVar19 = _cmap_cid_set_create_with_stream(lVar20);
                  *(undefined8 *)(lVar12 + 0x10) = uVar19;
                  func_0x0001881404a0(*(undefined8 *)(puVar13 + 8),lVar12);
                  uVar22 = uVar22 - 1;
                } while (uVar22 != 0);
                local_64 = 0;
                lVar12 = func_0x0001881411f0(lVar20,&local_64,4);
                uVar17 = local_64;
                puVar14 = (undefined4 *)0x0;
                if ((lVar12 != 0) && (local_64 != 0)) {
                  puVar14 = (undefined4 *)func_0x00018814d110(0x58,0x10b0c40a89e18dc);
                  *puVar14 = 0;
                  plVar21 = (long *)(puVar14 + 2);
                  *(undefined8 *)(puVar14 + 4) = 0;
                  *plVar21 = 0;
                  *(undefined8 *)(puVar14 + 8) = 0;
                  *(undefined8 *)(puVar14 + 6) = 0;
                  *(undefined8 *)(puVar14 + 0xc) = 0;
                  *(undefined8 *)(puVar14 + 10) = 0;
                  *(undefined8 *)(puVar14 + 0x10) = 0;
                  *(undefined8 *)(puVar14 + 0xe) = 0;
                  *(undefined8 *)(puVar14 + 0x12) = 0;
                  puVar14[0x14] = 0x3f800000;
                  local_64 = 0;
                  lVar12 = func_0x0001881411f0(lVar20,&local_64,4);
                  uVar6 = (local_64 & 0xff00ff00) >> 8 | (local_64 & 0xff00ff) << 8;
                  iVar7 = 1;
                  if (lVar12 != 0) {
                    iVar7 = (uVar6 >> 0x10 | uVar6 << 0x10) + 1;
                  }
                  iVar7 = __ZL13grow_code_mapP11cmap_bf_setj(puVar14,iVar7);
                  if (iVar7 == 0) {
LAB_183dc3368:
                    _cmap_bf_set_release(puVar14);
                    puVar14 = (undefined4 *)0x0;
                  }
                  else {
                    uVar17 = (uVar17 & 0xff00ff00) >> 8 | (uVar17 & 0xff00ff) << 8;
                    uVar17 = uVar17 >> 0x10 | uVar17 << 0x10;
                    if (uVar17 < 2) {
                      uVar17 = 1;
                    }
                    do {
                      local_64 = local_64 & 0xffff0000;
                      lVar12 = func_0x0001881411f0(lVar20,&local_64,2);
                      uVar5 = local_64 >> 8;
                      uVar4 = local_64 & 0xff;
                      local_64 = local_64 & 0xffff0000;
                      lVar15 = func_0x0001881411f0(lVar20,&local_64,2);
                      uVar6 = 0;
                      if (lVar15 != 0) {
                        uVar6 = local_64 >> 8 & 0xff | (local_64 & 0xff) << 8;
                      }
                      uVar22 = 0;
                      if (lVar12 != 0) {
                        uVar22 = (ulong)(uVar5 & 0xff | uVar4 << 8);
                      }
                      *(uint *)(*plVar21 + uVar22 * 8 + 4) = uVar6;
                      local_64 = 0;
                      lVar12 = func_0x0001881411f0(lVar20,&local_64,4);
                      uVar4 = (local_64 & 0xff00ff00) >> 8 | (local_64 & 0xff00ff) << 8;
                      uVar6 = 0;
                      if (lVar12 != 0) {
                        uVar6 = uVar4 >> 0x10 | uVar4 << 0x10;
                      }
                      *(uint *)(*plVar21 + uVar22 * 8) = uVar6;
                      uVar17 = uVar17 - 1;
                    } while (uVar17 != 0);
                    local_64 = local_64 & 0xffff0000;
                    lVar12 = func_0x0001881411f0(lVar20,&local_64,2);
                    uVar22 = 0;
                    if (lVar12 != 0) {
                      uVar22 = (ulong)(local_64 >> 8 & 0xff | (local_64 & 0xff) << 8);
                    }
                    *(ulong *)(puVar14 + 10) = uVar22;
                    local_64 = 0;
                    lVar12 = func_0x0001881411f0(lVar20,&local_64,4);
                    if ((lVar12 != 0) && (local_64 != 0)) {
                      uVar17 = (local_64 & 0xff00ff00) >> 8 | (local_64 & 0xff00ff) << 8;
                      uVar22 = (ulong)(uVar17 >> 0x10 | uVar17 << 0x10);
                      puVar16 = (ushort *)func_0x000188138470(uVar22 << 1,0x1000040bdfb0063);
                      *(ushort **)(puVar14 + 8) = puVar16;
                      if (puVar16 == (ushort *)0x0) goto LAB_183dc3368;
                      *(ulong *)(puVar14 + 4) = uVar22;
                      *(ulong *)(puVar14 + 6) = uVar22;
                      uVar22 = 1;
                      do {
                        local_64 = local_64 & 0xffff0000;
                        lVar12 = func_0x0001881411f0(lVar20,&local_64,2);
                        uVar3 = 0;
                        if (lVar12 != 0) {
                          uVar3 = (ushort)local_64 >> 8 | (ushort)local_64 << 8;
                        }
                        *puVar16 = uVar3;
                        bVar1 = uVar22 < *(ulong *)(puVar14 + 6);
                        puVar16 = puVar16 + 1;
                        uVar22 = (ulong)((int)uVar22 + 1);
                      } while (bVar1);
                    }
                  }
                }
                *(undefined4 **)(puVar13 + 0x10) = puVar14;
              }
            }
          }
          *(undefined1 **)(puVar11 + 0xc) = puVar13;
        }
      }
      func_0x000188141140(lVar20);
      func_0x000188141240(lVar20);
      goto LAB_183dc338c;
    }
  }
  puVar11 = (undefined4 *)0x0;
LAB_183dc338c:
  func_0x000188141240(lVar18);
  if (*(long *)(lVar8 + 8) != 0) {
    uVar19 = _cmap_create_with_name();
    _cmap_set_used_cmap(puVar11,uVar19);
    _cmap_release(uVar19);
  }
  return puVar11;
}



/* ==== _CMapEntry_compare @ 183dc33dc size=8 ==== */

/* WARNING: Control flow encountered bad instruction data */

void _CMapEntry_compare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* ==== _cmap_yy_create_buffer @ 183e18f80 size=132 ==== */

ulong _cmap_yy_create_buffer(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  ulong uVar2;
  long lVar3;
  ulong uVar4;
  long lVar5;
  long lVar6;
  int iVar7;
  byte *pbVar8;
  
  uVar2 = func_0x000188138470(0x48,0x4adc8ba7);
  if (uVar2 != 0) {
    *(undefined8 *)(uVar2 + 0x18) = 0x4000;
    lVar3 = func_0x000188138470(0x4002,0x4adc8ba7);
    *(long *)(uVar2 + 8) = lVar3;
    if (lVar3 != 0) {
      *(undefined4 *)(uVar2 + 0x28) = 1;
      _cmap_yy_init_buffer(uVar2,param_1,param_2);
      return uVar2;
    }
  }
  lVar3 = _fatal_scanner_error();
  uVar2 = (ulong)*(uint *)(lVar3 + 0x54);
  pbVar8 = *(byte **)(lVar3 + 0x88);
  if (pbVar8 < *(byte **)(lVar3 + 0x48)) {
    do {
      if ((ulong)*pbVar8 == 0) {
        uVar4 = 2;
      }
      else {
        uVar4 = (ulong)(byte)_yy_ec[*pbVar8];
      }
      iVar7 = (int)uVar2;
      if (*(short *)(_yy_accept + (long)iVar7 * 2) != 0) {
        *(int *)(lVar3 + 0x70) = iVar7;
        *(byte **)(lVar3 + 0x78) = pbVar8;
      }
      lVar5 = (long)iVar7;
      lVar6 = (long)*(short *)(lVar5 * 2 + 0x1841d7e9a) + uVar4;
      if (iVar7 != *(short *)(lVar6 * 2 + 0x1841d7bfa)) {
        do {
          lVar1 = lVar5 * 2;
          lVar5 = (long)*(short *)(_yy_def + lVar1);
          if (0xfc < lVar5) {
            uVar4 = (ulong)(byte)_yy_meta[uVar4];
          }
          lVar6 = (long)*(short *)(lVar5 * 2 + 0x1841d7e9a) + uVar4;
        } while (*(short *)(lVar6 * 2 + 0x1841d7bfa) != *(short *)(_yy_def + lVar1));
      }
      uVar2 = (ulong)*(short *)(lVar6 * 2 + 0x1841d82d2);
      pbVar8 = pbVar8 + 1;
    } while (pbVar8 != *(byte **)(lVar3 + 0x48));
  }
  return uVar2;
}



/* ==== _cmap_yy_init_buffer @ 183e190c8 size=220 ==== */

void _cmap_yy_init_buffer(undefined8 *param_1,undefined8 param_2,long param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  long lVar3;
  undefined8 *puVar4;
  undefined1 *puVar5;
  
  puVar2 = (undefined4 *)func_0x000188138110();
  uVar1 = *puVar2;
  param_1[4] = 0;
  *(undefined1 *)param_1[1] = 0;
  *(undefined1 *)(param_1[1] + 1) = 0;
  param_1[2] = param_1[1];
  *(undefined4 *)(param_1 + 6) = 1;
  *(undefined4 *)(param_1 + 8) = 0;
  lVar3 = *(long *)(param_3 + 0x28);
  if (lVar3 == 0) {
    *param_1 = param_2;
    *(undefined4 *)((long)param_1 + 0x3c) = 1;
  }
  else {
    puVar4 = *(undefined8 **)(lVar3 + *(long *)(param_3 + 0x18) * 8);
    if (param_1 == puVar4) {
      *(undefined8 *)(param_3 + 0x38) = puVar4[4];
      puVar5 = (undefined1 *)puVar4[2];
      *(undefined1 **)(param_3 + 0x48) = puVar5;
      *(undefined1 **)(param_3 + 0x88) = puVar5;
      *(undefined8 *)(param_3 + 8) = *puVar4;
      *(undefined1 *)(param_3 + 0x30) = *puVar5;
    }
    *param_1 = param_2;
    *(undefined4 *)((long)param_1 + 0x3c) = 1;
    if (param_1 == *(undefined8 **)(lVar3 + *(long *)(param_3 + 0x18) * 8)) goto LAB_183e19188;
  }
  *(undefined8 *)((long)param_1 + 0x34) = 1;
LAB_183e19188:
  *(undefined4 *)((long)param_1 + 0x2c) = 0;
  puVar2 = (undefined4 *)func_0x000188138110();
  *puVar2 = uVar1;
  return;
}



/* ==== _cmap_cid_set_release @ 183e848b0 size=68 ==== */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Possible PIC construction at 0x000183e848cc: Changing call to branch */
/* WARNING: Removing unreachable block (ram,0x000183e848d0) */
/* WARNING: Removing unreachable block (ram,0x000183e848ec) */
/* WARNING: Removing unreachable block (ram,0x000183e848e8) */

void _cmap_cid_set_release(long param_1)

{
  if (param_1 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return;
}



/* ==== _cmap_cid_set_normalize @ 183e84988 size=344 ==== */

void _cmap_cid_set_normalize(byte *param_1)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  ulong uVar4;
  ulong uVar5;
  long lVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  
  if (param_1[0x20] == 1) {
    func_0x00018813b900(*(undefined8 *)(param_1 + 0x18),*(undefined8 *)(param_1 + 0x10),0xc,
                        _compare_ranges);
    iVar2 = _contains_overlaps(param_1);
    if (iVar2 != 0) {
      bVar1 = *param_1;
      if (bVar1 < 5 && (1 << (ulong)(bVar1 & 0x1f) & 0x16U) != 0) {
        pbVar3 = (byte *)func_0x000188138460(1,0x28,0x10200401ae633e8);
        if (pbVar3 != (byte *)0x0) {
          *pbVar3 = bVar1;
          pbVar3[0x20] = 0;
        }
      }
      else {
        pbVar3 = (byte *)0x0;
      }
      uVar4 = *(ulong *)(param_1 + 0x10);
      if (uVar4 != 0) {
        uVar5 = 0;
        lVar6 = -1;
        do {
          _add_nonoverlapping_range(pbVar3,*(long *)(param_1 + 0x18) + (uVar4 + lVar6) * 0xc,0);
          uVar5 = uVar5 + 1;
          uVar4 = *(ulong *)(param_1 + 0x10);
          lVar6 = lVar6 + -1;
        } while (uVar5 < uVar4);
      }
      func_0x000188138390(*(undefined8 *)(param_1 + 0x18));
      uVar8 = *(undefined8 *)(pbVar3 + 8);
      uVar7 = *(undefined8 *)pbVar3;
      uVar10 = *(undefined8 *)(pbVar3 + 0x18);
      uVar9 = *(undefined8 *)(pbVar3 + 0x10);
      *(undefined8 *)(param_1 + 0x20) = *(undefined8 *)(pbVar3 + 0x20);
      *(undefined8 *)(param_1 + 8) = uVar8;
      *(undefined8 *)param_1 = uVar7;
      *(undefined8 *)(param_1 + 0x18) = uVar10;
      *(undefined8 *)(param_1 + 0x10) = uVar9;
      func_0x000188138390(pbVar3);
      iVar2 = _contains_overlaps(param_1);
      if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
        FUN_183c19214("remove_overlaps",0xcb,
                      "/Library/Caches/com.apple.xbs/418A84E5-A935-45BB-BEF3-31726BD24C5D/TemporaryDirectory.myKecQ/Sources/CoreGraphics/CoreGraphicsRIP/CMaps/cmap-cid-set.c"
                      ,"!contains_overlaps(set)","set %p contains overlaps");
      }
    }
    param_1[0x20] = 0;
  }
  return;
}



/* ==== _cmap_cid_set_find_matching_range @ 183e84ae0 size=112 ==== */

undefined8 _cmap_cid_set_find_matching_range(long param_1,undefined4 param_2,undefined8 *param_3)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  undefined4 local_24;
  
  uVar2 = 0;
  if (param_1 != 0) {
    local_24 = param_2;
    _cmap_cid_set_normalize();
    puVar1 = (undefined8 *)
             func_0x00018813a700(&local_24,*(undefined8 *)(param_1 + 0x18),
                                 *(undefined8 *)(param_1 + 0x10),0xc,_compare_code_with_range);
    uVar2 = 0;
    if (puVar1 != (undefined8 *)0x0) {
      uVar2 = *puVar1;
      *(undefined4 *)(param_3 + 1) = *(undefined4 *)(puVar1 + 1);
      *param_3 = uVar2;
      uVar2 = 1;
    }
  }
  return uVar2;
}



/* ==== _cmap_cid_set_create_with_stream @ 183e84b78 size=584 ==== */

undefined1 * _cmap_cid_set_create_with_stream(undefined8 param_1)

{
  uint uVar1;
  ushort uVar2;
  undefined1 uVar3;
  long lVar4;
  undefined1 *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  ulong uVar9;
  uint local_44;
  
  local_44 = local_44 & 0xffffff00;
  lVar4 = func_0x0001881411f0(param_1,&local_44,1);
  uVar8 = local_44;
  if (lVar4 != 0) {
    uVar3 = (undefined1)local_44;
    if (((local_44 & 0xff) != 0) &&
       (uVar6 = local_44 & 0xff,
       (local_44 & 0xff) < 5 && (1 << (ulong)(local_44 & 0x1f) & 0x16U) != 0)) {
      puVar5 = (undefined1 *)func_0x000188138460(1,0x28,0x10200401ae633e8);
      if (puVar5 == (undefined1 *)0x0) {
        return (undefined1 *)0x0;
      }
      *puVar5 = uVar3;
      puVar5[0x20] = 0;
      local_44 = 0;
      lVar4 = func_0x0001881411f0(param_1,&local_44,4);
      uVar7 = (local_44 & 0xff00ff00) >> 8 | (local_44 & 0xff00ff) << 8;
      uVar9 = 0;
      if (lVar4 != 0) {
        uVar9 = (ulong)(uVar7 >> 0x10 | uVar7 << 0x10);
      }
      *(ulong *)(puVar5 + 8) = uVar9;
      lVar4 = func_0x000188138470(uVar9 * 0xc,0x1000040cba68d63);
      *(long *)(puVar5 + 0x18) = lVar4;
      if (lVar4 != 0) {
        if (uVar9 != 0) {
          uVar8 = uVar8 & 0xff;
          if ((1 < uVar6 - 1) && (uVar8 != 4)) {
            puVar5 = (undefined1 *)func_0x000188138260();
            return puVar5;
          }
          do {
            if (uVar8 == 2) {
              local_44 = local_44 & 0xffff0000;
              lVar4 = func_0x0001881411f0(param_1,&local_44,2);
              uVar6 = 0;
              if (lVar4 != 0) {
                uVar6 = local_44 >> 8 & 0xff | (local_44 & 0xff) << 8;
              }
              local_44 = local_44 & 0xffff0000;
              lVar4 = func_0x0001881411f0(param_1,&local_44,2);
              uVar7 = local_44 >> 8 & 0xff | (local_44 & 0xff) << 8;
            }
            else if (uVar8 == 1) {
              local_44 = local_44 & 0xffffff00;
              lVar4 = func_0x0001881411f0(param_1,&local_44,1);
              uVar6 = 0;
              if (lVar4 != 0) {
                uVar6 = local_44 & 0xff;
              }
              local_44 = local_44 & 0xffffff00;
              lVar4 = func_0x0001881411f0(param_1,&local_44,1);
              uVar7 = local_44 & 0xff;
            }
            else {
              local_44 = 0;
              lVar4 = func_0x0001881411f0(param_1,&local_44,4);
              uVar7 = (local_44 & 0xff00ff00) >> 8 | (local_44 & 0xff00ff) << 8;
              uVar6 = 0;
              if (lVar4 != 0) {
                uVar6 = uVar7 >> 0x10 | uVar7 << 0x10;
              }
              local_44 = 0;
              lVar4 = func_0x0001881411f0(param_1,&local_44,4);
              uVar7 = (local_44 & 0xff00ff00) >> 8 | (local_44 & 0xff00ff) << 8;
              uVar7 = uVar7 >> 0x10 | uVar7 << 0x10;
            }
            uVar1 = 0;
            if (lVar4 != 0) {
              uVar1 = uVar7;
            }
            local_44 = local_44 & 0xffff0000;
            lVar4 = func_0x0001881411f0(param_1,&local_44,2);
            uVar2 = 0;
            if (lVar4 != 0) {
              uVar2 = (ushort)local_44 >> 8 | (ushort)local_44 << 8;
            }
            _add_range(puVar5,CONCAT44(uVar1,uVar6),uVar2);
            puVar5[0x20] = 1;
            uVar9 = uVar9 - 1;
          } while (uVar9 != 0);
        }
        puVar5[0x20] = 0;
        return puVar5;
      }
      func_0x000188138390(puVar5);
    }
  }
  return (undefined1 *)0x0;
}



/* ==== _cmap_release @ 183ed6dac size=116 ==== */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Possible PIC construction at 0x000183ed6dd8: Changing call to branch */
/* WARNING: Removing unreachable block (ram,0x000183ed6ddc) */
/* WARNING: Removing unreachable block (ram,0x000183ed6e10) */
/* WARNING: Removing unreachable block (ram,0x000183ed6e0c) */

void _cmap_release(int *param_1)

{
  int iVar1;
  
  if ((param_1 != (int *)0x0) && (iVar1 = *param_1, *param_1 = iVar1 + -1, iVar1 == 1)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return;
}



/* ==== _cmap_set_used_cmap @ 183ed6e20 size=412 ==== */

/* WARNING: Control flow encountered bad instruction data */

void _cmap_set_used_cmap(long param_1,int *param_2)

{
  code *pcVar1;
  long lVar2;
  long lVar3;
  undefined1 *puVar4;
  undefined8 uVar5;
  undefined4 *puVar6;
  long lVar7;
  uint *puVar8;
  uint uVar9;
  long lVar10;
  ulong unaff_x30;
  
  if (*(long *)(param_1 + 0x20) != 0) {
    return;
  }
  if ((param_2 == (int *)0x0) || (*(long *)(param_2 + 2) == 0)) {
    *(undefined8 *)(param_1 + 0x20) = 0;
    return;
  }
  *param_2 = *param_2 + 1;
  *(int **)(param_1 + 0x20) = param_2;
  if (*(long *)(param_1 + 0x30) != 0) {
    return;
  }
  lVar2 = _cmap_csr_set_create();
  *(long *)(param_1 + 0x30) = lVar2;
  if (lVar2 == 0) {
    return;
  }
  lVar10 = *(long *)(param_2 + 0xc);
  if (lVar10 == 0) {
    return;
  }
  lVar3 = func_0x0001881404e0(*(undefined8 *)(lVar10 + 8));
  if (lVar3 != 0) {
    lVar7 = 0;
    do {
      puVar4 = (undefined1 *)func_0x000188140510(*(undefined8 *)(lVar10 + 8),lVar7);
      _cmap_csr_set_add_codespace_range
                (lVar2,*puVar4,*(undefined4 *)(puVar4 + 4),*(undefined4 *)(puVar4 + 8));
      lVar7 = lVar7 + 1;
    } while (lVar3 != lVar7);
  }
  puVar8 = *(uint **)(lVar10 + 0x10);
  if (puVar8 == (uint *)0x0) {
    return;
  }
  puVar6 = *(undefined4 **)(lVar2 + 0x10);
  if (puVar6 == (undefined4 *)0x0) {
    puVar6 = (undefined4 *)func_0x00018814d110(0x58,0x10b0c40a89e18dc);
    *puVar6 = 0;
    *(undefined8 *)(puVar6 + 4) = 0;
    *(undefined8 *)(puVar6 + 2) = 0;
    *(undefined8 *)(puVar6 + 8) = 0;
    *(undefined8 *)(puVar6 + 6) = 0;
    *(undefined8 *)(puVar6 + 0xc) = 0;
    *(undefined8 *)(puVar6 + 10) = 0;
    *(undefined8 *)(puVar6 + 0x10) = 0;
    *(undefined8 *)(puVar6 + 0xe) = 0;
    *(undefined8 *)(puVar6 + 0x12) = 0;
    puVar6[0x14] = 0x3f800000;
    *(undefined4 **)(lVar2 + 0x10) = puVar6;
    puVar8 = *(uint **)(lVar10 + 0x10);
    if (puVar8 == (uint *)0x0) {
      lVar2 = 0;
      goto LAB_183ed6f1c;
    }
  }
  lVar2 = *(long *)(puVar8 + 10) << 1;
LAB_183ed6f1c:
  lVar2 = func_0x000188138470(lVar2,0x1000040bdfb0063);
  if (lVar2 == 0) {
    return;
  }
  if (*puVar8 != 0) {
    uVar9 = 0;
    do {
      uVar5 = _cmap_bf_set_get_unichars(puVar8,uVar9 & 0xffff,lVar2);
      _cmap_bf_set_add_range(puVar6,uVar9,uVar9,uVar5,lVar2);
      uVar9 = uVar9 + 1;
    } while (uVar9 < *puVar8);
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0xc471,0x183ed6f9c);
  (*pcVar1)();
}



/* ==== _cmap_add_cid_range @ 183ed6fbc size=244 ==== */

void _cmap_add_cid_range(long param_1,undefined1 param_2,ulong param_3,long param_4,
                        undefined4 param_5)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  
  if (((param_1 != 0) && (iVar2 = _check_dimension(param_2,param_3,param_4), iVar2 != 0)) &&
     (pbVar3 = (byte *)_find_csr(param_1,param_2,param_3,param_4), pbVar3 != (byte *)0x0)) {
    pbVar4 = *(byte **)(pbVar3 + 0x10);
    if (pbVar4 == (byte *)0x0) {
      bVar1 = *pbVar3;
      if ((4 < bVar1 || (1 << (ulong)(bVar1 & 0x1f) & 0x16U) == 0) ||
         (pbVar4 = (byte *)func_0x000188138460(1,0x28,0x10200401ae633e8), pbVar4 == (byte *)0x0)) {
        pbVar3[0x10] = 0;
        pbVar3[0x11] = 0;
        pbVar3[0x12] = 0;
        pbVar3[0x13] = 0;
        pbVar3[0x14] = 0;
        pbVar3[0x15] = 0;
        pbVar3[0x16] = 0;
        pbVar3[0x17] = 0;
        return;
      }
      *pbVar4 = bVar1;
      pbVar4[0x20] = 0;
      *(byte **)(pbVar3 + 0x10) = pbVar4;
    }
    _add_range(pbVar4,param_3 & 0xffffffff | param_4 << 0x20,param_5);
    pbVar4[0x20] = 1;
  }
  return;
}



/* ==== _cmap_add_notdef_range @ 183ed70b0 size=244 ==== */

void _cmap_add_notdef_range
               (long param_1,undefined1 param_2,ulong param_3,long param_4,undefined4 param_5)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  
  if (((param_1 != 0) && (iVar2 = _check_dimension(param_2,param_3,param_4), iVar2 != 0)) &&
     (pbVar3 = (byte *)_find_csr(param_1,param_2,param_3,param_4), pbVar3 != (byte *)0x0)) {
    pbVar4 = *(byte **)(pbVar3 + 0x18);
    if (pbVar4 == (byte *)0x0) {
      bVar1 = *pbVar3;
      if (bVar1 < 5 && (1 << (ulong)(bVar1 & 0x1f) & 0x16U) != 0) {
        pbVar4 = (byte *)func_0x000188138460(1,0x28,0x10200401ae633e8);
        if (pbVar4 != (byte *)0x0) {
          *pbVar4 = bVar1;
          pbVar4[0x20] = 0;
        }
      }
      else {
        pbVar4 = (byte *)0x0;
      }
      *(byte **)(pbVar3 + 0x18) = pbVar4;
    }
    _add_range(pbVar4,param_3 & 0xffffffff | param_4 << 0x20,param_5);
    pbVar4[0x20] = 1;
  }
  return;
}



/* ==== _cmap_convert @ 183ed71a4 size=1072 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong _cmap_convert(long param_1,ushort *param_2,ulong param_3,ushort *param_4,ulong *param_5)

{
  bool bVar1;
  int iVar2;
  long lVar3;
  byte *pbVar4;
  byte *pbVar5;
  long lVar6;
  ulong uVar7;
  ulong uVar8;
  ulong uVar9;
  byte bVar10;
  uint uVar11;
  ulong uVar12;
  long lVar13;
  uint uVar14;
  ulong uVar15;
  ulong uVar16;
  byte *pbVar17;
  ushort uVar18;
  uint uVar19;
  long lVar20;
  byte *pbVar21;
  ushort *local_c0;
  ulong *local_b8;
  undefined8 local_a0;
  uint local_98;
  ulong local_90 [4];
  ushort local_70 [4];
  long local_68;
  
  local_68 = *_DAT_1e0186220;
  if (*(char *)(param_1 + 0x28) == '\x01') {
    uVar16 = param_3 >> 1;
    uVar9 = uVar16;
    if (1 < param_3) {
      do {
        *param_4 = *param_2 >> 8 | *param_2 << 8;
        *param_5 = 2;
        uVar9 = uVar9 - 1;
        param_4 = param_4 + 1;
        param_5 = param_5 + 1;
        param_2 = param_2 + 1;
      } while (uVar9 != 0);
    }
  }
  else {
    if (param_3 != 0) {
      uVar16 = 0;
      pbVar17 = *(byte **)(param_1 + 0x30);
      lVar6 = *(long *)(param_1 + 0x20);
      local_c0 = param_4;
      local_b8 = param_5;
LAB_183ed7248:
      uVar9 = param_3;
      if (pbVar17 != (byte *)0x0) {
        local_98 = 0;
        local_a0 = 0;
        lVar3 = func_0x0001881404e0(*(undefined8 *)(pbVar17 + 8));
        uVar15 = (ulong)*pbVar17;
        if (lVar3 != 0) {
          uVar7 = (ulong)pbVar17[1];
          uVar8 = param_3;
          if (uVar7 <= param_3) {
            uVar8 = uVar7;
          }
          if (uVar15 <= uVar8) {
LAB_183ed73b0:
            lVar20 = 0;
            uVar19 = ((uint)uVar15 & 0xff) * 8 - 8;
LAB_183ed73c8:
            pbVar5 = (byte *)func_0x000188140510(*(undefined8 *)(pbVar17 + 8),lVar20);
            bVar10 = *pbVar5;
            if (uVar15 != bVar10) goto LAB_183ed7470;
            uVar7 = 0;
            if (uVar15 != 0) {
              uVar11 = *(uint *)(pbVar5 + 4);
              uVar12 = uVar15 & 0xff;
              uVar14 = uVar19;
              do {
                *(char *)((long)local_90 + uVar7) = (char)(uVar11 >> (ulong)(uVar14 & 0x1f));
                uVar7 = uVar7 + 1;
                uVar14 = uVar14 - 8;
                uVar12 = uVar12 - 1;
              } while (uVar12 != 0);
              lVar13 = 0;
              uVar11 = *(uint *)(pbVar5 + 8);
              uVar7 = uVar15 & 0xff;
              uVar14 = uVar19;
              do {
                *(char *)((long)local_70 + lVar13) = (char)(uVar11 >> (ulong)(uVar14 & 0x1f));
                lVar13 = lVar13 + 1;
                uVar14 = uVar14 - 8;
                uVar7 = uVar7 - 1;
              } while (uVar7 != 0);
              uVar7 = 0;
              while ((*(byte *)((long)local_90 + uVar7) <= *(byte *)((long)param_2 + uVar7) &&
                     (*(byte *)((long)param_2 + uVar7) <= *(byte *)((long)local_70 + uVar7)))) {
                uVar7 = uVar7 + 1;
                if (uVar15 == uVar7) goto LAB_183ed7498;
              }
            }
            if (uVar7 != uVar15) goto LAB_183ed7470;
LAB_183ed7498:
            uVar19 = 0;
            if (bVar10 != 0) {
              lVar3 = 0;
              do {
                uVar19 = (uint)*(byte *)((long)param_2 + lVar3) | uVar19 << 8;
                lVar3 = lVar3 + 1;
                uVar15 = uVar15 - 1;
              } while (uVar15 != 0);
            }
            iVar2 = _cmap_cid_set_find_matching_range
                              (*(undefined8 *)(pbVar5 + 0x10),uVar19,&local_a0);
            if (iVar2 == 0) {
              iVar2 = _cmap_cid_set_find_matching_range
                                (*(undefined8 *)(pbVar5 + 0x18),uVar19,&local_a0);
              if (iVar2 != 0) {
                uVar19 = local_98 & 0xffff;
                goto LAB_183ed755c;
              }
              if (lVar6 == 0) goto LAB_183ed755c;
              bVar10 = *pbVar5;
              if (3 < bVar10) {
                bVar10 = 4;
              }
              lVar3 = _cmap_convert(lVar6,param_2,bVar10,local_70,local_90);
              uVar9 = local_90[0];
              uVar18 = local_70[0];
              if (lVar3 != 1) {
                _pdf_log(
                        "CG-SEC-187882136: used-cmap codespace-dimension mismatch contained (decoded %zu codes from a %zu-byte code); falling back to identity."
                        );
                goto LAB_183ed755c;
              }
            }
            else {
              uVar19 = (uVar19 + (local_98 & 0xffff)) - (int)local_a0;
LAB_183ed755c:
              uVar9 = (ulong)*pbVar5;
              uVar18 = (ushort)uVar19;
            }
            *local_c0 = uVar18;
            *local_b8 = uVar9;
            uVar16 = uVar16 + 1;
            local_c0 = local_c0 + 1;
            local_b8 = local_b8 + 1;
            goto LAB_183ed757c;
          }
        }
        goto LAB_183ed727c;
      }
      goto LAB_183ed757c;
    }
    uVar16 = 0;
  }
LAB_183ed7594:
  if (*_DAT_1e0186220 != local_68) {
    uVar16 = func_0x000188138130();
    return uVar16;
  }
  return uVar16;
LAB_183ed7470:
  lVar20 = lVar20 + 1;
  if (lVar20 == lVar3) goto code_r0x000183ed747c;
  goto LAB_183ed73c8;
code_r0x000183ed747c:
  bVar1 = uVar15 == uVar8;
  uVar15 = uVar15 + 1;
  if (bVar1) goto code_r0x000183ed748c;
  goto LAB_183ed73b0;
code_r0x000183ed748c:
  uVar15 = (ulong)*pbVar17;
LAB_183ed727c:
  if (uVar15 <= param_3) {
    lVar3 = func_0x0001881404e0(*(undefined8 *)(pbVar17 + 8));
    pbVar5 = (byte *)0x0;
    if (lVar3 != 0) {
      lVar20 = 0;
      uVar9 = 0;
      pbVar21 = (byte *)0x0;
      do {
        pbVar4 = (byte *)func_0x000188140510(*(undefined8 *)(pbVar17 + 8),lVar20);
        bVar10 = *pbVar4;
        uVar8 = (ulong)bVar10;
        pbVar5 = pbVar21;
        uVar15 = uVar9;
        if (uVar8 <= param_3) {
          if (bVar10 == 0) {
            uVar7 = 0;
          }
          else {
            lVar13 = 0;
            uVar19 = *(uint *)(pbVar4 + 4);
            uVar11 = (uint)bVar10 * 8 - 8;
            uVar7 = uVar8;
            uVar14 = uVar11;
            do {
              *(char *)((long)local_90 + lVar13) = (char)(uVar19 >> (ulong)(uVar14 & 0x1f));
              lVar13 = lVar13 + 1;
              uVar14 = uVar14 - 8;
              uVar7 = uVar7 - 1;
            } while (uVar7 != 0);
            lVar13 = 0;
            uVar19 = *(uint *)(pbVar4 + 8);
            uVar7 = uVar8;
            do {
              *(char *)((long)local_70 + lVar13) = (char)(uVar19 >> (ulong)(uVar11 & 0x1f));
              lVar13 = lVar13 + 1;
              uVar11 = uVar11 - 8;
              uVar7 = uVar7 - 1;
            } while (uVar7 != 0);
            uVar12 = 0;
            do {
              uVar7 = uVar12;
              if ((*(byte *)((long)param_2 + uVar12) < *(byte *)((long)local_90 + uVar12)) ||
                 (*(byte *)((long)local_70 + uVar12) < *(byte *)((long)param_2 + uVar12))) break;
              uVar12 = uVar12 + 1;
              uVar7 = uVar8;
            } while (uVar8 != uVar12);
          }
          if ((((uVar9 <= uVar7) && (pbVar5 = pbVar4, uVar15 = uVar7, uVar7 == uVar9)) &&
              (uVar15 = uVar9, pbVar21 != (byte *)0x0)) && (pbVar5 = pbVar21, bVar10 < *pbVar21)) {
            pbVar5 = pbVar4;
          }
        }
        lVar20 = lVar20 + 1;
        uVar9 = uVar15;
        pbVar21 = pbVar5;
      } while (lVar20 != lVar3);
    }
    pbVar21 = pbVar17 + 1;
    if (pbVar5 != (byte *)0x0) {
      pbVar21 = pbVar5;
    }
    uVar9 = (ulong)*pbVar21;
  }
LAB_183ed757c:
  param_2 = (ushort *)((long)param_2 + uVar9);
  param_3 = param_3 - uVar9;
  if (param_3 == 0) goto LAB_183ed7594;
  goto LAB_183ed7248;
}



/* ==== _lookup_glyphs_by_cmap_nonsymbolic @ 183f9afcc size=1420 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _lookup_glyphs_by_cmap_nonsymbolic(undefined8 *param_1,long param_2,undefined8 *param_3)

{
  uint uVar1;
  bool bVar2;
  int iVar3;
  ushort *puVar4;
  undefined8 uVar5;
  ushort *puVar6;
  ushort uVar7;
  uint uVar8;
  long lVar9;
  ulong extraout_x8;
  long lVar10;
  long lVar11;
  ulong uVar12;
  long extraout_x12;
  ulong uVar13;
  undefined8 *local_890;
  ushort *local_888;
  undefined2 local_87a;
  ulong local_878;
  ulong local_870 [256];
  long local_70;
  
  local_70 = *_DAT_1e0186220;
  if (*(int *)(param_1 + 1) - 1U < 7) {
    func_0x0001881384d0(local_870,(&DAT_1e05d8818)[*(int *)(param_1 + 1) - 1U],0x800);
  }
  else {
    func_0x0001881382e0(local_870,0x800);
  }
  lVar9 = param_1[4];
  if (lVar9 != 0) {
    lVar10 = 0;
    lVar11 = 0x100;
    do {
      uVar12 = *(ulong *)(lVar9 + lVar10 * 8);
      if (uVar12 != 0) {
        local_870[lVar10] = uVar12;
      }
      lVar10 = lVar10 + 1;
      lVar11 = lVar11 + -1;
    } while (lVar11 != 0);
  }
  lVar9 = 0;
  lVar10 = 0x100;
  do {
    if (local_870[lVar9] == 0) {
      local_870[lVar9] = (&DAT_1e05c1ae8)[lVar9];
    }
    lVar9 = lVar9 + 1;
    lVar10 = lVar10 + -1;
  } while (lVar10 != 0);
  puVar4 = (ushort *)func_0x000188138460(1,0x208,0x1080040036ec52c);
  *puVar4 = 0;
  if (param_2 != 0) {
    iVar3 = (**(code **)(*(long *)(param_2 + 0x10) + 0x100))
                      (*(undefined8 *)(param_2 + 0x70),3,1,puVar4);
    if (iVar3 != 0) {
      lVar9 = 0;
      bVar2 = false;
      local_890 = param_1;
      local_888 = puVar4 + 4;
      lVar10 = 0x100;
      do {
        uVar12 = local_870[lVar9];
        if (uVar12 == 0) {
          *(undefined2 *)((long)param_3 + lVar9 * 2) = 0;
        }
        else {
          lVar11 = FUN_183bf7fb8(uVar12,0,0);
          if (lVar11 == 1) {
            local_878 = local_878 & 0xffffffffffff0000;
            FUN_183bf7fb8(uVar12,0,&local_878);
            uVar8 = (uint)local_878 & 0xffff;
            if (puVar4 != (ushort *)0xffffffffffffffff) {
              if (puVar4 == (ushort *)0x0) {
                *(undefined2 *)((long)param_3 + lVar9 * 2) = 0xffff;
                goto LAB_183f9b1b0;
              }
              if (*(long *)(local_888 + (ulong)((ushort)local_878 >> 10) * 4) == 0) {
                uVar8 = (uint)*puVar4;
              }
              else {
                uVar8 = (uint)*(ushort *)
                               (*(long *)(local_888 + (ulong)((ushort)local_878 >> 10) * 4) +
                               (ulong)((ushort)local_878 & 0x3ff) * 2);
              }
            }
            *(short *)((long)param_3 + lVar9 * 2) = (short)uVar8;
            if (uVar8 != 0) goto LAB_183f9b1b0;
          }
          else {
            *(undefined2 *)((long)param_3 + lVar9 * 2) = 0;
          }
          iVar3 = func_0x0001881386b0(uVar12,".notdef");
          bVar2 = (bool)(iVar3 != 0 | bVar2);
        }
LAB_183f9b1b0:
        lVar9 = lVar9 + 1;
        lVar10 = lVar10 + -1;
      } while (lVar10 != 0);
      if ((bVar2) && (lVar9 = FUN_183bf5274(*local_890), lVar9 != 0)) {
        lVar11 = *(long *)(*(long *)(lVar9 + 0x10) + 0x30);
        lVar10 = 0;
        if (lVar11 != 0) {
          lVar11 = *(long *)(lVar11 + 0x10);
          lVar10 = 0;
          if (lVar11 != 0) {
            lVar10 = *(long *)(lVar11 + 0x28);
          }
        }
        local_890 = &local_890;
        uVar5 = (*_DAT_1e1f91910)(lVar10 << 1);
        puVar6 = (ushort *)0x0;
        if (extraout_x8 < 0x7fffffffffffffff) {
          puVar6 = (ushort *)((long)&local_890 - extraout_x12);
        }
        if (0x8000000000000021 < extraout_x8 + 0x8000000000000001) {
          puVar6 = (ushort *)func_0x000188138470(uVar5,0xa775060e);
        }
        lVar10 = 0;
        do {
          if ((((*(short *)((long)param_3 + lVar10 * 2) == 0) && (local_870[lVar10] != 0)) &&
              (iVar3 = func_0x0001881386b0(local_870[lVar10],".notdef"), iVar3 != 0)) &&
             ((lVar11 = *(long *)(*(long *)(lVar9 + 0x10) + 0x30), lVar11 != 0 &&
              (lVar11 = _cmap_bf_set_get_unichars(*(undefined8 *)(lVar11 + 0x10),lVar10,puVar6),
              lVar11 != 0)))) {
            if (puVar4 == (ushort *)0x0) {
              uVar7 = 0xffff;
            }
            else {
              uVar7 = *puVar6;
              if (puVar4 != (ushort *)0xffffffffffffffff) {
                lVar11 = *(long *)((long)local_888 + ((ulong)(uVar7 >> 7) & 0x1f8));
                if (lVar11 == 0) {
                  uVar7 = *puVar4;
                }
                else {
                  uVar7 = *(ushort *)(lVar11 + ((ulong)uVar7 & 0x3ff) * 2);
                }
              }
            }
            *(ushort *)((long)param_3 + lVar10 * 2) = uVar7;
          }
          lVar10 = lVar10 + 1;
        } while (lVar10 != 0x100);
        if (puVar6 != (ushort *)((long)&local_890 - extraout_x12)) {
          func_0x000188138390(puVar6);
        }
      }
      goto LAB_183f9b478;
    }
    iVar3 = (**(code **)(*(long *)(param_2 + 0x10) + 0x100))
                      (*(undefined8 *)(param_2 + 0x70),3,0,puVar4);
    if (iVar3 != 0) {
      uVar8 = _get_3_0_cmap_prefix(puVar4);
      lVar9 = 0;
      do {
        if (puVar4 == (ushort *)0x0) {
          uVar7 = 0xffff;
        }
        else {
          uVar1 = uVar8 | (uint)lVar9;
          uVar7 = (ushort)uVar1;
          if (puVar4 != (ushort *)0xffffffffffffffff) {
            if (*(long *)(puVar4 + (ulong)(uVar1 >> 10 & 0x3f) * 4 + 4) == 0) {
              uVar7 = *puVar4;
            }
            else {
              uVar7 = *(ushort *)
                       (*(long *)(puVar4 + (ulong)(uVar1 >> 10 & 0x3f) * 4 + 4) +
                       (ulong)(uVar1 & 0x3ff) * 2);
            }
          }
        }
        *(ushort *)((long)param_3 + lVar9 * 2) = uVar7;
        lVar9 = lVar9 + 1;
      } while (lVar9 != 0x100);
      goto LAB_183f9b478;
    }
    iVar3 = (**(code **)(*(long *)(param_2 + 0x10) + 0x100))
                      (*(undefined8 *)(param_2 + 0x70),1,0,puVar4);
    if (iVar3 != 0) {
      lVar9 = 0;
      do {
        uVar12 = local_870[lVar9];
        if (uVar12 != 0) {
          uVar13 = 0;
          do {
            iVar3 = func_0x0001881386b0(uVar12,(&DAT_1e05c2ae8)[uVar13]);
            if (iVar3 == 0) {
              if (puVar4 == (ushort *)0x0) {
                uVar13 = 0xffff;
              }
              else if (puVar4 != (ushort *)0xffffffffffffffff) {
                if (*(long *)(puVar4 + (uVar13 >> 10 & 0x3f) * 4 + 4) == 0) {
                  uVar13 = (ulong)*puVar4;
                }
                else {
                  uVar13 = (ulong)*(ushort *)
                                   (*(long *)(puVar4 + (uVar13 >> 10 & 0x3f) * 4 + 4) +
                                   (uVar13 & 0x3ff) * 2);
                }
              }
              goto LAB_183f9b3e8;
            }
            uVar13 = uVar13 + 1;
          } while (uVar13 != 0x100);
        }
        uVar13 = 0;
LAB_183f9b3e8:
        *(short *)((long)param_3 + lVar9 * 2) = (short)uVar13;
        lVar9 = lVar9 + 1;
      } while (lVar9 != 0x100);
      goto LAB_183f9b478;
    }
  }
  param_3[0x3d] = 0;
  param_3[0x3c] = 0;
  param_3[0x3f] = 0;
  param_3[0x3e] = 0;
  param_3[0x39] = 0;
  param_3[0x38] = 0;
  param_3[0x3b] = 0;
  param_3[0x3a] = 0;
  param_3[0x35] = 0;
  param_3[0x34] = 0;
  param_3[0x37] = 0;
  param_3[0x36] = 0;
  param_3[0x31] = 0;
  param_3[0x30] = 0;
  param_3[0x33] = 0;
  param_3[0x32] = 0;
  param_3[0x2d] = 0;
  param_3[0x2c] = 0;
  param_3[0x2f] = 0;
  param_3[0x2e] = 0;
  param_3[0x29] = 0;
  param_3[0x28] = 0;
  param_3[0x2b] = 0;
  param_3[0x2a] = 0;
  param_3[0x25] = 0;
  param_3[0x24] = 0;
  param_3[0x27] = 0;
  param_3[0x26] = 0;
  param_3[0x21] = 0;
  param_3[0x20] = 0;
  param_3[0x23] = 0;
  param_3[0x22] = 0;
  param_3[0x1d] = 0;
  param_3[0x1c] = 0;
  param_3[0x1f] = 0;
  param_3[0x1e] = 0;
  param_3[0x19] = 0;
  param_3[0x18] = 0;
  param_3[0x1b] = 0;
  param_3[0x1a] = 0;
  param_3[0x15] = 0;
  param_3[0x14] = 0;
  param_3[0x17] = 0;
  param_3[0x16] = 0;
  param_3[0x11] = 0;
  param_3[0x10] = 0;
  param_3[0x13] = 0;
  param_3[0x12] = 0;
  param_3[0xd] = 0;
  param_3[0xc] = 0;
  param_3[0xf] = 0;
  param_3[0xe] = 0;
  param_3[9] = 0;
  param_3[8] = 0;
  param_3[0xb] = 0;
  param_3[10] = 0;
  param_3[5] = 0;
  param_3[4] = 0;
  param_3[7] = 0;
  param_3[6] = 0;
  param_3[1] = 0;
  *param_3 = 0;
  param_3[3] = 0;
  param_3[2] = 0;
LAB_183f9b478:
  FUN_183b7cf6c(puVar4);
  lVar9 = 0;
  lVar10 = 0x100;
  do {
    if (((*(short *)((long)param_3 + lVar9 * 2) == 0) && (uVar12 = local_870[lVar9], uVar12 != 0))
       && (iVar3 = func_0x0001881386b0(uVar12,".notdef"), iVar3 != 0)) {
      local_878 = uVar12;
      local_87a = 0;
      if (param_2 != 0) {
        (**(code **)(*(long *)(param_2 + 0x10) + 0x120))
                  (*(undefined8 *)(param_2 + 0x70),&local_878,&local_87a,1);
      }
      *(undefined2 *)((long)param_3 + lVar9 * 2) = local_87a;
    }
    lVar9 = lVar9 + 1;
    lVar10 = lVar10 + -1;
  } while (lVar10 != 0);
  if (*_DAT_1e0186220 == local_70) {
    return;
  }
  func_0x000188138130();
  return;
}



/* ==== _get_3_0_cmap_prefix @ 183f9b558 size=376 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong _get_3_0_cmap_prefix(undefined8 param_1)

{
  ushort uVar1;
  long lVar2;
  long lVar3;
  ulong uVar4;
  long lVar5;
  byte bVar6;
  byte bVar8;
  long lVar7;
  long lVar9;
  long lVar10;
  long lVar11;
  long lVar12;
  long lVar13;
  long lVar14;
  long lVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  undefined8 local_470;
  undefined8 uStack_468;
  undefined8 local_458 [64];
  undefined8 local_258 [64];
  long local_58;
  
  lVar5 = 0;
  local_58 = *_DAT_1e0186220;
  uStack_468 = 0x7000600050004;
  local_470 = 0x3000200010000;
  do {
    lVar2 = 0;
    uVar1 = *(ushort *)(_get_3_0_cmap_prefix_prefix + lVar5 * 2);
    uVar4 = (ulong)uVar1;
    lVar3 = 0x100;
    uVar16 = local_470;
    uVar17 = uStack_468;
    do {
      bVar6 = (byte)uVar1;
      bVar8 = (byte)(uVar1 >> 8);
      *(ulong *)((long)local_258 + lVar2 * 2 + 8) =
           CONCAT17(bVar8 | (byte)((ulong)uVar17 >> 0x38),
                    CONCAT16(bVar6 | (byte)((ulong)uVar17 >> 0x30),
                             CONCAT15(bVar8 | (byte)((ulong)uVar17 >> 0x28),
                                      CONCAT14(bVar6 | (byte)((ulong)uVar17 >> 0x20),
                                               CONCAT13(bVar8 | (byte)((ulong)uVar17 >> 0x18),
                                                        CONCAT12(bVar6 | (byte)((ulong)uVar17 >>
                                                                               0x10),
                                                                 CONCAT11(bVar8 | (byte)((ulong)
                                                  uVar17 >> 8),bVar6 | (byte)uVar17)))))));
      *(ulong *)((long)local_258 + lVar2 * 2) =
           CONCAT17(bVar8 | (byte)((ulong)uVar16 >> 0x38),
                    CONCAT16(bVar6 | (byte)((ulong)uVar16 >> 0x30),
                             CONCAT15(bVar8 | (byte)((ulong)uVar16 >> 0x28),
                                      CONCAT14(bVar6 | (byte)((ulong)uVar16 >> 0x20),
                                               CONCAT13(bVar8 | (byte)((ulong)uVar16 >> 0x18),
                                                        CONCAT12(bVar6 | (byte)((ulong)uVar16 >>
                                                                               0x10),
                                                                 CONCAT11(bVar8 | (byte)((ulong)
                                                  uVar16 >> 8),bVar6 | (byte)uVar16)))))));
      lVar2 = lVar2 + 8;
      uVar16 = CONCAT26((short)((ulong)uVar16 >> 0x30) + 8,
                        CONCAT24((short)((ulong)uVar16 >> 0x20) + 8,
                                 CONCAT22((short)((ulong)uVar16 >> 0x10) + 8,(short)uVar16 + 8)));
      uVar17 = CONCAT26((short)((ulong)uVar17 >> 0x30) + 8,
                        CONCAT24((short)((ulong)uVar17 >> 0x20) + 8,
                                 CONCAT22((short)((ulong)uVar17 >> 0x10) + 8,(short)uVar17 + 8)));
      lVar3 = lVar3 + -8;
    } while (lVar3 != 0);
    FUN_183fd7dc0(param_1,local_258,0x100,local_458);
    lVar2 = 0;
    lVar7 = 0;
    lVar9 = 0;
    lVar3 = 0x100;
    lVar10 = 0;
    lVar11 = 0;
    lVar12 = 0;
    lVar13 = 0;
    lVar14 = 0;
    lVar15 = 0;
    do {
      uVar17 = *(undefined8 *)((long)local_458 + lVar2 * 2 + 8);
      uVar16 = *(undefined8 *)((long)local_458 + lVar2 * 2);
      lVar14 = lVar14 + (ulong)(-((short)((ulong)uVar17 >> 0x20) != 0) & 1);
      lVar15 = lVar15 + (ulong)(-(ushort)((short)((ulong)uVar17 >> 0x30) != 0) & 1);
      lVar12 = lVar12 + (ulong)(-((short)uVar17 != 0) & 1);
      lVar13 = lVar13 + (ulong)(-(ushort)((short)((ulong)uVar17 >> 0x10) != 0) & 1);
      lVar10 = lVar10 + (ulong)(-((short)((ulong)uVar16 >> 0x20) != 0) & 1);
      lVar11 = lVar11 + (ulong)(-(ushort)((short)((ulong)uVar16 >> 0x30) != 0) & 1);
      lVar7 = lVar7 + (ulong)(-((short)uVar16 != 0) & 1);
      lVar9 = lVar9 + (ulong)(-(ushort)((short)((ulong)uVar16 >> 0x10) != 0) & 1);
      lVar2 = lVar2 + 8;
      lVar3 = lVar3 + -8;
    } while (lVar3 != 0);
    if (lVar7 + lVar12 + lVar10 + lVar14 + lVar9 + lVar13 + lVar11 + lVar15 != 0)
    goto LAB_183f9b694;
    lVar5 = lVar5 + 1;
  } while (lVar5 != 4);
  uVar4 = 0;
LAB_183f9b694:
  if (*_DAT_1e0186220 == local_58) {
    return uVar4;
  }
  uVar4 = func_0x000188138130();
  return uVar4;
}



/* ==== _CGPDFCMapFinalize @ 183fe69bc size=76 ==== */

/* WARNING: Control flow encountered bad instruction data */

void _CGPDFCMapFinalize(long param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  _cmap_release(*(undefined8 *)(param_1 + 0x10));
  if (*(long *)(param_1 + 0x18) == 0) {
    return;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0x183fe69f8);
    (*pcVar1)();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* ==== _cmap_Adobe_GB1_UCS2 @ 184087ed8 size=1 ==== */

/* WARNING: Control flow encountered bad instruction data */

void _cmap_Adobe_GB1_UCS2(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* ==== _cmap_GB_EUC_H @ 1840d08cf size=1 ==== */

/* WARNING: Control flow encountered bad instruction data */

void _cmap_GB_EUC_H(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* ==== _cmap_GBKp_EUC_V @ 1840e54d8 size=8 ==== */

/* WARNING: Control flow encountered bad instruction data */

void _cmap_GBKp_EUC_V(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* ==== _cmap_UniGB_UCS2_V @ 1840f9d34 size=4 ==== */

/* WARNING: Control flow encountered bad instruction data */

void _cmap_UniGB_UCS2_V(undefined1 param_1,undefined1 *param_2)

{
  *param_2 = param_1;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* ==== _cmap_UniGB_UTF16_V @ 18410e3c0 size=4 ==== */

/* WARNING: Control flow encountered bad instruction data */

void _cmap_UniGB_UTF16_V(undefined1 param_1 [16])

{
  a64_TBL(ZEXT816(0),param_1,param_1._0_8_);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* ==== _chinese_s_cmap_table_count @ 18410e4c8 size=4 ==== */

void _chinese_s_cmap_table_count(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)UndefinedInstructionException(0xf,0x18410e4c8);
  (*pcVar1)();
}



/* ==== _cmap_Adobe_Korea1_UCS2 @ 18410f1f8 size=4 ==== */

/* WARNING: Control flow encountered bad instruction data */

void _cmap_Adobe_Korea1_UCS2(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* ==== _cmap_KSC_EUC_V @ 18413c3e0 size=16 ==== */

void _cmap_KSC_EUC_V(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)UndefinedInstructionException(0x56,0x18413c3ec);
  (*pcVar1)();
}



/* ==== _cmap_KSCms_UHC_HW_H @ 18413d4ac size=1 ==== */

/* WARNING: Control flow encountered bad instruction data */

void _cmap_KSCms_UHC_HW_H(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* ==== _cmap_KSCms_UHC_HW_V @ 18413e4d4 size=1 ==== */

/* WARNING: Control flow encountered bad instruction data */

void _cmap_KSCms_UHC_HW_V(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* ==== _cmap_KSCms_UHC_V @ 18413e580 size=12 ==== */

/* WARNING: Control flow encountered bad instruction data */

void _cmap_KSCms_UHC_V(undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
                      undefined1 param_4 [16],undefined1 *param_5)

{
  *param_5 = param_1[0];
  param_5[1] = param_2[0];
  param_5[2] = param_3[0];
  param_5[3] = param_4[0];
  param_5[4] = param_1[1];
  param_5[5] = param_2[1];
  param_5[6] = param_3[1];
  param_5[7] = param_4[1];
  param_5[8] = param_1[2];
  param_5[9] = param_2[2];
  param_5[10] = param_3[2];
  param_5[0xb] = param_4[2];
  param_5[0xc] = param_1[3];
  param_5[0xd] = param_2[3];
  param_5[0xe] = param_3[3];
  param_5[0xf] = param_4[3];
  param_5[0x10] = param_1[4];
  param_5[0x11] = param_2[4];
  param_5[0x12] = param_3[4];
  param_5[0x13] = param_4[4];
  param_5[0x14] = param_1[5];
  param_5[0x15] = param_2[5];
  param_5[0x16] = param_3[5];
  param_5[0x17] = param_4[5];
  param_5[0x18] = param_1[6];
  param_5[0x19] = param_2[6];
  param_5[0x1a] = param_3[6];
  param_5[0x1b] = param_4[6];
  param_5[0x1c] = param_1[7];
  param_5[0x1d] = param_2[7];
  param_5[0x1e] = param_3[7];
  param_5[0x1f] = param_4[7];
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* ==== _korean_cmap_table_count @ 184158210 size=4 ==== */

void _korean_cmap_table_count(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)UndefinedInstructionException(0xc,0x184158210);
  (*pcVar1)();
}



/* ==== _cmap_83pv_RKSJ_H @ 184158860 size=4 ==== */

/* WARNING: Control flow encountered bad instruction data */

void _cmap_83pv_RKSJ_H(undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
                      undefined1 param_4 [16],undefined1 *param_5)

{
  *param_5 = param_1[0];
  param_5[1] = param_2[0];
  param_5[2] = param_3[0];
  param_5[3] = param_4[0];
  param_5[4] = param_1[1];
  param_5[5] = param_2[1];
  param_5[6] = param_3[1];
  param_5[7] = param_4[1];
  param_5[8] = param_1[2];
  param_5[9] = param_2[2];
  param_5[10] = param_3[2];
  param_5[0xb] = param_4[2];
  param_5[0xc] = param_1[3];
  param_5[0xd] = param_2[3];
  param_5[0xe] = param_3[3];
  param_5[0xf] = param_4[3];
  param_5[0x10] = param_1[4];
  param_5[0x11] = param_2[4];
  param_5[0x12] = param_3[4];
  param_5[0x13] = param_4[4];
  param_5[0x14] = param_1[5];
  param_5[0x15] = param_2[5];
  param_5[0x16] = param_3[5];
  param_5[0x17] = param_4[5];
  param_5[0x18] = param_1[6];
  param_5[0x19] = param_2[6];
  param_5[0x1a] = param_3[6];
  param_5[0x1b] = param_4[6];
  param_5[0x1c] = param_1[7];
  param_5[0x1d] = param_2[7];
  param_5[0x1e] = param_3[7];
  param_5[0x1f] = param_4[7];
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* ==== _cmap_90msp_RKSJ_H @ 1841594ac size=4 ==== */

/* WARNING: Control flow encountered bad instruction data */

void _cmap_90msp_RKSJ_H(undefined1 param_1,undefined1 *param_2)

{
  *param_2 = param_1;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* ==== _cmap_90msp_RKSJ_V @ 184159918 size=4 ==== */

/* WARNING: Control flow encountered bad instruction data */

void _cmap_90msp_RKSJ_V(undefined1 param_1,undefined1 *param_2)

{
  *param_2 = param_1;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* ==== _cmap_90pv_RKSJ_H @ 184159b4c size=4 ==== */

/* WARNING: Control flow encountered bad instruction data */

void _cmap_90pv_RKSJ_H(undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
                      undefined1 param_4 [16],undefined1 *param_5)

{
  *param_5 = param_1[0];
  param_5[1] = param_2[0];
  param_5[2] = param_3[0];
  param_5[3] = param_4[0];
  param_5[4] = param_1[1];
  param_5[5] = param_2[1];
  param_5[6] = param_3[1];
  param_5[7] = param_4[1];
  param_5[8] = param_1[2];
  param_5[9] = param_2[2];
  param_5[10] = param_3[2];
  param_5[0xb] = param_4[2];
  param_5[0xc] = param_1[3];
  param_5[0xd] = param_2[3];
  param_5[0xe] = param_3[3];
  param_5[0xf] = param_4[3];
  param_5[0x10] = param_1[4];
  param_5[0x11] = param_2[4];
  param_5[0x12] = param_3[4];
  param_5[0x13] = param_4[4];
  param_5[0x14] = param_1[5];
  param_5[0x15] = param_2[5];
  param_5[0x16] = param_3[5];
  param_5[0x17] = param_4[5];
  param_5[0x18] = param_1[6];
  param_5[0x19] = param_2[6];
  param_5[0x1a] = param_3[6];
  param_5[0x1b] = param_4[6];
  param_5[0x1c] = param_1[7];
  param_5[0x1d] = param_2[7];
  param_5[0x1e] = param_3[7];
  param_5[0x1f] = param_4[7];
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* ==== _cmap_Add_RKSJ_H @ 18415a1ec size=16 ==== */

void _cmap_Add_RKSJ_H(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)UndefinedInstructionException(0x482d,0x18415a1f8);
  (*pcVar1)();
}



/* ==== _cmap_Add_RKSJ_V @ 18415b13c size=16 ==== */

void _cmap_Add_RKSJ_V(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)UndefinedInstructionException(0x562d,0x18415b148);
  (*pcVar1)();
}



/* ==== _cmap_Adobe_Japan1_UCS2 @ 18415b2f4 size=4 ==== */

/* WARNING: Control flow encountered bad instruction data */

void _cmap_Adobe_Japan1_UCS2(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* ==== _cmap_EUC_H @ 18419b6ab size=1 ==== */

/* WARNING: Control flow encountered bad instruction data */

void _cmap_EUC_H(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* ==== _cmap_UniJIS_UCS2_HW_V @ 1841a97c8 size=8 ==== */

/* WARNING: Control flow encountered bad instruction data */

void _cmap_UniJIS_UCS2_HW_V(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* ==== _cmap_UniJIS_UCS2_V @ 1841a9cc4 size=8 ==== */

/* WARNING: Control flow encountered bad instruction data */

void _cmap_UniJIS_UCS2_V(undefined1 param_1 [16])

{
  a64_TBL(ZEXT816(0),param_1,param_1._0_8_);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* ==== _cmap_UniJIS_UTF16_V @ 1841bed54 size=1 ==== */

/* WARNING: Control flow encountered bad instruction data */

void _cmap_UniJIS_UTF16_V(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* ==== _japanese_cmap_table_count @ 1841bf3c0 size=4 ==== */

void _japanese_cmap_table_count(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)UndefinedInstructionException(0x15,0x1841bf3c0);
  (*pcVar1)();
}



/* ==== _cmap_Identity_H @ 1841d9180 size=16 ==== */

void _cmap_Identity_H(undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
                     undefined1 param_4 [16],undefined1 param_5 [16],undefined1 param_6 [16])

{
  code *pcVar1;
  
  NEON_umax(param_3,param_6,2);
                    /* WARNING: Does not return */
  pcVar1 = (code *)UndefinedInstructionException(0x482d,0x1841d918c);
  (*pcVar1)();
}



/* ==== _identity_cmap_table_count @ 1841d91d0 size=4 ==== */

void _identity_cmap_table_count(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)UndefinedInstructionException(2,0x1841d91d0);
  (*pcVar1)();
}



/* ==== _cmap_B5pc_H @ 184220237 size=1 ==== */

/* WARNING: Control flow encountered bad instruction data */

void _cmap_B5pc_H(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* ==== _cmap_B5pc_V @ 184220858 size=1 ==== */

/* WARNING: Control flow encountered bad instruction data */

void _cmap_B5pc_V(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* ==== _cmap_ETen_B5_V @ 184222b84 size=16 ==== */

void _cmap_ETen_B5_V(undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
                    undefined1 param_4 [16],undefined1 param_5 [16],undefined1 param_6 [16])

{
  code *pcVar1;
  long in_x17;
  undefined4 unaff_s13;
  undefined4 in_s16;
  
  NEON_urshl(param_3,param_6,2);
  *(undefined4 *)(in_x17 + -0x58) = unaff_s13;
  *(undefined4 *)(in_x17 + -0x54) = in_s16;
                    /* WARNING: Does not return */
  pcVar1 = (code *)UndefinedInstructionException(0x56,0x184222b90);
  (*pcVar1)();
}



