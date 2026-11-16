/* ==== _CGShadingCreateAxialInternal @ 183b7fe60 size=228 ==== */

long _CGShadingCreateAxialInternal
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               long param_5,undefined8 param_6,undefined8 param_7,undefined8 *param_8,long param_9,
               undefined1 param_10,undefined1 param_11)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = 0;
  if ((param_5 != 0) && (param_9 != 0)) {
    lVar1 = *(long *)(*(long *)(param_5 + 0x18) + 0x30);
    if (*(long *)(param_9 + 0x30) == lVar1 || *(long *)(param_9 + 0x30) == lVar1 + 1) {
      lVar1 = _CGShadingCreateEmpty(1,param_5,param_6,param_7);
      *(undefined8 *)(lVar1 + 0x80) = param_1;
      *(undefined8 *)(lVar1 + 0x88) = param_2;
      *(undefined1 *)(lVar1 + 0x90) = param_10;
      *(undefined8 *)(lVar1 + 0x98) = param_3;
      *(undefined8 *)(lVar1 + 0xa0) = param_4;
      *(undefined1 *)(lVar1 + 0xa8) = param_11;
      func_0x000188141250(param_9);
      *(long *)(lVar1 + 0xc0) = param_9;
      if (param_8 == (undefined8 *)0x0) {
        *(undefined8 *)(lVar1 + 0xb0) = 0;
        uVar2 = 0x3ff0000000000000;
      }
      else {
        *(undefined8 *)(lVar1 + 0xb0) = *param_8;
        uVar2 = param_8[1];
      }
      *(undefined8 *)(lVar1 + 0xb8) = uVar2;
    }
    else {
      lVar1 = 0;
    }
  }
  return lVar1;
}



/* ==== _rip_auto_context_draw_shading @ 183b80b0c size=440 ==== */

undefined8 _rip_auto_context_draw_shading(long param_1,undefined8 param_2,long param_3,long param_4)

{
  byte bVar1;
  uint uVar2;
  long lVar3;
  undefined8 uVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  float fVar8;
  undefined4 uVar9;
  float fVar10;
  
  if (param_1 == 0) {
    lVar5 = 0;
  }
  else {
    lVar5 = *(long *)(param_1 + 0x128);
  }
  func_0x00018813b850(lVar5 + 0x78);
  lVar7 = *(long *)(lVar5 + 0x58);
  if (lVar7 == 0) {
    lVar7 = *(long *)(lVar5 + 0x50);
  }
  _rip_auto_context_update_content_info_from_GState(lVar5,param_3);
  fVar10 = *(float *)(*(long *)(param_3 + 0x78) + 0x30);
  fVar8 = *(float *)(lVar5 + 0x70);
  if (*(float *)(lVar5 + 0x70) <= fVar10) {
    fVar8 = fVar10;
  }
  *(float *)(lVar5 + 0x70) = fVar8;
  lVar6 = *(long *)(param_4 + 0x18);
  uVar2 = _rip_auto_context_get_content_type_from_color_space(lVar6);
  *(uint *)(lVar5 + 0x74) = *(uint *)(lVar5 + 0x74) | uVar2;
  if (uVar2 == 2) {
    if (lVar6 == 0) {
LAB_183b80bc8:
      bVar1 = 0;
    }
    else {
      lVar3 = func_0x000188140d60(lVar6);
      if (DAT_1edf367a0 != -1) {
        func_0x00018813aad0(&DAT_1edf367a0,&DAT_1e22309c8);
      }
      if (lVar3 != DAT_1edf36a20) goto LAB_183b80bc8;
      bVar1 = *(byte *)(*(long *)(lVar6 + 0x18) + 0xe);
    }
    bVar1 = *(byte *)(lVar5 + 0x68) | bVar1 & 1;
  }
  else {
    if (uVar2 == 1) goto LAB_183b80be8;
    bVar1 = 1;
  }
  *(byte *)(lVar5 + 0x68) = bVar1;
LAB_183b80be8:
  fVar10 = *(float *)(lVar5 + 0x6c);
  fVar8 = (float)FUN_183b4c138(lVar6,0);
  if (fVar10 <= fVar8) {
    uVar9 = FUN_183b4c138(lVar6,0);
  }
  else {
    uVar9 = *(undefined4 *)(lVar5 + 0x6c);
  }
  *(undefined4 *)(lVar5 + 0x6c) = uVar9;
  if (lVar7 == 0) {
    uVar4 = 0;
  }
  else {
    lVar7 = *(long *)(lVar7 + 0x28);
    if (lVar7 == 0) {
      uVar4 = 0;
    }
    else if (*(code **)(lVar7 + 0x60) == (code *)0x0) {
      uVar4 = 0x3ee;
    }
    else {
      uVar4 = (**(code **)(lVar7 + 0x60))(lVar7,param_2,param_3,param_4);
    }
    bVar1 = _rip_auto_context_contains_transparency(lVar5);
    *(byte *)(lVar5 + 0x69) = *(byte *)(lVar5 + 0x69) | bVar1;
  }
  func_0x00018813b860(lVar5 + 0x78);
  return uVar4;
}



/* ==== __Z22dlRecorder_DrawShadingP17CGContextDelegateP16CGRenderingStateP8CGGStateP9CGShading @ 183b80cc4 size=788 ==== */

undefined8
__Z22dlRecorder_DrawShadingP17CGContextDelegateP16CGRenderingStateP8CGGStateP9CGShading
          (long param_1,undefined8 param_2,long param_3,long param_4)

{
  int iVar1;
  double *pdVar2;
  double *pdVar3;
  double *pdVar4;
  bool bVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  undefined8 *puVar9;
  uint uVar10;
  undefined8 uVar11;
  uint uVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  double local_a0;
  double dStack_98;
  double local_90;
  double dStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  
  if ((param_1 == 0) || (*(long *)(param_1 + 0x128) == 0)) {
    FUN_183b75268("%s: CGContextDelegateGetInfo() returned NULL");
  }
  else {
    lVar6 = __ZN2CG19DisplayListRecorder18currentDisplayListEv();
    if (lVar6 != 0) {
      bVar5 = true;
      if ((*(double *)(lVar6 + 0x28) != INFINITY) &&
         (bVar5 = false, !NAN(*(double *)(lVar6 + 0x30)))) {
        bVar5 = *(double *)(lVar6 + 0x30) == INFINITY;
      }
      if (bVar5) {
        return 0;
      }
      if (*(double *)(lVar6 + 0x38) == 0.0) {
        return 0;
      }
      if (*(double *)(lVar6 + 0x40) == 0.0) {
        return 0;
      }
      uStack_78 = *(undefined8 *)(param_3 + 0x20);
      local_80 = *(undefined8 *)(param_3 + 0x18);
      uStack_68 = *(undefined8 *)(param_3 + 0x30);
      local_70 = *(undefined8 *)(param_3 + 0x28);
      uStack_58 = *(undefined8 *)(param_3 + 0x40);
      local_60 = *(undefined8 *)(param_3 + 0x38);
      if (*(char *)(lVar6 + 0x49) == '\x01') {
        puVar9 = &DAT_1841d7848;
        pdVar2 = (double *)&DAT_1841d7830;
        pdVar3 = (double *)&DAT_1841d7838;
        pdVar4 = (double *)&DAT_1841d7840;
        if (*(char *)(param_4 + 0x28) == '\x01') {
          puVar9 = (undefined8 *)(param_4 + 0x48);
          pdVar2 = (double *)(param_4 + 0x30);
          pdVar3 = (double *)(param_4 + 0x38);
          pdVar4 = (double *)(param_4 + 0x40);
        }
        dStack_88 = (double)*puVar9;
        dVar13 = *pdVar2;
        dVar14 = *pdVar3;
        dVar15 = *pdVar4;
        local_a0 = dVar13;
        dStack_98 = dVar14;
        local_90 = dVar15;
        local_a0 = (double)__ZN2CG19DisplayListRecorder37intersectRectWithClipConsideringStyleERK6CGRectP16CGRenderingStateP8CGGState
                                     (&local_a0,param_2,*(undefined8 *)(param_3 + 0x70),
                                      *(undefined8 *)(*(long *)(param_3 + 0x78) + 0x10));
        if (local_a0 == INFINITY) {
          return 0;
        }
        if (dVar13 == INFINITY) {
          return 0;
        }
        if (dVar14 == 0.0) {
          return 0;
        }
        dStack_98 = dVar13;
        local_90 = dVar14;
        dStack_88 = dVar15;
        if (dVar15 == 0.0) {
          return 0;
        }
      }
      lVar7 = __ZN2CG11DisplayList25shadingResourceForShadingEP9CGShading(lVar6 + 0x10,param_4);
      if (lVar7 != 0) {
        lVar8 = __ZN2CG11DisplayList20getEntryDrawingStateEP8CGGStateP16CGRenderingState
                          (lVar6 + 0x10,param_3,param_2);
        if (*(long *)(lVar8 + 8) != 0) {
          uVar10 = *(uint *)(*(long *)(lVar8 + 8) + 8);
          if (*(long *)(lVar8 + 0x10) != 0) {
            uVar10 = *(uint *)(*(long *)(lVar8 + 0x10) + 8) | uVar10;
          }
          uVar10 = uVar10 & 0x1000;
          if (*(long *)(lVar8 + 0x18) != 0) {
            uVar10 = *(uint *)(*(long *)(lVar8 + 0x18) + 8) & 0x3400 | uVar10;
          }
          if (*(double *)(*(long *)(param_3 + 0x78) + 8) < 1.0) {
            uVar10 = uVar10 | 0x1000;
          }
          else {
            uVar10 = *(uint *)(lVar7 + 8) & 0x1000 | uVar10;
          }
          uVar12 = uVar10;
          if (((uVar10 >> 0xc & 1) == 0) &&
             (uVar12 = uVar10 | 0x1000,
             0xfffffffd < ((*(int *)(*(long *)(param_3 + 0x78) + 4) << 0x10) >> 0x18) - 3U)) {
            uVar12 = uVar10;
          }
          if ((uVar12 & 0x3000) != 0) {
            *(uint *)(lVar6 + 0x50) = *(uint *)(lVar6 + 0x50) | uVar12 & 0x3000;
          }
          if (*(char *)(lVar6 + 0x4a) != '\x01') {
            return 0;
          }
          if ((uVar12 >> 10 & 1) == 0) {
            uVar11 = 0;
          }
          else {
            uVar11 = __ZN2CG11DisplayList20getEntryPatternStateEP8CGGStateP16CGRenderingState
                               (lVar6 + 0x10,param_3,param_2);
          }
          puVar9 = (undefined8 *)func_0x00018814d110(0x90,0x10e1c40c500c17b);
          pdVar2 = &local_a0;
          if (*(char *)(lVar6 + 0x49) == '\0') {
            pdVar2 = (double *)&DAT_1841d7830;
          }
          uVar10 = *(uint *)(*(long *)(param_3 + 0x78) + 4);
          *(uint *)(puVar9 + 1) = uVar12 << 8 | 5;
          dVar15 = *pdVar2;
          dVar14 = pdVar2[3];
          dVar13 = pdVar2[2];
          puVar9[3] = pdVar2[1];
          puVar9[2] = dVar15;
          puVar9[5] = dVar14;
          puVar9[4] = dVar13;
          puVar9[6] = lVar8;
          puVar9[7] = 0;
          puVar9[8] = 0;
          puVar9[9] = uVar11;
          puVar9[0x10] = uStack_58;
          puVar9[0xf] = local_60;
          puVar9[0xe] = uStack_68;
          puVar9[0xd] = local_70;
          iVar1 = uVar10 << 0xc;
          if ((uVar10 >> 0x14 & 0xf) != 0) {
            iVar1 = uVar10 << 8;
          }
          *puVar9 = &DAT_1e2232fd8;
          puVar9[10] = lVar7;
          puVar9[0xc] = uStack_78;
          puVar9[0xb] = local_80;
          *(int *)(puVar9 + 0x11) = (int)(char)uVar10;
          *(int *)((long)puVar9 + 0x8c) = iVar1 >> 0x1c;
          __ZN2CG11DisplayList11appendEntryEPKNS_16DisplayListEntryE(lVar6 + 0x10,puVar9);
          return 0;
        }
      }
    }
  }
  return 1000;
}



/* ==== __ZN2CG11DisplayList25shadingResourceForShadingEP9CGShading @ 183b80fd8 size=440 ==== */

long __ZN2CG11DisplayList25shadingResourceForShadingEP9CGShading(long *param_1,ulong param_2)

{
  long *plVar1;
  long lVar2;
  int iVar3;
  long *plVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  ulong uVar7;
  ulong *puVar8;
  long lVar9;
  
  if (param_2 == 0) {
    return 0;
  }
  param_1[0x5e] = param_1[0x5e] + 1;
  plVar4 = (long *)__ZNSt3__16__treeINS_10shared_ptrIN2CG29DisplayListResourceColorSpaceEEENS2_25CompareResourceColorSpaceENS_9allocatorIS4_EEE19__lower_bound_multiIP12CGColorSpaceEENS_15__tree_iteratorIS4_PNS_11__tree_nodeIS4_PvEElEERKT_SG_PNS_15__tree_end_nodeIPNS_16__tree_node_baseISE_EEEE
                             (param_2,param_1[0x2f],param_1 + 0x2f);
  if (param_1 + 0x2f != plVar4) {
    lVar9 = plVar4[4];
    lVar2 = plVar4[5];
    if (lVar2 == 0) {
      if (param_2 == *(ulong *)(lVar9 + 0x10)) goto LAB_183b81124;
    }
    else {
      *(long *)(lVar2 + 8) = *(long *)(lVar2 + 8) + 1;
      if (*(ulong *)(lVar9 + 0x10) < param_2) {
        __ZNSt3__119__shared_weak_count16__release_sharedB9fqe220106Ev(lVar2);
      }
      else {
        lVar9 = plVar4[4];
        if (plVar4[5] == 0) {
          uVar7 = *(ulong *)(lVar9 + 0x10);
        }
        else {
          plVar1 = (long *)(plVar4[5] + 8);
          *plVar1 = *plVar1 + 1;
          uVar7 = *(ulong *)(lVar9 + 0x10);
          __ZNSt3__119__shared_weak_count16__release_sharedB9fqe220106Ev();
        }
        __ZNSt3__119__shared_weak_count16__release_sharedB9fqe220106Ev(lVar2);
        if (uVar7 <= param_2) goto LAB_183b81124;
      }
    }
  }
  puVar5 = (undefined8 *)func_0x00018814d110(0x28,0x10e1c40974e4e7a);
  lVar9 = *(long *)(*param_1 + -0x88);
  *(undefined4 *)(puVar5 + 1) = 0x6000000;
  *puVar5 = &DAT_1e2232dd0;
  puVar8 = puVar5 + 2;
  *puVar8 = 0;
  puVar5[3] = 0;
  puVar5[4] = 0;
  func_0x000188141250(param_2);
  *puVar8 = param_2;
  if (*(long *)(param_2 + 0x18) != 0) {
    uVar6 = (**(code **)(*(long *)((long)param_1 + lVar9) + 0x10))();
    puVar5[4] = uVar6;
  }
  if (((*(byte *)((long)param_1 + 0x3e) & 1) != 0) ||
     (iVar3 = __ZN2CG26DisplayListResourceShading22shouldEvaluateOnRecordEv(*puVar8), iVar3 != 0)) {
    __ZN2CG26DisplayListResourceShading22createEvaluatedShadingEv(puVar5);
  }
  plVar4 = (long *)__ZZNSt3__16__treeINS_10shared_ptrIN2CG26DisplayListResourceShadingEEENS2_22CompareResourceShadingENS_9allocatorIS4_EEE21__emplace_hint_uniqueB9fqe220106IJRPS3_EEENS_4pairINS_15__tree_iteratorIS4_PNS_11__tree_nodeIS4_PvEElEEbEENS_21__tree_const_iteratorIS4_SH_lEEDpOT_ENKUlSB_E_clESB_
                             (param_1 + 0x2e,plVar4,puVar5);
LAB_183b81124:
  return plVar4[4];
}



/* ==== ___CGShadingGetTypeID_block_invoke_2 @ 183b811f8 size=124 ==== */

void ___CGShadingGetTypeID_block_invoke_2(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)func_0x000188138470(0x60,0x10d00408820d60f);
  puVar1[2] = 0;
  puVar1[1] = 0x3000000428e69e;
  *puVar1 = 0;
  puVar1[4] = 0x8010000003b84540;
  puVar1[3] = 0;
  puVar1[6] = 0x8070000003e18ed0;
  puVar1[5] = 0x8010000003e18ebc;
  puVar1[7] = _copy_description;
  puVar1[8] = _copy_debug_description_24219;
  puVar1[9] = 0;
  puVar1[10] = 0;
  puVar1[0xb] = 0;
  DAT_1edf35c98 = func_0x000188142740();
  return;
}



/* ==== _CGShadingCreateAxialWithGradient @ 183b81404 size=248 ==== */

long _CGShadingCreateAxialWithGradient
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               long param_5,undefined8 param_6,undefined8 param_7)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  
  lVar1 = func_0x000188140d60();
  if (DAT_1edf35940 != -1) {
    func_0x00018813aad0(&DAT_1edf35940,&DAT_1e223f348);
  }
  if (lVar1 == DAT_1edf35d20) {
    uVar3 = *(undefined8 *)(param_5 + 0x18);
    lVar1 = FUN_183b83418(param_5);
    if (lVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined8 *)(lVar1 + 0x28);
    }
    lVar1 = _CGShadingCreateAxialInternal
                      (param_1,param_2,param_3,param_4,uVar3,0,0,uVar2,lVar1,param_6,param_7);
    if (lVar1 != 0) {
      uVar4 = FUN_183b83548(param_5);
      *(undefined4 *)(lVar1 + 0x60) = uVar4;
    }
  }
  else {
    lVar1 = 0;
  }
  return lVar1;
}



/* ==== _CGShadingCreateEmpty @ 183b814fc size=352 ==== */

long _CGShadingCreateEmpty(int param_1,long param_2,long param_3,undefined8 *param_4)

{
  int iVar1;
  undefined8 *puVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  undefined8 uVar6;
  long lVar7;
  undefined4 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  
  if (param_1 - 1U < 4) {
    uVar6 = *(undefined8 *)(&DAT_184266cc0 + (ulong)(param_1 - 1U) * 8);
  }
  else {
    uVar6 = 0x70;
  }
  if (DAT_1eb05da78 != -1) {
    func_0x00018813aad0(&DAT_1eb05da78,&DAT_1e223ee48);
  }
  lVar3 = FUN_183b18540(DAT_1edf35c98,uVar6);
  if (lVar3 == 0) {
    return 0;
  }
  iVar1 = DAT_1edf35ca0 + 1;
  DAT_1edf35ca0 = DAT_1edf35ca0 + 1;
  *(int *)(lVar3 + 0x10) = iVar1;
  if (param_2 == 0) {
    lVar5 = 0;
    *(undefined8 *)(lVar3 + 0x18) = 0;
    *(int *)(lVar3 + 0x14) = param_1;
    if (param_3 == 0) goto LAB_183b815e4;
  }
  else {
    func_0x000188141250(param_2);
    *(long *)(lVar3 + 0x18) = param_2;
    *(int *)(lVar3 + 0x14) = param_1;
    if (param_3 == 0) goto LAB_183b815e4;
    lVar5 = *(long *)(*(long *)(param_2 + 0x18) + 0x30);
  }
  lVar7 = lVar5 + 1;
  lVar4 = func_0x000188138470(lVar7 * 8,0x100004000313f17);
  if (lVar5 != -1) {
    lVar5 = 0;
    do {
      *(undefined8 *)(lVar4 + lVar5 * 8) = *(undefined8 *)(param_3 + lVar5 * 8);
      lVar5 = lVar5 + 1;
      lVar7 = lVar7 + -1;
    } while (lVar7 != 0);
  }
  *(long *)(lVar3 + 0x20) = lVar4;
LAB_183b815e4:
  puVar2 = param_4;
  if (param_4 == (undefined8 *)0x0) {
    puVar2 = &DAT_1841d77d8;
  }
  *(bool *)(lVar3 + 0x28) = param_4 != (undefined8 *)0x0;
  uVar6 = *puVar2;
  uVar10 = puVar2[3];
  uVar9 = puVar2[2];
  *(undefined8 *)(lVar3 + 0x38) = puVar2[1];
  *(undefined8 *)(lVar3 + 0x30) = uVar6;
  *(undefined8 *)(lVar3 + 0x48) = uVar10;
  *(undefined8 *)(lVar3 + 0x40) = uVar9;
  *(undefined8 *)(lVar3 + 0x58) = 0;
  uVar8 = FUN_183b4c138(param_2,0);
  *(undefined4 *)(lVar3 + 0x60) = uVar8;
  return lVar3;
}



