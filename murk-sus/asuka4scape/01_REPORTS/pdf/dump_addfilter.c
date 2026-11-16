/* ==== _add_filter @ 183bdc47c size=2148 ==== */

long _add_filter(undefined8 param_1,long param_2,long param_3,long param_4,undefined4 *param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  code *pcVar5;
  byte bVar6;
  int iVar7;
  long *plVar8;
  long lVar9;
  undefined8 *puVar10;
  ulong uVar11;
  long *plVar12;
  long lVar13;
  undefined4 *puVar14;
  char *pcVar15;
  undefined4 uVar16;
  undefined2 *puVar17;
  ulong unaff_x30;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined8 uVar20;
  ulong local_60;
  ulong local_58;
  
  if (param_3 == 0) {
    _pdf_error("filter name cannot be null.");
    return 0;
  }
  iVar7 = _filter_kind_from_name(param_3);
  if (9 < iVar7 - 1U) {
    return 0;
  }
  switch(iVar7) {
  default:
    if (param_5 != (undefined4 *)0x0) {
      *param_5 = 0;
    }
    plVar8 = (long *)func_0x000188138460(1,0x10,0x10200405f07fb98);
    if (plVar8 == (long *)0x0) {
      return 0;
    }
    *(undefined1 *)(plVar8 + 1) = 0;
    if (param_2 != 0) {
      func_0x000188141250(param_2);
    }
    *plVar8 = param_2;
    lVar9 = _CGPDFSourceCreateInternal(0xf80);
    if (lVar9 != 0) {
      puVar10 = (undefined8 *)&DAT_1e222de88;
LAB_183bdc794:
      *(undefined1 *)(lVar9 + 0xd1) = 1;
      uVar18 = *puVar10;
      uVar20 = puVar10[3];
      uVar19 = puVar10[2];
      *(undefined8 *)(lVar9 + 0x38) = puVar10[1];
      *(undefined8 *)(lVar9 + 0x30) = uVar18;
      *(undefined8 *)(lVar9 + 0x48) = uVar20;
      *(undefined8 *)(lVar9 + 0x40) = uVar19;
      *(long **)(lVar9 + 0x50) = plVar8;
      return lVar9;
    }
    break;
  case 2:
    if (param_5 != (undefined4 *)0x0) {
      *param_5 = 0;
    }
    plVar8 = (long *)func_0x000188138460(1,0x20,0x10300404b55cad2);
    if (plVar8 == (long *)0x0) {
      return 0;
    }
    *(undefined1 *)(plVar8 + 1) = 0;
    if (param_2 != 0) {
      func_0x000188141250(param_2);
    }
    *plVar8 = param_2;
    lVar9 = _CGPDFSourceCreateInternal(0xf80);
    if (lVar9 != 0) {
      puVar10 = (undefined8 *)&DAT_1e222dea8;
      goto LAB_183bdc794;
    }
    break;
  case 3:
    if (param_5 != (undefined4 *)0x0) {
      *param_5 = 0;
    }
    plVar8 = (long *)func_0x000188138460(1,0x28,0x1020040239958b0);
    if (plVar8 == (long *)0x0) {
      return 0;
    }
    *(undefined4 *)(plVar8 + 2) = 0;
    *(undefined4 *)((long)plVar8 + 0x14) = 0x6c0;
    *(undefined4 *)((long)plVar8 + 0xc) = 0;
    *(undefined4 *)(plVar8 + 3) = 0x10000;
    *(undefined4 *)((long)plVar8 + 0x1c) = 0;
    if (param_4 != 0) {
      local_58 = 0;
      local_60 = local_60 & 0xffffffffffffff00;
      iVar7 = FUN_183bd6c4c(param_4,"K",&local_58);
      if (iVar7 != 0) {
        if (local_58 == (long)(int)local_58) {
          *(int *)((long)plVar8 + 0xc) = (int)local_58;
        }
        else {
          _pdf_error("/%s is outside the range of allowed values.");
        }
      }
      iVar7 = FUN_183bdf1c8(param_4,"EndOfLine",&local_60);
      if (iVar7 != 0) {
        *(bool *)(plVar8 + 3) = (char)local_60 != '\0';
      }
      iVar7 = FUN_183bdf1c8(param_4,"EncodedByteAlign",&local_60);
      if (iVar7 != 0) {
        *(bool *)((long)plVar8 + 0x19) = (char)local_60 != '\0';
      }
      iVar7 = FUN_183bd6c4c(param_4,"Columns",&local_58);
      if (iVar7 != 0) {
        if (local_58 >> 0x1f == 0) {
          *(int *)((long)plVar8 + 0x14) = (int)local_58;
        }
        else {
          _pdf_error("/%s is outside the range of allowed values.");
        }
      }
      iVar7 = FUN_183bd6c4c(param_4,"Rows",&local_58);
      if (iVar7 != 0) {
        if (local_58 >> 0x1f == 0) {
          *(int *)(plVar8 + 2) = (int)local_58;
        }
        else {
          _pdf_error("/%s is outside the range of allowed values.");
        }
      }
      iVar7 = FUN_183bdf1c8(param_4,"EndOfBlock",&local_60);
      if (iVar7 != 0) {
        *(bool *)((long)plVar8 + 0x1a) = (char)local_60 != '\0';
      }
      iVar7 = FUN_183bdf1c8(param_4,"BlackIs1",&local_60);
      if (iVar7 != 0) {
        *(bool *)((long)plVar8 + 0x1b) = (char)local_60 != '\0';
      }
      iVar7 = FUN_183bd6c4c(param_4,"DamagedRowsBeforeError",&local_58);
      if (iVar7 != 0) {
        if (local_58 >> 0x1f == 0) {
          *(int *)((long)plVar8 + 0x1c) = (int)local_58;
        }
        else {
          _pdf_error("/%s is outside the range of allowed values.");
        }
      }
    }
    iVar7 = *(int *)((long)plVar8 + 0xc);
    uVar16 = 3;
    if (iVar7 < 0) {
      uVar16 = 4;
    }
    uVar4 = (uint)(0 < iVar7) | (uint)*(byte *)(plVar8 + 3) << 1 |
            (uint)*(byte *)((long)plVar8 + 0x19) << 2;
    if (*(char *)((long)plVar8 + 0x1a) == '\x01') {
      uVar4 = uVar4 | 8;
      *(undefined4 *)(plVar8 + 2) = 0;
    }
    if (*(char *)((long)plVar8 + 0x1b) == '\0') {
      uVar4 = uVar4 | 0x10;
    }
    *(undefined1 *)(plVar8 + 1) = 0;
    if (param_2 != 0) {
      func_0x000188141250(param_2);
    }
    *plVar8 = param_2;
    uVar3 = *(uint *)((long)plVar8 + 0x14);
    if (((int)uVar3 < 0x40000000) &&
       (puVar14 = (undefined4 *)func_0x000188138460(1,0x50,0x1090040b0f722c2),
       puVar14 != (undefined4 *)0x0)) {
      *puVar14 = uVar16;
      puVar14[1] = uVar4;
      iVar1 = uVar3 + 0xe;
      if (-8 < (int)uVar3) {
        iVar1 = uVar3 + 7;
      }
      puVar14[2] = iVar1 >> 3;
      puVar14[3] = uVar3;
      uVar2 = uVar3 * 2 + 0x3e & 0xffffffc0;
      if (-1 < iVar7 && (uVar4 & 1) == 0) {
        uVar2 = uVar3;
      }
      lVar9 = func_0x000188138470((ulong)uVar2 * 4 + 0xc,0x1000040bdfb0063);
      *(long *)(puVar14 + 8) = lVar9;
      if (lVar9 != 0) {
        *(long *)(puVar14 + 0xc) = lVar9;
        puVar14[0xe] = uVar2;
        if (-1 < iVar7 && (uVar4 & 1) == 0) {
          puVar17 = (undefined2 *)0x0;
        }
        else {
          lVar9 = lVar9 + (ulong)uVar2 * 2;
          puVar17 = (undefined2 *)(lVar9 + 6);
          *puVar17 = (short)puVar14[3];
          *(undefined2 *)(lVar9 + 8) = 0;
        }
        *(undefined2 **)(puVar14 + 10) = puVar17;
        *(undefined8 *)(puVar14 + 4) = 0;
        puVar14[6] = 0;
        plVar8[4] = (long)puVar14;
        *(code **)(puVar14 + 0x10) = _ccitt_fax_filter_getc;
        *(long *)(puVar14 + 0x12) = param_2;
        iVar7 = *(int *)((long)plVar8 + 0x14);
        uVar4 = iVar7 + 0xe;
        if (-8 < iVar7) {
          uVar4 = iVar7 + 7;
        }
        lVar9 = _CGPDFSourceCreateInternal((long)((ulong)uVar4 << 0x20) >> 0x23);
        if (lVar9 != 0) {
          *(undefined1 *)(lVar9 + 0xd1) = 1;
          *(undefined8 *)(lVar9 + 0x38) = 0x8010000003ca41cc;
          *(undefined8 *)(lVar9 + 0x30) = 0;
          *(undefined8 *)(lVar9 + 0x48) = 0;
          *(undefined8 *)(lVar9 + 0x40) = 0x8020000003ca60f8;
          *(long **)(lVar9 + 0x50) = plVar8;
          return lVar9;
        }
        goto LAB_183bdcbe4;
      }
    }
    plVar8[4] = 0;
LAB_183bdcbe4:
    _ccitt_fax_filter_finalize(plVar8);
    return 0;
  case 4:
    if (param_5 == (undefined4 *)0x0) goto LAB_183bdc85c;
    uVar16 = 1;
    goto LAB_183bdc858;
  case 5:
    if (param_5 != (undefined4 *)0x0) {
      *param_5 = 0;
    }
    if (param_2 == 0) {
      return 0;
    }
    puVar10 = (undefined8 *)func_0x000188138470(0x88,0x10b004050fb1e12);
    if (puVar10 == (undefined8 *)0x0) {
      return 0;
    }
    *(undefined4 *)((long)puVar10 + 0x6f) = 0;
    puVar10[0xb] = 0;
    puVar10[10] = 0;
    puVar10[0xd] = 0;
    puVar10[0xc] = 0;
    puVar10[7] = 0;
    puVar10[6] = 0;
    puVar10[9] = 0;
    puVar10[8] = 0;
    puVar10[3] = 0;
    puVar10[2] = 0;
    puVar10[5] = 0;
    puVar10[4] = 0;
    puVar10[1] = 0;
    *puVar10 = 0;
    func_0x000188141250(param_2);
    puVar10[0xf] = param_2;
    lVar9 = func_0x000188138470(0xf00,0xa07d9450);
    puVar10[0x10] = lVar9;
    if (lVar9 != 0) {
      iVar7 = func_0x00018814d420(puVar10,"1.2.12",0x70);
      if (iVar7 == 0) {
        lVar9 = _CGPDFSourceCreateInternal(0x3000);
        if (lVar9 == 0) {
          _fstream_release(puVar10);
          return 0;
        }
        *(undefined1 *)(lVar9 + 0xd1) = 1;
        *(undefined8 *)(lVar9 + 0x38) = 0x8010000003bdcf08;
        *(undefined8 *)(lVar9 + 0x30) = 0x8010000003ed7fb0;
        *(undefined8 *)(lVar9 + 0x48) = 0x8020000003bf4734;
        *(undefined8 *)(lVar9 + 0x40) = 0x8010000003bda9a0;
        *(undefined8 **)(lVar9 + 0x50) = puVar10;
        local_58 = 0;
        iVar7 = FUN_183bd6c4c(param_4,"Predictor",&local_58);
        uVar11 = local_58;
        goto joined_r0x000183bdc91c;
      }
      if (puVar10[6] == 0) {
        pcVar15 = "FlateDecode: initialization error.";
      }
      else {
        pcVar15 = "FlateDecode: initialization error: %s.";
      }
      _pdf_error(pcVar15);
    }
    _fstream_release(puVar10);
    return 0;
  case 6:
    if (param_5 != (undefined4 *)0x0) {
      *param_5 = 0;
    }
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0xc471,0x183bdc7e4);
      (*pcVar5)();
    }
    lVar9 = _pdf_source_create_jbig2_filter(param_2,param_1,param_4);
    return lVar9;
  case 7:
    if (param_5 != (undefined4 *)0x0) {
      *param_5 = 0;
    }
    bVar6 = 1;
    plVar8 = (long *)func_0x000188138460(1,0x10,0x10200405f07fb98);
    if (plVar8 == (long *)0x0) {
      return 0;
    }
    local_60 = 0;
    local_58 = 0;
    *(undefined1 *)(plVar8 + 1) = 1;
    if (param_4 != 0) {
      uVar11 = FUN_183bd6c4c(param_4,"EarlyChange",&local_58);
      if ((uVar11 & 1) == 0) {
        bVar6 = *(byte *)(plVar8 + 1);
      }
      else {
        bVar6 = local_58 != 0;
        *(byte *)(plVar8 + 1) = bVar6;
      }
    }
    plVar12 = (long *)func_0x000188138460(1,0x4450,0x1030040eb8d5a71);
    if (plVar12 != (long *)0x0) {
      if (param_2 != 0) {
        func_0x000188141250(param_2);
      }
      *plVar12 = param_2;
      *(byte *)((long)plVar12 + 10) = bVar6 & 1;
      *(undefined4 *)(plVar12 + 0x84) = 9;
      *(undefined2 *)((long)plVar12 + 0x4424) = 0x102;
      *(undefined2 *)(plVar12 + 0x885) = 0;
      *plVar8 = (long)plVar12;
      lVar9 = _CGPDFSourceCreateInternal(0xf80);
      if (lVar9 == 0) {
        _lzw_decoder_release(*plVar8);
        func_0x000188138390(plVar8);
        return 0;
      }
      *(undefined1 *)(lVar9 + 0xd1) = 1;
      *(undefined8 *)(lVar9 + 0x38) = 0x8010000003f8547c;
      *(undefined8 *)(lVar9 + 0x30) = 0x8010000003f853f4;
      *(undefined8 *)(lVar9 + 0x48) = 0;
      *(undefined8 *)(lVar9 + 0x40) = 0x8020000003f85790;
      *(long **)(lVar9 + 0x50) = plVar8;
      iVar7 = FUN_183bd6c4c(param_4,"Predictor",&local_60);
      uVar11 = local_60;
joined_r0x000183bdc91c:
      if (iVar7 == 0) {
        return lVar9;
      }
      if (uVar11 != 1) {
        if (uVar11 == 2) {
          lVar13 = _pdf_source_create_predictor2_filter();
        }
        else {
          lVar13 = _pdf_source_create_png_filter(lVar9,param_4);
        }
        func_0x000188141240(lVar9);
        return lVar13;
      }
      return lVar9;
    }
    goto LAB_183bdc948;
  case 8:
    if (param_5 != (undefined4 *)0x0) {
      *param_5 = 0;
    }
    plVar8 = (long *)func_0x000188138460(1,0x20,0x10300404b55cad2);
    if (plVar8 == (long *)0x0) {
      return 0;
    }
    *(undefined1 *)(plVar8 + 1) = 0;
    if (param_2 != 0) {
      func_0x000188141250(param_2);
    }
    *plVar8 = param_2;
    lVar9 = _CGPDFSourceCreateInternal(0xf00);
    if (lVar9 != 0) {
      puVar10 = (undefined8 *)&DAT_1e222dda8;
      goto LAB_183bdc794;
    }
    break;
  case 9:
    if (param_5 == (undefined4 *)0x0) goto LAB_183bdc85c;
    uVar16 = 2;
LAB_183bdc858:
    *param_5 = uVar16;
LAB_183bdc85c:
    if (param_2 != 0) {
      func_0x000188141250(param_2);
      return param_2;
    }
    return 0;
  case 10:
    if (param_5 != (undefined4 *)0x0) {
      *param_5 = 0;
    }
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0xc471,0x183bdc648);
      (*pcVar5)();
    }
    lVar9 = _add_crypt_filter(param_1,param_2,param_4);
    return lVar9;
  }
  if (*plVar8 != 0) {
    func_0x000188141240();
  }
LAB_183bdc948:
  func_0x000188138390(plVar8);
  return 0;
}



