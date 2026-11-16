/* ==== _CGPDFStreamFinalize @ 183be0be4 size=80 ==== */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Possible PIC construction at 0x000183be0c00: Changing call to branch */

void _CGPDFStreamFinalize(long param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if (*(long *)(param_1 + 0x30) == 0) {
    if (*(long *)(param_1 + 0x48) == 0) {
      return;
    }
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xc471,0x183be0c24);
      (*pcVar1)();
    }
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* ==== ___CGPDFStreamGetTypeID_block_invoke @ 183bee1f8 size=40 ==== */

void ___CGPDFStreamGetTypeID_block_invoke(void)

{
  DAT_1edf35140 = _pdf_register_cftype(&DAT_1e2238770);
  return;
}



/* ==== _CGPDFStreamContextCreate @ 183ca99c8 size=104 ==== */

undefined8 _CGPDFStreamContextCreate(undefined8 param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = FUN_183b1e20c();
  uVar2 = 0;
  if (lVar1 != 0) {
    FUN_183b1e270(lVar1,&DAT_1e22311b8,7);
    uVar2 = FUN_183b1dab0(lVar1,1,0,0,param_1,0);
    func_0x000188141240(lVar1);
  }
  return uVar2;
}



/* ==== _xref_stream_create @ 183ced3f4 size=1008 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long _xref_stream_create(long param_1)

{
  int iVar1;
  ulong uVar2;
  long lVar3;
  long lVar4;
  long *plVar5;
  char *pcVar6;
  undefined8 *puVar7;
  long lVar8;
  long *plVar9;
  long lVar10;
  long *plVar11;
  long lVar12;
  undefined8 uVar13;
  long lVar14;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 uStack_d0;
  undefined8 uStack_c8;
  long local_c0;
  undefined8 local_b8;
  undefined4 local_ac;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  int local_8c;
  long local_88;
  ulong local_80 [4];
  
  local_80[3] = *_DAT_1e0186220;
  local_c0 = 0;
  uStack_d8 = 0;
  local_e0 = 0;
  uStack_c8 = 0;
  uStack_d0 = 0;
  FUN_183bcd514(*(undefined8 *)(param_1 + 8));
  uVar2 = _pdf_object_scanner_read_indirect_object(param_1,&local_e0);
  lVar8 = local_c0;
  if ((uVar2 & 1) == 0) {
    _pdf_error("missing or invalid cross-reference stream.");
  }
  else {
    if ((int)uStack_d8 == 9) {
      if (local_c0 != 0) {
        *(undefined1 *)(local_c0 + 0x29) = 1;
      }
      lVar3 = func_0x000188138460(1,0x18,0x102004023cb03e4);
      func_0x000188142e40(lVar3,"CGPDFNamedAlloc_XRef");
      if (lVar3 != 0) {
        if (lVar8 == 0) {
          lVar12 = 0;
        }
        else {
          lVar12 = *(long *)(lVar8 + 0x30);
          if (lVar12 != 0) {
            func_0x000188141250(lVar12);
          }
        }
        local_b8 = 0;
        *(long *)(lVar3 + 8) = lVar12;
        uVar2 = FUN_183bd1218(lVar12,"Type",&local_b8);
        if ((uVar2 & 1) == 0) {
          pcVar6 = "invalid xref stream: missing or invalid `Type\' value.";
LAB_183ced540:
          _pdf_error(pcVar6);
        }
        else {
          iVar1 = func_0x0001881386b0(local_b8,"XRef");
          if (iVar1 != 0) {
            pcVar6 = "invalid xref stream: unrecognized `Type\' value: %s.";
            goto LAB_183ced540;
          }
          local_88 = 0;
          local_8c = 0;
          local_a0 = 0;
          local_98 = 0;
          local_a8 = 0;
          iVar1 = FUN_183bd6c4c(*(undefined8 *)(lVar3 + 8),"Size",&local_98);
          if (iVar1 == 0) {
            pcVar6 = "invalid xref stream: missing or invalid `Size\' value.";
            goto LAB_183ced540;
          }
          iVar1 = FUN_183ee2a18(*(undefined8 *)(lVar3 + 8),"W",local_80,3);
          if (iVar1 == 0) {
            pcVar6 = "invalid xref stream: missing or invalid `W\' value.";
            goto LAB_183ced540;
          }
          lVar12 = 0;
          lVar10 = 3;
          pcVar6 = "invalid xref stream: invalid `W\' value.";
          do {
            if (8 < local_80[lVar12]) goto LAB_183ced540;
            lVar12 = lVar12 + 1;
            lVar10 = lVar10 + -1;
          } while (lVar10 != 0);
          local_ac = 6;
          lVar8 = _CGPDFStreamCreateFilterChainExcluding(lVar8,&local_ac,1,&local_8c);
          if ((lVar8 != 0) && (local_8c == 0)) {
            uVar2 = FUN_183bcf620(*(undefined8 *)(lVar3 + 8),"Index",&local_88);
            lVar12 = local_88;
            if ((uVar2 & 1) == 0) {
              lVar12 = _xref_stream_read_section(lVar8,local_80,0,local_98);
              if (lVar12 == 0) goto LAB_183ced780;
              uVar13 = *(undefined8 *)(lVar3 + 0x10);
              puVar7 = (undefined8 *)func_0x000188138460(1,0x10,0xa0040aff93c70);
              *puVar7 = uVar13;
              puVar7[1] = lVar12;
              *(undefined8 **)(lVar3 + 0x10) = puVar7;
            }
            else {
              if (local_88 == 0) {
LAB_183ced790:
                plVar5 = *(long **)(lVar3 + 0x10);
                if (plVar5 != (long *)0x0) goto LAB_183ced798;
                plVar9 = (long *)0x0;
              }
              else {
                lVar10 = *(long *)(local_88 + 0x18) - *(long *)(local_88 + 0x10);
                if (((uint)lVar10 >> 3 & 1) != 0) {
LAB_183ced774:
                  _pdf_error("invalid xref stream: invalid `Index\' value.");
                  goto LAB_183ced780;
                }
                if (*(long *)(local_88 + 0x18) == *(long *)(local_88 + 0x10)) goto LAB_183ced790;
                uVar2 = 0;
                do {
                  iVar1 = FUN_183d52894(lVar12,uVar2,&local_a0);
                  if ((iVar1 == 0) ||
                     (iVar1 = FUN_183d52894(lVar12,uVar2 + 1,&local_a8), iVar1 == 0))
                  goto LAB_183ced774;
                  lVar4 = _xref_stream_read_section(lVar8,local_80,local_a0,local_a8);
                  if (lVar4 == 0) goto LAB_183ced780;
                  lVar14 = *(long *)(lVar3 + 0x10);
                  plVar5 = (long *)func_0x000188138460(1,0x10,0xa0040aff93c70);
                  *plVar5 = lVar14;
                  plVar5[1] = lVar4;
                  *(long *)(lVar3 + 0x10) = (long)plVar5;
                  uVar2 = uVar2 + 2;
                } while (uVar2 < (ulong)(lVar10 >> 3));
LAB_183ced798:
                plVar11 = (long *)0x0;
                do {
                  plVar9 = plVar5;
                  plVar5 = (long *)*plVar9;
                  *plVar9 = (long)plVar11;
                  plVar11 = plVar9;
                } while (plVar5 != (long *)0x0);
              }
              *(long **)(lVar3 + 0x10) = plVar9;
            }
            func_0x000188141240(lVar8);
            if ((int)uStack_d8 - 5U < 5) {
              _pdf_object_release_compound_value(&local_e0);
            }
            goto LAB_183ced568;
          }
          _pdf_error("invalid xref stream: invalid or disallowed `Filter\' value.");
          if (lVar8 != 0) {
LAB_183ced780:
            func_0x000188141240(lVar8);
          }
        }
        if ((int)uStack_d8 - 5U < 5) {
          _pdf_object_release_compound_value(&local_e0);
        }
        _xref_stream_release(lVar3);
        goto LAB_183ced564;
      }
    }
    else {
      _pdf_error("missing or invalid cross-reference stream.");
    }
    if ((int)uStack_d8 - 5U < 5) {
      _pdf_object_release_compound_value(&local_e0);
    }
  }
LAB_183ced564:
  lVar3 = 0;
LAB_183ced568:
  if (*_DAT_1e0186220 != local_80[3]) {
    lVar8 = func_0x000188138130();
    return lVar8;
  }
  return lVar3;
}



/* ==== __ZNK9ToUnicode13create_streamINSt3__13setItNS1_4lessItEENS1_9allocatorItEEEEEEP11CGPDFStreamRKT_ @ 183cf04e4 size=188 ==== */

undefined8
__ZNK9ToUnicode13create_streamINSt3__13setItNS1_4lessItEENS1_9allocatorItEEEEEEP11CGPDFStreamRKT_
          (undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  
  lVar1 = func_0x00018814c4e0(0,0);
  lVar2 = FUN_183c87290();
  __ZNK9ToUnicode15write_ToUnicodeEP14CGDataConsumerRKNSt3__13setItNS2_4lessItEENS2_9allocatorItEEEE
            (param_1,lVar2,param_2);
  if (lVar2 != 0) {
    func_0x000188141240(lVar2);
  }
  lVar2 = _CGPDFDictionaryCreateWithObjects(0,0);
  uVar3 = func_0x000188140ab0(lVar1);
  __ZN2CG20PDFDictionaryMutator10setIntegerEPKcl(lVar2,"Length",uVar3);
  uVar3 = FUN_183fe4d5c(lVar2,0,lVar1);
  if (lVar2 != 0) {
    func_0x000188141240(lVar2);
  }
  if (lVar1 != 0) {
    func_0x000188141240(lVar1);
  }
  return uVar3;
}



