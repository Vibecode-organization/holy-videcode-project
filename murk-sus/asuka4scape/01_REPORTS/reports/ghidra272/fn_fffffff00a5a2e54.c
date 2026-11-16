// FUN_fffffff00a5a2e54 @ fffffff00a5a2e54 size=2724

void FUN_fffffff00a5a2e54(ulong param_1,uint *param_2,undefined8 *param_3,undefined8 *param_4)

{
  ulong *puVar1;
  undefined *puVar2;
  ulong uVar3;
  uint uVar4;
  int iVar5;
  undefined8 uVar6;
  long lVar7;
  uint *puVar8;
  long lVar9;
  uint *puVar10;
  uint in_wzr;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  uint *local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined4 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  local_58 = DAT_fffffff00ad30000;
  local_a0 = 0;
  local_98 = 0;
  local_90 = 0;
  if (DAT_fffffff00ad7e080 != 0) {
    local_80 = 0;
    uStack_78 = 0;
    FUN_fffffff00a8dd3c8(2,param_2,&local_80,0x10);
    uVar3 = param_1 & 0x7ffffffffff;
    if ((param_1 & 0x80000000000000) != 0) {
      uVar3 = param_1 | 0xffffff8000000000;
    }
    if ((((DAT_fffffff007c6a360 <= uVar3 || uVar3 < DAT_fffffff007c6a358) &&
         (uVar3 < DAT_fffffff007c6a378 || DAT_fffffff007c6a380 <= uVar3)) &&
        (DAT_fffffff007c6a3a8 <= uVar3 || uVar3 < DAT_fffffff007c6a3a0)) &&
       (uVar3 + 0x2400000000 >> 0x25 == 0)) {
      FUN_fffffff00a1d12d4();
    }
  }
  local_80 = 0;
  uStack_78 = 0;
  local_70 = 0;
  *param_4 = 0;
  if (param_3 == (undefined8 *)0x0) {
    local_98 = 0;
    local_a0 = 0;
    local_90 = 0x200;
    param_3 = &local_a0;
  }
  local_68 = 0;
  uStack_60 = 0;
  local_88 = (uint *)0x0;
  FUN_fffffff00a228180(&DAT_fffffff00adcf430);
  if (DAT_fffffff00ad7e750 != (uint *)0x0) {
    lVar9 = tpidr_el1;
    puVar8 = DAT_fffffff00ad7e750;
    do {
      while( true ) {
        puVar10 = *(uint **)(puVar8 + 8);
        *(int *)(lVar9 + 0x1c0) = *(int *)(lVar9 + 0x1c0) + 1;
        if (*(ulong *)(puVar8 + 2) == 0) {
          *(ulong *)(puVar8 + 2) = (ulong)*(uint *)(lVar9 + 0x4e8) | 0x30000000;
        }
        else {
          FUN_fffffff00a2262d4(puVar8,lVar9,1);
        }
        if ((*(ulong *)(puVar8 + 0xe) == param_1) && (puVar8[0xc] == *param_2)) {
          uVar4 = puVar8[4];
          puVar8[4] = uVar4 + 1;
          if (0xfffffffe < uVar4) goto LAB_fffffff00a5a38d0;
          if (*(code **)(puVar8 + 0x34) != (code *)0x0) {
            (**(code **)(puVar8 + 0x34))(puVar8,1);
          }
          puVar1 = (ulong *)(puVar8 + 2);
          if ((uint)*puVar1 == *(uint *)(lVar9 + 0x4e8)) {
            *(uint *)puVar1 = in_wzr;
          }
          else {
            FUN_fffffff00a226e08(puVar8,lVar9);
          }
          if (*puVar1 == 0) {
            *puVar1 = (ulong)*(uint *)(lVar9 + 0x4e8);
            uVar4 = puVar8[5];
          }
          else {
            FUN_fffffff00a2262d4(puVar8,lVar9,0);
            uVar4 = puVar8[5];
          }
          if (uVar4 == 0) {
                    /* WARNING: Subroutine does not return */
            FUN_fffffff00aa5d948
                      ("inm->inm_reqcnt >= 1",
                       "/Library/Caches/com.apple.xbs/FBE73862-C372-4A76-BC3C-8E79BBE064EA/TemporaryDirectory.14N5mt/Sources/xnu/bsd/netinet/in_mcast.c"
                       ,0x22c);
          }
          puVar8[5] = uVar4 + 1;
          if (0xfffffffe < uVar4) {
                    /* WARNING: Subroutine does not return */
            FUN_fffffff00aa5d948
                      ("inm->inm_reqcnt != 0",
                       "/Library/Caches/com.apple.xbs/FBE73862-C372-4A76-BC3C-8E79BBE064EA/TemporaryDirectory.14N5mt/Sources/xnu/bsd/netinet/in_mcast.c"
                       ,0x22e);
          }
          puVar10 = puVar8;
          if (puVar8[2] != *(uint *)(lVar9 + 0x4e8)) goto LAB_fffffff00a5a386c;
          puVar8[2] = in_wzr;
          goto LAB_fffffff00a5a342c;
        }
        if (puVar8[2] == *(uint *)(lVar9 + 0x4e8)) break;
        FUN_fffffff00a226e08(puVar8,lVar9);
        puVar8 = puVar10;
        if (puVar10 == (uint *)0x0) goto LAB_fffffff00a5a3010;
      }
      puVar8[2] = in_wzr;
      puVar8 = puVar10;
    } while (puVar10 != (uint *)0x0);
  }
LAB_fffffff00a5a3010:
  FUN_fffffff00a228d30(&DAT_fffffff00adcf430);
  uStack_60 = 0;
  local_68 = CONCAT44(*param_2,0x210);
  uVar6 = FUN_fffffff00a463870(param_1,&local_68,&local_88,0);
  if ((int)uVar6 != 0) goto LAB_fffffff00a5a35e4;
  FUN_fffffff00a227a00(&DAT_fffffff00adcf430);
  puVar10 = local_88;
  lVar9 = tpidr_el1;
  if (*(ulong *)(local_88 + 2) == 0) {
    *(ulong *)(local_88 + 2) = (ulong)*(uint *)(lVar9 + 0x4e8);
    puVar8 = *(uint **)(local_88 + 0x14);
    if (puVar8 == (uint *)0x0) goto LAB_fffffff00a5a3274;
LAB_fffffff00a5a307c:
    if (*(long *)(puVar10 + 0xe) == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa5d948
                ("ifma->ifma_addr != NULL",
                 "/Library/Caches/com.apple.xbs/FBE73862-C372-4A76-BC3C-8E79BBE064EA/TemporaryDirectory.14N5mt/Sources/xnu/bsd/netinet/in_mcast.c"
                 ,0x24e);
    }
    if (*(char *)(*(long *)(puVar10 + 0xe) + 1) != '\x02') {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa5d948
                ("ifma->ifma_addr->sa_family == AF_INET",
                 "/Library/Caches/com.apple.xbs/FBE73862-C372-4A76-BC3C-8E79BBE064EA/TemporaryDirectory.14N5mt/Sources/xnu/bsd/netinet/in_mcast.c"
                 ,0x24f);
    }
    *(int *)(lVar9 + 0x1c0) = *(int *)(lVar9 + 0x1c0) + 1;
    if (*(ulong *)(puVar8 + 2) == 0) {
      *(ulong *)(puVar8 + 2) = (ulong)*(uint *)(lVar9 + 0x4e8) | 0x30000000;
    }
    else {
      FUN_fffffff00a2262d4(puVar8,lVar9,1);
    }
    uVar4 = puVar8[4];
    puVar8[4] = uVar4 + 1;
    if (0xfffffffe < uVar4) {
LAB_fffffff00a5a38d0:
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa4d114("%s: inm=%p wraparound refcnt @%s:%d");
    }
    if (*(code **)(puVar8 + 0x34) != (code *)0x0) {
      (**(code **)(puVar8 + 0x34))(puVar8,1);
    }
    if (puVar8[2] == *(uint *)(lVar9 + 0x4e8)) {
      puVar8[2] = in_wzr;
    }
    else {
      FUN_fffffff00a226e08(puVar8,lVar9);
    }
    puVar10 = local_88;
    if (local_88[2] == *(uint *)(lVar9 + 0x4e8)) {
      local_88[2] = in_wzr;
    }
    else {
      FUN_fffffff00a226e08(local_88,lVar9);
    }
    if (*(ulong *)(puVar8 + 2) == 0) {
      *(ulong *)(puVar8 + 2) = (ulong)*(uint *)(lVar9 + 0x4e8);
    }
    else {
      FUN_fffffff00a2262d4(puVar8,lVar9,0);
    }
    if (*(uint **)(puVar8 + 0x10) != puVar10) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa5d948
                ("inm->inm_ifma == ifma",
                 "/Library/Caches/com.apple.xbs/FBE73862-C372-4A76-BC3C-8E79BBE064EA/TemporaryDirectory.14N5mt/Sources/xnu/bsd/netinet/in_mcast.c"
                 ,0x253);
    }
    if (*(ulong *)(puVar8 + 0xe) != param_1) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa5d948
                ("inm->inm_ifp == ifp",
                 "/Library/Caches/com.apple.xbs/FBE73862-C372-4A76-BC3C-8E79BBE064EA/TemporaryDirectory.14N5mt/Sources/xnu/bsd/netinet/in_mcast.c"
                 ,0x254);
    }
    if (puVar8[0xc] != *param_2) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa5d948
                ("in_hosteq(inm->inm_addr, *group)",
                 "/Library/Caches/com.apple.xbs/FBE73862-C372-4A76-BC3C-8E79BBE064EA/TemporaryDirectory.14N5mt/Sources/xnu/bsd/netinet/in_mcast.c"
                 ,0x255);
    }
    if ((puVar8[6] & 1) == 0) {
      FUN_fffffff00a5a38f8(puVar8);
      if ((puVar8[6] & 0x11) != 1) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa5d948
                  ("(inm->inm_debug & (IFD_ATTACHED | IFD_TRASHED)) == IFD_ATTACHED",
                   "/Library/Caches/com.apple.xbs/FBE73862-C372-4A76-BC3C-8E79BBE064EA/TemporaryDirectory.14N5mt/Sources/xnu/bsd/netinet/in_mcast.c"
                   ,0x26e);
      }
    }
    else {
      uVar4 = puVar8[5];
      if (uVar4 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa5d948
                  ("inm->inm_reqcnt >= 1",
                   "/Library/Caches/com.apple.xbs/FBE73862-C372-4A76-BC3C-8E79BBE064EA/TemporaryDirectory.14N5mt/Sources/xnu/bsd/netinet/in_mcast.c"
                   ,599);
      }
      puVar8[5] = uVar4 + 1;
      if (0xfffffffe < uVar4) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa5d948
                  ("inm->inm_reqcnt != 0",
                   "/Library/Caches/com.apple.xbs/FBE73862-C372-4A76-BC3C-8E79BBE064EA/TemporaryDirectory.14N5mt/Sources/xnu/bsd/netinet/in_mcast.c"
                   ,0x259);
      }
    }
    if (puVar8[2] == *(uint *)(lVar9 + 0x4e8)) {
      puVar8[2] = in_wzr;
    }
    else {
      FUN_fffffff00a226e08(puVar8,lVar9);
    }
    FUN_fffffff00a228d30(&DAT_fffffff00adcf430);
    FUN_fffffff00a464f60(local_88);
  }
  else {
    FUN_fffffff00a2262d4(local_88,lVar9,0);
    puVar8 = *(uint **)(puVar10 + 0x14);
    if (puVar8 != (uint *)0x0) goto LAB_fffffff00a5a307c;
LAB_fffffff00a5a3274:
    if (puVar10[2] == *(uint *)(lVar9 + 0x4e8)) {
      puVar10[2] = in_wzr;
    }
    else {
      FUN_fffffff00a226e08(puVar10,lVar9);
    }
    puVar2 = &DAT_fffffff007c75c10;
    if ((DAT_fffffff007bfbc34 & 1) != 0) {
      puVar2 = &DAT_fffffff007c75c50;
    }
    puVar10 = (uint *)FUN_fffffff00a2216c4(puVar2,4);
    if (puVar10 != (uint *)0x0) {
      *puVar10 = DAT_fffffff00ad23350 & 0xffffff | 0x22000000;
      puVar10[1] = 0;
      puVar10[2] = 0;
      puVar10[3] = 0;
      DAT_fffffff00ad2335c = DAT_fffffff00ad2335c + 1;
      if (((int)DAT_fffffff00ad23350 < 0) &&
         (iVar5 = DAT_fffffff00ad2334c + 1, uVar4 = DAT_fffffff00ad2334c + 0xf0000001,
         DAT_fffffff00ad2334c = iVar5, uVar4 < 0xf0000002)) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa61ed0(&DAT_fffffff00ad2334c);
      }
      uVar4 = puVar10[6];
      puVar10[6] = uVar4 | 2;
      if ((DAT_fffffff007bfbc34 & 1) != 0) {
        puVar10[6] = uVar4 | 6;
        *(code **)(puVar10 + 0x34) = FUN_fffffff00a5a4a10;
      }
    }
    if (*(ulong *)(puVar10 + 2) == 0) {
      *(ulong *)(puVar10 + 2) = (ulong)*(uint *)(lVar9 + 0x4e8);
    }
    else {
      FUN_fffffff00a2262d4(puVar10,lVar9,0);
    }
    puVar10[0xc] = *param_2;
    *(ulong *)(puVar10 + 0xe) = param_1;
    lVar7 = *(long *)(param_1 + 0x868);
    *(long *)(puVar10 + 0x16) = lVar7;
    if (lVar7 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa5d948
                ("inm->inm_igi != NULL",
                 "/Library/Caches/com.apple.xbs/FBE73862-C372-4A76-BC3C-8E79BBE064EA/TemporaryDirectory.14N5mt/Sources/xnu/bsd/netinet/in_mcast.c"
                 ,0x284);
    }
    FUN_fffffff00a590270(lVar7,0);
    *(uint **)(puVar10 + 0x10) = local_88;
    puVar10[0x13] = 0;
    puVar10[0x27] = 0x18;
    *(undefined2 *)(puVar10 + 0x2f) = 0;
    *(undefined2 *)((long)puVar10 + 0xc6) = 0;
    puVar10[0x1e] = 0;
    puVar10[0x1f] = 0;
    FUN_fffffff00a5a38f8(puVar10);
    if ((puVar10[6] & 0x11) != 1) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa5d948
                ("(inm->inm_debug & (IFD_ATTACHED | IFD_TRASHED)) == IFD_ATTACHED",
                 "/Library/Caches/com.apple.xbs/FBE73862-C372-4A76-BC3C-8E79BBE064EA/TemporaryDirectory.14N5mt/Sources/xnu/bsd/netinet/in_mcast.c"
                 ,0x291);
    }
    uVar4 = puVar10[4];
    puVar10[4] = uVar4 + 1;
    if (0xfffffffe < uVar4) goto LAB_fffffff00a5a38d0;
    if (*(code **)(puVar10 + 0x34) != (code *)0x0) {
      (**(code **)(puVar10 + 0x34))(puVar10,1);
    }
    if (puVar10[2] == *(uint *)(lVar9 + 0x4e8)) {
      puVar10[2] = in_wzr;
    }
    else {
      FUN_fffffff00a226e08(puVar10,lVar9);
    }
    puVar8 = local_88;
    if (*(ulong *)(local_88 + 2) == 0) {
      *(ulong *)(local_88 + 2) = (ulong)*(uint *)(lVar9 + 0x4e8);
      lVar7 = *(long *)(local_88 + 0x14);
    }
    else {
      FUN_fffffff00a2262d4(local_88,lVar9,0);
      lVar7 = *(long *)(puVar8 + 0x14);
    }
    if (lVar7 != 0) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa5d948
                ("ifma->ifma_protospec == NULL",
                 "/Library/Caches/com.apple.xbs/FBE73862-C372-4A76-BC3C-8E79BBE064EA/TemporaryDirectory.14N5mt/Sources/xnu/bsd/netinet/in_mcast.c"
                 ,0x296);
    }
    *(uint **)(puVar8 + 0x14) = puVar10;
    if (puVar8[2] == *(uint *)(lVar9 + 0x4e8)) {
      puVar8[2] = in_wzr;
      puVar8 = puVar10;
    }
    else {
LAB_fffffff00a5a386c:
      FUN_fffffff00a226e08(puVar8,lVar9);
      puVar8 = puVar10;
    }
