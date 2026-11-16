// FUN_fffffff0081e36b0 @ fffffff0081e36b0 size=796

undefined8 FUN_fffffff0081e36b0(long param_1,ulong param_2)

{
  uint uVar1;
  undefined8 *puVar2;
  long *plVar3;
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  int iVar6;
  long *plVar7;
  long *plVar8;
  long *plVar9;
  long lVar10;
  long lVar11;
  long lVar12;
  undefined8 *puVar13;
  undefined8 uVar14;
  ulong uVar15;
  ulong uVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  int local_64;
  
  uVar15 = (ulong)*(uint *)(param_1 + 0x20);
  if (uVar15 <= param_2) {
    uVar14 = *(undefined8 *)(*(long *)(param_1 + 0x18) + 0xf8);
    local_64 = 0;
    uVar16 = *(ulong *)(param_1 + 0x30);
    do {
      lVar10 = *(long *)(param_1 + 0x18);
      if ((*(byte *)(lVar10 + 0x1ac44) >> 3 & 1) != 0) {
        thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar10 + 0x1ac48));
        thunk_EXT_FUN_80110000036da494(0x85930d0c,param_1,param_2,uVar15,uVar16,0);
        thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar10 + 0x1ac48));
        uVar16 = *(ulong *)(param_1 + 0x30);
      }
      if (*(ulong *)(param_1 + 0x38) == uVar16) {
        uVar15 = uVar16 * 2;
        if (uVar15 == 0) {
          lVar10 = 0;
        }
        else {
          auVar4._8_8_ = 0;
          auVar4._0_8_ = uVar15;
          lVar10 = -0x8000000000000000;
          if (SUB168(auVar4 * ZEXT816(0x18),8) == 0 && -1 < (long)(uVar16 * 0x30)) {
            lVar10 = uVar16 * 0x30;
          }
          lVar10 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ca4378,lVar10);
          if (lVar10 == 0) {
            return 0;
          }
          uVar16 = *(ulong *)(param_1 + 0x38);
        }
        if (uVar16 != 0) {
          uVar16 = 0;
          do {
            puVar13 = (undefined8 *)(*(ulong *)(param_1 + 0x28) + uVar16 * 0x18);
            if (((*(ulong *)(param_1 + 0x28) ^ (ulong)puVar13) & 0xffc0000000000000) != 0) {
              puVar13 = (undefined8 *)((ulong)puVar13 & 0xffffffffffff | 0xc8a2000000000000);
            }
            lVar12 = uVar16 * 0x18;
            puVar2 = (undefined8 *)(lVar10 + (int)lVar12);
            if (lVar12 - (int)lVar12 != 0) {
              puVar2 = (undefined8 *)(lVar10 + lVar12 & 0xffffffffffffU | 0x2bad000000000000);
            }
            uVar18 = puVar13[1];
            uVar17 = *puVar13;
            puVar2[2] = puVar13[2];
            puVar2[1] = uVar18;
            *puVar2 = uVar17;
            uVar16 = uVar16 + 1;
          } while (uVar16 < *(ulong *)(param_1 + 0x38));
        }
        uVar17 = *(undefined8 *)(param_1 + 0x28);
        auVar5._8_8_ = 0;
        auVar5._0_8_ = *(ulong *)(param_1 + 0x30);
        lVar11 = *(ulong *)(param_1 + 0x30) * 0x18;
        lVar12 = -0x8000000000000000;
        if (SUB168(auVar5 * ZEXT816(0x18),8) == 0 && -1 < lVar11) {
          lVar12 = lVar11;
        }
        *(undefined8 *)(param_1 + 0x28) = 0;
        thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ca43c8,uVar17,lVar12);
        *(long *)(param_1 + 0x28) = lVar10;
        *(ulong *)(param_1 + 0x30) = uVar15;
      }
      plVar7 = (long *)thunk_EXT_FUN_8011000002c32c6c(uVar14,param_2,&local_64);
      if (plVar7 == (long *)0x0) {
        return 0;
      }
      plVar8 = (long *)thunk_EXT_FUN_801100000297d1cc(*(undefined8 *)(param_1 + 0x18),0,plVar7);
      if (plVar8 == (long *)0x0) {
LAB_fffffff0081e3990:
        (**(code **)(*plVar7 + 0x28))(plVar7);
        return 0;
      }
      plVar9 = (long *)(**(code **)(*plVar8 + 0x90))
                                 (plVar8,*(undefined8 *)(*(long *)(param_1 + 0x18) + 0x11da0),
                                  0x800000005);
      if (plVar9 == (long *)0x0) {
        (**(code **)(*plVar7 + 0x28))(plVar7);
        plVar7 = plVar8;
        goto LAB_fffffff0081e3990;
      }
      iVar6 = thunk_EXT_FUN_801100000297b3fc();
      if (iVar6 != 0) {
        (**(code **)(*plVar7 + 0x28))(plVar7);
        (**(code **)(*plVar8 + 0x28))(plVar8);
        plVar7 = plVar9;
        goto LAB_fffffff0081e3990;
      }
      uVar16 = *(ulong *)(param_1 + 0x30);
      uVar15 = *(ulong *)(param_1 + 0x38);
      if (uVar15 < uVar16) {
        lVar10 = uVar15 * 0x18;
        plVar3 = (long *)(*(long *)(param_1 + 0x28) + (long)(int)lVar10);
        if (lVar10 - (int)lVar10 != 0) {
          plVar3 = (long *)(*(long *)(param_1 + 0x28) + lVar10 & 0xffffffffffffU |
                           0x2bad000000000000);
        }
        *(ulong *)(param_1 + 0x38) = uVar15 + 1;
        *plVar3 = (long)plVar8;
        plVar3[1] = (long)plVar7;
        plVar3[2] = (long)plVar9;
      }
      uVar1 = *(int *)(param_1 + 0x20) + local_64;
      uVar15 = (ulong)uVar1;
      *(uint *)(param_1 + 0x20) = uVar1;
    } while (uVar15 <= param_2);
  }
  return 1;
}