/* ==== __ZNK9ToUnicode13create_streamINSt3__16vectorItNS1_9allocatorItEEEEEEP11CGPDFStreamRKT_ @ 183cf0600 size=188 ==== */

undefined8
__ZNK9ToUnicode13create_streamINSt3__16vectorItNS1_9allocatorItEEEEEEP11CGPDFStreamRKT_
          (undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  
  lVar1 = func_0x00018814c4e0(0,0);
  lVar2 = FUN_183c87290();
  __ZNK9ToUnicode15write_ToUnicodeEP14CGDataConsumerRKNSt3__16vectorItNS2_9allocatorItEEEE
            (param_1,lVar2,param_2);
  if (lVar2 != 0) {
    func_0x000188141240(lVar2);
  }
  lVar2 = _CGPDFDictionaryCreateWithObjects(0,0);
  uVar3 = func_0x000188140ab0(lVar1);
  __ZN2CG20PDFDictionaryMutator10setIntegerEPKcl(lVar2,"Length",uVar3);
  uVar3 = FUN_183fe4d5c(lVar2,0,lVar1);
  if (lVar2 != 0) {
    func_0x000188141240(lVar2);
  }
  if (lVar1 != 0) {
    func_0x000188141240(lVar1);
  }
  return uVar3;
}



/* ==== __ZN2CG20PDFDictionaryMutator9setStreamEPKcP11CGPDFStream @ 183d14130 size=112 ==== */

void __ZN2CG20PDFDictionaryMutator9setStreamEPKcP11CGPDFStream
               (undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  long lVar2;
  ulong unaff_x30;
  
  lVar2 = FUN_183e7cc5c(param_3);
  FUN_183ee2d58(param_1,param_2,lVar2);
  if (lVar2 == 0) {
    return;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0x183d1418c);
    (*pcVar1)();
  }
  FUN_183e7cd1c(lVar2);
  return;
}



/* ==== __ZNK14FontDescriptor17create_dictionaryERKNSt3__112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEEP11CGPDFStream @ 183db5f48 size=800 ==== */

undefined8
__ZNK14FontDescriptor17create_dictionaryERKNSt3__112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEEP11CGPDFStream
          (long *param_1,int param_2,long *param_3,long param_4)

{
  long *plVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  char *pcVar6;
  long lVar7;
  long lVar8;
  undefined8 uVar9;
  undefined8 local_110 [4];
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 uStack_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  double local_a8;
  double local_a0;
  double local_98;
  double local_90;
  double local_88;
  double local_80;
  
  uVar3 = _CGPDFDictionaryCreateWithObjects(0,0);
  __ZN2CG20PDFDictionaryMutator7setNameEPKcS2_(uVar3,"Type","FontDescriptor");
  plVar1 = (long *)*param_3;
  if (-1 < *(char *)((long)param_3 + 0x17)) {
    plVar1 = param_3;
  }
  __ZN2CG20PDFDictionaryMutator7setNameEPKcS2_(uVar3,"FontName",plVar1);
  __ZN2CG20PDFDictionaryMutator10setIntegerEPKcl(uVar3,"Flags",(long)param_2);
  iVar2 = FUN_183c10efc(param_1[2],&local_f0);
  if (iVar2 != 0) {
    local_110[1] = uStack_e8;
    local_110[0] = local_f0;
    local_110[3] = uStack_d8;
    local_110[2] = uStack_e0;
    lVar4 = _CGPDFArrayCreateWithObjects(0,0);
    if (lVar4 != 0) {
      lVar7 = 0;
      lVar8 = 0x20;
      do {
        uVar9 = *(undefined8 *)((long)local_110 + lVar7);
        lVar5 = func_0x000188138460(1,0x28,0x103204077d336df);
        *(byte *)(lVar5 + 0xc) = *(byte *)(lVar5 + 0xc) | 1;
        *(undefined4 *)(lVar5 + 8) = 4;
        *(undefined8 *)(lVar5 + 0x20) = uVar9;
        uVar9 = _pdf_object_create_copy();
        __ZNSt3__16vectorIPN10ClipperLib8PolyNodeENS_9allocatorIS3_EEE9push_backB9fqe220106EOS3_
                  (lVar4 + 0x10,uVar9);
        FUN_183e7cd1c(lVar5);
        lVar7 = lVar7 + 8;
        lVar8 = lVar8 + -8;
      } while (lVar8 != 0);
    }
    __ZN2CG20PDFDictionaryMutator8setArrayEPKcP10CGPDFArray(uVar3,"FontBBox",lVar4);
    __ZN2CG20PDFDictionaryMutator7setRealEPKcd(local_b8,uVar3,"ItalicAngle");
    __ZN2CG20PDFDictionaryMutator7setRealEPKcd(local_d0,uVar3,"Ascent");
    __ZN2CG20PDFDictionaryMutator7setRealEPKcd(local_c8,uVar3,"Descent");
    __ZN2CG20PDFDictionaryMutator7setRealEPKcd(local_c0,uVar3,"CapHeight");
    __ZN2CG20PDFDictionaryMutator7setRealEPKcd(local_b0,uVar3,"StemV");
    if (local_88 != 0.0) {
      __ZN2CG20PDFDictionaryMutator7setRealEPKcd(uVar3,"Leading");
    }
    if (local_80 != 0.0) {
      __ZN2CG20PDFDictionaryMutator7setRealEPKcd(uVar3,"XHeight");
    }
    if (local_a8 != 0.0) {
      __ZN2CG20PDFDictionaryMutator7setRealEPKcd(uVar3,"StemH");
    }
    if (local_a0 != 0.0) {
      __ZN2CG20PDFDictionaryMutator7setRealEPKcd(uVar3,"AvgWidth");
    }
    if (local_98 != 0.0) {
      __ZN2CG20PDFDictionaryMutator7setRealEPKcd(uVar3,"MaxWidth");
    }
    if (local_90 != 0.0) {
      __ZN2CG20PDFDictionaryMutator7setRealEPKcd(uVar3,"MissingWidth");
    }
    if (lVar4 != 0) {
      func_0x000188141240(lVar4);
    }
  }
  if (param_4 != 0) {
    iVar2 = (**(code **)(*param_1 + 0x10))(param_1);
    if (iVar2 == 2) {
      pcVar6 = "FontFile";
    }
    else {
      iVar2 = (**(code **)(*param_1 + 0x10))(param_1);
      if ((iVar2 == 3) || (iVar2 = (**(code **)(*param_1 + 0x10))(param_1), iVar2 == 4)) {
        pcVar6 = "FontFile3";
      }
      else {
        pcVar6 = "FontFile2";
      }
    }
    __ZN2CG20PDFDictionaryMutator9setStreamEPKcP11CGPDFStream(uVar3,pcVar6,param_4);
  }
  return uVar3;
}



/* ==== __ZN2CG15PDFDocumentCore20getPDFImageForStreamEP11CGPDFStream @ 183ef0950 size=1288 ==== */

void __ZN2CG15PDFDocumentCore20getPDFImageForStreamEP11CGPDFStream
               (ulong *param_1,long param_2,long param_3)

