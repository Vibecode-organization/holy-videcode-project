// FUN_fffffff00a2da81c @ fffffff00a2da81c size=3624

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_fffffff00a2da81c
              (undefined8 *param_1,long param_2,ulong param_3,ulong *param_4,long *param_5,
              long param_6,ulong param_7,ulong param_8)

{
  long *plVar1;
  ulong uVar2;
  undefined8 uVar3;
  ushort uVar4;
  ushort uVar5;
  long lVar6;
  int iVar7;
  undefined8 uVar8;
  ulong uVar9;
  undefined8 *puVar10;
  undefined8 uVar11;
  ulong uVar12;
  uint uVar13;
  undefined8 *puVar14;
  uint uVar15;
  ulong uVar16;
  ulong uVar17;
  long lVar18;
  undefined8 *puVar19;
  undefined4 in_wzr;
  ulong in_stack_fffffffffffffe80;
  undefined4 uVar20;
  long local_150;
  ulong local_118;
  ulong local_110;
  ulong uStack_108;
  undefined8 local_100;
  ulong local_f8;
  long local_f0;
  undefined8 uStack_e8;
  ulong local_e0;
  ulong local_d8;
  undefined8 local_d0;
  ulong uStack_c8;
  long lStack_c0;
  undefined8 local_b8;
  int local_a4;
  undefined8 local_a0;
  long local_98;
  undefined8 *local_90;
  undefined4 local_84;
  undefined8 local_80;
  long local_78;
  byte local_69 [9];
  
  uVar5 = 0;
  local_150 = 0;
  local_80 = 0;
  local_78 = 0;
  local_d8 = 0;
  uStack_c8 = param_3 & 0xffffffffffffc000;
  uVar17 = *param_4;
  lStack_c0 = uVar17 + uStack_c8;
  local_f8 = param_7 & 0xffffffffffffc000;
  local_f0 = uVar17 + local_f8;
  uStack_108 = 0;
  local_e0 = param_8 & 0xffffffff;
  local_d0 = 2;
  local_b8 = 2;
  local_110 = param_8 & 0xffffffff;
  local_100 = 2;
  uStack_e8 = 2;
  local_84 = 0;
  local_98 = 0;
  local_90 = (undefined8 *)0x0;
  local_a0 = 0;
  local_a4 = 0;
  local_118 = param_3;
LAB_fffffff00a2da8c4:
  uVar16 = param_1[2];
  FUN_fffffff00a34a93c(param_1,1);
  uVar9 = 0xffffc000;
  if (uVar17 >> 0x20 == 0) {
    uVar9 = uVar17 & 0xffffffff;
  }
  lVar6 = tpidr_el1;
  do {
    while( true ) {
      uVar20 = (undefined4)(in_stack_fffffffffffffe80 >> 0x20);
      local_a0 = CONCAT44(3,(int)local_a0);
      *(int *)(lVar6 + 0x1c0) = *(int *)(lVar6 + 0x1c0) + 1;
      lVar18 = *(long *)(lVar6 + 0x1b0) >> 0x10;
      plVar1 = (long *)(&DAT_fffffff00ad28260 + lVar18);
      if (*plVar1 == 0) {
        puVar14 = *(undefined8 **)(&DAT_fffffff00ad28268 + lVar18);
        if (puVar14 == (undefined8 *)0x0) {
          *plVar1 = 0;
        }
        else {
          *(undefined8 *)(&DAT_fffffff00ad28268 + lVar18) = *puVar14;
          *puVar14 = 0;
          *plVar1 = (long)puVar14;
          if (puVar14 < DAT_fffffff007bf0010 || DAT_fffffff007bf0008 <= puVar14) {
            uVar15 = *(uint *)((long)puVar14 + 0x3c);
          }
          else {
            uVar15 = DAT_fffffff007bf0000 +
                     (int)((ulong)((long)puVar14 - (long)DAT_fffffff007bf0010) >> 6);
          }
          FUN_fffffff00a38dfd0((ulong)uVar15 << 0xe,0x4000);
          plVar1 = (long *)(_DAT_fffffff00ad0e4f8 + (ulong)*(ushort *)(lVar6 + 0x1b0) * 0x4000);
          *plVar1 = *plVar1 + 1;
        }
      }
      if (*(int *)(lVar6 + 0x1c0) == 0) goto LAB_fffffff00a2db518;
      lVar18 = *(long *)(&DAT_fffffff00ad28268 + lVar18);
      iVar7 = *(int *)(lVar6 + 0x1c0) + -1;
      *(int *)(lVar6 + 0x1c0) = iVar7;
      if ((iVar7 == 0) && ((*(byte *)(*(long *)(lVar6 + 0x1b8) + 0x4c) >> 2 & 1) != 0)) {
        FUN_fffffff00a3976a4();
      }
      if (lVar18 == 0) {
        FUN_fffffff00a32d064(10);
      }
      FUN_fffffff00a3061bc(param_6);
      uVar15 = *(ushort *)(param_6 + 0x6c) + 1;
      *(short *)(param_6 + 0x6c) = (short)uVar15;
      if (uVar15 >> 0x10 != 0) goto LAB_fffffff00a2db554;
      local_90 = (undefined8 *)0x0;
      in_stack_fffffffffffffe80 =
           CONCAT44(uVar20,*(uint *)(uVar16 + 0xf8) >> 1) & 0xffffffff00000001;
      uStack_108 = uVar9;
      iVar7 = FUN_fffffff00a2d5330
                        (param_6,param_7 & 0xffffffffffffc000,3,0,0,(long)&local_a0 + 4,&local_90,
                         &local_98,0,&local_a0,in_stack_fffffffffffffe80,&local_110,param_1);
      if (iVar7 < 3) break;
      if (iVar7 != 3) {
        if (iVar7 == 5) goto LAB_fffffff00a2db3b0;
        if (iVar7 != 6) goto LAB_fffffff00a2db560;
        uVar5 = *(ushort *)(param_6 + 0x6c);
        uVar15 = uVar5 - 1;
        *(short *)(param_6 + 0x6c) = (short)uVar15;
        if (0xffff < uVar15) goto LAB_fffffff00a2db5f8;
        uVar15 = uVar15 & 0xffff;
        uVar13 = *(uint *)(param_6 + 0x74);
        if (((uVar13 >> 0xc & 1) == 0) &&
           (((*(byte *)(param_6 + 0xa9) & (uint)uVar5 == (uint)DAT_fffffff007bccab0) != 0 ||
            (DAT_fffffff007bccab2 == uVar5)))) {
          if ((uVar13 >> 6 & 1) != 0) {
            plVar1 = (long *)(_DAT_fffffff00ad0e458 + (ulong)*(ushort *)(lVar6 + 0x1b0) * 0x4000);
            lVar6 = *plVar1;
            *plVar1 = lVar6 + 1;
            FUN_fffffff00a24a024(lVar6,param_6 + 6,0,0);
            uVar13 = *(uint *)(param_6 + 0x74);
            uVar15 = (uint)*(ushort *)(param_6 + 0x6c);
          }
          uVar13 = uVar13 & 0xffffffbf;
          *(uint *)(param_6 + 0x74) = uVar13;
        }
        if (uVar15 == 0) {
          if ((uVar13 >> 5 & 1) != 0) {
            FUN_fffffff00a24a024(param_6 + 5,0,0);
            uVar13 = *(uint *)(param_6 + 0x74);
          }
          uVar15 = uVar13 & 0xffffffdf;
          *(uint *)(param_6 + 0x74) = uVar15;
          if (*(int *)(param_6 + 0x70) == 0) {
            if ((uVar13 >> 2 & 1) != 0) {
              FUN_fffffff00a24a024(param_6 + 2,0,0);
              uVar15 = *(uint *)(param_6 + 0x74);
            }
            *(uint *)(param_6 + 0x74) = uVar15 & 0xfffffffb;
          }
        }
        FUN_fffffff00a22aeac(param_6 + 8);
        goto LAB_fffffff00a2db3b0;
      }
      iVar7 = FUN_fffffff00a32d760(param_8);
      if (iVar7 == 0) {
        if (lVar6 == 0) {
          uVar11 = 0;
        }
        else {
          uVar11 = *(undefined8 *)(lVar6 + 0x4e0);
        }
        FUN_fffffff00a6db8c0(uVar11,0x1000018,0);
        local_a4 = 0x10000007;
        goto LAB_fffffff00a2db3f4;
      }
    }
  } while (iVar7 == 1);
  if (iVar7 == 0) {
    uVar11 = *(undefined8 *)(param_6 + 0x38);
    uVar3 = *(undefined8 *)(param_6 + 0x40);
    *(int *)(lVar6 + 0x1c0) = *(int *)(lVar6 + 0x1c0) + 1;
    uVar12 = (ulong)*(uint *)(lVar6 + 0x4e8) | 0x30000000;
    if (DAT_fffffff00ad6d188 != 0) {
      FUN_fffffff00a2262d4(&DAT_fffffff00ad6d180,lVar6,1);
      uVar12 = DAT_fffffff00ad6d188;
    }
    DAT_fffffff00ad6d188 = uVar12;
    puVar14 = local_90;
    uVar8 = FUN_fffffff00a329420(local_90,1,1);
    if ((int)DAT_fffffff00ad6d188 == *(int *)(lVar6 + 0x4e8)) {
      DAT_fffffff00ad6d188 = CONCAT44(DAT_fffffff00ad6d188._4_4_,in_wzr);
    }
    else {
      uVar8 = FUN_fffffff00a226e08(&DAT_fffffff00ad6d180,lVar6);
    }
    FUN_fffffff00a30a920(uVar8,puVar14);
    FUN_fffffff00a22aeac(param_6 + 8);
    lVar18 = local_98;
    if (local_98 != 0) {
      FUN_fffffff00a3061bc(param_6);
      FUN_fffffff00a329e50(lVar18);
      uVar4 = *(ushort *)(param_6 + 0x6c);
      uVar15 = uVar4 - 1;
      *(short *)(param_6 + 0x6c) = (short)uVar15;
      if (0xffff < uVar15) {
LAB_fffffff00a2db5f8:
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa4d114("vm_object_paging_end(%p): underflow\n @%s:%d");
      }
      uVar15 = uVar15 & 0xffff;
      uVar13 = *(uint *)(param_6 + 0x74);
      if (((uVar13 >> 0xc & 1) == 0) &&
         (((*(byte *)(param_6 + 0xa9) & (uint)uVar4 == (uint)DAT_fffffff007bccab0) != 0 ||
          (DAT_fffffff007bccab2 == uVar4)))) {
        if ((uVar13 >> 6 & 1) != 0) {
          plVar1 = (long *)(_DAT_fffffff00ad0e458 + (ulong)*(ushort *)(lVar6 + 0x1b0) * 0x4000);
          lVar18 = *plVar1;
          *plVar1 = lVar18 + 1;
          FUN_fffffff00a24a024(lVar18,param_6 + 6,0,0);
          uVar13 = *(uint *)(param_6 + 0x74);
          uVar15 = (uint)*(ushort *)(param_6 + 0x6c);
        }
        uVar13 = uVar13 & 0xffffffbf;
        *(uint *)(param_6 + 0x74) = uVar13;
      }
      if (uVar15 == 0) {
        if ((uVar13 >> 5 & 1) != 0) {
          FUN_fffffff00a24a024(param_6 + 5,0,0);
          uVar13 = *(uint *)(param_6 + 0x74);
        }
        *(uint *)(param_6 + 0x74) = uVar13 & 0xffffffdf;
        if (*(int *)(param_6 + 0x70) == 0) {
          FUN_fffffff00a30c550(param_6,2);
        }
      }
      FUN_fffffff00a22aeac(param_6 + 8);
    }
    if (param_2 != 0) {
LAB_fffffff00a2dabc8:
      do {
        *(int *)(lVar6 + 0x1c0) = *(int *)(lVar6 + 0x1c0) + 1;
        lVar18 = *(long *)(lVar6 + 0x1b0) >> 0x10;
        plVar1 = (long *)(&DAT_fffffff00ad28260 + lVar18);
        if (*plVar1 == 0) {
          puVar19 = *(undefined8 **)(&DAT_fffffff00ad28268 + lVar18);
          if (puVar19 == (undefined8 *)0x0) {
            *plVar1 = 0;
          }
          else {
            *(undefined8 *)(&DAT_fffffff00ad28268 + lVar18) = *puVar19;
            *puVar19 = 0;
            *plVar1 = (long)puVar19;
            if (puVar19 < DAT_fffffff007bf0010 || DAT_fffffff007bf0008 <= puVar19) {
              uVar15 = *(uint *)((long)puVar19 + 0x3c);
            }
            else {
              uVar15 = DAT_fffffff007bf0000 +
                       (int)((ulong)((long)puVar19 - (long)DAT_fffffff007bf0010) >> 6);
            }
            FUN_fffffff00a38dfd0((ulong)uVar15 << 0xe,0x4000);
            plVar1 = (long *)(_DAT_fffffff00ad0e4f8 + (ulong)*(ushort *)(lVar6 + 0x1b0) * 0x4000);
            *plVar1 = *plVar1 + 1;
          }
        }
        if (*(int *)(lVar6 + 0x1c0) == 0) {
LAB_fffffff00a2db518:
                    /* WARNING: Subroutine does not return */
          FUN_fffffff00aa5c868();
        }
        lVar18 = *(long *)(&DAT_fffffff00ad28268 + lVar18);
        iVar7 = *(int *)(lVar6 + 0x1c0) + -1;
        *(int *)(lVar6 + 0x1c0) = iVar7;
        if ((iVar7 == 0) && ((*(byte *)(*(long *)(lVar6 + 0x1b8) + 0x4c) >> 2 & 1) != 0)) {
          FUN_fffffff00a3976a4();
        }
        if (lVar18 == 0) {
          FUN_fffffff00a32d064(10);
        }
        FUN_fffffff00a3061bc(param_2);
        puVar19 = (undefined8 *)FUN_fffffff00a32bd34(param_2,local_118 & 0xffffffffffffc000);
        if (puVar19 == puVar14) {
          local_84 = local_a0._4_4_;
          local_78 = 0;
          puVar19 = puVar14;
          goto LAB_fffffff00a2dad8c;
        }
        local_84 = 1;
        uVar15 = *(ushort *)(param_2 + 0x6c) + 1;
        *(short *)(param_2 + 0x6c) = (short)uVar15;
        if (uVar15 >> 0x10 != 0) {
LAB_fffffff00a2db554:
                    /* WARNING: Subroutine does not return */
          FUN_fffffff00aa4d114("vm_object_paging_begin(%p): overflow\n @%s:%d");
        }
        local_78 = 0;
        in_stack_fffffffffffffe80 = in_stack_fffffffffffffe80 & 0xffffffff00000000;
        local_d8 = uVar9;
        iVar7 = FUN_fffffff00a2d5330
                          (param_2,local_118 & 0xffffffffffffc000,1,0,0,&local_84,&local_78,
                           &local_80,0,&local_a0,in_stack_fffffffffffffe80,&local_e0,param_1);
        if (iVar7 < 3) goto LAB_fffffff00a2dabbc;
        if (iVar7 != 3) {
          if (iVar7 != 5) {
            if (iVar7 != 6) goto LAB_fffffff00a2db5b4;
            uVar5 = *(ushort *)(param_2 + 0x6c);
            uVar15 = uVar5 - 1;
            *(short *)(param_2 + 0x6c) = (short)uVar15;
            if (0xffff < uVar15) goto LAB_fffffff00a2db5f8;
            uVar15 = uVar15 & 0xffff;
            if (((*(byte *)(param_2 + 0x75) >> 4 & 1) == 0) &&
               (((*(byte *)(param_2 + 0xa9) & (uint)uVar5 == (uint)DAT_fffffff007bccab0) != 0 ||
                (DAT_fffffff007bccab2 == uVar5)))) {
              FUN_fffffff00a30c550(param_2,6);
              uVar15 = (uint)*(ushort *)(param_2 + 0x6c);
            }
            if ((uVar15 == 0) && (FUN_fffffff00a30c550(param_2,5), *(int *)(param_2 + 0x70) == 0)) {
              FUN_fffffff00a30c550(param_2,2);
            }
            FUN_fffffff00a22aeac(param_2 + 8);
          }
          FUN_fffffff00a2db644(puVar14);
LAB_fffffff00a2db3b0:
          local_a4 = 10;
          if ((int)local_a0 != 0) {
            local_a4 = (int)local_a0;
          }
          goto LAB_fffffff00a2db3f4;
        }
        iVar7 = FUN_fffffff00a32d760(param_8);
      } while (iVar7 != 0);
      goto LAB_fffffff00a2db4ec;
    }
    puVar19 = (undefined8 *)0x0;
    local_78 = 0;
    goto LAB_fffffff00a2dad98;
  }
  if (iVar7 != 2) {
LAB_fffffff00a2db560:
                    /* WARNING: Subroutine does not return */
    FUN_fffffff00aa4d114("vm_fault_copy: unexpected error 0x%x from vm_fault_page()\n @%s:%d");
  }
  local_a4 = 0x10000007;
  goto LAB_fffffff00a2db3f4;
LAB_fffffff00a2dabbc:
  if (iVar7 != 1) goto LAB_fffffff00a2dad68;
  goto LAB_fffffff00a2dabc8;
LAB_fffffff00a2dad68:
  if (iVar7 != 0) {
    if (iVar7 != 2) {
LAB_fffffff00a2db5b4:
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa4d114("vm_fault_copy(2): unexpected error 0x%x from vm_fault_page()\n @%s:%d");
    }
LAB_fffffff00a2db4ec:
    FUN_fffffff00a2db644(puVar14);
    local_a4 = 0x10000007;
    goto LAB_fffffff00a2db3f4;
  }
  local_150 = 0;
  if (*(uint *)(local_78 + 0x1c) != 0) {
    local_150 = (ulong)*(uint *)(local_78 + 0x1c) * 0x40 + -0x2400000000;
  }
LAB_fffffff00a2dad8c:
  FUN_fffffff00a22aeac(local_150 + 8);
LAB_fffffff00a2dad98:
  *(uint *)(param_1 + 5) = *(uint *)(param_1 + 5) | 0x10000;
  lVar18 = FUN_fffffff00a34a078(param_1,&local_a4);
  puVar14 = local_90;
  *param_5 = lVar18;
  *(uint *)(param_1 + 5) = *(uint *)(param_1 + 5) & 0xfffeffff;
  if (*param_5 == 0) {
    if ((local_78 != 0) && (puVar19 != local_90)) {
      FUN_fffffff00a2db850(local_78,local_80);
    }
    FUN_fffffff00a2db644(puVar14);
    if (local_a4 != 0x20008006) {
LAB_fffffff00a2db3f4:
      *param_5 = 0;
      goto LAB_fffffff00a2db3fc;
    }
    if ((*(byte *)(uVar16 + 0xfb) & 1) != 0) {
      uVar11 = *param_1;
      uVar3 = param_1[1];
      plVar1 = (long *)(_DAT_fffffff00ad18860 + (ulong)*(ushort *)(lVar6 + 0x1b0) * 0x4000);
      *plVar1 = *plVar1 + 1;
      if ((DAT_fffffff00ad98b00 & 0xfffffff7) != 0) {
        iVar7 = FUN_fffffff00a2d7940(uVar16);
        if (iVar7 == 0) {
          uVar8 = 0;
        }
        else {
          uVar9 = uVar16 & 0x7ffffffffff;
          if ((uVar16 & 0x80000000000000) != 0) {
            uVar9 = uVar16 | 0xffffff8000000000;
          }
          uVar8 = FUN_fffffff00a396010(uVar9);
        }
        FUN_fffffff00a6de494(0x1b12020,uVar8,uVar11,uVar3,0);
      }
    }
    uVar5 = uVar5 + 1;
    if (DAT_fffffff007bca168 <= uVar5) {
      uVar15 = (uint)(ushort)(uVar5 - DAT_fffffff007bca168);
      uVar13 = uVar15;
      if (0x1e < uVar15) {
        uVar13 = 0x1f;
      }
      (&DAT_fffffff00ad33da0)[uVar13] = (&DAT_fffffff00ad33da0)[uVar13] + 1;
      if (6 < uVar15) {
        uVar15 = 7;
      }
      FUN_fffffff00a246e7c
                (FUN_fffffff00a2271e0,0,*(undefined4 *)(&DAT_fffffff00ad0c410 + (ulong)uVar15 * 4),
                 1000);
      FUN_fffffff00a247a70(0,0,0);
    }
    lVar6 = FUN_fffffff00a34a078(param_1,&local_a4);
    *param_5 = lVar6;
    if (local_a4 != 0) goto LAB_fffffff00a2db3f4;
    if (DAT_fffffff007bca166 < uVar5) goto LAB_fffffff00a2db3fc;
    goto LAB_fffffff00a2db150;
  }
  uVar9 = FUN_fffffff00a2ec1e8(uVar16,*param_5,param_7,local_90,uVar11,uVar3);
  if ((uVar9 & 1) == 0) {
    if ((puVar19 != puVar14) && (local_78 != 0)) {
      FUN_fffffff00a2db850(local_78,local_80);
    }
    FUN_fffffff00a2db644(puVar14);
    goto LAB_fffffff00a2db3fc;
  }
  if ((*(byte *)((long)puVar14 + 0x2c) >> 2 & 1) == 0) {
    if ((puVar14 < DAT_fffffff007bf0010) || (DAT_fffffff007bf0008 <= puVar14)) {
      uVar15 = *(uint *)((long)puVar14 + 0x3c);
    }
    else {
      uVar15 = DAT_fffffff007bf0000 +
               (int)((ulong)((long)puVar14 - (long)DAT_fffffff007bf0010) >> 6);
    }
    local_69[0] = 0;
    iVar7 = FUN_fffffff00aa432b8((ulong)uVar15 << 0xe,local_69);
    if (iVar7 != 0) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa4d114("%s: sptm_get_paddr_type returned failure for paddr 0x%llx @%s:%d");
    }
    if (local_69[0] - 0xe < 3) {
      if (((*(byte *)((long)puVar14 + 0x2c) >> 5 & 1) != 0) ||
         ((*(byte *)((long)puVar14 + 0x2a) & 0xf) == 0xe)) {
        FUN_fffffff00a22aeac(param_6 + 8);
        if ((puVar19 != puVar14) && (local_78 != 0)) {
          FUN_fffffff00a2db850(local_78,local_80);
        }
        FUN_fffffff00a3061bc(param_6);
        if ((*(byte *)((long)puVar14 + 0x2a) & 0xf) == 0xe) {
          FUN_fffffff00a22aeac(param_6 + 8);
          FUN_fffffff00a2db644(puVar14);
          local_a4 = 10;
          goto LAB_fffffff00a2db3f4;
        }
        if ((*(byte *)((long)puVar14 + 0x2c) & 0x24) != 0) {
          iVar7 = FUN_fffffff00a305a48(param_6,puVar14,param_8,1);
          FUN_fffffff00a2db644(puVar14);
          if ((iVar7 == 0) || (iVar7 == 3)) goto LAB_fffffff00a2db150;
          local_a4 = 0xe;
          goto LAB_fffffff00a2db3f4;
        }
        FUN_fffffff00a22aeac(param_6 + 8);
        goto LAB_fffffff00a2db23c;
      }
      if ((puVar14 < DAT_fffffff007bf0010) || (DAT_fffffff007bf0008 <= puVar14)) {
        iVar7 = *(int *)((long)puVar14 + 0x3c);
      }
      else {
        iVar7 = DAT_fffffff007bf0000 +
                (int)((ulong)((long)puVar14 - (long)DAT_fffffff007bf0010) >> 6);
      }
      FUN_fffffff00a37c028(iVar7,0x100000,0);
    }
    lVar6 = local_78;
    uVar16 = local_118 & 0x3fff;
    uVar12 = param_7 & 0x3fff;
    uVar9 = uVar12;
    if (uVar12 <= uVar16) {
      uVar9 = uVar16;
    }
    uVar2 = 0x4000 - uVar9;
    if (uVar17 <= 0x4000 - uVar9) {
      uVar2 = uVar17;
    }
    if (local_78 == 0) {
      if ((puVar14 < DAT_fffffff007bf0010) || (DAT_fffffff007bf0008 <= puVar14)) {
        uVar15 = *(uint *)((long)puVar14 + 0x3c);
      }
      else {
        uVar15 = DAT_fffffff007bf0000 +
                 (int)((ulong)((long)puVar14 - (long)DAT_fffffff007bf0010) >> 6);
      }
      FUN_fffffff00a38dfd0(uVar12 | (ulong)uVar15 << 0xe,uVar2);
    }
    else {
      FUN_fffffff00a32ef9c(local_78,uVar16,puVar14,uVar12,uVar2);
    }
    if ((puVar14 < DAT_fffffff007bf0010) || (DAT_fffffff007bf0008 <= puVar14)) {
      uVar15 = *(uint *)((long)puVar14 + 0x3c);
    }
    else {
      uVar15 = DAT_fffffff007bf0000 +
               (int)((ulong)((long)puVar14 - (long)DAT_fffffff007bf0010) >> 6);
    }
    if ((DAT_fffffff007bf0df0 <= (ulong)uVar15 << 0xe) &&
       ((ulong)uVar15 << 0xe < DAT_fffffff007bf0df8)) {
      if (uVar15 < DAT_fffffff007bca750 + DAT_fffffff007bf0000) {
        if (uVar15 < DAT_fffffff007bf0000) {
          puVar10 = (undefined8 *)FUN_fffffff00a3285d4();
        }
        else {
          puVar10 = DAT_fffffff007bf0010 + (ulong)(uVar15 - DAT_fffffff007bf0000) * 8;
        }
      }
      else {
        puVar10 = (undefined8 *)0x0;
      }
      *(ushort *)(puVar10 + 7) = *(ushort *)(puVar10 + 7) | 0x80;
    }
    *(byte *)((long)puVar14 + 0x2d) = *(byte *)((long)puVar14 + 0x2d) | 1;
    FUN_fffffff00a22aeac(param_6 + 8);
    if ((puVar19 != puVar14) && (lVar6 != 0)) {
      FUN_fffffff00a2db850(lVar6,local_80);
    }
    FUN_fffffff00a2db644(puVar14);
    uVar5 = 0;
    uVar17 = uVar17 - uVar2;
    local_118 = uVar2 + local_118;
    param_7 = uVar2 + param_7;
  }
  else {
    FUN_fffffff00a22aeac(param_6 + 8);
    if ((puVar19 != puVar14) && (local_78 != 0)) {
      FUN_fffffff00a2db850(local_78,local_80);
    }
LAB_fffffff00a2db23c:
    FUN_fffffff00a2db644(puVar14);
  }
LAB_fffffff00a2db150:
  if (uVar17 == 0) {
LAB_fffffff00a2db3fc:
    *param_4 = *param_4 - uVar17;
    return local_a4;
  }
  goto LAB_fffffff00a2da8c4;
}

