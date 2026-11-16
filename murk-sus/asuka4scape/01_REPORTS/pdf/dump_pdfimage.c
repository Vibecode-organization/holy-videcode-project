/* ==== _create_image_stream @ 183c699e8 size=1124 ==== */

long * _create_image_stream
                 (long param_1,long param_2,uint param_3,long param_4,long param_5,ulong param_6,
                 ulong param_7,ulong param_8,ulong param_9,long param_10,long param_11,long param_12
                 ,long param_13,long param_14)

{
  ulong uVar1;
  bool bVar2;
  uint uVar3;
  bool bVar4;
  long *plVar5;
  long lVar6;
  long lVar7;
  undefined1 auStack_1e8 [40];
  undefined1 auStack_1c0 [304];
  undefined1 auStack_90 [48];
  
  if (param_8 < param_6) {
                    /* WARNING: Subroutine does not return */
    FUN_183c19214("create_image_stream",0x91,
                  "/Library/Caches/com.apple.xbs/418A84E5-A935-45BB-BEF3-31726BD24C5D/TemporaryDirectory.myKecQ/Sources/CoreGraphics/CoreGraphics/Images/CGImageStream.c"
                  ,"src_image_bytes_per_row >= image_data_bytes_per_row",
                  "src image bpr: %lu  image bpr: %lu");
  }
  if (param_9 < param_7) {
                    /* WARNING: Subroutine does not return */
    FUN_183c19214("create_image_stream",0x92,
                  "/Library/Caches/com.apple.xbs/418A84E5-A935-45BB-BEF3-31726BD24C5D/TemporaryDirectory.myKecQ/Sources/CoreGraphics/CoreGraphics/Images/CGImageStream.c"
                  ,"src_smask_bytes_per_row >= smask_data_bytes_per_row",
                  "src mask bpr: %lu  mask bpr: %lu");
  }
  if (1 < *(uint *)(param_2 + 0x18) && *(uint *)(param_2 + 0x18) != 3) {
                    /* WARNING: Subroutine does not return */
    FUN_183c19214("create_image_stream",0x95,
                  "/Library/Caches/com.apple.xbs/418A84E5-A935-45BB-BEF3-31726BD24C5D/TemporaryDirectory.myKecQ/Sources/CoreGraphics/CoreGraphics/Images/CGImageStream.c"
                  ,
                  "pixel_info.alpha_info == kCGImageAlphaNone || pixel_info.alpha_info == kCGImageAlphaLast || pixel_info.alpha_info == kCGImageAlphaPremultipliedLast"
                  ,"alpha unsupported (%d)");
  }
  plVar5 = (long *)func_0x000188138460(1,0x518,0x10b0040abf645e3);
  if (plVar5 == (long *)0x0) {
    return (long *)0x0;
  }
  if (param_1 != 0) {
    func_0x000188141250(param_1);
  }
  *plVar5 = param_1;
  func_0x0001881384d0(plVar5 + 1,param_2,0x130);
  if (*(long *)(param_2 + 0x28) != 0) {
    uVar3 = *(int *)(param_2 + 0x18) - 1;
    if (uVar3 < 9) {
      lVar6 = (&DAT_184266e38)[uVar3];
    }
    else {
      lVar6 = 0;
    }
    lVar6 = lVar6 + *(long *)(param_2 + 0x10);
    if (lVar6 != 0) {
      lVar7 = 0;
      do {
        plVar5[lVar7 * 2 + 7] = *(long *)(param_2 + 0x30 + lVar7 * 0x10);
        uVar1 = lVar7 << 4 | 8;
        *(undefined8 *)((long)plVar5 + uVar1 + 0x38) = *(undefined8 *)(param_2 + 0x30 + uVar1);
        lVar7 = lVar7 + 1;
        lVar6 = lVar6 + -1;
      } while (lVar6 != 0);
    }
    plVar5[6] = (long)(plVar5 + 7);
  }
  plVar5[0x27] = param_4;
  plVar5[0x28] = param_5;
  plVar5[0x29] = param_6;
  plVar5[0x2a] = param_7;
  plVar5[0x2c] = param_8;
  plVar5[0x2d] = param_9;
  FUN_183b1d778(param_12);
  plVar5[0x42] = param_12;
  FUN_183b1d778(param_13);
  plVar5[0x43] = param_13;
  bVar4 = (param_3 & 1) == 0;
  *(bool *)(plVar5 + 0x41) = bVar4 && (param_13 != 0 && param_14 != 0);
  if ((param_14 != 0) && (lVar6 = *(long *)(param_2 + 0x10), lVar6 != 0)) {
    lVar7 = 0;
    do {
      plVar5[lVar7 + 0x44] = *(long *)(param_14 + lVar7 * 8);
      lVar7 = lVar7 + 1;
      lVar6 = lVar6 + -1;
    } while (lVar6 != 0);
  }
  if (*(int *)(param_2 + 0x18) == 0) {
    *(bool *)((long)plVar5 + 0x209) = param_13 != 0;
    if (param_13 != 0) goto LAB_183c69bb4;
    bVar4 = false;
  }
  else {
    *(undefined1 *)((long)plVar5 + 0x209) = 1;
LAB_183c69bb4:
    if (bVar4 && (param_13 != 0 && param_14 != 0)) {
      if ((param_13 == 0) || (param_14 == 0)) {
                    /* WARNING: Subroutine does not return */
        FUN_183c19214("create_image_stream",0xbb,
                      "/Library/Caches/com.apple.xbs/418A84E5-A935-45BB-BEF3-31726BD24C5D/TemporaryDirectory.myKecQ/Sources/CoreGraphics/CoreGraphics/Images/CGImageStream.c"
                      ,"src_image_matte != NULL && src_smask_data_provider != NULL",
                      "matte %p  provider %p");
      }
      lVar6 = *(long *)(param_2 + 0x10);
      if (lVar6 != 0) {
        lVar7 = 0;
        do {
          plVar5[lVar7 + 0x31] = *(long *)(param_14 + lVar7 * 8);
          lVar7 = lVar7 + 1;
          lVar6 = lVar6 + -1;
        } while (lVar6 != 0);
      }
    }
    bVar4 = true;
  }
  bVar2 = false;
  if (param_13 == 0) {
    bVar2 = bVar4;
  }
  lVar6 = FUN_183b46824(param_12);
  plVar5[0x54] = lVar6;
  if (lVar6 != 0) {
    uVar1 = 0;
    if (param_6 != 0) {
      uVar1 = 0x10000 / param_6;
    }
    if (0x10000 < param_6) {
      uVar1 = 1;
    }
    plVar5[0x2b] = uVar1;
    param_10 = param_10 + uVar1 * param_6;
    lVar6 = func_0x000188138460(1,param_10,0xf803a1de);
    plVar5[0x2e] = lVar6;
    if (lVar6 != 0) {
      if (*(char *)((long)plVar5 + 0x209) == '\x01') {
        if (param_9 == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_183c19214("create_image_stream",0xda,
                        "/Library/Caches/com.apple.xbs/418A84E5-A935-45BB-BEF3-31726BD24C5D/TemporaryDirectory.myKecQ/Sources/CoreGraphics/CoreGraphics/Images/CGImageStream.c"
                        ,"src_smask_bytes_per_row > 0","bpr %lu");
        }
        lVar6 = func_0x000188138460(1,param_11 + uVar1 * param_7,0x3b22438d);
        plVar5[0x2f] = lVar6;
        if (lVar6 == 0) goto LAB_183c69d30;
      }
      if (param_13 == 0) {
        if (!bVar2) {
          return plVar5;
        }
        lVar6 = func_0x000188138460(1,param_10,0x1ddffada);
        plVar5[0x30] = lVar6;
        if (lVar6 == 0) goto LAB_183c69d30;
        func_0x0001881384d0(plVar5 + 0x57,param_2,0x130);
        func_0x0001881384d0(plVar5 + 0x7d,param_2,0x130);
        *(undefined4 *)(plVar5 + 0x5a) = 5;
        *(undefined4 *)(plVar5 + 0x80) = 0;
        func_0x0001881384d0(auStack_1c0,plVar5 + 0x57,0x130);
        _CGBitmapPixelInfoGet_vImageFormat(auStack_90,auStack_1c0);
        func_0x0001881384d0(auStack_1c0,plVar5 + 0x7d,0x130);
        _CGBitmapPixelInfoGet_vImageFormat(auStack_1e8,auStack_1c0);
        lVar6 = func_0x00018814d830(auStack_90,auStack_1e8,0,0x100,0);
        plVar5[0x56] = lVar6;
      }
      else {
        lVar6 = FUN_183b46824(param_13);
        plVar5[0x55] = lVar6;
      }
      if (lVar6 != 0) {
        return plVar5;
      }
    }
  }
LAB_183c69d30:
  _CGImageStreamRelease(plVar5);
  return (long *)0x0;
}