{
  long *plVar1;
  ulong uVar2;
  ulong uVar3;
  long lVar4;
  long lVar5;
  ulong uVar6;
  undefined8 *puVar7;
  ulong uVar8;
  long *plVar9;
  long *plVar10;
  ulong uVar11;
  long *plVar12;
  long *plVar13;
  ulong uVar14;
  long *plVar15;
  bool bVar16;
  ulong unaff_x26;
  ulong uVar17;
  float fVar18;
  long *local_78;
  long *local_70;
  undefined8 uStack_68;
  
  if (param_3 == 0) {
    uVar3 = 0;
LAB_183ef09a0:
    *param_1 = uVar3;
    return;
  }
  lVar5 = *(long *)(param_3 + 0x18);
  uVar3 = *(ulong *)(param_3 + 0x20);
  if (lVar5 == 0 && (uVar3 & 0xffff) == 0) {
    uVar3 = _CGPDFImageCreate(param_3);
    goto LAB_183ef09a0;
  }
  func_0x00018814cf00(param_2 + 800);
  plVar10 = (long *)(param_2 + 0x3c8);
  lVar4 = __ZNSt3__112__hash_tableINS_17__hash_value_typeI9pdf_ref_tN10applesauce2CF9ObjectRefIP10CGPDFImageEEEENS_22__unordered_map_hasherIS2_NS_4pairIKS2_S8_EE10PDFRefHash11PDFRefEqualEENS_21__unordered_map_equalIS2_SD_SF_SE_EENS_9allocatorISD_EEE4findIS2_EENS_15__hash_iteratorIPNS_11__hash_nodeIS9_PvEEEERKT_
                    (plVar10,lVar5,uVar3);
  if (lVar4 != 0) {
    unaff_x26 = *(ulong *)(lVar4 + 0x20);
    if (unaff_x26 != 0) {
      func_0x000188141250(unaff_x26);
    }
    *param_1 = unaff_x26;
  }
  func_0x00018814cf10(param_2 + 800);
  if (lVar4 != 0) {
    return;
  }
  func_0x00018814cf20(param_2 + 800);
  lVar4 = __ZNSt3__112__hash_tableINS_17__hash_value_typeI9pdf_ref_tN10applesauce2CF9ObjectRefIP10CGPDFImageEEEENS_22__unordered_map_hasherIS2_NS_4pairIKS2_S8_EE10PDFRefHash11PDFRefEqualEENS_21__unordered_map_equalIS2_SD_SF_SE_EENS_9allocatorISD_EEE4findIS2_EENS_15__hash_iteratorIPNS_11__hash_nodeIS9_PvEEEERKT_
                    (plVar10,lVar5,uVar3);
  if (lVar4 == 0) {
    lVar4 = _CGPDFImageCreate(param_3);
    if (lVar4 != 0) {
      uVar11 = (uVar3 & 0xffff) * -0x395b586ca42e166b;
      uVar17 = ((uVar11 ^ uVar11 >> 0x2f) * -0x395b586ca42e166b ^
               (lVar5 * -0x395b586ca42e166b ^ (ulong)(lVar5 * -0x395b586ca42e166b) >> 0x2f) *
               0x35a98f4d286a90b9 + 0xe6546b64) * -0x395b586ca42e166b + 0xe6546b64;
      uVar11 = *(ulong *)(param_2 + 0x3d0);
      if (uVar11 != 0) {
        uVar6 = uVar11 - 1;
        if ((uVar11 & uVar6) == 0) {
          unaff_x26 = uVar17 & uVar6;
        }
        else {
          unaff_x26 = uVar17;
          if (uVar11 <= uVar17) {
            uVar8 = 0;
            if (uVar11 != 0) {
              uVar8 = uVar17 / uVar11;
            }
            unaff_x26 = uVar17 - uVar8 * uVar11;
          }
        }
        puVar7 = *(undefined8 **)(*plVar10 + unaff_x26 * 8);
        if (puVar7 != (undefined8 *)0x0) {
          for (plVar15 = (long *)*puVar7; plVar15 != (long *)0x0; plVar15 = (long *)*plVar15) {
            uVar8 = plVar15[1];
            if (uVar8 == uVar17) {
              if ((lVar5 == plVar15[2]) &&
                 ((uint)*(ushort *)(plVar15 + 3) == ((uint)uVar3 & 0xffff))) goto LAB_183ef0e30;
            }
            else {
              if ((uVar11 & uVar6) == 0) {
                uVar8 = uVar8 & uVar6;
              }
              else if (uVar11 <= uVar8) {
                uVar14 = 0;
                if (uVar11 != 0) {
                  uVar14 = uVar8 / uVar11;
                }
                uVar8 = uVar8 - uVar14 * uVar11;
              }
              if (uVar8 != unaff_x26) break;
            }
          }
        }
      }
      plVar15 = (long *)func_0x00018814d110(0x28,0x1020c005f33fe60);
      plVar1 = (long *)(param_2 + 0x3d8);
      uStack_68 = 1;
      *plVar15 = 0;
      plVar15[1] = uVar17;
      plVar15[2] = lVar5;
      plVar15[3] = uVar3;
      fVar18 = (float)(*(long *)(param_2 + 0x3e0) + 1);
      plVar15[4] = lVar4;
      local_70 = plVar1;
      if (*(float *)(param_2 + 1000) * (float)uVar11 < fVar18) {
        uVar3 = 1;
        if (2 < uVar11) {
          uVar3 = (ulong)((uVar11 & uVar11 - 1) != 0);
        }
        uVar3 = uVar3 | uVar11 << 1;
        uVar11 = (ulong)(fVar18 / *(float *)(param_2 + 1000));
        if (uVar3 <= uVar11) {
          uVar3 = uVar11;
        }
        local_78 = plVar15;
        if (uVar3 - 1 == 0) {
          uVar3 = 2;
        }
        else if ((uVar3 & uVar3 - 1) != 0) {
          uVar3 = func_0x0001881457f0(uVar3);
        }
        uVar11 = *(ulong *)(param_2 + 0x3d0);
        if (uVar11 < uVar3) {
LAB_183ef0c00:
          if (uVar3 >> 0x3d != 0) {
                    /* WARNING: Subroutine does not return */
            __ZSt28__throw_bad_array_new_lengthB9nqe220106v();
          }
          lVar5 = func_0x00018814d110(uVar3 << 3,0x20c0093837f09);
          bVar16 = false;
LAB_183ef0c24:
          lVar4 = *plVar10;
          *plVar10 = lVar5;
          if (lVar4 != 0) {
            func_0x00018814d0d0(lVar4);
          }
          *(ulong *)(param_2 + 0x3d0) = uVar3;
          uVar11 = uVar3;
          if (!bVar16) {
            lVar5 = *plVar10;
            func_0x0001881382e0(lVar5,uVar3 << 3);
            plVar9 = (long *)*plVar1;
            if (plVar9 != (long *)0x0) {
              uVar6 = plVar9[1];
              uVar8 = uVar3 - 1;
              if ((uVar3 & uVar8) == 0) {
                uVar6 = uVar6 & uVar8;
              }
              else if (uVar3 <= uVar6) {
                uVar14 = 0;
                if (uVar3 != 0) {
                  uVar14 = uVar6 / uVar3;
                }
                uVar6 = uVar6 - uVar14 * uVar3;
              }
              *(long **)(lVar5 + uVar6 * 8) = plVar1;
              plVar12 = (long *)*plVar9;
              while (plVar12 != (long *)0x0) {
                uVar14 = plVar12[1];
                if ((uVar3 & uVar8) == 0) {
                  uVar14 = uVar14 & uVar8;
                }
                else if (uVar3 <= uVar14) {
                  uVar2 = 0;
                  if (uVar3 != 0) {
                    uVar2 = uVar14 / uVar3;
                  }
                  uVar14 = uVar14 - uVar2 * uVar3;
                }
                plVar13 = plVar12;
                if (uVar14 != uVar6) {
                  if (*(long *)(lVar5 + uVar14 * 8) == 0) {
                    *(long **)(lVar5 + uVar14 * 8) = plVar9;
                    uVar6 = uVar14;
                  }
                  else {
                    *plVar9 = *plVar12;
                    *plVar12 = **(undefined8 **)(lVar5 + uVar14 * 8);
                    **(long **)(lVar5 + uVar14 * 8) = (long)plVar12;
                    plVar13 = plVar9;
                  }
                }
                plVar9 = plVar13;
                plVar12 = (long *)*plVar13;
              }
            }
          }
        }
        else if (uVar3 < uVar11) {
          uVar6 = (ulong)((float)*(ulong *)(param_2 + 0x3e0) / *(float *)(param_2 + 1000));
          if ((uVar11 < 3) || ((uVar11 & uVar11 - 1) != 0)) {
            uVar6 = func_0x0001881457f0();
          }
          else if (1 < uVar6) {
            uVar6 = 1L << (-LZCOUNT(uVar6 - 1) & 0x3fU);
          }
          if (uVar3 <= uVar6) {
            uVar3 = uVar6;
          }
          if (uVar3 < uVar11) {
            if (uVar3 != 0) goto LAB_183ef0c00;
            lVar5 = 0;
            bVar16 = true;
            goto LAB_183ef0c24;
          }
          uVar11 = *(ulong *)(param_2 + 0x3d0);
        }
        if ((uVar11 & uVar11 - 1) == 0) {
          unaff_x26 = uVar11 - 1 & uVar17;
        }
        else {
          unaff_x26 = uVar17;
          if (uVar11 <= uVar17) {
            uVar3 = 0;
            if (uVar11 != 0) {
              uVar3 = uVar17 / uVar11;
            }
            unaff_x26 = uVar17 - uVar3 * uVar11;
          }
        }
      }
      lVar5 = *plVar10;
      plVar10 = *(long **)(lVar5 + unaff_x26 * 8);
      if (plVar10 == (long *)0x0) {
        *plVar15 = *plVar1;
        *plVar1 = (long)plVar15;
        *(long **)(lVar5 + unaff_x26 * 8) = plVar1;
        if (*plVar15 != 0) {
          uVar3 = *(ulong *)(*plVar15 + 8);
          if ((uVar11 & uVar11 - 1) == 0) {
            uVar3 = uVar3 & uVar11 - 1;
          }
          else if (uVar11 <= uVar3) {
            uVar17 = 0;
            if (uVar11 != 0) {
              uVar17 = uVar3 / uVar11;
            }
            uVar3 = uVar3 - uVar17 * uVar11;
          }
          *(long **)(lVar5 + uVar3 * 8) = plVar15;
        }
      }
      else {
        *plVar15 = *plVar10;
        *plVar10 = (long)plVar15;
      }
      local_78 = (long *)0x0;
      *(long *)(param_2 + 0x3e0) = *(long *)(param_2 + 0x3e0) + 1;
      __ZNSt3__110unique_ptrINS_11__hash_nodeINS_17__hash_value_typeI9pdf_ref_tN10applesauce2CF9ObjectRefIP10CGPDFImageEEEEPvEENS_22__hash_node_destructorINS_9allocatorISC_EEEEED1B9fqe220106Ev
                (&local_78);
      lVar4 = 0;
LAB_183ef0e30:
      uVar3 = plVar15[4];
      if (uVar3 != 0) {
        func_0x000188141250(uVar3);
      }
      *param_1 = uVar3;
      if (lVar4 != 0) {
        func_0x000188141240(lVar4);
      }
      goto LAB_183ef0aac;
    }
    uVar3 = 0;
  }
  else {
    uVar3 = *(ulong *)(lVar4 + 0x20);
    if (uVar3 != 0) {
      func_0x000188141250(uVar3);
    }
  }
  *param_1 = uVar3;
LAB_183ef0aac:
  func_0x00018814cf30(param_2 + 800);
  return;
}



