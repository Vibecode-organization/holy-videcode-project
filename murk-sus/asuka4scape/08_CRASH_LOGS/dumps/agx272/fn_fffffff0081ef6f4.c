// FUN_fffffff0081ef6f4 @ fffffff0081ef6f4 size=1804

undefined8 FUN_fffffff0081ef6f4(long *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined *puVar4;
  int iVar5;
  int iVar6;
  long *plVar7;
  long *plVar8;
  long *plVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  long lVar12;
  long lVar13;
  ulong uVar14;
  ulong uVar15;
  ulong uVar16;
  long lVar17;
  ulong uVar18;
  ulong uVar19;
  undefined8 *puVar20;
  undefined8 *puVar21;
  long lVar22;
  long lVar23;
  undefined8 uVar24;
  undefined8 uVar25;
  undefined8 uVar26;
  undefined8 uVar27;
  undefined8 uVar28;
  undefined8 uVar29;
  undefined8 uVar30;
  undefined8 uVar31;
  undefined8 uVar32;
  undefined8 uVar33;
  undefined8 uVar34;
  undefined8 uVar35;
  undefined8 uVar36;
  undefined8 uVar37;
  undefined8 uVar38;
  undefined8 uVar39;
  undefined8 uVar40;
  undefined8 uVar41;
  undefined8 uVar42;
  undefined8 uVar43;
  undefined8 uVar44;
  undefined8 uVar45;
  undefined8 uVar46;
  undefined8 uVar47;
  undefined8 uVar48;
  undefined8 uVar49;
  undefined8 uVar50;
  
  uVar3 = *(uint *)(param_1 + 9);
  if (uVar3 == 0) {
LAB_fffffff0081efd68:
    uVar10 = 1;
  }
  else {
    if ((param_1[0xc] != 0) || (param_1[0xd] != 0)) {
      return 0;
    }
    uVar14 = param_1[7];
    if (uVar14 == 0) {
      uVar18 = 0;
      uVar15 = 0;
    }
    else {
      uVar15 = uVar14 + (ulong)*(uint *)(param_1 + 8) * 0x68;
      if (((uVar14 ^ uVar15) & 0xffc0000000000000) != 0) {
        uVar15 = uVar15 & 0xffffffffffff | 0xc8a2000000000000;
      }
      uVar18 = uVar15 - uVar14;
      if ((uVar15 < uVar14) || (uVar15 = uVar14, uVar18 >> 0x20 != 0)) goto LAB_fffffff0081efdac;
    }
    lVar17 = (ulong)(uVar3 - 1) * 0x68;
    if (lVar17 - (int)lVar17 != 0) {
LAB_fffffff0081efd88:
                    /* WARNING: Subroutine does not return */
      FUN_fffffff008214ca8
                (
                "bounded_ptr<T>::operator+=(n): Adding the specified number of bytes to the offset representing the current position would overflow."
                );
    }
    uVar16 = (ulong)(uVar3 - 1) * 0x6800000000;
    if ((long)uVar16 < 0) {
LAB_fffffff0081efd94:
                    /* WARNING: Subroutine does not return */
      FUN_fffffff008214ca8
                (
                "bounded_ptr<T>::operator*: Dereferencing this pointer would access memory outside of the bounds set originally"
                );
    }
    uVar1 = (int)(uVar16 >> 0x20) + 0x68;
    if ((uint)uVar18 < uVar1) goto LAB_fffffff0081efd94;
    uVar19 = (ulong)CARRY8(uVar15,uVar16 >> 0x20);
    uVar18 = -uVar19;
    if ((uVar18 != uVar19) || ((long)uVar18 < 0)) {
LAB_fffffff0081efda0:
                    /* WARNING: Subroutine does not return */
      FUN_fffffff008214ca8
                (
                "This bounded_ptr is pointing to memory outside of what can be represented by a native pointer."
                );
    }
    if (uVar14 == 0) goto LAB_fffffff0081efd94;
    uVar18 = uVar14 + (ulong)*(uint *)(param_1 + 8) * 0x68;
    if (((uVar14 ^ uVar18) & 0xffc0000000000000) != 0) {
      uVar18 = uVar18 & 0xffffffffffff | 0xc8a2000000000000;
    }
    if ((uVar18 < uVar15) || (uVar18 - uVar15 >> 0x20 != 0)) {
LAB_fffffff0081efdac:
                    /* WARNING: Subroutine does not return */
      FUN_fffffff008214ca8
                (
                "The range of valid memory is too large to be represented by this type, or [begin, end) is not a well-formed range"
                );
    }
    if ((uint)(uVar18 - uVar15) < uVar1) goto LAB_fffffff0081efd94;
    lVar17 = *(long *)(uVar15 + (uVar16 >> 0x20));
    iVar6 = *(int *)(lVar17 + 0x18);
    iVar2 = *(int *)(lVar17 + 0x1c);
    plVar7 = (long *)(**(code **)(DAT_fffffff00ae22f20 + 0x68))(&DAT_fffffff00ae22f20);
    if (plVar7 == (long *)0x0) {
      return 0;
    }
    iVar5 = (**(code **)(*param_1 + 0x110))(param_1);
    puVar4 = PTR_DAT_fffffff007ca61d0;
    lVar17 = param_1[2];
    uVar1 = *(uint *)(lVar17 + 0x18b70);
    plVar7[2] = *(long *)PTR_DAT_fffffff007ca61d0;
    iVar5 = FUN_fffffff0081e07cc(plVar7,lVar17,iVar5 + 0x4000,uVar1 | 0x23);
    if (iVar5 != 0) {
      plVar8 = (long *)plVar7[10];
      if (plVar8 == (long *)0x0) {
        plVar8 = (long *)(**(code **)(*(long *)plVar7[9] + 0x90))
                                   ((long *)plVar7[9],plVar7[3],0x20900000084);
        if (plVar8 == (long *)0x0) goto LAB_fffffff0081efdd8;
        (**(code **)(*plVar8 + 0x20))();
        (**(code **)(*plVar8 + 0x28))(plVar8);
        plVar7[10] = (long)plVar8;
      }
      lVar17 = (**(code **)(*plVar8 + 0x98))();
      if (lVar17 != 0) {
        plVar8 = (long *)plVar7[0xc];
        if (plVar8 == (long *)0x0) {
          lVar17 = thunk_EXT_FUN_801100000297ea14(plVar7[9],0);
          plVar7[0xc] = lVar17;
          if (lVar17 == 0) goto LAB_fffffff0081efdd8;
          LOAcquire();
          DAT_fffffff00ae22f48 = DAT_fffffff00ae22f48 + plVar7[6];
          LORelease();
          plVar8 = (long *)plVar7[0xc];
        }
        lVar17 = (**(code **)(*plVar8 + 0x78))();
        if (((lVar17 != 0) && (iVar5 = FUN_fffffff0081e0b20(plVar7), iVar5 == 0)) &&
           (plVar8 = (long *)(**(code **)(DAT_fffffff00ae22f20 + 0x68))(&DAT_fffffff00ae22f20),
           plVar8 != (long *)0x0)) {
          lVar22 = (ulong)uVar3 * 0x538;
          uVar3 = iVar6 + iVar2;
          lVar17 = param_1[2];
          uVar1 = *(uint *)(lVar17 + 0x18b70);
          plVar8[2] = *(long *)puVar4;
          iVar6 = FUN_fffffff0081e07cc(plVar8,lVar17,lVar22 + (ulong)uVar3 * 0x38,uVar1 | 0x23);
          if (iVar6 != 0) {
            plVar9 = (long *)plVar8[10];
            if (plVar9 == (long *)0x0) {
              plVar9 = (long *)(**(code **)(*(long *)plVar8[9] + 0x90))
                                         ((long *)plVar8[9],plVar8[3],0x800000084);
              if (plVar9 == (long *)0x0) goto LAB_fffffff0081efdb8;
              (**(code **)(*plVar9 + 0x20))();
              (**(code **)(*plVar9 + 0x28))(plVar9);
              plVar8[10] = (long)plVar9;
            }
            lVar17 = (**(code **)(*plVar9 + 0x98))();
            if (lVar17 != 0) {
              plVar9 = (long *)plVar8[0xc];
              if (plVar9 == (long *)0x0) {
                lVar17 = thunk_EXT_FUN_801100000297ea14(plVar8[9],0);
                plVar8[0xc] = lVar17;
                if (lVar17 == 0) goto LAB_fffffff0081efdb8;
                LOAcquire();
                DAT_fffffff00ae22f48 = DAT_fffffff00ae22f48 + plVar8[6];
                LORelease();
                plVar9 = (long *)plVar8[0xc];
              }
              lVar17 = (**(code **)(*plVar9 + 0x78))();
              if ((lVar17 != 0) && (iVar6 = FUN_fffffff0081e0b20(plVar8), iVar6 == 0)) {
                param_1[0xc] = (long)plVar7;
                param_1[0xd] = (long)plVar8;
                uVar10 = (**(code **)(*(long *)plVar7[10] + 0x98))();
                lVar17 = (**(code **)(**(long **)(param_1[0xd] + 0x60) + 0x78))();
                uVar11 = (**(code **)(**(long **)(param_1[0xd] + 0x50) + 0x98))();
                lVar12 = (**(code **)(**(long **)(param_1[0xd] + 0x60) + 0x78))();
                lVar13 = (**(code **)(**(long **)(param_1[0xd] + 0x50) + 0x98))();
                lVar23 = *(long *)(*(long *)(param_1[2] + 0x4b0) + 0x910);
                param_1[0xe] = lVar17;
                *(uint *)(param_1 + 0xf) = *(uint *)(param_1 + 9);
                param_1[0x10] = lVar22 + lVar12;
                *(uint *)(param_1 + 0x11) = uVar3;
                thunk_EXT_FUN_8011000003a61cc0(lVar17,(ulong)*(uint *)(param_1 + 9) * 0x538);
                thunk_EXT_FUN_8011000003a61cc0
                          (param_1[0x10],(ulong)*(uint *)(param_1 + 0x11) * 0x38);
                if ((int)param_1[9] != 0) {
                  uVar18 = 0;
                  lVar17 = 0;
                  uVar14 = 0;
                  do {
                    puVar20 = (undefined8 *)(param_1[0xe] + uVar14 * 0x538);
                    if (((param_1[0xe] ^ (ulong)puVar20) & 0xffc0000000000000) != 0) {
                      puVar20 = (undefined8 *)((ulong)puVar20 & 0xffffffffffff | 0xc8a2000000000000)
                      ;
                    }
                    uVar15 = param_1[7];
                    if (uVar15 == 0) {
                      uVar16 = 0;
                    }
                    else {
                      uVar19 = uVar15 + (ulong)*(uint *)(param_1 + 8) * 0x68;
                      if (((uVar15 ^ uVar19) & 0xffc0000000000000) != 0) {
                        uVar19 = uVar19 & 0xffffffffffff | 0xc8a2000000000000;
                      }
                      uVar16 = uVar19 - uVar15;
                      if ((uVar19 < uVar15) || (uVar16 >> 0x20 != 0)) goto LAB_fffffff0081efdac;
                    }
                    if (lVar17 == 0x66c4ec8f0) goto LAB_fffffff0081efd88;
                    if (((long)uVar18 < 0) || ((uint)uVar16 < (int)(uVar18 >> 0x20) + 0x68U))
                    goto LAB_fffffff0081efd94;
                    uVar16 = (ulong)CARRY8(uVar15,uVar18 >> 0x20);
                    uVar19 = -uVar16;
                    if ((uVar19 != uVar16) || ((long)uVar19 < 0)) goto LAB_fffffff0081efda0;
                    puVar21 = *(undefined8 **)(uVar15 + (uVar18 >> 0x20));
                    uVar25 = puVar21[1];
                    uVar24 = *puVar21;
                    uVar27 = puVar21[3];
                    uVar26 = puVar21[2];
                    uVar29 = puVar21[5];
                    uVar28 = puVar21[4];
                    uVar31 = puVar21[7];
                    uVar30 = puVar21[6];
                    uVar33 = puVar21[9];
                    uVar32 = puVar21[8];
                    uVar35 = puVar21[0xb];
                    uVar34 = puVar21[10];
                    uVar37 = puVar21[0xd];
                    uVar36 = puVar21[0xc];
                    uVar39 = puVar21[0xf];
                    uVar38 = puVar21[0xe];
                    uVar41 = puVar21[0x11];
                    uVar40 = puVar21[0x10];
                    uVar43 = puVar21[0x13];
                    uVar42 = puVar21[0x12];
                    uVar45 = puVar21[0x15];
                    uVar44 = puVar21[0x14];
                    uVar47 = puVar21[0x17];
                    uVar46 = puVar21[0x16];
                    uVar48 = puVar21[0x18];
                    uVar50 = puVar21[0x1b];
                    uVar49 = puVar21[0x1a];
                    puVar20[0x19] = puVar21[0x19];
                    puVar20[0x18] = uVar48;
                    puVar20[0x1b] = uVar50;
                    puVar20[0x1a] = uVar49;
                    puVar20[0x15] = uVar45;
                    puVar20[0x14] = uVar44;
                    puVar20[0x17] = uVar47;
                    puVar20[0x16] = uVar46;
                    puVar20[0x11] = uVar41;
                    puVar20[0x10] = uVar40;
                    puVar20[0x13] = uVar43;
                    puVar20[0x12] = uVar42;
                    puVar20[0xd] = uVar37;
                    puVar20[0xc] = uVar36;
                    puVar20[0xf] = uVar39;
                    puVar20[0xe] = uVar38;
                    puVar20[9] = uVar33;
                    puVar20[8] = uVar32;
                    puVar20[0xb] = uVar35;
                    puVar20[10] = uVar34;
                    puVar20[5] = uVar29;
                    puVar20[4] = uVar28;
                    puVar20[7] = uVar31;
                    puVar20[6] = uVar30;
                    uVar14 = uVar14 + 1;
                    puVar20[1] = uVar25;
                    *puVar20 = uVar24;
                    puVar20[3] = uVar27;
                    puVar20[2] = uVar26;
                    lVar17 = lVar17 + 0x538;
                    uVar18 = uVar18 + 0x6800000000;
                  } while (uVar14 < *(uint *)(param_1 + 9));
                }
                *(undefined8 *)(lVar23 + 0x4060) = uVar11;
                *(int *)(lVar23 + 0x4068) = (int)param_1[0xf];
                *(long *)(lVar23 + 0x406c) = lVar13 + lVar22;
                *(int *)(lVar23 + 0x4074) = (int)param_1[0x11];
                *(undefined8 *)(lVar23 + 0x404c) = uVar10;
                *(undefined4 *)(lVar23 + 0x4054) = 0x4000;
                *(ulong *)(lVar23 + 0x4058) =
                     *(long *)(lVar23 + 0x404c) + (ulong)*(uint *)(lVar23 + 0x4054);
                thunk_EXT_FUN_801100000297d510(*(undefined8 *)(param_1[0xd] + 0x48));
                DataMemoryBarrier(2,3);
                goto LAB_fffffff0081efd68;
              }
            }
          }
LAB_fffffff0081efdb8:
          (**(code **)(*plVar8 + 0x28))(plVar8);
        }
      }
    }
LAB_fffffff0081efdd8:
    (**(code **)(*plVar7 + 0x28))(plVar7);
    uVar10 = 0;
  }
  return uVar10;
}