LAB_fffffff00a5a342c:
    FUN_fffffff00a228d30(&DAT_fffffff00adcf430);
  }
  if (*(ulong *)(puVar8 + 2) == 0) {
    *(ulong *)(puVar8 + 2) = (ulong)*(uint *)(lVar9 + 0x4e8);
  }
  else {
    FUN_fffffff00a2262d4(puVar8,lVar9,0);
  }
  uVar6 = FUN_fffffff00a5a3b38(puVar8,param_3);
  if ((int)uVar6 == 0) {
    uVar6 = FUN_fffffff00a5972a4(puVar8,&local_80);
    if ((int)uVar6 != 0) {
      FUN_fffffff00a5a425c(param_3);
      goto joined_r0xfffffff00a5a3490;
    }
    if (puVar8[2] == *(uint *)(lVar9 + 0x4e8)) {
      puVar8[2] = in_wzr;
    }
    else {
      FUN_fffffff00a226e08(puVar8,lVar9);
    }
    uVar6 = 0;
    *param_4 = puVar8;
  }
  else {
joined_r0xfffffff00a5a3490:
    if (DAT_fffffff00ad7e080 != 0) {
      uVar3 = (ulong)puVar8 & 0x7ffffffffff;
      if (((ulong)puVar8 & 0x80000000000000) != 0) {
        uVar3 = (ulong)puVar8 | 0xffffff8000000000;
      }
      if ((((DAT_fffffff007c6a360 <= uVar3 || uVar3 < DAT_fffffff007c6a358) &&
           (uVar3 < DAT_fffffff007c6a378 || DAT_fffffff007c6a380 <= uVar3)) &&
          (DAT_fffffff007c6a3a8 <= uVar3 || uVar3 < DAT_fffffff007c6a3a0)) &&
         (uVar3 + 0x2400000000 >> 0x25 == 0)) {
        FUN_fffffff00a1d12d4(uVar3);
      }
    }
    puVar1 = (ulong *)(puVar8 + 2);
    if ((uint)*puVar1 == *(uint *)(lVar9 + 0x4e8)) {
      *(uint *)puVar1 = in_wzr;
    }
    else {
      FUN_fffffff00a226e08(puVar8,lVar9);
    }
    FUN_fffffff00a227a00(&DAT_fffffff00adcf430);
    if (*puVar1 == 0) {
      *puVar1 = (ulong)*(uint *)(lVar9 + 0x4e8);
    }
    else {
      FUN_fffffff00a2262d4(puVar8,lVar9,0);
    }
    iVar5 = FUN_fffffff00a5a43f4(puVar8);
    if (iVar5 == 0) {
      if (puVar8[2] == *(uint *)(lVar9 + 0x4e8)) {
        puVar8[2] = in_wzr;
      }
      else {
        FUN_fffffff00a226e08(puVar8,lVar9);
      }
      FUN_fffffff00a228d30(&DAT_fffffff00adcf430);
    }
    else {
      if (((puVar8[6] & 1) != 0) || (puVar8[5] != 0)) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa5d948
                  ("!lastref || (!(inm->inm_debug & IFD_ATTACHED) && inm->inm_reqcnt == 0)",
                   "/Library/Caches/com.apple.xbs/FBE73862-C372-4A76-BC3C-8E79BBE064EA/TemporaryDirectory.14N5mt/Sources/xnu/bsd/netinet/in_mcast.c"
                   ,0x555);
      }
      if (puVar8[2] == *(uint *)(lVar9 + 0x4e8)) {
        puVar8[2] = in_wzr;
      }
      else {
        FUN_fffffff00a226e08(puVar8,lVar9);
      }
      FUN_fffffff00a228d30(&DAT_fffffff00adcf430);
      FUN_fffffff00a5a263c(puVar8,0);
    }
    FUN_fffffff00a5a263c(puVar8,0);
  }
  local_70 = CONCAT31(local_70._1_3_,1);
  FUN_fffffff00a593b00(&local_80);
LAB_fffffff00a5a35e4:
  if (DAT_fffffff00ad30000 != local_58) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff00aa4c590(uVar6);
  }
  return;
}

