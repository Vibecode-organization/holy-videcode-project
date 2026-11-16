// FUN_fffffff00a713c20 @ fffffff00a713c20 size=2296

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong FUN_fffffff00a713c20(long param_1,undefined8 *param_2)

{
  ulong uVar1;
  long lVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  int iVar6;
  uint uVar7;
  long lVar8;
  undefined8 *puVar9;
  ulong uVar10;
  long lVar11;
  long lVar12;
  undefined8 uVar13;
  int *piVar14;
  undefined4 uVar15;
  ulong uVar16;
  long lVar17;
  bool bVar18;
  undefined8 local_80;
  long local_78;
  undefined8 local_70;
  undefined8 local_68;
  
  if ((param_1 == 0) || ((*(byte *)(param_1 + 0x444) >> 2 & 1) == 0)) {
    bVar3 = true;
  }
  else {
    bVar3 = false;
  }
  local_70 = 0;
  local_68 = 0;
  lVar2 = tpidr_el1;
  lVar8 = FUN_fffffff00a29bafc(lVar2);
  local_78 = 0;
  puVar9 = (undefined8 *)FUN_fffffff00a2216c4(&DAT_fffffff007c78790,4);
  if (puVar9 == (undefined8 *)0x0) {
    *(undefined8 *)(lVar2 + 0x5f0) = 0;
    return 0xc;
  }
  *puVar9 = *param_2;
  puVar9[1] = param_2[1];
  puVar9[2] = param_2[2];
  puVar9[5] = puVar9 + 0x6d;
  puVar9[6] = puVar9 + 0xa6;
  puVar9[0x55] = &local_70;
  uVar7 = 0;
  if (!bVar3) {
    uVar7 = 4;
  }
  *(uint *)(puVar9 + 9) = *(uint *)(param_1 + 0x444) >> 7 & 0x20 | uVar7;
  uVar15 = 5;
  if (!bVar3) {
    uVar15 = 8;
  }
  *(undefined4 *)(puVar9 + 3) = uVar15;
  *(undefined4 *)((long)puVar9 + 0x2dc) = 0;
  puVar9[0x65] = 0;
  *(undefined4 *)(puVar9 + 0x6c) = 0;
  puVar9[0x10] = 0;
  *(undefined8 **)(lVar2 + 0x5f0) = puVar9;
  if ((param_2[3] == 0) || (uVar10 = FUN_fffffff00aa1d128(param_2[3],puVar9), (int)uVar10 == 0)) {
    *(uint *)(puVar9 + 9) = *(uint *)(puVar9 + 9) | 0x100;
    lVar11 = FUN_fffffff00a29b24c();
    FUN_fffffff00a723e4c(*(undefined4 *)(*(long *)(lVar11 + 8) + 0x1c),1);
    lVar17 = FUN_fffffff00a71e630(lVar8,0,param_1,4);
    puVar9[0x57] = lVar17;
    if (lVar17 == 0) {
      FUN_fffffff00a723e4c(*(undefined4 *)(*(long *)(lVar11 + 8) + 0x1c),0xffffffff);
      lVar17 = 0;
      bVar4 = false;
      bVar3 = false;
      uVar10 = 0xc;
      lVar11 = puVar9[0x57];
      goto joined_r0xfffffff00a713dd4;
    }
    lVar17 = FUN_fffffff00a29bafc();
    *(undefined2 *)(puVar9 + 0x68) = 0x102;
    lVar12 = FUN_fffffff00a332ff4(lVar8);
    if (lVar12 == 0) {
      uVar13 = 0;
    }
    else {
      uVar13 = *(undefined8 *)(lVar12 + 0xb0);
      FUN_fffffff00a334174();
    }
    puVar9[0x67] = uVar13;
    param_1 = FUN_fffffff00a29b12c(puVar9[0x57]);
    local_70 = puVar9[0x57];
    local_68 = FUN_fffffff00a6e9c80();
    uVar13 = 0;
    if (*(long *)(param_1 + 0x760) != 0) {
      uVar13 = *(undefined8 *)(*(long *)(param_1 + 0x760) + 0x30);
    }
    puVar9[0x10] = uVar13;
    FUN_fffffff00a72cf54(param_1,0);
    FUN_fffffff00a737e54(param_1,0);
    uVar7 = FUN_fffffff00a711e8c(puVar9);
    if (puVar9[0x57] != 0) {
      lVar17 = FUN_fffffff00a29bafc();
      *(byte *)(lVar17 + 0x358) = (byte)((uint)*(undefined4 *)(puVar9 + 9) >> 0x1f);
      *(uint *)(puVar9[0x57] + 0x100) =
           *(uint *)(puVar9[0x57] + 0x100) & 0xfffffffe | *(uint *)(puVar9 + 9) >> 0x1f;
    }
    if (uVar7 == 0) {
      lVar12 = *(long *)(lVar11 + 0x18);
      if (*(long *)(lVar11 + 0x18) == 0) {
        lVar12 = DAT_fffffff007c6b250;
      }
      FUN_fffffff00a712670(lVar12,param_1,lVar8,lVar17,puVar9,&local_78);
      bVar4 = true;
    }
    else {
      bVar4 = false;
    }
    local_80 = local_68;
    FUN_fffffff00a6eaeec(&local_80);
    local_68 = local_80;
    if (uVar7 == 0) {
      FUN_fffffff00a712c08(param_1,puVar9);
      lVar11 = *(long *)(lVar17 + 0x28);
      if (lVar11 == 0) {
        lVar11 = 0;
      }
      FUN_fffffff00a2ec05c(lVar11,lVar17);
      lVar11 = param_1 + 0x55c;
      if (*(char *)(param_1 + 0x56d) != '\0') {
        lVar11 = param_1 + 0x56d;
      }
      FUN_fffffff00a1d1550(lVar11);
      FUN_fffffff00a726898(param_1);
      FUN_fffffff00a7269d8(param_1);
      uVar7 = _DAT_fffffff00ad169d0;
      if ((*(ushort *)(lVar17 + 0x694) & 0x38) == 0) {
        uVar7 = _DAT_fffffff00ad169d0 >> 8 & 0xff;
LAB_fffffff00a714418:
        *(uint *)(lVar17 + 0x614) = uVar7;
      }
      else {
        *(uint *)(lVar17 + 0x614) = _DAT_fffffff00ad169d0 & 0xff;
        if (*(int *)(*(long *)(lVar17 + 0x318) + 0x18) == 1) {
          uVar7 = 0x59;
          goto LAB_fffffff00a714418;
        }
        if ((*(ushort *)(lVar17 + 0x694) >> 8 & 1) != 0) {
          uVar7 = uVar7 & 0xf0 | 9;
          goto LAB_fffffff00a714418;
        }
      }
      FUN_fffffff00a714c38(lVar17);
      lVar11 = FUN_fffffff00a29b0b4(lVar17);
      iVar6 = FUN_fffffff00a9dee48(lVar17,"com.apple.private.vfs.support-long-paths");
      if (iVar6 != 0) {
        *(ushort *)(lVar11 + 0x616) = *(ushort *)(lVar11 + 0x616) | 0x1000;
      }
      FUN_fffffff00a25fcec(lVar17,puVar9[0x57]);
      FUN_fffffff00a219f74(lVar17);
      uVar7 = FUN_fffffff00a712d78(param_1,puVar9);
      bVar5 = uVar7 != 0;
      if ((puVar9[0x57] != 0) && (uVar7 == 0)) {
        FUN_fffffff00a3969c4(lVar17,*(uint *)(puVar9 + 9) & 0x80000000);
        *(undefined8 *)(puVar9[0x57] + 0x1d0) = *(undefined8 *)(lVar17 + 0x350);
      }
      if ((*(byte *)(param_1 + 1099) >> 2 & 1) == 0) {
        FUN_fffffff00a72d078(param_1,0x20000000);
      }
      bVar3 = true;
      lVar11 = puVar9[4];
    }
    else {
      bVar3 = false;
      bVar5 = true;
      lVar11 = puVar9[4];
    }
    if (lVar11 != 0) {
      FUN_fffffff00a3e8aa8();
    }
    if (puVar9[0x5a] != 0) {
      FUN_fffffff00a3e8aa8();
    }
    if (puVar9[0x5f] != 0) {
      FUN_fffffff00a2e6e78();
    }
    if (puVar9[0xe] != 0) {
      FUN_fffffff00a713818(puVar9);
    }
    if (puVar9[0x58] != 0) {
      FUN_fffffff00aa1ca90();
      puVar9[0x58] = 0;
    }
    lVar11 = puVar9[0x59];
    if (lVar11 != 0) {
      FUN_fffffff00aa224c4(lVar11);
      uVar13 = DAT_fffffff00ad4c548;
      uVar15 = DAT_fffffff007bccf94;
      FUN_fffffff00a38107c(4,lVar11,0,DAT_fffffff007bccf94);
      FUN_fffffff00a29223c(&DAT_fffffff00ad4c540,uVar13,lVar11,uVar15);
      puVar9[0x59] = 0;
    }
    if (puVar9[0x65] != 0) {
      FUN_fffffff00a7d1d48();
      puVar9[0x65] = 0;
    }
    uVar10 = (ulong)uVar7;
    if (!bVar5) {
      uVar10 = FUN_fffffff00a72cd24(param_1,0,0);
    }
    if ((int)uVar10 == 0) {
      if (*(long *)(lVar17 + 0x468) != 0) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa4d114
                  (
                  "Task bank init called with non null bank context for task: %p and bank_context: %p @%s:%d"
                  );
      }
      FUN_fffffff00a2ad4dc(lVar17);
      FUN_fffffff00a72cf54(param_1,0);
      *(undefined1 *)(param_1 + 0x6ca) = 0;
      *(undefined8 *)(param_1 + 0x748) = 0;
      if ((DAT_fffffff00ad89f80 != 0) &&
         (iVar6 = FUN_fffffff00aa7451c(param_1 + 0x55c,&DAT_fffffff00ad89f84), iVar6 == 0)) {
        *(byte *)(param_1 + 0x6ca) = *(byte *)(param_1 + 0x6ca) | 1;
      }
      if ((DAT_fffffff00ad8a084 != 0) &&
         (iVar6 = FUN_fffffff00aa7451c(param_1 + 0x55c,&DAT_fffffff00ad8a088), iVar6 == 0)) {
        *(byte *)(param_1 + 0x6ca) = *(byte *)(param_1 + 0x6ca) | 4;
      }
      if ((DAT_fffffff00ad8a188 != 0) &&
         (iVar6 = FUN_fffffff00aa7451c(param_1 + 0x55c,&DAT_fffffff00ad8a18c), iVar6 == 0)) {
        *(byte *)(param_1 + 0x6ca) = *(byte *)(param_1 + 0x6ca) | 8;
      }
      if (0xffffffffddbffffe < DAT_fffffff00ad970f0 - 0x80000001U) {
        lVar11 = 0;
        if ((*(uint *)(param_1 + 0x448) & 2) != 0) {
          lVar11 = param_1 + 0x768;
        }
        iVar6 = FUN_fffffff00a9dee48(lVar11,"com.apple.developer.memory.ios13extended_footprint");
        if (iVar6 != 0) {
          FUN_fffffff00a26ae68(lVar17);
        }
      }
      if ((DAT_fffffff00ad8a860 == 0) ||
         (iVar6 = FUN_fffffff00a9dee48
                            (lVar17,"com.apple.developer.kernel.increased-debugging-memory-limit"),
         iVar6 == 0)) {
        if ((DAT_fffffff00ad8e1a8 != 0) &&
           (iVar6 = FUN_fffffff00a9dee48(lVar17,"com.apple.developer.kernel.increased-memory-limit")
           , iVar6 != 0)) {
          FUN_fffffff00a747cd0(param_1);
        }
      }
      else {
        FUN_fffffff00a747ddc(param_1);
      }
      lVar11 = 0;
      if ((*(uint *)(param_1 + 0x448) & 2) != 0) {
        lVar11 = param_1 + 0x768;
      }
      iVar6 = FUN_fffffff00a9dee48(lVar11,"com.apple.private.internal-jetsam-range");
      if (iVar6 != 0) {
        *(uint *)(param_1 + 0x6d0) = *(uint *)(param_1 + 0x6d0) | 0x1000000;
      }
      lVar11 = 0;
      if ((*(uint *)(param_1 + 0x448) & 2) != 0) {
        lVar11 = param_1 + 0x768;
      }
      iVar6 = FUN_fffffff00a9dee48(lVar11,"com.apple.private.vfs.unmunged-access-time");
      if (iVar6 != 0) {
        *(uint *)(param_1 + 0x450) = *(uint *)(param_1 + 0x450) | 8;
      }
      FUN_fffffff00a20575c(lVar2);
      FUN_fffffff00a26ea94(lVar17,lVar8);
      FUN_fffffff00a282648(lVar17,puVar9[0x57]);
      FUN_fffffff00a26b850(lVar17);
      FUN_fffffff00a26ba84(lVar17);
      FUN_fffffff00a7135a8(puVar9,param_1,lVar17);
      if (DAT_fffffff00ad8a820 == 1) {
        FUN_fffffff00a26ac1c(lVar17,1);
      }
    }
    else if (lVar17 == 0) goto LAB_fffffff00a713d28;
    if ((*(uint *)(lVar17 + 0x6a8) >> 3 & 1) != 0) {
      FUN_fffffff00a25d670(lVar17);
    }
    bVar18 = false;
    bVar5 = false;
    lVar11 = puVar9[0x57];
  }
  else {
    lVar17 = 0;
    bVar4 = false;
    bVar3 = false;
LAB_fffffff00a713d28:
    lVar11 = puVar9[0x57];
joined_r0xfffffff00a713dd4:
    bVar18 = true;
    bVar5 = true;
  }
  if (lVar11 != 0) {
    lVar11 = FUN_fffffff00a29bafc();
    uVar1 = lVar11 + 0x48;
    uVar16 = (uVar1 ^ uVar1 >> 0x1f) * 0x7fb5d329728ea185;
    lVar11 = (uVar16 ^ uVar16 >> 0x1b) * -0x7e25210b43d22bb3;
    uVar16 = DAT_fffffff007bc7040 +
             (ulong)(DAT_fffffff007bc7048 - 1U & ((uint)((ulong)lVar11 >> 0x21) ^ (uint)lVar11)) *
             0x18;
    if (((DAT_fffffff007bc7040 ^ uVar16) & 0xffc0000000000000) != 0) {
      uVar16 = uVar16 & 0xffffffffffff | 0xc8a2000000000000;
    }
    FUN_fffffff00a28c5d4(uVar16,uVar1,0,0,0xffffffff);
    bVar5 = bVar18;
  }
  if ((int)uVar10 == 0) {
    FUN_fffffff00a265a14(lVar8,lVar17,puVar9[0x57]);
    if ((*(uint *)(lVar8 + 0x6a8) >> 2 & 1) != 0) goto LAB_fffffff00a7142a0;
LAB_fffffff00a71427c:
    lVar8 = puVar9[0x57];
  }
  else {
    if ((*(uint *)(lVar8 + 0x6a8) >> 2 & 1) == 0) goto LAB_fffffff00a71427c;
LAB_fffffff00a7142a0:
    FUN_fffffff00a25d670(lVar8);
    lVar8 = puVar9[0x57];
  }
  if (lVar8 != 0) {
    uVar15 = 6;
    if ((int)uVar10 == 0 || bVar3) {
      uVar15 = 2;
    }
    uVar13 = FUN_fffffff00a29bafc();
    FUN_fffffff00a25fb10(uVar13,uVar15);
    if (puVar9[0x57] != 0) {
      piVar14 = (int *)(puVar9[0x57] + 0x218);
      iVar6 = *piVar14;
      *piVar14 = iVar6 + -1;
      LORelease();
      if (iVar6 == 0) goto LAB_fffffff00a7144d4;
      if (iVar6 == 1) {
        FUN_fffffff00a270c78();
      }
    }
    puVar9[0x57] = 0;
  }
  if (lVar17 == 0) {
    bVar5 = true;
  }
  if (!bVar5) {
    piVar14 = (int *)(lVar17 + 0x10);
    iVar6 = *piVar14;
    *piVar14 = iVar6 + -1;
    LORelease();
    if (iVar6 == 0) {
LAB_fffffff00a7144d4:
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa61ea0(piVar14);
    }
    FUN_fffffff00a2626e0(lVar17,iVar6 + -1);
  }
  if (bVar4) {
    FUN_fffffff00a724838(param_1);
  }
  lVar8 = local_78;
  *(undefined8 *)(lVar2 + 0x5f0) = 0;
  FUN_fffffff00a29762c(&DAT_fffffff007c787d0,puVar9);
  if (lVar8 != 0) {
    FUN_fffffff00a1e3aa4(lVar8);
  }
  return uVar10;
}