/* ==== __ZN2CG15PDFDocumentCore18addStreamResourcesEP11CGPDFStream @ 183ef1524 size=804 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __ZN2CG15PDFDocumentCore18addStreamResourcesEP11CGPDFStream(undefined8 param_1,long param_2)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 local_138;
  undefined8 local_130;
  code *local_128;
  undefined *puStack_120;
  undefined8 local_118;
  undefined8 local_110;
  undefined8 local_108;
  undefined8 local_100;
  code *local_f8;
  undefined *puStack_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  code *local_c8;
  undefined *puStack_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  code *local_98;
  undefined *puStack_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  code *local_68;
  undefined *puStack_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  
  if (param_2 != 0) {
    lVar2 = func_0x000188138460(1,0x28,0x103204077d336df);
    *(byte *)(lVar2 + 0xc) = *(byte *)(lVar2 + 0xc) | 1;
    *(undefined4 *)(lVar2 + 8) = 9;
    func_0x000188141250(param_2);
    *(long *)(lVar2 + 0x20) = param_2;
    __ZN2CG15PDFDocumentCore9addObjectEP11CGPDFObject(param_1,lVar2);
    FUN_183e7cd1c(lVar2);
    uVar3 = *(undefined8 *)(param_2 + 0x30);
    local_38 = 0;
    iVar1 = FUN_183bcf4b0(uVar3,"ColorSpace",&local_38);
    if (iVar1 != 0) {
      __ZN2CG15PDFDocumentCore14addObjectGraphEP11CGPDFObject(param_1,local_38);
    }
    local_40 = 0;
    iVar1 = FUN_183bf4260(uVar3,"SMask",&local_40);
    if (iVar1 != 0) {
      __ZN2CG15PDFDocumentCore18addStreamResourcesEP11CGPDFStream(param_1,local_40);
    }
    local_48 = 0;
    iVar1 = FUN_183bd75c4(uVar3,"Resources",&local_48);
    uVar3 = local_48;
    if (iVar1 != 0) {
      local_50 = 0;
      iVar1 = FUN_183bd75c4(local_48,"XObject",&local_50);
      if (iVar1 != 0) {
        local_78 = _DAT_1e0186208;
        local_70 = 0x40000000;
        local_68 = ____ZN2CG15PDFDocumentCore18addStreamResourcesEP11CGPDFStream_block_invoke;
        puStack_60 = &DAT_1e05d97c0;
        local_58 = param_1;
        FUN_183ee2ba0(local_50,&local_78);
      }
      local_80 = 0;
      iVar1 = FUN_183bd75c4(uVar3,"Font",&local_80);
      if (iVar1 != 0) {
        local_a8 = _DAT_1e0186208;
        local_a0 = 0x40000000;
        local_98 = ____ZN2CG15PDFDocumentCore18addStreamResourcesEP11CGPDFStream_block_invoke_2;
        puStack_90 = &DAT_1e05adb48;
        local_88 = param_1;
        FUN_183ee2ba0(local_80,&local_a8);
      }
      local_b0 = 0;
      iVar1 = FUN_183bd75c4(uVar3,"Shading",&local_b0);
      if (iVar1 != 0) {
        local_d8 = _DAT_1e0186208;
        local_d0 = 0x40000000;
        local_c8 = ____ZN2CG15PDFDocumentCore18addStreamResourcesEP11CGPDFStream_block_invoke_3;
        puStack_c0 = &DAT_1e05d97e0;
        local_b8 = param_1;
        FUN_183ee2ba0(local_b0,&local_d8);
      }
      local_e0 = 0;
      iVar1 = FUN_183bd75c4(uVar3,"Pattern",&local_e0);
      if (iVar1 != 0) {
        local_108 = _DAT_1e0186208;
        local_100 = 0x40000000;
        local_f8 = ____ZN2CG15PDFDocumentCore18addStreamResourcesEP11CGPDFStream_block_invoke_4;
        puStack_f0 = &DAT_1e05d9800;
        local_e8 = param_1;
        FUN_183ee2ba0(local_e0,&local_108);
      }
      local_110 = 0;
      iVar1 = FUN_183bd75c4(uVar3,"ColorSpace",&local_110);
      if (iVar1 != 0) {
        local_138 = _DAT_1e0186208;
        local_130 = 0x40000000;
        local_128 = ____ZN2CG15PDFDocumentCore18addStreamResourcesEP11CGPDFStream_block_invoke_5;
        puStack_120 = &DAT_1e05ad9c0;
        local_118 = param_1;
        FUN_183ee2ba0(local_110,&local_138);
      }
    }
  }
  return;
}



/* ==== ____ZN2CG15PDFDocumentCore18addStreamResourcesEP11CGPDFStream_block_invoke @ 183ef1a60 size=56 ==== */

undefined8
____ZN2CG15PDFDocumentCore18addStreamResourcesEP11CGPDFStream_block_invoke
          (long param_1,undefined8 param_2,long param_3)

{
  if ((param_3 != 0) && (*(int *)(param_3 + 8) == 9)) {
    __ZN2CG15PDFDocumentCore18addStreamResourcesEP11CGPDFStream
              (*(undefined8 *)(param_1 + 0x20),*(undefined8 *)(param_3 + 0x20));
  }
  return 1;
}



/* ==== ____ZN2CG15PDFDocumentCore18addStreamResourcesEP11CGPDFStream_block_invoke_2 @ 183ef1a98 size=64 ==== */

undefined8
____ZN2CG15PDFDocumentCore18addStreamResourcesEP11CGPDFStream_block_invoke_2
          (long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  
  uVar1 = *(undefined8 *)(param_1 + 0x20);
  __ZN2CG15PDFDocumentCore9addObjectEP11CGPDFObject(uVar1,param_3);
  __ZN2CG15PDFDocumentCore16addFontResourcesEP11CGPDFObject(uVar1,param_3);
  return 1;
}



/* ==== ____ZN2CG15PDFDocumentCore18addStreamResourcesEP11CGPDFStream_block_invoke_3 @ 183ef1ad8 size=56 ==== */

undefined8
____ZN2CG15PDFDocumentCore18addStreamResourcesEP11CGPDFStream_block_invoke_3
          (long param_1,undefined8 param_2,long param_3)

{
  if ((param_3 != 0) && (*(int *)(param_3 + 8) == 9)) {
    __ZN2CG15PDFDocumentCore18addStreamResourcesEP11CGPDFStream
              (*(undefined8 *)(param_1 + 0x20),*(undefined8 *)(param_3 + 0x20));
  }
  return 1;
}



/* ==== ____ZN2CG15PDFDocumentCore18addStreamResourcesEP11CGPDFStream_block_invoke_4 @ 183ef1b10 size=56 ==== */

undefined8
____ZN2CG15PDFDocumentCore18addStreamResourcesEP11CGPDFStream_block_invoke_4
          (long param_1,undefined8 param_2,long param_3)

{
  if ((param_3 != 0) && (*(int *)(param_3 + 8) == 9)) {
    __ZN2CG15PDFDocumentCore18addStreamResourcesEP11CGPDFStream
              (*(undefined8 *)(param_1 + 0x20),*(undefined8 *)(param_3 + 0x20));
  }
  return 1;
}



/* ==== ____ZN2CG15PDFDocumentCore18addStreamResourcesEP11CGPDFStream_block_invoke_5 @ 183ef1b48 size=36 ==== */

undefined8
____ZN2CG15PDFDocumentCore18addStreamResourcesEP11CGPDFStream_block_invoke_5
          (long param_1,undefined8 param_2,undefined8 param_3)

{
  __ZN2CG15PDFDocumentCore14addObjectGraphEP11CGPDFObject(*(undefined8 *)(param_1 + 0x20),param_3);
  return 1;
}