/* ==== _ripc_DrawShading @ 183b8165c size=6744 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _ripc_DrawShading(long param_1,long param_2,long param_3,long param_4)

{
  double *pdVar1;
  undefined8 *puVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  bool bVar6;
  double *pdVar7;
  double *pdVar8;
  double *pdVar9;
  bool bVar10;
  bool bVar11;
  bool bVar12;
  bool bVar13;
  int iVar14;
  undefined8 uVar15;
  long ******pppppplVar16;
  long lVar17;
  char **ppcVar18;
  long *****ppppplVar19;
  long ****pppplVar20;
  char *pcVar21;
  ushort uVar22;
  uint uVar23;
  long ***ppplVar24;
  long extraout_x8;
  long ****pppplVar25;
  long lVar26;
  long lVar27;
  int iVar28;
  long *****ppppplVar29;
  double dVar30;
  long ******pppppplVar31;
  ulong uVar32;
  long lVar33;
  int *piVar34;
  ulong uVar35;
  undefined1 (*pauVar36) [12];
  char **ppcVar37;
  ulong uVar38;
  undefined4 uVar39;
  float fVar40;
  float fVar41;
  undefined4 uVar42;
  undefined4 uVar43;
  undefined4 uVar44;
  undefined4 uVar45;
  undefined4 uVar46;
  undefined4 uVar47;
  undefined4 uVar48;
  undefined4 uVar49;
  undefined4 uVar50;
  undefined4 uVar51;
  double dVar52;
  double dVar53;
  long *****ppppplVar54;
  long *****ppppplVar55;
  undefined1 auVar56 [16];
  undefined1 auVar57 [16];
  undefined1 auVar58 [16];
  undefined1 auVar59 [16];
  undefined1 auVar60 [16];
  undefined1 auVar61 [16];
  undefined1 auVar62 [16];
  undefined1 auVar63 [16];
  undefined1 auVar64 [16];
  undefined1 auVar65 [16];
  undefined1 auVar66 [16];
  undefined1 auVar67 [16];
  undefined1 auVar68 [16];
  undefined1 auVar69 [16];
  undefined1 auVar70 [16];
  undefined1 auVar71 [16];
  undefined1 auVar72 [16];
  undefined1 auVar73 [16];
  undefined1 auVar74 [16];
  undefined1 auVar75 [16];
  undefined1 auVar76 [16];
  undefined1 auVar77 [16];
  undefined1 auVar78 [16];
  double dVar79;
  float fVar80;
  float fVar81;
  double dVar82;
  undefined8 uVar83;
  undefined8 uVar84;
  undefined8 uVar85;
  undefined8 uVar86;
  double dVar87;
  double dVar88;
  undefined8 uVar89;
  double dVar90;
  undefined8 uVar91;
  undefined8 uVar92;
  long *****ppppplVar93;
  undefined8 uVar94;
  double dVar95;
  undefined1 auVar96 [16];
  undefined1 auVar97 [16];
  undefined1 auVar98 [16];
  long *****ppppplVar99;
  long *****ppppplVar100;
  long *****ppppplVar101;
  double dVar102;
  char *local_400;
  int local_3f8;
  long ****local_3f0 [2];
  double dStack_3e0;
  undefined8 uStack_3d8;
  double local_3d0;
  undefined8 uStack_3c8;
  double local_3c0;
  undefined8 uStack_3b8;
  long ****local_3b0;
  undefined8 uStack_3a8;
  long local_3a0;
  long local_398;
  long *****local_390;
  long ****pppplStack_388;
  long ****local_380;
  long ****pppplStack_378;
  double local_370;
  double dStack_368;
  double local_358;
  long ****local_350;
  long ****pppplStack_348;
  double local_340;
  double dStack_338;
  long ****local_330;
  long ****pppplStack_328;
  long ****local_320;
  long ****pppplStack_318;
  double local_310;
  double dStack_308;
  long ****local_300;
  long ****pppplStack_2f8;
  double local_2f0;
  long *****local_2e8;
  long *****local_2e0;
  long ****pppplStack_2d8;
  undefined8 local_2d0;
  undefined8 local_2c8;
  long ****local_2c0;
  undefined8 uStack_2b8;
  double dStack_2b0;
  double local_2a8;
  long ****local_2a0;
  long ****pppplStack_298;
  double local_290;
  double dStack_288;
  double dStack_280;
  double dStack_278;
  double local_270;
  double dStack_268;
  undefined8 local_258;
  undefined8 local_250;
  undefined8 uStack_248;
  undefined8 *local_240;
  float *local_238;
  float *local_230;
  ulong uStack_228;
  long ****local_220;
  long *****local_218;
  double *local_210;
  undefined8 local_200;
  undefined8 uStack_1f8;
  undefined8 local_1f0;
  undefined8 uStack_1e8;
  undefined8 local_1e0;
  long *local_1d8;
  long *****local_1d0;
  long ****pppplStack_1c8;
  long ****local_1c0;
  long ****pppplStack_1b8;
  long *****local_1b0;
  long ****pppplStack_1a8;
  undefined8 uStack_1a0;
  undefined8 uStack_198;
  undefined8 local_190;
  undefined8 uStack_188;
  undefined8 local_180;
  undefined8 local_178;
  long *****local_170;
  ulong uStack_168;
  undefined8 local_160;
  undefined8 local_158;
  undefined8 local_150;
  long lStack_148;
  undefined8 uStack_140;
  undefined8 uStack_138;
  undefined8 local_130;
  undefined8 local_120;
  undefined8 uStack_118;
  float local_104;
  float fStack_100;
  float local_fc;
  undefined8 local_f8;
  undefined8 local_f0;
  code *local_e8;
  undefined *puStack_e0;
  double local_d8;
  undefined8 *puStack_d0;
  ulong local_c8;
  ulong uStack_c0;
  int local_b8;
  long local_b0;
  
  local_b0 = *_DAT_1e0186220;
  if (param_1 == 0) {
    dVar30 = 0.0;
  }
  else {
    dVar30 = *(double *)(param_1 + 0x128);
  }
  uStack_1e8 = 0;
  local_1f0 = 0;
  local_1d8 = (long *)0x0;
  local_1e0 = 0;
  uStack_1f8 = 0;
  local_200 = 0;
  uStack_248 = 0;
  local_250 = 0;
  local_238 = (float *)0x0;
  local_240 = (undefined8 *)0x0;
  uStack_228 = 0;
  local_230 = (float *)0x0;
  local_218 = (long *****)0x0;
  local_220 = (long ****)0x0;
  local_210 = (double *)0x0;
  local_258 = 0;
  dStack_288 = 0.0;
  local_290 = 0.0;
  dStack_278 = 0.0;
  dStack_280 = 0.0;
  dStack_268 = 0.0;
  local_270 = 0.0;
  uStack_2b8._0_4_ = 0;
  uStack_2b8._4_4_ = 0;
  local_2c0 = (long ****)0x0;
  local_2a8 = 0.0;
  dStack_2b0 = 0.0;
  pppplStack_298 = (long ****)0x0;
  local_2a0 = (long ****)0x0;
  local_2d0 = 0;
  local_2c8 = 0;
  uVar15 = _ripc_GetRenderingState(dVar30,param_2,param_3,&local_200);
  uStack_2b8 = (long *****)CONCAT44(uStack_2b8._4_4_,(undefined4)uStack_2b8);
  if ((int)uVar15 == 0) goto LAB_183b820e4;
  pauVar36 = (undefined1 (*) [12])(param_3 + 0x18);
  dVar52 = *(double *)((long)dVar30 + 0x28);
  lVar26 = -(ulong)(dVar52 == 1.0);
  auVar56._0_8_ = *(double *)*pauVar36 * dVar52;
  auVar56._8_8_ = *(double *)(param_3 + 0x20) * dVar52;
  auVar96._12_4_ = (int)((ulong)*(double *)(param_3 + 0x20) >> 0x20);
  auVar96._0_12_ = *pauVar36;
  auVar5._8_8_ = lVar26;
  auVar5._0_8_ = lVar26;
  auVar56 = auVar56 ^ (auVar56 ^ auVar96) & auVar5;
  local_2e0 = auVar56._0_8_;
  dVar53 = *(double *)*(undefined1 (*) [16])(param_3 + 0x28) * dVar52;
  dVar82 = *(double *)(param_3 + 0x30) * dVar52;
  uVar39 = SUB84(dVar82,0);
  uVar43 = (undefined4)((ulong)dVar82 >> 0x20);
  auVar63._8_8_ = lVar26;
  auVar63._0_8_ = lVar26;
  auVar97._8_4_ = uVar39;
  auVar97._0_8_ = dVar53;
  auVar97._12_4_ = uVar43;
  auVar64._8_4_ = uVar39;
  auVar64._0_8_ = dVar53;
  auVar64._12_4_ = uVar43;
  auVar64 = auVar64 ^ (auVar97 ^ *(undefined1 (*) [16])(param_3 + 0x28)) & auVar63;
  local_300 = auVar64._0_8_;
  dVar53 = *(double *)*(undefined1 (*) [16])(param_3 + 0x38) * dVar52;
  dVar52 = *(double *)(param_3 + 0x40) * dVar52;
  uVar39 = SUB84(dVar52,0);
  uVar43 = (undefined4)((ulong)dVar52 >> 0x20);
  auVar71._8_8_ = lVar26;
  auVar71._0_8_ = lVar26;
  auVar98._8_4_ = uVar39;
  auVar98._0_8_ = dVar53;
  auVar98._12_4_ = uVar43;
  auVar72._8_4_ = uVar39;
  auVar72._0_8_ = dVar53;
  auVar72._12_4_ = uVar43;
  auVar72 = auVar72 ^ (auVar98 ^ *(undefined1 (*) [16])(param_3 + 0x38)) & auVar71;
  local_310 = auVar72._0_8_;
  auVar98 = NEON_ext(auVar72,auVar72,8,1);
  local_340 = auVar98._0_8_;
  auVar96 = NEON_ext(auVar64,auVar64,8,1);
  local_320 = auVar96._0_8_;
  auVar97 = NEON_ext(auVar56,auVar56,8,1);
  local_330 = auVar97._0_8_;
  local_2e8 = (long *****)(double)(int)uStack_1e8;
  ppppplVar93 = (long *****)(double)uStack_1e8._4_4_;
  uVar94 = 0;
  dVar53 = (double)(int)local_1e0;
  dVar82 = (double)local_1e0._4_4_;
  uVar83 = 0;
  pdVar1 = (double *)&DAT_1841d7848;
  pdVar7 = (double *)&DAT_1841d7830;
  pdVar8 = (double *)&DAT_1841d7838;
  pdVar9 = (double *)&DAT_1841d7840;
  if (*(char *)(param_4 + 0x28) == '\x01') {
    pdVar1 = (double *)(param_4 + 0x48);
    pdVar7 = (double *)(param_4 + 0x30);
    pdVar8 = (double *)(param_4 + 0x38);
    pdVar9 = (double *)(param_4 + 0x40);
  }
  dVar52 = *pdVar1;
  uVar85 = 0;
  dVar87 = *pdVar7;
  dVar88 = *pdVar8;
  uVar89 = 0;
  dVar90 = *pdVar9;
  uVar92 = 0;
  pppplStack_2d8 = auVar56._8_8_;
  dStack_308 = auVar72._8_8_;
  pppplStack_2f8 = auVar64._8_8_;
  pppplStack_328 = auVar97._8_8_;
  pppplStack_318 = auVar96._8_8_;
  dStack_338 = auVar98._8_8_;
  local_2f0 = dVar53;
  if ((((dVar87 == -8.988465674311579e+307) && (dVar88 == -8.988465674311579e+307)) &&
      (dVar90 == 1.79769313486232e+308)) && (dVar52 == 1.79769313486232e+308)) {
    local_210 = (double *)0x0;
    bVar6 = true;
    uVar84 = 0xffdfffffffffffff;
    uVar86 = 0;
    dVar52 = 1.79769313486232e+308;
    uVar85 = 0;
    uVar91 = 0x7fefffffffffffff;
    dVar87 = -8.988465674311579e+307;
    uVar92 = uVar85;
  }
  else {
    local_390 = local_2e0;
    pppplStack_388 = local_330;
    local_380 = local_300;
    pppplStack_378 = local_320;
    local_370 = local_310;
    dStack_368 = local_340;
    local_358 = dVar82;
    local_350 = (long ****)ppppplVar93;
    local_1d0 = local_2e0;
    pppplStack_1c8 = local_330;
    local_1c0 = local_300;
    pppplStack_1b8 = local_320;
    local_1b0 = (long *****)local_310;
    pppplStack_1a8 = (long ****)local_340;
    uVar39 = FUN_183b23598((int)local_2e8,(int)ppppplVar93,SUB84(dVar53,0),dVar82,&local_1d0);
    uVar44 = SUB84(dVar88,0);
    uVar47 = (undefined4)((ulong)dVar88 >> 0x20);
    uVar42 = SUB84(dVar90,0);
    uVar50 = (undefined4)((ulong)dVar90 >> 0x20);
    dVar87 = (double)FUN_183b1f8b4(SUB84(dVar87,0));
    uVar43 = SUB84(dVar87,0);
    uVar15 = 0;
    uStack_2b8 = (long *****)CONCAT44(uStack_2b8._4_4_,(undefined4)uStack_2b8);
    if ((dVar87 == INFINITY) ||
       (uVar84 = CONCAT44(uVar47,uVar44),
       uStack_2b8 = (long *****)CONCAT44(uStack_2b8._4_4_,(undefined4)uStack_2b8),
       (double)CONCAT44(uVar47,uVar44) == INFINITY)) goto LAB_183b820e4;
    uVar91 = CONCAT44(uVar50,uVar42);
    uVar15 = 0;
    uStack_2b8 = (long *****)CONCAT44(uStack_2b8._4_4_,(undefined4)uStack_2b8);
    if (((double)CONCAT44(uVar50,uVar42) == 0.0) ||
       (uStack_2b8 = (long *****)CONCAT44(uStack_2b8._4_4_,(undefined4)uStack_2b8), dVar52 == 0.0))
    goto LAB_183b820e4;
    auVar57._8_8_ = uVar89;
    auVar57._0_8_ = uVar84;
    auVar65._8_8_ = uVar92;
    auVar65._0_8_ = uVar91;
    auVar73._8_8_ = uVar85;
    auVar73._0_8_ = dVar52;
    iVar14 = FUN_183b2347c(uVar39,(int)ppppplVar93,SUB84(dVar53,0),dVar82,uVar43,auVar57,auVar65,
                           auVar73,0);
    if (iVar14 == 0) {
      uVar83 = uVar85;
      FUN_183c041c4(&local_1d0,uVar43,uVar44,uVar42,dVar52);
      local_290 = (double)local_380 * (double)pppplStack_1c8 + (double)local_390 * (double)local_1d0
      ;
      dStack_288 = (double)pppplStack_378 * (double)pppplStack_1c8 +
                   (double)pppplStack_388 * (double)local_1d0;
      dStack_280 = (double)local_380 * (double)pppplStack_1b8 +
                   (double)local_390 * (double)local_1c0;
      dStack_278 = (double)pppplStack_378 * (double)pppplStack_1b8 +
                   (double)pppplStack_388 * (double)local_1c0;
      local_270 = local_370 +
                  (double)local_380 * (double)pppplStack_1a8 + (double)local_390 * (double)local_1b0
      ;
      dStack_268 = dStack_368 +
                   (double)pppplStack_378 * (double)pppplStack_1a8 +
                   (double)pppplStack_388 * (double)local_1b0;
      local_210 = &local_290;
      pppplStack_1c8 = pppplStack_388;
      local_1d0 = local_390;
      pppplStack_1b8 = pppplStack_378;
      local_1c0 = local_380;
      pppplStack_1a8 = (long ****)dStack_368;
      local_1b0 = (long *****)local_370;
      dVar82 = dVar52;
      uVar86 = uVar89;
      uVar85 = uVar83;
      local_2e8 = (long *****)FUN_183b24a3c(uVar43,&local_1d0);
      ppppplVar93 = (long *****)CONCAT44(uVar47,uVar44);
      local_2f0 = (double)CONCAT44(uVar50,uVar42);
      auVar96 = _RIPRectToExtent();
      local_2d0 = auVar96._0_8_;
      local_2c8 = CONCAT44(auVar96._12_4_ - auVar96._4_4_,auVar96._8_4_ - auVar96._0_4_);
    }
    else {
      local_210 = (double *)0x0;
      uVar83 = 0;
      dVar82 = local_358;
      uVar86 = uVar89;
      ppppplVar93 = (long *****)local_350;
      uVar89 = 0;
    }
    bVar6 = iVar14 != 0;
    uVar94 = uVar89;
  }
  iVar14 = *(int *)(param_4 + 0x14);
  local_370 = (double)CONCAT44(local_370._4_4_,*(undefined4 *)(*(long *)(param_3 + 0x78) + 4));
  uVar46 = SUB84(ppppplVar93,0);
  uVar48 = (undefined4)((ulong)ppppplVar93 >> 0x20);
  uVar50 = SUB84(dVar87,0);
  uVar39 = (undefined4)uVar84;
  uVar43 = (undefined4)((ulong)uVar84 >> 0x20);
  uVar44 = (undefined4)uVar91;
  uVar47 = (undefined4)((ulong)uVar91 >> 0x20);
  uVar42 = SUB84(local_2e8,0);
  uVar49 = SUB84(local_2f0,0);
  uVar51 = (undefined4)((ulong)local_2f0 >> 0x20);
  local_358 = dVar30;
  if (iVar14 == 1) {
    dVar30 = *(double *)(param_4 + 0x98) - *(double *)(param_4 + 0x80);
    dVar53 = *(double *)(param_4 + 0xa0) - *(double *)(param_4 + 0x88);
    ppppplVar29 = *(long ******)(param_4 + 0xb8);
    pppppplVar16 = *(long *******)(param_4 + 0xb0);
    local_120 = CONCAT44((float)(double)ppppplVar29,(float)(double)pppppplVar16);
    uStack_118 = 0x3f80000000000000;
    if ((dVar30 == 0.0) && (dVar53 == 0.0)) {
      dVar30 = 1.0;
      dVar53 = 0.0;
      dVar87 = 1.0;
    }
    else {
      dVar87 = SQRT(dVar53 * dVar53 + dVar30 * dVar30);
      dVar30 = dVar30 / dVar87;
      dVar53 = dVar53 / dVar87;
    }
    dVar87 = dVar87 / ((double)ppppplVar29 - (double)pppppplVar16);
    ppppplVar101 = (long *****)(dVar30 * dVar87);
    dVar88 = dVar53 * dVar87;
    dVar90 = -(dVar53 * dVar87);
    dVar30 = *(double *)(param_4 + 0x80) + dVar30 * -((double)pppppplVar16 * dVar87);
    ppppplVar54 = (long *****)
                  (*(double *)(param_4 + 0x88) + dVar53 * -((double)pppppplVar16 * dVar87));
    ppppplVar99 = (long *****)
                  ((double)local_300 * dVar88 + (double)local_2e0 * (double)ppppplVar101);
    ppppplVar100 = (long *****)
                   ((double)local_320 * dVar88 + (double)local_330 * (double)ppppplVar101);
    dStack_2b0 = (double)local_300 * (double)ppppplVar101 + (double)local_2e0 * dVar90;
    local_2a8 = (double)local_320 * (double)ppppplVar101 + (double)local_330 * dVar90;
    ppppplVar19 = (long *****)
                  (local_310 + (double)local_300 * (double)ppppplVar54 + (double)local_2e0 * dVar30)
    ;
    ppppplVar55 = (long *****)
                  (local_340 + (double)local_320 * (double)ppppplVar54 + (double)local_330 * dVar30)
    ;
    dVar87 = *(double *)(param_4 + 0x20);
    local_2c0 = (long ****)ppppplVar99;
    local_2a0 = (long ****)ppppplVar19;
    pppplStack_298 = (long ****)ppppplVar55;
    uStack_2b8 = ppppplVar100;
    pppppplVar31 = (long ******)local_2e8;
    if (((dVar87 == 0.0) && (uVar92 = 0, (*(byte *)(param_4 + 0x90) & 1) == 0)) &&
       ((*(byte *)(param_4 + 0xa8) & 1) == 0)) {
      local_3f0[1] = (long ****)0x0;
      uStack_3d8 = 0;
      uStack_3c8 = 0;
      uStack_3b8 = 0;
      uStack_3a8 = 0;
      uVar43 = uVar46;
      uVar47 = uVar48;
      dVar53 = dVar82;
      local_3f0[0] = (long ****)ppppplVar54;
      dStack_3e0 = dVar30;
      local_3d0 = dVar90;
      local_3c0 = dVar88;
      local_3b0 = (long ****)ppppplVar101;
      local_390 = (long *****)pppppplVar16;
      pppplStack_388 = (long ****)ppppplVar29;
      local_380 = (long ****)ppppplVar19;
      pppplStack_378 = (long ****)ppppplVar55;
      local_350 = (long ****)ppppplVar99;
      pppplStack_348 = (long ****)ppppplVar100;
      dVar30 = (double)FUN_183b23598(uVar42,uVar46,uVar49,dVar82,&local_2c0);
      uVar15 = 0;
      if (((double)ppppplVar29 < dVar30) ||
         (dVar30 + (double)CONCAT44(uVar51,uVar49) < (double)local_390)) goto LAB_183b820e4;
      FUN_183b1f8b4(0);
      if (bVar6) {
        pppppplVar31 = (long ******)&local_2c0;
      }
      else {
        local_1d0 = (long *****)local_3b0;
        pppplStack_1c8 = (long ****)local_3c0;
        local_1c0 = (long ****)local_3d0;
        pppplStack_1b8 = local_3b0;
        local_1b0 = (long *****)dStack_3e0;
        pppplStack_1a8 = local_3f0[0];
        uVar42 = FUN_183b24a3c(&local_1d0);
        auVar58._4_4_ = uVar47;
        auVar58._0_4_ = uVar43;
        auVar58._8_8_ = uVar94;
        auVar66._4_4_ = uVar51;
        auVar66._0_4_ = uVar49;
        auVar66._8_8_ = uVar92;
        auVar74._8_8_ = uVar83;
        auVar74._0_8_ = dVar53;
        FUN_183b1f8b4(uVar50,uVar39,uVar44,dVar52,uVar42,auVar58,auVar66,auVar74);
        pppplStack_1a8 = (long ****)local_340;
        local_1b0 = (long *****)local_310;
        pppplStack_1c8 = local_330;
        local_1d0 = local_2e0;
        pppplStack_1b8 = local_320;
        local_1c0 = local_300;
        pppppplVar31 = &local_1d0;
      }
      FUN_183b24a3c(pppppplVar31);
      uVar49 = SUB84(local_2f0,0);
      uVar51 = (undefined4)((ulong)local_2f0 >> 0x20);
      pppppplVar31 = (long ******)FUN_183b1f8b4((int)local_2e8);
      ppppplVar93 = (long *****)CONCAT44(uVar48,uVar46);
      ppppplVar55 = (long *****)pppplStack_378;
      ppppplVar99 = (long *****)local_350;
      ppppplVar100 = (long *****)pppplStack_348;
      ppppplVar19 = (long *****)local_380;
    }
    uVar39 = SUB84(pppppplVar31,0);
    if (((double)CONCAT44(uVar51,uVar49) < 0.0) || (dVar82 < 0.0)) {
      uVar47 = SUB84(ppppplVar93,0);
      local_380 = (long ****)ppppplVar19;
      pppplStack_378 = (long ****)ppppplVar55;
      local_350 = (long ****)ppppplVar99;
      pppplStack_348 = (long ****)ppppplVar100;
      pppppplVar31 = (long ******)FUN_183b180b4(uVar39,uVar47);
      uVar43 = uVar49;
      dVar30 = (double)FUN_183b180b4(uVar39,uVar47,uVar49,dVar82);
      dVar30 = dVar30 + (double)CONCAT44(uVar51,uVar43);
      uVar42 = (undefined4)((ulong)ppppplVar93 >> 0x20);
      uVar43 = uVar47;
      uVar44 = uVar42;
      FUN_183b180b4(uVar39,uVar47,uVar49,dVar82);
      ppppplVar100 = (long *****)CONCAT44(uVar44,uVar43);
      FUN_183b180b4(uVar39,uVar47,uVar49);
      ppppplVar93 = (long *****)CONCAT44(uVar42,uVar47);
      ppppplVar55 = (long *****)pppplStack_378;
      ppppplVar99 = (long *****)local_350;
      ppppplVar19 = (long *****)local_380;
    }
    else {
      dVar30 = (double)pppppplVar31 + (double)CONCAT44(uVar51,uVar49);
      ppppplVar100 = ppppplVar93;
    }
    iVar28 = (int)((double)pppppplVar31 + 0.00390625);
    iVar14 = (int)((double)ppppplVar93 + dVar82 + -0.00390625);
    local_250 = CONCAT44((int)((double)ppppplVar100 + 0.00390625),iVar28);
    uStack_248 = CONCAT44(iVar14 - (int)((double)ppppplVar100 + 0.00390625),
                          (int)(dVar30 + -0.00390625) - iVar28);
    local_2a0 = (long ****)((double)ppppplVar19 - (double)iVar28);
    pppplStack_298 = (long ****)((double)iVar14 - (double)ppppplVar55);
    dStack_2b0 = -dStack_2b0;
    local_238 = (float *)0x0;
    local_230 = (float *)0x0;
    uVar23 = (uint)*(byte *)(param_4 + 0x90);
    if (*(char *)(param_4 + 0xa8) == '\x01') {
      uVar23 = uVar23 | 2;
    }
    uStack_228 = CONCAT44(uStack_228._4_4_,uVar23);
    dVar53 = *(double *)(param_4 + 0xc0);
    local_2e0 = (long *****)
                CONCAT44(1,(int)(ABS((double)ppppplVar29 - (double)pppppplVar16) *
                                SQRT((double)uStack_2b8 * (double)uStack_2b8 +
                                     (double)ppppplVar99 * (double)ppppplVar99)));
    dVar30 = local_358;
LAB_183b81c04:
    uStack_2b8 = (long *****)-(double)uStack_2b8;
    local_220 = (long ****)&local_2c0;
    local_240 = &local_120;
    pppplStack_2d8 = (long ****)0x0;
    ppppplVar93 = *(long ******)(param_4 + 0x18);
    uVar39 = FUN_183b7ff44(param_4);
    local_130 = 0;
    lStack_148 = 0;
    local_150 = 0;
    uStack_138 = 0;
    uStack_140 = 0;
    uStack_168 = 0;
    local_170 = (long *****)0x0;
    local_158 = 0;
    local_160 = 0;
    uStack_188 = 0;
    local_190 = 0;
    local_178 = 0;
    local_180 = 0;
    pppplStack_1a8 = (long ****)0x0;
    local_1b0 = (long *****)0x0;
    uStack_198 = 0;
    uStack_1a0 = 0;
    pppplStack_1c8 = (long ****)0x0;
    local_1d0 = (long *****)0x0;
    pppplStack_1b8 = (long ****)0x0;
    local_1c0 = (long ****)0x0;
    iVar14 = *(int *)(*(long *)(param_3 + 0x78) + 4);
    if (DAT_1edf36458 != -1) {
      func_0x00018813aad0(&DAT_1edf36458,&DAT_1e223f208);
    }
    if ((*(byte *)(DAT_1edf36460 + 0x20) & 1) == 0) {
LAB_183b81e90:
      if (*(char *)(DAT_1edf36460 + 0x20) == '\x01') {
        if (dVar53 == 0.0) {
          local_1b0 = (long *****)0x0;
        }
        else {
          local_1b0 = *(long ******)((long)dVar53 + 0x60);
        }
      }
      uVar15 = 1000;
      if ((2 < *(uint *)((long)dVar30 + 0x80)) || (dVar53 == 0.0)) goto LAB_183b820e4;
      fVar41 = (float)local_120;
      if (*(long *)((long)dVar53 + 0x20) == 2) {
        uVar35 = (ulong)local_2e0 >> 0x20;
        uVar32 = (ulong)((int)local_2e0 + 2) + 3;
        local_2e0 = (long *****)(uVar32 & 0x1fffffffc);
        pppppplVar16 = (long ******)local_2e0;
        if ((uVar32 & 0x1fffff000) != 0) {
          pppppplVar16 = (long ******)0x1000;
        }
        uVar32 = (ulong)((int)uVar35 + 2) + 3;
        uVar38 = uVar32 & 0x1fffffffc;
        uVar35 = uVar38;
        if ((uVar32 & 0x1fffff000) != 0) {
          uVar35 = 0x1000;
        }
        if (ppppplVar93 == (long *****)0x0) {
          ppplVar24 = (long ***)0x0;
        }
        else {
          ppplVar24 = ppppplVar93[3][6];
        }
        fVar80 = (float)uStack_118;
        if ((ppplVar24 != *(long ****)((long)dVar53 + 0x30)) &&
           ((long ***)((long)ppplVar24 + 1U) != *(long ****)((long)dVar53 + 0x30))) {
          pcVar21 = "acquire_function_2d";
          uVar15 = 0x158;
LAB_183b830a8:
          local_400 = (char *)0x0;
          local_3a0 = param_2;
          local_2f0 = dVar87;
                    /* WARNING: Subroutine does not return */
          FUN_183c19214(pcVar21,uVar15,
                        "/Library/Caches/com.apple.xbs/418A84E5-A935-45BB-BEF3-31726BD24C5D/TemporaryDirectory.myKecQ/Sources/CoreGraphics/CoreGraphicsRIP/RIP/RIPFunction.c"
                        ,
                        "(components == CGFunctionGetRangeDimension(function)) || (components + 1 == CGFunctionGetRangeDimension(function))"
                        ,"");
        }
        fVar81 = local_120._4_4_ - (float)local_120;
        fVar40 = uStack_118._4_4_ - (float)uStack_118;
        ppppplVar29 = (long *****)(uVar35 * (long)pppppplVar16);
        local_330 = (long ****)((long)ppplVar24 * (long)ppppplVar29 * 4);
        local_3a0 = param_2;
        local_398 = param_3;
        local_2f0 = dVar87;
        local_310 = (double)func_0x000188138470(local_330,0x100004052888210);
        local_2e8 = (long *****)pppppplVar16;
        local_320 = (long ****)ppppplVar29;
        if (ppplVar24 < *(long ****)((long)dVar53 + 0x30)) {
          local_300 = (long ****)ppppplVar93;
          lVar26 = func_0x000188138460(ppppplVar29,4,0x100004052888210);
        }
        else {
          lVar26 = 0;
          local_300 = (long ****)ppppplVar93;
        }
        fVar81 = fVar81 / (float)((long)pppppplVar16 - 2);
        fVar40 = fVar40 / (float)(uVar35 - 2);
        if (uVar38 != 0) {
          uVar32 = 0;
          dVar30 = local_310;
          pppppplVar16 = (long ******)local_2e8;
          if (local_2e8 < (long ******)0x2) {
            pppppplVar16 = (long ******)0x1;
          }
          do {
            local_f8 = CONCAT44((fVar80 - fVar40 * 0.5) + fVar40 * (float)uVar32,
                                (undefined4)local_f8);
            if ((long ******)local_2e0 != (long ******)0x0) {
              pppppplVar31 = (long ******)0x0;
              lVar17 = uVar32 * (long)local_2e8;
              do {
                local_f8 = CONCAT44(local_f8._4_4_,
                                    (fVar41 - fVar81 * 0.5) + fVar81 * (float)pppppplVar31);
                lVar27 = 0;
                if (lVar26 != 0) {
                  lVar27 = lVar26 + (long)((long)pppppplVar31 + lVar17) * 4;
                }
                _function_evaluate(dVar53,&local_f8,dVar30,lVar27);
                dVar30 = (double)((long)dVar30 + (long)ppplVar24 * 4);
                pppppplVar31 = (long ******)((long)pppppplVar31 + 1);
              } while (pppppplVar16 != pppppplVar31);
            }
            uVar32 = uVar32 + 1;
          } while (uVar32 != uVar35);
        }
        pppplVar20 = local_320;
        dVar30 = local_358;
        if (2 < *(uint *)((long)local_358 + 0x80)) {
LAB_183b830b4:
          func_0x000188138260();
          return;
        }
        lVar17 = *(long *)(&DAT_1842669d8 + (ulong)*(uint *)((long)local_358 + 0x80) * 8);
        lVar27 = lVar17 * (long)local_320;
        uVar15 = func_0x000188138460(lVar27,4,0x100004052888210);
        ppppplVar93 = (long *****)local_300;
        dVar82 = local_310;
        local_400 = (char *)(lVar17 << 5);
        local_3f8 = (int)lVar27 << 2;
        uVar32 = _rip_function_convert_color_components
                           (uVar39,*(undefined8 *)((long)dVar30 + 0x78),local_300,local_398,
                            pppplVar20,local_310,(long)ppplVar24 << 5,local_330,uVar15);
        if ((uVar32 & 1) == 0) {
          local_400 = "acquire_function_2d";
          FUN_183b75268("%s - rip_function_convert_color_components failed");
        }
        func_0x000188138390(dVar82);
        uStack_188 = *(undefined8 *)((long)dVar30 + 0x8c);
        local_190 = *(undefined8 *)((long)dVar30 + 0x84);
        local_178 = CONCAT44(local_178._4_4_,
                             (*(int *)(*(long *)(local_398 + 0x78) + 4) << 0xc) >> 0x1c);
        local_180 = CONCAT44(*(undefined4 *)((long)dVar30 + 0x80),
                             *(undefined4 *)((long)dVar30 + 0x94));
        local_160 = CONCAT44(fVar81 + local_120._4_4_,(float)local_120 - fVar81);
        fVar41 = (float)uStack_118 - fVar40;
        fVar40 = fVar40 + uStack_118._4_4_;
      }
      else {
        if (*(long *)((long)dVar53 + 0x20) != 1) goto LAB_183b820e4;
        uVar32 = (ulong)((int)local_2e0 + 2) + 0xf;
        pppppplVar31 = (long ******)(uVar32 & 0x1fffffff0);
        pppppplVar16 = pppppplVar31;
        if ((uVar32 & 0x1fffff000) != 0) {
          pppppplVar16 = (long ******)0x1000;
        }
        if (ppppplVar93 == (long *****)0x0) {
          ppplVar24 = (long ***)0x0;
        }
        else {
          ppplVar24 = ppppplVar93[3][6];
        }
        if ((ppplVar24 != *(long ****)((long)dVar53 + 0x30)) &&
           ((long ***)((long)ppplVar24 + 1U) != *(long ****)((long)dVar53 + 0x30))) {
          pcVar21 = "acquire_function_1d";
          uVar15 = 0xf5;
          goto LAB_183b830a8;
        }
        fVar80 = local_120._4_4_ - (float)local_120;
        local_2e0 = (long *****)((long)ppplVar24 * (long)pppppplVar16 * 4);
        local_3a0 = param_2;
        local_398 = param_3;
        local_2f0 = dVar87;
        lVar17 = func_0x000188138470(local_2e0,0x100004052888210);
        if (ppplVar24 < *(long ****)((long)dVar53 + 0x30)) {
          local_300 = (long ****)ppppplVar93;
          lVar26 = func_0x000188138460(pppppplVar16,4,0x100004052888210);
        }
        else {
          lVar26 = 0;
          local_300 = (long ****)ppppplVar93;
        }
        fVar80 = fVar80 / (float)((long)pppppplVar16 - 2);
        if (pppppplVar31 != (long ******)0x0) {
          pppppplVar31 = (long ******)0x0;
          lVar27 = lVar17;
          do {
            local_f8 = CONCAT44(local_f8._4_4_,fVar41 + fVar80 * -0.5 + fVar80 * (float)pppppplVar31
                               );
            lVar33 = 0;
            if (lVar26 != 0) {
              lVar33 = lVar26 + (long)pppppplVar31 * 4;
            }
            _function_evaluate(dVar53,&local_f8,lVar27,lVar33);
            lVar27 = lVar27 + (long)ppplVar24 * 4;
            pppppplVar31 = (long ******)((long)pppppplVar31 + 1);
          } while (pppppplVar16 != pppppplVar31);
        }
        dVar30 = local_358;
        if (2 < *(uint *)((long)local_358 + 0x80)) goto LAB_183b830b4;
        lVar27 = *(long *)(&DAT_1842669d8 + (ulong)*(uint *)((long)local_358 + 0x80) * 8);
        lVar33 = lVar27 * (long)pppppplVar16;
        uVar15 = func_0x000188138460(lVar33,4,0x100004052888210);
        ppppplVar93 = (long *****)local_300;
        local_400 = (char *)(lVar27 << 5);
        local_3f8 = (int)lVar33 << 2;
        uVar32 = _rip_function_convert_color_components
                           (uVar39,*(undefined8 *)((long)dVar30 + 0x78),local_300,local_398,
                            pppppplVar16,lVar17,(long)ppplVar24 << 5,local_2e0,uVar15);
        if ((uVar32 & 1) == 0) {
          local_400 = "acquire_function_1d";
          FUN_183b75268("%s - rip_function_convert_color_components failed");
        }
        func_0x000188138390(lVar17);
        uStack_188 = *(undefined8 *)((long)dVar30 + 0x8c);
        local_190 = *(undefined8 *)((long)dVar30 + 0x84);
        local_178 = CONCAT44(local_178._4_4_,
                             (*(int *)(*(long *)(local_398 + 0x78) + 4) << 0xc) >> 0x1c);
        local_180 = CONCAT44(*(undefined4 *)((long)dVar30 + 0x80),
                             *(undefined4 *)((long)dVar30 + 0x94));
        local_160 = CONCAT44(fVar80 + local_120._4_4_,(float)local_120 - fVar80);
        fVar41 = 0.0;
        fVar40 = 1.0;
        uVar35 = 1;
        local_2e8 = (long *****)pppppplVar16;
      }
      local_158 = CONCAT44(fVar40,fVar41);
      pppppplVar16 = &local_1d0;
      dVar87 = local_2f0;
      param_2 = local_3a0;
      pppplStack_1a8 = (long ****)dVar53;
      local_170 = local_2e8;
      uStack_168 = uVar35;
      local_150 = uVar15;
      lStack_148 = lVar26;
    }
    else {
      local_b8 = (iVar14 << 0xc) >> 0x1c;
      local_c8 = NEON_umin(local_2e0,0x100000001000,4);
      if (dVar53 == 0.0) {
        uVar15 = 0;
      }
      else {
        uVar15 = *(undefined8 *)((long)dVar53 + 0x60);
      }
      local_f8 = _DAT_1e0186208;
      local_f0 = 0x40000000;
      local_e8 = ___lookup_function_entry_block_invoke;
      puStack_e0 = &DAT_1e05d7fe0;
      puStack_d0 = &local_120;
      uStack_c0 = local_c8 >> 0x20;
      local_c8 = local_c8 & 0xffffffff;
      local_398 = param_3;
      local_d8 = dVar30;
      pppppplVar16 = (long ******)_RIPDataGetEntry(dVar30,uVar15,0,&local_f8);
      param_3 = local_398;
      if (pppppplVar16 == (long ******)0x0) {
        if (DAT_1edf36458 != -1) {
          func_0x00018813aad0(&DAT_1edf36458,&DAT_1e223f208);
        }
        goto LAB_183b81e90;
      }
    }
    iVar14 = (local_370._0_4_ << 0xc) >> 0x1c;
    local_2e8 = (long *****)(pppppplVar16 + 8);
    if ((*(char *)(param_2 + 0x51) == '\x01') &&
       ((*(byte *)(*(long *)(local_398 + 0x78) + 7) & 1) != 0)) {
      *(ushort *)((long)dVar30 + 0x6c) = *(ushort *)((long)dVar30 + 0x6c) | 0xff00;
      uVar22 = 0xff00;
    }
    else {
      uVar22 = 0;
      *(ushort *)((long)dVar30 + 0x6c) = (ushort)*(byte *)((long)dVar30 + 0x6c);
    }
    uVar22 = uVar22 | *(byte *)(param_2 + 0x52);
    *(ushort *)((long)dVar30 + 0x6c) = uVar22;
    *(int *)((long)dVar30 + 0x70) = iVar14;
    lVar26 = *(long *)(local_398 + 0x78);
    piVar34 = (int *)((long)dVar30 + 0x68);
    *piVar34 = (*(int *)(lVar26 + 4) << 0x10) >> 0x18;
    *(double *)((long)dVar30 + 0x98) = (double)(float)*(double *)(lVar26 + 8);
    local_218 = local_2e8;
    if (dVar87 == 0.0) {
      uVar15 = 0;
    }
    else {
      if (ppppplVar93 == (long *****)0x0) {
        ppplVar24 = (long ***)0x0;
      }
      else {
        ppplVar24 = ppppplVar93[3][6];
      }
      uVar15 = *(undefined8 *)((long)dVar87 + (long)ppplVar24 * 8);
      lVar26 = FUN_183b1eccc(*(undefined8 *)((long)dVar30 + 0x78));
      local_3a0 = param_2;
      if (lVar26 == 0) {
        local_2e0 = local_3f0;
        (*_DAT_1e1f91910)();
        ppcVar37 = &local_400;
        uVar32 = 0;
        ppcVar18 = ppcVar37;
      }
      else {
        uVar32 = *(ulong *)(*(long *)(lVar26 + 0x18) + 0x30);
        if (uVar32 >> 0x3d == 0) {
          lVar26 = 1;
          if (uVar32 < 0x21) {
            lVar26 = uVar32 * 8 + 1;
          }
          local_2e0 = local_3f0;
          uVar83 = (*_DAT_1e1f91910)(lVar26 + 0xfU & 0xfffffffffffffff0);
          ppcVar37 = (char **)((long)local_3f0 - extraout_x8);
          ppcVar18 = (char **)0x0;
          if (uVar32 != 0x1fffffffffffffff) {
            ppcVar18 = ppcVar37;
          }
          if (0xe000000000000021 < uVar32 + 0xe000000000000001) {
            ppcVar18 = (char **)func_0x000188138470(uVar83,0x1a16d886);
          }
        }
        else {
          local_2e0 = local_3f0;
          (*_DAT_1e1f91910)();
          ppcVar37 = &local_400;
          ppcVar18 = (char **)0x0;
        }
      }
      iVar14 = FUN_183b34034(*(undefined8 *)((long)dVar30 + 0x78),ppppplVar93,iVar14,dVar87,ppcVar18
                            );
      if (iVar14 == 0) {
        uVar15 = 0;
      }
      else {
        uVar15 = _RIPColorCreateWithColor
                           ((int)uVar15,*(undefined4 *)((long)dVar30 + 0x80),ppcVar18,uVar32);
      }
      if (ppcVar18 != ppcVar37) {
        func_0x000188138390(ppcVar18);
      }
      uVar22 = *(ushort *)((long)dVar30 + 0x6c);
      param_2 = local_3a0;
    }
    if (((uVar22 & 0xff) == 0) || ((*(byte *)(*(long *)((long)dVar30 + 0x30) + 0x1d) >> 1 & 1) == 0)
       ) {
      local_258 = 0;
    }
    else {
      dVar53 = *(double *)(*(long *)(local_398 + 0x78) + 0x18);
      dVar52 = *(double *)(*(long *)(local_398 + 0x78) + 0x20);
      dVar95 = *(double *)((long)dVar30 + 0x28);
      dVar82 = *(double *)(param_2 + 0x40);
      dVar87 = *(double *)(param_2 + 0x38);
      dVar88 = *(double *)(param_2 + 0x30);
      dVar90 = *(double *)(param_2 + 0x28);
      dVar102 = *(double *)(param_2 + 0x20);
      dVar79 = *(double *)(param_2 + 0x18);
      if (dVar95 != 1.0) {
        dVar82 = *(double *)(param_2 + 0x40) * dVar95;
        dVar87 = *(double *)(param_2 + 0x38) * dVar95;
        dVar88 = *(double *)(param_2 + 0x30) * dVar95;
        dVar90 = *(double *)(param_2 + 0x28) * dVar95;
        dVar102 = *(double *)(param_2 + 0x20) * dVar95;
        dVar79 = *(double *)(param_2 + 0x18) * dVar95;
      }
      dVar87 = dVar52 * dVar90 + dVar53 * dVar79 + dVar87;
      if (dVar87 <= 1073741823.0) {
        iVar14 = -0x3fffffff;
        if (-1073741823.0 <= dVar87) {
          iVar14 = (int)dVar87;
        }
      }
      else {
        iVar14 = 0x3fffffff;
      }
      dVar82 = dVar52 * dVar88 + dVar53 * dVar102 + dVar82;
      if (dVar82 <= 1073741823.0) {
        iVar28 = -0x3fffffff;
        if (-1073741823.0 <= dVar82) {
          iVar28 = (int)dVar82;
        }
      }
      else {
        iVar28 = 0x3fffffff;
      }
      local_258 = CONCAT44(iVar28,iVar14);
    }
    if ((local_1d8 == (long *)0x0) || (-1 < *(char *)((long)local_1d8 + 0xc))) {
      puVar2 = (undefined8 *)0x0;
      if (local_210 != (double *)0x0) {
        puVar2 = &local_2d0;
      }
      _RIPLayerBltShade(*(undefined8 *)((long)dVar30 + 0x30),local_200,puVar2,&local_250,uVar15,
                        piVar34);
    }
    else {
      puVar2 = (undefined8 *)0x0;
      if (local_210 != (double *)0x0) {
        puVar2 = &local_2d0;
      }
      (**(code **)(*local_1d8 + 0x50))
                (local_1d8,*(undefined8 *)((long)dVar30 + 0x30),local_200,puVar2,&local_250,uVar15,
                 &local_258,piVar34);
    }
    func_0x000188138390(uVar15);
    if (DAT_1edf36458 != -1) {
      func_0x00018813aad0(&DAT_1edf36458,&DAT_1e223f208);
    }
    if ((*(char *)(DAT_1edf36460 + 0x20) == '\x01') &&
       (ppppplVar93 = pppppplVar16[5], ppppplVar93 != (long *****)0x0)) {
      ppppplVar29 = pppppplVar16[4];
      if (ppppplVar29 == (long *****)0x0) {
        ppppplVar19 = (long *****)_RIPDataCreate(ppppplVar93);
        pppplVar20 = ppppplVar93[0xc];
        if (pppplVar20 == (long ****)0x0) {
          ppppplVar93[0xc] = (long ****)ppppplVar19;
        }
        ppppplVar29 = (long *****)ppppplVar93[0xc];
        if (ppppplVar29 != ppppplVar19) {
          func_0x000188141240(pppplVar20);
        }
      }
      if (*(int *)((long)pppppplVar16 + 0x34) == 0) {
        pppplVar20 = (long ****)_RIPCacheEntryCreate(0,ppppplVar29);
        ppppplVar93 = (long *****)*local_2e8;
        pppplVar20[9] = (long ***)local_2e8[1];
        pppplVar20[8] = (long ***)ppppplVar93;
        ppppplVar93 = (long *****)local_2e8[6];
        ppppplVar99 = (long *****)local_2e8[9];
        ppppplVar19 = (long *****)local_2e8[8];
        ppppplVar101 = (long *****)local_2e8[3];
        ppppplVar54 = (long *****)local_2e8[2];
        ppppplVar100 = (long *****)local_2e8[5];
        ppppplVar55 = (long *****)local_2e8[4];
        pppplVar20[0xf] = (long ***)local_2e8[7];
        pppplVar20[0xe] = (long ***)ppppplVar93;
        pppplVar20[0x11] = (long ***)ppppplVar99;
        pppplVar20[0x10] = (long ***)ppppplVar19;
        pppplVar20[0xb] = (long ***)ppppplVar101;
        pppplVar20[10] = (long ***)ppppplVar54;
        pppplVar20[0xd] = (long ***)ppppplVar100;
        pppplVar20[0xc] = (long ***)ppppplVar55;
        _RIPLockCacheState();
        pppplVar25 = ppppplVar29[3];
        ppplVar24 = *pppplVar20;
        ppppplVar29[3] = pppplVar20;
        *pppplVar20 = (long ***)(ppppplVar29 + 2);
        *pppplVar25 = ppplVar24;
        ppplVar24[1] = (long **)pppplVar25;
        ppppplVar29[5] = (long ****)((long)ppppplVar29[5] + 1);
        _ripc_AddEntry(*(undefined8 *)((long)local_358 + 0xd0),pppplVar20);
        if ((long ****)0x20 < ppppplVar29[5]) {
          pppplVar20 = ppppplVar29[2];
          _RIPCacheEntryRemove(pppplVar20);
          pppplVar20[1] = (long ***)0x0;
          _RIPUnlockCacheState();
          do {
            pppplVar25 = (long ****)pppplVar20[1];
            _RIPCacheEntryRelease(pppplVar20);
            pppplVar20 = pppplVar25;
          } while (pppplVar25 != (long ****)0x0);
          goto LAB_183b820e0;
        }
      }
      else {
        _RIPLockCacheState();
        *(int *)((long)pppppplVar16 + 0x34) = *(int *)((long)pppppplVar16 + 0x34) + -1;
      }
      _RIPUnlockCacheState();
    }
    else {
      func_0x000188138390(pppppplVar16[0x10]);
      func_0x000188138390(pppppplVar16[0x11]);
    }
  }
  else {
    uVar15 = 1000;
    if (2 < iVar14) {
      if (iVar14 == 3) {
        auVar4._12_4_ = (int)((ulong)*(undefined8 *)(param_4 + 0xa0) >> 0x20);
        auVar4._0_12_ = *(undefined1 (*) [12])(param_4 + 0x98);
        fVar41 = (float)SUB128(*(undefined1 (*) [12])(param_4 + 0x98),0);
        fVar80 = (float)auVar4._8_8_;
        fVar40 = 0.0;
        local_120 = CONCAT44(fVar80,fVar41);
        uStack_118 = 0x3f80000000000000;
        pppplStack_348 = (long ****)0x0;
        local_350 = (long ****)CONCAT44(fVar80 - fVar80,fVar80 - fVar41);
        local_104 = (float)*(double *)(param_4 + 0x90);
        dVar87 = *(double *)(param_4 + 0x20);
        fVar41 = (float)func_0x00018814d1c0(1000);
        dVar53 = (double)-fVar41;
        local_2c0 = (long ****)((double)local_300 * dVar53 + (double)local_2e0 * (double)-fVar40);
        uStack_2b8 = (long *****)((double)local_320 * dVar53 + (double)local_330 * (double)-fVar40);
        dStack_2b0 = (double)local_300 * (double)fVar40 + (double)local_2e0 * dVar53;
        local_2a8 = (double)local_320 * (double)fVar40 + (double)local_330 * dVar53;
        local_2e0 = (long *****)
                    (local_310 +
                    (double)local_300 * *(double *)(param_4 + 0x88) +
                    (double)local_2e0 * *(double *)(param_4 + 0x80));
        pppplStack_2d8 =
             (long ****)
             (local_340 +
             (double)local_320 * *(double *)(param_4 + 0x88) +
             (double)local_330 * *(double *)(param_4 + 0x80));
        auVar96 = _RIPRectToExtent((int)local_2e8,uVar46,SUB84(local_2f0,0),dVar82);
        local_250 = auVar96._0_8_;
        dVar53 = (double)auVar96._0_4_;
        uStack_248 = CONCAT44(auVar96._12_4_ - auVar96._4_4_,auVar96._8_4_ - auVar96._0_4_);
        local_2a0 = (long ****)((double)local_2e0 - dVar53);
        pppplStack_298 = (long ****)((double)auVar96._12_4_ - (double)pppplStack_2d8);
        dVar53 = dVar53 - (double)local_2a0;
        dVar82 = (double)auVar96._4_4_ - (double)pppplStack_298;
        dVar82 = dVar82 * dVar82;
        dVar52 = dVar82 + dVar53 * dVar53;
        dVar53 = (double)auVar96._8_4_ - (double)local_2a0;
        dVar82 = dVar82 + dVar53 * dVar53;
        if (dVar52 <= dVar82) {
          dVar52 = dVar82;
        }
        local_238 = (float *)0x0;
        local_230 = &local_104;
        uStack_228 = uStack_228 & 0xffffffff00000000;
        dVar53 = *(double *)(param_4 + 0xa8);
        iVar14 = (int)(ABS(SUB84(local_350,0)) * SQRT((float)dVar52) * 3.1415927);
        if (iVar14 < 0x81) {
          iVar14 = 0x80;
        }
        goto LAB_183b82c0c;
      }
      if (iVar14 != 4) goto LAB_183b820e4;
      dVar90 = *(double *)(param_4 + 0x88);
      dVar88 = *(double *)(param_4 + 0x80);
      ppppplVar100 = SUB168(*(undefined1 (*) [16])(param_4 + 0x90),0);
      ppppplVar54 = SUB168(*(undefined1 (*) [16])(param_4 + 0x90),8);
      uStack_118 = CONCAT44((float)(double)ppppplVar54,(float)(double)ppppplVar100);
      local_120 = CONCAT44((float)dVar90,(float)dVar88);
      local_350 = (long ****)(dVar90 - dVar88);
      pppplStack_348 = (long ****)((double)ppppplVar54 - (double)ppppplVar100);
      dVar53 = *(double *)(param_4 + 200);
      ppppplVar99 = *(long ******)(param_4 + 0xd0);
      ppppplVar55 = SUB168(*(undefined1 (*) [16])(param_4 + 0xa8),8);
      pppppplVar16 = SUB168(*(undefined1 (*) [16])(param_4 + 0xa8),0);
      local_2c0 = (long ****)
                  ((double)local_300 * (double)ppppplVar55 +
                  (double)local_2e0 * (double)pppppplVar16);
      uStack_2b8 = (long *****)
                   ((double)local_320 * (double)ppppplVar55 +
                   (double)local_330 * (double)pppppplVar16);
      ppppplVar19 = SUB168(*(undefined1 (*) [16])(param_4 + 0xb8),8);
      ppppplVar29 = SUB168(*(undefined1 (*) [16])(param_4 + 0xb8),0);
      dStack_2b0 = (double)local_300 * (double)ppppplVar19 + (double)local_2e0 * (double)ppppplVar29
      ;
      local_2a8 = (double)local_320 * (double)ppppplVar19 + (double)local_330 * (double)ppppplVar29;
      local_2a0 = (long ****)
                  (local_310 + (double)local_300 * (double)ppppplVar99 + (double)local_2e0 * dVar53)
      ;
      pppplStack_318 =
           (long ****)
           (local_340 + (double)local_320 * (double)ppppplVar99 + (double)local_330 * dVar53);
      dVar87 = *(double *)(param_4 + 0x20);
      ppppplVar93 = (long *****)local_2a0;
      pppplStack_298 = pppplStack_318;
      if (dVar87 == 0.0) {
        uStack_3b8 = 0;
        uStack_3a8 = 0;
        dStack_308 = local_340;
        pppplStack_2f8 = local_320;
        pppplStack_2d8 = local_330;
        uVar89 = 0;
        uVar45 = uVar46;
        dVar102 = dVar82;
        local_3c0 = dVar53;
        local_3b0 = (long ****)ppppplVar99;
        local_390 = (long *****)pppppplVar16;
        pppplStack_388 = (long ****)ppppplVar55;
        local_380 = (long ****)ppppplVar29;
        pppplStack_378 = (long ****)ppppplVar19;
        local_340 = dVar88;
        dStack_338 = dVar90;
        local_330 = (long ****)ppppplVar100;
        pppplStack_328 = (long ****)ppppplVar54;
        local_320 = local_2a0;
        FUN_183b23598(uVar42,&local_2c0);
        dVar53 = (double)FUN_183b1f8b4();
        uVar15 = 0;
        if (((dVar53 == INFINITY) || ((double)CONCAT44(uVar48,uVar45) == INFINITY)) ||
           ((uVar15 = 0, (double)CONCAT44(uVar51,uVar49) == 0.0 || (dVar102 == 0.0))))
        goto LAB_183b820e4;
        if (bVar6) {
          pppppplVar16 = (long ******)&local_2c0;
          uVar39 = uVar45;
          uVar43 = uVar48;
          uVar86 = uVar94;
          uVar44 = uVar49;
          uVar47 = uVar51;
          uVar92 = uVar89;
          dVar52 = dVar102;
          uVar85 = uVar83;
        }
        else {
          pppplStack_1c8 = pppplStack_388;
          local_1d0 = local_390;
          pppplStack_1b8 = pppplStack_378;
          local_1c0 = local_380;
          local_1b0 = (long *****)local_3c0;
          pppplStack_1a8 = local_3b0;
          uVar42 = FUN_183b24a3c(&local_1d0);
          auVar59._4_4_ = uVar48;
          auVar59._0_4_ = uVar45;
          auVar59._8_8_ = uVar94;
          auVar67._4_4_ = uVar51;
          auVar67._0_4_ = uVar49;
          auVar67._8_8_ = uVar89;
          auVar75._8_8_ = uVar83;
          auVar75._0_8_ = dVar102;
          FUN_183b1f8b4(uVar50,uVar39,uVar44,dVar52,uVar42,auVar59,auVar67,auVar75);
          pppplStack_1c8 = pppplStack_2d8;
          local_1d0 = local_2e0;
          pppplStack_1b8 = pppplStack_2f8;
          local_1c0 = local_300;
          pppplStack_1a8 = (long ****)dStack_308;
          local_1b0 = (long *****)local_310;
          pppppplVar16 = &local_1d0;
        }
        uVar42 = FUN_183b24a3c(pppppplVar16);
        auVar60._4_4_ = uVar43;
        auVar60._0_4_ = uVar39;
        auVar60._8_8_ = uVar86;
        auVar68._4_4_ = uVar47;
        auVar68._0_4_ = uVar44;
        auVar68._8_8_ = uVar92;
        auVar76._8_8_ = uVar85;
        auVar76._0_8_ = dVar52;
        local_2e8 = (long *****)
                    FUN_183b1f8b4((int)local_2e8,uVar46,SUB84(local_2f0,0),dVar82,uVar42,auVar60,
                                  auVar68,auVar76);
        ppppplVar93 = (long *****)local_320;
      }
      local_320 = (long ****)ppppplVar93;
      auVar96 = _RIPRectToExtent((int)local_2e8);
      local_250 = auVar96._0_8_;
      uStack_248 = CONCAT44(auVar96._12_4_ - auVar96._4_4_,auVar96._8_4_ - auVar96._0_4_);
      local_2a0 = (long ****)((double)local_320 - (double)auVar96._0_4_);
      pppplStack_298 = (long ****)((double)auVar96._12_4_ - (double)pppplStack_318);
      local_238 = (float *)0x0;
      local_230 = (float *)0x0;
      uStack_228 = uStack_228 & 0xffffffff00000000;
      dVar53 = *(double *)(param_4 + 0xa0);
      auVar3._8_4_ = (undefined4)uStack_2b8;
      auVar3._0_8_ = local_2c0;
      auVar3._12_4_ = uStack_2b8._4_4_;
      dVar82 = (double)local_350 * auVar3._8_8_;
      dVar52 = (double)pppplStack_348 * local_2a8;
      local_2a8 = -local_2a8;
      iVar14 = (int)(long)(double)(long)SQRT(dVar82 * dVar82 +
                                             (double)local_350 * (double)local_2c0 *
                                             (double)local_350 * (double)local_2c0);
      uVar39 = (undefined4)
               (long)(double)(long)SQRT(dVar52 * dVar52 +
                                        (double)pppplStack_348 * dStack_2b0 *
                                        (double)pppplStack_348 * dStack_2b0);
LAB_183b82c14:
      local_2e0 = (long *****)CONCAT44(uVar39,iVar14);
      goto LAB_183b81c04;
    }
    if (iVar14 != 0) {
      local_350 = (long ****)ppppplVar93;
      uStack_2b8 = (long *****)CONCAT44(uStack_2b8._4_4_,(undefined4)uStack_2b8);
      if (iVar14 != 2) goto LAB_183b820e4;
      pppppplVar16 = *(long *******)(param_4 + 0x80);
      dVar102 = *(double *)(param_4 + 0x88);
      dVar87 = *(double *)(param_4 + 0xa0) - (double)pppppplVar16;
      dVar88 = *(double *)(param_4 + 0xa8) - dVar102;
      dVar90 = *(double *)(param_4 + 200);
      local_120 = CONCAT44((float)dVar90,(float)*(double *)(param_4 + 0xc0));
      dVar30 = *(double *)(param_4 + 0x90);
      dVar53 = *(double *)(param_4 + 0xb0);
      local_380 = (long ****)(dVar90 - *(double *)(param_4 + 0xc0));
      pppplStack_378 = (long ****)(dVar90 - dVar90);
      uStack_118 = 0x3f80000000000000;
      if ((dVar87 == 0.0) && (dVar88 == 0.0)) {
        dVar87 = 1.0;
        dVar79 = 0.0;
        dVar88 = 0.0;
        dVar90 = ABS(dVar53 - dVar30) / (double)local_380;
      }
      else {
        dVar79 = SQRT(dVar88 * dVar88 + dVar87 * dVar87);
        dVar87 = dVar87 / dVar79;
        dVar88 = dVar88 / dVar79;
        dVar90 = (dVar79 + ABS(dVar53 - dVar30)) / (double)local_380;
        dVar79 = dVar79 / dVar90;
      }
      dVar30 = dVar30 / dVar90;
      dVar53 = dVar53 / dVar90;
      ppppplVar19 = (long *****)(dVar87 * dVar90);
      dVar95 = dVar88 * dVar90;
      dVar88 = -(dVar88 * dVar90);
      local_2c0 = (long ****)((double)local_300 * dVar95 + (double)local_2e0 * (double)ppppplVar19);
      pppplStack_318 =
           (long ****)((double)local_320 * dVar95 + (double)local_330 * (double)ppppplVar19);
      dStack_2b0 = (double)local_300 * (double)ppppplVar19 + (double)local_2e0 * dVar88;
      local_2a8 = (double)local_320 * (double)ppppplVar19 + (double)local_330 * dVar88;
      local_2a0 = (long ****)
                  (local_310 +
                  (double)local_300 * dVar102 + (double)local_2e0 * (double)pppppplVar16);
      pppplStack_328 =
           (long ****)
           (local_340 + (double)local_320 * dVar102 + (double)local_330 * (double)pppppplVar16);
      local_104 = (float)dVar30;
      fStack_100 = (float)dVar79;
      local_fc = (float)dVar53;
      dVar87 = *(double *)(param_4 + 0x20);
      uVar23 = (uint)*(byte *)(param_4 + 0x98);
      ppppplVar93 = (long *****)local_2a0;
      ppppplVar29 = (long *****)local_2c0;
      pppplStack_298 = pppplStack_328;
      uStack_2b8 = (long *****)pppplStack_318;
      if (dVar87 == 0.0) {
        uVar15 = 0;
        dStack_308 = local_340;
        pppplStack_2d8 = local_330;
        pppplStack_2f8 = local_320;
        if ((*(byte *)(param_4 + 0x98) & 1) == 0) {
          if ((*(byte *)(param_4 + 0xb8) & 1) == 0) {
            uStack_3c8 = 0;
            uStack_3b8 = 0;
            uStack_3a8 = 0;
            pppplStack_388 = (long ****)0x0;
            dStack_338 = 0.0;
            uVar94 = 0;
            dVar90 = dVar82;
            local_3d0 = dVar88;
            local_3c0 = dVar95;
            local_3b0 = (long ****)ppppplVar19;
            local_390 = (long *****)pppppplVar16;
            local_340 = dVar102;
            local_330 = local_2a0;
            local_320 = local_2c0;
            dVar102 = (double)FUN_183b23598(uVar42,&local_2c0);
            dVar88 = dVar30;
            if (dVar30 <= dVar79 + dVar53) {
              dVar88 = dVar79 + dVar53;
            }
            dVar95 = dVar79 - dVar53;
            if (-dVar30 <= dVar79 - dVar53) {
              dVar95 = -dVar30;
            }
            if (dVar53 <= dVar30) {
              dVar53 = dVar30;
            }
            dVar30 = dVar102 + (double)CONCAT44(uVar51,uVar49);
            bVar10 = true;
            if ((dVar102 <= dVar88) && (bVar10 = false, !NAN(dVar30) && !NAN(dVar95))) {
              bVar10 = dVar30 < dVar95;
            }
            bVar11 = false;
            bVar12 = false;
            bVar13 = false;
            if (!bVar10) {
              bVar11 = false;
              bVar12 = false;
              bVar13 = true;
              if (!NAN((double)CONCAT44(uVar48,uVar46)) && !NAN(dVar53)) {
                bVar11 = (double)CONCAT44(uVar48,uVar46) < dVar53;
                bVar12 = (double)CONCAT44(uVar48,uVar46) == dVar53;
                bVar13 = false;
              }
            }
            if ((!bVar12 && bVar11 == bVar13) ||
               ((double)CONCAT44(uVar48,uVar46) + dVar90 < -dVar53)) goto LAB_183b820e0;
            FUN_183b1f8b4();
            if (bVar6) {
              pppppplVar16 = (long ******)&local_2c0;
              uVar39 = uVar46;
              uVar43 = uVar48;
              uVar86 = uVar94;
              uVar44 = uVar49;
              uVar47 = uVar51;
              uVar92 = uVar15;
              dVar52 = dVar90;
              uVar85 = uVar83;
            }
            else {
              local_1d0 = (long *****)local_3b0;
              pppplStack_1c8 = (long ****)local_3c0;
              local_1c0 = (long ****)local_3d0;
              pppplStack_1b8 = local_3b0;
              local_1b0 = local_390;
              pppplStack_1a8 = (long ****)local_340;
              uVar42 = FUN_183b24a3c(&local_1d0);
              auVar61._4_4_ = uVar48;
              auVar61._0_4_ = uVar46;
              auVar61._8_8_ = uVar94;
              auVar69._4_4_ = uVar51;
              auVar69._0_4_ = uVar49;
              auVar69._8_8_ = uVar15;
              auVar77._8_8_ = uVar83;
              auVar77._0_8_ = dVar90;
              FUN_183b1f8b4(uVar50,uVar39,uVar44,dVar52,uVar42,auVar61,auVar69,auVar77);
              pppplStack_1c8 = pppplStack_2d8;
              local_1d0 = local_2e0;
              pppplStack_1b8 = pppplStack_2f8;
              local_1c0 = local_300;
              pppplStack_1a8 = (long ****)dStack_308;
              local_1b0 = (long *****)local_310;
              pppppplVar16 = &local_1d0;
            }
            uVar42 = FUN_183b24a3c(pppppplVar16);
            auVar62._4_4_ = uVar43;
            auVar62._0_4_ = uVar39;
            auVar62._8_8_ = uVar86;
            auVar70._4_4_ = uVar47;
            auVar70._0_4_ = uVar44;
            auVar70._8_8_ = uVar92;
            auVar78._8_8_ = uVar85;
            auVar78._0_8_ = dVar52;
            local_2e8 = (long *****)
                        FUN_183b1f8b4((int)local_2e8,(int)local_350,SUB84(local_2f0,0),dVar82,uVar42
                                      ,auVar62,auVar70,auVar78);
            uVar23 = 0;
            ppppplVar93 = (long *****)local_330;
            ppppplVar29 = (long *****)local_320;
          }
          else {
            uVar23 = 0;
          }
        }
        else {
          uVar23 = 1;
        }
      }
      local_320 = (long ****)ppppplVar29;
      local_330 = (long ****)ppppplVar93;
      dVar30 = local_358;
      auVar96 = _RIPRectToExtent((int)local_2e8);
      local_250 = auVar96._0_8_;
      uStack_248 = CONCAT44(auVar96._12_4_ - auVar96._4_4_,auVar96._8_4_ - auVar96._0_4_);
      local_2a0 = (long ****)((double)local_330 - (double)auVar96._0_4_);
      pppplStack_298 = (long ****)((double)auVar96._12_4_ - (double)pppplStack_328);
      local_238 = &local_104;
      local_230 = (float *)0x0;
      if (*(char *)(param_4 + 0xb8) == '\x01') {
        uVar23 = uVar23 | 2;
      }
      uStack_228 = CONCAT44(uStack_228._4_4_,uVar23);
      dVar53 = *(double *)(param_4 + 0xd0);
      iVar14 = (int)(ABS((double)local_380) *
                    SQRT((double)uStack_2b8 * (double)uStack_2b8 +
                         (double)local_320 * (double)local_320));
LAB_183b82c0c:
      dStack_2b0 = -dStack_2b0;
      uVar39 = 1;
      goto LAB_183b82c14;
    }
    lVar26 = FUN_183b22bbc(param_3);
    *(undefined8 *)(lVar26 + 0x20) = 0;
    *(undefined8 *)(lVar26 + 0x18) = 0x3ff0000000000000;
    *(undefined8 *)(lVar26 + 0x30) = 0x3ff0000000000000;
    *(undefined8 *)(lVar26 + 0x28) = 0;
    *(undefined8 *)(lVar26 + 0x40) = 0;
    *(undefined8 *)(lVar26 + 0x38) = 0;
    FUN_183b2880c((int)local_2e8,uVar46,SUB84(local_2f0,0),dVar82);
    uVar83 = *(undefined8 *)(param_3 + 0x20);
    uVar15 = *(undefined8 *)*pauVar36;
    uVar85 = *(undefined8 *)(param_3 + 0x30);
    uVar94 = *(undefined8 *)(param_3 + 0x28);
    uVar92 = *(undefined8 *)(param_3 + 0x38);
    *(undefined8 *)(lVar26 + 0x40) = *(undefined8 *)(param_3 + 0x40);
    *(undefined8 *)(lVar26 + 0x38) = uVar92;
    *(undefined8 *)(lVar26 + 0x30) = uVar85;
    *(undefined8 *)(lVar26 + 0x28) = uVar94;
    *(undefined8 *)(lVar26 + 0x20) = uVar83;
    *(undefined8 *)(lVar26 + 0x18) = uVar15;
    FUN_183e18f08(param_4,param_1,param_2,lVar26);
    FUN_183b21200(lVar26);
  }
