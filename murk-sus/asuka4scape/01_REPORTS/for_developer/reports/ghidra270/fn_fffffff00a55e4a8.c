// FUN_fffffff00a55e4a8 @ fffffff00a55e4a8 size=2856

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fffffff00a55e4a8
               (long param_1,long param_2,undefined2 *param_3,ulong param_4,long param_5,
               long param_6)

{
  uint uVar1;
  undefined4 uVar2;
  code *pcVar3;
  bool bVar4;
  int iVar5;
  uint uVar6;
  ulong uVar7;
  undefined8 uVar8;
  long lVar9;
  long lVar10;
  bool bVar11;
  undefined2 *puVar12;
  long lVar13;
  uint *puVar14;
  byte *pbVar15;
  ulong uVar16;
  ulong uVar17;
  int in_wzr;
  long local_98;
  long local_90;
  undefined8 uStack_88;
  long local_80;
  long lStack_78;
  undefined4 local_70;
  long local_68;
  
  local_68 = DAT_fffffff00acf0000;
  local_98 = 0;
  local_80 = 0;
  lStack_78 = 0;
  local_70 = 0;
  uVar7 = 0x16;
  if ((param_1 == 0) || (param_2 == 0)) goto LAB_fffffff00a55e5a4;
  if (*(char *)(param_2 + 1) != '\x02') {
    uVar7 = 0x2f;
    goto LAB_fffffff00a55e5a4;
  }
  if (((*(ushort *)(param_1 + 0xd2) ^ 0xffff) & 0x41) != 0) {
    uVar7 = 0x32;
    goto LAB_fffffff00a55e5a4;
  }
  if ((param_5 != 0) && (uVar7 = FUN_fffffff00a464268(param_2,param_5,&local_98), (int)uVar7 != 0))
  goto LAB_fffffff00a55e5a4;
  if (param_6 == 0) {
    iVar5 = FUN_fffffff00a55ddac(*(undefined4 *)(param_2 + 4),param_1);
    if (iVar5 != 0) goto LAB_fffffff00a55e5fc;
LAB_fffffff00a55e6b4:
    lVar9 = local_98;
    puVar14 = (uint *)(param_2 + 4);
    if ((*(short *)(param_1 + 0xd2) < 0) && ((*puVar14 & 0xf0) == 0xe0)) goto LAB_fffffff00a55e6cc;
    if (local_98 == 0) {
LAB_fffffff00a55e7bc:
      uVar6 = FUN_fffffff00a55efd0(puVar14,1,0,&local_98,*(undefined2 *)(param_1 + 0xcc));
    }
    else {
      if (*(long *)(local_98 + 0xa0) == 0) {
        if (local_98 == param_5) {
          FUN_fffffff00a46123c(local_98);
          FUN_fffffff00a460c2c(lVar9);
        }
        else {
          FUN_fffffff00a460c2c();
          FUN_fffffff00a45b594(lVar9,0);
        }
        goto LAB_fffffff00a55e7bc;
      }
      uVar6 = 0;
    }
    lVar9 = local_98;
    uVar7 = DAT_fffffff00ad55730;
    if ((uVar6 == 0) && (local_98 != 0)) {
      lVar13 = *(long *)(local_98 + 0xa0);
      if (lVar13 == 0) {
        uVar7 = 0x41;
        goto LAB_fffffff00a55e85c;
      }
      if ((*(ushort *)(param_1 + 0xd2) >> 7 & 1) != 0) {
        bVar11 = true;
        uVar7 = 0x2d;
        bVar4 = true;
        goto LAB_fffffff00a55e9a0;
      }
      pbVar15 = *(byte **)(local_98 + 0x80);
      if (*(long *)(local_98 + 0x130) == 0) {
        if (*(int *)(local_98 + 0xdc) != 0) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff00aa1cb7c
                    ("route->rt_expire != 0 || route->rt_rmx.rmx_expire == 0",
                     "/Library/Caches/com.apple.xbs/D9089588-4191-473E-9025-574E023945ED/TemporaryDirectory.nLq3V8/Sources/xnu/bsd/netinet/in_arp.c"
                     ,0x5bb);
        }
      }
      else if (*(int *)(local_98 + 0xdc) == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa1cb7c
                  ("route->rt_expire == 0 || route->rt_rmx.rmx_expire != 0",
                   "/Library/Caches/com.apple.xbs/D9089588-4191-473E-9025-574E023945ED/TemporaryDirectory.nLq3V8/Sources/xnu/bsd/netinet/in_arp.c"
                   ,0x5ba);
      }
      if ((((DAT_fffffff00ad55730 <= *(long *)(local_98 + 0x130) - 1U) && (pbVar15 != (byte *)0x0))
          && (pbVar15[1] == 0x12)) && (pbVar15[6] != 0)) {
        iVar5 = FUN_fffffff00a55f20c(lVar13);
        if ((((pbVar15 + 0x14 <= pbVar15) || ((param_3 != (undefined2 *)0x0 && (param_4 == 0)))) ||
            ((undefined2 *)((long)param_3 + 0xff) < param_3)) || (pbVar15 + 0xff < pbVar15))
        goto LAB_fffffff00a55e948;
        if (*pbVar15 <= param_4) {
          param_4 = (ulong)*pbVar15;
        }
        FUN_fffffff00aa24d30(param_3,pbVar15,param_4);
        uVar17 = *(ulong *)(lVar13 + 0x50);
        if (uVar17 != 0) {
          *(ulong *)(lVar13 + 0x58) = DAT_fffffff00ad55730;
          uVar16 = *(ulong *)(lVar9 + 0x90);
          if ((iVar5 == 0) || ((*(byte *)(lVar13 + 0x74) >> 1 & 1) != 0)) {
            FUN_fffffff00a1ead70(lVar9 + 0x60);
            FUN_fffffff00a1ea97c(uVar17);
            uVar6 = *(uint *)(uVar17 + 0x3c);
            if (uVar6 < _DAT_fffffff00acd26bc) {
              bVar4 = uVar6 != 0;
              if (uVar6 == 0) {
                *(ulong *)(lVar13 + 0x68) = uVar7 + _DAT_fffffff00acd26ac;
                *(uint *)(lVar13 + 0x74) = *(uint *)(lVar13 + 0x74) | 2;
                uVar6 = *(uint *)(uVar17 + 0x3c);
              }
              *(uint *)(uVar17 + 0x3c) = uVar6 + 1;
              if (&stack0x0000007f < &local_80) goto LAB_fffffff00a55e948;
              lStack_78 = 0;
              local_70 = 0;
              local_80 = (ulong)*(byte *)(param_1 + 0xfb) << 0x30;
              if (((&stack0x0000007f < &lStack_78) || (6 < *(byte *)(param_1 + 0xfb))) ||
                 (FUN_fffffff00aa24d30(&lStack_78,uVar17 + 0x62), uVar17 + 0x78 <= uVar17))
              goto LAB_fffffff00a55e948;
              lVar9 = tpidr_el1;
              if (*(int *)(uVar17 + 8) == *(int *)(lVar9 + 0x4e8)) {
                *(int *)(uVar17 + 8) = in_wzr;
              }
              else {
                FUN_fffffff00a1eab60(uVar17,lVar9);
              }
              FUN_fffffff00a1ea97c(uVar16);
              iVar5 = *(int *)(uVar16 + 0x10);
              *(int *)(uVar16 + 0x10) = iVar5 + 1;
              if (iVar5 + 0xf0000001U < 0xf0000002) goto LAB_fffffff00a55ef68;
              if (uVar16 + 0x70 <= uVar16) goto LAB_fffffff00a55e948;
              uVar8 = *(undefined8 *)(uVar16 + 0x18);
              if (*(int *)(uVar16 + 8) == *(int *)(lVar9 + 0x4e8)) {
                *(int *)(uVar16 + 8) = in_wzr;
              }
              else {
                FUN_fffffff00a1eab60(uVar16,lVar9);
              }
              lVar9 = local_98;
              uVar2 = *(undefined4 *)(local_98 + 0x74);
              FUN_fffffff00a460c2c(local_98);
              FUN_fffffff00a433324(param_1,1,0,uVar8,&local_80,param_2,uVar2);
              FUN_fffffff00a55f390(uVar16);
              FUN_fffffff00a460cec(lVar9,0);
              uVar7 = 0;
              bVar11 = false;
            }
            else {
              if (uVar17 + 0x78 <= uVar17) goto LAB_fffffff00a55e948;
              lVar9 = tpidr_el1;
              if (*(int *)(uVar17 + 8) == *(int *)(lVar9 + 0x4e8)) {
                *(int *)(uVar17 + 8) = in_wzr;
              }
              else {
                FUN_fffffff00a1eab60(uVar17);
              }
              if ((iVar5 == 0) || ((*(byte *)(lVar13 + 0x74) >> 1 & 1) != 0))
              goto LAB_fffffff00a55ec24;
              uVar7 = 0;
              bVar11 = true;
              bVar4 = true;
            }
            goto LAB_fffffff00a55e9a0;
          }
        }
LAB_fffffff00a55e98c:
        uVar7 = 0;
        goto LAB_fffffff00a55e99c;
      }
LAB_fffffff00a55ec24:
      if (param_6 == 0) {
        uVar6 = 0;
        iVar5 = *(int *)(lVar13 + 0x70) + 1;
        *(int *)(lVar13 + 0x70) = iVar5;
      }
      else {
        uVar6 = FUN_fffffff00a55f3cc(lVar13,param_6);
        iVar5 = *(int *)(lVar13 + 0x70);
      }
      lVar9 = local_98;
      if (iVar5 + *(int *)(lVar13 + 0x30) == 1) {
        *(ulong *)(lVar13 + 0x68) = uVar7 + _DAT_fffffff00acd26ac;
        *(uint *)(lVar13 + 0x74) = *(uint *)(lVar13 + 0x74) | 2;
      }
      if ((*(ulong *)(local_98 + 0x130) == 0) ||
         ((*(uint *)(local_98 + 0x74) = *(uint *)(local_98 + 0x74) & 0xfffffff7,
          *(ulong *)(local_98 + 0x130) == uVar7 && (*(int *)(lVar13 + 0x60) != 0)))) {
LAB_fffffff00a55ee3c:
        if (param_6 == 0) {
          uVar6 = 1;
        }
        if ((uVar6 & 1) == 0) {
          bVar4 = true;
          lVar9 = param_6;
          do {
            lVar9 = FUN_fffffff00a74f6b4(lVar9);
            param_6 = 0;
            bVar11 = false;
            uVar7 = 0xfffffffe;
          } while (lVar9 != 0);
        }
        else {
          bVar11 = false;
          bVar4 = true;
          uVar7 = 0xfffffffe;
        }
        goto LAB_fffffff00a55e9a0;
      }
      *(ulong *)(local_98 + 0x130) = uVar7;
      if (uVar7 == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = (*(int *)(local_98 + 0x138) + (int)uVar7) - *(int *)(local_98 + 0x140);
      }
      *(int *)(local_98 + 0xdc) = iVar5;
      uVar1 = *(uint *)(lVar13 + 0x60);
      *(uint *)(lVar13 + 0x60) = uVar1 + 1;
      if (uVar1 < *(uint *)(lVar13 + 100)) {
        uVar7 = *(ulong *)(local_98 + 0x90);
        uVar17 = *(ulong *)(lVar13 + 0x50);
        FUN_fffffff00a1ead70(local_98 + 0x60);
        if (uVar17 != 0) {
          FUN_fffffff00a1ea97c(uVar17);
          *(int *)(uVar17 + 0x3c) = *(int *)(uVar17 + 0x3c) + 1;
          if (uVar17 + 0x78 <= uVar17) goto LAB_fffffff00a55e948;
          lVar9 = tpidr_el1;
          if (*(int *)(uVar17 + 8) == *(int *)(lVar9 + 0x4e8)) {
            *(int *)(uVar17 + 8) = in_wzr;
          }
          else {
            FUN_fffffff00a1eab60(uVar17);
          }
        }
        bVar4 = true;
        if (((*(char *)(param_1 + 0xfb) == '\x06') && ((*(byte *)(local_98 + 0x77) >> 4 & 1) != 0))
           && (1 < *(uint *)(lVar13 + 0x60))) {
          bVar4 = false;
          *(uint *)(lVar13 + 0x74) = *(uint *)(lVar13 + 0x74) | 1;
        }
        FUN_fffffff00a1ea97c(uVar7);
        iVar5 = *(int *)(uVar7 + 0x10);
        *(int *)(uVar7 + 0x10) = iVar5 + 1;
        if (iVar5 + 0xf0000001U < 0xf0000002) {
LAB_fffffff00a55ef68:
                    /* WARNING: Subroutine does not return */
          FUN_fffffff00aa21104();
        }
        if (uVar7 + 0x70 <= uVar7) {
LAB_fffffff00a55e948:
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x5519,0xfffffff00a55e94c);
          (*pcVar3)();
        }
        uVar8 = *(undefined8 *)(uVar7 + 0x18);
        lVar9 = tpidr_el1;
        if (*(int *)(uVar7 + 8) == *(int *)(lVar9 + 0x4e8)) {
          *(int *)(uVar7 + 8) = in_wzr;
          lVar10 = *(long *)(lVar13 + 0x50);
          lVar9 = local_98;
        }
        else {
          FUN_fffffff00a1eab60(uVar7);
          lVar10 = *(long *)(lVar13 + 0x50);
          lVar9 = local_98;
        }
        if (lVar10 != 0) {
          *(ulong *)(lVar13 + 0x58) = DAT_fffffff00ad55730;
        }
        uVar2 = *(undefined4 *)(lVar9 + 0x74);
        local_98 = lVar9;
        FUN_fffffff00a460c2c(lVar9);
        FUN_fffffff00a433324(param_1,1,0,uVar8,0,param_2,uVar2);
        FUN_fffffff00a55f390(uVar7);
        if (!bVar4) {
          FUN_fffffff00a55f590(param_1);
        }
        FUN_fffffff00a460cec(lVar9,0);
        goto LAB_fffffff00a55ee3c;
      }
      *(uint *)(local_98 + 0x74) = *(uint *)(local_98 + 0x74) | 8;
      lVar10 = *(long *)(local_98 + 0x130) + (long)_DAT_fffffff00acd26b4;
      *(long *)(local_98 + 0x130) = lVar10;
      iVar5 = 0;
      if (lVar10 != 0) {
        iVar5 = (*(int *)(local_98 + 0x138) + (int)lVar10) - *(int *)(local_98 + 0x140);
      }
      *(int *)(local_98 + 0xdc) = iVar5;
      *(undefined4 *)(lVar13 + 0x60) = 0;
      if (uVar6 != 0) {
        local_90 = 0;
        uStack_88 = 0;
        FUN_fffffff00a542400(lVar13 + 0x18,&local_90);
        DAT_fffffff00ad3dfbc = DAT_fffffff00ad3dfbc + -1;
        if (local_90 != param_6) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff00aa1cb7c
                    ("pkt.cp_mbuf == packet",
                     "/Library/Caches/com.apple.xbs/D9089588-4191-473E-9025-574E023945ED/TemporaryDirectory.nLq3V8/Sources/xnu/bsd/netinet/in_arp.c"
                     ,0x663);
        }
      }
      FUN_fffffff00a45e8cc(lVar9,0,5,0,1);
      bVar11 = false;
    }
    else {
      uVar1 = 0x41;
      if (uVar6 != 0) {
        uVar1 = uVar6;
      }
      uVar7 = (ulong)uVar1;
      if ((local_98 == 0) || (*(long *)(local_98 + 0xa0) != 0)) goto LAB_fffffff00a55e8a0;
LAB_fffffff00a55e85c:
      local_90 = 0;
      uStack_88 = 0;
      uVar8 = FUN_fffffff00a89d5dc(2,puVar14,&local_90,0x10);
      FUN_fffffff00a1d4e18(uVar8,"%s: can\'t allocate llinfo for %s\n");
LAB_fffffff00a55e8a0:
      bVar11 = true;
      if ((int)uVar7 != 0x41) {
        bVar4 = true;
        goto LAB_fffffff00a55e9a0;
      }
    }
    bVar4 = true;
    DAT_fffffff00ad3dfa4 = DAT_fffffff00ad3dfa4 + 1;
    uVar7 = 0x41;
  }
  else {
    if (((*(ushort *)(param_6 + 0x1e) >> 8 & 1) == 0) &&
       (iVar5 = FUN_fffffff00a55ddac(*(undefined4 *)(param_2 + 4),param_1), iVar5 == 0)) {
      if ((*(ushort *)(param_6 + 0x1e) >> 9 & 1) == 0) goto LAB_fffffff00a55e6b4;
LAB_fffffff00a55e6cc:
      lVar9 = local_98;
      if (local_98 != 0) {
        FUN_fffffff00a460c2c(local_98);
      }
      if ((param_3 != (undefined2 *)0x0) && (param_4 == 0)) goto LAB_fffffff00a55e948;
      uVar7 = FUN_fffffff00a432f30(param_1,param_2);
      if (lVar9 != 0) {
        FUN_fffffff00a460cec(lVar9,0);
      }
      goto LAB_fffffff00a55e8a0;
    }
LAB_fffffff00a55e5fc:
    puVar12 = (undefined2 *)((long)param_3 + param_4);
    if ((((ulong)param_3 ^ (ulong)puVar12) & 0xffc0000000000000) != 0) {
      puVar12 = (undefined2 *)((ulong)puVar12 & 0xffffffffffff | 0xc8a2000000000000);
    }
    if ((((param_3 != (undefined2 *)0x0) && (param_4 == 0)) ||
        ((undefined2 *)((long)param_3 + 0xff) < param_3)) ||
       ((0xff < param_4 || (FUN_fffffff00aa24ee0(param_3,param_4), puVar12 < param_3 + 10))))
    goto LAB_fffffff00a55e948;
    puVar12 = (undefined2 *)((long)param_3 + (ulong)*(byte *)((long)param_3 + 5) + 8);
    if (((undefined2 *)((long)param_3 + 0xff) < puVar12) ||
       ((puVar12 < param_3 || (0xf7 - (ulong)*(byte *)((long)param_3 + 5) < param_4 - 8))))
    goto LAB_fffffff00a55e948;
    if (puVar12 != (undefined2 *)0x0) {
      uVar6 = *(uint *)(param_1 + 0x610);
      if ((ulong)uVar6 <= param_4 - 8) {
        if (uVar6 == 0) {
          bVar11 = true;
          uVar7 = 6;
          bVar4 = true;
          goto LAB_fffffff00a55e9a0;
        }
        FUN_fffffff00aa24d30(puVar12,*(undefined8 *)(param_1 + 0x618),(ulong)uVar6);
        if (uVar6 < 0x100) {
          *(char *)(param_3 + 3) = (char)uVar6;
          *param_3 = 0x1214;
        }
        goto LAB_fffffff00a55e98c;
      }
      bVar11 = true;
      uVar7 = 0x28;
      bVar4 = true;
      goto LAB_fffffff00a55e9a0;
    }
    uVar7 = 0x16;
LAB_fffffff00a55e99c:
    bVar4 = true;
    bVar11 = true;
  }
