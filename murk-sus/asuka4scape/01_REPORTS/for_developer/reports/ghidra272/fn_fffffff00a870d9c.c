// FUN_fffffff00a870d9c @ fffffff00a870d9c size=1176

undefined8 FUN_fffffff00a870d9c(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  bool bVar3;
  code *pcVar4;
  int iVar5;
  uint uVar6;
  ulong *puVar7;
  long lVar8;
  ulong uVar9;
  long *plVar10;
  undefined4 uVar11;
  ulong *puVar12;
  long lVar13;
  uint uVar14;
  long lVar15;
  ulong uVar16;
  bool bVar17;
  ulong local_b0;
  long local_a8;
  long *plStack_a0;
  long local_98;
  long *plStack_90;
  long local_88;
  long *plStack_80;
  long local_78;
  long *plStack_70;
  long local_68;
  
  local_68 = DAT_fffffff00ad30000;
  plStack_90 = &local_98;
  plStack_80 = &local_88;
  plStack_70 = &local_78;
  lVar13 = *(long *)(param_1 + 0x70);
  puVar12 = *(ulong **)(*(long *)(lVar13 + 0x70) + 0xe0);
  if ((puVar12 == (ulong *)0x0) || (*(short *)(*(long *)(lVar13 + 0x70) + 0xf2) == 0)) {
    local_b0 = 0;
  }
  else {
    local_b0 = *puVar12 & 0xfffffffffffffffc;
  }
  uVar14 = 0;
  bVar17 = false;
  lVar15 = *(long *)(lVar13 + 0x458);
  iVar1 = *(int *)(param_1 + 0xb0);
  plStack_a0 = &local_a8;
  local_a8 = 0;
  uVar11 = 9;
  if (iVar1 != 0) {
    uVar11 = 10;
  }
  local_98 = 0;
  local_88 = 0;
  local_78 = 0;
  bVar3 = true;
  puVar12 = (ulong *)0x0;
  while (puVar7 = (ulong *)FUN_fffffff00a7f7a94(param_1,puVar12,0), puVar7 != (ulong *)0x0) {
    uVar16 = *puVar7;
    if ((uVar16 == 0) || ((*(ushort *)(uVar16 + 0x18) >> 1 & 1) != 0)) {
      uVar2 = tpidr_el1;
      FUN_fffffff00a8df19c
                (&MACH_HEADER,DAT_fffffff00ad984e0,0x10,
                 "SK[%u]: %-30s packet got dropped by internalize\n");
      *(long *)(lVar15 + 0x240) = *(long *)(lVar15 + 0x240) + 1;
    }
    else if (*(int *)(uVar16 + 0x10) == 0) {
      uVar2 = tpidr_el1;
      FUN_fffffff00a8df19c
                (&MACH_HEADER,DAT_fffffff00ad984e0,0x10,"SK[%u]: %-30s dropped zero length packet\n"
                );
      *(long *)(lVar15 + 0x2c8) = *(long *)(lVar15 + 0x2c8) + 1;
    }
    else {
      lVar8 = *(long *)(param_1 + 0x90);
      *(ushort *)(uVar16 + 0x18) = *(ushort *)(uVar16 + 0x18) & 0xfffe;
      *(undefined8 *)(uVar16 + 0x38) = 0;
      *puVar7 = 0;
      if (-1 < *(int *)(param_1 + 8)) {
        uVar9 = (long)puVar7 - lVar8 & 0x7fffffff8;
        *(undefined4 *)(*(long *)(param_1 + 0x80) + uVar9) = 0xffffffff;
        lVar8 = *(long *)(param_1 + 0x80) + uVar9;
        *(ushort *)(lVar8 + 4) = *(ushort *)(lVar8 + 4) & 1;
        lVar8 = *(long *)(param_1 + 0x80) + uVar9;
        *(ushort *)(lVar8 + 4) = *(ushort *)(lVar8 + 4) & 0xfffe;
      }
      if (uVar16 + 0x78 <= uVar16) goto LAB_fffffff00a87122c;
      iVar5 = FUN_fffffff00a888624(uVar16);
      if (iVar5 != 0) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa5d948
                  ("err == 0",
                   "/Library/Caches/com.apple.xbs/FBE73862-C372-4A76-BC3C-8E79BBE064EA/TemporaryDirectory.14N5mt/Sources/xnu/bsd/skywalk/nexus/netif/nx_netif_filter_vp.c"
                   ,0x1d3);
      }
      if (iVar1 == 0) {
        uVar9 = 0x10000000000;
      }
      else {
        uVar9 = 0x10000000000;
        if ((*(byte *)(lVar15 + 0x490) & 2) != 0) {
          uVar9 = 0x4000000000;
        }
      }
      if ((*(ulong *)(uVar16 + 0x90) & 0x14000000000) == uVar9) {
        if (uVar16 + 0xf0 <= uVar16) goto LAB_fffffff00a87122c;
        if (*(short *)(uVar16 + 0xd8) == 0) {
          uVar9 = 0;
          plVar10 = (long *)0x0;
        }
        else {
          plVar10 = (long *)(uVar16 + 0x40);
          if (*(long *)(uVar16 + 0x48) == 0) {
            plVar10 = (long *)*plVar10;
            uVar9 = (long)plVar10 + 0x32;
          }
          else {
            uVar9 = uVar16 + 0x72;
          }
        }
        if (uVar9 < (long)plVar10 + 0x32U) goto LAB_fffffff00a87122c;
        if (*(long *)(uVar16 + 0xa8) != 0) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff00aa5d948
                    ("pkt->pkt_nextpkt == NULL",
                     "/Library/Caches/com.apple.xbs/FBE73862-C372-4A76-BC3C-8E79BBE064EA/TemporaryDirectory.14N5mt/Sources/xnu/bsd/skywalk/nexus/netif/nx_netif_filter_vp.c"
                     ,0x1ef);
        }
        uVar6 = FUN_fffffff00a888358(uVar16);
        if (3 < uVar6) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff00aa5d948
                    ("tc < KPKT_TC_MAX",
                     "/Library/Caches/com.apple.xbs/FBE73862-C372-4A76-BC3C-8E79BBE064EA/TemporaryDirectory.14N5mt/Sources/xnu/bsd/skywalk/nexus/netif/nx_netif_filter_vp.c"
                     ,0x1f6);
        }
        uVar14 = uVar14 + 1;
        *(&plStack_a0)[(ulong)uVar6 * 2] = uVar16;
        (&plStack_a0)[(ulong)uVar6 * 2] = (long *)(uVar16 + 0xa8);
      }
      else {
        if (DAT_fffffff00add6db0 == (int)DAT_fffffff00ad95818) {
          iVar5 = DAT_fffffff00add6db4 + 1;
          bVar17 = DAT_fffffff00add6db4 < 5;
          DAT_fffffff00add6db4 = iVar5;
          if (bVar17) goto LAB_fffffff00a871090;
        }
        else {
          DAT_fffffff00add6db0 = (int)DAT_fffffff00ad95818;
          DAT_fffffff00add6db4 = 1;
LAB_fffffff00a871090:
          uVar2 = tpidr_el1;
          FUN_fffffff00a8df19c
                    (&MACH_HEADER,DAT_fffffff00ad984e0,0x10,
                     "SK[%u]: %-30s dropped packet injected on ring %u whose wrap flag does not match the ring direction: pkt_pflags 0x%llx\n"
                    );
        }
        *(long *)(lVar15 + 0x2d0) = *(long *)(lVar15 + 0x2d0) + 1;
        *(long *)(lVar15 + 0x128) = *(long *)(lVar15 + 0x128) + 1;
        if (uVar16 + 0xf0 <= uVar16) goto LAB_fffffff00a87122c;
        FUN_fffffff00a875a20(uVar16);
      }
    }
    bVar3 = false;
    bVar17 = true;
    puVar12 = puVar7;
  }
  if (uVar14 != 0) {
    if (*(int *)(param_1 + 0xb0) == 0) {
      *(ulong *)(lVar15 + 0x278) = *(long *)(lVar15 + 0x278) + (ulong)uVar14;
    }
    else {
      *(ulong *)(lVar15 + 0x270) = *(long *)(lVar15 + 0x270) + (ulong)uVar14;
    }
    if (!bVar3) {
      if (!bVar17) {
LAB_fffffff00a87122c:
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x5519,0xfffffff00a871230);
        (*pcVar4)();
      }
      FUN_fffffff00a7f7cac(param_1,puVar12);
    }
    if (local_a8 != 0) {
      FUN_fffffff00a86d9c4(local_b0,*(undefined8 *)(lVar13 + 0x470),local_a8,uVar11);
    }
    if (local_98 != 0) {
      FUN_fffffff00a86d9c4(local_b0,*(undefined8 *)(lVar13 + 0x470),local_98,uVar11);
    }
    if (local_88 != 0) {
      FUN_fffffff00a86d9c4(local_b0,*(undefined8 *)(lVar13 + 0x470),local_88,uVar11);
    }
    if (local_78 != 0) {
      FUN_fffffff00a86d9c4(local_b0,*(undefined8 *)(lVar13 + 0x470),local_78,uVar11);
    }
  }
  if (DAT_fffffff00ad30000 == local_68) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  FUN_fffffff00aa4c590();
}

