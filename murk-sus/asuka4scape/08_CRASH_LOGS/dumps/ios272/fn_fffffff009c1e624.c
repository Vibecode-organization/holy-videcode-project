// FUN_fffffff009c1e624 @ fffffff009c1e624 size=2948

/* WARNING: Removing unreachable block (ram,0xfffffff009c1ea94) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c1eb4c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c1ed50) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c1e97c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c1ebe4) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c1f13c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c1e8e8) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c1ec5c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c1e7f0) */

ulong FUN_fffffff009c1e624(long *param_1)

{
  undefined8 *puVar1;
  undefined *puVar2;
  int iVar3;
  long *plVar4;
  long lVar5;
  long *plVar6;
  undefined8 uVar7;
  uint uVar8;
  uint uVar9;
  uint extraout_w8;
  ulong *puVar10;
  ulong uVar11;
  uint extraout_w9;
  ulong uVar12;
  ulong uVar13;
  undefined1 auVar14 [16];
  uint local_6c;
  long local_68;
  
  local_68 = *(long *)PTR_DAT_fffffff00806ca40;
  if (param_1[0x6f] != 0) {
    FUN_fffffff009c21f78(param_1 + 6,*(undefined8 *)(param_1[0x6f] + 0x30));
    goto LAB_fffffff009c1e674;
  }
  if (((((*(byte *)((long)param_1 + 0x3d3) & 1) == 0) && (param_1[0x74] == 0)) ||
      (*(long **)(DAT_fffffff00af483b0 + 0x430) == (long *)0x0)) ||
     (iVar3 = (**(code **)(**(long **)(DAT_fffffff00af483b0 + 0x430) + 0x80))(), iVar3 == 0)) {
    puVar2 = PTR_DAT_fffffff00806ca78;
    if (param_1[0x2a] == 0) {
      if (param_1[0x6e] != 0) {
        uVar8 = *(uint *)(param_1 + 0x6d);
        local_6c = uVar8;
        if (*(int *)((long)param_1 + 0x3b4) == 0) {
          uVar12 = 0;
        }
        else {
          uVar13 = 0;
          do {
            puVar10 = (ulong *)(param_1[0x6e] + uVar13 * 0x10);
            if (((param_1[0x6e] ^ (ulong)puVar10) & 0xffc0000000000000) != 0) {
              puVar10 = (ulong *)((ulong)puVar10 & 0xffffffffffff | 0xc8a2000000000000);
            }
            uVar12 = *puVar10;
            if ((*(long *)puVar2 - 1U & uVar12) != 0) {
              uVar12 = 0xe00002c2;
              thunk_EXT_FUN_80110000038db19c
                        (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                         "%s error - unaligned addr (0x%llx)\n");
              goto LAB_fffffff009c1e780;
            }
            uVar11 = puVar10[1];
            if (uVar11 == 0 || (*(long *)puVar2 - 1U & uVar11) != 0) {
              uVar12 = 0xe00002c2;
              thunk_EXT_FUN_80110000038db19c
                        (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                         "%s error - unaligned length (0x%llx)\n");
              goto LAB_fffffff009c1e780;
            }
            lVar5 = param_1[0x2e];
            if (lVar5 == 0) {
              lVar5 = 0;
            }
            uVar12 = FUN_fffffff009c2200c(lVar5,uVar12,uVar11 + uVar12,&local_6c);
            if ((int)uVar12 != 0) {
              thunk_EXT_FUN_80110000038db19c
                        (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                         "%s error - invalid range (0x%llx - 0x%llx)\n");
              goto LAB_fffffff009c1e780;
            }
            uVar13 = uVar13 + 1;
            uVar12 = (ulong)*(uint *)((long)param_1 + 0x3b4);
          } while (uVar13 < uVar12);
          uVar8 = *(uint *)(param_1 + 0x6d);
          if (local_6c != uVar8) {
            uVar12 = 0xe00002c2;
            thunk_EXT_FUN_80110000038db19c
                      (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                       "%s error - invalid direction (0x%x vs 0x%x)\n");
            goto LAB_fffffff009c1e780;
          }
        }
        auVar14._8_8_ = uVar12;
        auVar14._0_8_ = param_1[0x6e];
        uVar9 = 0x110100;
        lVar5 = param_1[0x2e];
        if (lVar5 == 0) {
LAB_fffffff009c1eda8:
          lVar5 = 0;
        }
        plVar4 = (long *)thunk_EXT_FUN_8011000003977010
                                   (auVar14._0_8_,auVar14._8_8_,uVar8 | uVar9,lVar5);
        if (plVar4 != (long *)0x0) {
          uVar12 = param_1[0x2d];
          uVar13 = param_1[0x12];
          if ((CARRY8(uVar12,uVar13)) ||
             (uVar11 = (**(code **)(*plVar4 + 0xb0))(plVar4), uVar11 < uVar12 + uVar13)) {
            thunk_EXT_FUN_80110000038db19c
                      (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                       "%s error - Address ranges do not cover requested allocation size\n");
          }
          else {
            FUN_fffffff009c21f08(param_1,plVar4);
          }
          (**(code **)(*plVar4 + 0x28))(plVar4);
        }
        goto LAB_fffffff009c1e674;
      }
      if ((int)param_1[0x32] != 0) {
        if ((*(byte *)((long)param_1 + 0x3d3) >> 3 & 1) != 0) {
          plVar4 = param_1 + 0x33;
          uVar12 = (long)(param_1 + 0x35) - (long)plVar4;
          if ((param_1 + 0x35 < plVar4) || (uVar12 >> 0x20 != 0)) {
            FUN_fffffff009c48f64();
            goto LAB_fffffff009c1f1a4;
          }
          uVar13 = 0;
          lVar5 = 0;
          uVar8 = 0;
          plVar6 = param_1 + 0x74;
          do {
            if ((lVar5 < 0) ||
               (uVar9 = (int)uVar13 + 8, plVar6 = (long *)(ulong)uVar9, (uint)uVar12 < uVar9)) {
                    /* WARNING: Subroutine does not return */
              FUN_fffffff009c48f28(plVar6);
            }
            puVar1 = (undefined8 *)((long)plVar4 + uVar13);
            uVar11 = -(ulong)CARRY8((ulong)plVar4,uVar13);
            if ((uVar11 != CARRY8((ulong)plVar4,uVar13)) || ((long)uVar11 < 0)) {
                    /* WARNING: Subroutine does not return */
              FUN_fffffff009c48f50();
            }
            iVar3 = (**(code **)(*(long *)*puVar1 + 0xb8))();
            if (*(uint *)((long)param_1 + 0x9c) == 0) {
              *(int *)((long)param_1 + 0x9c) = iVar3;
            }
            else if (((iVar3 == 0x400) || (iVar3 == 0x100)) &&
                    ((*(uint *)((long)param_1 + 0x9c) | 0x100) == 0x300)) {
              uVar12 = 0xe00002c2;
              (**(code **)(*(long *)*puVar1 + 0xb8))();
              puVar2 = PTR_DAT_fffffff00806ca48;
              thunk_EXT_FUN_80110000038db19c
                        (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                         "IOSurface::allocate() - requested cache mode %08x incompatible with memory region cache mode %08x\n"
                        );
              thunk_EXT_FUN_80110000038db19c
                        (&MACH_HEADER,puVar2,0x10,
                         "%s error - incompatible cache mode (0x%x in 0x%x)\n");
              goto LAB_fffffff009c1e780;
            }
            if ((param_1[0x74] == 0) &&
               (iVar3 = (**(code **)(*(long *)*puVar1 + 0x80))((long *)*puVar1,param_1), iVar3 != 0)
               ) {
              FUN_fffffff009c16670(param_1 + 5,*puVar1);
              uVar7 = (**(code **)(*(long *)param_1[5] + 0x90))();
              uVar12 = (ulong)(uint)~(-1 << (ulong)(*(uint *)PTR_DAT_fffffff00806c9b0 & 0x1f));
              plVar4 = (long *)thunk_EXT_FUN_801100000397c234
                                         (uVar7,param_1[0x11],
                                          param_1[0x12] + uVar12 & (uVar12 ^ 0xffffffffffffffff),
                                          0x100003);
              FUN_fffffff009c21f08(param_1,plVar4);
              if (plVar4 == (long *)0x0) {
                if ((long *)param_1[5] != (long *)0x0) {
                  (**(code **)(*(long *)param_1[5] + 0x28))();
                }
                param_1[5] = 0;
              }
              else {
                *(undefined1 *)(param_1[0x2f] + 0x30) = 1;
                (**(code **)(*plVar4 + 0x28))(plVar4);
              }
              goto LAB_fffffff009c1eab0;
            }
            uVar8 = uVar8 + 1;
            uVar9 = *(uint *)(param_1 + 0x32);
            if (uVar9 <= uVar8) goto LAB_fffffff009c1eab4;
            plVar6 = (long *)0x800000000;
            lVar5 = lVar5 + 0x800000000;
            uVar13 = uVar13 + 8;
          } while (uVar13 == (long)(int)uVar13);
          auVar14 = FUN_fffffff009c48f3c();
          uVar8 = extraout_w8;
          uVar9 = extraout_w9;
          goto LAB_fffffff009c1eda8;
        }
LAB_fffffff009c1eab0:
        uVar9 = *(uint *)(param_1 + 0x32);
LAB_fffffff009c1eab4:
        if ((uVar9 != 0) && (param_1[6] != 0)) goto LAB_fffffff009c1e674;
      }
      uVar8 = 0x110023;
      if ((*(uint *)(param_1 + 0x7a) & 0x20000) != 0) {
        uVar8 = 0x910023;
      }
      uVar9 = *(uint *)(param_1 + 0x7a) >> 9 & 0x40 | *(uint *)((long)param_1 + 0x9c);
      if ((param_1[0x68] != 0) &&
         (plVar4 = (long *)FUN_fffffff009c372dc(DAT_fffffff00af483b0), plVar4 != (long *)0x0)) {
        uVar12 = (ulong)(uint)~(-1 << (ulong)(*(uint *)PTR_DAT_fffffff00806c9b0 & 0x1f));
        lVar5 = param_1[0x2e];
        if (lVar5 == 0) {
          lVar5 = 0;
        }
        plVar6 = (long *)FUN_fffffff009c4405c
                                   (plVar4,param_1[0x12] + uVar12 & (uVar12 ^ 0xffffffffffffffff),
                                    uVar9 | uVar8,param_1[0x68],lVar5,
                                    *(uint *)(param_1 + 0x7a) >> 0xb & 1);
        FUN_fffffff009c21f08(param_1,plVar6);
        if (plVar6 != (long *)0x0) {
          (**(code **)(*plVar6 + 0x28))(plVar6);
        }
        (**(code **)(*plVar4 + 0x28))(plVar4);
      }
      if (param_1[6] == 0) {
        param_1[0x68] = 0;
        uVar12 = (ulong)(uint)~(-1 << (ulong)(*(uint *)PTR_DAT_fffffff00806c9b0 & 0x1f));
        plVar4 = (long *)thunk_EXT_FUN_8011000003962900
                                   (0,uVar9 | uVar8,
                                    param_1[0x12] + uVar12 & (uVar12 ^ 0xffffffffffffffff),
                                    *(undefined8 *)PTR_DAT_fffffff00806ca78);
        FUN_fffffff009c21f08(param_1,plVar4);
        if (plVar4 != (long *)0x0) {
          (**(code **)(*plVar4 + 0x28))(plVar4);
        }
        if (param_1[6] != 0) goto LAB_fffffff009c1f074;
LAB_fffffff009c1f09c:
        uVar8 = *(uint *)(param_1 + 0x7a) | 0x20;
      }
      else {
LAB_fffffff009c1f074:
        iVar3 = *(int *)((long)param_1 + 0x9c);
        if (((iVar3 != 0x100) && (iVar3 != 0x700)) && (iVar3 != 0x400)) goto LAB_fffffff009c1f09c;
        uVar8 = *(uint *)(param_1 + 0x7a) & 0xffffffdf;
      }
      *(uint *)(param_1 + 0x7a) = uVar8;
    }
    else {
      local_6c = *(uint *)(param_1 + 0x6d);
      lVar5 = param_1[0x2e];
      if (lVar5 == 0) {
        lVar5 = 0;
      }
      uVar12 = FUN_fffffff009c2200c(lVar5,param_1[0x2b],param_1[0x2c] + param_1[0x2b],&local_6c);
      if ((int)uVar12 != 0) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                   "%s error - invalid address range (0x%llx - 0x%llx) : (0x%llx - 0x%llx)\n");
        goto LAB_fffffff009c1e780;
      }
      lVar5 = param_1[0x2e];
      if (lVar5 == 0) {
        lVar5 = 0;
      }
      plVar4 = (long *)thunk_EXT_FUN_8011000003976e84
                                 (param_1[0x2b],param_1[0x2c],local_6c | 0x110000,lVar5);
      FUN_fffffff009c21f08(param_1,plVar4);
      if (plVar4 != (long *)0x0) {
        (**(code **)(*plVar4 + 0x28))(plVar4);
      }
      *(uint *)(param_1 + 0x7a) = *(uint *)(param_1 + 0x7a) | 0x20;
      lVar5 = param_1[0x2f];
      *(int *)(lVar5 + 0xc) = *(int *)(lVar5 + 0xc) + 1;
      *(uint *)(param_1 + 0x7a) = *(uint *)(param_1 + 0x7a) | 0xc;
      *(int *)(lVar5 + 0x10) = *(int *)(lVar5 + 0x10) + 1;
    }
