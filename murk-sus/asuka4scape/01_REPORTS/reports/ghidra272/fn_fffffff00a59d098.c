// FUN_fffffff00a59d098 @ fffffff00a59d098 size=2864

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fffffff00a59d098
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
  ulong uVar10;
  long lVar11;
  bool bVar12;
  undefined2 *puVar13;
  long lVar14;
  uint *puVar15;
  ulong uVar16;
  int in_wzr;
  long local_98;
  long local_90;
  undefined8 uStack_88;
  long local_80;
  long lStack_78;
  undefined4 local_70;
  long local_68;
  
  local_68 = DAT_fffffff00ad30000;
  local_98 = 0;
  local_80 = 0;
  lStack_78 = 0;
  local_70 = 0;
  uVar7 = 0x16;
  if ((param_1 == 0) || (param_2 == 0)) goto LAB_fffffff00a59d194;
  if (*(char *)(param_2 + 1) != '\x02') {
    uVar7 = 0x2f;
    goto LAB_fffffff00a59d194;
  }
  if (((*(ushort *)(param_1 + 0xd2) ^ 0xffff) & 0x41) != 0) {
    uVar7 = 0x32;
    goto LAB_fffffff00a59d194;
  }
  if ((param_5 != 0) && (uVar7 = FUN_fffffff00a4a14f0(param_2,param_5,&local_98), (int)uVar7 != 0))
  goto LAB_fffffff00a59d194;
  if (param_6 == 0) {
    iVar5 = FUN_fffffff00a59c99c(*(undefined4 *)(param_2 + 4),param_1);
    if (iVar5 != 0) goto LAB_fffffff00a59d1ec;
LAB_fffffff00a59d2a4:
    lVar9 = local_98;
    puVar15 = (uint *)(param_2 + 4);
    if ((*(short *)(param_1 + 0xd2) < 0) && ((*puVar15 & 0xf0) == 0xe0)) goto LAB_fffffff00a59d2bc;
    if (local_98 == 0) {
LAB_fffffff00a59d3b4:
      uVar6 = FUN_fffffff00a59dbc8(puVar15,1,0,&local_98,*(undefined2 *)(param_1 + 0xcc));
    }
    else {
      if (*(long *)(local_98 + 0xa0) == 0) {
        if (local_98 == param_5) {
          FUN_fffffff00a49e4c4(local_98);
          FUN_fffffff00a49deb4(lVar9);
        }
        else {
          FUN_fffffff00a49deb4();
          FUN_fffffff00a498684(lVar9,0);
        }
        goto LAB_fffffff00a59d3b4;
      }
      uVar6 = 0;
    }
    lVar9 = local_98;
    uVar16 = DAT_fffffff00ad95818;
    if ((uVar6 == 0) && (local_98 != 0)) {
      lVar14 = *(long *)(local_98 + 0xa0);
      if (lVar14 == 0) {
        uVar7 = 0x41;
        goto LAB_fffffff00a59d458;
      }
      if ((*(ushort *)(param_1 + 0xd2) >> 7 & 1) != 0) {
        bVar12 = true;
        uVar7 = 0x2d;
        bVar4 = true;
        goto LAB_fffffff00a59d580;
      }
      uVar7 = *(ulong *)(local_98 + 0x80);
      if (*(long *)(local_98 + 0x130) == 0) {
        if (*(int *)(local_98 + 0xdc) != 0) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff00aa5d948
                    ("route->rt_expire != 0 || route->rt_rmx.rmx_expire == 0",
                     "/Library/Caches/com.apple.xbs/FBE73862-C372-4A76-BC3C-8E79BBE064EA/TemporaryDirectory.14N5mt/Sources/xnu/bsd/netinet/in_arp.c"
                     ,0x5bb);
        }
      }
      else if (*(int *)(local_98 + 0xdc) == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa5d948
                  ("route->rt_expire == 0 || route->rt_rmx.rmx_expire != 0",
                   "/Library/Caches/com.apple.xbs/FBE73862-C372-4A76-BC3C-8E79BBE064EA/TemporaryDirectory.14N5mt/Sources/xnu/bsd/netinet/in_arp.c"
                   ,0x5ba);
      }
      if ((((DAT_fffffff00ad95818 <= *(long *)(local_98 + 0x130) - 1U) && (uVar7 != 0)) &&
          (*(char *)(uVar7 + 1) == '\x12')) && (*(char *)(uVar7 + 6) != '\0')) {
        iVar5 = FUN_fffffff00a59de04(lVar14);
        if ((uVar7 + 0x14 <= uVar7) || ((param_3 != (undefined2 *)0x0 && (param_4 == 0))))
        goto LAB_fffffff00a59d6b8;
        uVar7 = FUN_fffffff00a498250(uVar7,param_3,param_4);
        if ((int)uVar7 != 0) goto LAB_fffffff00a59d57c;
        uVar7 = *(ulong *)(lVar14 + 0x50);
        if (uVar7 != 0) {
          *(ulong *)(lVar14 + 0x58) = DAT_fffffff00ad95818;
          uVar10 = *(ulong *)(lVar9 + 0x90);
          if ((iVar5 == 0) || ((*(byte *)(lVar14 + 0x74) >> 1 & 1) != 0)) {
            FUN_fffffff00a227018(lVar9 + 0x60);
            FUN_fffffff00a226c24(uVar7);
            uVar6 = *(uint *)(uVar7 + 0x3c);
            if (uVar6 < _DAT_fffffff00ad126bc) {
              bVar4 = uVar6 != 0;
              if (uVar6 == 0) {
                *(ulong *)(lVar14 + 0x68) = uVar16 + _DAT_fffffff00ad126ac;
                *(uint *)(lVar14 + 0x74) = *(uint *)(lVar14 + 0x74) | 2;
                uVar6 = *(uint *)(uVar7 + 0x3c);
              }
              *(uint *)(uVar7 + 0x3c) = uVar6 + 1;
              if (&stack0x0000007f < &local_80) goto LAB_fffffff00a59d6b8;
              lStack_78 = 0;
              local_70 = 0;
              local_80 = (ulong)*(byte *)(param_1 + 0xfb) << 0x30;
              if (((&stack0x0000007f < &lStack_78) || (6 < *(byte *)(param_1 + 0xfb))) ||
                 (FUN_fffffff00aa65b10(&lStack_78,uVar7 + 0x62), uVar7 + 0x78 <= uVar7))
              goto LAB_fffffff00a59d6b8;
              lVar9 = tpidr_el1;
              if (*(int *)(uVar7 + 8) == *(int *)(lVar9 + 0x4e8)) {
                *(int *)(uVar7 + 8) = in_wzr;
              }
              else {
                FUN_fffffff00a226e08(uVar7,lVar9);
              }
              FUN_fffffff00a226c24(uVar10);
              iVar5 = *(int *)(uVar10 + 0x10);
              *(int *)(uVar10 + 0x10) = iVar5 + 1;
              if (iVar5 + 0xf0000001U < 0xf0000002) goto LAB_fffffff00a59db60;
              if (uVar10 + 0x70 <= uVar10) goto LAB_fffffff00a59d6b8;
              uVar8 = *(undefined8 *)(uVar10 + 0x18);
              if (*(int *)(uVar10 + 8) == *(int *)(lVar9 + 0x4e8)) {
                *(int *)(uVar10 + 8) = in_wzr;
              }
              else {
                FUN_fffffff00a226e08(uVar10,lVar9);
              }
              lVar9 = local_98;
              uVar2 = *(undefined4 *)(local_98 + 0x74);
              FUN_fffffff00a49deb4(local_98);
              FUN_fffffff00a4704bc(param_1,1,0,uVar8,&local_80,param_2,uVar2);
              FUN_fffffff00a59df88(uVar10);
              FUN_fffffff00a49df74(lVar9,0);
              uVar7 = 0;
              bVar12 = false;
            }
            else {
              if (uVar7 + 0x78 <= uVar7) goto LAB_fffffff00a59d6b8;
              lVar9 = tpidr_el1;
              if (*(int *)(uVar7 + 8) == *(int *)(lVar9 + 0x4e8)) {
                *(int *)(uVar7 + 8) = in_wzr;
              }
              else {
                FUN_fffffff00a226e08(uVar7);
              }
              if ((iVar5 == 0) || ((*(byte *)(lVar14 + 0x74) >> 1 & 1) != 0))
              goto LAB_fffffff00a59d70c;
              uVar7 = 0;
              bVar12 = true;
              bVar4 = true;
            }
            goto LAB_fffffff00a59d580;
          }
        }
LAB_fffffff00a59d568:
        uVar7 = 0;
        goto LAB_fffffff00a59d57c;
      }
LAB_fffffff00a59d70c:
      if (param_6 == 0) {
        uVar6 = 0;
        iVar5 = *(int *)(lVar14 + 0x70) + 1;
        *(int *)(lVar14 + 0x70) = iVar5;
      }
      else {
        uVar6 = FUN_fffffff00a59dfc4(lVar14,param_6);
        iVar5 = *(int *)(lVar14 + 0x70);
      }
      lVar9 = local_98;
      if (iVar5 + *(int *)(lVar14 + 0x30) == 1) {
        *(ulong *)(lVar14 + 0x68) = uVar16 + _DAT_fffffff00ad126ac;
        *(uint *)(lVar14 + 0x74) = *(uint *)(lVar14 + 0x74) | 2;
      }
      if ((*(ulong *)(local_98 + 0x130) == 0) ||
         ((*(uint *)(local_98 + 0x74) = *(uint *)(local_98 + 0x74) & 0xfffffff7,
          *(ulong *)(local_98 + 0x130) == uVar16 && (*(int *)(lVar14 + 0x60) != 0)))) {
LAB_fffffff00a59d928:
        if (param_6 == 0) {
          uVar6 = 1;
        }
        lVar9 = param_6;
        if ((uVar6 & 1) == 0) {
          do {
            lVar9 = FUN_fffffff00a78f188(lVar9);
            param_6 = 0;
            bVar12 = false;
            bVar4 = true;
            uVar7 = 0xfffffffe;
          } while (lVar9 != 0);
        }
        else {
          bVar12 = false;
          bVar4 = true;
          uVar7 = 0xfffffffe;
        }
        goto LAB_fffffff00a59d580;
      }
      *(ulong *)(local_98 + 0x130) = uVar16;
      if (uVar16 == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = (*(int *)(local_98 + 0x138) + (int)uVar16) - *(int *)(local_98 + 0x140);
      }
      *(int *)(local_98 + 0xdc) = iVar5;
      uVar1 = *(uint *)(lVar14 + 0x60);
      *(uint *)(lVar14 + 0x60) = uVar1 + 1;
      if (uVar1 < *(uint *)(lVar14 + 100)) {
        uVar7 = *(ulong *)(local_98 + 0x90);
        uVar16 = *(ulong *)(lVar14 + 0x50);
        FUN_fffffff00a227018(local_98 + 0x60);
        if (uVar16 != 0) {
          FUN_fffffff00a226c24(uVar16);
          *(int *)(uVar16 + 0x3c) = *(int *)(uVar16 + 0x3c) + 1;
          if (uVar16 + 0x78 <= uVar16) goto LAB_fffffff00a59d6b8;
          lVar9 = tpidr_el1;
          if (*(int *)(uVar16 + 8) == *(int *)(lVar9 + 0x4e8)) {
            *(int *)(uVar16 + 8) = in_wzr;
          }
          else {
            FUN_fffffff00a226e08(uVar16);
          }
        }
        bVar4 = true;
        if (((*(char *)(param_1 + 0xfb) == '\x06') && ((*(byte *)(local_98 + 0x77) >> 4 & 1) != 0))
           && (1 < *(uint *)(lVar14 + 0x60))) {
          bVar4 = false;
          *(uint *)(lVar14 + 0x74) = *(uint *)(lVar14 + 0x74) | 1;
        }
        FUN_fffffff00a226c24(uVar7);
        iVar5 = *(int *)(uVar7 + 0x10);
        *(int *)(uVar7 + 0x10) = iVar5 + 1;
        if (iVar5 + 0xf0000001U < 0xf0000002) {
LAB_fffffff00a59db60:
                    /* WARNING: Subroutine does not return */
          FUN_fffffff00aa61ed0();
        }
        if (uVar7 + 0x70 <= uVar7) {
LAB_fffffff00a59d6b8:
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x5519,0xfffffff00a59d6bc);
          (*pcVar3)();
        }
        uVar8 = *(undefined8 *)(uVar7 + 0x18);
        lVar9 = tpidr_el1;
        if (*(int *)(uVar7 + 8) == *(int *)(lVar9 + 0x4e8)) {
          *(int *)(uVar7 + 8) = in_wzr;
          lVar11 = *(long *)(lVar14 + 0x50);
          lVar9 = local_98;
        }
        else {
          FUN_fffffff00a226e08(uVar7);
          lVar11 = *(long *)(lVar14 + 0x50);
          lVar9 = local_98;
        }
        if (lVar11 != 0) {
          *(ulong *)(lVar14 + 0x58) = DAT_fffffff00ad95818;
        }
        uVar2 = *(undefined4 *)(lVar9 + 0x74);
        local_98 = lVar9;
        FUN_fffffff00a49deb4(lVar9);
        FUN_fffffff00a4704bc(param_1,1,0,uVar8,0,param_2,uVar2);
        FUN_fffffff00a59df88(uVar7);
        if (!bVar4) {
          FUN_fffffff00a59e188(param_1);
        }
        FUN_fffffff00a49df74(lVar9,0);
        goto LAB_fffffff00a59d928;
      }
      *(uint *)(local_98 + 0x74) = *(uint *)(local_98 + 0x74) | 8;
      lVar11 = *(long *)(local_98 + 0x130) + (long)_DAT_fffffff00ad126b4;
      *(long *)(local_98 + 0x130) = lVar11;
      iVar5 = 0;
      if (lVar11 != 0) {
        iVar5 = (*(int *)(local_98 + 0x138) + (int)lVar11) - *(int *)(local_98 + 0x140);
      }
      *(int *)(local_98 + 0xdc) = iVar5;
      *(undefined4 *)(lVar14 + 0x60) = 0;
      if (uVar6 != 0) {
        local_90 = 0;
        uStack_88 = 0;
        FUN_fffffff00a58075c(lVar14 + 0x18,&local_90);
        DAT_fffffff00ad7e07c = DAT_fffffff00ad7e07c + -1;
        if (local_90 != param_6) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff00aa5d948
                    ("pkt.cp_mbuf == packet",
                     "/Library/Caches/com.apple.xbs/FBE73862-C372-4A76-BC3C-8E79BBE064EA/TemporaryDirectory.14N5mt/Sources/xnu/bsd/netinet/in_arp.c"
                     ,0x665);
        }
      }
      FUN_fffffff00a49b9bc(lVar9,0,5,0,1);
      bVar12 = false;
    }
    else {
      uVar1 = 0x41;
      if (uVar6 != 0) {
        uVar1 = uVar6;
      }
      uVar7 = (ulong)uVar1;
      if ((local_98 == 0) || (*(long *)(local_98 + 0xa0) != 0)) goto LAB_fffffff00a59d49c;
LAB_fffffff00a59d458:
      local_90 = 0;
      uStack_88 = 0;
      uVar8 = FUN_fffffff00a8dd3c8(2,puVar15,&local_90,0x10);
      FUN_fffffff00a210fe8(uVar8,"%s: can\'t allocate llinfo for %s\n");
LAB_fffffff00a59d49c:
      bVar12 = true;
      if ((int)uVar7 != 0x41) {
        bVar4 = true;
        goto LAB_fffffff00a59d580;
      }
    }
    bVar4 = true;
    DAT_fffffff00ad7e064 = DAT_fffffff00ad7e064 + 1;
    uVar7 = 0x41;
  }
  else {
    if (((*(ushort *)(param_6 + 0x1e) >> 8 & 1) == 0) &&
       (iVar5 = FUN_fffffff00a59c99c(*(undefined4 *)(param_2 + 4),param_1), iVar5 == 0)) {
      if ((*(ushort *)(param_6 + 0x1e) >> 9 & 1) == 0) goto LAB_fffffff00a59d2a4;
LAB_fffffff00a59d2bc:
      lVar9 = local_98;
      if (local_98 != 0) {
        FUN_fffffff00a49deb4(local_98);
      }
      if ((param_3 != (undefined2 *)0x0) && (param_4 == 0)) goto LAB_fffffff00a59d6b8;
      uVar7 = FUN_fffffff00a4700c8(param_1,param_2);
      if (lVar9 != 0) {
        FUN_fffffff00a49df74(lVar9,0);
      }
      goto LAB_fffffff00a59d49c;
    }
LAB_fffffff00a59d1ec:
    puVar13 = (undefined2 *)((long)param_3 + param_4);
    if ((((ulong)param_3 ^ (ulong)puVar13) & 0xffc0000000000000) != 0) {
      puVar13 = (undefined2 *)((ulong)puVar13 & 0xffffffffffff | 0xc8a2000000000000);
    }
    if ((((param_3 != (undefined2 *)0x0) && (param_4 == 0)) ||
        ((undefined2 *)((long)param_3 + 0xff) < param_3)) ||
       ((0xff < param_4 || (FUN_fffffff00aa65cc0(param_3,param_4), puVar13 < param_3 + 10))))
    goto LAB_fffffff00a59d6b8;
    puVar13 = (undefined2 *)((long)param_3 + (ulong)*(byte *)((long)param_3 + 5) + 8);
    if (((undefined2 *)((long)param_3 + 0xff) < puVar13) ||
       ((puVar13 < param_3 || (0xf7 - (ulong)*(byte *)((long)param_3 + 5) < param_4 - 8))))
    goto LAB_fffffff00a59d6b8;
    if (puVar13 != (undefined2 *)0x0) {
      uVar6 = *(uint *)(param_1 + 0x610);
      if ((ulong)uVar6 <= param_4 - 8) {
        if (uVar6 == 0) {
          bVar12 = true;
          uVar7 = 6;
          bVar4 = true;
          goto LAB_fffffff00a59d580;
        }
        FUN_fffffff00aa65b10(puVar13,*(undefined8 *)(param_1 + 0x618),(ulong)uVar6);
        if (uVar6 < 0x100) {
          uVar7 = 0;
          *(char *)(param_3 + 3) = (char)uVar6;
          *param_3 = 0x1214;
          goto LAB_fffffff00a59d57c;
        }
        goto LAB_fffffff00a59d568;
      }
      bVar12 = true;
      uVar7 = 0x28;
      bVar4 = true;
      goto LAB_fffffff00a59d580;
    }
    uVar7 = 0x16;
LAB_fffffff00a59d57c:
    bVar4 = true;
    bVar12 = true;
  }
