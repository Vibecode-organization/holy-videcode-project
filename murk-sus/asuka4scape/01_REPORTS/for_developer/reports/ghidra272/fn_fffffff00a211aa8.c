// FUN_fffffff00a211aa8 @ fffffff00a211aa8 size=2616

void FUN_fffffff00a211aa8
               (undefined8 param_1,undefined8 param_2,undefined8 *param_3,undefined4 param_4,
               ulong param_5,long param_6)

{
  uint uVar1;
  code *pcVar2;
  byte bVar3;
  int iVar4;
  long lVar5;
  undefined8 uVar6;
  long lVar7;
  char *pcVar8;
  uint uVar9;
  undefined4 uVar10;
  uint uVar11;
  undefined4 uVar12;
  uint uVar13;
  long lVar14;
  undefined8 *puVar15;
  undefined4 uVar16;
  undefined8 uVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  long lVar22;
  ulong uVar23;
  long *plVar24;
  int in_wzr;
  undefined1 auVar25 [16];
  undefined8 in_stack_ffffffffffffeaa0;
  undefined4 local_152c;
  undefined4 local_14fc;
  ulong local_14f8;
  undefined8 local_14f0;
  undefined8 uStack_14e8;
  undefined8 uStack_14e0;
  undefined8 uStack_14d8;
  undefined8 local_14d0;
  int local_14c4;
  undefined4 local_14c0;
  undefined4 uStack_14bc;
  undefined4 local_14b8;
  undefined4 uStack_14b4;
  undefined4 local_14b0;
  undefined4 uStack_14ac;
  undefined4 local_14a8;
  undefined4 uStack_14a4;
  undefined8 local_80;
  long local_78;
  
  uVar10 = (undefined4)((ulong)in_stack_ffffffffffffeaa0 >> 0x20);
  auVar25 = (*DAT_fffffff007c88d70)();
  local_78 = DAT_fffffff00ad30000;
  lVar5 = auVar25._0_8_;
  if ((*(byte *)(lVar5 + 0x42b) & 0x11) == 0) {
    uVar6 = 0;
    goto LAB_fffffff00a211f00;
  }
  uVar6 = 5;
  uVar9 = auVar25._8_4_;
  if ((0xd < uVar9) || (param_5 == 0)) goto LAB_fffffff00a211f00;
  plVar24 = (long *)(param_5 + (auVar25._8_8_ & 0xffffffff) * 0x20);
  if (((param_5 ^ (ulong)plVar24) & 0xffc0000000000000) != 0) {
    plVar24 = (long *)((ulong)plVar24 & 0xffffffffffff | 0xc8a2000000000000);
  }
  lVar22 = tpidr_el1;
  if (*(ulong *)(param_6 + 8) == 0) {
    *(ulong *)(param_6 + 8) = (ulong)*(uint *)(lVar22 + 0x4e8);
    lVar14 = *plVar24;
  }
  else {
    FUN_fffffff00a2262d4(param_6,lVar22,0);
    lVar14 = *plVar24;
  }
  if (lVar14 == 0) {
    lVar14 = 0;
  }
  if (1 < lVar14 + 1U) {
    if (DAT_fffffff007bc7030 == lVar14) {
      lVar14 = FUN_fffffff00a1f45e4(lVar14);
    }
    else {
      lVar14 = FUN_fffffff00a1f472c();
    }
  }
  if (lVar14 + 1U < 2) {
    if (*(int *)(param_6 + 8) == *(int *)(lVar22 + 0x4e8)) {
      *(int *)(param_6 + 8) = in_wzr;
    }
    else {
      FUN_fffffff00a226e08(param_6,lVar22);
    }
    uVar6 = 5;
    goto LAB_fffffff00a211f00;
  }
  local_80 = 0;
  lVar7 = FUN_fffffff00a29bafc(lVar5);
  local_14c4 = (int)plVar24[1];
  uVar1 = *(uint *)((long)plVar24 + 0xc);
  iVar4 = *(int *)((long)plVar24 + 0x14);
  uVar11 = 4;
  if (iVar4 != 0) {
    uVar11 = 0x804;
  }
  if (*(int *)(param_6 + 8) == *(int *)(lVar22 + 0x4e8)) {
    *(int *)(param_6 + 8) = in_wzr;
  }
  else {
    FUN_fffffff00a226e08(param_6,lVar22);
  }
  bVar3 = FUN_fffffff00a26bb90(lVar7);
  uVar12 = 0x11;
  if (iVar4 != 0) {
    uVar12 = 0x401;
  }
  uVar13 = 0x1c;
  if (iVar4 != 0) {
    uVar13 = 0xc0c;
  }
  if (((DAT_fffffff007bbc8c0 | bVar3) & 1) == 0) {
    uVar12 = 1;
    uVar13 = uVar11;
  }
  if (-1 < (int)uVar1) {
    local_80 = CONCAT44((int)param_3[1],(int)*param_3);
  }
  local_14d0 = 0;
  uStack_14e8 = 0;
  local_14f0 = 0;
  uStack_14d8 = 0;
  uStack_14e0 = 0;
  if (DAT_fffffff007bc7030 == lVar14) {
LAB_fffffff00a211ddc:
    uVar6 = FUN_fffffff00a29bafc(lVar22);
    iVar4 = FUN_fffffff00a2131cc(uVar6,lVar14);
    if (iVar4 == 0) {
      lVar7 = 0;
      lVar22 = 0;
      uVar6 = 0x35;
      goto LAB_fffffff00a211eb4;
    }
    uVar11 = uVar1 & 0x1fffffff;
    *(ushort *)(lVar5 + 200) = *(ushort *)(lVar5 + 200) | 0x8000;
    if (uVar11 < 3) {
      if (uVar11 == 1) {
        DAT_fffffff00ad33d00 = DAT_fffffff00ad33d00 + 1;
        FUN_fffffff00a2705d4(lVar7);
        FUN_fffffff00a275374(lVar5);
        if (((DAT_fffffff007c14eb8 == (byte *)0x0) || ((*DAT_fffffff007c14eb8 & 1) == 0)) &&
           (iVar4 = FUN_fffffff00a25f704(lVar7), iVar4 == 0)) {
          lVar22 = FUN_fffffff00a21c70c(lVar7,1,0);
          pcVar8 = (char *)FUN_fffffff00a21dba4(lVar5);
        }
        else {
          lVar22 = FUN_fffffff00a21c70c(lVar7,0,0);
          pcVar8 = (char *)FUN_fffffff00a21db70(lVar5);
        }
        if ((int)uVar1 < 0) {
          uVar6 = FUN_fffffff00a2a13ac(lVar14,pcVar8,lVar22,uVar9,param_3,param_4,&local_14f0);
        }
        else {
          uVar6 = FUN_fffffff00a29ef8c(lVar14,pcVar8,lVar22,uVar9,&local_80,param_4,&local_14f0);
        }
LAB_fffffff00a212270:
        lVar7 = 0;
        goto LAB_fffffff00a212278;
      }
      if (uVar11 != 2) {
LAB_fffffff00a21248c:
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa4d114("bad exception behavior! @%s:%d");
      }
      FUN_fffffff00aa65cc0(&local_14c0,0x1440);
      DAT_fffffff00ad33d18 = DAT_fffffff00ad33d18 + 1;
      if (local_14c4 < 0x32) {
        uVar10 = *(undefined4 *)((long)local_14c4 * 4 + -0xff52efd3c);
      }
      else {
        uVar10 = 0;
      }
      local_14f8 = CONCAT44(local_14f8._4_4_,uVar10);
      uVar6 = FUN_fffffff00a277538(lVar5,(long)local_14c4,&local_14c0,&local_14f8,uVar12);
      uVar23 = local_14f8 & 0xffffffff;
      local_14fc = (undefined4)local_14f8;
      if ((int)uVar6 == 0) {
        lVar7 = FUN_fffffff00a220c30(&DAT_fffffff007c6afb0,0x1440,4,0);
        if (lVar7 == 0) {
          uVar6 = 6;
        }
        else {
          if ((int)uVar1 < 0) {
            uVar6 = FUN_fffffff00a2a155c
                              (lVar14,uVar9,param_3,param_4,&local_14c4,&local_14c0,uVar23,lVar7,
                               &local_14fc,&local_14f0);
          }
          else {
            uVar6 = FUN_fffffff00a29f13c
                              (lVar14,uVar9,&local_80,param_4,&local_14c4,&local_14c0,uVar23,lVar7,
                               &local_14fc,&local_14f0);
          }
          if ((int)uVar6 == 0) {
            if (uVar9 == 0xd) {
              uVar6 = 0;
              lVar22 = 0;
              goto LAB_fffffff00a211eb4;
            }
            uVar6 = FUN_fffffff00a2777d4
                              (lVar5,local_14c4,lVar7,local_14fc,&local_14c0,local_14f8 & 0xffffffff
                               ,uVar13 | 1,&local_14f0);
          }
        }
      }
      else {
        lVar7 = 0;
      }
      lVar22 = 0;
      goto LAB_fffffff00a211eb4;
    }
    if (uVar11 != 3) {
      if (uVar11 == 4) {
        DAT_fffffff00ad33d08 = DAT_fffffff00ad33d08 + 1;
        iVar4 = FUN_fffffff00a29e2f8(lVar7,&local_14d0);
        if (((*(uint *)(lVar7 + 0x6b0) >> 4 & 1) != 0) || (iVar4 != 4)) {
          lVar22 = FUN_fffffff00a29e774(local_14d0);
          if (-1 < (int)uVar1) {
                    /* WARNING: Subroutine does not return */
            FUN_fffffff00aa4d114("mach_exception_raise_identity_protected() must be code64 @%s:%d");
          }
          uVar6 = FUN_fffffff00a2a1a6c
                            (lVar14,*(undefined8 *)(lVar5 + 0x4e0),lVar22,uVar9,param_3,param_4,
                             &local_14f0);
          lVar7 = 0;
          goto LAB_fffffff00a211eb4;
        }
LAB_fffffff00a21201c:
        lVar7 = 0;
        lVar22 = 0;
LAB_fffffff00a212024:
        uVar6 = 0;
      }
      else {
        if (uVar11 != 5) goto LAB_fffffff00a21248c;
        FUN_fffffff00aa65cc0(&local_14c0,0x1440);
        DAT_fffffff00ad33d10 = DAT_fffffff00ad33d10 + 1;
        iVar4 = FUN_fffffff00a29e2f8(lVar7,&local_14d0);
        if (((*(uint *)(lVar7 + 0x6b0) >> 4 & 1) == 0) && (iVar4 == 4)) goto LAB_fffffff00a21201c;
        lVar22 = FUN_fffffff00a29e774(local_14d0);
        local_14f8 = CONCAT44(local_14f8._4_4_,*(undefined4 *)((long)local_14c4 * 4 + -0xff52efd3c))
        ;
        uVar6 = FUN_fffffff00a277538(lVar5,(long)local_14c4,&local_14c0,&local_14f8,uVar12);
        uVar12 = (undefined4)local_14f8;
        local_14fc = (undefined4)local_14f8;
        if ((int)uVar6 == 0) {
          lVar7 = FUN_fffffff00a220c30(&DAT_fffffff007c6afb0,0x1440,4,0);
          if (lVar7 == 0) {
            uVar6 = 6;
          }
          else {
            if (-1 < (int)uVar1) {
                    /* WARNING: Subroutine does not return */
              FUN_fffffff00aa4d114
                        ("mach_exception_raise_state_identity_protected() must be code64 @%s:%d");
            }
            uVar6 = FUN_fffffff00a2a1d8c
                              (lVar14,*(undefined8 *)(lVar5 + 0x4e0),lVar22,uVar9,param_3,param_4,
                               &local_14c4,&local_14c0,CONCAT44(uVar10,uVar12),lVar7,&local_14fc,
                               &local_14f0);
            if ((int)uVar6 == 0) {
              if (uVar9 == 0xd) goto LAB_fffffff00a212024;
              uVar6 = FUN_fffffff00a2777d4
                                (lVar5,local_14c4,lVar7,local_14fc,&local_14c0,
                                 local_14f8 & 0xffffffff,uVar13 | 1,&local_14f0);
            }
          }
        }
        else {
          lVar7 = 0;
        }
      }
      goto LAB_fffffff00a211eb4;
    }
    FUN_fffffff00aa65cc0(&local_14c0,0x1440);
    DAT_fffffff00ad33d20 = DAT_fffffff00ad33d20 + 1;
    FUN_fffffff00a2705d4(lVar7);
    FUN_fffffff00a275374(lVar5);
    if (((DAT_fffffff007c14eb8 == (byte *)0x0) || ((*DAT_fffffff007c14eb8 & 1) == 0)) &&
       (iVar4 = FUN_fffffff00a25f704(lVar7), iVar4 == 0)) {
      lVar22 = FUN_fffffff00a21c70c(lVar7,1,0);
      pcVar8 = (char *)FUN_fffffff00a21dba4(lVar5);
    }
    else {
      lVar22 = FUN_fffffff00a21c70c(lVar7,0,0);
      pcVar8 = (char *)FUN_fffffff00a21db70(lVar5);
    }
    if (local_14c4 < 0x32) {
      uVar18 = *(undefined4 *)((long)local_14c4 * 4 + -0xff52efd3c);
    }
    else {
      uVar18 = 0;
    }
    local_14f8 = CONCAT44(local_14f8._4_4_,uVar18);
    uVar6 = FUN_fffffff00a277538(lVar5,(long)local_14c4,&local_14c0,&local_14f8,uVar12);
    uVar12 = (undefined4)local_14f8;
    local_14fc = (undefined4)local_14f8;
    if ((int)uVar6 != 0) goto LAB_fffffff00a212270;
    lVar7 = FUN_fffffff00a220c30(&DAT_fffffff007c6afb0,0x1440,4,0);
    if (lVar7 == 0) {
      uVar6 = 6;
    }
    else {
      if ((int)uVar1 < 0) {
        uVar6 = FUN_fffffff00a2a17b8
                          (lVar14,pcVar8,lVar22,uVar9,param_3,param_4,&local_14c4,&local_14c0,
                           CONCAT44(uVar10,uVar12),lVar7,&local_14fc,&local_14f0);
      }
      else {
        uVar6 = FUN_fffffff00a29f398
                          (lVar14,pcVar8,lVar22,uVar9,&local_80,param_4,&local_14c4,&local_14c0,
                           CONCAT44(uVar10,uVar12),lVar7,&local_14fc,&local_14f0);
      }
      if ((int)uVar6 == 0) {
        if ((uVar9 == 0xd) || (*pcVar8 != '\r')) {
          uVar6 = 0;
        }
        else {
          uVar6 = FUN_fffffff00a2777d4
                            (lVar5,local_14c4,lVar7,local_14fc,&local_14c0,local_14f8 & 0xffffffff,
                             uVar13 | 1,&local_14f0);
        }
      }
    }
LAB_fffffff00a212278:
    *(ushort *)(lVar5 + 200) = *(ushort *)(lVar5 + 200) & 0x7fff;
    if (lVar22 != 0) {
      FUN_fffffff00a1f4ae8(lVar22);
    }
    if (pcVar8 != (char *)0x0) {
      FUN_fffffff00a1f4ae8(pcVar8);
    }
    lVar22 = 0;
  }
  else {
    local_14f8 = 0;
    FUN_fffffff00a1f036c(lVar14);
    FUN_fffffff00a1f3fe4(lVar14,&local_14f8);
    if (local_14f8 == 0) {
      local_152c = 0xffffffff;
      uVar17 = 0xffffffff;
      uVar6 = 0xffffffff;
      uVar20 = 0xffffffff;
      uVar19 = 0xffffffff;
      uVar18 = 0xffffffff;
      uVar21 = 0xffffffff;
      uVar16 = 0xffffffff;
    }
    else {
      puVar15 = *(undefined8 **)(local_14f8 + 0x318);
      uVar17 = *puVar15;
      uVar6 = puVar15[1];
      local_152c = *(undefined4 *)(puVar15 + 2);
      uVar20 = (undefined4)((ulong)uVar17 >> 0x20);
      uVar19 = (undefined4)((ulong)uVar6 >> 0x20);
      uVar18 = *(undefined4 *)(puVar15 + 3);
      uVar21 = *(undefined4 *)((long)puVar15 + 0x14);
      uVar16 = *(undefined4 *)((long)puVar15 + 0x1c);
    }
    if ((*(byte *)(lVar14 + 2) & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0xbffc,0xfffffff00a212488);
      (*pcVar2)();
    }
    FUN_fffffff00a22b804(lVar14 + 0x14);
    uStack_14bc = (undefined4)uVar17;
    local_14c0 = local_152c;
    local_14b8 = (undefined4)uVar6;
    uStack_14b4 = uVar20;
    local_14b0 = uVar19;
    uStack_14ac = uVar18;
    local_14a8 = uVar21;
    uStack_14a4 = uVar16;
    iVar4 = FUN_fffffff00aa3cb40(lVar7,plVar24,uVar9,param_3,param_4,&local_14c0);
    if (iVar4 == 0) goto LAB_fffffff00a211ddc;
    lVar7 = 0;
    lVar22 = 0;
    uVar6 = 5;
LAB_fffffff00a211eb4:
    *(ushort *)(lVar5 + 200) = *(ushort *)(lVar5 + 200) & 0x7fff;
  }
  if (lVar14 != 0) {
    FUN_fffffff00a1f4ae8(lVar14);
  }
  if (lVar22 != 0) {
    FUN_fffffff00a1f4ae8(lVar22);
  }
  if (lVar7 != 0) {
    FUN_fffffff00a2212a8(&DAT_fffffff007c6afb0,lVar7,0x1440);
  }
LAB_fffffff00a211f00:
  if (DAT_fffffff00ad30000 != local_78) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff00aa4c590(uVar6);
  }
  return;
}

