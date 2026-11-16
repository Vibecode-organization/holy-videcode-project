// FUN_fffffff00a67cfd0 @ fffffff00a67cfd0 size=2876

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
FUN_fffffff00a67cfd0
          (ulong param_1,char *param_2,undefined8 *param_3,undefined8 *param_4,undefined8 param_5)

{
  ulong *puVar1;
  byte bVar2;
  undefined *puVar3;
  int iVar4;
  uint uVar5;
  undefined8 uVar6;
  ulong uVar7;
  long lVar8;
  uint *puVar9;
  long lVar10;
  uint *puVar11;
  uint in_wzr;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined4 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  uint *local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined4 local_68;
  
  local_a0 = 0;
  local_98 = 0;
  local_90 = 0;
  if (*param_2 != -1) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff00aa5d948
              ("IN6_IS_ADDR_MULTICAST(mcaddr)",
               "/Library/Caches/com.apple.xbs/FBE73862-C372-4A76-BC3C-8E79BBE064EA/TemporaryDirectory.14N5mt/Sources/xnu/bsd/netinet6/in6_mcast.c"
               ,0x4ff);
  }
  if (((_DAT_fffffff00ad19dd8 != 0) &&
      (bVar2 = param_2[1] & 0xf, bVar2 == 1 || (param_2[1] & 0xf0U) != 0x30 && bVar2 == 2)) &&
     (*(short *)(param_2 + 2) == 0)) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff00aa5d948
              ("mcaddr->s6_addr16[1] != 0",
               "/Library/Caches/com.apple.xbs/FBE73862-C372-4A76-BC3C-8E79BBE064EA/TemporaryDirectory.14N5mt/Sources/xnu/bsd/netinet6/in6_mcast.c"
               ,0x502);
  }
  if (DAT_fffffff00ad85b04 != 0) {
    FUN_fffffff00a663bbc(param_2);
    uVar7 = param_1 & 0x7ffffffffff;
    if ((param_1 & 0x80000000000000) != 0) {
      uVar7 = param_1 | 0xffffff8000000000;
    }
    if (((DAT_fffffff007c6a360 <= uVar7 || uVar7 < DAT_fffffff007c6a358) &&
        (uVar7 < DAT_fffffff007c6a378 || DAT_fffffff007c6a380 <= uVar7)) &&
       ((DAT_fffffff007c6a3a8 <= uVar7 || uVar7 < DAT_fffffff007c6a3a0 &&
        (uVar7 + 0x2400000000 >> 0x25 == 0)))) {
      FUN_fffffff00a1d12d4();
    }
  }
  local_b8 = 0;
  uStack_b0 = 0;
  local_a8 = 0;
  *param_4 = 0;
  if (param_3 == (undefined8 *)0x0) {
    local_98 = 0;
    local_a0 = 0;
    local_90 = 0x200;
    param_3 = &local_a0;
  }
  local_80 = 0;
  local_78 = 0;
  local_68 = 0;
  uStack_70 = 0;
  local_88 = (uint *)0x0;
  FUN_fffffff00a228180(&DAT_fffffff00add3670);
  if (DAT_fffffff00ad88c58 != (uint *)0x0) {
    lVar10 = tpidr_el1;
    puVar9 = DAT_fffffff00ad88c58;
    do {
      while( true ) {
        puVar11 = *(uint **)(puVar9 + 8);
        *(int *)(lVar10 + 0x1c0) = *(int *)(lVar10 + 0x1c0) + 1;
        if (*(ulong *)(puVar9 + 2) == 0) {
          *(ulong *)(puVar9 + 2) = (ulong)*(uint *)(lVar10 + 0x4e8) | 0x30000000;
        }
        else {
          FUN_fffffff00a2262d4(puVar9,lVar10,1);
        }
        if ((*(ulong *)(puVar9 + 0x12) == param_1) &&
           (iVar4 = FUN_fffffff00a354278(puVar9 + 0xc,param_2,0x10), iVar4 == 0)) {
          uVar5 = puVar9[4];
          puVar9[4] = uVar5 + 1;
          if (0xfffffffe < uVar5) goto LAB_fffffff00a67dae4;
          if (*(code **)(puVar9 + 0x38) != (code *)0x0) {
            (**(code **)(puVar9 + 0x38))(puVar9,1);
          }
          puVar1 = (ulong *)(puVar9 + 2);
          if ((uint)*puVar1 == *(uint *)(lVar10 + 0x4e8)) {
            *(uint *)puVar1 = in_wzr;
          }
          else {
            FUN_fffffff00a226e08(puVar9,lVar10);
          }
          if (*puVar1 == 0) {
            *puVar1 = (ulong)*(uint *)(lVar10 + 0x4e8);
            uVar5 = puVar9[5];
          }
          else {
            FUN_fffffff00a2262d4(puVar9,lVar10,0);
            uVar5 = puVar9[5];
          }
          if (uVar5 == 0) {
                    /* WARNING: Subroutine does not return */
            FUN_fffffff00aa5d948
                      ("inm->in6m_reqcnt >= 1",
                       "/Library/Caches/com.apple.xbs/FBE73862-C372-4A76-BC3C-8E79BBE064EA/TemporaryDirectory.14N5mt/Sources/xnu/bsd/netinet6/in6_mcast.c"
                       ,0x1ef);
          }
          puVar9[5] = uVar5 + 1;
          if (0xfffffffe < uVar5) {
                    /* WARNING: Subroutine does not return */
            FUN_fffffff00aa5d948
                      ("inm->in6m_reqcnt != 0",
                       "/Library/Caches/com.apple.xbs/FBE73862-C372-4A76-BC3C-8E79BBE064EA/TemporaryDirectory.14N5mt/Sources/xnu/bsd/netinet6/in6_mcast.c"
                       ,0x1f1);
          }
          puVar11 = puVar9;
          if (puVar9[2] != *(uint *)(lVar10 + 0x4e8)) goto LAB_fffffff00a67da70;
          puVar9[2] = in_wzr;
          goto LAB_fffffff00a67d654;
        }
        if (puVar9[2] == *(uint *)(lVar10 + 0x4e8)) break;
        FUN_fffffff00a226e08(puVar9,lVar10);
        puVar9 = puVar11;
        if (puVar11 == (uint *)0x0) goto LAB_fffffff00a67d1c4;
      }
      puVar9[2] = in_wzr;
      puVar9 = puVar11;
    } while (puVar11 != (uint *)0x0);
  }
