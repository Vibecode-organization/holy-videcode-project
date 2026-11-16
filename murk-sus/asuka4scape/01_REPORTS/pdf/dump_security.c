/* ==== _PDFSecurityHandlerCreate @ 183caee70 size=3764 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long * _PDFSecurityHandlerCreate(long param_1,long *param_2)

{
  bool bVar1;
  long *plVar2;
  cfstringStruct *pcVar3;
  int iVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  int iVar11;
  long lVar12;
  long *plVar13;
  long lVar14;
  long lVar15;
  long lVar16;
  ulong uVar17;
  ulong uVar18;
  long lVar19;
  cfstringStruct *pcVar20;
  char *pcVar21;
  ulong uVar22;
  undefined8 uVar23;
  uint uVar24;
  uint uVar25;
  undefined8 *puVar26;
  uint *puVar27;
  long *plVar28;
  int local_108;
  undefined4 uStack_104;
  long lStack_100;
  long local_f8;
  long lStack_f0;
  uint local_e4;
  undefined4 uStack_e0;
  long lStack_dc;
  long local_d4;
  long lStack_cc;
  byte local_c0 [16];
  undefined4 local_b0 [4];
  long local_a0;
  long lStack_98;
  long lStack_90;
  long lStack_88;
  undefined4 local_80;
  undefined1 local_7c;
  long local_70;
  
  local_70 = *_DAT_1e0186220;
  if ((param_1 != 0) &&
     ((lVar12 = __Z27CGCFDictionaryGetTypedValueIPK10__CFStringET_PK14__CFDictionaryS2_
                          (param_1,&cfstringStruct_1e2245d20), lVar12 == 0 ||
      (iVar11 = func_0x000188140cb0(lVar12,&cfstringStruct_1e2245d40), iVar11 == 0)))) {
    if ((*param_2 == 0) || ((param_2[1] == 0 || (param_2[2] == 0)))) {
                    /* WARNING: Subroutine does not return */
      FUN_183c19214("create",0xd2,
                    "/Library/Caches/com.apple.xbs/418A84E5-A935-45BB-BEF3-31726BD24C5D/TemporaryDirectory.myKecQ/Sources/CoreGraphics/CoreGraphicsRIP/PDF/Encryption/PDFSecurityHandler.cpp"
                    ,"0","Required parameter is NULL");
    }
    plVar13 = (long *)func_0x00018814d110(0x128,0x10e0c4008a5779d);
    plVar28 = plVar13 + 0x12;
    *plVar28 = 0;
    plVar13[0x15] = 0;
    plVar13[0x13] = 0;
    *(undefined1 *)(plVar13 + 0x16) = 1;
    puVar26 = (undefined8 *)((long)plVar13 + 0xb1);
    *(undefined8 *)((long)plVar13 + 0xb9) = 0;
    *puVar26 = 0;
    *(undefined4 *)(plVar13 + 0x14) = 0;
    *(undefined8 *)((long)plVar13 + 0xc9) = 0;
    *(undefined8 *)((long)plVar13 + 0xc1) = 0;
    *(undefined1 *)((long)plVar13 + 0x121) = 0;
    plVar13[1] = 0;
    *plVar13 = 0;
    plVar13[3] = 0;
    plVar13[2] = 0;
    plVar13[5] = 0;
    plVar13[4] = 0;
    plVar13[7] = 0;
    plVar13[6] = 0;
    plVar13[9] = 0;
    plVar13[8] = 0;
    plVar13[0xb] = 0;
    plVar13[10] = 0;
    plVar13[0xd] = 0;
    plVar13[0xc] = 0;
    plVar13[0xf] = 0;
    plVar13[0xe] = 0;
    plVar13[0x10] = 0;
    lVar12 = func_0x000188141250(param_1);
    *plVar28 = lVar12;
    lVar12 = func_0x000188138000(*param_2);
    *plVar13 = lVar12;
    lVar12 = func_0x000188138000(param_2[1]);
    plVar13[1] = lVar12;
    lVar12 = func_0x000188138000(param_2[2]);
    plVar13[2] = lVar12;
    lVar12 = __Z27CGCFDictionaryGetTypedValueIPK8__CFDataET_PK14__CFDictionaryPK10__CFString
                       (*plVar28,&cfstringStruct_1e2245dc0);
    lVar14 = __Z27CGCFDictionaryGetTypedValueIPK8__CFDataET_PK14__CFDictionaryPK10__CFString
                       (*plVar28,&cfstringStruct_1e2245de0);
    lVar15 = __Z27CGCFDictionaryGetTypedValueIPK8__CFDataET_PK14__CFDictionaryPK10__CFString
                       (*plVar28,&cfstringStruct_1e2245e00);
    lVar16 = __Z27CGCFDictionaryGetTypedValueIPK11__CFBooleanET_PK14__CFDictionaryPK10__CFString
                       (*plVar28,&cfstringStruct_1e2245e20);
    bVar6 = lVar12 == 0;
    bVar7 = lVar14 == 0;
    bVar8 = lVar15 == 0;
    bVar9 = lVar16 != 0;
    if (((!bVar6 && !bVar7) && !bVar8) && bVar9) {
      uVar17 = func_0x000188140ab0(lVar12);
      uVar18 = func_0x000188140ab0(lVar14);
      lVar19 = func_0x000188140ab0(lVar15);
      if ((((uVar17 & 0xffffffffffffffef) == 0x20) && ((uVar18 & 0xffffffffffffffef) == 0x20)) &&
         (lVar19 < 0x21)) {
        iVar11 = func_0x000188140690(lVar16);
        *(bool *)(plVar13 + 0x16) = iVar11 != 0;
        goto LAB_183caf080;
      }
      _pdf_error("Unexpected data size for encryption parameter(s)");
      goto LAB_183caf700;
    }
    if (((lVar12 != 0) || (lVar14 != 0)) || ((lVar15 != 0 || (lVar16 != 0)))) {
      _pdf_error("Invalid combination of encryption options");
    }