LAB_183b820e0:
  uVar15 = 0;
LAB_183b820e4:
  if (*_DAT_1e0186220 != local_b0) {
    func_0x000188138130(uVar15);
    return;
  }
  return;
}



/* ==== _shading_finalize @ 183b84540 size=260 ==== */

/* WARNING: Control flow encountered bad instruction data */

void _shading_finalize(long param_1)

{
  int iVar1;
  code *pcVar2;
  long lVar3;
  long lVar4;
  ulong unaff_x30;
  
  if (*(long *)(param_1 + 0x58) != 0) {
    func_0x000188141240();
  }
  lVar4 = *(long *)(param_1 + 0x18);
  if (lVar4 != 0) {
    lVar3 = func_0x000188140d60(lVar4);
    if (DAT_1edf367a0 != -1) {
      func_0x00018813aad0(&DAT_1edf367a0,&DAT_1e22309c8);
    }
    if (lVar3 == DAT_1edf36a20) {
      func_0x000188141240(lVar4);
    }
  }
  iVar1 = *(int *)(param_1 + 0x14);
  if (iVar1 == 1) {
    lVar4 = *(long *)(param_1 + 0xc0);
  }
  else if (iVar1 == 2) {
    lVar4 = *(long *)(param_1 + 0xd0);
  }
  else if (iVar1 == 3) {
    lVar4 = *(long *)(param_1 + 0xa8);
  }
  else {
    if (iVar1 != 4) {
      if (*(code **)(param_1 + 0x78) != (code *)0x0) {
        (**(code **)(param_1 + 0x78))(*(undefined8 *)(param_1 + 0x50));
      }
      goto LAB_183b845b8;
    }
    lVar4 = *(long *)(param_1 + 0xa0);
  }
  if (lVar4 != 0) {
    func_0x000188141240();
  }
LAB_183b845b8:
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0xc471,0x183b845d8);
    (*pcVar2)();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* ==== __ZN2CG23DisplayListEntryShadingD0Ev @ 183bc4eec size=20 ==== */

/* WARNING: Control flow encountered bad instruction data */

void __ZN2CG23DisplayListEntryShadingD0Ev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* ==== __ZNSt3__120__shared_ptr_pointerIPN2CG26DisplayListResourceShadingENS_10shared_ptrIS2_E27__shared_ptr_default_deleteIS2_S2_EENS_9allocatorIS2_EEE16__on_zero_sharedEv @ 183bc4f00 size=40 ==== */

void __ZNSt3__120__shared_ptr_pointerIPN2CG26DisplayListResourceShadingENS_10shared_ptrIS2_E27__shared_ptr_default_deleteIS2_S2_EENS_9allocatorIS2_EEE16__on_zero_sharedEv
               (long param_1)

{
  if (*(long **)(param_1 + 0x18) != (long *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000183bc4f20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(long **)(param_1 + 0x18) + 8))();
    return;
  }
  return;
}



/* ==== __ZN2CG26DisplayListResourceShadingD0Ev @ 183bc4f28 size=56 ==== */

/* WARNING: Control flow encountered bad instruction data */

void __ZN2CG26DisplayListResourceShadingD0Ev(void)

{
  code *pcVar1;
  ulong unaff_x30;
  
  __ZN2CG26DisplayListResourceShadingD2Ev();
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0x183bc4f5c);
    (*pcVar1)();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* ==== __ZN2CG26DisplayListResourceShadingD2Ev @ 183bc4f60 size=88 ==== */

undefined8 * __ZN2CG26DisplayListResourceShadingD2Ev(undefined8 *param_1)

{
  *param_1 = &DAT_1e2232dd0;
  if (param_1[2] != 0) {
    func_0x000188141240();
  }
  if (param_1[3] != 0) {
    func_0x000188141240();
  }
  return param_1;
}



/* ==== __ZNSt3__120__shared_ptr_pointerIPN2CG26DisplayListResourceShadingENS_10shared_ptrIS2_E27__shared_ptr_default_deleteIS2_S2_EENS_9allocatorIS2_EEE21__on_zero_shared_weakEv @ 183bc4fb8 size=4 ==== */

/* WARNING: Control flow encountered bad instruction data */