LAB_fffffff00a67d1c4:
  FUN_fffffff00a228d30(&DAT_fffffff00add3670);
  local_68 = 0;
  local_80 = 0x1e1c;
  uStack_70 = *(undefined8 *)(param_2 + 8);
  local_78 = *(undefined8 *)param_2;
  uVar6 = FUN_fffffff00a463870(param_1,&local_80,&local_88,0);
  if ((int)uVar6 != 0) {
    return uVar6;
  }
  FUN_fffffff00a227a00(&DAT_fffffff00add3670);
  puVar11 = local_88;
  lVar10 = tpidr_el1;
  if (*(ulong *)(local_88 + 2) == 0) {
    *(ulong *)(local_88 + 2) = (ulong)*(uint *)(lVar10 + 0x4e8);
    puVar9 = *(uint **)(local_88 + 0x14);
    if (puVar9 != (uint *)0x0) goto LAB_fffffff00a67d238;
LAB_fffffff00a67d468:
    if (puVar11[2] == *(uint *)(lVar10 + 0x4e8)) {
      puVar11[2] = in_wzr;
    }
    else {
      FUN_fffffff00a226e08(puVar11,lVar10);
    }
    puVar3 = &DAT_fffffff007c77490;
    if ((DAT_fffffff007c036b4 & 1) != 0) {
      puVar3 = &DAT_fffffff007c774d0;
    }
    puVar11 = (uint *)FUN_fffffff00a2216c4(puVar3,4);
    if (puVar11 == (uint *)0x0) {
      uVar7 = (ulong)*(uint *)(lVar10 + 0x4e8);
      if (_DAT_00000008 != 0) {
        puVar9 = (uint *)0x0;
        goto LAB_fffffff00a67dac0;
      }
    }
    else {
      *puVar11 = DAT_fffffff00ad238d0 & 0xffffff | 0x22000000;
      puVar11[1] = 0;
      puVar11[2] = 0;
      puVar11[3] = 0;
      DAT_fffffff00ad238dc = DAT_fffffff00ad238dc + 1;
      if (((int)DAT_fffffff00ad238d0 < 0) &&
         (iVar4 = DAT_fffffff00ad238cc + 1, uVar5 = DAT_fffffff00ad238cc + 0xf0000001,
         DAT_fffffff00ad238cc = iVar4, uVar5 < 0xf0000002)) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa61ed0(&DAT_fffffff00ad238cc);
      }
      uVar5 = puVar11[6];
      puVar11[6] = uVar5 | 2;
      if ((DAT_fffffff007c036b4 & 1) != 0) {
        puVar11[6] = uVar5 | 6;
        *(code **)(puVar11 + 0x38) = FUN_fffffff00a67ee18;
      }
      puVar11[0x10] = 0;
      puVar9 = puVar11;
      if (*(ulong *)(puVar11 + 2) == 0) {
        *(ulong *)(puVar11 + 2) = (ulong)*(uint *)(lVar10 + 0x4e8);
        uVar7 = _DAT_00000008;
      }
      else {
LAB_fffffff00a67dac0:
        FUN_fffffff00a2262d4(puVar9,lVar10,0);
        uVar7 = _DAT_00000008;
      }
    }
    _DAT_00000008 = uVar7;
    uVar6 = *(undefined8 *)param_2;
    *(undefined8 *)(puVar11 + 0xe) = *(undefined8 *)(param_2 + 8);
    *(undefined8 *)(puVar11 + 0xc) = uVar6;
    uVar5 = FUN_fffffff00a6b2cc0(param_1,puVar11 + 0xc);
    puVar11[0x10] = uVar5;
    *(ulong *)(puVar11 + 0x12) = param_1;
    lVar8 = *(long *)(param_1 + 0x870);
    *(long *)(puVar11 + 0x1a) = lVar8;
    if (lVar8 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa5d948
                ("inm->in6m_mli != NULL",
                 "/Library/Caches/com.apple.xbs/FBE73862-C372-4A76-BC3C-8E79BBE064EA/TemporaryDirectory.14N5mt/Sources/xnu/bsd/netinet6/in6_mcast.c"
                 ,0x249);
    }
    FUN_fffffff00a68bafc(lVar8,0);
    *(uint **)(puVar11 + 0x14) = local_88;
    puVar11[0x16] = 0;
    puVar11[0x2b] = 0x18;
    *(undefined2 *)(puVar11 + 0x33) = 0;
    *(undefined2 *)((long)puVar11 + 0xd6) = 0;
    puVar11[0x22] = 0;
    puVar11[0x23] = 0;
    FUN_fffffff00a67db0c(puVar11);
    if ((puVar11[6] & 0x11) != 1) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa5d948
                ("(inm->in6m_debug & (IFD_ATTACHED | IFD_TRASHED)) == IFD_ATTACHED",
                 "/Library/Caches/com.apple.xbs/FBE73862-C372-4A76-BC3C-8E79BBE064EA/TemporaryDirectory.14N5mt/Sources/xnu/bsd/netinet6/in6_mcast.c"
                 ,599);
    }
    uVar5 = puVar11[4];
    puVar11[4] = uVar5 + 1;
    if (0xfffffffe < uVar5) {
LAB_fffffff00a67dae4:
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa4d114("%s: in6m=%p wraparound refcnt @%s:%d");
    }
    if (*(code **)(puVar11 + 0x38) != (code *)0x0) {
      (**(code **)(puVar11 + 0x38))(puVar11,1);
    }
    if (puVar11[2] == *(uint *)(lVar10 + 0x4e8)) {
      puVar11[2] = in_wzr;
    }
    else {
      FUN_fffffff00a226e08(puVar11,lVar10);
    }
    puVar9 = local_88;
    if (*(ulong *)(local_88 + 2) == 0) {
      *(ulong *)(local_88 + 2) = (ulong)*(uint *)(lVar10 + 0x4e8);
      lVar8 = *(long *)(local_88 + 0x14);
    }
    else {
      FUN_fffffff00a2262d4(local_88,lVar10,0);
      lVar8 = *(long *)(puVar9 + 0x14);
    }
    if (lVar8 != 0) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa5d948
                ("ifma->ifma_protospec == NULL",
                 "/Library/Caches/com.apple.xbs/FBE73862-C372-4A76-BC3C-8E79BBE064EA/TemporaryDirectory.14N5mt/Sources/xnu/bsd/netinet6/in6_mcast.c"
                 ,0x25c);
    }
    *(uint **)(puVar9 + 0x14) = puVar11;
    if (puVar9[2] == *(uint *)(lVar10 + 0x4e8)) {
      puVar9[2] = in_wzr;
      puVar9 = puVar11;
    }
    else {
LAB_fffffff00a67da70:
      FUN_fffffff00a226e08(puVar9,lVar10);
      puVar9 = puVar11;
    }
