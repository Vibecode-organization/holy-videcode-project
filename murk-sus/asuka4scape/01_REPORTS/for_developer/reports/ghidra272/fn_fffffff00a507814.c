// FUN_fffffff00a507814 @ fffffff00a507814 size=4308

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_fffffff00a507814(long param_1,long param_2,long param_3,undefined4 *param_4)

{
  ulong *puVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  code *pcVar5;
  bool bVar6;
  char cVar7;
  int iVar8;
  int iVar9;
  long lVar10;
  long lVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  byte bVar14;
  ushort uVar15;
  ulong uVar16;
  ulong uVar17;
  ulong uVar18;
  uint *puVar19;
  undefined8 uVar20;
  undefined1 *puVar21;
  long lVar22;
  int in_wzr;
  undefined4 local_ad4;
  undefined8 local_ad0;
  undefined8 uStack_ac8;
  undefined8 uStack_ac0;
  undefined8 uStack_ab8;
  undefined8 local_ab0;
  undefined8 uStack_aa8;
  undefined8 uStack_aa0;
  undefined8 uStack_a98;
  undefined8 local_a90;
  undefined8 uStack_a88;
  undefined8 uStack_a80;
  undefined8 local_a78;
  undefined8 local_a70;
  undefined8 uStack_a68;
  undefined8 uStack_a60;
  undefined8 uStack_a58;
  undefined8 local_a50;
  undefined8 uStack_a48;
  undefined8 uStack_a40;
  undefined8 uStack_a38;
  undefined8 local_a30;
  undefined8 uStack_a28;
  undefined8 uStack_a20;
  undefined8 uStack_a18;
  undefined8 local_a10;
  undefined8 uStack_a08;
  undefined8 uStack_a00;
  undefined8 uStack_9f8;
  undefined8 local_9f0;
  undefined8 uStack_9e8;
  undefined8 uStack_9e0;
  undefined8 uStack_9d8;
  undefined8 local_9d0;
  undefined8 uStack_9c8;
  undefined8 uStack_9c0;
  undefined8 uStack_9b8;
  undefined8 local_9b0;
  undefined8 uStack_9a8;
  undefined8 uStack_9a0;
  undefined8 uStack_998;
  undefined8 local_990;
  undefined8 uStack_988;
  undefined8 uStack_980;
  undefined8 uStack_978;
  undefined8 local_970;
  undefined8 uStack_968;
  undefined8 uStack_960;
  undefined8 uStack_958;
  undefined8 local_950;
  undefined8 uStack_948;
  undefined8 local_940;
  undefined8 uStack_938;
  undefined8 local_930;
  undefined8 uStack_928;
  undefined8 uStack_920;
  undefined5 uStack_918;
  undefined3 local_913;
  undefined5 uStack_910;
  undefined3 uStack_90b;
  undefined8 uStack_908;
  undefined8 uStack_900;
  undefined8 uStack_8f8;
  undefined8 local_8f0;
  undefined8 uStack_8e8;
  undefined8 local_8e0;
  undefined8 local_8d8;
  undefined8 local_8d0;
  undefined8 uStack_8c8;
  undefined8 uStack_8c0;
  undefined8 uStack_8b8;
  undefined4 local_8a8;
  uint local_8a4;
  long local_8a0;
  undefined2 local_898;
  short local_896;
  undefined1 auStack_894 [4];
  undefined1 auStack_890 [20];
  undefined1 local_87c;
  char local_87b;
  short local_87a;
  byte local_1ca;
  uint local_1c4;
  undefined8 local_1b0;
  undefined8 uStack_1a8;
  short local_19a;
  byte local_80;
  long local_78;
  
  local_78 = DAT_fffffff00ad30000;
  lVar4 = 0;
  if ((*(byte *)(param_1 + 0x448) & 2) != 0) {
    lVar4 = param_1 + 0x768;
  }
  if ((*(byte *)(param_2 + 0x3c) >> 2 & 1) != 0) {
    FUN_fffffff00a8df19c(&MACH_HEADER,DAT_fffffff00ad7ce40,0x10,"%s: %s\n");
    uVar20 = 0x16;
    goto LAB_fffffff00a507c10;
  }
  if ((ulong)(long)_DAT_fffffff00ad121a8 <= *(ulong *)(param_2 + 0x40)) {
    FUN_fffffff00a8df19c(&MACH_HEADER,DAT_fffffff00ad7ce40,0x10,"%s: %s\n");
    uVar20 = 0x18;
    goto LAB_fffffff00a507c10;
  }
  if (*(long *)(param_3 + 0x10) == 0) {
LAB_fffffff00a5079b4:
    uVar20 = 0x16;
    goto LAB_fffffff00a507c10;
  }
  uVar20 = 0x16;
  if ((*(long *)(param_3 + 0x18) != 0x10) ||
     (lVar22 = *(long *)(param_3 + 0x28), lVar22 - 0x801U < 0xfffffffffffff800))
  goto LAB_fffffff00a507c10;
  if (*(long *)(param_3 + 0x20) == 0) goto LAB_fffffff00a5079b4;
  lVar10 = FUN_fffffff00a2216c4(&DAT_fffffff007c73410,0x8004);
  uVar20 = FUN_fffffff00a220c30(&DAT_fffffff007c6afb0,lVar22,0x8000,0);
  *(undefined8 *)(lVar10 + 0x5a8) = uVar20;
  *(long *)(lVar10 + 0x5a0) = lVar22;
  uVar3 = DAT_fffffff00ad22e28;
  uVar2 = DAT_fffffff00ad22e28 & 0xffffff | 0x22000000;
  puVar19 = (uint *)(lVar10 + 0x30);
  *puVar19 = uVar2;
  *(undefined4 *)(lVar10 + 0x34) = 0;
  *(undefined8 *)(lVar10 + 0x38) = 0;
  DAT_fffffff00ad22e34 = DAT_fffffff00ad22e34 + 1;
  if ((int)uVar3 < 0) {
    iVar8 = DAT_fffffff00ad22e24 + 1;
    uVar3 = DAT_fffffff00ad22e24 + 0xf0000001;
    DAT_fffffff00ad22e24 = iVar8;
    if (uVar3 < 0xf0000002) {
LAB_fffffff00a508420:
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa61ed0(&DAT_fffffff00ad22e24,uVar20);
    }
    *(uint *)(lVar10 + 0x40) = uVar2;
    *(undefined4 *)(lVar10 + 0x44) = 0;
    *(undefined8 *)(lVar10 + 0x48) = 0;
    DAT_fffffff00ad22e34 = DAT_fffffff00ad22e34 + 1;
    iVar8 = DAT_fffffff00ad22e24 + 1;
    uVar2 = DAT_fffffff00ad22e24 + 0xf0000001;
    DAT_fffffff00ad22e24 = iVar8;
    if (uVar2 < 0xf0000002) goto LAB_fffffff00a508420;
  }
  else {
    *(uint *)(lVar10 + 0x40) = uVar2;
    *(undefined4 *)(lVar10 + 0x44) = 0;
    *(undefined8 *)(lVar10 + 0x48) = 0;
    DAT_fffffff00ad22e34 = DAT_fffffff00ad22e34 + 1;
  }
  uVar20 = FUN_fffffff00a389b14(*(undefined8 *)(param_3 + 0x20),uVar20,lVar22);
  if ((int)uVar20 == 0) {
    *(undefined4 *)(lVar10 + 0x50) = 1;
    *(undefined4 *)(lVar10 + 0x48c) = *(undefined4 *)(param_2 + 0x4c);
    *(long *)(lVar10 + 0x550) = param_2;
    iVar8 = FUN_fffffff00a6ec3c0(param_1);
    bVar14 = 0;
    if (iVar8 != 0) {
      bVar14 = 0x10;
    }
    *(byte *)(lVar10 + 100) = *(byte *)(lVar10 + 100) & 0xef | bVar14;
    cVar7 = FUN_fffffff00a9dee48(lVar4,"com.apple.private.network.lpw_capable");
    *(byte *)(lVar10 + 100) = *(byte *)(lVar10 + 100) & 0xbf | cVar7 << 6;
    FUN_fffffff00a8de44c(lVar10 + 0x54);
    *(byte *)(lVar10 + 0x5d) = *(byte *)(lVar10 + 0x5d) & 0xfe;
    *(undefined8 *)(lVar10 + 0x4a8) = 0;
    *(undefined8 *)(lVar10 + 0x4a0) = 0;
    if ((0 < DAT_fffffff00adcdd64) &&
       ((DAT_fffffff00adcdd68 == 0 || (*(int *)(lVar10 + 0x48c) == DAT_fffffff00adcdd68)))) {
      uStack_910 = 0;
      uStack_928 = 0;
      local_930 = 0;
      uStack_918 = 0;
      local_913 = 0;
      uStack_920 = 0;
      FUN_fffffff00a8de848(lVar10 + 0x54,&local_930);
      FUN_fffffff00a8df19c
                (&MACH_HEADER,DAT_fffffff00ad7ce40,0,
                 "%s: NECP_CLIENT_LOG <pid %d %s>: Adding client\n\n");
    }
    uVar20 = FUN_fffffff00a38a690(lVar10 + 0x54,*(undefined8 *)(param_3 + 0x10),0x10);
    if ((int)uVar20 != 0) {
      FUN_fffffff00a8df19c
                (&MACH_HEADER,DAT_fffffff00ad7ce40,0x10,
                 "%s: necp_client_add client_id copyout error (%d)\n");
      goto LAB_fffffff00a507b80;
    }
    FUN_fffffff00aa65cc0(&local_8a8,0x830);
    iVar8 = FUN_fffffff00a4febd8
                      (lVar10,*(undefined8 *)(lVar10 + 0x5a8),*(undefined4 *)(lVar10 + 0x5a0),
                       &local_8a8);
    lVar22 = local_8a0;
    uVar2 = local_8a8;
    if ((local_8a8 >> 0x14 & 1) == 0) {
      bVar6 = false;
    }
    else {
      lVar11 = FUN_fffffff00a723da0(param_1);
      bVar6 = lVar22 != lVar11;
    }
    if ((iVar8 == 0) && (bVar6 || (uVar2 & 0x1000000) != 0)) {
      lVar22 = FUN_fffffff00a29b24c();
      iVar9 = FUN_fffffff00a723994(*(undefined8 *)(lVar22 + 8),0x2711,0);
      uVar20 = DAT_fffffff00ad7ce40;
      if (iVar9 != 0) {
        if (bVar6) {
          FUN_fffffff00a724f30(param_1);
          FUN_fffffff00a8df19c
                    (&MACH_HEADER,uVar20,0x10,
                     "%s: %s(%d) does not hold the necessary entitlement to delegate network traffic for other processes by upid\n"
                    );
        }
        uVar20 = DAT_fffffff00ad7ce40;
        if ((uVar2 >> 0x18 & 1) != 0) {
          FUN_fffffff00a724f30();
          FUN_fffffff00a8df19c
                    (&MACH_HEADER,uVar20,0x10,
                     "%s: %s(%d) does not hold the necessary entitlement to set attributed bundle identifier\n"
                    );
        }
        uVar20 = 1;
        goto LAB_fffffff00a507b80;
      }
    }
    if ((iVar8 == 0) && ((uVar2 >> 0x14 & 1) != 0)) {
      *(long *)(lVar10 + 0x490) = local_8a0;
LAB_fffffff00a507e94:
      if ((local_8a8._3_1_ >> 6 & 1) != 0) {
        *(byte *)(lVar10 + 100) = *(byte *)(lVar10 + 100) | 0x80;
      }
      if ((local_8a4 >> 0xb & 1) != 0) {
        lVar22 = FUN_fffffff00a29b24c();
        iVar9 = FUN_fffffff00a7f1648(param_1,*(undefined8 *)(lVar22 + 8));
        uVar20 = DAT_fffffff00ad7ce40;
        if (iVar9 != 0) {
          FUN_fffffff00a724f30(param_1);
          FUN_fffffff00a8df19c
                    (&MACH_HEADER,uVar20,0x10,
                     "%s: %s(%d) does not hold the necessary entitlement to open a custom nexus client\n"
                    );
          uVar20 = 1;
          goto LAB_fffffff00a507b80;
        }
      }
      if ((local_8a4 & 0x600) != 0) {
        lVar22 = FUN_fffffff00a29b24c();
        iVar9 = FUN_fffffff00a723994(*(undefined8 *)(lVar22 + 8),0x271f,0);
        uVar20 = DAT_fffffff00ad7ce40;
        if (iVar9 != 0) {
          FUN_fffffff00a724f30(param_1);
          FUN_fffffff00a8df19c
                    (&MACH_HEADER,uVar20,0x10,
                     "%s: %s(%d) does not hold the necessary entitlement for custom protocol APIs\n"
                    );
          uVar20 = 1;
          goto LAB_fffffff00a507b80;
        }
      }
      if ((local_80 & 1) != 0) {
        iVar9 = FUN_fffffff00a9dee48(lVar4,"com.apple.private.network.aop2_offload");
        uVar20 = DAT_fffffff00ad7ce40;
        if (iVar9 == 0) {
          FUN_fffffff00a724f30(param_1);
          FUN_fffffff00a8df19c
                    (&MACH_HEADER,uVar20,0x10,
                     "%s: %s(%d) does not hold the necessary entitlement for aop offload\n");
          uVar20 = 1;
        }
        else {
          if (((byte)local_8a4 >> 3 & 1) == 0) goto LAB_fffffff00a507d74;
          FUN_fffffff00a8df19c(&MACH_HEADER,DAT_fffffff00ad7ce40,0,"%s: %s\n");
          uVar20 = 0x16;
        }
        goto LAB_fffffff00a507b80;
      }
      if ((((byte)local_8a4 >> 3 & 1) == 0) || ((local_1ca != 0x11 && (local_1ca != 6))))
      goto LAB_fffffff00a507d74;
      uStack_8c8 = 0;
      local_8d0 = 0;
      uStack_8b8 = 0;
      uStack_8c0 = 0;
      uStack_8e8 = 0;
      local_8f0 = 0;
      uStack_908 = 0;
      uStack_910 = 0;
      uStack_90b = 0;
      uStack_8f8 = 0;
      uStack_900 = 0;
      uStack_928 = *(undefined8 *)(lVar10 + 0x5c);
      local_930 = *(undefined8 *)(lVar10 + 0x54);
      uStack_918 = 0;
      local_913 = 0;
      uStack_920 = 0;
      uVar3 = *(uint *)(lVar10 + 0x48c);
      uVar2 = uVar3;
      if ((local_8a8 & 0x10000) != 0) {
        uVar2 = local_1c4;
      }
      local_8e0 = CONCAT44(uVar3,(uint)local_1ca);
      local_8d8 = (ulong)uVar2;
      FUN_fffffff00a726d80(uVar3,(long)&local_8d8 + 4,0x10);
      FUN_fffffff00a726d80(local_8d8 & 0xffffffff,(long)&uStack_8c8 + 5,0x10);
      if (local_898._1_1_ == '\x1e') {
        if (0x1c < (byte)local_898) goto LAB_fffffff00a508284;
LAB_fffffff00a5081f4:
        puVar21 = auStack_890;
        FUN_fffffff00aa65b10(&uStack_918,&local_898,(byte)local_898);
        uVar17 = 0x10;
        uVar16 = 0x10;
      }
      else {
        if (local_898._1_1_ != '\x02') {
          if (local_898._1_1_ != '\0') {
            FUN_fffffff00a8df19c
                      (&MACH_HEADER,DAT_fffffff00ad7ce40,0x10,
                       "%s: necp_client_add listener invalid address family (%d)\n");
            uVar20 = 0x16;
            goto LAB_fffffff00a507b80;
          }
          local_898 = 0x1e1c;
          local_898._0_1_ = 0x1c;
          goto LAB_fffffff00a5081f4;
        }
        if (0x10 < (byte)local_898) goto LAB_fffffff00a508284;
        puVar21 = auStack_894;
        FUN_fffffff00aa65b10(&uStack_918,&local_898);
        uVar16 = 4;
        uVar17 = 4;
      }
      uVar2 = local_8a4 >> 0xf & (local_8a8 >> 8 & 0xff) << 2;
      if (local_896 == 0) {
        if (uVar16 < uVar17) goto LAB_fffffff00a508284;
        uVar20 = FUN_fffffff00a7ec084
                           (lVar10 + 0x568,puVar21,uVar17,local_1ca,&local_896,uVar2 & 0x100,
                            &local_930);
        if ((int)uVar20 != 0) {
          FUN_fffffff00a8df19c
                    (&MACH_HEADER,DAT_fffffff00ad7ce40,0x10,
                     "%s: necp_client_add netns_reserve_ephemeral error (%d)\n");
          goto LAB_fffffff00a507b80;
        }
        FUN_fffffff00a5186c0
                  (*(undefined8 *)(lVar10 + 0x5a8),*(undefined4 *)(lVar10 + 0x5a0),local_896);
      }
      else {
        if (uVar16 < uVar17) {
LAB_fffffff00a508284:
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(0x5519,0xfffffff00a508288);
          (*pcVar5)();
        }
        uVar20 = FUN_fffffff00a7e9f70
                           (lVar10 + 0x568,puVar21,uVar17,local_1ca,local_896,uVar2 & 0x100,
                            &local_930);
        if ((int)uVar20 != 0) {
          FUN_fffffff00a8df19c
                    (&MACH_HEADER,DAT_fffffff00ad7ce40,0x10,
                     "%s: necp_client_add netns_reserve error (%d)\n");
          goto LAB_fffffff00a507b80;
        }
      }
    }
    else if (iVar8 == 0) goto LAB_fffffff00a507e94;
LAB_fffffff00a507d74:
    local_940 = 0;
    uStack_938 = 0;
    uStack_ac8 = 0;
    local_ad0 = 0;
    uStack_ab8 = 0;
    uStack_ac0 = 0;
    uStack_aa8 = 0;
    local_ab0 = 0;
    uStack_a98 = 0;
    uStack_aa0 = 0;
    uStack_a88 = 0;
    local_a90 = 0;
    local_a78 = 0;
    uStack_a80 = 0;
    uStack_a68 = 0;
    local_a70 = 0;
    uStack_a58 = 0;
    uStack_a60 = 0;
    uStack_a48 = 0;
    local_a50 = 0;
    uStack_a38 = 0;
    uStack_a40 = 0;
    uStack_a28 = 0;
    local_a30 = 0;
    uStack_a18 = 0;
    uStack_a20 = 0;
    uStack_a08 = 0;
    local_a10 = 0;
    uStack_9f8 = 0;
    uStack_a00 = 0;
    uStack_9e8 = 0;
    local_9f0 = 0;
    uStack_9d8 = 0;
    uStack_9e0 = 0;
    uStack_9c8 = 0;
    local_9d0 = 0;
    uStack_9b8 = 0;
    uStack_9c0 = 0;
    uStack_9a8 = 0;
    local_9b0 = 0;
    uStack_998 = 0;
    uStack_9a0 = 0;
    uStack_988 = 0;
    local_990 = 0;
    uStack_978 = 0;
    uStack_980 = 0;
    uStack_968 = 0;
    local_970 = 0;
    uStack_958 = 0;
    uStack_960 = 0;
    uStack_948 = 0;
    local_950 = 0;
    if ((local_8a8._3_1_ >> 1 & 1) != 0) {
      lVar4 = tpidr_el1;
      if (*(ulong *)(param_2 + 0x58) == 0) {
        *(ulong *)(param_2 + 0x58) = (ulong)*(uint *)(lVar4 + 0x4e8);
      }
      else {
        FUN_fffffff00a2262d4(param_2 + 0x50,lVar4,0);
      }
      lVar22 = FUN_fffffff00a4fcfe0(param_2,&local_1b0);
      if (lVar22 == 0) {
        if (*(int *)(param_2 + 0x58) == *(int *)(lVar4 + 0x4e8)) {
          *(int *)(param_2 + 0x58) = in_wzr;
        }
        else {
          FUN_fffffff00a226e08(param_2 + 0x50,lVar4);
        }
        FUN_fffffff00a8df19c(&MACH_HEADER,DAT_fffffff00ad7ce40,0x10,"%s: %s\n");
      }
      else {
        lVar11 = lVar22;
        if (*(long *)(lVar22 + 0x598) != 0) {
          lVar11 = *(long *)(lVar22 + 0x598);
        }
        *(long *)(lVar10 + 0x598) = lVar11;
        FUN_fffffff00a50ee68(lVar11);
        FUN_fffffff00a50f150(lVar10,&local_ad0);
        uStack_938 = uStack_1a8;
        local_940 = local_1b0;
        uVar16 = *(ulong *)(lVar22 + 0x4a0);
        if (*(ulong *)(lVar22 + 0x4a0) != 0) {
          do {
            uVar17 = uVar16;
            uVar16 = *(ulong *)(uVar17 + 0x30);
          } while (uVar16 != 0);
          uVar15 = 0;
          do {
            do {
              while( true ) {
                uVar16 = uVar17;
                uVar15 = uVar15 + 1;
                uVar18 = *(ulong *)(uVar16 + 0x38);
                if (*(ulong *)(uVar16 + 0x38) == 0) break;
                do {
                  puVar1 = (ulong *)(uVar18 + 0x30);
                  uVar17 = uVar18;
                  uVar18 = *puVar1;
                } while (*puVar1 != 0);
              }
              uVar17 = *(ulong *)(uVar16 + 0x40) & 0xfffffffffffffffe;
            } while ((uVar17 != 0) && (uVar16 == *(ulong *)(uVar17 + 0x30)));
            do {
              uVar17 = *(ulong *)(uVar16 + 0x40) & 0xfffffffffffffffe;
              if (uVar17 == 0) {
                bVar6 = 1 < uVar15;
                goto LAB_fffffff00a508138;
              }
              bVar6 = uVar16 == *(ulong *)(uVar17 + 0x38);
              uVar16 = uVar17;
            } while (bVar6);
          } while( true );
        }
        bVar6 = false;
LAB_fffffff00a508138:
        if (*(int *)(param_2 + 0x58) == *(int *)(lVar4 + 0x4e8)) {
          *(int *)(param_2 + 0x58) = in_wzr;
        }
        else {
          FUN_fffffff00a226e08(param_2 + 0x50,lVar4);
        }
        if ((iVar8 == 0) && ((local_8a8._3_1_ >> 2 & 1) != 0)) {
          if (local_19a == 0) {
            FUN_fffffff00a8df19c(&MACH_HEADER,DAT_fffffff00ad7ce40,0,"%s: %s\n");
          }
          else {
            iVar8 = FUN_fffffff00a3542b4(&local_940,&DAT_fffffff007029084,0x10);
            if (iVar8 == 0) {
              FUN_fffffff00a8df19c(&MACH_HEADER,DAT_fffffff00ad7ce40,0,"%s: %s\n");
            }
            else if (bVar6) {
              FUN_fffffff00a8df19c(&MACH_HEADER,DAT_fffffff00ad7ce40,0,"%s: %s\n");
            }
            else if (local_1ca == 0x11) {
              if ((char)local_a78 == '\x11') {
                if ((local_898._1_1_ == '\x02') || (local_898._1_1_ == '\x1e')) {
                  if (local_898._1_1_ == local_87b) {
                    if (local_898._1_1_ == local_ab0._1_1_) {
                      iVar8 = FUN_fffffff00a354278(&local_898,&local_ab0,(byte)local_898);
                      if (iVar8 == 0) {
                        iVar8 = FUN_fffffff00a354278(&local_87c,(long)&uStack_a98 + 4,local_87c);
                        if (iVar8 == 0) {
                          if (local_896 == local_ab0._2_2_) {
                            if (local_87a == uStack_a98._6_2_) {
                              *(byte *)(lVar10 + 100) = *(byte *)(lVar10 + 100) | 0x20;
                              *(undefined8 *)(lVar10 + 0x590) = uStack_938;
                              *(undefined8 *)(lVar10 + 0x588) = local_940;
                            }
                            else {
                              FUN_fffffff00a8df19c(&MACH_HEADER,DAT_fffffff00ad7ce40,0,"%s: %s\n");
                            }
                          }
                          else {
                            FUN_fffffff00a8df19c(&MACH_HEADER,DAT_fffffff00ad7ce40,0,"%s: %s\n");
                          }
                        }
                        else {
                          FUN_fffffff00a8df19c(&MACH_HEADER,DAT_fffffff00ad7ce40,0,"%s: %s\n");
                        }
                      }
                      else {
                        FUN_fffffff00a8df19c(&MACH_HEADER,DAT_fffffff00ad7ce40,0,"%s: %s\n");
                      }
                    }
                    else {
                      FUN_fffffff00a8df19c(&MACH_HEADER,DAT_fffffff00ad7ce40,0,"%s: %s\n");
                    }
                  }
                  else {
                    FUN_fffffff00a8df19c(&MACH_HEADER,DAT_fffffff00ad7ce40,0,"%s: %s\n");
                  }
                }
                else {
                  FUN_fffffff00a8df19c
                            (&MACH_HEADER,DAT_fffffff00ad7ce40,0,
                             "%s: necp_client_add, flow demux pattern not supported for %d family\n"
                            );
                }
              }
              else {
                FUN_fffffff00a8df19c(&MACH_HEADER,DAT_fffffff00ad7ce40,0,"%s: %s\n");
              }
            }
            else {
              FUN_fffffff00a8df19c
                        (&MACH_HEADER,DAT_fffffff00ad7ce40,0,
                         "%s: necp_client_add, flow demux pattern not supported for %d protocol\n");
            }
          }
        }
      }
    }
    FUN_fffffff00a5188d8(lVar10);
    lVar4 = tpidr_el1;
    if (*(ulong *)(param_2 + 0x58) == 0) {
      *(ulong *)(param_2 + 0x58) = (ulong)*(uint *)(lVar4 + 0x4e8);
    }
    else {
      FUN_fffffff00a2262d4(param_2 + 0x50,lVar4,0);
    }
    FUN_fffffff00a4fad2c(param_2 + 0x18,lVar10);
    *(long *)(param_2 + 0x40) = *(long *)(param_2 + 0x40) + 1;
    uVar20 = CONCAT44(0xfffffff0,DAT_fffffff00adcdd54);
    DAT_fffffff00adcdd54 = DAT_fffffff00adcdd54 + 1;
    FUN_fffffff00a227a00(uVar20,&DAT_fffffff00adcdd98);
    FUN_fffffff00a4fb6a4(&DAT_fffffff00adcde18,lVar10);
    FUN_fffffff00a228d30(&DAT_fffffff00adcdd98);
    if (*(ulong *)(lVar10 + 0x38) == 0) {
      *(ulong *)(lVar10 + 0x38) = (ulong)*(uint *)(lVar4 + 0x4e8);
    }
    else {
      FUN_fffffff00a2262d4(puVar19,lVar4,0);
    }
    lVar11 = FUN_fffffff00a29b24c();
    lVar22 = *(long *)(lVar11 + 0x18);
    if (*(long *)(lVar11 + 0x18) == 0) {
      lVar22 = DAT_fffffff007c6b250;
    }
    FUN_fffffff00a5150d4(lVar22,param_2,lVar10,0);
    if ((2 < DAT_fffffff00adcdd64) &&
       ((DAT_fffffff00adcdd68 == 0 || (*(int *)(lVar10 + 0x48c) == DAT_fffffff00adcdd68)))) {
      uStack_910 = 0;
      uStack_928 = 0;
      local_930 = 0;
      uStack_918 = 0;
      local_913 = 0;
      uStack_920 = 0;
      FUN_fffffff00a8de848(lVar10 + 0x54,&local_930);
      FUN_fffffff00a8df19c
                (&MACH_HEADER,DAT_fffffff00ad7ce40,0,
                 "%s: NECP_CLIENT_RESULT_LOG <pid %d %s> <result %d> <tunnel %d> <scope %d> <flowdivert %d> <filter %d>: Updated client result\n\n"
                );
    }
    iVar8 = *(int *)(lVar10 + 0x50);
    *(int *)(lVar10 + 0x50) = iVar8 + 1;
    if (iVar8 + 0xf0000001U < 0xf0000002) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa61ed0();
    }
    if (*(int *)(lVar10 + 0x38) == *(int *)(lVar4 + 0x4e8)) {
      *(int *)(lVar10 + 0x38) = in_wzr;
    }
    else {
      FUN_fffffff00a226e08(puVar19,lVar4);
    }
    if (*(int *)(param_2 + 0x58) == *(int *)(lVar4 + 0x4e8)) {
      *(int *)(param_2 + 0x58) = in_wzr;
    }
    else {
      FUN_fffffff00a226e08(param_2 + 0x50,lVar4);
    }
    local_ad4 = 0;
    FUN_fffffff00a518930
              (*(undefined8 *)(lVar10 + 0x5a0),*(undefined8 *)(lVar10 + 0x5a8),&local_ad4,0,0,0,0,0)
    ;
    uVar20 = FUN_fffffff00a4b68b4(lVar10,9,local_ad4,FUN_fffffff00a518d38,FUN_fffffff00a518c00);
    *(undefined8 *)(lVar10 + 0x570) = uVar20;
    FUN_fffffff00a50f57c(lVar10);
    uVar20 = 0;
  }
  else {
    FUN_fffffff00a8df19c
              (&MACH_HEADER,DAT_fffffff00ad7ce40,0x10,
               "%s: necp_client_add parameters copyin error (%d)\n");
LAB_fffffff00a507b80:
    uVar12 = *(undefined8 *)(lVar10 + 0x528);
    *(undefined8 *)(lVar10 + 0x528) = 0;
    *(undefined8 *)(lVar10 + 0x530) = 0x18;
    FUN_fffffff00a2212a8(&DAT_fffffff007c6afb0,uVar12,0x2a0);
    *(undefined8 *)(lVar10 + 0x530) = 0;
    *(undefined8 *)(lVar10 + 0x528) = 0;
    uVar13 = *(undefined8 *)(lVar10 + 0x5a0);
    uVar12 = *(undefined8 *)(lVar10 + 0x5a8);
    *(undefined8 *)(lVar10 + 0x5a8) = 0;
    *(undefined8 *)(lVar10 + 0x5a0) = 0;
    FUN_fffffff00a2212a8(&DAT_fffffff007c6afb0,uVar12,uVar13);
    uVar13 = *(undefined8 *)(lVar10 + 0x4b0);
    uVar12 = *(undefined8 *)(lVar10 + 0x4b8);
    *(undefined8 *)(lVar10 + 0x4b8) = 0;
    *(undefined8 *)(lVar10 + 0x4b0) = 0;
    FUN_fffffff00a2212a8(&DAT_fffffff007c6afb0,uVar12,uVar13);
    FUN_fffffff00a2261c0(lVar10 + 0x40,&DAT_fffffff00ad22e24);
    FUN_fffffff00a2261c0(puVar19,&DAT_fffffff00ad22e24);
    FUN_fffffff00a29762c(&DAT_fffffff007c73250,lVar10);
  }
  *param_4 = (int)uVar20;
LAB_fffffff00a507c10:
  if (DAT_fffffff00ad30000 == local_78) {
    return uVar20;
  }
                    /* WARNING: Subroutine does not return */
  FUN_fffffff00aa4c590();
}

