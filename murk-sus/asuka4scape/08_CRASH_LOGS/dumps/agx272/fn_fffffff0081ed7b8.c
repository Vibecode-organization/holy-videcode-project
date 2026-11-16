// FUN_fffffff0081ed7b8 @ fffffff0081ed7b8 size=912

long * FUN_fffffff0081ed7b8(long param_1)

{
  uint uVar1;
  ulong uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  long *plVar6;
  long *plVar7;
  long *plVar8;
  undefined8 uVar9;
  long lVar10;
  ulong uVar11;
  
  uVar4 = **(uint **)(param_1 + 0x88);
  if (*(uint *)(param_1 + 0x138) <= uVar4) goto LAB_fffffff0081edaa0;
  uVar1 = uVar4 + 1;
  uVar3 = 0;
  if (uVar1 != *(uint *)(param_1 + 0x138)) {
    uVar3 = uVar4 + 1;
  }
  if (uVar3 == (*(uint **)(param_1 + 0x88))[2]) {
    return (long *)0x0;
  }
  lVar10 = (ulong)uVar4 * 0x40;
  uVar11 = *(long *)(param_1 + 0x188) + (long)(int)lVar10;
  if (lVar10 != (int)lVar10) {
    uVar11 = *(long *)(param_1 + 0x188) + lVar10 & 0xffffffffffffU | 0x2bad000000000000;
  }
  iVar5 = thunk_EXT_FUN_80110000029479f8(*(undefined8 *)(*(long *)(param_1 + 0x10) + 0x148),uVar11);
  if (iVar5 == 0) {
    return (long *)0x0;
  }
  plVar6 = (long *)(**(code **)(DAT_fffffff00ae23480 + 0x68))();
  if (plVar6 == (long *)0x0) {
    return (long *)0x0;
  }
  (**(code **)(*plVar6 + 0x68))();
  lVar10 = *(long *)(param_1 + 0x10);
  uVar9 = *(undefined8 *)(param_1 + 0x18);
  plVar7 = (long *)thunk_EXT_FUN_8011000003962900
                             (0,*(uint *)(lVar10 + 0x18b70) | 0x100063,0x20000,0x8000);
  if (plVar7 != (long *)0x0) {
    plVar8 = (long *)thunk_EXT_FUN_801100000297d1cc(lVar10,0,plVar7);
    if (plVar8 != (long *)0x0) {
      thunk_EXT_FUN_801100000297d2f8();
      uVar11 = *(ulong *)(lVar10 + 0x5c8) & 0x200000000000;
      uVar2 = 0x500000000;
      if (uVar11 != 0) {
        uVar2 = 0x100000000;
      }
      uVar9 = thunk_EXT_FUN_80110000029636a8(uVar9);
      lVar10 = (**(code **)(*plVar8 + 0x90))(plVar8,uVar9,uVar2 | uVar11 >> 9 | 7);
      plVar6[3] = lVar10;
      (**(code **)(*plVar8 + 0x28))(plVar8);
      if (lVar10 != 0) {
        plVar8 = (long *)plVar6[3];
        if ((*(ushort *)(plVar8 + 2) & 1) == 0) {
          uVar11 = (**(code **)(*plVar8 + 0xb0))();
          plVar8 = (long *)plVar6[3];
          if ((uVar11 & 1) == 0) {
            if (plVar8 != (long *)0x0) {
              (**(code **)(*plVar8 + 0x28))();
            }
            plVar6[3] = 0;
            goto LAB_fffffff0081edaf8;
          }
        }
        lVar10 = plVar8[3];
        if (lVar10 == 0) {
          plVar6 = (long *)thunk_EXT_FUN_8011000003a49114
                                     ("AGXk: %s:%d:%s: !!! unbacked mapping cannot be volatile\n");
          return plVar6;
        }
        thunk_EXT_FUN_801100000293ed9c(lVar10,*(uint *)(lVar10 + 0x30) | 8);
        (**(code **)(*plVar7 + 0x28))(plVar7);
        if (*(uint *)(*(long *)(plVar6[3] + 0x18) + 0x78) < *(uint *)(param_1 + 0x108)) {
          thunk_EXT_FUN_801100000293ff9c();
        }
        *(uint *)((long)plVar6 + 0xc) = uVar4;
        uVar4 = *(uint *)(param_1 + 0x138);
        uVar3 = 0;
        if (uVar4 != 0) {
          uVar3 = uVar1 / uVar4;
        }
        **(int **)(param_1 + 0x88) = uVar1 - uVar3 * uVar4;
        uVar1 = *(uint *)(param_1 + 0x238);
        if (uVar4 <= uVar1) {
LAB_fffffff0081edaa0:
          plVar6 = (long *)thunk_EXT_FUN_8011000003a49114
                                     (
                                     "AGXk: %s:%d:%s: !!! Assertion failed: %s: OOB access in GPU Driver Resource\n"
                                     );
          return plVar6;
        }
        lVar10 = (ulong)uVar1 * 8;
        plVar7 = (long *)(*(long *)(param_1 + 0x230) + (long)(int)lVar10);
        if (lVar10 - (int)lVar10 != 0) {
          plVar7 = (long *)(*(long *)(param_1 + 0x230) + lVar10 & 0xffffffffffffU |
                           0x2bad000000000000);
        }
        *plVar7 = plVar6[3];
        *(uint *)(param_1 + 0x238) = uVar1 + 1;
        (**(code **)(*plVar6 + 0x20))(plVar6);
        plVar7 = plVar6;
        goto LAB_fffffff0081eda3c;
      }
    }
LAB_fffffff0081edaf8:
    (**(code **)(*plVar7 + 0x28))(plVar7);
  }
  plVar7 = (long *)0x0;
LAB_fffffff0081eda3c:
  (**(code **)(*plVar6 + 0x28))(plVar6);
  return plVar7;
}

