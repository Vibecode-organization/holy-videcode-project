// FUN_fffffff008181a9c @ fffffff008181a9c size=1716

undefined8 FUN_fffffff008181a9c(long param_1,undefined8 param_2,undefined8 param_3)

{
  ulong uVar1;
  undefined4 *puVar2;
  uint uVar3;
  ushort uVar4;
  long lVar5;
  int iVar6;
  undefined8 uVar7;
  long lVar8;
  long lVar9;
  long *plVar10;
  uint uVar11;
  uint uVar12;
  ulong uVar13;
  uint uVar14;
  long *plVar15;
  undefined4 uVar16;
  undefined *local_a0;
  ulong local_98;
  long local_90;
  ulong local_88;
  undefined *local_80;
  ulong local_78;
  undefined8 local_70;
  undefined8 local_68;
  
  local_70 = 0;
  local_80 = &DAT_fffffff007c9eda0;
  local_78 = 0;
  local_68 = 0;
  uVar7 = FUN_fffffff0081ff778(&local_80,&local_80,param_3);
  if ((int)uVar7 == 0) {
    return uVar7;
  }
  if ((local_78 & 1) != 0) {
    *(undefined8 *)(param_1 + 0x78) = local_70;
    if (*(long *)(param_1 + 0x80) == 0) {
      *(undefined4 *)(param_1 + 0x88) = 4;
      lVar8 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ca2c58,0x40);
      *(long *)(param_1 + 0x80) = lVar8;
      if (lVar8 == 0) {
        return 0;
      }
      if ((local_78 & 1) == 0) goto LAB_fffffff008181e54;
    }
    iVar6 = (uint)local_68;
    thunk_EXT_FUN_801100000296ba88(0x30);
    lVar8 = thunk_EXT_FUN_801100000296ba9c();
    *(long *)(param_1 + 0x70) = lVar8;
    if (lVar8 == 0) {
      return 0;
    }
    uVar7 = thunk_EXT_FUN_801100000296bb54(lVar8,iVar6 * 6);
    if ((int)uVar7 == 0) {
      return uVar7;
    }
    plVar15 = (long *)(param_1 + 0x10);
    if (*plVar15 == 0) {
      thunk_EXT_FUN_801100000296c0c8(0x30);
      plVar10 = (long *)thunk_EXT_FUN_801100000296c0dc();
      *plVar15 = (long)plVar10;
      if (plVar10 == (long *)0x0) {
        return 0;
      }
      uVar7 = (**(code **)(*plVar10 + 0x68))();
      if ((int)uVar7 == 0) {
        return uVar7;
      }
    }
    if (*(long *)(param_1 + 0x18) == 0) {
      thunk_EXT_FUN_801100000296c0c8(0x30);
      plVar10 = (long *)thunk_EXT_FUN_801100000296c0dc();
      *(long **)(param_1 + 0x18) = plVar10;
      if (plVar10 == (long *)0x0) {
        return 0;
      }
      uVar7 = (**(code **)(*plVar10 + 0x68))();
      if ((int)uVar7 == 0) {
        return uVar7;
      }
    }
    if (*(long *)(param_1 + 0x20) == 0) {
      thunk_EXT_FUN_801100000296c0c8(0x30);
      plVar10 = (long *)thunk_EXT_FUN_801100000296c0dc();
      *(long **)(param_1 + 0x20) = plVar10;
      if (plVar10 == (long *)0x0) {
        return 0;
      }
      uVar7 = (**(code **)(*plVar10 + 0x68))();
      if ((int)uVar7 == 0) {
        return uVar7;
      }
    }
    if (*(long *)(param_1 + 0x28) == 0) {
      thunk_EXT_FUN_801100000296c0c8(0x30);
      plVar10 = (long *)thunk_EXT_FUN_801100000296c0dc();
      *(long **)(param_1 + 0x28) = plVar10;
      if (plVar10 == (long *)0x0) {
        return 0;
      }
      uVar7 = (**(code **)(*plVar10 + 0x68))();
      if ((int)uVar7 == 0) {
        return uVar7;
      }
    }
    if (*(long *)(param_1 + 0x30) == 0) {
      thunk_EXT_FUN_801100000296c0c8(0x30);
      plVar10 = (long *)thunk_EXT_FUN_801100000296c0dc();
      *(long **)(param_1 + 0x30) = plVar10;
      if (plVar10 == (long *)0x0) {
        return 0;
      }
      uVar7 = (**(code **)(*plVar10 + 0x68))();
      if ((int)uVar7 == 0) {
        return uVar7;
      }
    }
    if (*(long *)(param_1 + 0x38) == 0) {
      thunk_EXT_FUN_801100000296c0c8(0x30);
      plVar10 = (long *)thunk_EXT_FUN_801100000296c0dc();
      *(long **)(param_1 + 0x38) = plVar10;
      if (plVar10 == (long *)0x0) {
        return 0;
      }
      uVar7 = (**(code **)(*plVar10 + 0x68))();
      if ((int)uVar7 == 0) {
        return uVar7;
      }
    }
    if (*(long *)(param_1 + 0x40) == 0) {
      thunk_EXT_FUN_801100000296c0c8(0x30);
      plVar10 = (long *)thunk_EXT_FUN_801100000296c0dc();
      *(long **)(param_1 + 0x40) = plVar10;
      if (plVar10 == (long *)0x0) {
        return 0;
      }
      uVar7 = (**(code **)(*plVar10 + 0x68))();
      if ((int)uVar7 == 0) {
        return uVar7;
      }
    }
    if (*(long *)(param_1 + 0x48) == 0) {
      thunk_EXT_FUN_801100000296c0c8(0x30);
      plVar10 = (long *)thunk_EXT_FUN_801100000296c0dc();
      *(long **)(param_1 + 0x48) = plVar10;
      if (plVar10 == (long *)0x0) {
        return 0;
      }
      uVar7 = (**(code **)(*plVar10 + 0x68))();
      if ((int)uVar7 == 0) {
        return uVar7;
      }
    }
    if (*(long *)(param_1 + 0x50) == 0) {
      thunk_EXT_FUN_801100000296c0c8(0x30);
      plVar10 = (long *)thunk_EXT_FUN_801100000296c0dc();
      *(long **)(param_1 + 0x50) = plVar10;
      if (plVar10 == (long *)0x0) {
        return 0;
      }
      uVar7 = (**(code **)(*plVar10 + 0x68))();
      if ((int)uVar7 == 0) {
        return uVar7;
      }
    }
    if (*(long *)(param_1 + 0x58) == 0) {
      thunk_EXT_FUN_801100000296c0c8(0x30);
      plVar10 = (long *)thunk_EXT_FUN_801100000296c0dc();
      *(long **)(param_1 + 0x58) = plVar10;
      if (plVar10 == (long *)0x0) {
        return 0;
      }
      uVar7 = (**(code **)(*plVar10 + 0x68))();
      if ((int)uVar7 == 0) {
        return uVar7;
      }
    }
    if (*(long *)(param_1 + 0x60) == 0) {
      thunk_EXT_FUN_801100000296c0c8(0x30);
      plVar10 = (long *)thunk_EXT_FUN_801100000296c0dc();
      *(long **)(param_1 + 0x60) = plVar10;
      if (plVar10 == (long *)0x0) {
        return 0;
      }
      uVar7 = (**(code **)(*plVar10 + 0x68))();
      if ((int)uVar7 == 0) {
        return uVar7;
      }
    }
    if (*(long *)(param_1 + 0x68) == 0) {
      thunk_EXT_FUN_801100000296c0c8(0x30);
      plVar10 = (long *)thunk_EXT_FUN_801100000296c0dc();
      *(long **)(param_1 + 0x68) = plVar10;
      if (plVar10 == (long *)0x0) {
        return 0;
      }
      uVar7 = (**(code **)(*plVar10 + 0x68))();
      if ((int)uVar7 == 0) {
        return uVar7;
      }
    }
    if ((local_78 & 1) != 0) {
      uVar12 = 0;
      while( true ) {
        if ((uint)local_68 <= uVar12) {
          return 1;
        }
        local_90 = 0;
        local_98 = 0;
        local_a0 = &DAT_fffffff007c9ed80;
        local_88 = 0;
        iVar6 = FUN_fffffff0081ff6fc(&local_a0,param_3);
        if (iVar6 == 0) {
          return 0;
        }
        if ((local_98 & 1) == 0) break;
        uVar13 = 0;
        while (uVar13 < (local_88 & 0xffff)) {
          uVar4 = *(ushort *)(local_90 + 0x30 + uVar13 * 2);
          uVar14 = (uint)uVar4;
          lVar8 = thunk_EXT_FUN_801100000296161c(param_2,*(undefined4 *)(local_90 + uVar13 * 4));
          if (lVar8 == 0) {
            return 0;
          }
          if ((uVar4 & 0x82a) == 0) {
            if ((uVar4 & 0x415) == 0 && (uVar4 & 0x80) == 0) {
              return 0;
            }
          }
          else if (((uint)uVar4 & (uVar4 & 0x415) << 1) != (uVar4 & 0x82a)) {
            return 0;
          }
          if ((uVar4 & 0xc3f) != 0) {
            uVar14 = 0x80;
            if ((*(byte *)(lVar8 + 0xc1) & 1) == 0) {
              uVar14 = (uint)uVar4;
            }
            if ((uVar4 >> 7 & 1) != 0) {
              return 0;
            }
          }
          if ((uVar4 & 0xc00) != 0 && (uVar14 & 0xfffff3ff) != 0) {
            return 0;
          }
          uVar11 = uVar14;
          if (((*(byte *)(lVar8 + 0xc0) & 1) == 0) &&
             (uVar11 = 0x80, (*(byte *)(param_1 + 0x90) & 1) == 0)) {
            uVar11 = uVar14;
          }
          uVar14 = uVar11 & 0xfffe;
          if (((uVar11 ^ 0xffffffff) & 3) != 0) {
            uVar14 = uVar11;
          }
          uVar11 = uVar14 & 0xfffffffb;
          if (((uVar14 ^ 0xffffffff) & 0xc) != 0) {
            uVar11 = uVar14;
          }
          uVar14 = uVar11 & 0xffffffef;
          if (((uVar11 ^ 0xffffffff) & 0x30) != 0) {
            uVar14 = uVar11;
          }
          if (((uVar14 >> 8 & 1) != 0) && ((*(byte *)(lVar8 + 0xb1) & 1) == 0)) {
            return 0;
          }
          uVar11 = uVar14 & 0xfff;
          if (uVar11 != 0) {
            do {
              uVar3 = (uint)LZCOUNT(uVar11) ^ 0x1f;
              uVar16 = 1;
              uVar11 = uVar11 & (1 << (ulong)(uVar3 & 0x1f) ^ 0xffffffffU);
              thunk_EXT_FUN_801100000296c194(plVar15[uVar3],lVar8);
            } while (uVar11 != 0);
            thunk_EXT_FUN_801100000296bdb4(*(undefined8 *)(param_1 + 0x70),lVar8);
            lVar8 = thunk_EXT_FUN_8011000002951e3c(lVar8);
            if (lVar8 != 0) {
              uVar11 = *(uint *)(param_1 + 0x8c);
              if (uVar11 < *(uint *)(param_1 + 0x88)) {
                lVar9 = *(long *)(param_1 + 0x80);
              }
              else {
                uVar11 = *(uint *)(param_1 + 0x88) << 1;
                lVar9 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ca2ca8,(ulong)uVar11 << 4);
                if (lVar9 == 0) {
                  return 0;
                }
                thunk_EXT_FUN_8011000003a61b10
                          (lVar9,*(undefined8 *)(param_1 + 0x80),
                           (ulong)*(uint *)(param_1 + 0x88) << 4);
                uVar7 = *(undefined8 *)(param_1 + 0x80);
                *(undefined8 *)(param_1 + 0x80) = 0;
                thunk_EXT_FUN_80110000038fe768
                          (&DAT_fffffff007ca2cf8,uVar7,(ulong)*(uint *)(param_1 + 0x88) << 4);
                *(uint *)(param_1 + 0x88) = uVar11;
                *(long *)(param_1 + 0x80) = lVar9;
                uVar11 = *(uint *)(param_1 + 0x8c);
              }
              lVar5 = (ulong)uVar11 * 0x10;
              plVar10 = (long *)(lVar9 + (int)lVar5);
              if (lVar5 != (int)lVar5) {
                plVar10 = (long *)(lVar9 + lVar5 & 0xffffffffffffU | 0x2bad000000000000);
              }
              if ((uVar14 & 0x82a) != 0) {
                uVar16 = 2;
              }
              uVar1 = (ulong)uVar11 << 4 | 8;
              puVar2 = (undefined4 *)(lVar9 + (int)uVar1);
              if (uVar1 != (long)(int)uVar1) {
                puVar2 = (undefined4 *)(lVar9 + uVar1 & 0xffffffffffff | 0x2bad000000000000);
              }
              *plVar10 = lVar8;
              *puVar2 = uVar16;
              *(uint *)(param_1 + 0x8c) = uVar11 + 1;
            }
          }
          uVar13 = uVar13 + 1;
          if ((local_98 & 1) == 0) goto LAB_fffffff008181e54;
        }
        uVar12 = uVar12 + 1;
        if ((local_78 & 1) == 0) break;
      }
    }
  }
LAB_fffffff008181e54:
  uVar7 = thunk_EXT_FUN_8011000003a49114
                    ("AGXk: %s:%d:%s: !!! Assertion failed: %s: stream validator is invalid!\n");
  return uVar7;
}

