// FUN_fffffff008195510 @ fffffff008195510 size=1704

/* WARNING: Removing unreachable block (ram,0xfffffff008195b10) */
/* WARNING: Removing unreachable block (ram,0xfffffff00819599c) */

undefined8
FUN_fffffff008195510
          (long param_1,long param_2,undefined8 param_3,uint *param_4,uint param_5,uint param_6,
          ulong param_7)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  ulong uVar5;
  uint uVar6;
  undefined *puVar7;
  int iVar8;
  long *plVar9;
  long *plVar10;
  undefined8 uVar11;
  long lVar12;
  long lVar13;
  long lVar14;
  uint uVar15;
  long lVar16;
  int *piVar17;
  ulong uVar18;
  ulong uVar19;
  ulong uVar20;
  ulong uVar21;
  long lVar22;
  ulong uVar23;
  
  puVar7 = PTR_DAT_fffffff007ca5f88;
  uVar15 = *(uint *)(*(long *)(param_1 + 0x530) + 0x1118c);
  if (uVar15 == 0) {
    uVar15 = *(uint *)(*(long *)(param_1 + 0x530) + 0x11124);
  }
  uVar3 = param_5;
  if (uVar15 <= param_5) {
    uVar3 = uVar15;
  }
  uVar4 = param_6;
  if (uVar15 <= param_6) {
    uVar4 = uVar15;
  }
  uVar2 = uVar4 + uVar3;
  lVar13 = *(long *)(param_1 + 0x610);
  if ((uint)(*(int *)(lVar13 + 0xf0) - *(int *)(lVar13 + 0xf4)) < uVar2) {
    if (*(long **)(lVar13 + 0xe8) != (long *)0x0) {
      (**(code **)(**(long **)(lVar13 + 0xe8) + 0x28))();
      lVar13 = *(long *)(param_1 + 0x610);
    }
    lVar16 = (long)(1 << (ulong)(*(uint *)puVar7 & 0x1f));
    uVar23 = (lVar16 + (ulong)uVar2 * 8) - 1 & -lVar16;
    *(int *)(lVar13 + 0xf0) = (int)(uVar23 >> 3);
    *(undefined4 *)(lVar13 + 0xf4) = 0;
    plVar9 = (long *)(**(code **)(DAT_fffffff00ae22f20 + 0x68))();
    if (plVar9 == (long *)0x0) {
      return 0;
    }
    lVar13 = *(long *)(param_1 + 0x530);
    uVar6 = *(uint *)(lVar13 + 0x18b70);
    plVar9[2] = *(long *)PTR_DAT_fffffff007ca61d0;
    iVar8 = FUN_fffffff0081e07cc(plVar9,lVar13,uVar23,uVar6 | 0x23);
    if (iVar8 != 0) {
      plVar10 = (long *)plVar9[0xc];
      if (plVar10 == (long *)0x0) {
        lVar13 = thunk_EXT_FUN_801100000297ea14(plVar9[9],0);
        plVar9[0xc] = lVar13;
        if (lVar13 == 0) goto LAB_fffffff008195b74;
        LOAcquire();
        DAT_fffffff00ae22f48 = DAT_fffffff00ae22f48 + plVar9[6];
        LORelease();
        plVar10 = (long *)plVar9[0xc];
      }
      lVar13 = (**(code **)(*plVar10 + 0x78))();
      if (lVar13 != 0) {
        plVar10 = (long *)plVar9[10];
        if (plVar10 == (long *)0x0) {
          plVar10 = (long *)(**(code **)(*(long *)plVar9[9] + 0x90))
                                      ((long *)plVar9[9],plVar9[3],0x800000084);
          if (plVar10 == (long *)0x0) goto LAB_fffffff008195b74;
          (**(code **)(*plVar10 + 0x20))();
          (**(code **)(*plVar10 + 0x28))(plVar10);
          plVar9[10] = (long)plVar10;
        }
        lVar13 = (**(code **)(*plVar10 + 0x98))();
        if (lVar13 != 0) {
          lVar13 = *(long *)(param_1 + 0x610);
          *(long **)(lVar13 + 0xe8) = plVar9;
          goto LAB_fffffff008195748;
        }
      }
    }
LAB_fffffff008195b74:
    (**(code **)(*plVar9 + 0x28))(plVar9);
  }
  else {
LAB_fffffff008195748:
    lVar16 = *(long *)(param_2 + 0x50);
    if (lVar16 != 0) {
      if (*(long *)(lVar16 + 0x20) != 0) {
        uVar23 = 0;
        uVar21 = 1;
        do {
          lVar13 = *(long *)(*(long *)(lVar16 + 0x18) + uVar23 * 8);
          if (lVar13 == 0) {
            return 0;
          }
          if ((*(byte *)(lVar13 + 0xb1) & 1) == 0) {
            return 0;
          }
          if (0x8000 < *(ulong *)(lVar13 + 0x78) ||
              (*(ulong *)(lVar13 + 0x78) & (ulong)(uint)~(-1 << (ulong)(*(uint *)puVar7 & 0x1f))) !=
              0) {
            return 0;
          }
          lVar12 = *(long *)(lVar13 + 0xb8);
          if (lVar12 == 0) {
            plVar9 = *(long **)(*(long *)(lVar13 + 0x50) + 0x4b0);
            lVar12 = (**(code **)(*plVar9 + 0x170))(plVar9,*(undefined8 *)(lVar13 + 0x28),0xb,0);
            if (lVar12 == 0) {
              return 0;
            }
            *(long *)(lVar13 + 0xb8) = lVar12;
          }
          thunk_EXT_FUN_8011000002969a34(param_3,lVar12);
          bVar1 = uVar21 < *(ulong *)(lVar16 + 0x20);
          uVar23 = uVar21;
          uVar21 = (ulong)((int)uVar21 + 1);
        } while (bVar1);
        lVar13 = *(long *)(param_1 + 0x610);
      }
      uVar23 = (ulong)(uint)(*(int *)(lVar13 + 0xf4) << 3);
      lVar13 = (**(code **)(**(long **)(*(long *)(lVar13 + 0xe8) + 0x50) + 0x98))();
      lVar12 = (**(code **)(**(long **)(*(long *)(*(long *)(param_1 + 0x610) + 0xe8) + 0x60) + 0x78)
               )();
      lVar22 = *(long *)(*(long *)(param_1 + 0x610) + 0xe8);
      if (*(long *)(lVar22 + 0x50) != 0) {
        thunk_EXT_FUN_8011000002969a34(param_3);
      }
      if (*(long *)(lVar22 + 0x58) != 0) {
        thunk_EXT_FUN_8011000002969a34(param_3);
      }
      uVar21 = lVar12 + uVar23;
      *param_4 = uVar3;
      param_4[1] = uVar4;
      *(ulong *)(param_4 + 2) = lVar13 + uVar23;
      lVar13 = *(long *)(*(long *)(param_1 + 0x530) + 0x111e8);
      uVar23 = uVar21;
      if (param_5 != 0) {
        if (uVar15 == 0) {
          lVar12 = 0;
        }
        else {
          uVar23 = 0;
          lVar12 = *(long *)(lVar13 + 0x10);
          do {
            piVar17 = (int *)(param_7 + uVar23 * 8);
            if (((param_7 ^ (ulong)piVar17) & 0xffc0000000000000) != 0) {
              piVar17 = (int *)((ulong)piVar17 & 0xffffffffffff | 0xc8a2000000000000);
            }
            if (*(ulong *)(lVar16 + 0x20) == 0) {
              return 0;
            }
            uVar6 = piVar17[1];
            uVar5 = 1;
            uVar19 = 0;
            while ((uVar20 = uVar5, lVar22 = *(long *)(*(long *)(lVar16 + 0x18) + uVar19 * 8),
                   lVar22 == 0 || (*(int *)(lVar22 + 0x88) != *piVar17))) {
              uVar5 = (ulong)((int)uVar20 + 1);
              uVar19 = uVar20;
              if (*(ulong *)(lVar16 + 0x20) <= uVar20) {
                return 0;
              }
            }
            if (*(ulong *)(lVar22 + 0x78) >> 3 <= (ulong)uVar6) {
              return 0;
            }
            if (*(long **)(lVar22 + 0xb8) == (long *)0x0) {
              return 0;
            }
            plVar9 = *(long **)(lVar12 + 0x4b0);
            uVar11 = (**(code **)(**(long **)(lVar22 + 0xb8) + 0x98))();
            lVar22 = *plVar9;
            lVar22 = (**(code **)(lVar22 + 0x208))(lVar22 + 0x208,plVar9,uVar11,0);
            lVar14 = uVar23 * 8;
            plVar9 = (long *)(uVar21 + (long)(int)lVar14);
            if (lVar14 - (int)lVar14 != 0) {
              plVar9 = (long *)(uVar21 + lVar14 & 0xffffffffffff | 0x2bad000000000000);
            }
            *plVar9 = lVar22 + (ulong)uVar6 * 8;
            uVar23 = uVar23 + 1;
          } while (uVar23 != uVar3);
          lVar12 = (ulong)uVar3 << 3;
        }
        uVar23 = uVar21 + (long)(int)lVar12;
        if (lVar12 != (int)lVar12) {
          uVar23 = uVar21 + lVar12 & 0xffffffffffff | 0x2bad000000000000;
        }
      }
      if ((param_6 != 0) && (uVar15 != 0)) {
        uVar21 = 0;
        lVar12 = (ulong)param_5 * 8;
        uVar5 = param_7 + (long)(int)lVar12;
        if (lVar12 != (int)lVar12) {
          uVar5 = param_7 + lVar12 & 0xffffffffffff | 0x2bad000000000000;
        }
        lVar13 = *(long *)(lVar13 + 0x10);
        do {
          if (*(ulong *)(lVar16 + 0x20) == 0) {
            return 0;
          }
          lVar12 = uVar21 * 8;
          iVar8 = (int)lVar12;
          piVar17 = (int *)(uVar5 + (long)iVar8);
          if (lVar12 - iVar8 != 0) {
            piVar17 = (int *)(uVar5 + lVar12 & 0xffffffffffff | 0x2bad000000000000);
          }
          uVar15 = piVar17[1];
          uVar19 = 1;
          uVar20 = 0;
          while ((uVar18 = uVar19, lVar22 = *(long *)(*(long *)(lVar16 + 0x18) + uVar20 * 8),
                 lVar22 == 0 || (*(int *)(lVar22 + 0x88) != *piVar17))) {
            uVar19 = (ulong)((int)uVar18 + 1);
            uVar20 = uVar18;
            if (*(ulong *)(lVar16 + 0x20) <= uVar18) {
              return 0;
            }
          }
          if (*(ulong *)(lVar22 + 0x78) >> 3 <= (ulong)uVar15) {
            return 0;
          }
          if (*(long **)(lVar22 + 0xb8) == (long *)0x0) {
            return 0;
          }
          plVar9 = *(long **)(lVar13 + 0x4b0);
          uVar11 = (**(code **)(**(long **)(lVar22 + 0xb8) + 0x98))();
          lVar22 = *plVar9;
          lVar22 = (**(code **)(lVar22 + 0x208))(lVar22 + 0x208,plVar9,uVar11,0);
          plVar9 = (long *)(uVar23 + (long)iVar8);
          if (lVar12 - iVar8 != 0) {
            plVar9 = (long *)(uVar23 + lVar12 & 0xffffffffffff | 0x2bad000000000000);
          }
          *plVar9 = lVar22 + (ulong)uVar15 * 8;
          uVar21 = uVar21 + 1;
        } while (uVar21 != uVar4);
      }
      *(uint *)(*(long *)(param_1 + 0x610) + 0xf4) =
           *(int *)(*(long *)(param_1 + 0x610) + 0xf4) + uVar2;
      return 1;
    }
  }
  return 0;
}

