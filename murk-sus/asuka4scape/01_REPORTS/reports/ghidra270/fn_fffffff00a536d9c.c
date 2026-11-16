// FUN_fffffff00a536d9c @ fffffff00a536d9c size=2380

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fffffff00a536d9c(ulong param_1,ulong param_2,int param_3)

{
  ulong *puVar1;
  long lVar2;
  ulong uVar3;
  byte bVar4;
  bool bVar5;
  int iVar6;
  code *pcVar7;
  long *plVar8;
  long *plVar9;
  ulong uVar10;
  ulong uVar11;
  int iVar12;
  ulong uVar13;
  long lVar14;
  int *piVar15;
  ulong uVar16;
  long *plVar17;
  ulong uVar18;
  int iVar19;
  ulong uVar20;
  ulong uVar21;
  
  if (param_2 == 0) {
    return;
  }
  pcVar7 = *(code **)(*(long *)(param_1 + 0x20) + 0x70);
  if (pcVar7 != (code *)0x0) {
    (*pcVar7)(param_1,0);
  }
  if (*(short *)(param_1 + 0x16) < 0) {
    return;
  }
  bVar5 = param_3 != 0;
  lVar14 = 0x120;
  if (bVar5) {
    lVar14 = 0xd8;
  }
  lVar2 = 0x168;
  if (bVar5) {
    lVar2 = 0x120;
  }
  uVar13 = 0xffffffffffffffef;
  if (bVar5) {
    uVar13 = 0xffffffffffffffdf;
  }
  puVar1 = (ulong *)(param_2 + lVar14);
  *(ulong *)(param_2 + 0x28) = *(ulong *)(param_2 + 0x28) & uVar13;
  plVar17 = (long *)puVar1[7];
  if (plVar17 == (long *)0x0) {
    return;
  }
  if (((*(int *)(param_2 + 0xd4) == 0) || (DAT_fffffff00ad3dd14 == 0)) ||
     (_DAT_fffffff00acd8400 < 3)) {
LAB_fffffff00a536f40:
    bVar5 = false;
    uVar13 = param_1 & 0x7ffffffffff;
    if ((param_1 & 0x80000000000000) != 0) {
      uVar13 = param_1 | 0xffffff8000000000;
    }
    do {
      uVar21 = DAT_fffffff007c5e238;
      uVar18 = DAT_fffffff007c5e230;
      uVar16 = DAT_fffffff007c5e218;
      uVar11 = DAT_fffffff007c5e210;
      plVar8 = plVar17;
      do {
        plVar9 = plVar8;
        if ((*(ushort *)((long)plVar8 + 0x1e) >> 1 & 1) != 0) break;
        plVar8 = (long *)*plVar8;
        plVar9 = plVar17;
      } while (plVar8 != (long *)0x0);
      uVar20 = 0;
      iVar19 = 0;
      iVar6 = 0;
      do {
        if ((*(ushort *)((long)plVar9 + 0x1e) & 1) == 0) {
          iVar12 = 0x200;
        }
        else {
          iVar12 = (int)plVar9[6] + 0x200;
        }
        uVar20 = (ulong)(uint)((int)plVar9[3] + (int)uVar20);
        iVar19 = iVar12 + iVar19;
        plVar9 = (long *)*plVar9;
        iVar6 = iVar6 + 1;
      } while (plVar9 != (long *)0x0);
      if ((*(int *)(param_2 + 0xd4) != 0 && DAT_fffffff00ad3dd14 != 0) && 2 < _DAT_fffffff00acd8400)
      {
        if (((uVar13 < DAT_fffffff007c5e218 && DAT_fffffff007c5e210 <= uVar13) ||
            (DAT_fffffff007c5e230 <= uVar13 && uVar13 < DAT_fffffff007c5e238)) ||
           ((DAT_fffffff007c5e258 <= uVar13 && (uVar13 < DAT_fffffff007c5e260)))) {
          FUN_fffffff00a35921c();
        }
        else if (uVar13 + 0x2400000000 >> 0x25 == 0) {
          FUN_fffffff00a1952d4(uVar13);
          uVar16 = DAT_fffffff007c5e218;
          uVar11 = DAT_fffffff007c5e210;
          uVar18 = DAT_fffffff007c5e230;
          uVar21 = DAT_fffffff007c5e238;
        }
        uVar10 = (ulong)plVar17 | 0xffffff8000000000;
        uVar3 = uVar10;
        if (((ulong)plVar17 & 0x80000000000000) == 0) {
          uVar3 = (ulong)plVar17 & 0x7ffffffffff;
        }
        if (((uVar3 < uVar16 && uVar11 <= uVar3) || (uVar18 <= uVar3 && uVar3 < uVar21)) ||
           ((DAT_fffffff007c5e258 <= uVar3 && (uVar3 < DAT_fffffff007c5e260)))) {
          FUN_fffffff00a35921c();
        }
        else if (((((ulong)plVar17 >> 0x37 & 1) != 0) && (0xffffffdbffffffff < uVar10)) &&
                (uVar10 < 0xfffffffc00000000)) {
          FUN_fffffff00a1952d4(uVar10);
        }
        FUN_fffffff00a89f3b0
                  (&MACH_HEADER,&DAT_fffffff00ad58ac0,0,
                   "%s:%d CFIL: SERVICE INJECT-Q: <so %llx> data %llx datalen %u (mbcnt %u)\n");
      }
      FUN_fffffff00a537cc0(puVar1 + 5,plVar17,uVar20);
      if ((ulong *)(param_2 + lVar2) < puVar1 + 9) goto LAB_fffffff00a5376e4;
      uVar11 = *puVar1 + uVar20;
      *puVar1 = uVar11;
      *(int *)(puVar1 + 2) = (int)puVar1[2] - iVar19;
      *(int *)((long)puVar1 + 0x14) = *(int *)((long)puVar1 + 0x14) - iVar6;
      if (_DAT_fffffff00acd23f4 != 0) {
        FUN_fffffff00a534f00(puVar1 + 5);
        uVar11 = *puVar1;
      }
      if (puVar1[1] < uVar11) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa1cb7c
                  ("cfi_buf->cfi_pending_first <= cfi_buf->cfi_pending_last",
                   "/Library/Caches/com.apple.xbs/D9089588-4191-473E-9025-574E023945ED/TemporaryDirectory.nLq3V8/Sources/xnu/bsd/net/content_filter.c"
                   ,0x4b7);
      }
      if (param_3 == 0) {
        *(ushort *)((long)plVar17 + 0x1e) = *(ushort *)((long)plVar17 + 0x1e) | 0x80;
        if (((*(int *)(param_1 + 8) == 0x1e) || (*(int *)(param_1 + 8) == 2)) &&
           ((*(short *)(param_1 + 4) == 2 && (*(short *)(param_1 + 6) == 0x11)))) {
          if (plVar17 + 0x40 <= plVar17) {
LAB_fffffff00a5376e4:
                    /* WARNING: Does not return */
            pcVar7 = (code *)SoftwareBreakpoint(0x5519,0xfffffff00a5376e8);
            (*pcVar7)();
          }
          iVar6 = FUN_fffffff00a76c608(param_1 + 0x70,plVar17);
        }
        else {
          if (plVar17 + 0x40 <= plVar17) goto LAB_fffffff00a5376e4;
          iVar6 = FUN_fffffff00a76c11c(param_1 + 0x70,plVar17);
        }
        if (iVar6 != 0) {
          bVar5 = true;
        }
        plVar17 = &DAT_fffffff00ad3de50;
      }
      else {
        iVar6 = FUN_fffffff00a760348(param_1,0,plVar17,0,0);
        if (iVar6 != 0) {
          FUN_fffffff00a52d2b8(3,param_2,"CFIL: Error: sosend_reinject() failed");
          if (2 < _DAT_fffffff00acd8400) {
            FUN_fffffff00a89f3b0
                      (&MACH_HEADER,&DAT_fffffff00ad58ac0,0,"%s:%d CFIL: sosend() failed %d\n");
          }
          break;
        }
        bVar5 = true;
        plVar17 = &DAT_fffffff00ad3de58;
      }
      *plVar17 = *plVar17 + uVar20;
      plVar17 = (long *)puVar1[7];
      iVar6 = 0;
    } while (plVar17 != (long *)0x0);
    iVar19 = *(int *)(param_2 + 0xd4);
  }
  else {
    uVar13 = param_1 & 0x7ffffffffff;
    if ((param_1 & 0x80000000000000) != 0) {
      uVar13 = param_1 | 0xffffff8000000000;
    }
    if (((uVar13 < DAT_fffffff007c5e218 && DAT_fffffff007c5e210 <= uVar13) ||
        (DAT_fffffff007c5e230 <= uVar13 && uVar13 < DAT_fffffff007c5e238)) ||
       ((DAT_fffffff007c5e258 <= uVar13 && (uVar13 < DAT_fffffff007c5e260)))) {
      FUN_fffffff00a35921c();
    }
    else if (uVar13 + 0x2400000000 >> 0x25 == 0) {
      FUN_fffffff00a1952d4();
    }
    FUN_fffffff00a89f3b0
              (&MACH_HEADER,&DAT_fffffff00ad58ac0,0,
               "%s:%d CFIL: SERVICE INJECT-Q: <so %llx> outgoing %d queue len %llu\n");
    plVar17 = (long *)puVar1[7];
    if (plVar17 != (long *)0x0) goto LAB_fffffff00a536f40;
    bVar5 = false;
    iVar19 = *(int *)(param_2 + 0xd4);
    iVar6 = 0;
  }
  if (((iVar19 != 0) && (DAT_fffffff00ad3dd14 != 0)) && (2 < _DAT_fffffff00acd8400)) {
    uVar13 = param_1 & 0x7ffffffffff;
    if ((param_1 & 0x80000000000000) != 0) {
      uVar13 = param_1 | 0xffffff8000000000;
    }
    if (((uVar13 < DAT_fffffff007c5e218 && DAT_fffffff007c5e210 <= uVar13) ||
        (DAT_fffffff007c5e230 <= uVar13 && uVar13 < DAT_fffffff007c5e238)) ||
       ((DAT_fffffff007c5e258 <= uVar13 && (uVar13 < DAT_fffffff007c5e260)))) {
      FUN_fffffff00a35921c();
    }
    else if (uVar13 + 0x2400000000 >> 0x25 == 0) {
      FUN_fffffff00a1952d4();
    }
    FUN_fffffff00a89f3b0
              (&MACH_HEADER,&DAT_fffffff00ad58ac0,0,
               "%s:%d CFIL: SERVICE INJECT-Q: <so %llx> injected %d\n");
  }
  if (bVar5) {
    if (param_3 == 0) {
      lVar14 = param_1 + 0x70;
      if (*(int *)(param_1 + 0x10c) == 0) {
        bVar4 = *(byte *)(param_1 + 0xf0);
        goto joined_r0xfffffff00a537414;
      }
    }
    else {
      lVar14 = param_1 + 0x130;
      if (*(int *)(param_1 + 0x1cc) == 0) {
        bVar4 = *(byte *)(param_1 + 0x1b0);
joined_r0xfffffff00a537414:
        if ((bVar4 & 0x78) == 0) goto LAB_fffffff00a537424;
      }
    }
    FUN_fffffff00a768d50(param_1,lVar14,0);
  }
