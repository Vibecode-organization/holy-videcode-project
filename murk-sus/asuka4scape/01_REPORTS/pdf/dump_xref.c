/* ==== _CGPDFXRefStreamRelease @ 183be0a74 size=116 ==== */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Possible PIC construction at 0x000183be0ab0: Changing call to branch */
/* WARNING: Removing unreachable block (ram,0x000183be0ab4) */

void _CGPDFXRefStreamRelease(long param_1)

{
  code *pcVar1;
  long *plVar2;
  ulong unaff_x30;
  
  if (param_1 == 0) {
    return;
  }
  plVar2 = *(long **)(param_1 + 8);
  if (plVar2 != (long *)0x0) {
    do {
      _xref_stream_release(plVar2[1]);
      plVar2 = (long *)*plVar2;
    } while (plVar2 != (long *)0x0);
    if (*(long *)(param_1 + 8) != 0) {
      halt_baddata();
    }
  }
  _pdf_object_scanner_release(*(undefined8 *)(param_1 + 0x10));
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0xc471,0x183be0ae0);
  (*pcVar1)();
}



/* ==== _CGPDFXRefStreamCreate @ 183ced28c size=360 ==== */

undefined8 * _CGPDFXRefStreamCreate(undefined8 param_1,long param_2,int param_3)

{
  long *plVar1;
  int iVar2;
  undefined8 *puVar3;
  long lVar4;
  long *plVar5;
  long *plVar6;
  long *plVar7;
  long lVar8;
  long local_58;
  
  local_58 = param_2;
  puVar3 = (undefined8 *)func_0x000188138460(1,0x20,0x102004016ee4530);
  func_0x000188142e40(puVar3,"CGPDFNamedAlloc_XRef");
  if (puVar3 != (undefined8 *)0x0) {
    *puVar3 = param_1;
    puVar3[3] = param_2;
    lVar4 = _pdf_object_scanner_create_with_xref(param_1,0);
    puVar3[2] = lVar4;
    if (lVar4 != 0) {
      plVar1 = puVar3 + 1;
      while (lVar4 = _xref_stream_create(lVar4,param_2), lVar4 != 0) {
        lVar8 = *plVar1;
        plVar5 = (long *)func_0x000188138460(1,0x10,0xa0040aff93c70);
        *plVar5 = lVar8;
        plVar5[1] = lVar4;
        *plVar1 = (long)plVar5;
        if (param_3 == 0) {
LAB_183ced3cc:
          plVar7 = (long *)0x0;
          do {
            plVar6 = plVar5;
            plVar5 = (long *)*plVar6;
            *plVar6 = (long)plVar7;
            plVar7 = plVar6;
          } while (plVar5 != (long *)0x0);
LAB_183ced3e4:
          *plVar1 = (long)plVar6;
          return puVar3;
        }
        iVar2 = FUN_183bd02e0(*(undefined8 *)(lVar4 + 8),"Prev",&local_58);
        if (iVar2 == 0) {
          plVar5 = (long *)*plVar1;
          if (plVar5 != (long *)0x0) goto LAB_183ced3cc;
          plVar6 = (long *)0x0;
          goto LAB_183ced3e4;
        }
        plVar5 = plVar1;
        if (local_58 == 0) break;
        while (plVar5 = (long *)*plVar5, plVar5 != (long *)0x0) {
          if (*(long *)plVar5[1] == local_58) goto LAB_183ced398;
        }
        lVar4 = puVar3[2];
        param_2 = local_58;
      }
    }
LAB_183ced398:
    _CGPDFXRefStreamRelease(puVar3);
  }
  return (undefined8 *)0x0;
}



/* ==== _CGPDFXRefStreamGetSize @ 183ced85c size=152 ==== */

ulong _CGPDFXRefStreamGetSize(long param_1)

{
  ulong uVar1;
  long *plVar2;
  ulong uVar3;
  long *plVar4;
  long *plVar5;
  ulong uVar6;
  
  if ((param_1 != 0) && (plVar4 = *(long **)(param_1 + 8), plVar4 != (long *)0x0)) {
    uVar3 = 0;
    do {
      if ((plVar4[1] == 0) || (plVar5 = *(long **)(plVar4[1] + 0x10), plVar5 == (long *)0x0)) {
        uVar6 = 0;
      }
      else {
        uVar6 = 0;
        do {
          plVar2 = (long *)*plVar5;
          uVar1 = ((long *)plVar5[1])[1] + *(long *)plVar5[1];
          if ((long)uVar6 <= (long)uVar1) {
            uVar6 = uVar1;
          }
          plVar5 = plVar2;
        } while (plVar2 != (long *)0x0);
      }
      if (uVar3 <= uVar6) {
        uVar3 = uVar6;
      }
      plVar4 = (long *)*plVar4;
    } while (plVar4 != (long *)0x0);
    if (0x989681 < uVar3) {
      _pdf_error("xref stream size too large.");
      uVar3 = 0x989681;
    }
    return uVar3;
  }
  return 0;
}



