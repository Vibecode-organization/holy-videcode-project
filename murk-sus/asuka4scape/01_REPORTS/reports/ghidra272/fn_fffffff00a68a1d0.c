// FUN_fffffff00a68a1d0 @ fffffff00a68a1d0 size=1124

void FUN_fffffff00a68a1d0(long param_1)

{
  uint uVar1;
  byte bVar2;
  long lVar3;
  code *pcVar4;
  ulong uVar5;
  char *pcVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  long lVar10;
  long lVar11;
  int iVar12;
  int in_wzr;
  long local_58;
  
  lVar3 = tpidr_el1;
  *(int *)(lVar3 + 0x1c0) = *(int *)(lVar3 + 0x1c0) + 1;
  if (*(ulong *)(param_1 + 8) == 0) {
    *(ulong *)(param_1 + 8) = (ulong)*(uint *)(lVar3 + 0x4e8) | 0x30000000;
    iVar12 = *(int *)(param_1 + 0x10);
  }
  else {
    FUN_fffffff00a2262d4(param_1,lVar3,1);
    iVar12 = *(int *)(param_1 + 0x10);
  }
  if (iVar12 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff00aa4d114("%s: mli=%p negative refcnt @%s:%d");
  }
  *(int *)(param_1 + 0x10) = iVar12 + -1;
  if (iVar12 + -1 != 0) {
    if (*(int *)(param_1 + 8) != *(int *)(lVar3 + 0x4e8)) {
      FUN_fffffff00a226e08(param_1,lVar3);
      return;
    }
    *(int *)(param_1 + 8) = in_wzr;
    return;
  }
  *(undefined8 *)(param_1 + 0x28) = 0;
  while (uVar5 = *(ulong *)(param_1 + 0x58), uVar5 != 0) {
    lVar7 = *(long *)(uVar5 + 8);
    *(long *)(param_1 + 0x58) = lVar7;
    if (lVar7 == 0) {
      *(undefined8 *)(param_1 + 0x60) = 0;
    }
    *(undefined8 *)(uVar5 + 8) = 0;
    *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x68) + -1;
    if (uVar5 + 0x200 <= uVar5) goto LAB_fffffff00a68a5b8;
    do {
      lVar7 = FUN_fffffff00a78f188();
    } while (lVar7 != 0);
  }
  while (uVar5 = *(ulong *)(param_1 + 0x78), uVar5 != 0) {
    lVar7 = *(long *)(uVar5 + 8);
    *(long *)(param_1 + 0x78) = lVar7;
    if (lVar7 == 0) {
      *(undefined8 *)(param_1 + 0x80) = 0;
    }
    *(undefined8 *)(uVar5 + 8) = 0;
    *(int *)(param_1 + 0x88) = *(int *)(param_1 + 0x88) + -1;
    if (uVar5 + 0x200 <= uVar5) {
LAB_fffffff00a68a5b8:
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x5519,0xfffffff00a68a5bc);
      (*pcVar4)();
    }
    do {
      lVar7 = FUN_fffffff00a78f188();
    } while (lVar7 != 0);
  }
  local_58 = 0;
  FUN_fffffff00a68abd8(param_1,&local_58);
  if (*(int *)(param_1 + 8) == *(int *)(lVar3 + 0x4e8)) {
    *(int *)(param_1 + 8) = in_wzr;
    lVar7 = local_58;
  }
  else {
    FUN_fffffff00a226e08(param_1,lVar3);
    lVar7 = local_58;
  }
  lVar10 = lVar7;
  local_58 = lVar7;
  if (lVar7 != 0) {
    do {
      lVar11 = *(long *)(lVar7 + 0x70);
      lVar9 = lVar10;
      if (lVar10 == lVar7) {
        lVar10 = *(long *)(lVar10 + 0x70);
      }
      else {
        do {
          lVar8 = lVar9;
          lVar9 = *(long *)(lVar8 + 0x70);
        } while (lVar9 != lVar7);
        *(undefined8 *)(lVar8 + 0x70) = *(undefined8 *)(lVar9 + 0x70);
      }
      *(int *)(lVar3 + 0x1c0) = *(int *)(lVar3 + 0x1c0) + 1;
      if (*(ulong *)(lVar7 + 8) == 0) {
        *(ulong *)(lVar7 + 8) = (ulong)*(uint *)(lVar3 + 0x4e8) | 0x30000000;
        bVar2 = *(byte *)(lVar7 + 0x61);
      }
      else {
        FUN_fffffff00a2262d4(lVar7,lVar3,1);
        bVar2 = *(byte *)(lVar7 + 0x61);
      }
      if ((bVar2 & 1) == 0) {
        pcVar6 = "_in6m->in6m_in_dtle == true";
        goto LAB_fffffff00a68a4cc;
      }
      *(undefined1 *)(lVar7 + 0x61) = 0;
      iVar12 = *(int *)(lVar7 + 0x84);
      *(undefined4 *)(lVar7 + 0x84) = 0;
      if (iVar12 == 0) {
        pcVar6 = "_dtlecnt != 0";
        goto LAB_fffffff00a68a4cc;
      }
      if (*(int *)(lVar7 + 8) == *(int *)(lVar3 + 0x4e8)) {
        *(int *)(lVar7 + 8) = in_wzr;
      }
      else {
        FUN_fffffff00a226e08(lVar7,lVar3);
      }
      do {
        FUN_fffffff00a67e75c(lVar7,0);
        iVar12 = iVar12 + -1;
      } while (iVar12 != 0);
      lVar7 = lVar11;
    } while (lVar11 != 0);
    if (lVar10 != 0) {
      pcVar6 = "SLIST_EMPTY(&in6m_dthead)";
LAB_fffffff00a68a4cc:
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa5d948
                (pcVar6,
                 "/Library/Caches/com.apple.xbs/FBE73862-C372-4A76-BC3C-8E79BBE064EA/TemporaryDirectory.14N5mt/Sources/xnu/bsd/netinet6/mld6.c"
                 ,0x349);
    }
  }
  FUN_fffffff00a8df19c(&MACH_HEADER,&DAT_fffffff00ad98ba0,0,"%s: freeing mld_ifinfo for ifp %s\n");
  if (*(ulong *)(param_1 + 8) == 0) {
    *(ulong *)(param_1 + 8) = (ulong)*(uint *)(lVar3 + 0x4e8);
    uVar1 = *(uint *)(param_1 + 0x14);
  }
  else {
    FUN_fffffff00a2262d4(param_1,lVar3,0);
    uVar1 = *(uint *)(param_1 + 0x14);
  }
  if ((uVar1 & 1) != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff00aa4d114("%s: attached mli=%p is being freed @%s:%d");
  }
  if (*(long *)(param_1 + 0x28) != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff00aa4d114("%s: ifp not NULL for mli=%p @%s:%d");
  }
  if ((uVar1 >> 1 & 1) != 0) {
    if (*(int *)(param_1 + 0x10) == 0) {
      *(uint *)(param_1 + 0x14) = uVar1 & 0xfffffffc;
      if (*(int *)(param_1 + 8) == *(int *)(lVar3 + 0x4e8)) {
        *(int *)(param_1 + 8) = in_wzr;
      }
      else {
        FUN_fffffff00a226e08(param_1,lVar3);
      }
      FUN_fffffff00a2261c0(param_1,&DAT_fffffff00ad23924);
      FUN_fffffff00a29762c(&DAT_fffffff007c77590,param_1);
      return;
    }
                    /* WARNING: Subroutine does not return */
    FUN_fffffff00aa4d114("%s: non-zero refcnt mli=%p @%s:%d");
  }
                    /* WARNING: Subroutine does not return */
  FUN_fffffff00aa4d114("%s: mli %p cannot be freed @%s:%d");
}