LAB_fffffff00a537424:
  if (iVar6 == 0) goto LAB_fffffff00a5374a4;
  if (iVar6 == 0x37) {
    piVar15 = &DAT_fffffff00ad3dde4;
LAB_fffffff00a53744c:
    *piVar15 = *piVar15 + 1;
  }
  else if (iVar6 == 0xc) {
    piVar15 = &DAT_fffffff00ad3dde0;
    goto LAB_fffffff00a53744c;
  }
  uVar13 = 0x10;
  if (param_3 != 0) {
    uVar13 = 0x20;
  }
  lVar14 = 0xcc;
  if (param_3 != 0) {
    lVar14 = 0xd0;
  }
  *(ulong *)(param_2 + 0x28) = *(ulong *)(param_2 + 0x28) | uVar13;
  piVar15 = (int *)(lVar14 - 0xff52c22e0);
  if ((((ulong)piVar15 ^ 0xfffffff00ad3dd20) & 0xffc0000000000000) != 0) {
    piVar15 = (int *)((ulong)piVar15 & 0xffffffffffff | 0xc8a2000000000000);
  }
  *piVar15 = *piVar15 + 1;
LAB_fffffff00a5374a4:
  if ((*(byte *)(param_2 + 0x28) >> 6 & 1) != 0) {
    FUN_fffffff00a537de0(param_1,1);
    iVar6 = FUN_fffffff00a537a48(param_1 + 0x130);
    if (iVar6 == 0) {
      FUN_fffffff00a763c08(param_1,1);
    }
  }
  if (((*(byte *)(param_2 + 0x28) >> 1 & 1) != 0) &&
     (iVar6 = FUN_fffffff00a534424(param_1), iVar6 == 0)) {
    if (5 < _DAT_fffffff00acd8400) {
      uVar13 = param_1 & 0x7ffffffffff;
      if ((param_1 & 0x80000000000000) != 0) {
        uVar13 = param_1 | 0xffffff8000000000;
      }
      if (((uVar13 < DAT_fffffff007c5e218 && DAT_fffffff007c5e210 <= uVar13) ||
          (DAT_fffffff007c5e230 <= uVar13 && uVar13 < DAT_fffffff007c5e238)) ||
         ((DAT_fffffff007c5e258 <= uVar13 && (uVar13 < DAT_fffffff007c5e260)))) {
        FUN_fffffff00a35921c();
      }
      else if (uVar13 + 0x2400000000 >> 0x25 == 0) {
        FUN_fffffff00a1952d4();
      }
      FUN_fffffff00a89f3b0(&MACH_HEADER,&DAT_fffffff00ad58ac0,0,"%s:%d so %llx waking\n");
    }
    uVar13 = (param_2 ^ param_2 >> 0x1f) * 0x7fb5d329728ea185;
    lVar14 = (uVar13 ^ uVar13 >> 0x1b) * -0x7e25210b43d22bb3;
    uVar13 = DAT_fffffff007bbb040 +
             (ulong)(DAT_fffffff007bbb048 - 1U & ((uint)((ulong)lVar14 >> 0x21) ^ (uint)lVar14)) *
             0x18;
    if (((DAT_fffffff007bbb040 ^ uVar13) & 0xffc0000000000000) != 0) {
      uVar13 = uVar13 & 0xffffffffffff | 0xc8a2000000000000;
    }
    FUN_fffffff00a2501cc(uVar13,param_2,0,0,0xffffffff);
  }
  if (_DAT_fffffff00acd23f4 == 0) {
    return;
  }
  FUN_fffffff00a534dfc(param_2);
  return;
}

