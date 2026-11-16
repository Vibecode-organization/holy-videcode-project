// FUN_fffffff008200fc8 @ fffffff008200fc8 size=1776

undefined8 FUN_fffffff008200fc8(long param_1,uint param_2,undefined1 *param_3,int param_4)

{
  long *plVar1;
  long *plVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  int *piVar5;
  uint uVar6;
  bool bVar7;
  int iVar8;
  undefined8 *puVar9;
  long lVar10;
  ulong uVar11;
  long lVar12;
  uint uVar13;
  ulong uVar14;
  ulong uVar15;
  ulong uVar16;
  long lVar17;
  ulong local_80 [4];
  
  if (0xff < param_2) {
    return 0;
  }
  if (*(int *)(*(long *)(param_1 + 0x48) + 0x10934) == 0) {
    return 0;
  }
  lVar10 = *(long *)(param_1 + 0x178);
  if (lVar10 == 0) {
    puVar9 = (undefined8 *)thunk_EXT_FUN_80110000038fe580(0x200);
    *(undefined8 **)(param_1 + 0x178) = puVar9;
    if (puVar9 == (undefined8 *)0x0) {
      return 0;
    }
    puVar9[0x3d] = 0;
    puVar9[0x3c] = 0;
    puVar9[0x3f] = 0;
    puVar9[0x3e] = 0;
    puVar9[0x39] = 0;
    puVar9[0x38] = 0;
    puVar9[0x3b] = 0;
    puVar9[0x3a] = 0;
    puVar9[0x35] = 0;
    puVar9[0x34] = 0;
    puVar9[0x37] = 0;
    puVar9[0x36] = 0;
    puVar9[0x31] = 0;
    puVar9[0x30] = 0;
    puVar9[0x33] = 0;
    puVar9[0x32] = 0;
    puVar9[0x2d] = 0;
    puVar9[0x2c] = 0;
    puVar9[0x2f] = 0;
    puVar9[0x2e] = 0;
    puVar9[0x29] = 0;
    puVar9[0x28] = 0;
    puVar9[0x2b] = 0;
    puVar9[0x2a] = 0;
    puVar9[0x25] = 0;
    puVar9[0x24] = 0;
    puVar9[0x27] = 0;
    puVar9[0x26] = 0;
    puVar9[0x21] = 0;
    puVar9[0x20] = 0;
    puVar9[0x23] = 0;
    puVar9[0x22] = 0;
    puVar9[0x1d] = 0;
    puVar9[0x1c] = 0;
    puVar9[0x1f] = 0;
    puVar9[0x1e] = 0;
    puVar9[0x19] = 0;
    puVar9[0x18] = 0;
    puVar9[0x1b] = 0;
    puVar9[0x1a] = 0;
    puVar9[0x15] = 0;
    puVar9[0x14] = 0;
    puVar9[0x17] = 0;
    puVar9[0x16] = 0;
    puVar9[0x11] = 0;
    puVar9[0x10] = 0;
    puVar9[0x13] = 0;
    puVar9[0x12] = 0;
    puVar9[0xd] = 0;
    puVar9[0xc] = 0;
    puVar9[0xf] = 0;
    puVar9[0xe] = 0;
    puVar9[9] = 0;
    puVar9[8] = 0;
    puVar9[0xb] = 0;
    puVar9[10] = 0;
    puVar9[5] = 0;
    puVar9[4] = 0;
    puVar9[7] = 0;
    puVar9[6] = 0;
    puVar9[1] = 0;
    *puVar9 = 0;
    puVar9[3] = 0;
    puVar9[2] = 0;
    lVar10 = *(long *)(param_1 + 0x178);
  }
  uVar15 = (ulong)param_2;
  puVar3 = (undefined1 *)(lVar10 + uVar15 * 2);
  if ((puVar3[1] & 1) != 0) {
    *param_3 = *puVar3;
    return 1;
  }
  if (param_4 == 0) {
    return 0;
  }
  lVar17 = *(long *)(param_1 + 0x48);
  plVar1 = (long *)(lVar17 + 0x17f70);
  puVar9 = (undefined8 *)(lVar17 + 0x11f30);
  thunk_EXT_FUN_80110000032222a8(*puVar9);
  lVar10 = *(long *)(lVar17 + 0x17f88);
  if (lVar10 == 0) {
    lVar10 = *(long *)(lVar17 + 0x17f80);
    if (lVar10 == 0) {
      lVar10 = *(long *)(lVar17 + 0x17f78);
      if (lVar10 == 0) {
        lVar10 = *plVar1;
        if (lVar10 == 0) {
          thunk_EXT_FUN_8011000003222de0(*puVar9);
          thunk_EXT_FUN_80110000032222a8(*puVar9);
          plVar2 = (long *)(lVar17 + 0x17f90);
          lVar10 = *(long *)(lVar17 + 0x17fa8);
          if (lVar10 == 0) {
            lVar10 = *(long *)(lVar17 + 0x17fa0);
            if (lVar10 == 0) {
              lVar10 = *(long *)(lVar17 + 0x17f98);
              if (lVar10 == 0) {
                lVar10 = *plVar2;
                if (lVar10 == 0) {
                  thunk_EXT_FUN_8011000003222de0(*puVar9);
                  goto LAB_fffffff008201484;
                }
                uVar13 = 0;
              }
              else {
                uVar13 = 0x40;
              }
            }
            else {
              uVar13 = 0x80;
            }
          }
          else {
            uVar13 = 0xc0;
          }
          uVar13 = (uVar13 | (uint)LZCOUNT(lVar10)) ^ 0x3f;
          lVar10 = lVar17 + 0x11f70;
          bVar7 = false;
          do {
            uVar16 = (ulong)uVar13;
            lVar12 = *(long *)(*(long *)(lVar17 + 0x11f38) + 0x490);
            uVar14 = -(ulong)(uVar13 >> 0x1f) & 0xfffffffc00000000 | uVar16 << 2;
            iVar8 = (int)(uVar16 << 2);
            piVar5 = (int *)(lVar12 + iVar8);
            if (uVar14 != (long)iVar8) {
              piVar5 = (int *)(lVar12 + uVar14 & 0xffffffffffff | 0x2bad000000000000);
            }
            lVar12 = ((long)(int)uVar13 + (long)(int)uVar13 * 2) * 0x20;
            uVar14 = lVar10 + (int)lVar12;
            if (lVar12 - (int)lVar12 != 0) {
              uVar14 = lVar10 + lVar12 & 0xffffffffffffU | 0x2bad000000000000;
            }
            if ((*(int *)(uVar14 + 0x48) - *piVar5 < 1) &&
               (iVar8 = thunk_EXT_FUN_80110000029479f8
                                  (*(undefined8 *)(*(long *)(lVar17 + 0x11f38) + 0x148),uVar14 + 8),
               iVar8 != 0)) {
              uVar14 = (ulong)(uVar13 & 0xff);
              iVar8 = (**(code **)(**(long **)(lVar17 + 0x11f38) + 0xbf8))
                                (*(long **)(lVar17 + 0x11f38),uVar14);
              if (iVar8 != 0) {
                uVar11 = (ulong)(uVar13 >> 3) & 0x1ffffff8;
                *(ulong *)((long)plVar2 + uVar11) =
                     *(ulong *)((long)plVar2 + uVar11) &
                     (1L << (uVar16 & 0x3f) ^ 0xffffffffffffffffU);
                puVar4 = (undefined4 *)(lVar10 + uVar14 * 0x60);
                puVar4[0x12] = 0;
                *puVar4 = 0;
                *(undefined8 *)(puVar4 + 0x14) = 0;
                thunk_EXT_FUN_8011000002946f14(puVar4 + 2);
                bVar7 = true;
                uVar11 = (ulong)((uVar13 & 0xff) >> 3) & 0x18;
                *(ulong *)((long)plVar1 + uVar11) =
                     *(ulong *)((long)plVar1 + uVar11) | 1L << (uVar14 & 0x3f);
              }
            }
            if (uVar13 == 0) break;
            uVar11 = (ulong)(uVar13 - 1 >> 6);
            uVar14 = 0xffffffffffffffff;
            if ((uVar13 & 0x3f) != 0) {
              uVar14 = ~(-1L << (uVar16 & 0x3f));
            }
            if ((plVar2[uVar11] & uVar14) == 0) {
              if (uVar13 < 0x41) break;
              lVar12 = uVar11 + 1;
              while( true ) {
                uVar11 = uVar11 - 1;
                if (plVar2[uVar11] != 0) break;
                lVar12 = lVar12 + -1;
                if (lVar12 < 2) goto LAB_fffffff0082013b4;
              }
              uVar13 = ((uint)LZCOUNT(plVar2[uVar11]) | ((int)lVar12 + -2) * 0x40) ^ 0x3f;
            }
            else {
              uVar13 = (uVar13 - 1 | 0x3f) - (int)LZCOUNT(plVar2[uVar11] & uVar14);
            }
          } while (uVar13 != 0xffffffff);
LAB_fffffff0082013b4:
          thunk_EXT_FUN_8011000003222de0(*puVar9);
          if (!bVar7) {
LAB_fffffff008201484:
            uVar6 = *(uint *)(*(long *)(lVar17 + 0x11f38) + 0x10930);
            uVar15 = (ulong)(int)uVar6;
            uVar13 = uVar6 + *(int *)(*(long *)(lVar17 + 0x11f38) + 0x10934);
            local_80[1] = 0;
            local_80[0] = 0;
            local_80[3] = 0;
            local_80[2] = 0;
            if (uVar6 < uVar13) {
              lVar10 = lVar17 + 0x11f70;
              do {
                thunk_EXT_FUN_80110000032222a8(*puVar9);
                uVar14 = uVar15 >> 6 & 0x3ffffff;
                uVar16 = 1L << (uVar15 & 0x3f);
                if (((plVar1[uVar14] & uVar16) == 0) && ((plVar2[uVar14] & uVar16) == 0)) {
                  lVar12 = uVar15 * 0x60;
                  piVar5 = (int *)(lVar10 + (int)lVar12);
                  if (lVar12 - (int)lVar12 != 0) {
                    piVar5 = (int *)(lVar10 + lVar12 & 0xffffffffffffU | 0x2bad000000000000);
                  }
                  iVar8 = thunk_EXT_FUN_80110000029479f8
                                    (*(undefined8 *)(*(long *)(lVar17 + 0x11f38) + 0x148),piVar5 + 2
                                    );
                  if ((iVar8 != 0) && (*piVar5 != 0)) {
                    lVar12 = *(long *)(piVar5 + 0x14);
                    if ((lVar12 != 0) &&
                       ((ulong)*(ushort *)(piVar5 + 0x16) < 0x100 &&
                        *(int *)(*(long *)(lVar12 + 0x48) + 0x10934) != 0)) {
                      *(undefined2 *)
                       (*(long *)(lVar12 + 0x178) + (ulong)*(ushort *)(piVar5 + 0x16) * 2) = 0;
                    }
                    uVar11 = uVar15 >> 3 & 0x18;
                    *(ulong *)((long)plVar2 + uVar11) = *(ulong *)((long)plVar2 + uVar11) | uVar16;
                    puVar4 = (undefined4 *)(lVar10 + ((uVar15 & 0xff) + (uVar15 & 0xff) * 2) * 0x20)
                    ;
                    *puVar4 = 0;
                    *(undefined8 *)(puVar4 + 0x14) = 0;
                    local_80[uVar14] = local_80[uVar14] | uVar16;
                  }
                }
                thunk_EXT_FUN_8011000003222de0(*puVar9);
                uVar15 = uVar15 + 1;
              } while ((uint)uVar15 < uVar13);
              if (local_80[3] == 0) {
                if (local_80[2] == 0) {
                  if (local_80[1] == 0) {
                    if (local_80[0] == 0) {
                      return 0;
                    }
                    uVar13 = 0;
                    uVar15 = local_80[0];
                  }
                  else {
                    uVar13 = 0x40;
                    uVar15 = local_80[1];
                  }
                }
                else {
                  uVar13 = 0x80;
                  uVar15 = local_80[2];
                }
              }
              else {
                uVar13 = 0xc0;
                uVar15 = local_80[3];
              }
              uVar13 = (uVar13 | (uint)LZCOUNT(uVar15)) ^ 0x3f;
              do {
                FUN_fffffff0081e02dc(lVar17 + 0x11ee8,uVar13 & 0xff);
                if (uVar13 == 0) {
                  return 0;
                }
                uVar14 = (ulong)(uVar13 - 1 >> 6);
                uVar15 = 0xffffffffffffffff;
                if ((uVar13 & 0x3f) != 0) {
                  uVar15 = ~(-1L << ((ulong)uVar13 & 0x3f));
                }
                if ((local_80[uVar14] & uVar15) == 0) {
                  if (uVar13 < 0x41) {
                    return 0;
                  }
                  lVar10 = uVar14 + 1;
                  while( true ) {
                    uVar14 = uVar14 - 1;
                    if (local_80[uVar14] != 0) break;
                    lVar10 = lVar10 + -1;
                    if (lVar10 < 2) {
                      return 0;
                    }
                  }
                  uVar13 = ((uint)LZCOUNT(local_80[uVar14]) | ((int)lVar10 + -2) * 0x40) ^ 0x3f;
                }
                else {
                  uVar13 = (uVar13 - 1 | 0x3f) - (int)LZCOUNT(local_80[uVar14] & uVar15);
                }
              } while (uVar13 != 0xffffffff);
            }
            return 0;
          }
          thunk_EXT_FUN_80110000032222a8(*puVar9);
          lVar12 = *(long *)(lVar17 + 0x17f88);
          if (lVar12 == 0) {
            lVar12 = *(long *)(lVar17 + 0x17f80);
            if (lVar12 == 0) {
              lVar12 = *(long *)(lVar17 + 0x17f78);
              if (lVar12 == 0) {
                lVar12 = *plVar1;
                if (lVar12 == 0) {
                  thunk_EXT_FUN_8011000003222de0(*puVar9);
                  return 0;
                }
                uVar13 = 0;
              }
              else {
                uVar13 = 0x40;
              }
            }
            else {
              uVar13 = 0x80;
            }
          }
          else {
            uVar13 = 0xc0;
          }
          uVar13 = (uVar13 | (uint)LZCOUNT(lVar12)) ^ 0x3f;
          uVar14 = (ulong)uVar13;
          uVar16 = (ulong)(uVar13 >> 3) & 0x18;
          *(ulong *)((long)plVar1 + uVar16) =
               *(ulong *)((long)plVar1 + uVar16) & (1L << (uVar14 & 0x3f) ^ 0xffffffffffffffffU);
          lVar10 = lVar10 + uVar14 * 0x60;
          *(short *)(lVar10 + 0x58) = (short)param_2;
          *(long *)(lVar10 + 0x50) = param_1;
          *param_3 = (char)uVar13;
          if ((*(byte *)(*(long *)(lVar17 + 0x11f38) + 0x1ac44) >> 3 & 1) != 0) {
            FUN_fffffff00817dc48(*(long *)(lVar17 + 0x11f38),0x325,0,uVar14,uVar15,param_1,0,0);
          }
          goto LAB_fffffff00820112c;
        }
        uVar13 = 0;
      }
      else {
        uVar13 = 0x40;
      }
    }
    else {
      uVar13 = 0x80;
    }
  }
  else {
    uVar13 = 0xc0;
  }
  uVar13 = (uVar13 | (uint)LZCOUNT(lVar10)) ^ 0x3f;
  uVar16 = (ulong)uVar13;
  uVar14 = (ulong)(uVar13 >> 3) & 0x18;
  *(ulong *)((long)plVar1 + uVar14) =
       *(ulong *)((long)plVar1 + uVar14) & (1L << (uVar16 & 0x3f) ^ 0xffffffffffffffffU);
  lVar10 = lVar17 + 0x11f70 + uVar16 * 0x60;
  *(short *)(lVar10 + 0x58) = (short)param_2;
  *(long *)(lVar10 + 0x50) = param_1;
  *param_3 = (char)uVar13;
  lVar10 = *(long *)(lVar17 + 0x11f38);
  if ((*(byte *)(lVar10 + 0x1ac44) >> 3 & 1) != 0) {
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar10 + 0x1ac48));
    thunk_EXT_FUN_80110000036da494(0x85930c94,uVar16,uVar15,param_1,0,0);
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar10 + 0x1ac48));
  }
LAB_fffffff00820112c:
  thunk_EXT_FUN_8011000003222de0(*puVar9);
  puVar3 = (undefined1 *)(*(long *)(param_1 + 0x178) + uVar15 * 2);
  puVar3[1] = 1;
  *puVar3 = *param_3;
  return 1;
}