void __ZNSt3__120__shared_ptr_pointerIPN2CG26DisplayListResourceShadingENS_10shared_ptrIS2_E27__shared_ptr_default_deleteIS2_S2_EENS_9allocatorIS2_EEE21__on_zero_shared_weakEv
               (void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* ==== __ZNSt3__112__hash_tableINS_17__hash_value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEN10applesauce2CF9ObjectRefIP12CGPDFShadingEEEENS_22__unordered_map_hasherIS7_NS_4pairIKS7_SD_EENS_4hashIS7_EENS_8equal_toIvEEEENS_21__unordered_map_equalIS7_SI_SM_SK_EENS5_ISI_EEED2Ev @ 183be0b6c size=116 ==== */

long * __ZNSt3__112__hash_tableINS_17__hash_value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEN10applesauce2CF9ObjectRefIP12CGPDFShadingEEEENS_22__unordered_map_hasherIS7_NS_4pairIKS7_SD_EENS_4hashIS7_EENS_8equal_toIvEEEENS_21__unordered_map_equalIS7_SI_SM_SK_EENS5_ISI_EEED2Ev
                 (long *param_1)

{
  long *plVar1;
  long lVar2;
  
  plVar1 = (long *)param_1[2];
  while (plVar1 != (long *)0x0) {
    lVar2 = *plVar1;
    if (plVar1[5] != 0) {
      func_0x000188141240();
    }
    if (*(char *)((long)plVar1 + 0x27) < '\0') {
      func_0x00018814d0d0(plVar1[2]);
    }
    func_0x00018814d0d0(plVar1);
    plVar1 = (long *)lVar2;
  }
  lVar2 = *param_1;
  *param_1 = 0;
  if (lVar2 != 0) {
    func_0x00018814d0d0();
  }
  return param_1;
}



/* ==== __ZN2CG26DisplayListResourceShading22shouldEvaluateOnRecordEv @ 183c0c634 size=148 ==== */

bool __ZN2CG26DisplayListResourceShading22shouldEvaluateOnRecordEv(long param_1)

{
  uint uVar1;
  bool bVar2;
  undefined8 uVar3;
  ulong uVar4;
  long lVar5;
  ulong uVar6;
  
  if (((param_1 != 0) && (uVar1 = *(int *)(param_1 + 0x14) - 1, uVar1 < 4)) &&
     (*(long *)(param_1 + *(long *)(&DAT_184266ce0 + (ulong)uVar1 * 8)) != 0)) {
    uVar6 = *(ulong *)(*(long *)(param_1 + *(long *)(&DAT_184266ce0 + (ulong)uVar1 * 8)) + 0x18);
    if (uVar6 == 0) {
      bVar2 = false;
    }
    else {
      uVar3 = func_0x00018813b8a0();
      uVar4 = func_0x000188145eb0();
      lVar5 = func_0x000188145ec0(uVar3);
      bVar2 = (uVar4 >= uVar6 && uVar4 - lVar5 <= uVar6) &&
              (uVar4 < uVar6 || uVar6 != uVar4 - lVar5);
    }
    return bVar2;
  }
  return false;
}



/* ==== __ZN2CG19DisplayListExecutor11drawShadingEPKNS_23DisplayListEntryShadingE @ 183c0c6c8 size=640 ==== */

void __ZN2CG19DisplayListExecutor11drawShadingEPKNS_23DisplayListEntryShadingE
               (long param_1,long param_2)

{
  uint uVar1;
  int iVar2;
  code *pcVar3;
  bool bVar4;
  bool bVar5;
  long lVar6;
  double *pdVar7;
  uint uVar8;
  long lVar9;
  long lVar10;
  long lVar11;
  ulong unaff_x30;
  double dVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  double dVar18;
  double dVar19;
  double dVar20;
  double dVar21;
  double dVar22;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  
  if (param_2 == 0) {
    return;
  }
  if (*(long *)(param_1 + 0x20) == 0) {
    return;
  }
  dVar14 = *(double *)(param_1 + 0x30);
  dVar15 = *(double *)(param_1 + 0x38);
  bVar5 = true;
  if ((dVar14 != INFINITY) && (bVar5 = false, !NAN(dVar15))) {
    bVar5 = dVar15 == INFINITY;
  }
  if (!bVar5) {
    if (dVar14 + *(double *)(param_1 + 0x40) < *(double *)(param_2 + 0x10)) {
      return;
    }
    dVar16 = *(double *)(param_2 + 0x10) + *(double *)(param_2 + 0x20);
    dVar18 = *(double *)(param_2 + 0x18) + *(double *)(param_2 + 0x28);
    bVar5 = true;
    if ((*(double *)(param_2 + 0x18) <= dVar15 + *(double *)(param_1 + 0x48)) &&
       (bVar5 = false, !NAN(dVar16) && !NAN(dVar14))) {
      bVar5 = dVar16 < dVar14;
    }
    bVar4 = true;
    if ((!bVar5) && (bVar4 = false, !NAN(dVar18) && !NAN(dVar15))) {
      bVar4 = dVar18 < dVar15;
    }
    if (bVar4) {
      return;
    }
  }
  lVar9 = *(long *)(param_2 + 0x30);
  uStack_78 = *(undefined8 *)(param_2 + 0x60);
  local_80 = *(undefined8 *)(param_2 + 0x58);
  uStack_68 = *(undefined8 *)(param_2 + 0x70);
  uStack_70 = *(undefined8 *)(param_2 + 0x68);
  uStack_58 = *(undefined8 *)(param_2 + 0x80);
  local_60 = *(undefined8 *)(param_2 + 0x78);
  __ZN2CG19DisplayListExecutor22applyEntryDrawingStateEPKNS_28DisplayListEntryStateDrawingERK17CGAffineTransformP8CGGState
            (param_1,lVar9,&local_80);
  if ((*(byte *)(param_2 + 10) >> 2 & 1) != 0) {
    lVar11 = *(long *)(param_2 + 0x48);
    lVar10 = *(long *)(param_1 + 0x20);
    dVar15 = *(double *)(lVar11 + 0x38);
    dVar16 = *(double *)(lVar11 + 0x40);
    dVar14 = *(double *)(*(long *)(lVar10 + 0x78) + 0x20);
    bVar5 = false;
    if ((*(double *)(*(long *)(lVar10 + 0x78) + 0x18) == dVar15) &&
       (bVar5 = false, !NAN(dVar14) && !NAN(dVar16))) {
      bVar5 = dVar14 == dVar16;
    }
    if (!bVar5) {
      _maybeCopyRenderingState(lVar10);
      lVar6 = *(long *)(lVar10 + 0x78);
      *(double *)(lVar6 + 0x18) = dVar15;
      *(double *)(lVar6 + 0x20) = dVar16;
    }
    dVar14 = *(double *)(lVar11 + 0x48);
    if (*(double *)(*(long *)(lVar10 + 0x90) + 0x10) != dVar14) {
      _maybe_copy_device_state(lVar10);
      *(double *)(*(long *)(lVar10 + 0x90) + 0x10) = dVar14;
    }
    dVar22 = *(double *)(lVar11 + 0x10);
    dVar21 = *(double *)(lVar11 + 8);
    dVar18 = *(double *)(lVar11 + 0x20);
    dVar16 = *(double *)(lVar11 + 0x18);
    dVar15 = *(double *)(lVar11 + 0x30);
    dVar14 = *(double *)(lVar11 + 0x28);
    pdVar7 = *(double **)(param_1 + 0x58);
    if (pdVar7 != (double *)0x0) {
      dVar13 = pdVar7[1];
      dVar17 = *pdVar7;
      dVar20 = pdVar7[3];
      dVar19 = pdVar7[2];
      dVar12 = dVar13 * dVar21;
      dVar21 = dVar19 * dVar22 + dVar17 * dVar21;
      dVar22 = dVar20 * dVar22 + dVar12;
      dVar12 = dVar13 * dVar16;
      dVar16 = dVar19 * dVar18 + dVar17 * dVar16;
      dVar18 = dVar20 * dVar18 + dVar12;
      dVar13 = dVar13 * dVar14;
      dVar14 = pdVar7[4] + dVar19 * dVar15 + dVar17 * dVar14;
      dVar15 = pdVar7[5] + dVar20 * dVar15 + dVar13;
    }
    lVar10 = *(long *)(param_1 + 0x10);
    *(double *)(lVar10 + 0x20) = dVar22;
    *(double *)(lVar10 + 0x18) = dVar21;
    *(double *)(lVar10 + 0x30) = dVar18;
    *(double *)(lVar10 + 0x28) = dVar16;
    *(double *)(lVar10 + 0x40) = dVar15;
    *(double *)(lVar10 + 0x38) = dVar14;
  }
  _CGGStateSetInterpolationQuality(*(undefined8 *)(param_1 + 0x20),*(undefined4 *)(param_2 + 0x88));
  lVar11 = *(long *)(param_1 + 0x20);
  uVar1 = *(uint *)(param_2 + 0x8c);
  lVar10 = *(long *)(lVar11 + 0x78);
  uVar8 = (*(int *)(lVar10 + 4) << 0xc) >> 0x1c;
  if (uVar8 != uVar1) {
    _maybeCopyRenderingState(lVar11);
    uVar8 = *(uint *)(*(long *)(lVar11 + 0x78) + 4);
    *(uint *)(*(long *)(lVar11 + 0x78) + 4) =
         uVar8 & 0xfff00000 | uVar8 & 0xffff | (uVar1 & 0xf) << 0x10;
    lVar11 = *(long *)(param_1 + 0x20);
    lVar10 = *(long *)(lVar11 + 0x78);
    uVar8 = (*(int *)(lVar10 + 4) << 0xc) >> 0x1c;
  }
  iVar2 = *(int *)(lVar9 + 0x60);
  if (uVar8 != (iVar2 << 0x12) >> 0x1a) {
    _maybeCopyRenderingState(lVar11);
    uVar1 = *(uint *)(*(long *)(lVar11 + 0x78) + 4);
    *(uint *)(*(long *)(lVar11 + 0x78) + 4) =
         uVar1 & 0xfff00000 | uVar1 & 0xffff | ((iVar2 << 0x12) >> 0x1a & 0xfU) << 0x10;
    lVar11 = *(long *)(param_1 + 0x20);
    lVar10 = *(long *)(lVar11 + 0x78);
  }
  dVar14 = *(double *)(lVar9 + 0x38);
  if (*(double *)(lVar10 + 8) != dVar14) {
    _maybeCopyRenderingState(lVar11);
    *(double *)(*(long *)(lVar11 + 0x78) + 8) = dVar14;
  }
  lVar9 = *(long *)(param_2 + 0x50);
  if (((lVar9 != 0) &&
      (((*(long *)(lVar9 + 0x18) != 0 || (*(long *)(lVar9 + 0x10) != 0)) &&
       (lVar9 = *(long *)(param_1 + 8), lVar9 != 0)))) && (*(code **)(lVar9 + 0x60) != (code *)0x0))
  {
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0x000183c0c8d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(lVar9 + 0x60))
                (lVar9,*(undefined8 *)(param_1 + 0x10),*(undefined8 *)(param_1 + 0x20));
      return;
    }
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0xc471,0x183c0c8d4);
    (*pcVar3)();
  }
  return;
}



/* ==== _CGShadingCreateRadialInternal @ 183c19c78 size=280 ==== */

long _CGShadingCreateRadialInternal
               (undefined8 param_1,undefined8 param_2,double param_3,undefined8 param_4,
               undefined8 param_5,double param_6,long param_7,undefined8 param_8,undefined8 param_9,
               undefined8 *param_10,long param_11,undefined1 param_12,undefined1 param_13)

{
  long lVar1;
  undefined8 uVar2;
  double dVar3;
  
  lVar1 = 0;
  if ((param_7 != 0) && (param_11 != 0)) {
    lVar1 = *(long *)(*(long *)(param_7 + 0x18) + 0x30);
    if (*(long *)(param_11 + 0x30) == lVar1 || *(long *)(param_11 + 0x30) == lVar1 + 1) {
      dVar3 = param_6 + 1e-06;
      if (1e-06 <= ABS(param_3 - param_6)) {
        dVar3 = param_6;
      }
      lVar1 = _CGShadingCreateEmpty(2,param_7,param_8,param_9);
      *(undefined8 *)(lVar1 + 0x80) = param_1;
      *(undefined8 *)(lVar1 + 0x88) = param_2;
      *(double *)(lVar1 + 0x90) = ABS(param_3);
      *(undefined1 *)(lVar1 + 0x98) = param_12;
      *(undefined8 *)(lVar1 + 0xa0) = param_4;
      *(undefined8 *)(lVar1 + 0xa8) = param_5;
      *(double *)(lVar1 + 0xb0) = ABS(dVar3);
      *(undefined1 *)(lVar1 + 0xb8) = param_13;
      func_0x000188141250(param_11);
      *(long *)(lVar1 + 0xd0) = param_11;
      if (param_10 == (undefined8 *)0x0) {
        *(undefined8 *)(lVar1 + 0xc0) = 0;
        uVar2 = 0x3ff0000000000000;
      }
      else {
        *(undefined8 *)(lVar1 + 0xc0) = *param_10;
        uVar2 = param_10[1];
      }
      *(undefined8 *)(lVar1 + 200) = uVar2;
    }
    else {
      lVar1 = 0;
    }
  }
  return lVar1;
}



/* ==== __ZNK2CG23DisplayListEntryShading5_hashEP13XXH64_state_s @ 183c19d90 size=148 ==== */

void __ZNK2CG23DisplayListEntryShading5_hashEP13XXH64_state_s(long param_1,undefined8 param_2)

{
  code *pcVar1;
  ulong unaff_x30;
  undefined4 local_24;
  
  local_24 = *(undefined4 *)(*(long *)(*(long *)(param_1 + 0x50) + 0x10) + 0x10);
  _XXH64_update(param_2,&local_24,4);
  _XXH64_update(param_2,param_1 + 0x58,0x30);
  _XXH64_update(param_2,param_1 + 0x88,4);
  _XXH64_update(param_2,param_1 + 0x8c,4);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0x183c19e20);
    (*pcVar1)();
  }
  __ZNK2CG16DisplayListEntry5_hashEP13XXH64_state_s(param_1,param_2);
  return;
}



/* ==== __ZN2CG26DisplayListResourceShading22createEvaluatedShadingEv @ 183c4ad10 size=304 ==== */

void __ZN2CG26DisplayListResourceShading22createEvaluatedShadingEv(long param_1)

{
  int iVar1;
  uint uVar2;
  long lVar3;
  long lVar4;
  undefined8 uVar5;
  long lVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  
  lVar6 = *(long *)(param_1 + 0x10);
  if (lVar6 == 0) {
    return;
  }
  uVar2 = *(int *)(lVar6 + 0x14) - 1;
  if (uVar2 < 4) {
    lVar4 = 0;
    if (*(long *)(lVar6 + *(long *)(&DAT_184266ce0 + (ulong)uVar2 * 8)) == 0) goto LAB_183c4adc8;
    lVar3 = FUN_183d788b0();
    lVar4 = 0;
    if (lVar3 == 0) goto LAB_183c4adc8;
    lVar4 = lVar6 + 0x30;
    if (*(char *)(lVar6 + 0x28) == '\0') {
      lVar4 = 0;
    }
    lVar4 = _CGShadingCreateEmpty
                      (*(undefined4 *)(lVar6 + 0x14),*(undefined8 *)(lVar6 + 0x18),
                       *(undefined8 *)(lVar6 + 0x20),lVar4);
    if (lVar4 != 0) {
      iVar1 = *(int *)(lVar6 + 0x14);
      if (iVar1 < 3) {
        if (iVar1 == 1) {
          uVar7 = *(undefined8 *)(lVar6 + 0x88);
          uVar5 = *(undefined8 *)(lVar6 + 0x80);
          uVar9 = *(undefined8 *)(lVar6 + 0x98);
          uVar8 = *(undefined8 *)(lVar6 + 0x90);
          uVar10 = *(undefined8 *)(lVar6 + 0xa0);
          uVar12 = *(undefined8 *)(lVar6 + 0xb8);
          uVar11 = *(undefined8 *)(lVar6 + 0xb0);
          *(undefined8 *)(lVar4 + 0xa8) = *(undefined8 *)(lVar6 + 0xa8);
          *(undefined8 *)(lVar4 + 0xa0) = uVar10;
          *(undefined8 *)(lVar4 + 0xb8) = uVar12;
          *(undefined8 *)(lVar4 + 0xb0) = uVar11;
          *(undefined8 *)(lVar4 + 0x88) = uVar7;
          *(undefined8 *)(lVar4 + 0x80) = uVar5;
          *(undefined8 *)(lVar4 + 0x98) = uVar9;
          *(undefined8 *)(lVar4 + 0x90) = uVar8;
          *(long *)(lVar4 + 0xc0) = lVar3;
        }
        else if (iVar1 == 2) {
          uVar5 = *(undefined8 *)(lVar6 + 0x80);
          *(undefined8 *)(lVar4 + 0x88) = *(undefined8 *)(lVar6 + 0x88);
          *(undefined8 *)(lVar4 + 0x80) = uVar5;
          uVar7 = *(undefined8 *)(lVar6 + 0x98);
          uVar5 = *(undefined8 *)(lVar6 + 0x90);
          uVar9 = *(undefined8 *)(lVar6 + 0xa8);
          uVar8 = *(undefined8 *)(lVar6 + 0xa0);
          uVar10 = *(undefined8 *)(lVar6 + 0xb0);
          uVar12 = *(undefined8 *)(lVar6 + 200);
          uVar11 = *(undefined8 *)(lVar6 + 0xc0);
          *(undefined8 *)(lVar4 + 0xb8) = *(undefined8 *)(lVar6 + 0xb8);
          *(undefined8 *)(lVar4 + 0xb0) = uVar10;
          *(undefined8 *)(lVar4 + 200) = uVar12;
          *(undefined8 *)(lVar4 + 0xc0) = uVar11;
          *(undefined8 *)(lVar4 + 0x98) = uVar7;
          *(undefined8 *)(lVar4 + 0x90) = uVar5;
          *(undefined8 *)(lVar4 + 0xa8) = uVar9;
          *(undefined8 *)(lVar4 + 0xa0) = uVar8;
          *(long *)(lVar4 + 0xd0) = lVar3;
        }
      }
      else if (iVar1 == 3) {
        uVar7 = *(undefined8 *)(lVar6 + 0x80);
        uVar9 = *(undefined8 *)(lVar6 + 0x98);
        uVar8 = *(undefined8 *)(lVar6 + 0x90);
        uVar5 = *(undefined8 *)(lVar6 + 0xa0);
        *(undefined8 *)(lVar4 + 0x88) = *(undefined8 *)(lVar6 + 0x88);
        *(undefined8 *)(lVar4 + 0x80) = uVar7;
        *(undefined8 *)(lVar4 + 0x98) = uVar9;
        *(undefined8 *)(lVar4 + 0x90) = uVar8;
        *(undefined8 *)(lVar4 + 0xa0) = uVar5;
        *(long *)(lVar4 + 0xa8) = lVar3;
      }
      else if (iVar1 == 4) {
        uVar10 = *(undefined8 *)(lVar6 + 0xb8);
        uVar9 = *(undefined8 *)(lVar6 + 0xb0);
        uVar8 = *(undefined8 *)(lVar6 + 200);
        uVar7 = *(undefined8 *)(lVar6 + 0xc0);
        uVar5 = *(undefined8 *)(lVar6 + 0xd0);
        uVar11 = *(undefined8 *)(lVar6 + 0xa0);
        *(undefined8 *)(lVar4 + 0xa8) = *(undefined8 *)(lVar6 + 0xa8);
        *(undefined8 *)(lVar4 + 0xa0) = uVar11;
        uVar11 = *(undefined8 *)(lVar6 + 0x80);
        uVar13 = *(undefined8 *)(lVar6 + 0x98);
        uVar12 = *(undefined8 *)(lVar6 + 0x90);
        *(undefined8 *)(lVar4 + 0x88) = *(undefined8 *)(lVar6 + 0x88);
        *(undefined8 *)(lVar4 + 0x80) = uVar11;
        *(undefined8 *)(lVar4 + 0x98) = uVar13;
        *(undefined8 *)(lVar4 + 0x90) = uVar12;
        *(undefined8 *)(lVar4 + 0xd0) = uVar5;
        *(undefined8 *)(lVar4 + 0xb8) = uVar10;
        *(undefined8 *)(lVar4 + 0xb0) = uVar9;
        *(undefined8 *)(lVar4 + 200) = uVar8;
        *(undefined8 *)(lVar4 + 0xc0) = uVar7;
        *(long *)(lVar4 + 0xa0) = lVar3;
      }
      goto LAB_183c4adc8;
    }
    func_0x000188141240(lVar3);
  }
  lVar4 = 0;
LAB_183c4adc8:
  *(long *)(param_1 + 0x18) = lVar4;
  return;
}



/* ==== __ZN2CG26DisplayListResourceShadingD1Ev @ 183c4b2b8 size=4 ==== */

undefined8 * __ZN2CG26DisplayListResourceShadingD1Ev(undefined8 *param_1)

{
  *param_1 = &DAT_1e2232dd0;
  if (param_1[2] != 0) {
    func_0x000188141240();
  }
  if (param_1[3] != 0) {
    func_0x000188141240();
  }
  return param_1;
}



/* ==== __ZNK2CG26DisplayListResourceShading17getChildResourcesEv @ 183c4b2bc size=56 ==== */

void __ZNK2CG26DisplayListResourceShading17getChildResourcesEv(undefined8 *param_1,long param_2)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  if (*(long *)(param_2 + 0x20) != 0) {
    __ZNSt3__16vectorIPKN2CG19DisplayListResourceENS_9allocatorIS4_EEE9push_backB9fqe220106EOS4_
              (param_1);
  }
  return;
}



/* ==== __ZNK2CG26DisplayListResourceShading9_equal_toERKNS_19DisplayListResourceEm @ 183c4b310 size=208 ==== */

undefined8
__ZNK2CG26DisplayListResourceShading9_equal_toERKNS_19DisplayListResourceEm
          (long *param_1,long *param_2)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  ulong uVar4;
  long lVar5;
  ulong uVar6;
  ulong unaff_x30;
  
  if (param_1 == (long *)0x0) {
    uVar3 = func_0x00018814d150();
    return uVar3;
  }
  uVar4 = *(ulong *)(*(long *)(*param_1 + -8) + 8);
  uVar6 = *(ulong *)(*(long *)(*param_2 + -8) + 8);
  if ((uVar4 != uVar6) &&
     ((-1 < (long)(uVar6 & uVar4) ||
      (iVar2 = func_0x0001881386b0(uVar4 & 0x7fffffffffffffff,uVar6 & 0x7fffffffffffffff),
      iVar2 != 0)))) {
    return 0;
  }
  lVar5 = param_2[2];
  if (param_1[2] == 0) {
    if (lVar5 != 0) {
      return 0;
    }
  }
  else {
    if (lVar5 == 0) {
      return 0;
    }
    if (*(int *)(param_1[2] + 0x10) != *(int *)(lVar5 + 0x10)) {
      return 0;
    }
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0x183c4b3d8);
    (*pcVar1)();
  }
  uVar3 = __ZNK2CG19DisplayListResource9_equal_toERKS0_m(param_1,param_2);
  return uVar3;
}



/* ==== _PDFShadingRelease @ 183c5b0e0 size=96 ==== */

/* WARNING: Control flow encountered bad instruction data */

void _PDFShadingRelease(int *param_1)

{
  int iVar1;
  code *pcVar2;
  ulong unaff_x30;
  
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
    *param_1 = iVar1 + -1;
    if (iVar1 + -1 == 0) {
      if (*(long *)(param_1 + 4) != 0) {
        func_0x000188141240();
      }
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0xc471,0x183c5b13c);
        (*pcVar2)();
      }
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  }
  return;
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



/* ==== _type5_create_shading @ 183c5cc60 size=288 ==== */

long _type5_create_shading(long param_1,long param_2)

{
  double *pdVar1;
  double *pdVar2;
  double *pdVar3;
  double *pdVar4;
  bool bVar5;
  bool bVar6;
  undefined8 uVar7;
  long lVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  double local_70;
  double dStack_68;
  double local_60;
  double dStack_58;
  
  pdVar1 = (double *)&DAT_1841d77f0;
  pdVar2 = (double *)&DAT_1841d77d8;
  pdVar3 = (double *)&DAT_1841d77e0;
  pdVar4 = (double *)&DAT_1841d77e8;
  if (param_1 != 0) {
    pdVar1 = (double *)(param_1 + 0x58);
    pdVar2 = (double *)(param_1 + 0x40);
    pdVar3 = (double *)(param_1 + 0x48);
    pdVar4 = (double *)(param_1 + 0x50);
  }
  dVar11 = *pdVar1;
  dVar9 = *pdVar2;
  dVar10 = *pdVar3;
  dVar12 = *pdVar4;
  if (param_1 == 0) {
    lVar8 = 0;
    uVar7 = 0;
  }
  else {
    lVar8 = *(long *)(param_1 + 0x28);
    uVar7 = *(undefined8 *)(param_1 + 0x30);
  }
  local_70 = dVar9;
  dStack_68 = dVar10;
  local_60 = dVar12;
  dStack_58 = dVar11;
  uVar7 = FUN_183b343f4(uVar7);
  bVar5 = false;
  if ((dVar11 == 1.79769313486232e+308) && (bVar5 = false, !NAN(dVar12))) {
    bVar5 = dVar12 == 1.79769313486232e+308;
  }
  bVar6 = false;
  if ((bVar5) && (bVar6 = false, !NAN(dVar10))) {
    bVar6 = dVar10 == -8.988465674311579e+307;
  }
  bVar5 = false;
  if ((bVar6) && (bVar5 = false, !NAN(dVar9))) {
    bVar5 = dVar9 == -8.988465674311579e+307;
  }
  pdVar1 = (double *)(undefined1 *)0x0;
  if (!bVar5) {
    pdVar1 = &local_70;
  }
  if (param_2 == 0) {
    if (lVar8 == 0) {
      return 0;
    }
  }
  else {
    func_0x000188141250(param_2);
    if (lVar8 == 0) {
      return 0;
    }
  }
  lVar8 = _CGShadingCreateEmpty(0,lVar8,uVar7,pdVar1);
  *(long *)(lVar8 + 0x50) = param_2;
  *(undefined8 *)(lVar8 + 0x70) = 0x8010000003c5ce60;
  *(undefined8 *)(lVar8 + 0x68) = 0;
  *(undefined8 *)(lVar8 + 0x78) = 0x8010000003c5da1c;
  return lVar8;
}



