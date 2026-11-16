/* ==== _CGPDFShadingType1Init @ 183f01694 size=472 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _CGPDFShadingType1Init(long param_1,undefined8 *param_2,undefined8 *param_3)

{
  bool bVar1;
  int iVar2;
  long lVar3;
  undefined8 *puVar4;
  ulong uVar5;
  char *pcVar6;
  long lVar7;
  undefined8 uVar8;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  long local_48;
  
  local_48 = *_DAT_1e0186220;
  if ((param_1 == 0) || (lVar7 = *(long *)(param_1 + 0x28), lVar7 == 0)) {
LAB_183f01720:
    puVar4 = (undefined8 *)func_0x000188138460(1,0x58,0x102004004d1cacc);
    func_0x000188142e40(puVar4,"CGPDFNamedAlloc_Graphics");
    *param_2 = puVar4;
    param_3[1] = 0x802000000407c11c;
    *param_3 = 0x8010000003f0186c;
    uVar8 = 0;
    if (param_1 != 0) {
      uVar8 = *(undefined8 *)(param_1 + 0x18);
    }
    uVar5 = FUN_183bd5f94(uVar8,"Domain",puVar4,4);
    if ((uVar5 & 1) == 0) {
      puVar4[1] = 0x3ff0000000000000;
      *puVar4 = 0;
      puVar4[3] = 0x3ff0000000000000;
      puVar4[2] = 0;
    }
    iVar2 = FUN_183bd5f94(uVar8,"Matrix",&local_80,6);
    if (iVar2 == 0) {
      puVar4[5] = 0;
      puVar4[4] = 0x3ff0000000000000;
      puVar4[7] = 0x3ff0000000000000;
      puVar4[6] = 0;
      puVar4[9] = 0;
      puVar4[8] = 0;
    }
    else {
      puVar4[5] = uStack_78;
      puVar4[4] = local_80;
      puVar4[7] = uStack_68;
      puVar4[6] = uStack_70;
      puVar4[9] = uStack_58;
      puVar4[8] = local_60;
    }
    local_80 = 0;
    uVar5 = FUN_183bcf4b0(uVar8,"Function",&local_80);
    if ((uVar5 & 1) != 0) {
      lVar7 = _CGPDFShadingCreateShadingFunction(local_80,2);
      puVar4[10] = lVar7;
      bVar1 = lVar7 != 0;
      goto LAB_183f01820;
    }
    pcVar6 = "missing or invalid shading `Function\' value.";
  }
  else {
    lVar3 = func_0x000188140d60(lVar7);
    if (DAT_1edf367a0 != -1) {
      func_0x00018813aad0(&DAT_1edf367a0,&DAT_1e22309c8);
    }
    if ((lVar3 != DAT_1edf36a20) || (*(int *)(*(long *)(lVar7 + 0x18) + 0x18) != 7))
    goto LAB_183f01720;
    pcVar6 = "invalid shading `ColorSpace\' value.";
  }
  _pdf_error(pcVar6);
  bVar1 = false;
LAB_183f01820:
  if (*_DAT_1e0186220 == local_48) {
    return;
  }
  func_0x000188138130(bVar1);
  return;
}



/* ==== _CGPDFShadingType6Init @ 183f7df14 size=908 ==== */

undefined8 _CGPDFShadingType6Init(long param_1,long *param_2,undefined8 *param_3)

{
  long lVar1;
  ulong uVar2;
  long lVar3;
  long lVar4;
  char *pcVar5;
  undefined8 *puVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  int local_54;
  undefined8 local_50;
  ulong local_48;
  
  if (DAT_1eb058458 != -1) {
    func_0x00018813aad0(&DAT_1eb058458,&DAT_1e22402b0);
  }
  lVar1 = _pdf_create_cftype(DAT_1eb058450,0x70);
  if (lVar1 == 0) {
    return 0;
  }
  local_50 = 0;
  local_48 = 0;
  local_54 = 0;
  *param_2 = lVar1;
  param_3[1] = 0x8010000003f7e3c0;
  *param_3 = 0x8010000003f7e2a0;
  if (param_1 == 0) {
    uVar7 = 0;
    uVar8 = 0;
  }
  else {
    uVar7 = *(undefined4 *)(param_1 + 0x10);
    uVar8 = *(undefined8 *)(param_1 + 0x18);
  }
  *(undefined4 *)(lVar1 + 0x10) = uVar7;
  uVar2 = FUN_183bd6c4c(uVar8,"BitsPerCoordinate",&local_48);
  if ((uVar2 & 1) == 0) {
    pcVar5 = "missing or invalid shading `BitsPerCoordinate\' value.";
    goto LAB_183f7e248;
  }
  if ((0x20 < local_48) || ((1L << (local_48 & 0x3f) & 0x101011116U) == 0)) {
    pcVar5 = "invalid shading `BitsPerCoordinate\' value.";
    goto LAB_183f7e248;
  }
  *(ulong *)(lVar1 + 0x20) = local_48;
  uVar2 = FUN_183bd6c4c(uVar8,"BitsPerComponent",&local_48);
  if ((uVar2 & 1) == 0) {
    pcVar5 = "missing or invalid shading `BitsPerComponent\' value.";
    goto LAB_183f7e248;
  }
  if ((0x10 < local_48) || ((1L << (local_48 & 0x3f) & 0x11116U) == 0)) {
    pcVar5 = "invalid shading `BitsPerComponent\' value.";
    goto LAB_183f7e248;
  }
  *(ulong *)(lVar1 + 0x28) = local_48;
  uVar2 = FUN_183bd6c4c(uVar8,"BitsPerFlag",&local_48);
  if ((uVar2 & 1) == 0) {
    pcVar5 = "missing or invalid shading `BitsPerFlag\' value.";
    goto LAB_183f7e248;
  }
  if ((8 < local_48) || ((1L << (local_48 & 0x3f) & 0x114U) == 0)) {
    pcVar5 = "invalid shading `BitsPerFlag\' value.";
    goto LAB_183f7e248;
  }
  *(ulong *)(lVar1 + 0x30) = local_48;
  *(undefined8 *)(lVar1 + 0x60) = 0;
  uVar2 = FUN_183bcf4b0(uVar8,"Function",&local_50);
  if ((uVar2 & 1) != 0) {
    lVar3 = _CGPDFShadingCreateShadingFunction(local_50,1);
    *(long *)(lVar1 + 0x60) = lVar3;
    if (lVar3 == 0) {
      return 0;
    }
  }
  if (param_1 == 0) {
    if (*(long *)(lVar1 + 0x60) != 0) {
LAB_183f7e138:
      *(undefined8 *)(lVar1 + 0x18) = 0;
      goto LAB_183f7e164;
    }
LAB_183f7e144:
    lVar3 = 0;
    *(undefined8 *)(lVar1 + 0x18) = 0;
  }
  else {
    lVar3 = *(long *)(param_1 + 0x28);
    if (*(long *)(lVar1 + 0x60) == 0) {
      if (lVar3 == 0) goto LAB_183f7e144;
    }
    else {
      if (lVar3 == 0) goto LAB_183f7e138;
      lVar4 = func_0x000188140d60(lVar3);
      if (DAT_1edf367a0 != -1) {
        func_0x00018813aad0(&DAT_1edf367a0,&DAT_1e22309c8);
      }
      if ((lVar4 == DAT_1edf36a20) && (*(int *)(*(long *)(lVar3 + 0x18) + 0x18) == 7)) {
        pcVar5 = "invalid shading `ColorSpace\' value.";
        goto LAB_183f7e248;
      }
    }
    func_0x000188141250(lVar3);
    *(long *)(lVar1 + 0x18) = lVar3;
    if (*(long *)(lVar1 + 0x60) == 0) {
      lVar3 = *(long *)(*(long *)(lVar3 + 0x18) + 0x30) << 1;
    }
    else {
LAB_183f7e164:
      lVar3 = 2;
    }
  }
  puVar6 = (undefined8 *)func_0x000188138470((lVar3 + 4) * 8,0x100004000313f17);
  func_0x000188142e40(puVar6,"CGPDFNamedAlloc_Graphics");
  if (puVar6 == (undefined8 *)0x0) {
    return 0;
  }
  uVar2 = FUN_183bd5f94(uVar8,"Decode",puVar6,lVar3 + 4);
  if ((uVar2 & 1) == 0) {
    _pdf_error("missing or invalid shading `Decode\' value.");
    func_0x000188138390(puVar6);
    return 0;
  }
  *(undefined8 *)(lVar1 + 0x38) = *puVar6;
  *(undefined8 *)(lVar1 + 0x48) = puVar6[1];
  *(undefined8 *)(lVar1 + 0x40) = puVar6[2];
  *(undefined8 *)(lVar1 + 0x50) = puVar6[3];
  func_0x0001881384e0(puVar6,puVar6 + 4,lVar3 << 3);
  *(undefined8 **)(lVar1 + 0x58) = puVar6;
  if (param_1 == 0) {
    uVar8 = 0;
  }
  else {
    uVar8 = *(undefined8 *)(param_1 + 0x20);
  }
  lVar3 = FUN_183ca244c(uVar8,0,0,&local_54);
  *(long *)(lVar1 + 0x68) = lVar3;
  if (lVar3 == 0) {
    return 0;
  }
  if (local_54 == 0) {
    return 1;
  }
  pcVar5 = "invalid shading data format.";
LAB_183f7e248:
  _pdf_error(pcVar5);
  return 0;
}



