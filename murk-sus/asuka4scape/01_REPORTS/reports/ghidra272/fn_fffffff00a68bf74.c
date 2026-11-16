// FUN_fffffff00a68bf74 @ fffffff00a68bf74 size=976

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fffffff00a68bf74(long param_1)

{
  byte bVar1;
  long lVar2;
  code *pcVar3;
  ulong uVar4;
  char *pcVar5;
  long *plVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  long lVar10;
  int iVar11;
  long lVar12;
  int in_wzr;
  long local_48;
  
  local_48 = 0;
  FUN_fffffff00a8df19c(&MACH_HEADER,&DAT_fffffff00ad98ba0,1,"%s: called for ifp %s\n");
  lVar2 = tpidr_el1;
  uVar4 = (ulong)*(uint *)(lVar2 + 0x4e8);
  lVar9 = DAT_fffffff00add3788;
  if (_DAT_fffffff00add3780 != 0) {
    FUN_fffffff00a2262d4(&DAT_fffffff00add3778,lVar2,0);
    uVar4 = _DAT_fffffff00add3780;
    lVar9 = DAT_fffffff00add3788;
  }
  while (_DAT_fffffff00add3780 = uVar4, lVar9 != 0) {
    while( true ) {
      lVar12 = *(long *)(lVar9 + 0x18);
      if (*(ulong *)(lVar9 + 8) == 0) {
        *(ulong *)(lVar9 + 8) = (ulong)*(uint *)(lVar2 + 0x4e8);
      }
      else {
        FUN_fffffff00a2262d4(lVar9,lVar2,0);
      }
      if (*(long *)(lVar9 + 0x28) == param_1) goto LAB_fffffff00a68c0cc;
      if (*(int *)(lVar9 + 8) != *(int *)(lVar2 + 0x4e8)) break;
      *(int *)(lVar9 + 8) = in_wzr;
      lVar9 = lVar12;
      if (lVar12 == 0) goto LAB_fffffff00a68c068;
    }
    FUN_fffffff00a226e08(lVar9,lVar2);
    uVar4 = _DAT_fffffff00add3780;
    lVar9 = lVar12;
  }
LAB_fffffff00a68c068:
                    /* WARNING: Subroutine does not return */
  FUN_fffffff00aa4d114("%s: mld_ifinfo not found for ifp %p(%s) @%s:%d");
LAB_fffffff00a68c0cc:
  uVar4 = *(ulong *)(lVar9 + 0x58);
  if (uVar4 == 0) goto LAB_fffffff00a68c10c;
  lVar12 = *(long *)(uVar4 + 8);
  *(long *)(lVar9 + 0x58) = lVar12;
  if (lVar12 == 0) {
    *(undefined8 *)(lVar9 + 0x60) = 0;
  }
  *(undefined8 *)(uVar4 + 8) = 0;
  *(int *)(lVar9 + 0x68) = *(int *)(lVar9 + 0x68) + -1;
  if (uVar4 + 0x200 <= uVar4) goto LAB_fffffff00a68c340;
  do {
    lVar12 = FUN_fffffff00a78f188();
  } while (lVar12 != 0);
  goto LAB_fffffff00a68c0cc;
LAB_fffffff00a68c10c:
  while (uVar4 = *(ulong *)(lVar9 + 0x78), uVar4 != 0) {
    lVar12 = *(long *)(uVar4 + 8);
    *(long *)(lVar9 + 0x78) = lVar12;
    if (lVar12 == 0) {
      *(undefined8 *)(lVar9 + 0x80) = 0;
    }
    *(undefined8 *)(uVar4 + 8) = 0;
    *(int *)(lVar9 + 0x88) = *(int *)(lVar9 + 0x88) + -1;
    if (uVar4 + 0x200 <= uVar4) {
LAB_fffffff00a68c340:
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x5519,0xfffffff00a68c344);
      (*pcVar3)();
    }
    do {
      lVar12 = FUN_fffffff00a78f188();
    } while (lVar12 != 0);
  }
  plVar6 = (long *)(lVar9 + 0x18);
  FUN_fffffff00a68abd8(lVar9,&local_48);
  *(uint *)(lVar9 + 0x14) = *(uint *)(lVar9 + 0x14) & 0xfffffffe;
  if (*(int *)(lVar9 + 8) == *(int *)(lVar2 + 0x4e8)) {
    *(int *)(lVar9 + 8) = in_wzr;
    lVar12 = *plVar6;
  }
  else {
    FUN_fffffff00a226e08(lVar9,lVar2);
    lVar12 = *plVar6;
  }
  if (lVar12 == 0) {
    plVar6 = *(long **)(lVar9 + 0x20);
    if (*plVar6 != lVar9) {
LAB_fffffff00a68c308:
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00a68c310);
      (*pcVar3)();
    }
    lVar12 = 0;
  }
  else {
    if (*(long **)(lVar12 + 0x20) != plVar6) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00a68c340);
      (*pcVar3)();
    }
    if (**(long **)(lVar9 + 0x20) != lVar9) goto LAB_fffffff00a68c308;
    *(long **)(lVar12 + 0x20) = *(long **)(lVar9 + 0x20);
    lVar12 = *(long *)(lVar9 + 0x18);
    plVar6 = *(long **)(lVar9 + 0x20);
  }
  *plVar6 = lVar12;
  FUN_fffffff00a68a1d0(lVar9);
  DAT_fffffff00add3790 = DAT_fffffff00add3790 + 1;
  if (DAT_fffffff00add3780 == *(int *)(lVar2 + 0x4e8)) {
    _DAT_fffffff00add3780 = CONCAT44(DAT_fffffff00add3780_4,in_wzr);
    lVar9 = local_48;
  }
  else {
    FUN_fffffff00a226e08(&DAT_fffffff00add3778,lVar2);
    lVar9 = local_48;
  }
  lVar12 = lVar9;
  local_48 = lVar9;
  if (lVar9 != 0) {
    do {
      lVar10 = *(long *)(lVar9 + 0x70);
      lVar8 = lVar12;
      if (lVar12 == lVar9) {
        lVar12 = *(long *)(lVar12 + 0x70);
      }
      else {
        do {
          lVar7 = lVar8;
          lVar8 = *(long *)(lVar7 + 0x70);
        } while (lVar8 != lVar9);
        *(undefined8 *)(lVar7 + 0x70) = *(undefined8 *)(lVar8 + 0x70);
      }
      *(int *)(lVar2 + 0x1c0) = *(int *)(lVar2 + 0x1c0) + 1;
      if (*(ulong *)(lVar9 + 8) == 0) {
        *(ulong *)(lVar9 + 8) = (ulong)*(uint *)(lVar2 + 0x4e8) | 0x30000000;
        bVar1 = *(byte *)(lVar9 + 0x61);
      }
      else {
        FUN_fffffff00a2262d4(lVar9,lVar2,1);
        bVar1 = *(byte *)(lVar9 + 0x61);
      }
      if ((bVar1 & 1) == 0) {
        pcVar5 = "_in6m->in6m_in_dtle == true";
        goto LAB_fffffff00a68c2f8;
      }
      *(undefined1 *)(lVar9 + 0x61) = 0;
      iVar11 = *(int *)(lVar9 + 0x84);
      *(undefined4 *)(lVar9 + 0x84) = 0;
      if (iVar11 == 0) {
        pcVar5 = "_dtlecnt != 0";
        goto LAB_fffffff00a68c2f8;
      }
      if (*(int *)(lVar9 + 8) == *(int *)(lVar2 + 0x4e8)) {
        *(int *)(lVar9 + 8) = in_wzr;
      }
      else {
        FUN_fffffff00a226e08(lVar9,lVar2);
      }
      do {
        FUN_fffffff00a67e75c(lVar9,0);
        iVar11 = iVar11 + -1;
      } while (iVar11 != 0);
      lVar9 = lVar10;
    } while (lVar10 != 0);
    if (lVar12 != 0) {
      pcVar5 = "SLIST_EMPTY(&in6m_dthead)";
LAB_fffffff00a68c2f8:
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa5d948
                (pcVar5,
                 "/Library/Caches/com.apple.xbs/FBE73862-C372-4A76-BC3C-8E79BBE064EA/TemporaryDirectory.14N5mt/Sources/xnu/bsd/netinet6/mld6.c"
                 ,0x2a2);
    }
  }
  return;
}

