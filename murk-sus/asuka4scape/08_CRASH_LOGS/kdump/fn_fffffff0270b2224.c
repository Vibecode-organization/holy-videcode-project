// FUN_fffffff0270b2224 @ fffffff0270b2224 size=5760
// CALLERS:
// CALLS:
//   fffffff02709adf4 FUN_fffffff02709adf4
//   fffffff0270a67c8 thunk_FUN_fffffff0270a4570
//   fffffff0270a3ed8 FUN_fffffff0270a3ed8
//   fffffff0270b3f68 FUN_fffffff0270b3f68
//   fffffff0270d260c FUN_fffffff0270d260c
//   fffffff0270b0ac8 FUN_fffffff0270b0ac8
//   fffffff0270b38a4 FUN_fffffff0270b38a4
//   fffffff0270e1754 FUN_fffffff0270e1754
//   fffffff0270bb1e0 FUN_fffffff0270bb1e0
//   fffffff0270a3d90 thunk_FUN_fffffff0270a3d9c
//   fffffff0270b1158 FUN_fffffff0270b1158
//   fffffff0270d841c FUN_fffffff0270d841c
//   fffffff0270b0fa4 FUN_fffffff0270b0fa4
//   fffffff0270a6a50 thunk_FUN_fffffff0270a4230
//   fffffff0270b08b0 FUN_fffffff0270b08b0
//   fffffff0270d4730 FUN_fffffff0270d4730
//   fffffff0270b0e14 FUN_fffffff0270b0e14
//   fffffff0270d2f50 FUN_fffffff0270d2f50
//   fffffff0270a67d0 FUN_fffffff0270a67d0
//   fffffff0270b39b4 FUN_fffffff0270b39b4
//   fffffff02709af04 FUN_fffffff02709af04
//   fffffff0270b3e48 FUN_fffffff0270b3e48
//   fffffff0270d3fa0 FUN_fffffff0270d3fa0
//   fffffff0270f34fc FUN_fffffff0270f34fc
//   fffffff0270d05a8 FUN_fffffff0270d05a8
//   fffffff0270b107c FUN_fffffff0270b107c

void FUN_fffffff0270b2224(undefined8 param_1)