/* ==== _cg_shading_type6_draw @ 183f7e4a0 size=14284 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _cg_shading_type6_draw(long param_1,undefined8 param_2)

{
  char cVar1;
  int iVar2;
  ulong uVar3;
  int iVar4;
  byte *pbVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  undefined8 *puVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  byte bVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  bool bVar17;
  bool bVar18;
  bool bVar19;
  bool bVar20;
  int iVar21;
  long lVar22;
  byte *pbVar23;
  long lVar24;
  double *pdVar25;
  undefined4 *puVar26;
  int *piVar27;
  int *piVar28;
  undefined1 (*pauVar29) [16];
  undefined1 (*pauVar30) [16];
  undefined1 (*pauVar31) [16];
  undefined8 *puVar32;
  byte *pbVar33;
  int *piVar34;
  double *pdVar35;
  int iVar36;
  int iVar37;
  uint uVar38;
  long lVar39;
  uint uVar40;
  double *pdVar41;
  long lVar42;
  ulong uVar43;
  long lVar44;
  int iVar45;
  long lVar46;
  uint *puVar47;
  undefined1 (*pauVar48) [16];
  undefined8 *puVar49;
  int iVar50;
  int *piVar51;
  uint uVar52;
  ulong uVar53;
  long lVar54;
  ulong uVar55;
  long lVar56;
  int iVar57;
  int iVar58;
  long lVar59;
  ulong uVar60;
  uint uVar61;
  undefined1 uVar62;
  int iVar63;
  uint uVar64;
  ulong uVar65;
  int iVar66;
  undefined8 uVar67;
  int *piVar68;
  undefined8 *puVar69;
  undefined8 *puVar70;
  undefined1 (*pauVar71) [16];
  undefined1 (*pauVar72) [16];
  undefined4 **ppuVar73;
  undefined8 uVar74;
  long lVar75;
  undefined8 uVar76;
  undefined8 uVar77;
  long lVar78;
  undefined1 (*pauVar79) [16];
  undefined1 (*pauVar80) [16];
  int iVar81;
  double dVar82;
  double dVar83;
  undefined1 auVar84 [16];
  undefined1 auVar85 [16];
  undefined1 auVar86 [16];
  undefined1 auVar87 [16];
  undefined1 auVar88 [16];
  undefined1 auVar89 [16];
  double dVar94;
  undefined1 auVar90 [16];
  undefined1 auVar91 [16];
  undefined1 auVar92 [16];
  undefined1 auVar93 [16];
  double dVar95;
  double dVar96;
  double dVar97;
  double dVar98;
  double dVar99;
  double dVar100;
  double dVar101;
  double dVar102;
  double dVar103;
  double dVar104;
  double dVar105;
  double dVar106;
  double dVar107;
  double dVar108;
  double dVar109;
  double dVar110;
  undefined1 auVar111 [16];
  undefined1 auVar112 [16];
  double dVar113;
  double dVar114;
  long in_stack_fffffffffffff788;
  int local_804;
  double *local_7e8;
  long local_7a0;
  undefined4 local_790;
  int local_780;
  double *local_750;
  uint *local_708;
  undefined8 *local_6f0;
  double local_6d8;
  double dStack_6d0;
  double local_6c8;
  double dStack_6c0;
  double local_6b8;
  double dStack_6b0;
  double local_6a8;
  double dStack_6a0;
  double local_698;
  double dStack_690;
  double local_688;
  double dStack_680;
  double local_678;
  double dStack_670;
  double local_668;
  double dStack_660;
  double local_658;
  double dStack_650;
  double local_648;
  double dStack_640;
  double local_638;
  double dStack_630;
  double local_628;
  double dStack_620;
  double local_618 [41];
  double dStack_4d0;
  double local_4c8;
  double dStack_4c0;
  double local_4b8 [5];
  double local_490 [5];
  double local_468 [5];
  double local_440 [5];
  ulong local_418;
  long local_410;
  double local_408;
  double local_400;
  double local_3f8;
  double local_3f0;
  int local_3e8;
  int local_3e4;
  int local_3e0;
  int local_3dc;
  int local_3d8;
  int local_3d4;
  int local_3d0;
  int local_3cc;
  int local_3c8;
  int local_3c4;
  int local_3c0;
  int local_3bc;
  undefined4 *local_3b8;
  undefined4 *local_3b0;
  double local_3a8 [29];
  double local_2c0 [65];
  long local_b8;
  
  local_b8 = *_DAT_1e0186220;
  FUN_183b20e14(param_2,*(undefined8 *)(param_1 + 0x18));
  FUN_183b20f5c(param_2,*(undefined8 *)(param_1 + 0x18));
  if (*(long *)(param_1 + 0x60) == 0) {
    if (*(long *)(param_1 + 0x18) == 0) {
      lVar75 = 0;
    }
    else {
      lVar75 = *(long *)(*(long *)(*(long *)(param_1 + 0x18) + 0x18) + 0x30);
    }
    lVar22 = func_0x000188138470(lVar75 * 0x20 + 0x20,0x100004000313f17);
    if (lVar22 != 0) {
      bVar17 = false;
      uVar3 = lVar75 + 1;
      lVar46 = uVar3 * 8;
      bVar19 = true;
      do {
        bVar18 = bVar19;
        pbVar23 = (byte *)func_0x000188140aa0(*(undefined8 *)(param_1 + 0x68));
        lVar24 = func_0x000188140ab0(*(undefined8 *)(param_1 + 0x68));
        pbVar5 = pbVar23 + lVar24;
        if (lVar24 != 0) {
          uVar65 = 0;
          uVar64 = 0;
          do {
            uVar43 = *(ulong *)(param_1 + 0x30);
            if (*(int *)(param_1 + 0x10) == 6) {
              if (uVar43 < 0x19) {
                uVar38 = 0;
                if (uVar43 == 0) goto LAB_183f7e6d0;
LAB_183f7e6f0:
                for (; uVar65 < uVar43; uVar65 = uVar65 + 8) {
                  uVar64 = uVar64 << 8;
                  pbVar33 = pbVar23;
                  if (pbVar23 < pbVar5) {
                    pbVar33 = pbVar23 + 1;
                    uVar64 = uVar64 | *pbVar23;
                  }
                  pbVar23 = pbVar33;
                }
                uVar65 = uVar65 - uVar43;
                uVar52 = uVar64 >> (ulong)((uint)uVar65 & 0x1f) &
                         0xffffffffU >> (ulong)(-(int)uVar43 & 0x1f);
              }
              else {
                pbVar33 = pbVar23;
                uVar55 = uVar65;
                if (uVar65 < 0x18) {
                  do {
                    uVar64 = uVar64 << 8;
                    pbVar23 = pbVar33;
                    if (pbVar33 < pbVar5) {
                      pbVar23 = pbVar33 + 1;
                      uVar64 = uVar64 | *pbVar33;
                    }
                    uVar65 = uVar55 + 8;
                    bVar19 = uVar55 < 0x10;
                    pbVar33 = pbVar23;
                    uVar55 = uVar65;
                  } while (bVar19);
                }
                uVar43 = uVar43 - 0x18;
                uVar65 = uVar65 - 0x18;
                uVar38 = (uVar64 >> (ulong)((uint)uVar65 & 0x1f) & 0xffffff) <<
                         (ulong)((uint)uVar43 & 0x1f);
                if (uVar43 != 0) goto LAB_183f7e6f0;
LAB_183f7e6d0:
                uVar52 = 0;
              }
              uVar43 = *(ulong *)(param_1 + 0x20);
              uVar55 = *(ulong *)(param_1 + 0x28);
              dVar95 = (double)(0xffffffff >> (ulong)(-(int)uVar43 & 0x1f));
              dVar82 = (double)(0xffffffff >> (ulong)(-(int)uVar55 & 0x1f));
              uVar40 = (uVar52 | uVar38) & 3;
              if (uVar40 == 0) {
                lVar24 = 0;
                dVar99 = *(double *)(param_1 + 0x38);
                dVar102 = *(double *)(param_1 + 0x40);
                dVar105 = *(double *)(param_1 + 0x48);
                dVar108 = *(double *)(param_1 + 0x50);
                uVar53 = uVar43 - 0x18;
                do {
                  if (uVar43 < 0x19) {
                    uVar38 = 0;
                    uVar60 = uVar43;
                    if (uVar43 != 0) goto LAB_183f7eae8;
                    uVar52 = 0;
                  }
                  else {
                    pbVar33 = pbVar23;
                    uVar60 = uVar65;
                    if (uVar65 < 0x18) {
                      do {
                        uVar64 = uVar64 << 8;
                        pbVar23 = pbVar33;
                        if (pbVar33 < pbVar5) {
                          pbVar23 = pbVar33 + 1;
                          uVar64 = uVar64 | *pbVar33;
                        }
                        uVar65 = uVar60 + 8;
                        bVar19 = uVar60 < 0x10;
                        pbVar33 = pbVar23;
                        uVar60 = uVar65;
                      } while (bVar19);
                    }
                    uVar65 = uVar65 - 0x18;
                    uVar38 = (uVar64 >> (ulong)((uint)uVar65 & 0x1f) & 0xffffff) <<
                             (ulong)((uint)uVar53 & 0x1f);
                    uVar52 = 0;
                    uVar60 = uVar53;
                    if (uVar53 != 0) {
LAB_183f7eae8:
                      for (; uVar65 < uVar60; uVar65 = uVar65 + 8) {
                        uVar64 = uVar64 << 8;
                        pbVar33 = pbVar23;
                        if (pbVar23 < pbVar5) {
                          pbVar33 = pbVar23 + 1;
                          uVar64 = uVar64 | *pbVar23;
                        }
                        pbVar23 = pbVar33;
                      }
                      uVar65 = uVar65 - uVar60;
                      uVar52 = uVar64 >> (ulong)((uint)uVar65 & 0x1f) &
                               0xffffffffU >> (ulong)(-(int)uVar60 & 0x1f);
                    }
                  }
                  local_3a8[lVar24 * 2] =
                       dVar99 + ((dVar105 - dVar99) * (double)(uVar52 | uVar38)) / dVar95;
                  if (uVar43 < 0x19) {
                    uVar38 = 0;
                    uVar60 = uVar43;
                    if (uVar43 != 0) goto LAB_183f7eba0;
                    uVar52 = 0;
                  }
                  else {
                    pbVar33 = pbVar23;
                    uVar60 = uVar65;
                    if (uVar65 < 0x18) {
                      do {
                        uVar64 = uVar64 << 8;
                        pbVar23 = pbVar33;
                        if (pbVar33 < pbVar5) {
                          pbVar23 = pbVar33 + 1;
                          uVar64 = uVar64 | *pbVar33;
                        }
                        uVar65 = uVar60 + 8;
                        bVar19 = uVar60 < 0x10;
                        pbVar33 = pbVar23;
                        uVar60 = uVar65;
                      } while (bVar19);
                    }
                    uVar65 = uVar65 - 0x18;
                    uVar38 = (uVar64 >> (ulong)((uint)uVar65 & 0x1f) & 0xffffff) <<
                             (ulong)((uint)uVar53 & 0x1f);
                    uVar52 = 0;
                    uVar60 = uVar53;
                    if (uVar53 != 0) {
LAB_183f7eba0:
                      for (; uVar65 < uVar60; uVar65 = uVar65 + 8) {
                        uVar64 = uVar64 << 8;
                        pbVar33 = pbVar23;
                        if (pbVar23 < pbVar5) {
                          pbVar33 = pbVar23 + 1;
                          uVar64 = uVar64 | *pbVar23;
                        }
                        pbVar23 = pbVar33;
                      }
                      uVar65 = uVar65 - uVar60;
                      uVar52 = uVar64 >> (ulong)((uint)uVar65 & 0x1f) &
                               0xffffffffU >> (ulong)(-(int)uVar60 & 0x1f);
                    }
                  }
                  local_3a8[lVar24 * 2 + 1] =
                       dVar102 + ((dVar108 - dVar102) * (double)(uVar52 | uVar38)) / dVar95;
                  lVar24 = lVar24 + 1;
                } while (lVar24 != 0xc);
                lVar24 = 0;
                uVar43 = uVar55 - 0x18;
                do {
                  if (lVar75 != 0) {
                    lVar59 = 0;
                    lVar56 = *(long *)(param_1 + 0x58);
                    do {
                      if (uVar55 < 0x19) {
                        uVar38 = 0;
                        uVar53 = uVar55;
                        if (uVar55 != 0) goto LAB_183f7ec78;
                        uVar52 = 0;
                      }
                      else {
                        pbVar33 = pbVar23;
                        uVar53 = uVar65;
                        if (uVar65 < 0x18) {
                          do {
                            uVar64 = uVar64 << 8;
                            pbVar23 = pbVar33;
                            if (pbVar33 < pbVar5) {
                              pbVar23 = pbVar33 + 1;
                              uVar64 = uVar64 | *pbVar33;
                            }
                            uVar65 = uVar53 + 8;
                            bVar19 = uVar53 < 0x10;
                            pbVar33 = pbVar23;
                            uVar53 = uVar65;
                          } while (bVar19);
                        }
                        uVar65 = uVar65 - 0x18;
                        uVar38 = (uVar64 >> (ulong)((uint)uVar65 & 0x1f) & 0xffffff) <<
                                 (ulong)((uint)uVar43 & 0x1f);
                        uVar52 = 0;
                        uVar53 = uVar43;
                        if (uVar43 != 0) {
LAB_183f7ec78:
                          for (; uVar65 < uVar53; uVar65 = uVar65 + 8) {
                            uVar64 = uVar64 << 8;
                            pbVar33 = pbVar23;
                            if (pbVar23 < pbVar5) {
                              pbVar33 = pbVar23 + 1;
                              uVar64 = uVar64 | *pbVar23;
                            }
                            pbVar23 = pbVar33;
                          }
                          uVar65 = uVar65 - uVar53;
                          uVar52 = uVar64 >> (ulong)((uint)uVar65 & 0x1f) &
                                   0xffffffffU >> (ulong)(-(int)uVar53 & 0x1f);
                        }
                      }
                      dVar95 = *(double *)(lVar56 + lVar59 * 0x10);
                      dVar102 = *(double *)(lVar56 + (lVar59 << 4 | 8U)) - dVar95;
                      *(double *)(lVar22 + (lVar59 + lVar24 * lVar75) * 8) =
                           dVar95 + (dVar102 * (double)(uVar52 | uVar38)) / dVar82;
                      lVar59 = lVar59 + 1;
                    } while (lVar59 != lVar75);
                  }
                  lVar24 = lVar24 + 1;
                } while (lVar24 != 4);
              }
              else {
                lVar24 = 0;
                lVar59 = 4;
                do {
                  uVar53 = (ulong)((uVar40 * 3 + (int)lVar24) % 0xc);
                  dVar99 = local_3a8[uVar53 * 2];
                  local_3a8[lVar24 * 2 + 1] = local_3a8[uVar53 * 2 + 1];
                  local_3a8[lVar24 * 2] = dVar99;
                  lVar24 = lVar24 + 1;
                  lVar59 = lVar59 + -1;
                } while (lVar59 != 0);
                dVar99 = *(double *)(param_1 + 0x38);
                dVar102 = *(double *)(param_1 + 0x40);
                dVar105 = *(double *)(param_1 + 0x48);
                dVar108 = *(double *)(param_1 + 0x50);
                uVar53 = uVar43 - 0x18;
                lVar24 = 4;
                do {
                  if (uVar43 < 0x19) {
                    uVar40 = 0;
                    uVar60 = uVar43;
                    if (uVar43 != 0) goto LAB_183f7e7fc;
                    uVar61 = 0;
                  }
                  else {
                    pbVar33 = pbVar23;
                    uVar60 = uVar65;
                    if (uVar65 < 0x18) {
                      do {
                        uVar64 = uVar64 << 8;
                        pbVar23 = pbVar33;
                        if (pbVar33 < pbVar5) {
                          pbVar23 = pbVar33 + 1;
                          uVar64 = uVar64 | *pbVar33;
                        }
                        uVar65 = uVar60 + 8;
                        bVar19 = uVar60 < 0x10;
                        pbVar33 = pbVar23;
                        uVar60 = uVar65;
                      } while (bVar19);
                    }
                    uVar65 = uVar65 - 0x18;
                    uVar40 = (uVar64 >> (ulong)((uint)uVar65 & 0x1f) & 0xffffff) <<
                             (ulong)((uint)uVar53 & 0x1f);
                    uVar61 = 0;
                    uVar60 = uVar53;
                    if (uVar53 != 0) {
LAB_183f7e7fc:
                      for (; uVar65 < uVar60; uVar65 = uVar65 + 8) {
                        uVar64 = uVar64 << 8;
                        pbVar33 = pbVar23;
                        if (pbVar23 < pbVar5) {
                          pbVar33 = pbVar23 + 1;
                          uVar64 = uVar64 | *pbVar23;
                        }
                        pbVar23 = pbVar33;
                      }
                      uVar65 = uVar65 - uVar60;
                      uVar61 = uVar64 >> (ulong)((uint)uVar65 & 0x1f) &
                               0xffffffffU >> (ulong)(-(int)uVar60 & 0x1f);
                    }
                  }
                  local_3a8[lVar24 * 2] =
                       dVar99 + ((dVar105 - dVar99) * (double)(uVar61 | uVar40)) / dVar95;
                  if (uVar43 < 0x19) {
                    uVar40 = 0;
                    uVar60 = uVar43;
                    if (uVar43 != 0) goto LAB_183f7e8b4;
                    uVar61 = 0;
                  }
                  else {
                    pbVar33 = pbVar23;
                    uVar60 = uVar65;
                    if (uVar65 < 0x18) {
                      do {
                        uVar64 = uVar64 << 8;
                        pbVar23 = pbVar33;
                        if (pbVar33 < pbVar5) {
                          pbVar23 = pbVar33 + 1;
                          uVar64 = uVar64 | *pbVar33;
                        }
                        uVar65 = uVar60 + 8;
                        bVar19 = uVar60 < 0x10;
                        pbVar33 = pbVar23;
                        uVar60 = uVar65;
                      } while (bVar19);
                    }
                    uVar65 = uVar65 - 0x18;
                    uVar40 = (uVar64 >> (ulong)((uint)uVar65 & 0x1f) & 0xffffff) <<
                             (ulong)((uint)uVar53 & 0x1f);
                    uVar61 = 0;
                    uVar60 = uVar53;
                    if (uVar53 != 0) {
LAB_183f7e8b4:
                      for (; uVar65 < uVar60; uVar65 = uVar65 + 8) {
                        uVar64 = uVar64 << 8;
                        pbVar33 = pbVar23;
                        if (pbVar23 < pbVar5) {
                          pbVar33 = pbVar23 + 1;
                          uVar64 = uVar64 | *pbVar23;
                        }
                        pbVar23 = pbVar33;
                      }
                      uVar65 = uVar65 - uVar60;
                      uVar61 = uVar64 >> (ulong)((uint)uVar65 & 0x1f) &
                               0xffffffffU >> (ulong)(-(int)uVar60 & 0x1f);
                    }
                  }
                  local_3a8[lVar24 * 2 + 1] =
                       dVar102 + ((dVar108 - dVar102) * (double)(uVar61 | uVar40)) / dVar95;
                  lVar24 = lVar24 + 1;
                } while (lVar24 != 0xc);
                lVar24 = 0;
                bVar19 = true;
                do {
                  bVar20 = bVar19;
                  if (lVar75 != 0) {
                    lVar59 = 0;
                    lVar56 = lVar75;
                    do {
                      *(undefined8 *)(lVar22 + (lVar59 + lVar24 * lVar75) * 8) =
                           *(undefined8 *)
                            (lVar22 + (lVar59 + ((ulong)((int)lVar24 + (uVar52 | uVar38)) & 3) *
                                                lVar75) * 8);
                      lVar59 = lVar59 + 1;
                      lVar56 = lVar56 + -1;
                    } while (lVar56 != 0);
                  }
                  lVar24 = 1;
                  bVar19 = false;
                } while (bVar20);
                uVar43 = uVar55 - 0x18;
                lVar24 = 2;
                bVar19 = false;
                do {
                  if (lVar75 != 0) {
                    lVar59 = 0;
                    lVar56 = *(long *)(param_1 + 0x58);
                    do {
                      if (uVar55 < 0x19) {
                        uVar38 = 0;
                        uVar53 = uVar55;
                        if (uVar55 != 0) goto LAB_183f7e9e4;
                        uVar52 = 0;
                      }
                      else {
                        pbVar33 = pbVar23;
                        uVar53 = uVar65;
                        if (uVar65 < 0x18) {
                          do {
                            uVar64 = uVar64 << 8;
                            pbVar23 = pbVar33;
                            if (pbVar33 < pbVar5) {
                              pbVar23 = pbVar33 + 1;
                              uVar64 = uVar64 | *pbVar33;
                            }
                            uVar65 = uVar53 + 8;
                            bVar20 = uVar53 < 0x10;
                            pbVar33 = pbVar23;
                            uVar53 = uVar65;
                          } while (bVar20);
                        }
                        uVar65 = uVar65 - 0x18;
                        uVar38 = (uVar64 >> (ulong)((uint)uVar65 & 0x1f) & 0xffffff) <<
                                 (ulong)((uint)uVar43 & 0x1f);
                        uVar52 = 0;
                        uVar53 = uVar43;
                        if (uVar43 != 0) {
LAB_183f7e9e4:
                          for (; uVar65 < uVar53; uVar65 = uVar65 + 8) {
                            uVar64 = uVar64 << 8;
                            pbVar33 = pbVar23;
                            if (pbVar23 < pbVar5) {
                              pbVar33 = pbVar23 + 1;
                              uVar64 = uVar64 | *pbVar23;
                            }
                            pbVar23 = pbVar33;
                          }
                          uVar65 = uVar65 - uVar53;
                          uVar52 = uVar64 >> (ulong)((uint)uVar65 & 0x1f) &
                                   0xffffffffU >> (ulong)(-(int)uVar53 & 0x1f);
                        }
                      }
                      dVar95 = *(double *)(lVar56 + lVar59 * 0x10);
                      dVar102 = *(double *)(lVar56 + (lVar59 << 4 | 8U)) - dVar95;
                      *(double *)(lVar22 + (lVar59 + lVar24 * lVar75) * 8) =
                           dVar95 + (dVar102 * (double)(uVar52 | uVar38)) / dVar82;
                      lVar59 = lVar59 + 1;
                    } while (lVar59 != lVar75);
                  }
                  lVar24 = 3;
                  bVar20 = !bVar19;
                  bVar19 = true;
                } while (bVar20);
              }
            }
            else {
              if (uVar43 < 0x19) {
                uVar38 = 0;
                if (uVar43 == 0) goto LAB_183f7ed00;
LAB_183f7ed20:
                for (; uVar65 < uVar43; uVar65 = uVar65 + 8) {
                  uVar64 = uVar64 << 8;
                  pbVar33 = pbVar23;
                  if (pbVar23 < pbVar5) {
                    pbVar33 = pbVar23 + 1;
                    uVar64 = uVar64 | *pbVar23;
                  }
                  pbVar23 = pbVar33;
                }
                uVar65 = uVar65 - uVar43;
                uVar52 = uVar64 >> (ulong)((uint)uVar65 & 0x1f) &
                         0xffffffffU >> (ulong)(-(int)uVar43 & 0x1f);
              }
              else {
                pbVar33 = pbVar23;
                uVar55 = uVar65;
                if (uVar65 < 0x18) {
                  do {
                    uVar64 = uVar64 << 8;
                    pbVar23 = pbVar33;
                    if (pbVar33 < pbVar5) {
                      pbVar23 = pbVar33 + 1;
                      uVar64 = uVar64 | *pbVar33;
                    }
                    uVar65 = uVar55 + 8;
                    bVar19 = uVar55 < 0x10;
                    pbVar33 = pbVar23;
                    uVar55 = uVar65;
                  } while (bVar19);
                }
                uVar43 = uVar43 - 0x18;
                uVar65 = uVar65 - 0x18;
                uVar38 = (uVar64 >> (ulong)((uint)uVar65 & 0x1f) & 0xffffff) <<
                         (ulong)((uint)uVar43 & 0x1f);
                if (uVar43 != 0) goto LAB_183f7ed20;
LAB_183f7ed00:
                uVar52 = 0;
              }
              uVar43 = *(ulong *)(param_1 + 0x20);
              uVar55 = *(ulong *)(param_1 + 0x28);
              dVar95 = (double)(0xffffffff >> (ulong)(-(int)uVar43 & 0x1f));
              dVar82 = (double)(0xffffffff >> (ulong)(-(int)uVar55 & 0x1f));
              lVar24 = 0;
              uVar40 = (uVar52 | uVar38) & 3;
              if (uVar40 == 0) {
                dVar99 = *(double *)(param_1 + 0x38);
                dVar102 = *(double *)(param_1 + 0x40);
                dVar105 = *(double *)(param_1 + 0x48);
                dVar108 = *(double *)(param_1 + 0x50);
                uVar53 = uVar43 - 0x18;
                do {
                  if (uVar43 < 0x19) {
                    uVar38 = 0;
                    uVar60 = uVar43;
                    if (uVar43 != 0) goto LAB_183f7f218;
                    uVar52 = 0;
                  }
                  else {
                    pbVar33 = pbVar23;
                    uVar60 = uVar65;
                    if (uVar65 < 0x18) {
                      do {
                        uVar64 = uVar64 << 8;
                        pbVar23 = pbVar33;
                        if (pbVar33 < pbVar5) {
                          pbVar23 = pbVar33 + 1;
                          uVar64 = uVar64 | *pbVar33;
                        }
                        uVar65 = uVar60 + 8;
                        bVar19 = uVar60 < 0x10;
                        pbVar33 = pbVar23;
                        uVar60 = uVar65;
                      } while (bVar19);
                    }
                    uVar65 = uVar65 - 0x18;
                    uVar38 = (uVar64 >> (ulong)((uint)uVar65 & 0x1f) & 0xffffff) <<
                             (ulong)((uint)uVar53 & 0x1f);
                    uVar52 = 0;
                    uVar60 = uVar53;
                    if (uVar53 != 0) {
LAB_183f7f218:
                      for (; uVar65 < uVar60; uVar65 = uVar65 + 8) {
                        uVar64 = uVar64 << 8;
                        pbVar33 = pbVar23;
                        if (pbVar23 < pbVar5) {
                          pbVar33 = pbVar23 + 1;
                          uVar64 = uVar64 | *pbVar23;
                        }
                        pbVar23 = pbVar33;
                      }
                      uVar65 = uVar65 - uVar60;
                      uVar52 = uVar64 >> (ulong)((uint)uVar65 & 0x1f) &
                               0xffffffffU >> (ulong)(-(int)uVar60 & 0x1f);
                    }
                  }
                  local_3a8[lVar24 * 2] =
                       dVar99 + ((dVar105 - dVar99) * (double)(uVar52 | uVar38)) / dVar95;
                  if (uVar43 < 0x19) {
                    uVar38 = 0;
                    uVar60 = uVar43;
                    if (uVar43 != 0) goto LAB_183f7f2d0;
                    uVar52 = 0;
                  }
                  else {
                    pbVar33 = pbVar23;
                    uVar60 = uVar65;
                    if (uVar65 < 0x18) {
                      do {
                        uVar64 = uVar64 << 8;
                        pbVar23 = pbVar33;
                        if (pbVar33 < pbVar5) {
                          pbVar23 = pbVar33 + 1;
                          uVar64 = uVar64 | *pbVar33;
                        }
                        uVar65 = uVar60 + 8;
                        bVar19 = uVar60 < 0x10;
                        pbVar33 = pbVar23;
                        uVar60 = uVar65;
                      } while (bVar19);
                    }
                    uVar65 = uVar65 - 0x18;
                    uVar38 = (uVar64 >> (ulong)((uint)uVar65 & 0x1f) & 0xffffff) <<
                             (ulong)((uint)uVar53 & 0x1f);
                    uVar52 = 0;
                    uVar60 = uVar53;
                    if (uVar53 != 0) {
LAB_183f7f2d0:
                      for (; uVar65 < uVar60; uVar65 = uVar65 + 8) {
                        uVar64 = uVar64 << 8;
                        pbVar33 = pbVar23;
                        if (pbVar23 < pbVar5) {
                          pbVar33 = pbVar23 + 1;
                          uVar64 = uVar64 | *pbVar23;
                        }
                        pbVar23 = pbVar33;
                      }
                      uVar65 = uVar65 - uVar60;
                      uVar52 = uVar64 >> (ulong)((uint)uVar65 & 0x1f) &
                               0xffffffffU >> (ulong)(-(int)uVar60 & 0x1f);
                    }
                  }
                  local_3a8[lVar24 * 2 + 1] =
                       dVar102 + ((dVar108 - dVar102) * (double)(uVar52 | uVar38)) / dVar95;
                  lVar24 = lVar24 + 1;
                } while (lVar24 != 0xc);
                do {
                  uVar60 = uVar43;
                  if (0x18 < uVar43) {
                    pbVar33 = pbVar23;
                    uVar60 = uVar65;
                    if (uVar65 < 0x18) {
                      do {
                        uVar64 = uVar64 << 8;
                        pbVar23 = pbVar33;
                        if (pbVar33 < pbVar5) {
                          pbVar23 = pbVar33 + 1;
                          uVar64 = uVar64 | *pbVar33;
                        }
                        uVar65 = uVar60 + 8;
                        bVar19 = uVar60 < 0x10;
                        pbVar33 = pbVar23;
                        uVar60 = uVar65;
                      } while (bVar19);
                    }
                    uVar65 = uVar65 - 0x18;
                    uVar60 = uVar53;
                  }
                  if (uVar60 != 0) {
                    for (; uVar65 < uVar60; uVar65 = uVar65 + 8) {
                      uVar64 = uVar64 << 8;
                      pbVar33 = pbVar23;
                      if (pbVar23 < pbVar5) {
                        pbVar33 = pbVar23 + 1;
                        uVar64 = uVar64 | *pbVar23;
                      }
                      pbVar23 = pbVar33;
                    }
                    uVar65 = uVar65 - uVar60;
                  }
                  uVar60 = uVar43;
                  if (0x18 < uVar43) {
                    pbVar33 = pbVar23;
                    uVar60 = uVar65;
                    if (uVar65 < 0x18) {
                      do {
                        uVar64 = uVar64 << 8;
                        pbVar23 = pbVar33;
                        if (pbVar33 < pbVar5) {
                          pbVar23 = pbVar33 + 1;
                          uVar64 = uVar64 | *pbVar33;
                        }
                        uVar65 = uVar60 + 8;
                        bVar19 = uVar60 < 0x10;
                        pbVar33 = pbVar23;
                        uVar60 = uVar65;
                      } while (bVar19);
                    }
                    uVar65 = uVar65 - 0x18;
                    uVar60 = uVar53;
                  }
                  if (uVar60 != 0) {
                    for (; uVar65 < uVar60; uVar65 = uVar65 + 8) {
                      uVar64 = uVar64 << 8;
                      pbVar33 = pbVar23;
                      if (pbVar23 < pbVar5) {
                        pbVar33 = pbVar23 + 1;
                        uVar64 = uVar64 | *pbVar23;
                      }
                      pbVar23 = pbVar33;
                    }
                    uVar65 = uVar65 - uVar60;
                  }
                  lVar24 = lVar24 + 1;
                } while (lVar24 != 0x10);
                lVar24 = 0;
                uVar43 = uVar55 - 0x18;
                do {
                  if (lVar75 != 0) {
                    lVar59 = 0;
                    lVar56 = *(long *)(param_1 + 0x58);
                    do {
                      if (uVar55 < 0x19) {
                        uVar38 = 0;
                        uVar53 = uVar55;
                        if (uVar55 != 0) goto LAB_183f7f4ac;
                        uVar52 = 0;
                      }
                      else {
                        pbVar33 = pbVar23;
                        uVar53 = uVar65;
                        if (uVar65 < 0x18) {
                          do {
                            uVar64 = uVar64 << 8;
                            pbVar23 = pbVar33;
                            if (pbVar33 < pbVar5) {
                              pbVar23 = pbVar33 + 1;
                              uVar64 = uVar64 | *pbVar33;
                            }
                            uVar65 = uVar53 + 8;
                            bVar19 = uVar53 < 0x10;
                            pbVar33 = pbVar23;
                            uVar53 = uVar65;
                          } while (bVar19);
                        }
                        uVar65 = uVar65 - 0x18;
                        uVar38 = (uVar64 >> (ulong)((uint)uVar65 & 0x1f) & 0xffffff) <<
                                 (ulong)((uint)uVar43 & 0x1f);
                        uVar52 = 0;
                        uVar53 = uVar43;
                        if (uVar43 != 0) {
LAB_183f7f4ac:
                          for (; uVar65 < uVar53; uVar65 = uVar65 + 8) {
                            uVar64 = uVar64 << 8;
                            pbVar33 = pbVar23;
                            if (pbVar23 < pbVar5) {
                              pbVar33 = pbVar23 + 1;
                              uVar64 = uVar64 | *pbVar23;
                            }
                            pbVar23 = pbVar33;
                          }
                          uVar65 = uVar65 - uVar53;
                          uVar52 = uVar64 >> (ulong)((uint)uVar65 & 0x1f) &
                                   0xffffffffU >> (ulong)(-(int)uVar53 & 0x1f);
                        }
                      }
                      dVar95 = *(double *)(lVar56 + lVar59 * 0x10);
                      dVar102 = *(double *)(lVar56 + (lVar59 << 4 | 8U)) - dVar95;
                      *(double *)(lVar22 + (lVar59 + lVar24 * lVar75) * 8) =
                           dVar95 + (dVar102 * (double)(uVar52 | uVar38)) / dVar82;
                      lVar59 = lVar59 + 1;
                    } while (lVar59 != lVar75);
                  }
                  lVar24 = lVar24 + 1;
                } while (lVar24 != 4);
              }
              else {
                lVar59 = 4;
                do {
                  uVar53 = (ulong)((uVar40 * 3 + (int)lVar24) % 0xc);
                  dVar99 = local_3a8[uVar53 * 2];
                  local_3a8[lVar24 * 2 + 1] = local_3a8[uVar53 * 2 + 1];
                  local_3a8[lVar24 * 2] = dVar99;
                  lVar24 = lVar24 + 1;
                  lVar59 = lVar59 + -1;
                } while (lVar59 != 0);
                dVar99 = *(double *)(param_1 + 0x38);
                dVar102 = *(double *)(param_1 + 0x40);
                dVar105 = *(double *)(param_1 + 0x48);
                dVar108 = *(double *)(param_1 + 0x50);
                uVar53 = uVar43 - 0x18;
                lVar24 = 4;
                do {
                  if (uVar43 < 0x19) {
                    uVar40 = 0;
                    uVar60 = uVar43;
                    if (uVar43 != 0) goto LAB_183f7ee2c;
                    uVar61 = 0;
                  }
                  else {
                    pbVar33 = pbVar23;
                    uVar60 = uVar65;
                    if (uVar65 < 0x18) {
                      do {
                        uVar64 = uVar64 << 8;
                        pbVar23 = pbVar33;
                        if (pbVar33 < pbVar5) {
                          pbVar23 = pbVar33 + 1;
                          uVar64 = uVar64 | *pbVar33;
                        }
                        uVar65 = uVar60 + 8;
                        bVar19 = uVar60 < 0x10;
                        pbVar33 = pbVar23;
                        uVar60 = uVar65;
                      } while (bVar19);
                    }
                    uVar65 = uVar65 - 0x18;
                    uVar40 = (uVar64 >> (ulong)((uint)uVar65 & 0x1f) & 0xffffff) <<
                             (ulong)((uint)uVar53 & 0x1f);
                    uVar61 = 0;
                    uVar60 = uVar53;
                    if (uVar53 != 0) {
LAB_183f7ee2c:
                      for (; uVar65 < uVar60; uVar65 = uVar65 + 8) {
                        uVar64 = uVar64 << 8;
                        pbVar33 = pbVar23;
                        if (pbVar23 < pbVar5) {
                          pbVar33 = pbVar23 + 1;
                          uVar64 = uVar64 | *pbVar23;
                        }
                        pbVar23 = pbVar33;
                      }
                      uVar65 = uVar65 - uVar60;
                      uVar61 = uVar64 >> (ulong)((uint)uVar65 & 0x1f) &
                               0xffffffffU >> (ulong)(-(int)uVar60 & 0x1f);
                    }
                  }
                  local_3a8[lVar24 * 2] =
                       dVar99 + ((dVar105 - dVar99) * (double)(uVar61 | uVar40)) / dVar95;
                  if (uVar43 < 0x19) {
                    uVar40 = 0;
                    uVar60 = uVar43;
                    if (uVar43 != 0) goto LAB_183f7eee4;
                    uVar61 = 0;
                  }
                  else {
                    pbVar33 = pbVar23;
                    uVar60 = uVar65;
                    if (uVar65 < 0x18) {
                      do {
                        uVar64 = uVar64 << 8;
                        pbVar23 = pbVar33;
                        if (pbVar33 < pbVar5) {
                          pbVar23 = pbVar33 + 1;
                          uVar64 = uVar64 | *pbVar33;
                        }
                        uVar65 = uVar60 + 8;
                        bVar19 = uVar60 < 0x10;
                        pbVar33 = pbVar23;
                        uVar60 = uVar65;
                      } while (bVar19);
                    }
                    uVar65 = uVar65 - 0x18;
                    uVar40 = (uVar64 >> (ulong)((uint)uVar65 & 0x1f) & 0xffffff) <<
                             (ulong)((uint)uVar53 & 0x1f);
                    uVar61 = 0;
                    uVar60 = uVar53;
                    if (uVar53 != 0) {
LAB_183f7eee4:
                      for (; uVar65 < uVar60; uVar65 = uVar65 + 8) {
                        uVar64 = uVar64 << 8;
                        pbVar33 = pbVar23;
                        if (pbVar23 < pbVar5) {
                          pbVar33 = pbVar23 + 1;
                          uVar64 = uVar64 | *pbVar23;
                        }
                        pbVar23 = pbVar33;
                      }
                      uVar65 = uVar65 - uVar60;
                      uVar61 = uVar64 >> (ulong)((uint)uVar65 & 0x1f) &
                               0xffffffffU >> (ulong)(-(int)uVar60 & 0x1f);
                    }
                  }
                  local_3a8[lVar24 * 2 + 1] =
                       dVar102 + ((dVar108 - dVar102) * (double)(uVar61 | uVar40)) / dVar95;
                  lVar24 = lVar24 + 1;
                } while (lVar24 != 0xc);
                do {
                  uVar60 = uVar43;
                  if (0x18 < uVar43) {
                    pbVar33 = pbVar23;
                    uVar60 = uVar65;
                    if (uVar65 < 0x18) {
                      do {
                        uVar64 = uVar64 << 8;
                        pbVar23 = pbVar33;
                        if (pbVar33 < pbVar5) {
                          pbVar23 = pbVar33 + 1;
                          uVar64 = uVar64 | *pbVar33;
                        }
                        uVar65 = uVar60 + 8;
                        bVar19 = uVar60 < 0x10;
                        pbVar33 = pbVar23;
                        uVar60 = uVar65;
                      } while (bVar19);
                    }
                    uVar65 = uVar65 - 0x18;
                    uVar60 = uVar53;
                  }
                  if (uVar60 != 0) {
                    for (; uVar65 < uVar60; uVar65 = uVar65 + 8) {
                      uVar64 = uVar64 << 8;
                      pbVar33 = pbVar23;
                      if (pbVar23 < pbVar5) {
                        pbVar33 = pbVar23 + 1;
                        uVar64 = uVar64 | *pbVar23;
                      }
                      pbVar23 = pbVar33;
                    }
                    uVar65 = uVar65 - uVar60;
                  }
                  uVar60 = uVar43;
                  if (0x18 < uVar43) {
                    pbVar33 = pbVar23;
                    uVar60 = uVar65;
                    if (uVar65 < 0x18) {
                      do {
                        uVar64 = uVar64 << 8;
                        pbVar23 = pbVar33;
                        if (pbVar33 < pbVar5) {
                          pbVar23 = pbVar33 + 1;
                          uVar64 = uVar64 | *pbVar33;
                        }
                        uVar65 = uVar60 + 8;
                        bVar19 = uVar60 < 0x10;
                        pbVar33 = pbVar23;
                        uVar60 = uVar65;
                      } while (bVar19);
                    }
                    uVar65 = uVar65 - 0x18;
                    uVar60 = uVar53;
                  }
                  if (uVar60 != 0) {
                    for (; uVar65 < uVar60; uVar65 = uVar65 + 8) {
                      uVar64 = uVar64 << 8;
                      pbVar33 = pbVar23;
                      if (pbVar23 < pbVar5) {
                        pbVar33 = pbVar23 + 1;
                        uVar64 = uVar64 | *pbVar23;
                      }
                      pbVar23 = pbVar33;
                    }
                    uVar65 = uVar65 - uVar60;
                  }
                  lVar24 = lVar24 + 1;
                } while (lVar24 != 0x10);
                lVar24 = 0;
                bVar19 = true;
                do {
                  bVar20 = bVar19;
                  if (lVar75 != 0) {
                    lVar59 = 0;
                    lVar56 = lVar75;
                    do {
                      *(undefined8 *)(lVar22 + (lVar59 + lVar24 * lVar75) * 8) =
                           *(undefined8 *)
                            (lVar22 + (lVar59 + ((ulong)((int)lVar24 + (uVar52 | uVar38)) & 3) *
                                                lVar75) * 8);
                      lVar59 = lVar59 + 1;
                      lVar56 = lVar56 + -1;
                    } while (lVar56 != 0);
                  }
                  lVar24 = 1;
                  bVar19 = false;
                } while (bVar20);
                uVar43 = uVar55 - 0x18;
                lVar24 = 2;
                bVar19 = false;
                do {
                  if (lVar75 != 0) {
                    lVar59 = 0;
                    lVar56 = *(long *)(param_1 + 0x58);
                    do {
                      if (uVar55 < 0x19) {
                        uVar38 = 0;
                        uVar53 = uVar55;
                        if (uVar55 != 0) goto LAB_183f7f118;
                        uVar52 = 0;
                      }
                      else {
                        pbVar33 = pbVar23;
                        uVar53 = uVar65;
                        if (uVar65 < 0x18) {
                          do {
                            uVar64 = uVar64 << 8;
                            pbVar23 = pbVar33;
                            if (pbVar33 < pbVar5) {
                              pbVar23 = pbVar33 + 1;
                              uVar64 = uVar64 | *pbVar33;
                            }
                            uVar65 = uVar53 + 8;
                            bVar20 = uVar53 < 0x10;
                            pbVar33 = pbVar23;
                            uVar53 = uVar65;
                          } while (bVar20);
                        }
                        uVar65 = uVar65 - 0x18;
                        uVar38 = (uVar64 >> (ulong)((uint)uVar65 & 0x1f) & 0xffffff) <<
                                 (ulong)((uint)uVar43 & 0x1f);
                        uVar52 = 0;
                        uVar53 = uVar43;
                        if (uVar43 != 0) {
LAB_183f7f118:
                          for (; uVar65 < uVar53; uVar65 = uVar65 + 8) {
                            uVar64 = uVar64 << 8;
                            pbVar33 = pbVar23;
                            if (pbVar23 < pbVar5) {
                              pbVar33 = pbVar23 + 1;
                              uVar64 = uVar64 | *pbVar23;
                            }
                            pbVar23 = pbVar33;
                          }
                          uVar65 = uVar65 - uVar53;
                          uVar52 = uVar64 >> (ulong)((uint)uVar65 & 0x1f) &
                                   0xffffffffU >> (ulong)(-(int)uVar53 & 0x1f);
                        }
                      }
                      dVar95 = *(double *)(lVar56 + lVar59 * 0x10);
                      dVar102 = *(double *)(lVar56 + (lVar59 << 4 | 8U)) - dVar95;
                      *(double *)(lVar22 + (lVar59 + lVar24 * lVar75) * 8) =
                           dVar95 + (dVar102 * (double)(uVar52 | uVar38)) / dVar82;
                      lVar59 = lVar59 + 1;
                    } while (lVar59 != lVar75);
                  }
                  lVar24 = 3;
                  bVar20 = !bVar19;
                  bVar19 = true;
                } while (bVar20);
              }
            }
            if (bVar17) {
              lVar59 = 0xb;
              lVar24 = 1;
              dVar95 = local_3a8[1];
              dVar99 = local_3a8[1];
              dVar82 = local_3a8[0];
              dVar105 = local_3a8[0];
              do {
                dVar83 = local_3a8[lVar24 * 2];
                dVar96 = local_3a8[lVar24 * 2 + 1];
                dVar108 = dVar82;
                if (dVar82 < dVar83) {
                  dVar108 = dVar83;
                }
                if (dVar105 <= dVar83) {
                  dVar83 = dVar105;
                  dVar82 = dVar108;
                }
                dVar105 = dVar95;
                if (dVar95 < dVar96) {
                  dVar105 = dVar96;
                }
                dVar94 = dVar96;
                if (dVar99 <= dVar96) {
                  dVar94 = dVar99;
                  dVar95 = dVar105;
                }
                lVar24 = lVar24 + 1;
                lVar59 = lVar59 + -1;
                dVar99 = dVar94;
                dVar105 = dVar83;
              } while (lVar59 != 0);
              FUN_183b23d60(param_2);
              auVar84 = FUN_183b1f840();
              local_408 = auVar84._0_8_;
              local_400 = dVar96;
              local_3f8 = dVar108;
              local_3f0 = dVar102;
              dVar99 = (double)NEON_fminnm(dVar108,dVar102);
              if (0.0 <= dVar99) {
                dVar105 = local_408;
                if (dVar83 <= local_408 + dVar108) goto LAB_183f7f884;
              }
              else {
                dVar97 = local_408 + dVar108;
                dVar105 = -dVar108;
                if (0.0 <= dVar108) {
                  dVar97 = local_408;
                  dVar105 = dVar108;
                }
                dVar98 = INFINITY;
                if (dVar96 != INFINITY && local_408 != INFINITY) {
                  dVar98 = dVar97;
                }
                dVar97 = 0.0;
                if (dVar96 != INFINITY && local_408 != INFINITY) {
                  dVar97 = dVar105;
                }
                if (dVar83 <= dVar98 + dVar97) {
                  dVar105 = INFINITY;
                  if (((local_408 != INFINITY) && (dVar96 != INFINITY)) &&
                     (dVar105 = local_408 + dVar108, 0.0 <= dVar108)) {
                    dVar105 = local_408;
                  }
LAB_183f7f884:
                  if (dVar105 <= dVar82) {
                    if (0.0 <= dVar99) {
                      dVar82 = dVar96;
                      if (dVar94 <= dVar96 + dVar102) goto LAB_183f7f914;
                    }
                    else {
                      dVar99 = dVar96 + dVar102;
                      dVar82 = -dVar102;
                      if (0.0 <= dVar102) {
                        dVar99 = dVar96;
                        dVar82 = dVar102;
                      }
                      dVar105 = INFINITY;
                      if (dVar96 != INFINITY && local_408 != INFINITY) {
                        dVar105 = dVar99;
                      }
                      dVar99 = 0.0;
                      if (dVar96 != INFINITY && local_408 != INFINITY) {
                        dVar99 = dVar82;
                      }
                      if (dVar94 <= dVar105 + dVar99) {
                        dVar82 = INFINITY;
                        if (((local_408 != INFINITY) && (dVar96 != INFINITY)) &&
                           (dVar82 = dVar96 + dVar102, 0.0 <= dVar102)) {
                          dVar82 = dVar96;
                        }
LAB_183f7f914:
                        if (dVar82 <= dVar95) {
                          local_410 = 0;
                          local_618[1] = 0.0;
                          local_618[0] = 0.0;
                          local_618[3] = 0.0;
                          local_618[2] = 0.0;
                          local_618[5] = 0.0;
                          local_618[4] = 0.0;
                          local_618[7] = 0.0;
                          local_618[6] = 0.0;
                          local_618[9] = 0.0;
                          local_618[8] = 0.0;
                          local_618[0xb] = 0.0;
                          local_618[10] = 0.0;
                          local_618[0xd] = 0.0;
                          local_618[0xc] = 0.0;
                          local_618[0xf] = 0.0;
                          local_618[0xe] = 0.0;
                          local_618[0x11] = 0.0;
                          local_618[0x10] = 0.0;
                          local_618[0x13] = 0.0;
                          local_618[0x12] = 0.0;
                          local_618[0x15] = 0.0;
                          local_618[0x14] = 0.0;
                          local_618[0x17] = 0.0;
                          local_618[0x16] = 0.0;
                          local_618[0x19] = 0.0;
                          local_618[0x18] = 0.0;
                          local_618[0x1b] = 0.0;
                          local_618[0x1a] = 0.0;
                          local_618[0x1d] = 0.0;
                          local_618[0x1c] = 0.0;
                          local_618[0x1f] = 0.0;
                          local_618[0x1e] = 0.0;
                          local_618[0x21] = 0.0;
                          local_618[0x20] = 0.0;
                          local_618[0x23] = 0.0;
                          local_618[0x22] = 0.0;
                          local_618[0x25] = 0.0;
                          local_618[0x24] = 0.0;
                          local_618[0x27] = 0.0;
                          local_618[0x26] = 0.0;
                          FUN_183bdc19c(local_2c0,param_2);
                          local_6d8 = local_2c0[4] +
                                      local_2c0[2] * local_3a8[1] + local_2c0[0] * local_3a8[0];
                          dStack_6d0 = local_2c0[5] +
                                       local_2c0[3] * local_3a8[1] + local_2c0[1] * local_3a8[0];
                          local_6c8 = local_2c0[4] +
                                      local_2c0[2] * local_3a8[3] + local_2c0[0] * local_3a8[2];
                          dStack_6c0 = local_2c0[5] +
                                       local_2c0[3] * local_3a8[3] + local_2c0[1] * local_3a8[2];
                          local_6b8 = local_2c0[4] +
                                      local_2c0[2] * local_3a8[5] + local_2c0[0] * local_3a8[4];
                          dStack_6b0 = local_2c0[5] +
                                       local_2c0[3] * local_3a8[5] + local_2c0[1] * local_3a8[4];
                          local_6a8 = local_2c0[4] +
                                      local_2c0[2] * local_3a8[7] + local_2c0[0] * local_3a8[6];
                          dStack_6a0 = local_2c0[5] +
                                       local_2c0[3] * local_3a8[7] + local_2c0[1] * local_3a8[6];
                          local_698 = local_2c0[4] +
                                      local_2c0[2] * local_3a8[9] + local_2c0[0] * local_3a8[8];
                          dStack_690 = local_2c0[5] +
                                       local_2c0[3] * local_3a8[9] + local_2c0[1] * local_3a8[8];
                          local_688 = local_2c0[4] +
                                      local_2c0[2] * local_3a8[0xb] + local_2c0[0] * local_3a8[10];
                          dStack_680 = local_2c0[5] +
                                       local_2c0[3] * local_3a8[0xb] + local_2c0[1] * local_3a8[10];
                          local_678 = local_2c0[4] +
                                      local_2c0[2] * local_3a8[0xd] + local_2c0[0] * local_3a8[0xc];
                          dStack_670 = local_2c0[5] +
                                       local_2c0[3] * local_3a8[0xd] + local_2c0[1] * local_3a8[0xc]
                          ;
                          local_668 = local_2c0[4] +
                                      local_2c0[2] * local_3a8[0xf] + local_2c0[0] * local_3a8[0xe];
                          dStack_660 = local_2c0[5] +
                                       local_2c0[3] * local_3a8[0xf] + local_2c0[1] * local_3a8[0xe]
                          ;
                          local_658 = local_2c0[4] +
                                      local_2c0[2] * local_3a8[0x11] +
                                      local_2c0[0] * local_3a8[0x10];
                          dStack_650 = local_2c0[5] +
                                       local_2c0[3] * local_3a8[0x11] +
                                       local_2c0[1] * local_3a8[0x10];
                          local_648 = local_2c0[4] +
                                      local_2c0[2] * local_3a8[0x13] +
                                      local_2c0[0] * local_3a8[0x12];
                          dStack_640 = local_2c0[5] +
                                       local_2c0[3] * local_3a8[0x13] +
                                       local_2c0[1] * local_3a8[0x12];
                          local_638 = local_2c0[4] +
                                      local_2c0[2] * local_3a8[0x15] +
                                      local_2c0[0] * local_3a8[0x14];
                          dStack_630 = local_2c0[5] +
                                       local_2c0[3] * local_3a8[0x15] +
                                       local_2c0[1] * local_3a8[0x14];
                          local_628 = local_2c0[4] +
                                      local_2c0[2] * local_3a8[0x17] +
                                      local_2c0[0] * local_3a8[0x16];
                          dStack_620 = local_2c0[5] +
                                       local_2c0[3] * local_3a8[0x17] +
                                       local_2c0[1] * local_3a8[0x16];
                          if (uVar3 < 6) {
                            if (lVar75 != 0) {
                              lVar24 = 0;
                              lVar59 = lVar75;
                              do {
                                local_618[lVar24] = *(double *)(lVar22 + lVar24 * 8);
                                local_618[lVar24 + 5] = *(double *)(lVar22 + (lVar24 + lVar75) * 8);
                                local_618[lVar24 + 10] =
                                     *(double *)(lVar22 + (lVar24 + lVar75 * 2) * 8);
                                local_618[lVar24 + 0xf] =
                                     *(double *)(lVar22 + (lVar24 + lVar75 * 3) * 8);
                                lVar24 = lVar24 + 1;
                                lVar59 = lVar59 + -1;
                              } while (lVar59 != 0);
                            }
                            local_618[lVar75] = 1.0;
                            local_618[lVar75 + 5] = 1.0;
                            local_618[lVar75 + 10] = 1.0;
                            local_618[lVar75 + 0xf] = 1.0;
                            auVar84 = NEON_fmov(0x4008000000000000,8);
                            dVar99 = auVar84._0_8_;
                            local_618[0x16] = (local_628 - local_6d8) * dVar99;
                            dVar102 = auVar84._8_8_;
                            local_618[0x17] = (dStack_620 - dStack_6d0) * dVar102;
                            local_618[0x18] = (local_6c8 - local_6d8) * dVar99;
                            local_618[0x19] = (dStack_6c0 - dStack_6d0) * dVar102;
                            auVar84 = NEON_fmov(0x4014000000000000,8);
                            auVar111 = NEON_fmov(0xc000000000000000,8);
                            dVar82 = auVar111._0_8_;
                            dVar95 = auVar111._8_8_;
                            local_618[0x1a] =
                                 ((((local_698 - local_628) + local_658) - local_6c8) * dVar99 +
                                  auVar84._0_8_ * local_6d8 + dVar82 * (local_6a8 + local_648)) -
                                 local_678;
                            local_618[0x1b] =
                                 ((((dStack_690 - dStack_620) + dStack_650) - dStack_6c0) * dVar102
                                  + auVar84._8_8_ * dStack_6d0 + dVar95 * (dStack_6a0 + dStack_640))
                                 - dStack_670;
                            local_618[0x1c] = (local_6d8 + local_638 + dVar82 * local_628) * dVar99;
                            local_618[0x1d] =
                                 (dStack_6d0 + dStack_630 + dVar95 * dStack_620) * dVar102;
                            local_618[0x1e] = (local_6d8 + local_6b8 + dVar82 * local_6c8) * dVar99;
                            local_618[0x1f] =
                                 (dStack_6d0 + dStack_6b0 + dVar95 * dStack_6c0) * dVar102;
                            auVar84 = NEON_fmov(0x4000000000000000,8);
                            dVar82 = auVar84._0_8_;
                            dVar95 = auVar84._8_8_;
                            local_618[0x20] =
                                 ((((local_6a8 + local_688) - local_638) - local_6d8) +
                                 dVar82 * (local_628 - local_698)) * dVar99;
                            local_618[0x21] =
                                 ((((dStack_6a0 + dStack_680) - dStack_630) - dStack_6d0) +
                                 dVar95 * (dStack_620 - dStack_690)) * dVar102;
                            local_618[0x22] =
                                 ((((local_648 + local_668) - local_6b8) - local_6d8) +
                                 dVar82 * (local_6c8 - local_658)) * dVar99;
                            local_618[0x23] =
                                 ((((dStack_640 + dStack_660) - dStack_6b0) - dStack_6d0) +
                                 dVar95 * (dStack_6c0 - dStack_650)) * dVar102;
                            local_618[0x24] =
                                 (local_648 - local_6d8) + dVar99 * (local_628 - local_638);
                            local_618[0x25] =
                                 (dStack_640 - dStack_6d0) + dVar102 * (dStack_620 - dStack_630);
                            local_618[0x26] =
                                 (local_6a8 - local_6d8) + dVar99 * (local_6c8 - local_6b8);
                            local_618[0x27] =
                                 (dStack_6a0 - dStack_6d0) + dVar102 * (dStack_6c0 - dStack_6b0);
                            local_618[0x28] =
                                 local_6d8 + ((local_678 - local_6a8) - local_648) +
                                 dVar99 * (local_698 + ((local_638 - local_628) - local_688));
                            dStack_4d0 = dStack_6d0 + ((dStack_670 - dStack_6a0) - dStack_640) +
                                         dVar102 * (dStack_690 +
                                                   ((dStack_630 - dStack_620) - dStack_680));
                            local_4c8 = local_6d8 + ((local_678 - local_648) - local_6a8) +
                                        dVar99 * (local_658 + ((local_6b8 - local_6c8) - local_668))
                            ;
                            dStack_4c0 = dStack_6d0 + ((dStack_670 - dStack_640) - dStack_6a0) +
                                         dVar102 * (dStack_650 +
                                                   ((dStack_6b0 - dStack_6c0) - dStack_660));
                            if (uVar3 != 0) {
                              lVar24 = 0;
                              uVar43 = uVar3;
                              do {
                                dVar105 = local_618[lVar24];
                                local_4b8[lVar24] = dVar105;
                                dVar108 = local_618[lVar24 + 0xf];
                                local_490[lVar24] = dVar108 - dVar105;
                                dVar83 = local_618[lVar24 + 5];
                                local_468[lVar24] = dVar83 - dVar105;
                                local_440[lVar24] =
                                     dVar105 + ((local_618[lVar24 + 10] - dVar83) - dVar108);
                                lVar24 = lVar24 + 1;
                                uVar43 = uVar43 - 1;
                              } while (uVar43 != 0);
                            }
                            local_618[0x14] = local_6d8;
                            local_618[0x15] = dStack_6d0;
                            local_418 = uVar3;
                            pdVar25 = (double *)func_0x000188138470(0x30,0x1000040451b5be8);
                            auVar84 = NEON_fmov(0x3fe0000000000000,8);
                            dVar108 = auVar84._8_8_;
                            dVar105 = auVar84._0_8_;
                            if (pdVar25 == (double *)0x0) {
                              local_708 = (uint *)0x0;
                            }
                            else {
                              lVar24 = func_0x000188138470(0x78,0x100004000313f17);
                              uVar43 = local_418;
                              if (lVar24 == 0) {
                                local_708 = (uint *)0x0;
                              }
                              else {
                                local_708 = (uint *)func_0x000188138460(1,0x50,0x1020040af517f5c);
                                if (local_708 == (uint *)0x0) {
LAB_183f80330:
                                  local_708 = (uint *)0x0;
                                }
                                else {
                                  local_708[2] = 0;
                                  local_708[3] = 0;
                                  local_708[6] = 0;
                                  local_708[7] = 0;
                                  local_708[10] = 0;
                                  local_708[0xb] = 0;
                                  *local_708 = (uint)uVar43;
                                  lVar59 = func_0x000188138470(0x1098,0x1000040ff89c88e);
                                  *(long *)(local_708 + 2) = lVar59;
                                  if (lVar59 == 0) {
LAB_183f80328:
                                    _CoonsMeshFree(local_708);
                                    goto LAB_183f80330;
                                  }
                                  lVar59 = 0;
                                  lVar56 = 0x3b;
                                  do {
                                    puVar32 = (undefined8 *)
                                              (*(long *)(local_708 + 2) + lVar59 * 0x48);
                                    puVar32[8] = 0;
                                    puVar32[5] = 0;
                                    puVar32[4] = 0;
                                    puVar32[7] = 0;
                                    puVar32[6] = 0;
                                    puVar32[1] = 0;
                                    *puVar32 = 0;
                                    puVar32[3] = 0;
                                    puVar32[2] = 0;
                                    lVar59 = lVar59 + 1;
                                    lVar56 = lVar56 + -1;
                                  } while (lVar56 != 0);
                                  local_708[4] = 0;
                                  local_708[5] = 0x3b;
                                  lVar59 = func_0x000188138470(0x528,0x1000040a86a77d5);
                                  *(long *)(local_708 + 6) = lVar59;
                                  if (lVar59 == 0) goto LAB_183f80328;
                                  lVar56 = 0;
                                  lVar59 = 0;
                                  do {
                                    puVar32 = (undefined8 *)
                                              (*(long *)(local_708 + 6) + lVar59 * 0x14);
                                    *(undefined4 *)(puVar32 + 2) = 0xffffffff;
                                    *puVar32 = 0xffffffffffffffff;
                                    puVar32[1] = 0xffffffffffffffff;
                                    lVar59 = lVar59 + 1;
                                    lVar56 = lVar56 + 0x14;
                                  } while (lVar56 != 0x528);
                                  local_708[8] = 0;
                                  local_708[9] = 0x42;
                                  lVar59 = func_0x000188138470(0xae0,0x1000040eed21634);
                                  *(long *)(local_708 + 10) = lVar59;
                                  if (lVar59 == 0) goto LAB_183f80328;
                                  lVar59 = 0;
                                  lVar56 = 0x2c;
                                  do {
                                    puVar32 = (undefined8 *)
                                              (*(long *)(local_708 + 10) + lVar59 * 0x30);
                                    puVar32[1] = 0xffffffffffffffff;
                                    *puVar32 = 0xffffffffffffffff;
                                    puVar32[3] = 0xffffffffffffffff;
                                    puVar32[2] = 0xffffffffffffffff;
                                    puVar32[4] = 0xffffffffffffffff;
                                    puVar32[5] = 1;
                                    lVar59 = lVar59 + 1;
                                    lVar56 = lVar56 + 0x30;
                                  } while (lVar56 != 0xb0c);
                                  puVar47 = local_708 + 0xe;
                                  puVar47[0] = 0xffffffff;
                                  puVar47[1] = 0xffffffff;
                                  local_708[0x10] = 0xffffffff;
                                  local_708[0x11] = 0xffffffff;
                                  local_708[4] = 9;
                                  local_708[8] = 0x10;
                                  local_708[0xc] = 8;
                                  local_708[0xd] = 0x3a;
                                  auVar112 = ZEXT816(0);
                                  lVar59 = 0;
                                  while( true ) {
                                    uVar43 = local_418;
                                    dVar83 = auVar112._0_8_;
                                    if (local_418 != 0) {
                                      lVar56 = 0;
                                      uVar55 = local_418;
                                      do {
                                        dVar96 = local_490[lVar56] + dVar83 * local_440[lVar56];
                                        local_2c0[lVar56] =
                                             local_4b8[lVar56] + dVar83 * local_468[lVar56] +
                                             dVar96 * 0.0;
                                        local_3a8[lVar56 + 0x18] = dVar96 * 0.5;
                                        lVar56 = lVar56 + 1;
                                        uVar55 = uVar55 - 1;
                                      } while (uVar55 != 0);
                                    }
                                    lVar56 = 0;
                                    dVar100 = local_618[0x24] + local_618[0x28] * dVar83;
                                    dVar101 = local_618[0x25] + dStack_4d0 * dVar83;
                                    dVar97 = local_618[0x1c] + local_618[0x20] * dVar83;
                                    dVar98 = local_618[0x1d] + local_618[0x21] * dVar83;
                                    dVar96 = local_618[0x16] +
                                             (local_618[0x1a] +
                                             (local_618[0x22] + local_4c8 * dVar83) * dVar83) *
                                             dVar83;
                                    dVar94 = local_618[0x17] +
                                             (local_618[0x1b] +
                                             (local_618[0x23] + dStack_4c0 * dVar83) * dVar83) *
                                             dVar83;
                                    dVar103 = dVar100 * dVar99 * dVar105;
                                    dVar104 = dVar101 * dVar102 * dVar108;
                                    dVar106 = (dVar103 + dVar82 * dVar97) * dVar105;
                                    dVar107 = (dVar104 + dVar95 * dVar98) * dVar108;
                                    dVar109 = (dVar103 + dVar103) * dVar105;
                                    dVar110 = (dVar104 + dVar104) * dVar108;
                                    dVar113 = local_618[0x14] +
                                              (local_618[0x18] +
                                              (local_618[0x1e] + local_618[0x26] * dVar83) * dVar83)
                                              * dVar83 +
                                              (dVar96 + (dVar97 + dVar100 * 0.0) * 0.0) * 0.0;
                                    dVar114 = local_618[0x15] +
                                              (local_618[0x19] +
                                              (local_618[0x1f] + local_618[0x27] * dVar83) * dVar83)
                                              * dVar83 +
                                              (dVar94 + (dVar98 + dVar101 * 0.0) * 0.0) * 0.0;
                                    dVar96 = (dVar96 + dVar105 * (dVar97 + dVar105 * dVar100)) *
                                             dVar105 + (dVar106 + dVar103 * 0.0) * 0.0;
                                    dVar94 = (dVar94 + dVar108 * (dVar98 + dVar108 * dVar101)) *
                                             dVar108 + (dVar107 + dVar104 * 0.0) * 0.0;
                                    dVar97 = (dVar106 + dVar105 * dVar103) * dVar105 + dVar109 * 0.0
                                    ;
                                    dVar98 = (dVar107 + dVar108 * dVar104) * dVar108 + dVar110 * 0.0
                                    ;
                                    lVar78 = local_418 << 3;
                                    lVar54 = lVar24;
                                    pdVar35 = pdVar25;
                                    do {
                                      pdVar35[1] = dVar114;
                                      *pdVar35 = dVar113;
                                      if (uVar43 != 0) {
                                        func_0x0001881384d0(lVar54,local_2c0,lVar78);
                                        lVar44 = 0;
                                        uVar55 = uVar43;
                                        do {
                                          local_2c0[lVar44] =
                                               local_3a8[lVar44 + 0x18] + local_2c0[lVar44];
                                          lVar44 = lVar44 + 1;
                                          uVar55 = uVar55 - 1;
                                        } while (uVar55 != 0);
                                      }
                                      dVar113 = dVar113 + dVar96;
                                      dVar114 = dVar114 + dVar94;
                                      dVar96 = dVar96 + dVar97;
                                      dVar94 = dVar94 + dVar98;
                                      dVar97 = dVar109 * dVar105 + dVar97;
                                      dVar98 = dVar110 * dVar108 + dVar98;
                                      lVar56 = lVar56 + 1;
                                      pdVar35 = pdVar35 + 2;
                                      lVar54 = lVar54 + 0x28;
                                    } while (lVar56 != 3);
                                    lVar56 = 0;
                                    lVar54 = lVar59 * 2;
                                    iVar21 = (int)(lVar59 * 3);
                                    iVar45 = (int)lVar54 + 2;
                                    iVar57 = iVar21 + 3;
                                    dVar96 = 1.0;
                                    if (dVar83 <= 1.0) {
                                      dVar96 = dVar83;
                                    }
                                    dVar94 = 0.0;
                                    lVar78 = lVar24;
                                    pdVar35 = pdVar25;
                                    while( true ) {
                                      lVar44 = lVar56 + lVar59 * 3;
                                      pdVar41 = (double *)(*(long *)(local_708 + 2) + lVar44 * 0x48)
                                      ;
                                      dVar97 = *pdVar35;
                                      pdVar41[1] = pdVar35[1];
                                      *pdVar41 = dVar97;
                                      dVar97 = 1.0;
                                      if (dVar94 <= 1.0) {
                                        dVar97 = dVar94;
                                      }
                                      pdVar41[2] = dVar97;
                                      pdVar41[3] = dVar96;
                                      uVar43 = (ulong)*local_708;
                                      if (*local_708 != 0) {
                                        lVar39 = 0;
                                        do {
                                          pdVar41[lVar39 + 4] = *(double *)(lVar78 + lVar39 * 8);
                                          lVar39 = lVar39 + 1;
                                          uVar43 = uVar43 - 1;
                                        } while (uVar43 != 0);
                                      }
                                      iVar63 = (int)lVar44;
                                      if (lVar56 == 2) break;
                                      lVar42 = *(long *)(local_708 + 6);
                                      lVar39 = lVar56 + lVar54;
                                      piVar51 = (int *)(lVar42 + lVar39 * 0x14);
                                      iVar36 = (int)lVar56;
                                      iVar81 = iVar21 + 1 + iVar36;
                                      *piVar51 = iVar63;
                                      piVar51[1] = iVar81;
                                      if (lVar59 == 2) {
                                        piVar51[2] = -1;
                                        piVar51[3] = (iVar36 + 6) * 3;
                                      }
                                      else {
                                        uVar38 = (uint)lVar39;
                                        iVar50 = uVar38 * 3;
                                        piVar51[2] = iVar50;
                                        piVar6 = (int *)(lVar42 + lVar44 * 0x14 + 0x78);
                                        iVar66 = (iVar36 + iVar45) * 3;
                                        lVar44 = lVar54 + 0xc + lVar56;
                                        piVar68 = (int *)(lVar42 + lVar44 * 0x14);
                                        lVar42 = *(long *)(local_708 + 10);
                                        piVar7 = (int *)(lVar42 + lVar39 * 0x30);
                                        if (lVar59 == 0) {
                                          iVar66 = -1;
                                        }
                                        piVar51[3] = iVar66;
                                        iVar4 = iVar57 + iVar36;
                                        *piVar6 = iVar4;
                                        piVar6[1] = iVar63;
                                        iVar66 = iVar50 + 0xb;
                                        iVar2 = iVar36 * 3 + 0xc;
                                        if (lVar59 == 0) {
                                          iVar2 = -1;
                                        }
                                        if (lVar56 == 0) {
                                          iVar66 = -1;
                                        }
                                        piVar6[2] = iVar50 + 2;
                                        piVar6[3] = iVar66;
                                        *piVar68 = iVar81;
                                        piVar68[1] = iVar4;
                                        lVar39 = lVar56 + lVar54 + 4;
                                        uVar40 = (uint)lVar39;
                                        iVar66 = uVar40 * 3 + 1;
                                        piVar68[2] = iVar50 + 1;
                                        piVar68[3] = iVar66;
                                        *piVar7 = iVar63;
                                        piVar7[1] = iVar81;
                                        piVar7[2] = iVar4;
                                        piVar7[3] = uVar38 << 1;
                                        uVar52 = (int)lVar44 << 1;
                                        piVar7[4] = uVar52;
                                        piVar7[5] = iVar63 * 2 + 0xc;
                                        piVar7[6] = iVar2;
                                        piVar7[7] = iVar66;
                                        iVar63 = (int)(lVar54 + 4) * 3 + 2;
                                        if (lVar56 == 0) {
                                          iVar63 = -1;
                                        }
                                        piVar7[8] = iVar63;
                                        if (local_708[0xe] == 0xffffffff) {
                                          local_708[0xf] = uVar38;
                                        }
                                        piVar7[9] = local_708[0xe];
                                        *puVar47 = uVar38;
                                        piVar7[10] = 1;
                                        piVar7[0xb] = 7 - uVar38;
                                        piVar51 = (int *)(lVar42 + lVar39 * 0x30);
                                        iVar63 = iVar36 + 1;
                                        *piVar51 = iVar63 + iVar57;
                                        piVar51[1] = iVar36 + iVar57;
                                        iVar36 = iVar36 + (int)(lVar59 + 1) * 2;
                                        piVar51[2] = iVar63 + iVar21;
                                        piVar51[3] = iVar36 * 2 | 1;
                                        piVar51[4] = uVar52 | 1;
                                        piVar51[5] = (iVar63 + iVar21) * 2 + 0xd;
                                        iVar36 = iVar36 * 3;
                                        if (lVar59 == 1) {
                                          iVar36 = -1;
                                        }
                                        piVar51[6] = iVar36;
                                        piVar51[7] = iVar50 + 1;
                                        iVar63 = (iVar63 + (int)lVar54) * 3 + 2;
                                        if (lVar56 == 1) {
                                          iVar63 = -1;
                                        }
                                        piVar51[8] = iVar63;
                                        if (*puVar47 == 0xffffffff) {
                                          local_708[0xf] = uVar40;
                                        }
                                        piVar51[9] = *puVar47;
                                        *puVar47 = uVar40;
                                        piVar51[10] = 1;
                                        piVar51[0xb] = 7 - uVar40;
                                      }
                                      lVar56 = lVar56 + 1;
                                      dVar94 = dVar94 + 0.5;
                                      pdVar35 = pdVar35 + 2;
                                      lVar78 = lVar78 + 0x28;
                                    }
                                    if (lVar59 == 2) break;
                                    piVar51 = (int *)(*(long *)(local_708 + 6) +
                                                     lVar44 * 0x14 + 0x78);
                                    *piVar51 = iVar21 + 5;
                                    piVar51[1] = iVar63;
                                    piVar51[2] = -1;
                                    piVar51[3] = iVar45 * 3 + 0xb;
                                    auVar112._0_8_ = dVar83 + 0.5;
                                    auVar112._8_8_ = 0;
                                    lVar59 = lVar59 + 1;
                                  }
                                }
                                func_0x000188138390(lVar24);
                              }
                              func_0x000188138390(pdVar25);
                            }
                            local_708[0x12] = 0;
                            local_708[0x13] = 0;
                            uVar38 = local_708[0xe];
                            while (uVar38 != 0xffffffff) {
                              piVar51 = (int *)(*(long *)(local_708 + 10) + (long)(int)uVar38 * 0x30
                                               );
                              local_708[0xe] = piVar51[9];
                              lVar24 = *(long *)(local_708 + 2);
                              pdVar25 = (double *)(lVar24 + (long)*piVar51 * 0x48);
                              dVar82 = *pdVar25;
                              dVar95 = pdVar25[1];
                              pdVar25 = (double *)(lVar24 + (long)piVar51[1] * 0x48);
                              dVar99 = *pdVar25;
                              pdVar35 = (double *)(lVar24 + (long)piVar51[2] * 0x48);
                              dVar83 = *pdVar35;
                              dVar102 = pdVar25[1] - dVar95;
                              dVar95 = pdVar35[1] - dVar95;
                              if (ABS(((dVar99 - dVar82) * dVar102 +
                                       (dVar102 + dVar95) * (dVar83 - dVar99) +
                                      dVar95 * (dVar82 - dVar83)) * 0.5) < 8.0) {
LAB_183f8140c:
                                *(undefined1 *)(piVar51 + 10) = 0;
                              }
                              else {
                                lVar24 = 0;
                                bVar13 = 0;
                                lVar59 = 3;
                                do {
                                  bVar13 = piVar51[lVar24 + 6] == -1 | bVar13;
                                  lVar24 = lVar24 + 1;
                                  lVar59 = lVar59 + -1;
                                } while (lVar59 != 0);
                                if (!(bool)(*(char *)((long)piVar51 + 0x29) < '\a' | bVar13))
                                goto LAB_183f8140c;
                                uVar43 = 0;
                                local_3a8[0x19] = 0.0;
                                local_3a8[0x18] = 0.0;
                                do {
                                  iVar21 = piVar51[uVar43 + 6];
                                  if (iVar21 != -1) {
                                    uVar55 = 2;
                                    if (uVar43 != 0) {
                                      uVar55 = (ulong)((int)uVar43 - 1);
                                    }
                                    lVar24 = *(long *)(local_708 + 2);
                                    pdVar25 = (double *)(lVar24 + (long)piVar51[uVar55] * 0x48);
                                    iVar45 = 2;
                                    if (0 < iVar21 % 3) {
                                      iVar45 = -1;
                                    }
                                    pdVar35 = (double *)
                                              (lVar24 + (long)*(int *)(*(long *)(local_708 + 10) +
                                                                       (long)(iVar21 / 3) * 0x30 +
                                                                      (ulong)(uint)(iVar45 + iVar21 
                                                  % 3) * 4) * 0x48);
                                    pdVar41 = (double *)(lVar24 + (long)piVar51[uVar43] * 0x48);
                                    dVar82 = *pdVar41;
                                    dVar95 = pdVar41[1];
                                    lVar59 = 0;
                                    if (uVar43 != 2) {
                                      lVar59 = uVar43 + 1;
                                    }
                                    pdVar41 = (double *)(lVar24 + (long)piVar51[lVar59] * 0x48);
                                    dVar99 = *pdVar41 - dVar82;
                                    dVar102 = pdVar41[1] - dVar95;
                                    dVar83 = *pdVar25 - dVar82;
                                    dVar96 = pdVar25[1] - dVar95;
                                    dVar82 = *pdVar35 - dVar82;
                                    dVar95 = pdVar35[1] - dVar95;
                                    if (ABS(dVar83 * (dVar95 - dVar102) + (dVar96 - dVar95) * dVar99
                                            + (dVar102 - dVar96) * dVar82) <=
                                        2.2250738585072014e-308) goto LAB_183f8140c;
                                    if (0.0 <= -(dVar99 * dVar95) + dVar102 * dVar82 ==
                                        -(dVar83 * dVar102) + dVar96 * dVar99 < 0.0) {
                                      local_708[0x13] = local_708[0x13] + 1;
                                      goto LAB_183f8135c;
                                    }
                                  }
                                  uVar43 = uVar43 + 1;
                                } while (uVar43 != 3);
                                uVar43 = 0xffffffff;
                                dVar82 = 0.0;
                                lVar24 = 0;
                                do {
                                  pdVar25 = (double *)
                                            (*(long *)(local_708 + 2) + (long)piVar51[lVar24] * 0x48
                                            );
                                  lVar59 = 0;
                                  if (lVar24 != 2) {
                                    lVar59 = lVar24 + 1;
                                  }
                                  pdVar35 = (double *)
                                            (*(long *)(local_708 + 2) + (long)piVar51[lVar59] * 0x48
                                            );
                                  dVar95 = *pdVar25;
                                  dVar99 = pdVar25[1];
                                  dVar102 = *pdVar35;
                                  dVar83 = pdVar35[1];
                                  lVar59 = lVar24 + 1;
                                  auVar91._0_8_ = (pdVar25[2] + pdVar35[2]) * 0.5;
                                  auVar91._8_8_ = 0;
                                  _Coons(auVar91,(pdVar25[3] + pdVar35[3]) * 0.5,&local_6d8,
                                         local_3a8 + 0x18,local_2c0);
                                  dVar95 = local_3a8[0x18] - (dVar95 + dVar102) * 0.5;
                                  dVar99 = local_3a8[0x19] - (dVar99 + dVar83) * 0.5;
                                  dVar95 = dVar99 * dVar99 + dVar95 * dVar95;
                                  uVar38 = (uint)uVar43;
                                  if (dVar82 <= dVar95) {
                                    uVar38 = (uint)lVar24;
                                  }
                                  uVar43 = (ulong)uVar38;
                                  if (dVar82 <= dVar95) {
                                    dVar82 = dVar95;
                                  }
                                  lVar24 = lVar59;
                                } while (lVar59 != 3);
                                if ((uVar38 == 0xffffffff) || (dVar82 <= 0.48999999999999994)) {
                                  uVar43 = 0xffffffff;
                                  auVar92 = ZEXT816(0);
                                  lVar24 = 0;
                                  do {
                                    lVar59 = lVar24 + 1;
                                    lVar56 = 0;
                                    if (lVar59 != 3) {
                                      lVar56 = lVar24 + 1;
                                    }
                                    if (*local_708 != 0) {
                                      lVar54 = 0;
                                      uVar55 = (ulong)*local_708;
                                      do {
                                        dVar95 = *(double *)
                                                  (*(long *)(local_708 + 2) +
                                                   (long)piVar51[lVar24] * 0x48 + 0x20 + lVar54 * 8)
                                                 - *(double *)
                                                    (*(long *)(local_708 + 2) +
                                                     (long)piVar51[lVar56] * 0x48 + 0x20 +
                                                    lVar54 * 8);
                                        dVar82 = -dVar95;
                                        if (0.0 <= dVar95) {
                                          dVar82 = dVar95;
                                        }
                                        dVar95 = auVar92._0_8_;
                                        uVar38 = (uint)uVar43;
                                        if (dVar95 <= dVar82) {
                                          uVar38 = (uint)lVar24;
                                        }
                                        uVar43 = (ulong)uVar38;
                                        if (dVar95 <= dVar82) {
                                          dVar95 = dVar82;
                                        }
                                        auVar92._8_8_ = 0;
                                        auVar92._0_8_ = dVar95;
                                        lVar54 = lVar54 + 1;
                                        uVar55 = uVar55 - 1;
                                      } while (uVar55 != 0);
                                    }
                                    lVar24 = lVar59;
                                  } while (lVar59 != 3);
                                  if (((int)uVar43 == -1) || (auVar92._0_8_ <= 0.1))
                                  goto LAB_183f8140c;
                                }
                                else {
                                  local_708[0x12] = local_708[0x12] + 1;
                                }
LAB_183f8135c:
                                local_3a8[0x19] = 0.0;
                                local_3a8[0x18] = 0.0;
                                iVar66 = (int)uVar43;
                                iVar21 = piVar51[iVar66];
                                iVar81 = (iVar66 + 1) % 3;
                                iVar45 = piVar51[iVar81];
                                iVar36 = (iVar66 + 2) % 3;
                                iVar57 = piVar51[iVar36];
                                iVar63 = piVar51[(long)iVar66 + 6];
                                if (iVar63 == -1) {
                                  local_804 = 0;
                                  local_6f0 = (undefined8 *)0x0;
                                  local_790 = 0xffffffff;
                                  local_780 = -1;
                                }
                                else {
                                  local_780 = iVar63 / 3;
                                  local_6f0 = (undefined8 *)
                                              (*(long *)(local_708 + 10) + (long)local_780 * 0x30);
                                  local_804 = iVar63 % 3;
                                  iVar50 = 2;
                                  if (0 < local_804) {
                                    iVar50 = -1;
                                  }
                                  local_790 = *(undefined4 *)
                                               ((long)local_6f0 +
                                               (ulong)(uint)(iVar50 + local_804) * 4);
                                }
                                lVar24 = *(long *)(local_708 + 2) + (long)iVar21 * 0x48;
                                lVar59 = *(long *)(local_708 + 2) + (long)iVar45 * 0x48;
                                iVar50 = (int)((long)piVar51 - *(long *)(local_708 + 10) >> 4) *
                                         -0x55555555;
                                auVar90._0_8_ =
                                     (*(double *)(lVar24 + 0x10) + *(double *)(lVar59 + 0x10)) *
                                     dVar105;
                                auVar90._8_8_ =
                                     (*(double *)(lVar24 + 0x18) + *(double *)(lVar59 + 0x18)) *
                                     dVar108;
                                _Coons(auVar90,auVar90._8_8_,&local_6d8,local_3a8 + 0x18,local_2c0);
                                piVar51 = &local_3bc;
                                bVar19 = true;
                                do {
                                  bVar20 = bVar19;
                                  lVar24 = _AllocateCoonsMeshTriangle(local_708);
                                  lVar59 = *(long *)(local_708 + 10);
                                  *piVar51 = (int)((ulong)(lVar24 - lVar59) >> 4) * -0x55555555;
                                  piVar51 = &local_3c0;
                                  bVar19 = false;
                                } while (bVar20);
                                local_3b0 = (undefined4 *)0x0;
                                local_3b8 = (undefined4 *)0x0;
                                if (iVar63 == -1) {
                                  local_3c4 = -1;
                                  local_3c8 = -1;
                                }
                                else {
                                  ppuVar73 = &local_3b0;
                                  piVar51 = &local_3c4;
                                  bVar19 = true;
                                  do {
                                    bVar20 = bVar19;
                                    puVar26 = (undefined4 *)_AllocateCoonsMeshTriangle(local_708);
                                    *ppuVar73 = puVar26;
                                    lVar59 = *(long *)(local_708 + 10);
                                    *piVar51 = (int)((ulong)((long)puVar26 - lVar59) >> 4) *
                                               -0x55555555;
                                    ppuVar73 = &local_3b8;
                                    piVar51 = &local_3c8;
                                    bVar19 = false;
                                  } while (bVar20);
                                }
                                dVar95 = local_3a8[0x19];
                                dVar82 = local_3a8[0x18];
                                iVar2 = local_3bc;
                                iVar4 = local_3c0;
                                piVar51 = (int *)(lVar59 + (long)local_3bc * 0x30);
                                piVar6 = (int *)(lVar59 + (long)local_3c0 * 0x30);
                                puVar32 = (undefined8 *)
                                          (lVar59 + ((long)iVar50 * 2 + (long)iVar50) * 0x10);
                                if (iVar63 != -1) {
                                  local_3b0 = (undefined4 *)(lVar59 + (long)local_3c4 * 0x30);
                                  local_3b8 = (undefined4 *)(lVar59 + (long)local_3c8 * 0x30);
                                  local_6f0 = (undefined8 *)(lVar59 + (long)local_780 * 0x30);
                                }
                                uVar38 = local_708[4];
                                local_7a0 = *(long *)(local_708 + 2);
                                if (uVar38 == local_708[5]) {
                                  local_7a0 = func_0x000188138490(local_7a0,
                                                                  (ulong)(uVar38 + 0x32) * 0x48,
                                                                  0x1000040ff89c88e);
                                  *(long *)(local_708 + 2) = local_7a0;
                                  if (local_7a0 != 0) {
                                    uVar38 = local_708[4];
                                    local_708[5] = local_708[5] + 0x32;
                                    goto LAB_183f80570;
                                  }
                                  local_7a0 = 0;
                                  local_7e8 = (double *)0x0;
                                }
                                else {
LAB_183f80570:
                                  local_708[4] = uVar38 + 1;
                                  local_7e8 = (double *)(local_7a0 + (ulong)uVar38 * 0x48);
                                  *local_7e8 = dVar82;
                                  local_7e8[1] = dVar95;
                                  local_7e8[3] = auVar90._8_8_;
                                  local_7e8[2] = auVar90._0_8_;
                                  uVar43 = (ulong)*local_708;
                                  if (*local_708 != 0) {
                                    lVar24 = 0;
                                    do {
                                      local_7e8[lVar24 + 4] = local_2c0[lVar24];
                                      lVar24 = lVar24 + 1;
                                      uVar43 = uVar43 - 1;
                                    } while (uVar43 != 0);
                                  }
                                }
                                lVar24 = _AllocateCoonsMeshEdge(local_708);
                                lVar59 = *(long *)(local_708 + 6);
                                piVar68 = &local_3cc;
                                bVar19 = true;
                                do {
                                  bVar20 = bVar19;
                                  lVar56 = _AllocateCoonsMeshEdge(local_708);
                                  lVar54 = *(long *)(local_708 + 6);
                                  *piVar68 = (int)((ulong)(lVar56 - lVar54) >> 2) * -0x33333333;
                                  piVar68 = &local_3d0;
                                  bVar19 = false;
                                } while (bVar20);
                                if (iVar63 == -1) {
                                  iVar58 = 0;
                                  puVar26 = (undefined4 *)0x0;
                                }
                                else {
                                  puVar26 = (undefined4 *)_AllocateCoonsMeshEdge(local_708);
                                  lVar54 = *(long *)(local_708 + 6);
                                  iVar58 = (int)((ulong)((long)puVar26 - lVar54) >> 2) * -0x33333333
                                  ;
                                }
                                piVar68 = (int *)(lVar54 + (long)local_3cc * 0x14);
                                piVar7 = (int *)(lVar54 + (long)local_3d0 * 0x14);
                                iVar14 = (int)(lVar24 - lVar59 >> 2);
                                iVar37 = iVar14 * -0x33333333;
                                piVar8 = (int *)(lVar54 + ((long)iVar37 * 4 + (long)iVar37) * 4);
                                if (iVar63 != -1) {
                                  puVar26 = (undefined4 *)(lVar54 + (long)iVar58 * 0x14);
                                }
                                if (local_6f0 == (undefined8 *)0x0) {
                                  local_3d4 = -1;
                                  local_3d8 = -1;
                                }
                                else {
                                  uVar40 = *(uint *)((long)puVar32 + (long)iVar66 * 4 + 0xc);
                                  uVar38 = uVar40 & 1;
                                  uVar61 = *(uint *)((long)local_6f0 + (long)local_804 * 4 + 0xc);
                                  uVar52 = -uVar38;
                                  if (-1 < (int)uVar40) {
                                    uVar52 = uVar38;
                                  }
                                  uVar38 = uVar61 & 1;
                                  uVar40 = -uVar38;
                                  if (-1 < (int)uVar61) {
                                    uVar40 = uVar38;
                                  }
                                  iVar63 = 0;
                                  if (uVar52 == uVar40) {
                                    piVar34 = &local_3d4;
                                    piVar27 = &local_3dc;
                                    piVar28 = &local_3e4;
                                    bVar19 = true;
                                    do {
                                      bVar20 = bVar19;
                                      iVar63 = (local_804 + 2) - iVar63;
                                      uVar38 = iVar63 * 0x56;
                                      lVar24 = (long)(char)((char)iVar63 +
                                                           (((byte)(uVar38 >> 0xf) & 1) +
                                                           (char)(uVar38 >> 8)) * -3);
                                      iVar63 = *(int *)((long)local_6f0 + lVar24 * 4 + 0xc);
                                      *piVar34 = iVar63 / 2;
                                      *piVar27 = ((iVar63 - (iVar63 >> 0x1f) & 0xfffffffeU) - iVar63
                                                 ) + 1;
                                      iVar63 = 1;
                                      *piVar28 = *(int *)((long)local_6f0 + lVar24 * 4 + 0x18);
                                      piVar34 = &local_3d8;
                                      piVar27 = &local_3e0;
                                      piVar28 = &local_3e8;
                                      bVar19 = false;
                                    } while (bVar20);
                                  }
                                  else {
                                    piVar34 = &local_3d4;
                                    piVar27 = &local_3dc;
                                    piVar28 = &local_3e4;
                                    bVar19 = true;
                                    do {
                                      bVar20 = bVar19;
                                      iVar63 = local_804 + 1 + iVar63;
                                      uVar38 = iVar63 * 0x56;
                                      lVar24 = (long)(char)((char)iVar63 +
                                                           (((byte)(uVar38 >> 0xf) & 1) +
                                                           (char)(uVar38 >> 8)) * -3);
                                      iVar63 = *(int *)((long)local_6f0 + lVar24 * 4 + 0xc);
                                      *piVar34 = iVar63 / 2;
                                      *piVar27 = iVar63 % 2;
                                      iVar63 = 1;
                                      *piVar28 = *(int *)((long)local_6f0 + lVar24 * 4 + 0x18);
                                      piVar34 = &local_3d8;
                                      piVar27 = &local_3e0;
                                      piVar28 = &local_3e8;
                                      bVar19 = false;
                                    } while (bVar20);
                                  }
                                }
                                iVar37 = *(int *)((long)puVar32 + (long)iVar36 * 4 + 0xc);
                                iVar36 = *(int *)((long)puVar32 + (long)iVar36 * 4 + 0x18);
                                iVar12 = (int)((ulong)((long)local_7e8 - local_7a0) >> 3) *
                                         0x38e38e39;
                                iVar10 = *(int *)((long)puVar32 + (long)iVar81 * 4 + 0xc);
                                iVar11 = *(int *)((long)puVar32 + (long)iVar81 * 4 + 0x18);
                                *piVar8 = iVar12;
                                piVar8[1] = iVar57;
                                iVar2 = iVar2 * 3;
                                iVar4 = iVar4 * 3;
                                piVar8[2] = iVar2 + 1;
                                piVar8[3] = iVar4 + 1;
                                *piVar68 = iVar21;
                                piVar68[1] = iVar12;
                                iVar15 = local_3c4 * 3;
                                iVar81 = -1;
                                iVar63 = iVar81;
                                if (local_3c4 != -1) {
                                  iVar63 = iVar15 + 1;
                                }
                                piVar68[2] = iVar2;
                                piVar68[3] = iVar63;
                                *piVar7 = iVar12;
                                piVar7[1] = iVar45;
                                iVar16 = local_3c8 * 3;
                                if (local_3c8 != -1) {
                                  iVar81 = iVar16 + 1;
                                }
                                piVar7[2] = iVar4 + 2;
                                piVar7[3] = iVar81;
                                if (local_6f0 != (undefined8 *)0x0) {
                                  *puVar26 = local_790;
                                  puVar26[1] = iVar12;
                                  puVar26[2] = iVar15;
                                  puVar26[3] = iVar16 + 2;
                                }
                                uVar38 = iVar37 / 2;
                                *piVar51 = iVar21;
                                piVar51[1] = iVar12;
                                piVar51[2] = iVar57;
                                piVar51[3] = local_3cc << 1;
                                uVar52 = iVar14 * -0x66666666;
                                piVar51[4] = uVar52;
                                piVar68 = (int *)(lVar54 + ((-(ulong)(uVar38 >> 0x1f) &
                                                             0xfffffffc00000000 | (ulong)uVar38 << 2
                                                            ) + (long)(int)uVar38) * 4);
                                if (*piVar68 == iVar57) {
                                  uVar40 = uVar38 << 1;
LAB_183f80924:
                                  piVar51[5] = uVar40;
                                }
                                else if (piVar68[1] == iVar57) {
                                  uVar40 = uVar38 << 1 | 1;
                                  goto LAB_183f80924;
                                }
                                piVar51[6] = iVar63;
                                piVar51[7] = iVar4 + 1;
                                piVar51[8] = iVar36;
                                lVar24 = *(long *)(local_708 + 10);
                                uVar40 = (int)((ulong)((long)piVar51 - lVar24) >> 4) * -0x55555555;
                                piVar51[9] = -1;
                                if (local_708[0xe] == 0xffffffff) {
                                  local_708[0xe] = uVar40;
                                }
                                else {
                                  *(uint *)(lVar24 + (long)(int)local_708[0xf] * 0x30 + 0x24) =
                                       uVar40;
                                }
                                local_708[0xf] = uVar40;
                                *(undefined1 *)(piVar51 + 10) = 1;
                                cVar1 = *(char *)((long)puVar32 + 0x29) + '\x01';
                                *(char *)((long)piVar51 + 0x29) = cVar1;
                                *(short *)((long)piVar51 + 0x2a) =
                                     *(short *)((long)piVar51 + 0x2a) +
                                     (short)(1 << (ulong)(0x10U - (int)cVar1 & 0x1f));
                                if (iVar36 != -1) {
                                  *(int *)(lVar24 + (long)(iVar36 / 3) * 0x30 + 0x18 +
                                          (long)(iVar36 % 3) * 4) = iVar2 + 2;
                                }
                                lVar59 = lVar54 + (long)(int)uVar38 * 0x14;
                                iVar63 = *(int *)(lVar59 + 8);
                                if ((iVar63 == -1) || (iVar63 / 3 != iVar50)) {
                                  if ((*(int *)(lVar59 + 0xc) != -1) &&
                                     (*(int *)(lVar59 + 0xc) / 3 == iVar50)) {
                                    *(int *)(lVar59 + 0xc) = iVar2 + 2;
                                  }
                                }
                                else {
                                  *(int *)(lVar59 + 8) = iVar2 + 2;
                                }
                                uVar38 = iVar10 / 2;
                                *piVar6 = iVar45;
                                piVar6[1] = iVar57;
                                piVar6[2] = iVar12;
                                piVar51 = (int *)(lVar54 + ((-(ulong)(uVar38 >> 0x1f) &
                                                             0xfffffffc00000000 | (ulong)uVar38 << 2
                                                            ) + (long)(int)uVar38) * 4);
                                if (*piVar51 == iVar45) {
                                  uVar40 = uVar38 << 1;
LAB_183f80ad4:
                                  piVar6[3] = uVar40;
                                }
                                else if (piVar51[1] == iVar45) {
                                  uVar40 = uVar38 << 1 | 1;
                                  goto LAB_183f80ad4;
                                }
                                piVar6[4] = uVar52 | 1;
                                piVar6[5] = local_3d0 << 1;
                                piVar6[6] = iVar11;
                                piVar6[7] = iVar2 + 1;
                                uVar52 = (int)((ulong)((long)piVar6 - lVar24) >> 4) * -0x55555555;
                                piVar6[8] = iVar81;
                                piVar6[9] = -1;
                                if (local_708[0xe] == 0xffffffff) {
                                  local_708[0xe] = uVar52;
                                }
                                else {
                                  *(uint *)(lVar24 + (long)(int)local_708[0xf] * 0x30 + 0x24) =
                                       uVar52;
                                }
                                local_708[0xf] = uVar52;
                                *(undefined1 *)(piVar6 + 10) = 1;
                                *(char *)((long)piVar6 + 0x29) =
                                     *(char *)((long)puVar32 + 0x29) + '\x01';
                                if (iVar11 != -1) {
                                  *(int *)(lVar24 + (long)(iVar11 / 3) * 0x30 + 0x18 +
                                          (long)(iVar11 % 3) * 4) = iVar4;
                                }
                                lVar59 = lVar54 + (long)(int)uVar38 * 0x14;
                                iVar57 = *(int *)(lVar59 + 8);
                                if ((iVar57 == -1) || (iVar57 / 3 != iVar50)) {
                                  if ((*(int *)(lVar59 + 0xc) != -1) &&
                                     (*(int *)(lVar59 + 0xc) / 3 == iVar50)) {
                                    *(int *)(lVar59 + 0xc) = iVar4;
                                  }
                                }
                                else {
                                  *(int *)(lVar59 + 8) = iVar4;
                                }
                                if (local_3b0 != (undefined4 *)0x0) {
                                  *local_3b0 = local_790;
                                  local_3b0[1] = iVar12;
                                  local_3b0[2] = iVar21;
                                  local_3b0[3] = iVar58 << 1;
                                  local_3b0[4] = local_3cc << 1 | 1;
                                  local_3b0[5] = local_3dc + local_3d4 * 2;
                                  local_3b0[6] = iVar16 + 2;
                                  local_3b0[7] = iVar2;
                                  local_3b0[8] = local_3e4;
                                  if (*(char *)(local_6f0 + 5) == '\x01') {
                                    uVar38 = (int)((ulong)((long)local_3b0 - lVar24) >> 4) *
                                             -0x55555555;
                                    local_3b0[9] = 0xffffffff;
                                    if (local_708[0xe] == 0xffffffff) {
                                      local_708[0xe] = uVar38;
                                    }
                                    else {
                                      *(uint *)(lVar24 + (long)(int)local_708[0xf] * 0x30 + 0x24) =
                                           uVar38;
                                    }
                                    local_708[0xf] = uVar38;
                                    uVar62 = 1;
                                  }
                                  else {
                                    uVar62 = 0;
                                    local_3b0[9] = 0xffffffff;
                                  }
                                  *(undefined1 *)(local_3b0 + 10) = uVar62;
                                  *(char *)((long)local_3b0 + 0x29) =
                                       *(char *)((long)local_6f0 + 0x29) + '\x01';
                                  if (local_3e4 != -1) {
                                    *(int *)(lVar24 + (long)(local_3e4 / 3) * 0x30 + 0x18 +
                                            (long)(local_3e4 % 3) * 4) = iVar15 + 2;
                                  }
                                  lVar59 = lVar54 + (long)local_3d4 * 0x14;
                                  iVar21 = *(int *)(lVar59 + 8);
                                  if ((iVar21 == -1) || (iVar21 / 3 != local_780)) {
                                    if ((*(int *)(lVar59 + 0xc) != -1) &&
                                       (*(int *)(lVar59 + 0xc) / 3 == local_780)) {
                                      *(int *)(lVar59 + 0xc) = iVar15 + 2;
                                    }
                                  }
                                  else {
                                    *(int *)(lVar59 + 8) = iVar15 + 2;
                                  }
                                }
                                if (local_3b8 == (undefined4 *)0x0) {
                                  if (local_6f0 != (undefined8 *)0x0) goto LAB_183f80ee4;
                                  uVar38 = *(int *)((long)puVar32 + (long)iVar66 * 4 + 0xc) / 2;
                                  puVar49 = (undefined8 *)(lVar54 + (long)(int)uVar38 * 0x14);
                                  *(uint *)(puVar49 + 2) = local_708[0x11];
                                  local_708[0x11] = uVar38;
                                  *puVar49 = 0xfffffff3fffffff3;
                                  *(uint *)((long)puVar32 + 0x24) = local_708[0x10];
                                  local_708[0x10] =
                                       (int)((ulong)((long)puVar32 - lVar24) >> 4) * -0x55555555;
                                  *(undefined4 *)(puVar32 + 1) = 0xfffffff3;
                                  *puVar32 = 0xfffffff3fffffff3;
                                }
                                else {
                                  *local_3b8 = local_790;
                                  local_3b8[1] = iVar45;
                                  local_3b8[2] = iVar12;
                                  local_3b8[3] = local_3e0 + local_3d8 * 2;
                                  local_3b8[4] = local_3d0 << 1 | 1;
                                  local_3b8[5] = iVar58 << 1 | 1;
                                  local_3b8[6] = local_3e8;
                                  local_3b8[7] = iVar4 + 2;
                                  local_3b8[8] = iVar15;
                                  if (*(char *)(local_6f0 + 5) == '\x01') {
                                    uVar38 = (int)((ulong)((long)local_3b8 - lVar24) >> 4) *
                                             -0x55555555;
                                    local_3b8[9] = 0xffffffff;
                                    if (local_708[0xe] == 0xffffffff) {
                                      local_708[0xe] = uVar38;
                                    }
                                    else {
                                      *(uint *)(lVar24 + (long)(int)local_708[0xf] * 0x30 + 0x24) =
                                           uVar38;
                                    }
                                    local_708[0xf] = uVar38;
                                    uVar62 = 1;
                                  }
                                  else {
                                    uVar62 = 0;
                                    local_3b8[9] = 0xffffffff;
                                  }
                                  *(undefined1 *)(local_3b8 + 10) = uVar62;
                                  *(char *)((long)local_3b8 + 0x29) =
                                       *(char *)((long)local_6f0 + 0x29) + '\x01';
                                  if (local_3e8 != -1) {
                                    *(int *)(lVar24 + (long)(local_3e8 / 3) * 0x30 + 0x18 +
                                            (long)(local_3e8 % 3) * 4) = iVar16;
                                  }
                                  lVar59 = lVar54 + (long)local_3d8 * 0x14;
                                  iVar21 = *(int *)(lVar59 + 8);
                                  if ((iVar21 == -1) || (iVar21 / 3 != local_780)) {
                                    if ((*(int *)(lVar59 + 0xc) != -1) &&
                                       (*(int *)(lVar59 + 0xc) / 3 == local_780)) {
                                      *(int *)(lVar59 + 0xc) = iVar16;
                                    }
                                  }
                                  else {
                                    *(int *)(lVar59 + 8) = iVar16;
                                  }
LAB_183f80ee4:
                                  uVar38 = (int)((ulong)((long)local_6f0 - lVar24) >> 4) *
                                           -0x55555555;
                                  if (local_708[0xe] != 0xffffffff) {
                                    uVar40 = 0xffffffff;
                                    uVar52 = local_708[0xe];
                                    do {
                                      uVar61 = *(uint *)(lVar24 + (long)(int)uVar52 * 0x30 + 0x24);
                                      if (uVar52 == uVar38) {
                                        if (uVar40 == 0xffffffff) {
                                          local_708[0xe] = uVar61;
                                        }
                                        else {
                                          *(uint *)(lVar24 + (long)(int)uVar40 * 0x30 + 0x24) =
                                               uVar61;
                                        }
                                        uVar52 = uVar40;
                                        if (local_708[0xf] == uVar38) {
                                          local_708[0xf] = uVar40;
                                        }
                                      }
                                      uVar40 = uVar52;
                                      uVar52 = uVar61;
                                    } while (uVar61 != 0xffffffff);
                                  }
                                  uVar52 = *(int *)((long)puVar32 + (long)iVar66 * 4 + 0xc) / 2;
                                  puVar49 = (undefined8 *)(lVar54 + (long)(int)uVar52 * 0x14);
                                  *(uint *)(puVar49 + 2) = local_708[0x11];
                                  local_708[0x11] = uVar52;
                                  *puVar49 = 0xfffffff3fffffff3;
                                  *(uint *)((long)puVar32 + 0x24) = local_708[0x10];
                                  local_708[0x10] =
                                       (int)((ulong)((long)puVar32 - lVar24) >> 4) * -0x55555555;
                                  *(undefined4 *)(puVar32 + 1) = 0xfffffff3;
                                  *puVar32 = 0xfffffff3fffffff3;
                                  *(uint *)((long)local_6f0 + 0x24) = local_708[0x10];
                                  local_708[0x10] = uVar38;
                                  *(undefined4 *)(local_6f0 + 1) = 0xfffffff3;
                                  *local_6f0 = 0xfffffff3fffffff3;
                                }
                              }
                              uVar38 = local_708[0xe];
                            }
                            uVar43 = (ulong)local_708[0xc];
                            if (local_708[0xc] != 0) {
                              uVar55 = 0;
                              piVar51 = *(int **)(local_708 + 10);
                              do {
                                uVar38 = (uint)uVar55;
                                if (*piVar51 != -0xd) {
                                  uVar38 = uVar38 + 1;
                                }
                                uVar55 = (ulong)uVar38;
                                uVar43 = uVar43 - 1;
                                piVar51 = piVar51 + 0xc;
                              } while (uVar43 != 0);
                              pauVar29 = (undefined1 (*) [16])
                                         func_0x000188138470(uVar55 * 8,0x2004093837f09);
                              if (pauVar29 != (undefined1 (*) [16])0x0) {
                                uVar43 = (ulong)local_708[0xc];
                                if (local_708[0xc] != 0) {
                                  iVar21 = 0;
                                  piVar51 = *(int **)(local_708 + 10);
                                  do {
                                    if (*piVar51 != -0xd) {
                                      *(int **)(*pauVar29 + (long)iVar21 * 8) = piVar51;
                                      iVar21 = iVar21 + 1;
                                    }
                                    piVar51 = piVar51 + 0xc;
                                    uVar43 = uVar43 - 1;
                                  } while (uVar43 != 0);
                                }
                                local_2c0[0x3d] = 0.0;
                                local_2c0[0x3c] = 0.0;
                                local_2c0[0x3f] = 0.0;
                                local_2c0[0x3e] = 0.0;
                                local_2c0[0x39] = 0.0;
                                local_2c0[0x38] = 0.0;
                                local_2c0[0x3b] = 0.0;
                                local_2c0[0x3a] = 0.0;
                                local_2c0[0x35] = 0.0;
                                local_2c0[0x34] = 0.0;
                                local_2c0[0x37] = 0.0;
                                local_2c0[0x36] = 0.0;
                                local_2c0[0x31] = 0.0;
                                local_2c0[0x30] = 0.0;
                                local_2c0[0x33] = 0.0;
                                local_2c0[0x32] = 0.0;
                                local_2c0[0x2d] = 0.0;
                                local_2c0[0x2c] = 0.0;
                                local_2c0[0x2f] = 0.0;
                                local_2c0[0x2e] = 0.0;
                                local_2c0[0x29] = 0.0;
                                local_2c0[0x28] = 0.0;
                                local_2c0[0x2b] = 0.0;
                                local_2c0[0x2a] = 0.0;
                                local_2c0[0x25] = 0.0;
                                local_2c0[0x24] = 0.0;
                                local_2c0[0x27] = 0.0;
                                local_2c0[0x26] = 0.0;
                                local_2c0[0x21] = 0.0;
                                local_2c0[0x20] = 0.0;
                                local_2c0[0x23] = 0.0;
                                local_2c0[0x22] = 0.0;
                                local_2c0[0x1d] = 0.0;
                                local_2c0[0x1c] = 0.0;
                                local_2c0[0x1f] = 0.0;
                                local_2c0[0x1e] = 0.0;
                                local_2c0[0x19] = 0.0;
                                local_2c0[0x18] = 0.0;
                                local_2c0[0x1b] = 0.0;
                                local_2c0[0x1a] = 0.0;
                                local_2c0[0x15] = 0.0;
                                local_2c0[0x14] = 0.0;
                                local_2c0[0x17] = 0.0;
                                local_2c0[0x16] = 0.0;
                                local_2c0[0x11] = 0.0;
                                local_2c0[0x10] = 0.0;
                                local_2c0[0x13] = 0.0;
                                local_2c0[0x12] = 0.0;
                                local_2c0[0xd] = 0.0;
                                local_2c0[0xc] = 0.0;
                                local_2c0[0xf] = 0.0;
                                local_2c0[0xe] = 0.0;
                                local_2c0[9] = 0.0;
                                local_2c0[8] = 0.0;
                                local_2c0[0xb] = 0.0;
                                local_2c0[10] = 0.0;
                                local_2c0[5] = 0.0;
                                local_2c0[4] = 0.0;
                                local_2c0[7] = 0.0;
                                local_2c0[6] = 0.0;
                                local_2c0[1] = 0.0;
                                local_2c0[0] = 0.0;
                                local_2c0[3] = 0.0;
                                local_2c0[2] = 0.0;
                                if (10 < uVar38) {
                                  pauVar31 = (undefined1 (*) [16])(pauVar29[-1] + uVar55 * 8 + 8);
                                  uVar76 = *(undefined8 *)(local_708 + 2);
                                  local_750 = local_2c0;
                                  pauVar30 = pauVar29;
LAB_183f818a8:
                                  do {
                                    pauVar79 = pauVar30;
                                    pauVar48 = pauVar79 + 1;
                                    pauVar72 = pauVar31;
                                    do {
                                      while( true ) {
                                        pauVar31 = pauVar72;
                                        lVar24 = (((long)pauVar31 - (long)pauVar79 >> 3) -
                                                  ((long)pauVar31 - (long)pauVar79 >> 0x3f) &
                                                 0x3ffffffffffffffeU) * 4;
                                        uVar67 = *(undefined8 *)(*pauVar79 + 8);
                                        *(undefined8 *)(*pauVar79 + 8) =
                                             *(undefined8 *)(*pauVar79 + lVar24);
                                        *(undefined8 *)(*pauVar79 + lVar24) = uVar67;
                                        uVar67 = *(undefined8 *)*pauVar79;
                                        uVar74 = *(undefined8 *)(*pauVar79 + 8);
                                        iVar21 = _TriangleGreater(uVar76,uVar67,uVar74);
                                        uVar77 = *(undefined8 *)*pauVar31;
                                        pauVar71 = pauVar31;
                                        pauVar80 = pauVar48;
                                        if (iVar21 == 0) {
                                          iVar21 = _TriangleGreater(uVar76,uVar74,uVar77);
                                          if (iVar21 != 0) {
                                            uVar43 = _TriangleGreater(uVar76,uVar67,uVar77);
                                            if ((uVar43 & 1) == 0) {
                                              *(undefined8 *)(*pauVar79 + 8) = uVar77;
                                              *(undefined8 *)*pauVar31 = uVar74;
                                            }
                                            else {
                                              *(undefined8 *)*pauVar79 = uVar77;
                                              *(undefined8 *)*pauVar31 = uVar67;
                                              *(undefined8 *)*pauVar31 =
                                                   *(undefined8 *)(*pauVar79 + 8);
                                              *(undefined8 *)(*pauVar79 + 8) = uVar67;
                                            }
                                          }
                                        }
                                        else {
                                          uVar43 = _TriangleGreater(uVar76,uVar77,uVar74);
                                          if ((uVar43 & 1) == 0) {
                                            *(undefined8 *)*pauVar31 = uVar67;
                                            *(undefined8 *)*pauVar79 = uVar77;
                                          }
                                          else {
                                            uVar43 = _TriangleGreater(uVar76,uVar67,uVar77);
                                            if ((uVar43 & 1) == 0) {
                                              auVar84 = NEON_ext(*pauVar79,*pauVar79,8,1);
                                              *(long *)(*pauVar79 + 8) = auVar84._8_8_;
                                              *(long *)*pauVar79 = auVar84._0_8_;
                                            }
                                            else {
                                              *(undefined8 *)*pauVar31 = uVar67;
                                              *(undefined8 *)*pauVar79 =
                                                   *(undefined8 *)(*pauVar79 + 8);
                                              *(undefined8 *)(*pauVar79 + 8) = uVar77;
                                            }
                                          }
                                        }
                                        while( true ) {
                                          uVar67 = *(undefined8 *)(*pauVar79 + 8);
                                          do {
                                            pauVar30 = pauVar80;
                                            pauVar80 = (undefined1 (*) [16])(*pauVar30 + 8);
                                            uVar74 = *(undefined8 *)*pauVar30;
                                            uVar43 = _TriangleGreater(uVar76,uVar67,uVar74);
                                          } while ((uVar43 & 1) != 0);
                                          do {
                                            pauVar72 = pauVar71;
                                            pauVar71 = (undefined1 (*) [16])(pauVar72[-1] + 8);
                                            uVar77 = *(undefined8 *)*pauVar71;
                                            uVar43 = _TriangleGreater(uVar76,uVar77,uVar67);
                                          } while ((uVar43 & 1) != 0);
                                          if (pauVar71 < pauVar80) break;
                                          *(undefined8 *)*pauVar30 = uVar77;
                                          *(undefined8 *)*pauVar71 = uVar74;
                                        }
                                        *(undefined8 *)(*pauVar79 + 8) = uVar77;
                                        *(undefined8 *)(pauVar72[-1] + 8) = uVar67;
                                        pauVar72 = pauVar72 + -1;
                                        iVar21 = (int)((ulong)((long)pauVar71 - (long)pauVar79) >> 3
                                                      );
                                        iVar45 = (int)((ulong)((long)pauVar31 + (8 - (long)pauVar30)
                                                              ) >> 3);
                                        if (iVar45 < iVar21) break;
                                        if (iVar45 < 0xb) {
LAB_183f81a68:
                                          if (local_750 == local_2c0) goto LAB_183f814f4;
                                          pauVar31 = (undefined1 (*) [16])local_750[-1];
                                          pauVar30 = (undefined1 (*) [16])local_750[-2];
                                          local_750 = local_750 + -2;
                                          goto LAB_183f818a8;
                                        }
                                        if (iVar21 < 0xb) goto LAB_183f818a8;
                                        *local_750 = (double)pauVar30;
                                        local_750[1] = (double)pauVar31;
                                        local_750 = local_750 + 2;
                                      }
                                      if (iVar21 < 0xb) goto LAB_183f81a68;
                                    } while (iVar45 < 0xb);
                                    *local_750 = (double)pauVar79;
                                    local_750[1] = (double)pauVar72;
                                    local_750 = local_750 + 2;
                                  } while( true );
                                }
LAB_183f814f4:
                                if (1 < uVar38) {
                                  puVar32 = (undefined8 *)(*pauVar29 + uVar55 * 8);
                                  uVar76 = *(undefined8 *)(local_708 + 2);
                                  lVar59 = -0x10;
                                  lVar24 = -8;
                                  do {
                                    lVar54 = lVar24 + -8;
                                    puVar9 = (undefined8 *)((long)puVar32 + lVar54);
                                    puVar49 = (undefined8 *)((long)puVar32 + lVar24);
                                    uVar67 = *puVar9;
                                    puVar69 = puVar49;
                                    lVar56 = lVar59;
                                    do {
                                      uVar43 = _TriangleGreater(uVar76,uVar67,*puVar69);
                                      puVar70 = puVar69;
                                      if ((uVar43 & 1) == 0) break;
                                      lVar24 = lVar24 + 8;
                                      puVar69 = (undefined8 *)((long)puVar32 + lVar24);
                                      lVar56 = lVar56 + 8;
                                      puVar70 = puVar32;
                                    } while (lVar56 < -8);
                                    if (puVar9 != puVar70 + -1) {
                                      uVar67 = *puVar9;
                                      for (; puVar49 < puVar70; puVar49 = puVar49 + 1) {
                                        puVar49[-1] = *puVar49;
                                      }
                                      puVar70[-1] = uVar67;
                                    }
                                    lVar59 = lVar59 + -8;
                                    lVar24 = lVar54;
                                  } while ((long)(uVar55 * -8) < lVar54);
                                }
                                pauVar30 = (undefined1 (*) [16])
                                           func_0x000188138470(0x28,0x102004050851865);
                                pauVar31 = pauVar29;
                                if (pauVar30 != (undefined1 (*) [16])0x0) {
                                  *(uint *)*pauVar30 = *local_708;
                                  *(uint *)pauVar30[1] = local_708[4];
                                  *(uint *)pauVar30[2] = uVar38;
                                  pauVar31 = (undefined1 (*) [16])
                                             func_0x000188138470(uVar55 << 4,0x1000040451b5be8);
                                  if (pauVar31 != (undefined1 (*) [16])0x0) {
                                    *(undefined1 (**) [16])(pauVar30[1] + 8) = pauVar31;
                                    if (uVar38 != 0) {
                                      uVar43 = 0;
                                      pauVar48 = pauVar31;
                                      do {
                                        lVar24 = 0;
                                        lVar59 = *(long *)(*pauVar29 + uVar43 * 8);
                                        *(undefined4 *)(*pauVar48 + 0xc) = 0;
                                        do {
                                          *(undefined4 *)(*pauVar48 + lVar24 * 4) =
                                               *(undefined4 *)(lVar59 + lVar24 * 4);
                                          if (*(int *)(lVar59 + 0x18 + lVar24 * 4) == -1) {
                                            *(uint *)(*pauVar48 + 0xc) =
                                                 *(uint *)(*pauVar48 + 0xc) |
                                                 1 << (ulong)((uint)lVar24 & 0x1f);
                                          }
                                          lVar24 = lVar24 + 1;
                                        } while (lVar24 != 3);
                                        uVar43 = uVar43 + 1;
                                        pauVar48 = pauVar48 + 1;
                                      } while (uVar43 != uVar55);
                                    }
                                    puVar32 = (undefined8 *)
                                              func_0x000188138470((ulong)local_708[4] * 0x48,
                                                                  0x1000040ff89c88e);
                                    if (puVar32 == (undefined8 *)0x0) {
                                      func_0x000188138390(pauVar29);
                                      pauVar29 = pauVar30;
                                      pauVar30 = pauVar31;
                                    }
                                    else {
                                      *(undefined8 **)(*pauVar30 + 8) = puVar32;
                                      if (local_708[4] != 0) {
                                        uVar43 = 0;
                                        puVar49 = *(undefined8 **)(local_708 + 2);
                                        do {
                                          uVar76 = *puVar49;
                                          puVar32[1] = puVar49[1];
                                          *puVar32 = uVar76;
                                          auVar84 = *(undefined1 (*) [16])(puVar49 + 2);
                                          uVar67 = puVar49[5];
                                          uVar76 = puVar49[4];
                                          uVar77 = puVar49[7];
                                          uVar74 = puVar49[6];
                                          puVar32[8] = puVar49[8];
                                          puVar32[5] = uVar67;
                                          puVar32[4] = uVar76;
                                          puVar32[7] = uVar77;
                                          puVar32[6] = uVar74;
                                          puVar32[3] = auVar84._8_8_;
                                          puVar32[2] = auVar84._0_8_;
                                          uVar43 = uVar43 + 1;
                                          puVar32 = puVar32 + 9;
                                          puVar49 = puVar49 + 9;
                                        } while (uVar43 < local_708[4]);
                                      }
                                      func_0x000188138390(pauVar29);
                                      iVar21 = _RenderTriangleMesh(*(undefined8 *)(*pauVar30 + 8),
                                                                   *(undefined4 *)pauVar30[1],
                                                                   *(undefined8 *)(pauVar30[1] + 8),
                                                                   *(undefined4 *)pauVar30[2],uVar3,
                                                                   &local_410,&local_408);
                                      if (iVar21 == 0) goto LAB_183f81b78;
                                      FUN_183b30f84(param_2);
                                      FUN_183e1be58(param_2);
                                      dVar95 = local_3f0;
                                      dVar82 = local_3f8;
                                      lVar24 = local_410;
                                      if ((local_3f8 < 0.0) ||
                                         (dVar99 = local_3f8, dVar102 = local_3f0, local_3f0 < 0.0))
                                      {
                                        dVar102 = -local_3f8;
                                        if (0.0 <= local_3f8) {
                                          dVar102 = local_3f8;
                                        }
                                        bVar19 = true;
                                        if ((local_400 != INFINITY) &&
                                           (bVar19 = false, !NAN(local_408))) {
                                          bVar19 = local_408 == INFINITY;
                                        }
                                        dVar99 = 0.0;
                                        if (!bVar19) {
                                          dVar99 = dVar102;
                                        }
                                        dVar102 = -local_3f0;
                                        if (0.0 <= local_3f0) {
                                          dVar102 = local_3f0;
                                        }
                                        dVar105 = 0.0;
                                        if (local_400 != INFINITY) {
                                          dVar105 = dVar102;
                                        }
                                        dVar102 = 0.0;
                                        if (local_408 != INFINITY) {
                                          dVar102 = dVar105;
                                        }
                                      }
                                      lVar56 = (long)dVar99;
                                      lVar54 = (long)dVar102;
                                      uVar43 = (ulong)(lVar46 * lVar56) >> 3;
                                      lVar59 = uVar43 * lVar54;
                                      _check_clients_buffer
                                                ("CGDataProviderCreateWithData",local_410,lVar59);
                                      if (lVar24 == 0) {
LAB_183f81ae8:
                                        in_stack_fffffffffffff788 =
                                             (ulong)((uint7)((ulong)in_stack_fffffffffffff788 >> 8)
                                                    & 0xffffff) << 8;
                                        lVar59 = FUN_183b1c47c(lVar56,lVar54,8,lVar46,uVar43,
                                                               *(undefined8 *)(param_1 + 0x18),3,0,0
                                                               ,in_stack_fffffffffffff788);
                                      }
                                      else {
                                        puVar32 = (undefined8 *)
                                                  func_0x000188138470(0x20,0x10c0040176be1e5);
                                        puVar32[1] = lVar59;
                                        puVar32[2] = lVar24;
                                        *puVar32 = 0;
                                        puVar32[3] = _patch_data_release_21301;
                                        if (lVar59 < 1) {
                                          FUN_183b75268("%s: Invalid size = %jd");
                                          in_stack_fffffffffffff788 = lVar59;
                                          goto LAB_183f81ae8;
                                        }
                                        lVar24 = _create_provider(puVar32,0);
                                        if (lVar24 == 0) goto LAB_183f81ae8;
                                        *(long *)(lVar24 + 0x20) = lVar59;
                                        *(undefined8 *)(lVar24 + 0x58) = 0;
                                        *(code **)(lVar24 + 0x50) = _data_get_byte_pointer;
                                        *(code **)(lVar24 + 0x60) = _data_get_bytes_at_position;
                                        *(code **)(lVar24 + 0x48) = _data_release_info;
                                        in_stack_fffffffffffff788 =
                                             (ulong)((uint7)((ulong)in_stack_fffffffffffff788 >> 8)
                                                    & 0xffffff) << 8;
                                        lVar59 = FUN_183b1c47c(lVar56,lVar54,8,lVar46,uVar43,
                                                               *(undefined8 *)(param_1 + 0x18),3,
                                                               lVar24,0,in_stack_fffffffffffff788);
                                        lVar56 = func_0x000188140d60(lVar24);
                                        if (DAT_1edf367f0 != -1) {
                                          func_0x00018813aad0(&DAT_1edf367f0,&DAT_1e223ea08);
                                        }
                                        if (lVar56 == DAT_1edf36990) {
                                          func_0x000188141240(lVar24);
                                        }
                                      }
                                      FUN_183b40648(lVar59,1);
                                      auVar93._8_8_ = 0;
                                      auVar93._0_8_ = local_408;
                                      FUN_183b40078(auVar93,local_400,dVar82,dVar95,param_2,lVar59);
                                      FUN_183b537d8(param_2);
                                      if (lVar59 != 0) {
                                        func_0x000188141240(lVar59);
                                      }
                                      if (*(long *)(*pauVar30 + 8) != 0) {
                                        func_0x000188138390();
                                      }
                                      pauVar29 = *(undefined1 (**) [16])(pauVar30[1] + 8);
                                      pauVar31 = pauVar30;
                                      if (*(undefined1 (**) [16])(pauVar30[1] + 8) ==
                                          (undefined1 (*) [16])0x0) goto LAB_183f81b6c;
                                    }
                                  }
                                  func_0x000188138390(pauVar29);
                                  pauVar31 = pauVar30;
                                }
LAB_183f81b6c:
                                func_0x000188138390(pauVar31);
                              }
                            }
LAB_183f81b78:
                            _CoonsMeshFree(local_708);
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            else {
              lVar24 = func_0x000188138470(lVar75 * 8 + 8,0x100004000313f17);
              if (lVar75 != 0) {
                lVar59 = 0;
                do {
                  lVar56 = 0;
                  *(undefined8 *)(lVar24 + lVar59 * 8) = 0;
                  dVar82 = 0.0;
                  lVar54 = 4;
                  do {
                    dVar82 = dVar82 + *(double *)(lVar22 + (lVar59 + lVar56 * lVar75) * 8);
                    *(double *)(lVar24 + lVar59 * 8) = dVar82;
                    lVar56 = lVar56 + 1;
                    lVar54 = lVar54 + -1;
                  } while (lVar54 != 0);
                  *(double *)(lVar24 + lVar59 * 8) = dVar82 * 0.25;
                  lVar59 = lVar59 + 1;
                } while (lVar59 != lVar75);
              }
              *(undefined8 *)(lVar24 + lVar75 * 8) = 0x3ff0000000000000;
              FUN_183b75480(param_2,lVar24);
              auVar84._8_8_ = 0;
              auVar84._0_8_ = local_3a8[0];
              FUN_183b7d4b4(auVar84,local_3a8[1],param_2);
              auVar111._8_8_ = 0;
              auVar111._0_8_ = local_3a8[2];
              FUN_183bd7950(auVar111,local_3a8[3],local_3a8[4],local_3a8[5],local_3a8[6],
                            local_3a8[7],param_2);
              auVar85._8_8_ = 0;
              auVar85._0_8_ = local_3a8[8];
              FUN_183bd7950(auVar85,local_3a8[9],local_3a8[10],local_3a8[0xb],local_3a8[0xc],
                            local_3a8[0xd],param_2);
              auVar86._8_8_ = 0;
              auVar86._0_8_ = local_3a8[0xe];
              FUN_183bd7950(auVar86,local_3a8[0xf],local_3a8[0x10],local_3a8[0x11],local_3a8[0x12],
                            local_3a8[0x13],param_2);
              auVar87._8_8_ = 0;
              auVar87._0_8_ = local_3a8[0x14];
              FUN_183bd7950(auVar87,local_3a8[0x15],local_3a8[0x16],local_3a8[0x17],local_3a8[0],
                            local_3a8[1],param_2);
              FUN_183b353a8(param_2,0);
              lVar59 = 0;
              do {
                if (lVar75 != 0) {
                  lVar56 = 0;
                  do {
                    lVar54 = 0;
                    *(undefined8 *)(lVar24 + lVar56 * 8) = 0;
                    dVar82 = 0.0;
                    do {
                      dVar82 = dVar82 + *(double *)
                                         (lVar22 + (lVar56 + ((ulong)(uint)((int)lVar59 +
                                                                           (int)lVar54) & 3) *
                                                             lVar75) * 8);
                      *(double *)(lVar24 + lVar56 * 8) = dVar82;
                      lVar54 = lVar54 + 1;
                    } while (lVar54 != 2);
                    *(double *)(lVar24 + lVar56 * 8) = dVar82 * 0.5;
                    lVar56 = lVar56 + 1;
                  } while (lVar56 != lVar75);
                }
                *(undefined8 *)(lVar24 + lVar75 * 8) = 0x3ff0000000000000;
                FUN_183b7554c(param_2,lVar24);
                FUN_183b30f84(param_2);
                FUN_183b8bbd0(ZEXT816(0x4000000000000000),param_2);
                dVar82 = local_3a8[lVar59 * 6];
                dVar95 = local_3a8[lVar59 * 6 + 1];
                lVar56 = lVar59 * 3 + 3;
                lVar54 = 0;
                if (lVar56 != 0xc) {
                  lVar54 = lVar56;
                }
                dVar102 = local_3a8[lVar54 * 2];
                uVar76 = 0;
                dVar99 = local_3a8[lVar54 * 2 + 1];
                FUN_183b7d4b4(param_2);
                bVar19 = false;
                if ((ABS(dVar82 - dVar102) < 1.0) && (bVar19 = false, !NAN(ABS(dVar95 - dVar99)))) {
                  bVar19 = ABS(dVar95 - dVar99) < 1.0;
                }
                if (bVar19) {
                  auVar89._8_8_ = uVar76;
                  auVar89._0_8_ = dVar102;
                  FUN_183b7d2e8(auVar89,dVar99,param_2);
                }
                else {
                  auVar88._0_8_ = local_3a8[lVar59 * 6 + 2];
                  auVar88._8_8_ = 0;
                  FUN_183bd7950(auVar88,local_3a8[lVar59 * 6 + 3],local_3a8[lVar59 * 6 + 4],
                                local_3a8[lVar59 * 6 + 5],dVar102,dVar99,param_2);
                }
                FUN_183c1e2bc(param_2,&DAT_184158800);
                FUN_183b353a8(param_2,2);
                FUN_183b537d8(param_2);
                lVar59 = lVar59 + 1;
              } while (lVar59 != 4);
              func_0x000188138390(lVar24);
            }
          } while ((uVar65 != 0) || (pbVar23 != pbVar5));
        }
        bVar17 = true;
        bVar19 = false;
      } while (bVar18);
      func_0x000188138390(lVar22);
    }
  }
  if (*_DAT_1e0186220 != local_b8) {
    func_0x000188138130();
    return;
  }
  return;
}



/* ==== _CGPDFShadingType4Init @ 183f8323c size=980 ==== */

