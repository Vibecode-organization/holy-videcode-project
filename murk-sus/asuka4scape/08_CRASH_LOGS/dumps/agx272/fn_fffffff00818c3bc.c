// FUN_fffffff00818c3bc @ fffffff00818c3bc size=2428

undefined8 FUN_fffffff00818c3bc(long param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined8 *puVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  long *plVar8;
  undefined8 uVar9;
  long lVar10;
  long lVar11;
  long lVar12;
  uint uVar13;
  long lVar14;
  long lVar15;
  ulong uVar16;
  ulong uVar17;
  undefined4 uVar18;
  undefined8 uVar19;
  long *plVar20;
  ulong uVar21;
  uint local_64;
  
  lVar10 = *(long *)(param_1 + 0x548);
  if ((lVar10 != 0) && ((*(byte *)(*(long *)(param_1 + 0x530) + 0x10a9d) & 1) != 0)) {
    lVar12 = *(long *)(param_1 + 0x610);
    if (lVar10 == 1) {
      lVar14 = 0;
    }
    else if (lVar10 == 7) {
      lVar14 = 2;
    }
    else {
      if (lVar10 != 3) goto LAB_fffffff00818cce4;
      lVar14 = 1;
    }
    if (*(long *)(lVar12 + 0x68 + lVar14 * 8) == 0) {
      lVar14 = FUN_fffffff00818d738(param_1,0);
      if (lVar14 == 0) {
        return 0;
      }
      lVar12 = *(long *)(param_1 + 0x610);
      lVar10 = *(long *)(param_1 + 0x548);
      if (lVar10 == 1) {
        lVar15 = 0;
      }
      else if (lVar10 == 7) {
        lVar15 = 2;
      }
      else {
        if (lVar10 != 3) goto LAB_fffffff00818cce4;
        lVar15 = 1;
      }
      *(long *)(lVar12 + 0x68 + lVar15 * 8) = lVar14;
    }
    if (lVar10 == 1) {
      lVar10 = 0;
    }
    else if (lVar10 == 7) {
      lVar10 = 2;
    }
    else {
      if (lVar10 != 3) {
LAB_fffffff00818cce4:
        uVar9 = thunk_EXT_FUN_8011000003a49114("AGXk: %s:%d:%s: !!! Invalid Protection Options\n");
        return uVar9;
      }
      lVar10 = 1;
    }
    return *(undefined8 *)(lVar12 + 0x68 + lVar10 * 8);
  }
  iVar6 = *(int *)(param_1 + 0x7f8);
  if (iVar6 == 4) {
    lVar10 = *(long *)(param_1 + 0x610);
    if (*(int *)(lVar10 + 0x98) != 0) {
      uVar17 = 0;
      lVar12 = *(long *)(*(long *)(param_1 + 0x530) + 0x148);
      do {
        local_64 = 0;
        lVar14 = *(long *)(lVar10 + 0x28 + uVar17 * 8);
        if ((*(long *)(lVar14 + 0x218) != 0) &&
           (iVar6 = *(int *)(*(long *)(lVar14 + 0x218) + 0x18), iVar6 != 0x80)) {
          uVar21 = thunk_EXT_FUN_80110000029493bc(lVar12,param_2,iVar6,&local_64);
          if ((uVar21 & 1) == 0) {
            lVar10 = *(long *)(param_1 + 0x610);
            lVar14 = *(long *)(lVar10 + 0x28 + uVar17 * 8);
            goto LAB_fffffff00818c5d0;
          }
LAB_fffffff00818c960:
          uVar21 = (ulong)(*(int *)(lVar12 + 0x144c) - 1U & local_64 >> 8 & 0xff) << 2 |
                   (long)iVar6 << 10;
          piVar2 = (int *)(lVar12 + 0x1450 + (long)(int)uVar21);
          if (uVar21 != (long)(int)uVar21) {
            piVar2 = (int *)(lVar12 + 0x1450 + uVar21 & 0xffffffffffff | 0x2bad000000000000);
          }
          iVar6 = *piVar2;
          *piVar2 = iVar6 + 1;
          uVar13 = iVar6 + (int)uVar17;
          uVar1 = *(uint *)(param_1 + 0x834);
          uVar5 = 0;
          if (uVar1 != 0) {
            uVar5 = uVar13 / uVar1;
          }
          uVar17 = (ulong)(uVar13 - uVar5 * uVar1);
          lVar10 = 5;
          if (iVar6 == 0) {
            lVar10 = 1;
          }
          goto LAB_fffffff00818c730;
        }
LAB_fffffff00818c5d0:
        if ((*(long *)(lVar14 + 0x220) != 0) &&
           (iVar6 = *(int *)(*(long *)(lVar14 + 0x220) + 0x18), iVar6 != 0x80)) {
          uVar21 = thunk_EXT_FUN_80110000029493bc(lVar12,param_2,iVar6,&local_64);
          if ((uVar21 & 1) != 0) goto LAB_fffffff00818c960;
          lVar10 = *(long *)(param_1 + 0x610);
        }
        uVar17 = uVar17 + 1;
      } while (uVar17 < *(uint *)(lVar10 + 0x98));
      if (*(uint *)(lVar10 + 0x98) != 0) {
        uVar21 = 0;
        do {
          lVar14 = *(long *)(lVar10 + 0x28 + uVar21 * 8);
          if ((*(long *)(lVar14 + 0x218) == 0) ||
             (*(int *)(*(long *)(lVar14 + 0x218) + 0x18) == 0x80)) {
LAB_fffffff00818c6c4:
            if ((*(long *)(lVar14 + 0x220) == 0) ||
               (*(int *)(*(long *)(lVar14 + 0x220) + 0x18) == 0x80)) break;
            iVar6 = thunk_EXT_FUN_8011000002947748(lVar12);
            if (iVar6 != 0) goto LAB_fffffff00818cc38;
          }
          else {
            iVar6 = thunk_EXT_FUN_8011000002947748(lVar12);
            if (iVar6 != 0) {
              lVar10 = *(long *)(param_1 + 0x610);
              lVar14 = *(long *)(lVar10 + 0x28 + uVar21 * 8);
              goto LAB_fffffff00818c6c4;
            }
          }
          uVar21 = uVar21 + 1;
          lVar10 = *(long *)(param_1 + 0x610);
        } while (uVar21 < *(uint *)(lVar10 + 0x98));
        goto LAB_fffffff00818cc3c;
      }
    }
LAB_fffffff00818c6fc:
    uVar17 = 0;
    goto LAB_fffffff00818c700;
  }
  if (iVar6 == 3) {
    lVar10 = *(long *)(param_1 + 0x610);
    if (*(int *)(lVar10 + 0x98) != 0) {
      uVar17 = 0;
      uVar9 = *(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148);
      do {
        lVar12 = *(long *)(lVar10 + 0x28 + uVar17 * 8);
        if ((*(long *)(lVar12 + 0x218) != 0) && (*(int *)(*(long *)(lVar12 + 0x218) + 0x18) != 0x80)
           ) {
          uVar21 = thunk_EXT_FUN_8011000002948c40(uVar9,param_2);
          lVar10 = *(long *)(param_1 + 0x610);
          if ((uVar21 & 1) != 0) break;
          lVar12 = *(long *)(lVar10 + 0x28 + uVar17 * 8);
        }
        if ((*(long *)(lVar12 + 0x220) != 0) && (*(int *)(*(long *)(lVar12 + 0x220) + 0x18) != 0x80)
           ) {
          uVar21 = thunk_EXT_FUN_8011000002948c40(uVar9,param_2);
          lVar10 = *(long *)(param_1 + 0x610);
          if ((uVar21 & 1) != 0) break;
        }
        uVar17 = uVar17 + 1;
      } while (uVar17 < *(uint *)(lVar10 + 0x98));
      if (*(int *)(lVar10 + 0x98) != (int)uVar17) {
        lVar10 = 1;
        goto LAB_fffffff00818c730;
      }
      if (uVar17 != 0) {
        uVar21 = 0;
        do {
          lVar12 = *(long *)(lVar10 + 0x28 + uVar21 * 8);
          if ((*(long *)(lVar12 + 0x218) == 0) ||
             (*(int *)(*(long *)(lVar12 + 0x218) + 0x18) == 0x80)) {
LAB_fffffff00818c528:
            if ((*(long *)(lVar12 + 0x220) == 0) ||
               (*(int *)(*(long *)(lVar12 + 0x220) + 0x18) == 0x80)) break;
            iVar6 = thunk_EXT_FUN_8011000002947748(uVar9);
            if (iVar6 != 0) goto LAB_fffffff00818cc38;
          }
          else {
            iVar6 = thunk_EXT_FUN_8011000002947748(uVar9);
            if (iVar6 != 0) {
              lVar10 = *(long *)(param_1 + 0x610);
              lVar12 = *(long *)(lVar10 + 0x28 + uVar21 * 8);
              goto LAB_fffffff00818c528;
            }
          }
          uVar21 = uVar21 + 1;
          lVar10 = *(long *)(param_1 + 0x610);
        } while (uVar21 < *(uint *)(lVar10 + 0x98));
        goto LAB_fffffff00818cc3c;
      }
    }
    goto LAB_fffffff00818c6fc;
  }
  if (iVar6 == 2) {
    uVar13 = *(uint *)(param_1 + 0x834);
    goto LAB_fffffff00818c718;
  }
  lVar10 = 0;
  uVar17 = 0;
LAB_fffffff00818c730:
  lVar12 = *(long *)(param_1 + 0x610) + 0x28;
  uVar21 = (uVar17 & 0xffffffff) << 3;
  uVar16 = -(uVar17 >> 0x1f & 1) & 0xfffffff800000000 | uVar21;
  iVar6 = (int)uVar21;
  plVar8 = (long *)(lVar12 + iVar6);
  if (uVar16 != (long)iVar6) {
    plVar8 = (long *)(lVar12 + uVar16 & 0xffffffffffff | 0x2bad000000000000);
  }
  if (*plVar8 == 0) {
    lVar12 = FUN_fffffff00818d738(param_1,param_3,0);
    if (lVar12 == 0) {
      uVar17 = 0;
    }
    else {
      lVar14 = *(long *)(param_1 + 0x610);
      uVar13 = *(uint *)(lVar14 + 0x98);
      *(uint *)(lVar14 + 0x98) = uVar13 + 1;
      lVar15 = (ulong)uVar13 * 8;
      plVar8 = (long *)(lVar14 + 0x28 + (long)(int)lVar15);
      if (lVar15 - (int)lVar15 != 0) {
        plVar8 = (long *)(lVar14 + 0x28 + lVar15 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *plVar8 = lVar12;
    }
  }
  if ((int)param_3 != 0) goto LAB_fffffff00818cb84;
  lVar14 = *(long *)(param_1 + 0x610);
  lVar12 = lVar14 + 0x28;
  uVar21 = (uVar17 & 0xffffffff) << 3;
  uVar16 = -(uVar17 >> 0x1f & 1) & 0xfffffff800000000 | uVar21;
  iVar6 = (int)uVar21;
  plVar8 = (long *)(lVar12 + iVar6);
  if (uVar16 != (long)iVar6) {
    plVar8 = (long *)(lVar12 + uVar16 & 0xffffffffffff | 0x2bad000000000000);
  }
  if (*(long *)(*plVar8 + 0x218) == 0) {
    uVar21 = uVar17 & 0xffffffff;
    lVar15 = (uVar17 & 0xffffffff) * 8;
    plVar8 = (long *)(lVar12 + (int)lVar15);
    if (lVar15 != (int)lVar15) {
      plVar8 = (long *)(lVar12 + lVar15 & 0xffffffffffffU | 0x2bad000000000000);
    }
    lVar12 = *plVar8;
    lVar15 = *(long *)(lVar12 + 0x230);
    iVar6 = (int)uVar17;
    if (lVar15 == 0) {
      uVar9 = *(undefined8 *)(param_1 + 0x488);
      plVar20 = *(long **)(lVar12 + 0xc0);
      uVar19 = *(undefined8 *)(lVar12 + 0x100);
      plVar8 = (long *)(**(code **)(*plVar20 + 0x878))(plVar20);
      if (plVar8 != (long *)0x0) {
        uVar16 = (**(code **)(*plVar8 + 0x78))(plVar8,plVar20,uVar9,uVar19);
        if ((uVar16 & 1) != 0) {
          *(long **)(lVar12 + 0x230) = plVar8;
          lVar14 = *(long *)(param_1 + 0x610);
          lVar12 = uVar21 * 8;
          plVar8 = (long *)(lVar14 + 0x28 + (long)(int)lVar12);
          if (lVar12 - (int)lVar12 != 0) {
            plVar8 = (long *)(lVar14 + 0x28 + lVar12 & 0xffffffffffffU | 0x2bad000000000000);
          }
          lVar12 = *plVar8;
          lVar11 = *(long *)(param_1 + 0x918);
          if (iVar6 != 0) goto LAB_fffffff00818c810;
          goto LAB_fffffff00818c908;
        }
        (**(code **)(*plVar8 + 0x28))(plVar8);
      }
      *(undefined8 *)(lVar12 + 0x230) = 0;
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ca61a8,0x10,
                 "Failed to create Render Target Memory\n");
LAB_fffffff00818cc94:
      lVar12 = *(long *)(param_1 + 0x610);
    }
    else {
      lVar11 = *(long *)(param_1 + 0x918);
      if (iVar6 == 0) {
LAB_fffffff00818c908:
        iVar7 = FUN_fffffff00821465c(lVar12,*(undefined8 *)(param_1 + 0x488));
        if (lVar15 != 0 || iVar7 == 0) goto LAB_fffffff00818cc94;
        lVar12 = *(long *)(param_1 + 0x610);
        lVar14 = uVar21 * 8;
        plVar8 = (long *)(lVar12 + 0x28 + (long)(int)lVar14);
        if (lVar14 - (int)lVar14 != 0) {
          plVar8 = (long *)(lVar12 + 0x28 + lVar14 & 0xffffffffffffU | 0x2bad000000000000);
        }
        lVar14 = *plVar8;
        lVar15 = *(long *)(lVar14 + 0x228);
        if ((*(byte *)(*(long *)(lVar15 + 0x10) + 0x11181) & 1) == 0) {
          uVar13 = *(int *)(*(long *)(param_1 + 0x918) + 0x20) + iVar6;
          uVar1 = *(uint *)(*(long *)(param_1 + 0x530) + 0x418);
          uVar5 = 0;
          if (uVar1 != 0) {
            uVar5 = uVar13 / uVar1;
          }
          iVar7 = uVar13 - uVar5 * uVar1;
        }
        else {
          iVar7 = *(int *)(*(long *)(lVar15 + 0x10) + 0x11184);
        }
        *(int *)(lVar15 + 0x1c4) = iVar7;
        *(int *)(*(long *)(*(long *)(lVar15 + 0x20) + 0x48) + 0xc) = iVar7;
      }
      else {
LAB_fffffff00818c810:
        if ((*(byte *)(lVar11 + 0x24) & 1) != 0) goto LAB_fffffff00818c908;
        iVar7 = FUN_fffffff008214808(lVar12,*(undefined8 *)(*(long *)(lVar14 + 0x28) + 0x228));
        if (lVar15 != 0 || iVar7 == 0) goto LAB_fffffff00818cc94;
        lVar12 = *(long *)(param_1 + 0x610);
        lVar14 = uVar21 * 8;
        plVar8 = (long *)(lVar12 + 0x28 + (long)(int)lVar14);
        if (lVar14 - (int)lVar14 != 0) {
          plVar8 = (long *)(lVar12 + 0x28 + lVar14 & 0xffffffffffffU | 0x2bad000000000000);
        }
        lVar14 = *plVar8;
      }
      uVar21 = FUN_fffffff008214518(lVar14,*(undefined8 *)(*(long *)(lVar12 + 0xb0) + 0x28));
      lVar12 = *(long *)(param_1 + 0x610);
      if ((uVar21 & 1) != 0) {
        lVar14 = (long)iVar6 * 8;
        plVar8 = (long *)(lVar12 + 0x28 + (long)(int)lVar14);
        if (lVar14 - (int)lVar14 != 0) {
          plVar8 = (long *)(lVar12 + 0x28 + lVar14 & 0xffffffffffffU | 0x2bad000000000000);
        }
        lVar12 = *plVar8;
        uVar13 = *(uint *)(param_1 + 0x7ec);
        uVar21 = (ulong)uVar13;
        if (*(int *)(param_1 + 0x44c) == 1) {
          uVar18 = *(undefined4 *)(param_1 + 0x450);
        }
        else {
          uVar18 = 2;
        }
        plVar8 = *(long **)(lVar12 + 0x218);
        if (plVar8 != (long *)0x0) {
          (**(code **)(*plVar8 + 0x110))(plVar8,uVar21,uVar18);
        }
        (**(code **)(**(long **)(lVar12 + 0x220) + 0x110))(*(long **)(lVar12 + 0x220),uVar21,uVar18)
        ;
        if ((5 < uVar13) || ((0x37U >> (ulong)(uVar13 & 0x1f) & 1) == 0)) {
          uVar9 = thunk_EXT_FUN_8011000003a49114
                            ("AGXk: %s:%d:%s: !!! Invalid priority %d used for work queue 0x%p\n");
          return uVar9;
        }
        lVar14 = uVar21 * 4;
        puVar3 = (undefined4 *)(&DAT_fffffff007115cc0 + (int)lVar14);
        if (lVar14 - (int)lVar14 != 0) {
          puVar3 = (undefined4 *)
                   ((ulong)(&DAT_fffffff007115cc0 + lVar14) & 0xffffffffffff | 0x2bad000000000000);
        }
        thunk_EXT_FUN_8011000002958c50(lVar12,*puVar3);
        goto LAB_fffffff00818cb14;
      }
    }
    uVar13 = *(uint *)(lVar12 + 0x98);
    if (uVar13 == 0) {
      return 0;
    }
    uVar17 = 0;
    while ((lVar14 = *(long *)(lVar12 + 0x28 + uVar17 * 8), *(long *)(lVar14 + 0x218) == 0 ||
           (*(long *)(lVar14 + 0x228) == 0))) {
      uVar17 = uVar17 + 1;
      if (uVar13 == uVar17) {
        return 0;
      }
    }
    if (uVar13 == (uint)uVar17) {
      return 0;
    }
  }
LAB_fffffff00818cb14:
  lVar12 = *(long *)(*(long *)(param_1 + 0x530) + 0x1ac50);
  thunk_EXT_FUN_80110000039b5664
            (*(undefined8 *)(lVar12 + 0xe0),*(undefined8 *)(lVar12 + 0x1110 + lVar10 * 8),1);
  lVar15 = *(long *)(*(long *)(param_1 + 0x530) + 0x1ac50);
  lVar12 = lVar15 + 0x1188;
  lVar14 = (uVar17 & 0xffffffff) * 8;
  puVar4 = (undefined8 *)(lVar12 + (int)lVar14);
  if (lVar14 != (int)lVar14) {
    puVar4 = (undefined8 *)(lVar12 + lVar14 & 0xffffffffffffU | 0x2bad000000000000);
  }
  thunk_EXT_FUN_80110000039b5664(*(undefined8 *)(lVar15 + 200),*puVar4,1);
LAB_fffffff00818cb84:
  lVar12 = *(long *)(*(long *)(param_1 + 0x530) + 0x1ac50);
  thunk_EXT_FUN_80110000039b5664
            (*(undefined8 *)(lVar12 + 0xe0),*(undefined8 *)(lVar12 + lVar10 * 8 + 0x1138),1);
  lVar12 = *(long *)(*(long *)(param_1 + 0x530) + 0x1ac50);
  lVar10 = lVar12 + 0x11b0;
  lVar14 = (uVar17 & 0xffffffff) * 8;
  puVar4 = (undefined8 *)(lVar10 + (int)lVar14);
  if (lVar14 - (int)lVar14 != 0) {
    puVar4 = (undefined8 *)(lVar10 + lVar14 & 0xffffffffffffU | 0x2bad000000000000);
  }
  thunk_EXT_FUN_80110000039b5664(*(undefined8 *)(lVar12 + 0xd0),*puVar4,1);
  lVar10 = *(long *)(param_1 + 0x610) + 0x28;
  uVar21 = (uVar17 & 0xffffffff) << 3;
  uVar17 = -(uVar17 >> 0x1f & 1) & 0xfffffff800000000 | uVar21;
  iVar6 = (int)uVar21;
  puVar4 = (undefined8 *)(lVar10 + iVar6);
  if (uVar17 != (long)iVar6) {
    puVar4 = (undefined8 *)(lVar10 + uVar17 & 0xffffffffffff | 0x2bad000000000000);
  }
  return *puVar4;
LAB_fffffff00818cc38:
  lVar10 = *(long *)(param_1 + 0x610);
LAB_fffffff00818cc3c:
  uVar17 = (ulong)*(uint *)(lVar10 + 0x98);
  if ((uint)uVar21 < *(uint *)(lVar10 + 0x98)) {
    lVar10 = 2;
    uVar17 = uVar21;
    goto LAB_fffffff00818c730;
  }
LAB_fffffff00818c700:
  uVar13 = *(uint *)(param_1 + 0x834);
  if ((uint)uVar17 < uVar13) {
    lVar10 = 3;
  }
  else {
LAB_fffffff00818c718:
    uVar1 = *(int *)(param_1 + 0x830) + 1;
    uVar5 = 0;
    if (uVar13 != 0) {
      uVar5 = uVar1 / uVar13;
    }
    uVar1 = uVar1 - uVar5 * uVar13;
    *(uint *)(param_1 + 0x830) = uVar1;
    lVar10 = 4;
    uVar17 = (ulong)uVar1;
  }
  goto LAB_fffffff00818c730;
}