LAB_183caf080:
    lVar16 = __Z27CGCFDictionaryGetTypedValueIPK10__CFStringET_PK14__CFDictionaryS2_
                       (*plVar28,&cfstringStruct_1e2245d20);
    if (lVar16 == 0) {
      *(undefined4 *)(plVar13 + 0x13) = 0;
LAB_183caf0e4:
      local_e4 = 0;
      lVar16 = __Z27CGCFDictionaryGetTypedValueIPK10__CFNumberET_PK14__CFDictionaryPK10__CFString
                         (plVar13[0x12],&cfstringStruct_1e2245ce0);
      if (lVar16 == 0) {
LAB_183caf110:
        if ((DAT_1eb0574c0 & 1) == 0) {
          func_0x000188143c80(&DAT_1eb056010,_handleDefaults);
        }
        puVar27 = &DAT_1eb055324;
      }
      else {
        puVar27 = &local_e4;
        iVar11 = func_0x000188141030(lVar16,9,&local_e4);
        if (iVar11 == 0) goto LAB_183caf110;
      }
      uVar25 = *puVar27;
      plVar13[0x15] = (long)(int)uVar25;
      if ((0x58 < (long)(int)uVar25 - 0x28U) || ((uVar25 & 7) != 0)) {
        _pdf_error("invalid encryption key length: %zu.");
        plVar13[0x15] = 0x28;
      }
      if ((int)plVar13[0x13] == 2) {
        uVar23 = 0x500000005;
      }
      else {
        if ((int)plVar13[0x13] == 1) goto LAB_183caf18c;
        uVar23 = 0x300000002;
      }
LAB_183caf190:
      *(undefined8 *)((long)plVar13 + 0x9c) = uVar23;
      if (((!bVar6 && !bVar7) && !bVar8) && bVar9) goto LAB_183caf198;
      iVar11 = (int)((ulong)uVar23 >> 0x20);
    }
    else {
      iVar11 = func_0x000188140cb0(lVar16,&cfstringStruct_1e2245d80);
      if (iVar11 != 0) {
        *(undefined4 *)(plVar13 + 0x13) = 1;
LAB_183caf0b4:
        plVar13[0x15] = 0x80;
LAB_183caf18c:
        uVar23 = 0x400000004;
        goto LAB_183caf190;
      }
      iVar11 = func_0x000188140cb0(lVar16,&cfstringStruct_1e2245da0);
      plVar2 = plVar13 + 0x13;
      if (iVar11 == 0) {
        *(undefined4 *)plVar2 = 0;
        goto LAB_183caf0e4;
      }
      *(undefined4 *)plVar2 = 2;
      if (((bVar6 || bVar7) || bVar8) || !bVar9) {
        func_0x00018813b8c0(
                           "Warning: Downgrading AES-256 (V=5) to AES-128 (V=4) for new file creation."
                           );
        *(undefined4 *)plVar2 = 1;
        goto LAB_183caf0b4;
      }
      plVar13[0x15] = 0x100;
      *(undefined8 *)((long)plVar13 + 0x9c) = 0x500000005;
LAB_183caf198:
      local_e4 = 0;
      local_108 = 0;
      lVar16 = __Z27CGCFDictionaryGetTypedValueIPK10__CFNumberET_PK14__CFDictionaryPK10__CFString
                         (plVar13[0x12],&cfstringStruct_1e2245e40);
      if (lVar16 == 0) {
        bVar10 = false;
      }
      else {
        iVar11 = func_0x000188141030(lVar16,9,&local_e4);
        bVar10 = iVar11 != 0;
      }
      lVar16 = __Z27CGCFDictionaryGetTypedValueIPK10__CFNumberET_PK14__CFDictionaryPK10__CFString
                         (*plVar28,&cfstringStruct_1e2245e60);
      if (lVar16 == 0) {
        iVar11 = 0;
        bVar1 = false;
      }
      else {
        iVar11 = func_0x000188141030(lVar16,9,&local_108);
        bVar1 = iVar11 != 0 && local_108 - 2U < 5;
        iVar11 = local_108;
      }
      iVar4 = (int)plVar13[0x13];
      if (iVar4 == 2) {
        bVar5 = local_e4 == 5;
LAB_183caf2ac:
        if ((!(bool)(bVar10 & bVar1)) || (!bVar5)) goto LAB_183caf2c4;
        *(uint *)((long)plVar13 + 0x9c) = local_e4;
        *(int *)(plVar13 + 0x14) = iVar11;
      }
      else {
        if (iVar4 == 1) {
          bVar5 = local_e4 == 4;
          goto LAB_183caf2ac;
        }
        if (iVar4 == 0) {
          bVar5 = local_e4 - 1 < 2;
          goto LAB_183caf2ac;
        }
LAB_183caf2c4:
        if (bVar10 || bVar1) {
          pcVar21 = 
          "%s: ignoring /V %d /R %d, which does not describe the requested cipher; writing /V %d /R %d"
          ;
        }
        else {
          pcVar21 = 
          "%s: reproducing an existing encryption with no /V or /R supplied; writing /V %d /R %d, which will not match hashed passwords computed under a different revision"
          ;
        }
        _pdf_error(pcVar21);
      }
      iVar11 = (int)plVar13[0x14];
    }
    if (iVar11 == 2) {
      uVar23 = 4;
LAB_183caf33c:
      (**(code **)(plVar13[2] + 0x10))(plVar13[2],1,uVar23);
    }
    else {
      if (iVar11 == 4) {
        uVar23 = 6;
        goto LAB_183caf33c;
      }
      if (4 < iVar11) {
        uVar23 = 7;
        goto LAB_183caf33c;
      }
    }
    lVar16 = __Z27CGCFDictionaryGetTypedValueIPK10__CFNumberET_PK14__CFDictionaryPK10__CFString
                       (*plVar28,&cfstringStruct_1e2245d00);
    if ((lVar16 != 0) && (iVar11 = func_0x000188141030(lVar16,3,plVar13 + 0x11), iVar11 != 0)) {
      uVar25 = *(uint *)(plVar13 + 0x11) & 0xfffffffc;
      if ((int)plVar13[0x14] == 2) {
        uVar25 = uVar25 | 0x55555540;
        uVar24 = 0xaa80;
      }
      else {
        uVar24 = uVar25 | 0x11111000;
        uVar25 = CONCAT13((char)(uVar24 >> 0x18),
                          CONCAT12((char)(uVar24 >> 0x10),CONCAT11((char)(uVar24 >> 8),(char)uVar25)
                                  )) | 0x444440c0;
        uVar24 = 0xa000;
      }
      *(uint *)(plVar13 + 0x11) = uVar25 | uVar24 | 0xaaaa0000;
      if (((bVar6 || bVar7) || bVar8) || !bVar9) goto LAB_183caf4cc;
LAB_183caf628:
      uVar17 = func_0x000188140ab0(lVar12);
      uVar18 = func_0x000188140ab0(lVar14);
      uVar22 = func_0x000188140ab0(lVar15);
      if ((((long)uVar17 < 0) || ((long)uVar18 < 0)) || ((long)uVar22 < 0)) {
        pcVar21 = "Invalid (negative) encryption parameter size";
LAB_183caf6f8:
        _pdf_error(pcVar21);
        goto LAB_183caf700;
      }
      if (((0x30 < uVar17) || (0x30 < uVar18)) || (0x20 < uVar22)) {
        pcVar21 = "Unexpected data size for encryption parameter(s)";
        goto LAB_183caf6f8;
      }
      func_0x000188147c60(lVar12,0,uVar17,plVar13 + 3);
      func_0x000188147c60(lVar14,0,uVar18,plVar13 + 9);
      func_0x000188147c60(lVar15,0,uVar22,puVar26);
      if (uVar17 == 0x30) {
        if (*(int *)((long)plVar13 + 0x9c) < 5) {
          *(undefined4 *)((long)plVar13 + 0x9c) = 5;
        }
        if ((int)plVar13[0x14] < 5) {
          *(undefined4 *)(plVar13 + 0x14) = 5;
        }
LAB_183caf788:
        lVar12 = __Z27CGCFDictionaryGetTypedValueIPK8__CFDataET_PK14__CFDictionaryPK10__CFString
                           (*plVar28,&cfstringStruct_1e22434a0);
        lVar14 = __Z27CGCFDictionaryGetTypedValueIPK8__CFDataET_PK14__CFDictionaryPK10__CFString
                           (*plVar28,&cfstringStruct_1e22434c0);
        lVar15 = __Z27CGCFDictionaryGetTypedValueIPK8__CFDataET_PK14__CFDictionaryPK10__CFString
                           (*plVar28,&cfstringStruct_1e22434e0);
        if (lVar15 == 0) {
          lVar15 = __Z27CGCFDictionaryGetTypedValueIPK10__CFStringET_PK14__CFDictionaryS2_
                             (*plVar28,&cfstringStruct_1e22434e0);
          if ((lVar15 != 0) && (lVar16 = func_0x000188141800(), lVar16 == 0x10)) {
            func_0x0001881417a0(lVar15,0,0x10,0x201,0,0,(long)plVar13 + 0x111,0x10,0);
            goto LAB_183caf838;
          }
        }
        else {
          lVar16 = func_0x000188140ab0();
          if (lVar16 == 0x10) {
            func_0x000188147c60(lVar15,0,0x10,(long)plVar13 + 0x111);
LAB_183caf838:
            if ((lVar12 != 0) && (lVar14 != 0)) {
              lVar15 = func_0x000188140ab0(lVar12);
              if (lVar15 == 0x20) {
                func_0x000188147c60(lVar12,0,0x20,(long)plVar13 + 0xd1);
              }
              lVar12 = func_0x000188140ab0(lVar14);
              if (lVar12 == 0x20) {
                func_0x000188147c60(lVar14,0,0x20,(long)plVar13 + 0xf1);
              }
              *(undefined1 *)((long)plVar13 + 0x121) = 1;
              goto LAB_183cafca0;
            }
          }
        }
        func_0x00018813b8c0("Warning: Missing /UE, /OE, or /Perms for AESv3 pass-through.");
      }
      else if (4 < *(int *)((long)plVar13 + 0x9c)) goto LAB_183caf788;
LAB_183cafca0:
      if ((int)plVar13[0x13] - 1U < 2) {
        func_0x000188138280(plVar13 + 0xf,0x10);
      }
      else {
        plVar13[0xf] = 0;
        plVar13[0x10] = 0;
      }
      goto LAB_183caf714;
    }
    local_e4 = 0;
    lVar16 = __Z27CGCFDictionaryGetTypedValueIPK10__CFNumberET_PK14__CFDictionaryPK10__CFString
                       (*plVar28,&cfstringStruct_1e2245ec0);
    if ((lVar16 == 0) || (iVar11 = func_0x000188141030(lVar16,3,&local_e4), iVar11 == 0)) {
      *(undefined4 *)(plVar13 + 0x11) = 0;
      lVar16 = __Z27CGCFDictionaryGetTypedValueIPK11__CFBooleanET_PK14__CFDictionaryPK10__CFString
                         (plVar13[0x12],&cfstringStruct_1e2245c80);
      if ((lVar16 == 0) || (iVar11 = func_0x000188140690(), iVar11 != 0)) {
        uVar25 = *(uint *)(plVar13 + 0x11) | 4;
        bVar10 = true;
      }
      else {
        bVar10 = false;
        uVar25 = *(uint *)(plVar13 + 0x11);
      }
      *(uint *)(plVar13 + 0x11) = uVar25 | 8;
      lVar16 = __Z27CGCFDictionaryGetTypedValueIPK11__CFBooleanET_PK14__CFDictionaryPK10__CFString
                         (plVar13[0x12],&cfstringStruct_1e2245ca0);
      if ((lVar16 == 0) || (iVar11 = func_0x000188140690(), iVar11 != 0)) {
        uVar25 = *(uint *)(plVar13 + 0x11) | 0x1f0;
LAB_183caf5d4:
        uVar25 = uVar25 | 0x200;
      }
      else {
        uVar25 = *(uint *)(plVar13 + 0x11) | 0x1e0;
        if ((int)plVar13[0x14] == 2) goto LAB_183caf5d4;
      }
      if ((bVar10) || ((int)plVar13[0x14] == 2)) {
        uVar25 = uVar25 | 0xc00;
      }
      else {
        uVar25 = uVar25 | 0x400;
      }
      uVar25 = uVar25 | 0x11111000;
    }
    else {
      if ((int)plVar13[0x14] < 3) {
                    /* WARNING: Subroutine does not return */
        FUN_183c19214("parsePermissions",0x1a3,
                      "/Library/Caches/com.apple.xbs/418A84E5-A935-45BB-BEF3-31726BD24C5D/TemporaryDirectory.myKecQ/Sources/CoreGraphics/CoreGraphicsRIP/PDF/Encryption/PDFSecurityHandler.cpp"
                      ,"_revision > 2","revision (%d) too old?");
      }
      uVar24 = (local_e4 & 4) << 4 | local_e4 >> 1 & 1 | (local_e4 >> 4 & 1) << 5 | local_e4;
      uVar25 = 0xc0;
      if (((local_e4 | uVar24 << 1) & 0x80) != 0) {
        uVar25 = 0x1c0;
      }
      uVar25 = (local_e4 & 4) << 1 | (uVar24 & 1) << 2 | local_e4 & 0x10 | uVar24 >> 1 & 0x20 |
               uVar25 | (uVar24 >> 5 & 1) << 9 | (local_e4 >> 3 & 1) << 10 |
               (local_e4 & 2) << 10 | 0x11111000;
    }
    *(uint *)(plVar13 + 0x11) = uVar25 | 0xeeeee000;
    if (((!bVar6 && !bVar7) && !bVar8) && bVar9) goto LAB_183caf628;
