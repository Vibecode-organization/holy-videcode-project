// FUN_fffffff0081ece8c @ fffffff0081ece8c size=1860

undefined8 FUN_fffffff0081ece8c(long *param_1,long param_2)

{
  undefined8 *puVar1;
  long *plVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  ulong uVar6;
  ulong uVar7;
  ulong uVar8;
  long lVar9;
  ulong uVar10;
  long lVar11;
  undefined8 uVar12;
  ulong uVar13;
  undefined8 *puVar14;
  long lVar15;
  long *plVar16;
  long *plVar17;
  long lVar18;
  ulong uVar19;
  undefined8 uVar20;
  undefined8 uVar21;
  
  plVar16 = (long *)0x0;
  if ((char)param_1[5] != '\0') {
    if ((char)param_1[5] == '\x02') {
      if (((param_1[0x48] == 0) || (iVar4 = thunk_EXT_FUN_801100000293f7e4(), iVar4 == 0)) ||
         (iVar4 = thunk_EXT_FUN_801100000293f644(param_1[0x48]), iVar4 != 0)) {
        plVar16 = (long *)0x0;
      }
      else {
        plVar16 = (long *)param_1[0x48];
        (**(code **)(*plVar16 + 0x20))(plVar16);
      }
    }
    (**(code **)(*param_1 + 0x120))(param_1);
  }
  plVar17 = (long *)param_1[0x48];
  if (plVar17 == (long *)0x0) {
LAB_fffffff0081ed170:
    lVar18 = param_1[2];
    lVar5 = param_1[0x46];
    uVar3 = *(uint *)(param_1 + 0x47);
    plVar17 = (long *)(**(code **)(DAT_fffffff00ae234d0 + 0x68))();
    if (plVar17 != (long *)0x0) {
      iVar4 = (**(code **)(PTR_DAT_fffffff007ca60d8 + 0x90))(plVar17,lVar18);
      if (iVar4 != 0) {
        uVar19 = plVar17[0x11] + (ulong)(uVar3 + 0x3f & 0xffffffc0);
        if (uVar19 == 0) {
          lVar18 = 0;
          uVar8 = plVar17[0x12];
        }
        else {
          uVar8 = uVar19 * 8;
          if (0x7fffffffffffffff < uVar8) {
            uVar8 = 0x8000000000000000;
          }
          if (uVar19 >> 0x3d != 0) {
            uVar8 = 0x8000000000000000;
          }
          lVar18 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ca4918,uVar8);
          if (lVar18 == 0) goto LAB_fffffff0081ed218;
          uVar8 = plVar17[0x12];
        }
        if (uVar8 != 0) {
          uVar6 = 0;
          lVar15 = plVar17[0x10];
          if ((3 < uVar8) && (0x1f < (ulong)(lVar18 - lVar15))) {
            lVar9 = 0;
            uVar6 = uVar8 & 0xfffffffffffffffc;
            uVar10 = uVar6;
            do {
              lVar11 = lVar9 * 8;
              iVar4 = (int)lVar11;
              puVar14 = (undefined8 *)(lVar15 + iVar4);
              if (lVar11 - iVar4 != 0) {
                puVar14 = (undefined8 *)(lVar15 + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
              }
              puVar1 = (undefined8 *)(lVar18 + iVar4);
              if (lVar11 - iVar4 != 0) {
                puVar1 = (undefined8 *)(lVar18 + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
              }
              uVar12 = *puVar14;
              uVar21 = puVar14[3];
              uVar20 = puVar14[2];
              puVar1[1] = puVar14[1];
              *puVar1 = uVar12;
              puVar1[3] = uVar21;
              puVar1[2] = uVar20;
              lVar9 = lVar9 + 4;
              uVar10 = uVar10 - 4;
            } while (uVar10 != 0);
            if (uVar8 == uVar6) goto LAB_fffffff0081ed33c;
          }
          lVar9 = uVar8 - uVar6;
          do {
            lVar11 = uVar6 * 8;
            iVar4 = (int)lVar11;
            puVar14 = (undefined8 *)(lVar15 + iVar4);
            if (lVar11 - iVar4 != 0) {
              puVar14 = (undefined8 *)(lVar15 + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
            }
            puVar1 = (undefined8 *)(lVar18 + iVar4);
            if (lVar11 - iVar4 != 0) {
              puVar1 = (undefined8 *)(lVar18 + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
            }
            *puVar1 = *puVar14;
            uVar6 = uVar6 + 1;
            lVar9 = lVar9 + -1;
          } while (lVar9 != 0);
        }
LAB_fffffff0081ed33c:
        lVar15 = plVar17[0x10];
        uVar8 = plVar17[0x11] << 3;
        if (0x7fffffffffffffff < uVar8) {
          uVar8 = 0x8000000000000000;
        }
        if ((ulong)plVar17[0x11] >> 0x3d != 0) {
          uVar8 = 0x8000000000000000;
        }
        plVar17[0x10] = 0;
        thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ca4968,lVar15,uVar8);
        plVar17[0x10] = lVar18;
        plVar17[0x11] = uVar19;
        if (uVar3 != 0) {
          lVar15 = 0;
          lVar18 = 0;
          do {
            uVar19 = plVar17[0x12];
            lVar9 = plVar17[0x10];
            if (uVar19 < (ulong)plVar17[0x11]) {
              uVar12 = *(undefined8 *)(lVar5 + lVar18 * 8);
              plVar17[0x12] = uVar19 + 1;
              lVar11 = uVar19 * 8;
              puVar14 = (undefined8 *)(lVar9 + (int)lVar11);
              if (lVar11 - (int)lVar11 != 0) {
                puVar14 = (undefined8 *)(lVar9 + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
              }
              *puVar14 = uVar12;
            }
            lVar11 = lVar18 * 8;
            iVar4 = (int)lVar11;
            puVar14 = (undefined8 *)(lVar9 + iVar4);
            if (lVar11 - iVar4 != 0) {
              puVar14 = (undefined8 *)(lVar9 + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
            }
            (**(code **)(*(long *)*puVar14 + 0x20))();
            plVar2 = (long *)(plVar17[0x10] + (long)iVar4);
            if (lVar11 - iVar4 != 0) {
              plVar2 = (long *)(plVar17[0x10] + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
            }
            lVar9 = (**(code **)(**(long **)(*plVar2 + 0x18) + 0x88))();
            plVar17[0x13] = plVar17[0x13] + lVar9;
            lVar18 = lVar18 + 1;
            lVar15 = lVar15 + 8;
          } while ((ulong)uVar3 * 8 - lVar15 != 0);
        }
        param_1[0x48] = (long)plVar17;
        goto LAB_fffffff0081ed454;
      }
LAB_fffffff0081ed218:
      (**(code **)(*plVar17 + 0x28))(plVar17);
    }
    uVar12 = 0xe00002bd;
    param_1[0x48] = 0;
    if (plVar16 != (long *)0x0) {
      thunk_EXT_FUN_801100000293f7a0(plVar16);
      (**(code **)(*plVar16 + 0x28))(plVar16);
      uVar12 = 0xe00002bd;
    }
  }
  else {
    if ((int)param_1[0x23] != 0) {
      uVar19 = 0;
      do {
        lVar18 = param_1[0x48];
        plVar17 = *(long **)(*(long *)(param_1[0x22] + uVar19 * 8) + 0x18);
        thunk_EXT_FUN_801100000293ed70(lVar18);
        uVar8 = *(ulong *)(lVar18 + 0x88);
        uVar6 = *(ulong *)(lVar18 + 0x90);
        if (uVar6 == uVar8) {
          uVar8 = uVar8 + 0x40;
          if (uVar8 == 0) {
            lVar5 = 0;
            uVar6 = 0xffffffffffffffc0;
LAB_fffffff0081ecfd0:
            uVar10 = 0;
            uVar7 = *(ulong *)(lVar18 + 0x80);
            if ((3 < uVar6) && (0x1f < lVar5 - uVar7)) {
              lVar15 = 0;
              uVar10 = uVar6 & 0xfffffffffffffffc;
              uVar13 = uVar10;
              do {
                puVar14 = (undefined8 *)(uVar7 + lVar15 * 8);
                if (((uVar7 ^ (ulong)puVar14) & 0xffc0000000000000) != 0) {
                  puVar14 = (undefined8 *)((ulong)puVar14 & 0xffffffffffff | 0xc8a2000000000000);
                }
                lVar9 = lVar15 * 8;
                puVar1 = (undefined8 *)(lVar5 + (int)lVar9);
                if (lVar9 - (int)lVar9 != 0) {
                  puVar1 = (undefined8 *)(lVar5 + lVar9 & 0xffffffffffffU | 0x2bad000000000000);
                }
                uVar12 = *puVar14;
                uVar21 = puVar14[3];
                uVar20 = puVar14[2];
                puVar1[1] = puVar14[1];
                *puVar1 = uVar12;
                puVar1[3] = uVar21;
                puVar1[2] = uVar20;
                lVar15 = lVar15 + 4;
                uVar13 = uVar13 - 4;
              } while (uVar13 != 0);
              if (uVar6 == uVar10) goto LAB_fffffff0081ed084;
            }
            lVar15 = uVar6 - uVar10;
            do {
              lVar9 = uVar10 * 8;
              iVar4 = (int)lVar9;
              puVar14 = (undefined8 *)(uVar7 + (long)iVar4);
              if (lVar9 - iVar4 != 0) {
                puVar14 = (undefined8 *)(uVar7 + lVar9 & 0xffffffffffff | 0x2bad000000000000);
              }
              puVar1 = (undefined8 *)(lVar5 + iVar4);
              if (lVar9 - iVar4 != 0) {
                puVar1 = (undefined8 *)(lVar5 + lVar9 & 0xffffffffffffU | 0x2bad000000000000);
              }
              *puVar1 = *puVar14;
              uVar10 = uVar10 + 1;
              lVar15 = lVar15 + -1;
            } while (lVar15 != 0);
LAB_fffffff0081ed084:
            uVar12 = *(undefined8 *)(lVar18 + 0x80);
            uVar6 = *(ulong *)(lVar18 + 0x88) << 3;
            if (0x7fffffffffffffff < uVar6) {
              uVar6 = 0x8000000000000000;
            }
            if (*(ulong *)(lVar18 + 0x88) >> 0x3d != 0) {
              uVar6 = 0x8000000000000000;
            }
            *(undefined8 *)(lVar18 + 0x80) = 0;
            thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ca4968,uVar12,uVar6);
            *(long *)(lVar18 + 0x80) = lVar5;
            *(ulong *)(lVar18 + 0x88) = uVar8;
            uVar6 = *(ulong *)(lVar18 + 0x90);
            goto LAB_fffffff0081ed0b4;
          }
          uVar6 = uVar8 * 8;
          if (0x7fffffffffffffff < uVar6) {
            uVar6 = 0x8000000000000000;
          }
          if (uVar8 >> 0x3d != 0) {
            uVar6 = 0x8000000000000000;
          }
          lVar5 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ca4918,uVar6);
          if (lVar5 != 0) {
            uVar6 = *(ulong *)(lVar18 + 0x90);
            if (uVar6 != 0) goto LAB_fffffff0081ecfd0;
            goto LAB_fffffff0081ed084;
          }
        }
        else {
LAB_fffffff0081ed0b4:
          if (uVar6 == uVar8) {
            uVar12 = thunk_EXT_FUN_8011000003a49114
                               (
                               "AGXk: %s:%d:%s: !!! AGXParameterMemoryVirtual: no space for additional mapping\n"
                               );
            return uVar12;
          }
          lVar5 = (**(code **)(*(long *)plVar17[3] + 0x88))();
          iVar4 = thunk_EXT_FUN_801100000293f7e4(lVar18);
          if (iVar4 != 0) {
            iVar4 = thunk_EXT_FUN_801100000297b3fc(plVar17);
            if (iVar4 != 0) goto LAB_fffffff0081ecf50;
            thunk_EXT_FUN_80110000029718c4(*(undefined8 *)(lVar18 + 0x10),lVar5,0);
          }
          *(long *)(lVar18 + 0x98) = *(long *)(lVar18 + 0x98) + lVar5;
          (**(code **)(*plVar17 + 0x20))(plVar17);
          uVar8 = *(ulong *)(lVar18 + 0x90);
          if (uVar8 < *(ulong *)(lVar18 + 0x88)) {
            *(ulong *)(lVar18 + 0x90) = uVar8 + 1;
            lVar5 = uVar8 * 8;
            puVar14 = (undefined8 *)(*(long *)(lVar18 + 0x80) + (long)(int)lVar5);
            if (lVar5 - (int)lVar5 != 0) {
              puVar14 = (undefined8 *)
                        (*(long *)(lVar18 + 0x80) + lVar5 & 0xffffffffffffU | 0x2bad000000000000);
            }
            *puVar14 = plVar17;
          }
        }
LAB_fffffff0081ecf50:
        thunk_EXT_FUN_801100000293ed7c(lVar18);
        uVar19 = uVar19 + 1;
      } while (uVar19 < *(uint *)(param_1 + 0x23));
      plVar17 = (long *)param_1[0x48];
      if (plVar17 == (long *)0x0) goto LAB_fffffff0081ed170;
    }
LAB_fffffff0081ed454:
    uVar12 = thunk_EXT_FUN_801100000293f644(plVar17);
    if ((int)uVar12 == 0) {
      if (plVar16 != (long *)0x0) {
        thunk_EXT_FUN_801100000293f7a0(plVar16);
        (**(code **)(*plVar16 + 0x28))(plVar16);
      }
      plVar16 = (long *)param_1[0x48];
      *(long **)(param_2 + 0xbf8) = plVar16;
      (**(code **)(*plVar16 + 0x20))();
      if (param_1[0x45] == 0) {
        uVar12 = 0;
      }
      else {
        uVar12 = thunk_EXT_FUN_801100000297b3fc(*(undefined8 *)(param_1[0x45] + 0x20));
        if ((int)uVar12 == 0) {
          (**(code **)(**(long **)(param_1[0x45] + 0x20) + 0x20))();
          uVar12 = 0;
          *(undefined8 *)(param_2 + 0xc18) = *(undefined8 *)(param_1[0x45] + 0x20);
        }
      }
    }
    else {
      (**(code **)(*param_1 + 0x120))(param_1);
      if (plVar16 != (long *)0x0) {
        thunk_EXT_FUN_801100000293f7a0(plVar16);
        (**(code **)(*plVar16 + 0x28))(plVar16);
      }
    }
  }
  return uVar12;
}

