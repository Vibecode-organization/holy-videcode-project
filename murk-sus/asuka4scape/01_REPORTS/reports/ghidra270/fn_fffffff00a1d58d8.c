// FUN_fffffff00a1d58d8 @ fffffff00a1d58d8 size=2384

void FUN_fffffff00a1d58d8
               (undefined8 param_1,undefined8 param_2,undefined8 *param_3,undefined4 param_4,
               ulong param_5,long param_6)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  undefined8 uVar6;
  long lVar7;
  char *pcVar8;
  uint uVar9;
  uint uVar10;
  undefined4 uVar11;
  uint uVar12;
  long lVar13;
  long lVar14;
  long lVar15;
  long *plVar16;
  int in_wzr;
  undefined1 auVar17 [16];
  undefined8 in_stack_ffffffffffffeae0;
  undefined4 uVar18;
  undefined4 local_14f8;
  undefined4 local_14f4;
  undefined8 local_14f0;
  undefined8 uStack_14e8;
  undefined8 uStack_14e0;
  undefined8 uStack_14d8;
  undefined8 local_14c8;
  int local_14bc;
  undefined1 auStack_14b8 [5184];
  undefined8 local_78;
  long local_70;
  
  uVar18 = (undefined4)((ulong)in_stack_ffffffffffffeae0 >> 0x20);
  auVar17 = (*DAT_fffffff007c7cae8)();
  local_70 = DAT_fffffff00acf0000;
  lVar5 = auVar17._0_8_;
  if ((*(byte *)(lVar5 + 0x42b) & 0x11) == 0) {
    uVar6 = 0;
    goto LAB_fffffff00a1d5c6c;
  }
  uVar6 = 5;
  uVar9 = auVar17._8_4_;
  if ((0xd < uVar9) || (param_5 == 0)) goto LAB_fffffff00a1d5c6c;
  plVar16 = (long *)(param_5 + (auVar17._8_8_ & 0xffffffff) * 0x20);
  if (((param_5 ^ (ulong)plVar16) & 0xffc0000000000000) != 0) {
    plVar16 = (long *)((ulong)plVar16 & 0xffffffffffff | 0xc8a2000000000000);
  }
  lVar14 = tpidr_el1;
  if (*(ulong *)(param_6 + 8) == 0) {
    *(ulong *)(param_6 + 8) = (ulong)*(uint *)(lVar14 + 0x4e8);
    lVar13 = *plVar16;
  }
  else {
    FUN_fffffff00a1ea02c(param_6,lVar14,0);
    lVar13 = *plVar16;
  }
  if (lVar13 == 0) {
    lVar13 = 0;
  }
  if (1 < lVar13 + 1U) {
    if (DAT_fffffff007bbb030 == lVar13) {
      lVar13 = FUN_fffffff00a1b8448(lVar13);
    }
    else {
      lVar13 = FUN_fffffff00a1b8590();
    }
  }
  if (lVar13 + 1U < 2) {
    if (*(int *)(param_6 + 8) == *(int *)(lVar14 + 0x4e8)) {
      *(int *)(param_6 + 8) = in_wzr;
    }
    else {
      FUN_fffffff00a1eab60(param_6,lVar14);
    }
    uVar6 = 5;
    goto LAB_fffffff00a1d5c6c;
  }
  local_78 = 0;
  lVar7 = FUN_fffffff00a25f6f4(lVar5);
  iVar4 = (int)plVar16[1];
  uVar1 = *(uint *)((long)plVar16 + 0xc);
  lVar15 = (long)iVar4;
  iVar3 = *(int *)((long)plVar16 + 0x14);
  uVar10 = 4;
  if (iVar3 != 0) {
    uVar10 = 0x804;
  }
  local_14bc = iVar4;
  if (*(int *)(param_6 + 8) == *(int *)(lVar14 + 0x4e8)) {
    *(int *)(param_6 + 8) = in_wzr;
  }
  else {
    FUN_fffffff00a1eab60(param_6,lVar14);
  }
  bVar2 = FUN_fffffff00a22f7ec(lVar7);
  uVar11 = 0x11;
  if (iVar3 != 0) {
    uVar11 = 0x401;
  }
  uVar12 = 0x1c;
  if (iVar3 != 0) {
    uVar12 = 0xc0c;
  }
  if (((DAT_fffffff007bb08c0 | bVar2) & 1) == 0) {
    uVar11 = 1;
    uVar12 = uVar10;
  }
  if (-1 < (int)uVar1) {
    local_78 = CONCAT44((int)param_3[1],(int)*param_3);
  }
  local_14c8 = 0;
  uStack_14e8 = 0;
  local_14f0 = 0;
  uStack_14d8 = 0;
  uStack_14e0 = 0;
  if ((DAT_fffffff007bbb030 == lVar13) || (iVar3 = FUN_fffffff00a9fbfb0(lVar7,plVar16), iVar3 == 0))
  {
    uVar6 = FUN_fffffff00a25f6f4(lVar14);
    iVar3 = FUN_fffffff00a1d6f14(uVar6,lVar13);
    if (iVar3 == 0) {
      lVar7 = 0;
      lVar14 = 0;
      uVar6 = 0x35;
      goto LAB_fffffff00a1d5c20;
    }
    uVar10 = uVar1 & 0x1fffffff;
    *(ushort *)(lVar5 + 200) = *(ushort *)(lVar5 + 200) | 0x8000;
    if (uVar10 < 3) {
      if (uVar10 == 1) {
        DAT_fffffff00acf3d00 = DAT_fffffff00acf3d00 + 1;
        FUN_fffffff00a234230(lVar7);
        FUN_fffffff00a238fd0(lVar5);
        if (((DAT_fffffff007c08e68 == (byte *)0x0) || ((*DAT_fffffff007c08e68 & 1) == 0)) &&
           (iVar4 = FUN_fffffff00a2233cc(lVar7), iVar4 == 0)) {
          lVar14 = FUN_fffffff00a1e0478(lVar7,1,0);
          pcVar8 = (char *)FUN_fffffff00a1e1910(lVar5);
        }
        else {
          lVar14 = FUN_fffffff00a1e0478(lVar7,0,0);
          pcVar8 = (char *)FUN_fffffff00a1e18dc(lVar5);
        }
        if ((int)uVar1 < 0) {
          uVar6 = FUN_fffffff00a264fa4(lVar13,pcVar8,lVar14,uVar9,param_3,param_4,&local_14f0);
        }
        else {
          uVar6 = FUN_fffffff00a262b84(lVar13,pcVar8,lVar14,uVar9,&local_78,param_4,&local_14f0);
        }
LAB_fffffff00a1d5fdc:
        lVar7 = 0;
        goto LAB_fffffff00a1d5fe4;
      }
      if (uVar10 != 2) {
LAB_fffffff00a1d61d4:
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa0c4f8("bad exception behavior! @%s:%d");
      }
      FUN_fffffff00aa24ee0(auStack_14b8,0x1440);
      DAT_fffffff00acf3d18 = DAT_fffffff00acf3d18 + 1;
      if (iVar4 < 0x32) {
        local_14f4 = *(undefined4 *)(lVar15 * 4 + -0xff532fd3c);
      }
      else {
        local_14f4 = 0;
      }
      uVar6 = FUN_fffffff00a23b194(lVar5,lVar15,auStack_14b8,&local_14f4,uVar11);
      uVar18 = local_14f4;
      local_14f8 = local_14f4;
      if ((int)uVar6 == 0) {
        lVar7 = FUN_fffffff00a1e4988(&DAT_fffffff007c5ee68,0x1440,4,0);
        if (lVar7 == 0) {
          uVar6 = 6;
        }
        else {
          if ((int)uVar1 < 0) {
            uVar6 = FUN_fffffff00a265154
                              (lVar13,uVar9,param_3,param_4,&local_14bc,auStack_14b8,uVar18,lVar7,
                               &local_14f8,&local_14f0);
          }
          else {
            uVar6 = FUN_fffffff00a262d34
                              (lVar13,uVar9,&local_78,param_4,&local_14bc,auStack_14b8,uVar18,lVar7,
                               &local_14f8,&local_14f0);
          }
          if ((int)uVar6 == 0) {
            if (uVar9 == 0xd) {
              uVar6 = 0;
              lVar14 = 0;
              goto LAB_fffffff00a1d5c20;
            }
            uVar6 = FUN_fffffff00a23b430
                              (lVar5,local_14bc,lVar7,local_14f8,auStack_14b8,local_14f4,uVar12 | 1,
                               &local_14f0);
          }
        }
      }
      else {
        lVar7 = 0;
      }
      lVar14 = 0;
      goto LAB_fffffff00a1d5c20;
    }
    if (uVar10 != 3) {
      if (uVar10 == 4) {
        DAT_fffffff00acf3d08 = DAT_fffffff00acf3d08 + 1;
        iVar4 = FUN_fffffff00a261ef0(lVar7,&local_14c8);
        if (((*(uint *)(lVar7 + 0x6b0) >> 4 & 1) != 0) || (iVar4 != 4)) {
          lVar14 = FUN_fffffff00a26236c(local_14c8);
          if (-1 < (int)uVar1) {
                    /* WARNING: Subroutine does not return */
            FUN_fffffff00aa0c4f8("mach_exception_raise_identity_protected() must be code64 @%s:%d");
          }
          uVar6 = FUN_fffffff00a265664
                            (lVar13,*(undefined8 *)(lVar5 + 0x4e0),lVar14,uVar9,param_3,param_4,
                             &local_14f0);
          lVar7 = 0;
          goto LAB_fffffff00a1d5c20;
        }
LAB_fffffff00a1d5d84:
        lVar7 = 0;
        lVar14 = 0;
LAB_fffffff00a1d5d8c:
        uVar6 = 0;
      }
      else {
        if (uVar10 != 5) goto LAB_fffffff00a1d61d4;
        FUN_fffffff00aa24ee0(auStack_14b8,0x1440);
        DAT_fffffff00acf3d10 = DAT_fffffff00acf3d10 + 1;
        iVar4 = FUN_fffffff00a261ef0(lVar7,&local_14c8);
        if (((*(uint *)(lVar7 + 0x6b0) >> 4 & 1) == 0) && (iVar4 == 4)) goto LAB_fffffff00a1d5d84;
        lVar14 = FUN_fffffff00a26236c(local_14c8);
        local_14f4 = *(undefined4 *)((long)local_14bc * 4 + -0xff532fd3c);
        uVar6 = FUN_fffffff00a23b194(lVar5,(long)local_14bc,auStack_14b8,&local_14f4,uVar11);
        uVar11 = local_14f4;
        local_14f8 = local_14f4;
        if ((int)uVar6 == 0) {
          lVar7 = FUN_fffffff00a1e4988(&DAT_fffffff007c5ee68,0x1440,4,0);
          if (lVar7 == 0) {
            uVar6 = 6;
          }
          else {
            if (-1 < (int)uVar1) {
                    /* WARNING: Subroutine does not return */
              FUN_fffffff00aa0c4f8
                        ("mach_exception_raise_state_identity_protected() must be code64 @%s:%d");
            }
            uVar6 = FUN_fffffff00a265984
                              (lVar13,*(undefined8 *)(lVar5 + 0x4e0),lVar14,uVar9,param_3,param_4,
                               &local_14bc,auStack_14b8,CONCAT44(uVar18,uVar11),lVar7,&local_14f8,
                               &local_14f0);
            if ((int)uVar6 == 0) {
              if (uVar9 == 0xd) goto LAB_fffffff00a1d5d8c;
              uVar6 = FUN_fffffff00a23b430
                                (lVar5,local_14bc,lVar7,local_14f8,auStack_14b8,local_14f4,
                                 uVar12 | 1,&local_14f0);
            }
          }
        }
        else {
          lVar7 = 0;
        }
      }
      goto LAB_fffffff00a1d5c20;
    }
    FUN_fffffff00aa24ee0(auStack_14b8,0x1440);
    DAT_fffffff00acf3d20 = DAT_fffffff00acf3d20 + 1;
    FUN_fffffff00a234230(lVar7);
    FUN_fffffff00a238fd0(lVar5);
    if (((DAT_fffffff007c08e68 == (byte *)0x0) || ((*DAT_fffffff007c08e68 & 1) == 0)) &&
       (iVar3 = FUN_fffffff00a2233cc(lVar7), iVar3 == 0)) {
      lVar14 = FUN_fffffff00a1e0478(lVar7,1,0);
      pcVar8 = (char *)FUN_fffffff00a1e1910(lVar5);
    }
    else {
      lVar14 = FUN_fffffff00a1e0478(lVar7,0,0);
      pcVar8 = (char *)FUN_fffffff00a1e18dc(lVar5);
    }
    if (iVar4 < 0x32) {
      local_14f4 = *(undefined4 *)(lVar15 * 4 + -0xff532fd3c);
    }
    else {
      local_14f4 = 0;
    }
    uVar6 = FUN_fffffff00a23b194(lVar5,lVar15,auStack_14b8,&local_14f4,uVar11);
    uVar11 = local_14f4;
    local_14f8 = local_14f4;
    if ((int)uVar6 != 0) goto LAB_fffffff00a1d5fdc;
    lVar7 = FUN_fffffff00a1e4988(&DAT_fffffff007c5ee68,0x1440,4,0);
    if (lVar7 == 0) {
      uVar6 = 6;
    }
    else {
      if ((int)uVar1 < 0) {
        uVar6 = FUN_fffffff00a2653b0
                          (lVar13,pcVar8,lVar14,uVar9,param_3,param_4,&local_14bc,auStack_14b8,
                           CONCAT44(uVar18,uVar11),lVar7,&local_14f8,&local_14f0);
      }
      else {
        uVar6 = FUN_fffffff00a262f90
                          (lVar13,pcVar8,lVar14,uVar9,&local_78,param_4,&local_14bc,auStack_14b8,
                           CONCAT44(uVar18,uVar11),lVar7,&local_14f8,&local_14f0);
      }
      if ((int)uVar6 == 0) {
        if ((uVar9 == 0xd) || (*pcVar8 != '\r')) {
          uVar6 = 0;
        }
        else {
          uVar6 = FUN_fffffff00a23b430
                            (lVar5,local_14bc,lVar7,local_14f8,auStack_14b8,local_14f4,uVar12 | 1,
                             &local_14f0);
        }
      }
    }
LAB_fffffff00a1d5fe4:
    *(ushort *)(lVar5 + 200) = *(ushort *)(lVar5 + 200) & 0x7fff;
    if (lVar14 != 0) {
      FUN_fffffff00a1b894c(lVar14);
    }
    if (pcVar8 != (char *)0x0) {
      FUN_fffffff00a1b894c(pcVar8);
    }
    lVar14 = 0;
  }
  else {
    lVar7 = 0;
    lVar14 = 0;
    uVar6 = 5;
LAB_fffffff00a1d5c20:
    *(ushort *)(lVar5 + 200) = *(ushort *)(lVar5 + 200) & 0x7fff;
  }
  if (lVar13 != 0) {
    FUN_fffffff00a1b894c(lVar13);
  }
  if (lVar14 != 0) {
    FUN_fffffff00a1b894c(lVar14);
  }
  if (lVar7 != 0) {
    FUN_fffffff00a1e5000(&DAT_fffffff007c5ee68,lVar7,0x1440);
  }
LAB_fffffff00a1d5c6c:
  if (DAT_fffffff00acf0000 != local_70) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff00aa0b974(uVar6);
  }
  return;
}