LAB_183caf4cc:
    if (*(int *)((long)plVar13 + 0x9c) < 5) {
      lVar12 = __Z27CGCFDictionaryGetTypedValueIPK10__CFStringET_PK14__CFDictionaryS2_
                         (*plVar28,&cfstringStruct_1e2245c40);
      if ((lVar12 != 0) &&
         (uVar17 = __ZN18PDFSecurityHandler16getPasswordBytesEPK10__CFStringPh(lVar12,&local_e4),
         (uVar17 & 1) != 0)) {
        pcVar20 = (cfstringStruct *)
                  __Z27CGCFDictionaryGetTypedValueIPK10__CFStringET_PK14__CFDictionaryS2_
                            (*plVar28,&cfstringStruct_1e2245c60);
        pcVar3 = &cfstringStruct_1e2241180;
        if (pcVar20 != (cfstringStruct *)0x0) {
          pcVar3 = pcVar20;
        }
        uVar17 = __ZN18PDFSecurityHandler16getPasswordBytesEPK10__CFStringPh(pcVar3,&local_108);
        if ((uVar17 & 1) != 0) {
          if ((char)local_e4 == '\0') {
            _pdf_error("no owner password specified; substituting user password.");
            func_0x00018814d5d0(&local_e4,&local_108);
          }
          uVar17 = func_0x0001881386f0(&local_e4);
          if (uVar17 < 0x20) {
            func_0x0001881384d0(&local_a0,&local_e4,uVar17);
            func_0x0001881384d0((long)&local_a0 + uVar17,kPad,0x20 - uVar17);
          }
          else {
            local_a0 = CONCAT44(uStack_e0,local_e4);
            lStack_98 = lStack_dc;
            lStack_88 = lStack_cc;
            lStack_90 = local_d4;
          }
          FUN_183f9931c(&local_80,&local_a0,0x20);
          uVar18 = plVar13[0x15];
          uVar17 = uVar18 >> 3;
          if (2 < (int)plVar13[0x14]) {
            iVar11 = 0x32;
            do {
              FUN_183f9931c(&local_80,&local_80,uVar17);
              iVar11 = iVar11 + -1;
            } while (iVar11 != 0);
          }
          func_0x0001881384d0(local_b0,&local_80,uVar17);
          uVar22 = func_0x0001881386f0(&local_108);
          if (uVar22 < 0x20) {
            func_0x0001881384d0(&local_a0,&local_108,uVar22);
            func_0x0001881384d0((long)&local_a0 + uVar22,kPad,0x20 - uVar22);
          }
          else {
            local_a0 = CONCAT44(uStack_104,local_108);
            lStack_98 = lStack_100;
            lStack_88 = lStack_f0;
            lStack_90 = local_f8;
          }
          uVar23 = FUN_183de7a14(local_b0,uVar17);
          FUN_183de7c8c(uVar23,&local_a0,0x20,&local_a0,0x20,0);
          FUN_183de7b60(uVar23);
          if (2 < (int)plVar13[0x14]) {
            iVar11 = 1;
            do {
              if (7 < uVar18) {
                lVar12 = 0;
                uVar22 = uVar17;
                do {
                  local_c0[lVar12] = *(byte *)((long)local_b0 + lVar12) ^ (byte)iVar11;
                  lVar12 = lVar12 + 1;
                  uVar22 = uVar22 - 1;
                } while (uVar22 != 0);
              }
              uVar23 = FUN_183de7a14(local_c0,uVar17);
              FUN_183de7c8c(uVar23,&local_a0,0x20,&local_a0,0x20,0);
              FUN_183de7b60(uVar23);
              iVar11 = iVar11 + 1;
            } while (iVar11 != 0x14);
          }
          plVar13[4] = lStack_98;
          plVar13[3] = local_a0;
          plVar13[6] = lStack_88;
          plVar13[5] = lStack_90;
          lVar12 = (**(code **)(*plVar13 + 0x10))(*plVar13,0);
          uVar17 = func_0x0001881386f0(&local_108);
          if (uVar17 < 0x20) {
            func_0x0001881384d0(&local_a0,&local_108,uVar17);
            func_0x0001881384d0((long)&local_a0 + uVar17,kPad,0x20 - uVar17);
          }
          else {
            local_a0 = CONCAT44(uStack_104,local_108);
            lStack_98 = lStack_100;
            lStack_88 = lStack_f0;
            lStack_90 = local_f8;
          }
          lVar14 = func_0x000188138470(0x5c,0x100004034a301b9);
          func_0x00018814c300();
          if (lVar14 != 0) {
            func_0x00018814c310(lVar14,&local_a0,0x20);
            func_0x00018814c310(lVar14,plVar13 + 3,0x20);
          }
          local_b0[0] = (undefined4)plVar13[0x11];
          if ((lVar14 != 0) && (func_0x00018814c310(lVar14,local_b0,4), lVar12 != 0)) {
            func_0x00018814c310(lVar14,lVar12,0x10);
          }
          if (((3 < (int)plVar13[0x14]) && ((*(byte *)(plVar13 + 0x16) & 1) == 0)) &&
             (local_80 = 0xffffffff, lVar14 != 0)) {
            func_0x00018814c310(lVar14,&local_80,4);
          }
          if (lVar14 != 0) {
            func_0x00018814c2f0(&local_80,lVar14);
          }
          func_0x000188138390(lVar14);
          if ((int)plVar13[0x14] < 3) {
LAB_183cafb80:
            *(undefined4 *)puVar26 = local_80;
            *(undefined1 *)((long)plVar13 + 0xb5) = local_7c;
          }
          else {
            uVar17 = plVar13[0x15];
            iVar11 = 0x32;
            do {
              FUN_183f9931c(&local_80,&local_80,uVar17 >> 3);
              iVar11 = iVar11 + -1;
            } while (iVar11 != 0);
            if ((int)plVar13[0x14] < 3) goto LAB_183cafb80;
            func_0x0001881384d0(puVar26,&local_80,uVar17 >> 3);
          }
          uVar18 = plVar13[0x15];
          uVar17 = uVar18 >> 3;
          lVar14 = func_0x000188138470(0x5c,0x100004034a301b9);
          func_0x00018814c300();
          if (lVar14 != 0) {
            func_0x00018814c310(lVar14,kPad,0x20);
            if (lVar12 != 0) {
              func_0x00018814c310(lVar14,lVar12,0x10);
            }
            func_0x00018814c2f0(&local_a0,lVar14);
          }
          func_0x000188138390(lVar14);
          uVar23 = FUN_183de7a14(puVar26,uVar17);
          FUN_183de7c8c(uVar23,&local_a0,0x10,&local_a0,0x10,0);
          FUN_183de7b60(uVar23);
          if (2 < (int)plVar13[0x14]) {
            iVar11 = 1;
            do {
              if (7 < uVar18) {
                lVar12 = 0;
                uVar22 = uVar17;
                do {
                  *(byte *)((long)&local_80 + lVar12) =
                       *(byte *)((long)puVar26 + lVar12) ^ (byte)iVar11;
                  lVar12 = lVar12 + 1;
                  uVar22 = uVar22 - 1;
                } while (uVar22 != 0);
              }
              uVar23 = FUN_183de7a14(&local_80,uVar17);
              FUN_183de7c8c(uVar23,&local_a0,0x10,&local_a0,0x10,0);
              FUN_183de7b60(uVar23);
              iVar11 = iVar11 + 1;
            } while (iVar11 != 0x14);
          }
          plVar13[10] = lStack_98;
          plVar13[9] = local_a0;
          plVar13[0xb] = 0;
          plVar13[0xc] = 0;
          goto LAB_183cafca0;
        }
      }
    }
    else {
      _pdf_error("Error: AES-256 (V=5) key generation is not supported. Use AES-128.");
    }
