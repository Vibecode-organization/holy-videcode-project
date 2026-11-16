// FUN_fffffff00a2c25e4 @ fffffff00a2c25e4 size=2820

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_fffffff00a2c25e4(long param_1,uint *param_2,uint param_3,undefined4 *param_4)

{
  uint uVar1;
  uint uVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  undefined1 uVar6;
  code *pcVar7;
  bool bVar8;
  long lVar9;
  int iVar10;
  int iVar11;
  long lVar12;
  ulong uVar13;
  long *plVar14;
  long lVar15;
  long lVar16;
  ulong uVar17;
  undefined8 uVar18;
  ushort *puVar19;
  ushort *puVar20;
  int in_wzr;
  uint local_74;
  uint *local_70;
  undefined8 local_68;
  
  local_70 = param_2;
  if ((param_3 >> 2 & 1) != 0) {
    if (_DAT_fffffff00ad102c0 != 0) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa4d114
                ("C_KDP passed to decompress page from outside of debugger context @%s:%d");
    }
    if (((param_3 ^ 0xffffffff) & 3) != 0) {
      return 0xfffffffe;
    }
    *param_4 = 0;
  }
joined_r0xfffffff00a2c2638:
  if ((param_3 & 4) == 0) goto LAB_fffffff00a2c2660;
LAB_fffffff00a2c263c:
  iVar11 = FUN_fffffff00a229014(&DAT_fffffff00ad6c7f8);
  if (iVar11 != 0) {
    return 0xfffffffe;
  }
  while( true ) {
    uVar4 = (*local_70 & 0x3fffff) - 1;
    if (DAT_fffffff00ad3dad8 <= uVar4) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa4d114
                (
                "c_decompress_page: c_segno %d >= c_segments_available %d, slot_ptr(%p), slot_data(%x) @%s:%d"
                );
    }
    uVar17 = *(ulong *)(DAT_fffffff00ad3dae0 + (ulong)uVar4 * 8);
    if (uVar17 < DAT_fffffff00ad3dad8) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa4d114
                ("c_decompress_page: c_segno %d is free, slot_ptr(%p), slot_data(%x) @%s:%d");
    }
    if ((param_3 & 4) == 0) {
      lVar9 = tpidr_el1;
      *(int *)(lVar9 + 0x1c0) = *(int *)(lVar9 + 0x1c0) + 1;
      if (*(ulong *)(uVar17 + 8) == 0) {
        *(ulong *)(uVar17 + 8) = (ulong)*(uint *)(lVar9 + 0x4e8) | 0x30000000;
      }
      else {
        FUN_fffffff00a2262d4(uVar17,lVar9,2);
      }
    }
    else {
      iVar11 = FUN_fffffff00a22708c(uVar17);
      if (iVar11 != 0) {
        return 0xfffffffe;
      }
    }
    uVar3 = *(ushort *)(uVar17 + 0x89);
    uVar4 = uVar3 >> 4 & 0xf;
    if ((param_1 == 0) && ((uVar3 >> 1 & 1) != 0)) break;
    if ((param_3 & 1) != 0) {
      if ((uVar3 & 1) == 0) {
        if (uVar4 == 5) {
          if (param_1 != 0) goto LAB_fffffff00a2c2994;
        }
        else if ((param_1 != 0) && (uVar4 == 6)) goto LAB_fffffff00a2c2994;
        break;
      }
LAB_fffffff00a2c2994:
      *param_4 = 0;
      uVar18 = 0xfffffffe;
      goto joined_r0xfffffff00a2c29a4;
    }
    if ((uVar3 & 1) == 0) break;
    FUN_fffffff00a228d30(&DAT_fffffff00ad6c7f8);
    FUN_fffffff00a2bf044(uVar17);
    if ((param_3 & 4) != 0) goto LAB_fffffff00a2c263c;