/* ==== _CGPDFXRefStreamEnumerateObjects @ 183ced8f4 size=180 ==== */

void _CGPDFXRefStreamEnumerateObjects(long *param_1,long param_2)

{
  long lVar1;
  long *plVar2;
  long *plVar3;
  long lVar4;
  
  for (; param_1 != (long *)0x0; param_1 = (long *)*param_1) {
    for (plVar2 = *(long **)(param_1[1] + 0x10); plVar2 != (long *)0x0; plVar2 = (long *)*plVar2) {
      plVar3 = (long *)plVar2[1];
      lVar1 = plVar3[1];
      if (0 < lVar1) {
        lVar4 = 0;
        do {
          if ((*(byte *)((long)plVar3 + lVar4 * 0x18 + 0x22) & 1) != 0) {
            (**(code **)(param_2 + 0x10))(param_2,lVar4 + *plVar3,(short)plVar3[lVar4 * 3 + 4]);
            lVar1 = plVar3[1];
          }
          lVar4 = lVar4 + 1;
        } while (lVar4 < lVar1);
      }
    }
  }
  return;
}



/* ==== _CGPDFXRefStreamGetObject @ 183ced9a8 size=768 ==== */

undefined8
_CGPDFXRefStreamGetObject(long *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  code *pcVar1;
  int iVar2;
  long *plVar3;
  undefined8 uVar4;
  long lVar5;
  long lVar6;
  char *pcVar7;
  long lVar8;
  long *plVar9;
  long lVar10;
  undefined8 *puVar11;
  ulong unaff_x30;
  undefined4 local_70;
  int local_6c;
  undefined8 local_68;
  long local_60;
  long local_58;
  
  plVar9 = param_1 + 1;
  do {
    plVar9 = (long *)*plVar9;
    if (plVar9 == (long *)0x0) {
      return 0;
    }
    plVar3 = (long *)_xref_stream_get_entry(*(undefined8 *)(plVar9[1] + 0x10),param_2,param_3);
  } while (plVar3 == (long *)0x0);
  lVar8 = *plVar3;
  if ((*(byte *)((long)plVar3 + 0x12) >> 1 & 1) == 0) {
    if (lVar8 == 0) {
      return 0;
    }
    FUN_183bcd514(*(undefined8 *)(param_1[2] + 8));
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
      uVar4 = _pdf_object_scanner_read_indirect_object(param_1[2],param_4);
      return uVar4;
    }
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0x183ceda48);
    (*pcVar1)();
  }
  if (lVar8 == 0) {
    return 0;
  }
  lVar10 = *param_1;
  lVar8 = _pdf_xref_resolve(lVar10,lVar8,0);
  if (lVar8 == 0) {
    return 0;
  }
  lVar5 = _CGPDFObjectCopyAssociation(lVar8,"ObjectStream");
  if (lVar5 != 0) {
    uVar4 = _CGPDFObjectStreamGetObject(lVar5,param_2,param_3,param_4);
LAB_183ceda90:
    func_0x000188141240(lVar5);
    return uVar4;
  }
  if (*(int *)(lVar8 + 8) != 9) {
    return 0;
  }
  if (lVar10 == 0) {
    return 0;
  }
  lVar5 = *(long *)(lVar8 + 0x20);
  if (lVar5 == 0) {
    return 0;
  }
  if (DAT_1eb056b08 != -1) {
    func_0x00018813aad0(&DAT_1eb056b08,&DAT_1e223f668);
  }
  lVar6 = _pdf_create_cftype(DAT_1eb056a20,0x30);
  if (lVar6 == 0) {
    return 0;
  }
  local_60 = 0;
  local_58 = 0;
  local_68 = 0;
  local_6c = 0;
  *(long *)(lVar6 + 0x20) = lVar5;
  uVar4 = *(undefined8 *)(lVar5 + 0x30);
  iVar2 = FUN_183bd1218(uVar4,"Type",&local_68);
  if (iVar2 == 0) {
    pcVar7 = "invalid object stream: missing or invalid `Type\' value.";
  }
  else {
    iVar2 = func_0x0001881386b0(local_68,"ObjStm");
    if (iVar2 == 0) {
      iVar2 = FUN_183bd6c4c(uVar4,"N",&local_58);
      pcVar7 = "invalid object stream: missing or invalid `N\' value.";
      if ((iVar2 != 0) && (-1 < local_58)) {
        *(long *)(lVar6 + 0x10) = local_58;
        iVar2 = FUN_183bd02e0(uVar4,"First",&local_60);
        pcVar7 = "invalid object stream: missing or invalid `First\' value.";
        if ((iVar2 != 0) && (-1 < local_60)) {
          *(long *)(lVar6 + 0x18) = local_60;
          lVar10 = _pdf_object_scanner_create_with_xref(lVar10,1);
          *(long *)(lVar6 + 0x28) = lVar10;
          if (lVar10 != 0) {
            local_70 = 6;
            lVar10 = _CGPDFStreamCreateFilterChainExcluding(lVar5,&local_70,1,&local_6c);
            if (lVar10 != 0) {
              if (local_6c == 0) {
                puVar11 = *(undefined8 **)(lVar6 + 0x28);
                if (puVar11[1] != lVar10) {
                  _pdf_lexer_release(puVar11[2]);
                  uVar4 = _pdf_lexer_create(*puVar11,lVar10,(ulong)*(byte *)(puVar11 + 3) << 1);
                  puVar11[1] = lVar10;
                  puVar11[2] = uVar4;
                }
                func_0x000188141240(lVar10);
                lVar5 = _CGPDFObjectSetAssociation(lVar8,lVar6,"ObjectStream");
                uVar4 = _CGPDFObjectStreamGetObject(lVar5,param_2,param_3,param_4);
                if (lVar5 == 0) {
                  return uVar4;
                }
                goto LAB_183ceda90;
              }
              _pdf_error("invalid offset stream: invalid `Filter\' value.");
              func_0x000188141240(lVar10);
            }
            goto LAB_183cedb34;
          }
          pcVar7 = "internal error: failed to create object stream.";
        }
      }
    }
    else {
      pcVar7 = "invalid object stream: unrecognized `Type\' value.";
    }
  }
  _pdf_error(pcVar7);