/* ==== __ZL53CGPDFAppenderCreateCGPDFStreamObjectFromCGDisplayListP13CGPDFAppenderP13CGDisplayList7CGPoint @ 183f24254 size=944 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16]
__ZL53CGPDFAppenderCreateCGPDFStreamObjectFromCGDisplayListP13CGPDFAppenderP13CGDisplayList7CGPoint
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long *plVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  undefined8 uVar5;
  long lVar6;
  ulong uVar7;
  undefined8 uVar8;
  undefined1 auVar9 [16];
  undefined8 local_b8;
  undefined8 local_b0;
  code *local_a8;
  undefined *puStack_a0;
  undefined8 *local_98;
  undefined8 local_90;
  undefined8 *local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  
  uVar8 = *_DAT_1e00fe6a8;
  uVar2 = func_0x00018814c4e0(uVar8,0);
  lVar3 = FUN_183c87290();
  lVar4 = FUN_183e158f4(lVar3,0,0);
  if (lVar3 != 0) {
    func_0x000188141240(lVar3);
  }
  uVar5 = func_0x000188140c00(uVar8,0,_DAT_1e00febc8,_DAT_1e00febd0);
  FUN_183c51214(param_1,param_2,uVar5,&cfstringStruct_1e2244660);
  FUN_183e15dac(lVar4,uVar5);
  FUN_183f00728(lVar4,param_4,0);
  FUN_183e15e94(lVar4);
  FUN_183e15d70(lVar4);
  if (lVar4 != 0) {
    func_0x000188141240(lVar4);
  }
  func_0x000188141240(uVar5);
  lVar3 = FUN_183b538e4(uVar2);
  func_0x000188141240(uVar2);
  lVar4 = FUN_183bd12e0(lVar3);
  if (lVar3 != 0) {
    lVar6 = func_0x000188140d60(lVar3);
    if (DAT_1edf367f0 != -1) {
      func_0x00018813aad0(&DAT_1edf367f0,&DAT_1e223ea08);
    }
    if (lVar6 == DAT_1edf36990) {
      func_0x000188141240(lVar3);
    }
  }
  if (lVar4 == 0) {
    local_68 = 0;
    uVar7 = FUN_183bd75c4(0,"Resources",&local_68);
    if ((uVar7 & 1) == 0) {
      return ZEXT816(0);
    }
    local_70 = 0;
    uVar7 = FUN_183bd75c4(local_68,"XObject",&local_70);
    if ((uVar7 & 1) == 0) {
      return ZEXT816(0);
    }
  }
  else {
    lVar3 = __ZN17CGPDFDocumentImpl7getPageEm(lVar4 + 0x10,1);
    uVar2 = 0;
    if (lVar3 != 0) {
      uVar2 = *(undefined8 *)(*(long *)(lVar3 + 0x10) + 0x30);
    }
    local_68 = 0;
    uVar7 = FUN_183bd75c4(uVar2,"Resources",&local_68);
    if ((uVar7 & 1) == 0) {
LAB_183f243e4:
      func_0x000188141240(lVar4);
      return ZEXT816(0);
    }
    local_70 = 0;
    uVar7 = FUN_183bd75c4(local_68,"XObject",&local_70);
    if ((uVar7 & 1) == 0) goto LAB_183f243e4;
  }
  local_98 = &local_90;
  local_90 = 0;
  local_80 = 0x2000000000;
  local_78 = 0;
  local_b8 = _DAT_1e0186208;
  local_b0 = 0x40000000;
  local_a8 = 
  ____ZL53CGPDFAppenderCreateCGPDFStreamObjectFromCGDisplayListP13CGPDFAppenderP13CGDisplayList7CGPoint_block_invoke
  ;
  puStack_a0 = &DAT_1e05ada68;
  local_88 = local_98;
  FUN_183bdfe74(local_70,&local_b8,0);
  if (local_88[3] == 0) {
    if (lVar4 != 0) {
      func_0x000188141240(lVar4);
    }
  }
  else {
    lVar3 = FUN_183f7b3a8();
    if (lVar3 != 0) {
      auVar9 = _CGPDFAppenderCreateMutableObject(param_3,lVar3);
      func_0x000188141240(lVar3);
      uVar2 = func_0x000188140c00(uVar8,0,_DAT_1e00febc8,_DAT_1e00febd0);
      lVar6 = local_88[3];
      if (lVar6 == 0) {
        uVar8 = 0;
        uVar5 = 0;
      }
      else {
        uVar8 = *(undefined8 *)(lVar6 + 0x18);
        uVar5 = *(undefined8 *)(lVar6 + 0x20);
      }
      FUN_183f7bbec(uVar2,uVar8,uVar5,auVar9._0_8_,auVar9._8_8_);
      if (lVar4 == 0) {
        uVar8 = 0;
        lVar6 = 0;
      }
      else {
        lVar6 = *(long *)(lVar4 + 0x18);
        uVar8 = *(undefined8 *)(lVar4 + 0x10);
        if (*(long *)(lVar4 + 0x18) != 0) {
          plVar1 = (long *)(*(long *)(lVar4 + 0x18) + 8);
          *plVar1 = *plVar1 + 1;
        }
      }
      __ZL33AppendModeDuplicateExternalObjectP13CGPDFAppenderNSt3__110shared_ptrIN2CG15PDFDocumentCoreEEEPKvP14__CFDictionary
                (param_3,uVar8,lVar6,lVar3,uVar2);
      if (lVar6 != 0) {
        __ZNSt3__119__shared_weak_count16__release_sharedB9fqe220106Ev(lVar6);
      }
      func_0x000188141240(uVar2);
      if (lVar4 != 0) {
        func_0x000188141240(lVar4);
      }
      goto LAB_183f245b8;
    }
    if (lVar4 != 0) {
      func_0x000188141240(lVar4);
    }
  }
  auVar9 = ZEXT816(0);
LAB_183f245b8:
  func_0x000188138010(&local_90,8);
  return auVar9;
}



/* ==== ____ZL53CGPDFAppenderCreateCGPDFStreamObjectFromCGDisplayListP13CGPDFAppenderP13CGDisplayList7CGPoint_block_invoke @ 183f24c54 size=152 ==== */

undefined8
____ZL53CGPDFAppenderCreateCGPDFStreamObjectFromCGDisplayListP13CGPDFAppenderP13CGDisplayList7CGPoint_block_invoke
          (long param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  undefined8 local_28;
  
  if ((param_3 != 0) && (*(int *)(param_3 + 8) == 9)) {
    lVar3 = *(long *)(param_3 + 0x20);
    local_28 = 0;
    if (lVar3 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined8 *)(lVar3 + 0x30);
    }
    iVar1 = FUN_183bd1218(uVar2,"Subtype",&local_28);
    if ((iVar1 == 0) || (uVar2 = func_0x0001881386b0(local_28,"Form"), (int)uVar2 != 0)) {
      uVar2 = 1;
    }
    else {
      *(long *)(*(long *)(*(long *)(param_1 + 0x20) + 8) + 0x18) = lVar3;
    }
    return uVar2;
  }
  return 1;
}



/* ==== __ZL20PDFWriteStreamObjectP9PDFWriterP17CGPDFStreamObject @ 183f253c4 size=464 ==== */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Possible PIC construction at 0x000183f25464: Changing call to branch */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __ZL20PDFWriteStreamObjectP9PDFWriterP17CGPDFStreamObject(undefined8 *param_1,long param_2)

{
  char cVar1;
  code *pcVar2;
  long lVar3;
  undefined8 uVar4;
  long lVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  ulong unaff_x30;
  
  uVar8 = *(undefined8 *)(param_2 + 0x10);
  uVar7 = *(undefined8 *)(param_2 + 0x18);
  lVar3 = func_0x000188140aa0(uVar7);
  if (lVar3 == 0) {
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0xc471,0x183f254c4);
      (*pcVar2)();
    }
    _pdf_error("Failed to get the raw data pointer for PDFWriteStreamObject(...)");
    return;
  }
  cVar1 = *(char *)(param_2 + 0x20);
  if (cVar1 == '\x01') {
    uVar4 = func_0x00018814c4e0(*_DAT_1e00fe6a8,0);
    lVar3 = FUN_183c87290();
    lVar5 = FUN_183c49430();
    uVar6 = func_0x000188140aa0(uVar7);
    uVar7 = func_0x000188140ab0(uVar7);
    FUN_183c0c28c(lVar5,uVar6,uVar7);
    FUN_183c0c30c(lVar5);
    if (lVar5 != 0) {
      halt_baddata();
    }
    if (lVar3 != 0) {
      func_0x000188141240(lVar3);
    }
    FUN_183f7ba28(uVar8,"Filter","FlateDecode");
    uVar7 = uVar4;
  }
  uVar4 = func_0x000188140ab0(uVar7);
  FUN_183f7b9a8(uVar8,"Length",uVar4);
  __ZL18PDFWriteDictionaryP9PDFWriterPK14__CFDictionary(param_1,*(undefined8 *)(param_2 + 0x10));
  _PDFWriterPrintf(param_1,"stream\n");
  uVar8 = func_0x000188140aa0(uVar7);
  if (param_1 != (undefined8 *)0x0) {
    FUN_183c0c28c(*param_1,uVar8,(long)(int)uVar4);
  }
  _PDFWriterPrintf(param_1,"\n");
  _PDFWriterPrintf(param_1,"endstream\n");
  if (cVar1 != '\0') {
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0xc471,0x183f25574);
    (*pcVar2)();
  }
  return;
}



/* ==== _CGPDFStreamObjectFinalize @ 183f7aacc size=60 ==== */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Possible PIC construction at 0x000183f7aae4: Changing call to branch */
/* WARNING: Removing unreachable block (ram,0x000183f7aae8) */
/* WARNING: Removing unreachable block (ram,0x000183f7ab04) */
/* WARNING: Removing unreachable block (ram,0x000183f7ab00) */

