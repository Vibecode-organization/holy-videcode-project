// FUN_fffffff00a846cac @ fffffff00a846cac size=7268

undefined8 FUN_fffffff00a846cac(long param_1,long param_2,int param_3,ulong param_4)

{
  byte *pbVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  byte bVar7;
  char cVar8;
  ushort uVar9;
  uint uVar10;
  uint uVar11;
  code *pcVar12;
  long lVar13;
  uint uVar14;
  undefined8 uVar15;
  long lVar16;
  byte *pbVar17;
  undefined8 *puVar18;
  undefined8 *puVar19;
  long *plVar20;
  undefined8 *puVar21;
  ulong uVar22;
  uint uVar23;
  ulong uVar24;
  ulong uVar25;
  uint *puVar26;
  byte *pbVar27;
  uint uVar28;
  undefined8 uVar29;
  undefined8 uVar30;
  
  puVar26 = (uint *)(param_1 + 0x10);
  if (*(short *)(param_1 + 0xd8) == 0) {
    uVar25 = 0;
    plVar20 = (long *)0x0;
  }
  else {
    plVar20 = (long *)(param_1 + 0x40);
    if (*(long *)(param_1 + 0x48) == 0) {
      plVar20 = (long *)*plVar20;
      uVar25 = (long)plVar20 + 0x32;
    }
    else {
      uVar25 = param_1 + 0x72;
    }
  }
  if (uVar25 < (long)plVar20 + 0x32U) goto LAB_fffffff00a846d14;
  pbVar27 = (byte *)plVar20[1];
  uVar25 = (ulong)*(uint *)((long)plVar20 + 0x1c);
  pbVar17 = pbVar27 + uVar25;
  if (pbVar17 < pbVar27 != (pbVar17 >= pbVar27 && SBORROW8(uVar25,uVar25)))
  goto LAB_fffffff00a846d14;
  bVar7 = *(byte *)(param_1 + 0x7b);
  lVar13 = plVar20[4];
  uVar10 = (*(uint *)((long)plVar20 + 0x1c) - (int)lVar13) - (uint)bVar7;
  uVar11 = *puVar26 - (uint)bVar7;
  if (uVar11 <= uVar10) {
    uVar10 = uVar11;
  }
  uVar10 = uVar10 & 0xffff;
  uVar24 = (ulong)uVar10;
  if (uVar11 < uVar10) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff00aa5d948
              ("pkt_len >= cls_len",
               "/Library/Caches/com.apple.xbs/FBE73862-C372-4A76-BC3C-8E79BBE064EA/TemporaryDirectory.14N5mt/Sources/xnu/bsd/skywalk/nexus/flowswitch/flow/flow_classifier.c"
               ,0xda);
  }
  pbVar3 = pbVar27 + (ulong)bVar7 + (ulong)*(byte *)(param_1 + 0x7a);
  if ((pbVar17 < pbVar3 || pbVar3 < pbVar27) ||
     ((long)((uVar25 - *(byte *)(param_1 + 0x7a)) - (ulong)bVar7) < (long)uVar24))
  goto LAB_fffffff00a846d14;
  pbVar4 = pbVar3 + uVar24;
  if (param_3 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff00aa5d948
              ("af != AF_UNSPEC",
               "/Library/Caches/com.apple.xbs/FBE73862-C372-4A76-BC3C-8E79BBE064EA/TemporaryDirectory.14N5mt/Sources/xnu/bsd/skywalk/nexus/flowswitch/flow/flow_classifier.c"
               ,0xe2);
  }
  uVar5 = *(uint *)(param_2 + 0x100);
  uVar6 = *(uint *)((long)plVar20 + 0x24);
  *(undefined1 *)(*(long *)(param_1 + 0xb8) + 0x20) = 0;
  uVar15 = DAT_fffffff00ad984e0;
  if (param_3 != 0x1e) {
    if (param_3 == 2) {
      if (uVar10 < 0x14) {
        uVar29 = tpidr_el1;
        lVar13 = FUN_fffffff00a29b24c();
        if ((*(long *)(lVar13 + 0x18) != 0) || (DAT_fffffff007c6b250 != 0)) {
          FUN_fffffff00a724f30();
        }
        FUN_fffffff00a8df19c
                  (&MACH_HEADER,uVar15,0x10,
                   "SK[%u]: %-30s %s(%d): %d: skip cls_len < sizeof(struct ip)\n");
        uVar15 = DAT_fffffff00ad984e0;
        pbVar3 = pbVar27 + *(byte *)(param_1 + 0x7a);
        if ((*(ulong *)(param_1 + 0x90) >> 0x27 & 1) != 0) {
          if (*(short *)(param_1 + 0xd8) == 0) {
            plVar20 = (long *)0x0;
          }
          else {
            plVar20 = (long *)(param_1 + 0x40);
            if (*(long *)(param_1 + 0x48) == 0) {
              plVar20 = (long *)*plVar20;
            }
          }
          puVar26 = (uint *)((long)plVar20 + 0x24);
        }
        if (0x7f < uVar6) {
          uVar6 = 0x80;
        }
        if ((((pbVar17 < pbVar3) || (pbVar3 < pbVar27)) || (uVar10 = *puVar26, (int)uVar10 < 0)) ||
           ((long)(uVar25 - *(byte *)(param_1 + 0x7a)) < (long)(int)uVar10))
        goto LAB_fffffff00a846d14;
        FUN_fffffff00a7f1864("buf",pbVar3,(long)(int)uVar10,uVar6);
        FUN_fffffff00a8df19c(&MACH_HEADER,uVar15,0x10,"SK[%u]: %-30s %s %s\n");
      }
      else {
        if (pbVar4 < pbVar3 + 0x14) goto LAB_fffffff00a846d14;
        uVar14 = (*pbVar3 & 0xf) << 2;
        if (uVar14 < 0x14) {
          uVar29 = tpidr_el1;
          lVar13 = FUN_fffffff00a29b24c();
          if ((*(long *)(lVar13 + 0x18) != 0) || (DAT_fffffff007c6b250 != 0)) {
            FUN_fffffff00a724f30();
          }
          FUN_fffffff00a8df19c
                    (&MACH_HEADER,uVar15,0x10,
                     "SK[%u]: %-30s %s(%d): %d: skip l3hlen < sizeof(struct ip)\n");
          uVar15 = DAT_fffffff00ad984e0;
          pbVar3 = pbVar27 + *(byte *)(param_1 + 0x7a);
          if ((*(ulong *)(param_1 + 0x90) >> 0x27 & 1) != 0) {
            if (*(short *)(param_1 + 0xd8) == 0) {
              plVar20 = (long *)0x0;
            }
            else {
              plVar20 = (long *)(param_1 + 0x40);
              if (*(long *)(param_1 + 0x48) == 0) {
                plVar20 = (long *)*plVar20;
              }
            }
            puVar26 = (uint *)((long)plVar20 + 0x24);
          }
          if (0x7f < uVar6) {
            uVar6 = 0x80;
          }
          if (((pbVar17 < pbVar3) || (pbVar3 < pbVar27)) ||
             ((uVar10 = *puVar26, (int)uVar10 < 0 ||
              ((long)(uVar25 - *(byte *)(param_1 + 0x7a)) < (long)(int)uVar10))))
          goto LAB_fffffff00a846d14;
          FUN_fffffff00a7f1864("buf",pbVar3,(long)(int)uVar10,uVar6);
          FUN_fffffff00a8df19c(&MACH_HEADER,uVar15,0x10,"SK[%u]: %-30s %s %s\n");
        }
        else if (uVar10 < uVar14) {
          uVar29 = tpidr_el1;
          lVar13 = FUN_fffffff00a29b24c();
          if ((*(long *)(lVar13 + 0x18) != 0) || (DAT_fffffff007c6b250 != 0)) {
            FUN_fffffff00a724f30();
          }
          FUN_fffffff00a8df19c
                    (&MACH_HEADER,uVar15,0x10,"SK[%u]: %-30s %s(%d): %d: skip cls_len < l3hlen\n");
          uVar15 = DAT_fffffff00ad984e0;
          pbVar3 = pbVar27 + *(byte *)(param_1 + 0x7a);
          if ((*(ulong *)(param_1 + 0x90) >> 0x27 & 1) != 0) {
            if (*(short *)(param_1 + 0xd8) == 0) {
              plVar20 = (long *)0x0;
            }
            else {
              plVar20 = (long *)(param_1 + 0x40);
              if (*(long *)(param_1 + 0x48) == 0) {
                plVar20 = (long *)*plVar20;
              }
            }
            puVar26 = (uint *)((long)plVar20 + 0x24);
          }
          if (0x7f < uVar6) {
            uVar6 = 0x80;
          }
          if ((((pbVar17 < pbVar3) || (pbVar3 < pbVar27)) || (uVar10 = *puVar26, (int)uVar10 < 0))
             || ((long)(uVar25 - *(byte *)(param_1 + 0x7a)) < (long)(int)uVar10))
          goto LAB_fffffff00a846d14;
          FUN_fffffff00a7f1864("buf",pbVar3,(long)(int)uVar10,uVar6);
          FUN_fffffff00a8df19c(&MACH_HEADER,uVar15,0x10,"SK[%u]: %-30s %s %s\n");
        }
        else if (((param_4 & 1) == 0) && ((*pbVar3 & 0xf) != 5)) {
          uVar29 = tpidr_el1;
          lVar13 = FUN_fffffff00a29b24c();
          if ((*(long *)(lVar13 + 0x18) != 0) || (DAT_fffffff007c6b250 != 0)) {
            FUN_fffffff00a724f30();
          }
          FUN_fffffff00a8df19c
                    (&MACH_HEADER,uVar15,0x10,
                     "SK[%u]: %-30s %s(%d): %d: skip !input && l3hlen != sizeof(struct ip)\n");
          uVar15 = DAT_fffffff00ad984e0;
          pbVar3 = pbVar27 + *(byte *)(param_1 + 0x7a);
          if ((*(ulong *)(param_1 + 0x90) >> 0x27 & 1) != 0) {
            if (*(short *)(param_1 + 0xd8) == 0) {
              plVar20 = (long *)0x0;
            }
            else {
              plVar20 = (long *)(param_1 + 0x40);
              if (*(long *)(param_1 + 0x48) == 0) {
                plVar20 = (long *)*plVar20;
              }
            }
            puVar26 = (uint *)((long)plVar20 + 0x24);
          }
          if (0x7f < uVar6) {
            uVar6 = 0x80;
          }
          if (((pbVar17 < pbVar3) || (pbVar3 < pbVar27)) ||
             ((uVar10 = *puVar26, (int)uVar10 < 0 ||
              ((long)(uVar25 - *(byte *)(param_1 + 0x7a)) < (long)(int)uVar10))))
          goto LAB_fffffff00a846d14;
          FUN_fffffff00a7f1864("buf",pbVar3,(long)(int)uVar10,uVar6);
          FUN_fffffff00a8df19c(&MACH_HEADER,uVar15,0x10,"SK[%u]: %-30s %s %s\n");
        }
        else {
          uVar28 = (uint)(*(ushort *)(pbVar3 + 2) >> 8) | (*(ushort *)(pbVar3 + 2) & 0xff00ff) << 8;
          if (uVar28 < uVar14) {
            uVar29 = tpidr_el1;
            lVar13 = FUN_fffffff00a29b24c();
            if ((*(long *)(lVar13 + 0x18) != 0) || (DAT_fffffff007c6b250 != 0)) {
              FUN_fffffff00a724f30();
            }
            FUN_fffffff00a8df19c
                      (&MACH_HEADER,uVar15,0x10,"SK[%u]: %-30s %s(%d): %d: skip l3tlen < l3hlen\n");
            uVar15 = DAT_fffffff00ad984e0;
            pbVar3 = pbVar27 + *(byte *)(param_1 + 0x7a);
            if ((*(ulong *)(param_1 + 0x90) >> 0x27 & 1) != 0) {
              if (*(short *)(param_1 + 0xd8) == 0) {
                plVar20 = (long *)0x0;
              }
              else {
                plVar20 = (long *)(param_1 + 0x40);
                if (*(long *)(param_1 + 0x48) == 0) {
                  plVar20 = (long *)*plVar20;
                }
              }
              puVar26 = (uint *)((long)plVar20 + 0x24);
            }
            if (0x7f < uVar6) {
              uVar6 = 0x80;
            }
            if ((((pbVar17 < pbVar3) || (pbVar3 < pbVar27)) || (uVar10 = *puVar26, (int)uVar10 < 0))
               || ((long)(uVar25 - *(byte *)(param_1 + 0x7a)) < (long)(int)uVar10))
            goto LAB_fffffff00a846d14;
            FUN_fffffff00a7f1864("buf",pbVar3,(long)(int)uVar10,uVar6);
            FUN_fffffff00a8df19c(&MACH_HEADER,uVar15,0x10,"SK[%u]: %-30s %s %s\n");
          }
          else if (uVar11 < uVar28) {
            uVar29 = tpidr_el1;
            lVar13 = FUN_fffffff00a29b24c();
            if ((*(long *)(lVar13 + 0x18) != 0) || (DAT_fffffff007c6b250 != 0)) {
              FUN_fffffff00a724f30();
            }
            FUN_fffffff00a8df19c
                      (&MACH_HEADER,uVar15,0x10,"SK[%u]: %-30s %s(%d): %d: skip pkt_len < l3tlen\n")
            ;
            uVar15 = DAT_fffffff00ad984e0;
            pbVar3 = pbVar27 + *(byte *)(param_1 + 0x7a);
            if ((*(ulong *)(param_1 + 0x90) >> 0x27 & 1) != 0) {
              if (*(short *)(param_1 + 0xd8) == 0) {
                plVar20 = (long *)0x0;
              }
              else {
                plVar20 = (long *)(param_1 + 0x40);
                if (*(long *)(param_1 + 0x48) == 0) {
                  plVar20 = (long *)*plVar20;
                }
              }
              puVar26 = (uint *)((long)plVar20 + 0x24);
            }
            if (0x7f < uVar6) {
              uVar6 = 0x80;
            }
            if (((pbVar17 < pbVar3) || (pbVar3 < pbVar27)) ||
               ((uVar10 = *puVar26, (int)uVar10 < 0 ||
                ((long)(uVar25 - *(byte *)(param_1 + 0x7a)) < (long)(int)uVar10))))
            goto LAB_fffffff00a846d14;
            FUN_fffffff00a7f1864("buf",pbVar3,(long)(int)uVar10,uVar6);
            FUN_fffffff00a8df19c(&MACH_HEADER,uVar15,0x10,"SK[%u]: %-30s %s %s\n");
          }
          else {
            if ((*pbVar3 & 0xf0) == 0x40) {
              pbVar4 = pbVar3 + 0xc;
              if (((ulong)pbVar4 & 7) == 0) {
                puVar21 = *(undefined8 **)(param_1 + 0xb8);
LAB_fffffff00a846e04:
                *puVar21 = *(undefined8 *)pbVar4;
              }
              else {
                puVar21 = *(undefined8 **)(param_1 + 0xb8);
                puVar18 = puVar21 + 1;
                if (((ulong)pbVar4 & 3) != 0) {
                  if (puVar18 <= puVar21) goto LAB_fffffff00a846d14;
                  goto LAB_fffffff00a846e04;
                }
                if (puVar18 < puVar21) goto LAB_fffffff00a846d14;
                puVar19 = (undefined8 *)((long)puVar21 + 4);
                *(undefined4 *)puVar21 = *(undefined4 *)pbVar4;
                if ((puVar18 <= puVar19) || (puVar19 < puVar21)) goto LAB_fffffff00a846d14;
                *(undefined4 *)puVar19 = *(undefined4 *)(pbVar3 + 0x10);
              }
              *(undefined1 *)(*(long *)(param_1 + 0xb8) + 0x20) = 4;
              *(byte *)(*(long *)(param_1 + 0xb8) + 0x21) = pbVar3[9];
              *(byte **)(*(long *)(param_1 + 0xb8) + 0x28) = pbVar3;
              if ((*(ushort *)(pbVar3 + 6) & 0xff3f) != 0) {
                *(byte *)(*(long *)(param_1 + 0xb8) + 0x23) =
                     *(byte *)(*(long *)(param_1 + 0xb8) + 0x23) | 1;
                *(uint *)(*(long *)(param_1 + 0xb8) + 0x24) = (uint)*(ushort *)(pbVar3 + 4);
                lVar16 = *(long *)(param_1 + 0xb8);
                if ((*(ushort *)(pbVar3 + 6) & 0xff1f) != 0) {
                  *(byte *)(lVar16 + 0x23) = *(byte *)(lVar16 + 0x23) & 0xfd;
                  *(char *)(*(long *)(param_1 + 0xb8) + 0x22) = (char)uVar14;
                  goto LAB_fffffff00a847e54;
                }
                *(byte *)(lVar16 + 0x23) = *(byte *)(lVar16 + 0x23) | 2;
              }
              goto LAB_fffffff00a846f0c;
            }
            uVar29 = tpidr_el1;
            lVar13 = FUN_fffffff00a29b24c();
            if ((*(long *)(lVar13 + 0x18) != 0) || (DAT_fffffff007c6b250 != 0)) {
              FUN_fffffff00a724f30();
            }
            FUN_fffffff00a8df19c
                      (&MACH_HEADER,uVar15,0x10,
                       "SK[%u]: %-30s %s(%d): %d: skip iph->ip_v != IPVERSION\n");
            uVar15 = DAT_fffffff00ad984e0;
            pbVar3 = pbVar27 + *(byte *)(param_1 + 0x7a);
            if ((*(ulong *)(param_1 + 0x90) >> 0x27 & 1) != 0) {
              if (*(short *)(param_1 + 0xd8) == 0) {
                plVar20 = (long *)0x0;
              }
              else {
                plVar20 = (long *)(param_1 + 0x40);
                if (*(long *)(param_1 + 0x48) == 0) {
                  plVar20 = (long *)*plVar20;
                }
              }
              puVar26 = (uint *)((long)plVar20 + 0x24);
            }
            if (0x7f < uVar6) {
              uVar6 = 0x80;
            }
            if ((((pbVar17 < pbVar3) || (pbVar3 < pbVar27)) || (uVar10 = *puVar26, (int)uVar10 < 0))
               || ((long)(uVar25 - *(byte *)(param_1 + 0x7a)) < (long)(int)uVar10))
            goto LAB_fffffff00a846d14;
            FUN_fffffff00a7f1864("buf",pbVar3,(long)(int)uVar10,uVar6);
            FUN_fffffff00a8df19c(&MACH_HEADER,uVar15,0x10,"SK[%u]: %-30s %s %s\n");
          }
        }
      }
    }
    goto LAB_fffffff00a84817c;
  }
  if (uVar10 < 0x28) {
    uVar29 = tpidr_el1;
    lVar13 = FUN_fffffff00a29b24c();
    if ((*(long *)(lVar13 + 0x18) != 0) || (DAT_fffffff007c6b250 != 0)) {
      FUN_fffffff00a724f30();
    }
    FUN_fffffff00a8df19c
              (&MACH_HEADER,uVar15,0x10,"SK[%u]: %-30s %s(%d): %d: skip cls_len < l3hlen\n");
    uVar15 = DAT_fffffff00ad984e0;
    pbVar3 = pbVar27 + *(byte *)(param_1 + 0x7a);
    if ((*(ulong *)(param_1 + 0x90) >> 0x27 & 1) != 0) {
      if (*(short *)(param_1 + 0xd8) == 0) {
        plVar20 = (long *)0x0;
      }
      else {
        plVar20 = (long *)(param_1 + 0x40);
        if (*(long *)(param_1 + 0x48) == 0) {
          plVar20 = (long *)*plVar20;
        }
      }
      puVar26 = (uint *)((long)plVar20 + 0x24);
    }
    if (0x7f < uVar6) {
      uVar6 = 0x80;
    }
    if ((((pbVar17 < pbVar3) || (pbVar3 < pbVar27)) || (uVar10 = *puVar26, (int)uVar10 < 0)) ||
       ((long)(uVar25 - *(byte *)(param_1 + 0x7a)) < (long)(int)uVar10)) goto LAB_fffffff00a846d14;
    FUN_fffffff00a7f1864("buf",pbVar3,(long)(int)uVar10,uVar6);
    FUN_fffffff00a8df19c(&MACH_HEADER,uVar15,0x10,"SK[%u]: %-30s %s %s\n");
    goto LAB_fffffff00a84817c;
  }
  if (pbVar4 < pbVar3 + 0x28) goto LAB_fffffff00a846d14;
  uVar9 = *(ushort *)(pbVar3 + 4);
  uVar28 = ((uint)(uVar9 >> 8) | (uVar9 & 0xff00ff) << 8) + 0x28;
  if (uVar11 < uVar28) {
    uVar29 = tpidr_el1;
    lVar13 = FUN_fffffff00a29b24c();
    if ((*(long *)(lVar13 + 0x18) != 0) || (DAT_fffffff007c6b250 != 0)) {
      FUN_fffffff00a724f30();
    }
    FUN_fffffff00a8df19c
              (&MACH_HEADER,uVar15,0x10,"SK[%u]: %-30s %s(%d): %d: skip pkt_len < l3tlen\n");
    uVar15 = DAT_fffffff00ad984e0;
    pbVar3 = pbVar27 + *(byte *)(param_1 + 0x7a);
    if ((*(ulong *)(param_1 + 0x90) >> 0x27 & 1) != 0) {
      if (*(short *)(param_1 + 0xd8) == 0) {
        plVar20 = (long *)0x0;
      }
      else {
        plVar20 = (long *)(param_1 + 0x40);
        if (*(long *)(param_1 + 0x48) == 0) {
          plVar20 = (long *)*plVar20;
        }
      }
      puVar26 = (uint *)((long)plVar20 + 0x24);
    }
    if (0x7f < uVar6) {
      uVar6 = 0x80;
    }
    if (((pbVar17 < pbVar3) || (pbVar3 < pbVar27)) ||
       ((uVar10 = *puVar26, (int)uVar10 < 0 ||
        ((long)(uVar25 - *(byte *)(param_1 + 0x7a)) < (long)(int)uVar10))))
    goto LAB_fffffff00a846d14;
    FUN_fffffff00a7f1864("buf",pbVar3,(long)(int)uVar10,uVar6);
    FUN_fffffff00a8df19c(&MACH_HEADER,uVar15,0x10,"SK[%u]: %-30s %s %s\n");
  }
  else {
    if ((*pbVar3 & 0xf0) == 0x60) {
      pbVar1 = pbVar3 + 8;
      if (((ulong)pbVar1 & 7) == 0) {
        puVar18 = *(undefined8 **)(param_1 + 0xb8);
        if (puVar18 + 4 < puVar18) goto LAB_fffffff00a846d14;
        uVar15 = *(undefined8 *)pbVar1;
        uVar30 = *(undefined8 *)(pbVar3 + 0x20);
        uVar29 = *(undefined8 *)(pbVar3 + 0x18);
        puVar18[1] = *(undefined8 *)(pbVar3 + 0x10);
        *puVar18 = uVar15;
        puVar18[3] = uVar30;
        puVar18[2] = uVar29;
      }
      else {
        puVar18 = *(undefined8 **)(param_1 + 0xb8);
        if (((ulong)pbVar1 & 3) == 0) {
          if (puVar18 + 4 < puVar18) goto LAB_fffffff00a846d14;
          uVar15 = *(undefined8 *)pbVar1;
          uVar30 = *(undefined8 *)(pbVar3 + 0x20);
          uVar29 = *(undefined8 *)(pbVar3 + 0x18);
          puVar18[1] = *(undefined8 *)(pbVar3 + 0x10);
          *puVar18 = uVar15;
          puVar18[3] = uVar30;
          puVar18[2] = uVar29;
        }
        else {
          if (puVar18 + 4 <= puVar18) goto LAB_fffffff00a846d14;
          uVar15 = *(undefined8 *)pbVar1;
          uVar30 = *(undefined8 *)(pbVar3 + 0x20);
          uVar29 = *(undefined8 *)(pbVar3 + 0x18);
          puVar18[1] = *(undefined8 *)(pbVar3 + 0x10);
          *puVar18 = uVar15;
          puVar18[3] = uVar30;
          puVar18[2] = uVar29;
        }
      }
      *(undefined1 *)(*(long *)(param_1 + 0xb8) + 0x20) = 0x60;
      *(byte *)(*(long *)(param_1 + 0xb8) + 0x21) = pbVar3[6];
      *(byte **)(*(long *)(param_1 + 0xb8) + 0x28) = pbVar3;
      uVar15 = DAT_fffffff00ad984e0;
      if (pbVar3[6] == 0x2c) {
        if (uVar10 < 0x30) {
          uVar29 = tpidr_el1;
          lVar13 = FUN_fffffff00a29b24c();
          if ((*(long *)(lVar13 + 0x18) != 0) || (DAT_fffffff007c6b250 != 0)) {
            FUN_fffffff00a724f30();
          }
          FUN_fffffff00a8df19c
                    (&MACH_HEADER,uVar15,0x10,
                     "SK[%u]: %-30s %s(%d): %d: skip cls_len < l3hlen + sizeof(struct ip6_frag)\n");
          uVar15 = DAT_fffffff00ad984e0;
          pbVar3 = pbVar27 + *(byte *)(param_1 + 0x7a);
          if ((*(ulong *)(param_1 + 0x90) >> 0x27 & 1) != 0) {
            if (*(short *)(param_1 + 0xd8) == 0) {
              plVar20 = (long *)0x0;
            }
            else {
              plVar20 = (long *)(param_1 + 0x40);
              if (*(long *)(param_1 + 0x48) == 0) {
                plVar20 = (long *)*plVar20;
              }
            }
            puVar26 = (uint *)((long)plVar20 + 0x24);
          }
          if (0x7f < uVar6) {
            uVar6 = 0x80;
          }
          if ((((pbVar17 < pbVar3) || (pbVar3 < pbVar27)) || (uVar10 = *puVar26, (int)uVar10 < 0))
             || ((long)(uVar25 - *(byte *)(param_1 + 0x7a)) < (long)(int)uVar10))
          goto LAB_fffffff00a846d14;
          FUN_fffffff00a7f1864("buf",pbVar3,(long)(int)uVar10,uVar6);
          FUN_fffffff00a8df19c(&MACH_HEADER,uVar15,0x10,"SK[%u]: %-30s %s %s\n");
          goto LAB_fffffff00a84817c;
        }
        *(byte *)(*(long *)(param_1 + 0xb8) + 0x23) =
             *(byte *)(*(long *)(param_1 + 0xb8) + 0x23) | 1;
        if ((pbVar4 < pbVar3 + 0x30) || (pbVar3 + 0x28 < pbVar3)) goto LAB_fffffff00a846d14;
        *(undefined4 *)(*(long *)(param_1 + 0xb8) + 0x24) = *(undefined4 *)(pbVar3 + 0x2c);
        *(byte *)(*(long *)(param_1 + 0xb8) + 0x21) = pbVar3[0x28];
        uVar15 = DAT_fffffff00ad984e0;
        if (((uint)(uVar9 >> 8) | (uVar9 & 0xff00ff) << 8) < 8) {
          uVar29 = tpidr_el1;
          lVar13 = FUN_fffffff00a29b24c();
          if ((*(long *)(lVar13 + 0x18) != 0) || (DAT_fffffff007c6b250 != 0)) {
            FUN_fffffff00a724f30();
          }
          FUN_fffffff00a8df19c
                    (&MACH_HEADER,uVar15,0x10,"SK[%u]: %-30s %s(%d): %d: skip l3tlen < l3hlen\n");
          uVar15 = DAT_fffffff00ad984e0;
          pbVar3 = pbVar27 + *(byte *)(param_1 + 0x7a);
          if ((*(ulong *)(param_1 + 0x90) >> 0x27 & 1) != 0) {
            if (*(short *)(param_1 + 0xd8) == 0) {
              plVar20 = (long *)0x0;
            }
            else {
              plVar20 = (long *)(param_1 + 0x40);
              if (*(long *)(param_1 + 0x48) == 0) {
                plVar20 = (long *)*plVar20;
              }
            }
            puVar26 = (uint *)((long)plVar20 + 0x24);
          }
          if (0x7f < uVar6) {
            uVar6 = 0x80;
          }
          if ((((pbVar17 < pbVar3) || (pbVar3 < pbVar27)) || (uVar10 = *puVar26, (int)uVar10 < 0))
             || ((long)(uVar25 - *(byte *)(param_1 + 0x7a)) < (long)(int)uVar10))
          goto LAB_fffffff00a846d14;
          FUN_fffffff00a7f1864("buf",pbVar3,(long)(int)uVar10,uVar6);
          FUN_fffffff00a8df19c(&MACH_HEADER,uVar15,0x10,"SK[%u]: %-30s %s %s\n");
          goto LAB_fffffff00a84817c;
        }
        lVar16 = *(long *)(param_1 + 0xb8);
        if ((*(ushort *)(pbVar3 + 0x2a) & 0xf8ff) == 0) {
          *(byte *)(lVar16 + 0x23) = *(byte *)(lVar16 + 0x23) | 2;
          if ((*(ushort *)(pbVar3 + 0x2a) & 63999) == 0) {
            *(byte *)(*(long *)(param_1 + 0xb8) + 0x23) =
                 *(byte *)(*(long *)(param_1 + 0xb8) + 0x23) & 0xfe;
          }
          uVar14 = 0x30;
          goto LAB_fffffff00a846f0c;
        }
        *(byte *)(lVar16 + 0x23) = *(byte *)(lVar16 + 0x23) & 0xfd;
        *(undefined1 *)(*(long *)(param_1 + 0xb8) + 0x22) = 0x30;
LAB_fffffff00a847e54:
        *(undefined2 *)(*(long *)(param_1 + 0xb8) + 0x80) = 0;
        *(undefined2 *)(*(long *)(param_1 + 0xb8) + 0x82) = 0;
      }
      else {
        uVar14 = 0x28;
LAB_fffffff00a846f0c:
        *(char *)(*(long *)(param_1 + 0xb8) + 0x22) = (char)uVar14;
        uVar15 = DAT_fffffff00ad984e0;
        cVar8 = *(char *)(*(long *)(param_1 + 0xb8) + 0x21);
        if ((cVar8 == '\x11') || (cVar8 == '\x06')) {
          uVar11 = uVar28 - uVar14;
          uVar22 = (ulong)uVar14;
          if (cVar8 == '\x06') {
            if ((uVar24 < uVar22 + 0x14) || (uVar11 < 0x14)) {
              uVar29 = tpidr_el1;
              lVar13 = FUN_fffffff00a29b24c();
              if ((*(long *)(lVar13 + 0x18) != 0) || (DAT_fffffff007c6b250 != 0)) {
                FUN_fffffff00a724f30();
              }
              FUN_fffffff00a8df19c
                        (&MACH_HEADER,uVar15,0x10,
                         "SK[%u]: %-30s %s(%d): %d: skip (cls_len < l3hlen + sizeof(struct tcphdr)) || (ulen < sizeof(struct tcphdr))\n"
                        );
              uVar15 = DAT_fffffff00ad984e0;
              pbVar3 = pbVar27 + *(byte *)(param_1 + 0x7a);
              if ((*(ulong *)(param_1 + 0x90) >> 0x27 & 1) != 0) {
                if (*(short *)(param_1 + 0xd8) == 0) {
                  plVar20 = (long *)0x0;
                }
                else {
                  plVar20 = (long *)(param_1 + 0x40);
                  if (*(long *)(param_1 + 0x48) == 0) {
                    plVar20 = (long *)*plVar20;
                  }
                }
                puVar26 = (uint *)((long)plVar20 + 0x24);
              }
              if (0x7f < uVar6) {
                uVar6 = 0x80;
              }
              if (((pbVar17 < pbVar3) || (pbVar3 < pbVar27)) ||
                 ((uVar10 = *puVar26, (int)uVar10 < 0 ||
                  ((long)(uVar25 - *(byte *)(param_1 + 0x7a)) < (long)(int)uVar10))))
              goto LAB_fffffff00a846d14;
              FUN_fffffff00a7f1864("buf",pbVar3,(long)(int)uVar10,uVar6);
              FUN_fffffff00a8df19c(&MACH_HEADER,uVar15,0x10,"SK[%u]: %-30s %s %s\n");
            }
            else {
              pbVar4 = pbVar3 + uVar22;
              if ((pbVar4 != (byte *)0x0) && (pbVar4 < pbVar3)) goto LAB_fffffff00a846d14;
              if (pbVar4[0xc] < 0x50) {
                uVar29 = tpidr_el1;
                lVar13 = FUN_fffffff00a29b24c();
                if ((*(long *)(lVar13 + 0x18) != 0) || (DAT_fffffff007c6b250 != 0)) {
                  FUN_fffffff00a724f30();
                }
                FUN_fffffff00a8df19c
                          (&MACH_HEADER,uVar15,0x10,
                           "SK[%u]: %-30s %s(%d): %d: skip l4hlen < sizeof(*tcph)\n");
                uVar15 = DAT_fffffff00ad984e0;
                pbVar3 = pbVar27 + *(byte *)(param_1 + 0x7a);
                if ((*(ulong *)(param_1 + 0x90) >> 0x27 & 1) != 0) {
                  if (*(short *)(param_1 + 0xd8) == 0) {
                    plVar20 = (long *)0x0;
                  }
                  else {
                    plVar20 = (long *)(param_1 + 0x40);
                    if (*(long *)(param_1 + 0x48) == 0) {
                      plVar20 = (long *)*plVar20;
                    }
                  }
                  puVar26 = (uint *)((long)plVar20 + 0x24);
                }
                if (0x7f < uVar6) {
                  uVar6 = 0x80;
                }
                if ((((pbVar17 < pbVar3) || (pbVar3 < pbVar27)) ||
                    (uVar10 = *puVar26, (int)uVar10 < 0)) ||
                   ((long)(uVar25 - *(byte *)(param_1 + 0x7a)) < (long)(int)uVar10))
                goto LAB_fffffff00a846d14;
                FUN_fffffff00a7f1864("buf",pbVar3,(long)(int)uVar10,uVar6);
                FUN_fffffff00a8df19c(&MACH_HEADER,uVar15,0x10,"SK[%u]: %-30s %s %s\n");
              }
              else {
                uVar23 = pbVar4[0xc] >> 2 & 0x3c;
                if (uVar11 < uVar23) {
                  uVar29 = tpidr_el1;
                  lVar13 = FUN_fffffff00a29b24c();
                  if ((*(long *)(lVar13 + 0x18) != 0) || (DAT_fffffff007c6b250 != 0)) {
                    FUN_fffffff00a724f30();
                  }
                  FUN_fffffff00a8df19c
                            (&MACH_HEADER,uVar15,0x10,
                             "SK[%u]: %-30s %s(%d): %d: skip l4hlen > ulen\n");
                  uVar15 = DAT_fffffff00ad984e0;
                  pbVar3 = pbVar27 + *(byte *)(param_1 + 0x7a);
                  if ((*(ulong *)(param_1 + 0x90) >> 0x27 & 1) != 0) {
                    if (*(short *)(param_1 + 0xd8) == 0) {
                      plVar20 = (long *)0x0;
                    }
                    else {
                      plVar20 = (long *)(param_1 + 0x40);
                      if (*(long *)(param_1 + 0x48) == 0) {
                        plVar20 = (long *)*plVar20;
                      }
                    }
                    puVar26 = (uint *)((long)plVar20 + 0x24);
                  }
                  if (0x7f < uVar6) {
                    uVar6 = 0x80;
                  }
                  if (((pbVar17 < pbVar3) || (pbVar3 < pbVar27)) ||
                     ((uVar10 = *puVar26, (int)uVar10 < 0 ||
                      ((long)(uVar25 - *(byte *)(param_1 + 0x7a)) < (long)(int)uVar10))))
                  goto LAB_fffffff00a846d14;
                  FUN_fffffff00a7f1864("buf",pbVar3,(long)(int)uVar10,uVar6);
                  FUN_fffffff00a8df19c(&MACH_HEADER,uVar15,0x10,"SK[%u]: %-30s %s %s\n");
                }
                else {
                  if (uVar23 + uVar14 <= uVar10) goto LAB_fffffff00a846f88;
                  uVar29 = tpidr_el1;
                  lVar13 = FUN_fffffff00a29b24c();
                  if ((*(long *)(lVar13 + 0x18) != 0) || (DAT_fffffff007c6b250 != 0)) {
                    FUN_fffffff00a724f30();
                  }
                  FUN_fffffff00a8df19c
                            (&MACH_HEADER,uVar15,0x10,
                             "SK[%u]: %-30s %s(%d): %d: skip cls_len < l3hlen + l4hlen\n");
                  uVar15 = DAT_fffffff00ad984e0;
                  pbVar3 = pbVar27 + *(byte *)(param_1 + 0x7a);
                  if ((*(ulong *)(param_1 + 0x90) >> 0x27 & 1) != 0) {
                    if (*(short *)(param_1 + 0xd8) == 0) {
                      plVar20 = (long *)0x0;
                    }
                    else {
                      plVar20 = (long *)(param_1 + 0x40);
                      if (*(long *)(param_1 + 0x48) == 0) {
                        plVar20 = (long *)*plVar20;
                      }
                    }
                    puVar26 = (uint *)((long)plVar20 + 0x24);
                  }
                  if (0x7f < uVar6) {
                    uVar6 = 0x80;
                  }
                  if (((pbVar17 < pbVar3) || (pbVar3 < pbVar27)) ||
                     ((uVar10 = *puVar26, (int)uVar10 < 0 ||
                      ((long)(uVar25 - *(byte *)(param_1 + 0x7a)) < (long)(int)uVar10))))
                  goto LAB_fffffff00a846d14;
                  FUN_fffffff00a7f1864("buf",pbVar3,(long)(int)uVar10,uVar6);
                  FUN_fffffff00a8df19c(&MACH_HEADER,uVar15,0x10,"SK[%u]: %-30s %s %s\n");
                }
              }
            }
          }
          else {
            if ((uVar22 + 8 <= uVar24) && (7 < uVar11)) {
              uVar23 = 8;
              if ((pbVar3 + uVar22 != (byte *)0x0) && (pbVar3 + uVar22 < pbVar3))
              goto LAB_fffffff00a846d14;
LAB_fffffff00a846f88:
              pbVar17 = pbVar3 + uVar22;
              *(char *)(*(long *)(param_1 + 0xb8) + 0x90) = (char)uVar23;
              *(byte **)(*(long *)(param_1 + 0xb8) + 0x98) = pbVar17;
              iVar2 = uVar11 - uVar23;
              if ((*(byte *)(*(long *)(param_1 + 0xb8) + 0x23) & 1) != 0) {
                iVar2 = 0;
              }
              *(int *)(*(long *)(param_1 + 0xb8) + 0x38) = iVar2;
              lVar16 = *(long *)(param_1 + 0xb8);
              puVar18 = (undefined8 *)(lVar16 + 0x80);
              if (((ulong)pbVar17 & 3) == 0) {
                if (*(char *)(lVar16 + 0x21) == '\x06') {
                  if ((pbVar3 + uVar22 + 0x10 < pbVar17) ||
                     ((undefined8 *)(lVar16 + 0x90U) < puVar18)) goto LAB_fffffff00a846d14;
                  uVar15 = *(undefined8 *)pbVar17;
                  *(undefined8 *)(lVar16 + 0x88) = *(undefined8 *)(pbVar17 + 8);
                  *puVar18 = uVar15;
                }
                else {
                  if ((pbVar3 + uVar22 + 8 < pbVar17) || ((undefined8 *)(lVar16 + 0x88U) < puVar18))
                  goto LAB_fffffff00a846d14;
                  *(undefined4 *)puVar18 = *(undefined4 *)pbVar17;
                  pbVar27 = pbVar3 + uVar22 + 4;
                  if ((pbVar3 + uVar22 + 8 <= pbVar27) || (pbVar27 < pbVar17))
                  goto LAB_fffffff00a846d14;
                  *(undefined4 *)(lVar16 + 0x84) = *(undefined4 *)pbVar27;
                }
              }
              else if (*(char *)(lVar16 + 0x21) == '\x06') {
                if ((undefined8 *)(lVar16 + 0x90U) <= puVar18) goto LAB_fffffff00a846d14;
                uVar15 = *(undefined8 *)pbVar17;
                *(undefined8 *)(lVar16 + 0x88) = *(undefined8 *)(pbVar17 + 8);
                *puVar18 = uVar15;
              }
              else {
                if ((undefined8 *)(lVar16 + 0x88U) <= puVar18) goto LAB_fffffff00a846d14;
                *puVar18 = *(undefined8 *)pbVar17;
              }
              if ((((param_4 & 1) == 0) && (*(char *)(*(long *)(param_1 + 0xb8) + 0x21) == '\x06'))
                 && (*(int *)(*(long *)(param_1 + 0xb8) + 0x38) != 0)) {
                *(ulong *)(param_1 + 0x90) = *(ulong *)(param_1 + 0x90) | 0x8000000;
              }
              goto LAB_fffffff00a847014;
            }
            uVar29 = tpidr_el1;
            lVar13 = FUN_fffffff00a29b24c();
            if ((*(long *)(lVar13 + 0x18) != 0) || (DAT_fffffff007c6b250 != 0)) {
              FUN_fffffff00a724f30();
            }
            FUN_fffffff00a8df19c
                      (&MACH_HEADER,uVar15,0x10,
                       "SK[%u]: %-30s %s(%d): %d: skip (cls_len < l3hlen + sizeof(struct udphdr)) || (ulen < sizeof(struct udphdr))\n"
                      );
            uVar15 = DAT_fffffff00ad984e0;
            pbVar3 = pbVar27 + *(byte *)(param_1 + 0x7a);
            if ((*(ulong *)(param_1 + 0x90) >> 0x27 & 1) != 0) {
              if (*(short *)(param_1 + 0xd8) == 0) {
                plVar20 = (long *)0x0;
              }
              else {
                plVar20 = (long *)(param_1 + 0x40);
                if (*(long *)(param_1 + 0x48) == 0) {
                  plVar20 = (long *)*plVar20;
                }
              }
              puVar26 = (uint *)((long)plVar20 + 0x24);
            }
            if (0x7f < uVar6) {
              uVar6 = 0x80;
            }
            if ((((pbVar17 < pbVar3) || (pbVar3 < pbVar27)) || (uVar10 = *puVar26, (int)uVar10 < 0))
               || ((long)(uVar25 - *(byte *)(param_1 + 0x7a)) < (long)(int)uVar10))
            goto LAB_fffffff00a846d14;
            FUN_fffffff00a7f1864("buf",pbVar3,(long)(int)uVar10,uVar6);
            FUN_fffffff00a8df19c(&MACH_HEADER,uVar15,0x10,"SK[%u]: %-30s %s %s\n");
          }
          goto LAB_fffffff00a84817c;
        }
      }
LAB_fffffff00a847014:
      if ((DAT_fffffff00ad984d8._3_1_ >> 5 & 1) != 0) {
        uVar15 = tpidr_el1;
        FUN_fffffff00a8df19c
                  (&MACH_HEADER,DAT_fffffff00ad984e0,0,
                   "SK[%u]: %-30s pkt_length %u l3_ip_len %u l3_ip_ver 0x%x l3_proto %u l4_sport %u l4_dport %u\n"
                  );
      }
      if ((param_4 & 1) != 0) {
LAB_fffffff00a847050:
        *(ushort *)(param_1 + 0x18) = *(ushort *)(param_1 + 0x18) | 0x10;
        return 0;
      }
      uVar10 = *(uint *)(param_1 + 0x10);
      if (uVar10 != uVar28 + *(byte *)(param_1 + 0x7b)) {
        uVar15 = tpidr_el1;
        FUN_fffffff00a8df19c
                  (&MACH_HEADER,DAT_fffffff00ad984e0,0x10,
                   "SK[%u]: %-30s packet is too long (%u), trimming to IP + L2 length (%d)\n");
        iVar2 = uVar28 + *(byte *)(param_1 + 0x7b);
        *(int *)(param_1 + 0x10) = iVar2;
        if (*(short *)(param_1 + 0xd8) == 0) {
          uVar25 = 0;
          plVar20 = (long *)0x0;
        }
        else {
          plVar20 = (long *)(param_1 + 0x40);
          if (*(long *)(param_1 + 0x48) == 0) {
            plVar20 = (long *)*plVar20;
            uVar25 = (long)plVar20 + 0x32;
          }
          else {
            uVar25 = param_1 + 0x72;
          }
        }
        if (uVar25 < (long)plVar20 + 0x32U) {
LAB_fffffff00a846d14:
                    /* WARNING: Does not return */
          pcVar12 = (code *)SoftwareBreakpoint(0x5519,0xfffffff00a846d18);
          (*pcVar12)();
        }
        *(int *)(plVar20 + 4) = (int)lVar13;
        *(int *)((long)plVar20 + 0x24) = iVar2;
        uVar10 = *puVar26;
      }
      if ((*(ushort *)(param_1 + 0x8e) != 0 || uVar10 <= uVar5) &&
         (*(ushort *)(param_1 + 0x8e) <= uVar5)) goto LAB_fffffff00a847050;
      uVar15 = tpidr_el1;
      FUN_fffffff00a8df19c
                (&MACH_HEADER,DAT_fffffff00ad984e0,0x10,
                 "SK[%u]: %-30s dropped; length (%u) exceeds MTU (%d)  proto_seg_sz %d\n");
      uVar15 = DAT_fffffff00ad984e0;
      FUN_fffffff00a7f1864("buf",pbVar3,uVar24,0x80);
      FUN_fffffff00a8df19c(&MACH_HEADER,uVar15,0x10,"SK[%u]: %-30s %s\n");
      uVar15 = 0x28;
      goto LAB_fffffff00a848180;
    }
    uVar29 = tpidr_el1;
    lVar13 = FUN_fffffff00a29b24c();
    if ((*(long *)(lVar13 + 0x18) != 0) || (DAT_fffffff007c6b250 != 0)) {
      FUN_fffffff00a724f30();
    }
    FUN_fffffff00a8df19c
              (&MACH_HEADER,uVar15,0x10,
               "SK[%u]: %-30s %s(%d): %d: skip (ip6->ip6_vfc & IPV6_VERSION_MASK) != IPV6_VERSION\n"
              );
    uVar15 = DAT_fffffff00ad984e0;
    pbVar3 = pbVar27 + *(byte *)(param_1 + 0x7a);
    if ((*(ulong *)(param_1 + 0x90) >> 0x27 & 1) != 0) {
      if (*(short *)(param_1 + 0xd8) == 0) {
        plVar20 = (long *)0x0;
      }
      else {
        plVar20 = (long *)(param_1 + 0x40);
        if (*(long *)(param_1 + 0x48) == 0) {
          plVar20 = (long *)*plVar20;
        }
      }
      puVar26 = (uint *)((long)plVar20 + 0x24);
    }
    if (0x7f < uVar6) {
      uVar6 = 0x80;
    }
    if ((((pbVar17 < pbVar3) || (pbVar3 < pbVar27)) || (uVar10 = *puVar26, (int)uVar10 < 0)) ||
       ((long)(uVar25 - *(byte *)(param_1 + 0x7a)) < (long)(int)uVar10)) goto LAB_fffffff00a846d14;
    FUN_fffffff00a7f1864("buf",pbVar3,(long)(int)uVar10,uVar6);
    FUN_fffffff00a8df19c(&MACH_HEADER,uVar15,0x10,"SK[%u]: %-30s %s %s\n");
  }
LAB_fffffff00a84817c:
  uVar15 = 0x2d;
LAB_fffffff00a848180:
  puVar18 = *(undefined8 **)(param_1 + 0xb8);
  puVar18[0x11] = 0;
  puVar18[0x10] = 0;
  puVar18[0x13] = 0;
  puVar18[0x12] = 0;
  puVar18[0xd] = 0;
  puVar18[0xc] = 0;
  puVar18[0xf] = 0;
  puVar18[0xe] = 0;
  puVar18[9] = 0;
  puVar18[8] = 0;
  puVar18[0xb] = 0;
  puVar18[10] = 0;
  puVar18[5] = 0;
  puVar18[4] = 0;
  puVar18[7] = 0;
  puVar18[6] = 0;
  puVar18[1] = 0;
  *puVar18 = 0;
  puVar18[3] = 0;
  puVar18[2] = 0;
  return uVar15;
}