undefined8 _CGPDFShadingType4Init(long param_1,long *param_2,undefined8 *param_3)

{
  long lVar1;
  ulong uVar2;
  long lVar3;
  undefined8 *puVar4;
  char *pcVar5;
  long lVar6;
  long lVar7;
  undefined8 uVar8;
  long lVar9;
  int local_54;
  undefined8 local_50;
  ulong local_48;
  
  if (DAT_1eb058468 != -1) {
    func_0x00018813aad0(&DAT_1eb058468,&DAT_1e22402d0);
  }
  lVar1 = _pdf_create_cftype(DAT_1eb058460,0x68);
  if (lVar1 == 0) {
    return 0;
  }
  local_50 = 0;
  local_48 = 0;
  local_54 = 0;
  *param_2 = lVar1;
  param_3[1] = 0x8010000003f83730;
  *param_3 = 0x8010000003f83610;
  if (param_1 == 0) {
    uVar8 = 0;
  }
  else {
    uVar8 = *(undefined8 *)(param_1 + 0x18);
  }
  uVar2 = FUN_183bd6c4c(uVar8,"BitsPerCoordinate",&local_48);
  if ((uVar2 & 1) == 0) {
    pcVar5 = "missing or invalid shading `BitsPerCoordinate\' value.";
    goto LAB_183f835a4;
  }
  if ((0x20 < local_48) || ((1L << (local_48 & 0x3f) & 0x101011116U) == 0)) {
    pcVar5 = "invalid shading `BitsPerCoordinate\' value.";
    goto LAB_183f835a4;
  }
  *(ulong *)(lVar1 + 0x18) = local_48;
  uVar2 = FUN_183bd6c4c(uVar8,"BitsPerComponent",&local_48);
  if ((uVar2 & 1) == 0) {
    pcVar5 = "missing or invalid shading `BitsPerComponent\' value.";
    goto LAB_183f835a4;
  }
  if ((0x10 < local_48) || ((1L << (local_48 & 0x3f) & 0x11116U) == 0)) {
    pcVar5 = "invalid shading `BitsPerComponent\' value.";
    goto LAB_183f835a4;
  }
  *(ulong *)(lVar1 + 0x20) = local_48;
  uVar2 = FUN_183bd6c4c(uVar8,"BitsPerFlag",&local_48);
  if ((uVar2 & 1) == 0) {
    pcVar5 = "missing or invalid shading `BitsPerFlag\' value.";
    goto LAB_183f835a4;
  }
  if ((8 < local_48) || ((1L << (local_48 & 0x3f) & 0x114U) == 0)) {
    pcVar5 = "invalid shading `BitsPerFlag\' value.";
    goto LAB_183f835a4;
  }
  *(ulong *)(lVar1 + 0x28) = local_48;
  *(undefined8 *)(lVar1 + 0x58) = 0;
  uVar2 = FUN_183bcf4b0(uVar8,"Function",&local_50);
  if ((uVar2 & 1) != 0) {
    lVar3 = _CGPDFShadingCreateShadingFunction(local_50,1);
    *(long *)(lVar1 + 0x58) = lVar3;
    if (lVar3 == 0) {
      return 0;
    }
  }
  if (param_1 == 0) {
    lVar3 = *(long *)(lVar1 + 0x58);
    if (lVar3 != 0) {
LAB_183f83454:
      lVar9 = 0;
      lVar7 = 0;
      lVar6 = *(long *)(lVar3 + 0x30);
      goto LAB_183f8348c;
    }
    lVar6 = 0;
    *(undefined8 *)(lVar1 + 0x10) = 0;
  }
  else {
    lVar9 = *(long *)(param_1 + 0x28);
    lVar3 = *(long *)(lVar1 + 0x58);
    if (lVar3 != 0) {
      if (lVar9 == 0) goto LAB_183f83454;
      lVar3 = func_0x000188140d60(lVar9);
      if (DAT_1edf367a0 != -1) {
        func_0x00018813aad0(&DAT_1edf367a0,&DAT_1e22309c8);
      }
      if ((lVar3 == DAT_1edf36a20) && (*(int *)(*(long *)(lVar9 + 0x18) + 0x18) == 7)) {
        pcVar5 = "invalid shading `ColorSpace\' value.";
        goto LAB_183f835a4;
      }
      lVar3 = *(long *)(lVar1 + 0x58);
      if (lVar3 == 0) {
        lVar6 = 0;
      }
      else {
        lVar6 = *(long *)(lVar3 + 0x30);
      }
      lVar7 = *(long *)(*(long *)(lVar9 + 0x18) + 0x30);
LAB_183f8348c:
      if (lVar6 != lVar7) {
        pcVar5 = "invalid function for type 4 shading";
        goto LAB_183f835a4;
      }
    }
    if (lVar9 == 0) {
      *(undefined8 *)(lVar1 + 0x10) = 0;
      lVar6 = 2;
      if (lVar3 == 0) {
        lVar6 = 0;
      }
    }
    else {
      func_0x000188141250(lVar9);
      *(long *)(lVar1 + 0x10) = lVar9;
      lVar6 = 2;
      if ((*(long *)(lVar1 + 0x58) == 0) && (lVar6 = 0, lVar9 != 0)) {
        lVar6 = *(long *)(*(long *)(lVar9 + 0x18) + 0x30) << 1;
      }
    }
  }
  puVar4 = (undefined8 *)func_0x000188138470((lVar6 + 4) * 8,0x100004000313f17);
  func_0x000188142e40(puVar4,"CGPDFNamedAlloc_Graphics");
  if (puVar4 == (undefined8 *)0x0) {
    return 0;
  }
  uVar2 = FUN_183bd5f94(uVar8,"Decode",puVar4,lVar6 + 4);
  if ((uVar2 & 1) == 0) {
    _pdf_error("missing or invalid shading `Decode\' value.");
    func_0x000188138390(puVar4);
    return 0;
  }
  *(undefined8 *)(lVar1 + 0x30) = *puVar4;
  *(undefined8 *)(lVar1 + 0x40) = puVar4[1];
  *(undefined8 *)(lVar1 + 0x38) = puVar4[2];
  *(undefined8 *)(lVar1 + 0x48) = puVar4[3];
  func_0x0001881384e0(puVar4,puVar4 + 4,lVar6 << 3);
  *(undefined8 **)(lVar1 + 0x50) = puVar4;
  if (param_1 == 0) {
    uVar8 = 0;
  }
  else {
    uVar8 = *(undefined8 *)(param_1 + 0x20);
  }
  lVar3 = FUN_183ca244c(uVar8,0,0,&local_54);
  *(long *)(lVar1 + 0x60) = lVar3;
  if (lVar3 == 0) {
    return 0;
  }
  if (local_54 == 0) {
    return 1;
  }
  pcVar5 = "invalid shading data format.";
LAB_183f835a4:
  _pdf_error(pcVar5);
  return 0;
}