/* ==== _cg_shading_type5_draw @ 183c5ce60 size=3004 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _cg_shading_type5_draw(long param_1,undefined8 param_2)

{
  byte *pbVar1;
  ulong uVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  bool bVar5;
  byte *pbVar6;
  long lVar7;
  undefined8 uVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  ulong uVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  undefined8 *puVar14;
  undefined8 uVar15;
  ulong uVar16;
  long extraout_x8;
  long extraout_x8_00;
  long lVar17;
  long extraout_x8_01;
  ulong extraout_x8_02;
  long lVar18;
  undefined8 *puVar19;
  long lVar20;
  long lVar21;
  long lVar22;
  ulong extraout_x12;
  ulong extraout_x12_00;
  ulong uVar23;
  ulong extraout_x12_01;
  long extraout_x12_02;
  ulong uVar24;
  double *pdVar25;
  uint uVar26;
  ulong uVar27;
  uint uVar28;
  long lVar29;
  ulong uVar30;
  byte *pbVar31;
  undefined1 *puVar32;
  ulong uVar33;
  uint uVar34;
  undefined1 *puVar35;
  double dVar36;
  double dVar37;
  double dVar38;
  double dVar39;
  double dVar40;
  undefined8 uStack_19d;
  undefined8 uStack_195;
  undefined1 auStack_18d [15];
  undefined1 auStack_17e [15];
  undefined1 auStack_16f [15];
  undefined8 local_160;
  undefined1 *local_158;
  undefined1 *local_150;
  undefined1 *local_148;
  ulong local_140;
  long local_138;
  undefined1 *local_130;
  undefined1 *local_128;
  long local_120;
  undefined1 auStack_118 [48];
  long local_e8;
  double local_e0;
  double dStack_d8;
  double local_d0;
  double dStack_c8;
  undefined8 local_b8;
  long local_b0 [3];
  undefined1 *local_98;
  undefined1 *local_90;
  undefined1 *local_88;
  long local_80;
  
  local_80 = *_DAT_1e0186220;
  if (0x1000000 < *(ulong *)(param_1 + 0x28)) goto LAB_183c5d93c;
  local_b8 = 0;
  dStack_d8 = 0.0;
  local_e0 = 0.0;
  dStack_c8 = 0.0;
  local_d0 = 0.0;
  local_e8 = 0;
  local_90 = (undefined1 *)0x0;
  local_88 = (undefined1 *)0x0;
  local_98 = (undefined1 *)0x0;
  FUN_183b20e14(param_2,*(undefined8 *)(param_1 + 0x10));
  FUN_183b20f5c(param_2,*(undefined8 *)(param_1 + 0x10));
  FUN_183bdc19c(auStack_118,param_2);
  local_120 = FUN_183f98b4c(*(undefined8 *)(param_1 + 0x10),*(undefined8 *)(param_1 + 0x58));
  if (local_120 == 0) {
    uVar33 = 0;
  }
  else {
    uVar33 = *(ulong *)(local_120 + 8);
  }
  local_160 = param_2;
  pbVar6 = (byte *)func_0x000188140aa0(*(undefined8 *)(param_1 + 0x60));
  lVar7 = func_0x000188140ab0(*(undefined8 *)(param_1 + 0x60));
  pbVar1 = pbVar6 + lVar7;
  uVar16 = *(ulong *)(param_1 + 0x28);
  auVar3._8_8_ = 0;
  auVar3._0_8_ = uVar16;
  lVar7 = uVar16 * 0x90;
  if (SUB168(auVar3 * ZEXT816(0x90),8) != 0) {
    uVar16 = 0xffffffffffffffff;
  }
  lVar17 = 1;
  if (uVar16 < 0x65) {
    lVar17 = lVar7 + 1;
  }
  local_158 = (undefined1 *)&local_160;
  uVar8 = (*_DAT_1e1f91910)(lVar17);
  puVar12 = auStack_16f + -extraout_x8;
  puVar9 = (undefined1 *)0x0;
  if (extraout_x12 < 0x1c71c71c71c71c7) {
    puVar9 = puVar12;
  }
  if (0xfe38e38e38e38e9d < extraout_x12 + 0xfe38e38e38e38e39) {
    puVar9 = (undefined1 *)func_0x000188138470(uVar8,0xd299385);
  }
  uVar16 = *(ulong *)(param_1 + 0x28);
  auVar4._8_8_ = 0;
  auVar4._0_8_ = uVar16;
  lVar7 = uVar16 * 0x90;
  if (SUB168(auVar4 * ZEXT816(0x90),8) != 0) {
    uVar16 = 0xffffffffffffffff;
  }
  lVar17 = 1;
  if (uVar16 < 0x65) {
    lVar17 = lVar7 + 1;
  }
  uVar8 = (*_DAT_1e1f91910)(lVar17);
  puVar10 = (undefined1 *)0x0;
  if (extraout_x12_00 < 0x1c71c71c71c71c7) {
    puVar10 = puVar12 + (-0xf - extraout_x8_00);
  }
  if (0xfe38e38e38e38e9d < extraout_x12_00 + 0xfe38e38e38e38e39) {
    puVar10 = (undefined1 *)func_0x000188138470(uVar8,0x6ad7dd46);
  }
  lVar7 = local_120;
  if (puVar9 != (undefined1 *)0x0) {
    uVar16 = 0;
    uVar34 = 0;
    puVar13 = puVar9;
    puVar32 = (undefined1 *)0x0;
    local_150 = puVar10;
    local_148 = puVar9;
    local_140 = uVar33;
    local_138 = param_1;
    do {
      puVar35 = puVar13;
      if ((uVar16 == 0) && (pbVar6 == pbVar1)) break;
      lVar17 = *(long *)(param_1 + 0x28);
      if (lVar17 == 0) {
        if (puVar32 != (undefined1 *)0x0) goto LAB_183c5d350;
      }
      else {
        lVar18 = 0;
        uVar30 = *(ulong *)(param_1 + 0x18);
        uVar2 = *(ulong *)(param_1 + 0x20);
        dVar36 = (double)(0xffffffff >> (ulong)(-(int)uVar30 & 0x1f));
        uVar23 = uVar30 - 0x18;
        uVar24 = uVar2 - 0x18;
        do {
          pdVar25 = (double *)(puVar35 + lVar18 * 0x90);
          if (uVar30 < 0x19) {
            uVar26 = 0;
            uVar27 = uVar30;
            if (uVar30 != 0) goto LAB_183c5d144;
            uVar28 = 0;
          }
          else {
            uVar27 = uVar16;
            pbVar31 = pbVar6;
            if (uVar16 < 0x18) {
              do {
                uVar34 = uVar34 << 8;
                pbVar6 = pbVar31;
                if (pbVar31 < pbVar1) {
                  pbVar6 = pbVar31 + 1;
                  uVar34 = uVar34 | *pbVar31;
                }
                uVar16 = uVar27 + 8;
                bVar5 = uVar27 < 0x10;
                uVar27 = uVar16;
                pbVar31 = pbVar6;
              } while (bVar5);
            }
            uVar16 = uVar16 - 0x18;
            uVar26 = (uVar34 >> (ulong)((uint)uVar16 & 0x1f) & 0xffffff) <<
                     (ulong)((uint)uVar23 & 0x1f);
            uVar27 = uVar23;
            if (uVar23 == 0) {
              uVar28 = 0;
            }
            else {
LAB_183c5d144:
              for (; uVar16 < uVar27; uVar16 = uVar16 + 8) {
                uVar34 = uVar34 << 8;
                pbVar31 = pbVar6;
                if (pbVar6 < pbVar1) {
                  pbVar31 = pbVar6 + 1;
                  uVar34 = uVar34 | *pbVar6;
                }
                pbVar6 = pbVar31;
              }
              uVar16 = uVar16 - uVar27;
              uVar28 = uVar34 >> (ulong)((uint)uVar16 & 0x1f) &
                       0xffffffffU >> (ulong)(-(int)uVar27 & 0x1f);
            }
          }
          *pdVar25 = *(double *)(param_1 + 0x30) +
                     ((*(double *)(param_1 + 0x40) - *(double *)(param_1 + 0x30)) *
                     (double)(uVar28 | uVar26)) / dVar36;
          if (uVar30 < 0x19) {
            uVar26 = 0;
            uVar27 = uVar30;
            if (uVar30 != 0) goto LAB_183c5d204;
            uVar28 = 0;
          }
          else {
            uVar27 = uVar16;
            pbVar31 = pbVar6;
            if (uVar16 < 0x18) {
              do {
                uVar34 = uVar34 << 8;
                pbVar6 = pbVar31;
                if (pbVar31 < pbVar1) {
                  pbVar6 = pbVar31 + 1;
                  uVar34 = uVar34 | *pbVar31;
                }
                uVar16 = uVar27 + 8;
                bVar5 = uVar27 < 0x10;
                uVar27 = uVar16;
                pbVar31 = pbVar6;
              } while (bVar5);
            }
            uVar16 = uVar16 - 0x18;
            uVar26 = (uVar34 >> (ulong)((uint)uVar16 & 0x1f) & 0xffffff) <<
                     (ulong)((uint)uVar23 & 0x1f);
            uVar27 = uVar23;
            if (uVar23 == 0) {
              uVar28 = 0;
            }
            else {
LAB_183c5d204:
              for (; uVar16 < uVar27; uVar16 = uVar16 + 8) {
                uVar34 = uVar34 << 8;
                pbVar31 = pbVar6;
                if (pbVar6 < pbVar1) {
                  pbVar31 = pbVar6 + 1;
                  uVar34 = uVar34 | *pbVar6;
                }
                pbVar6 = pbVar31;
              }
              uVar16 = uVar16 - uVar27;
              uVar28 = uVar34 >> (ulong)((uint)uVar16 & 0x1f) &
                       0xffffffffU >> (ulong)(-(int)uVar27 & 0x1f);
            }
          }
          pdVar25[1] = *(double *)(param_1 + 0x38) +
                       ((*(double *)(param_1 + 0x48) - *(double *)(param_1 + 0x38)) *
                       (double)(uVar28 | uVar26)) / dVar36;
          if (uVar33 != 0) {
            uVar27 = 0;
            lVar29 = *(long *)(param_1 + 0x50);
            pdVar25 = pdVar25 + 2;
            do {
              if (uVar2 < 0x19) {
                uVar26 = 0;
                uVar11 = uVar2;
                if (uVar2 != 0) goto LAB_183c5d2b8;
                uVar28 = 0;
              }
              else {
                uVar11 = uVar16;
                pbVar31 = pbVar6;
                if (uVar16 < 0x18) {
                  do {
                    uVar34 = uVar34 << 8;
                    pbVar6 = pbVar31;
                    if (pbVar31 < pbVar1) {
                      pbVar6 = pbVar31 + 1;
                      uVar34 = uVar34 | *pbVar31;
                    }
                    uVar16 = uVar11 + 8;
                    bVar5 = uVar11 < 0x10;
                    uVar11 = uVar16;
                    pbVar31 = pbVar6;
                  } while (bVar5);
                }
                uVar16 = uVar16 - 0x18;
                uVar26 = (uVar34 >> (ulong)((uint)uVar16 & 0x1f) & 0xffffff) <<
                         (ulong)((uint)uVar24 & 0x1f);
                uVar28 = 0;
                uVar11 = uVar24;
                if (uVar24 != 0) {
LAB_183c5d2b8:
                  for (; uVar16 < uVar11; uVar16 = uVar16 + 8) {
                    uVar34 = uVar34 << 8;
                    pbVar31 = pbVar6;
                    if (pbVar6 < pbVar1) {
                      pbVar31 = pbVar6 + 1;
                      uVar34 = uVar34 | *pbVar6;
                    }
                    pbVar6 = pbVar31;
                  }
                  uVar16 = uVar16 - uVar11;
                  uVar28 = uVar34 >> (ulong)((uint)uVar16 & 0x1f) &
                           0xffffffffU >> (ulong)(-(int)uVar11 & 0x1f);
                }
              }
              dVar40 = *(double *)(lVar29 + uVar27 * 0x10);
              *pdVar25 = dVar40 + ((*(double *)(lVar29 + (uVar27 << 4 | 8)) - dVar40) *
                                  (double)(uVar28 | uVar26)) /
                                  (double)(0xffffffff >> (ulong)(-(int)uVar2 & 0x1f));
              uVar27 = uVar27 + 1;
              pdVar25 = pdVar25 + 1;
            } while (uVar27 != uVar33);
          }
          uVar16 = uVar16 & 0xfffffffffffffff8;
          lVar18 = lVar18 + 1;
        } while (lVar18 != lVar17);
        if ((puVar32 != (undefined1 *)0x0) && (lVar17 != 1)) {
LAB_183c5d350:
          uVar30 = 0;
          local_130 = puVar32;
          local_128 = puVar35;
          do {
            puVar13 = local_128;
            local_98 = local_130 + uVar30 * 0x90;
            uVar2 = uVar30 + 1;
            lVar17 = uVar30 * 0x90 + 0x90;
            puVar9 = local_130 + lVar17;
            puVar10 = local_128 + uVar30 * 0x90;
            local_90 = puVar9;
            local_88 = puVar10;
            FUN_183f98f10(lVar7,auStack_118,local_b0 + 3);
            param_1 = local_138;
            local_88 = puVar13 + lVar17;
            local_98 = puVar9;
            local_90 = puVar10;
            FUN_183f98f10(lVar7,auStack_118,local_b0 + 3);
            puVar10 = local_150;
            puVar35 = local_128;
            uVar30 = uVar2;
            uVar33 = local_140;
            puVar9 = local_148;
          } while (uVar2 < *(long *)(param_1 + 0x28) - 1U);
        }
      }
      puVar13 = puVar10;
      if (puVar35 != puVar9) {
        puVar13 = puVar9;
      }
      puVar32 = puVar35;
    } while (puVar13 != (undefined1 *)0x0);
  }
  lVar7 = local_120;
  local_b0[0] = 0;
  local_b0[1] = 0;
  local_b0[2] = 0;
  if ((local_120 == 0) || (puVar9 = *(undefined1 **)(local_120 + 0x48), puVar9 == (undefined1 *)0x0)
     ) goto LAB_183c5d93c;
  puVar10 = puVar9;
  if ((ulong)puVar9 >> 0x3c != 0) {
    puVar10 = (undefined1 *)0xffffffffffffffff;
  }
  lVar17 = 1;
  if (puVar10 < (undefined1 *)0x101) {
    lVar17 = (long)puVar9 * 0x10 + 1;
  }
  uVar8 = (*_DAT_1e1f91910)(lVar17);
  puVar10 = puVar12 + (-0xf - extraout_x8_00) + (-0xf - extraout_x8_01);
  puVar12 = (undefined1 *)0x0;
  if (extraout_x12_01 < 0xfffffffffffffff) {
    puVar12 = puVar10;
  }
  if (0xf000000000000101 < extraout_x12_01 + 0xf000000000000001) {
    puVar12 = (undefined1 *)func_0x000188138470(uVar8,0xa61c8851);
  }
  uVar8 = (*_DAT_1e1f91910)((long)puVar9 * 0xd8);
  puVar32 = puVar10 + -extraout_x12_02;
  puVar13 = (undefined1 *)0x0;
  if (extraout_x8_02 < 0x38e38e38e38e38e) {
    puVar13 = puVar32;
  }
  if (0xfc71c71c71c71f72 < extraout_x8_02 + 0xfc71c71c71c71c72) {
    puVar13 = (undefined1 *)func_0x000188138470(uVar8,0x56f7bef6);
  }
  if (*(long *)(param_1 + 0x10) == 0) {
    lVar17 = 0;
    local_140 = 1;
    uVar33 = local_140;
LAB_183c5d584:
    local_140 = uVar33;
    puVar35 = (undefined1 *)0x0;
    lVar7 = 0;
    local_150 = puVar32;
    local_148 = puVar10;
    local_130 = puVar12;
    local_128 = puVar9;
    do {
      puVar9 = local_130;
      *(undefined4 *)(local_130 + (long)puVar35 * 0x10 + 0xc) = 0;
      if (puVar35 < *(undefined1 **)(local_120 + 0x48)) {
        lVar18 = 0;
        lVar20 = *(long *)(local_120 + 0x50);
        lVar21 = *(long *)(local_120 + 0x38);
        lVar22 = *(long *)(local_120 + 0x20);
        lVar29 = 3;
        do {
          local_b0[lVar18] = lVar21 + lVar22 * *(long *)(lVar20 + (long)puVar35 * 0x18 + lVar18 * 8)
          ;
          lVar18 = lVar18 + 1;
          lVar29 = lVar29 + -1;
        } while (lVar29 != 0);
      }
      lVar18 = 0;
      do {
        *(int *)(puVar9 + lVar18 * 4 + (long)puVar35 * 0x10) = (int)lVar7;
        puVar14 = (undefined8 *)(puVar13 + lVar7 * 0x48);
        puVar19 = (undefined8 *)local_b0[lVar18];
        uVar8 = *puVar19;
        puVar14[1] = puVar19[1];
        *puVar14 = uVar8;
        puVar14[2] = 0;
        puVar14[3] = 0;
        if (*(long *)(param_1 + 0x58) == 0) {
          if (lVar17 != 0) {
            lVar29 = 0;
            lVar20 = lVar17;
            do {
              puVar14[lVar29 + 4] = puVar19[lVar29 + 2];
              lVar29 = lVar29 + 1;
              lVar20 = lVar20 + -1;
            } while (lVar20 != 0);
          }
        }
        else {
          local_b8 = puVar19[2];
          FUN_183b7ffbc(*(long *)(param_1 + 0x58),&local_b8,puVar14 + 4);
        }
        lVar7 = lVar7 + 1;
        puVar14[lVar17 + 4] = 0x3ff0000000000000;
        puVar12 = local_130;
        lVar18 = lVar18 + 1;
      } while (lVar18 != 3);
      puVar35 = puVar35 + 1;
    } while (puVar35 != local_128);
    FUN_183f98c1c(local_120);
    uVar33 = local_140;
    uVar16 = _RenderTriangleMesh(puVar13,lVar7,puVar12,local_128,local_140,&local_e8,&local_e0);
    uVar8 = local_160;
    if ((uVar16 & 1) != 0) {
      FUN_183b30f84(local_160);
      FUN_183e1be58(uVar8);
      dVar40 = dStack_c8;
      dVar36 = local_d0;
      lVar7 = local_e8;
      if ((local_d0 < 0.0) || (dVar37 = dStack_c8, dVar39 = local_d0, dStack_c8 < 0.0)) {
        dVar37 = -local_d0;
        if (0.0 <= local_d0) {
          dVar37 = local_d0;
        }
        bVar5 = true;
        if ((dStack_d8 != INFINITY) && (bVar5 = false, !NAN(local_e0))) {
          bVar5 = local_e0 == INFINITY;
        }
        dVar39 = 0.0;
        if (!bVar5) {
          dVar39 = dVar37;
        }
        dVar37 = -dStack_c8;
        if (0.0 <= dStack_c8) {
          dVar37 = dStack_c8;
        }
        dVar38 = 0.0;
        if (dStack_d8 != INFINITY) {
          dVar38 = dVar37;
        }
        dVar37 = 0.0;
        if (local_e0 != INFINITY) {
          dVar37 = dVar38;
        }
      }
      lVar17 = (long)dVar39;
      lVar29 = (long)dVar37;
      lVar18 = uVar33 * 8;
      uVar33 = (ulong)(lVar18 * lVar17) >> 3;
      lVar20 = uVar33 * lVar29;
      _check_clients_buffer("CGDataProviderCreateWithData",local_e8,lVar20);
      if (lVar7 == 0) {
LAB_183c5d88c:
        uVar15 = *(undefined8 *)(param_1 + 0x10);
        *(undefined4 *)(puVar32 + -4) = 0;
        puVar32[-8] = 0;
        *(undefined8 *)(puVar32 + -0x10) = 0;
        lVar17 = FUN_183b1c47c(lVar17,lVar29,8,lVar18,uVar33,uVar15,3,0);
        puVar32 = local_150;
        puVar12 = local_130;
      }
      else {
        puVar14 = (undefined8 *)func_0x000188138470(0x20,0x10c0040176be1e5);
        puVar14[1] = lVar20;
        puVar14[2] = lVar7;
        *puVar14 = 0;
        puVar14[3] = _patch_data_release;
        if (lVar20 < 1) {
          *(char **)(puVar32 + -0x10) = "CGDataProviderCreateDirect";
          *(long *)(puVar32 + -8) = lVar20;
          FUN_183b75268("%s: Invalid size = %jd");
          goto LAB_183c5d88c;
        }
        lVar7 = _create_provider(puVar14,0);
        if (lVar7 == 0) goto LAB_183c5d88c;
        *(long *)(lVar7 + 0x20) = lVar20;
        *(undefined8 *)(lVar7 + 0x58) = 0;
        *(code **)(lVar7 + 0x50) = _data_get_byte_pointer;
        *(code **)(lVar7 + 0x60) = _data_get_bytes_at_position;
        *(code **)(lVar7 + 0x48) = _data_release_info;
        uVar15 = *(undefined8 *)(param_1 + 0x10);
        *(undefined4 *)(puVar32 + -4) = 0;
        puVar32[-8] = 0;
        *(undefined8 *)(puVar32 + -0x10) = 0;
        lVar17 = FUN_183b1c47c(lVar17,lVar29,8,lVar18,uVar33,uVar15,3,lVar7);
        lVar18 = func_0x000188140d60(lVar7);
        if (DAT_1edf367f0 != -1) {
          func_0x00018813aad0(&DAT_1edf367f0,&DAT_1e223ea08);
        }
        puVar12 = local_130;
        puVar32 = local_150;
        if (lVar18 == DAT_1edf36990) {
          func_0x000188141240(lVar7);
        }
      }
      puVar10 = local_148;
      FUN_183b40648(lVar17,1);
      FUN_183b40078(local_e0,dStack_d8,dVar36,dVar40,uVar8,lVar17);
      FUN_183b537d8(uVar8);
      if (lVar17 != 0) {
        func_0x000188141240(lVar17);
      }
      goto LAB_183c5d910;
    }
    if (puVar13 != local_150) {
      func_0x000188138390(puVar13);
    }
    if (puVar12 == local_148) goto LAB_183c5d93c;
  }
  else {
    lVar17 = *(long *)(*(long *)(*(long *)(param_1 + 0x10) + 0x18) + 0x30);
    uVar33 = lVar17 + 1U;
    if (lVar17 + 1U < 6) goto LAB_183c5d584;
    FUN_183f98c1c(lVar7);
LAB_183c5d910:
    if (puVar13 != puVar32) {
      func_0x000188138390(puVar13);
    }
    if (puVar12 == puVar10) goto LAB_183c5d93c;
  }
  func_0x000188138390(puVar12);
LAB_183c5d93c:
  if (*_DAT_1e0186220 == local_80) {
    return;
  }
  func_0x000188138130();
  return;
}



/* ==== _cg_shading_type5_release @ 183c5da1c size=12 ==== */

/* WARNING: Control flow encountered bad instruction data */

void _cg_shading_type5_release(long param_1)

{
  if (param_1 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return;
}



/* ==== _CGPDFShadingType3Init @ 183c9299c size=524 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _CGPDFShadingType3Init(long param_1,long *param_2,undefined8 *param_3)

{
  long lVar1;
  undefined8 *puVar2;
  ulong uVar3;
  char *pcVar4;
  undefined8 uVar5;
  long lVar6;
  undefined8 uVar7;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  double dStack_70;
  undefined8 uStack_68;
  undefined8 local_60;
  double dStack_58;
  long local_48;
  
  local_48 = *_DAT_1e0186220;
  if ((param_1 == 0) || (lVar6 = *(long *)(param_1 + 0x28), lVar6 == 0)) {
LAB_183c92a28:
    puVar2 = (undefined8 *)func_0x000188138460(1,0x50,0x1020040c9b8900f);
    func_0x000188142e40(puVar2,"CGPDFNamedAlloc_Graphics");
    if (puVar2 != (undefined8 *)0x0) {
      local_88 = 0;
      *param_2 = (long)puVar2;
      param_3[1] = 0x8010000003c92ca4;
      *param_3 = 0x8010000003c92ba8;
      uVar7 = 0;
      if (param_1 != 0) {
        uVar7 = *(undefined8 *)(param_1 + 0x18);
      }
      uVar3 = FUN_183bd5f94(uVar7,"Coords",&local_80,6);
      if ((uVar3 & 1) == 0) {
        pcVar4 = "missing or invalid shading `Coords\' value.";
      }
      else {
        puVar2[1] = uStack_78;
        *puVar2 = local_80;
        puVar2[3] = uStack_68;
        puVar2[2] = dStack_70;
        puVar2[5] = dStack_58;
        puVar2[4] = local_60;
        if ((dStack_70 < 0.0) || (dStack_58 < 0.0)) {
          pcVar4 = "invalid shading `Coords\' value.";
        }
        else {
          uVar3 = FUN_183bd5f94(uVar7,"Domain",puVar2 + 6,2);
          if ((uVar3 & 1) == 0) {
            puVar2[7] = 0x3ff0000000000000;
            puVar2[6] = 0;
          }
          uVar3 = FUN_183bcf4b0(uVar7,"Function",&local_88);
          if ((uVar3 & 1) != 0) {
            lVar6 = _CGPDFShadingCreateShadingFunction(local_88,1);
            puVar2[8] = lVar6;
            uVar5 = 0;
            if (lVar6 != 0) {
              uVar3 = FUN_183ee2970(uVar7,"Extend",puVar2 + 9,2);
              if ((uVar3 & 1) == 0) {
                *(undefined2 *)(puVar2 + 9) = 0;
              }
              uVar5 = 1;
            }
            goto LAB_183c92b5c;
          }
          pcVar4 = "missing or invalid shading `Function\' value.";
        }
      }
      goto LAB_183c92b54;
    }
  }
  else {
    lVar1 = func_0x000188140d60(lVar6);
    if (DAT_1edf367a0 != -1) {
      func_0x00018813aad0(&DAT_1edf367a0,&DAT_1e22309c8);
    }
    if ((lVar1 != DAT_1edf36a20) || (*(int *)(*(long *)(lVar6 + 0x18) + 0x18) != 7))
    goto LAB_183c92a28;
    pcVar4 = "invalid shading `ColorSpace\' value.";
LAB_183c92b54:
    _pdf_error(pcVar4);
  }
  uVar5 = 0;
LAB_183c92b5c:
  if (*_DAT_1e0186220 == local_48) {
    return;
  }
  func_0x000188138130(uVar5);
  return;
}



/* ==== _type3_create_shading @ 183c92ba8 size=252 ==== */

void _type3_create_shading(long param_1,undefined8 *param_2)

{
  double *pdVar1;
  double *pdVar2;
  double *pdVar3;
  double *pdVar4;
  bool bVar5;
  bool bVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  double local_60;
  double dStack_58;
  double local_50;
  double dStack_48;
  
  pdVar1 = (double *)&DAT_1841d77f0;
  pdVar2 = (double *)&DAT_1841d77d8;
  pdVar3 = (double *)&DAT_1841d77e0;
  pdVar4 = (double *)&DAT_1841d77e8;
  if (param_1 != 0) {
    pdVar1 = (double *)(param_1 + 0x58);
    pdVar2 = (double *)(param_1 + 0x40);
    pdVar3 = (double *)(param_1 + 0x48);
    pdVar4 = (double *)(param_1 + 0x50);
  }
  dVar11 = *pdVar1;
  dVar9 = *pdVar2;
  dVar10 = *pdVar3;
  dVar12 = *pdVar4;
  if (param_1 == 0) {
    uVar8 = 0;
    uVar7 = 0;
  }
  else {
    uVar8 = *(undefined8 *)(param_1 + 0x28);
    uVar7 = *(undefined8 *)(param_1 + 0x30);
  }
  local_60 = dVar9;
  dStack_58 = dVar10;
  local_50 = dVar12;
  dStack_48 = dVar11;
  uVar7 = FUN_183b343f4(uVar7);
  bVar5 = false;
  if ((dVar11 == 1.79769313486232e+308) && (bVar5 = false, !NAN(dVar12))) {
    bVar5 = dVar12 == 1.79769313486232e+308;
  }
  bVar6 = false;
  if ((bVar5) && (bVar6 = false, !NAN(dVar10))) {
    bVar6 = dVar10 == -8.988465674311579e+307;
  }
  bVar5 = false;
  if ((bVar6) && (bVar5 = false, !NAN(dVar9))) {
    bVar5 = dVar9 == -8.988465674311579e+307;
  }
  pdVar1 = (double *)(undefined1 *)0x0;
  if (!bVar5) {
    pdVar1 = &local_60;
  }
  _CGShadingCreateRadialInternal
            (*param_2,param_2[1],param_2[2],param_2[3],param_2[4],param_2[5],uVar8,uVar7,pdVar1,
             param_2 + 6,param_2[8],*(char *)(param_2 + 9) != '\0',
             *(char *)((long)param_2 + 0x49) != '\0');
  return;
}



/* ==== _rip_adaptive_bitmap_context_draw_shading @ 183c98510 size=432 ==== */

undefined8
_rip_adaptive_bitmap_context_draw_shading(long param_1,undefined8 param_2,long param_3,long param_4)

{
  byte bVar1;
  uint uVar2;
  long lVar3;
  undefined8 uVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  float fVar8;
  undefined4 uVar9;
  float fVar10;
  
  if (param_1 == 0) {
    lVar5 = 0;
  }
  else {
    lVar5 = *(long *)(param_1 + 0x128);
  }
  func_0x00018813b850(lVar5 + 0x78);
  lVar7 = *(long *)(lVar5 + 0x58);
  if (lVar7 == 0) {
    lVar7 = *(long *)(lVar5 + 0x50);
  }
  _rip_adaptive_bitmap_context_update_content_info_from_GState(lVar5,param_3);
  fVar10 = *(float *)(*(long *)(param_3 + 0x78) + 0x30);
  fVar8 = *(float *)(lVar5 + 0x70);
  if (*(float *)(lVar5 + 0x70) <= fVar10) {
    fVar8 = fVar10;
  }
  *(float *)(lVar5 + 0x70) = fVar8;
  lVar6 = *(long *)(param_4 + 0x18);
  uVar2 = _rip_adaptive_bitmap_context_get_content_type_from_color_space(lVar6);
  *(uint *)(lVar5 + 0x74) = *(uint *)(lVar5 + 0x74) | uVar2;
  if (uVar2 == 1) goto LAB_183c985fc;
  if (uVar2 == 2) {
    if (lVar6 == 0) {
LAB_183c985d4:
      bVar1 = 0;
    }
    else {
      lVar3 = func_0x000188140d60(lVar6);
      if (DAT_1edf367a0 != -1) {
        func_0x00018813aad0(&DAT_1edf367a0,&DAT_1e22309c8);
      }
      if (lVar3 != DAT_1edf36a20) goto LAB_183c985d4;
      bVar1 = *(byte *)(*(long *)(lVar6 + 0x18) + 0xe);
    }
    bVar1 = *(byte *)(lVar5 + 0x68) | bVar1 & 1;
  }
  else {
    bVar1 = 1;
  }
  *(byte *)(lVar5 + 0x68) = bVar1;
LAB_183c985fc:
  fVar10 = *(float *)(lVar5 + 0x6c);
  fVar8 = (float)FUN_183b7ff44(param_4);
  if (fVar10 <= fVar8) {
    uVar9 = FUN_183b7ff44(param_4);
  }
  else {
    uVar9 = *(undefined4 *)(lVar5 + 0x6c);
  }
  *(undefined4 *)(lVar5 + 0x6c) = uVar9;
  if (lVar7 == 0) {
    uVar4 = 0;
  }
  else {
    lVar7 = *(long *)(lVar7 + 0x28);
    if (lVar7 == 0) {
      uVar4 = 0;
    }
    else if (*(code **)(lVar7 + 0x60) == (code *)0x0) {
      uVar4 = 0x3ee;
    }
    else {
      uVar4 = (**(code **)(lVar7 + 0x60))(lVar7,param_2,param_3,param_4);
    }
    bVar1 = _rip_adaptive_bitmap_context_contains_transparency(lVar5);
    *(byte *)(lVar5 + 0x69) = *(byte *)(lVar5 + 0x69) | bVar1;
  }
  func_0x00018813b860(lVar5 + 0x78);
  return uVar4;
}



/* ==== __ZL18stream_DrawShadingP17CGContextDelegateP16CGRenderingStateP8CGGStateP9CGShading @ 183ca9b0c size=140 ==== */

undefined8
__ZL18stream_DrawShadingP17CGContextDelegateP16CGRenderingStateP8CGGStateP9CGShading
          (long param_1,long param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  
  if (*(uint *)(param_4 + 0x14) < 5 && (1 << (ulong)(*(uint *)(param_4 + 0x14) & 0x1f) & 0x16U) != 0
     ) {
    if ((param_1 == 0) || (lVar1 = *(long *)(param_1 + 0x128), lVar1 == 0)) {
      return 1000;
    }
    uVar3 = *(undefined8 *)(param_2 + 0x20);
    uVar2 = *(undefined8 *)(param_2 + 0x18);
    uVar4 = *(undefined8 *)(param_2 + 0x28);
    uVar6 = *(undefined8 *)(param_2 + 0x40);
    uVar5 = *(undefined8 *)(param_2 + 0x38);
    *(undefined8 *)(lVar1 + 0x150) = *(undefined8 *)(param_2 + 0x30);
    *(undefined8 *)(lVar1 + 0x148) = uVar4;
    *(undefined8 *)(lVar1 + 0x160) = uVar6;
    *(undefined8 *)(lVar1 + 0x158) = uVar5;
    *(undefined8 *)(lVar1 + 0x140) = uVar3;
    *(undefined8 *)(lVar1 + 0x138) = uVar2;
    _PDFContentStreamDrawShading(lVar1,param_3,param_4);
  }
  else {
    FUN_183e18f08(param_4,param_1,param_2,param_3);
  }
  return 0;
}



/* ==== __ZN35DisplayListXMLWriterResourceShadingD1Ev @ 183cea8c4 size=4 ==== */

void __ZN35DisplayListXMLWriterResourceShadingD1Ev(void)

{
  return;
}



/* ==== __ZN35DisplayListXMLWriterResourceShadingD0Ev @ 183cea8c8 size=20 ==== */

/* WARNING: Control flow encountered bad instruction data */

void __ZN35DisplayListXMLWriterResourceShadingD0Ev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* ==== __ZN35DisplayListXMLWriterResourceShading15writeAttributesERNSt3__13mapINS0_12basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEES7_NS0_4lessIS7_EENS5_INS0_4pairIKS7_S7_EEEEEE @ 183cea8dc size=100 ==== */

undefined8
__ZN35DisplayListXMLWriterResourceShading15writeAttributesERNSt3__13mapINS0_12basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEES7_NS0_4lessIS7_EENS5_INS0_4pairIKS7_S7_EEEEEE
          (long param_1,undefined8 param_2)

{
  __ZN28DisplayListXMLWriterResource15writeAttributesERNSt3__13mapINS0_12basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEES7_NS0_4lessIS7_EENS5_INS0_4pairIKS7_S7_EEEEEE
            ();
  if (*(long *)(*(long *)(param_1 + 0x18) + 0x20) != 0) {
    __ZN2CG24DisplayListXMLSerializer23getElementIDForResourceEPKNS_19DisplayListResourceE
              (*(undefined8 *)(param_1 + 0x10));
    __ZN2CG20DisplayListXMLHelper21addFormatToAttributesERNSt3__13mapINS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES8_NS1_4lessIS8_EENS6_INS1_4pairIKS8_S8_EEEEEEPKcSI_z
              (param_2,"colorSpace","%llu");
  }
  return 1;
}



/* ==== __ZNK35DisplayListXMLWriterResourceShading11getResourceEv @ 183cea940 size=8 ==== */

undefined8 __ZNK35DisplayListXMLWriterResourceShading11getResourceEv(long param_1)

{
  return *(undefined8 *)(param_1 + 0x18);
}



/* ==== __ZN32DisplayListXMLWriterEntryShadingD1Ev @ 183cec910 size=4 ==== */

void __ZN32DisplayListXMLWriterEntryShadingD1Ev(void)

{
  return;
}



/* ==== __ZN32DisplayListXMLWriterEntryShadingD0Ev @ 183cec914 size=20 ==== */

/* WARNING: Control flow encountered bad instruction data */

void __ZN32DisplayListXMLWriterEntryShadingD0Ev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* ==== __ZN32DisplayListXMLWriterEntryShading15writeAttributesERNSt3__13mapINS0_12basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEES7_NS0_4lessIS7_EENS5_INS0_4pairIKS7_S7_EEEEEE @ 183cec928 size=252 ==== */

undefined8
__ZN32DisplayListXMLWriterEntryShading15writeAttributesERNSt3__13mapINS0_12basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEES7_NS0_4lessIS7_EENS5_INS0_4pairIKS7_S7_EEEEEE
          (long param_1,undefined8 param_2)

{
  uint uVar1;
  undefined8 uVar2;
  
  __ZN25DisplayListXMLWriterEntry15writeAttributesERNSt3__13mapINS0_12basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEES7_NS0_4lessIS7_EENS5_INS0_4pairIKS7_S7_EEEEEE
            ();
  if (*(long *)(*(long *)(param_1 + 0x18) + 0x50) != 0) {
    __ZN2CG24DisplayListXMLSerializer23getElementIDForResourceEPKNS_19DisplayListResourceE
              (*(undefined8 *)(param_1 + 8));
    __ZN2CG20DisplayListXMLHelper21addFormatToAttributesERNSt3__13mapINS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES8_NS1_4lessIS8_EENS6_INS1_4pairIKS8_S8_EEEEEEPKcSI_z
              (param_2,"shading","%llu");
  }
  __ZN2CG20DisplayListXMLHelper21addFormatToAttributesERNSt3__13mapINS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES8_NS1_4lessIS8_EENS6_INS1_4pairIKS8_S8_EEEEEEPKcSI_z
            (param_2,"ctm","[%.17lg %.17lg %.17lg %.17lg %.17lg %.17lg]");
  uVar1 = *(uint *)(*(long *)(param_1 + 0x18) + 0x88);
  if (uVar1 < 5) {
    uVar2 = *(undefined8 *)(&DAT_1e05da670 + (ulong)uVar1 * 8);
  }
  else {
    uVar2 = 0;
  }
  __ZN2CG20DisplayListXMLHelper21addStringToAttributesERNSt3__13mapINS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES8_NS1_4lessIS8_EENS6_INS1_4pairIKS8_S8_EEEEEEPKcSI_
            (param_2,"interpolationQuality",uVar2);
  uVar1 = *(uint *)(*(long *)(param_1 + 0x18) + 0x8c);
  if (uVar1 < 5) {
    uVar2 = *(undefined8 *)(&DAT_1e05da4d0 + (ulong)uVar1 * 8);
  }
  else {
    uVar2 = 0;
  }
  __ZN2CG20DisplayListXMLHelper21addStringToAttributesERNSt3__13mapINS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES8_NS1_4lessIS8_EENS6_INS1_4pairIKS8_S8_EEEEEEPKcSI_
            (param_2,"renderingIntent",uVar2);
  return 1;
}



/* ==== __ZN32DisplayListXMLWriterEntryShading18writeChildElementsEv @ 183ceca24 size=8 ==== */

undefined8 __ZN32DisplayListXMLWriterEntryShading18writeChildElementsEv(void)

{
  return 1;
}



/* ==== __ZNK32DisplayListXMLWriterEntryShading8getEntryEv @ 183ceca2c size=8 ==== */

undefined8 __ZNK32DisplayListXMLWriterEntryShading8getEntryEv(long param_1)

{
  return *(undefined8 *)(param_1 + 0x18);
}



/* ==== _rips_DrawShading @ 183cf3d20 size=712 ==== */

undefined8 _rips_DrawShading(long param_1,undefined8 param_2,long param_3,undefined8 param_4)

{
  code *pcVar1;
  uint uVar2;
  long lVar3;
  long lVar4;
  undefined8 uVar5;
  long lVar6;
  long lVar7;
  long *plVar8;
  ulong unaff_x30;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  
  if (param_1 == 0) {
    lVar7 = *(long *)(*(long *)(param_3 + 0x78) + 0x10);
    if (lVar7 == 0) {
      return 0;
    }
    plVar8 = (long *)0x0;
  }
  else {
    lVar7 = *(long *)(*(long *)(param_3 + 0x78) + 0x10);
    if (lVar7 == 0) {
      lVar7 = *(long *)(param_1 + 0x10);
      if (lVar7 == 0) {
        return 0;
      }
      if (*(code **)(lVar7 + 0x60) != (code *)0x0) {
        if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0xc471,0x183cf3e08);
          (*pcVar1)();
        }
                    /* WARNING: Could not recover jumptable at 0x000183cf3e08. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar5 = (**(code **)(lVar7 + 0x60))(lVar7,param_2,param_3,param_4);
        return uVar5;
      }
      return 0x3ee;
    }
    plVar8 = *(long **)(param_1 + 0x128);
  }
  uStack_68 = 0;
  local_70 = 0;
  uStack_58 = 0;
  uStack_60 = 0;
  uStack_88 = 0;
  local_90 = 0;
  uStack_78 = 0;
  uStack_80 = 0;
  uStack_98 = 0;
  local_a0 = 0;
  lVar3 = _rips_Acquire(plVar8,param_2,lVar7,&local_a0,param_3);
  if (lVar3 == 0) {
    func_0x000188141250(lVar7);
    uVar2 = 0x200;
  }
  else {
    lVar4 = *plVar8;
    if ((lVar4 != 0) && (*(code **)(lVar4 + 0x60) != (code *)0x0)) {
      (**(code **)(lVar4 + 0x60))(lVar4,param_2,param_3,param_4);
    }
    uVar2 = _rips_Initialize(lVar3);
  }
  if (*(long *)(*(long *)(param_3 + 0x78) + 0x10) != 0) {
    _maybeCopyRenderingState(param_3);
    lVar4 = *(long *)(param_3 + 0x78);
    if (*(long *)(lVar4 + 0x10) != 0) {
      func_0x000188141240();
      lVar4 = *(long *)(param_3 + 0x78);
    }
    *(undefined8 *)(lVar4 + 0x10) = 0;
  }
  lVar4 = 0;
  if (param_1 != 0) {
    lVar4 = *(long *)(param_1 + 0x10);
  }
  if (lVar3 != 0) {
    _rips_Begin(lVar3,uVar2,lVar4,param_2,param_3);
  }
  if ((uVar2 >> 0xb & 1) == 0) {
    if (((uVar2 >> 9 & 1) == 0) || (lVar4 == 0)) {
      uVar5 = 0;
    }
    else if (*(code **)(lVar4 + 0x60) == (code *)0x0) {
      uVar5 = 0x3ee;
    }
    else {
      uVar5 = (**(code **)(lVar4 + 0x60))(lVar4,param_2,param_3,param_4);
    }
    if (lVar3 == 0) {
      if (*(long *)(*(long *)(param_3 + 0x78) + 0x10) != lVar7) {
        _maybeCopyRenderingState(param_3);
        if (*(long *)(*(long *)(param_3 + 0x78) + 0x10) != 0) {
          func_0x000188141240();
        }
        func_0x000188141250(lVar7);
        *(long *)(*(long *)(param_3 + 0x78) + 0x10) = lVar7;
        return uVar5;
      }
      return uVar5;
    }
  }
  else {
    lVar6 = __ZN2CG11DisplayList19createCGDisplayListEPK14__CFDictionaryRK6CGRect(0,&DAT_1841d7830);
    *(long *)(lVar3 + 0x48) = lVar6;
    if (lVar6 == 0) {
      uVar5 = 1000;
    }
    else {
      lVar6 = __ZN2CG11DisplayList21createContextDelegateEP13CGDisplayList();
      if (lVar6 == 0) {
        uVar5 = 0;
      }
      else {
        if (*(code **)(lVar6 + 0x60) == (code *)0x0) {
          uVar5 = 0x3ee;
        }
        else {
          uVar5 = (**(code **)(lVar6 + 0x60))(lVar6,param_2,param_3,param_4);
        }
        func_0x000188141240(lVar6);
      }
    }
  }
  _rips_End(lVar3,uVar2,lVar4,param_2);
  if (*(long *)(*(long *)(param_3 + 0x78) + 0x10) != lVar7) {
    _maybeCopyRenderingState(param_3);
    if (*(long *)(*(long *)(param_3 + 0x78) + 0x10) != 0) {
      func_0x000188141240();
    }
    func_0x000188141250(lVar7);
    *(long *)(*(long *)(param_3 + 0x78) + 0x10) = lVar7;
  }
  _rips_Release(lVar3);
  return uVar5;
}



/* ==== __ZN35DisplayListXMLParserResourceShadingD1Ev @ 183d0bdd0 size=4 ==== */

void __ZN35DisplayListXMLParserResourceShadingD1Ev(void)

{
  return;
}



/* ==== __ZN35DisplayListXMLParserResourceShadingD0Ev @ 183d0bdd4 size=20 ==== */

/* WARNING: Control flow encountered bad instruction data */

void __ZN35DisplayListXMLParserResourceShadingD0Ev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* ==== __ZN2CG23DisplayListEntryShadingD1Ev @ 183d10a54 size=4 ==== */

void __ZN2CG23DisplayListEntryShadingD1Ev(void)

{
  return;
}



/* ==== __ZNK2CG23DisplayListEntryShading7getSizeEv @ 183d10a58 size=8 ==== */

undefined8 __ZNK2CG23DisplayListEntryShading7getSizeEv(void)

{
  return 0x90;
}



/* ==== __ZNK2CG23DisplayListEntryShading9_equal_toERKNS_16DisplayListEntryEm @ 183d10a60 size=344 ==== */

undefined8
__ZNK2CG23DisplayListEntryShading9_equal_toERKNS_16DisplayListEntryEm
          (long *param_1,long *param_2,undefined8 param_3)

{
  code *pcVar1;
  int iVar2;
  long *plVar3;
  undefined8 uVar4;
  long lVar5;
  ulong uVar6;
  ulong uVar7;
  ulong unaff_x30;
  ushort uVar8;
  
  if (param_1 == (long *)0x0) {
    uVar4 = func_0x00018814d150();
    return uVar4;
  }
  uVar6 = *(ulong *)(*(long *)(*param_1 + -8) + 8);
  uVar7 = *(ulong *)(*(long *)(*param_2 + -8) + 8);
  if (((uVar6 == uVar7) ||
      (((long)(uVar7 & uVar6) < 0 &&
       (iVar2 = func_0x0001881386b0(uVar6 & 0x7fffffffffffffff,uVar7 & 0x7fffffffffffffff),
       iVar2 == 0)))) &&
     (((double)param_1[0xb] == (double)param_2[0xb] &&
      ((((uVar8 = NEON_uminv(CONCAT26(-(ushort)((double)param_1[0xf] == (double)param_2[0xf]),
                                      CONCAT24(-(ushort)((double)param_1[0xe] ==
                                                        (double)param_2[0xe]),
                                               CONCAT22(-(ushort)((double)param_1[0xd] ==
                                                                 (double)param_2[0xd]),
                                                        -(ushort)((double)param_1[0xc] ==
                                                                 (double)param_2[0xc])))),2),
         (uVar8 & 1) != 0 && ((double)param_1[0x10] == (double)param_2[0x10])) &&
        ((int)param_1[0x11] == (int)param_2[0x11])) &&
       (*(int *)((long)param_1 + 0x8c) == *(int *)((long)param_2 + 0x8c))))))) {
    plVar3 = (long *)param_1[10];
    lVar5 = param_2[10];
    if (plVar3 == (long *)0x0) {
      if (lVar5 == 0) goto LAB_183d10b88;
    }
    else if ((lVar5 != 0) &&
            (iVar2 = (**(code **)(*plVar3 + 0x18))(plVar3,lVar5,param_3), iVar2 != 0)) {
LAB_183d10b88:
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0xc471,0x183d10bb0);
        (*pcVar1)();
      }
      uVar4 = __ZNK2CG16DisplayListEntry9_equal_toERKS0_m(param_1,param_2,param_3);
      return uVar4;
    }
  }
  return 0;
}



/* ==== __ZN32DisplayListXMLParserEntryShadingD1Ev @ 183d10bb8 size=4 ==== */

void __ZN32DisplayListXMLParserEntryShadingD1Ev(void)

{
  return;
}



/* ==== __ZN32DisplayListXMLParserEntryShadingD0Ev @ 183d10bbc size=20 ==== */

/* WARNING: Control flow encountered bad instruction data */

void __ZN32DisplayListXMLParserEntryShadingD0Ev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* ==== _PDFDocumentAddShading @ 183d72c40 size=400 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * _PDFDocumentAddShading(long param_1,long param_2)

{
  undefined4 uVar1;
  long lVar2;
  undefined8 uVar3;
  long *plVar4;
  undefined4 *puVar5;
  
  plVar4 = *(long **)(param_1 + 0x1a8);
  if (plVar4 == (long *)0x0) {
    plVar4 = (long *)func_0x000188138460(1,0x20,0x102004055ccde27);
    func_0x000188142e40(plVar4,"CGPDFNamedAlloc_Graphics");
    if (plVar4 != (long *)0x0) {
      *plVar4 = param_1;
    }
    *(long **)(param_1 + 0x1a8) = plVar4;
  }
  if (plVar4 == (long *)0x0 || param_2 == 0) {
    puVar5 = (undefined4 *)0x0;
  }
  else {
    lVar2 = plVar4[1];
    if (lVar2 == 0) {
      lVar2 = func_0x000188140c00(*_DAT_1e00fe6a8,0,0,&DAT_1e222d750);
      plVar4[1] = lVar2;
    }
    uVar1 = *(undefined4 *)(param_2 + 0x10);
    puVar5 = (undefined4 *)func_0x000188140c60(lVar2,uVar1);
    if (puVar5 == (undefined4 *)0x0) {
      lVar2 = *plVar4;
      *(int *)(plVar4 + 3) = (int)plVar4[3] + 1;
      puVar5 = (undefined4 *)func_0x000188138460(1,0x38,0x102004018474591);
      func_0x000188142e40(puVar5,"CGPDFNamedAlloc_Graphics");
      if (puVar5 != (undefined4 *)0x0) {
        *puVar5 = 1;
        *(long *)(puVar5 + 2) = lVar2;
        func_0x000188141250(param_2);
        *(long *)(puVar5 + 4) = param_2;
        uVar3 = _PDFXRefTableAddObject(*(undefined8 *)(lVar2 + 0x1f8));
        *(undefined8 *)(puVar5 + 6) = uVar3;
        *(undefined1 *)(puVar5 + 0xc) = 0;
        func_0x00018813bab0(puVar5 + 8,0x10,0,"Sh%lu");
      }
      func_0x000188140ca0(plVar4[1],uVar1,puVar5);
      _PDFShadingRelease(puVar5);
    }
    lVar2 = plVar4[2];
    if (lVar2 == 0) {
      lVar2 = _CGOrderedSetCreate();
      plVar4[2] = lVar2;
    }
    _CGOrderedSetAddValue(lVar2,puVar5);
  }
  return puVar5;
}



/* ==== __ZNSt3__122__hash_node_destructorINS_9allocatorINS_11__hash_nodeINS_17__hash_value_typeINS_12basic_stringIcNS_11char_traitsIcEENS1_IcEEEEN10applesauce2CF9ObjectRefIP12CGPDFShadingEEEEPvEEEEEclB9fqe220106EPSH_ @ 183dc9420 size=84 ==== */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Possible PIC construction at 0x000183dc9450: Changing call to branch */

void __ZNSt3__122__hash_node_destructorINS_9allocatorINS_11__hash_nodeINS_17__hash_value_typeINS_12basic_stringIcNS_11char_traitsIcEENS1_IcEEEEN10applesauce2CF9ObjectRefIP12CGPDFShadingEEEEPvEEEEEclB9fqe220106EPSH_
               (ulong param_1,long param_2)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if ((param_1 & 1) != 0) {
    if (*(long *)(param_2 + 0x28) != 0) {
      func_0x000188141240();
    }
    if (*(char *)(param_2 + 0x27) < '\0') {
      halt_baddata();
    }
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0xc471,0x183dc9470);
  (*pcVar1)();
}