LAB_183caf700:
    uVar23 = __ZN18PDFSecurityHandlerD2Ev(plVar13);
    func_0x00018814d0e0(uVar23,0x10e0c4008a5779d);
  }
  plVar13 = (long *)0x0;
LAB_183caf714:
  if (*_DAT_1e0186220 == local_70) {
    return plVar13;
  }
  plVar13 = (long *)func_0x000188138130();
  return plVar13;
}



/* ==== _CGPDFSecurityManagerCreateCryptFilter @ 183e191a4 size=572 ==== */

long * _CGPDFSecurityManagerCreateCryptFilter(long param_1,long param_2)

{
  long lVar1;
  int iVar2;
  char *pcVar3;
  long *plVar4;
  undefined4 uVar5;
  ulong uVar6;
  long local_50;
  ulong local_48;
  char *local_40;
  char *local_38;
  
  if (param_2 == 0) {
    return (long *)0x0;
  }
  iVar2 = func_0x0001881386b0(param_2,"Identity");
  if (iVar2 == 0) {
    plVar4 = (long *)func_0x000188138460(1,0x18,0x10200409b6930f5);
    func_0x000188142e40(plVar4,"CGPDFNamedAlloc_Security");
    if (plVar4 != (long *)0x0) {
      *plVar4 = param_1;
      *(undefined1 *)((long)plVar4 + 0xc) = 1;
      *(undefined4 *)(plVar4 + 1) = 0;
      plVar4[2] = 0;
      return plVar4;
    }
    return (long *)0x0;
  }
  local_50 = 0;
  iVar2 = FUN_183bd75c4(*(undefined8 *)(param_1 + 0x18),param_2,&local_50);
  lVar1 = local_50;
  if (iVar2 == 0) {
    return (long *)0x0;
  }
  if (local_50 == 0) {
    return (long *)0x0;
  }
  local_40 = (char *)0x0;
  local_38 = (char *)0x0;
  local_48 = 0;
  iVar2 = FUN_183bd1218(local_50,"CFM",&local_38);
  pcVar3 = local_38;
  if (iVar2 == 0) {
    pcVar3 = "None";
  }
  if (((*pcVar3 == 'V') && (pcVar3[1] == '2')) && (pcVar3[2] == '\0')) {
    uVar5 = 1;
  }
  else {
    iVar2 = func_0x0001881386b0(pcVar3,"AESV2");
    if (iVar2 == 0) {
      uVar5 = 2;
    }
    else {
      iVar2 = func_0x0001881386b0(pcVar3,"AESV3");
      if (iVar2 != 0) {
        pcVar3 = "unsupported crypt filter `CFM\' value `%s\'.";
        goto LAB_183e19378;
      }
      uVar5 = 3;
    }
  }
  iVar2 = FUN_183bd6c4c(lVar1,"Length",&local_48);
  if (iVar2 == 0) {
    uVar6 = 0x80;
  }
  else {
    uVar6 = local_48 << 3;
    if (0x1b < local_48 - 5) {
      uVar6 = local_48;
    }
  }
  if ((uVar6 - 0x28 < 0xd9) && ((uVar6 & 7) == 0)) {
    iVar2 = FUN_183bd1218(lVar1,"AuthEvent",&local_40);
    pcVar3 = local_40;
    if (iVar2 == 0) {
      pcVar3 = "DocOpen";
    }
    iVar2 = func_0x0001881386b0(pcVar3);
    if (iVar2 == 0) {
      plVar4 = (long *)func_0x000188138460(1,0x18,0x10200409b6930f5);
      func_0x000188142e40(plVar4,"CGPDFNamedAlloc_Security");
      if (plVar4 != (long *)0x0) {
        *plVar4 = param_1;
        *(undefined4 *)(plVar4 + 1) = uVar5;
        *(undefined1 *)((long)plVar4 + 0xc) = 0;
        plVar4[2] = uVar6 >> 3;
        return plVar4;
      }
      return (long *)0x0;
    }
    pcVar3 = "unsupported crypt filter `AuthEvent\' value `%s\'.";
  }
  else {
    pcVar3 = "invalid crypt filter `Length\' value `%ld\'.";
  }
LAB_183e19378:
  _pdf_error(pcVar3);
  return (long *)0x0;
}



