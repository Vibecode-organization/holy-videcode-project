// FUN_fffffff00a575090 @ fffffff00a575090 size=2484

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fffffff00a575090(ulong param_1,ulong param_2,int param_3)

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
  int *piVar12;
  int iVar13;
  ulong uVar14;
  long lVar15;
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
  lVar15 = 0x120;
  if (bVar5) {
    lVar15 = 0xd8;
  }
  lVar2 = 0x168;
  if (bVar5) {
    lVar2 = 0x120;
  }
  uVar14 = 0xffffffffffffffef;
  if (bVar5) {
    uVar14 = 0xffffffffffffffdf;
  }
  puVar1 = (ulong *)(param_2 + lVar15);
  *(ulong *)(param_2 + 0x28) = *(ulong *)(param_2 + 0x28) & uVar14;
  plVar17 = (long *)puVar1[7];
  if (plVar17 == (long *)0x0) {
    return;
  }
  if (((*(int *)(param_2 + 0xd4) == 0) || (DAT_fffffff00ad7ddd4 == 0)) ||
     (_DAT_fffffff00ad18400 < 3)) {
LAB_fffffff00a575234:
    bVar5 = false;
    uVar14 = param_1 & 0x7ffffffffff;
    if ((param_1 & 0x80000000000000) != 0) {
      uVar14 = param_1 | 0xffffff8000000000;
    }
    do {
      uVar21 = DAT_fffffff007c6a380;
      uVar18 = DAT_fffffff007c6a378;
      uVar16 = DAT_fffffff007c6a360;
      uVar11 = DAT_fffffff007c6a358;
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
          iVar13 = 0x200;
        }
        else {
          iVar13 = (int)plVar9[6] + 0x200;
        }
        uVar20 = (ulong)(uint)((int)plVar9[3] + (int)uVar20);
        iVar19 = iVar13 + iVar19;
        plVar9 = (long *)*plVar9;
        iVar6 = iVar6 + 1;
      } while (plVar9 != (long *)0x0);
      if ((*(int *)(param_2 + 0xd4) != 0 && DAT_fffffff00ad7ddd4 != 0) && 2 < _DAT_fffffff00ad18400)
      {
        if (((uVar14 < DAT_fffffff007c6a360 && DAT_fffffff007c6a358 <= uVar14) ||
            (DAT_fffffff007c6a378 <= uVar14 && uVar14 < DAT_fffffff007c6a380)) ||
           ((DAT_fffffff007c6a3a0 <= uVar14 && (uVar14 < DAT_fffffff007c6a3a8)))) {
          FUN_fffffff00a396010();
        }
        else if (uVar14 + 0x2400000000 >> 0x25 == 0) {
          FUN_fffffff00a1d12d4(uVar14);
          uVar16 = DAT_fffffff007c6a360;
          uVar11 = DAT_fffffff007c6a358;
          uVar18 = DAT_fffffff007c6a378;
          uVar21 = DAT_fffffff007c6a380;
        }
        uVar10 = (ulong)plVar17 | 0xffffff8000000000;
        uVar3 = uVar10;
        if (((ulong)plVar17 & 0x80000000000000) == 0) {
          uVar3 = (ulong)plVar17 & 0x7ffffffffff;
        }
        if (((uVar3 < uVar16 && uVar11 <= uVar3) || (uVar18 <= uVar3 && uVar3 < uVar21)) ||
           ((DAT_fffffff007c6a3a0 <= uVar3 && (uVar3 < DAT_fffffff007c6a3a8)))) {
          FUN_fffffff00a396010();
        }
        else if (((((ulong)plVar17 >> 0x37 & 1) != 0) && (0xffffffdbffffffff < uVar10)) &&
                (uVar10 < 0xfffffffc00000000)) {
          FUN_fffffff00a1d12d4(uVar10);
        }
        FUN_fffffff00a8df19c
                  (&MACH_HEADER,&DAT_fffffff00ad98ba0,0,
                   "%s:%d CFIL: SERVICE INJECT-Q: <so %llx> data %llx datalen %u (mbcnt %u)\n");
      }
      FUN_fffffff00a57601c(puVar1 + 5,plVar17,uVar20);
      if ((ulong *)(param_2 + lVar2) < puVar1 + 9) goto LAB_fffffff00a575a40;
      uVar11 = *puVar1 + uVar20;
      *puVar1 = uVar11;
      *(int *)(puVar1 + 2) = (int)puVar1[2] - iVar19;
      *(int *)((long)puVar1 + 0x14) = *(int *)((long)puVar1 + 0x14) - iVar6;
      if (_DAT_fffffff00ad123f4 != 0) {
        FUN_fffffff00a5731f4(puVar1 + 5);
        uVar11 = *puVar1;
      }
      if (puVar1[1] < uVar11) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa5d948
                  ("cfi_buf->cfi_pending_first <= cfi_buf->cfi_pending_last",
                   "/Library/Caches/com.apple.xbs/FBE73862-C372-4A76-BC3C-8E79BBE064EA/TemporaryDirectory.14N5mt/Sources/xnu/bsd/net/content_filter.c"
                   ,0x4b7);
      }
      if (param_3 == 0) {
        *(ushort *)((long)plVar17 + 0x1e) = *(ushort *)((long)plVar17 + 0x1e) | 0x80;
        if (((*(int *)(param_1 + 8) == 0x1e) || (*(int *)(param_1 + 8) == 2)) &&
           ((*(short *)(param_1 + 4) == 2 && (*(short *)(param_1 + 6) == 0x11)))) {
          if (plVar17 + 0x40 <= plVar17) {
LAB_fffffff00a575a40:
                    /* WARNING: Does not return */
            pcVar7 = (code *)SoftwareBreakpoint(0x5519,0xfffffff00a575a44);
            (*pcVar7)();
          }
          iVar6 = FUN_fffffff00a7ac0d4(param_1 + 0x70,plVar17);
        }
        else {
          if (plVar17 + 0x40 <= plVar17) goto LAB_fffffff00a575a40;
          iVar6 = FUN_fffffff00a7abbe8(param_1 + 0x70,plVar17);
        }
        if (iVar6 != 0) {
          bVar5 = true;
        }
        plVar17 = &DAT_fffffff00ad7df10;
      }
      else {
        iVar6 = FUN_fffffff00a79fe14(param_1,0,plVar17,0,0);
        if (iVar6 != 0) {
          FUN_fffffff00a56b5ac(3,param_2,"CFIL: Error: sosend_reinject() failed");
          if (2 < _DAT_fffffff00ad18400) {
            FUN_fffffff00a8df19c
                      (&MACH_HEADER,&DAT_fffffff00ad98ba0,0,"%s:%d CFIL: sosend() failed %d\n");
          }
          break;
        }
        bVar5 = true;
        plVar17 = &DAT_fffffff00ad7df18;
      }
      *plVar17 = *plVar17 + uVar20;
      plVar17 = (long *)puVar1[7];
      iVar6 = 0;
    } while (plVar17 != (long *)0x0);
    iVar19 = *(int *)(param_2 + 0xd4);
  }
  else {
    uVar14 = param_1 & 0x7ffffffffff;
    if ((param_1 & 0x80000000000000) != 0) {
      uVar14 = param_1 | 0xffffff8000000000;
    }
    if (((uVar14 < DAT_fffffff007c6a360 && DAT_fffffff007c6a358 <= uVar14) ||
        (DAT_fffffff007c6a378 <= uVar14 && uVar14 < DAT_fffffff007c6a380)) ||
       ((DAT_fffffff007c6a3a0 <= uVar14 && (uVar14 < DAT_fffffff007c6a3a8)))) {
      FUN_fffffff00a396010();
    }
    else if (uVar14 + 0x2400000000 >> 0x25 == 0) {
      FUN_fffffff00a1d12d4();
    }
    FUN_fffffff00a8df19c
              (&MACH_HEADER,&DAT_fffffff00ad98ba0,0,
               "%s:%d CFIL: SERVICE INJECT-Q: <so %llx> outgoing %d queue len %llu\n");
    plVar17 = (long *)puVar1[7];
    if (plVar17 != (long *)0x0) goto LAB_fffffff00a575234;
    bVar5 = false;
    iVar19 = *(int *)(param_2 + 0xd4);
    iVar6 = 0;
  }
  if (((iVar19 != 0) && (DAT_fffffff00ad7ddd4 != 0)) && (2 < _DAT_fffffff00ad18400)) {
    uVar14 = param_1 & 0x7ffffffffff;
    if ((param_1 & 0x80000000000000) != 0) {
      uVar14 = param_1 | 0xffffff8000000000;
    }
    if (((uVar14 < DAT_fffffff007c6a360 && DAT_fffffff007c6a358 <= uVar14) ||
        (DAT_fffffff007c6a378 <= uVar14 && uVar14 < DAT_fffffff007c6a380)) ||
       ((DAT_fffffff007c6a3a0 <= uVar14 && (uVar14 < DAT_fffffff007c6a3a8)))) {
      FUN_fffffff00a396010();
    }
    else if (uVar14 + 0x2400000000 >> 0x25 == 0) {
      FUN_fffffff00a1d12d4();
    }
    FUN_fffffff00a8df19c
              (&MACH_HEADER,&DAT_fffffff00ad98ba0,0,
               "%s:%d CFIL: SERVICE INJECT-Q: <so %llx> injected %d\n");
  }
  if (bVar5) {
    if (param_3 == 0) {
      lVar15 = param_1 + 0x70;
      if (*(int *)(param_1 + 0x10c) == 0) {
        bVar4 = *(byte *)(param_1 + 0xf0);
        goto joined_r0xfffffff00a575708;
      }
    }
    else {
      lVar15 = param_1 + 0x130;
      if (*(int *)(param_1 + 0x1cc) == 0) {
        bVar4 = *(byte *)(param_1 + 0x1b0);
joined_r0xfffffff00a575708:
        if ((bVar4 & 0x78) == 0) goto LAB_fffffff00a575718;
      }
    }
    FUN_fffffff00a7a881c(param_1,lVar15,0);
  }
