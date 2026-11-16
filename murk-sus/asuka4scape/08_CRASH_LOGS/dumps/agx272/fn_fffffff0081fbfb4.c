// FUN_fffffff0081fbfb4 @ fffffff0081fbfb4 size=1820

/* WARNING: Removing unreachable block (ram,0xfffffff0081fc3dc) */

ulong FUN_fffffff0081fbfb4(long *param_1,long *param_2)

{
  undefined8 *puVar1;
  int *piVar2;
  uint uVar3;
  bool bVar4;
  bool bVar5;
  uint uVar6;
  int iVar7;
  ulong uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  long *plVar11;
  long lVar12;
  long lVar13;
  ulong uVar14;
  long lVar15;
  ulong uVar16;
  long lVar17;
  ulong uVar18;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  uint local_64;
  
  uVar3 = *(uint *)(param_2[3] + 0x78);
  if ((((*(byte *)(param_1 + 0x5e) & 1) != 0) || (*(int *)((long)param_1 + 0x274) != 0)) &&
     (uVar6 = (**(code **)(*param_1 + 0x160))(param_1), (uVar3 & (uVar6 ^ 0xffffffff)) != 0)) {
    return 1;
  }
  if (*(uint *)(param_1 + 0x3d) != 0xffffffff) {
    LOAcquire();
    *(ulong *)(param_1[2] + 0x1ac68) =
         *(ulong *)(param_1[2] + 0x1ac68) | 1L << ((ulong)*(uint *)(param_1 + 0x3d) & 0x3f);
    LORelease();
  }
  uVar8 = (**(code **)(*param_2 + 0x98))(param_2);
  if ((uVar8 >> 0x27 & 1) == 0) {
    lVar12 = param_1[2];
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar12 + 0x11df8));
    if ((int)param_1[0x3d] != -1) {
      lVar13 = (long)(int)param_1[0x3d] * 4;
      piVar2 = (int *)(*(long *)(lVar12 + 0x11e28) + (long)(int)lVar13);
      if (lVar13 - (int)lVar13 != 0) {
        piVar2 = (int *)(*(long *)(lVar12 + 0x11e28) + lVar13 & 0xffffffffffffU | 0x2bad000000000000
                        );
      }
      *piVar2 = *piVar2 + 1;
    }
    thunk_EXT_FUN_8011000003224180(param_1[0x3a]);
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar12 + 0x11df8));
    uVar18 = (ulong)*(uint *)(param_1 + 0x3d);
    if (*(uint *)(param_1 + 0x3d) != 0xffffffff) goto LAB_fffffff0081fc0f4;
    uVar18 = 0xffffffff;
    bVar4 = true;
  }
  else {
    uVar18 = 0x40;
LAB_fffffff0081fc0f4:
    uVar16 = -(uVar18 >> 0x1f) & 0xfffffff800000000 | uVar18 << 3;
    iVar7 = (int)(uVar18 << 3);
    puVar1 = (undefined8 *)(DAT_fffffff00ae23b38 + iVar7);
    if (uVar16 != (long)iVar7) {
      puVar1 = (undefined8 *)(DAT_fffffff00ae23b38 + uVar16 & 0xffffffffffff | 0x2bad000000000000);
    }
    thunk_EXT_FUN_80110000032222a8(*puVar1);
    bVar4 = false;
  }
  lVar12 = param_1[2];
  thunk_EXT_FUN_8011000003224180(*(undefined8 *)(lVar12 + 0x11a70));
  thunk_EXT_FUN_8011000003224180(*(undefined8 *)(lVar12 + 0x11a78));
  if (*(int *)(param_1[2] + 0x11a68) == 0) {
    bVar5 = (*(byte *)(param_2 + 0xb) & 8) == 0;
    if ((((0xffffff9fffffffff < uVar8 && bVar5) && 0xffffffa0bfffffff < uVar8) &&
        uVar8 + 0x5e76c00000 < 0xfffffffff8000000) && uVar8 < 0xffffffa17fffffff ||
        (((0xffffff9fffffffff < uVar8 && bVar5) && 0xffffffa0bfffffff < uVar8) &&
        uVar8 + 0x5e76c00000 < 0xfffffffff8000000) && uVar8 == 0xffffffa17fffffff) {
      lVar12 = param_1[0x5a];
      uVar9 = (**(code **)(*param_2 + 200))(param_2);
      if ((DAT_fffffff00ae25928 & 1) == 0) {
        FUN_fffffff008211088(*(undefined8 *)(lVar12 + 0x18));
      }
      else {
        uVar16 = thunk_EXT_FUN_80110000039eac08(*(undefined8 *)(lVar12 + 0x10),uVar8,uVar9);
        if ((uVar16 & 1) != 0) {
          (**(code **)(**(long **)(param_1[2] + 0x4b0) + 0x228))
                    (*(long **)(param_1[2] + 0x4b0),uVar8,0,uVar18);
          plVar11 = *(long **)(param_1[2] + 0x4b0);
          lVar12 = *plVar11;
          (**(code **)(lVar12 + 0x238))
                    (lVar12 + 0x238,plVar11,*(undefined4 *)(param_1[2] + 0x109f4));
        }
      }
    }
    lVar12 = thunk_EXT_FUN_8011000003890f30(param_2[3],&DAT_fffffff00ae21bd0);
    if (lVar12 == 0) {
      lVar12 = thunk_EXT_FUN_8011000003890f30(param_2[3],*(undefined8 *)PTR_DAT_fffffff007ca6050);
      uVar16 = 0;
      if (lVar12 != 0) {
        local_64 = 0;
        uVar3 = *(uint *)(lVar12 + 0x90);
        lVar13 = (**(code **)(*param_2 + 0x98))(param_2);
        local_80 = 0;
        uStack_78 = 0;
        local_70 = 0;
        thunk_EXT_FUN_801100000293e3ec(&local_80,lVar12);
        do {
          while( true ) {
            plVar11 = (long *)thunk_EXT_FUN_801100000293e410(&local_80,&local_64);
            if (plVar11 == (long *)0x0) {
              lVar15 = *(long *)(lVar12 + 0x88);
              plVar11 = *(long **)(lVar12 + 0xb0);
              if (plVar11 == (long *)0x0) {
                lVar17 = 0;
              }
              else {
                lVar17 = (**(code **)(*plVar11 + 0xb0))(plVar11);
                if ((DAT_fffffff00ae25928 & 1) == 0) {
                  FUN_fffffff008210f0c
                            (*(undefined8 *)(param_1[0x5a] + 0x18),plVar11,lVar15 + lVar13,lVar17);
                  bVar5 = true;
                }
                else {
                  iVar7 = thunk_EXT_FUN_80110000039ea854
                                    (*(undefined8 *)(param_1[0x5a] + 0x10),plVar11,lVar15 + lVar13,
                                     lVar17);
                  bVar5 = iVar7 == 0;
                }
                if ((DAT_fffffff00ae25928 & 1) == 0) {
                  FUN_fffffff00820f890(*(undefined8 *)(param_1[0x5a] + 0x18));
                }
                else {
                  thunk_EXT_FUN_80110000039e91e4(*(undefined8 *)(param_1[0x5a] + 0x10));
                }
                if (!bVar5) goto LAB_fffffff0081fc688;
              }
              plVar11 = *(long **)(lVar12 + 0xb8);
              if (plVar11 != (long *)0x0) {
                lVar12 = param_1[0x5a];
                uVar9 = (**(code **)(*plVar11 + 0xb0))(plVar11);
                if ((DAT_fffffff00ae25928 & 1) == 0) {
                  FUN_fffffff008210f0c
                            (*(undefined8 *)(lVar12 + 0x18),plVar11,lVar15 + lVar13 + lVar17,uVar9);
                  bVar5 = true;
                }
                else {
                  iVar7 = thunk_EXT_FUN_80110000039ea854
                                    (*(undefined8 *)(lVar12 + 0x10),plVar11,lVar15 + lVar13 + lVar17
                                    );
                  bVar5 = iVar7 == 0;
                }
                if ((DAT_fffffff00ae25928 & 1) == 0) {
                  FUN_fffffff00820f890(*(undefined8 *)(param_1[0x5a] + 0x18));
                }
                else {
                  thunk_EXT_FUN_80110000039e91e4(*(undefined8 *)(param_1[0x5a] + 0x10));
                }
                if (!bVar5) goto LAB_fffffff0081fc688;
              }
              thunk_EXT_FUN_801100000293e4f8(&local_80);
              uVar16 = 1;
              goto LAB_fffffff0081fc54c;
            }
            lVar15 = param_1[0x5a];
            lVar17 = lVar13 + (ulong)local_64 * (ulong)uVar3;
            uVar9 = (**(code **)(*plVar11 + 0xb0))();
            if ((DAT_fffffff00ae25928 & 1) == 0) {
              FUN_fffffff008210f0c(*(undefined8 *)(lVar15 + 0x18),plVar11,lVar17,uVar9);
              bVar5 = true;
            }
            else {
              iVar7 = thunk_EXT_FUN_80110000039ea854(*(undefined8 *)(lVar15 + 0x10),plVar11,lVar17);
              bVar5 = iVar7 == 0;
            }
            if ((DAT_fffffff00ae25928 & 1) == 0) break;
            thunk_EXT_FUN_80110000039e91e4(*(undefined8 *)(param_1[0x5a] + 0x10));
            if (!bVar5) goto LAB_fffffff0081fc688;
          }
          FUN_fffffff00820f890(*(undefined8 *)(param_1[0x5a] + 0x18));
        } while (bVar5);
        goto LAB_fffffff0081fc688;
      }
    }
    else {
      lVar12 = param_1[0x5a];
      uVar9 = thunk_EXT_FUN_801100000297dd00(param_2[3]);
      uVar10 = (**(code **)(*param_2 + 200))(param_2);
      if ((DAT_fffffff00ae25928 & 1) == 0) {
        FUN_fffffff008210f0c(*(undefined8 *)(lVar12 + 0x18),uVar9,uVar8,uVar10);
        uVar16 = 1;
      }
      else {
        iVar7 = thunk_EXT_FUN_80110000039ea854(*(undefined8 *)(lVar12 + 0x10),uVar9,uVar8);
        uVar16 = (ulong)(iVar7 == 0);
      }
LAB_fffffff0081fc54c:
      if ((1 << (ulong)(*(byte *)((long)param_2 + 0x59) & 0x1f) & 0x5f80U) != 0 && (int)uVar16 != 0)
      {
        if ((DAT_fffffff00ae25928 & 1) == 0) {
          FUN_fffffff00820f890(*(undefined8 *)(param_1[0x5a] + 0x18));
        }
        else {
          thunk_EXT_FUN_80110000039e91e4(*(undefined8 *)(param_1[0x5a] + 0x10));
        }
        uVar16 = 1;
      }
    }
    lVar12 = param_1[2];
    thunk_EXT_FUN_8011000003224d30(*(undefined8 *)(lVar12 + 0x11a78));
    thunk_EXT_FUN_8011000003224d30(*(undefined8 *)(lVar12 + 0x11a70));
    if (!bVar4) {
      uVar14 = -(uVar18 >> 0x1f) & 0xfffffff800000000 | uVar18 << 3;
      iVar7 = (int)(uVar18 << 3);
      puVar1 = (undefined8 *)(DAT_fffffff00ae23b38 + iVar7);
      if (uVar14 != (long)iVar7) {
        puVar1 = (undefined8 *)(DAT_fffffff00ae23b38 + uVar14 & 0xffffffffffff | 0x2bad000000000000)
        ;
      }
      thunk_EXT_FUN_8011000003222de0(*puVar1);
    }
    if ((uVar8 >> 0x27 & 1) == 0) {
      lVar13 = param_1[2];
      lVar12 = param_1[0x3d];
      thunk_EXT_FUN_8011000003224d30(param_1[0x3a]);
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar13 + 0x11df8));
      if ((int)lVar12 != -1) {
        lVar12 = (long)(int)lVar12 * 4;
        piVar2 = (int *)(*(long *)(lVar13 + 0x11e28) + (long)(int)lVar12);
        if (lVar12 - (int)lVar12 != 0) {
          piVar2 = (int *)(*(long *)(lVar13 + 0x11e28) + lVar12 & 0xffffffffffffU |
                          0x2bad000000000000);
        }
        if (((*piVar2 == 0) || (iVar7 = *piVar2 + -1, *piVar2 = iVar7, iVar7 == 0)) &&
           ((*(byte *)(lVar13 + 0x11e0c) & 1) != 0)) {
          thunk_EXT_FUN_801100000295c97c(*(undefined8 *)(*(long *)(lVar13 + 0x11df0) + 0x160));
        }
      }
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar13 + 0x11df8));
    }
    return uVar16;
  }
LAB_fffffff0081fc688:
  uVar8 = thunk_EXT_FUN_8011000003a49114("AGXk: %s:%d:%s: !!! AGXSecureGart::unmap\n");
  return uVar8;
}