/* ==== _CGPDFSecurityManagerCreateDecryptor @ 183e19600 size=216 ==== */

undefined8
_CGPDFSecurityManagerCreateDecryptor(long param_1,long param_2,long param_3,undefined8 param_4)

{
  undefined8 uVar1;
  code *pcVar2;
  long lVar3;
  undefined8 uVar4;
  ulong unaff_x30;
  
  if ((*(long *)(param_1 + 0x10) != 0) && (*(char *)(*(long *)(param_1 + 0x10) + 0xb8) == '\x01')) {
    uVar4 = *(undefined8 *)(param_2 + 0x18);
    uVar1 = *(undefined8 *)(param_2 + 0x20);
    if (param_3 == 0) {
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
        uVar4 = _CGPDFCryptFilterCreateDecryptor
                          (*(undefined8 *)(param_1 + 0x20),uVar4,uVar1,param_4);
        return uVar4;
      }
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0xc471,0x183e196a8);
      (*pcVar2)();
    }
    lVar3 = _CGPDFSecurityManagerCreateCryptFilter(param_1,param_3);
    if (lVar3 != 0) {
      uVar4 = _CGPDFCryptFilterCreateDecryptor(lVar3,uVar4,uVar1,param_4);
      func_0x000188138390(lVar3);
      return uVar4;
    }
    _pdf_error("missing or invalid crypt filter `%s\'.");
  }
  return 0;
}