/* ==== _zombie_DrawShading @ 183de7930 size=8 ==== */

undefined8 _zombie_DrawShading(void)

{
  return 0;
}



/* ==== _CGShadingCreateRadialWithGradient @ 183e18af0 size=272 ==== */

long _CGShadingCreateRadialWithGradient
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,long param_7,undefined8 param_8,
               undefined8 param_9)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  
  lVar1 = func_0x000188140d60();
  if (DAT_1edf35940 != -1) {
    func_0x00018813aad0(&DAT_1edf35940,&DAT_1e223f348);
  }
  if (lVar1 == DAT_1edf35d20) {
    uVar3 = *(undefined8 *)(param_7 + 0x18);
    lVar1 = FUN_183b83418(param_7);
    if (lVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined8 *)(lVar1 + 0x28);
    }
    lVar1 = _CGShadingCreateRadialInternal
                      (param_1,param_2,param_3,param_4,param_5,param_6,uVar3,0,0,uVar2,lVar1,param_8
                       ,param_9);
    if (lVar1 != 0) {
      uVar4 = FUN_183b83548(param_7);
      *(undefined4 *)(lVar1 + 0x60) = uVar4;
    }
  }
  else {
    lVar1 = 0;
  }
  return lVar1;
}



/* ==== _shading_equal @ 183e18ebc size=20 ==== */

bool _shading_equal(long param_1,long param_2)

{
  return *(int *)(param_1 + 0x10) == *(int *)(param_2 + 0x10);
}



/* ==== _shading_hash @ 183e18ed0 size=8 ==== */

undefined4 _shading_hash(long param_1)

{
  return *(undefined4 *)(param_1 + 0x10);
}



/* ==== _CGPDFShadingCreateShadingFunction @ 183e7f19c size=556 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _CGPDFShadingCreateShadingFunction(long param_1,long param_2)

{
  code *pcVar1;
  long *plVar2;
  ulong uVar3;
  long lVar4;
  char *pcVar5;
  double *pdVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  ulong unaff_x30;
  double dVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  long local_78;
  double local_70;
  double dStack_68;
  double local_60;
  double dStack_58;
  long local_48;
  
  local_48 = *_DAT_1e0186220;
  local_78 = param_1;
  if ((param_1 == 0) || (*(int *)(param_1 + 8) != 7)) {
    if (*_DAT_1e0186220 == local_48) {
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
        FUN_183ca31ac();
        return;
      }
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xc471,0x183e7f36c);
      (*pcVar1)();
    }
    goto LAB_183e7f3c4;
  }
  lVar8 = *(long *)(param_1 + 0x20);
  if ((lVar8 == 0) || (lVar7 = *(long *)(lVar8 + 0x18) - *(long *)(lVar8 + 0x10), lVar7 == 0)) {
LAB_183e7f390:
    param_1 = 0;
  }
  else {
    plVar2 = (long *)func_0x000188138460(1,lVar7 + 8,0x100004000313f17);
    func_0x000188142e40(plVar2,"CGPDFNamedAlloc_Graphics");
    if (plVar2 == (long *)0x0) goto LAB_183e7f390;
    lVar9 = 0;
    lVar7 = lVar7 >> 3;
    *plVar2 = lVar7;
    do {
      uVar3 = FUN_183bcfb04(lVar8,lVar9,&local_78);
      if ((uVar3 & 1) == 0) goto LAB_183e7f388;
      lVar4 = FUN_183ca31ac(local_78);
      plVar2[lVar9 + 1] = lVar4;
      if (lVar4 == 0) goto LAB_183e7f388;
      if (*(long *)(lVar4 + 0x20) != param_2) {
        pcVar5 = "invalid shading function domain dimension.";
LAB_183e7f384:
        _pdf_error(pcVar5);
        goto LAB_183e7f388;
      }
      if (*(long *)(lVar4 + 0x30) != 1) {
        pcVar5 = "invalid shading function range dimension.";
        goto LAB_183e7f384;
      }
      lVar9 = lVar9 + 1;
    } while (lVar7 != lVar9);
    lVar8 = 0;
    local_60 = 1.79769313486232e+308;
    dStack_58 = -1.79769313486232e+308;
    dStack_68 = -1.79769313486232e+308;
    local_70 = 1.79769313486232e+308;
    dVar10 = -1.79769313486232e+308;
    lVar9 = lVar7;
    dVar11 = 1.79769313486232e+308;
    dVar14 = -1.79769313486232e+308;
    dVar12 = 1.79769313486232e+308;
    do {
      pdVar6 = *(double **)(plVar2[lVar8 + 1] + 0x28);
      dVar13 = *pdVar6;
      dVar15 = pdVar6[1];
      dVar16 = dVar13;
      if (dVar12 <= dVar13) {
        dVar13 = dVar12;
        dVar16 = local_70;
      }
      local_70 = dVar16;
      dVar12 = dVar15;
      if (dVar15 <= dVar14) {
        dVar15 = dVar14;
        dVar12 = dStack_68;
      }
      dStack_68 = dVar12;
      dVar14 = dVar11;
      if (param_2 == 2) {
        dVar14 = pdVar6[2];
        dVar16 = pdVar6[3];
        dVar12 = dVar14;
        if (dVar11 <= dVar14) {
          dVar14 = dVar11;
          dVar12 = local_60;
        }
        local_60 = dVar12;
        if (dVar10 < dVar16) {
          dStack_58 = dVar16;
          dVar10 = dVar16;
        }
      }
      lVar8 = lVar8 + 1;
      lVar9 = lVar9 + -1;
      dVar11 = dVar14;
      dVar14 = dVar15;
      dVar12 = dVar13;
    } while (lVar9 != 0);
    param_1 = FUN_183b8324c(plVar2,param_2,&local_70,lVar7,0,&DAT_1e2238950);
    if (param_1 == 0) {
LAB_183e7f388:
      _shading_function_array_release(plVar2);
      goto LAB_183e7f390;
    }
  }
  if (*_DAT_1e0186220 == local_48) {
    return;
  }
LAB_183e7f3c4:
  func_0x000188138130(param_1);
  return;
}



/* ==== _shading_function_array_evaluate @ 183e7f3c8 size=108 ==== */

void _shading_function_array_evaluate(ulong *param_1,undefined8 param_2,long param_3)

{
  ulong uVar1;
  
  if (*param_1 != 0) {
    uVar1 = 0;
    do {
      FUN_183b7ffbc(param_1[uVar1 + 1],param_2,param_3 + uVar1 * 8);
      uVar1 = uVar1 + 1;
    } while (uVar1 < *param_1);
  }
  return;
}



/* ==== _shading_function_array_release @ 183e7f434 size=104 ==== */

/* WARNING: Control flow encountered bad instruction data */

void _shading_function_array_release(ulong *param_1)

