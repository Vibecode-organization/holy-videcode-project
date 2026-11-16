// FUN_fffffff00a64b4f0 @ fffffff00a64b4f0 size=940

void FUN_fffffff00a64b4f0(long param_1)

{
  int iVar1;
  uint uVar2;
  long lVar3;
  code *pcVar4;
  ulong uVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  long lVar10;
  int in_wzr;
  long local_48;
  
  lVar3 = tpidr_el1;
  *(int *)(lVar3 + 0x1c0) = *(int *)(lVar3 + 0x1c0) + 1;
  if (*(ulong *)(param_1 + 8) == 0) {
    *(ulong *)(param_1 + 8) = (ulong)*(uint *)(lVar3 + 0x4e8) | 0x30000000;
    iVar1 = *(int *)(param_1 + 0x10);
  }
  else {
    FUN_fffffff00a1ea02c(param_1,lVar3,1);
    iVar1 = *(int *)(param_1 + 0x10);
  }
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff00aa0c4f8("%s: mli=%p negative refcnt @%s:%d");
  }
  *(int *)(param_1 + 0x10) = iVar1 + -1;
  if (iVar1 + -1 != 0) {
    if (*(int *)(param_1 + 8) != *(int *)(lVar3 + 0x4e8)) {
      FUN_fffffff00a1eab60(param_1,lVar3);
      return;
    }
    *(int *)(param_1 + 8) = in_wzr;
    return;
  }
  *(undefined8 *)(param_1 + 0x28) = 0;
  while (uVar5 = *(ulong *)(param_1 + 0x58), uVar5 != 0) {
    lVar6 = *(long *)(uVar5 + 8);
    *(long *)(param_1 + 0x58) = lVar6;
    if (lVar6 == 0) {
      *(undefined8 *)(param_1 + 0x60) = 0;
    }
    *(undefined8 *)(uVar5 + 8) = 0;
    *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x68) + -1;
    if (uVar5 + 0x200 <= uVar5) goto LAB_fffffff00a64b820;
    do {
      lVar6 = FUN_fffffff00a74f6b4();
    } while (lVar6 != 0);
  }
  while( true ) {
    uVar5 = *(ulong *)(param_1 + 0x78);
    if (uVar5 == 0) {
      local_48 = 0;
      FUN_fffffff00a64be40(param_1,&local_48);
      if (*(int *)(param_1 + 8) == *(int *)(lVar3 + 0x4e8)) {
        *(int *)(param_1 + 8) = in_wzr;
        lVar6 = local_48;
      }
      else {
        FUN_fffffff00a1eab60(param_1,lVar3);
        lVar6 = local_48;
      }
      lVar9 = lVar6;
      local_48 = lVar6;
      if (lVar6 != 0) {
        do {
          lVar10 = *(long *)(lVar6 + 0x70);
          lVar8 = lVar9;
          if (lVar9 == lVar6) {
            lVar9 = *(long *)(lVar9 + 0x70);
          }
          else {
            do {
              lVar7 = lVar8;
              lVar8 = *(long *)(lVar7 + 0x70);
            } while (lVar8 != lVar6);
            *(undefined8 *)(lVar7 + 0x70) = *(undefined8 *)(lVar8 + 0x70);
          }
          FUN_fffffff00a63f95c(lVar6,0);
          lVar6 = lVar10;
        } while (lVar10 != 0);
        if (lVar9 != 0) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff00aa1cb7c
                    ("SLIST_EMPTY(&in6m_dthead)",
                     "/Library/Caches/com.apple.xbs/D9089588-4191-473E-9025-574E023945ED/TemporaryDirectory.nLq3V8/Sources/xnu/bsd/netinet6/mld6.c"
                     ,0x33e);
        }
      }
      FUN_fffffff00a89f3b0
                (&MACH_HEADER,&DAT_fffffff00ad58ac0,0,"%s: freeing mld_ifinfo for ifp %s\n");
      if (*(ulong *)(param_1 + 8) == 0) {
        *(ulong *)(param_1 + 8) = (ulong)*(uint *)(lVar3 + 0x4e8);
        uVar2 = *(uint *)(param_1 + 0x14);
      }
      else {
        FUN_fffffff00a1ea02c(param_1,lVar3,0);
        uVar2 = *(uint *)(param_1 + 0x14);
      }
      if ((uVar2 & 1) != 0) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa0c4f8("%s: attached mli=%p is being freed @%s:%d");
      }
      if (*(long *)(param_1 + 0x28) != 0) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa0c4f8("%s: ifp not NULL for mli=%p @%s:%d");
      }
      if ((uVar2 >> 1 & 1) != 0) {
        if (*(int *)(param_1 + 0x10) == 0) {
          *(uint *)(param_1 + 0x14) = uVar2 & 0xfffffffc;
          if (*(int *)(param_1 + 8) == *(int *)(lVar3 + 0x4e8)) {
            *(int *)(param_1 + 8) = in_wzr;
          }
          else {
            FUN_fffffff00a1eab60(param_1,lVar3);
          }
          FUN_fffffff00a1e9f18(param_1,&DAT_fffffff00ace38e4);
          FUN_fffffff00a25b224(&DAT_fffffff007c6a3f0,param_1);
          return;
        }
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa0c4f8("%s: non-zero refcnt mli=%p @%s:%d");
      }
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa0c4f8("%s: mli %p cannot be freed @%s:%d");
    }
    lVar6 = *(long *)(uVar5 + 8);
    *(long *)(param_1 + 0x78) = lVar6;
    if (lVar6 == 0) {
      *(undefined8 *)(param_1 + 0x80) = 0;
    }
    *(undefined8 *)(uVar5 + 8) = 0;
    *(int *)(param_1 + 0x88) = *(int *)(param_1 + 0x88) + -1;
    if (uVar5 + 0x200 <= uVar5) break;
    do {
      lVar6 = FUN_fffffff00a74f6b4();
    } while (lVar6 != 0);
  }
LAB_fffffff00a64b820:
                    /* WARNING: Does not return */
  pcVar4 = (code *)SoftwareBreakpoint(0x5519,0xfffffff00a64b824);
  (*pcVar4)();
}