/* ==== _CGPDFImageCreate @ 183c6b984 size=2220 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long _CGPDFImageCreate(long param_1)

{
  int iVar1;
  ulong uVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  undefined8 uVar8;
  char *pcVar9;
  ulong extraout_x1;
  cfstringStruct *pcVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined1 auVar13 [16];
  undefined1 auVar14 [16];
  char local_ba;
  char local_b9;
  long local_b8;
  long local_b0;
  char local_a5;
  int local_a4;
  long local_a0;
  undefined8 local_98;
  ulong local_90;
  long local_88;
  undefined2 local_7a;
  undefined8 local_78;
  long local_70;
  cfstringStruct *local_68;
  undefined *local_60;
  long local_58;
  
  local_58 = *_DAT_1e0186220;
  if (param_1 != 0) {
    local_ba = '\x01';
    uVar11 = *(undefined8 *)(param_1 + 0x30);
    uVar2 = FUN_183bdf1c8(uVar11,"ImageMask",&local_ba);
    if ((uVar2 & 1) == 0) {
      local_ba = '\0';
    }
    lVar3 = _get_image_filter_name(uVar11);
    auVar13 = func_0x000188139930();
    uVar2 = auVar13._8_8_;
    if (DAT_1eb056f38 == -1) {
      if (lVar3 == 0) goto LAB_183c6ba4c;
LAB_183c6ba0c:
      auVar14 = _objc_msgSend_stringWithCString_encoding_(_DAT_1e010bcd8,uVar2,lVar3,5);
      auVar14 = _objc_msgSend_objectForKeyedSubscript_(DAT_1eb056f40,auVar14._8_8_,auVar14._0_8_);
    }
    else {
      func_0x00018813aad0(&DAT_1eb056f38,&DAT_1e223f848);
      uVar2 = extraout_x1;
      if (lVar3 != 0) goto LAB_183c6ba0c;
LAB_183c6ba4c:
      auVar14._8_8_ = 0;
      auVar14._0_8_ = uVar2;
      auVar14 = auVar14 << 0x40;
    }
    local_60 = &DAT_1e22515f0;
    if (auVar14._0_8_ != (undefined *)0x0) {
      local_60 = auVar14._0_8_;
    }
    local_68 = &cfstringStruct_1e22489a0;
    uVar11 = _objc_msgSend_dictionaryWithObjects_forKeys_count_
                       (_DAT_1e00fe1b8,auVar14._8_8_,&local_60,&local_68,1);
    _send_analytics_event("com.apple.CoreGraphics.CreatePDFImage",uVar11);
    func_0x000188139920(auVar13._0_8_);
    if (local_ba != '\0') {
      lVar3 = _create_mask(param_1);
      goto LAB_183c6bb9c;
    }
    local_88 = param_1;
    if (DAT_1eb056f88 != -1) {
      func_0x00018813aad0(&DAT_1eb056f88,&DAT_1e223d8b0);
    }
    lVar3 = _pdf_create_cftype(DAT_1eb056f90,0x98);
    if (lVar3 == 0) goto LAB_183c6bb9c;
    *(long *)(lVar3 + 0x18) = param_1;
    *(undefined1 *)(lVar3 + 0x10) = 0;
    lVar4 = FUN_183bf42d0(param_1,lVar3 + 0x28);
    *(long *)(lVar3 + 0x20) = lVar4;
    if (lVar4 != 0) {
      local_98 = 0;
      local_90 = 0;
      local_a0 = 0;
      local_a4 = 0;
      local_a5 = '\0';
      local_b0 = 0;
      uVar11 = *(undefined8 *)(param_1 + 0x30);
      iVar1 = FUN_183bd6c4c(uVar11,"Width",&local_90);
      if ((iVar1 == 0) || ((long)local_90 < 1)) {
        pcVar9 = "missing or invalid image `Width\' value.";
      }
      else {
        *(ulong *)(lVar3 + 0x30) = local_90;
        iVar1 = FUN_183bd6c4c(uVar11,"Height",&local_90);
        if ((iVar1 == 0) || ((long)local_90 < 1)) {
          pcVar9 = "missing or invalid image `Height\' value.";
        }
        else {
          *(ulong *)(lVar3 + 0x38) = local_90;
          if (*(int *)(lVar3 + 0x28) == 2) {
            uVar2 = 0;
LAB_183c6bc10:
            *(ulong *)(lVar3 + 0x40) = uVar2;
            _set_image_rendering_intent(lVar3,uVar11);
            uVar2 = FUN_183bcf4b0(uVar11,"ColorSpace",&local_a0);
            if ((uVar2 & 1) == 0) {
              if (*(int *)(lVar3 + 0x28) == 2) {
                local_a0 = 0;
                goto LAB_183c6bca4;
              }
              pcVar9 = "missing or invalid image `ColorSpace\' value.";
            }
            else if (local_a0 == 0) {
LAB_183c6bca4:
              *(undefined8 *)(lVar3 + 0x48) = 0;
LAB_183c6bca8:
              *(undefined1 *)(lVar3 + 0x54) = 0;
              iVar1 = FUN_183bdf1c8(uVar11,"Interpolate",&local_a5);
              if (iVar1 != 0) {
                *(bool *)(lVar3 + 0x54) = local_a5 != '\0';
              }
              if (*(long *)(lVar3 + 0x48) == 0) {
                lVar4 = 0;
              }
              else {
                lVar4 = *(long *)(*(long *)(*(long *)(lVar3 + 0x48) + 0x18) + 0x30);
              }
              uVar2 = _set_image_decode_array(lVar3,uVar11,lVar4,0);
              if ((uVar2 & 1) == 0) {
                pcVar9 = "invalid image `Decode\' value.";
              }
              else {
                *(uint *)(lVar3 + 0x58) = (uint)(lVar4 == 3);
                if (((*(int *)(lVar3 + 0x28) == 1) &&
                    (((uVar2 = FUN_183bd75c4(uVar11,"DecodeParms",&local_b0), (uVar2 & 1) != 0 ||
                      (iVar1 = FUN_183bd75c4(uVar11,"DP",&local_b0), iVar1 != 0)) && (local_b0 != 0)
                     ))) && (iVar1 = FUN_183bd6c4c(local_b0,"ColorTransform",&local_90), iVar1 != 0)
                   ) {
                  if (local_90 < 2) {
                    *(int *)(lVar3 + 0x58) = (int)local_90;
                  }
                  else {
                    _pdf_error("invalid image `ColorTransform\' value.");
                  }
                }
                local_b8 = 0;
                local_b9 = '\0';
                iVar1 = FUN_183bd6c4c(uVar11,"SMaskInData",&local_b8);
                if (((iVar1 != 0) && (local_b8 != 0)) ||
                   ((iVar1 = FUN_183bdf1c8(uVar11,"SMaskInData",&local_b9), iVar1 != 0 &&
                    (local_b9 != '\0')))) {
                  *(undefined1 *)(lVar3 + 0x78) = 1;
                }
                iVar1 = FUN_183bf4260(uVar11,"SMask",&local_88);
                lVar5 = local_88;
                if (iVar1 != 0) {
                  if (DAT_1eb056f88 != -1) {
                    func_0x00018813aad0(&DAT_1eb056f88,&DAT_1e223d8b0);
                  }
                  lVar6 = _pdf_create_cftype(DAT_1eb056f90,0x98);
                  if (lVar6 != 0) {
                    *(long *)(lVar6 + 0x18) = lVar5;
                    *(undefined1 *)(lVar6 + 0x10) = 0;
                    lVar7 = FUN_183bf42d0(lVar5,lVar6 + 0x28);
                    *(long *)(lVar6 + 0x20) = lVar7;
                    if (lVar7 != 0) {
                      local_68 = (cfstringStruct *)0x0;
                      local_78 = 0;
                      local_70 = 0;
                      local_7a = 0;
                      uVar12 = 0;
                      if (lVar5 != 0) {
                        uVar12 = *(undefined8 *)(lVar5 + 0x30);
                      }
                      iVar1 = FUN_183bdf1c8(uVar12,"ImageMask",(long)&local_7a + 1);
                      if ((iVar1 == 0) || (local_7a._1_1_ == '\0')) {
                        iVar1 = FUN_183bd6c4c(uVar12,"Width",&local_68);
                        if ((iVar1 == 0) || ((long)local_68 < 1)) {
                          pcVar9 = "missing or invalid soft-mask `Width\' value.";
                        }
                        else {
                          *(cfstringStruct **)(lVar6 + 0x30) = local_68;
                          iVar1 = FUN_183bd6c4c(uVar12,"Height",&local_68);
                          if ((iVar1 == 0) || ((long)local_68 < 1)) {
                            pcVar9 = "missing or invalid soft-mask `Height\' value.";
                          }
                          else {
                            *(cfstringStruct **)(lVar6 + 0x38) = local_68;
                            if (*(int *)(lVar6 + 0x28) == 2) {
                              pcVar10 = (cfstringStruct *)0x0;
LAB_183c6c04c:
                              *(cfstringStruct **)(lVar6 + 0x40) = pcVar10;
                              uVar2 = FUN_183bd1218(uVar12,"ColorSpace",&local_70);
                              if ((uVar2 & 1) == 0) {
                                if (*(int *)(lVar6 + 0x28) == 2) goto LAB_183c6c0a0;
                                pcVar9 = "missing or invalid soft-mask `ColorSpace\' value.";
                              }
                              else {
                                if (local_70 == 0) {
LAB_183c6c0a0:
                                  uVar8 = 0;
                                }
                                else {
                                  iVar1 = func_0x0001881386b0(local_70,"DeviceGray");
                                  if (iVar1 != 0) {
                                    pcVar9 = "invalid soft-mask `ColorSpace\' value `%s\'.";
                                    goto LAB_183c6bffc;
                                  }
                                  uVar8 = FUN_183b2cf50();
                                }
                                *(undefined8 *)(lVar6 + 0x48) = uVar8;
                                *(undefined1 *)(lVar6 + 0x54) = 0;
                                iVar1 = FUN_183bdf1c8(uVar12,"Interpolate",&local_7a);
                                if (iVar1 != 0) {
                                  *(bool *)(lVar6 + 0x54) = (char)local_7a != '\0';
                                }
                                uVar2 = _set_image_decode_array(lVar6,uVar12,1,0);
                                if ((uVar2 & 1) == 0) {
                                  pcVar9 = "invalid soft-mask `Decode\' value.";
                                }
                                else {
                                  *(undefined8 *)(lVar6 + 0x90) = 0;
                                  iVar1 = FUN_183bcf620(uVar12,"Matte",&local_78);
                                  if (iVar1 != 0) {
                                    uVar8 = func_0x000188138470(lVar4 << 3,0x100004000313f17);
                                    func_0x000188142e40(uVar8,"CGPDFNamedAlloc_Image");
                                    *(undefined8 *)(lVar6 + 0x90) = uVar8;
                                    uVar2 = FUN_183d52c04(local_78,uVar8,lVar4);
                                    if ((uVar2 & 1) == 0) {
                                      pcVar9 = "invalid soft-mask `Matte\' value.";
                                      goto LAB_183c6bffc;
                                    }
                                  }
                                  iVar1 = FUN_183bcf4b0(uVar12,"Mask",0);
                                  if (iVar1 == 0) {
                                    local_60 = (undefined *)0x0;
                                    iVar1 = FUN_183bcf4b0(uVar12,"SMask",&local_60);
                                    if (((iVar1 == 0) || (local_60 == (undefined *)0x0)) ||
                                       (*(int *)(local_60 + 8) != 9)) {
                                      *(long *)(lVar3 + 0x70) = lVar6;
                                      goto LAB_183c6bf20;
                                    }
                                    pcVar9 = "`SMask\' not allowed in soft-mask image.";
                                  }
                                  else {
                                    pcVar9 = "`Mask\' not allowed in soft-mask image.";
                                  }
                                }
                              }
                            }
                            else {
                              uVar2 = FUN_183bd6c4c(uVar12,"BitsPerComponent",&local_68);
                              if ((uVar2 & 1) == 0) {
                                pcVar9 = "missing or invalid soft-mask `BitsPerComponent\' value.";
                              }
                              else {
                                if ((local_68 < (cfstringStruct *)0x11) &&
                                   (pcVar10 = local_68,
                                   (1L << ((ulong)local_68 & 0x3f) & 0x10116U) != 0))
                                goto LAB_183c6c04c;
                                pcVar9 = "invalid soft-mask `BitsPerComponent\' value.";
                              }
                            }
                          }
                        }
                      }
                      else {
                        pcVar9 = "invalid soft-mask `ImageMask\' value.";
                      }
LAB_183c6bffc:
                      _pdf_error(pcVar9);
                    }
                    func_0x000188141240(lVar6);
                  }
                  *(undefined8 *)(lVar3 + 0x70) = 0;
                  goto LAB_183c6bb90;
                }
                iVar1 = FUN_183bf4260(uVar11,"Mask",&local_88);
                if (iVar1 == 0) {
                  iVar1 = FUN_183bcf620(uVar11,"Mask",&local_98);
                  if (iVar1 != 0) {
                    uVar12 = func_0x000188138470(lVar4 << 4,0x100004000313f17);
                    func_0x000188142e40(uVar12,"CGPDFNamedAlloc_Image");
                    *(undefined8 *)(lVar3 + 0x80) = uVar12;
                    uVar2 = FUN_183d52c04(local_98,uVar12,lVar4 << 1);
                    if ((uVar2 & 1) == 0) {
                      pcVar9 = "invalid image `Mask\' value.";
                      goto LAB_183c6bb8c;
                    }
                  }
                }
                else {
                  lVar4 = _create_mask(local_88);
                  *(long *)(lVar3 + 0x68) = lVar4;
                  if (lVar4 == 0) goto LAB_183c6bb90;
                }
LAB_183c6bf20:
                iVar1 = FUN_183bf4260(uVar11,"AAPL:EPSData",&local_88);
                if (iVar1 == 0) goto LAB_183c6bb9c;
                lVar4 = FUN_183bf42d0(local_88,&local_a4);
                *(long *)(lVar3 + 0x60) = lVar4;
                if ((lVar4 != 0) && (local_a4 == 0)) goto LAB_183c6bb9c;
                pcVar9 = "invalid image `AAPL:EPSData\' value.";
              }
            }
            else {
              lVar4 = FUN_183bd8754();
              *(long *)(lVar3 + 0x48) = lVar4;
              if (lVar4 != 0) {
                lVar5 = func_0x000188140d60();
                if (DAT_1edf367a0 != -1) {
                  func_0x00018813aad0(&DAT_1edf367a0,&DAT_1e22309c8);
                }
                if ((lVar5 != DAT_1edf36a20) || (*(int *)(*(long *)(lVar4 + 0x18) + 0x18) != 9))
                goto LAB_183c6bca8;
              }
              pcVar9 = "invalid image `ColorSpace\' value.";
            }
          }
          else {
            uVar2 = FUN_183bd6c4c(uVar11,"BitsPerComponent",&local_90);
            if ((uVar2 & 1) == 0) {
              pcVar9 = "missing or invalid image `BitsPerComponent\' value.";
            }
            else {
              if ((local_90 < 0x11) && (uVar2 = local_90, (1L << (local_90 & 0x3f) & 0x10116U) != 0)
                 ) goto LAB_183c6bc10;
              pcVar9 = "invalid image `BitsPerComponent\' value.";
            }
          }
        }
      }
LAB_183c6bb8c:
      _pdf_error(pcVar9);
    }
LAB_183c6bb90:
    func_0x000188141240(lVar3);
  }
  lVar3 = 0;
LAB_183c6bb9c:
  if (*_DAT_1e0186220 != local_58) {
    lVar3 = func_0x000188138130();
    return lVar3;
  }
  return lVar3;
}



/* ==== _CGPDFImageCreateInline @ 183c6c4a4 size=1988 ==== */