LAB_fffffff00a2c2660:
    FUN_fffffff00a228180();
  }
  uVar2 = *local_70;
  uVar5 = uVar2 >> 0x16;
  if (*(ushort *)(uVar17 + 0x66) <= uVar5) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff00aa4d114
              (
              "c_decompress_page: c_indx %d >= c_nextslot %d, c_seg(%p), slot_ptr(%p), slot_data(%x) @%s:%d"
              );
  }
  if ((int)uVar5 < DAT_fffffff00ad8a484) {
    puVar19 = (ushort *)(uVar17 + 0xa0 + (ulong)uVar5 * 0xc);
  }
  else {
    puVar19 = (ushort *)(*(ulong *)(uVar17 + 0x98) + (ulong)(uVar5 - DAT_fffffff00ad8a484) * 0xc);
    if (((*(ulong *)(uVar17 + 0x98) ^ (ulong)puVar19) & 0xffc0000000000000) != 0) {
      puVar19 = (ushort *)((ulong)puVar19 & 0xffffffffffff | 0xc8a2000000000000);
    }
  }
  uVar1 = 0x4000;
  if ((*(uint *)(puVar19 + 1) & 0x3fff) != 0x3fff) {
    uVar1 = *(uint *)(puVar19 + 1) & 0x3fff;
  }
  if (uVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff00aa4d114
              ("c_decompress_page: c_size == 0, c_seg(%p), slot_ptr(%p), slot_data(%x) @%s:%d");
  }
  if (param_1 == 0) {
    if (uVar4 - 5 < 2) {
      if (DAT_fffffff00ad94f6c == 0) {
                    /* WARNING: Does not return */
        pcVar7 = (code *)SoftwareBreakpoint(0xbffc,0xfffffff00a2c3038);
        DAT_fffffff00ad94f6c = DAT_fffffff00ad94f6c + -1;
        (*pcVar7)();
      }
      lVar9 = *(long *)(&DAT_fffffff00ad94f70 + ((ulong)(uVar3 >> 10) & 7) * 8);
      DAT_fffffff00ad94f6c = DAT_fffffff00ad94f6c + -1;
      *(long *)(&DAT_fffffff00ad94f70 + ((ulong)(uVar3 >> 10) & 7) * 8) = lVar9 + -1;
      if (lVar9 == 0) {
                    /* WARNING: Does not return */
        pcVar7 = (code *)SoftwareBreakpoint(0xbffc,0xfffffff00a2c3044);
        (*pcVar7)();
      }
      iVar11 = DAT_fffffff00ad94f60 + 1;
      if (DAT_fffffff00ad94f60 == 0x7fffffff) {
                    /* WARNING: Does not return */
        pcVar7 = (code *)SoftwareBreakpoint(0xbffc,0xfffffff00a2c3050);
        DAT_fffffff00ad94f60 = iVar11;
        (*pcVar7)();
      }
      if (((*(ushort *)(uVar17 + 0x89) >> 9 & 1) != 0) &&
         (iVar10 = DAT_fffffff00ad94f64 + 1, bVar8 = DAT_fffffff00ad94f64 == 0x7fffffff,
         DAT_fffffff00ad94f64 = iVar10, bVar8)) {
                    /* WARNING: Does not return */
        pcVar7 = (code *)SoftwareBreakpoint(0xbffc,0xfffffff00a2c3070);
        DAT_fffffff00ad94f60 = iVar11;
        (*pcVar7)();
      }
      DAT_fffffff00ad94f60 = iVar11;
      if (*(long *)(uVar17 + 0x40) != 0) {
        FUN_fffffff00a223f24
                  (*(undefined8 *)(*(long *)(uVar17 + 0x40) + 800),DAT_fffffff007bf1760,0x4000);
      }
    }
    uVar18 = 0;
  }
  else {
    if (uVar4 - 5 < 2) {
      if ((DAT_fffffff00ad0e3d0 & 1) != 0) {
        if ((uint)(DAT_fffffff00ad94f60 + *(int *)(uVar17 + 0x60)) < DAT_fffffff00ad44628) {
          if ((DAT_fffffff00ad94fd8 - (DAT_fffffff00ad94ffc + DAT_fffffff00ad95000)) + 1U <
              DAT_fffffff00ad4462c) goto LAB_fffffff00a2c2858;
          FUN_fffffff00a228d30(&DAT_fffffff00ad6c7f8);
          lVar9 = tpidr_el1;
        }
        else {
          FUN_fffffff00a228d30(&DAT_fffffff00ad6c7f8);
          lVar9 = tpidr_el1;
        }
        if (*(int *)(uVar17 + 8) == *(int *)(lVar9 + 0x4e8)) {
          *(int *)(uVar17 + 8) = in_wzr;
        }
        else {
          FUN_fffffff00a226e08(uVar17);
        }
        FUN_fffffff00a7511b4(0);
        goto joined_r0xfffffff00a2c2638;
      }
LAB_fffffff00a2c2858:
      uVar18 = 1;
      FUN_fffffff00a2c0888(uVar17,0,1);
      uVar3 = *(ushort *)(uVar17 + 0x89);
    }
    else {
      uVar18 = 0;
    }
    if ((uVar3 & 0xf0) == 0x90) {
      *param_4 = 0;
      uVar18 = 0xfffffffd;
joined_r0xfffffff00a2c29a4:
      uVar6 = false;
      goto joined_r0xfffffff00a2c29a4;
    }
    if (uVar1 == 4) {
      if (*(int *)(*(long *)(uVar17 + 0x70) + (ulong)*puVar19 * 4) == 0) {
        FUN_fffffff00a1d1294(param_1,0x4000);
      }
      else {
        FUN_fffffff00a1d12ac(param_1,0x4000);
      }
    }
    else if (uVar1 == 0x4000) {
      FUN_fffffff00aa65b10(param_1,*(long *)(uVar17 + 0x70) + (ulong)*puVar19 * 4,0x4000);
    }
    else {
      lVar9 = tpidr_el1;
      lVar16 = DAT_fffffff00ad3db08;
      if (((param_3 & 4) == 0) ||
         (lVar12 = DAT_fffffff00ad45fe0, lVar16 = DAT_fffffff00ad45fc0, (param_3 >> 4 & 1) != 0)) {
        lVar12 = lVar16 + (ulong)*(ushort *)(lVar9 + 0x1b0) * 0x4000;
      }
      if (_DAT_fffffff00ad0e3d4 == 3) {
        FUN_fffffff00a1cd000(*(long *)(uVar17 + 0x70) + (ulong)*puVar19 * 4,param_1,lVar12,uVar1);
      }
      else {
        local_74 = 0;
        uVar13 = FUN_fffffff00a2cb01c
                           (*(long *)(uVar17 + 0x70) + (ulong)*puVar19 * 4,param_1,uVar1,
                            puVar19[1] >> 0xe & 1,lVar12,&local_74);
        if ((uVar13 & 1) == 0) {
          plVar14 = (long *)(_DAT_fffffff00ad0e368 + (ulong)*(ushort *)(lVar9 + 0x1b0) * 0x4000);
          *plVar14 = *plVar14 + 1;
          uVar18 = 0xfffffffc;
        }
        else {
          uVar13 = (ulong)local_74;
          if (local_74 != ((uint)(*(ulong *)(puVar19 + 1) >> 0xf) & 0x3ffff)) {
            if ((param_3 & 5) == 0) {
              local_68 = 0;
              FUN_fffffff00aa62d50(*(long *)(uVar17 + 0x70) + (ulong)*puVar19 * 4,&local_68);
            }
            plVar14 = (long *)(_DAT_fffffff00ad0e368 + (ulong)*(ushort *)(lVar9 + 0x1b0) * 0x4000);
            *plVar14 = *plVar14 + 1;
            if (lVar9 == 0) {
              uVar18 = 0;
            }
            else {
              uVar18 = *(undefined8 *)(lVar9 + 0x4e0);
            }
            FUN_fffffff00a6db8c0
                      (uVar18,0x100007c,uVar13 | (*(ulong *)(puVar19 + 1) >> 0xf & 0x3ffff) << 0x20)
            ;
            uVar18 = 0xfffffffb;
          }
        }
      }
    }
    if (*(int *)(uVar17 + 0x84) == 0 && (param_3 & 4) == 0) {
      lVar9 = tpidr_el1;
      lVar16 = *(long *)(*(long *)(lVar9 + 0x1b8) + 0x58);
      do {
        lVar15 = lVar16;
        lVar12 = UnkSytemRegRead(3,4,0xf,10,6);
        lVar16 = *(long *)(*(long *)(lVar9 + 0x1b8) + 0x58);
      } while (lVar16 != lVar15);
      uVar13 = 0;
      if ((ulong)DAT_fffffff00ad08000 != 0) {
        uVar13 = (ulong)(lVar12 + lVar15) / (ulong)DAT_fffffff00ad08000;
      }
      uVar13 = uVar13 - *(uint *)(uVar17 + 0x4c);
      if (uVar13 < 0x708) {
        plVar14 = &DAT_fffffff00ad40aa8 + uVar13;
        if ((((ulong)plVar14 ^ 0xfffffff00ad40aa8) & 0xffc0000000000000) != 0) {
          plVar14 = (long *)((ulong)plVar14 & 0xffffffffffff | 0xc8a2000000000000);
        }
        *plVar14 = *plVar14 + 1;
      }
      else {
        DAT_fffffff00ad3da18 = DAT_fffffff00ad3da18 + 1;
      }
      DAT_fffffff00ad3da00 = DAT_fffffff00ad3da00 + 1;
    }
  }
  if ((param_3 >> 1 & 1) == 0) {
    puVar20 = (ushort *)(uVar17 + 0x89);
    uVar4 = uVar1 + 0x3f & 0xffc0;
    *(uint *)(uVar17 + 0x58) = *(int *)(uVar17 + 0x58) - uVar4;
    *(ulong *)(uVar17 + 0x5c) =
         CONCAT44((int)((ulong)*(undefined8 *)(uVar17 + 0x5c) >> 0x20) + -1,
                  (int)*(undefined8 *)(uVar17 + 0x5c) + uVar4);
    if ((param_1 != 0) && ((*(byte *)(uVar17 + 0x88) & 1) != 0)) {
      lVar9 = tpidr_el1;
      FUN_fffffff00a223a40(*(undefined8 *)(lVar9 + 0x4b8),DAT_fffffff007bf17ec,0x4000);
    }
    *(ulong *)(puVar19 + 1) = *(ulong *)(puVar19 + 1) & 0xffffffffffffc000;
    if (uVar5 < *(ushort *)(uVar17 + 100)) {
      *(ushort *)(uVar17 + 100) = (ushort)(uVar2 >> 0x16);
    }
    DAT_fffffff00ad94f5c = DAT_fffffff00ad94f5c + -1;
    iVar11 = DAT_fffffff00ad94f60 + -1;
    if (DAT_fffffff00ad94f60 == -0x80000000) {
                    /* WARNING: Does not return */
      pcVar7 = (code *)SoftwareBreakpoint(0xbffc,0xfffffff00a2c3020);
      DAT_fffffff00ad94f60 = iVar11;
      (*pcVar7)();
    }
    uVar3 = *puVar20;
    if (((uVar3 >> 9 & 1) != 0) &&
       (iVar10 = DAT_fffffff00ad94f64 + -1, bVar8 = DAT_fffffff00ad94f64 == -0x80000000,
       DAT_fffffff00ad94f64 = iVar10, bVar8)) {
                    /* WARNING: Does not return */
      pcVar7 = (code *)SoftwareBreakpoint(0xbffc,0xfffffff00a2c302c);
      DAT_fffffff00ad94f60 = iVar11;
      (*pcVar7)();
    }
    uVar2 = uVar3 >> 4 & 0xf;
    if ((9 < uVar2) || ((1 << (ulong)uVar2 & 0x260U) == 0)) {
      DAT_fffffff00ad8a468 = DAT_fffffff00ad8a468 - (ulong)uVar4;
    }
    DAT_fffffff00ad94f60 = iVar11;
    if (((uVar3 >> 1 & 1) == 0) && (uVar2 != 2)) {
      if (*(int *)(uVar17 + 0x58) == 0) {
        if (uVar2 - 5 < 2) {
          if ((uVar3 & 0xf0) != 0x60) {
LAB_fffffff00a2c2d74:
            FUN_fffffff00a2c161c(uVar17);
            uVar6 = true;
            goto joined_r0xfffffff00a2c29a4;
          }
        }
        else {
          uVar4 = *(int *)(uVar17 + 0x6c) * 4;
          uVar2 = uVar4 + 0x3fff;
          if (0xffffc000 < uVar4) {
                    /* WARNING: Subroutine does not return */
            FUN_fffffff00aa4d114("overflow detected @%s:%d");
          }
          *(undefined4 *)(uVar17 + 0x6c) = 0;
          if (0x3fff < uVar2) {
            *puVar20 = uVar3 | 1;
            lVar9 = tpidr_el1;
            *(long *)(uVar17 + 0x78) = lVar9;
            if (*(int *)(uVar17 + 8) == *(int *)(lVar9 + 0x4e8)) {
              *(int *)(uVar17 + 8) = in_wzr;
            }
            else {
              FUN_fffffff00a226e08(uVar17,lVar9);
            }
            FUN_fffffff00a2de21c(*(undefined8 *)(uVar17 + 0x70),uVar2 & 0xffffc000,0x200,0xe);
            FUN_fffffff00a226c60(uVar17);
            FUN_fffffff00a2c30e8(uVar17);
            uVar3 = *puVar20;
          }
          if (((uVar3 >> 3 & 1) == 0) && (uVar3 = uVar3 >> 4 & 0xf, uVar3 != 10)) {
            iVar10 = DAT_fffffff00ad443f0;
            if (uVar3 == 4) {
              iVar11 = FUN_fffffff00a226d40(&DAT_fffffff00ad443e8);
              if (iVar11 == 0) {
                *puVar20 = *puVar20 | 1;
                lVar9 = tpidr_el1;
                *(long *)(uVar17 + 0x78) = lVar9;
                if (*(int *)(uVar17 + 8) == *(int *)(lVar9 + 0x4e8)) {
                  *(int *)(uVar17 + 8) = in_wzr;
                }
                else {
                  FUN_fffffff00a226e08(uVar17);
                }
                FUN_fffffff00a226c60(&DAT_fffffff00ad443e8);
                FUN_fffffff00a226c60(uVar17);
                FUN_fffffff00a2bcc80(uVar17,3,0);
                FUN_fffffff00a2c30e8(uVar17);
              }
              else {
                FUN_fffffff00a2bcc80(uVar17,3,0);
              }
              lVar9 = tpidr_el1;
              iVar10 = in_wzr;
              if (DAT_fffffff00ad443f0 != *(int *)(lVar9 + 0x4e8)) {
                FUN_fffffff00a226e08(&DAT_fffffff00ad443e8);
                iVar10 = DAT_fffffff00ad443f0;
              }
            }
LAB_fffffff00a2c2fc8:
            DAT_fffffff00ad443f0 = iVar10;
            FUN_fffffff00a2c13ac(uVar17,0);
          }
        }
      }
      else if ((uVar3 >> 3 & 1) == 0) {
        if (uVar2 < 0xb) {
          if ((1 << (ulong)uVar2 & 0x610U) == 0) {
            if ((1 << (ulong)uVar2 & 0x60U) == 0) goto LAB_fffffff00a2c2e6c;
            if (((uVar3 & 0xf0) != 0x60) && (*(int *)(uVar17 + 0x58) < *(int *)(uVar17 + 0x5c)))
            goto LAB_fffffff00a2c2d74;
          }
        }
        else {
LAB_fffffff00a2c2e6c:
          iVar10 = DAT_fffffff00ad443f0;
          if (0x3fff < (uint)(*(int *)(uVar17 + 0x5c) +
                             (*(int *)(uVar17 + 0x6c) - *(int *)(uVar17 + 0x68)) * 4))
          goto LAB_fffffff00a2c2fc8;
        }
      }
      else if (DAT_fffffff00ad950ec >> 2 <=
               (uint)(*(int *)(uVar17 + 0x5c) +
                     (*(int *)(uVar17 + 0x6c) - *(int *)(uVar17 + 0x68)) * 4)) {
        FUN_fffffff00a2c17fc(uVar17);
        if ((param_3 & 4) != 0) {
          return uVar18;
        }
        FUN_fffffff00a228d30(&DAT_fffffff00ad6c7f8);
        goto LAB_fffffff00a2c2ec0;
      }
    }
    uVar6 = false;
  }
  else {
    uVar6 = false;
    *param_4 = 0;
  }
joined_r0xfffffff00a2c29a4:
  if ((param_3 & 4) != 0) {
    return uVar18;
  }
  lVar9 = tpidr_el1;
  if (*(int *)(uVar17 + 8) == *(int *)(lVar9 + 0x4e8)) {
    *(int *)(uVar17 + 8) = in_wzr;
  }
  else {
    FUN_fffffff00a226e08(uVar17);
  }
  FUN_fffffff00a228d30(&DAT_fffffff00ad6c7f8);
  if ((bool)uVar6) {
    FUN_fffffff00a2ca0ec(0);
  }
LAB_fffffff00a2c2ec0:
  FUN_fffffff00a2c2068();
  return uVar18;
}