LAB_fffffff00a55e9a0:
  lVar9 = local_98;
  if (local_98 != 0) {
    if ((((int)uVar7 == 0) && (*(int *)(param_1 + 0xa68) != 0)) &&
       (uVar8 = FUN_fffffff00a465b04(local_98,1), param_6 != 0)) {
      *(uint *)(param_6 + 0xcc) = *(uint *)(param_6 + 0xcc) | 0x8000000;
      *(undefined8 *)(param_6 + 0xd0) = uVar8;
    }
    if (!bVar4) {
      FUN_fffffff00a55f668(lVar9);
    }
    if (lVar9 == param_5) {
      FUN_fffffff00a46123c(lVar9);
      FUN_fffffff00a460c2c(lVar9);
    }
    else {
      FUN_fffffff00a460c2c();
      FUN_fffffff00a45b594(lVar9,0);
    }
  }
  if (!bVar11) {
    lVar9 = tpidr_el1;
    uVar17 = (ulong)*(uint *)(lVar9 + 0x4e8);
    if (DAT_fffffff00ad553a0 != 0) {
      FUN_fffffff00a1ea02c(&DAT_fffffff00ad55398,lVar9,0);
      uVar17 = DAT_fffffff00ad553a0;
    }
    DAT_fffffff00ad553a0 = uVar17;
    FUN_fffffff00a55f7b8(0);
    if ((int)DAT_fffffff00ad553a0 == *(int *)(lVar9 + 0x4e8)) {
      DAT_fffffff00ad553a0 = CONCAT44(DAT_fffffff00ad553a0._4_4_,in_wzr);
    }
    else {
      FUN_fffffff00a1eab60(&DAT_fffffff00ad55398,lVar9);
    }
  }
LAB_fffffff00a55e5a4:
  if (DAT_fffffff00acf0000 == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_fffffff00aa0b974(uVar7);
}