LAB_fffffff00a575718:
  if (iVar6 == 0) {
LAB_fffffff00a5757c0:
    bVar4 = *(byte *)(param_2 + 0x28);
  }
  else {
    if (iVar6 == 0x37) {
      piVar12 = &DAT_fffffff00ad7dea4;
LAB_fffffff00a575740:
      *piVar12 = *piVar12 + 1;
    }
    else if (iVar6 == 0xc) {
      piVar12 = &DAT_fffffff00ad7dea0;
      goto LAB_fffffff00a575740;
    }
    if (param_3 == 0) {
      *(ulong *)(param_2 + 0x28) = *(ulong *)(param_2 + 0x28) | 0x10;
      piVar12 = &DAT_fffffff00ad7deac;
    }
    else {
      if ((iVar6 - 0x31U < 0x11) && ((1 << (ulong)(iVar6 - 0x31U & 0x1f) & 0x10007U) != 0)) {
        *(short *)(param_1 + 0xc) = (short)iVar6;
        if ((*(int *)(param_1 + 0x1cc) != 0) || ((*(byte *)(param_1 + 0x1b0) & 0x78) != 0)) {
          FUN_fffffff00a7a881c(param_1,param_1 + 0x130,0);
        }
        if ((*(int *)(param_1 + 0x10c) != 0) || ((*(byte *)(param_1 + 0xf0) & 0x78) != 0)) {
          FUN_fffffff00a7a881c(param_1,param_1 + 0x70,0);
        }
        goto LAB_fffffff00a5757c0;
      }
      *(ulong *)(param_2 + 0x28) = *(ulong *)(param_2 + 0x28) | 0x20;
      piVar12 = &DAT_fffffff00ad7deb0;
    }
    *piVar12 = *piVar12 + 1;
    bVar4 = *(byte *)(param_2 + 0x28);
  }
  if ((bVar4 >> 6 & 1) != 0) {
    FUN_fffffff00a57613c(param_1,1);
    iVar6 = FUN_fffffff00a575da4(param_1 + 0x130);
    if (iVar6 == 0) {
      FUN_fffffff00a7a36d4(param_1,1);
    }
  }
  if (((*(byte *)(param_2 + 0x28) >> 1 & 1) != 0) &&
     (iVar6 = FUN_fffffff00a572718(param_1), iVar6 == 0)) {
    if (5 < _DAT_fffffff00ad18400) {
      uVar14 = param_1 & 0x7ffffffffff;
      if ((param_1 & 0x80000000000000) != 0) {
        uVar14 = param_1 | 0xffffff8000000000;
      }
      if (((uVar14 < DAT_fffffff007c6a360 && DAT_fffffff007c6a358 <= uVar14) ||
          (DAT_fffffff007c6a378 <= uVar14 && uVar14 < DAT_fffffff007c6a380)) ||
         ((DAT_fffffff007c6a3a0 <= uVar14 && (uVar14 < DAT_fffffff007c6a3a8)))) {
        FUN_fffffff00a396010();
      }
      else if (uVar14 + 0x2400000000 >> 0x25 == 0) {
        FUN_fffffff00a1d12d4();
      }
      FUN_fffffff00a8df19c(&MACH_HEADER,&DAT_fffffff00ad98ba0,0,"%s:%d so %llx waking\n");
    }
    uVar14 = (param_2 ^ param_2 >> 0x1f) * 0x7fb5d329728ea185;
    lVar15 = (uVar14 ^ uVar14 >> 0x1b) * -0x7e25210b43d22bb3;
    uVar14 = DAT_fffffff007bc7040 +
             (ulong)(DAT_fffffff007bc7048 - 1U & ((uint)((ulong)lVar15 >> 0x21) ^ (uint)lVar15)) *
             0x18;
    if (((DAT_fffffff007bc7040 ^ uVar14) & 0xffc0000000000000) != 0) {
      uVar14 = uVar14 & 0xffffffffffff | 0xc8a2000000000000;
    }
    FUN_fffffff00a28c5d4(uVar14,param_2,0,0,0xffffffff);
  }
  if (_DAT_fffffff00ad123f4 == 0) {
    return;
  }
  FUN_fffffff00a5730f0(param_2);
  return;
}