/* ==== _cg_shading_type4_draw @ 183f83810 size=1760 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _cg_shading_type4_draw(long param_1,undefined8 param_2)

{
  double dVar1;
  double dVar2;
  bool bVar3;
  long lVar4;
  long lVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  ulong extraout_x8;
  long extraout_x8_00;
  long lVar8;
  long lVar9;
  undefined8 *puVar10;
  long lVar11;
  long lVar12;
  long lVar13;
  long extraout_x12;
  ulong extraout_x12_00;
  long lVar14;
  undefined8 uVar15;
  ulong uVar16;
  long lVar17;
  long lVar18;
  ulong uVar19;
  double dVar20;
  double dVar21;
  double dVar22;
  undefined8 uStack_17f;
  undefined8 uStack_177;
  undefined1 auStack_16f [15];
  undefined8 local_160;
  long local_158;
  long local_150;
  undefined1 *local_148;
  ulong local_140;
  long local_138;
  long local_130;
  ulong local_128;
  undefined1 auStack_120 [48];
  long local_f0;
  undefined8 local_e8;
  long local_e0;
  ulong local_d8;
  long local_d0;
  long local_c8;
  double local_c0;
  double dStack_b8;
  double local_b0;
  double dStack_a8;
  undefined8 local_a0;
  long local_98 [5];
  
  local_98[3] = *_DAT_1e0186220;
  if (*(long *)(param_1 + 0x10) == 0) {
    lVar18 = 0;
    uVar19 = 1;
  }
  else {
    lVar18 = *(long *)(*(long *)(*(long *)(param_1 + 0x10) + 0x18) + 0x30);
    uVar19 = lVar18 + 1;
    if (5 < uVar19) goto LAB_183f83d70;
  }
  local_a0 = 0;
  local_98[0] = 0;
  dStack_b8 = 0.0;
  local_c0 = 0.0;
  dStack_a8 = 0.0;
  local_b0 = 0.0;
  local_c8 = 0;
  local_e0 = 0;
  local_d8 = 0;
  local_e8 = 0;
  local_98[1] = 0;
  local_98[2] = 0;
  FUN_183b20e14(param_2);
  FUN_183b20f5c(param_2,*(undefined8 *)(param_1 + 0x10));
  FUN_183bdc19c(auStack_120,param_2);
  lVar4 = FUN_183f98b4c(*(undefined8 *)(param_1 + 0x10),*(undefined8 *)(param_1 + 0x58));
  if (lVar4 == 0) {
    uVar15 = 0;
  }
  else {
    uVar15 = *(undefined8 *)(lVar4 + 8);
  }
  lVar5 = func_0x000188140aa0(*(undefined8 *)(param_1 + 0x60));
  local_e0 = func_0x000188140ab0(*(undefined8 *)(param_1 + 0x60));
  local_e0 = lVar5 + local_e0;
  local_d8 = local_d8 & 0xffffffff00000000;
  local_d0 = 0;
  local_f0 = lVar5;
  while (local_f0 != local_e0) {
    do {
      _type4_read_triangle(param_1,&local_f0,auStack_120,lVar4,uVar15);
    } while (local_d0 != 0);
  }
  if ((lVar4 == 0) || (uVar16 = *(ulong *)(lVar4 + 0x48), uVar16 == 0)) goto LAB_183f83d70;
  local_140 = uVar19;
  uVar15 = (*_DAT_1e1f91910)(uVar16 * 0xd8);
  lVar17 = (long)&local_160 - extraout_x12;
  lVar5 = 0;
  if (extraout_x8 < 0x38e38e38e38e38e) {
    lVar5 = lVar17;
  }
  if (0xfc71c71c71c71cf2 < extraout_x8 + 0xfc71c71c71c71c72) {
    lVar5 = func_0x000188138470(uVar15,0x3155ea4c);
  }
  uVar19 = uVar16;
  if (uVar16 >> 0x3c != 0) {
    uVar19 = 0xffffffffffffffff;
  }
  lVar8 = 1;
  if (uVar19 < 0x81) {
    lVar8 = uVar16 * 0x10 + 1;
  }
  local_128 = uVar16;
  uVar15 = (*_DAT_1e1f91910)(lVar8);
  lVar8 = lVar17 - extraout_x8_00;
  local_158 = lVar8 + -0xf;
  local_130 = 0;
  if (extraout_x12_00 < 0xfffffffffffffff) {
    local_130 = local_158;
  }
  local_160 = param_2;
  local_150 = lVar17;
  local_148 = (undefined1 *)&local_160;
  if (0xf000000000000081 < extraout_x12_00 + 0xf000000000000001) {
    local_148 = (undefined1 *)&local_160;
    local_130 = func_0x000188138470(uVar15,0xed33e417);
  }
  lVar17 = 0;
  uVar19 = 0;
  local_138 = lVar4;
  do {
    lVar14 = local_138;
    lVar4 = local_130 + uVar19 * 0x10;
    *(undefined4 *)(lVar4 + 0xc) = 0;
    if (uVar19 < *(ulong *)(lVar14 + 0x48)) {
      lVar9 = 0;
      lVar11 = *(long *)(lVar14 + 0x50);
      lVar12 = *(long *)(lVar14 + 0x38);
      lVar13 = *(long *)(lVar14 + 0x20);
      lVar14 = 3;
      do {
        local_98[lVar9] = lVar12 + lVar13 * *(long *)(lVar11 + uVar19 * 0x18 + lVar9 * 8);
        lVar9 = lVar9 + 1;
        lVar14 = lVar14 + -1;
      } while (lVar14 != 0);
    }
    lVar14 = 0;
    do {
      *(int *)(lVar4 + lVar14 * 4) = (int)lVar17;
      puVar6 = (undefined8 *)(lVar5 + lVar17 * 0x48);
      puVar10 = (undefined8 *)local_98[lVar14];
      uVar15 = *puVar10;
      puVar6[1] = puVar10[1];
      *puVar6 = uVar15;
      puVar6[2] = 0;
      puVar6[3] = 0;
      if (*(long *)(param_1 + 0x58) == 0) {
        if (lVar18 != 0) {
          lVar9 = 0;
          lVar11 = lVar18;
          do {
            puVar6[lVar9 + 4] = puVar10[lVar9 + 2];
            lVar9 = lVar9 + 1;
            lVar11 = lVar11 + -1;
          } while (lVar11 != 0);
        }
      }
      else {
        local_a0 = puVar10[2];
        FUN_183b7ffbc(*(long *)(param_1 + 0x58),&local_a0,puVar6 + 4);
      }
      lVar17 = lVar17 + 1;
      puVar6[lVar18 + 4] = 0x3ff0000000000000;
      lVar9 = local_130;
      lVar14 = lVar14 + 1;
    } while (lVar14 != 3);
    uVar19 = uVar19 + 1;
  } while (uVar19 != local_128);
  FUN_183f98c1c(local_138);
  uVar19 = local_140;
  uVar16 = _RenderTriangleMesh(lVar5,lVar17,lVar9,local_128,local_140,&local_c8,&local_c0);
  uVar15 = local_160;
  if ((uVar16 & 1) == 0) {
    lVar18 = local_150;
    if (lVar9 != local_158) {
      func_0x000188138390(lVar9);
      lVar18 = local_150;
    }
  }
  else {
    FUN_183b30f84(local_160);
    FUN_183e1be58(uVar15);
    dVar2 = dStack_a8;
    dVar1 = local_b0;
    lVar18 = local_c8;
    if ((local_b0 < 0.0) || (dVar20 = dStack_a8, dVar22 = local_b0, dStack_a8 < 0.0)) {
      dVar20 = -local_b0;
      if (0.0 <= local_b0) {
        dVar20 = local_b0;
      }
      bVar3 = true;
      if ((dStack_b8 != INFINITY) && (bVar3 = false, !NAN(local_c0))) {
        bVar3 = local_c0 == INFINITY;
      }
      dVar22 = 0.0;
      if (!bVar3) {
        dVar22 = dVar20;
      }
      dVar20 = -dStack_a8;
      if (0.0 <= dStack_a8) {
        dVar20 = dStack_a8;
      }
      dVar21 = 0.0;
      if (dStack_b8 != INFINITY) {
        dVar21 = dVar20;
      }
      dVar20 = 0.0;
      if (local_c0 != INFINITY) {
        dVar20 = dVar21;
      }
    }
    lVar17 = (long)dVar22;
    lVar14 = (long)dVar20;
    lVar4 = uVar19 * 8;
    uVar19 = (ulong)(lVar4 * lVar17) >> 3;
    lVar9 = uVar19 * lVar14;
    _check_clients_buffer("CGDataProviderCreateWithData",local_c8,lVar9);
    if (lVar18 == 0) {
LAB_183f83dc8:
      uVar7 = *(undefined8 *)(param_1 + 0x10);
      *(undefined4 *)(lVar8 + -0x13) = 0;
      *(undefined1 *)(lVar8 + -0x17) = 0;
      *(undefined8 *)(lVar8 + -0x1f) = 0;
      lVar17 = FUN_183b1c47c(lVar17,lVar14,8,lVar4,uVar19,uVar7,3,0);
      lVar18 = local_150;
      lVar4 = local_158;
    }
    else {
      puVar6 = (undefined8 *)func_0x000188138470(0x20,0x10c0040176be1e5);
      puVar6[1] = lVar9;
      puVar6[2] = lVar18;
      *puVar6 = 0;
      puVar6[3] = _patch_data_release_21391;
      if (lVar9 < 1) {
        *(char **)(lVar8 + -0x1f) = "CGDataProviderCreateDirect";
        *(long *)(lVar8 + -0x17) = lVar9;
        FUN_183b75268("%s: Invalid size = %jd");
        goto LAB_183f83dc8;
      }
      lVar11 = _create_provider(puVar6,0);
      if (lVar11 == 0) goto LAB_183f83dc8;
      *(long *)(lVar11 + 0x20) = lVar9;
      *(undefined8 *)(lVar11 + 0x58) = 0;
      *(code **)(lVar11 + 0x50) = _data_get_byte_pointer;
      *(code **)(lVar11 + 0x60) = _data_get_bytes_at_position;
      *(code **)(lVar11 + 0x48) = _data_release_info;
      uVar7 = *(undefined8 *)(param_1 + 0x10);
      *(undefined4 *)(lVar8 + -0x13) = 0;
      *(undefined1 *)(lVar8 + -0x17) = 0;
      *(undefined8 *)(lVar8 + -0x1f) = 0;
      lVar17 = FUN_183b1c47c(lVar17,lVar14,8,lVar4,uVar19,uVar7,3,lVar11);
      lVar8 = func_0x000188140d60(lVar11);
      if (DAT_1edf367f0 != -1) {
        func_0x00018813aad0(&DAT_1edf367f0,&DAT_1e223ea08);
      }
      lVar18 = local_150;
      lVar4 = local_158;
      if (lVar8 == DAT_1edf36990) {
        func_0x000188141240(lVar11);
      }
    }
    FUN_183b40648(lVar17,1);
    FUN_183b40078(local_c0,dStack_b8,dVar1,dVar2,uVar15,lVar17);
    FUN_183b537d8(uVar15);
    if (lVar17 != 0) {
      func_0x000188141240(lVar17);
    }
    if (local_130 != lVar4) {
      func_0x000188138390();
    }
  }
  if (lVar5 != lVar18) {
    func_0x000188138390(lVar5);
  }
LAB_183f83d70:
  if (*_DAT_1e0186220 == local_98[3]) {
    return;
  }
  func_0x000188138130();
  return;
}



/* ==== _CGPDFShadingType2Init @ 183f925ec size=484 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _CGPDFShadingType2Init(long param_1,long *param_2,undefined8 *param_3)

{
  long lVar1;
  undefined8 *puVar2;
  ulong uVar3;
  char *pcVar4;
  undefined8 uVar5;
  long lVar6;
  undefined8 uVar7;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  long local_48;
  
  local_48 = *_DAT_1e0186220;
  if ((param_1 == 0) || (lVar6 = *(long *)(param_1 + 0x28), lVar6 == 0)) {
LAB_183f92678:
    puVar2 = (undefined8 *)func_0x000188138460(1,0x40,0x1020040222e9b24);
    func_0x000188142e40(puVar2,"CGPDFNamedAlloc_Graphics");
    if (puVar2 != (undefined8 *)0x0) {
      local_78 = 0;
      *param_2 = (long)puVar2;
      param_3[1] = 0x8010000003f928c8;
      *param_3 = 0x8010000003f927d0;
      uVar7 = 0;
      if (param_1 != 0) {
        uVar7 = *(undefined8 *)(param_1 + 0x18);
      }
      uVar3 = FUN_183bd5f94(uVar7,"Coords",&local_70,4);
      if ((uVar3 & 1) == 0) {
        pcVar4 = "missing or invalid shading `Coords\' value.";
      }
      else {
        puVar2[1] = uStack_68;
        *puVar2 = local_70;
        puVar2[3] = uStack_58;
        puVar2[2] = uStack_60;
        uVar3 = FUN_183bd5f94(uVar7,"Domain",puVar2 + 4,2);
        if ((uVar3 & 1) == 0) {
          puVar2[5] = 0x3ff0000000000000;
          puVar2[4] = 0;
        }
        uVar3 = FUN_183bcf4b0(uVar7,"Function",&local_78);
        if ((uVar3 & 1) != 0) {
          lVar6 = _CGPDFShadingCreateShadingFunction(local_78,1);
          puVar2[6] = lVar6;
          uVar5 = 0;
          if (lVar6 != 0) {
            uVar3 = FUN_183ee2970(uVar7,"Extend",puVar2 + 7,2);
            if ((uVar3 & 1) == 0) {
              *(undefined2 *)(puVar2 + 7) = 0;
            }
            uVar5 = 1;
          }
          goto LAB_183f92784;
        }
        pcVar4 = "missing or invalid shading `Function\' value.";
      }
      goto LAB_183f9277c;
    }
  }
  else {
    lVar1 = func_0x000188140d60(lVar6);
    if (DAT_1edf367a0 != -1) {
      func_0x00018813aad0(&DAT_1edf367a0,&DAT_1e22309c8);
    }
    if ((lVar1 != DAT_1edf36a20) || (*(int *)(*(long *)(lVar6 + 0x18) + 0x18) != 7))
    goto LAB_183f92678;
    pcVar4 = "invalid shading `ColorSpace\' value.";
LAB_183f9277c:
    _pdf_error(pcVar4);
  }
  uVar5 = 0;
LAB_183f92784:
  if (*_DAT_1e0186220 == local_48) {
    return;
  }
  func_0x000188138130(uVar5);
  return;
}