void _CGPDFStreamObjectFinalize(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* ==== _CGPDFStreamObjectDebugDesc @ 183f7ab08 size=136 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _CGPDFStreamObjectDebugDesc(long param_1)

{
  undefined8 uVar1;
  
  uVar1 = *_DAT_1e00fe6a8;
  func_0x000188140c20(*(undefined8 *)(param_1 + 0x10));
  func_0x000188140ab0(*(undefined8 *)(param_1 + 0x18));
  func_0x000188141720(uVar1,0,&cfstringStruct_1e2249f80);
  return;
}



/* ==== ___CGPDFStreamObjectTypeID_block_invoke @ 183f7ab90 size=40 ==== */

void ___CGPDFStreamObjectTypeID_block_invoke(void)

{
  DAT_1eb058430 = _pdf_register_cftype(&DAT_1e2238710);
  return;
}



/* ==== ____ZN2CG21PDFDocumentSerializer11writeStreamEP11CGPDFStream_block_invoke @ 183f886e8 size=340 ==== */

undefined8
____ZN2CG21PDFDocumentSerializer11writeStreamEP11CGPDFStream_block_invoke
          (long param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  char *pcVar2;
  undefined8 uVar3;
  long lVar4;
  long local_48;
  
  uVar3 = *(undefined8 *)(param_1 + 0x20);
  iVar1 = func_0x0001881386b0(param_2,"Length");
  if (iVar1 == 0) {
    __ZN2CG21PDFDocumentSerializer6printfEPKcz(uVar3,"/%N");
    func_0x000188140ab0(*(undefined8 *)(param_1 + 0x28));
    pcVar2 = "%d";
LAB_183f88818:
    __ZN2CG21PDFDocumentSerializer6printfEPKcz(uVar3,pcVar2);
  }
  else {
    lVar4 = *(long *)(param_1 + 0x30);
    if ((lVar4 == 0) ||
       ((iVar1 = func_0x0001881386b0(param_2,"Filter"), iVar1 != 0 &&
        (iVar1 = func_0x0001881386b0(param_2,"DecodeParms"), iVar1 != 0)))) {
      __ZN2CG21PDFDocumentSerializer6printfEPKcz(uVar3,"/%N");
      if ((*(long *)(param_3 + 0x10) != 0 || (*(ulong *)(param_3 + 0x18) & 0xffff) != 0) &&
         (*(int *)(param_3 + 8) != 10)) {
        __ZN2CG21PDFDocumentSerializer9addObjectEP11CGPDFObject(uVar3,param_3);
        pcVar2 = "%R";
        goto LAB_183f88818;
      }
    }
    else {
      local_48 = 0;
      iVar1 = FUN_183bcf4b0(lVar4,param_2,&local_48);
      if (iVar1 == 0) {
        return 1;
      }
      __ZN2CG21PDFDocumentSerializer6printfEPKcz(uVar3,"/%N");
      param_3 = local_48;
    }
    __ZN2CG21PDFDocumentSerializer11writeObjectEP11CGPDFObject(uVar3,param_3);
  }
  return 1;
}



/* ==== __ZN2CG11PDFPageCore13appendXObjectEP11CGPDFStreamb @ 183fca7b0 size=2100 ==== */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __ZN2CG11PDFPageCore13appendXObjectEP11CGPDFStreamb(long param_1,long param_2,int param_3)

{
  char cVar1;
  int *piVar2;
  undefined1 *puVar3;
  code *pcVar4;
  int iVar5;
  long lVar6;
  ulong uVar7;
  long *plVar8;
  long lVar9;
  long lVar10;
  long lVar11;
  undefined8 *******pppppppuVar12;
  undefined8 uVar13;
  undefined8 *******local_228;
  ulong uStack_220;
  byte local_211;
  undefined8 *******local_210;
  undefined7 local_208;
  char cStack_201;
  undefined7 local_200;
  char cStack_1f9;
  long local_1f8;
  long local_1f0 [2];
  int *local_1e0;
  undefined8 local_1d8;
  undefined7 *puStack_1d0;
  undefined8 local_1c8;
  undefined7 local_1c0;
  char cStack_1b9;
  undefined7 local_1b8;
  undefined1 uStack_1b1;
  undefined8 uStack_1b0;
  undefined1 *local_198;
  undefined8 local_190;
  long lStack_188;
  code *local_180;
  undefined8 uStack_178;
  undefined1 auStack_170 [256];
  undefined1 *local_70;
  long local_68;
  
  local_68 = *_DAT_1e0186220;
  uVar13 = *(undefined8 *)(param_2 + 0x30);
  local_1e0 = (int *)0x0;
  iVar5 = FUN_183bd1218(uVar13,"Subtype",&local_1e0);
  piVar2 = local_1e0;
  if (((iVar5 == 0) || (lVar6 = func_0x0001881386f0(local_1e0), lVar6 != 4)) ||
     (*piVar2 != 0x6d726f46)) {
    uVar13 = func_0x00018814d130(0x10);
    func_0x00018814ce00(uVar13,"Invalid/Missing /Subtype for XObject stream");
    func_0x00018814d190(uVar13,_DAT_1e0181e90,_DAT_1e0181d40);
    return;
  }
  local_1f0[1] = 0;
  uVar7 = FUN_183bcf620(uVar13,"BBox",local_1f0 + 1);
  if ((uVar7 & 1) == 0) {
    uVar13 = func_0x00018814d130(0x10);
    func_0x00018814ce00(uVar13,"Invalid/Missing /BBox for XObject stream");
    func_0x00018814d190(uVar13,_DAT_1e0181e90,_DAT_1e0181d40);
    return;
  }
  func_0x00018814cf20(param_1 + 0x40);
  local_1f0[0] = 0;
  iVar5 = FUN_183bd75c4(*(undefined8 *)(param_1 + 0x30),"Resources",local_1f0);
  lVar6 = local_1f0[0];
  if (iVar5 == 0) {
    lVar6 = _CGPDFDictionaryCreateWithObjects(0,0);
    if (lVar6 == 0) {
      plVar8 = (long *)func_0x00018814d130(0x10);
      __Z23_CGExceptionDescription16_CGConditionTypePKcS1_iS1_z
                (&local_198,0,"newResources",
                 "/Library/Caches/com.apple.xbs/418A84E5-A935-45BB-BEF3-31726BD24C5D/TemporaryDirectory.myKecQ/Sources/CoreGraphics/CoreGraphics/PDF/Documents/PDFPageCore.cpp"
                 ,0x1f0,0);
      func_0x00018814cde0(plVar8,&local_198);
      *plVar8 = _DAT_1e0182010 + 0x10;
      func_0x00018814d190(plVar8,PTR_DAT_1e05db420,_DAT_1e0181d28);
      return;
    }
    func_0x000188141250(lVar6);
    func_0x000188141240(lVar6);
    __ZN2CG20PDFDictionaryMutator13setDictionaryEPKcP15CGPDFDictionary
              (*(undefined8 *)(param_1 + 0x30),"Resources",lVar6);
    local_1f0[0] = lVar6;
    func_0x000188141240(lVar6);
  }
  local_1f8 = 0;
  uVar7 = FUN_183bd75c4(lVar6,"XObject",&local_1f8);
  if ((uVar7 & 1) == 0) {
    lVar10 = _CGPDFDictionaryCreateWithObjects(0,0);
    if (lVar10 == 0) {
      plVar8 = (long *)func_0x00018814d130(0x10);
      __Z23_CGExceptionDescription16_CGConditionTypePKcS1_iS1_z
                (&local_198,0,"newXObjects",
                 "/Library/Caches/com.apple.xbs/418A84E5-A935-45BB-BEF3-31726BD24C5D/TemporaryDirectory.myKecQ/Sources/CoreGraphics/CoreGraphics/PDF/Documents/PDFPageCore.cpp"
                 ,0x1fa,0);
      func_0x00018814cde0(plVar8,&local_198);
      *plVar8 = _DAT_1e0182010 + 0x10;
      func_0x00018814d190(plVar8,PTR_DAT_1e05db420,_DAT_1e0181d28);
      return;
    }
    func_0x000188141250(lVar10);
    func_0x000188141240(lVar10);
    __ZN2CG20PDFDictionaryMutator13setDictionaryEPKcP15CGPDFDictionary(lVar6,"XObject",lVar10);
    local_1f8 = lVar10;
    func_0x000188141240(lVar10);
LAB_183fca934:
    lVar6 = *(long *)(lVar10 + 0x48);
  }
  else {
    lVar10 = local_1f8;
    if (local_1f8 != 0) goto LAB_183fca934;
    lVar6 = 0;
  }
  local_210 = (undefined8 *******)0x0;
  local_208 = 0;
  cStack_201 = '\0';
  local_200 = 0;
  cStack_1f9 = '\0';
  do {
    lVar6 = lVar6 + 1;
    func_0x000188145b70(&local_198,lVar6);
    plVar8 = (long *)func_0x000188145b00(&local_198,0,"Fm",2);
    pppppppuVar12 = (undefined8 *******)*plVar8;
    local_1c0 = (undefined7)plVar8[1];
    cStack_1b9 = (char)*(undefined8 *)((long)plVar8 + 0xf);
    local_1b8 = (undefined7)((ulong)*(undefined8 *)((long)plVar8 + 0xf) >> 8);
    cVar1 = *(char *)((long)plVar8 + 0x17);
    plVar8[1] = 0;
    plVar8[2] = 0;
    *plVar8 = 0;
    if (cStack_1f9 < '\0') {
      func_0x00018814d0d0(local_210);
    }
    local_208 = local_1c0;
    cStack_201 = cStack_1b9;
    local_200 = local_1b8;
    local_210 = pppppppuVar12;
    cStack_1f9 = cVar1;
    if (lStack_188 < 0) {
      func_0x00018814d0d0(local_198);
    }
    pppppppuVar12 = local_210;
    if (-1 < cStack_1f9) {
      pppppppuVar12 = &local_210;
    }
  } while (((lVar10 != 0) && (pppppppuVar12 != (undefined8 *******)0x0)) &&
          (lVar9 = __ZNSt3__112__hash_tableINS_17__hash_value_typeIP11CGPDFObjectS3_EENS_22__unordered_map_hasherIS3_NS_4pairIKS3_S3_EE13pdf_name_hash14pdf_name_equalEENS_21__unordered_map_equalIS3_S8_SA_S9_EENS_9allocatorIS8_EEE4findIPKcEENS_15__hash_iteratorIPNS_11__hash_nodeIS4_PvEEEERKT_
                             (lVar10 + 0x30,pppppppuVar12), lVar9 != 0));
  __ZN2CG20PDFDictionaryMutator9setStreamEPKcP11CGPDFStream(lVar10,pppppppuVar12,param_2);
  __ZN2CG15PDFDocumentCore18addStreamResourcesEP11CGPDFStream
            (*(undefined8 *)(param_1 + 0x10),param_2);
  if (param_3 != 0) {
    __ZN2CG15PDFDocumentCore23addTransientObjectValueEPKv(*(undefined8 *)(param_1 + 0x10),param_2);
  }
  lVar6 = (long)cStack_1f9;
  if (lVar6 < 0) {
    lVar6 = CONCAT17(cStack_201,local_208);
    pppppppuVar12 = local_210;
    if (cStack_201 < '\0') goto LAB_183fcaff8;
  }
  else {
    pppppppuVar12 = &local_210;
  }
  local_1b8 = (undefined7)lVar6;
  uStack_1b1 = (undefined1)((ulong)lVar6 >> 0x38);
  uStack_1b0 = 0xd;
  local_1c8 = 0xd;
  local_1c0 = SUB87(pppppppuVar12,0);
  cStack_1b9 = (char)((ulong)pppppppuVar12 >> 0x38);
  lStack_188 = 0;
  local_190 = 0x100;
  local_180 = 
  __ZNSt3__18__format19__allocating_bufferIcE15__prepare_writeB9fqe220106ERNS0_15__output_bufferIcEEm
  ;
  uStack_178 = 0;
  puStack_1d0 = &local_1c0;
  local_1d8 = 1;
  local_198 = auStack_170;
  local_70 = auStack_170;
  __ZNSt3__112__vformat_toB9fqe220106INS_20back_insert_iteratorINS_8__format15__output_bufferIcEEEEcS5_EET_S6_NS_17basic_string_viewIT0_NS_11char_traitsIS8_EEEENS_17basic_format_argsINS_20basic_format_contextIT1_S8_EEEE
            (&local_198,"\nq /{} Do Q\n",0xc,&local_1d8);
  puVar3 = local_70;
  lVar6 = lStack_188;
  if (lStack_188 < 0) {
LAB_183fcaff8:
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(1,0x183fcaffc);
    (*pcVar4)();
  }
  lVar10 = __ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE22__init_internal_bufferB9fqe220106Em
                     (&local_228,lStack_188);
  func_0x0001881384e0(lVar10,puVar3,lVar6);
  *(undefined1 *)(lVar10 + lVar6) = 0;
  if (local_70 != auStack_170) {
    func_0x00018814d0d0();
  }
  pppppppuVar12 = local_228;
  if (-1 < (char)local_211) {
    uStack_220 = (ulong)local_211;
    pppppppuVar12 = &local_228;
  }
  lVar6 = func_0x000188140a80(*_DAT_1e00fe6a8,pppppppuVar12,uStack_220);
  lVar10 = _CGPDFDictionaryCreateWithObjects(0,0);
  uVar13 = func_0x000188140ab0(lVar6);
  __ZN2CG20PDFDictionaryMutator10setIntegerEPKcl(lVar10,"Length",uVar13);
  lVar9 = FUN_183fe4d5c(lVar10,0,lVar6);
  __ZN2CG15PDFDocumentCore18addStreamResourcesEP11CGPDFStream(*(undefined8 *)(param_1 + 0x10),lVar9)
  ;
  if (param_3 != 0) {
    __ZN2CG15PDFDocumentCore23addTransientObjectValueEPKv(*(undefined8 *)(param_1 + 0x10),lVar9);
  }
  local_1c0 = 0;
  cStack_1b9 = 0;
  iVar5 = FUN_183bcf4b0(*(undefined8 *)(param_1 + 0x30),"Contents",&local_1c0);
  if (iVar5 == 0) {
    lVar11 = _CGPDFArrayCreateWithObjects(0,0);
    if (lVar11 == 0) {
      plVar8 = (long *)func_0x00018814d130(0x10);
      __Z23_CGExceptionDescription16_CGConditionTypePKcS1_iS1_z
                (&local_198,0,"newArray",
                 "/Library/Caches/com.apple.xbs/418A84E5-A935-45BB-BEF3-31726BD24C5D/TemporaryDirectory.myKecQ/Sources/CoreGraphics/CoreGraphics/PDF/Documents/PDFPageCore.cpp"
                 ,0x24b,0);
      func_0x00018814cde0(plVar8,&local_198);
      *plVar8 = _DAT_1e0182010 + 0x10;
      func_0x00018814d190(plVar8,PTR_DAT_1e05db420,_DAT_1e0181d28);
      return;
    }
    func_0x000188141250(lVar11);
    func_0x000188141240(lVar11);
    __ZN2CG15PDFArrayMutator12appendStreamEP11CGPDFStream(lVar11,lVar9);
    __ZN2CG20PDFDictionaryMutator8setArrayEPKcP10CGPDFArray
              (*(undefined8 *)(param_1 + 0x30),"Contents",lVar11);
    func_0x000188141240(lVar11);
  }
  else {
    lVar11 = CONCAT17(cStack_1b9,local_1c0);
    if (lVar11 == 0) {
LAB_183fcadb0:
      uVar13 = func_0x00018814d130(0x10);
      func_0x00018814ce00(uVar13,"Malformed PDF: /Contents entry is neither an Array nor a Stream.")
      ;
      func_0x00018814d190(uVar13,_DAT_1e0181e90,_DAT_1e0181d40);
      return;
    }
    if (*(int *)(lVar11 + 8) == 9) {
      uVar13 = *(undefined8 *)(lVar11 + 0x20);
      lVar11 = _CGPDFArrayCreateWithObjects(0,0);
      if (lVar11 == 0) {
        plVar8 = (long *)func_0x00018814d130(0x10);
        __Z23_CGExceptionDescription16_CGConditionTypePKcS1_iS1_z
                  (&local_198,0,"newArray",
                   "/Library/Caches/com.apple.xbs/418A84E5-A935-45BB-BEF3-31726BD24C5D/TemporaryDirectory.myKecQ/Sources/CoreGraphics/CoreGraphics/PDF/Documents/PDFPageCore.cpp"
                   ,0x239,0);
        func_0x00018814cde0(plVar8,&local_198);
        *plVar8 = _DAT_1e0182010 + 0x10;
        func_0x00018814d190(plVar8,PTR_DAT_1e05db420,_DAT_1e0181d28);
        return;
      }
      func_0x000188141250(lVar11);
      func_0x000188141240(lVar11);
      __ZN2CG15PDFArrayMutator12appendStreamEP11CGPDFStream(lVar11,uVar13);
      __ZN2CG15PDFArrayMutator12appendStreamEP11CGPDFStream(lVar11,lVar9);
      __ZN2CG20PDFDictionaryMutator8setArrayEPKcP10CGPDFArray
                (*(undefined8 *)(param_1 + 0x30),"Contents",lVar11);
      func_0x000188141240(lVar11);
    }
    else {
      if (*(int *)(lVar11 + 8) != 7) goto LAB_183fcadb0;
      __ZN2CG15PDFArrayMutator12appendStreamEP11CGPDFStream(*(undefined8 *)(lVar11 + 0x20),lVar9);
    }
  }
  func_0x00018814cf30(param_1 + 0x40);
  func_0x00018814cf20(param_1 + 0x278);
  __ZNSt3__124__optional_destruct_baseIN10applesauce2CF9ObjectRefIP14CGPDFResourcesEELb0EE5resetB9fqe220106Ev
            (param_1 + 800);
  func_0x00018814cf30(param_1 + 0x278);
  func_0x00018814cf20(param_1 + 0x3f8);
  __ZNSt3__124__optional_destruct_baseIN10applesauce2CF9ObjectRefIP15CGPDFPageLayoutEELb0EE5resetB9fqe220106Ev
            (param_1 + 0x4a0);
  func_0x00018814cf30(param_1 + 0x3f8);
  func_0x00018814cf20(param_1 + 0x4b0);
  __ZNSt3__124__optional_destruct_baseIN10applesauce2CF9ObjectRefIP15CGPDFTaggedNodeEELb0EE5resetB9fqe220106Ev
            (param_1 + 0x558);
  func_0x00018814cf30(param_1 + 0x4b0);
  if (lVar9 != 0) {
    func_0x000188141240(lVar9);
  }
  if (lVar10 != 0) {
    func_0x000188141240(lVar10);
  }
  if (lVar6 != 0) {
    func_0x000188141240(lVar6);
  }
  if ((char)local_211 < '\0') {
    func_0x00018814d0d0(local_228);
  }
  if (cStack_1f9 < '\0') {
    func_0x00018814d0d0(local_210);
  }
  if (*_DAT_1e0186220 == local_68) {
    return;
  }
  func_0x000188138130();
  return;
}



/* ==== __ZN2CG15PDFArrayMutator12appendStreamEP11CGPDFStream @ 183fcb244 size=104 ==== */

void __ZN2CG15PDFArrayMutator12appendStreamEP11CGPDFStream(long param_1,undefined8 param_2)

{
  code *pcVar1;
  long lVar2;
  undefined8 uVar3;
  ulong unaff_x30;
  
  lVar2 = FUN_183e7cc5c(param_2);
  if (param_1 != 0) {
    uVar3 = _pdf_object_create_copy(lVar2);
    __ZNSt3__16vectorIPN10ClipperLib8PolyNodeENS_9allocatorIS3_EEE9push_backB9fqe220106EOS3_
              (param_1 + 0x10,uVar3);
  }
  if (lVar2 != 0) {
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xc471,0x183fcb29c);
      (*pcVar1)();
    }
    FUN_183e7cd1c(lVar2);
    return;
  }
  return;
}



