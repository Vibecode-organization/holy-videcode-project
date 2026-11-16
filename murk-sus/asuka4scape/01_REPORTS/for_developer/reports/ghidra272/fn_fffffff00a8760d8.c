// FUN_fffffff00a8760d8 @ fffffff00a8760d8 size=444

long FUN_fffffff00a8760d8(long param_1,long param_2,uint param_3)

{
  bool bVar1;
  int iVar2;
  undefined8 uVar3;
  code *pcVar4;
  long lVar5;
  long *plVar6;
  long *plVar7;
  long lVar8;
  long local_68;
  
  local_68 = 0;
  if (param_2 == 0) {
    local_68 = 0;
  }
  else {
    plVar6 = &local_68;
    plVar7 = (long *)&stack0xffffffffffffffa0;
    do {
      lVar5 = *(long *)(param_2 + 0xa8);
      *(undefined8 *)(param_2 + 0xa8) = 0;
      if ((param_3 & 3) == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa5d948
                  ("(flags & (NETIF_CONVERT_TX | NETIF_CONVERT_RX)) != 0",
                   "/Library/Caches/com.apple.xbs/FBE73862-C372-4A76-BC3C-8E79BBE064EA/TemporaryDirectory.14N5mt/Sources/xnu/bsd/skywalk/nexus/netif/nx_netif_util.c"
                   ,0x44);
      }
      if ((param_3 & 3) == 3) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa5d948
                  ("(flags & (NETIF_CONVERT_TX | NETIF_CONVERT_RX)) != (NETIF_CONVERT_TX | NETIF_CONVERT_RX)"
                   ,
                   "/Library/Caches/com.apple.xbs/FBE73862-C372-4A76-BC3C-8E79BBE064EA/TemporaryDirectory.14N5mt/Sources/xnu/bsd/skywalk/nexus/netif/nx_netif_util.c"
                   ,0x46);
      }
      lVar8 = *(long *)(param_1 + 0x458);
      if ((*(ulong *)(param_2 + 0x90) >> 0x26 & 1) == 0) {
        if (DAT_fffffff00add6dbc == (int)DAT_fffffff00ad95818) {
          iVar2 = DAT_fffffff00add6dc0 + 1;
          bVar1 = DAT_fffffff00add6dc0 < 5;
          DAT_fffffff00add6dc0 = iVar2;
          if (bVar1) goto LAB_fffffff00a87614c;
        }
        else {
          DAT_fffffff00add6dbc = (int)DAT_fffffff00ad95818;
          DAT_fffffff00add6dc0 = 1;
LAB_fffffff00a87614c:
          uVar3 = tpidr_el1;
          FUN_fffffff00a8df19c
                    (&MACH_HEADER,DAT_fffffff00ad984e0,0x10,
                     "SK[%u]: %-30s filter packet is not mbuf-wrapped: pkt_pflags 0x%llx\n");
        }
        *(long *)(lVar8 + 0x2d0) = *(long *)(lVar8 + 0x2d0) + 1;
        *(long *)(lVar8 + 0x128) = *(long *)(lVar8 + 0x128) + 1;
        FUN_fffffff00a875a20(param_2);
      }
      else {
        lVar8 = *(long *)(param_2 + 0xb0);
        *(ulong *)(param_2 + 0x90) = *(ulong *)(param_2 + 0x90) & 0xfffffe3fffffffff;
        *(undefined8 *)(param_2 + 0xb0) = 0;
        FUN_fffffff00a875a20();
        if (lVar8 != 0) {
          if (plVar7 <= plVar6) {
                    /* WARNING: Does not return */
            pcVar4 = (code *)SoftwareBreakpoint(0x5519,0xfffffff00a876294);
            (*pcVar4)();
          }
          *plVar6 = lVar8;
          plVar6 = (long *)(lVar8 + 8);
          plVar7 = (long *)(lVar8 + 0x10);
        }
      }
      param_2 = lVar5;
    } while (lVar5 != 0);
  }
  return local_68;
}