LAB_fffffff00a59d580:
  lVar9 = local_98;
  if (local_98 != 0) {
    if ((((int)uVar7 == 0) && (*(int *)(param_1 + 0xa68) != 0)) &&
       (uVar8 = FUN_fffffff00a4a2d8c(local_98,1), param_6 != 0)) {
      *(uint *)(param_6 + 0xcc) = *(uint *)(param_6 + 0xcc) | 0x8000000;
      *(undefined8 *)(param_6 + 0xd0) = uVar8;
    }
    if (!bVar4) {
      FUN_fffffff00a59e260(lVar9);
    }
    if (lVar9 == param_5) {
      FUN_fffffff00a49e4c4(lVar9);
      FUN_fffffff00a49deb4(lVar9);
    }
    else {
      FUN_fffffff00a49deb4();
      FUN_fffffff00a498684(lVar9,0);
    }
  }
  if (!bVar12) {
    lVar9 = tpidr_el1;
    uVar16 = (ulong)*(uint *)(lVar9 + 0x4e8);
    if (DAT_fffffff00ad95480 != 0) {
      FUN_fffffff00a2262d4(&DAT_fffffff00ad95478,lVar9,0);
      uVar16 = DAT_fffffff00ad95480;
    }
    DAT_fffffff00ad95480 = uVar16;
    FUN_fffffff00a59e3b0(0);
    if ((int)DAT_fffffff00ad95480 == *(int *)(lVar9 + 0x4e8)) {
      DAT_fffffff00ad95480 = CONCAT44(DAT_fffffff00ad95480._4_4_,in_wzr);
    }
    else {
      FUN_fffffff00a226e08(&DAT_fffffff00ad95478,lVar9);
    }
  }
LAB_fffffff00a59d194:
  if (DAT_fffffff00ad30000 == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_fffffff00aa4c590(uVar7);
}

