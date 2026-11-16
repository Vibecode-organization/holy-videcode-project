// FUN_fffffff0081b42a0 @ fffffff0081b42a0 size=808

undefined8 FUN_fffffff0081b42a0(long *param_1)

{
  uint uVar1;
  undefined8 *puVar2;
  uint uVar3;
  long *plVar4;
  undefined8 *puVar5;
  uint uVar6;
  undefined *puVar7;
  bool bVar8;
  int iVar9;
  long lVar10;
  ulong uVar11;
  uint uVar12;
  long lVar13;
  ulong uVar14;
  ulong uVar15;
  uint uVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined8 uVar20;
  ulong local_80 [4];
  
  puVar7 = PTR_DAT_fffffff007ca61a8;
  if (0x4000 < (uint)((int)param_1[9] + (int)param_1[9] * (int)param_1[0x14])) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ca61a8,0x10,"AGXk: out of fw resources");
    thunk_EXT_FUN_80110000038db19c(&MACH_HEADER,puVar7,1,"AGXk: out of fw resources");
    return 0;
  }
  lVar10 = (**(code **)*param_1)();
  if (lVar10 == 0) {
    return 0;
  }
  uVar12 = *(uint *)(param_1 + 0x14);
  uVar15 = (ulong)uVar12;
  uVar11 = param_1[0x10];
  if (uVar15 < uVar11) {
    uVar15 = 0;
    do {
      if (*(long *)(param_1[0xf] + uVar15 * 8) == 0) break;
      uVar15 = (ulong)((int)uVar15 + 1);
    } while (uVar15 < uVar11);
    uVar12 = (uint)uVar15;
    if (uVar11 == uVar15) goto LAB_fffffff0081b455c;
  }
  else if (uVar11 == uVar15) {
    iVar9 = FUN_fffffff0081b3c4c(param_1,uVar12 + 1);
    if (iVar9 == 0) goto LAB_fffffff0081b455c;
    uVar11 = param_1[0x10];
  }
  if (uVar15 < uVar11) {
    lVar13 = uVar15 * 8;
    plVar4 = (long *)(param_1[0xf] + (long)(int)lVar13);
    if (lVar13 - (int)lVar13 != 0) {
      plVar4 = (long *)(param_1[0xf] + lVar13 & 0xffffffffffffU | 0x2bad000000000000);
    }
    *plVar4 = lVar10;
    *(int *)(param_1 + 0x14) = (int)param_1[0x14] + 1;
    uVar6 = *(uint *)(param_1 + 9);
    if (uVar6 != 0) {
      uVar16 = 0;
      lVar10 = param_1[0x13];
      do {
        uVar1 = uVar16 + uVar6 * uVar12;
        uVar11 = (ulong)(uVar1 >> 0xb) & 0x1ffff8;
        *(ulong *)((long)param_1 + uVar11 + 0x90) =
             1L << ((ulong)(uVar1 >> 8) & 0x3f) | *(ulong *)((long)param_1 + uVar11 + 0x90);
        uVar3 = uVar6 - uVar16;
        if (0xff < (uVar1 & 0xff) + (uVar6 - uVar16)) {
          uVar3 = 0x100 - (uVar1 & 0xff);
        }
        puVar2 = (undefined8 *)(lVar10 + (ulong)(uVar1 >> 8) * 0x20);
        local_80[1] = 0;
        local_80[0] = 0;
        local_80[3] = 0;
        local_80[2] = 0;
        uVar1 = uVar3 - 0x40;
        if (uVar3 < 0x40) {
          uVar11 = 0;
          uVar1 = uVar3;
        }
        else {
          uVar11 = (ulong)((uVar1 >> 6) + 1);
          if (uVar1 < 0xc0) {
            uVar15 = 0;
LAB_fffffff0081b44fc:
            lVar13 = ((ulong)(uVar1 >> 6) ^ 0xffffffffffffffff) + uVar15;
            do {
              iVar9 = (int)(uVar15 * 8);
              puVar5 = (undefined8 *)((long)local_80 + (long)iVar9);
              if (uVar15 * 8 - (long)iVar9 != 0) {
                puVar5 = (undefined8 *)
                         ((ulong)(local_80 + uVar15) & 0xffffffffffff | 0x2bad000000000000);
              }
              *puVar5 = 0xffffffffffffffff;
              uVar15 = uVar15 + 1;
              bVar8 = lVar13 != -1;
              lVar13 = lVar13 + 1;
            } while (bVar8);
          }
          else {
            lVar13 = 0;
            uVar15 = uVar11 & 0x7fffffc;
            uVar14 = uVar15;
            do {
              local_80[lVar13 + 1] = 0xffffffffffffffff;
              local_80[lVar13] = 0xffffffffffffffff;
              local_80[lVar13 + 3] = 0xffffffffffffffff;
              local_80[lVar13 + 2] = 0xffffffffffffffff;
              lVar13 = lVar13 + 4;
              uVar14 = uVar14 - 4;
            } while (uVar14 != 0);
            if (uVar15 != uVar11) goto LAB_fffffff0081b44fc;
          }
          uVar1 = uVar3 & 0x3f;
        }
        if (uVar1 != 0) {
          local_80[uVar11] = local_80[uVar11] | -1L << ((ulong)uVar1 & 0x3f) ^ 0xffffffffffffffffU;
        }
        FUN_fffffff0081ad280(local_80);
        uVar18 = puVar2[1];
        uVar17 = *puVar2;
        uVar20 = puVar2[3];
        uVar19 = puVar2[2];
        puVar2[1] = CONCAT17((byte)((ulong)uVar18 >> 0x38) | (byte)(local_80[1] >> 0x38),
                             CONCAT16((byte)((ulong)uVar18 >> 0x30) | (byte)(local_80[1] >> 0x30),
                                      CONCAT15((byte)((ulong)uVar18 >> 0x28) |
                                               (byte)(local_80[1] >> 0x28),
                                               CONCAT14((byte)((ulong)uVar18 >> 0x20) |
                                                        (byte)(local_80[1] >> 0x20),
                                                        CONCAT13((byte)((ulong)uVar18 >> 0x18) |
                                                                 (byte)(local_80[1] >> 0x18),
                                                                 CONCAT12((byte)((ulong)uVar18 >>
                                                                                0x10) |
                                                                          (byte)(local_80[1] >> 0x10
                                                                                ),CONCAT11((byte)((
                                                  ulong)uVar18 >> 8) | (byte)(local_80[1] >> 8),
                                                  (byte)uVar18 | (byte)local_80[1])))))));
        *puVar2 = CONCAT17((byte)((ulong)uVar17 >> 0x38) | (byte)(local_80[0] >> 0x38),
                           CONCAT16((byte)((ulong)uVar17 >> 0x30) | (byte)(local_80[0] >> 0x30),
                                    CONCAT15((byte)((ulong)uVar17 >> 0x28) |
                                             (byte)(local_80[0] >> 0x28),
                                             CONCAT14((byte)((ulong)uVar17 >> 0x20) |
                                                      (byte)(local_80[0] >> 0x20),
                                                      CONCAT13((byte)((ulong)uVar17 >> 0x18) |
                                                               (byte)(local_80[0] >> 0x18),
                                                               CONCAT12((byte)((ulong)uVar17 >> 0x10
                                                                              ) | (byte)(local_80[0]
                                                                                        >> 0x10),
                                                                        CONCAT11((byte)((ulong)
                                                  uVar17 >> 8) | (byte)(local_80[0] >> 8),
                                                  (byte)uVar17 | (byte)local_80[0])))))));
        puVar2[3] = CONCAT17((byte)((ulong)uVar20 >> 0x38) | (byte)(local_80[3] >> 0x38),
                             CONCAT16((byte)((ulong)uVar20 >> 0x30) | (byte)(local_80[3] >> 0x30),
                                      CONCAT15((byte)((ulong)uVar20 >> 0x28) |
                                               (byte)(local_80[3] >> 0x28),
                                               CONCAT14((byte)((ulong)uVar20 >> 0x20) |
                                                        (byte)(local_80[3] >> 0x20),
                                                        CONCAT13((byte)((ulong)uVar20 >> 0x18) |
                                                                 (byte)(local_80[3] >> 0x18),
                                                                 CONCAT12((byte)((ulong)uVar20 >>
                                                                                0x10) |
                                                                          (byte)(local_80[3] >> 0x10
                                                                                ),CONCAT11((byte)((
                                                  ulong)uVar20 >> 8) | (byte)(local_80[3] >> 8),
                                                  (byte)uVar20 | (byte)local_80[3])))))));
        puVar2[2] = CONCAT17((byte)((ulong)uVar19 >> 0x38) | (byte)(local_80[2] >> 0x38),
                             CONCAT16((byte)((ulong)uVar19 >> 0x30) | (byte)(local_80[2] >> 0x30),
                                      CONCAT15((byte)((ulong)uVar19 >> 0x28) |
                                               (byte)(local_80[2] >> 0x28),
                                               CONCAT14((byte)((ulong)uVar19 >> 0x20) |
                                                        (byte)(local_80[2] >> 0x20),
                                                        CONCAT13((byte)((ulong)uVar19 >> 0x18) |
                                                                 (byte)(local_80[2] >> 0x18),
                                                                 CONCAT12((byte)((ulong)uVar19 >>
                                                                                0x10) |
                                                                          (byte)(local_80[2] >> 0x10
                                                                                ),CONCAT11((byte)((
                                                  ulong)uVar19 >> 8) | (byte)(local_80[2] >> 8),
                                                  (byte)uVar19 | (byte)local_80[2])))))));
        uVar16 = uVar3 + uVar16;
      } while (uVar16 < uVar6);
    }
    return 1;
  }
LAB_fffffff0081b455c:
  (**(code **)(*param_1 + 8))(param_1,lVar10);
  puVar7 = PTR_DAT_fffffff007ca61a8;
  thunk_EXT_FUN_80110000038db19c
            (&MACH_HEADER,PTR_DAT_fffffff007ca61a8,0x10,"AGXk: failed to grow fw resources");
  thunk_EXT_FUN_80110000038db19c(&MACH_HEADER,puVar7,1,"AGXk: failed to grow fw resources");
  return 0;
}