LAB_183cedb34:
  func_0x000188141240(lVar6);
  return 0;
}



/* ==== _xref_stream_get_entry @ 183cedca8 size=84 ==== */

ulong * _xref_stream_get_entry(long *param_1,ulong param_2,short param_3)

{
  ulong *puVar1;
  ulong uVar2;
  
  while( true ) {
    if (param_1 == (long *)0x0) {
      return (ulong *)0x0;
    }
    puVar1 = (ulong *)param_1[1];
    uVar2 = *puVar1;
    if (((uVar2 <= param_2) && (param_2 < puVar1[1] + uVar2)) &&
       ((short)(puVar1 + (param_2 - uVar2) * 3 + 2)[2] == param_3)) break;
    param_1 = (long *)*param_1;
  }
  return puVar1 + (param_2 - uVar2) * 3 + 2;
}



/* ==== _CGPDFXRefStreamGetEntry @ 183cedcfc size=160 ==== */

bool _CGPDFXRefStreamGetEntry
               (long param_1,undefined8 param_2,undefined8 param_3,undefined4 *param_4)

{
  undefined8 *puVar1;
  long *plVar2;
  
  plVar2 = (long *)(param_1 + 8);
  do {
    plVar2 = (long *)*plVar2;
    if (plVar2 == (long *)0x0) goto LAB_183cedd84;
    puVar1 = (undefined8 *)_xref_stream_get_entry(*(undefined8 *)(plVar2[1] + 0x10),param_2,param_3)
    ;
  } while (puVar1 == (undefined8 *)0x0);
  if ((*(byte *)((long)puVar1 + 0x12) >> 1 & 1) == 0) {
    *param_4 = 0;
    *(undefined8 *)(param_4 + 2) = *puVar1;
  }
  else {
    *param_4 = 1;
    *(undefined8 *)(param_4 + 2) = *puVar1;
    *(undefined8 *)(param_4 + 4) = puVar1[1];
  }
  *(byte *)(param_4 + 6) = *(byte *)((long)puVar1 + 0x12) & 1;
  *(undefined2 *)((long)param_4 + 0x1a) = *(undefined2 *)(puVar1 + 2);
LAB_183cedd84:
  return plVar2 != (long *)0x0;
}