{
  ulong uVar1;
  byte bVar2;
  undefined1 uVar3;
  code *pcVar4;
  bool bVar5;
  ulong uVar6;
  ulong uVar7;
  int iVar8;
  long lVar9;
  long *plVar10;
  ulong *puVar11;
  undefined8 *puVar12;
  uint uVar13;
  undefined **ppuVar14;
  long lVar15;
  char *pcVar16;
  char *pcVar17;
  long lVar18;
  long lVar19;
  long lVar20;
  int local_7c;
  ushort *local_78;
  int *local_70;
  undefined8 *local_68;
  
  DAT_fffffff0270fc5c8 = FUN_fffffff0270d05a8();
  FUN_fffffff0270b0e14(0,0,0);
  uVar6 = DAT_fffffff027102040 | 1;
  LORelease();
  uVar7 = DAT_fffffff027102040 & 1;
  DAT_fffffff027102040 = uVar6;
  if (uVar7 != 0) goto LAB_fffffff0270b36ec;
  thunk_FUN_fffffff0270a4570(&DAT_fffffff027090b10,param_1,0x488);
  FUN_fffffff0270b107c();
  DAT_fffffff027090ff0 = DAT_fffffff027090b18;
  DAT_fffffff0270921c8 = DAT_fffffff027090b20;
  if (((uint)DAT_fffffff027102040 >> 8 & 1) != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f34fc("%s: Unexpected bootstrap stages reached. Expected: %p, Actual: %p");
  }
  DAT_fffffff027044000 = &DAT_fffffff027034000;
  FUN_fffffff0270a67d0(&DAT_fffffff0270fc32c,"randseed",8,0x108);
  lVar9 = FUN_fffffff0270b38a4("random-seed",0x100,&DAT_fffffff0270fc334);
  DAT_fffffff0270fc438 = lVar9 + 8;
  lVar9 = FUN_fffffff0270b38a4("cl4-entropy",0xc0,&DAT_fffffff0270903b0);
  if (lVar9 != 0xc0) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f34fc("%s: Not enough SK entropy");
  }
  local_68 = (undefined8 *)0x0;
  iVar8 = FUN_fffffff0270b08b0(PTR_DAT_fffffff027090600,0,"/chosen",&local_68);
  if (iVar8 == 1) {
    local_70 = (int *)0x0;
    local_78 = (ushort *)((ulong)local_78 & 0xffffffff00000000);
    iVar8 = FUN_fffffff0270b0ac8
                      (local_68,"kernel-ctrr-to-be-enabled",&local_70,&local_78,
                       *(undefined8 *)PTR_DAT_fffffff027090600,
                       *(undefined8 *)(PTR_DAT_fffffff027090600 + 8));
    if (iVar8 != 1) goto LAB_fffffff0270b23c4;
    if ((int)local_78 != 4) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff0270f34fc
                ("%s: unexpected size %xu for bool property \'kernel-ctrr-to-be-enabled\'");
    }
    DAT_fffffff0270905e0 = *local_70 == 0;
    if (*local_70 == 0) {
      DAT_fffffff027090499 = 7;
      DAT_fffffff02709049a = 0xd;
    }
  }
  else {
LAB_fffffff0270b23c4:
    DAT_fffffff0270905e0 = false;
  }
  plVar10 = (long *)FUN_fffffff0270b0fa4("BootKC-rs",1);
  lVar9 = *plVar10;
  plVar10 = (long *)FUN_fffffff0270b0fa4("BootKC-rs",1);
  uVar7 = (*plVar10 - lVar9) + plVar10[1];
  if (uVar7 >> 0xe == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f34fc("%s: BootKC rs region does not fit xnu_ro_data (needed: %zu, have: %zu)");
  }
  uVar6 = (lVar9 - DAT_fffffff027090b20) + DAT_fffffff027090b18;
  DAT_fffffff027091010 = uVar6 + 0x4000;
  DAT_fffffff027090fe0 = uVar6 + uVar7;
  if ((uVar6 & 0x3fff) != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f34fc("%s: xnu ro pagetables don\'t begin on page boundary");
  }
  if ((uVar7 & 0x3fff) != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f34fc("%s: xnu ro pagetables don\'t end on page boundary");
  }
  thunk_FUN_fffffff0270a4230(uVar6);
  DAT_fffffff0270914f8 = uVar6 + 8;
  DAT_fffffff027091e60 = uVar6 + 0x10;
  DAT_fffffff027090fb8 = uVar6;
  puVar11 = (ulong *)FUN_fffffff0270b0fa4("BootKC-ro",1);
  uVar6 = *puVar11;
  plVar10 = (long *)FUN_fffffff0270b0fa4("BootKC-rs",1);
  uVar7 = (DAT_fffffff027090fb8 - DAT_fffffff027090b18) + DAT_fffffff027090b20;
  if ((uVar7 < uVar6) || (uVar1 = plVar10[1] + *plVar10, uVar1 <= uVar7)) {
LAB_fffffff0270b36d0:
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f34fc("%s: %s not fully within BootKC ro region");
  }
  uVar7 = DAT_fffffff027090fb8 + DAT_fffffff027090b20 + ~DAT_fffffff027090b18 + 8;
  if ((uVar7 < uVar6) ||
     (((uVar1 <= uVar7 ||
       (uVar7 = (DAT_fffffff0270914f8 - DAT_fffffff027090b18) + DAT_fffffff027090b20, uVar7 < uVar6)
       ) || (uVar1 <= uVar7)))) goto LAB_fffffff0270b36d0;
  lVar9 = DAT_fffffff027090b20 + ~DAT_fffffff027090b18;
  uVar7 = DAT_fffffff0270914f8 + lVar9 + 8;
  if (((((uVar7 < uVar6) || (uVar1 <= uVar7)) ||
       (uVar7 = (DAT_fffffff027091e60 - DAT_fffffff027090b18) + DAT_fffffff027090b20, uVar7 < uVar6)
       ) || (((uVar1 <= uVar7 || (uVar7 = DAT_fffffff027091e60 + lVar9 + 0x1e0, uVar7 < uVar6)) ||
             (((uVar1 <= uVar7 ||
               ((((uVar7 = (DAT_fffffff027091010 - DAT_fffffff027090b18) + DAT_fffffff027090b20,
                  uVar7 < uVar6 || (uVar1 <= uVar7)) ||
                 (uVar7 = DAT_fffffff027091010 + lVar9 + 1, uVar7 < uVar6)) ||
                ((uVar1 <= uVar7 ||
                 (uVar7 = ~DAT_fffffff027090b18 + DAT_fffffff027090fe0 + DAT_fffffff027090b20,
                 uVar7 < uVar6)))))) || (uVar1 <= uVar7)))))) ||
     (((ulong)(lVar9 + DAT_fffffff027090fe0) < uVar6 ||
      (uVar1 <= (ulong)(lVar9 + DAT_fffffff027090fe0))))) goto LAB_fffffff0270b36d0;
  local_68 = (undefined8 *)0x0;
  iVar8 = FUN_fffffff0270b08b0(PTR_DAT_fffffff027090600,0,"/product",&local_68);
  if ((iVar8 == 1) &&
     (iVar8 = FUN_fffffff0270b0ac8
                        (local_68,"internal-isa-vm-allowed",&local_70,&local_78,
                         *(undefined8 *)PTR_DAT_fffffff027090600,
                         *(undefined8 *)(PTR_DAT_fffffff027090600 + 8)), iVar8 == 1)) {
    DAT_fffffff0270921b0 = true;
  }
  else {
    local_70 = (int *)0x0;
    iVar8 = FUN_fffffff0270b08b0(PTR_DAT_fffffff027090600,0,"/chosen/asmb",&local_70);
    if (iVar8 == 1) {
      local_78 = (ushort *)0x0;
      local_7c = 0;
      iVar8 = FUN_fffffff0270b0ac8
                        (local_70,"lp-sip0",&local_78,&local_7c,
                         *(undefined8 *)PTR_DAT_fffffff027090600,
                         *(undefined8 *)(PTR_DAT_fffffff027090600 + 8));
      DAT_fffffff0270921b0 = false;
      if ((iVar8 == 1) && (local_7c == 8)) {
        DAT_fffffff0270921b0 = (*local_78 & 0x1010) != 0;
      }
    }
    else {
      DAT_fffffff0270921b0 = false;
    }
  }
  lVar9 = 0;
  pcVar17 = (char *)0x0;
  ppuVar14 = &PTR_s_TXM_ro_fffffff02701c728;
  pcVar16 = "TXM-ro";
  lVar20 = 0x10;
  lVar19 = 0;
  do {
    bVar2 = *(byte *)(ppuVar14 + 1);
    plVar10 = (long *)FUN_fffffff0270b0fa4(pcVar16,(bVar2 ^ 0xff) & 1);
    lVar18 = lVar19;
    if (plVar10 == (long *)0x0) {
      if ((bVar2 & 1) == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff0270f34fc("%s: init_get_image_region returned NULL for a non-optional region");
      }
    }
    else {
      lVar15 = *plVar10;
      if (((bVar2 & 1) == 0) || (lVar15 != -1)) {
        lVar18 = plVar10[1] + lVar15;
        if (0xfffffffffffffffd < lVar15 - 1U || 0xfffffffffffffffd < lVar18 - 1U) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff0270f34fc("%s: region \'%s\' beginning [%p] or end [%p] is invalid");
        }
        bVar5 = pcVar17 != (char *)0x0;
        pcVar17 = pcVar16;
        if (lVar15 != lVar19 && bVar5) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff0270f34fc
                    ("%s: region \'%s\' [%p-%p] not immediately after region \'%s\' [ending at %p]")
          ;
        }
      }
    }
    lVar9 = lVar9 + 1;
    ppuVar14 = &PTR_s_TXM_ro_fffffff02701c728 + lVar9 * 2;
    pcVar16 = *ppuVar14;
    lVar20 = lVar20 + -1;
    lVar19 = lVar18;
  } while (lVar20 != 0);
  puVar12 = (undefined8 *)FUN_fffffff0270b0fa4("DeviceTree",1);
  if (puVar12 != (undefined8 *)0x0) {
    FUN_fffffff0270d3fa0("DeviceTree",2,*puVar12,puVar12[1] + 0x3fff >> 0xe,0x20);
  }
  puVar12 = (undefined8 *)FUN_fffffff0270b0fa4("SPTM-ro",1);
  if (puVar12 != (undefined8 *)0x0) {
    FUN_fffffff0270d3fa0("SPTM-ro",2,*puVar12,puVar12[1] + 0x3fff >> 0xe,0x28);
  }
  puVar12 = (undefined8 *)FUN_fffffff0270b0fa4("SPTM-rx",1);
  if (puVar12 != (undefined8 *)0x0) {
    FUN_fffffff0270d3fa0("SPTM-rx",4,*puVar12,puVar12[1] + 0x3fff >> 0xe,0x121);
  }
  puVar12 = (undefined8 *)FUN_fffffff0270b0fa4("SPTM-rw",1);
  if (puVar12 != (undefined8 *)0x0) {
    FUN_fffffff0270d3fa0("SPTM-rw",2,*puVar12,puVar12[1] + 0x3fff >> 0xe,0x21);
  }
  puVar12 = (undefined8 *)FUN_fffffff0270b0fa4("SPTM-le",1);
  if (puVar12 != (undefined8 *)0x0) {
    FUN_fffffff0270d3fa0("SPTM-le",2,*puVar12,puVar12[1] + 0x3fff >> 0xe,0x21);
  }
  puVar12 = (undefined8 *)FUN_fffffff0270b0fa4("TXM-ro",1);
  if (puVar12 != (undefined8 *)0x0) {
    FUN_fffffff0270d3fa0("TXM-ro",0x2c,*puVar12,puVar12[1] + 0x3fff >> 0xe,0x48);
  }
  puVar12 = (undefined8 *)FUN_fffffff0270b0fa4("TXM-rx",1);
  if (puVar12 != (undefined8 *)0x0) {
    FUN_fffffff0270d3fa0("TXM-rx",0x2c,*puVar12,puVar12[1] + 0x3fff >> 0xe,0x141);
  }
  puVar12 = (undefined8 *)FUN_fffffff0270b0fa4("TXM-bx",1);
  if (puVar12 != (undefined8 *)0x0) {
    FUN_fffffff0270d3fa0("TXM-bx",5,*puVar12,puVar12[1] + 0x3fff >> 0xe,0x141);
  }
  puVar12 = (undefined8 *)FUN_fffffff0270b0fa4("TXM-rw",1);
  if (puVar12 != (undefined8 *)0x0) {
    FUN_fffffff0270d3fa0("TXM-rw",0x2c,*puVar12,puVar12[1] + 0x3fff >> 0xe,0x41);
  }
  puVar12 = (undefined8 *)FUN_fffffff0270b0fa4("TXM-le",1);
  if (puVar12 != (undefined8 *)0x0) {
    FUN_fffffff0270d3fa0("TXM-le",0x2c,*puVar12,puVar12[1] + 0x3fff >> 0xe,0x41);
  }
  puVar12 = (undefined8 *)FUN_fffffff0270b0fa4("BootKC-ro",1);
  if (puVar12 != (undefined8 *)0x0) {
    FUN_fffffff0270d3fa0("BootKC-ro",0x23,*puVar12,puVar12[1] + 0x3fff >> 0xe,0x48);
  }
  puVar12 = (undefined8 *)FUN_fffffff0270b0fa4("BootKC-rs",1);
  if (puVar12 != (undefined8 *)0x0) {
    FUN_fffffff0270d3fa0("BootKC-rs",2,*puVar12,puVar12[1] + 0x3fff >> 0xe,0x41);
  }
  puVar12 = (undefined8 *)FUN_fffffff0270b0fa4("BootKC-rx",1);
  if (puVar12 != (undefined8 *)0x0) {
    FUN_fffffff0270d3fa0("BootKC-rx",0x23,*puVar12,puVar12[1] + 0x3fff >> 0xe,0x141);
  }
  uVar3 = DAT_fffffff027090499;
  puVar12 = (undefined8 *)FUN_fffffff0270b0fa4("BootKC-bx",1);
  if (puVar12 != (undefined8 *)0x0) {
    FUN_fffffff0270d3fa0("BootKC-bx",uVar3,*puVar12,puVar12[1] + 0x3fff >> 0xe,0x141);
  }
  puVar12 = (undefined8 *)FUN_fffffff0270b0fa4("BootKC-rw",1);
  if (puVar12 != (undefined8 *)0x0) {
    FUN_fffffff0270d3fa0("BootKC-rw",0x23,*puVar12,puVar12[1] + 0x3fff >> 0xe,0x51);
  }
  puVar12 = (undefined8 *)FUN_fffffff0270b0fa4("BootKC-le",1);
  if (puVar12 != (undefined8 *)0x0) {
    FUN_fffffff0270d3fa0("BootKC-le",0x23,*puVar12,puVar12[1] + 0x3fff >> 0xe,0x51);
  }
  if (DAT_fffffff0270904c8 != 0) {
    local_68 = (undefined8 *)0x0;
    local_70 = (int *)((ulong)local_70 & 0xffffffff00000000);
    iVar8 = FUN_fffffff0270b0ac8
                      (DAT_fffffff0270904c8,"AuxKC-rw",&local_68,&local_70,
                       *(undefined8 *)PTR_DAT_fffffff027090600,
                       *(undefined8 *)(PTR_DAT_fffffff027090600 + 8));
    if (iVar8 == 1) {
      if ((int)local_70 != 0x10) goto LAB_fffffff0270b37c4;
      if (local_68 != (undefined8 *)0x0) {
        FUN_fffffff0270d3fa0("AuxKC-rw",0x23,*local_68,local_68[1] + 0x3fff >> 0xe,0x43);
      }
    }
    if (DAT_fffffff0270904c8 == 0) goto LAB_fffffff0270b37ac;
    local_68 = (undefined8 *)0x0;
    local_70 = (int *)((ulong)local_70 & 0xffffffff00000000);
    iVar8 = FUN_fffffff0270b0ac8
                      (DAT_fffffff0270904c8,"AuxKC-ro",&local_68,&local_70,
                       *(undefined8 *)PTR_DAT_fffffff027090600,
                       *(undefined8 *)(PTR_DAT_fffffff027090600 + 8));
    if (iVar8 == 1) {
      if ((int)local_70 != 0x10) goto LAB_fffffff0270b37c4;
      if (local_68 != (undefined8 *)0x0) {
        FUN_fffffff0270d3fa0("AuxKC-ro",0x23,*local_68,local_68[1] + 0x3fff >> 0xe,0x43);
      }
    }
    if (DAT_fffffff0270904c8 == 0) goto LAB_fffffff0270b37ac;
    local_68 = (undefined8 *)0x0;
    local_70 = (int *)((ulong)local_70 & 0xffffffff00000000);
    iVar8 = FUN_fffffff0270b0ac8
                      (DAT_fffffff0270904c8,"AuxKC-rx",&local_68,&local_70,
                       *(undefined8 *)PTR_DAT_fffffff027090600,
                       *(undefined8 *)(PTR_DAT_fffffff027090600 + 8));
    if (iVar8 == 1) {
      if ((int)local_70 != 0x10) goto LAB_fffffff0270b37c4;
      if (local_68 != (undefined8 *)0x0) {
        FUN_fffffff0270d3fa0("AuxKC-rx",0x23,*local_68,local_68[1] + 0x3fff >> 0xe,0x43);
      }
    }
    if (DAT_fffffff0270904c8 == 0) goto LAB_fffffff0270b37ac;
    local_68 = (undefined8 *)0x0;
    local_70 = (int *)((ulong)local_70 & 0xffffffff00000000);
    iVar8 = FUN_fffffff0270b0ac8
                      (DAT_fffffff0270904c8,"AuxKC-le",&local_68,&local_70,
                       *(undefined8 *)PTR_DAT_fffffff027090600,
                       *(undefined8 *)(PTR_DAT_fffffff027090600 + 8));
    if (iVar8 == 1) {
      if ((int)local_70 != 0x10) goto LAB_fffffff0270b37c4;
      if (local_68 != (undefined8 *)0x0) {
        FUN_fffffff0270d3fa0("AuxKC-le",0x23,*local_68,local_68[1] + 0x3fff >> 0xe,0x53);
      }
    }
    puVar12 = (undefined8 *)FUN_fffffff0270b0fa4("TrustCache",1);
    if (puVar12 != (undefined8 *)0x0) {
      FUN_fffffff0270d3fa0("TrustCache",0,*puVar12,puVar12[1] + 0x3fff >> 0xe,0x40);
    }
    if (DAT_fffffff0270904c8 == 0) goto LAB_fffffff0270b37ac;
    local_68 = (undefined8 *)0x0;
    local_70 = (int *)((ulong)local_70 & 0xffffffff00000000);
    iVar8 = FUN_fffffff0270b0ac8
                      (DAT_fffffff0270904c8,"CL4-rx",&local_68,&local_70,
                       *(undefined8 *)PTR_DAT_fffffff027090600,
                       *(undefined8 *)(PTR_DAT_fffffff027090600 + 8));
    if (iVar8 == 1) {
      if ((int)local_70 != 0x10) goto LAB_fffffff0270b37c4;
      if (local_68 != (undefined8 *)0x0) {
        FUN_fffffff0270d3fa0("CL4-rx",0x3f,*local_68,local_68[1] + 0x3fff >> 0xe,6);
      }
    }
    if (DAT_fffffff0270904c8 == 0) goto LAB_fffffff0270b37ac;
    local_68 = (undefined8 *)0x0;
    local_70 = (int *)((ulong)local_70 & 0xffffffff00000000);
    iVar8 = FUN_fffffff0270b0ac8
                      (DAT_fffffff0270904c8,"CL4-ro",&local_68,&local_70,
                       *(undefined8 *)PTR_DAT_fffffff027090600,
                       *(undefined8 *)(PTR_DAT_fffffff027090600 + 8));
    if (iVar8 == 1) {
      if ((int)local_70 != 0x10) goto LAB_fffffff0270b37c4;
      if (local_68 != (undefined8 *)0x0) {
        FUN_fffffff0270d3fa0("CL4-ro",0x3f,*local_68,local_68[1] + 0x3fff >> 0xe,6);
      }
    }
    if (DAT_fffffff0270904c8 == 0) goto LAB_fffffff0270b37ac;
    local_68 = (undefined8 *)0x0;
    local_70 = (int *)((ulong)local_70 & 0xffffffff00000000);
    iVar8 = FUN_fffffff0270b0ac8
                      (DAT_fffffff0270904c8,"CL4-rw",&local_68,&local_70,
                       *(undefined8 *)PTR_DAT_fffffff027090600,
                       *(undefined8 *)(PTR_DAT_fffffff027090600 + 8));
    if (iVar8 == 1) {
      if ((int)local_70 != 0x10) goto LAB_fffffff0270b37c4;
      if (local_68 != (undefined8 *)0x0) {
        FUN_fffffff0270d3fa0("CL4-rw",0x3f,*local_68,local_68[1] + 0x3fff >> 0xe,6);
      }
    }
    if (DAT_fffffff0270904c8 == 0) goto LAB_fffffff0270b37ac;
    local_68 = (undefined8 *)0x0;
    local_70 = (int *)((ulong)local_70 & 0xffffffff00000000);
    iVar8 = FUN_fffffff0270b0ac8
                      (DAT_fffffff0270904c8,"CL4-le",&local_68,&local_70,
                       *(undefined8 *)PTR_DAT_fffffff027090600,
                       *(undefined8 *)(PTR_DAT_fffffff027090600 + 8));
    if (iVar8 == 1) {
      if ((int)local_70 != 0x10) goto LAB_fffffff0270b37c4;
      if (local_68 != (undefined8 *)0x0) {
        FUN_fffffff0270d3fa0("CL4-le",0x3f,*local_68,local_68[1] + 0x3fff >> 0xe,6);
      }
    }
    if (DAT_fffffff0270904c8 == 0) goto LAB_fffffff0270b37ac;
    local_68 = (undefined8 *)0x0;
    local_70 = (int *)((ulong)local_70 & 0xffffffff00000000);
    iVar8 = FUN_fffffff0270b0ac8
                      (DAT_fffffff0270904c8,"CL4-dummypage",&local_68,&local_70,
                       *(undefined8 *)PTR_DAT_fffffff027090600,
                       *(undefined8 *)(PTR_DAT_fffffff027090600 + 8));
    if (iVar8 == 1) {
      if ((int)local_70 != 0x10) goto LAB_fffffff0270b37c4;
      if (local_68 != (undefined8 *)0x0) {
        FUN_fffffff0270d3fa0("CL4-dummypage",0x3f,*local_68,local_68[1] + 0x3fff >> 0xe,6);
      }
    }
    if (DAT_fffffff0270904c8 == 0) goto LAB_fffffff0270b37ac;
    local_68 = (undefined8 *)0x0;
    local_70 = (int *)((ulong)local_70 & 0xffffffff00000000);
    iVar8 = FUN_fffffff0270b0ac8
                      (DAT_fffffff0270904c8,"RAMDisk",&local_68,&local_70,
                       *(undefined8 *)PTR_DAT_fffffff027090600,
                       *(undefined8 *)(PTR_DAT_fffffff027090600 + 8));
    if (iVar8 == 1) {
      if ((int)local_70 != 0x10) goto LAB_fffffff0270b37c4;
      if (local_68 != (undefined8 *)0x0) {
        FUN_fffffff0270d3fa0("RAMDisk",0x23,*local_68,local_68[1] + 0x3fff >> 0xe,2);
      }
    }
    if (DAT_fffffff0270904c8 == 0) goto LAB_fffffff0270b37ac;
    local_68 = (undefined8 *)0x0;
    local_70 = (int *)((ulong)local_70 & 0xffffffff00000000);
    iVar8 = FUN_fffffff0270b0ac8
                      (DAT_fffffff0270904c8,"RTBuddySeg",&local_68,&local_70,
                       *(undefined8 *)PTR_DAT_fffffff027090600,
                       *(undefined8 *)(PTR_DAT_fffffff027090600 + 8));
    if (iVar8 == 1) {
      if ((int)local_70 != 0x10) goto LAB_fffffff0270b37c4;
      if (local_68 != (undefined8 *)0x0) {
        FUN_fffffff0270d3fa0("RTBuddySeg",0x23,*local_68,local_68[1] + 0x3fff >> 0xe,2);
      }
    }
    if (DAT_fffffff0270904c8 == 0) goto LAB_fffffff0270b37ac;
    local_68 = (undefined8 *)0x0;
    local_70 = (int *)((ulong)local_70 & 0xffffffff00000000);
    iVar8 = FUN_fffffff0270b0ac8
                      (DAT_fffffff0270904c8,"SEPFW",&local_68,&local_70,
                       *(undefined8 *)PTR_DAT_fffffff027090600,
                       *(undefined8 *)(PTR_DAT_fffffff027090600 + 8));
    if (iVar8 == 1) {
      if ((int)local_70 != 0x10) goto LAB_fffffff0270b37c4;
      if (local_68 != (undefined8 *)0x0) {
        FUN_fffffff0270d3fa0("SEPFW",0xb,*local_68,local_68[1] + 0x3fff >> 0xe,2);
      }
    }
    if (DAT_fffffff0270904c8 == 0) goto LAB_fffffff0270b37ac;
    local_68 = (undefined8 *)0x0;
    local_70 = (int *)((ulong)local_70 & 0xffffffff00000000);
    iVar8 = FUN_fffffff0270b0ac8
                      (DAT_fffffff0270904c8,"SEPPatches",&local_68,&local_70,
                       *(undefined8 *)PTR_DAT_fffffff027090600,
                       *(undefined8 *)(PTR_DAT_fffffff027090600 + 8));
    if (iVar8 == 1) {
      if ((int)local_70 != 0x10) goto LAB_fffffff0270b37c4;
      if (local_68 != (undefined8 *)0x0) {
        FUN_fffffff0270d3fa0("SEPPatches",0xb,*local_68,local_68[1] + 0x3fff >> 0xe,2);
      }
    }
    if (DAT_fffffff0270904c8 == 0) goto LAB_fffffff0270b37ac;
    local_68 = (undefined8 *)0x0;
    local_70 = (int *)((ulong)local_70 & 0xffffffff00000000);
    iVar8 = FUN_fffffff0270b0ac8
                      (DAT_fffffff0270904c8,"uStuff",&local_68,&local_70,
                       *(undefined8 *)PTR_DAT_fffffff027090600,
                       *(undefined8 *)(PTR_DAT_fffffff027090600 + 8));
    if (iVar8 == 1) {
      if ((int)local_70 != 0x10) goto LAB_fffffff0270b37c4;
      if (local_68 != (undefined8 *)0x0) {
        FUN_fffffff0270d3fa0("uStuff",0xb,*local_68,local_68[1] + 0x3fff >> 0xe,2);
      }
    }
    if (DAT_fffffff0270904c8 == 0) goto LAB_fffffff0270b37ac;
    local_68 = (undefined8 *)0x0;
    local_70 = (int *)((ulong)local_70 & 0xffffffff00000000);
    iVar8 = FUN_fffffff0270b0ac8
                      (DAT_fffffff0270904c8,"preoslog",&local_68,&local_70,
                       *(undefined8 *)PTR_DAT_fffffff027090600,
                       *(undefined8 *)(PTR_DAT_fffffff027090600 + 8));
    if (iVar8 == 1) {
      if ((int)local_70 != 0x10) goto LAB_fffffff0270b37c4;
      if (local_68 != (undefined8 *)0x0) {
        FUN_fffffff0270d3fa0("preoslog",0x23,*local_68,local_68[1] + 0x3fff >> 0xe,2);
      }
    }
    puVar12 = (undefined8 *)FUN_fffffff0270b0fa4("BootArgs",1);
    if (puVar12 != (undefined8 *)0x0) {
      FUN_fffffff0270d3fa0("BootArgs",0x23,*puVar12,puVar12[1] + 0x3fff >> 0xe,0);
    }
    if (DAT_fffffff0270904c8 == 0) goto LAB_fffffff0270b37ac;
    local_68 = (undefined8 *)0x0;
    local_70 = (int *)((ulong)local_70 & 0xffffffff00000000);
    iVar8 = FUN_fffffff0270b0ac8
                      (DAT_fffffff0270904c8,"SPTMDebug",&local_68,&local_70,
                       *(undefined8 *)PTR_DAT_fffffff027090600,
                       *(undefined8 *)(PTR_DAT_fffffff027090600 + 8));
    if (iVar8 == 1) {
      if ((int)local_70 != 0x10) goto LAB_fffffff0270b37c4;
      if (local_68 != (undefined8 *)0x0) {
        FUN_fffffff0270d3fa0("SPTMDebug",2,*local_68,local_68[1] + 0x3fff >> 0xe,2);
      }
    }
    if (DAT_fffffff0270904c8 == 0) goto LAB_fffffff0270b37ac;
    local_68 = (undefined8 *)0x0;
    local_70 = (int *)((ulong)local_70 & 0xffffffff00000000);
    iVar8 = FUN_fffffff0270b0ac8
                      (DAT_fffffff0270904c8,"ExclaveOSIntegrityCatalog",&local_68,&local_70,
                       *(undefined8 *)PTR_DAT_fffffff027090600,
                       *(undefined8 *)(PTR_DAT_fffffff027090600 + 8));
    if (iVar8 == 1) {
      if ((int)local_70 != 0x10) goto LAB_fffffff0270b37c4;
      if (local_68 != (undefined8 *)0x0) {
        FUN_fffffff0270d3fa0
                  ("ExclaveOSIntegrityCatalog",0x3f,*local_68,local_68[1] + 0x3fff >> 0xe,6);
      }
    }
    if (DAT_fffffff0270904c8 != 0) {
      local_68 = (undefined8 *)0x0;
      local_70 = (int *)((ulong)local_70 & 0xffffffff00000000);
      iVar8 = FUN_fffffff0270b0ac8
                        (DAT_fffffff0270904c8,"ExclaveOSTrustCache",&local_68,&local_70,
                         *(undefined8 *)PTR_DAT_fffffff027090600,
                         *(undefined8 *)(PTR_DAT_fffffff027090600 + 8));
      if (iVar8 == 1) {
        if ((int)local_70 != 0x10) {
LAB_fffffff0270b37c4:
                    /* WARNING: Subroutine does not return */
          FUN_fffffff0270f34fc("%s: DT property \'%s\' has illegal size %zu");
        }
        if (local_68 != (undefined8 *)0x0) {
          FUN_fffffff0270d3fa0("ExclaveOSTrustCache",0x3f,*local_68,local_68[1] + 0x3fff >> 0xe,6);
        }
      }
      DAT_fffffff0270fc730 = DAT_fffffff027090b30;
      FUN_fffffff0270d3fa0
                ("AVAILABLE",0xb,DAT_fffffff027090b30,
                 (ulong)((DAT_fffffff027090b28 - DAT_fffffff027090b30) +
                        DAT_fffffff027090b20 + 0x3fff) >> 0xe,0);
      plVar10 = (long *)FUN_fffffff0270b0fa4("TXM-ro",1);
      FUN_fffffff0270d3fa0
                ("PHYS_SLIDE",0x23,DAT_fffffff027090b20,
                 (*plVar10 - DAT_fffffff027090b20) + 0x3fffU >> 0xe,2);
      uVar7 = DAT_fffffff027102040 | 8;
      LORelease();
      uVar13 = (uint)DAT_fffffff027102040;
      DAT_fffffff027102040 = uVar7;
      if ((uVar13 >> 3 & 1) == 0) {
        uVar6 = id_aa64pfr1_el1;
        uVar7 = id_aa64pfr0_el1;
        if ((uVar6 & 0xf00000000) == 0x200000000 || (uVar7 & 0xf00000000000000) == 0x200000000000000
           ) {
          DAT_fffffff0270921b1 = 1;
        }
        uVar7 = id_aa64mmfr1_el1;
        DAT_fffffff0270921b2 = (uVar7 & 0xf0000000000) != 0;
        FUN_fffffff0270d4730
                  (DAT_fffffff027090b18,DAT_fffffff027090b20,DAT_fffffff0270fc730,
                   DAT_fffffff027090b28,PTR_DAT_fffffff027090600);
        thunk_FUN_fffffff0270a3d9c();
        FUN_fffffff0270a3ed8(&DAT_fffffff027102080);
        if ((DAT_fffffff0270fd028 & 1) != 0) {
          DAT_fffffff0270fd028 = 0;
        }
        FUN_fffffff0270b39b4(&DAT_fffffff027102080);
        puVar12 = (undefined8 *)FUN_fffffff0270b0fa4("slide",1);
        DAT_fffffff027090518 = *puVar12;
        DAT_fffffff027090510 = &UNK_fffffff027098000 + (DAT_fffffff027090b20 - DAT_fffffff027090b18)
        ;
        DAT_fffffff027102081 = 1;
        FUN_fffffff0270d841c(DAT_fffffff027090b20,DAT_fffffff027090b28,PTR_DAT_fffffff027090600);
        DAT_fffffff0270fc730 =
             DAT_fffffff0270921c8 +
             (ulong)(uint)(DAT_fffffff027090fcc + DAT_fffffff027090fc8) * 0x4000;
        plVar10 = (long *)FUN_fffffff0270b0fa4("CL4-entry",1);
        lVar9 = *plVar10;
        plVar10 = (long *)FUN_fffffff0270b0fa4("CL4-rx",1);
        lVar20 = *plVar10;
        plVar10 = (long *)FUN_fffffff0270b0fa4("CL4-virt",1);
        DAT_fffffff0270904b0 = (lVar20 + lVar9) - *plVar10;
        plVar10 = (long *)FUN_fffffff0270b0fa4("TXM-entry",1);
        lVar20 = *plVar10;
        puVar12 = (undefined8 *)FUN_fffffff0270b0fa4("TXM-ro",1);
        lVar9 = FUN_fffffff0270d260c(*puVar12);
        plVar10 = (long *)FUN_fffffff0270b0fa4("TXM-virt",1);
        DAT_fffffff0270904b8 = (lVar9 + lVar20) - *plVar10;
        plVar10 = (long *)FUN_fffffff0270b0fa4("BootKC-entry",1);
        lVar20 = *plVar10;
        puVar12 = (undefined8 *)FUN_fffffff0270b0fa4("BootKC-ro",1);
        lVar9 = FUN_fffffff0270d260c(*puVar12);
        plVar10 = (long *)FUN_fffffff0270b0fa4("BootKC-virt",1);
        DAT_fffffff0270904c0 = (lVar9 + lVar20) - *plVar10;
        FUN_fffffff0270e1754(0,FUN_fffffff0270e2414,2);
        FUN_fffffff0270e1754(1,FUN_fffffff0270e2414,4);
        FUN_fffffff0270e1754(2,FUN_fffffff0270e2414,8);
        if ((DAT_fffffff0270fc738 & 1) != 0) {
          FUN_fffffff0270e1754(10,FUN_fffffff0270e2414,0x10);
        }
        uVar7 = DAT_fffffff027102040 | 0x40000;
        LORelease();
        uVar13 = (uint)DAT_fffffff027102040;
        DAT_fffffff027102040 = uVar7;
        if ((uVar13 >> 0x12 & 1) == 0) {
          local_68 = (undefined8 *)0x0;
          iVar8 = FUN_fffffff0270b08b0(PTR_DAT_fffffff027090600,0,"/product",&local_68);
          if (iVar8 != 1) {
                    /* WARNING: Subroutine does not return */
            FUN_fffffff0270f34fc("%s: Error looking up /product");
          }
          local_70 = (int *)0x0;
          iVar8 = FUN_fffffff0270b0ac8
                            (local_68,"exclaves-enabled",&local_70,&local_78,
                             *(undefined8 *)PTR_DAT_fffffff027090600,
                             *(undefined8 *)(PTR_DAT_fffffff027090600 + 8));
          FUN_fffffff0270bb1e0("POE2 is disabled.\n");
          if ((iVar8 == 1) && (DAT_fffffff0270904b0 != -1)) {
            DAT_fffffff027090498 = *local_70 != 0;
            if (*local_70 != 0) {
              FUN_fffffff0270bb1e0("Starting SK...");
              FUN_fffffff0270b3e48();
              FUN_fffffff0270d2f50(&DAT_fffffff027090360);
              FUN_fffffff02709af04();
                    /* WARNING: Does not return */
              pcVar4 = (code *)SoftwareBreakpoint(1,0xfffffff0270b3878);
              (*pcVar4)();
            }
          }
          else {
            DAT_fffffff027090498 = false;
          }
          FUN_fffffff0270b1158();
          FUN_fffffff0270bb1e0("Starting TXM...");
          FUN_fffffff0270b3f68();
          FUN_fffffff02709adf4(&DAT_fffffff0270fc108);
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(1,0xfffffff0270b38a4);
          (*pcVar4)();
        }
      }
LAB_fffffff0270b36ec:
                    /* WARNING: Subroutine does not return */
      FUN_fffffff0270f34fc
                ("%s: Attempted to announce bootstrap stage that has already been reached %p %p");
    }
  }
LAB_fffffff0270b37ac:
                    /* WARNING: Subroutine does not return */
  FUN_fffffff0270f34fc("%s: DT memory-map is NULL");
}

