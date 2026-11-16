// FUN_fffffff008195bb8 @ fffffff008195bb8 size=2040

void FUN_fffffff008195bb8(long param_1,long param_2,long param_3,uint param_4,long param_5)

{
  byte *pbVar1;
  int *piVar2;
  ulong *puVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  byte bVar7;
  byte bVar8;
  ushort uVar9;
  short sVar10;
  bool bVar11;
  bool bVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  long *plVar17;
  ulong uVar18;
  undefined8 *puVar19;
  ulong uVar20;
  long lVar21;
  ulong uVar22;
  long lVar23;
  ulong uVar24;
  ulong *puVar25;
  long lVar26;
  ulong uVar27;
  undefined2 uVar28;
  ulong uVar29;
  long lVar30;
  long local_88;
  undefined1 local_61;
  
  if ((*(byte *)(param_2 + 8) & 1) == 0) {
LAB_fffffff008196378:
    thunk_EXT_FUN_8011000003a49114
              ("AGXk: %s:%d:%s: !!! Assertion failed: %s: stream validator is invalid!\n");
    return;
  }
  if (*(int *)(param_2 + 0xa0) == 0) {
    lVar26 = *(long *)(param_1 + 0x530);
    plVar17 = (long *)(lVar26 + 0x11f38);
    lVar21 = *plVar17;
    uVar14 = *(uint *)(lVar21 + 0x1116c);
    uVar4 = 0;
    uVar24 = 0;
    if (uVar14 != 0) goto LAB_fffffff00819616c;
LAB_fffffff008195c88:
    uVar16 = *(uint *)(lVar21 + 0x115c4);
  }
  else {
    uVar4 = *(uint *)(param_2 + 0xe8);
    uVar24 = (ulong)*(uint *)(param_2 + 0xec);
    bVar7 = *(byte *)(param_2 + 0xf0);
    lVar26 = *(long *)(param_1 + 0x530);
    if ((uVar4 != 0) && (plVar17 = *(long **)(lVar26 + 0x11ee8), plVar17 != (long *)0x0)) {
      if (*(long *)(lVar26 + 0x11f18) != 0) {
        iVar13 = thunk_EXT_FUN_8011000001335e8c(*(long *)(lVar26 + 0x11f18));
        if (iVar13 != 0) goto LAB_fffffff008195c6c;
        plVar17 = *(long **)(lVar26 + 0x11ee8);
      }
      iVar13 = (**(code **)(*plVar17 + 0x80))
                         (plVar17,4,*(undefined8 *)(lVar26 + 0x11f10),
                          (undefined8 *)(lVar26 + 0x11f18));
      if (iVar13 != 0) {
        *(undefined8 *)(lVar26 + 0x11f18) = 0;
      }
    }
LAB_fffffff008195c6c:
    lVar21 = *(long *)(lVar26 + 0x11f38);
    uVar14 = *(uint *)(lVar21 + 0x1116c);
    if (uVar14 != 0) {
      lVar26 = *(long *)(param_1 + 0x530);
LAB_fffffff00819616c:
      bVar7 = *(byte *)(lVar26 + 0x10940);
      bVar8 = *(byte *)(lVar26 + 0x10941);
      iVar13 = (int)uVar24;
      goto joined_r0xfffffff008195d3c;
    }
    plVar17 = (long *)(lVar26 + 0x11f38);
    if ((bVar7 & 1) == 0) goto LAB_fffffff008195c88;
    uVar16 = *(uint *)(lVar21 + 70000);
    if (uVar16 == 0) {
      uVar16 = *(uint *)(lVar21 + 0x115c8);
    }
  }
  uVar14 = uVar16;
  if (*(long *)(lVar26 + 0x11f08) != 0) {
    uVar14 = thunk_EXT_FUN_8011000001335e8c();
  }
  uVar15 = uVar16;
  if (*(long *)(lVar26 + 0x11f18) != 0) {
    uVar15 = thunk_EXT_FUN_8011000001335e8c(*(long *)(lVar26 + 0x11f18));
  }
  if (uVar15 < uVar14) {
    lVar21 = *(long *)(lVar26 + 0x11f08);
  }
  else {
    lVar21 = *(long *)(lVar26 + 0x11f18);
  }
  if (lVar21 != 0) {
    uVar16 = thunk_EXT_FUN_8011000001335e8c();
  }
  if ((*(byte *)(*plVar17 + 0x10948) & 1) == 0) {
    uVar15 = 1;
    if (uVar16 == 0) {
      return;
    }
  }
  else {
    uVar15 = *(uint *)(*plVar17 + 0x10944);
    if (uVar16 < uVar15) {
      return;
    }
  }
  bVar7 = *(byte *)(*(long *)(param_1 + 0x530) + 0x10940);
  bVar8 = *(byte *)(*(long *)(param_1 + 0x530) + 0x10941);
  uVar14 = 0;
  if (uVar15 != 0) {
    uVar14 = uVar16 / uVar15;
  }
  iVar13 = (int)uVar24;
joined_r0xfffffff008195d3c:
  if (iVar13 != 0) {
    uVar27 = 0;
    local_88 = 0;
    do {
      if ((*(byte *)(param_2 + 8) & 1) == 0) goto LAB_fffffff008196378;
      uVar20 = *(ulong *)(param_2 + 0x100);
      puVar25 = (ulong *)(uVar20 + uVar27 * 0x18);
      if (((uVar20 ^ (ulong)puVar25) & 0xffc0000000000000) != 0) {
        puVar25 = (ulong *)((ulong)puVar25 & 0xffffffffffff | 0xc8a2000000000000);
      }
      puVar3 = (ulong *)(param_2 + 0x108);
      if (uVar20 != 0) {
        puVar3 = puVar25;
      }
      lVar21 = *(long *)(param_1 + 0x530);
      if (*(int *)(param_5 + 0x100) == *(int *)(lVar21 + 0x1093c)) break;
      uVar9 = *(ushort *)((long)puVar3 + 0x14);
      if (((uint)puVar3[2] & param_4) != 0 && uVar9 != 0) {
        uVar16 = *(uint *)((long)puVar3 + 0xc);
        uVar20 = (ulong)uVar16;
        sVar10 = *(short *)((long)puVar3 + 0x16);
        uVar18 = *puVar3 & 0xffffffffff;
        if ((sVar10 == 0x100) || ((*(byte *)(lVar21 + 0x238) >> 5 & 1) == 0)) {
LAB_fffffff008195f8c:
          if (((bVar7 & sVar10 != 0x100) == 0) && ((bVar8 & sVar10 == 0x100) == 0)) {
            iVar13 = 0;
          }
          else {
            uVar22 = uVar20 * 0x80;
            uVar29 = ((ulong)(uint)uVar9 * (ulong)uVar14) / 100 + local_88;
            if (uVar22 < uVar29 || uVar22 - uVar29 == 0) {
              iVar13 = 0;
            }
            else {
              iVar13 = 0;
              do {
                iVar13 = iVar13 + 1;
                uVar22 = uVar22 >> 1;
                uVar20 = uVar22;
              } while (uVar29 < uVar22);
            }
            if (uVar20 == 0) goto LAB_fffffff008195d8c;
            local_88 = uVar29 - uVar22;
          }
          lVar21 = *(long *)(param_1 + 0x530);
          iVar5 = *(int *)(lVar21 + 0x1117c);
          if (((iVar5 != 0) || (iVar5 = iVar13, (sVar10 == 0x100 & bVar8) != 1)) || (iVar13 != 0)) {
            uVar28 = (undefined2)iVar5;
            if (sVar10 == 0x100) {
              uVar15 = *(uint *)(param_5 + 0x100);
              if (uVar15 < 0x10) {
                if ((bVar8 & 1) == 0) {
                  uVar28 = 0;
                }
                uVar6 = *(undefined4 *)(lVar21 + 0x10938);
                lVar21 = (ulong)uVar15 * 0x10;
                puVar25 = (ulong *)(param_5 + (int)lVar21);
                if (lVar21 - (int)lVar21 != 0) {
                  puVar25 = (ulong *)(param_5 + lVar21 & 0xffffffffffffU | 0x2bad000000000000);
                }
                *(uint *)(param_5 + 0x100) = uVar15 + 1;
                *puVar25 = uVar18;
                *(uint *)(puVar25 + 1) = uVar16;
                *(char *)((long)puVar25 + 0xc) = (char)uVar6;
                *(undefined2 *)((long)puVar25 + 0xe) = uVar28;
              }
            }
            else {
              local_61 = 0;
              iVar13 = FUN_fffffff008200fc8(*(undefined8 *)(param_1 + 0x488),sVar10,&local_61,1);
              if (iVar13 != 0) {
                uVar15 = *(uint *)(param_5 + 0x100);
                if (uVar15 < 0x10) {
                  if ((bVar7 & 1) == 0) {
                    uVar28 = 0;
                  }
                  lVar21 = (ulong)uVar15 * 0x10;
                  puVar25 = (ulong *)(param_5 + (int)lVar21);
                  if (lVar21 - (int)lVar21 != 0) {
                    puVar25 = (ulong *)(param_5 + lVar21 & 0xffffffffffffU | 0x2bad000000000000);
                  }
                  *(uint *)(param_5 + 0x100) = uVar15 + 1;
                  *puVar25 = uVar18;
                  *(uint *)(puVar25 + 1) = uVar16;
                  *(undefined1 *)((long)puVar25 + 0xc) = local_61;
                  *(undefined2 *)((long)puVar25 + 0xe) = uVar28;
                }
              }
            }
          }
        }
        else {
          plVar17 = (long *)thunk_EXT_FUN_8011000002961628
                                      (*(undefined8 *)(param_1 + 0x488),(int)puVar3[1]);
          if (plVar17 != (long *)0x0) {
            (**(code **)(*plVar17 + 0x20))();
            (**(code **)(*plVar17 + 0x28))(plVar17);
            lVar21 = (**(code **)(*(long *)plVar17[4] + 0x98))();
            if ((*(byte *)(plVar17 + 2) & 0x7f) == 0) {
              uVar29 = plVar17[9];
            }
            else if (*(byte *)(plVar17 + 2) == 0x82) {
              uVar29 = (ulong)*(uint *)((long)plVar17 + 0x4c);
            }
            else {
              uVar29 = 0;
            }
            lVar26 = (**(code **)(*(long *)plVar17[4] + 0x98))();
            uVar15 = *(uint *)(plVar17 + 2) & 0xff;
            if ((*(uint *)(plVar17 + 2) & 0x7f) == 0) {
              uVar22 = plVar17[9];
            }
            else if (uVar15 == 0x82) {
              uVar22 = (ulong)*(uint *)((long)plVar17 + 0x4c);
            }
            else {
              uVar22 = 0;
            }
            uVar22 = uVar22 + plVar17[0xf] + lVar26;
            if ((((uVar18 < uVar29 + lVar21 || uVar22 <= uVar18) || uVar22 < uVar18 + uVar20 * 0x80)
                || (uVar15 != 0)) || ((*(byte *)(plVar17 + 0x16) & 1) == 0)) {
              bVar11 = false;
              bVar12 = true;
            }
            else {
              bVar12 = false;
              bVar11 = true;
            }
            (**(code **)(*plVar17 + 0x28))(plVar17);
            if (bVar11) goto LAB_fffffff008195f8c;
            if (!bVar12) break;
          }
        }
      }
LAB_fffffff008195d8c:
      uVar27 = uVar27 + 1;
    } while (uVar27 != uVar24);
  }
  if (uVar4 != 0) {
    lVar26 = 0;
    lVar21 = 0;
    do {
      if ((*(byte *)(param_2 + 8) & 1) == 0) goto LAB_fffffff008196378;
      if (((*(long *)(param_2 + 0xf8) != 0) &&
          (uVar9 = *(ushort *)(*(long *)(param_2 + 0xf8) + lVar21 * 2), uVar9 < 0x100)) &&
         (lVar30 = *(long *)(param_1 + 0x488), *(int *)(*(long *)(lVar30 + 0x48) + 0x10934) != 0)) {
        lVar23 = *(long *)(lVar30 + 0x178);
        if (lVar23 == 0) {
          puVar19 = (undefined8 *)thunk_EXT_FUN_80110000038fe580(0x200);
          *(undefined8 **)(lVar30 + 0x178) = puVar19;
          if (puVar19 == (undefined8 *)0x0) goto LAB_fffffff0081961bc;
          puVar19[0x3d] = 0;
          puVar19[0x3c] = 0;
          puVar19[0x3f] = 0;
          puVar19[0x3e] = 0;
          puVar19[0x39] = 0;
          puVar19[0x38] = 0;
          puVar19[0x3b] = 0;
          puVar19[0x3a] = 0;
          puVar19[0x35] = 0;
          puVar19[0x34] = 0;
          puVar19[0x37] = 0;
          puVar19[0x36] = 0;
          puVar19[0x31] = 0;
          puVar19[0x30] = 0;
          puVar19[0x33] = 0;
          puVar19[0x32] = 0;
          puVar19[0x2d] = 0;
          puVar19[0x2c] = 0;
          puVar19[0x2f] = 0;
          puVar19[0x2e] = 0;
          puVar19[0x29] = 0;
          puVar19[0x28] = 0;
          puVar19[0x2b] = 0;
          puVar19[0x2a] = 0;
          puVar19[0x25] = 0;
          puVar19[0x24] = 0;
          puVar19[0x27] = 0;
          puVar19[0x26] = 0;
          puVar19[0x21] = 0;
          puVar19[0x20] = 0;
          puVar19[0x23] = 0;
          puVar19[0x22] = 0;
          puVar19[0x1d] = 0;
          puVar19[0x1c] = 0;
          puVar19[0x1f] = 0;
          puVar19[0x1e] = 0;
          puVar19[0x19] = 0;
          puVar19[0x18] = 0;
          puVar19[0x1b] = 0;
          puVar19[0x1a] = 0;
          puVar19[0x15] = 0;
          puVar19[0x14] = 0;
          puVar19[0x17] = 0;
          puVar19[0x16] = 0;
          puVar19[0x11] = 0;
          puVar19[0x10] = 0;
          puVar19[0x13] = 0;
          puVar19[0x12] = 0;
          puVar19[0xd] = 0;
          puVar19[0xc] = 0;
          puVar19[0xf] = 0;
          puVar19[0xe] = 0;
          puVar19[9] = 0;
          puVar19[8] = 0;
          puVar19[0xb] = 0;
          puVar19[10] = 0;
          puVar19[5] = 0;
          puVar19[4] = 0;
          puVar19[7] = 0;
          puVar19[6] = 0;
          puVar19[1] = 0;
          *puVar19 = 0;
          puVar19[3] = 0;
          puVar19[2] = 0;
          lVar23 = *(long *)(lVar30 + 0x178);
        }
        pbVar1 = (byte *)(lVar23 + (ulong)uVar9 * 2);
        if ((pbVar1[1] & 1) != 0) {
          bVar7 = *pbVar1;
          uVar24 = (ulong)(bVar7 >> 3) & 0x18;
          *(ulong *)(param_5 + 0x108 + uVar24) =
               1L << ((ulong)bVar7 & 0x3f) | *(ulong *)(param_5 + 0x108 + uVar24);
          lVar30 = *(long *)(*(long *)(param_1 + 0x488) + 0x48);
          if ((*(int *)(lVar30 + 0x10934) != 0) &&
             (pbVar1 = (byte *)(*(long *)(*(long *)(param_1 + 0x488) + 0x178) + (ulong)uVar9 * 2),
             (pbVar1[1] & 1) != 0)) {
            bVar7 = *pbVar1;
            uVar6 = *(undefined4 *)(param_3 + 0x18);
            thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar30 + 0x11f30));
            uVar24 = 1L << ((ulong)bVar7 & 0x3f);
            if (((*(ulong *)(lVar30 + 0x17f70 + (ulong)(bVar7 >> 6) * 8) & uVar24) == 0) &&
               ((*(ulong *)(lVar30 + 0x17f90 + (ulong)(bVar7 >> 6) * 8) & uVar24) == 0)) {
              piVar2 = (int *)(lVar30 + 0x11f70 + (ulong)bVar7 * 0x60);
              *piVar2 = *piVar2 + 1;
              thunk_EXT_FUN_80110000029481a8
                        (*(undefined8 *)(*(long *)(lVar30 + 0x11f38) + 0x148),uVar6,piVar2 + 2);
            }
            thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar30 + 0x11f30));
          }
        }
      }
LAB_fffffff0081961bc:
      lVar21 = lVar21 + 1;
      lVar26 = lVar26 + 2;
    } while ((ulong)uVar4 << 1 != lVar26);
  }
  return;
}