LAB_fffffff009c1e674:
    if (param_1[6] == 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                 "%s error - buffer allocation failed (%llu x %llu fmt: %08x size: %llu bytes)\n");
      thunk_EXT_FUN_80110000038fe9a0
                (
                "IOSurface warning: buffer allocation failed.  %llu x %llu fmt: %08x size: %llu bytes\n"
                );
      if (param_1[6] != 0) goto LAB_fffffff009c1e6e4;
    }
    else {
LAB_fffffff009c1e6e4:
      if (param_1[0x6f] == 0) {
        plVar4 = (long *)FUN_fffffff009c2cf30(param_1);
        thunk_EXT_FUN_8011000003977a94(param_1[6],plVar4);
        if (plVar4 != (long *)0x0) {
          (**(code **)(*plVar4 + 0x28))(plVar4);
        }
      }
    }
    uVar8 = *(uint *)(param_1 + 0x7a);
    if ((uVar8 >> 0x1a & 1) != 0) {
      if ((long *)param_1[6] != (long *)0x0) {
        iVar3 = (**(code **)(*(long *)param_1[6] + 0xa8))();
        if (iVar3 == 2) goto LAB_fffffff009c1e768;
        uVar8 = *(uint *)(param_1 + 0x7a);
      }
      *(uint *)(param_1 + 0x7a) = uVar8 & 0xfbffffff;
    }
LAB_fffffff009c1e768:
    uVar8 = 0xe00002be;
    if (param_1[6] != 0) {
      uVar8 = 0;
    }
    uVar12 = (ulong)uVar8;
  }
  else {
    (**(code **)(*param_1 + 0x20))(param_1);
    lVar5 = (**(code **)(**(long **)(DAT_fffffff00af483b0 + 0x430) + 0x78))
                      (*(long **)(DAT_fffffff00af483b0 + 0x430),param_1);
    if ((long *)param_1[0x78] != (long *)0x0) {
      (**(code **)(*(long *)param_1[0x78] + 0x28))();
    }
    param_1[0x78] = lVar5;
    if (lVar5 == 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,"%s error - can\'t prepare mapping\n");
      uVar12 = 0xe00002be;
    }
    else {
      uVar12 = 0;
    }
    (**(code **)(*param_1 + 0x28))(param_1);
  }
LAB_fffffff009c1e780:
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_68) {
    return uVar12;
  }
LAB_fffffff009c1f1a4:
  uVar12 = thunk_EXT_FUN_8011000003a48590();
  return uVar12;
}