long _CGPDFImageCreateInline(long param_1,long param_2)

{
  int iVar1;
  ulong uVar2;
  long lVar3;
  long lVar4;
  char *pcVar5;
  long lVar6;
  long lVar7;
  ulong uVar8;
  undefined8 uVar9;
  long lVar10;
  undefined8 uVar11;
  char local_7a;
  char local_79;
  long local_78;
  long local_70;
  ulong local_68;
  double local_60;
  long local_58;
  ulong local_50;
  char *local_48;
  
  if (param_1 == 0) {
    return 0;
  }
  if (param_2 == 0) {
    return 0;
  }
  local_7a = '\0';
  uVar11 = *(undefined8 *)(param_2 + 0x30);
  uVar2 = FUN_183bdf1c8(uVar11,"ImageMask",&local_7a);
  if (((uVar2 & 1) != 0) || (uVar2 = FUN_183bdf1c8(uVar11,"IM",&local_7a), (uVar2 & 1) != 0)) {
    if (local_7a == '\0') goto LAB_183c6c674;
    if (DAT_1eb056f88 != -1) {
      func_0x00018813aad0(&DAT_1eb056f88,&DAT_1e223d8b0);
    }
    lVar3 = _pdf_create_cftype(DAT_1eb056f90,0x98);
    if (lVar3 == 0) {
      return 0;
    }
    *(long *)(lVar3 + 0x18) = param_2;
    *(undefined1 *)(lVar3 + 0x10) = 1;
    lVar4 = FUN_183bf42d0(param_2,lVar3 + 0x28);
    *(long *)(lVar3 + 0x20) = lVar4;
    if (lVar4 == 0) goto LAB_183c6cc08;
    local_48 = (char *)0x0;
    local_50 = local_50 & 0xffffffffffffff00;
    uVar11 = *(undefined8 *)(param_2 + 0x30);
    iVar1 = FUN_183bd6c4c(uVar11,"Width",&local_48);
    if ((iVar1 == 0) || ((long)local_48 < 1)) {
      iVar1 = FUN_183bd6c4c(uVar11,"W",&local_48);
      pcVar5 = "missing or invalid image mask `Width\' value.";
      if ((iVar1 != 0) && (0 < (long)local_48)) goto LAB_183c6c5bc;
    }
    else {
LAB_183c6c5bc:
      *(char **)(lVar3 + 0x30) = local_48;
      iVar1 = FUN_183bd6c4c(uVar11,"Height",&local_48);
      if ((iVar1 == 0) || ((long)local_48 < 1)) {
        iVar1 = FUN_183bd6c4c(uVar11,"H",&local_48);
        pcVar5 = "missing or invalid image mask `Height\' value.";
        if ((iVar1 == 0) || ((long)local_48 < 1)) goto LAB_183c6cc04;
      }
      *(char **)(lVar3 + 0x38) = local_48;
      if (*(int *)(lVar3 + 0x28) == 2) {
        uVar9 = 0;
      }
      else {
        uVar2 = FUN_183bd6c4c(uVar11,"BitsPerComponent",&local_48);
        if ((uVar2 & 1) == 0) {
          iVar1 = FUN_183bd6c4c(uVar11,"BPC",&local_48);
          uVar9 = 1;
          if (iVar1 == 0) goto LAB_183c6c628;
        }
        uVar9 = 1;
        if (local_48 != (char *)0x1) {
          pcVar5 = "invalid image mask `BitsPerComponent\' value.";
          goto LAB_183c6cc04;
        }
      }
LAB_183c6c628:
      *(undefined8 *)(lVar3 + 0x40) = uVar9;
      iVar1 = FUN_183bdf1c8(uVar11,"Interpolate",&local_50);
      if ((iVar1 == 0) && (iVar1 = FUN_183bdf1c8(uVar11,"I",&local_50), iVar1 == 0)) {
        *(undefined1 *)(lVar3 + 0x54) = 0;
      }
      else {
        *(bool *)(lVar3 + 0x54) = (char)local_50 != '\0';
      }
      uVar2 = _set_image_decode_array(lVar3,uVar11,1,1);
      if ((uVar2 & 1) != 0) {
        return lVar3;
      }
      pcVar5 = "invalid image mask `Decode\' value.";
    }
    goto LAB_183c6cc04;
  }
  local_7a = '\0';
LAB_183c6c674:
  if (DAT_1eb056f88 != -1) {
    func_0x00018813aad0(&DAT_1eb056f88,&DAT_1e223d8b0);
  }
  lVar3 = _pdf_create_cftype(DAT_1eb056f90,0x98);
  if (lVar3 == 0) {
    return 0;
  }
  *(long *)(lVar3 + 0x18) = param_2;
  *(undefined1 *)(lVar3 + 0x10) = 0;
  lVar4 = FUN_183bf42d0(param_2,lVar3 + 0x28);
  *(long *)(lVar3 + 0x20) = lVar4;
  if (lVar4 == 0) goto LAB_183c6cc08;
  local_68 = 0;
  local_60 = 0.0;
  local_78 = 0;
  local_70 = 0;
  local_79 = '\0';
  uVar11 = *(undefined8 *)(param_2 + 0x30);
  iVar1 = FUN_183be0248(uVar11,"Width",&local_60);
  if (((iVar1 != 0) && (1.0 <= local_60)) ||
     ((iVar1 = FUN_183be0248(uVar11,"W",&local_60), iVar1 != 0 && (1.0 <= local_60)))) {
    *(long *)(lVar3 + 0x30) = (long)local_60;
    iVar1 = FUN_183be0248(uVar11,"Height",&local_60);
    if (((iVar1 != 0) && (1.0 <= local_60)) ||
       ((iVar1 = FUN_183be0248(uVar11,"H",&local_60), iVar1 != 0 && (1.0 <= local_60)))) {
      *(long *)(lVar3 + 0x38) = (long)local_60;
      if (*(int *)(lVar3 + 0x28) == 2) {
        uVar2 = 0;
      }
      else {
        uVar2 = FUN_183bd6c4c(uVar11,"BitsPerComponent",&local_68);
        if (((uVar2 & 1) == 0) && (uVar2 = FUN_183bd6c4c(uVar11,"BPC",&local_68), (uVar2 & 1) == 0))
        {
          pcVar5 = "missing or invalid image `BitsPerComponent\' value.";
          goto LAB_183c6cc04;
        }
        if ((0x10 < local_68) || (uVar2 = local_68, (1L << (local_68 & 0x3f) & 0x10116U) == 0)) {
          _pdf_error("invalid image `BitsPerComponent\' value.");
          return 0;
        }
      }
      *(ulong *)(lVar3 + 0x40) = uVar2;
      uVar2 = FUN_183bcf4b0(uVar11,"ColorSpace",&local_70);
      if (((uVar2 & 1) == 0) && (uVar2 = FUN_183bcf4b0(uVar11,"CS",&local_70), (uVar2 & 1) == 0)) {
        if (*(int *)(lVar3 + 0x28) == 2) {
LAB_183c6c8e0:
          lVar4 = 0;
LAB_183c6c8e4:
          *(long *)(lVar3 + 0x48) = lVar4;
LAB_183c6c8e8:
          _set_image_rendering_intent(lVar3,uVar11);
          iVar1 = FUN_183bdf1c8(uVar11,"Interpolate",&local_79);
          if ((iVar1 == 0) && (iVar1 = FUN_183bdf1c8(uVar11,"I",&local_79), iVar1 == 0)) {
            *(undefined1 *)(lVar3 + 0x54) = 0;
          }
          else {
            *(bool *)(lVar3 + 0x54) = local_79 != '\0';
          }
          if (*(long *)(lVar3 + 0x48) == 0) {
            uVar2 = 0;
          }
          else {
            uVar2 = *(ulong *)(*(long *)(*(long *)(lVar3 + 0x48) + 0x18) + 0x30);
          }
          local_68 = uVar2;
          uVar8 = _set_image_decode_array(lVar3,uVar11,uVar2,1);
          if ((uVar8 & 1) != 0) {
            *(uint *)(lVar3 + 0x58) = (uint)(uVar2 == 3);
            if (*(int *)(lVar3 + 0x28) != 1) {
              return lVar3;
            }
            uVar2 = FUN_183bd75c4(uVar11,"DecodeParms",&local_78);
            if (((uVar2 & 1) == 0) && (iVar1 = FUN_183bd75c4(uVar11,"DP",&local_78), iVar1 == 0)) {
              return lVar3;
            }
            if (local_78 == 0) {
              return lVar3;
            }
            iVar1 = FUN_183bd6c4c(local_78,"ColorTransform",&local_68);
            if (iVar1 != 0) {
              if (1 < local_68) {
                _pdf_error("invalid image `ColorTransform\' value.");
                return lVar3;
              }
              *(int *)(lVar3 + 0x58) = (int)local_68;
              return lVar3;
            }
            return lVar3;
          }
          pcVar5 = "invalid image `Decode\' value.";
        }
        else {
          pcVar5 = "missing or invalid image `ColorSpace\' value.";
        }
      }
      else {
        if (local_70 == 0) goto LAB_183c6c8e0;
        local_50 = 0;
        local_48 = (char *)0x0;
        local_58 = 0;
        if (*(int *)(local_70 + 8) != 7) {
          if (*(int *)(local_70 + 8) != 5) goto LAB_183c6cbf8;
          uVar9 = *(undefined8 *)(local_70 + 0x20);
          lVar4 = _create_inline_device_color_space(uVar9);
          if (lVar4 == 0) {
            lVar4 = __ZN22CGPDFContentStreamImpl13getColorSpaceEPKc(param_1 + 0x10,uVar9);
            if (lVar4 == 0) goto LAB_183c6cbf8;
            func_0x000188141250();
          }
          goto LAB_183c6c8e4;
        }
        lVar4 = *(long *)(local_70 + 0x20);
        if ((((((lVar4 == 0) || (*(long *)(lVar4 + 0x18) - *(long *)(lVar4 + 0x10) != 0x20)) ||
              (iVar1 = FUN_183be0724(lVar4,0,&local_48), pcVar5 = local_48, iVar1 == 0)) ||
             ((iVar1 = func_0x0001881386b0(local_48,"Indexed"), iVar1 != 0 &&
              ((*pcVar5 != 'I' || (pcVar5[1] != '\0')))))) ||
            (iVar1 = FUN_183be0724(lVar4,1,&local_48), iVar1 == 0)) ||
           (((iVar1 = FUN_183d52894(lVar4,2,&local_58), iVar1 == 0 ||
             (iVar1 = FUN_183d528fc(lVar4,3,&local_50), iVar1 == 0)) ||
            (lVar6 = _create_inline_device_color_space(local_48), uVar2 = local_50, lVar4 = local_58
            , lVar6 == 0)))) {
LAB_183c6cbf8:
          *(undefined8 *)(lVar3 + 0x48) = 0;
        }
        else {
          if (local_50 == 0) {
LAB_183c6cbc4:
            lVar4 = func_0x000188140d60(lVar6);
            if (DAT_1edf367a0 != -1) {
              func_0x00018813aad0(&DAT_1edf367a0,&DAT_1e22309c8);
            }
            if (lVar4 == DAT_1edf36a20) {
              func_0x000188141240(lVar6);
            }
            goto LAB_183c6cbf8;
          }
          lVar10 = *(long *)(*(long *)(lVar6 + 0x18) + 0x30);
          lVar7 = lVar10 * local_58;
          if (*(long *)(local_50 + 0x18) != 0) {
            _decrypt_string(local_50);
          }
          if ((lVar10 + lVar7 != *(long *)(uVar2 + 0x48)) || (uVar2 == 0)) goto LAB_183c6cbc4;
          if (*(long *)(uVar2 + 0x18) != 0) {
            _decrypt_string(uVar2);
          }
          lVar4 = FUN_183dc4ea0(lVar6,lVar4,uVar2 + 0x50);
          lVar7 = func_0x000188140d60(lVar6);
          if (DAT_1edf367a0 != -1) {
            func_0x00018813aad0(&DAT_1edf367a0,&DAT_1e22309c8);
          }
          if (lVar7 == DAT_1edf36a20) {
            func_0x000188141240(lVar6);
          }
          *(long *)(lVar3 + 0x48) = lVar4;
          if (lVar4 != 0) goto LAB_183c6c8e8;
        }
        pcVar5 = "invalid image `ColorSpace\' value.";
      }
    }
    else {
      pcVar5 = "missing or invalid image `Height\' value.";
    }
  }
  else {
    pcVar5 = "missing or invalid image `Width\' value.";
  }
LAB_183c6cc04:
  _pdf_error(pcVar5);
LAB_183c6cc08:
  func_0x000188141240(lVar3);
  return 0;
}



