/* ==== _flate_filter_finalize @ 183bda9a0 size=4 ==== */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Possible PIC construction at 0x000183bdd980: Changing call to branch */
/* WARNING: Removing unreachable block (ram,0x000183bdd984) */
/* WARNING: Removing unreachable block (ram,0x000183bdd9a4) */
/* WARNING: Removing unreachable block (ram,0x000183bdd9a0) */

void _flate_filter_finalize(long *param_1)

{
  uint uVar1;
  ulong uVar2;
  long lVar3;
  
  if (param_1 == (long *)0x0) {
    return;
  }
  if (param_1[7] != 0) {
    func_0x000188149560(param_1);
  }
  if (param_1[0xf] != 0) {
    uVar1 = *(uint *)(param_1 + 1);
    if (uVar1 != 0) {
      uVar2 = 0;
      lVar3 = (ulong)uVar1 - 1;
      do {
        FUN_183bcd60c(param_1[0xf],*(undefined1 *)(*param_1 + ~uVar2 + (ulong)uVar1));
        uVar2 = uVar2 + 1;
        lVar3 = lVar3 + -1;
      } while (lVar3 != -1);
      if (param_1[0xf] == 0) {
        halt_baddata();
      }
    }
    func_0x000188141240();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* ==== _flate_filter_refill @ 183bdcf08 size=400 ==== */

long _flate_filter_refill(undefined8 *param_1,undefined8 param_2,ulong param_3)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  char *pcVar4;
  
  lVar2 = 0;
  if (param_1 != (undefined8 *)0x0) {
    if (((*(byte *)((long)param_1 + 0x71) & 1) == 0) && ((*(byte *)(param_1 + 0xe) & 1) == 0)) {
      if (0x3000 < param_3) {
                    /* WARNING: Subroutine does not return */
        FUN_183c19214("fstream_read",0xaa,
                      "/Library/Caches/com.apple.xbs/418A84E5-A935-45BB-BEF3-31726BD24C5D/TemporaryDirectory.myKecQ/Sources/CoreGraphics/CoreGraphics/PDF/Filters/flate-filter.c"
                      ,"count <= OUTPUT_BUFFER_SIZE",
                      "Count (%lu) exceeds size of allocated buffer(%d)");
      }
      *(int *)(param_1 + 4) = (int)param_3;
      param_1[3] = param_2;
      if (param_3 != 0) {
        while( true ) {
          if ((*(int *)(param_1 + 1) == 0) && ((*(byte *)((long)param_1 + 0x72) & 1) == 0)) {
            uVar3 = FUN_183bd4a90(param_1[0xf],param_1[0x10],0xf00);
            if (uVar3 == 0) {
              *(undefined1 *)((long)param_1 + 0x72) = 1;
            }
            else if (0xf00 < uVar3) {
                    /* WARNING: Subroutine does not return */
              FUN_183c19214("fstream_read",0xb5,
                            "/Library/Caches/com.apple.xbs/418A84E5-A935-45BB-BEF3-31726BD24C5D/TemporaryDirectory.myKecQ/Sources/CoreGraphics/CoreGraphics/PDF/Filters/flate-filter.c"
                            ,"n <= INPUT_BUFFER_SIZE",
                            "Bytes read (%lu) exceeded input buffer size (%d)");
            }
            *(int *)(param_1 + 1) = (int)uVar3;
            *param_1 = param_1[0x10];
          }
          iVar1 = func_0x000188149550(param_1,0);
          if (iVar1 != 0) break;
          if (((*(byte *)((long)param_1 + 0x72) & 1) != 0) || (*(int *)(param_1 + 4) == 0))
          goto LAB_183bdd010;
        }
        if ((iVar1 + 5U < 7) && ((1 << (ulong)(iVar1 + 5U & 0x1f) & 0x45U) != 0)) {
          *(undefined1 *)(param_1 + 0xe) = 1;
        }
        else {
          if (param_1[6] == 0) {
            pcVar4 = "FlateDecode: decoding error.";
          }
          else {
            pcVar4 = "FlateDecode: decoding error: %s.";
          }
          _pdf_error(pcVar4);
          *(undefined1 *)((long)param_1 + 0x71) = 1;
        }
      }
LAB_183bdd010:
      lVar2 = param_3 - *(uint *)(param_1 + 4);
    }
    else {
      lVar2 = 0;
    }
  }
  return lVar2;
}



/* ==== _flate_has_error @ 183bf4734 size=24 ==== */

byte _flate_has_error(long param_1)

{
  byte bVar1;
  
  if (param_1 == 0) {
    bVar1 = 0;
  }
  else {
    bVar1 = *(byte *)(param_1 + 0x71);
  }
  return bVar1 & 1;
}



/* ==== _png_filter_refill @ 183c5c624 size=536 ==== */

ulong _png_filter_refill(undefined8 *param_1,long param_2,ulong param_3)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  ulong uVar7;
  ulong uVar8;
  long lVar9;
  ulong uVar10;
  long lVar11;
  uint uVar12;
  uint uVar13;
  
  iVar6 = FUN_183bdf3b0(*param_1);
  if (iVar6 == -1) {
    return 0;
  }
  uVar7 = FUN_183bd4a90(*param_1,param_2,param_3);
  if (param_2 == 0) {
    return 0;
  }
  if (uVar7 == 0) {
    return 0;
  }
  if (uVar7 <= param_3 && param_3 - uVar7 != 0) {
    func_0x0001881382e0(param_2 + uVar7,param_3 - uVar7);
  }
  uVar8 = param_1[5];
  if (iVar6 < 2) {
    if (iVar6 == 0) goto LAB_183c5c810;
    if (iVar6 == 1) {
      lVar9 = param_3 - uVar8;
      uVar10 = uVar8;
      if (uVar8 <= param_3 && lVar9 != 0) {
        do {
          *(char *)(param_2 + uVar10) =
               *(char *)(param_2 + (uVar10 - uVar8)) + *(char *)(param_2 + uVar10);
          lVar9 = lVar9 + -1;
          uVar10 = uVar10 + 1;
        } while (lVar9 != 0);
      }
      goto LAB_183c5c810;
    }
  }
  else {
    lVar9 = param_1[6];
    if (iVar6 == 2) {
      if (param_3 != 0) {
        lVar11 = 0;
        uVar8 = param_3;
        do {
          *(char *)(param_2 + lVar11) = *(char *)(lVar9 + lVar11) + *(char *)(param_2 + lVar11);
          lVar11 = lVar11 + 1;
          uVar8 = uVar8 - 1;
        } while (uVar8 != 0);
      }
      goto LAB_183c5c810;
    }
    if (iVar6 == 3) {
      if (uVar8 != 0) {
        lVar11 = 0;
        uVar10 = uVar8;
        do {
          *(byte *)(param_2 + lVar11) =
               *(char *)(param_2 + lVar11) + (*(byte *)(lVar9 + lVar11) >> 1);
          lVar11 = lVar11 + 1;
          uVar10 = uVar10 - 1;
        } while (uVar10 != 0);
      }
      lVar11 = param_3 - uVar8;
      uVar10 = uVar8;
      if (uVar8 <= param_3 && lVar11 != 0) {
        do {
          *(char *)(param_2 + uVar10) =
               *(char *)(param_2 + uVar10) +
               (char)((uint)*(byte *)(param_2 + (uVar10 - uVar8)) + (uint)*(byte *)(lVar9 + uVar10)
                     >> 1);
          lVar11 = lVar11 + -1;
          uVar10 = uVar10 + 1;
        } while (lVar11 != 0);
      }
      goto LAB_183c5c810;
    }
    if (iVar6 == 4) {
      if (param_3 != 0) {
        uVar10 = 0;
        do {
          if (uVar10 < uVar8) {
            uVar12 = 0;
            uVar13 = 0;
          }
          else {
            uVar12 = (uint)*(byte *)(param_2 + (uVar10 - uVar8));
            uVar13 = (uint)*(byte *)(lVar9 + (uVar10 - uVar8));
          }
          bVar2 = *(byte *)(lVar9 + uVar10);
          iVar6 = (uVar12 + bVar2) - uVar13;
          uVar3 = iVar6 - uVar12;
          uVar1 = -uVar3;
          if (-1 < (int)uVar3) {
            uVar1 = uVar3;
          }
          uVar4 = iVar6 - (uint)bVar2;
          uVar3 = -uVar4;
          if (-1 < (int)uVar4) {
            uVar3 = uVar4;
          }
          uVar5 = iVar6 - uVar13;
          uVar4 = -uVar5;
          if (-1 < (int)uVar5) {
            uVar4 = uVar5;
          }
          if (uVar3 <= uVar4) {
            uVar13 = (uint)bVar2;
          }
          if (uVar1 <= uVar4 && uVar1 <= uVar3) {
            uVar13 = uVar12;
          }
          *(char *)(param_2 + uVar10) = *(char *)(param_2 + uVar10) + (char)uVar13;
          uVar10 = uVar10 + 1;
        } while (param_3 != uVar10);
      }
      goto LAB_183c5c810;
    }
  }
  _pdf_error("unrecognized PNG predictor: %d");
LAB_183c5c810:
  func_0x0001881384e0(param_1[6],param_2,param_3);
  return uVar7;
}



/* ==== _cg_jbig2_library_link_symbol @ 183c62c18 size=12 ==== */

undefined * _cg_jbig2_library_link_symbol(void)

{
  return &DAT_1e2236708;
}



/* ==== _pdf_source_create_jbig2_filter @ 183ca2058 size=544 ==== */

long _pdf_source_create_jbig2_filter(long param_1,long param_2,undefined8 param_3)

{
  int iVar1;
  long *plVar2;
  undefined8 uVar3;
  ulong uVar4;
  long lVar5;
  undefined8 uVar6;
  long lVar7;
  long local_70;
  long local_68;
  int local_5c;
  long local_58;
  
  plVar2 = (long *)func_0x000188138460(1,0x20,0x10a0040169b3756);
  if (plVar2 == (long *)0x0) {
    return 0;
  }
  local_58 = 0;
  local_5c = 0;
  *(undefined1 *)(plVar2 + 3) = 0;
  if (param_1 != 0) {
    func_0x000188141250(param_1);
  }
  *plVar2 = param_1;
  iVar1 = FUN_183bf4260(param_3,"JBIG2Globals",&local_58);
  lVar5 = local_58;
  if ((iVar1 == 0) || (local_58 == 0)) {
    lVar5 = 0;
    plVar2[1] = 0;
  }
  else {
    uVar3 = func_0x000188141490(0,0,0);
    while (local_68 = param_2, param_2 != 0) {
      iVar1 = func_0x000188141480(uVar3,param_2);
      if (iVar1 != 0) {
        _pdf_error("JBIG2Filter: JBIG2Globals reference loop");
        goto LAB_183ca2250;
      }
      func_0x000188141470(uVar3,param_2);
      uVar6 = *(undefined8 *)(param_2 + 0x30);
      local_70 = 0;
      uVar4 = FUN_183bd75c4(uVar6,"DecodeParms",&local_70);
      if (((((uVar4 & 1) == 0) && (iVar1 = FUN_183bd75c4(uVar6,"DP",&local_70), iVar1 == 0)) ||
          (local_70 == 0)) ||
         (uVar4 = FUN_183bf4260(local_70,"JBIG2Globals",&local_68), param_2 = local_68,
         (uVar4 & 1) == 0)) break;
    }
    func_0x000188141240(uVar3);
    lVar5 = _CGPDFStreamCreateFilterChainExcluding(lVar5,0,0,&local_5c);
    plVar2[1] = lVar5;
    if ((lVar5 == 0) || (local_5c != 0)) goto LAB_183ca2250;
  }
  lVar7 = *plVar2;
  if ((DAT_1eb058480 & 1) == 0) {
    func_0x000188143c80(&DAT_1eb055350,_doLoadVTable);
  }
  if ((DAT_1eb058478 == 0) || (*(code **)(DAT_1eb058478 + 8) == (code *)0x0)) {
    lVar5 = 0;
  }
  else {
    lVar5 = (**(code **)(DAT_1eb058478 + 8))(lVar7,lVar5);
  }
  plVar2[2] = lVar5;
  lVar5 = _CGPDFSourceCreateInternal(0x1000);
  if (lVar5 != 0) {
    *(undefined1 *)(lVar5 + 0xd1) = 1;
    *(undefined8 *)(lVar5 + 0x38) = 0x8010000003ca230c;
    *(undefined8 *)(lVar5 + 0x30) = 0x8010000003ca2278;
    *(undefined8 *)(lVar5 + 0x48) = 0;
    *(undefined8 *)(lVar5 + 0x40) = 0x8020000003ca23b0;
    *(long **)(lVar5 + 0x50) = plVar2;
    return lVar5;
  }
LAB_183ca2250:
  _jbig2_filter_finalize(plVar2);
  return 0;
}



/* ==== _jbig2_filter_rewind @ 183ca2278 size=148 ==== */

void _jbig2_filter_rewind(undefined8 *param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  ulong unaff_x30;
  
  *(undefined1 *)(param_1 + 3) = 0;
  FUN_183d23b30(*param_1);
  FUN_183d23b30(param_1[1]);
  uVar2 = param_1[2];
  if ((DAT_1eb058480 & 1) == 0) {
    func_0x000188143c80(&DAT_1eb055350,_doLoadVTable);
  }
  if ((DAT_1eb058478 != 0) && (*(code **)(DAT_1eb058478 + 0x20) != (code *)0x0)) {
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xc471,0x183ca22fc);
      (*pcVar1)();
    }
                    /* WARNING: Could not recover jumptable at 0x000183ca22fc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(DAT_1eb058478 + 0x20))(uVar2);
    return;
  }
  return;
}



/* ==== _jbig2_filter_refill @ 183ca230c size=164 ==== */

long _jbig2_filter_refill(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  undefined8 uVar2;
  
  if ((*(byte *)(param_1 + 0x18) & 1) != 0) {
    return 0;
  }
  uVar2 = *(undefined8 *)(param_1 + 0x10);
  if ((DAT_1eb058480 & 1) == 0) {
    func_0x000188143c80(&DAT_1eb055350,_doLoadVTable);
  }
  if (((DAT_1eb058478 == 0) || (*(code **)(DAT_1eb058478 + 0x18) == (code *)0x0)) ||
     (lVar1 = (**(code **)(DAT_1eb058478 + 0x18))(uVar2,param_2,param_3), lVar1 == 0)) {
    lVar1 = 0;
    *(undefined1 *)(param_1 + 0x18) = 1;
  }
  return lVar1;
}



/* ==== _jbig2_filter_finalize @ 183ca23b0 size=156 ==== */

/* WARNING: Control flow encountered bad instruction data */

void _jbig2_filter_finalize(long *param_1)

{
  code *pcVar1;
  long lVar2;
  ulong unaff_x30;
  
  if (param_1 == (long *)0x0) {
    return;
  }
  lVar2 = param_1[2];
  if ((DAT_1eb058480 & 1) == 0) {
    func_0x000188143c80(&DAT_1eb055350,_doLoadVTable);
  }
  if ((DAT_1eb058478 != 0) && (*(code **)(DAT_1eb058478 + 0x10) != (code *)0x0)) {
    (**(code **)(DAT_1eb058478 + 0x10))(lVar2);
  }
  if (param_1[1] != 0) {
    func_0x000188141240();
  }
  if (*param_1 != 0) {
    func_0x000188141240();
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0x183ca2444);
    (*pcVar1)();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* ==== _ccitt_fax_filter_refill @ 183ca41cc size=7980 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 _ccitt_fax_filter_refill(long param_1,undefined8 param_2,undefined8 param_3)

{
  bool bVar1;
  code cVar2;
  int iVar3;
  short sVar4;
  ulong uVar5;
  ushort uVar6;
  ushort uVar7;
  uint uVar8;
  int iVar9;
  long lVar10;
  int iVar11;
  uint uVar12;
  undefined8 uVar13;
  uint uVar14;
  code *pcVar15;
  int iVar16;
  ushort *puVar17;
  ushort *puVar18;
  ushort *puVar19;
  ushort *puVar20;
  ushort *puVar21;
  int *piVar22;
  uint uVar23;
  uint uVar24;
  int iVar25;
  
  if ((*(byte *)(param_1 + 8) & 1) != 0) {
    return 0;
  }
  piVar22 = *(int **)(param_1 + 0x20);
  if (*piVar22 != 4) {
    uVar12 = piVar22[1];
    if ((uVar12 & 6) == 4) {
      uVar24 = piVar22[5] & 7;
      if (uVar24 != 0) {
        piVar22[4] = (uint)piVar22[4] >> (ulong)uVar24;
        piVar22[5] = piVar22[5] & 0xfffffff8;
      }
    }
    if (piVar22[6] == 0) {
      iVar9 = piVar22[5];
      do {
        if (iVar9 < 0xb) {
          uVar5 = (**(code **)(piVar22 + 0x10))(*(undefined8 *)(piVar22 + 0x12));
          if ((int)uVar5 == -1) {
            if (piVar22[5] == 0) goto LAB_183ca4bd0;
LAB_183ca4ba4:
            iVar9 = 0xb;
          }
          else {
            uVar24 = piVar22[5];
            iVar9 = uVar24 + 8;
            piVar22[4] = piVar22[4] |
                         (uint)(byte)_TIFFBitRevTable[uVar5 & 0xff] << (ulong)(uVar24 & 0x1f);
            piVar22[5] = iVar9;
            if (2 < (int)uVar24) goto LAB_183ca4bac;
            uVar5 = (**(code **)(piVar22 + 0x10))(*(undefined8 *)(piVar22 + 0x12));
            if ((int)uVar5 == -1) goto LAB_183ca4ba4;
            piVar22[4] = piVar22[4] |
                         (uint)(byte)_TIFFBitRevTable[uVar5 & 0xff] << (ulong)(piVar22[5] & 0x1f);
            iVar9 = piVar22[5] + 8;
          }
          piVar22[5] = iVar9;
        }
LAB_183ca4bac:
        if ((piVar22[4] & 0x7ffU) == 0) goto LAB_183ca494c;
        if ((*(byte *)(piVar22 + 1) >> 1 & 1) == 0) goto LAB_183ca4be4;
        iVar9 = iVar9 + -1;
        piVar22[4] = (uint)piVar22[4] >> 1;
        piVar22[5] = iVar9;
      } while( true );
    }
    iVar9 = piVar22[5];
LAB_183ca494c:
    iVar11 = 1;
    do {
      piVar22[6] = iVar11;
      while( true ) {
        if (iVar9 < 8) {
          uVar5 = (**(code **)(piVar22 + 0x10))(*(undefined8 *)(piVar22 + 0x12));
          if ((int)uVar5 == -1) {
            if (piVar22[5] == 0) goto LAB_183ca4bd0;
            iVar9 = 8;
          }
          else {
            piVar22[4] = piVar22[4] |
                         (uint)(byte)_TIFFBitRevTable[uVar5 & 0xff] << (ulong)(piVar22[5] & 0x1f);
            iVar9 = piVar22[5] + 8;
          }
        }
        uVar24 = piVar22[4];
        if ((uVar24 & 0xff) != 0) break;
        iVar9 = iVar9 + -8;
        piVar22[4] = uVar24 >> 8;
        piVar22[5] = iVar9;
      }
      for (; (uVar24 & 1) == 0; uVar24 = uVar24 >> 1) {
        iVar9 = iVar9 + -1;
      }
      iVar11 = iVar9 + -1;
      uVar24 = uVar24 >> 1;
      piVar22[4] = uVar24;
      piVar22[5] = iVar11;
      if ((*(byte *)(piVar22 + 1) & 1) == 0) {
        if (iVar9 < 0xc) {
          uVar5 = (**(code **)(piVar22 + 0x10))(*(undefined8 *)(piVar22 + 0x12));
          if ((int)uVar5 == -1) {
            if (piVar22[5] == 0) goto LAB_183ca4bd0;
            uVar24 = piVar22[4];
LAB_183ca4ac8:
            iVar11 = 0xb;
          }
          else {
            uVar23 = piVar22[5];
            uVar24 = piVar22[4] |
                     (uint)(byte)_TIFFBitRevTable[uVar5 & 0xff] << (ulong)(uVar23 & 0x1f);
            iVar11 = uVar23 + 8;
            piVar22[4] = uVar24;
            piVar22[5] = iVar11;
            if (2 < (int)uVar23) goto LAB_183ca4ad0;
            uVar5 = (**(code **)(piVar22 + 0x10))(*(undefined8 *)(piVar22 + 0x12));
            uVar24 = piVar22[4];
            if ((int)uVar5 == -1) goto LAB_183ca4ac8;
            uVar24 = uVar24 | (uint)(byte)_TIFFBitRevTable[uVar5 & 0xff] <<
                              (ulong)(piVar22[5] & 0x1f);
            piVar22[4] = uVar24;
            iVar11 = piVar22[5] + 8;
          }
          piVar22[5] = iVar11;
        }
LAB_183ca4ad0:
        if ((uVar24 & 0x7ff) != 0) goto LAB_183ca4ec8;
        iVar9 = iVar11 + -0xb;
        piVar22[5] = iVar9;
        uVar24 = uVar24 >> 0xb;
      }
      else {
        if (iVar9 < 0xd) {
          uVar5 = (**(code **)(piVar22 + 0x10))(*(undefined8 *)(piVar22 + 0x12));
          if ((int)uVar5 == -1) {
            if (piVar22[5] == 0) goto LAB_183ca4bd0;
            uVar24 = piVar22[4];
LAB_183ca4af4:
            iVar11 = 0xc;
          }
          else {
            uVar23 = piVar22[5];
            uVar24 = piVar22[4] |
                     (uint)(byte)_TIFFBitRevTable[uVar5 & 0xff] << (ulong)(uVar23 & 0x1f);
            iVar11 = uVar23 + 8;
            piVar22[4] = uVar24;
            piVar22[5] = iVar11;
            if (3 < (int)uVar23) goto LAB_183ca4afc;
            uVar5 = (**(code **)(piVar22 + 0x10))(*(undefined8 *)(piVar22 + 0x12));
            uVar24 = piVar22[4];
            if ((int)uVar5 == -1) goto LAB_183ca4af4;
            uVar24 = uVar24 | (uint)(byte)_TIFFBitRevTable[uVar5 & 0xff] <<
                              (ulong)(piVar22[5] & 0x1f);
            piVar22[4] = uVar24;
            iVar11 = piVar22[5] + 8;
          }
          piVar22[5] = iVar11;
        }
LAB_183ca4afc:
        if ((uVar24 & 0xffe) != 0) goto LAB_183ca4ec8;
        iVar9 = iVar11 + -0xc;
        piVar22[5] = iVar9;
        uVar24 = uVar24 >> 0xc;
      }
      piVar22[4] = uVar24;
      iVar11 = piVar22[6] + 1;
    } while( true );
  }
  puVar21 = *(ushort **)(piVar22 + 0xc);
  puVar18 = *(ushort **)(piVar22 + 10) + 1;
  uVar24 = (uint)**(ushort **)(piVar22 + 10);
  uVar12 = piVar22[3];
  if ((*(byte *)(piVar22 + 1) >> 2 & 1) != 0) {
    uVar23 = piVar22[5] & 7;
    if (uVar23 != 0) {
      piVar22[4] = (uint)piVar22[4] >> (ulong)uVar23;
      piVar22[5] = piVar22[5] & 0xfffffff8;
    }
  }
  iVar9 = (int)puVar21;
  uVar7 = (ushort)uVar12;
  if (0 < (int)uVar12) {
    iVar16 = 0;
    uVar23 = 0;
    iVar25 = 0;
    iVar11 = piVar22[5];
    puVar19 = puVar21;
LAB_183ca4278:
    if (iVar11 < 7) {
      uVar5 = (**(code **)(piVar22 + 0x10))(*(undefined8 *)(piVar22 + 0x12));
      if ((int)uVar5 != -1) {
        piVar22[4] = piVar22[4] |
                     (uint)(byte)_TIFFBitRevTable[uVar5 & 0xff] << (ulong)(piVar22[5] & 0x1f);
        iVar11 = piVar22[5] + 8;
        goto LAB_183ca42c4;
      }
      if (piVar22[5] != 0) {
        iVar11 = 7;
        goto LAB_183ca42c4;
      }
LAB_183ca5ec8:
      if (iVar25 != 0) goto LAB_183ca5ecc;
      goto LAB_183ca5ee4;
    }
LAB_183ca42c4:
    lVar10 = ((ulong)(uint)piVar22[4] & 0x7f) * 4;
    iVar11 = iVar11 - (uint)*(byte *)(lVar10 + 0x1841d96a1);
    uVar8 = (uint)piVar22[4] >> (ulong)(*(byte *)(lVar10 + 0x1841d96a1) & 0x1f);
    piVar22[4] = uVar8;
    piVar22[5] = iVar11;
    cVar2 = _pdf_TIFFFaxMainTable[lVar10];
    sVar4 = (short)iVar25;
    puVar20 = puVar19;
    if ((byte)cVar2 < 4) {
      if (cVar2 == (code)0x1) {
        if ((puVar19 != puVar21) && ((int)uVar24 <= (int)uVar23)) {
          do {
            if ((ushort *)(*(long *)(piVar22 + 10) + (ulong)(uint)piVar22[0xe] * 2) <= puVar18 + 1)
            break;
            uVar24 = uVar24 + *puVar18 + (uint)puVar18[1];
            puVar18 = puVar18 + 2;
          } while ((int)uVar24 <= (int)uVar23);
        }
        puVar20 = (ushort *)(*(long *)(piVar22 + 10) + (ulong)(uint)piVar22[0xe] * 2);
        if (puVar18 < puVar20) {
          uVar24 = uVar24 + *puVar18;
          iVar25 = (uVar24 - uVar23) + iVar25;
          uVar23 = uVar24;
          if (puVar18 + 1 < puVar20) {
            uVar6 = puVar18[1];
            puVar17 = puVar18 + 2;
            goto LAB_183ca46a4;
          }
        }
        goto LAB_183ca5a40;
      }
      if (cVar2 == (code)0x2) {
        if (((uint)((int)puVar19 - iVar9) >> 1 & 1) != 0) {
          do {
            if (iVar11 < 0xd) {
              uVar5 = (**(code **)(piVar22 + 0x10))(*(undefined8 *)(piVar22 + 0x12));
              if ((int)uVar5 == -1) {
                if (piVar22[5] == 0) goto LAB_183ca5ec8;
                uVar8 = piVar22[4];
LAB_183ca45b8:
                iVar11 = 0xd;
              }
              else {
                uVar14 = piVar22[5];
                uVar8 = piVar22[4] |
                        (uint)(byte)_TIFFBitRevTable[uVar5 & 0xff] << (ulong)(uVar14 & 0x1f);
                iVar11 = uVar14 + 8;
                piVar22[4] = uVar8;
                piVar22[5] = iVar11;
                if ((int)uVar14 < 5) {
                  uVar5 = (**(code **)(piVar22 + 0x10))(*(undefined8 *)(piVar22 + 0x12));
                  uVar8 = piVar22[4];
                  if ((int)uVar5 == -1) goto LAB_183ca45b8;
                  uVar8 = uVar8 | (uint)(byte)_TIFFBitRevTable[uVar5 & 0xff] <<
                                  (ulong)(piVar22[5] & 0x1f);
                  iVar11 = piVar22[5] + 8;
                }
              }
            }
            lVar10 = (ulong)(uVar8 & 0x1fff) * 4;
            iVar11 = iVar11 - (uint)*(byte *)(lVar10 + 0x1841dd8a1);
            uVar8 = uVar8 >> (ulong)(*(byte *)(lVar10 + 0x1841dd8a1) & 0x1f);
            piVar22[4] = uVar8;
            piVar22[5] = iVar11;
            if (1 < (byte)_pdf_TIFFFaxBlackTable[lVar10] - 10) goto LAB_183ca479c;
            iVar25 = iVar25 + (uint)*(ushort *)(lVar10 + 0x1841dd8a2);
            uVar23 = uVar23 + *(ushort *)(lVar10 + 0x1841dd8a2);
          } while( true );
        }
        do {
          if (iVar11 < 0xc) {
            uVar5 = (**(code **)(piVar22 + 0x10))(*(undefined8 *)(piVar22 + 0x12));
            if ((int)uVar5 == -1) {
              if (piVar22[5] == 0) goto LAB_183ca5ec8;
              uVar8 = piVar22[4];
LAB_183ca44fc:
              iVar11 = 0xc;
            }
            else {
              uVar14 = piVar22[5];
              uVar8 = piVar22[4] |
                      (uint)(byte)_TIFFBitRevTable[uVar5 & 0xff] << (ulong)(uVar14 & 0x1f);
              iVar11 = uVar14 + 8;
              piVar22[4] = uVar8;
              piVar22[5] = iVar11;
              if ((int)uVar14 < 4) {
                uVar5 = (**(code **)(piVar22 + 0x10))(*(undefined8 *)(piVar22 + 0x12));
                uVar8 = piVar22[4];
                if ((int)uVar5 == -1) goto LAB_183ca44fc;
                uVar8 = uVar8 | (uint)(byte)_TIFFBitRevTable[uVar5 & 0xff] <<
                                (ulong)(piVar22[5] & 0x1f);
                iVar11 = piVar22[5] + 8;
              }
            }
          }
          lVar10 = (ulong)(uVar8 & 0xfff) * 4;
          iVar11 = iVar11 - (uint)*(byte *)(lVar10 + 0x1841d98a1);
          uVar8 = uVar8 >> (ulong)(*(byte *)(lVar10 + 0x1841d98a1) & 0x1f);
          piVar22[4] = uVar8;
          piVar22[5] = iVar11;
          cVar2 = _pdf_TIFFFaxWhiteTable[lVar10];
          if (cVar2 != (code)0x9 && cVar2 != (code)0xb) goto LAB_183ca46bc;
          iVar25 = iVar25 + (uint)*(ushort *)(lVar10 + 0x1841d98a2);
          uVar23 = uVar23 + *(ushort *)(lVar10 + 0x1841d98a2);
        } while( true );
      }
      if (cVar2 != (code)0x3) goto LAB_183ca5a38;
      uVar5 = (ulong)(uint)piVar22[0xe];
      if ((puVar19 != puVar21) && ((int)uVar24 <= (int)uVar23)) {
        do {
          if ((ushort *)(*(long *)(piVar22 + 10) + uVar5 * 2) <= puVar18 + 1) break;
          uVar24 = uVar24 + *puVar18 + (uint)puVar18[1];
          puVar18 = puVar18 + 2;
        } while ((int)uVar24 <= (int)uVar23);
      }
      if (puVar19 < (ushort *)(*(long *)(piVar22 + 0xc) + uVar5 * 2)) {
        puVar20 = puVar19 + 1;
        *puVar19 = sVar4 + (short)iVar16 + (short)uVar24;
      }
      uVar23 = uVar24;
      if (puVar18 < (ushort *)(*(long *)(piVar22 + 10) + uVar5 * 2)) {
        iVar25 = 0;
        puVar17 = puVar18 + 1;
        uVar6 = *puVar18;
        puVar19 = puVar20;
LAB_183ca46a4:
        puVar18 = puVar17;
        puVar20 = puVar19;
        uVar23 = uVar24;
        uVar24 = uVar24 + uVar6;
        goto LAB_183ca46ac;
      }
      goto LAB_183ca5a5c;
    }
    if ((byte)cVar2 < 5) {
      uVar5 = (ulong)(uint)piVar22[0xe];
      puVar17 = puVar18;
      if ((puVar19 != puVar21) && ((int)uVar24 <= (int)uVar23)) {
        do {
          if ((ushort *)(*(long *)(piVar22 + 10) + uVar5 * 2) <= puVar17 + 1) break;
          uVar24 = uVar24 + *puVar17 + (uint)puVar17[1];
          puVar17 = puVar17 + 2;
        } while ((int)uVar24 <= (int)uVar23);
      }
      uVar6 = *(ushort *)(lVar10 + 0x1841d96a2);
      if (puVar19 < (ushort *)(*(long *)(piVar22 + 0xc) + uVar5 * 2)) {
        puVar20 = puVar19 + 1;
        *puVar19 = uVar6 + sVar4 + (short)iVar16 + (short)uVar24;
      }
      uVar23 = uVar24 + uVar6;
      if (puVar17 < (ushort *)(*(long *)(piVar22 + 10) + uVar5 * 2)) {
        iVar25 = 0;
        puVar18 = puVar17 + 1;
        uVar24 = uVar24 + *puVar17;
        goto LAB_183ca46ac;
      }
      goto LAB_183ca5a5c;
    }
    if (cVar2 == (code)0x5) {
      if ((puVar19 != puVar21) && ((int)uVar24 <= (int)uVar23)) {
        do {
          if ((ushort *)(*(long *)(piVar22 + 10) + (ulong)(uint)piVar22[0xe] * 2) <= puVar18 + 1)
          break;
          uVar24 = uVar24 + *puVar18 + (uint)puVar18[1];
          puVar18 = puVar18 + 2;
        } while ((int)uVar24 <= (int)uVar23);
      }
      iVar16 = uVar23 + *(ushort *)(lVar10 + 0x1841d96a2);
      iVar3 = uVar24 - iVar16;
      if (iVar16 <= (int)uVar24) {
        if (puVar19 < (ushort *)(*(long *)(piVar22 + 0xc) + (ulong)(uint)piVar22[0xe] * 2)) {
          puVar20 = puVar19 + 1;
          *puVar19 = (short)iVar3 + sVar4;
        }
        iVar25 = 0;
        uVar23 = iVar3 + uVar23;
        puVar18 = puVar18 + -1;
        uVar24 = uVar24 - *puVar18;
        goto LAB_183ca46ac;
      }
      goto LAB_183ca5a40;
    }
    if (cVar2 != (code)0x6) {
      if (cVar2 != (code)0xc) goto LAB_183ca5a38;
      if (puVar19 < (ushort *)(*(long *)(piVar22 + 0xc) + (ulong)(uint)piVar22[0xe] * 2)) {
        *puVar19 = uVar7 - (short)uVar23;
        puVar19 = puVar19 + 1;
      }
      if (iVar11 < 4) {
        uVar5 = (**(code **)(piVar22 + 0x10))(*(undefined8 *)(piVar22 + 0x12));
        if ((int)uVar5 == -1) {
          if (piVar22[5] == 0) goto LAB_183ca5ec8;
          uVar8 = piVar22[4];
          iVar11 = 4;
        }
        else {
          uVar8 = piVar22[4] |
                  (uint)(byte)_TIFFBitRevTable[uVar5 & 0xff] << (ulong)(piVar22[5] & 0x1f);
          iVar11 = piVar22[5] + 8;
        }
      }
      if ((uVar8 & 0xf) != 0) {
        piVar22[7] = 1;
      }
      uVar8 = uVar8 >> 4;
      piVar22[4] = uVar8;
      piVar22[5] = iVar11 + -4;
      piVar22[6] = 1;
      if (iVar11 < 0x11) {
        uVar5 = (**(code **)(piVar22 + 0x10))(*(undefined8 *)(piVar22 + 0x12));
        if ((int)uVar5 == -1) {
          if (piVar22[5] == 0) goto LAB_183ca5a74;
          uVar8 = piVar22[4];
LAB_183ca5f74:
          iVar9 = 0xd;
        }
        else {
          uVar12 = piVar22[5];
          uVar8 = piVar22[4] | (uint)(byte)_TIFFBitRevTable[uVar5 & 0xff] << (ulong)(uVar12 & 0x1f);
          piVar22[4] = uVar8;
          piVar22[5] = uVar12 + 8;
          if (4 < (int)uVar12) goto LAB_183ca5f7c;
          uVar5 = (**(code **)(piVar22 + 0x10))(*(undefined8 *)(piVar22 + 0x12));
          uVar8 = piVar22[4];
          if ((int)uVar5 == -1) goto LAB_183ca5f74;
          uVar8 = uVar8 | (uint)(byte)_TIFFBitRevTable[uVar5 & 0xff] << (ulong)(piVar22[5] & 0x1f);
          piVar22[4] = uVar8;
          iVar9 = piVar22[5] + 8;
        }
        piVar22[5] = iVar9;
      }
LAB_183ca5f7c:
      if ((uVar8 & 0x1fff) == 0x1001) goto LAB_183ca5a74;
      param_3 = 0;
      piVar22[7] = 1;
      goto LAB_183ca5a78;
    }
    if (puVar19 < (ushort *)(*(long *)(piVar22 + 0xc) + (ulong)(uint)piVar22[0xe] * 2)) {
      *puVar19 = uVar7 - (short)uVar23;
      puVar19 = puVar19 + 1;
    }
    goto LAB_183ca5a40;
  }
  puVar20 = puVar21;
  uVar23 = 0;
LAB_183ca5a5c:
  if (uVar23 != uVar12) {
    bVar1 = (int)uVar12 < (int)uVar23;
    if (((int)uVar12 < (int)uVar23) && (puVar21 < puVar20)) {
      do {
        puVar20 = puVar20 + -1;
        uVar23 = uVar23 - *puVar20;
        bVar1 = (int)uVar12 < (int)uVar23;
      } while (((int)uVar12 < (int)uVar23 && puVar21 <= puVar20) &&
               ((int)uVar23 <= (int)uVar12 || puVar20 != puVar21));
    }
    if ((int)uVar23 < (int)uVar12) {
      puVar19 = (ushort *)(*(long *)(piVar22 + 0xc) + (ulong)(uint)piVar22[0xe] * 2);
      puVar18 = puVar20;
      if ((((uint)((int)puVar20 - iVar9) >> 1 & 1) != 0) && (puVar20 < puVar19)) {
        puVar18 = puVar20 + 1;
        *puVar20 = 0;
      }
      puVar20 = puVar18;
      if (puVar18 < puVar19) {
        *puVar18 = uVar7 - ((ushort)uVar23 & ((ushort)((int)uVar23 >> 0x1f) ^ 0xffff));
        puVar20 = puVar18 + 1;
      }
    }
    else if (bVar1) {
      puVar19 = (ushort *)(*(long *)(piVar22 + 0xc) + (ulong)(uint)piVar22[0xe] * 2);
      puVar18 = puVar20;
      if (puVar20 < puVar19) {
        puVar18 = puVar20 + 1;
        *puVar20 = uVar7;
      }
      puVar20 = puVar18;
      if (puVar18 < puVar19) {
        puVar20 = puVar18 + 1;
        *puVar18 = 0;
      }
    }
  }
  if (piVar22[6] < 1) {
LAB_183ca5dbc:
    _fill_runs(param_2,puVar21,puVar20,uVar12,piVar22[1] & 0x10);
    lVar10 = *(long *)(piVar22 + 0xc);
    if (puVar20 < (ushort *)(lVar10 + (ulong)(uint)piVar22[0xe] * 2)) {
      *puVar20 = 0;
    }
    uVar13 = *(undefined8 *)(piVar22 + 10);
    *(long *)(piVar22 + 10) = lVar10;
    *(undefined8 *)(piVar22 + 0xc) = uVar13;
LAB_183ca5df8:
    piVar22[0xf] = piVar22[0xf] + 1;
    iVar9 = *(int *)(param_1 + 0x10) + -1;
    if (*(int *)(param_1 + 0x10) < 1) {
      return param_3;
    }
    *(int *)(param_1 + 0x10) = iVar9;
    if (iVar9 != 0) {
      return param_3;
    }
    goto LAB_183ca5a78;
  }
  goto LAB_183ca5a74;
LAB_183ca4be4:
  if ((uVar12 & 1) == 0) goto LAB_183ca4be8;
LAB_183ca4f14:
  piVar22[6] = 0;
  if (iVar9 < 1) {
    uVar5 = (**(code **)(piVar22 + 0x10))(*(undefined8 *)(piVar22 + 0x12));
    if ((int)uVar5 == -1) {
      if (piVar22[5] == 0) goto LAB_183ca5a74;
      iVar9 = 1;
    }
    else {
      piVar22[4] = piVar22[4] |
                   (uint)(byte)_TIFFBitRevTable[uVar5 & 0xff] << (ulong)(piVar22[5] & 0x1f);
      iVar9 = piVar22[5] + 8;
    }
  }
  iVar9 = iVar9 + -1;
  uVar12 = piVar22[3];
  uVar24 = piVar22[4];
  uVar23 = uVar24 >> 1;
  piVar22[4] = uVar23;
  piVar22[5] = iVar9;
  puVar21 = *(ushort **)(piVar22 + 0xc);
  iVar11 = (int)puVar21;
  uVar7 = (ushort)uVar12;
  puVar20 = puVar21;
  if ((uVar24 & 1) != 0) {
    uVar24 = 0;
LAB_183ca573c:
    iVar25 = 0;
    do {
      if (iVar9 < 0xc) {
        uVar5 = (**(code **)(piVar22 + 0x10))(*(undefined8 *)(piVar22 + 0x12));
        if ((int)uVar5 == -1) {
          if (piVar22[5] == 0) goto LAB_183ca5b3c;
          uVar23 = piVar22[4];
LAB_183ca57b8:
          iVar9 = 0xc;
        }
        else {
          uVar8 = piVar22[5];
          uVar23 = piVar22[4] | (uint)(byte)_TIFFBitRevTable[uVar5 & 0xff] << (ulong)(uVar8 & 0x1f);
          iVar9 = uVar8 + 8;
          piVar22[4] = uVar23;
          piVar22[5] = iVar9;
          if ((int)uVar8 < 4) {
            uVar5 = (**(code **)(piVar22 + 0x10))(*(undefined8 *)(piVar22 + 0x12));
            uVar23 = piVar22[4];
            if ((int)uVar5 == -1) goto LAB_183ca57b8;
            uVar23 = uVar23 | (uint)(byte)_TIFFBitRevTable[uVar5 & 0xff] <<
                              (ulong)(piVar22[5] & 0x1f);
            iVar9 = piVar22[5] + 8;
          }
        }
      }
      lVar10 = (ulong)(uVar23 & 0xfff) * 4;
      iVar9 = iVar9 - (uint)*(byte *)(lVar10 + 0x1841d98a1);
      uVar23 = uVar23 >> (ulong)(*(byte *)(lVar10 + 0x1841d98a1) & 0x1f);
      piVar22[4] = uVar23;
      piVar22[5] = iVar9;
      cVar2 = _pdf_TIFFFaxWhiteTable[lVar10];
      if ((byte)cVar2 < 0xb) {
        if (cVar2 != (code)0x9) goto LAB_183ca5800;
      }
      else if (cVar2 != (code)0xb) goto LAB_183ca5924;
      uVar24 = uVar24 + *(ushort *)(lVar10 + 0x1841d98a2);
      iVar25 = iVar25 + (uint)*(ushort *)(lVar10 + 0x1841d98a2);
    } while( true );
  }
  if (0 < (int)uVar12) {
    iVar16 = 0;
    uVar8 = 0;
    iVar25 = 0;
    puVar18 = *(ushort **)(piVar22 + 10) + 1;
    uVar24 = (uint)**(ushort **)(piVar22 + 10);
    puVar19 = puVar21;
LAB_183ca509c:
    if (iVar9 < 7) {
      uVar5 = (**(code **)(piVar22 + 0x10))(*(undefined8 *)(piVar22 + 0x12));
      if ((int)uVar5 != -1) {
        uVar23 = piVar22[4] |
                 (uint)(byte)_TIFFBitRevTable[uVar5 & 0xff] << (ulong)(piVar22[5] & 0x1f);
        iVar9 = piVar22[5] + 8;
        goto LAB_183ca50e0;
      }
      if (piVar22[5] != 0) {
        uVar23 = piVar22[4];
        iVar9 = 7;
        goto LAB_183ca50e0;
      }
LAB_183ca603c:
      if (iVar25 != 0) goto LAB_183ca6040;
      goto LAB_183ca6058;
    }
LAB_183ca50e0:
    lVar10 = (ulong)(uVar23 & 0x7f) * 4;
    iVar9 = iVar9 - (uint)*(byte *)(lVar10 + 0x1841d96a1);
    uVar23 = uVar23 >> (ulong)(*(byte *)(lVar10 + 0x1841d96a1) & 0x1f);
    piVar22[4] = uVar23;
    piVar22[5] = iVar9;
    cVar2 = _pdf_TIFFFaxMainTable[lVar10];
    sVar4 = (short)iVar25;
    puVar20 = puVar19;
    if ((byte)cVar2 < 4) {
      if (cVar2 == (code)0x1) {
        if ((puVar19 != puVar21) && ((int)uVar24 <= (int)uVar8)) {
          do {
            if ((ushort *)(*(long *)(piVar22 + 10) + (ulong)(uint)piVar22[0xe] * 2) <= puVar18 + 1)
            break;
            uVar24 = uVar24 + *puVar18 + (uint)puVar18[1];
            puVar18 = puVar18 + 2;
          } while ((int)uVar24 <= (int)uVar8);
        }
        puVar20 = (ushort *)(*(long *)(piVar22 + 10) + (ulong)(uint)piVar22[0xe] * 2);
        if (puVar18 < puVar20) {
          uVar24 = uVar24 + *puVar18;
          iVar25 = (uVar24 - uVar8) + iVar25;
          uVar8 = uVar24;
          if (puVar18 + 1 < puVar20) {
            uVar6 = puVar18[1];
            puVar17 = puVar18 + 2;
            goto LAB_183ca54bc;
          }
        }
        goto LAB_183ca5cfc;
      }
      if (cVar2 == (code)0x2) {
        if (((uint)((int)puVar19 - iVar11) >> 1 & 1) != 0) {
          do {
            if (iVar9 < 0xd) {
              uVar5 = (**(code **)(piVar22 + 0x10))(*(undefined8 *)(piVar22 + 0x12));
              if ((int)uVar5 == -1) {
                if (piVar22[5] == 0) goto LAB_183ca603c;
                uVar23 = piVar22[4];
LAB_183ca53c8:
                iVar9 = 0xd;
              }
              else {
                uVar14 = piVar22[5];
                uVar23 = piVar22[4] |
                         (uint)(byte)_TIFFBitRevTable[uVar5 & 0xff] << (ulong)(uVar14 & 0x1f);
                iVar9 = uVar14 + 8;
                piVar22[4] = uVar23;
                piVar22[5] = iVar9;
                if ((int)uVar14 < 5) {
                  uVar5 = (**(code **)(piVar22 + 0x10))(*(undefined8 *)(piVar22 + 0x12));
                  uVar23 = piVar22[4];
                  if ((int)uVar5 == -1) goto LAB_183ca53c8;
                  uVar23 = uVar23 | (uint)(byte)_TIFFBitRevTable[uVar5 & 0xff] <<
                                    (ulong)(piVar22[5] & 0x1f);
                  iVar9 = piVar22[5] + 8;
                }
              }
            }
            lVar10 = (ulong)(uVar23 & 0x1fff) * 4;
            iVar9 = iVar9 - (uint)*(byte *)(lVar10 + 0x1841dd8a1);
            uVar23 = uVar23 >> (ulong)(*(byte *)(lVar10 + 0x1841dd8a1) & 0x1f);
            piVar22[4] = uVar23;
            piVar22[5] = iVar9;
            if (1 < (byte)_pdf_TIFFFaxBlackTable[lVar10] - 10) goto LAB_183ca55bc;
            iVar25 = iVar25 + (uint)*(ushort *)(lVar10 + 0x1841dd8a2);
            uVar8 = uVar8 + *(ushort *)(lVar10 + 0x1841dd8a2);
          } while( true );
        }
        do {
          if (iVar9 < 0xc) {
            uVar5 = (**(code **)(piVar22 + 0x10))(*(undefined8 *)(piVar22 + 0x12));
            if ((int)uVar5 == -1) {
              if (piVar22[5] == 0) goto LAB_183ca603c;
              uVar23 = piVar22[4];
LAB_183ca5314:
              iVar9 = 0xc;
            }
            else {
              uVar14 = piVar22[5];
              uVar23 = piVar22[4] |
                       (uint)(byte)_TIFFBitRevTable[uVar5 & 0xff] << (ulong)(uVar14 & 0x1f);
              iVar9 = uVar14 + 8;
              piVar22[4] = uVar23;
              piVar22[5] = iVar9;
              if ((int)uVar14 < 4) {
                uVar5 = (**(code **)(piVar22 + 0x10))(*(undefined8 *)(piVar22 + 0x12));
                uVar23 = piVar22[4];
                if ((int)uVar5 == -1) goto LAB_183ca5314;
                uVar23 = uVar23 | (uint)(byte)_TIFFBitRevTable[uVar5 & 0xff] <<
                                  (ulong)(piVar22[5] & 0x1f);
                iVar9 = piVar22[5] + 8;
              }
            }
          }
          lVar10 = (ulong)(uVar23 & 0xfff) * 4;
          iVar9 = iVar9 - (uint)*(byte *)(lVar10 + 0x1841d98a1);
          uVar23 = uVar23 >> (ulong)(*(byte *)(lVar10 + 0x1841d98a1) & 0x1f);
          piVar22[4] = uVar23;
          piVar22[5] = iVar9;
          cVar2 = _pdf_TIFFFaxWhiteTable[lVar10];
          if (cVar2 != (code)0x9 && cVar2 != (code)0xb) goto LAB_183ca54d4;
          iVar25 = iVar25 + (uint)*(ushort *)(lVar10 + 0x1841d98a2);
          uVar8 = uVar8 + *(ushort *)(lVar10 + 0x1841d98a2);
        } while( true );
      }
      if (cVar2 != (code)0x3) goto LAB_183ca5cf4;
      uVar5 = (ulong)(uint)piVar22[0xe];
      if ((puVar19 != puVar21) && ((int)uVar24 <= (int)uVar8)) {
        do {
          if ((ushort *)(*(long *)(piVar22 + 10) + uVar5 * 2) <= puVar18 + 1) break;
          uVar24 = uVar24 + *puVar18 + (uint)puVar18[1];
          puVar18 = puVar18 + 2;
        } while ((int)uVar24 <= (int)uVar8);
      }
      if (puVar19 < (ushort *)(*(long *)(piVar22 + 0xc) + uVar5 * 2)) {
        puVar20 = puVar19 + 1;
        *puVar19 = sVar4 + (short)iVar16 + (short)uVar24;
      }
      uVar8 = uVar24;
      if (puVar18 < (ushort *)(*(long *)(piVar22 + 10) + uVar5 * 2)) {
        iVar25 = 0;
        puVar17 = puVar18 + 1;
        uVar6 = *puVar18;
        puVar19 = puVar20;
LAB_183ca54bc:
        puVar18 = puVar17;
        puVar20 = puVar19;
        uVar8 = uVar24;
        uVar24 = uVar24 + uVar6;
        goto LAB_183ca54c4;
      }
      goto LAB_183ca5d18;
    }
    if ((byte)cVar2 < 5) {
      uVar5 = (ulong)(uint)piVar22[0xe];
      puVar17 = puVar18;
      if ((puVar19 != puVar21) && ((int)uVar24 <= (int)uVar8)) {
        do {
          if ((ushort *)(*(long *)(piVar22 + 10) + uVar5 * 2) <= puVar17 + 1) break;
          uVar24 = uVar24 + *puVar17 + (uint)puVar17[1];
          puVar17 = puVar17 + 2;
        } while ((int)uVar24 <= (int)uVar8);
      }
      uVar6 = *(ushort *)(lVar10 + 0x1841d96a2);
      if (puVar19 < (ushort *)(*(long *)(piVar22 + 0xc) + uVar5 * 2)) {
        puVar20 = puVar19 + 1;
        *puVar19 = uVar6 + sVar4 + (short)iVar16 + (short)uVar24;
      }
      uVar8 = uVar24 + uVar6;
      if (puVar17 < (ushort *)(*(long *)(piVar22 + 10) + uVar5 * 2)) {
        iVar25 = 0;
        puVar18 = puVar17 + 1;
        uVar24 = uVar24 + *puVar17;
        goto LAB_183ca54c4;
      }
      goto LAB_183ca5d18;
    }
    if (cVar2 == (code)0x5) {
      if ((puVar19 != puVar21) && ((int)uVar24 <= (int)uVar8)) {
        do {
          if ((ushort *)(*(long *)(piVar22 + 10) + (ulong)(uint)piVar22[0xe] * 2) <= puVar18 + 1)
          break;
          uVar24 = uVar24 + *puVar18 + (uint)puVar18[1];
          puVar18 = puVar18 + 2;
        } while ((int)uVar24 <= (int)uVar8);
      }
      iVar16 = uVar8 + *(ushort *)(lVar10 + 0x1841d96a2);
      iVar3 = uVar24 - iVar16;
      if (iVar16 <= (int)uVar24) {
        if (puVar19 < (ushort *)(*(long *)(piVar22 + 0xc) + (ulong)(uint)piVar22[0xe] * 2)) {
          puVar20 = puVar19 + 1;
          *puVar19 = (short)iVar3 + sVar4;
        }
        iVar25 = 0;
        uVar8 = iVar3 + uVar8;
        puVar18 = puVar18 + -1;
        uVar24 = uVar24 - *puVar18;
        goto LAB_183ca54c4;
      }
      goto LAB_183ca5cfc;
    }
    if (cVar2 != (code)0x6) {
      if (cVar2 != (code)0xc) goto LAB_183ca5cf4;
      if (puVar19 < (ushort *)(*(long *)(piVar22 + 0xc) + (ulong)(uint)piVar22[0xe] * 2)) {
        *puVar19 = uVar7 - (short)uVar8;
        puVar19 = puVar19 + 1;
      }
      if (iVar9 < 4) {
        uVar5 = (**(code **)(piVar22 + 0x10))(*(undefined8 *)(piVar22 + 0x12));
        if ((int)uVar5 == -1) {
          if (piVar22[5] == 0) goto LAB_183ca603c;
          uVar23 = piVar22[4];
          iVar9 = 4;
        }
        else {
          uVar23 = piVar22[4] |
                   (uint)(byte)_TIFFBitRevTable[uVar5 & 0xff] << (ulong)(piVar22[5] & 0x1f);
          iVar9 = piVar22[5] + 8;
        }
      }
      if ((uVar23 & 0xf) != 0) {
        piVar22[7] = 1;
      }
      piVar22[4] = uVar23 >> 4;
      piVar22[5] = iVar9 + -4;
      piVar22[6] = 1;
      goto LAB_183ca5ef0;
    }
    if (puVar19 < (ushort *)(*(long *)(piVar22 + 0xc) + (ulong)(uint)piVar22[0xe] * 2)) {
      *puVar19 = uVar7 - (short)uVar8;
      puVar19 = puVar19 + 1;
    }
    goto LAB_183ca5cfc;
  }
  uVar8 = 0;
  goto LAB_183ca5d18;
LAB_183ca4bd0:
  bVar1 = true;
  if ((uVar12 & 1) == 0) goto LAB_183ca4bd8;
LAB_183ca4f0c:
  if (!bVar1) {
    iVar9 = piVar22[5];
    goto LAB_183ca4f14;
  }
  goto LAB_183ca5a74;
LAB_183ca4ec8:
  uVar24 = piVar22[6];
  if ((1 < (int)uVar24) && (uVar24 != 6)) {
    func_0x00018813ad80(*_DAT_1e0186228,"Line %d: bad RTC (%d EOLs)\n");
    uVar24 = piVar22[6];
  }
  bVar1 = 5 < uVar24;
  if ((uVar12 & 1) != 0) goto LAB_183ca4f0c;
LAB_183ca4bd8:
  if (!bVar1) {
    iVar9 = piVar22[5];
LAB_183ca4be8:
    iVar11 = 0;
    piVar22[6] = 0;
    puVar20 = *(ushort **)(piVar22 + 0xc);
    iVar25 = piVar22[3];
    puVar21 = puVar20;
LAB_183ca4c10:
    iVar16 = 0;
    do {
      uVar7 = (ushort)iVar25;
      if (iVar9 < 0xc) {
        uVar5 = (**(code **)(piVar22 + 0x10))(*(undefined8 *)(piVar22 + 0x12));
        if ((int)uVar5 == -1) {
          if (piVar22[5] == 0) goto LAB_183ca4fc0;
LAB_183ca4c88:
          iVar9 = 0xc;
        }
        else {
          uVar12 = piVar22[5];
          iVar9 = uVar12 + 8;
          piVar22[4] = piVar22[4] |
                       (uint)(byte)_TIFFBitRevTable[uVar5 & 0xff] << (ulong)(uVar12 & 0x1f);
          piVar22[5] = iVar9;
          if ((int)uVar12 < 4) {
            uVar5 = (**(code **)(piVar22 + 0x10))(*(undefined8 *)(piVar22 + 0x12));
            if ((int)uVar5 == -1) goto LAB_183ca4c88;
            piVar22[4] = piVar22[4] |
                         (uint)(byte)_TIFFBitRevTable[uVar5 & 0xff] << (ulong)(piVar22[5] & 0x1f);
            iVar9 = piVar22[5] + 8;
          }
        }
      }
      lVar10 = ((ulong)(uint)piVar22[4] & 0xfff) * 4;
      iVar9 = iVar9 - (uint)*(byte *)(lVar10 + 0x1841d98a1);
      uVar12 = (uint)piVar22[4] >> (ulong)(*(byte *)(lVar10 + 0x1841d98a1) & 0x1f);
      piVar22[4] = uVar12;
      piVar22[5] = iVar9;
      cVar2 = _pdf_TIFFFaxWhiteTable[lVar10];
      if ((byte)cVar2 < 0xb) {
        if (cVar2 != (code)0x9) goto LAB_183ca4cd4;
      }
      else if (cVar2 != (code)0xb) goto LAB_183ca4df8;
      iVar11 = iVar11 + (uint)*(ushort *)(lVar10 + 0x1841d98a2);
      iVar16 = iVar16 + (uint)*(ushort *)(lVar10 + 0x1841d98a2);
    } while( true );
  }
  goto LAB_183ca5a74;
LAB_183ca4cd4:
  if (cVar2 == (code)0x7) {
    uVar6 = *(ushort *)(lVar10 + 0x1841d98a2);
    puVar19 = puVar21;
    if (puVar21 < (ushort *)(*(long *)(piVar22 + 0xc) + (ulong)(uint)piVar22[0xe] * 2)) {
      puVar19 = puVar21 + 1;
      *puVar21 = uVar6 + (short)iVar16;
    }
    iVar11 = iVar11 + (uint)uVar6;
    puVar21 = puVar19;
    if (iVar11 < iVar25) {
      iVar16 = 0;
      do {
        if (iVar9 < 0xd) {
          uVar5 = (**(code **)(piVar22 + 0x10))(*(undefined8 *)(piVar22 + 0x12));
          if ((int)uVar5 == -1) {
            if (piVar22[5] == 0) goto LAB_183ca4fc0;
            uVar12 = piVar22[4];
LAB_183ca4d84:
            iVar9 = 0xd;
          }
          else {
            uVar24 = piVar22[5];
            uVar12 = piVar22[4] |
                     (uint)(byte)_TIFFBitRevTable[uVar5 & 0xff] << (ulong)(uVar24 & 0x1f);
            iVar9 = uVar24 + 8;
            piVar22[4] = uVar12;
            piVar22[5] = iVar9;
            if ((int)uVar24 < 5) {
              uVar5 = (**(code **)(piVar22 + 0x10))(*(undefined8 *)(piVar22 + 0x12));
              uVar12 = piVar22[4];
              if ((int)uVar5 == -1) goto LAB_183ca4d84;
              uVar12 = uVar12 | (uint)(byte)_TIFFBitRevTable[uVar5 & 0xff] <<
                                (ulong)(piVar22[5] & 0x1f);
              iVar9 = piVar22[5] + 8;
            }
          }
        }
        lVar10 = (ulong)(uVar12 & 0x1fff) * 4;
        iVar9 = iVar9 - (uint)*(byte *)(lVar10 + 0x1841dd8a1);
        uVar12 = uVar12 >> (ulong)(*(byte *)(lVar10 + 0x1841dd8a1) & 0x1f);
        piVar22[4] = uVar12;
        piVar22[5] = iVar9;
        cVar2 = _pdf_TIFFFaxBlackTable[lVar10];
        if (1 < (byte)cVar2 - 10) goto LAB_183ca4dc0;
        iVar11 = iVar11 + (uint)*(ushort *)(lVar10 + 0x1841dd8a2);
        iVar16 = iVar16 + (uint)*(ushort *)(lVar10 + 0x1841dd8a2);
      } while( true );
    }
    goto LAB_183ca4e30;
  }
  goto LAB_183ca4e0c;
LAB_183ca4fc0:
  puVar19 = puVar21;
  if ((iVar16 != 0) &&
     (puVar21 < (ushort *)(*(long *)(piVar22 + 0xc) + (ulong)(uint)piVar22[0xe] * 2))) {
    puVar19 = puVar21 + 1;
    *puVar21 = (ushort)iVar16;
  }
  if (iVar11 == iVar25) goto LAB_183ca5a74;
  bVar1 = iVar25 <= iVar11;
  if ((iVar25 < iVar11) && (puVar20 < puVar19)) {
    do {
      puVar19 = puVar19 + -1;
      iVar11 = iVar11 - (uint)*puVar19;
      bVar1 = iVar25 < iVar11;
    } while ((iVar25 < iVar11 && puVar20 <= puVar19) && (iVar11 <= iVar25 || puVar19 != puVar20));
  }
  if (iVar11 < iVar25) {
    puVar21 = (ushort *)(*(long *)(piVar22 + 0xc) + (ulong)(uint)piVar22[0xe] * 2);
    puVar18 = puVar19;
    if ((((uint)((int)puVar19 - (int)puVar20) >> 1 & 1) != 0) && (puVar19 < puVar21)) {
      puVar18 = puVar19 + 1;
      *puVar19 = 0;
    }
    if (puVar18 < puVar21) {
      param_3 = 0;
      *puVar18 = uVar7 - ((ushort)iVar11 & ((ushort)(iVar11 >> 0x1f) ^ 0xffff));
      goto LAB_183ca5a78;
    }
  }
  else if (bVar1) {
    puVar21 = (ushort *)(*(long *)(piVar22 + 0xc) + (ulong)(uint)piVar22[0xe] * 2);
    puVar20 = puVar19;
    if (puVar19 < puVar21) {
      puVar20 = puVar19 + 1;
      *puVar19 = uVar7;
    }
    if (puVar20 < puVar21) {
      param_3 = 0;
      *puVar20 = 0;
      goto LAB_183ca5a78;
    }
  }
  goto LAB_183ca5a74;
LAB_183ca4dc0:
  if ((byte)cVar2 == 8) {
    uVar6 = *(ushort *)(lVar10 + 0x1841dd8a2);
    if (puVar19 < (ushort *)(*(long *)(piVar22 + 0xc) + (ulong)(uint)piVar22[0xe] * 2)) {
      puVar21 = puVar19 + 1;
      *puVar19 = uVar6 + (short)iVar16;
    }
    iVar11 = iVar11 + (uint)uVar6;
    if (iVar25 <= iVar11) goto LAB_183ca4e30;
    goto LAB_183ca4c10;
  }
LAB_183ca4df8:
  if (cVar2 == (code)0xc) {
    piVar22[6] = 1;
    puVar19 = puVar21;
    goto LAB_183ca4e14;
  }
LAB_183ca4e0c:
  piVar22[7] = 1;
  puVar19 = puVar21;
LAB_183ca4e14:
  puVar21 = puVar19;
  if ((iVar16 != 0) &&
     (puVar19 < (ushort *)(*(long *)(piVar22 + 0xc) + (ulong)(uint)piVar22[0xe] * 2))) {
    puVar21 = puVar19 + 1;
    *puVar19 = (ushort)iVar16;
  }
LAB_183ca4e30:
  if (iVar11 != iVar25) {
    bVar1 = iVar25 < iVar11;
    if ((iVar25 < iVar11) && (puVar20 < puVar21)) {
      do {
        puVar21 = puVar21 + -1;
        iVar11 = iVar11 - (uint)*puVar21;
        bVar1 = iVar25 < iVar11;
      } while ((iVar25 < iVar11 && puVar20 <= puVar21) && (iVar11 <= iVar25 || puVar21 != puVar20));
    }
    if (iVar11 < iVar25) {
      puVar19 = (ushort *)(*(long *)(piVar22 + 0xc) + (ulong)(uint)piVar22[0xe] * 2);
      puVar18 = puVar21;
      if ((((uint)((int)puVar21 - (int)puVar20) >> 1 & 1) != 0) && (puVar21 < puVar19)) {
        puVar18 = puVar21 + 1;
        *puVar21 = 0;
      }
      puVar21 = puVar18;
      if (puVar18 < puVar19) {
        *puVar18 = uVar7 - ((ushort)iVar11 & ((ushort)(iVar11 >> 0x1f) ^ 0xffff));
        puVar21 = puVar18 + 1;
      }
    }
    else if (bVar1) {
      puVar19 = (ushort *)(*(long *)(piVar22 + 0xc) + (ulong)(uint)piVar22[0xe] * 2);
      puVar18 = puVar21;
      if (puVar21 < puVar19) {
        puVar18 = puVar21 + 1;
        *puVar21 = uVar7;
      }
      puVar21 = puVar18;
      if (puVar18 < puVar19) {
        puVar21 = puVar18 + 1;
        *puVar18 = 0;
      }
    }
  }
  if (piVar22[7] != 0) goto LAB_183ca5a74;
  _fill_runs(param_2,puVar20,puVar21,iVar25,piVar22[1] & 0x10);
  goto LAB_183ca5df8;
LAB_183ca5800:
  if (cVar2 == (code)0x7) {
    uVar6 = *(ushort *)(lVar10 + 0x1841d98a2);
    puVar19 = puVar20;
    if (puVar20 < (ushort *)(*(long *)(piVar22 + 0xc) + (ulong)(uint)piVar22[0xe] * 2)) {
      puVar19 = puVar20 + 1;
      *puVar20 = uVar6 + (short)iVar25;
    }
    uVar24 = uVar24 + uVar6;
    puVar20 = puVar19;
    if ((int)uVar24 < (int)uVar12) {
      iVar25 = 0;
      do {
        if (iVar9 < 0xd) {
          uVar5 = (**(code **)(piVar22 + 0x10))(*(undefined8 *)(piVar22 + 0x12));
          if ((int)uVar5 == -1) {
            if (piVar22[5] == 0) goto LAB_183ca5b3c;
            uVar23 = piVar22[4];
LAB_183ca58b0:
            iVar9 = 0xd;
          }
          else {
            uVar8 = piVar22[5];
            uVar23 = piVar22[4] |
                     (uint)(byte)_TIFFBitRevTable[uVar5 & 0xff] << (ulong)(uVar8 & 0x1f);
            iVar9 = uVar8 + 8;
            piVar22[4] = uVar23;
            piVar22[5] = iVar9;
            if ((int)uVar8 < 5) {
              uVar5 = (**(code **)(piVar22 + 0x10))(*(undefined8 *)(piVar22 + 0x12));
              uVar23 = piVar22[4];
              if ((int)uVar5 == -1) goto LAB_183ca58b0;
              uVar23 = uVar23 | (uint)(byte)_TIFFBitRevTable[uVar5 & 0xff] <<
                                (ulong)(piVar22[5] & 0x1f);
              iVar9 = piVar22[5] + 8;
            }
          }
        }
        lVar10 = (ulong)(uVar23 & 0x1fff) * 4;
        iVar9 = iVar9 - (uint)*(byte *)(lVar10 + 0x1841dd8a1);
        uVar23 = uVar23 >> (ulong)(*(byte *)(lVar10 + 0x1841dd8a1) & 0x1f);
        piVar22[4] = uVar23;
        piVar22[5] = iVar9;
        cVar2 = _pdf_TIFFFaxBlackTable[lVar10];
        if (1 < (byte)cVar2 - 10) goto LAB_183ca58ec;
        uVar24 = uVar24 + *(ushort *)(lVar10 + 0x1841dd8a2);
        iVar25 = iVar25 + (uint)*(ushort *)(lVar10 + 0x1841dd8a2);
      } while( true );
    }
    goto LAB_183ca595c;
  }
  goto LAB_183ca5938;
LAB_183ca58ec:
  if ((byte)cVar2 == 8) {
    uVar6 = *(ushort *)(lVar10 + 0x1841dd8a2);
    if (puVar19 < (ushort *)(*(long *)(piVar22 + 0xc) + (ulong)(uint)piVar22[0xe] * 2)) {
      puVar20 = puVar19 + 1;
      *puVar19 = uVar6 + (short)iVar25;
    }
    uVar24 = uVar24 + uVar6;
    if ((int)uVar12 <= (int)uVar24) goto LAB_183ca595c;
    goto LAB_183ca573c;
  }
LAB_183ca5924:
  if (cVar2 == (code)0xc) {
    piVar22[6] = 1;
    puVar19 = puVar20;
    goto LAB_183ca5940;
  }
LAB_183ca5938:
  piVar22[7] = 1;
  puVar19 = puVar20;
LAB_183ca5940:
  puVar20 = puVar19;
  if ((iVar25 != 0) &&
     (puVar19 < (ushort *)(*(long *)(piVar22 + 0xc) + (ulong)(uint)piVar22[0xe] * 2))) {
    puVar20 = puVar19 + 1;
    *puVar19 = (ushort)iVar25;
  }
LAB_183ca595c:
  if (uVar24 != uVar12) {
    bVar1 = (int)uVar12 <= (int)uVar24;
    puVar19 = puVar20;
    if (((int)uVar12 < (int)uVar24) && (puVar21 < puVar20)) {
      do {
        puVar19 = puVar19 + -1;
        uVar24 = uVar24 - *puVar19;
        bVar1 = (int)uVar12 < (int)uVar24;
      } while (((int)uVar12 < (int)uVar24 && puVar21 <= puVar19) &&
               ((int)uVar24 <= (int)uVar12 || puVar19 != puVar21));
    }
    if ((int)uVar12 <= (int)uVar24) goto LAB_183ca5d94;
    puVar18 = (ushort *)(*(long *)(piVar22 + 0xc) + (ulong)(uint)piVar22[0xe] * 2);
    puVar20 = puVar19;
    if ((((uint)((int)puVar19 - iVar11) >> 1 & 1) != 0) && (puVar19 < puVar18)) {
      puVar20 = puVar19 + 1;
      *puVar19 = 0;
    }
    if (puVar18 <= puVar20) goto LAB_183ca5dbc;
    uVar6 = (ushort)uVar24 & ((ushort)((int)uVar24 >> 0x1f) ^ 0xffff);
    goto LAB_183ca5d88;
  }
  goto LAB_183ca5dbc;
LAB_183ca55bc:
  if ((byte)_pdf_TIFFFaxBlackTable[lVar10] == 8) {
    uVar14 = (uint)*(ushort *)(lVar10 + 0x1841dd8a2);
    if (puVar19 < (ushort *)(*(long *)(piVar22 + 0xc) + (ulong)(uint)piVar22[0xe] * 2)) {
      *puVar19 = *(ushort *)(lVar10 + 0x1841dd8a2) + (short)iVar25;
      puVar19 = puVar19 + 1;
    }
    iVar25 = 0;
    do {
      uVar8 = uVar8 + uVar14;
      if (iVar9 < 0xc) {
        uVar5 = (**(code **)(piVar22 + 0x10))(*(undefined8 *)(piVar22 + 0x12));
        if ((int)uVar5 == -1) {
          if (piVar22[5] == 0) goto LAB_183ca603c;
          uVar23 = piVar22[4];
LAB_183ca5664:
          iVar9 = 0xc;
        }
        else {
          uVar14 = piVar22[5];
          uVar23 = piVar22[4] | (uint)(byte)_TIFFBitRevTable[uVar5 & 0xff] << (ulong)(uVar14 & 0x1f)
          ;
          iVar9 = uVar14 + 8;
          piVar22[4] = uVar23;
          piVar22[5] = iVar9;
          if ((int)uVar14 < 4) {
            uVar5 = (**(code **)(piVar22 + 0x10))(*(undefined8 *)(piVar22 + 0x12));
            uVar23 = piVar22[4];
            if ((int)uVar5 == -1) goto LAB_183ca5664;
            uVar23 = uVar23 | (uint)(byte)_TIFFBitRevTable[uVar5 & 0xff] <<
                              (ulong)(piVar22[5] & 0x1f);
            iVar9 = piVar22[5] + 8;
          }
        }
      }
      lVar10 = (ulong)(uVar23 & 0xfff) * 4;
      pcVar15 = _pdf_TIFFFaxWhiteTable + lVar10;
      iVar9 = iVar9 - (uint)*(byte *)(lVar10 + 0x1841d98a1);
      uVar23 = uVar23 >> (ulong)(*(byte *)(lVar10 + 0x1841d98a1) & 0x1f);
      piVar22[4] = uVar23;
      piVar22[5] = iVar9;
      cVar2 = *pcVar15;
      if (cVar2 != (code)0x9 && cVar2 != (code)0xb) goto LAB_183ca56a8;
      uVar14 = (uint)*(ushort *)(lVar10 + 0x1841d98a2);
      iVar25 = iVar25 + uVar14;
    } while( true );
  }
  goto LAB_183ca5cf4;
LAB_183ca56a8:
  puVar20 = puVar19;
  if (cVar2 == (code)0x7) goto LAB_183ca56b0;
  goto LAB_183ca5cf4;
LAB_183ca54d4:
  if (cVar2 == (code)0x7) {
    uVar14 = (uint)*(ushort *)(lVar10 + 0x1841d98a2);
    if (puVar19 < (ushort *)(*(long *)(piVar22 + 0xc) + (ulong)(uint)piVar22[0xe] * 2)) {
      puVar20 = puVar19 + 1;
      *puVar19 = *(ushort *)(lVar10 + 0x1841d98a2) + (short)iVar25;
    }
    iVar25 = 0;
    do {
      uVar8 = uVar8 + uVar14;
      puVar19 = puVar20;
      if (iVar9 < 0xd) {
        uVar5 = (**(code **)(piVar22 + 0x10))(*(undefined8 *)(piVar22 + 0x12));
        if ((int)uVar5 == -1) {
          if (piVar22[5] == 0) goto LAB_183ca603c;
          uVar23 = piVar22[4];
LAB_183ca557c:
          iVar9 = 0xd;
        }
        else {
          uVar14 = piVar22[5];
          uVar23 = piVar22[4] | (uint)(byte)_TIFFBitRevTable[uVar5 & 0xff] << (ulong)(uVar14 & 0x1f)
          ;
          iVar9 = uVar14 + 8;
          piVar22[4] = uVar23;
          piVar22[5] = iVar9;
          if ((int)uVar14 < 5) {
            uVar5 = (**(code **)(piVar22 + 0x10))(*(undefined8 *)(piVar22 + 0x12));
            uVar23 = piVar22[4];
            if ((int)uVar5 == -1) goto LAB_183ca557c;
            uVar23 = uVar23 | (uint)(byte)_TIFFBitRevTable[uVar5 & 0xff] <<
                              (ulong)(piVar22[5] & 0x1f);
            iVar9 = piVar22[5] + 8;
          }
        }
      }
      lVar10 = (ulong)(uVar23 & 0x1fff) * 4;
      pcVar15 = _pdf_TIFFFaxBlackTable + lVar10;
      iVar9 = iVar9 - (uint)*(byte *)(lVar10 + 0x1841dd8a1);
      uVar23 = uVar23 >> (ulong)(*(byte *)(lVar10 + 0x1841dd8a1) & 0x1f);
      piVar22[4] = uVar23;
      piVar22[5] = iVar9;
      if (1 < (byte)*pcVar15 - 10) goto LAB_183ca569c;
      uVar14 = (uint)*(ushort *)(lVar10 + 0x1841dd8a2);
      iVar25 = iVar25 + uVar14;
    } while( true );
  }
LAB_183ca5cf4:
  piVar22[7] = 1;
  puVar19 = puVar20;
LAB_183ca5cfc:
  puVar20 = puVar19;
  if (iVar25 != 0) goto LAB_183ca5d00;
  goto LAB_183ca5d18;
LAB_183ca569c:
  if ((byte)*pcVar15 == 8) {
LAB_183ca56b0:
    uVar6 = *(ushort *)(pcVar15 + 2);
    uVar14 = piVar22[0xe];
    puVar20 = puVar19;
    if (puVar19 < (ushort *)(*(long *)(piVar22 + 0xc) + (ulong)uVar14 * 2)) {
      puVar20 = puVar19 + 1;
      *puVar19 = uVar6 + (short)iVar25;
    }
    uVar8 = uVar8 + uVar6;
    if ((puVar20 != puVar21) && ((int)uVar24 <= (int)uVar8 && (int)uVar24 < (int)uVar12)) {
      do {
        if ((ushort *)(*(long *)(piVar22 + 10) + (ulong)uVar14 * 2) <= puVar18 + 1) break;
        uVar24 = uVar24 + *puVar18 + (uint)puVar18[1];
        puVar18 = puVar18 + 2;
      } while ((int)uVar24 <= (int)uVar8 && (int)uVar24 < (int)uVar12);
    }
    iVar25 = 0;
LAB_183ca54c4:
    iVar16 = -uVar8;
    puVar19 = puVar20;
    if ((int)uVar12 <= (int)uVar8) goto LAB_183ca5c24;
    goto LAB_183ca509c;
  }
  goto LAB_183ca5cf4;
LAB_183ca5c24:
  if (iVar25 != 0) {
    if (iVar9 < 1) {
      uVar5 = (**(code **)(piVar22 + 0x10))(*(undefined8 *)(piVar22 + 0x12));
      if ((int)uVar5 == -1) {
        if (piVar22[5] == 0) {
LAB_183ca6040:
          if (puVar19 < (ushort *)(*(long *)(piVar22 + 0xc) + (ulong)(uint)piVar22[0xe] * 2)) {
            *puVar19 = (ushort)iVar25;
            puVar19 = puVar19 + 1;
          }
LAB_183ca6058:
          if (uVar8 == uVar12) goto LAB_183ca5ef0;
          bVar1 = (int)uVar12 <= (int)uVar8;
          if (((int)uVar12 < (int)uVar8) && (puVar21 < puVar19)) {
            do {
              puVar19 = puVar19 + -1;
              uVar8 = uVar8 - *puVar19;
              bVar1 = (int)uVar12 < (int)uVar8;
            } while (((int)uVar12 < (int)uVar8 && puVar21 <= puVar19) &&
                     ((int)uVar8 <= (int)uVar12 || puVar19 != puVar21));
          }
          if ((int)uVar12 <= (int)uVar8) goto LAB_183ca60c8;
          puVar21 = (ushort *)(*(long *)(piVar22 + 0xc) + (ulong)(uint)piVar22[0xe] * 2);
          puVar20 = puVar19;
          if ((((uint)((int)puVar19 - iVar11) >> 1 & 1) != 0) && (puVar19 < puVar21)) {
            puVar20 = puVar19 + 1;
            *puVar19 = 0;
          }
          if (puVar20 < puVar21) {
            uVar7 = (ushort)uVar8 & ((ushort)((int)uVar8 >> 0x1f) ^ 0xffff);
            goto LAB_183ca5f5c;
          }
          goto LAB_183ca5a74;
        }
        iVar9 = 1;
        piVar22[5] = 1;
        uVar23 = piVar22[4];
      }
      else {
        uVar23 = piVar22[4] |
                 (uint)(byte)_TIFFBitRevTable[uVar5 & 0xff] << (ulong)(piVar22[5] & 0x1f);
        iVar9 = piVar22[5] + 8;
        piVar22[4] = uVar23;
        piVar22[5] = iVar9;
      }
    }
    if ((uVar23 & 1) == 0) {
      piVar22[7] = 1;
    }
    else {
      piVar22[4] = uVar23 >> 1;
      piVar22[5] = iVar9 + -1;
    }
LAB_183ca5d00:
    puVar20 = puVar19;
    if (puVar19 < (ushort *)(*(long *)(piVar22 + 0xc) + (ulong)(uint)piVar22[0xe] * 2)) {
      *puVar19 = (ushort)iVar25;
      puVar20 = puVar19 + 1;
    }
  }
LAB_183ca5d18:
  if (uVar8 != uVar12) {
    bVar1 = (int)uVar12 < (int)uVar8;
    puVar19 = puVar20;
    if (((int)uVar12 < (int)uVar8) && (puVar21 < puVar20)) {
      do {
        puVar19 = puVar19 + -1;
        uVar8 = uVar8 - *puVar19;
        bVar1 = (int)uVar12 < (int)uVar8;
      } while (((int)uVar12 < (int)uVar8 && puVar21 <= puVar19) &&
               ((int)uVar8 <= (int)uVar12 || puVar19 != puVar21));
    }
    if ((int)uVar8 < (int)uVar12) {
      puVar18 = (ushort *)(*(long *)(piVar22 + 0xc) + (ulong)(uint)piVar22[0xe] * 2);
      puVar20 = puVar19;
      if ((((uint)((int)puVar19 - iVar11) >> 1 & 1) != 0) && (puVar19 < puVar18)) {
        puVar20 = puVar19 + 1;
        *puVar19 = 0;
      }
      if (puVar20 < puVar18) {
        uVar6 = (ushort)uVar8 & ((ushort)((int)uVar8 >> 0x1f) ^ 0xffff);
LAB_183ca5d88:
        *puVar20 = uVar7 - uVar6;
        puVar20 = puVar20 + 1;
      }
    }
    else {
LAB_183ca5d94:
      puVar20 = puVar19;
      if (bVar1) {
        puVar18 = (ushort *)(*(long *)(piVar22 + 0xc) + (ulong)(uint)piVar22[0xe] * 2);
        puVar17 = puVar19;
        if (puVar19 < puVar18) {
          puVar17 = puVar19 + 1;
          *puVar19 = uVar7;
        }
        puVar20 = puVar17;
        if (puVar17 < puVar18) {
          puVar20 = puVar17 + 1;
          *puVar17 = 0;
        }
      }
    }
  }
  goto LAB_183ca5dbc;
LAB_183ca479c:
  if ((byte)_pdf_TIFFFaxBlackTable[lVar10] == 8) {
    uVar14 = (uint)*(ushort *)(lVar10 + 0x1841dd8a2);
    if (puVar19 < (ushort *)(*(long *)(piVar22 + 0xc) + (ulong)(uint)piVar22[0xe] * 2)) {
      *puVar19 = *(ushort *)(lVar10 + 0x1841dd8a2) + (short)iVar25;
      puVar19 = puVar19 + 1;
    }
    iVar25 = 0;
    do {
      uVar23 = uVar23 + uVar14;
      if (iVar11 < 0xc) {
        uVar5 = (**(code **)(piVar22 + 0x10))(*(undefined8 *)(piVar22 + 0x12));
        if ((int)uVar5 == -1) {
          if (piVar22[5] == 0) goto LAB_183ca5ec8;
          uVar8 = piVar22[4];
LAB_183ca4844:
          iVar11 = 0xc;
        }
        else {
          uVar14 = piVar22[5];
          uVar8 = piVar22[4] | (uint)(byte)_TIFFBitRevTable[uVar5 & 0xff] << (ulong)(uVar14 & 0x1f);
          iVar11 = uVar14 + 8;
          piVar22[4] = uVar8;
          piVar22[5] = iVar11;
          if ((int)uVar14 < 4) {
            uVar5 = (**(code **)(piVar22 + 0x10))(*(undefined8 *)(piVar22 + 0x12));
            uVar8 = piVar22[4];
            if ((int)uVar5 == -1) goto LAB_183ca4844;
            uVar8 = uVar8 | (uint)(byte)_TIFFBitRevTable[uVar5 & 0xff] << (ulong)(piVar22[5] & 0x1f)
            ;
            iVar11 = piVar22[5] + 8;
          }
        }
      }
      lVar10 = (ulong)(uVar8 & 0xfff) * 4;
      pcVar15 = _pdf_TIFFFaxWhiteTable + lVar10;
      iVar11 = iVar11 - (uint)*(byte *)(lVar10 + 0x1841d98a1);
      uVar8 = uVar8 >> (ulong)(*(byte *)(lVar10 + 0x1841d98a1) & 0x1f);
      piVar22[4] = uVar8;
      piVar22[5] = iVar11;
      cVar2 = *pcVar15;
      if (cVar2 != (code)0x9 && cVar2 != (code)0xb) goto LAB_183ca4890;
      uVar14 = (uint)*(ushort *)(lVar10 + 0x1841d98a2);
      iVar25 = iVar25 + uVar14;
    } while( true );
  }
  goto LAB_183ca5a38;
LAB_183ca4890:
  puVar20 = puVar19;
  if (cVar2 == (code)0x7) goto LAB_183ca4898;
  goto LAB_183ca5a38;
LAB_183ca46bc:
  if (cVar2 == (code)0x7) {
    uVar14 = (uint)*(ushort *)(lVar10 + 0x1841d98a2);
    if (puVar19 < (ushort *)(*(long *)(piVar22 + 0xc) + (ulong)(uint)piVar22[0xe] * 2)) {
      puVar20 = puVar19 + 1;
      *puVar19 = *(ushort *)(lVar10 + 0x1841d98a2) + (short)iVar25;
    }
    iVar25 = 0;
    do {
      uVar23 = uVar23 + uVar14;
      puVar19 = puVar20;
      if (iVar11 < 0xd) {
        uVar5 = (**(code **)(piVar22 + 0x10))(*(undefined8 *)(piVar22 + 0x12));
        if ((int)uVar5 == -1) {
          if (piVar22[5] == 0) goto LAB_183ca5ec8;
          uVar8 = piVar22[4];
LAB_183ca4764:
          iVar11 = 0xd;
        }
        else {
          uVar14 = piVar22[5];
          uVar8 = piVar22[4] | (uint)(byte)_TIFFBitRevTable[uVar5 & 0xff] << (ulong)(uVar14 & 0x1f);
          iVar11 = uVar14 + 8;
          piVar22[4] = uVar8;
          piVar22[5] = iVar11;
          if ((int)uVar14 < 5) {
            uVar5 = (**(code **)(piVar22 + 0x10))(*(undefined8 *)(piVar22 + 0x12));
            uVar8 = piVar22[4];
            if ((int)uVar5 == -1) goto LAB_183ca4764;
            uVar8 = uVar8 | (uint)(byte)_TIFFBitRevTable[uVar5 & 0xff] << (ulong)(piVar22[5] & 0x1f)
            ;
            iVar11 = piVar22[5] + 8;
          }
        }
      }
      lVar10 = (ulong)(uVar8 & 0x1fff) * 4;
      pcVar15 = _pdf_TIFFFaxBlackTable + lVar10;
      iVar11 = iVar11 - (uint)*(byte *)(lVar10 + 0x1841dd8a1);
      uVar8 = uVar8 >> (ulong)(*(byte *)(lVar10 + 0x1841dd8a1) & 0x1f);
      piVar22[4] = uVar8;
      piVar22[5] = iVar11;
      if (1 < (byte)*pcVar15 - 10) goto LAB_183ca4884;
      uVar14 = (uint)*(ushort *)(lVar10 + 0x1841dd8a2);
      iVar25 = iVar25 + uVar14;
    } while( true );
  }
LAB_183ca5a38:
  piVar22[7] = 1;
  puVar19 = puVar20;
LAB_183ca5a40:
  puVar20 = puVar19;
  if (iVar25 != 0) goto LAB_183ca5a44;
  goto LAB_183ca5a5c;
LAB_183ca4884:
  if ((byte)*pcVar15 == 8) {
LAB_183ca4898:
    uVar6 = *(ushort *)(pcVar15 + 2);
    uVar14 = piVar22[0xe];
    puVar20 = puVar19;
    if (puVar19 < (ushort *)(*(long *)(piVar22 + 0xc) + (ulong)uVar14 * 2)) {
      puVar20 = puVar19 + 1;
      *puVar19 = uVar6 + (short)iVar25;
    }
    uVar23 = uVar23 + uVar6;
    if ((puVar20 != puVar21) && ((int)uVar24 <= (int)uVar23 && (int)uVar24 < (int)uVar12)) {
      do {
        if ((ushort *)(*(long *)(piVar22 + 10) + (ulong)uVar14 * 2) <= puVar18 + 1) break;
        uVar24 = uVar24 + *puVar18 + (uint)puVar18[1];
        puVar18 = puVar18 + 2;
      } while ((int)uVar24 <= (int)uVar23 && (int)uVar24 < (int)uVar12);
    }
    iVar25 = 0;
LAB_183ca46ac:
    iVar16 = -uVar23;
    puVar19 = puVar20;
    if ((int)uVar12 <= (int)uVar23) goto LAB_183ca4f50;
    goto LAB_183ca4278;
  }
  goto LAB_183ca5a38;
LAB_183ca4f50:
  if (iVar25 != 0) {
    if (iVar11 < 1) {
      uVar5 = (**(code **)(piVar22 + 0x10))(*(undefined8 *)(piVar22 + 0x12));
      if ((int)uVar5 == -1) {
        if (piVar22[5] == 0) {
LAB_183ca5ecc:
          if (puVar19 < (ushort *)(*(long *)(piVar22 + 0xc) + (ulong)(uint)piVar22[0xe] * 2)) {
            *puVar19 = (ushort)iVar25;
            puVar19 = puVar19 + 1;
          }
LAB_183ca5ee4:
          if (uVar23 == uVar12) {
LAB_183ca5ef0:
            param_3 = 0;
            goto LAB_183ca5a78;
          }
          bVar1 = (int)uVar12 < (int)uVar23;
          if (((int)uVar12 < (int)uVar23) && (puVar21 < puVar19)) {
            do {
              puVar19 = puVar19 + -1;
              uVar23 = uVar23 - *puVar19;
              bVar1 = (int)uVar12 < (int)uVar23;
            } while (((int)uVar12 < (int)uVar23 && puVar21 <= puVar19) &&
                     ((int)uVar23 <= (int)uVar12 || puVar19 != puVar21));
          }
          if ((int)uVar12 <= (int)uVar23) goto LAB_183ca60c8;
          puVar21 = (ushort *)(*(long *)(piVar22 + 0xc) + (ulong)(uint)piVar22[0xe] * 2);
          puVar20 = puVar19;
          if ((((uint)((int)puVar19 - iVar9) >> 1 & 1) != 0) && (puVar19 < puVar21)) {
            puVar20 = puVar19 + 1;
            *puVar19 = 0;
          }
          if (puVar20 < puVar21) {
            uVar7 = (ushort)uVar23 & ((ushort)((int)uVar23 >> 0x1f) ^ 0xffff);
            goto LAB_183ca5f5c;
          }
          goto LAB_183ca5a74;
        }
        uVar8 = piVar22[4];
        iVar11 = 1;
      }
      else {
        uVar8 = piVar22[4] |
                (uint)(byte)_TIFFBitRevTable[uVar5 & 0xff] << (ulong)(piVar22[5] & 0x1f);
        piVar22[4] = uVar8;
        iVar11 = piVar22[5] + 8;
      }
      piVar22[5] = iVar11;
    }
    if ((uVar8 & 1) == 0) {
      piVar22[7] = 1;
    }
    else {
      piVar22[4] = uVar8 >> 1;
      piVar22[5] = iVar11 + -1;
    }
LAB_183ca5a44:
    puVar20 = puVar19;
    if (puVar19 < (ushort *)(*(long *)(piVar22 + 0xc) + (ulong)(uint)piVar22[0xe] * 2)) {
      *puVar19 = (ushort)iVar25;
      puVar20 = puVar19 + 1;
    }
  }
  goto LAB_183ca5a5c;
LAB_183ca5b3c:
  puVar19 = puVar20;
  if ((iVar25 != 0) &&
     (puVar20 < (ushort *)(*(long *)(piVar22 + 0xc) + (ulong)(uint)piVar22[0xe] * 2))) {
    puVar19 = puVar20 + 1;
    *puVar20 = (ushort)iVar25;
  }
  if (uVar24 == uVar12) goto LAB_183ca5a74;
  bVar1 = (int)uVar12 <= (int)uVar24;
  if (((int)uVar12 < (int)uVar24) && (puVar21 < puVar19)) {
    do {
      puVar19 = puVar19 + -1;
      uVar24 = uVar24 - *puVar19;
      bVar1 = (int)uVar12 < (int)uVar24;
    } while (((int)uVar12 < (int)uVar24 && puVar21 <= puVar19) &&
             ((int)uVar24 <= (int)uVar12 || puVar19 != puVar21));
  }
  if ((int)uVar24 < (int)uVar12) {
    puVar21 = (ushort *)(*(long *)(piVar22 + 0xc) + (ulong)(uint)piVar22[0xe] * 2);
    puVar20 = puVar19;
    if ((((uint)((int)puVar19 - iVar11) >> 1 & 1) != 0) && (puVar19 < puVar21)) {
      puVar20 = puVar19 + 1;
      *puVar19 = 0;
    }
    if (puVar20 < puVar21) {
      uVar7 = (ushort)uVar24 & ((ushort)((int)uVar24 >> 0x1f) ^ 0xffff);
LAB_183ca5f5c:
      param_3 = 0;
      *puVar20 = (short)uVar12 - uVar7;
      goto LAB_183ca5a78;
    }
  }
  else {
LAB_183ca60c8:
    if (bVar1) {
      puVar21 = (ushort *)(*(long *)(piVar22 + 0xc) + (ulong)(uint)piVar22[0xe] * 2);
      puVar20 = puVar19;
      if (puVar19 < puVar21) {
        puVar20 = puVar19 + 1;
        *puVar19 = (ushort)uVar12;
      }
      if (puVar20 < puVar21) {
        param_3 = 0;
        *puVar20 = 0;
        goto LAB_183ca5a78;
      }
    }
  }
LAB_183ca5a74:
  param_3 = 0;
LAB_183ca5a78:
  *(undefined1 *)(param_1 + 8) = 1;
  return param_3;
}



/* ==== _ccitt_fax_filter_finalize @ 183ca60f8 size=100 ==== */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Possible PIC construction at 0x000183ca6120: Changing call to branch */

void _ccitt_fax_filter_finalize(long *param_1)

{
  code *pcVar1;
  long lVar2;
  ulong unaff_x30;
  
  if (param_1 == (long *)0x0) {
    return;
  }
  lVar2 = param_1[4];
  if (lVar2 != 0) {
    if (*(long *)(lVar2 + 0x20) != 0) {
      halt_baddata();
    }
    func_0x000188138390(lVar2);
  }
  if (*param_1 != 0) {
    func_0x000188141240();
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0xc471,0x183ca6154);
  (*pcVar1)();
}



/* ==== _ccitt_fax_filter_getc @ 183ca615c size=4 ==== */

ulong _ccitt_fax_filter_getc(long param_1)

{
  int iVar1;
  long lVar2;
  byte *pbVar3;
  
  lVar2 = *(long *)(param_1 + 0x78);
  if (lVar2 == 0) {
    iVar1 = _CGPDFSourceRefill(param_1);
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    lVar2 = *(long *)(param_1 + 0x78);
  }
  pbVar3 = *(byte **)(param_1 + 0x80);
  *(long *)(param_1 + 0x78) = lVar2 + -1;
  *(byte **)(param_1 + 0x80) = pbVar3 + 1;
  return (ulong)*pbVar3;
}



/* ==== __ZN19JBIG2HuffmanDecoder9decodeIntEPiPK17JBIG2HuffmanTable @ 183cf631c size=260 ==== */

undefined8
__ZN19JBIG2HuffmanDecoder9decodeIntEPiPK17JBIG2HuffmanTable
          (undefined8 param_1,int *param_2,int *param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  if (param_3[2] == -1) {
    return 0;
  }
  uVar5 = 0;
  uVar6 = 0;
  uVar7 = 0;
  piVar4 = param_3;
  while( true ) {
    for (; uVar6 < (uint)piVar4[1]; uVar6 = uVar6 + 1) {
      uVar1 = __ZN19JBIG2HuffmanDecoder7readBitEv(param_1);
      uVar5 = uVar1 | uVar5 << 1;
    }
    if (uVar5 == piVar4[3]) break;
    uVar7 = uVar7 + 1;
    piVar4 = param_3 + (ulong)uVar7 * 4;
    if (piVar4[2] == -1) {
      return 0;
    }
  }
  iVar3 = piVar4[2];
  if (iVar3 == 0) {
    iVar3 = *piVar4;
  }
  else {
    if (iVar3 == -2) {
      return 0;
    }
    if (iVar3 == -3) {
      iVar3 = *piVar4;
      iVar2 = __ZN19JBIG2HuffmanDecoder8readBitsEj(param_1,0x20);
      iVar3 = iVar3 - iVar2;
    }
    else {
      iVar2 = *piVar4;
      iVar3 = __ZN19JBIG2HuffmanDecoder8readBitsEj(param_1);
      iVar3 = iVar3 + iVar2;
    }
  }
  *param_2 = iVar3;
  return 1;
}



/* ==== __ZN19JBIG2HuffmanDecoder7readBitEv @ 183cf6420 size=104 ==== */

uint __ZN19JBIG2HuffmanDecoder7readBitEv(undefined8 *param_1)

{
  uint uVar1;
  uint uVar2;
  
  if (*(int *)((long)param_1 + 0xc) == 0) {
    uVar1 = (**(code **)(*(long *)*param_1 + 0x20))();
    *(uint *)(param_1 + 1) = uVar1;
    uVar2 = 7;
  }
  else {
    uVar1 = *(uint *)(param_1 + 1);
    uVar2 = *(int *)((long)param_1 + 0xc) - 1;
  }
  *(uint *)((long)param_1 + 0xc) = uVar2;
  return uVar1 >> (ulong)(uVar2 & 0x1f) & 1;
}



/* ==== __ZN19JBIG2HuffmanDecoder8readBitsEj @ 183cf6488 size=264 ==== */

uint __ZN19JBIG2HuffmanDecoder8readBitsEj(undefined8 *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(uint *)((long)param_1 + 0xc);
  if (uVar1 < param_2) {
    uVar2 = *(uint *)(param_1 + 1) & (-1 << (ulong)(uVar1 & 0x1f) ^ 0xffffffffU);
    *(undefined4 *)((long)param_1 + 0xc) = 0;
    for (param_2 = param_2 - uVar1; 7 < param_2; param_2 = param_2 - 8) {
      uVar1 = (**(code **)(*(long *)*param_1 + 0x20))();
      uVar2 = uVar1 & 0xff | uVar2 << 8;
    }
    if (param_2 != 0) {
      uVar1 = (**(code **)(*(long *)*param_1 + 0x20))();
      *(uint *)(param_1 + 1) = uVar1;
      *(uint *)((long)param_1 + 0xc) = 8 - param_2;
      uVar2 = uVar1 >> (ulong)(8 - param_2 & 0x1f) & (-1 << (ulong)(param_2 & 0x1f) ^ 0xffffffffU) |
              uVar2 << (ulong)(param_2 & 0x1f);
    }
  }
  else {
    uVar2 = 0xffffffff;
    if (param_2 != 0x20) {
      uVar2 = ~(-1 << (ulong)(param_2 & 0x1f));
    }
    uVar2 = *(uint *)(param_1 + 1) >> (ulong)(uVar1 - param_2 & 0x1f) & uVar2;
    *(uint *)((long)param_1 + 0xc) = uVar1 - param_2;
  }
  return uVar2;
}



/* ==== __ZN19JBIG2HuffmanDecoder10buildTableEP17JBIG2HuffmanTablej @ 183cf6590 size=332 ==== */

void __ZN19JBIG2HuffmanDecoder10buildTableEP17JBIG2HuffmanTablej(long param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  ulong uVar5;
  long lVar6;
  int iVar7;
  ulong uVar8;
  ulong uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  ulong uVar12;
  
  if (param_2 == 0) {
    uVar5 = 0;
    uVar9 = 0;
  }
  else {
    uVar8 = 0;
    uVar5 = (ulong)param_2;
    uVar10 = param_2;
    do {
      uVar10 = uVar10 - 1;
      uVar12 = uVar8;
      uVar13 = uVar10;
      while (uVar9 = uVar8, *(int *)(param_1 + uVar12 * 0x10 + 4) == 0) {
        uVar12 = uVar12 + 1;
        uVar13 = uVar13 - 1;
        if (param_2 == (uint)uVar12) goto LAB_183cf6660;
      }
      if (param_2 == (uint)uVar12) break;
      uVar1 = (uint)uVar12 + 1;
      uVar9 = (ulong)uVar1;
      if (uVar1 < param_2) {
        do {
          uVar1 = *(uint *)(param_1 + uVar9 * 0x10 + 4);
          if (uVar1 != 0) {
            uVar11 = (uint)uVar9;
            if (*(uint *)(param_1 + (uVar12 & 0xffffffff) * 0x10 + 4) <= uVar1) {
              uVar11 = (uint)uVar12;
            }
            uVar12 = (ulong)uVar11;
          }
          uVar9 = uVar9 + 1;
          uVar13 = uVar13 - 1;
        } while (uVar13 != 0);
      }
      if (uVar8 != (uVar12 & 0xffffffff)) {
        puVar3 = (undefined8 *)(param_1 + (uVar12 & 0xffffffff) * 0x10);
        uVar16 = puVar3[1];
        uVar14 = *puVar3;
        uVar9 = uVar12 & 0xffffffff;
        while (uVar8 < uVar9) {
          puVar3 = (undefined8 *)(param_1 + (uVar9 - 1) * 0x10);
          uVar15 = *puVar3;
          puVar4 = (undefined8 *)(param_1 + uVar9 * 0x10);
          puVar4[1] = puVar3[1];
          *puVar4 = uVar15;
          uVar9 = uVar9 - 1;
        }
        puVar3 = (undefined8 *)(param_1 + uVar8 * 0x10);
        puVar3[1] = uVar16;
        *puVar3 = uVar14;
      }
      uVar8 = uVar8 + 1;
      uVar9 = uVar5;
    } while (uVar8 != uVar5);
LAB_183cf6660:
    uVar9 = uVar9 & 0xffffffff;
  }
  puVar3 = (undefined8 *)(param_1 + uVar5 * 0x10);
  uVar14 = *puVar3;
  puVar4 = (undefined8 *)(param_1 + uVar9 * 0x10);
  puVar4[1] = puVar3[1];
  *puVar4 = uVar14;
  if ((*(int *)(param_1 + 8) != -1) &&
     (*(undefined4 *)(param_1 + 0xc) = 0, *(int *)(param_1 + 0x18) != -1)) {
    lVar6 = param_1 + 0x10;
    iVar7 = 1;
    uVar10 = 2;
    do {
      iVar2 = iVar7 << (ulong)(*(int *)(lVar6 + 4) -
                               *(int *)(param_1 + (ulong)(uVar10 - 2) * 0x10 + 4) & 0x1f);
      iVar7 = iVar2 + 1;
      *(int *)(lVar6 + 0xc) = iVar2;
      lVar6 = param_1 + (ulong)uVar10 * 0x10;
      uVar10 = uVar10 + 1;
    } while (*(int *)(lVar6 + 8) != -1);
  }
  return;
}



/* ==== __ZN15JBIG2MMRDecoder12getWhiteCodeEv @ 183cf66dc size=416 ==== */

long __ZN15JBIG2MMRDecoder12getWhiteCodeEv(undefined8 *param_1)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
  uint uVar5;
  code *pcVar6;
  
  uVar3 = *(uint *)((long)param_1 + 0xc);
  if (uVar3 == 0) {
    uVar2 = (**(code **)(*(long *)*param_1 + 0x20))();
    uVar3 = 8;
    *(uint *)(param_1 + 1) = uVar2 & 0xff;
    *(undefined4 *)((long)param_1 + 0xc) = 8;
    *(int *)(param_1 + 2) = *(int *)(param_1 + 2) + 1;
  }
  do {
    if (uVar3 < 0xb) {
      uVar2 = *(uint *)(param_1 + 1);
      if (uVar3 == 10) goto LAB_183cf67a8;
      uVar5 = uVar2 << (ulong)(9 - uVar3 & 0x1f);
LAB_183cf67bc:
      pcVar6 = whiteTab2 + (ulong)(uVar5 & 0x1ff) * 4;
    }
    else {
      uVar2 = *(uint *)(param_1 + 1);
      if ((uVar2 >> (ulong)(uVar3 - 7 & 0x1f) & 0x7f) != 0) {
LAB_183cf67a8:
        uVar5 = uVar2 >> (ulong)(uVar3 - 9 & 0x1f);
        goto LAB_183cf67bc;
      }
      uVar5 = uVar2 << (ulong)(0xc - uVar3 & 0x1f);
      if (0xc < uVar3) {
        uVar5 = uVar2 >> (ulong)(uVar3 - 0xc & 0x1f);
      }
      pcVar6 = whiteTab1 + (ulong)(uVar5 & 0x1f) * 4;
    }
    sVar1 = *(short *)pcVar6;
    if (0 < sVar1 && (int)sVar1 <= (int)uVar3) {
      *(uint *)((long)param_1 + 0xc) = uVar3 - (int)sVar1;
      return (long)*(short *)(pcVar6 + 2);
    }
    if (0xb < uVar3) {
      uVar4 = (**(code **)(*(long *)*param_1 + 0x28))();
      __Z5erroriPKcz(uVar4,"Bad white code in JBIG2 MMR stream");
      *(int *)((long)param_1 + 0xc) = *(int *)((long)param_1 + 0xc) + -1;
      return 1;
    }
    uVar3 = (**(code **)(*(long *)*param_1 + 0x20))();
    *(uint *)(param_1 + 1) = uVar3 & 0xff | uVar2 << 8;
    uVar3 = (int)*(undefined8 *)((long)param_1 + 0xc) + 8;
    *(ulong *)((long)param_1 + 0xc) =
         CONCAT44((int)((ulong)*(undefined8 *)((long)param_1 + 0xc) >> 0x20) + 1,uVar3);
  } while( true );
}



/* ==== __ZN15JBIG2MMRDecoder12getBlackCodeEv @ 183cf687c size=504 ==== */

long __ZN15JBIG2MMRDecoder12getBlackCodeEv(undefined8 *param_1)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
  uint uVar5;
  code *pcVar6;
  
  uVar3 = *(uint *)((long)param_1 + 0xc);
  if (uVar3 == 0) {
    uVar2 = (**(code **)(*(long *)*param_1 + 0x20))();
    uVar3 = 8;
    *(uint *)(param_1 + 1) = uVar2 & 0xff;
    *(undefined4 *)((long)param_1 + 0xc) = 8;
    *(int *)(param_1 + 2) = *(int *)(param_1 + 2) + 1;
  }
  do {
    if (uVar3 < 10) {
      uVar2 = *(uint *)(param_1 + 1);
      if (6 < uVar3) goto LAB_183cf695c;
      uVar5 = uVar2 << (ulong)(6 - uVar3 & 0x1f);
LAB_183cf69b0:
      pcVar6 = blackTab3 + (ulong)(uVar5 & 0x3f) * 4;
    }
    else {
      uVar2 = *(uint *)(param_1 + 1);
      if ((uVar2 >> (ulong)(uVar3 - 6 & 0x1f) & 0x3f) == 0) {
        uVar5 = uVar2 << (ulong)(0xd - uVar3 & 0x1f);
        if (0xd < uVar3) {
          uVar5 = uVar2 >> (ulong)(uVar3 - 0xd & 0x1f);
        }
        pcVar6 = blackTab1 + (ulong)(uVar5 & 0x7f) * 4;
      }
      else {
LAB_183cf695c:
        uVar5 = uVar2 >> (ulong)(uVar3 - 6 & 0x1f);
        if ((uVar2 >> (ulong)(uVar3 - 4 & 0x1f) & 0xf) != 0 || (uVar5 & 3) == 0) goto LAB_183cf69b0;
        uVar5 = uVar2 << (ulong)(0xc - uVar3 & 0x1f);
        if (0xc < uVar3) {
          uVar5 = uVar2 >> (ulong)(uVar3 - 0xc & 0x1f);
        }
        if ((uVar5 & 0xff) < 0x40) {
LAB_183cf6a0c:
          uVar4 = (**(code **)(*(long *)*param_1 + 0x28))();
          __Z5erroriPKcz(uVar4,"Bad black code in JBIG2 MMR stream");
          *(int *)((long)param_1 + 0xc) = *(int *)((long)param_1 + 0xc) + -1;
          return 1;
        }
        pcVar6 = blackTab2 + (ulong)((uVar5 & 0xff) - 0x40) * 4;
      }
    }
    sVar1 = *(short *)pcVar6;
    if (0 < sVar1 && (int)sVar1 <= (int)uVar3) {
      *(uint *)((long)param_1 + 0xc) = uVar3 - (int)sVar1;
      return (long)*(short *)(pcVar6 + 2);
    }
    if (0xc < uVar3) goto LAB_183cf6a0c;
    uVar3 = (**(code **)(*(long *)*param_1 + 0x20))();
    *(uint *)(param_1 + 1) = uVar3 & 0xff | uVar2 << 8;
    uVar3 = (int)*(undefined8 *)((long)param_1 + 0xc) + 8;
    *(ulong *)((long)param_1 + 0xc) =
         CONCAT44((int)((ulong)*(undefined8 *)((long)param_1 + 0xc) >> 0x20) + 1,uVar3);
  } while( true );
}



/* ==== __ZN11JBIG2BitmapC2Ejii @ 183cf6a74 size=416 ==== */

/* WARNING: Removing unreachable block (ram,0x000183cf6bbc) */

undefined8 *
__ZN11JBIG2BitmapC2Ejii(undefined8 *param_1,undefined4 param_2,int param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  ulong uVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  ulong uVar9;
  ulong uVar10;
  
  *(undefined4 *)(param_1 + 1) = param_2;
  *param_1 = &DAT_1e2234570;
  *(int *)(param_1 + 2) = param_3;
  uVar4 = pacga((long)param_3,(ulong)(param_1 + 2) & 0xffffffffffff | 0x5363000000000000);
  param_1[3] = uVar4;
  *(uint *)(param_1 + 4) = param_4;
  uVar9 = (ulong)(param_1 + 4) & 0xffffffffffff | 0x5363000000000000;
  lVar6 = pacga((long)(int)param_4,uVar9);
  uVar1 = (int)(param_3 + 7U) >> 3;
  uVar5 = (ulong)uVar1;
  *(uint *)(param_1 + 6) = uVar1;
  param_1[5] = lVar6;
  uVar10 = (ulong)(param_1 + 6) & 0xffffffffffff | 0x5363000000000000;
  lVar7 = pacga((long)((ulong)(param_3 + 7U) << 0x20) >> 0x23,uVar10);
  param_1[7] = lVar7;
  if (((param_3 < 1) || ((int)param_4 < 1)) || ((int)uVar1 < 1)) {
LAB_183cf6b28:
    param_4 = 0xffffffff;
    *(undefined4 *)(param_1 + 4) = 0xffffffff;
    lVar6 = pacga(0xffffffffffffffff,uVar9);
    param_1[5] = lVar6;
    uVar5 = 2;
    *(undefined4 *)(param_1 + 6) = 2;
    lVar7 = pacga(2,uVar10);
    param_1[7] = lVar7;
  }
  else {
    uVar2 = 0;
    if (uVar1 != 0) {
      uVar2 = 0x7ffffffe / uVar1;
    }
    if (uVar2 <= param_4) goto LAB_183cf6b28;
  }
  lVar8 = pacga((long)(int)param_4,uVar9);
  if ((lVar8 == lVar6) && (lVar6 = pacga(uVar5,uVar10), lVar6 == lVar7)) {
    lVar6 = __Z13gmalloc_typediy((int)uVar5 * param_4 + 1,0x100004077774924);
    if (lVar6 == 0) {
      param_1[8] = 0;
    }
    else {
      param_1[8] = lVar6;
      if ((lVar6 != 0) && (lVar6 != 0)) {
        lVar7 = pacga((long)*(int *)(param_1 + 4),uVar9);
        if (lVar7 == param_1[5]) {
          lVar7 = pacga((long)*(int *)(param_1 + 6),uVar10);
          if (lVar7 == param_1[7]) {
            *(undefined1 *)(lVar6 + (long)*(int *)(param_1 + 6) * (long)*(int *)(param_1 + 4)) = 0;
            return param_1;
          }
        }
        goto LAB_183cf6c10;
      }
    }
    return param_1;
  }
LAB_183cf6c10:
  puVar3 = (undefined8 *)func_0x000188138260();
  return puVar3;
}



/* ==== __ZN11JBIG2BitmapD1Ev @ 183cf6c14 size=120 ==== */

/* WARNING: Removing unreachable block (ram,0x000183cf6c68) */

undefined8 * __ZN11JBIG2BitmapD1Ev(undefined8 *param_1)

{
  long lVar1;
  
  *param_1 = &DAT_1e2234570;
  lVar1 = param_1[8];
  if (lVar1 == 0) {
    lVar1 = 0;
  }
  func_0x000188138390(lVar1);
  return param_1;
}



/* ==== __ZN11JBIG2BitmapD0Ev @ 183cf6c8c size=152 ==== */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x000183cf6ce0) */

void __ZN11JBIG2BitmapD0Ev(undefined8 *param_1)

{
  code *pcVar1;
  long lVar2;
  ulong unaff_x30;
  
  *param_1 = &DAT_1e2234570;
  lVar2 = param_1[8];
  if (lVar2 == 0) {
    lVar2 = 0;
  }
  func_0x000188138390(lVar2);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0x183cf6d20);
    (*pcVar1)();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* ==== __ZN11JBIG2Bitmap8getSliceEjjjj @ 183cf6d24 size=256 ==== */

/* WARNING: Removing unreachable block (ram,0x000183cf6da4) */

long __ZN11JBIG2Bitmap8getSliceEjjjj
               (undefined8 param_1,int param_2,int param_3,undefined8 param_4,undefined8 param_5)

{
  int iVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  
  lVar2 = func_0x00018814d110(0x48,0x10d1c40b539ea8f);
  __ZN11JBIG2BitmapC2Ejii(lVar2,0,param_4,param_5);
  if ((*(long *)(lVar2 + 0x40) == 0) || (*(long *)(lVar2 + 0x40) == 0)) {
    lVar2 = 0;
  }
  else {
    __ZN11JBIG2Bitmap11clearToZeroEv(lVar2);
    if ((int)param_5 != 0) {
      iVar3 = 0;
      do {
        if ((int)param_4 != 0) {
          iVar4 = 0;
          do {
            iVar1 = __ZN11JBIG2Bitmap8getPixelEii(param_1,param_2 + iVar4,iVar3 + param_3);
            if (iVar1 != 0) {
              __ZN11JBIG2Bitmap8setPixelEii(lVar2,iVar4,iVar3);
            }
            iVar4 = iVar4 + 1;
          } while ((int)param_4 != iVar4);
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 != (int)param_5);
    }
  }
  return lVar2;
}



/* ==== __ZN11JBIG2Bitmap11clearToZeroEv @ 183cf6e3c size=140 ==== */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x000183cf6e68) */

void __ZN11JBIG2Bitmap11clearToZeroEv(long param_1)

{
  code *pcVar1;
  long lVar2;
  ulong unaff_x30;
  
  lVar2 = pacga((long)*(int *)(param_1 + 0x20),
                (ulong)(param_1 + 0x20) & 0xffffffffffff | 0x5363000000000000);
  if ((lVar2 == *(long *)(param_1 + 0x28)) &&
     (lVar2 = pacga((long)*(int *)(param_1 + 0x30),
                    (ulong)(param_1 + 0x30) & 0xffffffffffff | 0x5363000000000000),
     lVar2 == *(long *)(param_1 + 0x38))) {
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0x183cf6ec0);
    (*pcVar1)();
  }
  func_0x000188138260();
  return;
}



/* ==== __ZN11JBIG2Bitmap8getPixelEii @ 183cf6ec8 size=212 ==== */

/* WARNING: Removing unreachable block (ram,0x000183cf6f48) */

ulong __ZN11JBIG2Bitmap8getPixelEii(long param_1,uint param_2,int param_3)

{
  int iVar1;
  ulong uVar2;
  long lVar3;
  
  if ((int)param_2 < 0) {
    return 0;
  }
  iVar1 = *(int *)(param_1 + 0x10);
  lVar3 = pacga((long)iVar1,(ulong)(param_1 + 0x10) & 0xffffffffffff | 0x5363000000000000);
  if (lVar3 == *(long *)(param_1 + 0x18)) {
    if (param_3 < 0) {
      return 0;
    }
    if (iVar1 <= (int)param_2) {
      return 0;
    }
    iVar1 = *(int *)(param_1 + 0x20);
    lVar3 = pacga((long)iVar1,(ulong)(param_1 + 0x20) & 0xffffffffffff | 0x5363000000000000);
    if (lVar3 == *(long *)(param_1 + 0x28)) {
      if (iVar1 <= param_3) {
        return 0;
      }
      iVar1 = *(int *)(param_1 + 0x30);
      lVar3 = pacga((long)iVar1,(ulong)(param_1 + 0x30) & 0xffffffffffff | 0x5363000000000000);
      if (lVar3 == *(long *)(param_1 + 0x38)) {
        return (ulong)(*(byte *)(*(long *)(param_1 + 0x40) +
                                (long)(int)(iVar1 * param_3 + (param_2 >> 3))) >>
                       (ulong)((param_2 ^ 0xffffffff) & 7) & 1);
      }
    }
  }
  uVar2 = func_0x000188138260();
  return uVar2;
}



/* ==== __ZN11JBIG2Bitmap8setPixelEii @ 183cf6f9c size=204 ==== */

/* WARNING: Removing unreachable block (ram,0x000183cf7018) */

void __ZN11JBIG2Bitmap8setPixelEii(long param_1,uint param_2,int param_3)

{
  int iVar1;
  long lVar2;
  
  if (-1 < (int)param_2) {
    iVar1 = *(int *)(param_1 + 0x10);
    lVar2 = pacga((long)iVar1,(ulong)(param_1 + 0x10) & 0xffffffffffff | 0x5363000000000000);
    if (lVar2 != *(long *)(param_1 + 0x18)) {
LAB_183cf7064:
      func_0x000188138260();
      return;
    }
    if ((-1 < param_3) && ((int)param_2 < iVar1)) {
      iVar1 = *(int *)(param_1 + 0x20);
      lVar2 = pacga((long)iVar1,(ulong)(param_1 + 0x20) & 0xffffffffffff | 0x5363000000000000);
      if (lVar2 != *(long *)(param_1 + 0x28)) goto LAB_183cf7064;
      if (param_3 < iVar1) {
        iVar1 = *(int *)(param_1 + 0x30);
        lVar2 = pacga((long)iVar1,(ulong)(param_1 + 0x30) & 0xffffffffffff | 0x5363000000000000);
        if (lVar2 != *(long *)(param_1 + 0x38)) goto LAB_183cf7064;
        iVar1 = iVar1 * param_3 + (param_2 >> 3);
        *(byte *)(*(long *)(param_1 + 0x40) + (long)iVar1) =
             *(byte *)(*(long *)(param_1 + 0x40) + (long)iVar1) |
             (byte)(1 << (ulong)((param_2 ^ 0xffffffff) & 7));
      }
    }
  }
  return;
}



/* ==== __ZN11JBIG2Bitmap6expandEij @ 183cf7068 size=580 ==== */

/* WARNING: Removing unreachable block (ram,0x000183cf71a8) */
/* WARNING: Removing unreachable block (ram,0x000183cf716c) */
/* WARNING: Removing unreachable block (ram,0x000183cf7274) */
/* WARNING: Removing unreachable block (ram,0x000183cf7108) */

void __ZN11JBIG2Bitmap6expandEij(long param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined8 uVar5;
  long lVar6;
  long lVar7;
  long *plVar8;
  ulong uVar9;
  ulong uVar10;
  
  iVar1 = *(int *)(param_1 + 0x20);
  uVar10 = (ulong)(param_1 + 0x20) & 0xffffffffffff | 0x5363000000000000;
  lVar6 = pacga((long)iVar1,uVar10);
  if (lVar6 != *(long *)(param_1 + 0x28)) goto LAB_183cf72a8;
  if (param_2 <= iVar1) {
    return;
  }
  uVar2 = *(uint *)(param_1 + 0x30);
  uVar9 = (ulong)(param_1 + 0x30) & 0xffffffffffff | 0x5363000000000000;
  lVar6 = pacga((long)(int)uVar2,uVar9);
  if (lVar6 != *(long *)(param_1 + 0x38)) goto LAB_183cf72a8;
  if ((int)uVar2 < 1) {
    return;
  }
  uVar4 = 0;
  if (uVar2 != 0) {
    uVar4 = 0x7ffffffe / uVar2;
  }
  if ((int)uVar4 <= param_2) {
    return;
  }
  plVar8 = (long *)(param_1 + 0x40);
  lVar6 = *plVar8;
  if (lVar6 == 0) {
    lVar6 = 0;
  }
  lVar6 = __Z14grealloc_typedPviy(lVar6,uVar2 * param_2 + 1,0x100004077774924);
  if (lVar6 == 0) {
    lVar6 = 0;
    *plVar8 = 0;
    lVar7 = 0;
    if (param_3 == 0) goto LAB_183cf7204;
LAB_183cf71b8:
    iVar1 = *(int *)(param_1 + 0x20);
    lVar6 = pacga((long)iVar1,uVar10);
    if (lVar6 != *(long *)(param_1 + 0x28)) goto LAB_183cf72a8;
    iVar3 = *(int *)(param_1 + 0x30);
    lVar6 = pacga((long)iVar3,uVar9);
    if (lVar6 != *(long *)(param_1 + 0x38)) goto LAB_183cf72a8;
    func_0x0001881384f0(lVar7 + iVar3 * iVar1,0xff,(long)(iVar3 * (param_2 - iVar1)));
  }
  else {
    *plVar8 = lVar6;
    if (param_3 != 0) {
      lVar7 = lVar6;
      if (lVar6 == 0) {
        lVar7 = 0;
      }
      goto LAB_183cf71b8;
    }
    if (lVar6 == 0) {
      lVar6 = 0;
    }
LAB_183cf7204:
    iVar1 = *(int *)(param_1 + 0x20);
    lVar7 = pacga((long)iVar1,uVar10);
    if (lVar7 != *(long *)(param_1 + 0x28)) goto LAB_183cf72a8;
    iVar3 = *(int *)(param_1 + 0x30);
    lVar7 = pacga((long)iVar3,uVar9);
    if (lVar7 != *(long *)(param_1 + 0x38)) goto LAB_183cf72a8;
    func_0x0001881382e0(lVar6 + iVar3 * iVar1,(long)(iVar3 * (param_2 - iVar1)));
  }
  *(int *)(param_1 + 0x20) = param_2;
  uVar5 = pacga((long)param_2,uVar10);
  *(undefined8 *)(param_1 + 0x28) = uVar5;
  lVar6 = pacga((long)*(int *)(param_1 + 0x30),uVar9);
  if (lVar6 == *(long *)(param_1 + 0x38)) {
    *(undefined1 *)(*(long *)(param_1 + 0x40) + (long)*(int *)(param_1 + 0x30) * (long)param_2) = 0;
    return;
  }
LAB_183cf72a8:
  func_0x000188138260();
  return;
}



/* ==== __ZN11JBIG2Bitmap10clearToOneEv @ 183cf72ac size=144 ==== */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x000183cf72d8) */

void __ZN11JBIG2Bitmap10clearToOneEv(long param_1)

{
  code *pcVar1;
  long lVar2;
  ulong unaff_x30;
  
  lVar2 = pacga((long)*(int *)(param_1 + 0x20),
                (ulong)(param_1 + 0x20) & 0xffffffffffff | 0x5363000000000000);
  if ((lVar2 == *(long *)(param_1 + 0x28)) &&
     (lVar2 = pacga((long)*(int *)(param_1 + 0x30),
                    (ulong)(param_1 + 0x30) & 0xffffffffffff | 0x5363000000000000),
     lVar2 == *(long *)(param_1 + 0x38))) {
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0x183cf7334);
    (*pcVar1)();
  }
  func_0x000188138260();
  return;
}



/* ==== __ZN11JBIG2Bitmap7combineEPS_iij @ 183cf733c size=1576 ==== */

/* WARNING: Removing unreachable block (ram,0x000183cf74f8) */
/* WARNING: Removing unreachable block (ram,0x000183cf76f4) */
/* WARNING: Removing unreachable block (ram,0x000183cf75f8) */
/* WARNING: Removing unreachable block (ram,0x000183cf7760) */
/* WARNING: Removing unreachable block (ram,0x000183cf7640) */
/* WARNING: Removing unreachable block (ram,0x000183cf78a0) */
/* WARNING: Removing unreachable block (ram,0x000183cf753c) */
/* WARNING: Removing unreachable block (ram,0x000183cf771c) */

void __ZN11JBIG2Bitmap7combineEPS_iij
               (long param_1,long param_2,uint param_3,int param_4,int param_5)

{
  ulong uVar1;
  byte *pbVar2;
  uint uVar3;
  byte bVar4;
  byte bVar5;
  uint uVar6;
  byte bVar7;
  uint uVar8;
  uint uVar9;
  byte bVar10;
  uint uVar11;
  byte *pbVar12;
  uint uVar13;
  long lVar14;
  ulong uVar15;
  byte bVar16;
  int iVar17;
  long lVar18;
  ulong uVar19;
  byte bVar20;
  byte *pbVar21;
  byte bVar22;
  
  if ((param_2 == 0) || (param_4 == -0x80000000)) {
    return;
  }
  uVar8 = *(uint *)(param_2 + 0x20);
  lVar14 = pacga((long)(int)uVar8,(ulong)(param_2 + 0x20) & 0xffffffffffff | 0x5363000000000000);
  if (lVar14 == *(long *)(param_2 + 0x28)) {
    iVar17 = *(int *)(param_1 + 0x20);
    lVar14 = pacga((long)iVar17,(ulong)(param_1 + 0x20) & 0xffffffffffff | 0x5363000000000000);
    if (lVar14 == *(long *)(param_1 + 0x28)) {
      uVar13 = -param_4 & param_4 >> 0x1f;
      uVar6 = iVar17 - param_4;
      if ((int)(uVar8 + param_4) <= iVar17) {
        uVar6 = uVar8;
      }
      if ((int)uVar6 <= (int)uVar13) {
        return;
      }
      if ((int)(uVar13 ^ 0x7fffffff) < param_4) {
        return;
      }
      if ((int)(uVar6 ^ 0x7fffffff) < param_4) {
        return;
      }
      uVar8 = *(uint *)(param_1 + 0x30);
      uVar15 = (ulong)(param_1 + 0x30) & 0xffffffffffff | 0x5363000000000000;
      lVar14 = pacga((long)(int)uVar8,uVar15);
      if (lVar14 == *(long *)(param_1 + 0x38)) {
        if (0 < (int)uVar8) {
          uVar9 = 0;
          if (uVar8 != 0) {
            uVar9 = 0x7fffffff / uVar8;
          }
          if ((int)uVar9 < (int)(uVar13 + param_4) || (int)uVar9 < (int)(uVar6 + param_4)) {
            return;
          }
        }
        iVar17 = *(int *)(param_2 + 0x10);
        lVar14 = pacga((long)iVar17,(ulong)(param_2 + 0x10) & 0xffffffffffff | 0x5363000000000000);
        if (lVar14 == *(long *)(param_2 + 0x18)) {
          uVar8 = *(uint *)(param_1 + 0x10);
          lVar14 = pacga((long)(int)uVar8,
                         (ulong)(param_1 + 0x10) & 0xffffffffffff | 0x5363000000000000);
          if (lVar14 == *(long *)(param_1 + 0x18)) {
            uVar3 = param_3 & 0x7ffffff8 & ((int)param_3 >> 0x1f ^ 0xffffffffU);
            uVar9 = iVar17 + param_3;
            if ((int)uVar8 <= (int)uVar9) {
              uVar9 = uVar8;
            }
            if ((int)uVar9 <= (int)uVar3) {
              return;
            }
            uVar8 = param_3 & 7;
            bVar4 = 0xff;
            if ((uVar9 & 7) != 0) {
              bVar4 = (byte)(0xff << (ulong)(8 - (uVar9 & 7) & 0x1f));
            }
            uVar1 = param_2 + 0x30;
            uVar19 = (ulong)(param_3 >> 3);
            do {
              lVar14 = *(long *)(param_1 + 0x40);
              bVar16 = (byte)(0xff >> (ulong)(uVar9 & 7));
              if (uVar3 == (uVar9 - 1 & 0xfffffff8)) {
                if ((int)param_3 < 0) {
                  if (lVar14 == 0) {
                    lVar14 = 0;
                  }
                  lVar18 = pacga((long)*(int *)(param_1 + 0x30),uVar15);
                  if (lVar18 == *(long *)(param_1 + 0x38)) {
                    lVar18 = pacga((long)*(int *)(param_2 + 0x30),
                                   uVar1 & 0xffffffffffff | 0x5363000000000000);
                    if (lVar18 == *(long *)(param_2 + 0x38)) {
                      pbVar12 = (byte *)(lVar14 + (long)*(int *)(param_1 + 0x30) *
                                                  (long)(int)(uVar13 + param_4));
                      bVar10 = *(byte *)(*(long *)(param_2 + 0x40) +
                                         (long)*(int *)(param_2 + 0x30) * (long)(int)uVar13 +
                                        (ulong)(-param_3 >> 3));
                      bVar7 = *pbVar12;
                      bVar20 = bVar4 & bVar10;
                      bVar22 = bVar20 | bVar16 & bVar7;
                      if (param_5 != 4) {
                        bVar22 = bVar7;
                      }
                      bVar5 = (bVar10 ^ 0xff) & bVar4 ^ bVar7;
                      if (param_5 != 3) {
                        bVar5 = bVar22;
                      }
                      bVar22 = bVar20 ^ bVar7;
                      if (param_5 != 2) {
                        bVar22 = bVar5;
                      }
                      bVar20 = bVar20 | bVar7;
                      bVar16 = (bVar16 | bVar10) & bVar7;
                      if (param_5 != 1) {
                        bVar16 = bVar7;
                      }
                      goto LAB_183cf7924;
                    }
                  }
                  break;
                }
                lVar18 = pacga((long)*(int *)(param_1 + 0x30),uVar15);
                if (lVar18 != *(long *)(param_1 + 0x38)) break;
                lVar14 = lVar14 + (long)*(int *)(param_1 + 0x30) * (long)(int)(uVar13 + param_4);
                lVar18 = pacga((long)*(int *)(param_2 + 0x30),
                               uVar1 & 0xffffffffffff | 0x5363000000000000);
                if (lVar18 != *(long *)(param_2 + 0x38)) break;
                bVar20 = *(byte *)(lVar14 + uVar19);
                bVar7 = *(byte *)(*(long *)(param_2 + 0x40) +
                                 (long)*(int *)(param_2 + 0x30) * (long)(int)uVar13);
                bVar10 = bVar7 >> (ulong)uVar8 & bVar4;
                bVar22 = bVar10 | bVar20 & ~(bVar4 & (byte)(0xff >> (ulong)uVar8));
                if (param_5 != 4) {
                  bVar22 = bVar20;
                }
                bVar5 = (byte)((bVar7 ^ 0xff) >> (ulong)uVar8) & bVar4 ^ bVar20;
                if (param_5 != 3) {
                  bVar5 = bVar22;
                }
                bVar22 = bVar10 ^ bVar20;
                if (param_5 != 2) {
                  bVar22 = bVar5;
                }
                bVar16 = ((byte)((bVar7 | 0xff00) >> (ulong)uVar8) | bVar16) & bVar20;
                if (param_5 != 1) {
                  bVar16 = bVar20;
                }
                bVar20 = bVar10 | bVar20;
                if (param_5 != 0) {
                  bVar20 = bVar16;
                }
                if (param_5 < 2) {
                  bVar22 = bVar20;
                }
                *(byte *)(lVar14 + uVar19) = bVar22;
              }
              else {
                if ((int)param_3 < 0) {
                  lVar18 = pacga((long)*(int *)(param_1 + 0x30),uVar15);
                  if (lVar18 != *(long *)(param_1 + 0x38)) break;
                  pbVar12 = (byte *)(lVar14 + (long)*(int *)(param_1 + 0x30) *
                                              (long)(int)(uVar13 + param_4));
                  lVar14 = pacga((long)*(int *)(param_2 + 0x30),
                                 uVar1 & 0xffffffffffff | 0x5363000000000000);
                  if (lVar14 != *(long *)(param_2 + 0x38)) break;
                  iVar17 = 0;
                  pbVar21 = (byte *)(*(long *)(param_2 + 0x40) +
                                     (long)*(int *)(param_2 + 0x30) * (long)(int)uVar13 +
                                    (ulong)(-param_3 >> 3));
                  bVar22 = *pbVar21;
                }
                else {
                  lVar18 = pacga((long)*(int *)(param_1 + 0x30),uVar15);
                  if (lVar18 != *(long *)(param_1 + 0x38)) break;
                  pbVar2 = (byte *)(lVar14 + (long)*(int *)(param_1 + 0x30) *
                                             (long)(int)(uVar13 + param_4) + uVar19);
                  lVar14 = pacga((long)*(int *)(param_2 + 0x30),
                                 uVar1 & 0xffffffffffff | 0x5363000000000000);
                  if (lVar14 != *(long *)(param_2 + 0x38)) break;
                  pbVar21 = (byte *)(*(long *)(param_2 + 0x40) +
                                    (long)*(int *)(param_2 + 0x30) * (long)(int)uVar13);
                  bVar22 = *pbVar21;
                  bVar7 = *pbVar2;
                  bVar10 = bVar22 >> (ulong)uVar8;
                  bVar20 = (byte)(0xff << (ulong)(8 - uVar8 & 0x1f)) & bVar7 | bVar10;
                  if (param_5 != 4) {
                    bVar20 = bVar7;
                  }
                  bVar5 = (byte)((bVar22 ^ 0xff) >> (ulong)uVar8) ^ bVar7;
                  if (param_5 != 3) {
                    bVar5 = bVar20;
                  }
                  bVar20 = bVar10 ^ bVar7;
                  if (param_5 != 2) {
                    bVar20 = bVar5;
                  }
                  bVar5 = (byte)((bVar22 | 0xff00) >> (ulong)uVar8) & bVar7;
                  if (param_5 != 1) {
                    bVar5 = bVar7;
                  }
                  bVar7 = bVar10 | bVar7;
                  if (param_5 != 0) {
                    bVar7 = bVar5;
                  }
                  if (param_5 < 2) {
                    bVar20 = bVar7;
                  }
                  pbVar12 = pbVar2 + 1;
                  *pbVar2 = bVar20;
                  iVar17 = (param_3 & 0x7ffffff8) + 8;
                }
                uVar11 = (uint)bVar22;
                for (; pbVar21 = pbVar21 + 1, iVar17 < (int)(uVar9 - 8); iVar17 = iVar17 + 8) {
                  bVar7 = *pbVar12;
                  bVar20 = *pbVar21;
                  bVar10 = (byte)(((uint)bVar20 | uVar11 << 8) >> (ulong)uVar8);
                  bVar22 = bVar10;
                  if (param_5 != 4) {
                    bVar22 = bVar7;
                  }
                  bVar5 = bVar10 ^ bVar7 ^ 0xff;
                  if (param_5 != 3) {
                    bVar5 = bVar22;
                  }
                  bVar22 = bVar10 ^ bVar7;
                  if (param_5 != 2) {
                    bVar22 = bVar5;
                  }
                  bVar5 = bVar10 & bVar7;
                  if (param_5 != 1) {
                    bVar5 = bVar7;
                  }
                  bVar7 = bVar10 | bVar7;
                  if (param_5 != 0) {
                    bVar7 = bVar5;
                  }
                  if (param_5 < 2) {
                    bVar22 = bVar7;
                  }
                  *pbVar12 = bVar22;
                  pbVar12 = pbVar12 + 1;
                  uVar11 = (uint)bVar20;
                }
                bVar7 = *pbVar12;
                bVar10 = (byte)(((uint)*pbVar21 | uVar11 << 8) >> (ulong)uVar8);
                bVar20 = bVar10 & bVar4;
                bVar22 = bVar20 | bVar16 & bVar7;
                if (param_5 != 4) {
                  bVar22 = bVar7;
                }
                bVar5 = (bVar10 ^ 0xff) & bVar4 ^ bVar7;
                if (param_5 != 3) {
                  bVar5 = bVar22;
                }
                bVar22 = bVar20 ^ bVar7;
                if (param_5 != 2) {
                  bVar22 = bVar5;
                }
                bVar20 = bVar20 | bVar7;
                bVar16 = (bVar10 | bVar16) & bVar7;
                if (param_5 != 1) {
                  bVar16 = bVar7;
                }
LAB_183cf7924:
                if (param_5 != 0) {
                  bVar20 = bVar16;
                }
                if (param_5 < 2) {
                  bVar22 = bVar20;
                }
                *pbVar12 = bVar22;
              }
              uVar13 = uVar13 + 1;
              if ((int)uVar6 <= (int)uVar13) {
                return;
              }
            } while( true );
          }
        }
      }
    }
  }
  func_0x000188138260();
  return;
}



/* ==== __ZN15JBIG2SymbolDictD2Ev @ 183cf7964 size=228 ==== */

undefined8 * __ZN15JBIG2SymbolDictD2Ev(undefined8 *param_1)

{
  long lVar1;
  long *plVar2;
  ulong uVar3;
  ulong uVar4;
  undefined8 *puVar5;
  
  *param_1 = &DAT_1e2234378;
  lVar1 = param_1[2];
  if ((lVar1 != 0) &&
     (uVar3 = (ulong)*(uint *)((long)param_1 + 0xc), *(uint *)((long)param_1 + 0xc) != 0)) {
    uVar4 = 0;
    do {
      plVar2 = *(long **)(param_1[2] + uVar4 * 8);
      if (plVar2 != (long *)0x0) {
        (**(code **)(*plVar2 + 8))();
        uVar3 = (ulong)*(uint *)((long)param_1 + 0xc);
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar3);
    lVar1 = param_1[2];
  }
  func_0x000188138390(lVar1);
  puVar5 = (undefined8 *)param_1[3];
  if (puVar5 != (undefined8 *)0x0) {
    func_0x000188138390(*puVar5);
    func_0x00018814d0e0(puVar5,0x1010c40a1d9428b);
  }
  puVar5 = (undefined8 *)param_1[4];
  if (puVar5 != (undefined8 *)0x0) {
    func_0x000188138390(*puVar5);
    func_0x00018814d0e0(puVar5,0x1010c40a1d9428b);
  }
  return param_1;
}



/* ==== __ZN15JBIG2SymbolDictD1Ev @ 183cf7a48 size=4 ==== */

undefined8 * __ZN15JBIG2SymbolDictD1Ev(undefined8 *param_1)

{
  long lVar1;
  long *plVar2;
  ulong uVar3;
  ulong uVar4;
  undefined8 *puVar5;
  
  *param_1 = &DAT_1e2234378;
  lVar1 = param_1[2];
  if ((lVar1 != 0) &&
     (uVar3 = (ulong)*(uint *)((long)param_1 + 0xc), *(uint *)((long)param_1 + 0xc) != 0)) {
    uVar4 = 0;
    do {
      plVar2 = *(long **)(param_1[2] + uVar4 * 8);
      if (plVar2 != (long *)0x0) {
        (**(code **)(*plVar2 + 8))();
        uVar3 = (ulong)*(uint *)((long)param_1 + 0xc);
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar3);
    lVar1 = param_1[2];
  }
  func_0x000188138390(lVar1);
  puVar5 = (undefined8 *)param_1[3];
  if (puVar5 != (undefined8 *)0x0) {
    func_0x000188138390(*puVar5);
    func_0x00018814d0e0(puVar5,0x1010c40a1d9428b);
  }
  puVar5 = (undefined8 *)param_1[4];
  if (puVar5 != (undefined8 *)0x0) {
    func_0x000188138390(*puVar5);
    func_0x00018814d0e0(puVar5,0x1010c40a1d9428b);
  }
  return param_1;
}



/* ==== __ZN15JBIG2SymbolDictD0Ev @ 183cf7a4c size=56 ==== */

/* WARNING: Control flow encountered bad instruction data */

void __ZN15JBIG2SymbolDictD0Ev(void)

{
  code *pcVar1;
  ulong unaff_x30;
  
  __ZN15JBIG2SymbolDictD2Ev();
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0x183cf7a80);
    (*pcVar1)();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* ==== __ZN16JBIG2PatternDictD2Ev @ 183cf7a84 size=140 ==== */

undefined8 * __ZN16JBIG2PatternDictD2Ev(undefined8 *param_1)

{
  long *plVar1;
  ulong uVar2;
  ulong uVar3;
  
  *param_1 = &DAT_1e2234350;
  uVar2 = (ulong)*(uint *)((long)param_1 + 0xc);
  if (*(uint *)((long)param_1 + 0xc) != 0) {
    uVar3 = 0;
    do {
      plVar1 = *(long **)(param_1[2] + uVar3 * 8);
      if (plVar1 != (long *)0x0) {
        (**(code **)(*plVar1 + 8))();
        uVar2 = (ulong)*(uint *)((long)param_1 + 0xc);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar2);
  }
  func_0x000188138390(param_1[2]);
  return param_1;
}



/* ==== __ZN16JBIG2PatternDictD1Ev @ 183cf7b10 size=4 ==== */

undefined8 * __ZN16JBIG2PatternDictD1Ev(undefined8 *param_1)

{
  long *plVar1;
  ulong uVar2;
  ulong uVar3;
  
  *param_1 = &DAT_1e2234350;
  uVar2 = (ulong)*(uint *)((long)param_1 + 0xc);
  if (*(uint *)((long)param_1 + 0xc) != 0) {
    uVar3 = 0;
    do {
      plVar1 = *(long **)(param_1[2] + uVar3 * 8);
      if (plVar1 != (long *)0x0) {
        (**(code **)(*plVar1 + 8))();
        uVar2 = (ulong)*(uint *)((long)param_1 + 0xc);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar2);
  }
  func_0x000188138390(param_1[2]);
  return param_1;
}



/* ==== __ZN16JBIG2PatternDictD0Ev @ 183cf7b14 size=56 ==== */

/* WARNING: Control flow encountered bad instruction data */

void __ZN16JBIG2PatternDictD0Ev(void)

{
  code *pcVar1;
  ulong unaff_x30;
  
  __ZN16JBIG2PatternDictD2Ev();
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0x183cf7b48);
    (*pcVar1)();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* ==== __ZN14JBIG2CodeTableD1Ev @ 183cf7b4c size=72 ==== */

undefined8 * __ZN14JBIG2CodeTableD1Ev(undefined8 *param_1)

{
  *param_1 = &DAT_1e22343d0;
  func_0x000188138390(param_1[2]);
  return param_1;
}



/* ==== __ZN14JBIG2CodeTableD0Ev @ 183cf7b94 size=104 ==== */

/* WARNING: Control flow encountered bad instruction data */

void __ZN14JBIG2CodeTableD0Ev(undefined8 *param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  *param_1 = &DAT_1e22343d0;
  func_0x000188138390(param_1[2]);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0x183cf7bf8);
    (*pcVar1)();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* ==== __ZN11JBIG2StreamD2Ev @ 183cf7bfc size=816 ==== */

undefined8 * __ZN11JBIG2StreamD2Ev(undefined8 *param_1)

{
  int iVar1;
  uint uVar2;
  long *plVar3;
  uint uVar4;
  uint *puVar5;
  undefined8 *puVar6;
  
  *param_1 = &DAT_1e2234518;
  __ZN11JBIG2Stream5closeEv();
  plVar3 = (long *)param_1[3];
  if ((plVar3 != (long *)0x0) &&
     (iVar1 = (int)plVar3[1] + -1, *(int *)(plVar3 + 1) = iVar1, iVar1 == 0)) {
    (**(code **)(*plVar3 + 8))();
    param_1[3] = 0;
  }
  puVar5 = (uint *)param_1[0xd];
  if (puVar5 != (uint *)0x0) {
    if ((puVar5[9] != 0) && (uVar4 = puVar5[8], 0 < (int)uVar4)) {
      uVar2 = puVar5[1];
      do {
        *puVar5 = uVar2;
        if (puVar5[9] != 0) {
          puVar5[8] = uVar4 - 1;
        }
        uVar2 = (**(code **)(**(long **)(puVar5 + 6) + 0x20))();
        uVar2 = uVar2 & 0xff;
        puVar5[1] = uVar2;
        uVar4 = puVar5[8];
      } while (0 < (int)uVar4);
    }
    func_0x00018814d0e0(puVar5,0x1020c402dbdc18b);
  }
  puVar6 = (undefined8 *)param_1[0xe];
  if (puVar6 != (undefined8 *)0x0) {
    func_0x000188138390(*puVar6);
    func_0x00018814d0e0(puVar6,0x1010c40a1d9428b);
  }
  puVar6 = (undefined8 *)param_1[0xf];
  if (puVar6 != (undefined8 *)0x0) {
    func_0x000188138390(*puVar6);
    func_0x00018814d0e0(puVar6,0x1010c40a1d9428b);
  }
  puVar6 = (undefined8 *)param_1[0x10];
  if (puVar6 != (undefined8 *)0x0) {
    func_0x000188138390(*puVar6);
    func_0x00018814d0e0(puVar6,0x1010c40a1d9428b);
  }
  puVar6 = (undefined8 *)param_1[0x11];
  if (puVar6 != (undefined8 *)0x0) {
    func_0x000188138390(*puVar6);
    func_0x00018814d0e0(puVar6,0x1010c40a1d9428b);
  }
  puVar6 = (undefined8 *)param_1[0x12];
  if (puVar6 != (undefined8 *)0x0) {
    func_0x000188138390(*puVar6);
    func_0x00018814d0e0(puVar6,0x1010c40a1d9428b);
  }
  puVar6 = (undefined8 *)param_1[0x13];
  if (puVar6 != (undefined8 *)0x0) {
    func_0x000188138390(*puVar6);
    func_0x00018814d0e0(puVar6,0x1010c40a1d9428b);
  }
  puVar6 = (undefined8 *)param_1[0x14];
  if (puVar6 != (undefined8 *)0x0) {
    func_0x000188138390(*puVar6);
    func_0x00018814d0e0(puVar6,0x1010c40a1d9428b);
  }
  puVar6 = (undefined8 *)param_1[0x15];
  if (puVar6 != (undefined8 *)0x0) {
    func_0x000188138390(*puVar6);
    func_0x00018814d0e0(puVar6,0x1010c40a1d9428b);
  }
  puVar6 = (undefined8 *)param_1[0x16];
  if (puVar6 != (undefined8 *)0x0) {
    func_0x000188138390(*puVar6);
    func_0x00018814d0e0(puVar6,0x1010c40a1d9428b);
  }
  puVar6 = (undefined8 *)param_1[0x17];
  if (puVar6 != (undefined8 *)0x0) {
    func_0x000188138390(*puVar6);
    func_0x00018814d0e0(puVar6,0x1010c40a1d9428b);
  }
  puVar6 = (undefined8 *)param_1[0x18];
  if (puVar6 != (undefined8 *)0x0) {
    func_0x000188138390(*puVar6);
    func_0x00018814d0e0(puVar6,0x1010c40a1d9428b);
  }
  puVar6 = (undefined8 *)param_1[0x19];
  if (puVar6 != (undefined8 *)0x0) {
    func_0x000188138390(*puVar6);
    func_0x00018814d0e0(puVar6,0x1010c40a1d9428b);
  }
  puVar6 = (undefined8 *)param_1[0x1a];
  if (puVar6 != (undefined8 *)0x0) {
    func_0x000188138390(*puVar6);
    func_0x00018814d0e0(puVar6,0x1010c40a1d9428b);
  }
  puVar6 = (undefined8 *)param_1[0x1b];
  if (puVar6 != (undefined8 *)0x0) {
    func_0x000188138390(*puVar6);
    func_0x00018814d0e0(puVar6,0x1010c40a1d9428b);
  }
  puVar6 = (undefined8 *)param_1[0x1c];
  if (puVar6 != (undefined8 *)0x0) {
    func_0x000188138390(*puVar6);
    func_0x00018814d0e0(puVar6,0x1010c40a1d9428b);
  }
  puVar6 = (undefined8 *)param_1[0x1d];
  if (puVar6 != (undefined8 *)0x0) {
    func_0x000188138390(*puVar6);
    func_0x00018814d0e0(puVar6,0x1010c40a1d9428b);
  }
  if (param_1[0x1e] != 0) {
    func_0x00018814d0e0(param_1[0x1e],0x1020c40eded9539);
  }
  if (param_1[0x1f] != 0) {
    func_0x00018814d0e0(param_1[0x1f],0x1020c405af6bdc9);
  }
  if ((long *)param_1[2] != (long *)0x0) {
    (**(code **)(*(long *)param_1[2] + 8))();
  }
  return param_1;
}



/* ==== __ZN11JBIG2StreamD1Ev @ 183cf7f34 size=4 ==== */

undefined8 * __ZN11JBIG2StreamD1Ev(undefined8 *param_1)

{
  int iVar1;
  uint uVar2;
  long *plVar3;
  uint uVar4;
  uint *puVar5;
  undefined8 *puVar6;
  
  *param_1 = &DAT_1e2234518;
  __ZN11JBIG2Stream5closeEv();
  plVar3 = (long *)param_1[3];
  if ((plVar3 != (long *)0x0) &&
     (iVar1 = (int)plVar3[1] + -1, *(int *)(plVar3 + 1) = iVar1, iVar1 == 0)) {
    (**(code **)(*plVar3 + 8))();
    param_1[3] = 0;
  }
  puVar5 = (uint *)param_1[0xd];
  if (puVar5 != (uint *)0x0) {
    if ((puVar5[9] != 0) && (uVar4 = puVar5[8], 0 < (int)uVar4)) {
      uVar2 = puVar5[1];
      do {
        *puVar5 = uVar2;
        if (puVar5[9] != 0) {
          puVar5[8] = uVar4 - 1;
        }
        uVar2 = (**(code **)(**(long **)(puVar5 + 6) + 0x20))();
        uVar2 = uVar2 & 0xff;
        puVar5[1] = uVar2;
        uVar4 = puVar5[8];
      } while (0 < (int)uVar4);
    }
    func_0x00018814d0e0(puVar5,0x1020c402dbdc18b);
  }
  puVar6 = (undefined8 *)param_1[0xe];
  if (puVar6 != (undefined8 *)0x0) {
    func_0x000188138390(*puVar6);
    func_0x00018814d0e0(puVar6,0x1010c40a1d9428b);
  }
  puVar6 = (undefined8 *)param_1[0xf];
  if (puVar6 != (undefined8 *)0x0) {
    func_0x000188138390(*puVar6);
    func_0x00018814d0e0(puVar6,0x1010c40a1d9428b);
  }
  puVar6 = (undefined8 *)param_1[0x10];
  if (puVar6 != (undefined8 *)0x0) {
    func_0x000188138390(*puVar6);
    func_0x00018814d0e0(puVar6,0x1010c40a1d9428b);
  }
  puVar6 = (undefined8 *)param_1[0x11];
  if (puVar6 != (undefined8 *)0x0) {
    func_0x000188138390(*puVar6);
    func_0x00018814d0e0(puVar6,0x1010c40a1d9428b);
  }
  puVar6 = (undefined8 *)param_1[0x12];
  if (puVar6 != (undefined8 *)0x0) {
    func_0x000188138390(*puVar6);
    func_0x00018814d0e0(puVar6,0x1010c40a1d9428b);
  }
  puVar6 = (undefined8 *)param_1[0x13];
  if (puVar6 != (undefined8 *)0x0) {
    func_0x000188138390(*puVar6);
    func_0x00018814d0e0(puVar6,0x1010c40a1d9428b);
  }
  puVar6 = (undefined8 *)param_1[0x14];
  if (puVar6 != (undefined8 *)0x0) {
    func_0x000188138390(*puVar6);
    func_0x00018814d0e0(puVar6,0x1010c40a1d9428b);
  }
  puVar6 = (undefined8 *)param_1[0x15];
  if (puVar6 != (undefined8 *)0x0) {
    func_0x000188138390(*puVar6);
    func_0x00018814d0e0(puVar6,0x1010c40a1d9428b);
  }
  puVar6 = (undefined8 *)param_1[0x16];
  if (puVar6 != (undefined8 *)0x0) {
    func_0x000188138390(*puVar6);
    func_0x00018814d0e0(puVar6,0x1010c40a1d9428b);
  }
  puVar6 = (undefined8 *)param_1[0x17];
  if (puVar6 != (undefined8 *)0x0) {
    func_0x000188138390(*puVar6);
    func_0x00018814d0e0(puVar6,0x1010c40a1d9428b);
  }
  puVar6 = (undefined8 *)param_1[0x18];
  if (puVar6 != (undefined8 *)0x0) {
    func_0x000188138390(*puVar6);
    func_0x00018814d0e0(puVar6,0x1010c40a1d9428b);
  }
  puVar6 = (undefined8 *)param_1[0x19];
  if (puVar6 != (undefined8 *)0x0) {
    func_0x000188138390(*puVar6);
    func_0x00018814d0e0(puVar6,0x1010c40a1d9428b);
  }
  puVar6 = (undefined8 *)param_1[0x1a];
  if (puVar6 != (undefined8 *)0x0) {
    func_0x000188138390(*puVar6);
    func_0x00018814d0e0(puVar6,0x1010c40a1d9428b);
  }
  puVar6 = (undefined8 *)param_1[0x1b];
  if (puVar6 != (undefined8 *)0x0) {
    func_0x000188138390(*puVar6);
    func_0x00018814d0e0(puVar6,0x1010c40a1d9428b);
  }
  puVar6 = (undefined8 *)param_1[0x1c];
  if (puVar6 != (undefined8 *)0x0) {
    func_0x000188138390(*puVar6);
    func_0x00018814d0e0(puVar6,0x1010c40a1d9428b);
  }
  puVar6 = (undefined8 *)param_1[0x1d];
  if (puVar6 != (undefined8 *)0x0) {
    func_0x000188138390(*puVar6);
    func_0x00018814d0e0(puVar6,0x1010c40a1d9428b);
  }
  if (param_1[0x1e] != 0) {
    func_0x00018814d0e0(param_1[0x1e],0x1020c40eded9539);
  }
  if (param_1[0x1f] != 0) {
    func_0x00018814d0e0(param_1[0x1f],0x1020c405af6bdc9);
  }
  if ((long *)param_1[2] != (long *)0x0) {
    (**(code **)(*(long *)param_1[2] + 8))();
  }
  return param_1;
}



/* ==== __ZN11JBIG2StreamD0Ev @ 183cf7f38 size=56 ==== */

/* WARNING: Control flow encountered bad instruction data */

void __ZN11JBIG2StreamD0Ev(void)

{
  code *pcVar1;
  ulong unaff_x30;
  
  __ZN11JBIG2StreamD2Ev();
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0x183cf7f6c);
    (*pcVar1)();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* ==== __ZN11JBIG2Stream5resetEv @ 183cf7f70 size=492 ==== */

/* WARNING: Removing unreachable block (ram,0x000183cf80f4) */

void __ZN11JBIG2Stream5resetEv(long param_1)

{
  int iVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  long *plVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  
  puVar3 = (undefined8 *)func_0x00018814d110(0x18,0x1080c40a085cba5);
  *(undefined4 *)(puVar3 + 1) = 8;
  uVar4 = __Z13gmalloc_typediy(0x40,0x80040b8603338);
  *puVar3 = uVar4;
  *(undefined4 *)((long)puVar3 + 0xc) = 0;
  *(undefined4 *)(puVar3 + 2) = 0;
  *(undefined8 **)(param_1 + 0x48) = puVar3;
  plVar5 = *(long **)(param_1 + 0x18);
  if (plVar5 != (long *)0x0) {
    *(undefined8 **)(param_1 + 0x40) = puVar3;
    *(long **)(param_1 + 0x50) = plVar5;
    (**(code **)(*plVar5 + 0x10))();
    lVar6 = *(long *)(param_1 + 0x68);
    uVar4 = *(undefined8 *)(param_1 + 0x50);
    *(undefined8 *)(lVar6 + 0x18) = uVar4;
    *(undefined8 *)(lVar6 + 0x20) = 0;
    puVar3 = *(undefined8 **)(param_1 + 0xf8);
    **(undefined8 **)(param_1 + 0xf0) = uVar4;
    *puVar3 = uVar4;
    __ZN11JBIG2Stream12readSegmentsEv(param_1);
    (**(code **)(**(long **)(param_1 + 0x50) + 0x18))();
  }
  puVar3 = (undefined8 *)func_0x00018814d110(0x18,0x1080c40a085cba5);
  *(undefined4 *)(puVar3 + 1) = 8;
  uVar4 = __Z13gmalloc_typediy(0x40,0x80040b8603338);
  *puVar3 = uVar4;
  *(undefined8 *)((long)puVar3 + 0xc) = 0;
  *(undefined8 **)(param_1 + 0x40) = puVar3;
  *(long **)(param_1 + 0x50) = *(long **)(param_1 + 0x10);
  (**(code **)(**(long **)(param_1 + 0x10) + 0x10))();
  lVar6 = *(long *)(param_1 + 0x68);
  uVar4 = *(undefined8 *)(param_1 + 0x50);
  *(undefined8 *)(lVar6 + 0x18) = uVar4;
  *(undefined8 *)(lVar6 + 0x20) = 0;
  puVar3 = *(undefined8 **)(param_1 + 0xf8);
  **(undefined8 **)(param_1 + 0xf0) = uVar4;
  *puVar3 = uVar4;
  __ZN11JBIG2Stream12readSegmentsEv(param_1);
  lVar6 = *(long *)(param_1 + 0x30);
  if (lVar6 != 0) {
    lVar8 = *(long *)(lVar6 + 0x40);
    iVar1 = *(int *)(lVar6 + 0x20);
    *(long *)(param_1 + 0x58) = lVar8;
    lVar7 = pacga((long)iVar1,(ulong)(lVar6 + 0x20) & 0xffffffffffff | 0x5363000000000000);
    if (lVar7 == *(long *)(lVar6 + 0x28)) {
      iVar2 = *(int *)(lVar6 + 0x30);
      lVar7 = pacga((long)iVar2,(ulong)(lVar6 + 0x30) & 0xffffffffffff | 0x5363000000000000);
      if (lVar7 == *(long *)(lVar6 + 0x38)) {
        *(long *)(param_1 + 0x60) = lVar8 + (long)iVar2 * (long)iVar1;
        return;
      }
    }
    func_0x000188138260();
    return;
  }
  *(undefined8 *)(param_1 + 0x58) = 0;
  *(undefined8 *)(param_1 + 0x60) = 0;
  return;
}



/* ==== __ZN11JBIG2Stream12readSegmentsEv @ 183cf8178 size=15468 ==== */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Possible PIC construction at 0x000183cfb9f0: Changing call to branch */
/* WARNING: Possible PIC construction at 0x000183cfb97c: Changing call to branch */
/* WARNING: Possible PIC construction at 0x000183cfb90c: Changing call to branch */
/* WARNING: Possible PIC construction at 0x000183cfab4c: Changing call to branch */
/* WARNING: Possible PIC construction at 0x000183cfac64: Changing call to branch */
/* WARNING: Possible PIC construction at 0x000183cfb060: Changing call to branch */
/* WARNING: Possible PIC construction at 0x000183cfb434: Changing call to branch */
/* WARNING: Possible PIC construction at 0x000183cfb414: Changing call to branch */
/* WARNING: Possible PIC construction at 0x000183cfbb00: Changing call to branch */
/* WARNING: Possible PIC construction at 0x000183cf9970: Changing call to branch */
/* WARNING: Possible PIC construction at 0x000183cfbc64: Changing call to branch */
/* WARNING: Possible PIC construction at 0x000183cfa338: Changing call to branch */
/* WARNING: Possible PIC construction at 0x000183cfbcf4: Changing call to branch */
/* WARNING: Removing unreachable block (ram,0x000183cfa33c) */
/* WARNING: Removing unreachable block (ram,0x000183cfa344) */
/* WARNING: Removing unreachable block (ram,0x000183cfa348) */
/* WARNING: Removing unreachable block (ram,0x000183cfa35c) */
/* WARNING: Removing unreachable block (ram,0x000183cfa374) */
/* WARNING: Removing unreachable block (ram,0x000183cfa380) */
/* WARNING: Removing unreachable block (ram,0x000183cfbc68) */
/* WARNING: Removing unreachable block (ram,0x000183cfbc6c) */
/* WARNING: Removing unreachable block (ram,0x000183cf9974) */
/* WARNING: Removing unreachable block (ram,0x000183cf99d8) */
/* WARNING: Removing unreachable block (ram,0x000183cf99e4) */
/* WARNING: Removing unreachable block (ram,0x000183cf9990) */
/* WARNING: Removing unreachable block (ram,0x000183cf9998) */
/* WARNING: Removing unreachable block (ram,0x000183cf999c) */
/* WARNING: Removing unreachable block (ram,0x000183cf99a0) */
/* WARNING: Removing unreachable block (ram,0x000183cf9a0c) */
/* WARNING: Removing unreachable block (ram,0x000183cf9a14) */
/* WARNING: Removing unreachable block (ram,0x000183cf9a18) */
/* WARNING: Removing unreachable block (ram,0x000183cf9a1c) */
/* WARNING: Removing unreachable block (ram,0x000183cf9a34) */
/* WARNING: Removing unreachable block (ram,0x000183cf99c8) */
/* WARNING: Removing unreachable block (ram,0x000183cf9a38) */
/* WARNING: Removing unreachable block (ram,0x000183cf9a44) */
/* WARNING: Removing unreachable block (ram,0x000183cf9a54) */
/* WARNING: Removing unreachable block (ram,0x000183cf9a6c) */
/* WARNING: Removing unreachable block (ram,0x000183cf9a58) */
/* WARNING: Removing unreachable block (ram,0x000183cf9a7c) */
/* WARNING: Removing unreachable block (ram,0x000183cf9a84) */
/* WARNING: Removing unreachable block (ram,0x000183cf9a90) */
/* WARNING: Removing unreachable block (ram,0x000183cfbd18) */
/* WARNING: Removing unreachable block (ram,0x000183cfbd24) */
/* WARNING: Removing unreachable block (ram,0x000183cf9aa0) */
/* WARNING: Removing unreachable block (ram,0x000183cf9ac0) */
/* WARNING: Removing unreachable block (ram,0x000183cf9ad0) */
/* WARNING: Removing unreachable block (ram,0x000183cf9af4) */
/* WARNING: Removing unreachable block (ram,0x000183cf9df8) */
/* WARNING: Removing unreachable block (ram,0x000183cf9e00) */
/* WARNING: Removing unreachable block (ram,0x000183cfbdb0) */
/* WARNING: Removing unreachable block (ram,0x000183cf9e28) */
/* WARNING: Removing unreachable block (ram,0x000183cf9e64) */
/* WARNING: Removing unreachable block (ram,0x000183cf9eb4) */
/* WARNING: Removing unreachable block (ram,0x000183cf9ec8) */
/* WARNING: Removing unreachable block (ram,0x000183cf9ecc) */
/* WARNING: Removing unreachable block (ram,0x000183cf9ed0) */
/* WARNING: Removing unreachable block (ram,0x000183cf9ed4) */
/* WARNING: Removing unreachable block (ram,0x000183cf9ec4) */
/* WARNING: Removing unreachable block (ram,0x000183cf9e30) */
/* WARNING: Removing unreachable block (ram,0x000183cf9f00) */
/* WARNING: Removing unreachable block (ram,0x000183cf9f10) */
/* WARNING: Removing unreachable block (ram,0x000183cf9f18) */
/* WARNING: Removing unreachable block (ram,0x000183cf9f50) */
/* WARNING: Removing unreachable block (ram,0x000183cf9f54) */
/* WARNING: Removing unreachable block (ram,0x000183cf9f74) */
/* WARNING: Removing unreachable block (ram,0x000183cf9af8) */
/* WARNING: Removing unreachable block (ram,0x000183cf9b00) */
/* WARNING: Removing unreachable block (ram,0x000183cfbb4c) */
/* WARNING: Removing unreachable block (ram,0x000183cf9b0c) */
/* WARNING: Removing unreachable block (ram,0x000183cfbb78) */
/* WARNING: Removing unreachable block (ram,0x000183cf9b20) */
/* WARNING: Removing unreachable block (ram,0x000183cfbba4) */
/* WARNING: Removing unreachable block (ram,0x000183cf9b2c) */
/* WARNING: Removing unreachable block (ram,0x000183cf9b74) */
/* WARNING: Removing unreachable block (ram,0x000183cf9b34) */
/* WARNING: Removing unreachable block (ram,0x000183cf9b84) */
/* WARNING: Removing unreachable block (ram,0x000183cf9be0) */
/* WARNING: Removing unreachable block (ram,0x000183cf9bf4) */
/* WARNING: Removing unreachable block (ram,0x000183cf9d40) */
/* WARNING: Removing unreachable block (ram,0x000183cf9c00) */
/* WARNING: Removing unreachable block (ram,0x000183cf9b88) */
/* WARNING: Removing unreachable block (ram,0x000183cf9f78) */
/* WARNING: Removing unreachable block (ram,0x000183cf9f8c) */
/* WARNING: Removing unreachable block (ram,0x000183cf9ff8) */
/* WARNING: Removing unreachable block (ram,0x000183cfa000) */
/* WARNING: Removing unreachable block (ram,0x000183cfa2e4) */
/* WARNING: Removing unreachable block (ram,0x000183cfa024) */
/* WARNING: Removing unreachable block (ram,0x000183cfa030) */
/* WARNING: Removing unreachable block (ram,0x000183cfa048) */
/* WARNING: Removing unreachable block (ram,0x000183cfa034) */
/* WARNING: Removing unreachable block (ram,0x000183cfa05c) */
/* WARNING: Removing unreachable block (ram,0x000183cfa070) */
/* WARNING: Removing unreachable block (ram,0x000183cfa080) */
/* WARNING: Removing unreachable block (ram,0x000183cfbbd4) */
/* WARNING: Removing unreachable block (ram,0x000183cfa090) */
/* WARNING: Removing unreachable block (ram,0x000183cfa098) */
/* WARNING: Removing unreachable block (ram,0x000183cfa12c) */
/* WARNING: Removing unreachable block (ram,0x000183cfa130) */
/* WARNING: Removing unreachable block (ram,0x000183cfa134) */
/* WARNING: Removing unreachable block (ram,0x000183cfa138) */
/* WARNING: Removing unreachable block (ram,0x000183cfa13c) */
/* WARNING: Removing unreachable block (ram,0x000183cfa140) */
/* WARNING: Removing unreachable block (ram,0x000183cfa144) */
/* WARNING: Removing unreachable block (ram,0x000183cfa168) */
/* WARNING: Removing unreachable block (ram,0x000183cfa178) */
/* WARNING: Removing unreachable block (ram,0x000183cfa188) */
/* WARNING: Removing unreachable block (ram,0x000183cfa210) */
/* WARNING: Removing unreachable block (ram,0x000183cfa1a8) */
/* WARNING: Removing unreachable block (ram,0x000183cfa1bc) */
/* WARNING: Removing unreachable block (ram,0x000183cfa1dc) */
/* WARNING: Removing unreachable block (ram,0x000183cfa1e0) */
/* WARNING: Removing unreachable block (ram,0x000183cfa218) */
/* WARNING: Removing unreachable block (ram,0x000183cfa1ec) */
/* WARNING: Removing unreachable block (ram,0x000183cfa208) */
/* WARNING: Removing unreachable block (ram,0x000183cfa21c) */
/* WARNING: Removing unreachable block (ram,0x000183cfa230) */
/* WARNING: Removing unreachable block (ram,0x000183cfa244) */
/* WARNING: Removing unreachable block (ram,0x000183cfa254) */
/* WARNING: Removing unreachable block (ram,0x000183cfa270) */
/* WARNING: Removing unreachable block (ram,0x000183cfa284) */
/* WARNING: Removing unreachable block (ram,0x000183cfa298) */
/* WARNING: Removing unreachable block (ram,0x000183cfa2a0) */
/* WARNING: Removing unreachable block (ram,0x000183cfa2ac) */
/* WARNING: Removing unreachable block (ram,0x000183cfa2b4) */
/* WARNING: Removing unreachable block (ram,0x000183cfa26c) */
/* WARNING: Removing unreachable block (ram,0x000183cfa204) */
/* WARNING: Removing unreachable block (ram,0x000183cfa1d8) */
/* WARNING: Removing unreachable block (ram,0x000183cfa078) */
/* WARNING: Removing unreachable block (ram,0x000183cfa2c4) */
/* WARNING: Removing unreachable block (ram,0x000183cfa2e0) */
/* WARNING: Removing unreachable block (ram,0x000183cfa2e8) */
/* WARNING: Removing unreachable block (ram,0x000183cfbd84) */
/* WARNING: Removing unreachable block (ram,0x000183cfbbfc) */
/* WARNING: Removing unreachable block (ram,0x000183cfa2f4) */
/* WARNING: Removing unreachable block (ram,0x000183cfa2fc) */
/* WARNING: Removing unreachable block (ram,0x000183cfa300) */
/* WARNING: Removing unreachable block (ram,0x000183cfa30c) */
/* WARNING: Removing unreachable block (ram,0x000183cfa328) */
/* WARNING: Removing unreachable block (ram,0x000183cfa334) */
/* WARNING: Removing unreachable block (ram,0x000183cf9b9c) */
/* WARNING: Removing unreachable block (ram,0x000183cf9ca8) */
/* WARNING: Removing unreachable block (ram,0x000183cf9ba8) */
/* WARNING: Removing unreachable block (ram,0x000183cf9c5c) */
/* WARNING: Removing unreachable block (ram,0x000183cfbd58) */
/* WARNING: Removing unreachable block (ram,0x000183cfbbcc) */
/* WARNING: Removing unreachable block (ram,0x000183cf9c6c) */
/* WARNING: Removing unreachable block (ram,0x000183cf9b3c) */
/* WARNING: Removing unreachable block (ram,0x000183cf9dd4) */
/* WARNING: Removing unreachable block (ram,0x000183cf9de8) */
/* WARNING: Removing unreachable block (ram,0x000183cf9df4) */
/* WARNING: Removing unreachable block (ram,0x000183cf9ae4) */
/* WARNING: Removing unreachable block (ram,0x000183cfbb04) */
/* WARNING: Removing unreachable block (ram,0x000183cfb418) */
/* WARNING: Removing unreachable block (ram,0x000183cfb438) */
/* WARNING: Removing unreachable block (ram,0x000183cfb064) */
/* WARNING: Removing unreachable block (ram,0x000183cfb080) */
/* WARNING: Removing unreachable block (ram,0x000183cfb068) */
/* WARNING: Removing unreachable block (ram,0x000183cfb0b0) */
/* WARNING: Removing unreachable block (ram,0x000183cfb0c0) */
/* WARNING: Removing unreachable block (ram,0x000183cfb0d0) */
/* WARNING: Removing unreachable block (ram,0x000183cfb0dc) */
/* WARNING: Removing unreachable block (ram,0x000183cfb06c) */
/* WARNING: Removing unreachable block (ram,0x000183cfb118) */
/* WARNING: Removing unreachable block (ram,0x000183cfb120) */
/* WARNING: Removing unreachable block (ram,0x000183cfb434) */
/* WARNING: Removing unreachable block (ram,0x000183cfac68) */
/* WARNING: Removing unreachable block (ram,0x000183cfacc4) */
/* WARNING: Removing unreachable block (ram,0x000183cfacd8) */
/* WARNING: Removing unreachable block (ram,0x000183cfad00) */
/* WARNING: Removing unreachable block (ram,0x000183cfaf08) */
/* WARNING: Removing unreachable block (ram,0x000183cfada8) */
/* WARNING: Removing unreachable block (ram,0x000183cfadac) */
/* WARNING: Removing unreachable block (ram,0x000183cfadc4) */
/* WARNING: Removing unreachable block (ram,0x000183cfadc8) */
/* WARNING: Removing unreachable block (ram,0x000183cfae14) */
/* WARNING: Removing unreachable block (ram,0x000183cfae70) */
/* WARNING: Removing unreachable block (ram,0x000183cfae1c) */
/* WARNING: Removing unreachable block (ram,0x000183cfae84) */
/* WARNING: Removing unreachable block (ram,0x000183cfae24) */
/* WARNING: Removing unreachable block (ram,0x000183cfae2c) */
/* WARNING: Removing unreachable block (ram,0x000183cfae30) */
/* WARNING: Removing unreachable block (ram,0x000183cfae48) */
/* WARNING: Removing unreachable block (ram,0x000183cfae54) */
/* WARNING: Removing unreachable block (ram,0x000183cfae60) */
/* WARNING: Removing unreachable block (ram,0x000183cfade4) */
/* WARNING: Removing unreachable block (ram,0x000183cfae68) */
/* WARNING: Removing unreachable block (ram,0x000183cfadec) */
/* WARNING: Removing unreachable block (ram,0x000183cfadf0) */
/* WARNING: Removing unreachable block (ram,0x000183cfae04) */
/* WARNING: Removing unreachable block (ram,0x000183cfae0c) */
/* WARNING: Removing unreachable block (ram,0x000183cfae88) */
/* WARNING: Removing unreachable block (ram,0x000183cfae8c) */
/* WARNING: Removing unreachable block (ram,0x000183cfae94) */
/* WARNING: Removing unreachable block (ram,0x000183cfaf10) */
/* WARNING: Removing unreachable block (ram,0x000183cfac8c) */
/* WARNING: Removing unreachable block (ram,0x000183cfaf20) */
/* WARNING: Removing unreachable block (ram,0x000183cfafd8) */
/* WARNING: Removing unreachable block (ram,0x000183cfaf3c) */
/* WARNING: Removing unreachable block (ram,0x000183cfb058) */
/* WARNING: Removing unreachable block (ram,0x000183cfab50) */
/* WARNING: Removing unreachable block (ram,0x000183cfb910) */
/* WARNING: Removing unreachable block (ram,0x000183cfb918) */
/* WARNING: Removing unreachable block (ram,0x000183cfb938) */
/* WARNING: Removing unreachable block (ram,0x000183cfb984) */
/* WARNING: Removing unreachable block (ram,0x000183cfb994) */
/* WARNING: Removing unreachable block (ram,0x000183cfb9a8) */
/* WARNING: Removing unreachable block (ram,0x000183cfb9b4) */
/* WARNING: Removing unreachable block (ram,0x000183cfb93c) */
/* WARNING: Removing unreachable block (ram,0x000183cfb980) */
/* WARNING: Removing unreachable block (ram,0x000183cfbcf8) */
/* WARNING: Removing unreachable block (ram,0x000183cfbc1c) */
/* WARNING: Removing unreachable block (ram,0x000183cfbc28) */
/* WARNING: Removing unreachable block (ram,0x000183cfbc2c) */
/* WARNING: Removing unreachable block (ram,0x000183cfbc38) */
/* WARNING: Removing unreachable block (ram,0x000183cfbc54) */
/* WARNING: Removing unreachable block (ram,0x000183cfbc60) */
/* WARNING: Removing unreachable block (ram,0x000183cf90c8) */
/* WARNING: Removing unreachable block (ram,0x000183cfb58c) */
/* WARNING: Removing unreachable block (ram,0x000183cfb610) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __ZN11JBIG2Stream12readSegmentsEv(long *param_1)

{
  uint *puVar1;
  undefined4 *puVar2;
  ulong uVar3;
  ulong uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  code *pcVar8;
  bool bVar9;
  bool bVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  undefined4 uVar19;
  uint uVar20;
  uint uVar21;
  int iVar22;
  int *piVar23;
  undefined8 uVar24;
  undefined8 uVar25;
  undefined8 *puVar26;
  long *plVar27;
  long *plVar28;
  undefined8 uVar29;
  char *pcVar30;
  long lVar31;
  ulong uVar32;
  ulong uVar33;
  int iVar34;
  long lVar35;
  ulong uVar36;
  long lVar37;
  ulong uVar38;
  int iVar39;
  uint uVar40;
  ulong uVar41;
  ulong uVar42;
  uint uVar43;
  ulong unaff_x30;
  undefined8 in_stack_fffffffffffffba0;
  int local_3c8;
  int local_3c0;
  int local_3b4;
  uint local_3b0;
  long local_380;
  uint local_330;
  int local_324;
  undefined1 auStack_320 [4];
  uint local_31c [3];
  undefined8 local_310;
  undefined8 local_308;
  uint local_300;
  uint local_2fc;
  int local_2f8;
  uint local_2f4;
  uint local_2f0;
  uint local_2ec;
  uint local_2e8;
  uint local_2e4;
  uint local_2e0;
  undefined8 local_2dc;
  uint local_2d4;
  undefined8 local_a0;
  undefined8 uStack_98;
  long local_88;
  
  local_88 = *_DAT_1e0186220;
  local_31c[0] = 0;
  local_324 = 0;
  iVar11 = __ZN11JBIG2Stream9readULongEPj(param_1,local_31c);
  if (iVar11 == 0) {
    if (*_DAT_1e0186220 == local_88) {
      return;
    }
    goto LAB_183cfbde0;
  }
  uVar12 = (**(code **)(*(long *)param_1[10] + 0x20))();
  if ((uVar12 != 0xffffffff) &&
     (uVar13 = (**(code **)(*(long *)param_1[10] + 0x20))(), uVar13 != 0xffffffff)) {
    uVar15 = uVar13 >> 5;
    if (uVar15 == 7) {
      iVar11 = (**(code **)(*(long *)param_1[10] + 0x20))();
      if (((iVar11 == -1) || (iVar14 = (**(code **)(*(long *)param_1[10] + 0x20))(), iVar14 == -1))
         || (uVar15 = (**(code **)(*(long *)param_1[10] + 0x20))(), uVar15 == 0xffffffff))
      goto LAB_183cfb9f4;
      uVar15 = (iVar11 << 0x10 | uVar13 << 0x18 | iVar14 << 8 | uVar15) & 0x1fffffff;
      uVar13 = uVar15 + 9 >> 3;
      do {
        (**(code **)(*(long *)param_1[10] + 0x20))();
        uVar13 = uVar13 - 1;
      } while (uVar13 != 0);
    }
    uVar36 = (ulong)uVar15;
    if (uVar15 >> 0x18 == 0) {
      piVar23 = (int *)__Z14gmallocn_typediiy(uVar36,4,0x100004052888210);
      uVar13 = local_31c[0];
      uVar16 = (uint)((ulong)in_stack_fffffffffffffba0 >> 0x20);
      if ((uVar15 == 0) || (piVar23 != (int *)0x0)) {
        if (local_31c[0] < 0x101) {
          if (uVar15 != 0) {
            lVar35 = 0;
            uVar38 = (ulong)uVar15;
            do {
              iVar11 = (**(code **)(*(long *)param_1[10] + 0x20))();
              uVar16 = (uint)((ulong)in_stack_fffffffffffffba0 >> 0x20);
              if (iVar11 == -1) {
                halt_baddata();
              }
              piVar23[lVar35] = iVar11;
              lVar35 = lVar35 + 1;
              uVar38 = uVar38 - 1;
            } while (uVar38 != 0);
          }
        }
        else if (local_31c[0] < 0x10001) {
          if (uVar15 != 0) {
            lVar35 = 0;
            uVar38 = (ulong)uVar15;
            do {
              iVar11 = __ZN11JBIG2Stream9readUWordEPj(param_1,piVar23 + lVar35);
              uVar16 = (uint)((ulong)in_stack_fffffffffffffba0 >> 0x20);
              if (iVar11 == 0) {
                halt_baddata();
              }
              lVar35 = lVar35 + 1;
              uVar38 = uVar38 - 1;
            } while (uVar38 != 0);
          }
        }
        else if (uVar15 != 0) {
          lVar35 = 0;
          uVar38 = (ulong)uVar15;
          do {
            iVar11 = __ZN11JBIG2Stream9readULongEPj(param_1,piVar23 + lVar35);
            uVar16 = (uint)((ulong)in_stack_fffffffffffffba0 >> 0x20);
            if (iVar11 == 0) {
              halt_baddata();
            }
            lVar35 = lVar35 + 1;
            uVar38 = uVar38 - 1;
          } while (uVar38 != 0);
        }
        if ((uVar12 >> 6 & 1) == 0) {
          iVar11 = (**(code **)(*(long *)param_1[10] + 0x20))();
          if (iVar11 == -1) {
            halt_baddata();
          }
        }
        else {
          iVar11 = __ZN11JBIG2Stream9readULongEPj(param_1,auStack_320);
          if (iVar11 == 0) {
            halt_baddata();
          }
        }
        iVar14 = __ZN11JBIG2Stream9readULongEPj(param_1,&local_324);
        iVar11 = local_324;
        if (iVar14 == 0) {
          halt_baddata();
        }
        uVar17 = uVar12 & 0x3f;
        if ((param_1[6] == 0) && (((uVar12 & 0x3c) == 4 || (uVar17 - 0x14 < 0x18)))) {
          uVar29 = (**(code **)(*param_1 + 0x28))(param_1);
          pcVar30 = "First JBIG2 segment associated with a page must be a page information segment";
LAB_183cfbb44:
          __Z5erroriPKcz(uVar29,pcVar30);
          if (*_DAT_1e0186220 == local_88) {
            if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
              halt_baddata();
            }
                    /* WARNING: Does not return */
            pcVar8 = (code *)SoftwareBreakpoint(0xc471,0x183cfbcc0);
            (*pcVar8)();
          }
          goto LAB_183cfbde0;
        }
        if (uVar17 < 0x26) {
          bVar10 = true;
          if (uVar17 < 0x10) {
            if (1 < uVar17 - 6) {
              if (uVar17 == 0) {
                local_2f4 = 0;
                local_300 = 0;
                local_310 = 0;
                local_308 = 0;
                local_31c[1] = 0;
                local_31c[2] = 0;
                iVar11 = __ZN11JBIG2Stream9readUWordEPj(param_1,&local_2f4);
                uVar12 = local_2f4;
                if (iVar11 != 0) {
                  local_3b0 = local_2f4 >> 10 & 3;
                  if ((local_2f4 & 1) == 0) {
                    uVar13 = (**(code **)(*(long *)param_1[10] + 0x20))();
                    if (local_3b0 == 0) {
                      if (uVar13 != 0xffffffff) {
                        local_2e0 = uVar13;
                        if ((uVar13 & 0x80) != 0) {
                          local_2e0 = uVar13 | 0xffffff00;
                        }
                        uVar13 = (**(code **)(*(long *)param_1[10] + 0x20))();
                        if (uVar13 != 0xffffffff) {
                          if ((uVar13 & 0x80) != 0) {
                            uVar13 = uVar13 | 0xffffff00;
                          }
                          local_a0 = CONCAT44(local_a0._4_4_,uVar13);
                          uVar13 = (**(code **)(*(long *)param_1[10] + 0x20))();
                          if (uVar13 != 0xffffffff) {
                            if ((uVar13 & 0x80) != 0) {
                              uVar13 = uVar13 | 0xffffff00;
                            }
                            local_2dc = CONCAT44(local_2dc._4_4_,uVar13);
                            uVar13 = (**(code **)(*(long *)param_1[10] + 0x20))();
                            if (uVar13 != 0xffffffff) {
                              if ((uVar13 & 0x80) != 0) {
                                uVar13 = uVar13 | 0xffffff00;
                              }
                              local_a0 = CONCAT44(uVar13,(int)local_a0);
                              uVar13 = (**(code **)(*(long *)param_1[10] + 0x20))();
                              if (uVar13 != 0xffffffff) {
                                if ((uVar13 & 0x80) != 0) {
                                  uVar13 = uVar13 | 0xffffff00;
                                }
                                local_2dc = CONCAT44(uVar13,(undefined4)local_2dc);
                                uVar13 = (**(code **)(*(long *)param_1[10] + 0x20))();
                                if (uVar13 != 0xffffffff) {
                                  if ((uVar13 & 0x80) != 0) {
                                    uVar13 = uVar13 | 0xffffff00;
                                  }
                                  uStack_98 = CONCAT44(uStack_98._4_4_,uVar13);
                                  uVar13 = (**(code **)(*(long *)param_1[10] + 0x20))();
                                  if (uVar13 != 0xffffffff) {
                                    local_2d4 = uVar13;
                                    if ((uVar13 & 0x80) != 0) {
                                      local_2d4 = uVar13 | 0xffffff00;
                                    }
                                    uVar13 = (**(code **)(*(long *)param_1[10] + 0x20))();
                                    if (uVar13 != 0xffffffff) {
                                      if ((uVar13 & 0x80) != 0) {
                                        uVar13 = uVar13 | 0xffffff00;
                                      }
                                      uStack_98 = CONCAT44(uVar13,(undefined4)uStack_98);
                                      goto LAB_183cf9410;
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                    else if (uVar13 != 0xffffffff) {
                      local_2e0 = uVar13;
                      if ((uVar13 & 0x80) != 0) {
                        local_2e0 = uVar13 | 0xffffff00;
                      }
                      uVar13 = (**(code **)(*(long *)param_1[10] + 0x20))();
                      if (uVar13 != 0xffffffff) {
                        if ((uVar13 & 0x80) != 0) {
                          uVar13 = uVar13 | 0xffffff00;
                        }
                        local_a0 = CONCAT44(local_a0._4_4_,uVar13);
                        goto LAB_183cf9410;
                      }
                    }
                  }
                  else {
LAB_183cf9410:
                    if (((uVar12 >> 1 & 1) == 0) || ((uVar12 >> 0xc & 1) != 0)) {
LAB_183cf94fc:
                      local_2f8 = 0;
                      iVar11 = __ZN11JBIG2Stream9readULongEPj(param_1,&local_2f8);
                      if (iVar11 != 0) {
                        local_2fc = 0;
                        iVar11 = __ZN11JBIG2Stream9readULongEPj(param_1,&local_2fc);
                        if (iVar11 != 0) {
                          puVar26 = (undefined8 *)func_0x00018814d110(0x18,0x1080c40a085cba5);
                          *(undefined4 *)(puVar26 + 1) = 8;
                          uVar29 = __Z13gmalloc_typediy(0x40,0x80040b8603338);
                          *puVar26 = uVar29;
                          *(undefined4 *)((long)puVar26 + 0xc) = 0;
                          *(undefined4 *)(puVar26 + 2) = 0;
                          if (uVar15 == 0) {
                            uVar13 = 0;
                          }
                          else {
                            lVar35 = 0;
                            uVar13 = 0;
                            uVar38 = uVar36;
                            do {
                              plVar27 = (long *)__ZN11JBIG2Stream11findSegmentEj
                                                          (param_1,piVar23[lVar35]);
                              if (plVar27 != (long *)0x0) {
                                iVar11 = (**(code **)(*plVar27 + 0x10))();
                                if (iVar11 == 1) {
                                  if (CARRY4(*(uint *)((long)plVar27 + 0xc),uVar13))
                                  goto LAB_183cfbad0;
                                  uVar13 = *(uint *)((long)plVar27 + 0xc) + uVar13;
                                }
                                else {
                                  iVar11 = (**(code **)(*plVar27 + 0x10))(plVar27);
                                  if (iVar11 == 3) {
                                    __ZN5GList6appendEPv(puVar26,plVar27);
                                  }
                                }
                              }
                              lVar35 = lVar35 + 1;
                              uVar38 = uVar38 - 1;
                            } while (uVar38 != 0);
                            if (CARRY4(local_2fc,uVar13)) {
LAB_183cfbad0:
                              uVar29 = (**(code **)(*param_1 + 0x28))(param_1);
                              __Z5erroriPKcz(uVar29,
                                             "Too many input symbols in JBIG2 symbol dictionary");
                              halt_baddata();
                            }
                          }
                          uVar13 = local_2fc + uVar13;
                          uVar38 = (ulong)uVar13;
                          lVar35 = __Z14gmallocn_typediiy(uVar38,8,0x2004093837f09);
                          if (uVar13 != 0) {
                            func_0x0001881382e0(lVar35,uVar38 << 3);
                          }
                          if (uVar15 != 0) {
                            uVar42 = 0;
                            uVar41 = 0;
                            do {
                              plVar27 = (long *)__ZN11JBIG2Stream11findSegmentEj
                                                          (param_1,piVar23[uVar42]);
                              if (((plVar27 != (long *)0x0) &&
                                  (iVar11 = (**(code **)(*plVar27 + 0x10))(), iVar11 == 1)) &&
                                 (uVar15 = *(uint *)((long)plVar27 + 0xc),
                                 uVar15 != 0 && (uint)uVar41 < uVar13)) {
                                lVar37 = 0;
                                lVar31 = plVar27[2];
                                uVar41 = uVar41 & 0xffffffff;
                                uVar32 = uVar41;
                                uVar33 = 1;
                                do {
                                  *(undefined8 *)(lVar35 + uVar32 * 8) =
                                       *(undefined8 *)(lVar31 + lVar37 * 8);
                                  uVar3 = uVar33 + 1;
                                  if (uVar15 <= uVar33) break;
                                  uVar32 = uVar32 + 1;
                                  uVar4 = uVar41 + uVar33;
                                  lVar37 = lVar37 + 1;
                                  uVar33 = uVar3;
                                } while (uVar4 < uVar38);
                                uVar41 = (uVar41 + uVar3) - 1;
                              }
                              uVar42 = uVar42 + 1;
                            } while (uVar42 != uVar36);
                          }
                          if ((uVar12 & 1) == 0) {
                            halt_baddata();
                          }
                          uVar13 = uVar12 >> 2 & 3;
                          if ((uVar13 == 0) || (uVar13 == 1)) {
                            uVar13 = 0;
                          }
                          else {
                            if (*(int *)((long)puVar26 + 0xc) == 0) goto LAB_183cfbcc4;
                            uVar13 = 1;
                          }
                          uVar15 = uVar12 >> 4 & 3;
                          if ((uVar15 != 0) && (uVar15 != 1)) {
                            if (*(uint *)((long)puVar26 + 0xc) <= uVar13) goto LAB_183cfbcc4;
                            uVar13 = uVar13 + 1;
                          }
                          if ((uVar12 >> 6 & 1) != 0) {
                            if (*(uint *)((long)puVar26 + 0xc) <= uVar13) goto LAB_183cfbcc4;
                            uVar13 = uVar13 + 1;
                          }
                          if ((uVar12 >> 7 & 1) == 0) {
                            halt_baddata();
                          }
                          if (uVar13 < *(uint *)((long)puVar26 + 0xc)) {
                            halt_baddata();
                          }
LAB_183cfbcc4:
                          uVar29 = (**(code **)(*param_1 + 0x28))(param_1);
                          __Z5erroriPKcz(uVar29,"Missing code table in JBIG2 symbol dictionary");
                          halt_baddata();
                        }
                      }
                    }
                    else {
                      uVar13 = (**(code **)(*(long *)param_1[10] + 0x20))();
                      if (uVar13 != 0xffffffff) {
                        local_2e8 = uVar13;
                        if ((uVar13 & 0x80) != 0) {
                          local_2e8 = uVar13 | 0xffffff00;
                        }
                        uVar13 = (**(code **)(*(long *)param_1[10] + 0x20))();
                        if (uVar13 != 0xffffffff) {
                          local_2f0 = uVar13;
                          if ((uVar13 & 0x80) != 0) {
                            local_2f0 = uVar13 | 0xffffff00;
                          }
                          uVar13 = (**(code **)(*(long *)param_1[10] + 0x20))();
                          if (uVar13 != 0xffffffff) {
                            local_2e4 = uVar13;
                            if ((uVar13 & 0x80) != 0) {
                              local_2e4 = uVar13 | 0xffffff00;
                            }
                            uVar13 = (**(code **)(*(long *)param_1[10] + 0x20))();
                            if (uVar13 != 0xffffffff) {
                              local_2ec = uVar13;
                              if ((uVar13 & 0x80) != 0) {
                                local_2ec = uVar13 | 0xffffff00;
                              }
                              goto LAB_183cf94fc;
                            }
                          }
                        }
                      }
                    }
                  }
                }
                uVar29 = (**(code **)(*param_1 + 0x28))(param_1);
                pcVar30 = "Unexpected EOF in JBIG2 stream";
                goto LAB_183cfbb44;
              }
              if (uVar17 != 4) goto LAB_183cf9198;
            }
            local_2f0 = 0;
            local_308 = local_308 & 0xffffffff;
            local_310 = local_310 & 0xffffffff;
            iVar11 = __ZN11JBIG2Stream9readULongEPj(param_1,&local_2f0);
            if (iVar11 != 0) {
              local_2f4 = 0;
              iVar11 = __ZN11JBIG2Stream9readULongEPj(param_1,&local_2f4);
              if (iVar11 != 0) {
                local_2f8 = 0;
                iVar11 = __ZN11JBIG2Stream9readULongEPj(param_1,&local_2f8);
                if (iVar11 != 0) {
                  local_2fc = 0;
                  iVar11 = __ZN11JBIG2Stream9readULongEPj(param_1,&local_2fc);
                  if ((iVar11 != 0) &&
                     (iVar11 = (**(code **)(*(long *)param_1[10] + 0x20))(), iVar11 != -1)) {
                    local_300 = 0;
                    iVar11 = __ZN11JBIG2Stream9readUWordEPj(param_1,&local_300);
                    uVar12 = local_300;
                    if (iVar11 != 0) {
                      if ((local_300 & 1) == 0) {
                        uVar16 = 0;
                        uVar13 = 0;
                        uVar18 = 0;
                        uVar17 = 0;
                        uVar43 = 0;
                        uVar40 = 0;
                        uVar21 = 0;
                        bVar10 = true;
                      }
                      else {
                        iVar11 = __ZN11JBIG2Stream9readUWordEPj(param_1,(long)&local_308 + 4);
                        if (iVar11 == 0) goto LAB_183cfa5f8;
                        uVar16 = local_308._4_4_ >> 2 & 3;
                        uVar13 = local_308._4_4_ & 3;
                        uVar17 = local_308._4_4_ >> 4 & 3;
                        uVar18 = local_308._4_4_ >> 6 & 3;
                        uVar40 = local_308._4_4_ >> 8 & 3;
                        uVar43 = local_308._4_4_ >> 10 & 3;
                        uVar21 = local_308._4_4_ >> 0xc & 3;
                        bVar10 = (local_308 & 0x400000000000) == 0;
                      }
                      if (((uVar12 >> 1 & 1) == 0) || ((uVar12 >> 0xf & 1) != 0)) {
LAB_183cfa4d4:
                        local_308 = local_308 & 0xffffffff00000000;
                        iVar11 = __ZN11JBIG2Stream9readULongEPj(param_1,&local_308);
                        if (iVar11 != 0) {
                          puVar26 = (undefined8 *)func_0x00018814d110(0x18,0x1080c40a085cba5);
                          *(undefined4 *)(puVar26 + 1) = 8;
                          uVar29 = __Z13gmalloc_typediy(0x40,0x80040b8603338);
                          *puVar26 = uVar29;
                          *(undefined4 *)((long)puVar26 + 0xc) = 0;
                          *(undefined4 *)(puVar26 + 2) = 0;
                          if (uVar15 != 0) {
                            lVar35 = 0;
                            uVar15 = 0;
                            uVar38 = uVar36;
                            do {
                              plVar27 = (long *)__ZN11JBIG2Stream11findSegmentEj
                                                          (param_1,piVar23[lVar35]);
                              if (plVar27 == (long *)0x0) {
                                uVar29 = (**(code **)(*param_1 + 0x28))(param_1);
                                pcVar30 = "Invalid segment reference in JBIG2 text region";
LAB_183cfab40:
                                __Z5erroriPKcz(uVar29,pcVar30);
                                halt_baddata();
                              }
                              iVar11 = (**(code **)(*plVar27 + 0x10))();
                              if (iVar11 == 1) {
                                bVar9 = CARRY4(uVar15,*(uint *)((long)plVar27 + 0xc));
                                uVar15 = uVar15 + *(uint *)((long)plVar27 + 0xc);
                                if (bVar9) {
                                  uVar29 = (**(code **)(*param_1 + 0x28))(param_1);
                                  pcVar30 = "Number of symbols would overflow";
                                  goto LAB_183cfab40;
                                }
                              }
                              else {
                                iVar11 = (**(code **)(*plVar27 + 0x10))(plVar27);
                                if (iVar11 == 3) {
                                  __ZN5GList6appendEPv(puVar26,plVar27);
                                }
                              }
                              lVar35 = lVar35 + 1;
                              uVar38 = uVar38 - 1;
                            } while (uVar38 != 0);
                            if (1 < uVar15) {
                              uVar20 = 1;
                              do {
                                uVar20 = uVar20 << 1;
                              } while (uVar20 < uVar15);
                            }
                            lVar35 = __Z14gmallocn_typediiy(uVar15,8,0x2004093837f09);
                            uVar42 = 0;
                            uVar38 = 0;
                            do {
                              plVar27 = (long *)__ZN11JBIG2Stream11findSegmentEj
                                                          (param_1,piVar23[uVar42]);
                              if (plVar27 != (long *)0x0) {
                                iVar11 = (**(code **)(*plVar27 + 0x10))();
                                uVar20 = (uint)uVar38;
                                if (iVar11 == 1 && uVar20 < uVar15) {
                                  lVar31 = 0;
                                  lVar37 = 0;
                                  uVar5 = *(uint *)((long)plVar27 + 0xc);
                                  uVar41 = uVar38 & 0xffffffff;
                                  do {
                                    uVar38 = uVar41;
                                    if ((ulong)uVar5 * 8 - lVar31 == 0) break;
                                    uVar38 = uVar41 + 1;
                                    *(undefined8 *)(lVar35 + uVar41 * 8) =
                                         *(undefined8 *)(plVar27[2] + lVar37 * 8);
                                    lVar37 = lVar37 + 1;
                                    lVar31 = lVar31 + 8;
                                    uVar41 = uVar38;
                                  } while ((ulong)(uVar15 - uVar20) << 3 != lVar31);
                                }
                              }
                              uVar42 = uVar42 + 1;
                            } while (uVar42 != uVar36);
                          }
                          if ((uVar12 & 1) == 0) {
                            halt_baddata();
                          }
                          if (uVar13 == 0) {
                            uVar12 = 0;
                          }
                          else if (uVar13 == 1) {
                            uVar12 = 0;
                          }
                          else {
                            if (*(int *)((long)puVar26 + 0xc) == 0) goto LAB_183cfb3e0;
                            uVar12 = 1;
                          }
                          if ((1 < uVar16) && (uVar16 != 2)) {
                            if (*(uint *)((long)puVar26 + 0xc) <= uVar12) goto LAB_183cfb3e0;
                            uVar12 = uVar12 + 1;
                          }
                          if ((1 < uVar17) && (uVar17 != 2)) {
                            if (*(uint *)((long)puVar26 + 0xc) <= uVar12) goto LAB_183cfb3e0;
                            uVar12 = uVar12 + 1;
                          }
                          if ((uVar18 != 0) && (uVar18 != 1)) {
                            if (*(uint *)((long)puVar26 + 0xc) <= uVar12) goto LAB_183cfb3e0;
                            uVar12 = uVar12 + 1;
                          }
                          if ((uVar40 != 0) && (uVar40 != 1)) {
                            if (*(uint *)((long)puVar26 + 0xc) <= uVar12) goto LAB_183cfb3e0;
                            uVar12 = uVar12 + 1;
                          }
                          if ((uVar43 != 0) && (uVar43 != 1)) {
                            if (*(uint *)((long)puVar26 + 0xc) <= uVar12) goto LAB_183cfb3e0;
                            uVar12 = uVar12 + 1;
                          }
                          if ((uVar21 != 0) && (uVar21 != 1)) {
                            if (*(uint *)((long)puVar26 + 0xc) <= uVar12) goto LAB_183cfb3e0;
                            uVar12 = uVar12 + 1;
                          }
                          if (bVar10) {
                            halt_baddata();
                          }
                          if (uVar12 < *(uint *)((long)puVar26 + 0xc)) {
                            halt_baddata();
                          }
LAB_183cfb3e0:
                          uVar29 = (**(code **)(*param_1 + 0x28))(param_1);
                          __Z5erroriPKcz(uVar29,"Missing code table in JBIG2 text region");
                          halt_baddata();
                        }
                      }
                      else {
                        uVar20 = (**(code **)(*(long *)param_1[10] + 0x20))();
                        if (uVar20 != 0xffffffff) {
                          if ((uVar20 & 0x80) != 0) {
                            uVar20 = uVar20 | 0xffffff00;
                          }
                          local_a0 = CONCAT44(local_a0._4_4_,uVar20);
                          uVar20 = (**(code **)(*(long *)param_1[10] + 0x20))();
                          if (uVar20 != 0xffffffff) {
                            local_2e8 = uVar20;
                            if ((uVar20 & 0x80) != 0) {
                              local_2e8 = uVar20 | 0xffffff00;
                            }
                            uVar20 = (**(code **)(*(long *)param_1[10] + 0x20))();
                            if (uVar20 != 0xffffffff) {
                              if ((uVar20 & 0x80) != 0) {
                                uVar20 = uVar20 | 0xffffff00;
                              }
                              local_a0 = CONCAT44(uVar20,(int)local_a0);
                              uVar20 = (**(code **)(*(long *)param_1[10] + 0x20))();
                              if (uVar20 != 0xffffffff) {
                                local_2e4 = uVar20;
                                if ((uVar20 & 0x80) != 0) {
                                  local_2e4 = uVar20 | 0xffffff00;
                                }
                                goto LAB_183cfa4d4;
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
LAB_183cfa5f8:
            uVar29 = (**(code **)(*param_1 + 0x28))(param_1);
          }
          else {
            if (uVar17 < 0x16) {
              if (uVar17 == 0x10) {
                uVar12 = (**(code **)(*(long *)param_1[10] + 0x20))();
                if (uVar12 != 0xffffffff) {
                  uVar29 = (**(code **)(*(long *)param_1[10] + 0x20))();
                  uVar15 = (uint)uVar29;
                  if (uVar15 != 0xffffffff) {
                    uVar24 = (**(code **)(*(long *)param_1[10] + 0x20))();
                    if ((uint)uVar24 != 0xffffffff) {
                      local_2e8 = 0;
                      iVar14 = __ZN11JBIG2Stream9readULongEPj(param_1,&local_2e8);
                      uVar17 = local_2e8;
                      if (iVar14 != 0) {
                        if (0xfffe < uVar15) {
                          halt_baddata();
                        }
                        if (0xfffe < (uint)uVar24) {
                          halt_baddata();
                        }
                        if (0xfffe < local_2e8) {
                          halt_baddata();
                        }
                        uVar18 = uVar12 >> 1 & 3;
                        if ((uVar12 & 1) == 0) {
                          __ZN11JBIG2Stream17resetGenericStatsEjP23JArithmeticDecoderStats
                                    (param_1,uVar18,0);
                          __ZN18JArithmeticDecoder5startEv(param_1[0xd]);
                        }
                        local_2e0 = -uVar15;
                        local_2dc = 0x2fffffffd;
                        local_2d4 = 0xfffffffe;
                        uStack_98 = 0xfffffffefffffffe;
                        local_a0 = 0xffffffff00000000;
                        iVar14 = uVar17 + 1;
                        plVar27 = (long *)__ZN11JBIG2Stream17readGenericBitmapEiiiiiiP11JBIG2BitmapPiS2_i
                                                    (param_1,uVar12 & 1,iVar14 * uVar15,uVar24,
                                                     uVar18,0,0,0,&local_2e0,&local_a0,
                                                     CONCAT44(uVar16,iVar11 + -7));
                        puVar26 = (undefined8 *)func_0x00018814d110(0x18,0x1081c40eef68e16);
                        *(uint *)(puVar26 + 1) = uVar13;
                        *(int *)((long)puVar26 + 0xc) = iVar14;
                        *puVar26 = &DAT_1e2234350;
                        uVar25 = __Z14gmallocn_typediiy(iVar14,8,0x2004093837f09);
                        iVar11 = 0;
                        uVar12 = 0;
                        puVar26[2] = uVar25;
                        do {
                          uVar25 = __ZN11JBIG2Bitmap8getSliceEjjjj(plVar27,iVar11,0,uVar29,uVar24);
                          if (uVar12 < *(uint *)((long)puVar26 + 0xc)) {
                            *(undefined8 *)(puVar26[2] + (ulong)uVar12 * 8) = uVar25;
                          }
                          iVar11 = iVar11 + uVar15;
                          uVar12 = uVar12 + 1;
                        } while (uVar12 <= uVar17);
                        if (plVar27 != (long *)0x0) {
                          (**(code **)(*plVar27 + 8))(plVar27);
                        }
                        __ZN5GList6appendEPv(param_1[8],puVar26);
                        halt_baddata();
                      }
                    }
                  }
                }
                uVar29 = (**(code **)(*param_1 + 0x28))(param_1);
                goto LAB_183cfb96c;
              }
              if (uVar17 != 0x14) goto LAB_183cf9198;
            }
            else if (1 < uVar17 - 0x16) {
              if (uVar17 != 0x24) goto LAB_183cf9198;
              goto LAB_183cf8aa8;
            }
            local_2e8 = 0;
            iVar11 = __ZN11JBIG2Stream9readULongEPj(param_1,&local_2e8);
            if (iVar11 != 0) {
              local_2f0 = 0;
              iVar11 = __ZN11JBIG2Stream9readULongEPj(param_1,&local_2f0);
              if (iVar11 != 0) {
                local_2f4 = 0;
                iVar11 = __ZN11JBIG2Stream9readULongEPj(param_1,&local_2f4);
                if (iVar11 != 0) {
                  local_2f8 = 0;
                  iVar11 = __ZN11JBIG2Stream9readULongEPj(param_1,&local_2f8);
                  if (((iVar11 != 0) &&
                      (iVar11 = (**(code **)(*(long *)param_1[10] + 0x20))(), iVar11 != -1)) &&
                     (uVar12 = (**(code **)(*(long *)param_1[10] + 0x20))(), uVar12 != 0xffffffff))
                  {
                    local_2fc = 0;
                    iVar11 = __ZN11JBIG2Stream9readULongEPj(param_1,&local_2fc);
                    if (iVar11 != 0) {
                      local_300 = 0;
                      iVar11 = __ZN11JBIG2Stream9readULongEPj(param_1,&local_300);
                      if (iVar11 != 0) {
                        local_310 = local_310 & 0xffffffff;
                        iVar11 = __ZN11JBIG2Stream9readULongEPj(param_1,(long)&local_310 + 4);
                        if (iVar11 != 0) {
                          local_310 = local_310 & 0xffffffff00000000;
                          iVar11 = __ZN11JBIG2Stream9readULongEPj(param_1,&local_310);
                          if (iVar11 != 0) {
                            local_308 = local_308 & 0xffffffff;
                            iVar11 = __ZN11JBIG2Stream9readUWordEPj(param_1,(long)&local_308 + 4);
                            if (iVar11 != 0) {
                              local_308 = local_308 & 0xffffffff00000000;
                              iVar11 = __ZN11JBIG2Stream9readUWordEPj(param_1,&local_308);
                              uVar40 = local_2e8;
                              uVar18 = local_2f0;
                              uVar17 = local_2fc;
                              uVar16 = local_300;
                              if (iVar11 != 0) {
                                if ((local_2e8 != 0) && (local_2f0 != 0)) {
                                  uVar43 = 0;
                                  if (local_2f0 != 0) {
                                    uVar43 = 0x7fffffff / local_2f0;
                                  }
                                  if (local_2e8 < uVar43) {
                                    if (local_300 != 0) {
                                      uVar43 = 0;
                                      if (local_300 != 0) {
                                        uVar43 = 0x7fffffff / local_300;
                                      }
                                      if (local_2fc < uVar43) {
                                        if (uVar15 == 1) {
                                          plVar27 = (long *)__ZN11JBIG2Stream11findSegmentEj
                                                                      (param_1,*piVar23);
                                          if ((plVar27 != (long *)0x0) &&
                                             (iVar11 = (**(code **)(*plVar27 + 0x10))(), iVar11 == 2
                                             )) {
                                            if (*(uint *)((long)plVar27 + 0xc) < 2) {
                                              local_3c0 = -1;
                                            }
                                            else {
                                              uVar15 = 1;
                                              local_3c0 = -1;
                                              do {
                                                uVar15 = uVar15 << 1;
                                                local_3c0 = local_3c0 + 1;
                                              } while (uVar15 < *(uint *)((long)plVar27 + 0xc));
                                            }
                                            lVar35 = *(long *)plVar27[2];
                                            iVar11 = *(int *)(lVar35 + 0x10);
                                            lVar37 = pacga((long)iVar11,
                                                           (ulong)(lVar35 + 0x10) & 0xffffffffffff |
                                                           0x5363000000000000);
                                            if (lVar37 != *(long *)(lVar35 + 0x18)) {
LAB_183cfbddc:
                                              func_0x000188138260();
                                              return;
                                            }
                                            iVar14 = *(int *)(lVar35 + 0x20);
                                            lVar37 = pacga((long)iVar14,
                                                           (ulong)(lVar35 + 0x20) & 0xffffffffffff |
                                                           0x5363000000000000);
                                            if (lVar37 != *(long *)(lVar35 + 0x28))
                                            goto LAB_183cfbddc;
                                            uVar15 = uVar12 >> 1 & 3;
                                            if ((uVar12 & 1) == 0) {
                                              __ZN11JBIG2Stream17resetGenericStatsEjP23JArithmeticDecoderStats
                                                        (param_1,uVar15,0);
                                              __ZN18JArithmeticDecoder5startEv(param_1[0xd]);
                                            }
                                            lVar35 = func_0x00018814d110(0x48,0x10d1c40b539ea8f);
                                            __ZN11JBIG2BitmapC2Ejii(lVar35,uVar13,uVar40,uVar18);
                                            if ((*(long *)(lVar35 + 0x40) != 0) &&
                                               (*(long *)(lVar35 + 0x40) != 0)) {
                                              if ((uVar12 >> 7 & 1) == 0) {
                                                __ZN11JBIG2Bitmap11clearToZeroEv(lVar35);
                                              }
                                              else {
                                                __ZN11JBIG2Bitmap10clearToOneEv(lVar35);
                                              }
                                              uVar13 = uVar12 >> 3 & 1;
                                              if (uVar13 == 0) {
                                                local_380 = 0;
LAB_183cfb6f4:
                                                lVar37 = __Z14gmallocn_typediiy
                                                                   ((ulong)(uVar17 * uVar16),4,
                                                                    0x100004052888210);
                                                func_0x0001881382e0(lVar37,(ulong)(uVar17 * uVar16)
                                                                           << 2);
                                                local_2e0 = 2;
                                                if (uVar15 < 2) {
                                                  local_2e0 = 3;
                                                }
                                                local_2dc = 0x2fffffffd;
                                                local_2d4 = 0xfffffffe;
                                                uStack_98 = 0xfffffffefffffffe;
                                                local_a0 = 0xffffffffffffffff;
                                                if (-1 < local_3c0) {
                                                  do {
                                                    plVar28 = (long *)
                                                  __ZN11JBIG2Stream17readGenericBitmapEiiiiiiP11JBIG2BitmapPiS2_i
                                                            (param_1,uVar12 & 1,uVar17,uVar16,uVar15
                                                             ,0,uVar13,local_380,&local_2e0,
                                                             &local_a0,0xffffffff);
                                                  uVar36 = 0;
                                                  uVar18 = 0;
                                                  do {
                                                    if (uVar17 != 0) {
                                                      uVar40 = 0;
                                                      do {
                                                        uVar21 = __ZN11JBIG2Bitmap8getPixelEii
                                                                           (plVar28,uVar40,uVar18);
                                                        uVar43 = *(uint *)(lVar37 + uVar36 * 4);
                                                        *(uint *)(lVar37 + uVar36 * 4) =
                                                             uVar43 & 1 ^ uVar21 | uVar43 << 1;
                                                        uVar36 = (ulong)((int)uVar36 + 1);
                                                        uVar40 = uVar40 + 1;
                                                      } while (uVar17 != uVar40);
                                                    }
                                                    uVar18 = uVar18 + 1;
                                                  } while (uVar18 != uVar16);
                                                  if (plVar28 != (long *)0x0) {
                                                    (**(code **)(*plVar28 + 8))(plVar28);
                                                  }
                                                  bVar10 = 0 < local_3c0;
                                                  local_3c0 = local_3c0 + -1;
                                                  } while (bVar10);
                                                }
                                                uVar36 = 0;
                                                uVar15 = 0;
                                                iVar14 = local_310._4_4_;
                                                iVar6 = (int)local_308;
                                                iVar11 = (int)local_310;
                                                iVar7 = local_308._4_4_;
                                                do {
                                                  if (uVar17 != 0) {
                                                    uVar18 = 0;
                                                    iVar34 = iVar11 + iVar7 * uVar15;
                                                    iVar39 = iVar14 + iVar6 * uVar15;
                                                    do {
                                                      if ((uVar13 == 0) ||
                                                         (iVar22 = __ZN11JBIG2Bitmap8getPixelEii
                                                                             (local_380,uVar18,
                                                                              uVar15), iVar22 == 0))
                                                      {
                                                        uVar40 = *(uint *)(lVar37 + uVar36 * 4);
                                                        if (uVar40 < *(uint *)((long)plVar27 + 0xc))
                                                        {
                                                          uVar29 = *(undefined8 *)
                                                                    (plVar27[2] + (ulong)uVar40 * 8)
                                                          ;
                                                        }
                                                        else {
                                                          uVar29 = 0;
                                                        }
                                                        __ZN11JBIG2Bitmap7combineEPS_iij
                                                                  (lVar35,uVar29,iVar39 >> 8,
                                                                   iVar34 >> 8,uVar12 >> 4 & 7);
                                                      }
                                                      iVar39 = iVar39 + iVar7;
                                                      iVar34 = iVar34 - iVar6;
                                                      uVar36 = (ulong)((int)uVar36 + 1);
                                                      uVar18 = uVar18 + 1;
                                                    } while (uVar17 != uVar18);
                                                  }
                                                  uVar15 = uVar15 + 1;
                                                } while (uVar15 != uVar16);
                                                halt_baddata();
                                              }
                                              local_380 = func_0x00018814d110(0x48,0x10d1c40b539ea8f
                                                                             );
                                              __ZN11JBIG2BitmapC2Ejii(local_380,0,uVar17,uVar16);
                                              if ((*(long *)(local_380 + 0x40) != 0) &&
                                                 (*(long *)(local_380 + 0x40) != 0)) {
                                                __ZN11JBIG2Bitmap11clearToZeroEv(local_380);
                                                uVar43 = 0;
                                                local_3b4 = local_310._4_4_;
                                                iVar6 = (int)local_308;
                                                iVar7 = local_308._4_4_;
                                                local_3c8 = (int)local_310;
                                                do {
                                                  if (uVar17 != 0) {
                                                    uVar21 = 0;
                                                    iVar39 = local_3b4;
                                                    iVar34 = local_3c8;
                                                    do {
                                                      if ((((iVar11 + iVar39 < 0x100) ||
                                                           ((int)uVar40 <= iVar39 >> 8)) ||
                                                          (iVar14 + iVar34 < 0x100)) ||
                                                         ((int)uVar18 <= iVar34 >> 8)) {
                                                        __ZN11JBIG2Bitmap8setPixelEii
                                                                  (local_380,uVar21,uVar43);
                                                      }
                                                      uVar21 = uVar21 + 1;
                                                      iVar34 = iVar34 - iVar6;
                                                      iVar39 = iVar39 + iVar7;
                                                    } while (uVar17 != uVar21);
                                                  }
                                                  uVar43 = uVar43 + 1;
                                                  local_3c8 = local_3c8 + iVar7;
                                                  local_3b4 = local_3b4 + iVar6;
                                                } while (uVar43 != uVar16);
                                                goto LAB_183cfb6f4;
                                              }
                                            }
                                            goto LAB_183cfb94c;
                                          }
                                          uVar29 = (**(code **)(*param_1 + 0x28))(param_1);
                                        }
                                        else {
                                          uVar29 = (**(code **)(*param_1 + 0x28))(param_1);
                                        }
                                        pcVar30 = 
                                        "Bad symbol dictionary reference in JBIG2 halftone segment";
                                        goto LAB_183cfb974;
                                      }
                                    }
                                    uVar29 = (**(code **)(*param_1 + 0x28))(param_1);
                                    pcVar30 = "Bad grid size in JBIG2 halftone segment";
                                    goto LAB_183cfb974;
                                  }
                                }
                                uVar29 = (**(code **)(*param_1 + 0x28))(param_1);
                                pcVar30 = "Bad bitmap size in JBIG2 halftone segment";
                                goto LAB_183cfb974;
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
LAB_183cfb94c:
            uVar29 = (**(code **)(*param_1 + 0x28))(param_1);
          }
        }
        else if (uVar17 < 0x30) {
          if (uVar17 - 0x26 < 2) {
            bVar10 = false;
LAB_183cf8aa8:
            local_2e8 = 0;
            iVar14 = __ZN11JBIG2Stream9readULongEPj(param_1,&local_2e8);
            if (iVar14 != 0) {
              local_2f0 = 0;
              iVar14 = __ZN11JBIG2Stream9readULongEPj(param_1,&local_2f0);
              if (iVar14 != 0) {
                local_2f4 = 0;
                iVar14 = __ZN11JBIG2Stream9readULongEPj(param_1,&local_2f4);
                if (iVar14 != 0) {
                  local_2f8 = 0;
                  iVar14 = __ZN11JBIG2Stream9readULongEPj(param_1,&local_2f8);
                  if (((iVar14 != 0) &&
                      (uVar12 = (**(code **)(*(long *)param_1[10] + 0x20))(), uVar12 != 0xffffffff))
                     && (uVar17 = (**(code **)(*(long *)param_1[10] + 0x20))(), uVar15 = local_2f0,
                        uVar17 != 0xffffffff)) {
                    uVar18 = uVar17 >> 1 & 3;
                    uVar40 = uVar17 >> 3 & 1;
                    if ((uVar17 & 1) == 0) {
                      uVar15 = (**(code **)(*(long *)param_1[10] + 0x20))();
                      if (uVar18 == 0) {
                        if (uVar15 != 0xffffffff) {
                          local_2e0 = uVar15;
                          if ((uVar15 & 0x80) != 0) {
                            local_2e0 = uVar15 | 0xffffff00;
                          }
                          uVar15 = (**(code **)(*(long *)param_1[10] + 0x20))();
                          if (uVar15 != 0xffffffff) {
                            if ((uVar15 & 0x80) != 0) {
                              uVar15 = uVar15 | 0xffffff00;
                            }
                            local_a0 = CONCAT44(local_a0._4_4_,uVar15);
                            uVar15 = (**(code **)(*(long *)param_1[10] + 0x20))();
                            if (uVar15 != 0xffffffff) {
                              if ((uVar15 & 0x80) != 0) {
                                uVar15 = uVar15 | 0xffffff00;
                              }
                              local_2dc = CONCAT44(local_2dc._4_4_,uVar15);
                              uVar15 = (**(code **)(*(long *)param_1[10] + 0x20))();
                              if (uVar15 != 0xffffffff) {
                                if ((uVar15 & 0x80) != 0) {
                                  uVar15 = uVar15 | 0xffffff00;
                                }
                                local_a0 = CONCAT44(uVar15,(int)local_a0);
                                uVar15 = (**(code **)(*(long *)param_1[10] + 0x20))();
                                if (uVar15 != 0xffffffff) {
                                  if ((uVar15 & 0x80) != 0) {
                                    uVar15 = uVar15 | 0xffffff00;
                                  }
                                  local_2dc = CONCAT44(uVar15,(undefined4)local_2dc);
                                  uVar15 = (**(code **)(*(long *)param_1[10] + 0x20))();
                                  if (uVar15 != 0xffffffff) {
                                    if ((uVar15 & 0x80) != 0) {
                                      uVar15 = uVar15 | 0xffffff00;
                                    }
                                    uStack_98 = CONCAT44(uStack_98._4_4_,uVar15);
                                    uVar15 = (**(code **)(*(long *)param_1[10] + 0x20))();
                                    if (uVar15 != 0xffffffff) {
                                      local_2d4 = uVar15;
                                      if ((uVar15 & 0x80) != 0) {
                                        local_2d4 = uVar15 | 0xffffff00;
                                      }
                                      uVar15 = (**(code **)(*(long *)param_1[10] + 0x20))();
                                      if (uVar15 != 0xffffffff) {
                                        uVar17 = 0;
                                        if ((uVar15 & 0x80) != 0) {
                                          uVar15 = uVar15 | 0xffffff00;
                                        }
                                        uStack_98 = CONCAT44(uVar15,(undefined4)uStack_98);
                                        goto LAB_183cf8bd4;
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                      else if (uVar15 != 0xffffffff) {
                        local_2e0 = uVar15;
                        if ((uVar15 & 0x80) != 0) {
                          local_2e0 = uVar15 | 0xffffff00;
                        }
                        uVar15 = (**(code **)(*(long *)param_1[10] + 0x20))();
                        if (uVar15 != 0xffffffff) {
                          if ((uVar15 & 0x80) != 0) {
                            uVar15 = uVar15 | 0xffffff00;
                          }
                          local_a0 = CONCAT44(local_a0._4_4_,uVar15);
                          uVar17 = uVar18;
LAB_183cf8bd4:
                          __ZN11JBIG2Stream17resetGenericStatsEjP23JArithmeticDecoderStats
                                    (param_1,uVar17,0);
                          __ZN18JArithmeticDecoder5startEv(param_1[0xd]);
                          uVar15 = local_2f0;
                          plVar27 = (long *)__ZN11JBIG2Stream17readGenericBitmapEiiiiiiP11JBIG2BitmapPiS2_i
                                                      (param_1,0,local_2e8,local_2f0,uVar18,uVar40,0
                                                       ,0,&local_2e0,&local_a0,(ulong)uVar16 << 0x20
                                                      );
                          goto LAB_183cfa65c;
                        }
                      }
                    }
                    else {
                      plVar27 = (long *)__ZN11JBIG2Stream17readGenericBitmapEiiiiiiP11JBIG2BitmapPiS2_i
                                                  (param_1,1,local_2e8,local_2f0,uVar18,uVar40,0,0,
                                                   &local_2e0,&local_a0,
                                                   CONCAT44(uVar16,iVar11 + -0x12));
LAB_183cfa65c:
                      iVar11 = local_2f8;
                      if (plVar27 != (long *)0x0) {
                        if (bVar10) {
                          *(uint *)(plVar27 + 1) = uVar13;
                          __ZN5GList6appendEPv(param_1[8],plVar27);
                          halt_baddata();
                        }
                        if ((*(int *)((long)param_1 + 0x24) == -1) &&
                           (*(uint *)(param_1 + 5) < local_2f8 + uVar15)) {
                          __ZN11JBIG2Bitmap6expandEij
                                    (param_1[6],local_2f8 + uVar15,
                                     *(undefined4 *)((long)param_1 + 0x2c));
                        }
                        __ZN11JBIG2Bitmap7combineEPS_iij
                                  (param_1[6],plVar27,local_2f4,iVar11,uVar12 & 7);
                        pcVar8 = *(code **)(*plVar27 + 8);
LAB_183cfa740:
                        (*pcVar8)(plVar27);
                        halt_baddata();
                      }
                    }
                  }
                }
              }
            }
            uVar29 = (**(code **)(*param_1 + 0x28))(param_1);
          }
          else {
            if (uVar17 - 0x2a < 2) {
              bVar10 = true;
            }
            else {
              if (uVar17 != 0x28) goto LAB_183cf9198;
              bVar10 = false;
            }
            local_2e8 = 0;
            iVar11 = __ZN11JBIG2Stream9readULongEPj(param_1,&local_2e8);
            if (iVar11 != 0) {
              local_2f0 = 0;
              iVar11 = __ZN11JBIG2Stream9readULongEPj(param_1,&local_2f0);
              if (iVar11 != 0) {
                local_2f4 = 0;
                iVar11 = __ZN11JBIG2Stream9readULongEPj(param_1,&local_2f4);
                if (iVar11 != 0) {
                  local_2f8 = 0;
                  iVar11 = __ZN11JBIG2Stream9readULongEPj(param_1,&local_2f8);
                  if (((iVar11 != 0) &&
                      (uVar12 = (**(code **)(*(long *)param_1[10] + 0x20))(), uVar12 != 0xffffffff))
                     && (uVar16 = (**(code **)(*(long *)param_1[10] + 0x20))(), uVar16 != 0xffffffff
                        )) {
                    if ((uVar16 & 1) != 0) {
LAB_183cf8a08:
                      if (((!(bool)(uVar15 != 0 & (bVar10 ^ 1U))) &&
                          (*(int *)((long)param_1 + 0x24) == -1)) &&
                         (*(uint *)(param_1 + 5) < local_2f0 + local_2f8)) {
                        __ZN11JBIG2Bitmap6expandEij
                                  (param_1[6],local_2f0 + local_2f8,
                                   *(undefined4 *)((long)param_1 + 0x2c));
                      }
                      uVar18 = local_2e8;
                      uVar17 = local_2f0;
                      if (uVar15 < 2) {
                        if (uVar15 == 1) {
                          plVar27 = (long *)__ZN11JBIG2Stream11findSegmentEj(param_1,*piVar23);
                          if ((plVar27 == (long *)0x0) ||
                             (iVar11 = (**(code **)(*plVar27 + 0x10))(), uVar18 = local_2e8,
                             uVar17 = local_2f0, iVar11 != 0)) {
                            uVar29 = (**(code **)(*param_1 + 0x28))(param_1);
                            pcVar30 = "Bad bitmap reference in JBIG2 generic refinement segment";
                            goto LAB_183cfb974;
                          }
                        }
                        else {
                          plVar27 = (long *)__ZN11JBIG2Bitmap8getSliceEjjjj
                                                      (param_1[6],local_2f4,local_2f8,local_2e8,
                                                       local_2f0);
                        }
                        __ZN11JBIG2Stream20resetRefinementStatsEjP23JArithmeticDecoderStats
                                  (param_1,uVar16 & 1,0);
                        __ZN18JArithmeticDecoder5startEv(param_1[0xd]);
                        plVar28 = (long *)__ZN11JBIG2Stream27readGenericRefinementRegionEiiiiP11JBIG2BitmapiiPiS2_
                                                    (param_1,uVar18,uVar17,uVar16 & 1,
                                                     uVar16 >> 1 & 1,plVar27,0,0,&local_2e0,
                                                     &local_a0);
                        if (plVar28 == (long *)0x0) {
                          uVar29 = (**(code **)(*param_1 + 0x28))(param_1);
                          pcVar30 = "Bad bitmap in JBIG2 generic refinement region";
                          goto LAB_183cfb974;
                        }
                        if (bVar10) {
                          __ZN11JBIG2Bitmap7combineEPS_iij
                                    (param_1[6],plVar28,local_2f4,local_2f8,uVar12 & 7);
                          (**(code **)(*plVar28 + 8))(plVar28);
                        }
                        else {
                          *(uint *)(plVar28 + 1) = uVar13;
                          __ZN5GList6appendEPv(param_1[8],plVar28);
                        }
                        if (uVar15 == 1) {
                          plVar27 = (long *)param_1[9];
                          uVar12 = *(uint *)((long)plVar27 + 0xc);
                          if (0 < (int)uVar12) {
                            uVar36 = 0;
                            lVar35 = *plVar27;
                            do {
                              if (*(int *)(*(long *)(lVar35 + uVar36 * 8) + 8) == *piVar23)
                              goto LAB_183cfb2a4;
                              uVar36 = uVar36 + 1;
                            } while (uVar12 != uVar36);
                          }
                          plVar27 = (long *)param_1[8];
                          uVar12 = *(uint *)((long)plVar27 + 0xc);
                          if ((int)uVar12 < 1) {
                            halt_baddata();
                          }
                          uVar36 = 0;
                          lVar35 = *plVar27;
                          while (*(int *)(*(long *)(lVar35 + uVar36 * 8) + 8) != *piVar23) {
                            uVar36 = uVar36 + 1;
                            if (uVar12 == uVar36) {
                              halt_baddata();
                            }
                          }
LAB_183cfb2a4:
                          uVar13 = (uint)uVar36;
                          if ((int)uVar13 < (int)uVar12) {
                            uVar15 = uVar12 - 1;
                            if (uVar13 < uVar15) {
                              lVar35 = lVar35 + (uVar36 & 0xffffffff) * 8;
                              func_0x0001881384e0(lVar35,lVar35 + 8,
                                                  -(ulong)(uVar12 + ~uVar13 >> 0x1f) &
                                                  0xfffffff800000000 |
                                                  (ulong)(uVar12 + ~uVar13) << 3);
                              uVar15 = *(int *)((long)plVar27 + 0xc) - 1;
                            }
                            *(uint *)((long)plVar27 + 0xc) = uVar15;
                            iVar14 = (int)plVar27[1];
                            iVar11 = (int)plVar27[2];
                            if ((int)plVar27[2] < 1) {
                              iVar11 = iVar14 / 2;
                            }
                            if ((int)(iVar14 - uVar15) < iVar11) {
                              halt_baddata();
                            }
                            *(int *)(plVar27 + 1) = iVar14 - iVar11;
                            lVar35 = __Z15greallocn_typedPviiy
                                               (*plVar27,iVar14 - iVar11,8,0x80040b8603338);
                            *plVar27 = lVar35;
                            if (*(int *)((long)plVar27 + 0xc) <= (int)plVar27[1]) {
                              halt_baddata();
                            }
                            *(int *)((long)plVar27 + 0xc) = (int)plVar27[1];
                            halt_baddata();
                          }
                          uVar29 = 0xffffffff;
                          pcVar30 = "%s: Range error (index = %d, length = %d)";
                          goto LAB_183cfb974;
                        }
                        if (plVar27 == (long *)0x0) {
                          halt_baddata();
                        }
                        pcVar8 = *(code **)(*plVar27 + 8);
                        goto LAB_183cfa740;
                      }
                      uVar29 = (**(code **)(*param_1 + 0x28))(param_1);
                      pcVar30 = "Bad reference in JBIG2 generic refinement segment";
                      goto LAB_183cfb974;
                    }
                    uVar17 = (**(code **)(*(long *)param_1[10] + 0x20))();
                    if (uVar17 != 0xffffffff) {
                      local_2e0 = uVar17;
                      if ((uVar17 & 0x80) != 0) {
                        local_2e0 = uVar17 | 0xffffff00;
                      }
                      uVar17 = (**(code **)(*(long *)param_1[10] + 0x20))();
                      if (uVar17 != 0xffffffff) {
                        if ((uVar17 & 0x80) != 0) {
                          uVar17 = uVar17 | 0xffffff00;
                        }
                        local_a0 = CONCAT44(local_a0._4_4_,uVar17);
                        uVar17 = (**(code **)(*(long *)param_1[10] + 0x20))();
                        if (uVar17 != 0xffffffff) {
                          if ((uVar17 & 0x80) != 0) {
                            uVar17 = uVar17 | 0xffffff00;
                          }
                          local_2dc = CONCAT44(local_2dc._4_4_,uVar17);
                          uVar17 = (**(code **)(*(long *)param_1[10] + 0x20))();
                          if (uVar17 != 0xffffffff) {
                            if ((uVar17 & 0x80) != 0) {
                              uVar17 = uVar17 | 0xffffff00;
                            }
                            local_a0 = CONCAT44(uVar17,(int)local_a0);
                            goto LAB_183cf8a08;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            uVar29 = (**(code **)(*param_1 + 0x28))(param_1);
          }
        }
        else if (uVar17 < 0x34) {
          if (uVar17 != 0x30) {
            if (uVar17 == 0x32) {
              if (local_324 == 0) {
                halt_baddata();
              }
              do {
                iVar11 = iVar11 + -1;
                iVar14 = (**(code **)(*(long *)param_1[10] + 0x20))();
              } while (iVar14 != -1 && iVar11 != 0);
              halt_baddata();
            }
            goto LAB_183cf9198;
          }
          iVar11 = __ZN11JBIG2Stream9readULongEPj(param_1,param_1 + 4);
          if ((((iVar11 != 0) &&
               (iVar11 = __ZN11JBIG2Stream9readULongEPj(param_1,(long)param_1 + 0x24), iVar11 != 0))
              && (iVar11 = __ZN11JBIG2Stream9readULongEPj(param_1,&local_2e0), iVar11 != 0)) &&
             ((iVar11 = __ZN11JBIG2Stream9readULongEPj(param_1,&local_a0), iVar11 != 0 &&
              (uVar12 = (**(code **)(*(long *)param_1[10] + 0x20))(), uVar12 != 0xffffffff)))) {
            local_2e8 = 0;
            iVar11 = __ZN11JBIG2Stream9readUWordEPj(param_1,&local_2e8);
            if (iVar11 != 0) {
              *(uint *)(param_1 + 7) = uVar12 >> 3 & 3;
              uVar13 = local_2e8 & 0x7fff;
              if (*(uint *)((long)param_1 + 0x24) != 0xffffffff) {
                uVar13 = *(uint *)((long)param_1 + 0x24);
              }
              *(uint *)(param_1 + 5) = uVar13;
              *(uint *)((long)param_1 + 0x2c) = uVar12 >> 2 & 1;
              if ((long *)param_1[6] != (long *)0x0) {
                (**(code **)(*(long *)param_1[6] + 8))();
                param_1[6] = 0;
              }
              lVar35 = func_0x00018814d110(0x48,0x10d1c40b539ea8f);
              __ZN11JBIG2BitmapC2Ejii(lVar35,0,(int)param_1[4],(int)param_1[5]);
              param_1[6] = lVar35;
              if ((*(long *)(lVar35 + 0x40) != 0) && (*(long *)(lVar35 + 0x40) != 0)) {
                if (*(int *)((long)param_1 + 0x2c) != 0) {
                  __ZN11JBIG2Bitmap10clearToOneEv(lVar35);
                  halt_baddata();
                }
                __ZN11JBIG2Bitmap11clearToZeroEv(lVar35);
                halt_baddata();
              }
            }
          }
          uVar29 = (**(code **)(*param_1 + 0x28))(param_1);
        }
        else {
          if (uVar17 == 0x34) {
            if (local_324 == 0) {
              halt_baddata();
            }
            do {
              iVar11 = iVar11 + -1;
              iVar14 = (**(code **)(*(long *)param_1[10] + 0x20))();
            } while (iVar14 != -1 && iVar11 != 0);
            halt_baddata();
          }
          if (uVar17 != 0x35) {
            if (uVar17 == 0x3e) {
              if (local_324 == 0) {
                halt_baddata();
              }
              do {
                iVar11 = iVar11 + -1;
                iVar14 = (**(code **)(*(long *)param_1[10] + 0x20))();
              } while (iVar14 != -1 && iVar11 != 0);
              halt_baddata();
            }
LAB_183cf9198:
            uVar29 = (**(code **)(*param_1 + 0x28))(param_1);
            __Z5erroriPKcz(uVar29,"Unknown segment type in JBIG2 stream");
            iVar11 = local_324;
            while( true ) {
              if (iVar11 == 0) {
                halt_baddata();
              }
              iVar14 = (**(code **)(*(long *)param_1[10] + 0x20))();
              if (iVar14 == -1) break;
              iVar11 = iVar11 + -1;
            }
            halt_baddata();
          }
          uVar12 = (**(code **)(*(long *)param_1[10] + 0x20))();
          if (uVar12 != 0xffffffff) {
            local_2e0 = 0;
            iVar11 = __ZN11JBIG2Stream9readULongEPj(param_1,&local_2e0);
            if (iVar11 != 0) {
              local_a0 = local_a0 & 0xffffffff00000000;
              iVar11 = __ZN11JBIG2Stream9readULongEPj(param_1,&local_a0);
              if (iVar11 != 0) {
                *(undefined8 *)(param_1[0x1e] + 8) = 0;
                lVar35 = __Z13gmalloc_typediy(0x80,0x1000040451b5be8);
                local_330 = uVar12 >> 1 & 7;
                if ((int)local_2e0 < (int)local_a0) {
                  uVar38 = 0;
                  uVar15 = 0;
                  uVar36 = 8;
                  uVar17 = local_2e0;
                  do {
                    if (uVar15 == (uint)uVar36) {
                      if ((int)(uVar38 >> 0x16) != 0) goto LAB_183cf9248;
                      lVar35 = __Z15greallocn_typedPviiy(lVar35,uVar38,0x10,0x1000040451b5be8);
                      uVar36 = uVar38;
                    }
                    uVar16 = (uint)uVar36;
                    puVar1 = (uint *)(lVar35 + (ulong)uVar15 * 0x10);
                    *puVar1 = uVar17;
                    uVar18 = __ZN19JBIG2HuffmanDecoder8readBitsEj(param_1[0x1e],local_330 + 1);
                    puVar1[1] = uVar18;
                    uVar18 = __ZN19JBIG2HuffmanDecoder8readBitsEj
                                       (param_1[0x1e],(uVar12 >> 4 & 7) + 1);
                    puVar1[2] = uVar18;
                    uVar17 = (1 << (ulong)(uVar18 & 0x1f)) + uVar17;
                    uVar15 = uVar15 + 1;
                    uVar38 = (ulong)((int)uVar38 + 2);
                  } while ((int)uVar17 < (int)local_a0);
                }
                else {
                  uVar15 = 0;
                  uVar16 = 8;
                }
                uVar17 = (uVar12 & 1) + uVar15 + 3;
                if (uVar16 < uVar17) {
                  lVar35 = __Z15greallocn_typedPviiy(lVar35,uVar17,0x10,0x1000040451b5be8);
                }
                piVar23 = (int *)(lVar35 + (ulong)uVar15 * 0x10);
                *piVar23 = local_2e0 - 1;
                iVar11 = __ZN19JBIG2HuffmanDecoder8readBitsEj(param_1[0x1e],local_330 + 1);
                piVar23[1] = iVar11;
                piVar23[2] = -3;
                puVar2 = (undefined4 *)(lVar35 + (ulong)(uVar15 + 1) * 0x10);
                *puVar2 = (int)local_a0;
                uVar19 = __ZN19JBIG2HuffmanDecoder8readBitsEj(param_1[0x1e],local_330 + 1);
                puVar2[1] = uVar19;
                puVar2[2] = 0x20;
                uVar36 = (ulong)(uVar15 + 2);
                if ((uVar12 & 1) != 0) {
                  puVar2 = (undefined4 *)(lVar35 + uVar36 * 0x10);
                  *puVar2 = 0;
                  uVar19 = __ZN19JBIG2HuffmanDecoder8readBitsEj(param_1[0x1e],local_330 + 1);
                  puVar2[1] = uVar19;
                  puVar2[2] = 0xfffffffe;
                  uVar36 = (ulong)(uVar15 + 3);
                }
                puVar26 = (undefined8 *)(lVar35 + uVar36 * 0x10);
                *puVar26 = 0;
                *(undefined4 *)(puVar26 + 1) = 0xffffffff;
                __ZN19JBIG2HuffmanDecoder10buildTableEP17JBIG2HuffmanTablej(lVar35);
                lVar37 = param_1[8];
                puVar26 = (undefined8 *)func_0x00018814d110(0x18,0x10a1c406b6a53af);
                *(uint *)(puVar26 + 1) = uVar13;
                *puVar26 = &DAT_1e22343d0;
                puVar26[2] = lVar35;
                __ZN5GList6appendEPv(lVar37);
                halt_baddata();
              }
            }
          }
LAB_183cf9248:
          uVar29 = (**(code **)(*param_1 + 0x28))(param_1);
        }
LAB_183cfb96c:
        pcVar30 = "Unexpected EOF in JBIG2 stream";
LAB_183cfb974:
        __Z5erroriPKcz(uVar29,pcVar30);
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
    }
  }
LAB_183cfb9f4:
  uVar29 = (**(code **)(*param_1 + 0x28))(param_1);
  if (*_DAT_1e0186220 == local_88) {
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
      __Z5erroriPKcz(uVar29,"Unexpected EOF in JBIG2 stream");
      return;
    }
                    /* WARNING: Does not return */
    pcVar8 = (code *)SoftwareBreakpoint(0xc471,0x183cfba64);
    (*pcVar8)();
  }
LAB_183cfbde0:
  func_0x000188138130();
  return;
}



/* ==== __ZN11JBIG2Stream5closeEv @ 183cfc164 size=380 ==== */

void __ZN11JBIG2Stream5closeEv(long param_1)

{
  code *pcVar1;
  long *plVar2;
  int iVar3;
  long *plVar4;
  long lVar5;
  ulong unaff_x30;
  
  if (*(long **)(param_1 + 0x30) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x30) + 8))();
    *(undefined8 *)(param_1 + 0x30) = 0;
  }
  plVar4 = *(long **)(param_1 + 0x40);
  if (plVar4 == (long *)0x0) {
    plVar4 = *(long **)(param_1 + 0x48);
  }
  else {
    iVar3 = *(int *)((long)plVar4 + 0xc);
    if (0 < iVar3) {
      lVar5 = 0;
      do {
        plVar2 = *(long **)(*plVar4 + lVar5 * 8);
        if (plVar2 != (long *)0x0) {
          (**(code **)(*plVar2 + 8))();
          iVar3 = *(int *)((long)plVar4 + 0xc);
        }
        lVar5 = lVar5 + 1;
      } while (lVar5 < iVar3);
    }
    func_0x000188138390(*plVar4);
    func_0x00018814d0e0(plVar4,0x1080c40a085cba5);
    plVar4 = *(long **)(param_1 + 0x48);
    if (*(long **)(param_1 + 0x40) == plVar4) {
      plVar4 = (long *)0x0;
      *(undefined8 *)(param_1 + 0x48) = 0;
    }
    *(undefined8 *)(param_1 + 0x40) = 0;
  }
  if (plVar4 != (long *)0x0) {
    iVar3 = *(int *)((long)plVar4 + 0xc);
    if (0 < iVar3) {
      lVar5 = 0;
      do {
        plVar2 = *(long **)(*plVar4 + lVar5 * 8);
        if (plVar2 != (long *)0x0) {
          (**(code **)(*plVar2 + 8))();
          iVar3 = *(int *)((long)plVar4 + 0xc);
        }
        lVar5 = lVar5 + 1;
      } while (lVar5 < iVar3);
    }
    func_0x000188138390(*plVar4);
    func_0x00018814d0e0(plVar4,0x1080c40a085cba5);
    *(undefined8 *)(param_1 + 0x48) = 0;
  }
  *(undefined8 *)(param_1 + 0x58) = 0;
  *(undefined8 *)(param_1 + 0x60) = 0;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0x183cfc2d8);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0x000183cfc2dc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(long **)(param_1 + 0x10) + 0x18))();
  return;
}



/* ==== __ZN11JBIG2Stream7getCharEv @ 183cfc2e0 size=48 ==== */

uint __ZN11JBIG2Stream7getCharEv(long param_1)

{
  byte *pbVar1;
  
  pbVar1 = *(byte **)(param_1 + 0x58);
  if ((pbVar1 != (byte *)0x0) && (pbVar1 < *(byte **)(param_1 + 0x60))) {
    *(byte **)(param_1 + 0x58) = pbVar1 + 1;
    return *pbVar1 ^ 0xff;
  }
  return 0xffffffff;
}



/* ==== __ZN11JBIG2Stream8lookCharEv @ 183cfc310 size=40 ==== */

uint __ZN11JBIG2Stream8lookCharEv(long param_1)

{
  byte *pbVar1;
  
  pbVar1 = *(byte **)(param_1 + 0x58);
  if ((pbVar1 != (byte *)0x0) && (pbVar1 < *(byte **)(param_1 + 0x60))) {
    return *pbVar1 ^ 0xff;
  }
  return 0xffffffff;
}



/* ==== __ZN11JBIG2Stream8isBinaryEi @ 183cfc338 size=36 ==== */

void __ZN11JBIG2Stream8isBinaryEi(long param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000183cfc358. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(long **)(param_1 + 0x10) + 0x30))(*(long **)(param_1 + 0x10),1);
  return;
}



/* ==== __ZN11JBIG2Stream9readULongEPj @ 183cfc35c size=256 ==== */

undefined8 __ZN11JBIG2Stream9readULongEPj(long param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined8 uVar5;
  
  iVar1 = (**(code **)(**(long **)(param_1 + 0x50) + 0x20))();
  if ((((iVar1 == -1) || (iVar2 = (**(code **)(**(long **)(param_1 + 0x50) + 0x20))(), iVar2 == -1))
      || (iVar3 = (**(code **)(**(long **)(param_1 + 0x50) + 0x20))(), iVar3 == -1)) ||
     (uVar4 = (**(code **)(**(long **)(param_1 + 0x50) + 0x20))(), uVar4 == 0xffffffff)) {
    uVar5 = 0;
  }
  else {
    *param_2 = iVar2 << 0x10 | iVar1 << 0x18 | iVar3 << 8 | uVar4;
    uVar5 = 1;
  }
  return uVar5;
}



/* ==== __ZN11JBIG2Stream9readUWordEPj @ 183cfc45c size=148 ==== */

undefined8 __ZN11JBIG2Stream9readUWordEPj(long param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  undefined8 uVar3;
  
  iVar1 = (**(code **)(**(long **)(param_1 + 0x50) + 0x20))();
  if ((iVar1 == -1) ||
     (uVar2 = (**(code **)(**(long **)(param_1 + 0x50) + 0x20))(), uVar2 == 0xffffffff)) {
    uVar3 = 0;
  }
  else {
    *param_2 = uVar2 | iVar1 << 8;
    uVar3 = 1;
  }
  return uVar3;
}



/* ==== __ZN11JBIG2Stream11findSegmentEj @ 183cfc4f0 size=120 ==== */

long __ZN11JBIG2Stream11findSegmentEj(long param_1,int param_2)

{
  uint uVar1;
  long *plVar2;
  long lVar3;
  ulong uVar4;
  long lVar5;
  
  plVar2 = *(long **)(param_1 + 0x48);
  if (plVar2 != (long *)0x0) {
    uVar4 = (ulong)*(uint *)((long)plVar2 + 0xc);
    if (0 < (int)*(uint *)((long)plVar2 + 0xc)) {
      lVar5 = 0;
      do {
        lVar3 = *(long *)(*plVar2 + lVar5 * 8);
        if (*(int *)(lVar3 + 8) == param_2) {
          return lVar3;
        }
        lVar5 = lVar5 + 1;
        uVar4 = uVar4 - 1;
      } while (uVar4 != 0);
    }
    uVar1 = *(uint *)((long)*(long **)(param_1 + 0x40) + 0xc);
    uVar4 = (ulong)uVar1;
    if (0 < (int)uVar1) {
      lVar5 = 0;
      do {
        lVar3 = *(long *)(**(long **)(param_1 + 0x40) + lVar5 * 8);
        if (*(int *)(lVar3 + 8) == param_2) {
          return lVar3;
        }
        lVar5 = lVar5 + 1;
        uVar4 = uVar4 - 1;
      } while (uVar4 != 0);
    }
  }
  return 0;
}



/* ==== __ZN11JBIG2Stream17resetGenericStatsEjP23JArithmeticDecoderStats @ 183cfc568 size=340 ==== */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Possible PIC construction at 0x000183cfc678: Changing call to branch */
/* WARNING: Removing unreachable block (ram,0x000183cfc67c) */

void __ZN11JBIG2Stream17resetGenericStatsEjP23JArithmeticDecoderStats
               (long param_1,ulong param_2,long param_3)

{
  uint uVar1;
  int iVar2;
  code *pcVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  ulong unaff_x30;
  
  uVar1 = *(uint *)(contextSize + (param_2 & 0xffffffff) * 4);
  if ((param_3 == 0) || (*(uint *)(param_3 + 8) != uVar1)) {
    puVar5 = *(undefined8 **)(param_1 + 0x70);
    if (*(uint *)(puVar5 + 1) == uVar1) {
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0xc471,0x183cfc610);
        (*pcVar3)();
      }
    }
    else {
      func_0x000188138390(*puVar5);
      func_0x00018814d0e0(puVar5,0x1010c40a1d9428b);
      *(undefined8 *)(param_1 + 0x70) = 0;
      puVar5 = (undefined8 *)func_0x00018814d110(0x10,0x1010c40a1d9428b);
      iVar2 = 1 << (ulong)(uVar1 & 0x1f);
      *(int *)(puVar5 + 1) = iVar2;
      uVar4 = __Z14gmallocn_typediiy(iVar2,1,0x100004077774924);
      *puVar5 = uVar4;
    }
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  puVar5 = *(undefined8 **)(param_1 + 0x70);
  if (*(uint *)(puVar5 + 1) != uVar1) {
    func_0x000188138390(*puVar5);
    func_0x00018814d0e0(puVar5,0x1010c40a1d9428b);
    uVar4 = __ZN23JArithmeticDecoderStats4copyEv(param_3);
    *(undefined8 *)(param_1 + 0x70) = uVar4;
    return;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Does not return */
  pcVar3 = (code *)SoftwareBreakpoint(0xc471,0x183cfc5d8);
  (*pcVar3)();
}



/* ==== __ZN11JBIG2Stream13resetIntStatsEi @ 183cfc6d4 size=416 ==== */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Possible PIC construction at 0x000183cfc6fc: Changing call to branch */
/* WARNING: Possible PIC construction at 0x000183cfc71c: Changing call to branch */
/* WARNING: Possible PIC construction at 0x000183cfc73c: Changing call to branch */
/* WARNING: Possible PIC construction at 0x000183cfc75c: Changing call to branch */
/* WARNING: Possible PIC construction at 0x000183cfc77c: Changing call to branch */
/* WARNING: Possible PIC construction at 0x000183cfc79c: Changing call to branch */
/* WARNING: Possible PIC construction at 0x000183cfc7bc: Changing call to branch */
/* WARNING: Possible PIC construction at 0x000183cfc85c: Changing call to branch */
/* WARNING: Removing unreachable block (ram,0x000183cfc7c0) */
/* WARNING: Removing unreachable block (ram,0x000183cfc800) */
/* WARNING: Removing unreachable block (ram,0x000183cfc7e0) */
/* WARNING: Removing unreachable block (ram,0x000183cfc7fc) */
/* WARNING: Removing unreachable block (ram,0x000183cfc7f8) */
/* WARNING: Removing unreachable block (ram,0x000183cfc7a0) */
/* WARNING: Removing unreachable block (ram,0x000183cfc780) */
/* WARNING: Removing unreachable block (ram,0x000183cfc760) */
/* WARNING: Removing unreachable block (ram,0x000183cfc740) */
/* WARNING: Removing unreachable block (ram,0x000183cfc720) */
/* WARNING: Removing unreachable block (ram,0x000183cfc700) */
/* WARNING: Removing unreachable block (ram,0x000183cfc860) */

void __ZN11JBIG2Stream13resetIntStatsEi(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* ==== __ZN11JBIG2Stream20resetRefinementStatsEjP23JArithmeticDecoderStats @ 183cfc88c size=340 ==== */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Possible PIC construction at 0x000183cfc99c: Changing call to branch */
/* WARNING: Removing unreachable block (ram,0x000183cfc9a0) */

void __ZN11JBIG2Stream20resetRefinementStatsEjP23JArithmeticDecoderStats
               (long param_1,ulong param_2,long param_3)

{
  uint uVar1;
  int iVar2;
  code *pcVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  ulong unaff_x30;
  
  uVar1 = *(uint *)(refContextSize + (param_2 & 0xffffffff) * 4);
  if ((param_3 == 0) || (*(uint *)(param_3 + 8) != uVar1)) {
    puVar5 = *(undefined8 **)(param_1 + 0x78);
    if (*(uint *)(puVar5 + 1) == uVar1) {
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0xc471,0x183cfc934);
        (*pcVar3)();
      }
    }
    else {
      func_0x000188138390(*puVar5);
      func_0x00018814d0e0(puVar5,0x1010c40a1d9428b);
      *(undefined8 *)(param_1 + 0x78) = 0;
      puVar5 = (undefined8 *)func_0x00018814d110(0x10,0x1010c40a1d9428b);
      iVar2 = 1 << (ulong)(uVar1 & 0x1f);
      *(int *)(puVar5 + 1) = iVar2;
      uVar4 = __Z14gmallocn_typediiy(iVar2,1,0x100004077774924);
      *puVar5 = uVar4;
    }
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  puVar5 = *(undefined8 **)(param_1 + 0x78);
  if (*(uint *)(puVar5 + 1) != uVar1) {
    func_0x000188138390(*puVar5);
    func_0x00018814d0e0(puVar5,0x1010c40a1d9428b);
    uVar4 = __ZN23JArithmeticDecoderStats4copyEv(param_3);
    *(undefined8 *)(param_1 + 0x78) = uVar4;
    return;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Does not return */
  pcVar3 = (code *)SoftwareBreakpoint(0xc471,0x183cfc8fc);
  (*pcVar3)();
}



/* ==== __ZN11JBIG2Stream27readGenericRefinementRegionEiiiiP11JBIG2BitmapiiPiS2_ @ 183cfc9f8 size=11492 ==== */

/* WARNING: Removing unreachable block (ram,0x000183cfdee8) */
/* WARNING: Removing unreachable block (ram,0x000183cfdec0) */
/* WARNING: Removing unreachable block (ram,0x000183cfde98) */
/* WARNING: Removing unreachable block (ram,0x000183cfde04) */
/* WARNING: Removing unreachable block (ram,0x000183cfce6c) */
/* WARNING: Removing unreachable block (ram,0x000183cfd238) */
/* WARNING: Removing unreachable block (ram,0x000183cfcc48) */
/* WARNING: Removing unreachable block (ram,0x000183cff018) */
/* WARNING: Removing unreachable block (ram,0x000183cfeff0) */
/* WARNING: Removing unreachable block (ram,0x000183cfefc8) */
/* WARNING: Removing unreachable block (ram,0x000183cfef64) */
/* WARNING: Removing unreachable block (ram,0x000183cfe518) */
/* WARNING: Removing unreachable block (ram,0x000183cfef3c) */
/* WARNING: Removing unreachable block (ram,0x000183cfd128) */
/* WARNING: Removing unreachable block (ram,0x000183cfd344) */
/* WARNING: Removing unreachable block (ram,0x000183cfcf34) */
/* WARNING: Removing unreachable block (ram,0x000183cfcfa0) */
/* WARNING: Removing unreachable block (ram,0x000183cfd060) */
/* WARNING: Removing unreachable block (ram,0x000183cfd36c) */
/* WARNING: Removing unreachable block (ram,0x000183cfe3d0) */
/* WARNING: Removing unreachable block (ram,0x000183cfe4ac) */
/* WARNING: Removing unreachable block (ram,0x000183cfe5d0) */
/* WARNING: Removing unreachable block (ram,0x000183cfe6b0) */
/* WARNING: Removing unreachable block (ram,0x000183cfe748) */
/* WARNING: Removing unreachable block (ram,0x000183cfe7e0) */
/* WARNING: Removing unreachable block (ram,0x000183cfcd00) */
/* WARNING: Removing unreachable block (ram,0x000183cfcdc8) */
/* WARNING: Removing unreachable block (ram,0x000183cfd288) */
/* WARNING: Removing unreachable block (ram,0x000183cfd618) */
/* WARNING: Removing unreachable block (ram,0x000183cfd6fc) */
/* WARNING: Removing unreachable block (ram,0x000183cfd78c) */
/* WARNING: Removing unreachable block (ram,0x000183cfd81c) */
/* WARNING: Removing unreachable block (ram,0x000183cfcaa4) */

long __ZN11JBIG2Stream27readGenericRefinementRegionEiiiiP11JBIG2BitmapiiPiS2_
               (long param_1,int param_2,undefined8 param_3,int param_4,int param_5,long param_6,
               uint param_7,int param_8,uint *param_9,int *param_10)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  bool bVar14;
  bool bVar15;
  bool bVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  uint uVar22;
  byte bVar23;
  undefined4 uVar24;
  uint uVar25;
  int iVar26;
  ulong uVar27;
  ulong uVar28;
  ulong uVar29;
  byte bVar30;
  uint uVar31;
  uint uVar32;
  ulong uVar33;
  ulong uVar34;
  ulong uVar35;
  long lVar36;
  ulong uVar37;
  byte bVar38;
  int iVar39;
  uint uVar40;
  long lVar41;
  long lVar42;
  long lVar43;
  uint uVar44;
  uint uVar45;
  int iVar46;
  long *plVar47;
  byte bVar48;
  uint uVar49;
  uint uVar50;
  byte *pbVar51;
  byte bVar52;
  byte bVar53;
  byte *pbVar54;
  uint local_154;
  uint local_150;
  uint local_14c;
  uint local_148;
  uint local_144;
  uint local_140;
  uint local_13c;
  uint local_138;
  uint local_134;
  uint local_130;
  uint local_12c;
  uint local_128;
  uint local_124;
  ulong local_120;
  byte *local_118;
  byte *local_110;
  byte *local_108;
  byte *local_100;
  byte *local_f0;
  byte *local_e8;
  byte *local_e0;
  byte *local_d0;
  byte *local_c8;
  byte *local_c0;
  byte *local_b8;
  byte *local_90;
  long local_88;
  uint local_7c;
  uint uStack_78;
  uint local_74;
  
  local_88 = 0;
  if ((param_2 < 0x10000) && (iVar19 = (int)param_3, iVar19 < 0x10000)) {
    local_88 = func_0x00018814d110(0x48,0x10d1c40b539ea8f);
    __ZN11JBIG2BitmapC2Ejii(local_88,0,param_2,param_3);
    plVar47 = (long *)(local_88 + 0x40);
    if ((*plVar47 == 0) || (*plVar47 == 0)) {
      local_88 = 0;
    }
    else {
      __ZN11JBIG2Bitmap11clearToZeroEv(local_88);
      uVar24 = 0x10;
      if (param_4 != 0) {
        uVar24 = 8;
      }
      if (0 < iVar19) {
        iVar20 = 0;
        uVar5 = param_7 & 7;
        bVar14 = (param_7 & 7) == 0;
        uVar1 = local_88 + 0x30;
        uVar33 = (ulong)bVar14;
        uVar7 = 7;
        if (!bVar14) {
          uVar7 = (param_7 & 7) - 1;
        }
        uVar10 = -param_7;
        uVar2 = param_6 + 0x20;
        uVar3 = param_6 + 0x30;
        uVar34 = (ulong)(uVar10 >> 3);
        uVar4 = uVar10 & 7;
        uVar8 = uVar4 ^ 7;
        uVar9 = ~param_7;
        uVar35 = (ulong)(uVar9 >> 3);
        uVar12 = 1 - param_7;
        uVar13 = 2 - param_7;
        bVar14 = uVar4 == 7;
        if (!bVar14) {
          uVar4 = 6 - uVar4;
        }
        do {
          iVar21 = *(int *)(local_88 + 0x20);
          lVar36 = *(long *)(local_88 + 0x28);
          lVar41 = pacga((long)iVar21,local_88 + 0x20U & 0xffffffffffff | 0x5363000000000000);
          uVar27 = local_88 + 0x10U & 0xffffffffffff | 0x5363000000000000;
          uVar28 = param_6 + 0x10U & 0xffffffffffff | 0x5363000000000000;
          iVar18 = (int)((long)iVar20 + -1);
          local_134 = uVar5;
          local_130 = uVar5;
          if (param_4 == 0) {
            if (iVar20 == 0) {
LAB_183cfcf40:
              local_b8 = (byte *)0x0;
              local_138 = 0;
              iVar46 = 0;
              local_74 = 0;
            }
            else {
              if (lVar41 != lVar36) goto LAB_183cff6d8;
              if (iVar21 < iVar20) goto LAB_183cfcf40;
              lVar42 = pacga((long)*(int *)(local_88 + 0x10),uVar27);
              if (lVar42 != *(long *)(local_88 + 0x18)) goto LAB_183cff6d8;
              if (*(int *)(local_88 + 0x10) < 1) goto LAB_183cfcf40;
              lVar42 = *plVar47;
              if (lVar42 == 0) {
                lVar42 = 0;
              }
              lVar43 = pacga((long)*(int *)(local_88 + 0x30),
                             uVar1 & 0xffffffffffff | 0x5363000000000000);
              if (lVar43 != *(long *)(local_88 + 0x38)) goto LAB_183cff6d8;
              pbVar54 = (byte *)(lVar42 + (long)*(int *)(local_88 + 0x30) * (long)iVar18);
              if (lVar42 == 0) {
                local_b8 = (byte *)0x0;
                iVar46 = 0;
                local_74 = 0;
                local_138 = 7;
              }
              else {
                iVar46 = *(int *)(local_88 + 0x10);
                lVar42 = pacga((long)iVar46,uVar27);
                if (lVar42 != *(long *)(local_88 + 0x18)) goto LAB_183cff6d8;
                local_74 = (uint)(*pbVar54 >> 7);
                local_b8 = (byte *)0x0;
                if (iVar46 != 1) {
                  local_b8 = pbVar54;
                }
                local_138 = 6;
                if (iVar46 == 1) {
                  local_138 = 7;
                }
                iVar46 = 1;
              }
            }
            if (lVar41 != lVar36) goto LAB_183cff6d8;
            if (iVar20 < iVar21) {
              lVar36 = pacga((long)*(int *)(local_88 + 0x10),uVar27);
              if (lVar36 != *(long *)(local_88 + 0x18)) goto LAB_183cff6d8;
              if (*(int *)(local_88 + 0x10) < 0) goto LAB_183cfcfdc;
              lVar36 = pacga((long)*(int *)(local_88 + 0x30),
                             uVar1 & 0xffffffffffff | 0x5363000000000000);
              if (lVar36 != *(long *)(local_88 + 0x38)) goto LAB_183cff6d8;
              local_108 = (byte *)(*plVar47 + (long)*(int *)(local_88 + 0x30) * (long)iVar20);
              local_124 = -1;
              local_140 = 7;
            }
            else {
LAB_183cfcfdc:
              local_108 = (byte *)0x0;
              local_140 = 0;
              local_124 = 0;
            }
            iVar18 = iVar18 - param_8;
            if (iVar18 < 0) {
LAB_183cfd0a4:
              local_c0 = (byte *)0x0;
              uStack_78 = 0;
              uVar25 = 0;
              local_13c = 0;
            }
            else {
              lVar36 = pacga((long)*(int *)(param_6 + 0x20),
                             uVar2 & 0xffffffffffff | 0x5363000000000000);
              if (lVar36 != *(long *)(param_6 + 0x28)) goto LAB_183cff6d8;
              if (*(int *)(param_6 + 0x20) <= iVar18) goto LAB_183cfd0a4;
              lVar36 = pacga((long)*(int *)(param_6 + 0x10),uVar28);
              if (lVar36 != *(long *)(param_6 + 0x18)) goto LAB_183cff6d8;
              if (*(int *)(param_6 + 0x10) <= (int)uVar10) goto LAB_183cfd0a4;
              lVar36 = *(long *)(param_6 + 0x40);
              uVar25 = uVar12;
              if ((int)param_7 < 1) {
                if (lVar36 == 0) {
                  lVar36 = 0;
                }
                lVar41 = pacga((long)*(int *)(param_6 + 0x30),
                               uVar3 & 0xffffffffffff | 0x5363000000000000);
                if (lVar41 != *(long *)(param_6 + 0x38)) goto LAB_183cff6d8;
                pbVar54 = (byte *)(lVar36 + uVar34 + (long)*(int *)(param_6 + 0x30) * (long)iVar18);
                local_13c = uVar8;
                if (lVar36 == 0) goto LAB_183cfd500;
                lVar36 = pacga((long)(int)*(uint *)(param_6 + 0x10),uVar28);
                if (lVar36 != *(long *)(param_6 + 0x18)) goto LAB_183cff6d8;
                uStack_78 = *pbVar54 >> (ulong)uVar8 & 1;
                local_c0 = (byte *)0x0;
                if (uVar12 != *(uint *)(param_6 + 0x10)) {
                  local_13c = uVar4;
                  local_c0 = pbVar54 + bVar14;
                }
              }
              else {
                lVar41 = pacga((long)*(int *)(param_6 + 0x30),
                               uVar3 & 0xffffffffffff | 0x5363000000000000);
                if (lVar41 != *(long *)(param_6 + 0x38)) goto LAB_183cff6d8;
                if (lVar36 == 0) {
                  local_13c = 7;
LAB_183cfd500:
                  uStack_78 = 0;
                  local_c0 = (byte *)0x0;
                  uVar25 = uVar10;
                }
                else {
                  uStack_78 = 0;
                  local_13c = 7;
                  local_c0 = (byte *)(lVar36 + (long)*(int *)(param_6 + 0x30) * (long)iVar18);
                }
              }
            }
            iVar17 = iVar20 - param_8;
            if (iVar17 < 0) {
LAB_183cfd168:
              if (-1 < iVar17 + 1) {
                iVar26 = *(int *)(param_6 + 0x20);
                lVar36 = pacga((long)iVar26,uVar2 & 0xffffffffffff | 0x5363000000000000);
                if (lVar36 != *(long *)(param_6 + 0x28)) goto LAB_183cff6d8;
                pbVar54 = (byte *)0x0;
                local_130 = 0;
                uVar22 = 0;
                local_7c = 0;
                goto LAB_183cfe380;
              }
              local_7c = 0;
              uVar22 = 0;
              local_130 = 0;
              pbVar54 = (byte *)0x0;
              local_134 = 0;
              uVar49 = 0;
              uVar45 = 0;
              bVar16 = true;
LAB_183cfe428:
              local_90 = (byte *)0x0;
              uVar50 = 0;
              uVar45 = uVar45 << 1;
            }
            else {
              iVar26 = *(int *)(param_6 + 0x20);
              lVar36 = pacga((long)iVar26,uVar2 & 0xffffffffffff | 0x5363000000000000);
              if (lVar36 != *(long *)(param_6 + 0x28)) goto LAB_183cff6d8;
              if (iVar26 <= iVar17) goto LAB_183cfd168;
              uVar49 = *(uint *)(param_6 + 0x10);
              lVar36 = pacga((long)(int)uVar49,uVar28);
              if (lVar36 != *(long *)(param_6 + 0x18)) goto LAB_183cff6d8;
              if ((int)uVar9 < (int)uVar49) {
                lVar36 = *(long *)(param_6 + 0x40);
                if (-1 < (int)param_7) {
                  lVar41 = pacga((long)*(int *)(param_6 + 0x30),
                                 uVar3 & 0xffffffffffff | 0x5363000000000000);
                  if (lVar41 != *(long *)(param_6 + 0x38)) goto LAB_183cff6d8;
                  if (lVar36 == 0) {
                    local_130 = 7;
                    goto LAB_183cfd590;
                  }
                  pbVar54 = (byte *)(lVar36 + (long)*(int *)(param_6 + 0x30) * (long)iVar17);
                  uVar22 = 0;
                  if (param_7 == 0) {
                    local_7c = (uint)(*pbVar54 >> 7);
                    uVar45 = 7;
                    if (uVar49 == 1) {
                      pbVar54 = (byte *)0x0;
                      local_130 = 7;
                    }
                    else {
LAB_183cfe36c:
                      local_130 = uVar45 - 1;
                    }
                  }
                  else {
                    local_7c = 0;
LAB_183cfd160:
                    local_130 = 7;
                  }
LAB_183cfe370:
                  local_7c = local_7c | uVar22;
                  uVar22 = uVar12;
                  goto LAB_183cfe380;
                }
                if (lVar36 == 0) {
                  lVar36 = 0;
                }
                lVar41 = pacga((long)*(int *)(param_6 + 0x30),
                               uVar3 & 0xffffffffffff | 0x5363000000000000);
                if (lVar41 != *(long *)(param_6 + 0x38)) goto LAB_183cff6d8;
                pbVar54 = (byte *)(lVar36 + uVar35 + (long)*(int *)(param_6 + 0x30) * (long)iVar17);
                if (lVar36 == 0) {
LAB_183cfd590:
                  local_7c = 0;
                  uVar22 = uVar9;
                }
                else {
                  local_7c = *pbVar54 >> (ulong)uVar5 & 1;
                  uVar22 = uVar10;
                  if (uVar49 != uVar10) {
                    pbVar54 = pbVar54 + uVar33;
                    uVar22 = local_7c << 1;
                    local_7c = *pbVar54 >> (ulong)(uVar7 & 0x1f) & 1;
                    if (uVar12 != uVar49) {
                      uVar45 = uVar7;
                      if (uVar7 != 0) goto LAB_183cfe36c;
                      pbVar54 = pbVar54 + 1;
                      goto LAB_183cfd160;
                    }
                    pbVar54 = (byte *)0x0;
                    local_130 = uVar7;
                    goto LAB_183cfe370;
                  }
                }
              }
              else {
                local_130 = 0;
                uVar22 = 0;
                local_7c = 0;
              }
              pbVar54 = (byte *)0x0;
              local_7c = local_7c << 1;
LAB_183cfe380:
              iVar39 = iVar17 + 1;
              if (iVar26 <= iVar39) {
LAB_183cfe418:
                bVar16 = false;
                local_134 = 0;
                uVar49 = 0;
                uVar45 = 0;
                goto LAB_183cfe428;
              }
              lVar36 = pacga((long)*(int *)(param_6 + 0x10),uVar28);
              if (lVar36 != *(long *)(param_6 + 0x18)) goto LAB_183cff6d8;
              if (*(int *)(param_6 + 0x10) <= (int)uVar9) goto LAB_183cfe418;
              lVar36 = *(long *)(param_6 + 0x40);
              uVar49 = uVar12;
              if ((int)param_7 < 0) {
                if (lVar36 == 0) {
                  lVar36 = 0;
                }
                lVar41 = pacga((long)*(int *)(param_6 + 0x30),
                               uVar3 & 0xffffffffffff | 0x5363000000000000);
                if (lVar41 != *(long *)(param_6 + 0x38)) goto LAB_183cff6d8;
                local_90 = (byte *)(lVar36 + uVar35 + (long)*(int *)(param_6 + 0x30) * (long)iVar39)
                ;
                if (lVar36 == 0) goto LAB_183cff0a4;
                lVar36 = pacga((long)(int)*(uint *)(param_6 + 0x10),uVar28);
                if (lVar36 != *(long *)(param_6 + 0x18)) goto LAB_183cff6d8;
                uVar45 = *local_90 >> (ulong)uVar5 & 1;
                if (*(uint *)(param_6 + 0x10) == uVar10) {
                  bVar16 = false;
                  uVar49 = uVar10;
                  goto LAB_183cfe428;
                }
                local_90 = local_90 + uVar33;
                uVar45 = uVar45 << 1;
                local_134 = uVar7;
LAB_183cff178:
                lVar36 = pacga((long)(int)*(uint *)(param_6 + 0x10),uVar28);
                if (lVar36 != *(long *)(param_6 + 0x18)) goto LAB_183cff6d8;
                uVar50 = *local_90 >> (ulong)(local_134 & 0x1f) & 1;
                if (uVar12 != *(uint *)(param_6 + 0x10)) {
                  if (local_134 == 0) {
                    local_90 = local_90 + 1;
                    local_134 = 7;
                  }
                  else {
                    local_134 = local_134 - 1;
                  }
                  goto LAB_183cff53c;
                }
                bVar16 = false;
                local_90 = (byte *)0x0;
              }
              else {
                lVar41 = pacga((long)*(int *)(param_6 + 0x30),
                               uVar3 & 0xffffffffffff | 0x5363000000000000);
                if (lVar41 != *(long *)(param_6 + 0x38)) goto LAB_183cff6d8;
                if (lVar36 == 0) {
                  local_134 = 7;
LAB_183cff0a4:
                  bVar16 = false;
                  uVar45 = 0;
                  uVar49 = uVar9;
                  goto LAB_183cfe428;
                }
                local_90 = (byte *)(lVar36 + (long)*(int *)(param_6 + 0x30) * (long)iVar39);
                local_134 = 7;
                if (param_7 == 0) {
                  uVar45 = 0;
                  goto LAB_183cff178;
                }
                uVar45 = 0;
                uVar50 = 0;
LAB_183cff53c:
                bVar16 = false;
              }
            }
            iVar39 = iVar17 + 1;
            local_144 = 0;
            local_100 = (byte *)0x0;
            local_128 = 0;
            iVar26 = (int)((long)*param_10 + (long)iVar20);
            if ((-1 < iVar26) && (iVar26 < iVar21)) {
              lVar36 = pacga((long)*(int *)(local_88 + 0x10),uVar27);
              if (lVar36 != *(long *)(local_88 + 0x18)) goto LAB_183cff6d8;
              local_128 = *param_9;
              if ((int)local_128 < *(int *)(local_88 + 0x10)) {
                if ((int)local_128 < 0) {
                  lVar36 = pacga((long)*(int *)(local_88 + 0x30),
                                 uVar1 & 0xffffffffffff | 0x5363000000000000);
                  if (lVar36 != *(long *)(local_88 + 0x38)) goto LAB_183cff6d8;
                  local_100 = (byte *)(*plVar47 +
                                      (long)*(int *)(local_88 + 0x30) *
                                      ((long)*param_10 + (long)iVar20));
                  local_144 = 7;
                }
                else {
                  lVar36 = pacga((long)*(int *)(local_88 + 0x30),
                                 uVar1 & 0xffffffffffff | 0x5363000000000000);
                  if (lVar36 != *(long *)(local_88 + 0x38)) goto LAB_183cff6d8;
                  local_100 = (byte *)(*plVar47 +
                                      (long)(int)(*(int *)(local_88 + 0x30) * iVar26 +
                                                 (local_128 >> 3)));
                  local_144 = (local_128 ^ 0xffffffff) & 7;
                }
              }
              else {
                local_100 = (byte *)0x0;
                local_144 = 0;
                local_128 = 0;
              }
            }
            iVar21 = iVar17 + param_10[1];
            if (iVar21 < 0) {
LAB_183cfe60c:
              local_110 = (byte *)0x0;
              local_154 = 0;
              local_12c = 0;
            }
            else {
              lVar36 = pacga((long)*(int *)(param_6 + 0x20),
                             uVar2 & 0xffffffffffff | 0x5363000000000000);
              if (lVar36 != *(long *)(param_6 + 0x28)) goto LAB_183cff6d8;
              if (*(int *)(param_6 + 0x20) <= iVar21) goto LAB_183cfe60c;
              lVar36 = pacga((long)*(int *)(param_6 + 0x10),uVar28);
              if (lVar36 != *(long *)(param_6 + 0x18)) goto LAB_183cff6d8;
              local_12c = param_9[1] - param_7;
              if (*(int *)(param_6 + 0x10) <= (int)local_12c) goto LAB_183cfe60c;
              if ((int)local_12c < 0) {
                lVar36 = pacga((long)*(int *)(param_6 + 0x30),
                               uVar3 & 0xffffffffffff | 0x5363000000000000);
                if (lVar36 != *(long *)(param_6 + 0x38)) goto LAB_183cff6d8;
                lVar36 = (long)*(int *)(param_6 + 0x30) * (long)iVar21;
                local_154 = 7;
              }
              else {
                lVar36 = pacga((long)*(int *)(param_6 + 0x30),
                               uVar3 & 0xffffffffffff | 0x5363000000000000);
                if (lVar36 != *(long *)(param_6 + 0x38)) goto LAB_183cff6d8;
                lVar36 = (long)(int)(*(int *)(param_6 + 0x30) * iVar21 + (local_12c >> 3));
                local_154 = (local_12c ^ 0xffffffff) & 7;
              }
              local_110 = (byte *)(*(long *)(param_6 + 0x40) + lVar36);
            }
            if (param_5 == 0) {
              local_e8 = (byte *)0x0;
              local_148 = 0;
              local_d0 = (byte *)0x0;
              local_f0 = (byte *)0x0;
              local_14c = 0;
              local_e0 = (byte *)0x0;
              local_120 = 0;
              local_118 = (byte *)0x0;
              local_150 = 0;
              bVar52 = 0;
              bVar48 = 0;
              bVar53 = 0;
            }
            else {
              if (iVar18 < 0) {
LAB_183cfe6bc:
                local_148 = 0;
                local_d0 = (byte *)0x0;
                bVar23 = 0;
LAB_183cfe6c8:
                local_e8 = (byte *)0x0;
                bVar52 = 0;
                bVar23 = bVar23 << 1;
              }
              else {
                lVar36 = pacga((long)*(int *)(param_6 + 0x20),
                               uVar2 & 0xffffffffffff | 0x5363000000000000);
                if (lVar36 != *(long *)(param_6 + 0x28)) goto LAB_183cff6d8;
                if (*(int *)(param_6 + 0x20) <= iVar18) goto LAB_183cfe6bc;
                uVar44 = *(uint *)(param_6 + 0x10);
                uVar37 = (ulong)(int)uVar44;
                lVar36 = pacga(uVar37,uVar28);
                if (lVar36 != *(long *)(param_6 + 0x18)) goto LAB_183cff6d8;
                if ((int)uVar44 <= (int)uVar9) goto LAB_183cfe6bc;
                lVar36 = *(long *)(param_6 + 0x40);
                uVar32 = uVar9;
                if ((int)param_7 < 0) {
                  if (lVar36 == 0) {
                    lVar36 = 0;
                  }
                  lVar41 = pacga((long)*(int *)(param_6 + 0x30),
                                 uVar3 & 0xffffffffffff | 0x5363000000000000);
                  if (lVar41 != *(long *)(param_6 + 0x38)) goto LAB_183cff6d8;
                  local_148 = uVar5;
                  if ((lVar36 == 0) || (uVar32 = uVar10, uVar44 == uVar10)) goto LAB_183cff2b8;
                  local_e8 = (byte *)(lVar36 + uVar35 + (long)*(int *)(param_6 + 0x30) *
                                                        (long)iVar18 + uVar33);
                  local_148 = uVar7;
LAB_183cff39c:
                  bVar23 = *local_e8 >> (ulong)(local_148 & 0x1f) & 1;
                  local_d0 = (byte *)uVar37;
                  if (uVar32 + 1 != uVar44) {
                    uVar40 = local_148 - 1;
                    bVar15 = local_148 == 0;
                    if (bVar15) {
                      local_e8 = local_e8 + 1;
                    }
                    local_148 = 7;
                    if (!bVar15) {
                      local_148 = uVar40;
                    }
                    bVar23 = bVar23 << 1;
                    local_d0 = (byte *)(ulong)(uVar32 + 2);
                    bVar52 = *local_e8 >> (ulong)(local_148 & 0x1f) & 1;
                    if (uVar32 + 2 == uVar44) {
                      local_e8 = (byte *)0x0;
                      local_d0 = (byte *)uVar37;
                    }
                    else {
                      if (local_148 != 0) goto LAB_183cff5e4;
                      local_e8 = local_e8 + 1;
                      local_148 = 7;
                    }
                    goto LAB_183cfe6d4;
                  }
                  goto LAB_183cfe6c8;
                }
                if (lVar36 == 0) {
                  lVar36 = 0;
                }
                lVar41 = pacga((long)*(int *)(param_6 + 0x30),
                               uVar3 & 0xffffffffffff | 0x5363000000000000);
                if (lVar41 != *(long *)(param_6 + 0x38)) goto LAB_183cff6d8;
                local_e8 = (byte *)(lVar36 + (long)*(int *)(param_6 + 0x30) * (long)iVar18);
                if (lVar36 == 0) {
                  local_148 = 7;
LAB_183cff2b8:
                  bVar23 = 0;
                  local_d0 = (byte *)(ulong)uVar32;
                  goto LAB_183cfe6c8;
                }
                if (param_7 == 0) {
                  local_148 = 7;
                  uVar32 = 0;
                  goto LAB_183cff39c;
                }
                if ((int)param_7 < 2) {
                  bVar23 = 0;
                  bVar52 = *local_e8 >> 7;
                  local_d0 = (byte *)0x1;
                  local_148 = 7;
                  if (uVar44 == 1) {
                    local_e8 = (byte *)0x0;
                    local_d0 = (byte *)0x1;
                  }
                  else {
LAB_183cff5e4:
                    local_148 = local_148 - 1;
                  }
                }
                else {
                  bVar23 = 0;
                  bVar52 = 0;
                  local_148 = 7;
                  local_d0 = (byte *)(ulong)uVar13;
                }
              }
LAB_183cfe6d4:
              if (iVar17 < 0) {
LAB_183cfe754:
                local_14c = 0;
                local_e0 = (byte *)0x0;
                bVar30 = 0;
LAB_183cfe760:
                local_f0 = (byte *)0x0;
                bVar48 = 0;
                bVar30 = bVar30 << 1;
              }
              else {
                lVar36 = pacga((long)*(int *)(param_6 + 0x20),
                               uVar2 & 0xffffffffffff | 0x5363000000000000);
                if (lVar36 != *(long *)(param_6 + 0x28)) goto LAB_183cff6d8;
                if (*(int *)(param_6 + 0x20) <= iVar17) goto LAB_183cfe754;
                uVar44 = *(uint *)(param_6 + 0x10);
                uVar37 = (ulong)(int)uVar44;
                lVar36 = pacga(uVar37,uVar28);
                if (lVar36 != *(long *)(param_6 + 0x18)) goto LAB_183cff6d8;
                if ((int)uVar44 <= (int)uVar9) goto LAB_183cfe754;
                lVar36 = *(long *)(param_6 + 0x40);
                uVar32 = uVar9;
                if ((int)param_7 < 0) {
                  if (lVar36 == 0) {
                    lVar36 = 0;
                  }
                  lVar41 = pacga((long)*(int *)(param_6 + 0x30),
                                 uVar3 & 0xffffffffffff | 0x5363000000000000);
                  if (lVar41 != *(long *)(param_6 + 0x38)) goto LAB_183cff6d8;
                  local_14c = uVar5;
                  if ((lVar36 == 0) || (uVar32 = uVar10, uVar44 == uVar10)) goto LAB_183cff320;
                  local_f0 = (byte *)(lVar36 + uVar35 + (long)*(int *)(param_6 + 0x30) *
                                                        (long)iVar17 + uVar33);
                  local_14c = uVar7;
LAB_183cff410:
                  bVar30 = *local_f0 >> (ulong)(local_14c & 0x1f) & 1;
                  local_e0 = (byte *)uVar37;
                  if (uVar32 + 1 != uVar44) {
                    uVar40 = local_14c - 1;
                    bVar15 = local_14c == 0;
                    if (bVar15) {
                      local_f0 = local_f0 + 1;
                    }
                    local_14c = 7;
                    if (!bVar15) {
                      local_14c = uVar40;
                    }
                    bVar30 = bVar30 << 1;
                    local_e0 = (byte *)(ulong)(uVar32 + 2);
                    bVar48 = *local_f0 >> (ulong)(local_14c & 0x1f) & 1;
                    if (uVar32 + 2 == uVar44) {
                      local_f0 = (byte *)0x0;
                      local_e0 = (byte *)uVar37;
                    }
                    else {
                      if (local_14c != 0) goto LAB_183cff5fc;
                      local_f0 = local_f0 + 1;
                      local_14c = 7;
                    }
                    goto LAB_183cfe76c;
                  }
                  goto LAB_183cfe760;
                }
                if (lVar36 == 0) {
                  lVar36 = 0;
                }
                lVar41 = pacga((long)*(int *)(param_6 + 0x30),
                               uVar3 & 0xffffffffffff | 0x5363000000000000);
                if (lVar41 != *(long *)(param_6 + 0x38)) goto LAB_183cff6d8;
                local_f0 = (byte *)(lVar36 + (long)*(int *)(param_6 + 0x30) * (long)iVar17);
                if (lVar36 == 0) {
                  local_14c = 7;
LAB_183cff320:
                  bVar30 = 0;
                  local_e0 = (byte *)(ulong)uVar32;
                  goto LAB_183cfe760;
                }
                if (param_7 == 0) {
                  local_14c = 7;
                  uVar32 = 0;
                  goto LAB_183cff410;
                }
                if ((int)param_7 < 2) {
                  bVar30 = 0;
                  bVar48 = *local_f0 >> 7;
                  local_e0 = (byte *)0x1;
                  local_14c = 7;
                  if (uVar44 == 1) {
                    local_f0 = (byte *)0x0;
                    local_e0 = (byte *)0x1;
                  }
                  else {
LAB_183cff5fc:
                    local_14c = local_14c - 1;
                  }
                }
                else {
                  bVar30 = 0;
                  bVar48 = 0;
                  local_14c = 7;
                  local_e0 = (byte *)(ulong)uVar13;
                }
              }
LAB_183cfe76c:
              if (bVar16) {
LAB_183cfe7ec:
                local_150 = 0;
                local_120 = 0;
                bVar38 = 0;
LAB_183cfe800:
                local_118 = (byte *)0x0;
                bVar53 = 0;
                bVar38 = bVar38 << 1;
              }
              else {
                lVar36 = pacga((long)*(int *)(param_6 + 0x20),
                               uVar2 & 0xffffffffffff | 0x5363000000000000);
                if (lVar36 != *(long *)(param_6 + 0x28)) goto LAB_183cff6d8;
                if (*(int *)(param_6 + 0x20) <= iVar39) goto LAB_183cfe7ec;
                uVar44 = *(uint *)(param_6 + 0x10);
                uVar37 = (ulong)(int)uVar44;
                lVar36 = pacga(uVar37,uVar28);
                if (lVar36 != *(long *)(param_6 + 0x18)) goto LAB_183cff6d8;
                if ((int)uVar44 <= (int)uVar9) goto LAB_183cfe7ec;
                lVar36 = *(long *)(param_6 + 0x40);
                uVar32 = uVar9;
                if ((int)param_7 < 0) {
                  if (lVar36 == 0) {
                    lVar36 = 0;
                  }
                  lVar41 = pacga((long)*(int *)(param_6 + 0x30),
                                 uVar3 & 0xffffffffffff | 0x5363000000000000);
                  if (lVar41 != *(long *)(param_6 + 0x38)) goto LAB_183cff6d8;
                  local_150 = uVar5;
                  if ((lVar36 == 0) || (uVar32 = uVar10, uVar44 == uVar10)) goto LAB_183cff4f0;
                  local_118 = (byte *)(lVar36 + uVar35 + (long)*(int *)(param_6 + 0x30) *
                                                         (long)iVar39 + uVar33);
                  local_150 = uVar7;
LAB_183cff554:
                  bVar38 = *local_118 >> (ulong)(local_150 & 0x1f) & 1;
                  local_120 = uVar37;
                  if (uVar32 + 1 != uVar44) {
                    uVar40 = local_150 - 1;
                    bVar16 = local_150 == 0;
                    if (bVar16) {
                      local_118 = local_118 + 1;
                    }
                    local_150 = 7;
                    if (!bVar16) {
                      local_150 = uVar40;
                    }
                    bVar38 = bVar38 << 1;
                    local_120 = (ulong)(uVar32 + 2);
                    bVar53 = *local_118 >> (ulong)(local_150 & 0x1f) & 1;
                    if (uVar32 + 2 == uVar44) {
                      local_118 = (byte *)0x0;
                      local_120 = uVar37;
                    }
                    else {
                      if (local_150 != 0) goto LAB_183cff61c;
                      local_118 = local_118 + 1;
                      local_150 = 7;
                    }
                    goto LAB_183cfe80c;
                  }
                  goto LAB_183cfe800;
                }
                if (lVar36 == 0) {
                  lVar36 = 0;
                }
                lVar41 = pacga((long)*(int *)(param_6 + 0x30),
                               uVar3 & 0xffffffffffff | 0x5363000000000000);
                if (lVar41 != *(long *)(param_6 + 0x38)) goto LAB_183cff6d8;
                local_118 = (byte *)(lVar36 + (long)*(int *)(param_6 + 0x30) * (long)iVar39);
                if (lVar36 == 0) {
                  local_150 = 7;
LAB_183cff4f0:
                  bVar38 = 0;
                  local_120 = (ulong)uVar32;
                  goto LAB_183cfe800;
                }
                if (param_7 == 0) {
                  local_150 = 7;
                  uVar32 = 0;
                  goto LAB_183cff554;
                }
                if ((int)param_7 < 2) {
                  bVar38 = 0;
                  bVar53 = *local_118 >> 7;
                  local_120 = 1;
                  local_150 = 7;
                  if (uVar44 == 1) {
                    local_118 = (byte *)0x0;
                    local_120 = 1;
                  }
                  else {
LAB_183cff61c:
                    local_150 = local_150 - 1;
                  }
                }
                else {
                  bVar38 = 0;
                  bVar53 = 0;
                  local_150 = 7;
                  local_120 = (ulong)uVar13;
                }
              }
LAB_183cfe80c:
              bVar52 = bVar52 | bVar23;
              bVar48 = bVar48 | bVar30;
              bVar53 = bVar53 | bVar38;
            }
            if (0 < param_2) {
              iVar21 = 0;
              uVar50 = uVar50 | uVar45;
              do {
                if (local_b8 == (byte *)0x0) {
                  local_b8 = (byte *)0x0;
                  uVar45 = 0;
                }
                else if (iVar46 < 0) {
                  uVar45 = 0;
                  iVar46 = iVar46 + 1;
                }
                else {
                  lVar36 = pacga((long)*(int *)(local_88 + 0x10),uVar27);
                  if (lVar36 != *(long *)(local_88 + 0x18)) goto LAB_183cff6d8;
                  uVar45 = *local_b8 >> (ulong)(local_138 & 0x1f) & 1;
                  iVar46 = iVar46 + 1;
                  if (iVar46 == *(int *)(local_88 + 0x10)) {
                    local_b8 = (byte *)0x0;
                  }
                  else if (local_138 == 0) {
                    local_b8 = local_b8 + 1;
                    local_138 = 7;
                  }
                  else {
                    local_138 = local_138 - 1;
                  }
                }
                uVar32 = 0;
                uVar44 = uVar25;
                if (local_c0 == (byte *)0x0) {
LAB_183cfe93c:
                  local_c0 = (byte *)0x0;
                  if (pbVar54 == (byte *)0x0) goto LAB_183cfe9a8;
LAB_183cfe944:
                  uVar25 = uVar44;
                  if ((int)uVar22 < 0) {
                    uVar40 = 0;
                    uVar22 = uVar22 + 1;
                  }
                  else {
                    lVar36 = pacga((long)(int)*(uint *)(param_6 + 0x10),uVar28);
                    if (lVar36 != *(long *)(param_6 + 0x18)) goto LAB_183cff6d8;
                    uVar40 = *pbVar54 >> (ulong)(local_130 & 0x1f) & 1;
                    uVar22 = uVar22 + 1;
                    uVar44 = local_130 - 1;
                    pbVar51 = pbVar54;
                    if (local_130 == 0) {
                      pbVar51 = pbVar54 + 1;
                      uVar44 = 7;
                    }
                    pbVar54 = (byte *)0x0;
                    if (uVar22 != *(uint *)(param_6 + 0x10)) {
                      pbVar54 = pbVar51;
                      local_130 = uVar44;
                    }
                  }
                }
                else {
                  if ((int)uVar25 < 0) {
                    uVar32 = 0;
                  }
                  else {
                    lVar36 = pacga((long)(int)*(uint *)(param_6 + 0x10),uVar28);
                    if (lVar36 != *(long *)(param_6 + 0x18)) goto LAB_183cff6d8;
                    uVar32 = *local_c0 >> (ulong)(local_13c & 0x1f) & 1;
                    uVar44 = uVar25 + 1;
                    if (uVar44 == *(uint *)(param_6 + 0x10)) goto LAB_183cfe93c;
                    if (local_13c == 0) {
                      local_c0 = local_c0 + 1;
                      local_13c = 7;
                    }
                    else {
                      local_13c = local_13c - 1;
                    }
                  }
                  uVar44 = uVar25 + 1;
                  if (pbVar54 != (byte *)0x0) goto LAB_183cfe944;
LAB_183cfe9a8:
                  uVar40 = 0;
                  uVar25 = uVar44;
                }
                if (local_90 == (byte *)0x0) {
                  local_90 = (byte *)0x0;
                  uVar44 = 0;
                  pbVar51 = local_90;
                }
                else if ((int)uVar49 < 0) {
                  uVar44 = 0;
                  uVar49 = uVar49 + 1;
                  pbVar51 = local_90;
                }
                else {
                  lVar36 = pacga((long)(int)*(uint *)(param_6 + 0x10),uVar28);
                  if (lVar36 != *(long *)(param_6 + 0x18)) goto LAB_183cff6d8;
                  uVar44 = *local_90 >> (ulong)(local_134 & 0x1f) & 1;
                  uVar49 = uVar49 + 1;
                  uVar31 = local_134 - 1;
                  if (local_134 == 0) {
                    local_90 = local_90 + 1;
                    uVar31 = 7;
                  }
                  pbVar51 = (byte *)0x0;
                  if (uVar49 != *(uint *)(param_6 + 0x10)) {
                    local_134 = uVar31;
                    pbVar51 = local_90;
                  }
                }
                local_90 = pbVar51;
                local_74 = uVar45 | (local_74 & 1) << 1;
                uStack_78 = uVar32 | (uStack_78 & 1) << 1;
                local_7c = uVar40 | (local_7c & 3) << 1;
                uVar50 = uVar44 | (uVar50 & 3) << 1;
                if (param_5 == 0) {
LAB_183cfed00:
                  if (local_108 == (byte *)0x0) {
                    local_108 = (byte *)0x0;
                    uVar45 = 0;
                    pbVar51 = local_108;
                  }
                  else if ((int)local_124 < 0) {
                    uVar45 = 0;
                    local_124 = local_124 + 1;
                    pbVar51 = local_108;
                  }
                  else {
                    lVar36 = pacga((long)*(int *)(local_88 + 0x10),uVar27);
                    if (lVar36 != *(long *)(local_88 + 0x18)) goto LAB_183cff6d8;
                    uVar45 = *local_108 >> (ulong)(local_140 & 0x1f) & 1;
                    local_124 = local_124 + 1;
                    uVar44 = local_140 - 1;
                    if (local_140 == 0) {
                      local_108 = local_108 + 1;
                      uVar44 = 7;
                    }
                    pbVar51 = (byte *)0x0;
                    if (local_124 != *(int *)(local_88 + 0x10)) {
                      local_140 = uVar44;
                      pbVar51 = local_108;
                    }
                  }
                  local_108 = pbVar51;
                  if (local_100 == (byte *)0x0) {
                    local_100 = (byte *)0x0;
                    uVar44 = 0;
                    pbVar51 = local_100;
                  }
                  else if ((int)local_128 < 0) {
                    uVar44 = 0;
                    local_128 = local_128 + 1;
                    pbVar51 = local_100;
                  }
                  else {
                    lVar36 = pacga((long)(int)*(uint *)(local_88 + 0x10),uVar27);
                    if (lVar36 != *(long *)(local_88 + 0x18)) goto LAB_183cff6d8;
                    uVar44 = *local_100 >> (ulong)(local_144 & 0x1f) & 1;
                    local_128 = local_128 + 1;
                    uVar32 = local_144 - 1;
                    if (local_144 == 0) {
                      local_100 = local_100 + 1;
                      uVar32 = 7;
                    }
                    pbVar51 = (byte *)0x0;
                    if (local_128 != *(uint *)(local_88 + 0x10)) {
                      local_144 = uVar32;
                      pbVar51 = local_100;
                    }
                  }
                  local_100 = pbVar51;
                  uVar32 = 0;
                  if (local_110 == (byte *)0x0) {
LAB_183cfee60:
                    local_110 = (byte *)0x0;
                  }
                  else if ((int)local_12c < 0) {
                    uVar32 = 0;
                    local_12c = local_12c + 1;
                  }
                  else {
                    lVar36 = pacga((long)(int)*(uint *)(param_6 + 0x10),uVar28);
                    if (lVar36 != *(long *)(param_6 + 0x18)) goto LAB_183cff6d8;
                    uVar32 = *local_110 >> (ulong)(local_154 & 0x1f) & 1;
                    local_12c = local_12c + 1;
                    if (local_12c == *(uint *)(param_6 + 0x10)) goto LAB_183cfee60;
                    if (local_154 == 0) {
                      local_110 = local_110 + 1;
                      local_154 = 7;
                    }
                    else {
                      local_154 = local_154 - 1;
                    }
                  }
                  iVar18 = __ZN18JArithmeticDecoder9decodeBitEjP23JArithmeticDecoderStats
                                     (*(undefined8 *)(param_1 + 0x68),
                                      uVar32 | local_74 << 0xb | uVar45 << 10 | uStack_78 << 8 |
                                               local_7c << 5 | uVar50 << 2 | uVar44 << 1,
                                      *(undefined8 *)(param_1 + 0x78));
                  if (iVar18 != 0) {
                    __ZN11JBIG2Bitmap8setPixelEii(local_88,iVar21,iVar20);
                  }
                }
                else {
                  if (local_e8 == (byte *)0x0) {
joined_r0x000183cfeafc:
                    bVar23 = 0;
joined_r0x000183cfeafc:
                    if (local_f0 != (byte *)0x0) goto LAB_183cfeb00;
LAB_183cfeb60:
                    bVar30 = 0;
                  }
                  else {
                    iVar18 = (int)local_d0;
                    if (iVar18 < 0) {
                      local_d0 = (byte *)(ulong)(iVar18 + 1);
                      goto joined_r0x000183cfeafc;
                    }
                    lVar36 = pacga((long)(int)*(uint *)(param_6 + 0x10),uVar28);
                    if (lVar36 != *(long *)(param_6 + 0x18)) goto LAB_183cff6d8;
                    bVar23 = *local_e8 >> (ulong)(local_148 & 0x1f) & 1;
                    local_d0 = (byte *)(ulong)(iVar18 + 1U);
                    if (iVar18 + 1U != *(uint *)(param_6 + 0x10)) {
                      if (local_148 == 0) {
                        local_e8 = local_e8 + 1;
                        local_148 = 7;
                        goto joined_r0x000183cfebc0;
                      }
                      local_148 = local_148 - 1;
                      goto joined_r0x000183cfeafc;
                    }
                    local_e8 = (byte *)0x0;
joined_r0x000183cfebc0:
                    if (local_f0 == (byte *)0x0) goto LAB_183cfeb60;
LAB_183cfeb00:
                    iVar18 = (int)local_e0;
                    if (iVar18 < 0) {
                      bVar30 = 0;
                      local_e0 = (byte *)(ulong)(iVar18 + 1);
                    }
                    else {
                      lVar36 = pacga((long)(int)*(uint *)(param_6 + 0x10),uVar28);
                      if (lVar36 != *(long *)(param_6 + 0x18)) goto LAB_183cff6d8;
                      bVar30 = *local_f0 >> (ulong)(local_14c & 0x1f) & 1;
                      local_e0 = (byte *)(ulong)(iVar18 + 1U);
                      if (iVar18 + 1U == *(uint *)(param_6 + 0x10)) {
                        local_f0 = (byte *)0x0;
                      }
                      else if (local_14c == 0) {
                        local_f0 = local_f0 + 1;
                        local_14c = 7;
                      }
                      else {
                        local_14c = local_14c - 1;
                      }
                    }
                  }
                  if (local_118 == (byte *)0x0) {
                    local_118 = (byte *)0x0;
                    bVar38 = 0;
                  }
                  else {
                    iVar18 = (int)local_120;
                    if (iVar18 < 0) {
                      bVar38 = 0;
                      local_120 = (ulong)(iVar18 + 1);
                    }
                    else {
                      lVar36 = pacga((long)(int)*(uint *)(param_6 + 0x10),uVar28);
                      if (lVar36 != *(long *)(param_6 + 0x18)) goto LAB_183cff6d8;
                      bVar38 = *local_118 >> (ulong)(local_150 & 0x1f) & 1;
                      local_120 = (ulong)(iVar18 + 1U);
                      if (iVar18 + 1U == *(uint *)(param_6 + 0x10)) {
                        local_118 = (byte *)0x0;
                      }
                      else if (local_150 == 0) {
                        local_150 = 7;
                        local_118 = local_118 + 1;
                      }
                      else {
                        local_150 = local_150 - 1;
                      }
                    }
                  }
                  bVar52 = bVar23 | (bVar52 & 3) << 1;
                  bVar48 = bVar30 | (bVar48 & 3) << 1;
                  bVar53 = bVar38 | (bVar53 & 3) << 1;
                  __ZN18JArithmeticDecoder9decodeBitEjP23JArithmeticDecoderStats
                            (*(undefined8 *)(param_1 + 0x68),uVar24,*(undefined8 *)(param_1 + 0x78))
                  ;
                  if (((bVar52 == 0) && (bVar48 == 0)) && (bVar53 == 0)) {
                    __ZN11JBIG2Bitmap10clearPixelEii(local_88,iVar21,iVar20);
                    bVar52 = 0;
                    bVar48 = 0;
                  }
                  else {
                    if (((bVar52 != 7) || (bVar48 != 7)) || (bVar53 != 7)) goto LAB_183cfed00;
                    __ZN11JBIG2Bitmap8setPixelEii(local_88,iVar21,iVar20);
                    bVar52 = 7;
                    bVar48 = 7;
                  }
                }
                iVar21 = iVar21 + 1;
              } while (param_2 != iVar21);
            }
          }
          else {
            if (iVar20 == 0) {
LAB_183cfcca0:
              local_90 = (byte *)0x0;
              uVar25 = 0;
              iVar46 = 0;
              local_74 = 0;
            }
            else {
              if (lVar41 != lVar36) goto LAB_183cff6d8;
              if (iVar21 < iVar20) goto LAB_183cfcca0;
              iVar46 = *(int *)(local_88 + 0x10);
              lVar42 = pacga((long)iVar46,uVar27);
              if (lVar42 != *(long *)(local_88 + 0x18)) goto LAB_183cff6d8;
              if (iVar46 < 1) goto LAB_183cfcca0;
              lVar42 = pacga((long)*(int *)(local_88 + 0x30),
                             uVar1 & 0xffffffffffff | 0x5363000000000000);
              if (lVar42 != *(long *)(local_88 + 0x38)) goto LAB_183cff6d8;
              if (*plVar47 == 0) {
                local_90 = (byte *)0x0;
                iVar46 = 0;
                local_74 = 0;
                uVar25 = 7;
              }
              else {
                pbVar54 = (byte *)(*plVar47 + (long)*(int *)(local_88 + 0x30) * ((long)iVar20 + -1))
                ;
                local_74 = (uint)(*pbVar54 >> 7);
                local_90 = (byte *)0x0;
                if (iVar46 != 1) {
                  local_90 = pbVar54;
                }
                uVar25 = 6;
                if (iVar46 == 1) {
                  uVar25 = 7;
                }
                iVar46 = 1;
              }
            }
            if (lVar41 != lVar36) goto LAB_183cff6d8;
            if (iVar20 < iVar21) {
              lVar36 = pacga((long)*(int *)(local_88 + 0x10),uVar27);
              if (lVar36 != *(long *)(local_88 + 0x18)) goto LAB_183cff6d8;
              if (*(int *)(local_88 + 0x10) < 0) goto LAB_183cfcd3c;
              lVar36 = pacga((long)*(int *)(local_88 + 0x30),
                             uVar1 & 0xffffffffffff | 0x5363000000000000);
              if (lVar36 != *(long *)(local_88 + 0x38)) goto LAB_183cff6d8;
              local_e0 = (byte *)(*plVar47 + (long)*(int *)(local_88 + 0x30) * (long)iVar20);
              iVar21 = -1;
              local_124 = 7;
            }
            else {
LAB_183cfcd3c:
              local_e0 = (byte *)0x0;
              local_124 = 0;
              iVar21 = 0;
            }
            uVar37 = uVar2 & 0xffffffffffff | 0x5363000000000000;
            iVar18 = iVar18 - param_8;
            if (iVar18 < 0) {
LAB_183cfcdf4:
              local_e8 = (byte *)0x0;
              local_128 = 0;
              uVar22 = 0;
            }
            else {
              lVar36 = pacga((long)*(int *)(param_6 + 0x20),uVar37);
              if (lVar36 != *(long *)(param_6 + 0x28)) goto LAB_183cff6d8;
              if (*(int *)(param_6 + 0x20) <= iVar18) goto LAB_183cfcdf4;
              lVar36 = pacga((long)*(int *)(param_6 + 0x10),uVar28);
              if (lVar36 != *(long *)(param_6 + 0x18)) goto LAB_183cff6d8;
              if (*(int *)(param_6 + 0x10) <= (int)uVar10) goto LAB_183cfcdf4;
              uVar29 = uVar3 & 0xffffffffffff | 0x5363000000000000;
              if ((int)param_7 < 1) {
                lVar36 = pacga((long)*(int *)(param_6 + 0x30),uVar29);
                if (lVar36 != *(long *)(param_6 + 0x38)) goto LAB_183cff6d8;
                lVar36 = uVar34 + (long)*(int *)(param_6 + 0x30) * (long)iVar18;
                local_128 = uVar8;
              }
              else {
                lVar36 = pacga((long)*(int *)(param_6 + 0x30),uVar29);
                if (lVar36 != *(long *)(param_6 + 0x38)) goto LAB_183cff6d8;
                lVar36 = (long)*(int *)(param_6 + 0x30) * (long)iVar18;
                local_128 = 7;
              }
              local_e8 = (byte *)(*(long *)(param_6 + 0x40) + lVar36);
              uVar22 = uVar10;
            }
            iVar17 = iVar20 - param_8;
            if (iVar17 < 0) {
LAB_183cfceac:
              if (-1 < iVar17 + 1) {
                iVar26 = *(int *)(param_6 + 0x20);
                lVar36 = pacga((long)iVar26,uVar37);
                if (lVar36 != *(long *)(param_6 + 0x28)) goto LAB_183cff6d8;
                pbVar54 = (byte *)0x0;
                uVar45 = 0;
                uVar49 = 0;
                uStack_78 = 0;
                goto LAB_183cfd5c4;
              }
              local_7c = 0;
              uStack_78 = 0;
              uVar49 = 0;
              uVar45 = 0;
              pbVar54 = (byte *)0x0;
              bVar16 = true;
              pbVar51 = (byte *)0x0;
              uVar50 = 0;
              uVar44 = 0;
              goto LAB_183cfd66c;
            }
            iVar26 = *(int *)(param_6 + 0x20);
            lVar36 = pacga((long)iVar26,uVar37);
            if (lVar36 != *(long *)(param_6 + 0x28)) goto LAB_183cff6d8;
            if (iVar26 <= iVar17) goto LAB_183cfceac;
            uVar50 = *(uint *)(param_6 + 0x10);
            lVar36 = pacga((long)(int)uVar50,uVar28);
            if (lVar36 != *(long *)(param_6 + 0x18)) goto LAB_183cff6d8;
            if ((int)uVar9 < (int)uVar50) {
              lVar36 = *(long *)(param_6 + 0x40);
              if (-1 < (int)param_7) {
                lVar41 = pacga((long)*(int *)(param_6 + 0x30),
                               uVar3 & 0xffffffffffff | 0x5363000000000000);
                if (lVar41 != *(long *)(param_6 + 0x38)) goto LAB_183cff6d8;
                if (lVar36 == 0) {
                  uVar45 = 7;
                  goto LAB_183cfd430;
                }
                pbVar54 = (byte *)(lVar36 + (long)*(int *)(param_6 + 0x30) * (long)iVar17);
                uVar49 = 0;
                if (param_7 == 0) {
                  uStack_78 = (uint)(*pbVar54 >> 7);
                  uVar45 = 7;
                  if (uVar50 == 1) {
                    pbVar54 = (byte *)0x0;
                  }
                  else {
LAB_183cfd5b0:
                    uVar45 = uVar45 - 1;
                  }
                }
                else {
                  uStack_78 = 0;
LAB_183cfcea4:
                  uVar45 = 7;
                }
LAB_183cfd5b4:
                uStack_78 = uStack_78 | uVar49;
                uVar49 = uVar12;
                goto LAB_183cfd5c4;
              }
              if (lVar36 == 0) {
                lVar36 = 0;
              }
              lVar41 = pacga((long)*(int *)(param_6 + 0x30),
                             uVar3 & 0xffffffffffff | 0x5363000000000000);
              if (lVar41 != *(long *)(param_6 + 0x38)) goto LAB_183cff6d8;
              pbVar54 = (byte *)(lVar36 + uVar35 + (long)*(int *)(param_6 + 0x30) * (long)iVar17);
              uVar45 = uVar5;
              if (lVar36 == 0) {
LAB_183cfd430:
                uStack_78 = 0;
                uVar49 = uVar9;
              }
              else {
                uStack_78 = *pbVar54 >> (ulong)uVar5 & 1;
                uVar49 = uVar10;
                if (uVar50 != uVar10) {
                  pbVar54 = pbVar54 + uVar33;
                  uVar49 = uStack_78 << 1;
                  uStack_78 = *pbVar54 >> (ulong)(uVar7 & 0x1f) & 1;
                  if (uVar12 != uVar50) {
                    uVar45 = uVar7;
                    if (uVar7 != 0) goto LAB_183cfd5b0;
                    pbVar54 = pbVar54 + 1;
                    goto LAB_183cfcea4;
                  }
                  pbVar54 = (byte *)0x0;
                  uVar45 = uVar7;
                  goto LAB_183cfd5b4;
                }
              }
            }
            else {
              uVar45 = 0;
              uVar49 = 0;
              uStack_78 = 0;
            }
            pbVar54 = (byte *)0x0;
            uStack_78 = uStack_78 << 1;
LAB_183cfd5c4:
            iVar39 = iVar17 + 1;
            if (iVar39 < iVar26) {
              uVar32 = *(uint *)(param_6 + 0x10);
              lVar36 = pacga((long)(int)uVar32,uVar28);
              if (lVar36 != *(long *)(param_6 + 0x18)) goto LAB_183cff6d8;
              if ((int)uVar32 <= (int)uVar10) goto LAB_183cfd658;
              lVar36 = *(long *)(param_6 + 0x40);
              uVar50 = uVar12;
              if ((int)param_7 < 1) {
                lVar41 = pacga((long)*(int *)(param_6 + 0x30),
                               uVar3 & 0xffffffffffff | 0x5363000000000000);
                if (lVar41 != *(long *)(param_6 + 0x38)) goto LAB_183cff6d8;
                bVar16 = false;
                uVar44 = uVar8;
                if (lVar36 == 0) goto LAB_183cfdf00;
                pbVar6 = (byte *)(lVar36 + uVar34 + (long)*(int *)(param_6 + 0x30) * (long)iVar39);
                local_7c = *pbVar6 >> (ulong)uVar8 & 1;
                pbVar51 = (byte *)0x0;
                if (uVar12 != uVar32) {
                  pbVar51 = pbVar6 + bVar14;
                  uVar44 = uVar4;
                }
              }
              else {
                lVar41 = pacga((long)*(int *)(param_6 + 0x30),
                               uVar3 & 0xffffffffffff | 0x5363000000000000);
                if (lVar41 != *(long *)(param_6 + 0x38)) goto LAB_183cff6d8;
                bVar16 = false;
                if (lVar36 == 0) {
                  uVar44 = 7;
LAB_183cfdf00:
                  local_7c = 0;
                  bVar16 = false;
                  pbVar51 = (byte *)0x0;
                  uVar50 = uVar10;
                }
                else {
                  local_7c = 0;
                  pbVar51 = (byte *)(lVar36 + (long)*(int *)(param_6 + 0x30) * (long)iVar39);
                  uVar44 = 7;
                }
              }
            }
            else {
LAB_183cfd658:
              bVar16 = false;
              local_7c = 0;
              pbVar51 = (byte *)0x0;
              uVar50 = 0;
              uVar44 = 0;
            }
LAB_183cfd66c:
            iVar26 = iVar17 + 1;
            if (param_5 == 0) {
              local_c8 = (byte *)0x0;
              local_130 = 0;
              local_b8 = (byte *)0x0;
              local_d0 = (byte *)0x0;
              local_134 = 0;
              local_c0 = (byte *)0x0;
              local_f0 = (byte *)0x0;
              local_12c = 0;
              uVar37 = 0;
              bVar52 = 0;
              bVar48 = 0;
              bVar53 = 0;
            }
            else {
              if (iVar18 < 0) {
LAB_183cfd708:
                local_130 = 0;
                local_b8 = (byte *)0x0;
                bVar23 = 0;
LAB_183cfd714:
                local_c8 = (byte *)0x0;
                bVar52 = 0;
                bVar23 = bVar23 << 1;
              }
              else {
                lVar36 = pacga((long)*(int *)(param_6 + 0x20),uVar37);
                if (lVar36 != *(long *)(param_6 + 0x28)) goto LAB_183cff6d8;
                if (*(int *)(param_6 + 0x20) <= iVar18) goto LAB_183cfd708;
                uVar32 = *(uint *)(param_6 + 0x10);
                uVar29 = (ulong)(int)uVar32;
                lVar36 = pacga(uVar29,uVar28);
                if (lVar36 != *(long *)(param_6 + 0x18)) goto LAB_183cff6d8;
                if ((int)uVar32 <= (int)uVar9) goto LAB_183cfd708;
                lVar36 = *(long *)(param_6 + 0x40);
                uVar40 = uVar9;
                if ((int)param_7 < 0) {
                  if (lVar36 == 0) {
                    lVar36 = 0;
                  }
                  lVar41 = pacga((long)*(int *)(param_6 + 0x30),
                                 uVar3 & 0xffffffffffff | 0x5363000000000000);
                  if (lVar41 != *(long *)(param_6 + 0x38)) goto LAB_183cff6d8;
                  if ((lVar36 == 0) || (uVar40 = uVar10, uVar32 == uVar10)) goto LAB_183cfe098;
                  local_c8 = (byte *)(lVar36 + uVar35 + (long)*(int *)(param_6 + 0x30) *
                                                        (long)iVar18 + uVar33);
                  local_130 = uVar7;
LAB_183cfe16c:
                  bVar23 = *local_c8 >> (ulong)(local_130 & 0x1f) & 1;
                  local_b8 = (byte *)uVar29;
                  if (uVar40 + 1 != uVar32) {
                    uVar31 = local_130 - 1;
                    bVar15 = local_130 == 0;
                    if (bVar15) {
                      local_c8 = local_c8 + 1;
                    }
                    local_130 = 7;
                    if (!bVar15) {
                      local_130 = uVar31;
                    }
                    bVar23 = bVar23 << 1;
                    local_b8 = (byte *)(ulong)(uVar40 + 2);
                    bVar52 = *local_c8 >> (ulong)(local_130 & 0x1f) & 1;
                    if (uVar40 + 2 == uVar32) {
                      local_c8 = (byte *)0x0;
                      local_b8 = (byte *)uVar29;
                    }
                    else {
                      if (local_130 != 0) goto LAB_183cfe348;
                      local_c8 = local_c8 + 1;
                      local_130 = 7;
                    }
                    goto LAB_183cfd720;
                  }
                  goto LAB_183cfd714;
                }
                if (lVar36 == 0) {
                  lVar36 = 0;
                }
                lVar41 = pacga((long)*(int *)(param_6 + 0x30),
                               uVar3 & 0xffffffffffff | 0x5363000000000000);
                if (lVar41 != *(long *)(param_6 + 0x38)) goto LAB_183cff6d8;
                local_c8 = (byte *)(lVar36 + (long)*(int *)(param_6 + 0x30) * (long)iVar18);
                if (lVar36 == 0) {
                  local_130 = 7;
LAB_183cfe098:
                  bVar23 = 0;
                  local_b8 = (byte *)(ulong)uVar40;
                  goto LAB_183cfd714;
                }
                if (param_7 == 0) {
                  local_130 = 7;
                  uVar40 = 0;
                  goto LAB_183cfe16c;
                }
                if ((int)param_7 < 2) {
                  bVar23 = 0;
                  bVar52 = *local_c8 >> 7;
                  local_b8 = (byte *)0x1;
                  local_130 = 7;
                  if (uVar32 == 1) {
                    local_c8 = (byte *)0x0;
                    local_b8 = (byte *)0x1;
                  }
                  else {
LAB_183cfe348:
                    local_130 = local_130 - 1;
                  }
                }
                else {
                  bVar23 = 0;
                  bVar52 = 0;
                  local_130 = 7;
                  local_b8 = (byte *)(ulong)uVar13;
                }
              }
LAB_183cfd720:
              if (iVar17 < 0) {
LAB_183cfd798:
                local_134 = 0;
                local_c0 = (byte *)0x0;
                bVar30 = 0;
LAB_183cfd7a4:
                local_d0 = (byte *)0x0;
                bVar48 = 0;
                bVar30 = bVar30 << 1;
              }
              else {
                lVar36 = pacga((long)*(int *)(param_6 + 0x20),uVar37);
                if (lVar36 != *(long *)(param_6 + 0x28)) goto LAB_183cff6d8;
                if (*(int *)(param_6 + 0x20) <= iVar17) goto LAB_183cfd798;
                uVar32 = *(uint *)(param_6 + 0x10);
                uVar29 = (ulong)(int)uVar32;
                lVar36 = pacga(uVar29,uVar28);
                if (lVar36 != *(long *)(param_6 + 0x18)) goto LAB_183cff6d8;
                if ((int)uVar32 <= (int)uVar9) goto LAB_183cfd798;
                lVar36 = *(long *)(param_6 + 0x40);
                uVar40 = uVar9;
                if ((int)param_7 < 0) {
                  if (lVar36 == 0) {
                    lVar36 = 0;
                  }
                  lVar41 = pacga((long)*(int *)(param_6 + 0x30),
                                 uVar3 & 0xffffffffffff | 0x5363000000000000);
                  if (lVar41 != *(long *)(param_6 + 0x38)) goto LAB_183cff6d8;
                  if ((lVar36 == 0) || (uVar40 = uVar10, uVar32 == uVar10)) goto LAB_183cfe0f8;
                  local_d0 = (byte *)(lVar36 + uVar35 + (long)*(int *)(param_6 + 0x30) *
                                                        (long)iVar17 + uVar33);
                  local_134 = uVar7;
LAB_183cfe1d0:
                  bVar30 = *local_d0 >> (ulong)(local_134 & 0x1f) & 1;
                  local_c0 = (byte *)uVar29;
                  if (uVar40 + 1 != uVar32) {
                    uVar31 = local_134 - 1;
                    bVar15 = local_134 == 0;
                    if (bVar15) {
                      local_d0 = local_d0 + 1;
                    }
                    local_134 = 7;
                    if (!bVar15) {
                      local_134 = uVar31;
                    }
                    bVar30 = bVar30 << 1;
                    local_c0 = (byte *)(ulong)(uVar40 + 2);
                    bVar48 = *local_d0 >> (ulong)(local_134 & 0x1f) & 1;
                    if (uVar40 + 2 == uVar32) {
                      local_d0 = (byte *)0x0;
                      local_c0 = (byte *)uVar29;
                    }
                    else {
                      if (local_134 != 0) goto LAB_183cfe358;
                      local_d0 = local_d0 + 1;
                      local_134 = 7;
                    }
                    goto LAB_183cfd7b0;
                  }
                  goto LAB_183cfd7a4;
                }
                if (lVar36 == 0) {
                  lVar36 = 0;
                }
                lVar41 = pacga((long)*(int *)(param_6 + 0x30),
                               uVar3 & 0xffffffffffff | 0x5363000000000000);
                if (lVar41 != *(long *)(param_6 + 0x38)) goto LAB_183cff6d8;
                local_d0 = (byte *)(lVar36 + (long)*(int *)(param_6 + 0x30) * (long)iVar17);
                if (lVar36 == 0) {
                  local_134 = 7;
LAB_183cfe0f8:
                  bVar30 = 0;
                  local_c0 = (byte *)(ulong)uVar40;
                  goto LAB_183cfd7a4;
                }
                if (param_7 == 0) {
                  local_134 = 7;
                  uVar40 = 0;
                  goto LAB_183cfe1d0;
                }
                if ((int)param_7 < 2) {
                  bVar30 = 0;
                  bVar48 = *local_d0 >> 7;
                  local_c0 = (byte *)0x1;
                  local_134 = 7;
                  if (uVar32 == 1) {
                    local_d0 = (byte *)0x0;
                    local_c0 = (byte *)0x1;
                  }
                  else {
LAB_183cfe358:
                    local_134 = local_134 - 1;
                  }
                }
                else {
                  bVar30 = 0;
                  bVar48 = 0;
                  local_134 = 7;
                  local_c0 = (byte *)(ulong)uVar13;
                }
              }
LAB_183cfd7b0:
              if (bVar16) {
LAB_183cfd828:
                local_12c = 0;
                uVar29 = 0;
                bVar38 = 0;
LAB_183cfd838:
                local_f0 = (byte *)0x0;
                bVar53 = 0;
                bVar38 = bVar38 << 1;
                uVar37 = uVar29;
              }
              else {
                lVar36 = pacga((long)*(int *)(param_6 + 0x20),uVar37);
                if (lVar36 != *(long *)(param_6 + 0x28)) {
LAB_183cff6d8:
                  lVar36 = func_0x000188138260();
                  return lVar36;
                }
                if (*(int *)(param_6 + 0x20) <= iVar26) goto LAB_183cfd828;
                uVar32 = *(uint *)(param_6 + 0x10);
                uVar29 = (ulong)(int)uVar32;
                lVar36 = pacga(uVar29,uVar28);
                if (lVar36 != *(long *)(param_6 + 0x18)) goto LAB_183cff6d8;
                if ((int)uVar32 <= (int)uVar9) goto LAB_183cfd828;
                lVar36 = *(long *)(param_6 + 0x40);
                if ((int)param_7 < 0) {
                  if (lVar36 == 0) {
                    lVar36 = 0;
                  }
                  lVar41 = pacga((long)*(int *)(param_6 + 0x30),
                                 uVar3 & 0xffffffffffff | 0x5363000000000000);
                  if (lVar41 != *(long *)(param_6 + 0x38)) goto LAB_183cff6d8;
                  local_12c = uVar5;
                  if (lVar36 == 0) goto LAB_183cfe294;
                  if (uVar32 != uVar10) {
                    local_f0 = (byte *)(lVar36 + uVar35 + (long)*(int *)(param_6 + 0x30) *
                                                          (long)iVar26 + uVar33);
                    local_12c = uVar7;
                    uVar40 = uVar10;
                    goto LAB_183cfe2dc;
                  }
                  bVar38 = 0;
                  uVar29 = (ulong)uVar10;
                  goto LAB_183cfd838;
                }
                if (lVar36 == 0) {
                  lVar36 = 0;
                }
                lVar41 = pacga((long)*(int *)(param_6 + 0x30),
                               uVar3 & 0xffffffffffff | 0x5363000000000000);
                if (lVar41 != *(long *)(param_6 + 0x38)) goto LAB_183cff6d8;
                local_f0 = (byte *)(lVar36 + (long)*(int *)(param_6 + 0x30) * (long)iVar26);
                if (lVar36 == 0) {
                  local_12c = 7;
LAB_183cfe294:
                  bVar38 = 0;
                  uVar29 = (ulong)uVar9;
                  goto LAB_183cfd838;
                }
                if (param_7 == 0) {
                  local_12c = 7;
                  uVar40 = 0;
LAB_183cfe2dc:
                  bVar38 = *local_f0 >> (ulong)(local_12c & 0x1f) & 1;
                  if (uVar40 + 1 == uVar32) goto LAB_183cfd838;
                  uVar31 = local_12c - 1;
                  bVar16 = local_12c == 0;
                  if (bVar16) {
                    local_f0 = local_f0 + 1;
                  }
                  local_12c = 7;
                  if (!bVar16) {
                    local_12c = uVar31;
                  }
                  bVar38 = bVar38 << 1;
                  uVar37 = (ulong)(uVar40 + 2);
                  bVar53 = *local_f0 >> (ulong)(local_12c & 0x1f) & 1;
                  if (uVar40 + 2 == uVar32) {
                    local_f0 = (byte *)0x0;
                    uVar37 = uVar29;
                  }
                  else {
                    if (local_12c != 0) goto LAB_183cff5cc;
                    local_f0 = local_f0 + 1;
                    local_12c = 7;
                  }
                }
                else if ((int)param_7 < 2) {
                  bVar38 = 0;
                  bVar53 = *local_f0 >> 7;
                  uVar37 = 1;
                  local_12c = 7;
                  if (uVar32 == 1) {
                    local_f0 = (byte *)0x0;
                    uVar37 = 1;
                  }
                  else {
LAB_183cff5cc:
                    local_12c = local_12c - 1;
                  }
                }
                else {
                  bVar38 = 0;
                  bVar53 = 0;
                  local_12c = 7;
                  uVar37 = (ulong)uVar13;
                }
              }
              bVar52 = bVar52 | bVar23;
              bVar48 = bVar48 | bVar30;
              bVar53 = bVar53 | bVar38;
            }
            if (0 < param_2) {
              iVar18 = 0;
              do {
                if (local_90 == (byte *)0x0) {
                  local_90 = (byte *)0x0;
joined_r0x000183cfd9c4:
                  uVar32 = 0;
                  uVar40 = 0;
                  if (pbVar54 == (byte *)0x0) goto LAB_183cfd9c8;
LAB_183cfd908:
                  if (-1 < (int)uVar49) {
                    lVar36 = pacga((long)(int)*(uint *)(param_6 + 0x10),uVar28);
                    if (lVar36 == *(long *)(param_6 + 0x18)) {
                      uVar31 = *pbVar54 >> (ulong)(uVar45 & 0x1f) & 1;
                      uVar49 = uVar49 + 1;
                      uVar40 = uVar45 - 1;
                      if (uVar45 == 0) {
                        pbVar54 = pbVar54 + 1;
                        uVar40 = 7;
                      }
                      pbVar6 = (byte *)0x0;
                      if (uVar49 != *(uint *)(param_6 + 0x10)) {
                        uVar45 = uVar40;
                        pbVar6 = pbVar54;
                      }
                      goto joined_r0x000183cfd95c;
                    }
                    goto LAB_183cff6d8;
                  }
                  uVar31 = 0;
                  uVar49 = uVar49 + 1;
                  if (pbVar51 != (byte *)0x0) goto LAB_183cfd960;
LAB_183cfd9d0:
                  uVar40 = 0;
                }
                else {
                  if (iVar46 < 0) {
                    iVar46 = iVar46 + 1;
                    goto joined_r0x000183cfd9c4;
                  }
                  lVar36 = pacga((long)*(int *)(local_88 + 0x10),uVar27);
                  if (lVar36 != *(long *)(local_88 + 0x18)) goto LAB_183cff6d8;
                  uVar32 = *local_90 >> (ulong)(uVar25 & 0x1f) & 1;
                  iVar46 = iVar46 + 1;
                  uVar40 = uVar25 - 1;
                  if (uVar25 == 0) {
                    local_90 = local_90 + 1;
                    uVar40 = 7;
                  }
                  pbVar6 = (byte *)0x0;
                  if (iVar46 != *(int *)(local_88 + 0x10)) {
                    uVar25 = uVar40;
                    pbVar6 = local_90;
                  }
                  local_90 = pbVar6;
                  uVar40 = uVar32;
                  if (pbVar54 != (byte *)0x0) goto LAB_183cfd908;
LAB_183cfd9c8:
                  uVar31 = 0;
                  pbVar6 = pbVar54;
                  uVar32 = uVar40;
joined_r0x000183cfd95c:
                  pbVar54 = pbVar6;
                  if (pbVar51 == (byte *)0x0) goto LAB_183cfd9d0;
LAB_183cfd960:
                  if ((int)uVar50 < 0) {
                    uVar40 = 0;
                    uVar50 = uVar50 + 1;
                  }
                  else {
                    lVar36 = pacga((long)(int)*(uint *)(param_6 + 0x10),uVar28);
                    if (lVar36 != *(long *)(param_6 + 0x18)) goto LAB_183cff6d8;
                    uVar40 = *pbVar51 >> (ulong)(uVar44 & 0x1f) & 1;
                    uVar50 = uVar50 + 1;
                    uVar11 = uVar44 - 1;
                    pbVar6 = pbVar51;
                    if (uVar44 == 0) {
                      pbVar6 = pbVar51 + 1;
                      uVar11 = 7;
                    }
                    pbVar51 = (byte *)0x0;
                    if (uVar50 != *(uint *)(param_6 + 0x10)) {
                      pbVar51 = pbVar6;
                      uVar44 = uVar11;
                    }
                  }
                }
                local_74 = uVar32 | (local_74 & 3) << 1;
                uStack_78 = uVar31 | (uStack_78 & 3) << 1;
                local_7c = uVar40 | (local_7c & 1) << 1;
                if (param_5 == 0) {
LAB_183cfdc70:
                  if (local_e0 == (byte *)0x0) {
                    local_e0 = (byte *)0x0;
                    uVar32 = 0;
                    pbVar6 = local_e0;
                  }
                  else if (iVar21 < 0) {
                    uVar32 = 0;
                    iVar21 = iVar21 + 1;
                    pbVar6 = local_e0;
                  }
                  else {
                    lVar36 = pacga((long)*(int *)(local_88 + 0x10),uVar27);
                    if (lVar36 != *(long *)(local_88 + 0x18)) goto LAB_183cff6d8;
                    uVar32 = *local_e0 >> (ulong)(local_124 & 0x1f) & 1;
                    iVar21 = iVar21 + 1;
                    uVar40 = local_124 - 1;
                    if (local_124 == 0) {
                      local_e0 = local_e0 + 1;
                      uVar40 = 7;
                    }
                    pbVar6 = (byte *)0x0;
                    if (iVar21 != *(int *)(local_88 + 0x10)) {
                      local_124 = uVar40;
                      pbVar6 = local_e0;
                    }
                  }
                  local_e0 = pbVar6;
                  if (local_e8 == (byte *)0x0) {
                    local_e8 = (byte *)0x0;
                    uVar40 = 0;
                    pbVar6 = local_e8;
                  }
                  else if ((int)uVar22 < 0) {
                    uVar40 = 0;
                    uVar22 = uVar22 + 1;
                    pbVar6 = local_e8;
                  }
                  else {
                    lVar36 = pacga((long)(int)*(uint *)(param_6 + 0x10),uVar28);
                    if (lVar36 != *(long *)(param_6 + 0x18)) goto LAB_183cff6d8;
                    uVar40 = *local_e8 >> (ulong)(local_128 & 0x1f) & 1;
                    uVar22 = uVar22 + 1;
                    uVar31 = local_128 - 1;
                    if (local_128 == 0) {
                      local_e8 = local_e8 + 1;
                      uVar31 = 7;
                    }
                    pbVar6 = (byte *)0x0;
                    if (uVar22 != *(uint *)(param_6 + 0x10)) {
                      local_128 = uVar31;
                      pbVar6 = local_e8;
                    }
                  }
                  local_e8 = pbVar6;
                  iVar17 = __ZN18JArithmeticDecoder9decodeBitEjP23JArithmeticDecoderStats
                                     (*(undefined8 *)(param_1 + 0x68),
                                      local_74 << 7 | uVar32 << 6 | uVar40 << 5 | uStack_78 << 2 |
                                      local_7c,*(undefined8 *)(param_1 + 0x78));
                  if (iVar17 != 0) {
                    __ZN11JBIG2Bitmap8setPixelEii(local_88,iVar18,iVar20);
                  }
                }
                else {
                  if (local_c8 == (byte *)0x0) {
joined_r0x000183cfdaa8:
                    bVar23 = 0;
joined_r0x000183cfdaa8:
                    if (local_d0 != (byte *)0x0) goto LAB_183cfdaac;
LAB_183cfdaf8:
                    bVar30 = 0;
                  }
                  else {
                    iVar17 = (int)local_b8;
                    if (iVar17 < 0) {
                      local_b8 = (byte *)(ulong)(iVar17 + 1);
                      goto joined_r0x000183cfdaa8;
                    }
                    lVar36 = pacga((long)(int)*(uint *)(param_6 + 0x10),uVar28);
                    if (lVar36 != *(long *)(param_6 + 0x18)) goto LAB_183cff6d8;
                    bVar23 = *local_c8 >> (ulong)(local_130 & 0x1f) & 1;
                    local_b8 = (byte *)(ulong)(iVar17 + 1U);
                    if (iVar17 + 1U != *(uint *)(param_6 + 0x10)) {
                      if (local_130 == 0) {
                        local_c8 = local_c8 + 1;
                        local_130 = 7;
                        goto joined_r0x000183cfdb3c;
                      }
                      local_130 = local_130 - 1;
                      goto joined_r0x000183cfdaa8;
                    }
                    local_c8 = (byte *)0x0;
joined_r0x000183cfdb3c:
                    if (local_d0 == (byte *)0x0) goto LAB_183cfdaf8;
LAB_183cfdaac:
                    iVar17 = (int)local_c0;
                    if (iVar17 < 0) {
                      bVar30 = 0;
                      local_c0 = (byte *)(ulong)(iVar17 + 1);
                    }
                    else {
                      lVar36 = pacga((long)(int)*(uint *)(param_6 + 0x10),uVar28);
                      if (lVar36 != *(long *)(param_6 + 0x18)) goto LAB_183cff6d8;
                      bVar30 = *local_d0 >> (ulong)(local_134 & 0x1f) & 1;
                      local_c0 = (byte *)(ulong)(iVar17 + 1U);
                      if (iVar17 + 1U == *(uint *)(param_6 + 0x10)) {
                        local_d0 = (byte *)0x0;
                      }
                      else if (local_134 == 0) {
                        local_d0 = local_d0 + 1;
                        local_134 = 7;
                      }
                      else {
                        local_134 = local_134 - 1;
                      }
                    }
                  }
                  if (local_f0 == (byte *)0x0) {
                    local_f0 = (byte *)0x0;
                    bVar38 = 0;
                  }
                  else {
                    iVar17 = (int)uVar37;
                    if (iVar17 < 0) {
                      bVar38 = 0;
                      uVar37 = (ulong)(iVar17 + 1);
                    }
                    else {
                      lVar36 = pacga((long)(int)*(uint *)(param_6 + 0x10),uVar28);
                      if (lVar36 != *(long *)(param_6 + 0x18)) goto LAB_183cff6d8;
                      bVar38 = *local_f0 >> (ulong)(local_12c & 0x1f) & 1;
                      uVar37 = (ulong)(iVar17 + 1U);
                      if (iVar17 + 1U == *(uint *)(param_6 + 0x10)) {
                        local_f0 = (byte *)0x0;
                      }
                      else if (local_12c == 0) {
                        local_12c = 7;
                        local_f0 = local_f0 + 1;
                      }
                      else {
                        local_12c = local_12c - 1;
                      }
                    }
                  }
                  bVar52 = bVar23 | (bVar52 & 3) << 1;
                  bVar48 = bVar30 | (bVar48 & 3) << 1;
                  bVar53 = bVar38 | (bVar53 & 3) << 1;
                  __ZN18JArithmeticDecoder9decodeBitEjP23JArithmeticDecoderStats
                            (*(undefined8 *)(param_1 + 0x68),uVar24,*(undefined8 *)(param_1 + 0x78))
                  ;
                  if (((bVar52 == 0) && (bVar48 == 0)) && (bVar53 == 0)) {
                    __ZN11JBIG2Bitmap10clearPixelEii(local_88,iVar18,iVar20);
                    bVar52 = 0;
                    bVar48 = 0;
                  }
                  else {
                    if (((bVar52 != 7) || (bVar48 != 7)) || (bVar53 != 7)) goto LAB_183cfdc70;
                    __ZN11JBIG2Bitmap8setPixelEii(local_88,iVar18,iVar20);
                    bVar52 = 7;
                    bVar48 = 7;
                  }
                }
                iVar18 = iVar18 + 1;
              } while (param_2 != iVar18);
            }
          }
          iVar20 = iVar20 + 1;
        } while (iVar20 != iVar19);
      }
    }
  }
  return local_88;
}



/* ==== __ZN11JBIG2Stream14readTextRegionEiiiijjiP17JBIG2HuffmanTablejPP11JBIG2BitmapjjjjiPKS0_S6_S6_S6_S6_S6_S6_S6_jPiS7_ @ 183cff6f4 size=1576 ==== */

/* WARNING: Removing unreachable block (ram,0x000183cff794) */

long * __ZN11JBIG2Stream14readTextRegionEiiiijjiP17JBIG2HuffmanTablejPP11JBIG2BitmapjjjjiPKS0_S6_S6_S6_S6_S6_S6_S6_jPiS7_
                 (long *param_1,int param_2,int param_3,undefined8 param_4,undefined8 param_5,
                 uint param_6,uint param_7,uint param_8,long param_9,undefined4 param_10,
                 long param_11,undefined8 param_12,undefined8 param_13,int param_14,
                 undefined8 param_15,undefined8 param_16,undefined8 param_17,undefined8 param_18,
                 undefined8 param_19,undefined8 param_20,undefined8 param_21,undefined8 param_22,
                 undefined4 param_23,undefined8 param_24,undefined8 param_25)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  long *plVar5;
  undefined8 uVar6;
  ulong uVar7;
  long *plVar8;
  long lVar9;
  long lVar10;
  uint uVar11;
  char *pcVar12;
  int iVar13;
  int iVar14;
  int local_9c;
  undefined4 local_90;
  undefined8 local_8c;
  undefined8 local_84;
  undefined8 local_7c;
  undefined8 local_74;
  int local_6c [3];
  
  local_7c = 0;
  local_84 = 0;
  local_8c = 0;
  local_90 = 0;
  plVar5 = (long *)func_0x00018814d110(0x48,0x10d1c40b539ea8f);
  __ZN11JBIG2BitmapC2Ejii(plVar5,0,param_4,param_5);
  if ((plVar5[8] == 0) || (plVar5[8] == 0)) {
    pcVar12 = "Invalid JBIG2 bitmap allocation";
LAB_183cff7bc:
    uVar6 = (**(code **)(*param_1 + 0x28))(param_1);
    __Z5erroriPKcz(uVar6,pcVar12);
    (**(code **)(*plVar5 + 8))(plVar5);
    plVar5 = (long *)0x0;
  }
  else {
    if ((int)param_12 == 0) {
      __ZN11JBIG2Bitmap11clearToZeroEv(plVar5);
    }
    else {
      __ZN11JBIG2Bitmap10clearToOneEv();
    }
    local_6c[0] = 0;
    if (param_2 == 0) {
      __ZN18JArithmeticDecoder9decodeIntEPiP23JArithmeticDecoderStats
                (param_1[0xd],local_6c,param_1[0x14]);
    }
    else {
      __ZN19JBIG2HuffmanDecoder9decodeIntEPiPK17JBIG2HuffmanTable(param_1[0x1e],local_6c,param_17);
    }
    if (param_6 != 0) {
      uVar11 = 0;
      iVar14 = 0;
      local_9c = -(local_6c[0] << (ulong)(param_7 & 0x1f));
      local_74 = 0;
LAB_183cff910:
      if (param_2 == 0) {
        __ZN18JArithmeticDecoder9decodeIntEPiP23JArithmeticDecoderStats
                  (param_1[0xd],(long)&local_74 + 4,param_1[0x14]);
        iVar13 = local_74._4_4_;
        __ZN18JArithmeticDecoder9decodeIntEPiP23JArithmeticDecoderStats
                  (param_1[0xd],&local_74,param_1[0x16]);
      }
      else {
        __ZN19JBIG2HuffmanDecoder9decodeIntEPiPK17JBIG2HuffmanTable
                  (param_1[0x1e],(long)&local_74 + 4,param_17);
        iVar13 = local_74._4_4_;
        __ZN19JBIG2HuffmanDecoder9decodeIntEPiPK17JBIG2HuffmanTable
                  (param_1[0x1e],&local_74,param_15);
      }
      local_9c = local_9c + (iVar13 << (ulong)(param_7 & 0x1f));
      iVar14 = (int)local_74 + iVar14;
      iVar13 = iVar14;
      do {
        uVar11 = uVar11 + 1;
        if (param_7 == 0) {
          local_74 = local_74 & 0xffffffff;
          iVar3 = local_9c;
          if (param_2 == 0) goto LAB_183cff9f0;
LAB_183cff9b8:
          if (param_9 == 0) {
            uVar7 = __ZN19JBIG2HuffmanDecoder8readBitsEj(param_1[0x1e],param_10);
          }
          else {
            __ZN19JBIG2HuffmanDecoder9decodeIntEPiPK17JBIG2HuffmanTable
                      (param_1[0x1e],(long)&local_7c + 4);
            uVar7 = local_7c >> 0x20;
          }
        }
        else {
          if (param_2 != 0) {
            iVar3 = __ZN19JBIG2HuffmanDecoder8readBitsEj(param_1[0x1e],param_7);
            local_74 = CONCAT44(iVar3,(int)local_74);
            iVar3 = local_9c + iVar3;
            goto LAB_183cff9b8;
          }
          __ZN18JArithmeticDecoder9decodeIntEPiP23JArithmeticDecoderStats
                    (param_1[0xd],(long)&local_74 + 4,param_1[0x15]);
          iVar3 = local_74._4_4_ + local_9c;
LAB_183cff9f0:
          uVar7 = __ZN18JArithmeticDecoder10decodeIAIDEjP23JArithmeticDecoderStats
                            (param_1[0xd],param_10,param_1[0x1d]);
        }
        if (param_8 <= (uint)uVar7) {
          pcVar12 = "Invalid symbol number in JBIG2 text region";
          goto LAB_183cff7bc;
        }
        if (param_3 == 0) {
          local_8c = local_8c & 0xffffffff00000000;
LAB_183cffaa0:
          plVar8 = *(long **)(param_11 + (uVar7 & 0xffffffff) * 8);
          bVar2 = true;
        }
        else {
          if (param_2 == 0) {
            __ZN18JArithmeticDecoder9decodeIntEPiP23JArithmeticDecoderStats
                      (param_1[0xd],&local_8c,param_1[0x1c]);
            if ((int)local_8c == 0) goto LAB_183cffaa0;
            __ZN18JArithmeticDecoder9decodeIntEPiP23JArithmeticDecoderStats
                      (param_1[0xd],&local_7c,param_1[0x1a]);
            __ZN18JArithmeticDecoder9decodeIntEPiP23JArithmeticDecoderStats
                      (param_1[0xd],(long)&local_84 + 4,param_1[0x1b]);
            __ZN18JArithmeticDecoder9decodeIntEPiP23JArithmeticDecoderStats
                      (param_1[0xd],&local_84,param_1[0x18]);
            __ZN18JArithmeticDecoder9decodeIntEPiP23JArithmeticDecoderStats
                      (param_1[0xd],(long)&local_8c + 4,param_1[0x19]);
          }
          else {
            iVar4 = __ZN19JBIG2HuffmanDecoder7readBitEv(param_1[0x1e]);
            local_8c = CONCAT44(local_8c._4_4_,iVar4);
            if (iVar4 == 0) goto LAB_183cffaa0;
            __ZN19JBIG2HuffmanDecoder9decodeIntEPiPK17JBIG2HuffmanTable
                      (param_1[0x1e],&local_7c,param_18);
            __ZN19JBIG2HuffmanDecoder9decodeIntEPiPK17JBIG2HuffmanTable
                      (param_1[0x1e],(long)&local_84 + 4,param_19);
            __ZN19JBIG2HuffmanDecoder9decodeIntEPiPK17JBIG2HuffmanTable
                      (param_1[0x1e],&local_84,param_20);
            __ZN19JBIG2HuffmanDecoder9decodeIntEPiPK17JBIG2HuffmanTable
                      (param_1[0x1e],(long)&local_8c + 4,param_21);
            __ZN19JBIG2HuffmanDecoder9decodeIntEPiPK17JBIG2HuffmanTable
                      (param_1[0x1e],&local_90,param_22);
            *(undefined8 *)(param_1[0x1e] + 8) = 0;
            __ZN18JArithmeticDecoder5startEv(param_1[0xd]);
          }
          lVar9 = *(long *)(param_11 + (uVar7 & 0xffffffff) * 8);
          iVar4 = *(int *)(lVar9 + 0x10);
          lVar10 = pacga((long)iVar4,(ulong)(lVar9 + 0x10) & 0xffffffffffff | 0x5363000000000000);
          if (lVar10 != *(long *)(lVar9 + 0x18)) goto LAB_183cffd18;
          iVar1 = *(int *)(lVar9 + 0x20);
          lVar10 = pacga((long)iVar1,(ulong)(lVar9 + 0x20) & 0xffffffffffff | 0x5363000000000000);
          if (lVar10 != *(long *)(lVar9 + 0x28)) goto LAB_183cffd18;
          plVar8 = (long *)__ZN11JBIG2Stream27readGenericRefinementRegionEiiiiP11JBIG2BitmapiiPiS2_
                                     (param_1,iVar4 + (int)local_7c,iVar1 + local_84._4_4_,param_23,
                                      0,lVar9,(int)local_84 +
                                              ((int)local_7c + ((int)local_7c >> 0x1f)) / 2,
                                      local_8c._4_4_ +
                                      (local_84._4_4_ + (local_84._4_4_ >> 0x1f)) / 2,param_24,
                                      param_25);
          bVar2 = false;
        }
        if (plVar8 == (long *)0x0) {
          pcVar12 = "Failed to create symbolBitmap in JBIG2 text region";
          goto LAB_183cff7bc;
        }
        iVar4 = (int)plVar8[2];
        lVar9 = pacga((long)iVar4,(ulong)(plVar8 + 2) & 0xffffffffffff | 0x5363000000000000);
        if (lVar9 != plVar8[3]) {
LAB_183cffd18:
          plVar5 = (long *)func_0x000188138260();
          return plVar5;
        }
        iVar1 = (int)plVar8[4];
        lVar9 = pacga((long)iVar1,(ulong)(plVar8 + 4) & 0xffffffffffff | 0x5363000000000000);
        if (lVar9 != plVar8[5]) goto LAB_183cffd18;
        iVar4 = iVar4 + -1;
        iVar1 = iVar1 + -1;
        if ((int)param_13 == 0) {
          if (param_13._4_4_ < 2) {
            if (param_13._4_4_ == 0) {
LAB_183cffc10:
              iVar3 = iVar3 - iVar1;
            }
          }
          else if (param_13._4_4_ == 2) goto LAB_183cffc10;
          __ZN11JBIG2Bitmap7combineEPS_iij(plVar5,plVar8,iVar13,iVar3,param_12._4_4_);
          iVar1 = iVar4;
        }
        else {
          if (1 < param_13._4_4_) {
            iVar3 = iVar3 - iVar4;
          }
          __ZN11JBIG2Bitmap7combineEPS_iij(plVar5,plVar8,iVar3,iVar13,param_12._4_4_);
        }
        if (!bVar2) {
          (**(code **)(*plVar8 + 8))(plVar8);
        }
        if (param_6 < uVar11) goto LAB_183cffce8;
        if (param_2 == 0) {
          iVar3 = __ZN18JArithmeticDecoder9decodeIntEPiP23JArithmeticDecoderStats
                            (param_1[0xd],&local_74,param_1[0x17]);
        }
        else {
          iVar3 = __ZN19JBIG2HuffmanDecoder9decodeIntEPiPK17JBIG2HuffmanTable
                            (param_1[0x1e],&local_74,param_16);
        }
        if (iVar3 == 0) goto LAB_183cffce8;
        iVar13 = iVar13 + param_14 + (int)local_74 + iVar1;
      } while( true );
    }
  }
  return plVar5;
LAB_183cffce8:
  if (param_6 <= uVar11) {
    return plVar5;
  }
  goto LAB_183cff910;
}



/* ==== __ZN11JBIG2Stream17readGenericBitmapEiiiiiiP11JBIG2BitmapPiS2_i @ 183cffd34 size=12668 ==== */

/* WARNING: Removing unreachable block (ram,0x000183d01218) */
/* WARNING: Removing unreachable block (ram,0x000183d01964) */
/* WARNING: Removing unreachable block (ram,0x000183d018a4) */
/* WARNING: Removing unreachable block (ram,0x000183d017e8) */
/* WARNING: Removing unreachable block (ram,0x000183d0172c) */
/* WARNING: Removing unreachable block (ram,0x000183d01690) */
/* WARNING: Removing unreachable block (ram,0x000183d02534) */
/* WARNING: Removing unreachable block (ram,0x000183d0248c) */
/* WARNING: Removing unreachable block (ram,0x000183d02098) */
/* WARNING: Removing unreachable block (ram,0x000183d01ff4) */
/* WARNING: Removing unreachable block (ram,0x000183d01030) */
/* WARNING: Removing unreachable block (ram,0x000183d00f94) */
/* WARNING: Removing unreachable block (ram,0x000183d015f4) */
/* WARNING: Removing unreachable block (ram,0x000183d01330) */
/* WARNING: Removing unreachable block (ram,0x000183d023c8) */
/* WARNING: Removing unreachable block (ram,0x000183d013ac) */
/* WARNING: Removing unreachable block (ram,0x000183d028c0) */
/* WARNING: Removing unreachable block (ram,0x000183d012b4) */
/* WARNING: Removing unreachable block (ram,0x000183d01e64) */
/* WARNING: Removing unreachable block (ram,0x000183d01eb4) */
/* WARNING: Removing unreachable block (ram,0x000183d01f04) */
/* WARNING: Removing unreachable block (ram,0x000183d01f54) */
/* WARNING: Removing unreachable block (ram,0x000183d00e38) */
/* WARNING: Removing unreachable block (ram,0x000183d00d34) */
/* WARNING: Removing unreachable block (ram,0x000183cffdd8) */

long * __ZN11JBIG2Stream17readGenericBitmapEiiiiiiP11JBIG2BitmapPiS2_i
                 (long *param_1,int param_2,undefined8 param_3,undefined8 param_4,uint param_5,
                 int param_6,int param_7,undefined8 param_8,uint *param_9,
                 undefined1 (*param_10) [16],uint param_11)

{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  long *plVar6;
  uint *puVar7;
  undefined4 uVar8;
  byte bVar9;
  byte bVar10;
  byte bVar11;
  byte bVar12;
  byte bVar13;
  char cVar14;
  ushort uVar15;
  short sVar16;
  uint uVar17;
  int iVar18;
  bool bVar19;
  bool bVar20;
  bool bVar21;
  uint uVar22;
  int iVar23;
  int iVar24;
  int iVar25;
  uint uVar26;
  int iVar27;
  int iVar28;
  uint uVar29;
  long *plVar30;
  undefined8 uVar31;
  long lVar32;
  uint uVar33;
  undefined1 *puVar34;
  byte *pbVar35;
  byte *pbVar36;
  byte *pbVar37;
  uint uVar38;
  long *plVar39;
  long lVar40;
  long lVar41;
  ulong uVar42;
  long lVar43;
  ulong uVar44;
  ulong uVar45;
  ulong uVar46;
  long lVar47;
  long lVar48;
  long lVar49;
  long lVar50;
  long lVar51;
  uint uVar52;
  char *pcVar53;
  uint uVar54;
  uint uVar55;
  uint uVar56;
  uint uVar57;
  uint uVar58;
  ulong uVar59;
  int iVar60;
  uint uVar61;
  uint uVar62;
  uint uVar63;
  uint *puVar64;
  ulong uVar65;
  byte *pbVar66;
  uint uVar67;
  byte *pbVar68;
  uint uVar69;
  byte *pbVar70;
  ulong uVar71;
  uint uVar72;
  undefined8 *puVar73;
  ulong uVar74;
  byte *pbVar75;
  uint uVar76;
  long local_138;
  uint local_fc;
  uint local_bc;
  uint local_94;
  
  plVar30 = (long *)func_0x00018814d110(0x48,0x10d1c40b539ea8f);
  __ZN11JBIG2BitmapC2Ejii(plVar30,0,param_3,param_4);
  plVar39 = plVar30 + 8;
  if ((*plVar39 != 0) && (*plVar39 != 0)) {
    __ZN11JBIG2Bitmap11clearToZeroEv(plVar30);
    iVar25 = (int)param_3;
    uVar38 = (uint)param_4;
    if (param_2 != 0) {
      lVar40 = param_1[0x1f];
      *(undefined8 *)(lVar40 + 8) = 0;
      *(undefined4 *)(lVar40 + 0x10) = 0;
      if (0x7ffffffd < iVar25) {
        uVar31 = (**(code **)(*param_1 + 0x28))();
        __Z5erroriPKcz(uVar31,"Bad width in JBIG2 generic bitmap");
        param_3 = 0xfffffffd;
      }
      uVar26 = (uint)param_3;
      uVar44 = (long)(int)uVar26 + 2;
      lVar32 = __Z14gmallocn_typediiy(uVar44,4,0x100004052888210);
      uVar45 = (long)(int)uVar26 + 1;
      *(int *)(lVar32 + uVar45 * 4) = (int)uVar45;
      lVar40 = __Z14gmallocn_typediiy(uVar26 + 3,4,0x100004052888210);
      uVar76 = (uint)uVar44;
      *(uint *)(lVar40 + uVar44 * 4) = uVar76;
      uVar74 = 0;
      if (0x7fffffff < uVar26) {
        uVar74 = uVar45;
      }
      puVar7 = (uint *)(lVar32 + uVar74 * 4);
      *puVar7 = uVar26;
      if (0 < (int)uVar38) {
        uVar52 = 0;
        uVar74 = uVar45;
        if (-1 < (int)uVar26) {
          uVar74 = 0;
        }
        lVar41 = (long)(int)uVar26;
        do {
          iVar25 = *(int *)(lVar32 + uVar74 * 4);
          if (iVar25 < (int)uVar26) {
            uVar42 = 0;
            do {
              uVar65 = uVar42;
              if ((long)uVar44 <= (long)uVar42) {
                uVar65 = uVar44;
              }
              *(int *)(lVar40 + uVar65 * 4) = iVar25;
              uVar65 = uVar45;
              if ((long)uVar42 < lVar41) {
                uVar65 = uVar42 + 1;
              }
              uVar42 = uVar42 + 1;
              iVar25 = *(int *)(lVar32 + uVar65 * 4);
            } while (iVar25 < (int)uVar26);
            iVar25 = (int)uVar42;
          }
          else {
            iVar25 = 0;
            uVar42 = 0;
          }
          if ((int)uVar76 <= iVar25) {
            uVar42 = uVar44;
          }
          *(uint *)(lVar40 + uVar42 * 4) = uVar26;
          uVar42 = (ulong)(iVar25 + 1U);
          if ((int)uVar76 <= (int)(iVar25 + 1U)) {
            uVar42 = uVar44;
          }
          *(uint *)(lVar40 + uVar42 * 4) = uVar26;
          *puVar7 = 0;
          if (0 < (int)uVar26) {
            uVar65 = 0;
            local_94 = 0;
            uVar71 = 0;
            uVar42 = 0;
            puVar64 = puVar7;
            do {
              puVar73 = (undefined8 *)param_1[0x1f];
              iVar25 = *(int *)((long)puVar73 + 0xc);
              uVar58 = (uint)uVar42;
              uVar59 = uVar42;
              uVar63 = local_94;
              if (iVar25 == 8) {
                uVar22 = *(uint *)(puVar73 + 1) >> 1;
                iVar25 = 8;
LAB_183d00054:
                uVar46 = (ulong)(uVar22 & 0x7f);
                sVar16 = *(short *)(twoDimTab1 + uVar46 * 4);
                if (-1 < sVar16) goto LAB_183d0006c;
                uVar31 = (**(code **)(*(long *)*puVar73 + 0x28))();
                __Z5erroriPKcz(uVar31,"Bad two dim code in JBIG2 MMR stream");
                uVar59 = uVar42 & 0xffffffff;
LAB_183d0019c:
                uVar58 = (uint)uVar59;
                if (*(int *)(lVar32 + (long)(int)uVar58 * 4) < (int)uVar26) {
                  uVar58 = (uVar58 & 1) + uVar58;
                  uVar59 = (ulong)uVar58;
                  *(uint *)(lVar32 + (long)(int)uVar58 * 4) = uVar26;
                }
                goto LAB_183d00b54;
              }
              if (iVar25 == 0) {
                uVar22 = (**(code **)(*(long *)*puVar73 + 0x20))();
                iVar25 = 8;
                *(uint *)(puVar73 + 1) = uVar22 & 0xff;
                *(undefined4 *)((long)puVar73 + 0xc) = 8;
                *(int *)(puVar73 + 2) = *(int *)(puVar73 + 2) + 1;
                uVar22 = uVar22 >> 1;
LAB_183d00050:
                uVar59 = uVar42 & 0xffffffff;
                goto LAB_183d00054;
              }
              iVar23 = *(int *)(puVar73 + 1);
              uVar46 = (ulong)(iVar23 << (ulong)(7U - iVar25 & 0x1f) & 0x7f);
              sVar16 = *(short *)(twoDimTab1 + uVar46 * 4);
              if ((sVar16 < 0) || (iVar25 < sVar16)) {
                uVar22 = (**(code **)(*(long *)*puVar73 + 0x20))();
                uVar22 = uVar22 & 0xff | iVar23 << 8;
                *(uint *)(puVar73 + 1) = uVar22;
                iVar23 = (int)*(undefined8 *)((long)puVar73 + 0xc);
                iVar25 = iVar23 + 8;
                *(ulong *)((long)puVar73 + 0xc) =
                     CONCAT44((int)((ulong)*(undefined8 *)((long)puVar73 + 0xc) >> 0x20) + 1,
                              iVar23 + 8);
                uVar22 = uVar22 >> (ulong)(iVar23 + 1U & 0x1f);
                goto LAB_183d00050;
              }
LAB_183d0006c:
              uVar22 = (uint)uVar59;
              *(int *)((long)puVar73 + 0xc) = iVar25 - sVar16;
              uVar15 = *(ushort *)(&DAT_1841d209a + uVar46 * 4);
              uVar29 = (uint)uVar71;
              if (uVar15 < 5) {
                if (uVar15 < 2) {
                  if (uVar15 == 0) {
                    uVar42 = (ulong)(uVar29 + 1);
                    if ((int)uVar76 <= (int)(uVar29 + 1) || (int)uVar29 < -1) {
                      uVar42 = uVar44;
                    }
                    uVar62 = *(uint *)(lVar40 + uVar42 * 4);
                    if (*(int *)(lVar32 + (long)(int)uVar22 * 4) < (int)uVar62) {
                      if ((int)uVar26 < (int)uVar62) {
                        uVar31 = (**(code **)(*param_1 + 0x28))(param_1);
                        __Z5erroriPKcz(uVar31,"JBIG2 MMR row is wrong length ({0:%d})");
                        uVar22 = uVar58;
                        uVar62 = uVar26;
                      }
                      if ((uVar22 & 1) != local_94) {
                        uVar22 = uVar22 + 1;
                      }
                      uVar59 = (ulong)uVar22;
                      *(uint *)(lVar32 + (long)(int)uVar22 * 4) = uVar62;
                      uVar62 = *(uint *)(lVar40 + uVar42 * 4);
                    }
                    uVar58 = uVar29 + 2;
                    if ((int)uVar26 <= (int)uVar62) {
                      uVar58 = uVar29;
                    }
                    uVar71 = (ulong)uVar58;
                  }
                  else {
                    if (uVar15 != 1) goto LAB_183d00538;
                    if (local_94 == 0) {
                      iVar25 = 0;
                      do {
                        iVar23 = __ZN15JBIG2MMRDecoder12getWhiteCodeEv(param_1[0x1f]);
                        iVar25 = iVar23 + iVar25;
                      } while (0x3f < iVar23);
                      iVar23 = 0;
                      do {
                        iVar24 = __ZN15JBIG2MMRDecoder12getBlackCodeEv(param_1[0x1f]);
                        iVar23 = iVar24 + iVar23;
                      } while (0x3f < iVar24);
                    }
                    else {
                      iVar25 = 0;
                      do {
                        iVar23 = __ZN15JBIG2MMRDecoder12getBlackCodeEv(param_1[0x1f]);
                        iVar25 = iVar23 + iVar25;
                      } while (0x3f < iVar23);
                      iVar23 = 0;
                      do {
                        iVar24 = __ZN15JBIG2MMRDecoder12getWhiteCodeEv(param_1[0x1f]);
                        iVar23 = iVar24 + iVar23;
                      } while (0x3f < iVar24);
                    }
                    uVar22 = *puVar64 + iVar25;
                    uVar29 = *(uint *)(lVar32 + (long)(int)uVar58 * 4);
                    if ((int)uVar29 < (int)uVar22) {
                      uVar29 = uVar22;
                      if ((int)uVar26 < (int)uVar22) {
                        uVar31 = (**(code **)(*param_1 + 0x28))(param_1);
                        __Z5erroriPKcz(uVar31,"JBIG2 MMR row is wrong length ({0:%d})");
                        uVar29 = uVar26;
                      }
                      if ((uVar58 & 1) != local_94) {
                        uVar58 = uVar58 + 1;
                      }
                      *(uint *)(lVar32 + (long)(int)uVar58 * 4) = uVar29;
                    }
                    uVar59 = (ulong)uVar58;
                    uVar42 = uVar45;
                    if (uVar58 <= uVar26) {
                      uVar42 = uVar59;
                    }
                    iVar25 = *(int *)(lVar32 + uVar42 * 4);
                    uVar22 = iVar25 + iVar23;
                    if (iVar25 < (int)uVar26 && (int)uVar29 < (int)uVar22) {
                      if ((int)uVar26 < (int)uVar22) {
                        uVar31 = (**(code **)(*param_1 + 0x28))(param_1);
                        __Z5erroriPKcz(uVar31,"JBIG2 MMR row is wrong length ({0:%d})");
                        uVar22 = uVar26;
                      }
                      if ((uVar58 & 1 ^ local_94) != 1) {
                        uVar58 = uVar58 + 1;
                      }
                      uVar59 = (ulong)uVar58;
                      *(uint *)(lVar32 + (long)(int)uVar58 * 4) = uVar22;
                    }
                    uVar42 = uVar45;
                    if ((uint)uVar59 <= uVar26) {
                      uVar42 = uVar59;
                    }
                    uVar65 = uVar71;
                    do {
                      uVar71 = uVar65;
                      uVar65 = uVar71;
                      if (uVar76 <= (uint)uVar71) {
                        uVar65 = uVar44;
                      }
                      iVar25 = *(int *)(lVar40 + uVar65 * 4);
                      uVar65 = (ulong)((uint)uVar71 + 2);
                    } while (iVar25 < (int)uVar26 && iVar25 <= *(int *)(lVar32 + uVar42 * 4));
                  }
                }
                else if (uVar15 == 2) {
                  uVar42 = uVar71;
                  if (uVar76 <= uVar29) {
                    uVar42 = uVar44;
                  }
                  uVar63 = *(uint *)(lVar40 + uVar42 * 4);
                  if (*(int *)(lVar32 + (long)(int)uVar22 * 4) < (int)uVar63) {
                    if ((int)uVar26 < (int)uVar63) {
                      uVar31 = (**(code **)(*param_1 + 0x28))(param_1);
                      __Z5erroriPKcz(uVar31,"JBIG2 MMR row is wrong length ({0:%d})");
                      uVar22 = uVar58;
                      uVar63 = uVar26;
                    }
                    if ((uVar22 & 1) != local_94) {
                      uVar22 = uVar22 + 1;
                    }
                    uVar59 = (ulong)uVar22;
                    *(uint *)(lVar32 + (long)(int)uVar22 * 4) = uVar63;
                  }
                  uVar42 = uVar45;
                  if ((uint)uVar59 <= uVar26) {
                    uVar42 = uVar59 & 0xffffffff;
                  }
                  iVar25 = *(int *)(lVar32 + uVar42 * 4);
                  uVar63 = local_94 ^ 1;
                  if (iVar25 < (int)uVar26) {
                    uVar71 = (ulong)(uVar29 - 1);
                    do {
                      uVar58 = (int)uVar71 + 2;
                      uVar71 = (ulong)uVar58;
                      uVar42 = uVar71;
                      if (uVar76 <= uVar58) {
                        uVar42 = uVar44;
                      }
                    } while (*(int *)(lVar40 + uVar42 * 4) <= iVar25);
                  }
                }
                else if (uVar15 == 3) {
                  uVar42 = uVar71;
                  if (uVar76 <= uVar29) {
                    uVar42 = uVar44;
                  }
                  iVar25 = *(int *)(lVar40 + uVar42 * 4);
                  if (*(int *)(lVar32 + (long)(int)uVar22 * 4) <= iVar25) {
                    uVar63 = iVar25 + 1;
                    if ((int)uVar26 <= iVar25) {
                      uVar31 = (**(code **)(*param_1 + 0x28))(param_1);
                      __Z5erroriPKcz(uVar31,"JBIG2 MMR row is wrong length ({0:%d})");
                      uVar22 = uVar58;
                      uVar63 = uVar26;
                    }
                    if ((uVar22 & 1) != local_94) {
                      uVar22 = uVar22 + 1;
                    }
                    uVar59 = (ulong)uVar22;
                    *(uint *)(lVar32 + (long)(int)uVar22 * 4) = uVar63;
                  }
                  uVar42 = uVar45;
                  if ((uint)uVar59 <= uVar26) {
                    uVar42 = uVar59 & 0xffffffff;
                  }
                  iVar25 = *(int *)(lVar32 + uVar42 * 4);
                  uVar63 = local_94 ^ 1;
                  if (iVar25 < (int)uVar26) {
                    uVar71 = (ulong)(uVar29 - 1);
                    do {
                      uVar58 = (int)uVar71 + 2;
                      uVar71 = (ulong)uVar58;
                      uVar42 = uVar71;
                      if (uVar76 <= uVar58) {
                        uVar42 = uVar44;
                      }
                    } while (*(int *)(lVar40 + uVar42 * 4) <= iVar25);
                    goto LAB_183d007c0;
                  }
                }
                else {
                  if (uVar15 != 4) goto LAB_183d00538;
                  uVar46 = uVar71;
                  if (uVar76 <= uVar29) {
                    uVar46 = uVar44;
                  }
                  iVar25 = *(int *)(lVar40 + uVar46 * 4);
                  uVar63 = iVar25 - 1;
                  iVar23 = *(int *)(lVar32 + (long)(int)uVar22 * 4);
                  if (iVar23 < (int)uVar63) {
                    if ((int)uVar26 < (int)uVar63) {
                      uVar31 = (**(code **)(*param_1 + 0x28))(param_1);
                      __Z5erroriPKcz(uVar31,"JBIG2 MMR row is wrong length ({0:%d})");
                      uVar22 = uVar58;
                      uVar63 = uVar26;
                    }
                    if ((uVar22 & 1) != local_94) {
                      uVar22 = uVar22 + 1;
                    }
                    uVar59 = (ulong)uVar22;
LAB_183d00a60:
                    *(uint *)(lVar32 + (long)(int)uVar22 * 4) = uVar63;
                  }
                  else if (iVar25 <= iVar23) {
                    if (iVar25 < 1) {
                      uVar31 = (**(code **)(*param_1 + 0x28))(param_1);
                      __Z5erroriPKcz(uVar31,"Invalid JBIG2 MMR code");
                      uVar63 = 0;
                      uVar59 = uVar42 & 0xffffffff;
                    }
                    uVar42 = uVar59;
                    if ((0 < (int)uVar59) &&
                       (lVar43 = uVar65 - 1, uVar42 = uVar65,
                       (int)uVar63 <= *(int *)(lVar32 + lVar43 * 4))) {
                      uVar59 = uVar65;
                      do {
                        if (uVar59 < 2) {
                          uVar59 = (ulong)-(uint)(uVar65 == 0);
                          uVar42 = 0;
                          break;
                        }
                        uVar59 = uVar59 - 1;
                        lVar43 = lVar43 + -1;
                        uVar42 = uVar59;
                      } while ((int)uVar63 <= *(int *)(lVar32 + lVar43 * 4));
                    }
                    uVar22 = (uint)uVar42;
                    goto LAB_183d00a60;
                  }
                  uVar42 = uVar45;
                  if ((uint)uVar59 <= uVar26) {
                    uVar42 = uVar59 & 0xffffffff;
                  }
                  iVar25 = *(int *)(lVar32 + uVar42 * 4);
                  uVar63 = local_94 ^ 1;
                  if (iVar25 < (int)uVar26) {
                    uVar58 = uVar29 - 1;
                    if ((int)uVar29 < 1) {
                      uVar58 = uVar29 + 1;
                    }
                    do {
                      uVar42 = (ulong)uVar58;
                      if (uVar76 <= uVar58) {
                        uVar42 = uVar44;
                      }
                      uVar58 = uVar58 + 2;
                    } while (*(int *)(lVar40 + uVar42 * 4) <= iVar25);
                    goto LAB_183d00b50;
                  }
                }
                goto LAB_183d00b54;
              }
              if (uVar15 < 7) {
                if (uVar15 == 5) {
                  uVar42 = uVar71;
                  if (uVar76 <= uVar29) {
                    uVar42 = uVar44;
                  }
                  uVar63 = *(int *)(lVar40 + uVar42 * 4) + 2;
                  if (*(int *)(lVar32 + (long)(int)uVar22 * 4) < (int)uVar63) {
                    if ((int)uVar26 < (int)uVar63) {
                      uVar31 = (**(code **)(*param_1 + 0x28))(param_1);
                      __Z5erroriPKcz(uVar31,"JBIG2 MMR row is wrong length ({0:%d})");
                      uVar22 = uVar58;
                      uVar63 = uVar26;
                    }
                    if ((uVar22 & 1) != local_94) {
                      uVar22 = uVar22 + 1;
                    }
                    uVar59 = (ulong)uVar22;
                    *(uint *)(lVar32 + (long)(int)uVar22 * 4) = uVar63;
                  }
                  uVar42 = uVar45;
                  if ((uint)uVar59 <= uVar26) {
                    uVar42 = uVar59 & 0xffffffff;
                  }
                  iVar25 = *(int *)(lVar32 + uVar42 * 4);
                  uVar63 = local_94 ^ 1;
                  if (iVar25 < (int)uVar26) {
                    uVar71 = (ulong)(uVar29 - 1);
                    do {
                      uVar58 = (int)uVar71 + 2;
                      uVar71 = (ulong)uVar58;
                      uVar42 = uVar71;
                      if (uVar76 <= uVar58) {
                        uVar42 = uVar44;
                      }
                    } while (*(int *)(lVar40 + uVar42 * 4) <= iVar25);
                    goto LAB_183d007c0;
                  }
                  goto LAB_183d00b54;
                }
                if (uVar15 != 6) goto LAB_183d00538;
                uVar46 = uVar71;
                if (uVar76 <= uVar29) {
                  uVar46 = uVar44;
                }
                iVar25 = *(int *)(lVar40 + uVar46 * 4);
                uVar63 = iVar25 - 2;
                iVar23 = *(int *)(lVar32 + (long)(int)uVar22 * 4);
                if (iVar23 < (int)uVar63) {
                  if ((int)uVar26 < (int)uVar63) {
                    uVar31 = (**(code **)(*param_1 + 0x28))(param_1);
                    __Z5erroriPKcz(uVar31,"JBIG2 MMR row is wrong length ({0:%d})");
                    uVar22 = uVar58;
                    uVar63 = uVar26;
                  }
                  if ((uVar22 & 1) != local_94) {
                    uVar22 = uVar22 + 1;
                  }
                  uVar59 = (ulong)uVar22;
LAB_183d00ab4:
                  *(uint *)(lVar32 + (long)(int)uVar22 * 4) = uVar63;
                }
                else if ((int)uVar63 < iVar23) {
                  if (iVar25 < 2) {
                    uVar31 = (**(code **)(*param_1 + 0x28))(param_1);
                    __Z5erroriPKcz(uVar31,"Invalid JBIG2 MMR code");
                    uVar63 = 0;
                    uVar59 = uVar42 & 0xffffffff;
                  }
                  uVar42 = uVar59;
                  if ((0 < (int)uVar59) &&
                     (lVar43 = uVar65 - 1, uVar42 = uVar65,
                     (int)uVar63 <= *(int *)(lVar32 + lVar43 * 4))) {
                    uVar59 = uVar65;
                    do {
                      if (uVar59 < 2) {
                        uVar59 = (ulong)-(uint)(uVar65 == 0);
                        uVar42 = 0;
                        break;
                      }
                      uVar59 = uVar59 - 1;
                      lVar43 = lVar43 + -1;
                      uVar42 = uVar59;
                    } while ((int)uVar63 <= *(int *)(lVar32 + lVar43 * 4));
                  }
                  uVar22 = (uint)uVar42;
                  goto LAB_183d00ab4;
                }
                uVar42 = uVar45;
                if ((uint)uVar59 <= uVar26) {
                  uVar42 = uVar59 & 0xffffffff;
                }
                iVar25 = *(int *)(lVar32 + uVar42 * 4);
                uVar63 = local_94 ^ 1;
                if ((int)uVar26 <= iVar25) goto LAB_183d00b54;
                uVar58 = uVar29 - 1;
                if ((int)uVar29 < 1) {
                  uVar58 = uVar29 + 1;
                }
                do {
                  uVar42 = (ulong)uVar58;
                  if (uVar76 <= uVar58) {
                    uVar42 = uVar44;
                  }
                  uVar58 = uVar58 + 2;
                } while (*(int *)(lVar40 + uVar42 * 4) <= iVar25);
LAB_183d00b50:
                local_94 = local_94 ^ 1;
                uVar71 = (ulong)(uVar58 - 2);
                uVar63 = local_94;
              }
              else if (uVar15 == 7) {
                uVar42 = uVar71;
                if (uVar76 <= uVar29) {
                  uVar42 = uVar44;
                }
                uVar63 = *(int *)(lVar40 + uVar42 * 4) + 3;
                if (*(int *)(lVar32 + (long)(int)uVar22 * 4) < (int)uVar63) {
                  if ((int)uVar26 < (int)uVar63) {
                    uVar31 = (**(code **)(*param_1 + 0x28))(param_1);
                    __Z5erroriPKcz(uVar31,"JBIG2 MMR row is wrong length ({0:%d})");
                    uVar22 = uVar58;
                    uVar63 = uVar26;
                  }
                  if ((uVar22 & 1) != local_94) {
                    uVar22 = uVar22 + 1;
                  }
                  uVar59 = (ulong)uVar22;
                  *(uint *)(lVar32 + (long)(int)uVar22 * 4) = uVar63;
                }
                uVar42 = uVar45;
                if ((uint)uVar59 <= uVar26) {
                  uVar42 = uVar59 & 0xffffffff;
                }
                iVar25 = *(int *)(lVar32 + uVar42 * 4);
                uVar63 = local_94 ^ 1;
                if (iVar25 < (int)uVar26) {
                  uVar71 = (ulong)(uVar29 - 1);
                  do {
                    uVar58 = (int)uVar71 + 2;
                    uVar71 = (ulong)uVar58;
                    uVar42 = uVar71;
                    if (uVar76 <= uVar58) {
                      uVar42 = uVar44;
                    }
                  } while (*(int *)(lVar40 + uVar42 * 4) <= iVar25);
LAB_183d007c0:
                  local_94 = local_94 ^ 1;
                  uVar63 = local_94;
                }
              }
              else if (uVar15 == 8) {
                uVar46 = uVar71;
                if (uVar76 <= uVar29) {
                  uVar46 = uVar44;
                }
                iVar25 = *(int *)(lVar40 + uVar46 * 4);
                uVar63 = iVar25 - 3;
                iVar23 = *(int *)(lVar32 + (long)(int)uVar22 * 4);
                if (iVar23 < (int)uVar63) {
                  if ((int)uVar26 < (int)uVar63) {
                    uVar31 = (**(code **)(*param_1 + 0x28))(param_1);
                    __Z5erroriPKcz(uVar31,"JBIG2 MMR row is wrong length ({0:%d})");
                    uVar22 = uVar58;
                    uVar63 = uVar26;
                  }
                  if ((uVar22 & 1) != local_94) {
                    uVar22 = uVar22 + 1;
                  }
                  uVar59 = (ulong)uVar22;
LAB_183d00b08:
                  *(uint *)(lVar32 + (long)(int)uVar22 * 4) = uVar63;
                }
                else if ((int)uVar63 < iVar23) {
                  if (iVar25 < 3) {
                    uVar31 = (**(code **)(*param_1 + 0x28))(param_1);
                    __Z5erroriPKcz(uVar31,"Invalid JBIG2 MMR code");
                    uVar63 = 0;
                    uVar59 = uVar42 & 0xffffffff;
                  }
                  uVar42 = uVar59;
                  if ((0 < (int)uVar59) &&
                     (lVar43 = uVar65 - 1, uVar42 = uVar65,
                     (int)uVar63 <= *(int *)(lVar32 + lVar43 * 4))) {
                    uVar59 = uVar65;
                    do {
                      if (uVar59 < 2) {
                        uVar59 = (ulong)-(uint)(uVar65 == 0);
                        uVar42 = 0;
                        break;
                      }
                      uVar59 = uVar59 - 1;
                      lVar43 = lVar43 + -1;
                      uVar42 = uVar59;
                    } while ((int)uVar63 <= *(int *)(lVar32 + lVar43 * 4));
                  }
                  uVar22 = (uint)uVar42;
                  goto LAB_183d00b08;
                }
                uVar42 = uVar45;
                if ((uint)uVar59 <= uVar26) {
                  uVar42 = uVar59 & 0xffffffff;
                }
                iVar25 = *(int *)(lVar32 + uVar42 * 4);
                uVar63 = local_94 ^ 1;
                if (iVar25 < (int)uVar26) {
                  uVar58 = uVar29 - 1;
                  if ((int)uVar29 < 1) {
                    uVar58 = uVar29 + 1;
                  }
                  do {
                    uVar42 = (ulong)uVar58;
                    if (uVar76 <= uVar58) {
                      uVar42 = uVar44;
                    }
                    uVar58 = uVar58 + 2;
                  } while (*(int *)(lVar40 + uVar42 * 4) <= iVar25);
                  goto LAB_183d00b50;
                }
              }
              else {
                if (uVar15 == 0xffff) goto LAB_183d0019c;
LAB_183d00538:
                uVar31 = (**(code **)(*param_1 + 0x28))(param_1);
                __Z5erroriPKcz(uVar31,"Illegal code in JBIG2 MMR bitmap data");
                if (*(int *)(lVar32 + (long)(int)uVar58 * 4) < (int)uVar26) {
                  uVar58 = (uVar58 & 1) + uVar58;
                  *(uint *)(lVar32 + (long)(int)uVar58 * 4) = uVar26;
                }
                uVar59 = (ulong)uVar58;
              }
LAB_183d00b54:
              local_94 = uVar63;
              uVar65 = uVar59 & 0xffffffff;
              uVar42 = uVar45;
              if ((uint)uVar59 <= uVar26) {
                uVar42 = uVar65;
              }
              puVar64 = (uint *)(lVar32 + uVar42 * 4);
              uVar42 = uVar59;
            } while ((int)*puVar64 < (int)uVar26);
          }
          uVar42 = 0;
          do {
            uVar65 = uVar45;
            if ((long)uVar42 <= lVar41) {
              uVar65 = uVar42;
            }
            iVar25 = *(int *)(lVar32 + uVar65 * 4);
            uVar65 = uVar45;
            if ((long)uVar42 < lVar41) {
              uVar65 = uVar42 + 1;
            }
            iVar23 = *(int *)(lVar32 + uVar65 * 4);
            if (iVar25 < (int)uVar26 && iVar25 < iVar23) {
              do {
                __ZN11JBIG2Bitmap8setPixelEii(plVar30,iVar25,uVar52);
                iVar25 = iVar25 + 1;
                iVar23 = *(int *)(lVar32 + uVar65 * 4);
                if ((int)uVar26 <= iVar25) break;
              } while (iVar25 < iVar23);
            }
            if ((int)uVar26 <= iVar23) break;
            uVar42 = uVar42 + 2;
            uVar65 = uVar45;
            if ((int)uVar42 <= (int)uVar26) {
              uVar65 = uVar42;
            }
          } while (*(int *)(lVar32 + uVar65 * 4) < (int)uVar26);
          uVar52 = uVar52 + 1;
        } while (uVar52 != uVar38);
      }
      puVar73 = (undefined8 *)param_1[0x1f];
      if ((int)param_11 < 0) {
        uVar38 = *(uint *)(puVar73 + 1);
        uVar26 = *(uint *)((long)puVar73 + 0xc);
        while (uVar26 < 0x18) {
          uVar26 = (**(code **)(*(long *)*puVar73 + 0x20))();
          uVar38 = uVar26 & 0xff | uVar38 << 8;
          *(uint *)(puVar73 + 1) = uVar38;
          uVar26 = (int)*(undefined8 *)((long)puVar73 + 0xc) + 8;
          *(ulong *)((long)puVar73 + 0xc) =
               CONCAT44((int)((ulong)*(undefined8 *)((long)puVar73 + 0xc) >> 0x20) + 1,uVar26);
        }
        if ((uVar38 >> (ulong)(uVar26 - 0x18 & 0x1f) & 0xffffff) != 0x1001) {
          uVar31 = (**(code **)(*param_1 + 0x28))(param_1);
          __Z5erroriPKcz(uVar31,"Missing EOFB in JBIG2 MMR bitmap data");
        }
      }
      else {
        uVar38 = *(uint *)(puVar73 + 2);
        while ((uVar38 < param_11 &&
               (iVar25 = (**(code **)(*(long *)*puVar73 + 0x20))(), iVar25 != -1))) {
          uVar38 = *(int *)(puVar73 + 2) + 1;
          *(uint *)(puVar73 + 2) = uVar38;
        }
      }
      if (lVar40 != 0) {
        func_0x000188138390(lVar40);
      }
LAB_183d00d9c:
      func_0x000188138390(lVar32);
      return plVar30;
    }
    if ((param_6 != 0 || param_5 != 0) || param_7 != 0) {
      if (param_6 == 0) {
        uVar8 = 0;
      }
      else {
        uVar8 = *(undefined4 *)(&DAT_184265950 + (ulong)param_5 * 4);
      }
      if ((int)uVar38 < 1) {
        return plVar30;
      }
      uVar26 = 0;
      bVar20 = false;
      bVar19 = false;
      plVar6 = plVar30 + 6;
      uVar44 = (ulong)(plVar30 + 4) & 0xffffffffffff | 0x5363000000000000;
      do {
        if (param_6 == 0) {
LAB_183d00e48:
          uVar45 = (ulong)(plVar30 + 2) & 0xffffffffffff | 0x5363000000000000;
          if ((int)param_5 < 2) {
            if (param_5 == 0) {
              if (uVar26 < 2) {
                if (uVar26 != 0) {
                  iVar23 = (int)plVar30[4];
                  lVar40 = pacga((long)iVar23,uVar44);
                  if (lVar40 != plVar30[5]) goto LAB_183d02eac;
                  iVar24 = 0;
                  uVar52 = 0;
                  pbVar35 = (byte *)0x0;
                  uVar76 = 0;
                  goto LAB_183d01644;
                }
                iVar24 = 0;
                uVar52 = 0;
                pbVar35 = (byte *)0x0;
                uVar76 = 0;
LAB_183d016a0:
                uVar63 = 0;
                uVar29 = 0;
                pbVar37 = (byte *)0x0;
                uVar22 = 0;
                iVar23 = 0;
                uVar58 = 0;
              }
              else {
                iVar23 = (int)plVar30[4];
                lVar40 = pacga((long)iVar23,uVar44);
                if (lVar40 != plVar30[5]) goto LAB_183d02eac;
                if ((int)((long)(int)uVar26 + -2) < iVar23) {
                  iVar24 = (int)plVar30[2];
                  lVar40 = pacga((long)iVar24,uVar45);
                  if (lVar40 != plVar30[3]) goto LAB_183d02eac;
                  if (0 < iVar24) {
                    lVar40 = *plVar39;
                    if (lVar40 == 0) {
                      lVar40 = 0;
                    }
                    lVar32 = pacga((long)(int)plVar30[6],
                                   (ulong)plVar6 & 0xffffffffffff | 0x5363000000000000);
                    if (lVar32 != plVar30[7]) goto LAB_183d02eac;
                    pbVar37 = (byte *)(lVar40 + (long)(int)plVar30[6] * ((long)(int)uVar26 + -2));
                    if (lVar40 == 0) {
                      iVar24 = 0;
                      uVar76 = 0;
                    }
                    else {
                      bVar9 = *pbVar37;
                      bVar10 = bVar9 >> 7;
                      uVar76 = (uint)bVar10;
                      if (iVar24 != 1) {
                        uVar52 = 5;
                        if (iVar24 == 2) {
                          uVar52 = 6;
                        }
                        pbVar35 = (byte *)0x0;
                        if (iVar24 != 2) {
                          pbVar35 = pbVar37;
                        }
                        uVar76 = bVar9 >> 6 & 1 | (uint)bVar10 << 1;
                        iVar24 = 2;
                        goto LAB_183d01644;
                      }
                      iVar24 = 1;
                    }
                    pbVar35 = (byte *)0x0;
                    uVar76 = uVar76 << 1;
                    uVar52 = 7;
                    goto LAB_183d01644;
                  }
                }
                uVar76 = 0;
                pbVar35 = (byte *)0x0;
                uVar52 = 0;
                iVar24 = 0;
LAB_183d01644:
                if (iVar23 < (int)uVar26) goto LAB_183d016a0;
                iVar23 = (int)plVar30[2];
                lVar40 = pacga((long)iVar23,uVar45);
                if (lVar40 != plVar30[3]) goto LAB_183d02eac;
                if (iVar23 < 1) goto LAB_183d016a0;
                lVar40 = *plVar39;
                if (lVar40 == 0) {
                  lVar40 = 0;
                }
                lVar32 = pacga((long)(int)plVar30[6],
                               (ulong)plVar6 & 0xffffffffffff | 0x5363000000000000);
                if (lVar32 != plVar30[7]) goto LAB_183d02eac;
                pbVar37 = (byte *)(lVar40 + (long)(int)plVar30[6] * (long)(int)(uVar26 - 1));
                if (lVar40 == 0) {
                  uVar29 = 0;
                  pbVar37 = (byte *)0x0;
                  iVar23 = 0;
                  uVar22 = 7;
                  uVar63 = 0;
                  uVar58 = 0;
                }
                else {
                  bVar9 = *pbVar37;
                  uVar29 = (uint)(bVar9 >> 7);
                  pbVar66 = (byte *)0x0;
                  if (iVar23 != 3) {
                    pbVar66 = pbVar37;
                  }
                  uVar58 = 4;
                  if (iVar23 == 3) {
                    uVar58 = 5;
                  }
                  bVar21 = iVar23 != 2;
                  pbVar70 = (byte *)0x0;
                  if (bVar21) {
                    pbVar70 = pbVar66;
                  }
                  uVar62 = 6;
                  if (bVar21) {
                    uVar62 = uVar58;
                  }
                  iVar27 = 2;
                  if (bVar21) {
                    iVar27 = 3;
                  }
                  uVar54 = 0;
                  if (bVar21) {
                    uVar54 = bVar9 >> 5 & 1;
                  }
                  bVar21 = iVar23 != 1;
                  uVar63 = 0;
                  if (bVar21) {
                    uVar63 = bVar9 >> 6 & 1;
                  }
                  pbVar37 = (byte *)0x0;
                  if (bVar21) {
                    pbVar37 = pbVar70;
                  }
                  uVar22 = 7;
                  if (bVar21) {
                    uVar22 = uVar62;
                  }
                  iVar23 = 1;
                  if (bVar21) {
                    iVar23 = iVar27;
                  }
                  uVar58 = 0;
                  if (bVar21) {
                    uVar58 = uVar54;
                  }
                }
              }
              lVar40 = (long)*(int *)*param_10 + (long)(int)uVar26;
              iVar27 = (int)lVar40;
              if (iVar27 < 0) {
LAB_183d01764:
                pbVar66 = (byte *)0x0;
                uVar54 = 0;
                uVar62 = 0;
              }
              else {
                lVar32 = pacga((long)(int)plVar30[4],uVar44);
                if (lVar32 != plVar30[5]) goto LAB_183d02eac;
                if ((int)plVar30[4] <= iVar27) goto LAB_183d01764;
                lVar32 = pacga((long)(int)plVar30[2],uVar45);
                if (lVar32 != plVar30[3]) goto LAB_183d02eac;
                uVar62 = *param_9;
                if ((int)plVar30[2] <= (int)uVar62) goto LAB_183d01764;
                if ((int)uVar62 < 0) {
                  lVar32 = pacga((long)(int)plVar30[6],
                                 (ulong)plVar6 & 0xffffffffffff | 0x5363000000000000);
                  if (lVar32 != plVar30[7]) goto LAB_183d02eac;
                  lVar40 = (int)plVar30[6] * lVar40;
                  uVar54 = 7;
                }
                else {
                  lVar40 = pacga((long)(int)plVar30[6],
                                 (ulong)plVar6 & 0xffffffffffff | 0x5363000000000000);
                  if (lVar40 != plVar30[7]) goto LAB_183d02eac;
                  lVar40 = (long)(int)((int)plVar30[6] * iVar27 + (uVar62 >> 3));
                  uVar54 = (uVar62 ^ 0xffffffff) & 7;
                }
                pbVar66 = (byte *)(*plVar39 + lVar40);
              }
              lVar40 = (long)*(int *)(*param_10 + 4) + (long)(int)uVar26;
              iVar27 = (int)lVar40;
              if (iVar27 < 0) {
LAB_183d01820:
                pbVar70 = (byte *)0x0;
                uVar55 = 0;
                uVar33 = 0;
              }
              else {
                lVar32 = pacga((long)(int)plVar30[4],uVar44);
                if (lVar32 != plVar30[5]) goto LAB_183d02eac;
                if ((int)plVar30[4] <= iVar27) goto LAB_183d01820;
                lVar32 = pacga((long)(int)plVar30[2],uVar45);
                if (lVar32 != plVar30[3]) goto LAB_183d02eac;
                uVar33 = param_9[1];
                if ((int)plVar30[2] <= (int)uVar33) goto LAB_183d01820;
                if ((int)uVar33 < 0) {
                  lVar32 = pacga((long)(int)plVar30[6],
                                 (ulong)plVar6 & 0xffffffffffff | 0x5363000000000000);
                  if (lVar32 != plVar30[7]) goto LAB_183d02eac;
                  lVar40 = (int)plVar30[6] * lVar40;
                  uVar55 = 7;
                }
                else {
                  lVar40 = pacga((long)(int)plVar30[6],
                                 (ulong)plVar6 & 0xffffffffffff | 0x5363000000000000);
                  if (lVar40 != plVar30[7]) goto LAB_183d02eac;
                  lVar40 = (long)(int)((int)plVar30[6] * iVar27 + (uVar33 >> 3));
                  uVar55 = (uVar33 ^ 0xffffffff) & 7;
                }
                pbVar70 = (byte *)(*plVar39 + lVar40);
              }
              lVar40 = (long)*(int *)(*param_10 + 8) + (long)(int)uVar26;
              iVar27 = (int)lVar40;
              if (iVar27 < 0) {
LAB_183d018dc:
                pbVar75 = (byte *)0x0;
                uVar56 = 0;
                uVar72 = 0;
              }
              else {
                lVar32 = pacga((long)(int)plVar30[4],uVar44);
                if (lVar32 != plVar30[5]) goto LAB_183d02eac;
                if ((int)plVar30[4] <= iVar27) goto LAB_183d018dc;
                lVar32 = pacga((long)(int)plVar30[2],uVar45);
                if (lVar32 != plVar30[3]) goto LAB_183d02eac;
                uVar72 = param_9[2];
                if ((int)plVar30[2] <= (int)uVar72) goto LAB_183d018dc;
                if ((int)uVar72 < 0) {
                  lVar32 = pacga((long)(int)plVar30[6],
                                 (ulong)plVar6 & 0xffffffffffff | 0x5363000000000000);
                  if (lVar32 != plVar30[7]) goto LAB_183d02eac;
                  lVar40 = (int)plVar30[6] * lVar40;
                  uVar56 = 7;
                }
                else {
                  lVar40 = pacga((long)(int)plVar30[6],
                                 (ulong)plVar6 & 0xffffffffffff | 0x5363000000000000);
                  if (lVar40 != plVar30[7]) goto LAB_183d02eac;
                  lVar40 = (long)(int)((int)plVar30[6] * iVar27 + (uVar72 >> 3));
                  uVar56 = (uVar72 ^ 0xffffffff) & 7;
                }
                pbVar75 = (byte *)(*plVar39 + lVar40);
              }
              lVar40 = (long)*(int *)(*param_10 + 0xc) + (long)(int)uVar26;
              iVar27 = (int)lVar40;
              if (iVar27 < 0) {
LAB_183d0199c:
                pbVar68 = (byte *)0x0;
                uVar57 = 0;
                local_fc = 0;
              }
              else {
                lVar32 = pacga((long)(int)plVar30[4],uVar44);
                if (lVar32 != plVar30[5]) {
LAB_183d02eac:
                  plVar30 = (long *)func_0x000188138260();
                  return plVar30;
                }
                if ((int)plVar30[4] <= iVar27) goto LAB_183d0199c;
                lVar32 = pacga((long)(int)plVar30[2],uVar45);
                if (lVar32 != plVar30[3]) goto LAB_183d02eac;
                local_fc = param_9[3];
                if ((int)plVar30[2] <= (int)local_fc) goto LAB_183d0199c;
                if ((int)local_fc < 0) {
                  lVar32 = pacga((long)(int)plVar30[6],
                                 (ulong)plVar6 & 0xffffffffffff | 0x5363000000000000);
                  if (lVar32 != plVar30[7]) goto LAB_183d02eac;
                  lVar40 = (int)plVar30[6] * lVar40;
                  uVar57 = 7;
                }
                else {
                  lVar40 = pacga((long)(int)plVar30[6],
                                 (ulong)plVar6 & 0xffffffffffff | 0x5363000000000000);
                  if (lVar40 != plVar30[7]) goto LAB_183d02eac;
                  lVar40 = (long)(int)((int)plVar30[6] * iVar27 + (local_fc >> 3));
                  uVar57 = (local_fc ^ 0xffffffff) & 7;
                }
                pbVar68 = (byte *)(*plVar39 + lVar40);
              }
              if (0 < iVar25) {
                iVar27 = 0;
                uVar61 = 0;
                uVar58 = uVar58 | uVar63 << 1 | uVar29 << 2;
                do {
                  if (pbVar66 == (byte *)0x0) {
joined_r0x000183d01a2c:
                    uVar63 = 0;
                    if (pbVar70 == (byte *)0x0) goto joined_r0x000183d01aa0;
LAB_183d01a30:
                    if ((int)uVar33 < 0) {
                      uVar33 = uVar33 + 1;
                      goto joined_r0x000183d01aa0;
                    }
                    lVar40 = pacga((long)(int)*(uint *)(plVar30 + 2),uVar45);
                    if (lVar40 != plVar30[3]) goto LAB_183d02eac;
                    uVar29 = *pbVar70 >> (ulong)(uVar55 & 0x1f) & 1;
                    uVar33 = uVar33 + 1;
                    uVar67 = uVar55 - 1;
                    if (uVar55 == 0) {
                      pbVar70 = pbVar70 + 1;
                      uVar67 = 7;
                    }
                    pbVar36 = (byte *)0x0;
                    if (uVar33 != *(uint *)(plVar30 + 2)) {
                      uVar55 = uVar67;
                      pbVar36 = pbVar70;
                    }
                    pbVar70 = pbVar36;
                    if (pbVar75 != (byte *)0x0) goto LAB_183d01aa4;
LAB_183d01b0c:
                    uVar67 = 0;
                  }
                  else {
                    if ((int)uVar62 < 0) {
                      uVar62 = uVar62 + 1;
                      goto joined_r0x000183d01a2c;
                    }
                    lVar40 = pacga((long)(int)*(uint *)(plVar30 + 2),uVar45);
                    if (lVar40 != plVar30[3]) goto LAB_183d02eac;
                    uVar63 = *pbVar66 >> (ulong)(uVar54 & 0x1f) & 1;
                    uVar62 = uVar62 + 1;
                    uVar29 = uVar54 - 1;
                    if (uVar54 == 0) {
                      pbVar66 = pbVar66 + 1;
                      uVar29 = 7;
                    }
                    pbVar36 = (byte *)0x0;
                    if (uVar62 != *(uint *)(plVar30 + 2)) {
                      uVar54 = uVar29;
                      pbVar36 = pbVar66;
                    }
                    pbVar66 = pbVar36;
                    if (pbVar70 != (byte *)0x0) goto LAB_183d01a30;
joined_r0x000183d01aa0:
                    uVar29 = 0;
                    if (pbVar75 == (byte *)0x0) goto LAB_183d01b0c;
LAB_183d01aa4:
                    if ((int)uVar72 < 0) {
                      uVar67 = 0;
                      uVar72 = uVar72 + 1;
                    }
                    else {
                      lVar40 = pacga((long)(int)*(uint *)(plVar30 + 2),uVar45);
                      if (lVar40 != plVar30[3]) goto LAB_183d02eac;
                      uVar67 = *pbVar75 >> (ulong)(uVar56 & 0x1f) & 1;
                      uVar72 = uVar72 + 1;
                      uVar69 = uVar56 - 1;
                      pbVar36 = pbVar75;
                      if (uVar56 == 0) {
                        pbVar36 = pbVar75 + 1;
                        uVar69 = 7;
                      }
                      pbVar75 = (byte *)0x0;
                      if (uVar72 != *(uint *)(plVar30 + 2)) {
                        pbVar75 = pbVar36;
                        uVar56 = uVar69;
                      }
                    }
                  }
                  if (pbVar68 == (byte *)0x0) {
                    uVar69 = 0;
                  }
                  else if ((int)local_fc < 0) {
                    uVar69 = 0;
                    local_fc = local_fc + 1;
                  }
                  else {
                    lVar40 = pacga((long)(int)*(uint *)(plVar30 + 2),uVar45);
                    if (lVar40 != plVar30[3]) goto LAB_183d02eac;
                    uVar69 = *pbVar68 >> (ulong)(uVar57 & 0x1f) & 1;
                    local_fc = local_fc + 1;
                    uVar17 = uVar57 - 1;
                    pbVar36 = pbVar68;
                    if (uVar57 == 0) {
                      pbVar36 = pbVar68 + 1;
                      uVar17 = 7;
                    }
                    pbVar68 = (byte *)0x0;
                    if (local_fc != *(uint *)(plVar30 + 2)) {
                      pbVar68 = pbVar36;
                      uVar57 = uVar17;
                    }
                  }
                  if ((param_7 == 0) ||
                     (iVar28 = __ZN11JBIG2Bitmap8getPixelEii(param_8,iVar27,uVar26), iVar28 == 0)) {
                    iVar28 = __ZN18JArithmeticDecoder9decodeBitEjP23JArithmeticDecoderStats
                                       (param_1[0xd],
                                        uVar69 | uVar76 << 0xd | uVar58 << 8 | uVar61 << 4 |
                                                 uVar63 << 3 | uVar29 << 2 | uVar67 << 1,
                                        param_1[0xe]);
                    if (iVar28 != 0) {
                      __ZN11JBIG2Bitmap8setPixelEii(plVar30,iVar27,uVar26);
                    }
                    uVar63 = (uint)(iVar28 != 0);
                  }
                  else {
                    uVar63 = 0;
                  }
                  if (pbVar35 == (byte *)0x0) {
joined_r0x000183d01cec:
                    uVar29 = 0;
                    pbVar36 = pbVar35;
                    if (pbVar37 != (byte *)0x0) goto LAB_183d01cf0;
LAB_183d01d58:
                    uVar67 = 0;
                    pbVar35 = pbVar36;
                  }
                  else {
                    if (iVar24 < 0) {
                      iVar24 = iVar24 + 1;
                      goto joined_r0x000183d01cec;
                    }
                    iVar28 = (int)plVar30[2];
                    lVar40 = pacga((long)iVar28,uVar45);
                    if (lVar40 != plVar30[3]) goto LAB_183d02eac;
                    uVar29 = *pbVar35 >> (ulong)(uVar52 & 0x1f) & 1;
                    iVar24 = iVar24 + 1;
                    uVar67 = uVar52 - 1;
                    if (uVar52 == 0) {
                      uVar67 = 7;
                      pbVar35 = pbVar35 + 1;
                    }
                    if (iVar24 != iVar28) {
                      uVar52 = uVar67;
                    }
                    pbVar36 = (byte *)0x0;
                    if (iVar24 != iVar28) {
                      pbVar36 = pbVar35;
                    }
                    pbVar35 = pbVar36;
                    if (pbVar37 == (byte *)0x0) goto LAB_183d01d58;
LAB_183d01cf0:
                    if (iVar23 < 0) {
                      uVar67 = 0;
                      iVar23 = iVar23 + 1;
                    }
                    else {
                      lVar40 = pacga((long)(int)plVar30[2],uVar45);
                      if (lVar40 != plVar30[3]) goto LAB_183d02eac;
                      uVar67 = *pbVar37 >> (ulong)(uVar22 & 0x1f) & 1;
                      iVar23 = iVar23 + 1;
                      uVar69 = uVar22 - 1;
                      pbVar36 = pbVar37;
                      if (uVar22 == 0) {
                        pbVar36 = pbVar37 + 1;
                        uVar69 = 7;
                      }
                      pbVar37 = (byte *)0x0;
                      if (iVar23 != (int)plVar30[2]) {
                        pbVar37 = pbVar36;
                        uVar22 = uVar69;
                      }
                    }
                  }
                  uVar76 = uVar29 | (uVar76 & 3) << 1;
                  uVar58 = uVar67 | (uVar58 & 0xf) << 1;
                  uVar61 = uVar63 | (uVar61 & 7) << 1;
                  iVar27 = iVar27 + 1;
                } while (iVar25 != iVar27);
              }
            }
            else {
              if (uVar26 < 2) {
                if (uVar26 != 0) {
                  iVar23 = (int)plVar30[4];
                  lVar40 = pacga((long)iVar23,uVar44);
                  if (lVar40 != plVar30[5]) goto LAB_183d02eac;
                  iVar27 = 0;
                  local_bc = 0;
                  pbVar35 = (byte *)0x0;
                  uVar76 = 0;
                  goto LAB_183d02440;
                }
                iVar27 = 0;
                local_bc = 0;
                pbVar35 = (byte *)0x0;
                uVar76 = 0;
LAB_183d0249c:
                uVar58 = 0;
                uVar22 = 0;
                pbVar37 = (byte *)0x0;
                uVar63 = 0;
                iVar23 = 0;
                uVar52 = 0;
              }
              else {
                iVar23 = (int)plVar30[4];
                lVar40 = pacga((long)iVar23,uVar44);
                if (lVar40 != plVar30[5]) goto LAB_183d02eac;
                if ((int)((long)(int)uVar26 + -2) < iVar23) {
                  iVar24 = (int)plVar30[2];
                  lVar40 = pacga((long)iVar24,uVar45);
                  if (lVar40 != plVar30[3]) goto LAB_183d02eac;
                  if (0 < iVar24) {
                    lVar40 = *plVar39;
                    if (lVar40 == 0) {
                      lVar40 = 0;
                    }
                    lVar32 = pacga((long)(int)plVar30[6],
                                   (ulong)plVar6 & 0xffffffffffff | 0x5363000000000000);
                    if (lVar32 != plVar30[7]) goto LAB_183d02eac;
                    pbVar37 = (byte *)(lVar40 + (long)(int)plVar30[6] * ((long)(int)uVar26 + -2));
                    if (lVar40 == 0) {
                      iVar27 = 0;
                      uVar76 = 0;
                    }
                    else {
                      bVar9 = *pbVar37;
                      uVar76 = (uint)(bVar9 >> 7);
                      if (iVar24 != 1) {
                        local_bc = 4;
                        if (iVar24 == 3) {
                          local_bc = 5;
                        }
                        pbVar35 = (byte *)0x0;
                        if (iVar24 != 3) {
                          pbVar35 = pbVar37;
                        }
                        uVar52 = (uint)(bVar9 >> 7) << 2 | (bVar9 >> 6 & 1) << 1;
                        uVar76 = uVar52 | bVar9 >> 5 & 1;
                        if (iVar24 == 2) {
                          pbVar35 = (byte *)0x0;
                          local_bc = 6;
                          uVar76 = uVar52;
                        }
                        iVar27 = 3;
                        if (iVar24 == 2) {
                          iVar27 = 2;
                        }
                        goto LAB_183d02440;
                      }
                      iVar27 = 1;
                    }
                    pbVar35 = (byte *)0x0;
                    uVar76 = uVar76 << 2;
                    local_bc = 7;
                    goto LAB_183d02440;
                  }
                }
                uVar76 = 0;
                pbVar35 = (byte *)0x0;
                local_bc = 0;
                iVar27 = 0;
LAB_183d02440:
                if (iVar23 < (int)uVar26) goto LAB_183d0249c;
                iVar23 = (int)plVar30[2];
                lVar40 = pacga((long)iVar23,uVar45);
                if (lVar40 != plVar30[3]) goto LAB_183d02eac;
                if (iVar23 < 1) goto LAB_183d0249c;
                lVar40 = *plVar39;
                if (lVar40 == 0) {
                  lVar40 = 0;
                }
                lVar32 = pacga((long)(int)plVar30[6],
                               (ulong)plVar6 & 0xffffffffffff | 0x5363000000000000);
                if (lVar32 != plVar30[7]) goto LAB_183d02eac;
                pbVar37 = (byte *)(lVar40 + (long)(int)plVar30[6] * (long)(int)(uVar26 - 1));
                if (lVar40 == 0) {
                  uVar22 = 0;
                  pbVar37 = (byte *)0x0;
                  iVar23 = 0;
                  uVar63 = 7;
                  uVar58 = 0;
                  uVar52 = 0;
                }
                else {
                  bVar9 = *pbVar37;
                  uVar22 = (uint)(bVar9 >> 7);
                  pbVar66 = (byte *)0x0;
                  if (iVar23 != 3) {
                    pbVar66 = pbVar37;
                  }
                  uVar52 = 4;
                  if (iVar23 == 3) {
                    uVar52 = 5;
                  }
                  bVar21 = iVar23 != 2;
                  pbVar70 = (byte *)0x0;
                  if (bVar21) {
                    pbVar70 = pbVar66;
                  }
                  uVar29 = 6;
                  if (bVar21) {
                    uVar29 = uVar52;
                  }
                  iVar24 = 2;
                  if (bVar21) {
                    iVar24 = 3;
                  }
                  uVar62 = 0;
                  if (bVar21) {
                    uVar62 = bVar9 >> 5 & 1;
                  }
                  bVar21 = iVar23 != 1;
                  uVar58 = 0;
                  if (bVar21) {
                    uVar58 = bVar9 >> 6 & 1;
                  }
                  pbVar37 = (byte *)0x0;
                  if (bVar21) {
                    pbVar37 = pbVar70;
                  }
                  uVar63 = 7;
                  if (bVar21) {
                    uVar63 = uVar29;
                  }
                  iVar23 = 1;
                  if (bVar21) {
                    iVar23 = iVar24;
                  }
                  uVar52 = 0;
                  if (bVar21) {
                    uVar52 = uVar62;
                  }
                }
              }
              lVar40 = (long)*(int *)*param_10 + (long)(int)uVar26;
              iVar24 = (int)lVar40;
              if (iVar24 < 0) {
LAB_183d02570:
                pbVar66 = (byte *)0x0;
                uVar62 = 0;
                uVar29 = 0;
              }
              else {
                lVar32 = pacga((long)(int)plVar30[4],uVar44);
                if (lVar32 != plVar30[5]) goto LAB_183d02eac;
                if ((int)plVar30[4] <= iVar24) goto LAB_183d02570;
                lVar32 = pacga((long)(int)plVar30[2],uVar45);
                if (lVar32 != plVar30[3]) goto LAB_183d02eac;
                uVar29 = *param_9;
                if ((int)plVar30[2] <= (int)uVar29) goto LAB_183d02570;
                if ((int)uVar29 < 0) {
                  lVar32 = pacga((long)(int)plVar30[6],
                                 (ulong)plVar6 & 0xffffffffffff | 0x5363000000000000);
                  if (lVar32 != plVar30[7]) goto LAB_183d02eac;
                  pbVar66 = (byte *)(*plVar39 + (int)plVar30[6] * lVar40);
                  uVar62 = 7;
                }
                else {
                  lVar40 = pacga((long)(int)plVar30[6],
                                 (ulong)plVar6 & 0xffffffffffff | 0x5363000000000000);
                  if (lVar40 != plVar30[7]) goto LAB_183d02eac;
                  pbVar66 = (byte *)(*plVar39 +
                                    (long)(int)((int)plVar30[6] * iVar24 + (uVar29 >> 3)));
                  uVar62 = (uVar29 ^ 0xffffffff) & 7;
                }
              }
              if (0 < iVar25) {
                iVar24 = 0;
                uVar54 = 0;
                uVar52 = uVar52 | uVar58 << 1 | uVar22 << 2;
                do {
                  if (pbVar66 == (byte *)0x0) {
                    uVar58 = 0;
                    pbVar66 = (byte *)0x0;
                  }
                  else if ((int)uVar29 < 0) {
                    uVar58 = 0;
                    uVar29 = uVar29 + 1;
                  }
                  else {
                    lVar40 = pacga((long)(int)*(uint *)(plVar30 + 2),uVar45);
                    if (lVar40 != plVar30[3]) goto LAB_183d02eac;
                    uVar58 = *pbVar66 >> (ulong)(uVar62 & 0x1f) & 1;
                    uVar29 = uVar29 + 1;
                    uVar22 = uVar62 - 1;
                    pbVar70 = pbVar66;
                    if (uVar62 == 0) {
                      pbVar70 = pbVar66 + 1;
                      uVar22 = 7;
                    }
                    pbVar66 = (byte *)0x0;
                    if (uVar29 != *(uint *)(plVar30 + 2)) {
                      pbVar66 = pbVar70;
                      uVar62 = uVar22;
                    }
                  }
                  if ((param_7 == 0) ||
                     (iVar28 = __ZN11JBIG2Bitmap8getPixelEii(param_8,iVar24,uVar26), iVar28 == 0)) {
                    iVar28 = __ZN18JArithmeticDecoder9decodeBitEjP23JArithmeticDecoderStats
                                       (param_1[0xd],
                                        uVar52 << 4 | uVar76 << 9 | uVar58 | uVar54 << 1,
                                        param_1[0xe]);
                    if (iVar28 != 0) {
                      __ZN11JBIG2Bitmap8setPixelEii(plVar30,iVar24,uVar26);
                    }
                    uVar58 = (uint)(iVar28 != 0);
                  }
                  else {
                    uVar58 = 0;
                  }
                  if (pbVar35 == (byte *)0x0) {
joined_r0x000183d0272c:
                    uVar22 = 0;
                    pbVar70 = pbVar35;
                    if (pbVar37 != (byte *)0x0) goto LAB_183d02730;
LAB_183d02798:
                    uVar33 = 0;
                    pbVar35 = pbVar70;
                  }
                  else {
                    if (iVar27 < 0) {
                      iVar27 = iVar27 + 1;
                      goto joined_r0x000183d0272c;
                    }
                    iVar28 = (int)plVar30[2];
                    lVar40 = pacga((long)iVar28,uVar45);
                    if (lVar40 != plVar30[3]) goto LAB_183d02eac;
                    uVar22 = *pbVar35 >> (ulong)(local_bc & 0x1f) & 1;
                    iVar27 = iVar27 + 1;
                    uVar33 = local_bc - 1;
                    if (local_bc == 0) {
                      uVar33 = 7;
                      pbVar35 = pbVar35 + 1;
                    }
                    if (iVar27 != iVar28) {
                      local_bc = uVar33;
                    }
                    pbVar70 = (byte *)0x0;
                    if (iVar27 != iVar28) {
                      pbVar70 = pbVar35;
                    }
                    pbVar35 = pbVar70;
                    if (pbVar37 == (byte *)0x0) goto LAB_183d02798;
LAB_183d02730:
                    if (iVar23 < 0) {
                      uVar33 = 0;
                      iVar23 = iVar23 + 1;
                    }
                    else {
                      lVar40 = pacga((long)(int)plVar30[2],uVar45);
                      if (lVar40 != plVar30[3]) goto LAB_183d02eac;
                      uVar33 = *pbVar37 >> (ulong)(uVar63 & 0x1f) & 1;
                      iVar23 = iVar23 + 1;
                      uVar55 = uVar63 - 1;
                      pbVar70 = pbVar37;
                      if (uVar63 == 0) {
                        pbVar70 = pbVar37 + 1;
                        uVar55 = 7;
                      }
                      pbVar37 = (byte *)0x0;
                      if (iVar23 != (int)plVar30[2]) {
                        pbVar37 = pbVar70;
                        uVar63 = uVar55;
                      }
                    }
                  }
                  uVar76 = uVar22 | (uVar76 & 7) << 1;
                  uVar52 = uVar33 | (uVar52 & 0xf) << 1;
                  uVar54 = uVar58 | uVar54 << 1 & 6;
                  iVar24 = iVar24 + 1;
                } while (iVar25 != iVar24);
              }
            }
          }
          else {
            if (param_5 != 2) {
              if (uVar26 == 0) {
LAB_183d00fa0:
                uVar58 = 0;
                pbVar37 = (byte *)0x0;
                uVar52 = 0;
                iVar23 = 0;
                uVar76 = 0;
              }
              else {
                lVar40 = pacga((long)(int)plVar30[4],uVar44);
                if (lVar40 != plVar30[5]) goto LAB_183d02eac;
                if ((int)plVar30[4] < (int)uVar26) goto LAB_183d00fa0;
                iVar23 = (int)plVar30[2];
                lVar40 = pacga((long)iVar23,uVar45);
                if (lVar40 != plVar30[3]) goto LAB_183d02eac;
                if (iVar23 < 1) goto LAB_183d00fa0;
                lVar40 = *plVar39;
                if (lVar40 == 0) {
                  lVar40 = 0;
                }
                lVar32 = pacga((long)(int)plVar30[6],
                               (ulong)plVar6 & 0xffffffffffff | 0x5363000000000000);
                if (lVar32 != plVar30[7]) goto LAB_183d02eac;
                pbVar37 = (byte *)(lVar40 + (long)(int)plVar30[6] * ((long)(int)uVar26 + -1));
                if (lVar40 == 0) {
                  pbVar37 = (byte *)0x0;
                  iVar23 = 0;
                  uVar52 = 7;
                  uVar58 = 0;
                  uVar76 = 0;
                }
                else {
                  bVar9 = *pbVar37;
                  uVar58 = (uint)(bVar9 >> 7);
                  pbVar35 = (byte *)0x0;
                  if (iVar23 != 2) {
                    pbVar35 = pbVar37;
                  }
                  uVar76 = 5;
                  if (iVar23 == 2) {
                    uVar76 = 6;
                  }
                  bVar21 = iVar23 != 1;
                  pbVar37 = (byte *)0x0;
                  if (bVar21) {
                    pbVar37 = pbVar35;
                  }
                  uVar52 = 7;
                  if (bVar21) {
                    uVar52 = uVar76;
                  }
                  iVar23 = 1;
                  if (bVar21) {
                    iVar23 = 2;
                  }
                  uVar76 = 0;
                  if (bVar21) {
                    uVar76 = bVar9 >> 6 & 1;
                  }
                }
              }
              lVar40 = (long)*(int *)*param_10 + (long)(int)uVar26;
              iVar24 = (int)lVar40;
              if (iVar24 < 0) {
LAB_183d01068:
                pbVar35 = (byte *)0x0;
                uVar22 = 0;
                uVar63 = 0;
              }
              else {
                lVar32 = pacga((long)(int)plVar30[4],uVar44);
                if (lVar32 != plVar30[5]) goto LAB_183d02eac;
                if ((int)plVar30[4] <= iVar24) goto LAB_183d01068;
                lVar32 = pacga((long)(int)plVar30[2],uVar45);
                if (lVar32 != plVar30[3]) goto LAB_183d02eac;
                uVar63 = *param_9;
                if ((int)plVar30[2] <= (int)uVar63) goto LAB_183d01068;
                if ((int)uVar63 < 0) {
                  lVar32 = pacga((long)(int)plVar30[6],
                                 (ulong)plVar6 & 0xffffffffffff | 0x5363000000000000);
                  if (lVar32 != plVar30[7]) goto LAB_183d02eac;
                  pbVar35 = (byte *)(*plVar39 + (int)plVar30[6] * lVar40);
                  uVar22 = 7;
                }
                else {
                  lVar40 = pacga((long)(int)plVar30[6],
                                 (ulong)plVar6 & 0xffffffffffff | 0x5363000000000000);
                  if (lVar40 != plVar30[7]) goto LAB_183d02eac;
                  pbVar35 = (byte *)(*plVar39 +
                                    (long)(int)((int)plVar30[6] * iVar24 + (uVar63 >> 3)));
                  uVar22 = (uVar63 ^ 0xffffffff) & 7;
                }
              }
              if (0 < iVar25) {
                iVar24 = 0;
                uVar29 = 0;
                uVar76 = uVar76 | uVar58 << 1;
                do {
                  if (pbVar35 == (byte *)0x0) {
                    uVar58 = 0;
                  }
                  else if ((int)uVar63 < 0) {
                    uVar58 = 0;
                    uVar63 = uVar63 + 1;
                  }
                  else {
                    lVar40 = pacga((long)(int)*(uint *)(plVar30 + 2),uVar45);
                    if (lVar40 != plVar30[3]) goto LAB_183d02eac;
                    uVar58 = *pbVar35 >> (ulong)(uVar22 & 0x1f) & 1;
                    uVar63 = uVar63 + 1;
                    uVar62 = uVar22 - 1;
                    pbVar66 = pbVar35;
                    if (uVar22 == 0) {
                      pbVar66 = pbVar35 + 1;
                      uVar62 = 7;
                    }
                    pbVar35 = (byte *)0x0;
                    if (uVar63 != *(uint *)(plVar30 + 2)) {
                      pbVar35 = pbVar66;
                      uVar22 = uVar62;
                    }
                  }
                  if (((param_7 == 0) ||
                      (iVar27 = __ZN11JBIG2Bitmap8getPixelEii(param_8,iVar24,uVar26), iVar27 == 0))
                     && (iVar27 = __ZN18JArithmeticDecoder9decodeBitEjP23JArithmeticDecoderStats
                                            (param_1[0xd],uVar58 | uVar76 << 5 | uVar29 << 1,
                                             param_1[0xe]), iVar27 != 0)) {
                    __ZN11JBIG2Bitmap8setPixelEii(plVar30,iVar24,uVar26);
                    uVar58 = 1;
                    if (pbVar37 != (byte *)0x0) goto LAB_183d01150;
LAB_183d01140:
                    uVar62 = 0;
                  }
                  else {
                    uVar58 = 0;
                    if (pbVar37 == (byte *)0x0) goto LAB_183d01140;
LAB_183d01150:
                    if (iVar23 < 0) {
                      uVar62 = 0;
                      iVar23 = iVar23 + 1;
                    }
                    else {
                      lVar40 = pacga((long)(int)plVar30[2],uVar45);
                      if (lVar40 != plVar30[3]) goto LAB_183d02eac;
                      uVar62 = *pbVar37 >> (ulong)(uVar52 & 0x1f) & 1;
                      iVar23 = iVar23 + 1;
                      uVar54 = uVar52 - 1;
                      pbVar66 = pbVar37;
                      if (uVar52 == 0) {
                        pbVar66 = pbVar37 + 1;
                        uVar54 = 7;
                      }
                      pbVar37 = (byte *)0x0;
                      if (iVar23 != (int)plVar30[2]) {
                        pbVar37 = pbVar66;
                        uVar52 = uVar54;
                      }
                    }
                  }
                  uVar76 = uVar62 | (uVar76 & 0xf) << 1;
                  uVar29 = uVar58 | uVar29 << 1 & 0xe;
                  iVar24 = iVar24 + 1;
                } while (iVar25 != iVar24);
              }
              goto LAB_183d027e0;
            }
            if (uVar26 < 2) {
              if (uVar26 != 0) {
                iVar23 = (int)plVar30[4];
                lVar40 = pacga((long)iVar23,uVar44);
                if (lVar40 != plVar30[5]) goto LAB_183d02eac;
                iVar24 = 0;
                local_bc = 0;
                pbVar35 = (byte *)0x0;
                uVar76 = 0;
                goto LAB_183d01fa8;
              }
              uVar76 = 0;
              pbVar35 = (byte *)0x0;
              local_bc = 0;
              iVar24 = 0;
LAB_183d02004:
              uVar63 = 0;
              pbVar37 = (byte *)0x0;
              uVar58 = 0;
              iVar23 = 0;
              uVar52 = 0;
            }
            else {
              iVar23 = (int)plVar30[4];
              lVar40 = pacga((long)iVar23,uVar44);
              if (lVar40 != plVar30[5]) goto LAB_183d02eac;
              if ((int)((long)(int)uVar26 + -2) < iVar23) {
                iVar24 = (int)plVar30[2];
                lVar40 = pacga((long)iVar24,uVar45);
                if (lVar40 != plVar30[3]) goto LAB_183d02eac;
                if (0 < iVar24) {
                  lVar40 = *plVar39;
                  if (lVar40 == 0) {
                    lVar40 = 0;
                  }
                  lVar32 = pacga((long)(int)plVar30[6],
                                 (ulong)plVar6 & 0xffffffffffff | 0x5363000000000000);
                  if (lVar32 != plVar30[7]) goto LAB_183d02eac;
                  pbVar37 = (byte *)(lVar40 + (long)(int)plVar30[6] * ((long)(int)uVar26 + -2));
                  if (lVar40 == 0) {
                    iVar24 = 0;
                    uVar76 = 0;
                  }
                  else {
                    bVar9 = *pbVar37;
                    bVar10 = bVar9 >> 7;
                    uVar76 = (uint)bVar10;
                    if (iVar24 != 1) {
                      local_bc = 5;
                      if (iVar24 == 2) {
                        local_bc = 6;
                      }
                      pbVar35 = (byte *)0x0;
                      if (iVar24 != 2) {
                        pbVar35 = pbVar37;
                      }
                      uVar76 = bVar9 >> 6 & 1 | (uint)bVar10 << 1;
                      iVar24 = 2;
                      goto LAB_183d01fa8;
                    }
                    iVar24 = 1;
                  }
                  pbVar35 = (byte *)0x0;
                  uVar76 = uVar76 << 1;
                  local_bc = 7;
                  goto LAB_183d01fa8;
                }
              }
              uVar76 = 0;
              pbVar35 = (byte *)0x0;
              local_bc = 0;
              iVar24 = 0;
LAB_183d01fa8:
              if (iVar23 < (int)uVar26) goto LAB_183d02004;
              iVar23 = (int)plVar30[2];
              lVar40 = pacga((long)iVar23,uVar45);
              if (lVar40 != plVar30[3]) goto LAB_183d02eac;
              if (iVar23 < 1) goto LAB_183d02004;
              lVar40 = *plVar39;
              if (lVar40 == 0) {
                lVar40 = 0;
              }
              lVar32 = pacga((long)(int)plVar30[6],
                             (ulong)plVar6 & 0xffffffffffff | 0x5363000000000000);
              if (lVar32 != plVar30[7]) goto LAB_183d02eac;
              pbVar37 = (byte *)(lVar40 + (long)(int)plVar30[6] * (long)(int)(uVar26 - 1));
              if (lVar40 == 0) {
                pbVar37 = (byte *)0x0;
                iVar23 = 0;
                uVar58 = 7;
                uVar63 = 0;
                uVar52 = 0;
              }
              else {
                bVar9 = *pbVar37;
                uVar63 = (uint)(bVar9 >> 7);
                pbVar66 = (byte *)0x0;
                if (iVar23 != 2) {
                  pbVar66 = pbVar37;
                }
                uVar52 = 5;
                if (iVar23 == 2) {
                  uVar52 = 6;
                }
                bVar21 = iVar23 != 1;
                pbVar37 = (byte *)0x0;
                if (bVar21) {
                  pbVar37 = pbVar66;
                }
                uVar58 = 7;
                if (bVar21) {
                  uVar58 = uVar52;
                }
                iVar23 = 1;
                if (bVar21) {
                  iVar23 = 2;
                }
                uVar52 = 0;
                if (bVar21) {
                  uVar52 = bVar9 >> 6 & 1;
                }
              }
            }
            lVar40 = (long)*(int *)*param_10 + (long)(int)uVar26;
            iVar27 = (int)lVar40;
            if (iVar27 < 0) {
LAB_183d020d4:
              pbVar66 = (byte *)0x0;
              uVar29 = 0;
              uVar22 = 0;
            }
            else {
              lVar32 = pacga((long)(int)plVar30[4],uVar44);
              if (lVar32 != plVar30[5]) goto LAB_183d02eac;
              if ((int)plVar30[4] <= iVar27) goto LAB_183d020d4;
              lVar32 = pacga((long)(int)plVar30[2],uVar45);
              if (lVar32 != plVar30[3]) goto LAB_183d02eac;
              uVar22 = *param_9;
              if ((int)plVar30[2] <= (int)uVar22) goto LAB_183d020d4;
              if ((int)uVar22 < 0) {
                lVar32 = pacga((long)(int)plVar30[6],
                               (ulong)plVar6 & 0xffffffffffff | 0x5363000000000000);
                if (lVar32 != plVar30[7]) goto LAB_183d02eac;
                pbVar66 = (byte *)(*plVar39 + (int)plVar30[6] * lVar40);
                uVar29 = 7;
              }
              else {
                lVar40 = pacga((long)(int)plVar30[6],
                               (ulong)plVar6 & 0xffffffffffff | 0x5363000000000000);
                if (lVar40 != plVar30[7]) goto LAB_183d02eac;
                pbVar66 = (byte *)(*plVar39 + (long)(int)((int)plVar30[6] * iVar27 + (uVar22 >> 3)))
                ;
                uVar29 = (uVar22 ^ 0xffffffff) & 7;
              }
            }
            if (0 < iVar25) {
              iVar27 = 0;
              uVar62 = 0;
              uVar52 = uVar52 | uVar63 << 1;
              do {
                if (pbVar66 == (byte *)0x0) {
                  uVar63 = 0;
                  pbVar66 = (byte *)0x0;
                }
                else if ((int)uVar22 < 0) {
                  uVar63 = 0;
                  uVar22 = uVar22 + 1;
                }
                else {
                  lVar40 = pacga((long)(int)*(uint *)(plVar30 + 2),uVar45);
                  if (lVar40 != plVar30[3]) goto LAB_183d02eac;
                  uVar63 = *pbVar66 >> (ulong)(uVar29 & 0x1f) & 1;
                  uVar22 = uVar22 + 1;
                  uVar54 = uVar29 - 1;
                  pbVar70 = pbVar66;
                  if (uVar29 == 0) {
                    pbVar70 = pbVar66 + 1;
                    uVar54 = 7;
                  }
                  pbVar66 = (byte *)0x0;
                  if (uVar22 != *(uint *)(plVar30 + 2)) {
                    pbVar66 = pbVar70;
                    uVar29 = uVar54;
                  }
                }
                if ((param_7 == 0) ||
                   (iVar28 = __ZN11JBIG2Bitmap8getPixelEii(param_8,iVar27,uVar26), iVar28 == 0)) {
                  iVar28 = __ZN18JArithmeticDecoder9decodeBitEjP23JArithmeticDecoderStats
                                     (param_1[0xd],uVar52 << 3 | uVar76 << 7 | uVar63 | uVar62 << 1,
                                      param_1[0xe]);
                  if (iVar28 != 0) {
                    __ZN11JBIG2Bitmap8setPixelEii(plVar30,iVar27,uVar26);
                  }
                  uVar63 = (uint)(iVar28 != 0);
                }
                else {
                  uVar63 = 0;
                }
                if (pbVar35 == (byte *)0x0) {
joined_r0x000183d02288:
                  uVar54 = 0;
                  pbVar70 = pbVar35;
                  if (pbVar37 != (byte *)0x0) goto LAB_183d0228c;
LAB_183d022f4:
                  uVar33 = 0;
                  pbVar35 = pbVar70;
                }
                else {
                  if (iVar24 < 0) {
                    iVar24 = iVar24 + 1;
                    goto joined_r0x000183d02288;
                  }
                  iVar28 = (int)plVar30[2];
                  lVar40 = pacga((long)iVar28,uVar45);
                  if (lVar40 != plVar30[3]) goto LAB_183d02eac;
                  uVar54 = *pbVar35 >> (ulong)(local_bc & 0x1f) & 1;
                  iVar24 = iVar24 + 1;
                  uVar33 = local_bc - 1;
                  if (local_bc == 0) {
                    uVar33 = 7;
                    pbVar35 = pbVar35 + 1;
                  }
                  if (iVar24 != iVar28) {
                    local_bc = uVar33;
                  }
                  pbVar70 = (byte *)0x0;
                  if (iVar24 != iVar28) {
                    pbVar70 = pbVar35;
                  }
                  pbVar35 = pbVar70;
                  if (pbVar37 == (byte *)0x0) goto LAB_183d022f4;
LAB_183d0228c:
                  if (iVar23 < 0) {
                    uVar33 = 0;
                    iVar23 = iVar23 + 1;
                  }
                  else {
                    lVar40 = pacga((long)(int)plVar30[2],uVar45);
                    if (lVar40 != plVar30[3]) goto LAB_183d02eac;
                    uVar33 = *pbVar37 >> (ulong)(uVar58 & 0x1f) & 1;
                    iVar23 = iVar23 + 1;
                    uVar55 = uVar58 - 1;
                    pbVar70 = pbVar37;
                    if (uVar58 == 0) {
                      pbVar70 = pbVar37 + 1;
                      uVar55 = 7;
                    }
                    pbVar37 = (byte *)0x0;
                    if (iVar23 != (int)plVar30[2]) {
                      pbVar37 = pbVar70;
                      uVar58 = uVar55;
                    }
                  }
                }
                uVar76 = uVar54 | (uVar76 & 3) << 1;
                uVar52 = uVar33 | (uVar52 & 7) << 1;
                uVar62 = uVar63 | uVar62 << 1 & 2;
                iVar27 = iVar27 + 1;
              } while (iVar25 != iVar27);
            }
          }
        }
        else {
          iVar23 = __ZN18JArithmeticDecoder9decodeBitEjP23JArithmeticDecoderStats
                             (param_1[0xd],uVar8,param_1[0xe]);
          if (iVar23 != 0) {
            bVar19 = !bVar20;
          }
          if (!bVar19) {
            bVar20 = false;
            bVar19 = false;
            goto LAB_183d00e48;
          }
          if (uVar26 != 0) {
            lVar32 = *plVar39;
            lVar40 = lVar32;
            if (lVar32 == 0) {
              lVar40 = 0;
            }
            iVar23 = (int)plVar30[6];
            lVar41 = pacga((long)iVar23,(ulong)plVar6 & 0xffffffffffff | 0x5363000000000000);
            if (lVar41 != plVar30[7]) goto LAB_183d02eac;
            func_0x0001881384d0(lVar40 + (long)iVar23 * (long)(int)uVar26,
                                lVar32 + (int)(iVar23 * (uVar26 - 1)));
          }
          bVar20 = true;
          bVar19 = true;
        }
LAB_183d027e0:
        uVar26 = uVar26 + 1;
        if (uVar26 == uVar38) {
          return plVar30;
        }
      } while( true );
    }
    uVar44 = (long)iVar25 + 7;
    if ((7 < uVar44) && (uVar38 != 0)) {
      uVar45 = uVar44 >> 3;
      local_138 = *plVar39;
      if (local_138 == 0) {
        local_138 = 0;
      }
      lVar40 = 0;
      uVar74 = (ulong)(int)uVar38;
      lVar32 = 4;
      do {
        uVar26 = param_9[lVar40];
        if ((int)uVar26 < -0x7f) {
          uVar26 = 0xffffff80;
        }
        if (0x7e < (int)uVar26) {
          uVar26 = 0x7f;
        }
        param_9[lVar40] = uVar26;
        uVar26 = *(uint *)(*param_10 + lVar40 * 4);
        if ((int)uVar26 < -0x7f) {
          uVar26 = 0xffffff80;
        }
        *(uint *)(*param_10 + lVar40 * 4) = uVar26 & (int)uVar26 >> 0x1f;
        lVar40 = lVar40 + 1;
        lVar32 = lVar32 + -1;
      } while (lVar32 != 0);
      uVar52 = *param_9;
      uVar58 = param_9[1];
      uVar76 = param_9[2];
      uVar63 = param_9[3];
      uVar26 = uVar76;
      if ((int)uVar63 <= (int)uVar76) {
        uVar26 = uVar63;
      }
      if ((int)uVar76 <= (int)uVar63) {
        uVar76 = uVar63;
      }
      uVar63 = uVar52;
      if ((int)uVar58 <= (int)uVar52) {
        uVar63 = uVar58;
      }
      if ((int)uVar52 <= (int)uVar58) {
        uVar52 = uVar58;
      }
      if ((int)uVar26 <= (int)uVar63) {
        uVar63 = uVar26;
      }
      uVar26 = uVar63 & (int)uVar63 >> 0x1f;
      if ((int)uVar52 <= (int)uVar76) {
        uVar52 = uVar76;
      }
      if ((int)uVar52 < 4) {
        uVar52 = 3;
      }
      if (uVar45 <= 0x80000006 - (ulong)(uVar52 - uVar26) >> 3) {
        uVar44 = (uVar44 & 0xfffffffffffffff8) + (ulong)(uVar52 - uVar26);
        uVar76 = NEON_sminv(*param_10,4);
        if (-3 < (int)uVar76) {
          uVar76 = 0xfffffffe;
        }
        iVar23 = 1 - uVar76;
        uVar65 = (ulong)iVar23;
        uVar42 = 0;
        if (uVar65 != 0) {
          uVar42 = 0x7fffffff / uVar65;
        }
        uVar71 = uVar44 * uVar65;
        if (uVar44 <= uVar42 && uVar71 >> 0x1f == 0) {
          lVar41 = __Z13gmalloc_typediy(uVar71,0x100004077774924);
          func_0x0001881382e0(lVar41,uVar71);
          lVar32 = __Z13gmalloc_typediy(iVar23 * 8,0x10040436913f5);
          lVar40 = 0;
          uVar52 = -uVar26;
          uVar42 = uVar65;
          do {
            *(ulong *)(lVar32 + lVar40 * 8) = lVar41 + lVar40 * uVar44;
            lVar40 = lVar40 + 1;
            uVar42 = uVar42 - 1;
          } while (uVar42 != 0);
          if ((int)uVar38 < 1) {
            lVar40 = 0;
          }
          else {
            uVar44 = 0;
            lVar43 = 0;
            iVar60 = *(int *)(*param_10 + 0xc) - uVar76;
            iVar28 = *(int *)(*param_10 + 8) - uVar76;
            iVar27 = *(int *)(*param_10 + 4) - uVar76;
            iVar24 = *(int *)*param_10 - uVar76;
            uVar22 = ~uVar76;
            uVar58 = -uVar76 - 2;
            lVar40 = (long)(int)uVar52;
            uVar38 = uVar52;
            if ((int)uVar52 < 2) {
              uVar38 = 1;
            }
            uVar42 = (ulong)-uVar76;
            do {
              pbVar37 = (byte *)(*(long *)(lVar32 + (ulong)uVar58 * 8) + lVar40);
              pbVar35 = (byte *)(*(long *)(lVar32 + (ulong)uVar22 * 8) + lVar40);
              lVar47 = *(long *)(lVar32 + uVar42 * 8);
              lVar48 = *(long *)(lVar32 + (long)iVar24 * 8);
              uVar29 = *param_9;
              lVar49 = *(long *)(lVar32 + (long)iVar27 * 8);
              uVar62 = param_9[1];
              lVar50 = *(long *)(lVar32 + (long)iVar28 * 8);
              uVar54 = param_9[2];
              lVar51 = *(long *)(lVar32 + (long)iVar60 * 8);
              uVar33 = param_9[3];
              bVar9 = *pbVar37;
              bVar10 = pbVar37[1];
              bVar11 = *pbVar35;
              bVar12 = pbVar35[1];
              bVar13 = pbVar35[2];
              if ((int)uVar63 < 0) {
                uVar71 = 0;
                do {
                  *(undefined1 *)(*(long *)(lVar32 + uVar42 * 8) + uVar71) = 0;
                  uVar71 = uVar71 + 1;
                } while (uVar38 != uVar71);
              }
              if (0 < iVar25) {
                uVar56 = 0;
                uVar55 = (uint)bVar10 | (uint)bVar9 << 1;
                uVar72 = (uint)bVar12 << 1 | (uint)bVar11 << 2 | (uint)bVar13;
                puVar34 = (undefined1 *)(lVar47 + lVar40);
                pbVar66 = (byte *)(lVar49 + ((long)(int)uVar62 - (long)(int)uVar26));
                lVar47 = (long)iVar25;
                pbVar70 = (byte *)(lVar51 + ((long)(int)uVar33 - (long)(int)uVar26));
                pbVar75 = (byte *)(lVar50 + ((long)(int)uVar54 - (long)(int)uVar26));
                pbVar68 = (byte *)(lVar48 + ((long)(int)uVar29 - (long)(int)uVar26));
                do {
                  uVar29 = __ZN18JArithmeticDecoder9decodeBitEjP23JArithmeticDecoderStats
                                     (param_1[0xd],
                                      uVar72 << 8 | uVar55 << 0xd | uVar56 << 4 |
                                      (uint)*pbVar68 << 3 | (uint)*pbVar66 << 2 |
                                      (uint)*pbVar75 << 1 | (uint)*pbVar70,param_1[0xe]);
                  *puVar34 = (char)uVar29;
                  uVar55 = ((uint)pbVar37[2] | uVar55 << 1) & 7;
                  uVar72 = ((uint)pbVar35[3] | uVar72 << 1) & 0x1f;
                  uVar56 = uVar29 & 0xfffffff0 | uVar29 & 1 | (uVar56 & 7) << 1;
                  pbVar37 = pbVar37 + 1;
                  pbVar35 = pbVar35 + 1;
                  lVar47 = lVar47 + -1;
                  puVar34 = puVar34 + 1;
                  pbVar66 = pbVar66 + 1;
                  pbVar70 = pbVar70 + 1;
                  pbVar75 = pbVar75 + 1;
                  pbVar68 = pbVar68 + 1;
                } while (lVar47 != 0);
              }
              if (-uVar76 <= uVar44) {
                lVar47 = 0;
                pcVar53 = (char *)(*(long *)(lVar32 + (long)(int)lVar43 * 8) + lVar40);
                uVar71 = uVar45;
                do {
                  cVar14 = *pcVar53;
                  pcVar1 = pcVar53 + 1;
                  pcVar2 = pcVar53 + 2;
                  pbVar37 = (byte *)(pcVar53 + 3);
                  pcVar3 = pcVar53 + 4;
                  pcVar4 = pcVar53 + 5;
                  pcVar5 = pcVar53 + 6;
                  pbVar35 = (byte *)(pcVar53 + 7);
                  pcVar53 = pcVar53 + 8;
                  *(byte *)(local_138 + uVar45 * (uVar44 + (long)(int)uVar76) + lVar47) =
                       (*pcVar1 << 2 | cVar14 << 3 | *pbVar37) << 4 | *pcVar2 << 5 | *pcVar3 << 3 |
                       *pcVar4 << 2 | *pbVar35 | *pcVar5 << 1;
                  lVar47 = lVar47 + 1;
                  uVar71 = uVar71 - 1;
                } while (uVar71 != 0);
              }
              uVar59 = (ulong)((int)lVar43 + 1);
              uVar71 = 0;
              if (uVar65 != 0) {
                uVar71 = uVar59 / uVar65;
              }
              lVar43 = uVar59 - uVar71 * uVar65;
              iVar18 = 0;
              if (uVar65 != 0) {
                iVar18 = (int)((uVar58 + 1) / uVar65);
              }
              uVar58 = (uVar58 + 1) - iVar18 * iVar23;
              iVar18 = 0;
              if (uVar65 != 0) {
                iVar18 = (int)((uVar22 + 1) / uVar65);
              }
              uVar22 = (uVar22 + 1) - iVar18 * iVar23;
              uVar29 = (int)uVar42 + 1;
              iVar18 = 0;
              if (uVar65 != 0) {
                iVar18 = (int)(uVar29 / uVar65);
              }
              uVar42 = (ulong)(uVar29 - iVar18 * iVar23);
              iVar18 = 0;
              if (uVar65 != 0) {
                iVar18 = (int)((ulong)(long)(iVar24 + 1) / uVar65);
              }
              iVar24 = (iVar24 + 1) - iVar18 * iVar23;
              iVar18 = 0;
              if (uVar65 != 0) {
                iVar18 = (int)((ulong)(long)(iVar27 + 1) / uVar65);
              }
              iVar27 = (iVar27 + 1) - iVar18 * iVar23;
              iVar18 = 0;
              if (uVar65 != 0) {
                iVar18 = (int)((ulong)(long)(iVar28 + 1) / uVar65);
              }
              iVar28 = (iVar28 + 1) - iVar18 * iVar23;
              iVar18 = 0;
              if (uVar65 != 0) {
                iVar18 = (int)((ulong)(long)(iVar60 + 1) / uVar65);
              }
              iVar60 = (iVar60 + 1) - iVar18 * iVar23;
              uVar44 = uVar44 + 1;
            } while (uVar44 != uVar74);
            lVar40 = (long)(int)lVar43;
          }
          uVar42 = uVar65 - 1;
          uVar44 = 0;
          if (uVar74 <= uVar42) {
            uVar44 = uVar42 - uVar74;
          }
          if (uVar44 < uVar42) {
            do {
              lVar43 = 0;
              uVar71 = 0;
              if (uVar65 != 0) {
                uVar71 = (uVar44 + lVar40) / uVar65;
              }
              pcVar53 = (char *)(*(long *)(lVar32 + ((uVar44 + lVar40) - uVar71 * uVar65) * 8) +
                                (long)(int)uVar52);
              uVar71 = uVar45;
              do {
                cVar14 = *pcVar53;
                pcVar1 = pcVar53 + 1;
                pcVar2 = pcVar53 + 2;
                pbVar37 = (byte *)(pcVar53 + 3);
                pcVar3 = pcVar53 + 4;
                pcVar4 = pcVar53 + 5;
                pcVar5 = pcVar53 + 6;
                pbVar35 = (byte *)(pcVar53 + 7);
                pcVar53 = pcVar53 + 8;
                *(byte *)(local_138 + ((uVar74 - uVar65) + 1 + uVar44) * uVar45 + lVar43) =
                     (*pcVar1 << 2 | cVar14 << 3 | *pbVar37) << 4 | *pcVar2 << 5 | *pcVar3 << 3 |
                     *pcVar4 << 2 | *pbVar35 | *pcVar5 << 1;
                lVar43 = lVar43 + 1;
                uVar71 = uVar71 - 1;
              } while (uVar71 != 0);
              uVar44 = uVar44 + 1;
            } while (uVar44 != uVar42);
          }
          func_0x000188138390(lVar41);
          goto LAB_183d00d9c;
        }
      }
    }
  }
  (**(code **)(*plVar30 + 8))(plVar30);
  return (long *)0x0;
}



/* ==== __ZN11JBIG2Bitmap10clearPixelEii @ 183d02fc8 size=200 ==== */

/* WARNING: Removing unreachable block (ram,0x000183d03044) */

void __ZN11JBIG2Bitmap10clearPixelEii(long param_1,uint param_2,int param_3)

{
  int iVar1;
  long lVar2;
  
  if (-1 < (int)param_2) {
    iVar1 = *(int *)(param_1 + 0x10);
    lVar2 = pacga((long)iVar1,(ulong)(param_1 + 0x10) & 0xffffffffffff | 0x5363000000000000);
    if (lVar2 != *(long *)(param_1 + 0x18)) {
LAB_183d0308c:
      func_0x000188138260();
      return;
    }
    if ((-1 < param_3) && ((int)param_2 < iVar1)) {
      iVar1 = *(int *)(param_1 + 0x20);
      lVar2 = pacga((long)iVar1,(ulong)(param_1 + 0x20) & 0xffffffffffff | 0x5363000000000000);
      if (lVar2 != *(long *)(param_1 + 0x28)) goto LAB_183d0308c;
      if (param_3 < iVar1) {
        iVar1 = *(int *)(param_1 + 0x30);
        lVar2 = pacga((long)iVar1,(ulong)(param_1 + 0x30) & 0xffffffffffff | 0x5363000000000000);
        if (lVar2 != *(long *)(param_1 + 0x38)) goto LAB_183d0308c;
        iVar1 = iVar1 * param_3 + (param_2 >> 3);
        *(byte *)(*(long *)(param_1 + 0x40) + (long)iVar1) =
             *(byte *)(*(long *)(param_1 + 0x40) + (long)iVar1) &
             (byte)(0x7f7f >> (ulong)(param_2 & 7));
      }
    }
  }
  return;
}



/* ==== __ZN11JBIG2Bitmap7getTypeEv @ 183d03090 size=8 ==== */

undefined8 __ZN11JBIG2Bitmap7getTypeEv(void)

{
  return 0;
}



/* ==== __ZN15JBIG2SymbolDict7getTypeEv @ 183d03098 size=8 ==== */

undefined8 __ZN15JBIG2SymbolDict7getTypeEv(void)

{
  return 1;
}



/* ==== __ZN16JBIG2PatternDict7getTypeEv @ 183d030a0 size=8 ==== */

undefined8 __ZN16JBIG2PatternDict7getTypeEv(void)

{
  return 2;
}



/* ==== __ZN14JBIG2CodeTable7getTypeEv @ 183d030a8 size=8 ==== */

undefined8 __ZN14JBIG2CodeTable7getTypeEv(void)

{
  return 3;
}



/* ==== _rle_filter_refill @ 183e19f2c size=248 ==== */

long _rle_filter_refill(undefined8 *param_1,undefined8 param_2,ulong param_3)

{
  int iVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  
  lVar3 = 0;
  param_1[2] = 0;
  param_1[3] = param_2;
  if (0x80 < param_3) {
    lVar3 = 0;
    do {
      if ((*(byte *)(param_1 + 1) & 1) != 0) {
        return lVar3;
      }
      iVar1 = FUN_183bdf3b0(*param_1);
      if (iVar1 == -1) {
LAB_183e19ffc:
        _pdf_error("RunLengthDecode: encountered unexpected EOF.");
LAB_183e1a008:
        *(undefined1 *)(param_1 + 1) = 1;
        return param_1[2];
      }
      if (iVar1 < 0x80) {
        uVar4 = (ulong)(iVar1 + 1);
        do {
          iVar1 = FUN_183bdf3b0(*param_1);
          if (iVar1 == -1) goto LAB_183e19ffc;
          lVar3 = param_1[2];
          param_1[2] = lVar3 + 1;
          *(char *)(param_1[3] + lVar3) = (char)iVar1;
          uVar4 = uVar4 - 1;
        } while (uVar4 != 0);
      }
      else {
        if (iVar1 == 0x80) goto LAB_183e1a008;
        iVar2 = FUN_183bdf3b0(*param_1);
        if (iVar2 == -1) goto LAB_183e19ffc;
        uVar4 = (ulong)(0x101 - iVar1);
        do {
          lVar3 = param_1[2];
          param_1[2] = lVar3 + 1;
          *(char *)(param_1[3] + lVar3) = (char)iVar2;
          uVar4 = uVar4 - 1;
        } while (uVar4 != 0);
      }
      lVar3 = param_1[2];
    } while (lVar3 + 0x80U < param_3);
  }
  return lVar3;
}



/* ==== _lzw_decoder_release @ 183e6a13c size=80 ==== */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Possible PIC construction at 0x000183e6a164: Changing call to branch */
/* WARNING: Removing unreachable block (ram,0x000183e6a168) */
/* WARNING: Removing unreachable block (ram,0x000183e6a184) */
/* WARNING: Removing unreachable block (ram,0x000183e6a180) */

void _lzw_decoder_release(long *param_1)

{
  if (param_1 != (long *)0x0) {
    if (*param_1 != 0) {
      func_0x000188141240();
    }
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return;
}



/* ==== _lzw_read_code @ 183e6a18c size=168 ==== */

uint _lzw_read_code(undefined8 *param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x886);
  uVar1 = *(uint *)(param_1 + 0x84);
  if (iVar3 < (int)uVar1) {
    do {
      uVar1 = FUN_183bdf3b0(*param_1);
      if (uVar1 == 0xffffffff) {
        _pdf_error("LZW decode: encountered unexpected EOF.");
        *(undefined1 *)((long)param_1 + 9) = 1;
        uVar1 = 0x101;
        goto LAB_183e6a224;
      }
      uVar2 = uVar1 & 0xff | *(int *)((long)param_1 + 0x442c) << 8;
      *(uint *)((long)param_1 + 0x442c) = uVar2;
      iVar3 = *(int *)(param_1 + 0x886) + 8;
      *(int *)(param_1 + 0x886) = iVar3;
      uVar1 = *(uint *)(param_1 + 0x84);
    } while (iVar3 < (int)uVar1);
  }
  else {
    uVar2 = *(uint *)((long)param_1 + 0x442c);
  }
  *(uint *)(param_1 + 0x886) = iVar3 - uVar1;
  uVar1 = uVar2 >> (ulong)(iVar3 - uVar1 & 0x1f) & (-1 << (ulong)(uVar1 & 0x1f) ^ 0xffffffffU);
LAB_183e6a224:
  return uVar1 & 0xffff;
}



/* ==== _lzw_push @ 183e6a234 size=144 ==== */

void _lzw_push(long param_1,undefined1 param_2)

{
  long lVar1;
  long lVar2;
  
  lVar1 = *(long *)(param_1 + 0x4438);
  lVar2 = *(long *)(param_1 + 0x4440);
  if (lVar1 == lVar2) {
    lVar2 = lVar1 * 2 + 10;
    lVar1 = func_0x000188138490(*(undefined8 *)(param_1 + 0x4448),lVar2,0xf56e5f40);
    *(long *)(param_1 + 0x4448) = lVar1;
    func_0x0001881384e0((lVar1 + lVar2) - *(long *)(param_1 + 0x4440),lVar1);
    *(long *)(param_1 + 0x4440) = lVar2;
    lVar1 = *(long *)(param_1 + 0x4438);
  }
  *(long *)(param_1 + 0x4438) = lVar1 + 1;
  *(undefined1 *)(*(long *)(param_1 + 0x4448) + (lVar2 - (lVar1 + 1))) = param_2;
  return;
}



/* ==== _flate_filter_rewind @ 183ed7fb0 size=128 ==== */

void _flate_filter_rewind(undefined8 *param_1)

{
  int iVar1;
  char *pcVar2;
  
  if (param_1 != (undefined8 *)0x0) {
    *param_1 = 0;
    *(undefined4 *)(param_1 + 1) = 0;
    *(undefined1 *)((long)param_1 + 0x72) = 0;
    *(undefined2 *)(param_1 + 0xe) = 0;
    FUN_183d23b30(param_1[0xf]);
    iVar1 = func_0x000188149580(param_1);
    if (iVar1 != 0) {
      if (param_1[6] == 0) {
        pcVar2 = "FlateDecode: rewind error.";
      }
      else {
        pcVar2 = "FlateDecode: rewind error: %s.";
      }
      _pdf_error(pcVar2);
      *(undefined1 *)((long)param_1 + 0x71) = 1;
    }
  }
  return;
}



/* ==== _pdf_source_create_predictor2_filter @ 183f1db4c size=476 ==== */

long _pdf_source_create_predictor2_filter(undefined8 param_1,long param_2)

{
  ulong uVar1;
  int iVar2;
  undefined8 *puVar3;
  ulong uVar4;
  undefined8 uVar5;
  long lVar6;
  ulong uVar7;
  ulong uVar8;
  ulong local_38;
  
  puVar3 = (undefined8 *)func_0x000188138460(1,0x28,0x10300406bfc95ce);
  puVar3[3] = 8;
  puVar3[2] = 1;
  puVar3[1] = 1;
  if (param_2 != 0) {
    local_38 = 0;
    iVar2 = FUN_183bd6c4c(param_2,"Colors",&local_38);
    if (iVar2 != 0) {
      if ((long)local_38 < 1) {
        _pdf_error("/%s is outside the range of allowed values.");
      }
      else {
        puVar3[1] = local_38;
      }
    }
    iVar2 = FUN_183bd6c4c(param_2,"BitsPerComponent",&local_38);
    if (iVar2 != 0) {
      if ((local_38 < 0x11) && ((1L << (local_38 & 0x3f) & 0x10116U) != 0)) {
        puVar3[3] = local_38;
      }
      else {
        _pdf_error("/%s is outside the range of allowed values.");
      }
    }
    iVar2 = FUN_183bd6c4c(param_2,"Columns",&local_38);
    if (iVar2 != 0) {
      if (local_38 - 1 < 0x3fffffff) {
        puVar3[2] = local_38;
      }
      else {
        _pdf_error("/%s is outside the range of allowed values.");
      }
    }
  }
  func_0x000188141250(param_1);
  *puVar3 = param_1;
  uVar4 = puVar3[1];
  uVar7 = puVar3[3];
  uVar1 = 0;
  if (uVar7 != 0) {
    uVar1 = 0xfffffffffffffff8 / uVar7;
  }
  if (uVar4 <= uVar1) {
    uVar7 = uVar7 * uVar4;
    uVar8 = puVar3[2];
    uVar1 = 0;
    if (uVar7 != 0) {
      uVar1 = 0xfffffffffffffff8 / uVar7;
    }
    if (uVar8 <= uVar1) {
      uVar5 = func_0x000188138470(uVar4,0xe3d5d5b);
      puVar3[4] = uVar5;
      lVar6 = _CGPDFSourceCreateInternal(uVar8 * uVar7 + 7 >> 3);
      if (lVar6 != 0) {
        *(undefined1 *)(lVar6 + 0xd1) = 1;
        *(undefined8 *)(lVar6 + 0x38) = 0x8010000003f1dd30;
        *(undefined8 *)(lVar6 + 0x30) = 0x8010000003f1dd28;
        *(undefined8 *)(lVar6 + 0x48) = 0;
        *(undefined8 *)(lVar6 + 0x40) = 0x8020000003f1dfb0;
        *(undefined8 **)(lVar6 + 0x50) = puVar3;
        return lVar6;
      }
    }
  }
  _predictor2_filter_finalize(puVar3);
  return 0;
}



/* ==== _predictor2_filter_rewind @ 183f1dd28 size=8 ==== */

void _predictor2_filter_rewind(undefined8 *param_1)

{
  FUN_183d23b30(*param_1);
  return;
}



/* ==== _predictor2_filter_refill @ 183f1dd30 size=640 ==== */

ulong _predictor2_filter_refill(undefined8 *param_1,byte *param_2)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  ulong uVar4;
  long lVar5;
  uint uVar6;
  ulong uVar7;
  ulong uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  ulong uVar12;
  ulong uVar13;
  byte *pbVar14;
  ulong uVar15;
  byte *pbVar16;
  ulong uVar17;
  ulong uVar18;
  
  uVar4 = FUN_183bd4a90(*param_1);
  uVar15 = uVar4;
  if (uVar4 != 0) {
    pbVar1 = param_2 + uVar4;
    uVar17 = param_1[3];
    uVar18 = uVar17 - 1;
    uVar15 = 0;
    if ((uVar18 < 8) && ((0x8bU >> (ulong)((uint)uVar18 & 0x1f) & 1) != 0)) {
      func_0x0001881382e0(param_1[4],param_1[1]);
      uVar15 = param_1[2];
      if (uVar15 == 0) {
        uVar10 = 0;
        uVar6 = 0;
        uVar17 = 0;
        uVar7 = 0;
      }
      else {
        uVar7 = 0;
        uVar12 = 0;
        uVar13 = 0;
        uVar6 = 0;
        uVar8 = 0;
        uVar9 = 0;
        uVar10 = 0xffffffff >> (ulong)(-(uint)uVar17 & 0x1f);
        pbVar16 = param_2;
        do {
          if (param_1[1] != 0) {
            uVar15 = 0;
            do {
              if (uVar17 == 0) {
                bVar3 = 0;
              }
              else {
                for (; uVar8 < uVar17; uVar8 = uVar8 + 8) {
                  uVar9 = uVar9 << 8;
                  pbVar14 = param_2;
                  if (param_2 < pbVar1) {
                    pbVar14 = param_2 + 1;
                    uVar9 = uVar9 | *param_2;
                  }
                  param_2 = pbVar14;
                }
                uVar8 = uVar8 - uVar17;
                bVar3 = (byte)(uVar9 >> (ulong)((uint)uVar8 & 0x1f)) & (byte)uVar10;
              }
              *(byte *)(param_1[4] + uVar15) = *(char *)(param_1[4] + uVar15) + bVar3;
              lVar5 = param_1[4];
              bVar3 = *(byte *)(lVar5 + uVar15);
              pbVar14 = pbVar16;
              bVar2 = bVar3;
              if (7 < uVar7) {
                do {
                  uVar7 = uVar7 - 8;
                  pbVar16 = pbVar14 + 1;
                  *pbVar14 = (byte)(uVar6 >> (ulong)((uint)uVar7 & 0x1f));
                  pbVar14 = pbVar16;
                } while (7 < uVar7);
                lVar5 = param_1[4];
                bVar2 = *(byte *)(lVar5 + uVar15);
              }
              uVar6 = uVar10 & bVar3 | uVar6 << (ulong)((uint)uVar17 & 0x1f);
              uVar7 = uVar7 + uVar17;
              *(byte *)(lVar5 + uVar15) = bVar2 & (byte)(0xff00000007000301 >> (uVar18 * 8 & 0x3f));
              uVar12 = uVar12 + uVar17;
            } while ((uVar4 != uVar12 >> 3) && (uVar15 = uVar15 + 1, uVar15 < (ulong)param_1[1]));
            uVar15 = param_1[2];
          }
          uVar13 = uVar13 + 1;
        } while (uVar13 < uVar15);
        uVar17 = uVar8 - 0x18;
        if (uVar8 < 0x18 || uVar17 == 0) {
          uVar17 = uVar8;
          uVar10 = 0;
          if (uVar8 == 0) goto LAB_183f1df3c;
          uVar10 = uVar9 & 0xffffffffU >> (ulong)(-(int)uVar8 & 0x1f);
          goto LAB_183f1df3c;
        }
        uVar11 = (uint)uVar17;
        uVar10 = uVar9 & 0xffffffffU >> (ulong)(-uVar11 & 0x1f) |
                 (uVar9 >> (ulong)(uVar11 & 0x1f) & 0xffffff) << (ulong)(uVar11 & 0x1f);
        while (7 < uVar7) {
          uVar7 = uVar7 - 8;
          *pbVar16 = (byte)(uVar6 >> (ulong)((uint)uVar7 & 0x1f));
          pbVar16 = pbVar16 + 1;
        }
        uVar6 = uVar10 >> (ulong)(uVar11 & 0x1f) & 0xffffff | uVar6 << 0x18;
        uVar7 = uVar7 | 0x18;
        do {
          uVar7 = uVar7 - 8;
          *pbVar16 = (byte)(uVar6 >> (ulong)((uint)uVar7 & 0x1f));
          pbVar16 = pbVar16 + 1;
LAB_183f1df3c:
          param_2 = pbVar16;
        } while (7 < uVar7);
      }
      uVar7 = uVar7 + uVar17;
      uVar15 = uVar4;
      if (uVar7 != 0) {
        uVar6 = 0xffffffffU >> (ulong)(-(uint)uVar17 & 0x1f) & uVar10 |
                uVar6 << (ulong)((uint)uVar17 & 0x1f);
        uVar17 = uVar7;
        do {
          while (7 < uVar7) {
            uVar7 = uVar7 - 8;
            *param_2 = (byte)(uVar6 >> (ulong)((uint)uVar7 & 0x1f));
            param_2 = param_2 + 1;
          }
          uVar15 = (ulong)(uint)-(int)uVar17 & 7;
          uVar6 = uVar6 << uVar15;
          uVar7 = uVar7 + uVar15;
          uVar15 = uVar4;
          uVar17 = uVar7;
        } while (uVar7 != 0);
      }
    }
  }
  return uVar15;
}



/* ==== _predictor2_filter_finalize @ 183f1dfb0 size=80 ==== */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Possible PIC construction at 0x000183f1dfd8: Changing call to branch */
/* WARNING: Removing unreachable block (ram,0x000183f1dfdc) */
/* WARNING: Removing unreachable block (ram,0x000183f1dff8) */
/* WARNING: Removing unreachable block (ram,0x000183f1dff4) */

void _predictor2_filter_finalize(long *param_1)

{
  if (param_1 != (long *)0x0) {
    if (*param_1 != 0) {
      func_0x000188141240();
    }
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return;
}



/* ==== _lzw_filter_rewind @ 183f853f4 size=136 ==== */

void _lzw_filter_rewind(long *param_1)

{
  undefined8 uVar1;
  long lVar2;
  
  if ((undefined8 *)*param_1 == (undefined8 *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined8 *)*param_1;
  }
  FUN_183d23b30(uVar1);
  lVar2 = *param_1;
  if (lVar2 != 0) {
    *(undefined2 *)(lVar2 + 8) = 0;
    *(undefined8 *)(lVar2 + 0x442c) = 0;
    *(undefined8 *)(lVar2 + 0x4438) = 0;
    func_0x0001881382e0(lVar2 + 0x10,0x410);
    func_0x000188138390(*(undefined8 *)(lVar2 + 0x4448));
    *(undefined8 *)(lVar2 + 0x4448) = 0;
    *(undefined8 *)(lVar2 + 0x4440) = 0;
    *(undefined4 *)(lVar2 + 0x420) = 9;
    *(undefined4 *)(lVar2 + 0x4424) = 0x102;
    *(undefined2 *)(lVar2 + 0x4428) = 0;
  }
  return;
}



/* ==== _lzw_filter_refill @ 183f8547c size=788 ==== */

long _lzw_filter_refill(long *param_1,long param_2,long param_3)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  ulong uVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  ulong uVar8;
  
  lVar6 = *param_1;
  if ((lVar6 == 0) || ((*(byte *)(lVar6 + 9) & 1) != 0)) {
    lVar7 = 0;
  }
  else {
    lVar7 = 0;
    uVar4 = *(ulong *)(lVar6 + 0x4438);
    do {
      lVar5 = 0;
      if (uVar4 != 0) {
        uVar8 = uVar4;
        if ((ulong)(param_3 - lVar7) <= uVar4) {
          uVar8 = param_3 - lVar7;
        }
        func_0x0001881384d0(param_2 + lVar7,
                            (*(long *)(lVar6 + 0x4448) + *(long *)(lVar6 + 0x4440)) - uVar4,uVar8);
        lVar7 = uVar8 + lVar7;
        lVar5 = *(long *)(lVar6 + 0x4438) - uVar8;
        *(long *)(lVar6 + 0x4438) = lVar5;
      }
      if (lVar7 == param_3) {
        return param_3;
      }
      if ((*(byte *)(lVar6 + 8) & 1) != 0) {
        return lVar7;
      }
      if (lVar5 != 0) {
                    /* WARNING: Subroutine does not return */
        FUN_183c19214("lzw_decode",0xbb,
                      "/Library/Caches/com.apple.xbs/418A84E5-A935-45BB-BEF3-31726BD24C5D/TemporaryDirectory.myKecQ/Sources/CoreGraphics/CoreGraphics/PDF/Filters/LZW/lzw-decode.c"
                      ,"d->pending == 0","pending (%lu) is nonzero for decoder %p");
      }
      uVar4 = _lzw_read_code(lVar6);
      uVar3 = (uint)uVar4;
      if (uVar3 == 0x100) {
        *(undefined4 *)(lVar6 + 0x420) = 9;
        *(undefined2 *)(lVar6 + 0x4424) = 0x102;
        *(undefined2 *)(lVar6 + 0x4428) = 0;
        uVar4 = _lzw_read_code(lVar6);
        if ((int)uVar4 == 0x101) goto LAB_183f855a8;
        *(short *)(lVar6 + 0x4428) = (short)uVar4;
        *(short *)(lVar6 + 0x4426) = (short)uVar4;
LAB_183f855c0:
        _lzw_push(lVar6,uVar4);
      }
      else if (uVar3 == 0x101) {
LAB_183f855a8:
        *(undefined1 *)(lVar6 + 8) = 1;
      }
      else {
        if (0xfff < *(ushort *)(lVar6 + 0x4424)) goto LAB_183f855c0;
        uVar8 = uVar4;
        if (*(ushort *)(lVar6 + 0x4424) <= uVar3) {
          uVar8 = (ulong)*(ushort *)(lVar6 + 0x4426);
          _lzw_push(lVar6,*(undefined2 *)(lVar6 + 0x4428));
        }
        do {
          if ((uint)uVar8 < 0x100) {
            _lzw_push(lVar6,uVar8);
            *(short *)(lVar6 + 0x4428) = (short)uVar8;
            if (0xfff < *(ushort *)(lVar6 + 0x4426)) {
                    /* WARNING: Subroutine does not return */
              FUN_183c19214("lzw_decode",0xfb,
                            "/Library/Caches/com.apple.xbs/418A84E5-A935-45BB-BEF3-31726BD24C5D/TemporaryDirectory.myKecQ/Sources/CoreGraphics/CoreGraphics/PDF/Filters/LZW/lzw-decode.c"
                            ,"d->oldCode < LZW_TABLE_SIZE",
                            "lzw table building: old code (%u) is outside of table bounds (%u)");
            }
            *(ushort *)(lVar6 + 0x424 + (ulong)*(ushort *)(lVar6 + 0x4424) * 2) =
                 *(ushort *)(lVar6 + 0x4426);
            *(undefined2 *)(lVar6 + 0x2424 + (ulong)*(ushort *)(lVar6 + 0x4424) * 2) =
                 *(undefined2 *)(lVar6 + 0x4428);
            *(short *)(lVar6 + 0x4426) = (short)uVar4;
            uVar1 = *(short *)(lVar6 + 0x4424) + 1;
            *(ushort *)(lVar6 + 0x4424) = uVar1;
            uVar3 = *(uint *)(lVar6 + 0x420);
            if ((int)uVar3 < 0xc) {
              uVar2 = ((-1 << (ulong)(uVar3 & 0x1f)) + (uint)*(byte *)(lVar6 + 10) ^ 0xffffffff) &
                      0xffff;
              if (uVar2 < uVar1) {
                if (uVar2 + 1 != (uint)uVar1) {
                    /* WARNING: Subroutine does not return */
                  FUN_183c19214("lzw_decode",0x10a,
                                "/Library/Caches/com.apple.xbs/418A84E5-A935-45BB-BEF3-31726BD24C5D/TemporaryDirectory.myKecQ/Sources/CoreGraphics/CoreGraphics/PDF/Filters/LZW/lzw-decode.c"
                                ,"d->freeCode == maxCode + 1",
                                "sanity check failed that the free code(%u) should be maxCode(%u) +1"
                               );
                }
                *(uint *)(lVar6 + 0x420) = uVar3 + 1;
              }
            }
            goto LAB_183f855c4;
          }
          if (0xfff < (uint)uVar8) {
                    /* WARNING: Subroutine does not return */
            FUN_183c19214("lzw_decode",0xea,
                          "/Library/Caches/com.apple.xbs/418A84E5-A935-45BB-BEF3-31726BD24C5D/TemporaryDirectory.myKecQ/Sources/CoreGraphics/CoreGraphics/PDF/Filters/LZW/lzw-decode.c"
                          ,"code < LZW_TABLE_SIZE","lzw code (%u) is outside of table bounds (%u)");
          }
          _lzw_push(lVar6,*(undefined2 *)(lVar6 + 0x2424 + (uVar8 & 0xffffffff) * 2));
          uVar8 = (ulong)*(ushort *)(lVar6 + 0x424 + (uVar8 & 0xffffffff) * 2);
        } while (*(ulong *)(lVar6 + 0x4438) >> 1 < 0x801);
        _pdf_error("LZW decode: invalid chain sequence.");
        *(undefined1 *)(lVar6 + 9) = 1;
      }
LAB_183f855c4:
      uVar4 = *(ulong *)(lVar6 + 0x4438);
    } while (uVar4 != 0);
  }
  return lVar7;
}



/* ==== _lzw_filter_finalize @ 183f85790 size=68 ==== */

/* WARNING: Control flow encountered bad instruction data */

void _lzw_filter_finalize(undefined8 *param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if (param_1 == (undefined8 *)0x0) {
    return;
  }
  _lzw_decoder_release(*param_1);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0x183f857cc);
    (*pcVar1)();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* ==== _ascii_hex_filter_refill @ 183f9291c size=324 ==== */

ulong _ascii_hex_filter_refill(undefined8 *param_1,long param_2,ulong param_3)

{
  uint uVar1;
  uint uVar2;
  ulong uVar3;
  int iVar4;
  ulong uVar5;
  uint uVar6;
  byte bVar7;
  
  uVar5 = 0;
  if ((param_3 != 0) && ((*(byte *)(param_1 + 1) & 1) == 0)) {
    uVar5 = 0;
    bVar7 = 0;
    uVar6 = 0;
LAB_183f92978:
    do {
      uVar2 = FUN_183bdf3b0(*param_1);
      uVar1 = 0x3e;
      if (uVar2 != 0xffffffff) {
        uVar1 = uVar2;
      }
      uVar3 = (ulong)uVar1;
      if (uVar1 < 0x3f) {
        if ((1L << (uVar3 & 0x3f) & 0x100003601U) != 0) goto LAB_183f92978;
        if ((1L << (uVar3 & 0x3f) & 0x3ff000000000000U) == 0) {
          if (uVar3 == 0x3e) {
            *(undefined1 *)(param_1 + 1) = 1;
            if (bVar7 == 0) {
              return uVar5;
            }
            *(char *)(param_2 + uVar5) = (char)(uVar6 << 4);
            return uVar5 + 1;
          }
          goto LAB_183f929b8;
        }
        iVar4 = -0x30;
      }
      else {
LAB_183f929b8:
        if (uVar1 - 0x41 < 6) {
          iVar4 = -0x37;
        }
        else {
          if (5 < uVar1 - 0x61) {
            _pdf_error("ASCIIHexDecode: invalid character 0x%02x encountered in stream.");
            *(undefined1 *)(param_1 + 1) = 1;
            return 0;
          }
          iVar4 = -0x57;
        }
      }
      uVar6 = uVar1 + iVar4 | uVar6 << 4;
      if ((bool)(bVar7 & 1)) {
        *(char *)(param_2 + uVar5) = (char)uVar6;
        uVar5 = uVar5 + 1;
      }
      bVar7 = bVar7 + 1;
    } while (uVar5 < param_3);
  }
  return uVar5;
}



/* ==== _filter_GetColorTransform @ 183f92b84 size=32 ==== */

undefined8 _filter_GetColorTransform(long param_1)

{
  undefined8 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (((param_1 != 0) && (*(long *)(param_1 + 0x10) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(param_1 + 0x10) + 0x20),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x000183f92b98. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)();
    return uVar1;
  }
  return 0;
}



/* ==== _ascii85_filter_rewind @ 184001b78 size=12 ==== */

void _ascii85_filter_rewind(undefined8 *param_1)

{
  *(undefined1 *)(param_1 + 1) = 0;
  FUN_183d23b30(*param_1);
  return;
}



/* ==== _ascii85_filter_refill @ 184001b84 size=600 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 _ascii85_filter_refill(undefined8 *param_1,undefined8 param_2,ulong param_3)

{
  uint uVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  int iVar4;
  ulong uVar5;
  long lVar6;
  int iVar7;
  ulong uVar8;
  long lVar9;
  long lVar10;
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  byte bVar13;
  byte bVar14;
  byte bVar15;
  byte bVar16;
  byte bVar17;
  byte bVar18;
  byte bVar19;
  
  if ((*(byte *)(param_1 + 1) & 1) != 0) {
    return 0;
  }
  param_1[2] = 0;
  param_1[3] = param_2;
  auVar3 = _DAT_184265930;
  if (4 < param_3) {
    while ((*(byte *)(param_1 + 1) & 1) == 0) {
      iVar7 = 0;
      lVar10 = 0;
      lVar6 = -1;
      uVar8 = 8;
      lVar9 = 5;
      do {
        while( true ) {
          iVar4 = FUN_183bdf3b0(*param_1);
          uVar1 = iVar4 + 1;
          if (0x21 < uVar1) break;
          if ((1L << ((ulong)uVar1 & 0x3f) & 0x200006c02U) == 0) {
            if ((ulong)uVar1 != 0) break;
LAB_184001dac:
            *(undefined1 *)(param_1 + 1) = 1;
            goto LAB_184001db4;
          }
        }
        if (iVar4 == 0x7a) {
          if (lVar10 == 0) {
            lVar10 = 4;
            do {
              lVar6 = param_1[2];
              param_1[2] = lVar6 + 1;
              *(undefined1 *)(param_1[3] + lVar6) = 0;
              lVar10 = lVar10 + -1;
            } while (lVar10 != 0);
            goto LAB_184001d6c;
          }
LAB_184001d9c:
          _pdf_error("ASCII85Decode: invalid character 0x%02x encountered in stream.");
          goto LAB_184001dac;
        }
        if (iVar4 == 0x7e) {
          *(undefined1 *)(param_1 + 1) = 1;
          iVar4 = FUN_183bdf3b0(*param_1);
          if ((lVar10 == 1) || (iVar4 != 0x3e)) {
            _pdf_error("ASCII85Decode: encountered unexpected EOF.");
          }
          else if (lVar10 != 0) {
            iVar7 = iVar7 + 1;
            if (lVar10 != 5) {
              auVar12._8_4_ = 1;
              auVar12._0_8_ = 0x100000000;
              auVar12._12_4_ = 1;
              auVar11._4_12_ = auVar12._4_12_;
              auVar11._0_4_ = iVar7;
              uVar5 = uVar8 & 0xfffffffffffffffc;
              do {
                auVar12 = auVar11;
                auVar11._0_4_ = auVar12._0_4_ * 0x55;
                auVar11._4_4_ = auVar12._4_4_ * 0x55;
                auVar11._8_4_ = auVar12._8_4_ * 0x55;
                auVar11._12_4_ = auVar12._12_4_ * 0x55;
                uVar5 = uVar5 - 4;
              } while (uVar5 != 0);
              uVar5 = lVar9 - 1;
              uVar8 = (uVar8 & 0xfffffffffffffffc) - 4;
              bVar13 = (byte)(uVar8 >> 8);
              bVar14 = (byte)(uVar8 >> 0x10);
              bVar15 = (byte)(uVar8 >> 0x18);
              bVar16 = (byte)(uVar8 >> 0x20);
              bVar17 = (byte)(uVar8 >> 0x28);
              bVar18 = (byte)(uVar8 >> 0x30);
              bVar19 = (byte)(uVar8 >> 0x38);
              auVar2._4_4_ = -(uint)(uVar5 < (uVar8 | 1));
              auVar2._0_4_ = -(uint)(uVar5 < uVar8);
              auVar2._8_4_ = -(uint)(uVar5 < CONCAT17(bVar19 | auVar3[7],
                                                      CONCAT16(bVar18 | auVar3[6],
                                                               CONCAT15(bVar17 | auVar3[5],
                                                                        CONCAT14(bVar16 | auVar3[4],
                                                                                 CONCAT13(bVar15 | 
                                                  auVar3[3],
                                                  CONCAT12(bVar14 | auVar3[2],
                                                           CONCAT11(bVar13 | auVar3[1],
                                                                    (byte)uVar8 | auVar3[0]))))))));
              auVar2._12_4_ =
                   -(uint)(uVar5 < CONCAT17(bVar19 | auVar3[0xf],
                                            CONCAT16(bVar18 | auVar3[0xe],
                                                     CONCAT15(bVar17 | auVar3[0xd],
                                                              CONCAT14(bVar16 | auVar3[0xc],
                                                                       CONCAT13(bVar15 | auVar3[0xb]
                                                                                ,CONCAT12(bVar14 | 
                                                  auVar3[10],
                                                  CONCAT11(bVar13 | auVar3[9],
                                                           (byte)uVar8 | auVar3[8]))))))));
              auVar11 = auVar11 ^ (auVar11 ^ auVar12) & auVar2;
              auVar12 = NEON_ext(auVar11,auVar11,8,1);
              iVar7 = auVar11._0_4_ * auVar12._0_4_ * auVar11._4_4_ * auVar12._4_4_;
            }
            do {
              lVar10 = param_1[2];
              param_1[2] = lVar10 + 1;
              *(char *)(param_1[3] + lVar10) = (char)((uint)iVar7 >> 0x18);
              iVar7 = iVar7 << 8;
              lVar6 = lVar6 + -1;
            } while (lVar6 != 0);
            goto LAB_184001d6c;
          }
          goto LAB_184001db4;
        }
        if (iVar4 - 0x76U < 0xffffffab) goto LAB_184001d9c;
        iVar7 = iVar4 + iVar7 * 0x55 + -0x21;
        lVar10 = lVar10 + 1;
        lVar9 = lVar9 + -1;
        uVar8 = uVar8 - 1;
        lVar6 = lVar6 + 1;
      } while (lVar10 != 5);
      lVar10 = 4;
      do {
        lVar6 = param_1[2];
        param_1[2] = lVar6 + 1;
        *(char *)(param_1[3] + lVar6) = (char)((uint)iVar7 >> 0x18);
        iVar7 = iVar7 << 8;
        lVar10 = lVar10 + -1;
      } while (lVar10 != 0);
LAB_184001d6c:
      if (param_3 <= param_1[2] + 4) break;
    }
  }
LAB_184001db4:
  return param_1[2];
}



/* ==== _ascii85_filter_finalize @ 184001ddc size=72 ==== */

/* WARNING: Control flow encountered bad instruction data */

void _ascii85_filter_finalize(long *param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if (param_1 == (long *)0x0) {
    return;
  }
  if (*param_1 != 0) {
    func_0x000188141240();
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0x184001e1c);
    (*pcVar1)();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* ==== _pdf_TIFFFaxMainTable @ 1841d96a0 size=4 ==== */

void _pdf_TIFFFaxMainTable(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)UndefinedInstructionException(0x70c,0x1841d96a0);
  (*pcVar1)();
}



/* ==== _pdf_TIFFFaxWhiteTable @ 1841d98a0 size=4 ==== */

void _pdf_TIFFFaxWhiteTable(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)UndefinedInstructionException(0xb0c,0x1841d98a0);
  (*pcVar1)();
}



/* ==== _pdf_TIFFFaxBlackTable @ 1841dd8a0 size=4 ==== */

void _pdf_TIFFFaxBlackTable(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)UndefinedInstructionException(0xb0c,0x1841dd8a0);
  (*pcVar1)();
}