/* ==== __ZN12_GLOBAL__N_133isColorSpaceFromStreamIsWideGamutEP11CGPDFStream @ 183fcc540 size=236 ==== */

byte __ZN12_GLOBAL__N_133isColorSpaceFromStreamIsWideGamutEP11CGPDFStream(long param_1)

{
  long lVar1;
  long lVar2;
  long lVar3;
  byte bVar4;
  byte bVar5;
  int local_34;
  
  if (param_1 == 0) {
    bVar5 = 0;
  }
  else {
    local_34 = 0;
    lVar1 = FUN_183ca244c(param_1,0,0,&local_34);
    if ((lVar1 == 0) || (local_34 != 0)) {
      bVar4 = 0;
      bVar5 = 0;
      if (lVar1 == 0) goto LAB_183fcc5f0;
    }
    else {
      lVar2 = FUN_183b739b8(lVar1);
      if (lVar2 == 0) {
        bVar4 = 0;
      }
      else {
        lVar3 = func_0x000188140d60();
        if (DAT_1edf367a0 != -1) {
          func_0x00018813aad0(&DAT_1edf367a0,&DAT_1e22309c8);
        }
        if (lVar3 == DAT_1edf36a20) {
          bVar4 = *(byte *)(*(long *)(lVar2 + 0x18) + 0xe);
        }
        else {
          bVar4 = 0;
        }
        func_0x000188141240(lVar2);
      }
    }
    func_0x000188141240(lVar1);
    bVar5 = bVar4;
  }
LAB_183fcc5f0:
  return bVar5 & 1;
}