LAB_fffffff00a67d654:
    FUN_fffffff00a228d30(&DAT_fffffff00add3670);
  }
  else {
    FUN_fffffff00a2262d4(local_88,lVar10,0);
    puVar9 = *(uint **)(puVar11 + 0x14);
    if (puVar9 == (uint *)0x0) goto LAB_fffffff00a67d468;
LAB_fffffff00a67d238:
    if (*(long *)(puVar11 + 0xe) == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa5d948
                ("ifma->ifma_addr != NULL",
                 "/Library/Caches/com.apple.xbs/FBE73862-C372-4A76-BC3C-8E79BBE064EA/TemporaryDirectory.14N5mt/Sources/xnu/bsd/netinet6/in6_mcast.c"
                 ,0x211);
    }
    if (*(char *)(*(long *)(puVar11 + 0xe) + 1) != '\x1e') {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa5d948
                ("ifma->ifma_addr->sa_family == AF_INET6",
                 "/Library/Caches/com.apple.xbs/FBE73862-C372-4A76-BC3C-8E79BBE064EA/TemporaryDirectory.14N5mt/Sources/xnu/bsd/netinet6/in6_mcast.c"
                 ,0x212);
    }
    *(int *)(lVar10 + 0x1c0) = *(int *)(lVar10 + 0x1c0) + 1;
    if (*(ulong *)(puVar9 + 2) == 0) {
      *(ulong *)(puVar9 + 2) = (ulong)*(uint *)(lVar10 + 0x4e8) | 0x30000000;
    }
    else {
      FUN_fffffff00a2262d4(puVar9,lVar10,1);
    }
    uVar5 = puVar9[4];
    puVar9[4] = uVar5 + 1;
    if (0xfffffffe < uVar5) goto LAB_fffffff00a67dae4;
    if (*(code **)(puVar9 + 0x38) != (code *)0x0) {
      (**(code **)(puVar9 + 0x38))(puVar9,1);
    }
    if (puVar9[2] == *(uint *)(lVar10 + 0x4e8)) {
      puVar9[2] = in_wzr;
    }
    else {
      FUN_fffffff00a226e08(puVar9,lVar10);
    }
    puVar11 = local_88;
    if (local_88[2] == *(uint *)(lVar10 + 0x4e8)) {
      local_88[2] = in_wzr;
    }
    else {
      FUN_fffffff00a226e08(local_88,lVar10);
    }
    if (*(ulong *)(puVar9 + 2) == 0) {
      *(ulong *)(puVar9 + 2) = (ulong)*(uint *)(lVar10 + 0x4e8);
    }
    else {
      FUN_fffffff00a2262d4(puVar9,lVar10,0);
    }
    if (*(uint **)(puVar9 + 0x14) != puVar11) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa5d948
                ("inm->in6m_ifma == ifma",
                 "/Library/Caches/com.apple.xbs/FBE73862-C372-4A76-BC3C-8E79BBE064EA/TemporaryDirectory.14N5mt/Sources/xnu/bsd/netinet6/in6_mcast.c"
                 ,0x216);
    }
    if (*(ulong *)(puVar9 + 0x12) != param_1) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa5d948
                ("inm->in6m_ifp == ifp",
                 "/Library/Caches/com.apple.xbs/FBE73862-C372-4A76-BC3C-8E79BBE064EA/TemporaryDirectory.14N5mt/Sources/xnu/bsd/netinet6/in6_mcast.c"
                 ,0x217);
    }
    uVar7 = FUN_fffffff00a6b3564(puVar9 + 0xc,param_2,puVar9[0x10],*(undefined2 *)(param_1 + 0xcc));
    if ((uVar7 & 1) == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa5d948
                ("in6_are_addr_equal_scoped(&inm->in6m_addr, group, inm->ifscope, ifp->if_index)",
                 "/Library/Caches/com.apple.xbs/FBE73862-C372-4A76-BC3C-8E79BBE064EA/TemporaryDirectory.14N5mt/Sources/xnu/bsd/netinet6/in6_mcast.c"
                 ,0x218);
    }
    if ((puVar9[6] & 1) == 0) {
      FUN_fffffff00a67db0c(puVar9);
      if ((puVar9[6] & 0x11) != 1) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa5d948
                  ("(inm->in6m_debug & (IFD_ATTACHED | IFD_TRASHED)) == IFD_ATTACHED",
                   "/Library/Caches/com.apple.xbs/FBE73862-C372-4A76-BC3C-8E79BBE064EA/TemporaryDirectory.14N5mt/Sources/xnu/bsd/netinet6/in6_mcast.c"
                   ,0x231);
      }
    }
    else {
      uVar5 = puVar9[5];
      if (uVar5 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa5d948
                  ("inm->in6m_reqcnt >= 1",
                   "/Library/Caches/com.apple.xbs/FBE73862-C372-4A76-BC3C-8E79BBE064EA/TemporaryDirectory.14N5mt/Sources/xnu/bsd/netinet6/in6_mcast.c"
                   ,0x21a);
      }
      puVar9[5] = uVar5 + 1;
      if (0xfffffffe < uVar5) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa5d948
                  ("inm->in6m_reqcnt != 0",
                   "/Library/Caches/com.apple.xbs/FBE73862-C372-4A76-BC3C-8E79BBE064EA/TemporaryDirectory.14N5mt/Sources/xnu/bsd/netinet6/in6_mcast.c"
                   ,0x21c);
      }
    }
    if (puVar9[2] == *(uint *)(lVar10 + 0x4e8)) {
      puVar9[2] = in_wzr;
    }
    else {
      FUN_fffffff00a226e08(puVar9,lVar10);
    }
    FUN_fffffff00a228d30(&DAT_fffffff00add3670);
    FUN_fffffff00a464f60(local_88);
  }
  if (*(ulong *)(puVar9 + 2) == 0) {
    *(ulong *)(puVar9 + 2) = (ulong)*(uint *)(lVar10 + 0x4e8);
  }
  else {
    FUN_fffffff00a2262d4(puVar9,lVar10,0);
  }
  uVar6 = FUN_fffffff00a67dd20(puVar9,param_3);
  if ((int)uVar6 == 0) {
    uVar6 = FUN_fffffff00a68dec8(puVar9,&local_b8,param_5);
    if ((int)uVar6 == 0) {
      if (puVar9[2] == *(uint *)(lVar10 + 0x4e8)) {
        puVar9[2] = in_wzr;
      }
      else {
        FUN_fffffff00a226e08(puVar9,lVar10);
      }
      uVar6 = 0;
      *param_4 = puVar9;
      goto LAB_fffffff00a67d7fc;
    }
    FUN_fffffff00a67e3e8(param_3);
  }
  if (DAT_fffffff00ad85b04 != 0) {
    uVar7 = (ulong)puVar9 & 0x7ffffffffff;
    if (((ulong)puVar9 & 0x80000000000000) != 0) {
      uVar7 = (ulong)puVar9 | 0xffffff8000000000;
    }
    if ((((DAT_fffffff007c6a360 <= uVar7 || uVar7 < DAT_fffffff007c6a358) &&
         (uVar7 < DAT_fffffff007c6a378 || DAT_fffffff007c6a380 <= uVar7)) &&
        (DAT_fffffff007c6a3a8 <= uVar7 || uVar7 < DAT_fffffff007c6a3a0)) &&
       (uVar7 + 0x2400000000 >> 0x25 == 0)) {
      FUN_fffffff00a1d12d4(uVar7);
    }
  }
  puVar1 = (ulong *)(puVar9 + 2);
  if ((uint)*puVar1 == *(uint *)(lVar10 + 0x4e8)) {
    *(uint *)puVar1 = in_wzr;
  }
  else {
    FUN_fffffff00a226e08(puVar9,lVar10);
  }
  FUN_fffffff00a227a00(&DAT_fffffff00add3670);
  if (*puVar1 == 0) {
    *puVar1 = (ulong)*(uint *)(lVar10 + 0x4e8);
  }
  else {
    FUN_fffffff00a2262d4(puVar9,lVar10,0);
  }
  iVar4 = FUN_fffffff00a67e580(puVar9);
  if (iVar4 == 0) {
    if (puVar9[2] == *(uint *)(lVar10 + 0x4e8)) {
      puVar9[2] = in_wzr;
    }
    else {
      FUN_fffffff00a226e08(puVar9,lVar10);
    }
    FUN_fffffff00a228d30(&DAT_fffffff00add3670);
  }
  else {
    if (((puVar9[6] & 1) != 0) || (puVar9[5] != 0)) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa5d948
                ("!lastref || (!(inm->in6m_debug & IFD_ATTACHED) && inm->in6m_reqcnt == 0)",
                 "/Library/Caches/com.apple.xbs/FBE73862-C372-4A76-BC3C-8E79BBE064EA/TemporaryDirectory.14N5mt/Sources/xnu/bsd/netinet6/in6_mcast.c"
                 ,0x543);
    }
    if (puVar9[2] == *(uint *)(lVar10 + 0x4e8)) {
      puVar9[2] = in_wzr;
    }
    else {
      FUN_fffffff00a226e08(puVar9,lVar10);
    }
    FUN_fffffff00a228d30(&DAT_fffffff00add3670);
    FUN_fffffff00a67e75c(puVar9,0);
  }
  FUN_fffffff00a67e75c(puVar9,0);
LAB_fffffff00a67d7fc:
  local_a8 = CONCAT31(local_a8._1_3_,1);
  FUN_fffffff00a68784c(&local_b8);
  return uVar6;
}