/* ==== _CGPDFXRefStreamPrint @ 183cedd9c size=408 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _CGPDFXRefStreamPrint(long param_1,long param_2)

{
  long lVar1;
  char *pcVar2;
  long *plVar3;
  long lVar4;
  long lVar5;
  long *plVar6;
  
  if (param_1 != 0) {
    lVar1 = *_DAT_1e0186238;
    if (param_2 != 0) {
      lVar1 = param_2;
    }
    for (plVar3 = *(long **)(param_1 + 8); plVar3 != (long *)0x0; plVar3 = (long *)*plVar3) {
      lVar4 = plVar3[1];
      func_0x00018813ad80(lVar1,"xref stream %p:\n");
      for (plVar6 = *(long **)(lVar4 + 0x10); plVar6 != (long *)0x0; plVar6 = (long *)*plVar6) {
        lVar4 = plVar6[1];
        func_0x00018813ad80(lVar1,"  Section %zu\n");
        func_0x00018813ad80(lVar1,"    start = %ld\n");
        func_0x00018813ad80(lVar1,"    count = %ld\n");
        if (0 < *(long *)(lVar4 + 8)) {
          lVar5 = 0;
          do {
            func_0x00018813ad80(lVar1,"    Entry %ld %hu (%s)\n");
            if ((*(byte *)(lVar4 + lVar5 * 0x18 + 0x22) >> 1 & 1) == 0) {
              pcVar2 = "      Offset: %lld\n";
            }
            else {
              pcVar2 = "      Stream: %lu index: %ld\n";
            }
            func_0x00018813ad80(lVar1,pcVar2);
            lVar5 = lVar5 + 1;
          } while (lVar5 < *(long *)(lVar4 + 8));
        }
      }
    }
  }
  return;
}



/* ==== _xref_stream_read_section @ 183cedf34 size=464 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 *
_xref_stream_read_section(undefined8 param_1,long *param_2,undefined8 param_3,ulong param_4)

{
  undefined8 *puVar1;
  uint uVar2;
  undefined8 *puVar3;
  byte bVar4;
  ulong uVar5;
  ulong uVar6;
  long lVar7;
  long lVar8;
  ulong local_80 [4];
  
  local_80[3] = *_DAT_1e0186220;
  if (param_4 < 0x155555555555556) {
    puVar3 = (undefined8 *)func_0x000188138460(1,param_4 * 0x18 + 0x10,0x1000040451b5be8);
    func_0x000188142e40(puVar3,"CGPDFNamedAlloc_XRef");
    if (puVar3 != (undefined8 *)0x0) {
      *puVar3 = param_3;
      puVar3[1] = param_4;
      if (param_4 != 0) {
        uVar5 = 0;
        do {
          lVar7 = 0;
          puVar1 = puVar3 + uVar5 * 3 + 2;
          do {
            lVar8 = param_2[lVar7];
            if (lVar8 == 0) {
              uVar6 = 0;
            }
            else {
              uVar6 = 0;
              do {
                uVar2 = FUN_183bdf3b0(param_1);
                if (uVar2 == 0xffffffff) goto LAB_183cee0b8;
                uVar6 = (ulong)uVar2 | uVar6 << 8;
                lVar8 = lVar8 + -1;
              } while (lVar8 != 0);
            }
            local_80[lVar7] = uVar6;
            lVar7 = lVar7 + 1;
          } while (lVar7 != 3);
          uVar6 = local_80[0];
          if (*param_2 == 0) {
            uVar6 = 1;
          }
          if (uVar6 == 2) {
            puVar1[1] = local_80[2];
            *puVar1 = local_80[1];
            *(undefined2 *)(puVar1 + 2) = 0;
            *(byte *)((long)puVar1 + 0x12) = *(byte *)((long)puVar1 + 0x12) | 3;
          }
          else {
            if (uVar6 == 1) {
              *puVar1 = local_80[1];
              *(short *)(puVar1 + 2) = (short)local_80[2];
              bVar4 = *(byte *)((long)puVar1 + 0x12) & 0xfc | 1;
            }
            else {
              if (uVar6 != 0) {
LAB_183cee0b8:
                func_0x000188138390(puVar3);
                goto LAB_183cee0c0;
              }
              *puVar1 = local_80[1];
              *(short *)(puVar1 + 2) = (short)local_80[2];
              bVar4 = *(byte *)((long)puVar1 + 0x12) & 0xfc;
            }
            *(byte *)((long)puVar1 + 0x12) = bVar4;
          }
          uVar5 = uVar5 + 1;
        } while (uVar5 != param_4);
      }
    }
  }
  else {
LAB_183cee0c0:
    puVar3 = (undefined8 *)0x0;
  }
  if (*_DAT_1e0186220 != local_80[3]) {
    puVar3 = (undefined8 *)func_0x000188138130();
    return puVar3;
  }
  return puVar3;
}



