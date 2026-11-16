// FUN_fffffff00a717c1c @ fffffff00a717c1c size=2824

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fffffff00a717c1c(long *param_1,uint param_2,int param_3)

{
  ushort uVar1;
  long lVar2;
  code *pcVar3;
  bool bVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  undefined8 uVar9;
  undefined4 uVar10;
  char *pcVar11;
  uint uVar12;
  long *plVar13;
  ulong uVar14;
  long lVar15;
  long *plVar16;
  long lVar17;
  ulong uVar18;
  long lVar19;
  long lVar20;
  ulong uVar21;
  undefined8 uVar22;
  int iVar23;
  int in_wzr;
  undefined8 in_stack_fffffffffffffec0;
  undefined4 uVar24;
  uint local_104;
  ulong local_100;
  ulong local_f8;
  undefined8 local_f0;
  long lStack_e8;
  undefined8 uStack_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 uStack_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  long local_70;
  
  uVar24 = (undefined4)((ulong)in_stack_fffffffffffffec0 >> 0x20);
  local_70 = DAT_fffffff00ad30000;
  lVar2 = tpidr_el1;
  plVar16 = (long *)0x0;
  if ((*(byte *)(param_1 + 0x89) & 2) != 0) {
    plVar16 = param_1 + 0xed;
  }
  if (*(byte *)((long)param_1 + 0x6ca) == 0) {
    if ((DAT_fffffff00ad95888 != (long *)0x0) && (param_1 == DAT_fffffff00ad95888))
    goto LAB_fffffff00a717c8c;
  }
  else {
    if (DAT_fffffff00ad95888 != (long *)0x0) {
LAB_fffffff00a717c8c:
      if (param_1 == DAT_fffffff00ad95888) goto LAB_fffffff00a717f28;
    }
    if ((DAT_fffffff007c07b48 & 1) == 0) {
      if ((*(byte *)((long)param_1 + 0x6ca) & 0xc) != 0) goto LAB_fffffff00a717f28;
      if (((*(byte *)((long)param_1 + 0x6cb) & 1) == 0) &&
         ((param_1[0xe9] == 0 ||
          (uVar21 = UnkSytemRegRead(3,4,0xf,10,6), uVar21 <= (ulong)param_1[0xe9])))) {
        uVar5 = param_2 & 0x7f;
        if ((param_2 & 0x7f) == 0) {
          if ((0xff < param_2) && ((*(byte *)((long)param_1 + 0x6ca) >> 1 & 1) != 0))
          goto LAB_fffffff00a717f28;
        }
        else {
          if (uVar5 == 0x7f) goto LAB_fffffff00a717f28;
          if ((*(byte *)((long)param_1 + 0x6ca) & 1) != 0) {
            lVar17 = param_1[0xeb];
            if (lVar17 != 0) {
              if ((*(ulong *)(lVar17 + 0x20) & 0x201) == 1) goto LAB_fffffff00a717d58;
              if (*(int *)(lVar17 + 0x14) != 2) goto LAB_fffffff00a717f28;
              uVar5 = *(uint *)(lVar17 + 0x18);
            }
            if ((uVar5 < 0xd) && ((1 << (ulong)(uVar5 & 0x1f) & 0x1d70U) != 0)) {
LAB_fffffff00a717f28:
              FUN_fffffff00a717518(param_1[0xeb]);
              uStack_88 = 0;
              local_90 = 0;
              uStack_78 = 0;
              uStack_80 = 0;
              uStack_a8 = 0;
              local_b0 = 0;
              uStack_98 = 0;
              uStack_a0 = 0;
              uStack_c8 = 0;
              local_d0 = 0;
              uStack_b8 = 0;
              uStack_c0 = 0;
              lStack_e8 = 0;
              local_f0 = (long *)0x0;
              uStack_d8 = 0;
              uStack_e0 = 0;
              if ((DAT_fffffff00ad95888 == (long *)0x0) || (param_1 != DAT_fffffff00ad95888)) {
                FUN_fffffff00a76d3ec(&local_f0,0x80,"%s[%d] exited");
              }
              else {
                FUN_fffffff00a354a0c((long)param_1 + 0x56d,"preinit",0x21);
              }
              do {
                FUN_fffffff00a3fccd4();
                if (param_1[0xeb] == 0) {
                  FUN_fffffff00a7266f8(param_1);
                  pcVar11 = "%s -- no exit reason available -- (signal %d, exit status %d %s)";
                }
                else {
                  FUN_fffffff00a7266f8(param_1);
                  pcVar11 = "%s %s -- exit reason namespace %d subcode 0x%llx description: %.800s";
                }
                FUN_fffffff00aa4d1d0(0,0,0x2020,pcVar11);
              } while( true );
            }
          }
        }
      }
    }
  }
LAB_fffffff00a717d58:
  if (plVar16 == (long *)0x0) {
    uVar5 = 0;
    lVar17 = param_1[0xeb];
    if (lVar17 != 0) goto LAB_fffffff00a717d9c;
LAB_fffffff00a717da4:
    param_2 = param_2 & 0x7f;
    if ((((*(byte *)((ulong)param_2 * 4 + -0xff52ea958) >> 1 & 1) == 0) &&
        (uVar6 = FUN_fffffff00a7266f8(param_1), (uVar6 >> 0x18 & 1) == 0)) &&
       ((param_1[0xeb] == 0 || ((*(byte *)(param_1[0xeb] + 0x20) >> 1 & 1) == 0))))
    goto LAB_fffffff00a717ef8;
    if (param_2 == 0xb) {
      uVar6 = _DAT_00000e10;
      if (param_1[2] != 0) {
        uVar6 = *(uint *)(param_1[2] + 0xe10);
      }
      if ((uVar6 >> 9 & 1) != 0) goto LAB_fffffff00a717ef8;
    }
    uVar6 = *(uint *)(lVar2 + 0x5dc);
    uVar21 = (ulong)(param_2 << 0x18 | (uVar6 & 0xf) << 0x14 | *(uint *)(lVar2 + 0x5e0) & 0xfffff);
    uVar22 = *(undefined8 *)(lVar2 + 0x5e8);
    local_104 = 10;
    if (0xfffffffd < uVar6 - 0xd) {
      local_104 = uVar6;
    }
    uVar1 = *(ushort *)(lVar2 + 200);
    *(ushort *)(lVar2 + 200) = uVar1 & 0xfffc;
    local_f0 = (long *)uVar21;
    lStack_e8 = uVar22;
    iVar7 = FUN_fffffff00a212bd0(10,&local_f0,2,0);
    bVar4 = false;
    *(ushort *)(lVar2 + 200) = *(ushort *)(lVar2 + 200) & 0xfffc | uVar1 & 3;
    if (iVar7 != 0 || (uVar5 & 1) != 0) {
      lVar17 = FUN_fffffff00a29b24c();
      plVar13 = *(long **)(lVar17 + 0x18);
      if (*(long **)(lVar17 + 0x18) == (long *)0x0) {
        plVar13 = DAT_fffffff007c6b250;
      }
      bVar4 = param_1 == plVar13;
    }
    local_100 = 0;
    local_f8 = 0;
    lStack_e8 = 0;
    local_f0 = (long *)0x0;
    uStack_d8 = 0;
    uStack_e0 = 0;
    uVar6 = FUN_fffffff00a2061cc(&local_100,2,0,&local_f0);
    uVar14 = local_100;
    lVar17 = lStack_e8;
    if ((local_f0._4_4_ == 0) && (uVar6 != 0)) {
      iVar7 = FUN_fffffff00a2dc0d0(plVar16,local_100);
      if (iVar7 == 0) {
        lVar17 = plVar16[5];
        if ((lVar17 == 0) || (lVar17 == 0)) {
          uVar12 = 0xe;
        }
        else {
          uVar12 = (uint)*(byte *)(lVar17 + 0x2c);
        }
        iVar7 = FUN_fffffff00a2dc0d0(plVar16,uVar14 - (uint)(1 << (ulong)(uVar12 & 0x1f)));
        if ((iVar7 == 0) && (1 < uVar6)) {
          uVar14 = uVar14 >> 0xe;
          lVar17 = lStack_e8;
          if ((uVar14 == local_f8 >> 0xe) || (uVar14 - 1 == local_f8 >> 0xe))
          goto joined_r0xfffffff00a718038;
          iVar7 = FUN_fffffff00a2dc0d0(plVar16);
        }
        lVar17 = lStack_e8;
        if (iVar7 == 0) goto joined_r0xfffffff00a718038;
      }
      uVar24 = 0;
      FUN_fffffff00a8df19c
                (&MACH_HEADER,&DAT_fffffff00ad98ba0,0,
                 "Text page corruption detected in dying process %d\n");
      lVar17 = lStack_e8;
    }
  }
  else {
    lVar17 = plVar16[5];
    if (lVar17 == 0) {
      lVar17 = 0;
    }
    uVar5 = FUN_fffffff00a2f9488(lVar17);
    lVar17 = param_1[0xeb];
    if (lVar17 == 0) goto LAB_fffffff00a717da4;
LAB_fffffff00a717d9c:
    if ((*(byte *)(lVar17 + 0x20) & 1) == 0) goto LAB_fffffff00a717da4;
LAB_fffffff00a717ef8:
    uVar21 = 0;
    uVar22 = 0;
    bVar4 = false;
    local_104 = 0;
    lVar17 = lStack_e8;
  }
joined_r0xfffffff00a718038:
  if (((plVar16 != (long *)0x0) && ((param_1[0x182] & 0xf000000000000U) == 0x7000000000000)) &&
     (lStack_e8 = param_1[0xeb], lStack_e8 != 0)) {
    local_f0 = plVar16;
    FUN_fffffff00a89694c(&DAT_fffffff00ad98190,FUN_fffffff00a9d2278,&local_f0);
    lVar17 = lStack_e8;
  }
  lStack_e8 = lVar17;
  if (param_3 != 0) {
    if (param_1 == DAT_fffffff007c6b250) {
      uVar10 = 0;
    }
    else {
      uVar10 = (undefined4)param_1[0xc];
    }
    FUN_fffffff00a212e94(lVar2,uVar10);
  }
  if (bVar4) {
    iVar7 = FUN_fffffff00a263170(plVar16);
    bVar4 = iVar7 != 0;
    if ((bVar4 & uVar5) != 0) {
LAB_fffffff00a71812c:
      lVar17 = plVar16[5];
      if (lVar17 == 0) {
        lVar17 = 0;
      }
      FUN_fffffff00a2f95b8(lVar17);
      goto LAB_fffffff00a718150;
    }
    if ((*(uint *)((long)param_1 + 0x454) >> 5 & 1) != 0) goto LAB_fffffff00a71815c;
LAB_fffffff00a7180cc:
    lVar17 = FUN_fffffff00a2216c4(&DAT_fffffff007c78a50,0);
    FUN_fffffff00a7359b0(param_1,lVar17 + 0x90,6);
    *(undefined8 *)(lVar17 + 0xd8) = 0;
    lVar20 = *(long *)(*(long *)(lVar2 + 0x1b8) + 0x58);
    do {
      lVar19 = lVar20;
      lVar15 = UnkSytemRegRead(3,4,0xf,10,6);
      lVar20 = *(long *)(*(long *)(lVar2 + 0x1b8) + 0x58);
    } while (lVar20 != lVar19);
    *(long *)(lVar17 + 0xe8) = lVar15 + lVar19;
    param_1[0xbe] = lVar17;
  }
  else {
    if (uVar5 != 0) goto LAB_fffffff00a71812c;
LAB_fffffff00a718150:
    bVar4 = true;
    if ((*(uint *)((long)param_1 + 0x454) >> 5 & 1) == 0) goto LAB_fffffff00a7180cc;
LAB_fffffff00a71815c:
    lVar17 = 0;
  }
  if (!bVar4) {
    iVar7 = FUN_fffffff00a7059d8(param_1,0,0);
    if (iVar7 < 1) {
      lVar20 = 0;
      iVar23 = 0;
LAB_fffffff00a7181dc:
      iVar8 = 0;
      if ((*(byte *)((long)param_1 + 1099) >> 4 & 1) != 0) goto LAB_fffffff00a7181c8;
LAB_fffffff00a7181e8:
      lVar15 = param_1[0xeb];
    }
    else {
      iVar7 = iVar7 + 0x20;
      iVar23 = iVar7 * 8;
      lVar20 = FUN_fffffff00a220c30(&DAT_fffffff007c6afb0,iVar23,0,0);
      if (lVar20 == 0) goto LAB_fffffff00a7181dc;
      iVar8 = FUN_fffffff00a7059d8(param_1,lVar20,iVar23);
      if (iVar7 <= iVar8) {
        iVar8 = iVar7;
      }
      if ((*(byte *)((long)param_1 + 1099) >> 4 & 1) == 0) goto LAB_fffffff00a7181e8;
LAB_fffffff00a7181c8:
      if (lVar2 == 0) {
        uVar9 = 0;
      }
      else {
        uVar9 = *(undefined8 *)(lVar2 + 0x4e0);
      }
      FUN_fffffff00a6db8c0(uVar9,0x10000f0,0);
      lVar15 = param_1[0xeb];
    }
    if ((lVar15 != 0) && (*(int *)(lVar15 + 0x14) == 1)) {
      if (*(long *)(lVar15 + 0x18) == 0x10) {
        uVar14 = 0;
        if ((param_1[0x151] != 0) && (DAT_fffffff007bf17b8 != 0)) {
          if ((DAT_fffffff007bf17b8 & 0x60000000) == 0) {
            uVar14 = 0xffff;
          }
          else {
            uVar14 = *(ulong *)(param_1[0x151] + (ulong)(ushort)DAT_fffffff007bf17b8 + 0x18) >> 0x14
                     & 0xffff;
          }
        }
        uVar18 = 0x6c00000000020000;
      }
      else {
        if (*(long *)(lVar15 + 0x18) != 7) goto LAB_fffffff00a7182e0;
        uVar14 = 0;
        if ((param_1[0x151] != 0) && (DAT_fffffff007bf17c8 != 0)) {
          if ((DAT_fffffff007bf17c8 & 0x60000000) == 0) {
            uVar14 = 0xffff;
          }
          else {
            uVar14 = *(ulong *)(param_1[0x151] + (ulong)(ushort)DAT_fffffff007bf17c8 + 0x18) >> 0x14
                     & 0xffff;
          }
        }
        uVar18 = 0x6400000000020000;
      }
      uVar22 = 0;
      uVar21 = uVar21 | uVar14 | uVar18;
    }
LAB_fffffff00a7182e0:
    FUN_fffffff00a714e0c
              (param_1,plVar16,lVar17,uVar21,uVar22,lVar20,iVar8,0,CONCAT44(uVar24,local_104));
    FUN_fffffff00a2212a8(&DAT_fffffff007c6afb0,lVar20,iVar23);
  }
  uVar21 = (ulong)*(uint *)(lVar2 + 0x4e8);
  if (_DAT_fffffff00ad8a320 != 0) {
    FUN_fffffff00a2262d4(&DAT_fffffff00ad8a318,lVar2,0);
    uVar21 = _DAT_fffffff00ad8a320;
  }
  while (_DAT_fffffff00ad8a320 = uVar21, iVar7 = FUN_fffffff00a74f25c(param_1), iVar7 == 0x23) {
    FUN_fffffff00a8df19c
              (&MACH_HEADER,&DAT_fffffff00ad98ba0,0,
               "memorystatus_remove: Process[%d] tried to exit while being frozen. Blocking exit until freeze completes."
              );
    FUN_fffffff00a73ed8c(param_1 + 0xda,0x20,"proc_memorystatus_remove",0,0,&DAT_fffffff00ad8a318);
    uVar21 = _DAT_fffffff00ad8a320;
  }
  lVar17 = *param_1;
  if (lVar17 == 0) {
    plVar16 = (long *)param_1[1];
    if ((long *)*plVar16 != param_1) goto LAB_fffffff00a7185c8;
    lVar17 = 0;
  }
  else {
    if (*(long **)(lVar17 + 8) != param_1) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00a718620);
      (*pcVar3)();
    }
    if (*(long **)param_1[1] != param_1) {
LAB_fffffff00a7185c8:
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00a7185d0);
      (*pcVar3)();
    }
    *(undefined8 **)(lVar17 + 8) = (undefined8 *)param_1[1];
    lVar17 = *param_1;
    plVar16 = (long *)param_1[1];
  }
  *plVar16 = lVar17;
  if (DAT_fffffff00ad94648 == (long *)0x0) {
    *param_1 = 0;
  }
  else {
    if ((long **)*(undefined8 **)((long)DAT_fffffff00ad94648 + 8) != &DAT_fffffff00ad94648) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00a718624);
      (*pcVar3)();
    }
    *param_1 = (long)DAT_fffffff00ad94648;
    *(long **)((long)DAT_fffffff00ad94648 + 8) = param_1;
  }
  DAT_fffffff00ad94648 = param_1;
  param_1[1] = (long)&DAT_fffffff00ad94648;
  *(uint *)((long)param_1 + 0x454) = *(uint *)((long)param_1 + 0x454) | 2;
  if (DAT_fffffff00ad8a320 == *(int *)(lVar2 + 0x4e8)) {
    _DAT_fffffff00ad8a320 = CONCAT44(DAT_fffffff00ad8a320_4,in_wzr);
  }
  else {
    FUN_fffffff00a226e08(&DAT_fffffff00ad8a318,lVar2);
  }
  if (param_1[0xb] == 0) {
    param_1[0xb] = (ulong)*(uint *)(lVar2 + 0x4e8);
  }
  else {
    FUN_fffffff00a2262d4(param_1 + 10,lVar2,0);
  }
  *(uint *)(param_1 + 0x1c2) = *(uint *)(param_1 + 0x1c2) & 0xffffff7f;
  *(uint *)(param_1 + 0x89) = *(uint *)(param_1 + 0x89) & 0xfffffbff;
  *(undefined4 *)((long)param_1 + 0x54c) = 0xfffefeff;
  if (*(byte *)((long)param_1 + 0xe09) < 5) {
    *(undefined1 *)((long)param_1 + 0xe09) = 5;
    *(uint *)(param_1 + 0x89) = *(uint *)(param_1 + 0x89) | 4;
  }
  else {
    plVar16 = param_1 + 0xa0;
    uVar21 = ((ulong)plVar16 ^ (ulong)plVar16 >> 0x1f) * 0x7fb5d329728ea185;
    lVar17 = (uVar21 ^ uVar21 >> 0x1b) * -0x7e25210b43d22bb3;
    uVar21 = DAT_fffffff007bc7040 +
             (ulong)(DAT_fffffff007bc7048 - 1U & ((uint)((ulong)lVar17 >> 0x21) ^ (uint)lVar17)) *
             0x18;
    if (((DAT_fffffff007bc7040 ^ uVar21) & 0xffc0000000000000) != 0) {
      uVar21 = uVar21 & 0xffffffffffff | 0xc8a2000000000000;
    }
    FUN_fffffff00a28c5d4(uVar21,plVar16,0,0,0xffffffff);
  }
  lVar17 = FUN_fffffff00a29b24c();
  plVar16 = DAT_fffffff007c6b250;
  if (*(long **)(lVar17 + 0x18) != (long *)0x0) {
    plVar16 = *(long **)(lVar17 + 0x18);
  }
  if (param_1 == plVar16) {
    *(undefined4 *)(lVar2 + 0x684) = 0;
  }
  if ((int)param_1[0xb] == *(int *)(lVar2 + 0x4e8)) {
    *(int *)(param_1 + 0xb) = in_wzr;
  }
  else {
    FUN_fffffff00a226e08(param_1 + 10,lVar2);
  }
  if (DAT_fffffff00ad30000 != local_70) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff00aa4c590();
  }
  return;
}