{
  code *pcVar1;
  ulong uVar2;
  ulong uVar3;
  ulong unaff_x30;
  
  uVar2 = *param_1;
  if (uVar2 != 0) {
    uVar3 = 0;
    do {
      if (param_1[uVar3 + 1] != 0) {
        func_0x000188141240();
        uVar2 = *param_1;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar2);
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0x183e7f498);
    (*pcVar1)();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* ==== __ZNK2CG11DisplayList34enumerateShadingResourcesWithBlockEbU13block_pointerFvPKNS_26DisplayListResourceShadingEE @ 183ed8ec8 size=252 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __ZNK2CG11DisplayList34enumerateShadingResourcesWithBlockEbU13block_pointerFvPKNS_26DisplayListResourceShadingEE
               (long param_1,byte param_2,long param_3)

{
  long *plVar1;
  bool bVar2;
  long *plVar3;
  long *plVar4;
  undefined8 local_70;
  undefined8 local_68;
  code *local_60;
  undefined *puStack_58;
  long local_50;
  byte local_48;
  
  plVar3 = *(long **)(param_1 + 0x170);
  while (plVar3 != (long *)(param_1 + 0x178)) {
    (**(code **)(param_3 + 0x10))(param_3,plVar3[4]);
    plVar1 = (long *)plVar3[1];
    plVar4 = plVar3;
    if ((long *)plVar3[1] == (long *)0x0) {
      do {
        plVar3 = (long *)plVar4[2];
        bVar2 = plVar4 != (long *)*plVar3;
        plVar4 = plVar3;
      } while (bVar2);
    }
    else {
      do {
        plVar3 = plVar1;
        plVar1 = (long *)*plVar3;
      } while ((long *)*plVar3 != (long *)0x0);
    }
  }
  if ((param_2 & 1) != 0) {
    local_68 = 0x40000000;
    local_60 = 
    ____ZNK2CG11DisplayList34enumerateShadingResourcesWithBlockEbU13block_pointerFvPKNS_26DisplayListResourceShadingEE_block_invoke
    ;
    puStack_58 = &DAT_1e05aeb98;
    local_70 = _DAT_1e0186208;
    local_50 = param_3;
    local_48 = param_2;
    __ZNK2CG11DisplayList36enumerateDisplayListEntriesWithBlockEU13block_pointerFvPKNS_27DisplayListEntryDisplayListEPKS0_E
              (*(undefined8 *)(param_1 + 0x2a0),*(undefined8 *)(param_1 + 0x2a8),&local_70);
  }
  return;
}



/* ==== ____ZNK2CG11DisplayList34enumerateShadingResourcesWithBlockEbU13block_pointerFvPKNS_26DisplayListResourceShadingEE_block_invoke @ 183edb6ac size=20 ==== */

void ____ZNK2CG11DisplayList34enumerateShadingResourcesWithBlockEbU13block_pointerFvPKNS_26DisplayListResourceShadingEE_block_invoke
               (long param_1,undefined8 param_2,undefined8 param_3)

{
  __ZNK2CG11DisplayList34enumerateShadingResourcesWithBlockEbU13block_pointerFvPKNS_26DisplayListResourceShadingEE
            (param_3,*(undefined1 *)(param_1 + 0x28),*(undefined8 *)(param_1 + 0x20));
  return;
}



/* ==== __ZNSt3__16__treeINS_10shared_ptrIN2CG26DisplayListResourceShadingEEENS2_22CompareResourceShadingENS_9allocatorIS4_EEE21__construct_from_treeB9fqe220106IZNS8_21__copy_construct_treeB9fqe220106EPNS_11__tree_nodeIS4_PvEEEUlRKS4_E_EESD_SD_T_ @ 183edd474 size=188 ==== */

long * __ZNSt3__16__treeINS_10shared_ptrIN2CG26DisplayListResourceShadingEEENS2_22CompareResourceShadingENS_9allocatorIS4_EEE21__construct_from_treeB9fqe220106IZNS8_21__copy_construct_treeB9fqe220106EPNS_11__tree_nodeIS4_PvEEEUlRKS4_E_EESD_SD_T_
                 (undefined8 param_1,undefined8 *param_2)

{
  long *plVar1;
  long lVar2;
  long *plVar3;
  long lVar4;
  
  if (param_2 == (undefined8 *)0x0) {
    plVar3 = (long *)0x0;
  }
  else {
    plVar3 = (long *)func_0x00018814d110(0x30,0x1020c009b2ca512);
    *plVar3 = 0;
    lVar4 = param_2[5];
    lVar2 = param_2[4];
    plVar3[5] = param_2[5];
    plVar3[4] = lVar2;
    lVar2 = 0;
    if (lVar4 != 0) {
      plVar1 = (long *)(lVar4 + 8);
      lVar2 = *plVar1;
      *plVar1 = lVar2 + 1;
    }
    lVar2 = __ZNSt3__16__treeINS_10shared_ptrIN2CG26DisplayListResourceShadingEEENS2_22CompareResourceShadingENS_9allocatorIS4_EEE21__construct_from_treeB9fqe220106IZNS8_21__copy_construct_treeB9fqe220106EPNS_11__tree_nodeIS4_PvEEEUlRKS4_E_EESD_SD_T_
                      (lVar2,param_1,*param_2);
    lVar4 = __ZNSt3__16__treeINS_10shared_ptrIN2CG26DisplayListResourceShadingEEENS2_22CompareResourceShadingENS_9allocatorIS4_EEE21__construct_from_treeB9fqe220106IZNS8_21__copy_construct_treeB9fqe220106EPNS_11__tree_nodeIS4_PvEEEUlRKS4_E_EESD_SD_T_
                      (param_1,param_2[1]);
    *(undefined1 *)(plVar3 + 3) = *(undefined1 *)(param_2 + 3);
    *plVar3 = lVar2;
    plVar3[1] = lVar4;
    if (lVar2 != 0) {
      *(long **)(lVar2 + 0x10) = plVar3;
    }
    if (lVar4 != 0) {
      *(long **)(lVar4 + 0x10) = plVar3;
    }
  }
  return plVar3;
}



/* ==== __ZZNSt3__16__treeINS_10shared_ptrIN2CG26DisplayListResourceShadingEEENS2_22CompareResourceShadingENS_9allocatorIS4_EEE21__emplace_hint_uniqueB9fqe220106IJRPS3_EEENS_4pairINS_15__tree_iteratorIS4_PNS_11__tree_nodeIS4_PvEElEEbEENS_21__tree_const_iteratorIS4_SH_lEEDpOT_ENKUlSB_E_clESB_ @ 183edf72c size=764 ==== */

long * __ZZNSt3__16__treeINS_10shared_ptrIN2CG26DisplayListResourceShadingEEENS2_22CompareResourceShadingENS_9allocatorIS4_EEE21__emplace_hint_uniqueB9fqe220106IJRPS3_EEENS_4pairINS_15__tree_iteratorIS4_PNS_11__tree_nodeIS4_PvEElEEbEENS_21__tree_const_iteratorIS4_SH_lEEDpOT_ENKUlSB_E_clESB_
                 (long *param_1,long *param_2,undefined8 param_3)

{
  long lVar1;
  long lVar2;
  long lVar3;
  bool bVar4;
  long *plVar5;
  long *plVar6;
  long *plVar7;
  long *plVar8;
  long *plVar9;
  undefined1 auVar10 [16];
  
  plVar5 = (long *)func_0x00018814d110(0x30,0x1020c009b2ca512);
  *plVar5 = 0;
  __ZNSt3__110shared_ptrIN2CG26DisplayListResourceShadingEEC2B9fqe220106IS2_Li0EEEPT_
            (plVar5 + 4,param_3);
  plVar7 = param_2;
  if (param_2 == param_1 + 1) {
LAB_183edf7dc:
    plVar8 = param_2;
    if (param_2 != (long *)*param_1) {
      plVar6 = param_2;
      plVar9 = (long *)*param_2;
      if ((long *)*param_2 == (long *)0x0) {
        do {
          plVar8 = (long *)plVar6[2];
          bVar4 = plVar6 == (long *)*plVar8;
          plVar6 = plVar8;
        } while (bVar4);
      }
      else {
        do {
          plVar8 = plVar9;
          plVar9 = (long *)plVar8[1];
        } while ((long *)plVar8[1] != (long *)0x0);
      }
      lVar1 = plVar8[4];
      lVar3 = plVar8[5];
      if (lVar3 != 0) {
        *(long *)(lVar3 + 8) = *(long *)(lVar3 + 8) + 1;
      }
      lVar2 = plVar5[4];
      if (plVar5[5] == 0) {
        bVar4 = *(ulong *)(lVar1 + 0x10) < *(ulong *)(lVar2 + 0x10);
      }
      else {
        plVar6 = (long *)(plVar5[5] + 8);
        *plVar6 = *plVar6 + 1;
        bVar4 = *(ulong *)(lVar1 + 0x10) < *(ulong *)(lVar2 + 0x10);
        __ZNSt3__119__shared_weak_count16__release_sharedB9fqe220106Ev();
      }
      if (lVar3 != 0) {
        __ZNSt3__119__shared_weak_count16__release_sharedB9fqe220106Ev(lVar3);
      }
      if (!bVar4) {
LAB_183edf9cc:
        auVar10 = __ZNSt3__16__treeINS_10shared_ptrIN2CG29DisplayListResourceColorSpaceEEENS2_25CompareResourceColorSpaceENS_9allocatorIS4_EEE12__find_equalB9fqe220106IS4_EENS_4pairIPNS_15__tree_end_nodeIPNS_16__tree_node_baseIPvEEEERSF_EERKT_
                            (param_1,plVar5 + 4);
        plVar6 = auVar10._8_8_;
        plVar7 = auVar10._0_8_;
        goto LAB_183edf9e0;
      }
    }
    plVar6 = param_2;
    if (*param_2 != 0) {
      plVar6 = plVar8 + 1;
      plVar7 = plVar8;
    }
  }
  else {
    lVar1 = plVar5[4];
    lVar3 = plVar5[5];
    if (lVar3 != 0) {
      *(long *)(lVar3 + 8) = *(long *)(lVar3 + 8) + 1;
    }
    lVar2 = param_2[4];
    if (param_2[5] == 0) {
      bVar4 = *(ulong *)(lVar1 + 0x10) < *(ulong *)(lVar2 + 0x10);
      if (lVar3 != 0) goto LAB_183edf7d0;
LAB_183edf818:
      if (bVar4) goto LAB_183edf7dc;
    }
    else {
      plVar8 = (long *)(param_2[5] + 8);
      *plVar8 = *plVar8 + 1;
      bVar4 = *(ulong *)(lVar1 + 0x10) < *(ulong *)(lVar2 + 0x10);
      __ZNSt3__119__shared_weak_count16__release_sharedB9fqe220106Ev();
      if (lVar3 == 0) goto LAB_183edf818;
LAB_183edf7d0:
      __ZNSt3__119__shared_weak_count16__release_sharedB9fqe220106Ev(lVar3);
      if (bVar4) goto LAB_183edf7dc;
    }
    lVar1 = param_2[4];
    lVar3 = param_2[5];
    if (lVar3 != 0) {
      *(long *)(lVar3 + 8) = *(long *)(lVar3 + 8) + 1;
    }
    lVar2 = plVar5[4];
    if (plVar5[5] == 0) {
      bVar4 = *(ulong *)(lVar1 + 0x10) < *(ulong *)(lVar2 + 0x10);
    }
    else {
      plVar8 = (long *)(plVar5[5] + 8);
      *plVar8 = *plVar8 + 1;
      bVar4 = *(ulong *)(lVar1 + 0x10) < *(ulong *)(lVar2 + 0x10);
      __ZNSt3__119__shared_weak_count16__release_sharedB9fqe220106Ev();
    }
    if (lVar3 != 0) {
      __ZNSt3__119__shared_weak_count16__release_sharedB9fqe220106Ev(lVar3);
    }
    if (!bVar4) goto LAB_183edf9e8;
    plVar6 = (long *)param_2[1];
    plVar8 = param_2;
    if (plVar6 == (long *)0x0) {
      do {
        plVar9 = (long *)plVar8[2];
        bVar4 = plVar8 != (long *)*plVar9;
        plVar8 = plVar9;
      } while (bVar4);
    }
    else {
      do {
        plVar9 = plVar6;
        plVar6 = (long *)*plVar9;
      } while ((long *)*plVar9 != (long *)0x0);
    }
    if (plVar9 != param_1 + 1) {
      lVar1 = plVar5[4];
      lVar3 = plVar5[5];
      if (lVar3 != 0) {
        *(long *)(lVar3 + 8) = *(long *)(lVar3 + 8) + 1;
      }
      lVar2 = plVar9[4];
      if (plVar9[5] == 0) {
        bVar4 = *(ulong *)(lVar1 + 0x10) < *(ulong *)(lVar2 + 0x10);
      }
      else {
        plVar8 = (long *)(plVar9[5] + 8);
        *plVar8 = *plVar8 + 1;
        bVar4 = *(ulong *)(lVar1 + 0x10) < *(ulong *)(lVar2 + 0x10);
        __ZNSt3__119__shared_weak_count16__release_sharedB9fqe220106Ev();
      }
      if (lVar3 != 0) {
        __ZNSt3__119__shared_weak_count16__release_sharedB9fqe220106Ev(lVar3);
      }
      if (!bVar4) goto LAB_183edf9cc;
    }
    plVar6 = param_2 + 1;
    if (param_2[1] != 0) {
      plVar6 = plVar9;
      plVar7 = plVar9;
    }
  }
LAB_183edf9e0:
  param_2 = (long *)*plVar6;
  if (param_2 == (long *)0x0) {
    __ZNSt3__16__treeItNS_4lessItEENS_9allocatorItEEE16__insert_node_atEPNS_15__tree_end_nodeIPNS_16__tree_node_baseIPvEEEERSA_SA_
              (param_1,plVar7,plVar6,plVar5);
    return plVar5;
  }
LAB_183edf9e8:
  __ZNSt3__122__tree_node_destructorINS_9allocatorINS_11__tree_nodeINS_10shared_ptrIN2CG29DisplayListResourceColorSpaceEEEPvEEEEEclB9fqe220106EPS8_
            (1,plVar5);
  return param_2;
}



/* ==== __ZNSt3__110shared_ptrIN2CG26DisplayListResourceShadingEEC2B9fqe220106IS2_Li0EEEPT_ @ 183ee0af8 size=104 ==== */

undefined8 *
__ZNSt3__110shared_ptrIN2CG26DisplayListResourceShadingEEC2B9fqe220106IS2_Li0EEEPT_
          (undefined8 *param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  
  *param_1 = param_2;
  puVar1 = (undefined8 *)func_0x00018814d110(0x20,0x10a1c4064a2ae3f);
  *puVar1 = &DAT_1e2231b10;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = param_2;
  param_1[1] = puVar1;
  return param_1;
}



/* ==== __ZNSt3__120__shared_ptr_pointerIPN2CG26DisplayListResourceShadingENS_10shared_ptrIS2_E27__shared_ptr_default_deleteIS2_S2_EENS_9allocatorIS2_EEED1Ev @ 183ee0b90 size=4 ==== */

/* WARNING: Control flow encountered bad instruction data */

void __ZNSt3__120__shared_ptr_pointerIPN2CG26DisplayListResourceShadingENS_10shared_ptrIS2_E27__shared_ptr_default_deleteIS2_S2_EENS_9allocatorIS2_EEED1Ev
               (void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* ==== __ZNSt3__120__shared_ptr_pointerIPN2CG26DisplayListResourceShadingENS_10shared_ptrIS2_E27__shared_ptr_default_deleteIS2_S2_EENS_9allocatorIS2_EEED0Ev @ 183ee0b94 size=56 ==== */

/* WARNING: Control flow encountered bad instruction data */

void __ZNSt3__120__shared_ptr_pointerIPN2CG26DisplayListResourceShadingENS_10shared_ptrIS2_E27__shared_ptr_default_deleteIS2_S2_EENS_9allocatorIS2_EEED0Ev
               (void)

{
  code *pcVar1;
  ulong unaff_x30;
  
  func_0x00018814cf70();
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0x183ee0bc8);
    (*pcVar1)();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* ==== __ZNKSt3__120__shared_ptr_pointerIPN2CG26DisplayListResourceShadingENS_10shared_ptrIS2_E27__shared_ptr_default_deleteIS2_S2_EENS_9allocatorIS2_EEE13__get_deleterERKSt9type_info @ 183ee0bcc size=100 ==== */

/* WARNING: Removing unreachable block (ram,0x000183ee0c0c) */
/* WARNING: Removing unreachable block (ram,0x000183ee0c20) */

long __ZNKSt3__120__shared_ptr_pointerIPN2CG26DisplayListResourceShadingENS_10shared_ptrIS2_E27__shared_ptr_default_deleteIS2_S2_EENS_9allocatorIS2_EEE13__get_deleterERKSt9type_info
               (long param_1,long param_2)

{
  if (*(char **)(param_2 + 8) ==
      "NSt3__110shared_ptrIN2CG26DisplayListResourceShadingEE27__shared_ptr_default_deleteIS2_S2_EE"
     ) {
    param_1 = param_1 + 0x18;
  }
  else {
    param_1 = 0;
  }
  return param_1;
}



/* ==== __ZNSt3__16__treeINS_12__value_typeIN10applesauce2CF9ObjectRefIP9CGShadingEENS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEEENS_19__map_value_compareIS7_NS_4pairIKS7_SD_EEN23PDFContentStreamBuilder19ObjectRefComparatorIS6_EEEENSB_ISI_EEE14__tree_deleterclB9fqe220106EPNS_11__tree_nodeISE_PvEE @ 183eeb1c8 size=92 ==== */

void __ZNSt3__16__treeINS_12__value_typeIN10applesauce2CF9ObjectRefIP9CGShadingEENS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEEENS_19__map_value_compareIS7_NS_4pairIKS7_SD_EEN23PDFContentStreamBuilder19ObjectRefComparatorIS6_EEEENSB_ISI_EEE14__tree_deleterclB9fqe220106EPNS_11__tree_nodeISE_PvEE
               (undefined8 *param_1)

{
  undefined8 *puVar1;
  
  while (param_1 != (undefined8 *)0x0) {
    __ZNSt3__16__treeINS_12__value_typeIN10applesauce2CF9ObjectRefIP9CGShadingEENS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEEENS_19__map_value_compareIS7_NS_4pairIKS7_SD_EEN23PDFContentStreamBuilder19ObjectRefComparatorIS6_EEEENSB_ISI_EEE14__tree_deleterclB9fqe220106EPNS_11__tree_nodeISE_PvEE
              (*param_1);
    puVar1 = (undefined8 *)param_1[1];
    if (*(char *)((long)param_1 + 0x3f) < '\0') {
      func_0x00018814d0d0(param_1[5]);
    }
    if (param_1[4] != 0) {
      func_0x000188141240();
    }
    func_0x00018814d0d0(param_1);
    param_1 = puVar1;
  }
  return;
}



/* ==== _CGPDFShadingCreateWithObject @ 183eed21c size=764 ==== */

long _CGPDFShadingCreateWithObject(long param_1)

{
  byte bVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  ulong uVar5;
  long lVar6;
  char *pcVar7;
  long lVar8;
  code *pcVar9;
  char local_41;
  undefined8 local_40;
  ulong local_38;
  
  if (param_1 == 0) {
    return 0;
  }
  lVar3 = _CGPDFObjectCopyAssociation(param_1,"Shading");
  if (lVar3 != 0) {
    return lVar3;
  }
  if (DAT_1eb056d28 != -1) {
    func_0x00018813aad0(&DAT_1eb056d28,&DAT_1e223f938);
  }
  lVar3 = _pdf_create_cftype(DAT_1eb056d30,0x88);
  if (lVar3 == 0) {
    return 0;
  }
  local_40 = 0;
  local_38 = 0;
  local_41 = '\0';
  if (*(int *)(param_1 + 8) == 9) {
    lVar8 = *(long *)(param_1 + 0x20);
    if (lVar8 == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = *(undefined8 *)(lVar8 + 0x30);
    }
LAB_183eed2bc:
    *(undefined8 *)(lVar3 + 0x18) = uVar4;
    *(long *)(lVar3 + 0x20) = lVar8;
    uVar5 = FUN_183bcf4b0(uVar4,"ColorSpace",&local_40);
    if ((uVar5 & 1) == 0) {
      pcVar7 = "missing or invalid shading `ColorSpace\' value.";
    }
    else {
      lVar8 = FUN_183bd8754(local_40);
      *(long *)(lVar3 + 0x28) = lVar8;
      if (lVar8 == 0) goto LAB_183eed338;
      lVar6 = func_0x000188140d60();
      if (DAT_1edf367a0 != -1) {
        func_0x00018813aad0(&DAT_1edf367a0,&DAT_1e22309c8);
      }
      if ((lVar6 == DAT_1edf36a20) && (*(int *)(*(long *)(lVar8 + 0x18) + 0x18) == 9)) {
        pcVar7 = "invalid shading `ColorSpace\' value.";
      }
      else {
        *(undefined8 *)(lVar3 + 0x30) = 0;
        if (*(long *)(lVar3 + 0x28) == 0) {
          lVar8 = 0;
        }
        else {
          lVar8 = *(long *)(*(long *)(*(long *)(lVar3 + 0x28) + 0x18) + 0x30);
        }
        lVar6 = func_0x000188138470(lVar8 * 8 + 8,0x100004000313f17);
        if (lVar6 == 0) goto LAB_183eed338;
        iVar2 = FUN_183bd5f94(*(undefined8 *)(lVar3 + 0x18),"Background",lVar6,lVar8);
        if (iVar2 != 0) {
          *(undefined8 *)(lVar6 + lVar8 * 8) = 0x3ff0000000000000;
          uVar4 = _CGColorCreateWithContentHeadroomAndComponents
                            (0,*(undefined8 *)(lVar3 + 0x28),lVar6);
          *(undefined8 *)(lVar3 + 0x30) = uVar4;
        }
        func_0x000188138390(lVar6);
        bVar1 = FUN_183bdeec8(*(undefined8 *)(lVar3 + 0x18),"BBox",lVar3 + 0x40);
        *(byte *)(lVar3 + 0x39) = bVar1;
        if ((bVar1 & 1) == 0) {
          *(undefined8 *)(lVar3 + 0x48) = 0xffdfffffffffffff;
          *(undefined8 *)(lVar3 + 0x40) = 0xffdfffffffffffff;
          *(undefined8 *)(lVar3 + 0x58) = 0x7fefffffffffffff;
          *(undefined8 *)(lVar3 + 0x50) = 0x7fefffffffffffff;
        }
        *(undefined1 *)(lVar3 + 0x38) = 0;
        uVar5 = FUN_183bdf1c8(*(undefined8 *)(lVar3 + 0x18),"AntiAlias",&local_41);
        if ((uVar5 & 1) == 0) {
          *(bool *)(lVar3 + 0x38) = local_41 != '\0';
        }
        uVar5 = FUN_183bd6c4c(*(undefined8 *)(lVar3 + 0x18),"ShadingType",&local_38);
        if ((uVar5 & 1) == 0) {
          pcVar7 = "missing or invalid shading `ShadingType\' value.";
        }
        else if (local_38 - 8 < 0xfffffffffffffff9) {
          pcVar7 = "invalid shading `ShadingType\' value.";
        }
        else if (local_38 < 4) {
          if (*(long *)(lVar3 + 0x20) == 0) {
LAB_183eed48c:
            pcVar9 = *(code **)(&DAT_1e223f958 + (local_38 - 1) * 8);
            *(int *)(lVar3 + 0x10) = (int)(local_38 - 1) + 1;
            uVar5 = (*pcVar9)(lVar3,lVar3 + 0x60,lVar3 + 0x68);
            if ((uVar5 & 1) != 0) {
              *(undefined4 *)(lVar3 + 0x80) = 0;
              lVar3 = _CGPDFObjectSetAssociation(param_1,lVar3,"Shading");
              return lVar3;
            }
            goto LAB_183eed338;
          }
          pcVar7 = "invalid shading object: not a dictionary.";
        }
        else {
          if (*(long *)(lVar3 + 0x20) != 0) goto LAB_183eed48c;
          pcVar7 = "invalid shading object: not a stream.";
        }
      }
    }
  }
  else {
    if (*(int *)(param_1 + 8) == 8) {
      lVar8 = 0;
      uVar4 = *(undefined8 *)(param_1 + 0x20);
      goto LAB_183eed2bc;
    }
    pcVar7 = "invalid shading: not a dictionary or stream.";
  }
  _pdf_error(pcVar7);
LAB_183eed338:
  func_0x000188141240(lVar3);
  return 0;
}



/* ==== _CGPDFShadingGetShading @ 183eed518 size=108 ==== */

long _CGPDFShadingGetShading(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_1 + 0x78);
  if (lVar1 == 0) {
    if (*(long *)(param_1 + 0x68) == 0) {
      lVar1 = 0;
    }
    else {
      func_0x00018813b710(param_1 + 0x80);
      if ((*(long *)(param_1 + 0x78) == 0) && (*(code **)(param_1 + 0x68) != (code *)0x0)) {
        uVar2 = (**(code **)(param_1 + 0x68))(param_1,*(undefined8 *)(param_1 + 0x60));
        *(undefined8 *)(param_1 + 0x78) = uVar2;
      }
      func_0x000188138580(param_1 + 0x80);
      lVar1 = *(long *)(param_1 + 0x78);
    }
  }
  return lVar1;
}



/* ==== _CGPDFShadingFinalize @ 183eed584 size=196 ==== */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Possible PIC construction at 0x000183eed5b8: Changing call to branch */
/* WARNING: Possible PIC construction at 0x000183eed5f4: Changing call to branch */

void _CGPDFShadingFinalize(long param_1)

{
  code *pcVar1;
  long lVar2;
  ulong unaff_x30;
  
  if (*(code **)(param_1 + 0x70) != (code *)0x0) {
    (**(code **)(param_1 + 0x70))(param_1,*(undefined8 *)(param_1 + 0x60));
  }
  if (*(long *)(param_1 + 0x30) == 0) {
    if (*(long *)(param_1 + 0x28) != 0) {
      lVar2 = func_0x000188140d60(*(long *)(param_1 + 0x28));
      if (DAT_1edf367a0 != -1) {
        func_0x00018813aad0(&DAT_1edf367a0,&DAT_1e22309c8);
      }
      if (lVar2 == DAT_1edf36a20) {
        halt_baddata();
      }
    }
    if (*(long *)(param_1 + 0x78) == 0) {
      return;
    }
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xc471,0x183eed61c);
      (*pcVar1)();
    }
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* ==== ___CGPDFShadingGetTypeID_block_invoke @ 183eed648 size=40 ==== */

void ___CGPDFShadingGetTypeID_block_invoke(void)

{
  DAT_1eb056d30 = _pdf_register_cftype(&DAT_1e22388f0);
  return;
}



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



/* ==== _type1_create_shading @ 183f0186c size=220 ==== */

void _type1_create_shading(long param_1,long param_2)

{
  bool bVar1;
  bool bVar2;
  undefined8 uVar3;
  double *pdVar4;
  double *pdVar5;
  double *pdVar6;
  double *pdVar7;
  undefined8 uVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  double local_60;
  double dStack_58;
  double local_50;
  double dStack_48;
  
  if (param_1 == 0) {
    uVar8 = 0;
    pdVar5 = (double *)&DAT_1841d77d8;
    pdVar4 = (double *)&DAT_1841d77f0;
    pdVar6 = (double *)&DAT_1841d77e0;
    pdVar7 = (double *)&DAT_1841d77e8;
    uVar3 = 0;
  }
  else {
    uVar8 = *(undefined8 *)(param_1 + 0x28);
    uVar3 = *(undefined8 *)(param_1 + 0x30);
    pdVar5 = (double *)(param_1 + 0x40);
    pdVar6 = (double *)(param_1 + 0x48);
    pdVar7 = (double *)(param_1 + 0x50);
    pdVar4 = (double *)(param_1 + 0x58);
  }
  dVar9 = *pdVar4;
  dVar10 = *pdVar5;
  dVar11 = *pdVar6;
  dVar12 = *pdVar7;
  local_60 = dVar10;
  dStack_58 = dVar11;
  local_50 = dVar12;
  dStack_48 = dVar9;
  uVar3 = FUN_183b343f4(uVar3);
  bVar1 = false;
  if ((dVar9 == 1.79769313486232e+308) && (bVar1 = false, !NAN(dVar12))) {
    bVar1 = dVar12 == 1.79769313486232e+308;
  }
  bVar2 = false;
  if ((bVar1) && (bVar2 = false, !NAN(dVar11))) {
    bVar2 = dVar11 == -8.988465674311579e+307;
  }
  bVar1 = false;
  if ((bVar2) && (bVar1 = false, !NAN(dVar10))) {
    bVar1 = dVar10 == -8.988465674311579e+307;
  }
  pdVar5 = (double *)0x0;
  if (!bVar1) {
    pdVar5 = &local_60;
  }
  uStack_88 = *(undefined8 *)(param_2 + 0x28);
  local_90 = *(undefined8 *)(param_2 + 0x20);
  uStack_78 = *(undefined8 *)(param_2 + 0x38);
  uStack_80 = *(undefined8 *)(param_2 + 0x30);
  uStack_68 = *(undefined8 *)(param_2 + 0x48);
  local_70 = *(undefined8 *)(param_2 + 0x40);
  FUN_183e18cc4(uVar8,uVar3,pdVar5,param_2,&local_90,*(undefined8 *)(param_2 + 0x50));
  return;
}



/* ==== _pdf_DrawShading @ 183f04ad8 size=372 ==== */

undefined8 _pdf_DrawShading(long param_1,long param_2,undefined8 param_3,long param_4)

{
  int iVar1;
  int *piVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  
  lVar4 = *(long *)(*(long *)(param_1 + 0x128) + 0x208);
  if ((lVar4 != 0) && (lVar5 = *(long *)(lVar4 + 0x48), lVar5 != 0)) {
    piVar2 = (int *)FUN_183bb4860(param_2);
    *(undefined1 *)((long)piVar2 + 0x51) = 1;
    piVar2[0x12] = 3;
    piVar2[0x13] = 3;
    uVar3 = _copyGState(lVar4,param_3);
    if (*(int *)(lVar5 + 0x10) == 0x43545854) {
      lVar4 = *(long *)(lVar5 + 0x28);
      if ((lVar4 != 0) && (*(code **)(lVar4 + 0x60) != (code *)0x0)) {
        (**(code **)(lVar4 + 0x60))(lVar4,piVar2,uVar3,param_4);
      }
    }
    else {
      _handle_invalid_context("CGContextGetDelegate",lVar5);
    }
    iVar1 = *piVar2;
    *piVar2 = iVar1 + -1;
    if (iVar1 == 1) {
      func_0x000188138390(piVar2);
    }
    FUN_183b21200(uVar3);
  }
  if (*(uint *)(param_4 + 0x14) < 5 && (1 << (ulong)(*(uint *)(param_4 + 0x14) & 0x1f) & 0x16U) != 0
     ) {
    lVar4 = _PDFDocumentGetContentStream(*(undefined8 *)(param_1 + 0x128));
    if (lVar4 == 0) {
      return 1000;
    }
    uVar6 = *(undefined8 *)(param_2 + 0x20);
    uVar3 = *(undefined8 *)(param_2 + 0x18);
    uVar7 = *(undefined8 *)(param_2 + 0x28);
    uVar9 = *(undefined8 *)(param_2 + 0x40);
    uVar8 = *(undefined8 *)(param_2 + 0x38);
    *(undefined8 *)(lVar4 + 0x150) = *(undefined8 *)(param_2 + 0x30);
    *(undefined8 *)(lVar4 + 0x148) = uVar7;
    *(undefined8 *)(lVar4 + 0x160) = uVar9;
    *(undefined8 *)(lVar4 + 0x158) = uVar8;
    *(undefined8 *)(lVar4 + 0x140) = uVar6;
    *(undefined8 *)(lVar4 + 0x138) = uVar3;
    _PDFContentStreamSetRedactionPath(lVar4,*(undefined8 *)(*(long *)(param_1 + 0x128) + 0x210));
    _PDFContentStreamDrawShading(lVar4,param_3,param_4);
  }
  else {
    FUN_183e18f08(param_4,param_1,param_2,param_3);
  }
  return 0;
}



/* ==== _draw_shading @ 183f26cc4 size=16 ==== */

void _draw_shading(undefined8 param_1,undefined8 param_2)

{
  FUN_183b835c0(param_2,param_1);
  return;
}



/* ==== _release_shading @ 183f26cd4 size=12 ==== */

/* WARNING: Control flow encountered bad instruction data */

void _release_shading(long param_1)

{
  if (param_1 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return;
}



/* ==== __ZN22CGPDFContentStreamImpl10getShadingEPKc @ 183f3384c size=1400 ==== */

long __ZN22CGPDFContentStreamImpl10getShadingEPKc(long param_1,char *param_2)

{
  undefined8 *******pppppppuVar1;
  undefined8 ******ppppppuVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  char *pcVar6;
  ulong uVar7;
  char cVar8;
  undefined8 *puVar9;
  char *pcVar10;
  long *plVar11;
  long *plVar12;
  long *plVar13;
  long *plVar14;
  long lVar15;
  bool bVar16;
  char *pcVar17;
  long *plVar18;
  char *pcVar19;
  char *pcVar20;
  float fVar21;
  undefined8 ******local_78;
  long lStack_70;
  undefined7 local_68;
  char cStack_61;
  
  if ((param_2 == (char *)0x0) || (cVar8 = *param_2, cVar8 == '\0')) {
    return 0;
  }
  do {
    pcVar19 = "Shading";
    lVar15 = *(long *)(param_1 + 0x18);
    if (lVar15 != 0) {
      lVar3 = func_0x0001881386f0(param_2);
      lVar4 = __ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE22__init_internal_bufferB9fqe220106Em
                        (&local_78,lVar3);
      func_0x0001881384e0(lVar4,param_2,lVar3);
      *(undefined1 *)(lVar4 + lVar3) = 0;
      func_0x00018814cf00(lVar15 + 0x378);
      plVar12 = (long *)(lVar15 + 0x420);
      lVar3 = __ZNSt3__112__hash_tableINS_17__hash_value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEN10applesauce2CF9ObjectRefIP9CGPDFFontEEEENS_22__unordered_map_hasherIS7_NS_4pairIKS7_SD_EENS_4hashIS7_EENS_8equal_toIvEEEENS_21__unordered_map_equalIS7_SI_SM_SK_EENS5_ISI_EEE4findIS7_EENS_15__hash_iteratorIPNS_11__hash_nodeISE_PvEEEERKT_
                        (plVar12,&local_78);
      if (lVar3 == 0) {
        lVar4 = 0;
      }
      else {
        lVar4 = *(long *)(lVar3 + 0x28);
        if (lVar4 != 0) {
          func_0x000188141250(lVar4);
        }
      }
      func_0x00018814cf10(lVar15 + 0x378);
      if (lVar3 == 0) {
        func_0x00018814cf20(lVar15 + 0x378);
        lVar3 = __ZNSt3__112__hash_tableINS_17__hash_value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEN10applesauce2CF9ObjectRefIP9CGPDFFontEEEENS_22__unordered_map_hasherIS7_NS_4pairIKS7_SD_EENS_4hashIS7_EENS_8equal_toIvEEEENS_21__unordered_map_equalIS7_SI_SM_SK_EENS5_ISI_EEE4findIS7_EENS_15__hash_iteratorIPNS_11__hash_nodeISE_PvEEEERKT_
                          (plVar12,&local_78);
        if (lVar3 == 0) {
          __ZN18CGPDFResourcesImpl11getResourceEPKcS1_(lVar15 + 0x10,"Shading",param_2);
          lVar5 = _CGPDFShadingCreateWithObject();
          cVar8 = cStack_61;
          lVar3 = lStack_70;
          ppppppuVar2 = local_78;
          if (lVar5 == 0) {
            lVar4 = 0;
          }
          else {
            pppppppuVar1 = (undefined8 *******)local_78;
            if (-1 < (long)cStack_61) {
              pppppppuVar1 = &local_78;
            }
            lVar4 = lStack_70;
            if (-1 < cStack_61) {
              lVar4 = (long)cStack_61;
            }
            pcVar6 = (char *)__ZNKSt3__121__murmur2_or_cityhashImLm64EEclB9fqe220106EPKvm
                                       (pppppppuVar1,lVar4);
            pcVar20 = *(char **)(lVar15 + 0x428);
            if (pcVar20 != (char *)0x0) {
              pcVar17 = pcVar20 + -1;
              if (((ulong)pcVar20 & (ulong)pcVar17) == 0) {
                pcVar19 = (char *)((ulong)pcVar17 & (ulong)pcVar6);
              }
              else {
                pcVar19 = pcVar6;
                if (pcVar20 <= pcVar6) {
                  uVar7 = 0;
                  if (pcVar20 != (char *)0x0) {
                    uVar7 = (ulong)pcVar6 / (ulong)pcVar20;
                  }
                  pcVar19 = pcVar6 + -(uVar7 * (long)pcVar20);
                }
              }
              puVar9 = *(undefined8 **)(*plVar12 + (long)pcVar19 * 8);
              if (puVar9 != (undefined8 *)0x0) {
                for (plVar18 = (long *)*puVar9; plVar18 != (long *)0x0; plVar18 = (long *)*plVar18)
                {
                  pcVar10 = (char *)plVar18[1];
                  if (pcVar10 == pcVar6) {
                    uVar7 = __ZNKSt3__18equal_toIvEclB9fqe220106IRKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEESA_EEDTeqclsr3stdE7forwardIT_Efp_Eclsr3stdE7forwardIT0_Efp0_EEOSB_OSC_
                                      (plVar18 + 2,&local_78);
                    if ((uVar7 & 1) != 0) goto LAB_183f33d30;
                  }
                  else {
                    if (((ulong)pcVar20 & (ulong)pcVar17) == 0) {
                      pcVar10 = (char *)((ulong)pcVar10 & (ulong)pcVar17);
                    }
                    else if (pcVar20 <= pcVar10) {
                      uVar7 = 0;
                      if (pcVar20 != (char *)0x0) {
                        uVar7 = (ulong)pcVar10 / (ulong)pcVar20;
                      }
                      pcVar10 = pcVar10 + -(uVar7 * (long)pcVar20);
                    }
                    if (pcVar10 != pcVar19) break;
                  }
                }
              }
            }
            plVar18 = (long *)func_0x00018814d110(0x30,0x1032c0080936f94);
            *plVar18 = 0;
            plVar18[1] = (long)pcVar6;
            if (cVar8 < '\0') {
              __ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE25__init_copy_ctor_externalEPKcm
                        (plVar18 + 2,ppppppuVar2,lVar3);
            }
            else {
              plVar18[3] = lStack_70;
              plVar18[2] = (long)local_78;
              plVar18[4] = CONCAT17(cStack_61,local_68);
            }
            fVar21 = (float)(*(long *)(lVar15 + 0x438) + 1);
            plVar18[5] = lVar5;
            if (*(float *)(lVar15 + 0x440) * (float)pcVar20 < fVar21) {
              uVar7 = 1;
              if ((char *)0x2 < pcVar20) {
                uVar7 = (ulong)(((ulong)pcVar20 & (ulong)(pcVar20 + -1)) != 0);
              }
              pcVar19 = (char *)(uVar7 | (long)pcVar20 << 1);
              pcVar20 = (char *)(long)(fVar21 / *(float *)(lVar15 + 0x440));
              if (pcVar19 <= pcVar20) {
                pcVar19 = pcVar20;
              }
              if (pcVar19 + -1 == (char *)0x0) {
                pcVar19 = (char *)0x2;
              }
              else if (((ulong)pcVar19 & (ulong)(pcVar19 + -1)) != 0) {
                pcVar19 = (char *)func_0x0001881457f0(pcVar19);
              }
              pcVar20 = *(char **)(lVar15 + 0x428);
              if (pcVar20 < pcVar19) {
LAB_183f33af0:
                if ((ulong)pcVar19 >> 0x3d != 0) {
                    /* WARNING: Subroutine does not return */
                  __ZSt28__throw_bad_array_new_lengthB9nqe220106v();
                }
                lVar3 = func_0x00018814d110((long)pcVar19 << 3,0x20c0093837f09);
                bVar16 = false;
                pcVar20 = pcVar19;
LAB_183f33b14:
                lVar4 = *plVar12;
                *plVar12 = lVar3;
                if (lVar4 != 0) {
                  func_0x00018814d0d0(lVar4);
                }
                *(char **)(lVar15 + 0x428) = pcVar20;
                if (!bVar16) {
                  lVar3 = *(long *)(lVar15 + 0x420);
                  func_0x0001881382e0(lVar3,(long)pcVar20 << 3);
                  plVar11 = *(long **)(lVar15 + 0x430);
                  if (plVar11 != (long *)0x0) {
                    pcVar19 = (char *)plVar11[1];
                    pcVar17 = pcVar20 + -1;
                    if (((ulong)pcVar20 & (ulong)pcVar17) == 0) {
                      pcVar19 = (char *)((ulong)pcVar19 & (ulong)pcVar17);
                    }
                    else if (pcVar20 <= pcVar19) {
                      uVar7 = 0;
                      if (pcVar20 != (char *)0x0) {
                        uVar7 = (ulong)pcVar19 / (ulong)pcVar20;
                      }
                      pcVar19 = pcVar19 + -(uVar7 * (long)pcVar20);
                    }
                    *(long *)(lVar3 + (long)pcVar19 * 8) = lVar15 + 0x430;
                    plVar13 = (long *)*plVar11;
                    while (plVar13 != (long *)0x0) {
                      pcVar10 = (char *)plVar13[1];
                      if (((ulong)pcVar20 & (ulong)pcVar17) == 0) {
                        pcVar10 = (char *)((ulong)pcVar10 & (ulong)pcVar17);
                      }
                      else if (pcVar20 <= pcVar10) {
                        uVar7 = 0;
                        if (pcVar20 != (char *)0x0) {
                          uVar7 = (ulong)pcVar10 / (ulong)pcVar20;
                        }
                        pcVar10 = pcVar10 + -(uVar7 * (long)pcVar20);
                      }
                      plVar14 = plVar13;
                      if (pcVar10 != pcVar19) {
                        if (*(long *)(lVar3 + (long)pcVar10 * 8) == 0) {
                          *(long **)(lVar3 + (long)pcVar10 * 8) = plVar11;
                          pcVar19 = pcVar10;
                        }
                        else {
                          *plVar11 = *plVar13;
                          *plVar13 = **(undefined8 **)(lVar3 + (long)pcVar10 * 8);
                          **(long **)(lVar3 + (long)pcVar10 * 8) = (long)plVar13;
                          plVar14 = plVar11;
                        }
                      }
                      plVar11 = plVar14;
                      plVar13 = (long *)*plVar14;
                    }
                  }
                }
              }
              else if (pcVar19 < pcVar20) {
                pcVar17 = (char *)(long)((float)*(ulong *)(lVar15 + 0x438) /
                                        *(float *)(lVar15 + 0x440));
                if ((pcVar20 < (char *)0x3) || (((ulong)pcVar20 & (ulong)(pcVar20 + -1)) != 0)) {
                  pcVar17 = (char *)func_0x0001881457f0();
                }
                else if ((char *)0x1 < pcVar17) {
                  pcVar17 = (char *)(1L << (-LZCOUNT(pcVar17 + -1) & 0x3fU));
                }
                if (pcVar19 <= pcVar17) {
                  pcVar19 = pcVar17;
                }
                if (pcVar19 < pcVar20) {
                  if (pcVar19 != (char *)0x0) goto LAB_183f33af0;
                  lVar3 = 0;
                  bVar16 = true;
                  pcVar20 = pcVar19;
                  goto LAB_183f33b14;
                }
                pcVar20 = *(char **)(lVar15 + 0x428);
              }
              if (((ulong)pcVar20 & (ulong)(pcVar20 + -1)) == 0) {
                pcVar19 = (char *)((ulong)(pcVar20 + -1) & (ulong)pcVar6);
              }
              else {
                pcVar19 = pcVar6;
                if (pcVar20 <= pcVar6) {
                  uVar7 = 0;
                  if (pcVar20 != (char *)0x0) {
                    uVar7 = (ulong)pcVar6 / (ulong)pcVar20;
                  }
                  pcVar19 = pcVar6 + -(uVar7 * (long)pcVar20);
                }
              }
            }
            lVar3 = *plVar12;
            plVar12 = *(long **)(lVar3 + (long)pcVar19 * 8);
            if (plVar12 == (long *)0x0) {
              *plVar18 = *(long *)(lVar15 + 0x430);
              *(long **)(lVar15 + 0x430) = plVar18;
              *(long *)(lVar3 + (long)pcVar19 * 8) = lVar15 + 0x430;
              if (*plVar18 != 0) {
                pcVar19 = *(char **)(*plVar18 + 8);
                if (((ulong)pcVar20 & (ulong)(pcVar20 + -1)) == 0) {
                  pcVar19 = (char *)((ulong)pcVar19 & (ulong)(pcVar20 + -1));
                }
                else if (pcVar20 <= pcVar19) {
                  uVar7 = 0;
                  if (pcVar20 != (char *)0x0) {
                    uVar7 = (ulong)pcVar19 / (ulong)pcVar20;
                  }
                  pcVar19 = pcVar19 + -(uVar7 * (long)pcVar20);
                }
                *(long **)(lVar3 + (long)pcVar19 * 8) = plVar18;
              }
            }
            else {
              *plVar18 = *plVar12;
              *plVar12 = (long)plVar18;
            }
            lVar5 = 0;
            *(long *)(lVar15 + 0x438) = *(long *)(lVar15 + 0x438) + 1;
LAB_183f33d30:
            lVar4 = plVar18[5];
            if (lVar4 != 0) {
              func_0x000188141250(lVar4);
            }
            if (lVar5 != 0) {
              func_0x000188141240(lVar5);
            }
          }
        }
        else {
          lVar4 = *(long *)(lVar3 + 0x28);
          if (lVar4 != 0) {
            func_0x000188141250(lVar4);
          }
        }
        func_0x00018814cf30(lVar15 + 0x378);
      }
      if (lVar4 != 0) {
        func_0x000188141240(lVar4);
      }
      if (cStack_61 < '\0') {
        func_0x00018814d0d0(local_78);
      }
      if (lVar4 != 0) {
        return lVar4;
      }
      cVar8 = *param_2;
    }
    lVar15 = *(long *)(param_1 + 0x20);
    param_1 = lVar15 + 0x10;
    if (lVar15 == 0) {
      param_1 = 0;
    }
    if (cVar8 == '\0') {
      return 0;
    }
    if (lVar15 == 0) {
      return 0;
    }
  } while( true );
}



/* ==== _emitShading @ 183f3756c size=28 ==== */

void _emitShading(long param_1,undefined8 param_2)

{
  _PDFDocumentPrintNameReferencePair
            (param_2,"/%N %R",param_1 + 0x20,*(undefined8 *)(param_1 + 0x18));
  return;
}



/* ==== _PDFContentStreamDrawShading @ 183f74b4c size=616 ==== */

void _PDFContentStreamDrawShading(long param_1,long param_2,long param_3)

{
  uint uVar1;
  int iVar2;
  undefined1 auVar3 [16];
  uint uVar4;
  long lVar5;
  undefined8 uVar6;
  char *pcVar7;
  long lVar8;
  long lVar9;
  long lVar10;
  
  if (param_3 == 0) {
    return;
  }
  (**(code **)(*(long *)(param_1 + 0x28) + 0x10))(*(long *)(param_1 + 0x28),param_3);
  _PDFWriterAnnotate(*(undefined8 *)(param_1 + 0xf8),"Drawing shading");
  _PDFGStateSetClipStack(*(undefined8 *)(param_1 + 0x130),*(undefined8 *)(param_2 + 0x70));
  lVar5 = *(long *)(param_1 + 0x130);
  lVar8 = *(long *)(param_2 + 0x78);
  uVar1 = *(uint *)(lVar8 + 4);
  uVar4 = uVar1 << 0xc;
  if ((uVar1 >> 0x14 & 0xf) != 0) {
    uVar4 = uVar1 << 8;
  }
  iVar2 = 2;
  if (uVar4 >> 0x1c != 0) {
    iVar2 = (int)uVar4 >> 0x1c;
  }
  if (*(int *)(lVar5 + 0x48) != iVar2) {
    *(int *)(lVar5 + 0x48) = iVar2;
    _addEmitFunction(lVar5,_emitRenderingIntentChange);
    lVar5 = *(long *)(param_1 + 0x130);
    lVar8 = *(long *)(param_2 + 0x78);
  }
  if (*(double *)(lVar5 + 0xa0) != *(double *)(lVar8 + 8)) {
    *(double *)(lVar5 + 0xa0) = *(double *)(lVar8 + 8);
    _addEmitFunction(lVar5,_emitNonStrokeAlphaChange);
    lVar5 = *(long *)(param_1 + 0x130);
  }
  lVar8 = *(long *)(param_2 + 0x90);
  if (*(char *)(lVar5 + 0xc0) != *(char *)(lVar8 + 0x18)) {
    *(char *)(lVar5 + 0xc0) = *(char *)(lVar8 + 0x18);
    _addEmitFunction(lVar5,_emitNonStrokeOverprintChange);
    lVar5 = *(long *)(param_1 + 0x130);
    lVar8 = *(long *)(param_2 + 0x90);
  }
  _PDFGStateSetOverprintMode(lVar5,*(undefined4 *)(lVar8 + 0x1c));
  _PDFGStateSetBlackGeneration
            (*(undefined8 *)(param_1 + 0x130),*(undefined8 *)(*(long *)(param_2 + 0x90) + 0x20));
  _PDFGStateSetUndercolorRemoval
            (*(undefined8 *)(param_1 + 0x130),*(undefined8 *)(*(long *)(param_2 + 0x90) + 0x28));
  _PDFGStateSetStyle(*(undefined8 *)(param_1 + 0x130),
                     *(undefined8 *)(*(long *)(param_2 + 0x78) + 0x10));
  _PDFGStateSetSoftMask
            (*(undefined8 *)(param_1 + 0x130),*(undefined8 *)(*(long *)(param_2 + 0x78) + 0x28));
  lVar5 = *(long *)(param_1 + 0x130);
  iVar2 = (*(int *)(*(long *)(param_2 + 0x78) + 4) << 0x10) >> 0x18;
  if (0xe < iVar2 - 0xdU) {
    iVar2 = 2;
  }
  if (*(int *)(lVar5 + 0xf0) != iVar2) {
    *(int *)(lVar5 + 0xf0) = iVar2;
    _addEmitFunction(lVar5,_emitBlendModeChange);
    lVar5 = *(long *)(param_1 + 0x130);
  }
  _PDFGStateEmit(lVar5);
  if (*(double *)(param_2 + 0x18) == 1.0) {
    lVar9 = -(ulong)(*(double *)(param_2 + 0x30) == 1.0);
    lVar10 = -(ulong)(*(double *)(param_2 + 0x38) == 0.0);
    lVar5 = -(ulong)(*(double *)(param_2 + 0x20) == 0.0);
    lVar8 = -(ulong)(*(double *)(param_2 + 0x28) == 0.0);
    auVar3[1] = ~(byte)((ulong)lVar5 >> 8);
    auVar3[0] = ~(byte)lVar5;
    auVar3[2] = ~(byte)((ulong)lVar5 >> 0x10);
    auVar3[3] = ~(byte)((ulong)lVar5 >> 0x18);
    auVar3[4] = ~(byte)lVar8;
    auVar3[5] = ~(byte)((ulong)lVar8 >> 8);
    auVar3[6] = ~(byte)((ulong)lVar8 >> 0x10);
    auVar3[7] = ~(byte)((ulong)lVar8 >> 0x18);
    auVar3[8] = ~(byte)lVar9;
    auVar3[9] = ~(byte)((ulong)lVar9 >> 8);
    auVar3[10] = ~(byte)((ulong)lVar9 >> 0x10);
    auVar3[0xb] = ~(byte)((ulong)lVar9 >> 0x18);
    auVar3[0xc] = ~(byte)lVar10;
    auVar3[0xd] = ~(byte)((ulong)lVar10 >> 8);
    auVar3[0xe] = ~(byte)((ulong)lVar10 >> 0x10);
    auVar3[0xf] = ~(byte)((ulong)lVar10 >> 0x18);
    uVar4 = NEON_umaxv(auVar3,4);
    if ((uVar4 & 1) != 0) goto LAB_183f74d64;
    uVar6 = *(undefined8 *)(param_1 + 0xf8);
    if (*(double *)(param_2 + 0x40) == 0.0) {
      pcVar7 = "/%s sh";
      goto LAB_183f74d9c;
    }
  }
  else {
LAB_183f74d64:
    uVar6 = *(undefined8 *)(param_1 + 0xf8);
  }
  _PDFWriterPrintf(uVar6,"q %*m cm");
  _PDFWriterPrintf(*(undefined8 *)(param_1 + 0xf8),"/%s sh");
  uVar6 = *(undefined8 *)(param_1 + 0xf8);
  pcVar7 = "Q";
LAB_183f74d9c:
  _PDFWriterPrintf(uVar6,pcVar7);
  return;
}



/* ==== _emitShadingDefinition @ 183f790ec size=960 ==== */

void _emitShadingDefinition(long param_1,undefined1 *param_2)

{
  double *pdVar1;
  int iVar2;
  double *pdVar3;
  double *pdVar4;
  double *pdVar5;
  bool bVar6;
  bool bVar7;
  long lVar8;
  undefined8 uVar9;
  long lVar10;
  long lVar11;
  long lVar12;
  long lVar13;
  
  if ((((*(byte *)(param_1 + 0x30) & 1) != 0) || (lVar12 = *(long *)(param_1 + 0x10), lVar12 == 0))
     || (3 < *(int *)(lVar12 + 0x14) - 1U)) goto LAB_183f79480;
  _PDFDocumentBeginObject(*(undefined8 *)(param_1 + 8),*(undefined8 *)(param_1 + 0x18));
  _PDFDocumentPrintf(*(undefined8 *)(param_1 + 8),"<<");
  pdVar1 = (double *)&DAT_1841d7848;
  pdVar3 = (double *)&DAT_1841d7830;
  pdVar4 = (double *)&DAT_1841d7838;
  pdVar5 = (double *)&DAT_1841d7840;
  if (*(char *)(lVar12 + 0x28) == '\x01') {
    pdVar1 = (double *)(lVar12 + 0x48);
    pdVar3 = (double *)(lVar12 + 0x30);
    pdVar4 = (double *)(lVar12 + 0x38);
    pdVar5 = (double *)(lVar12 + 0x40);
  }
  bVar6 = false;
  if ((*pdVar3 == -8.988465674311579e+307) && (bVar6 = false, !NAN(*pdVar4))) {
    bVar6 = *pdVar4 == -8.988465674311579e+307;
  }
  bVar7 = false;
  if ((bVar6) && (bVar7 = false, !NAN(*pdVar5))) {
    bVar7 = *pdVar5 == 1.79769313486232e+308;
  }
  bVar6 = false;
  if ((bVar7) && (bVar6 = false, !NAN(*pdVar1))) {
    bVar6 = *pdVar1 == 1.79769313486232e+308;
  }
  if (!bVar6) {
    _PDFDocumentPrintf(*(undefined8 *)(param_1 + 8),"/BBox %r");
  }
  lVar8 = _PDFDocumentResolveColorSpace(*(undefined8 *)(param_1 + 8),*(undefined8 *)(lVar12 + 0x18))
  ;
  uVar9 = _PDFDocumentAddColorSpace(*(undefined8 *)(param_1 + 8),lVar8);
  _PDFDocumentPrintf(*(undefined8 *)(param_1 + 8),"/ColorSpace");
  _PDFColorSpaceEmitReference(uVar9);
  if (lVar8 == 0) {
    lVar8 = 0;
  }
  else {
    lVar8 = *(long *)(*(long *)(lVar8 + 0x18) + 0x30);
  }
  if (*(long *)(lVar12 + 0x20) != 0) {
    _PDFDocumentPrintf(*(undefined8 *)(param_1 + 8),"/Background [");
    for (lVar11 = lVar8; lVar11 != 0; lVar11 = lVar11 + -1) {
      _PDFDocumentPrintf(*(undefined8 *)(param_1 + 8),"%f");
    }
    _PDFDocumentPrintf(*(undefined8 *)(param_1 + 8),"]");
  }
  iVar2 = *(int *)(lVar12 + 0x14);
  if (iVar2 == 1) {
    if ((*(long *)(param_1 + 0x10) != 0) && (*(int *)(*(long *)(param_1 + 0x10) + 0x14) - 1U < 4)) {
      _PDFDocumentPrintf(*(undefined8 *)(param_1 + 8),"/ShadingType 2");
      _PDFDocumentPrintf(*(undefined8 *)(param_1 + 8),"/Coords [ %f %f %f %f ]");
      _PDFDocumentPrintf(*(undefined8 *)(param_1 + 8),"/Domain [ %f %f ]");
      _PDFDocumentPrintf(*(undefined8 *)(param_1 + 8),"/Extend [ %b %b ]");
    }
    lVar11 = 0x40;
LAB_183f79400:
    lVar11 = *(long *)(lVar12 + 0x80 + lVar11);
    if (lVar11 != 0) {
      lVar13 = *(long *)(param_1 + 8);
      lVar10 = *(long *)(lVar13 + 0x198);
      if (lVar10 == 0) {
        lVar10 = _PDFFunctionSetCreate(lVar13);
        *(long *)(lVar13 + 0x198) = lVar10;
      }
      lVar8 = _PDFFunctionSetAddFunctionWithRange(lVar10,lVar11,lVar8 + -1,1);
      if (lVar8 != 0) {
        _PDFDocumentPrintReference
                  (*(undefined8 *)(param_1 + 8),"/Function %R",*(undefined8 *)(lVar8 + 0x30));
      }
    }
  }
  else {
    if (iVar2 == 2) {
      if ((*(long *)(param_1 + 0x10) != 0) && (*(int *)(*(long *)(param_1 + 0x10) + 0x14) - 1U < 4))
      {
        _PDFDocumentPrintf(*(undefined8 *)(param_1 + 8),"/ShadingType 3");
        _PDFDocumentPrintf(*(undefined8 *)(param_1 + 8),"/Coords [ %f %f %f %f %f %f ]");
        _PDFDocumentPrintf(*(undefined8 *)(param_1 + 8),"/Domain [ %f %f ]");
        _PDFDocumentPrintf(*(undefined8 *)(param_1 + 8),"/Extend [ %b %b ]");
      }
      lVar11 = 0x50;
      goto LAB_183f79400;
    }
    if (iVar2 == 4) {
      if ((*(long *)(param_1 + 0x10) != 0) && (*(int *)(*(long *)(param_1 + 0x10) + 0x14) - 1U < 4))
      {
        _PDFDocumentPrintf(*(undefined8 *)(param_1 + 8),"/ShadingType 1");
        _PDFDocumentPrintf(*(undefined8 *)(param_1 + 8),"/Domain [ %f %f %f %f ]");
      }
      lVar11 = 0x20;
      goto LAB_183f79400;
    }
  }
  _PDFDocumentPrintf(*(undefined8 *)(param_1 + 8),">>");
  _PDFDocumentEndObject(*(undefined8 *)(param_1 + 8));
  *(undefined8 *)(param_1 + 0x10) = 0;
  func_0x000188141240(lVar12);
  *(undefined1 *)(param_1 + 0x30) = 1;
LAB_183f79480:
  *param_2 = 1;
  return;
}



/* ==== _shadingRetain @ 183f794ac size=24 ==== */

void _shadingRetain(undefined8 param_1,int *param_2)

{
  if (param_2 != (int *)0x0) {
    *param_2 = *param_2 + 1;
  }
  return;
}



/* ==== _shadingRelease @ 183f794c4 size=8 ==== */

void _shadingRelease(undefined8 param_1,undefined8 param_2)

{
  _PDFShadingRelease(param_2);
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



/* ==== _type6_create_shading @ 183f7e2a0 size=288 ==== */

long _type6_create_shading(long param_1,long param_2)

{
  double *pdVar1;
  double *pdVar2;
  double *pdVar3;
  double *pdVar4;
  bool bVar5;
  bool bVar6;
  undefined8 uVar7;
  long lVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  double local_70;
  double dStack_68;
  double local_60;
  double dStack_58;
  
  pdVar1 = (double *)&DAT_1841d77f0;
  pdVar2 = (double *)&DAT_1841d77d8;
  pdVar3 = (double *)&DAT_1841d77e0;
  pdVar4 = (double *)&DAT_1841d77e8;
  if (param_1 != 0) {
    pdVar1 = (double *)(param_1 + 0x58);
    pdVar2 = (double *)(param_1 + 0x40);
    pdVar3 = (double *)(param_1 + 0x48);
    pdVar4 = (double *)(param_1 + 0x50);
  }
  dVar11 = *pdVar1;
  dVar9 = *pdVar2;
  dVar10 = *pdVar3;
  dVar12 = *pdVar4;
  if (param_1 == 0) {
    lVar8 = 0;
    uVar7 = 0;
  }
  else {
    lVar8 = *(long *)(param_1 + 0x28);
    uVar7 = *(undefined8 *)(param_1 + 0x30);
  }
  local_70 = dVar9;
  dStack_68 = dVar10;
  local_60 = dVar12;
  dStack_58 = dVar11;
  uVar7 = FUN_183b343f4(uVar7);
  bVar5 = false;
  if ((dVar11 == 1.79769313486232e+308) && (bVar5 = false, !NAN(dVar12))) {
    bVar5 = dVar12 == 1.79769313486232e+308;
  }
  bVar6 = false;
  if ((bVar5) && (bVar6 = false, !NAN(dVar10))) {
    bVar6 = dVar10 == -8.988465674311579e+307;
  }
  bVar5 = false;
  if ((bVar6) && (bVar5 = false, !NAN(dVar9))) {
    bVar5 = dVar9 == -8.988465674311579e+307;
  }
  pdVar1 = (double *)(undefined1 *)0x0;
  if (!bVar5) {
    pdVar1 = &local_70;
  }
  if (param_2 == 0) {
    if (lVar8 == 0) {
      return 0;
    }
  }
  else {
    func_0x000188141250(param_2);
    if (lVar8 == 0) {
      return 0;
    }
  }
  lVar8 = _CGShadingCreateEmpty(0,lVar8,uVar7,pdVar1);
  *(long *)(lVar8 + 0x50) = param_2;
  *(undefined8 *)(lVar8 + 0x70) = 0x8010000003f7e4a0;
  *(undefined8 *)(lVar8 + 0x68) = 0;
  *(undefined8 *)(lVar8 + 0x78) = 0x8020000003f81c6c;
  return lVar8;
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



/* ==== _cg_shading_type6_release @ 183f81c6c size=12 ==== */

/* WARNING: Control flow encountered bad instruction data */

void _cg_shading_type6_release(long param_1)

{
  if (param_1 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
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



/* ==== _type4_create_shading @ 183f83610 size=288 ==== */

long _type4_create_shading(long param_1,long param_2)

{
  double *pdVar1;
  double *pdVar2;
  double *pdVar3;
  double *pdVar4;
  bool bVar5;
  bool bVar6;
  undefined8 uVar7;
  long lVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  double local_70;
  double dStack_68;
  double local_60;
  double dStack_58;
  
  pdVar1 = (double *)&DAT_1841d77f0;
  pdVar2 = (double *)&DAT_1841d77d8;
  pdVar3 = (double *)&DAT_1841d77e0;
  pdVar4 = (double *)&DAT_1841d77e8;
  if (param_1 != 0) {
    pdVar1 = (double *)(param_1 + 0x58);
    pdVar2 = (double *)(param_1 + 0x40);
    pdVar3 = (double *)(param_1 + 0x48);
    pdVar4 = (double *)(param_1 + 0x50);
  }
  dVar11 = *pdVar1;
  dVar9 = *pdVar2;
  dVar10 = *pdVar3;
  dVar12 = *pdVar4;
  if (param_1 == 0) {
    lVar8 = 0;
    uVar7 = 0;
  }
  else {
    lVar8 = *(long *)(param_1 + 0x28);
    uVar7 = *(undefined8 *)(param_1 + 0x30);
  }
  local_70 = dVar9;
  dStack_68 = dVar10;
  local_60 = dVar12;
  dStack_58 = dVar11;
  uVar7 = FUN_183b343f4(uVar7);
  bVar5 = false;
  if ((dVar11 == 1.79769313486232e+308) && (bVar5 = false, !NAN(dVar12))) {
    bVar5 = dVar12 == 1.79769313486232e+308;
  }
  bVar6 = false;
  if ((bVar5) && (bVar6 = false, !NAN(dVar10))) {
    bVar6 = dVar10 == -8.988465674311579e+307;
  }
  bVar5 = false;
  if ((bVar6) && (bVar5 = false, !NAN(dVar9))) {
    bVar5 = dVar9 == -8.988465674311579e+307;
  }
  pdVar1 = (double *)(undefined1 *)0x0;
  if (!bVar5) {
    pdVar1 = &local_70;
  }
  if (param_2 == 0) {
    if (lVar8 == 0) {
      return 0;
    }
  }
  else {
    func_0x000188141250(param_2);
    if (lVar8 == 0) {
      return 0;
    }
  }
  lVar8 = _CGShadingCreateEmpty(0,lVar8,uVar7,pdVar1);
  *(long *)(lVar8 + 0x50) = param_2;
  *(undefined8 *)(lVar8 + 0x70) = 0x8010000003f83810;
  *(undefined8 *)(lVar8 + 0x68) = 0;
  *(undefined8 *)(lVar8 + 0x78) = 0x8020000003f83ef0;
  return lVar8;
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



/* ==== _cg_shading_type4_release @ 183f83ef0 size=12 ==== */

/* WARNING: Control flow encountered bad instruction data */

void _cg_shading_type4_release(long param_1)

{
  if (param_1 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
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



/* ==== _type2_create_shading @ 183f927d0 size=248 ==== */

void _type2_create_shading(long param_1,undefined8 *param_2)

{
  double *pdVar1;
  double *pdVar2;
  double *pdVar3;
  double *pdVar4;
  bool bVar5;
  bool bVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  double local_60;
  double dStack_58;
  double local_50;
  double dStack_48;
  
  pdVar1 = (double *)&DAT_1841d77f0;
  pdVar2 = (double *)&DAT_1841d77d8;
  pdVar3 = (double *)&DAT_1841d77e0;
  pdVar4 = (double *)&DAT_1841d77e8;
  if (param_1 != 0) {
    pdVar1 = (double *)(param_1 + 0x58);
    pdVar2 = (double *)(param_1 + 0x40);
    pdVar3 = (double *)(param_1 + 0x48);
    pdVar4 = (double *)(param_1 + 0x50);
  }
  dVar11 = *pdVar1;
  dVar9 = *pdVar2;
  dVar10 = *pdVar3;
  dVar12 = *pdVar4;
  if (param_1 == 0) {
    uVar8 = 0;
    uVar7 = 0;
  }
  else {
    uVar8 = *(undefined8 *)(param_1 + 0x28);
    uVar7 = *(undefined8 *)(param_1 + 0x30);
  }
  local_60 = dVar9;
  dStack_58 = dVar10;
  local_50 = dVar12;
  dStack_48 = dVar11;
  uVar7 = FUN_183b343f4(uVar7);
  bVar5 = false;
  if ((dVar11 == 1.79769313486232e+308) && (bVar5 = false, !NAN(dVar12))) {
    bVar5 = dVar12 == 1.79769313486232e+308;
  }
  bVar6 = false;
  if ((bVar5) && (bVar6 = false, !NAN(dVar10))) {
    bVar6 = dVar10 == -8.988465674311579e+307;
  }
  bVar5 = false;
  if ((bVar6) && (bVar5 = false, !NAN(dVar9))) {
    bVar5 = dVar9 == -8.988465674311579e+307;
  }
  pdVar1 = (double *)(undefined1 *)0x0;
  if (!bVar5) {
    pdVar1 = &local_60;
  }
  _CGShadingCreateAxialInternal
            (*param_2,param_2[1],param_2[2],param_2[3],uVar8,uVar7,pdVar1,param_2 + 4,param_2[6],
             *(char *)(param_2 + 7) != '\0',*(char *)((long)param_2 + 0x39) != '\0');
  return;
}



/* ==== _filter_DrawShading @ 183f92cb4 size=32 ==== */

undefined8 _filter_DrawShading(long param_1)

{
  undefined8 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = 0;
  if ((param_1 != 0) && (uVar1 = 0, *(long *)(param_1 + 0x10) != 0)) {
    UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(param_1 + 0x10) + 0x60);
    if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000183f92cc8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar1 = (*UNRECOVERED_JUMPTABLE)();
      return uVar1;
    }
    uVar1 = 0x3ee;
  }
  return uVar1;
}



/* ==== _CGPDFNodeDrawShadingInContext @ 184000c30 size=1240 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong _CGPDFNodeDrawShadingInContext
                (long param_1,undefined8 param_2,undefined8 param_3,ulong param_4,double *param_5,
                int param_6)

{
  undefined8 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  ulong uVar5;
  long lVar6;
  long lVar7;
  undefined1 uVar8;
  uint uVar9;
  undefined4 uVar10;
  long lVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  char local_f1;
  undefined8 local_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  long local_c8;
  double local_c0 [4];
  double local_a0;
  double dStack_98;
  long local_90;
  
  local_90 = *_DAT_1e0186220;
  if ((param_4 & 0xfffffffffffffffe) == 2) {
    local_d0 = 0;
    iVar2 = FUN_183bcf4b0(param_3,"ColorSpace",&local_d0);
    if ((iVar2 != 0) && (_CreateColorSpaceFromObject(local_d0,&local_c8), local_c8 != 0)) {
      local_d8 = 0;
      iVar2 = FUN_183bcf620(param_3,"BBox",&local_d8);
      uVar1 = local_d8;
      if (iVar2 == 0) {
LAB_184000d64:
        dVar12 = 0.0;
        dVar13 = INFINITY;
        dVar15 = 0.0;
        dVar14 = INFINITY;
      }
      else {
        lVar11 = 0;
        do {
          iVar2 = FUN_183bdf144(uVar1,lVar11,local_c0 + lVar11);
          if (iVar2 == 0) goto LAB_184000d64;
          lVar11 = lVar11 + 1;
        } while (lVar11 != 4);
        dVar12 = local_c0[2] - local_c0[0];
        dVar15 = local_c0[3] - local_c0[1];
        dVar13 = local_c0[1];
        dVar14 = local_c0[0];
      }
      local_e0 = 0;
      iVar2 = FUN_183bcf4b0(param_3,"Function",&local_e0);
      if ((iVar2 == 0) || (lVar11 = FUN_183ca31ac(local_e0), lVar11 == 0)) {
LAB_18400101c:
        uVar5 = 0;
      }
      else {
        local_e8 = 0;
        uVar5 = FUN_183bcf620(param_3,"Coords",&local_e8);
        uVar1 = local_e8;
        if ((uVar5 & 1) == 0) {
          func_0x000188141240(lVar11);
          goto LAB_18400101c;
        }
        uVar5 = 0;
        uVar9 = 4;
        if (param_4 != 2) {
          uVar9 = 6;
        }
        do {
          iVar2 = FUN_183bdf144(uVar1,uVar5,local_c0 + uVar5);
          if (iVar2 == 0) {
            if (uVar9 != (uint)uVar5) {
              func_0x000188141240(lVar11);
              uVar5 = 0;
              goto LAB_184001020;
            }
            break;
          }
          uVar5 = uVar5 + 1;
        } while (uVar9 != uVar5);
        local_f0 = 0;
        iVar2 = FUN_183bcf620(param_3,"Extend",&local_f0);
        uVar1 = local_f0;
        if (iVar2 == 0) {
          uVar10 = 0;
          uVar3 = 0;
        }
        else {
          local_f1 = '\0';
          uVar3 = FUN_183d52830(local_f0,0,&local_f1);
          uVar10 = 0;
          if (local_f1 != '\0') {
            uVar10 = uVar3;
          }
          uVar4 = FUN_183d52830(uVar1,1,&local_f1);
          uVar3 = 0;
          if (local_f1 != '\0') {
            uVar3 = uVar4;
          }
        }
        if (param_4 == 2) {
          lVar6 = _CGShadingCreateAxialInternal
                            (local_c8,0,0,*(undefined8 *)(lVar11 + 0x28),lVar11,uVar10);
        }
        else {
          lVar6 = _CGShadingCreateRadialInternal
                            (local_c0[0],local_c0[1],local_c0[2],local_c0[3],local_a0,dStack_98,
                             local_c8,0,0,*(undefined8 *)(lVar11 + 0x28),lVar11,uVar10,uVar3);
        }
        func_0x000188141240(lVar11);
        if (lVar6 == 0) goto LAB_18400101c;
        lVar11 = FUN_183fff2b0(param_1);
        uVar5 = (ulong)(lVar11 != 0);
        if (lVar11 != 0) {
          FUN_183b30f84(param_2);
          _CGPDFNodeApplyClipToContext(param_1,param_2);
          if ((dVar14 != INFINITY) && (dVar13 != INFINITY)) {
            if (DAT_1edf360f8 != -1) {
              func_0x00018813aad0(&DAT_1edf360f8,&DAT_1e223fd10);
            }
            if (DAT_1edf367d0 != -1) {
              func_0x00018813aad0(&DAT_1edf367d0,&DAT_1e223fd30);
            }
            lVar7 = func_0x000188142730(0,DAT_1edf367d8,0x80,0);
            if (lVar7 == 0) {
              FUN_183b75268("%s: failed to create instance of type %jd.");
            }
            FUN_183be589c(dVar14,dVar13,dVar12,dVar15,lVar7,param_5);
            FUN_183b352bc(param_2,lVar7);
            _clip(param_2,0);
            if (lVar7 != 0) {
              func_0x000188141240(lVar7);
            }
          }
          FUN_183b352bc(param_2,lVar11);
          if (param_6 == 0) {
            uVar8 = *(undefined1 *)(param_1 + 0x88);
          }
          else {
            FUN_183b8bbd0(*(undefined8 *)(param_1 + 0x90),param_2);
            FUN_183b8bab0(param_2,*(undefined4 *)(param_1 + 0xa0));
            FUN_183b8bb84(param_2,*(undefined4 *)(param_1 + 0xa4));
            FUN_183b8dbec(*(undefined8 *)(param_1 + 0x98),param_2);
            FUN_183e93e9c(param_2);
            uVar8 = 0;
          }
          _clip(param_2,uVar8);
          local_c0[1] = param_5[1];
          local_c0[0] = *param_5;
          local_c0[3] = param_5[3];
          local_c0[2] = param_5[2];
          dStack_98 = param_5[5];
          local_a0 = param_5[4];
          FUN_183bf0850(param_2,local_c0);
          FUN_183b835c0(param_2,lVar6);
          FUN_183b537d8(param_2);
          func_0x000188141240(lVar11);
        }
        func_0x000188141240(lVar6);
      }
LAB_184001020:
      lVar11 = func_0x000188140d60(local_c8);
      if (DAT_1edf367a0 != -1) {
        func_0x00018813aad0(&DAT_1edf367a0,&DAT_1e22309c8);
      }
      if (lVar11 == DAT_1edf36a20) {
        func_0x000188141240(local_c8);
      }
      goto LAB_184000d20;
    }
  }
  uVar5 = 0;
LAB_184000d20:
  if (*_DAT_1e0186220 == local_90) {
    return uVar5;
  }
  uVar5 = func_0x000188138130();
  return uVar5;
}



