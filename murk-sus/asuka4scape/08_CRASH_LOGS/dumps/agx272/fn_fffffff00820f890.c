// FUN_fffffff00820f890 @ fffffff00820f890 size=2172

void FUN_fffffff00820f890(long param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  int *piVar3;
  long *plVar4;
  uint uVar5;
  undefined *puVar6;
  code *pcVar7;
  bool bVar8;
  undefined8 uVar9;
  long lVar10;
  ulong uVar11;
  ulong uVar12;
  long lVar13;
  int iVar14;
  ulong uVar15;
  ulong uVar16;
  ulong uVar17;
  ulong uVar18;
  int iVar19;
  long lVar20;
  long *plVar21;
  ulong uVar22;
  long *plVar23;
  long lVar24;
  int iVar25;
  long lVar26;
  ulong uVar27;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000038ff214(*(undefined8 *)(param_1 + 0xc0));
  if (*(int *)(param_1 + 0x3d8) == 0) goto LAB_fffffff0082100d8;
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0xb8));
  uVar11 = (ulong)*(uint *)(param_1 + 0x3d8);
  if (*(uint *)(param_1 + 0x3d8) != 0) {
    uVar18 = 0;
    do {
      uVar15 = param_1 + 0xd8U + uVar18 * 0x18;
      if (((param_1 + 0xd8U ^ uVar15) & 0xffc0000000000000) != 0) {
        uVar15 = uVar15 & 0xffffffffffff | 0xc8a2000000000000;
      }
      uVar22 = *(ulong *)(uVar15 + 8);
      lVar10 = *(long *)(uVar15 + 0x10);
      if (uVar22 < lVar10 + uVar22) {
        uVar5 = *(uint *)PTR_DAT_fffffff007ca5f88;
        uVar16 = uVar22;
        do {
          *(undefined8 *)
           (*(long *)(*(long *)(*(long *)(param_1 + 0x30 + (uVar16 >> 0x21 & 0x40 | 0x30)) +
                               (uVar16 >> 0x24 & 7) * 8) + (uVar16 >> 0x19 & 0x7ff) * 8) +
           (uVar16 >> 0xe & 0x7ff) * 8) = 0;
          uVar16 = uVar16 + (long)(1 << (ulong)(uVar5 & 0x1f));
          uVar22 = *(ulong *)(uVar15 + 8);
          lVar10 = *(long *)(uVar15 + 0x10);
        } while (uVar16 < lVar10 + uVar22);
      }
      uVar17 = uVar22 >> 0x24 & 7;
      uVar15 = (uVar22 + lVar10) - 1;
      uVar16 = uVar15 >> 0x24 & 7;
      if (uVar17 <= uVar16) {
        lVar10 = param_1 + 0x30 + (uVar22 >> 0x27 & 1) * 0x40;
        uVar11 = uVar17;
        do {
          lVar26 = uVar11 * 8;
          iVar25 = (int)lVar26;
          plVar21 = (long *)(*(long *)(lVar10 + 0x18) + (long)iVar25);
          if (lVar26 - iVar25 != 0) {
            plVar21 = (long *)(*(long *)(lVar10 + 0x18) + lVar26 & 0xffffffffffffU |
                              0x2bad000000000000);
          }
          puVar2 = (undefined8 *)(*(long *)(lVar10 + 0x10) + (long)iVar25);
          if (lVar26 - iVar25 != 0) {
            puVar2 = (undefined8 *)
                     (*(long *)(lVar10 + 0x10) + lVar26 & 0xffffffffffffU | 0x2bad000000000000);
          }
          lVar24 = *plVar21;
          plVar21 = (long *)*puVar2;
          uVar12 = uVar22 >> 0x19 & 0x7ff;
          if (uVar11 != uVar17) {
            uVar12 = 0;
          }
          uVar27 = uVar15 >> 0x19 & 0x7ff;
          if (uVar11 != uVar16) {
            uVar27 = ((ulong)(long)(1 << (ulong)(*(uint *)PTR_DAT_fffffff007ca5f88 & 0x1f)) >> 3) -
                     1;
          }
          if (uVar12 <= uVar27) {
            plVar4 = (long *)(*(long *)(lVar10 + 0x38) + (long)iVar25);
            if (lVar26 - iVar25 != 0) {
              plVar4 = (long *)(*(long *)(lVar10 + 0x38) + lVar26 & 0xffffffffffffU |
                               0x2bad000000000000);
            }
            lVar13 = *plVar4;
            do {
              lVar20 = uVar12 * 4;
              iVar19 = (int)lVar20;
              piVar3 = (int *)(lVar13 + iVar19);
              if (lVar20 - iVar19 != 0) {
                piVar3 = (int *)(lVar13 + lVar20 & 0xffffffffffffU | 0x2bad000000000000);
              }
              if (*piVar3 == 1) {
                plVar4 = (long *)(*(long *)(lVar10 + 0x28) + (long)iVar25);
                if (lVar26 - iVar25 != 0) {
                  plVar4 = (long *)(*(long *)(lVar10 + 0x28) + lVar26 & 0xffffffffffffU |
                                   0x2bad000000000000);
                }
                lVar13 = uVar12 * 8;
                iVar14 = (int)lVar13;
                puVar2 = (undefined8 *)(*plVar4 + (long)iVar14);
                if (lVar13 - iVar14 != 0) {
                  puVar2 = (undefined8 *)(*plVar4 + lVar13 & 0xffffffffffffU | 0x2bad000000000000);
                }
                puVar1 = (undefined8 *)(lVar24 + iVar14);
                if (lVar13 - iVar14 != 0) {
                  puVar1 = (undefined8 *)(lVar24 + lVar13 & 0xffffffffffffU | 0x2bad000000000000);
                }
                plVar23 = (long *)*puVar2;
                plVar4 = (long *)(*(long *)(lVar10 + 0x30) + (long)iVar25);
                if (lVar26 - iVar25 != 0) {
                  plVar4 = (long *)(*(long *)(lVar10 + 0x30) + lVar26 & 0xffffffffffffU |
                                   0x2bad000000000000);
                }
                *puVar1 = 0;
                puVar1 = (undefined8 *)(*plVar4 + (long)iVar14);
                if (lVar13 - iVar14 != 0) {
                  puVar1 = (undefined8 *)(*plVar4 + lVar13 & 0xffffffffffffU | 0x2bad000000000000);
                }
                *puVar1 = 0;
                *puVar2 = 0;
                (**(code **)(*plVar23 + 0xe0))(plVar23,0);
                (**(code **)(*plVar23 + 0x28))(plVar23);
                uVar5 = *(uint *)(param_1 + 0xb0);
                if (uVar5 != 0xffffffff) {
                  if (*(int *)(param_1 + 0xcc) == 0) {
                    (**(code **)(**(long **)(param_1 + 0x10) + 0xcf0))
                              (*(long **)(param_1 + 0x10),(ulong)uVar5,0,0);
                  }
                  else if (*(int *)(param_1 + 0xd0) == 0) {
                    SysOp_W(0,8,1,0,0);
                  }
                  else {
                    SysOp_W(0,8,1,2,((ulong)uVar5 & 0x1ff) << 0x30);
                  }
                }
              }
              plVar4 = (long *)(*(long *)(lVar10 + 0x38) + (long)iVar25);
              if (lVar26 - iVar25 != 0) {
                plVar4 = (long *)(*(long *)(lVar10 + 0x38) + lVar26 & 0xffffffffffffU |
                                 0x2bad000000000000);
              }
              lVar13 = *plVar4;
              piVar3 = (int *)(lVar13 + iVar19);
              if (lVar20 != iVar19) {
                piVar3 = (int *)(lVar13 + lVar20 & 0xffffffffffffU | 0x2bad000000000000);
              }
              *piVar3 = *piVar3 + -1;
              uVar12 = uVar12 + 1;
            } while (uVar12 <= uVar27);
          }
          lVar24 = uVar11 * 4;
          iVar19 = (int)lVar24;
          piVar3 = (int *)(*(long *)(lVar10 + 0x20) + (long)iVar19);
          if (lVar24 - iVar19 != 0) {
            piVar3 = (int *)(*(long *)(lVar10 + 0x20) + lVar24 & 0xffffffffffffU |
                            0x2bad000000000000);
          }
          if (*piVar3 == 1) {
            puVar2 = (undefined8 *)(*(long *)(lVar10 + 8) + (long)iVar25);
            if (lVar26 - iVar25 != 0) {
              puVar2 = (undefined8 *)
                       (*(long *)(lVar10 + 8) + lVar26 & 0xffffffffffffU | 0x2bad000000000000);
            }
            *puVar2 = 0;
            puVar6 = PTR_DAT_fffffff007ca5f88;
            uVar5 = *(uint *)PTR_DAT_fffffff007ca5f88;
            puVar2 = (undefined8 *)(*(long *)(lVar10 + 0x28) + (long)iVar25);
            if (lVar26 - iVar25 != 0) {
              puVar2 = (undefined8 *)
                       (*(long *)(lVar10 + 0x28) + lVar26 & 0xffffffffffffU | 0x2bad000000000000);
            }
            uVar9 = *puVar2;
            *puVar2 = 0;
            thunk_EXT_FUN_80110000038fe768
                      (&DAT_fffffff007ca4fa8,uVar9,
                       (long)(int)(1 << (ulong)(uVar5 & 0x1f) & 0xfffffff8));
            lVar13 = *(long *)(lVar10 + 0x30);
            puVar2 = (undefined8 *)(*(long *)(lVar10 + 0x28) + (long)iVar25);
            if (lVar26 - iVar25 != 0) {
              puVar2 = (undefined8 *)
                       (*(long *)(lVar10 + 0x28) + lVar26 & 0xffffffffffffU | 0x2bad000000000000);
            }
            *puVar2 = 0;
            uVar12 = (ulong)(int)(1 << (ulong)(*(uint *)puVar6 & 0x1f) & 0xfffffff8);
            if (0x7fffffffffffffff < uVar12) {
              uVar12 = 0x8000000000000000;
            }
            puVar2 = (undefined8 *)(lVar13 + iVar25);
            if (lVar26 - iVar25 != 0) {
              puVar2 = (undefined8 *)(lVar13 + lVar26 & 0xffffffffffffU | 0x2bad000000000000);
            }
            uVar9 = *puVar2;
            *puVar2 = 0;
            thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ca4ff8,uVar9,uVar12);
            lVar13 = *(long *)(lVar10 + 0x38);
            puVar2 = (undefined8 *)(*(long *)(lVar10 + 0x30) + (long)iVar25);
            if (lVar26 - iVar25 != 0) {
              puVar2 = (undefined8 *)
                       (*(long *)(lVar10 + 0x30) + lVar26 & 0xffffffffffffU | 0x2bad000000000000);
            }
            *puVar2 = 0;
            puVar2 = (undefined8 *)(lVar13 + iVar25);
            if (lVar26 - iVar25 != 0) {
              puVar2 = (undefined8 *)(lVar13 + lVar26 & 0xffffffffffffU | 0x2bad000000000000);
            }
            uVar5 = *(uint *)puVar6;
            uVar9 = *puVar2;
            *puVar2 = 0;
            thunk_EXT_FUN_80110000038fe6b0
                      (uVar9,(ulong)(long)(1 << (ulong)(uVar5 & 0x1f)) >> 1 & 0x7ffffffffffffffc);
            puVar2 = (undefined8 *)(*(long *)(lVar10 + 0x38) + (long)iVar25);
            if (lVar26 - iVar25 != 0) {
              puVar2 = (undefined8 *)
                       (*(long *)(lVar10 + 0x38) + lVar26 & 0xffffffffffffU | 0x2bad000000000000);
            }
            lVar13 = *(long *)(lVar10 + 0x10);
            puVar1 = (undefined8 *)(*(long *)(lVar10 + 0x18) + (long)iVar25);
            if (lVar26 - iVar25 != 0) {
              puVar1 = (undefined8 *)
                       (*(long *)(lVar10 + 0x18) + lVar26 & 0xffffffffffffU | 0x2bad000000000000);
            }
            *puVar2 = 0;
            puVar2 = (undefined8 *)(lVar13 + iVar25);
            if (lVar26 - iVar25 != 0) {
              puVar2 = (undefined8 *)(lVar13 + lVar26 & 0xffffffffffffU | 0x2bad000000000000);
            }
            *puVar1 = 0;
            *puVar2 = 0;
            (**(code **)(*plVar21 + 0xe0))(plVar21,0);
            (**(code **)(*plVar21 + 0x28))(plVar21);
            uVar5 = *(uint *)(param_1 + 0xb0);
            if (uVar5 != 0xffffffff) {
              if (*(int *)(param_1 + 0xcc) == 0) {
                (**(code **)(**(long **)(param_1 + 0x10) + 0xcf0))
                          (*(long **)(param_1 + 0x10),(ulong)uVar5,0,0);
              }
              else if (*(int *)(param_1 + 0xd0) == 0) {
                SysOp_W(0,8,1,0,0);
              }
              else {
                SysOp_W(0,8,1,2,((ulong)uVar5 & 0x1ff) << 0x30);
              }
            }
          }
          piVar3 = (int *)(*(long *)(lVar10 + 0x20) + (long)iVar19);
          if (lVar24 != iVar19) {
            piVar3 = (int *)(*(long *)(lVar10 + 0x20) + lVar24 & 0xffffffffffffU |
                            0x2bad000000000000);
          }
          *piVar3 = *piVar3 + -1;
          bVar8 = uVar11 != uVar16;
          uVar11 = uVar11 + 1;
        } while (bVar8);
        uVar11 = (ulong)*(uint *)(param_1 + 0x3d8);
      }
      uVar18 = uVar18 + 1;
    } while (uVar18 < uVar11);
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0xb8));
  if (*(int *)(param_1 + 0xcc) == 0) {
    (**(code **)(**(long **)(param_1 + 0x10) + 0xcf8))();
  }
  else {
    DataSynchronizationBarrier(3,3,0);
  }
  uVar5 = *(uint *)(param_1 + 0xb0);
  if (uVar5 == 0xffffffff) {
LAB_fffffff008210008:
    iVar25 = *(int *)(param_1 + 0x3d8);
  }
  else {
    plVar21 = *(long **)(param_1 + 0x10);
    if (*(int *)(param_1 + 0xd0) == 1) {
      iVar25 = *(int *)((long)plVar21 + 0x1095c);
      uVar11 = param_1 + 0xd8;
      thunk_EXT_FUN_80110000037bf1a4
                (uVar11,*(undefined4 *)(param_1 + 0x3d8),0x18,FUN_fffffff008210214);
      lVar26 = *(long *)(param_1 + 0xe0);
      lVar10 = *(long *)(param_1 + 0xe8);
      uVar18 = (ulong)*(uint *)(param_1 + 0x3d8);
      if (1 < *(uint *)(param_1 + 0x3d8)) {
        if (iVar25 == 1) {
          uVar15 = 1;
          do {
            uVar22 = uVar11 + uVar15 * 0x18;
            if (((uVar11 ^ uVar22) & 0xffc0000000000000) != 0) {
              uVar22 = uVar22 & 0xffffffffffff | 0xc8a2000000000000;
            }
            if (lVar26 + lVar10 + 0x100000U < *(ulong *)(uVar22 + 8)) {
              FUN_fffffff00821010c(param_1,*(undefined4 *)(param_1 + 0xb0));
              lVar26 = *(long *)(uVar22 + 8);
              lVar10 = *(long *)(uVar22 + 0x10);
              uVar18 = (ulong)*(uint *)(param_1 + 0x3d8);
            }
            else {
              lVar10 = (*(ulong *)(uVar22 + 8) - lVar26) + *(long *)(uVar22 + 0x10);
            }
            uVar15 = uVar15 + 1;
          } while (uVar15 < uVar18);
        }
        else {
          uVar18 = 1;
          do {
            FUN_fffffff00821010c(param_1,*(undefined4 *)(param_1 + 0xb0),lVar26,lVar10);
            uVar15 = uVar11 + uVar18 * 0x18;
            if (((uVar11 ^ uVar15) & 0xffc0000000000000) != 0) {
              uVar15 = uVar15 & 0xffffffffffff | 0xc8a2000000000000;
            }
            lVar26 = *(long *)(uVar15 + 8);
            lVar10 = *(long *)(uVar15 + 0x10);
            uVar18 = uVar18 + 1;
          } while (uVar18 < *(uint *)(param_1 + 0x3d8));
        }
      }
      FUN_fffffff00821010c(param_1,*(undefined4 *)(param_1 + 0xb0),lVar26,lVar10);
      iVar25 = *(int *)(param_1 + 0xcc);
    }
    else if (*(int *)(param_1 + 0xcc) == 0) {
      (**(code **)(*plVar21 + 0xcf0))(plVar21,(ulong)uVar5,0,0);
      iVar25 = *(int *)(param_1 + 0xcc);
    }
    else if (*(int *)(param_1 + 0xd0) == 0) {
      SysOp_W(0,8,1,0,0);
      iVar25 = *(int *)(param_1 + 0xcc);
    }
    else {
      SysOp_W(0,8,1,2,((ulong)uVar5 & 0x1ff) << 0x30);
      iVar25 = *(int *)(param_1 + 0xcc);
    }
    if (iVar25 != 0) {
      DataSynchronizationBarrier(3,3,0);
      goto LAB_fffffff008210008;
    }
    (**(code **)(**(long **)(param_1 + 0x10) + 0xcf8))();
    iVar25 = *(int *)(param_1 + 0x3d8);
  }
  if (iVar25 != 0) {
    uVar11 = 0;
    do {
      plVar21 = (long *)(param_1 + 0xd8U + uVar11 * 0x18);
      if (((param_1 + 0xd8U ^ (ulong)plVar21) & 0xffc0000000000000) != 0) {
        plVar21 = (long *)((ulong)plVar21 & 0xffffffffffff | 0xc8a2000000000000);
      }
      (**(code **)(*(long *)*plVar21 + 0xe0))((long *)*plVar21,0);
      if ((long *)*plVar21 != (long *)0x0) {
        (**(code **)(*(long *)*plVar21 + 0x28))();
      }
      *plVar21 = 0;
      uVar11 = uVar11 + 1;
    } while (uVar11 < *(uint *)(param_1 + 0x3d8));
  }
  *(undefined4 *)(param_1 + 0x3d8) = 0;
  DataMemoryBarrier(2,3);
LAB_fffffff0082100d8:
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
    thunk_EXT_FUN_80110000038ff2e0(*(undefined8 *)(param_1 + 0xc0));
    return;
  }
                    /* WARNING: Does not return */
  pcVar7 = (code *)SoftwareBreakpoint(0xc471,0xfffffff008210108);
  (*pcVar7)();
}