/* ==== _CGPDFStreamCreateFilterChainExcluding @ 183fe4ea4 size=804 ==== */

long _CGPDFStreamCreateFilterChainExcluding
               (long param_1,long param_2,long param_3,undefined4 *param_4)

{
  undefined1 uVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  ulong uVar5;
  long lVar6;
  long lVar7;
  undefined8 uVar8;
  long lVar9;
  undefined8 uVar10;
  long lVar11;
  long lVar12;
  long local_80;
  undefined8 local_78;
  long local_70;
  undefined8 local_68;
  
  if ((param_1 == 0) ||
     (lVar3 = _CGPDFSourceCreateCopy
                        (*(undefined8 *)(param_1 + 0x48),*(undefined8 *)(param_1 + 0x38),
                         *(undefined8 *)(param_1 + 0x40)), lVar3 == 0)) {
    return 0;
  }
  uVar1 = *(undefined1 *)(param_1 + 0x28);
  uVar10 = *(undefined8 *)(param_1 + 0x30);
  if ((((*(long *)(param_1 + 0x10) == 0) || ((*(byte *)(param_1 + 0x29) & 1) != 0)) ||
      (lVar7 = *(long *)(*(long *)(param_1 + 0x10) + 0x28), lVar7 == 0)) ||
     (iVar2 = _has_crypt_filter(uVar10,uVar1), iVar2 != 0)) {
    func_0x000188141250(lVar3);
    lVar7 = lVar3;
  }
  else if (((*(long *)(lVar7 + 0x10) == 0) || (*(char *)(*(long *)(lVar7 + 0x10) + 0xb8) != '\x01'))
          || (lVar7 = _CGPDFCryptFilterCreateDecryptor
                                (*(undefined8 *)(lVar7 + 0x20),*(undefined8 *)(param_1 + 0x18),
                                 *(undefined8 *)(param_1 + 0x20),lVar3), lVar7 == 0)) {
    _pdf_error("failed to create default crypt filter.");
    lVar7 = 0;
    goto LAB_183fe519c;
  }
  lVar4 = _get_filter_object(uVar10,uVar1);
  if (lVar4 == 0) {
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = 0;
    }
  }
  else {
    if (*(int *)(lVar4 + 8) == 5) {
      uVar10 = *(undefined8 *)(lVar4 + 0x20);
      if ((param_2 != 0) && (iVar2 = _filter_kind_from_name(uVar10), param_3 != 0)) {
        lVar4 = 0;
        do {
          if (iVar2 == *(int *)(param_2 + lVar4 * 4)) {
            _pdf_error("Disallowed filter %s");
            goto LAB_183fe518c;
          }
          lVar4 = lVar4 + 1;
          param_3 = param_3 + -1;
        } while (param_3 != 0);
      }
      local_68 = 0;
      uVar8 = *(undefined8 *)(param_1 + 0x30);
      uVar5 = FUN_183bd75c4(uVar8,"DecodeParms",&local_68);
      if (((uVar5 & 1) == 0) && (uVar5 = FUN_183bd75c4(uVar8,"DP",&local_68), (uVar5 & 1) == 0)) {
        local_68 = 0;
      }
      lVar4 = _add_filter(param_1,lVar7,uVar10,local_68,param_4);
    }
    else if (*(int *)(lVar4 + 8) == 7) {
      lVar9 = *(long *)(lVar4 + 0x20);
      local_70 = 0;
      local_68 = 0;
      local_78 = 0;
      if (lVar9 == 0) {
        local_80 = 0;
      }
      else {
        local_80 = *(long *)(lVar9 + 0x18) - *(long *)(lVar9 + 0x10) >> 3;
      }
      uVar10 = *(undefined8 *)(param_1 + 0x30);
      uVar5 = FUN_183bcf620(uVar10,"DecodeParms",&local_70);
      if (((uVar5 & 1) == 0) && (uVar5 = FUN_183bcf620(uVar10,"DP",&local_70), (uVar5 & 1) == 0)) {
        local_70 = 0;
      }
      func_0x000188141250(lVar7);
      if (param_4 != (undefined4 *)0x0) {
        *param_4 = 0;
      }
      lVar4 = lVar7;
      if (local_80 != 0) {
        lVar12 = 0;
        lVar11 = lVar7;
        do {
          iVar2 = FUN_183be0724(lVar9,lVar12,&local_68);
          if (iVar2 == 0) {
LAB_183fe5170:
            func_0x000188141240(lVar11);
            goto LAB_183fe518c;
          }
          if ((param_2 != 0) && (iVar2 = _filter_kind_from_name(local_68), param_3 != 0)) {
            lVar4 = 0;
            lVar6 = param_3;
            do {
              if (iVar2 == *(int *)(param_2 + lVar4 * 4)) {
                _pdf_error("Disallowed filter %s");
                goto LAB_183fe5170;
              }
              lVar4 = lVar4 + 1;
              lVar6 = lVar6 + -1;
            } while (lVar6 != 0);
          }
          if ((local_70 == 0) || (iVar2 = FUN_183bd5ee4(local_70,lVar12,&local_78), iVar2 == 0)) {
            local_78 = 0;
          }
          lVar4 = _add_filter(param_1,lVar11,local_68,local_78,param_4);
          if (lVar4 == 0) goto LAB_183fe5170;
          func_0x000188141240(lVar11);
          lVar12 = lVar12 + 1;
          lVar11 = lVar4;
        } while (lVar12 != local_80);
      }
    }
    else {
LAB_183fe518c:
      lVar4 = 0;
    }
    func_0x000188141240(lVar7);
    lVar7 = lVar4;
  }
LAB_183fe519c:
  func_0x000188141240(lVar3);
  return lVar7;
}



/* ==== __ZN23CGPDFDrawingContextImplC1EP11CGPDFStreamP15CGPDFDictionaryPS_ @ 18400e9ac size=156 ==== */

undefined8 *
__ZN23CGPDFDrawingContextImplC1EP11CGPDFStreamP15CGPDFDictionaryPS_
          (undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4)

{
  long *plVar1;
  long lVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  if (param_4 == (undefined8 *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = param_4[2];
  }
  lVar2 = FUN_183f33f04(param_2,param_3,uVar4);
  __ZN23CGPDFDrawingContextImplC2EP18CGPDFContentStreamPS_(param_1,lVar2,param_4);
  if (lVar2 != 0) {
    func_0x000188141240(lVar2);
  }
  if (param_4 != (undefined8 *)0x0) {
    uVar5 = param_4[1];
    uVar4 = *param_4;
    lVar2 = 0;
    if (param_4[1] != 0) {
      plVar1 = (long *)(param_4[1] + 8);
      lVar2 = *plVar1;
      *plVar1 = lVar2 + 1;
    }
    lVar3 = param_1[1];
    param_1[1] = uVar5;
    *param_1 = uVar4;
    if (lVar3 != 0) {
      __ZNSt3__119__shared_weak_count16__release_sharedB9fqe220106Ev(lVar2);
    }
  }
  return param_1;
}



/* ==== _CGPDFStreamCreate.end @ 18425e96d size=1 ==== */

/* WARNING: Control flow encountered bad instruction data */

void _CGPDFStreamCreate_end(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



