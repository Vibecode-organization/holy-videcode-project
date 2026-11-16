// FUN_fffffff00996d884 @ fffffff00996d884 size=348

undefined8 FUN_fffffff00996d884(long param_1,long *param_2)

{
  long lVar1;
  undefined8 *puVar2;
  uint uVar3;
  ulong uVar4;
  undefined8 uVar5;
  int iVar6;
  ulong uVar7;
  ulong uVar8;
  long lVar9;
  
  uVar7 = (ulong)*(uint *)(param_1 + 0x30);
  iVar6 = *(int *)(param_1 + 0x34);
  if ((int)*(uint *)(param_1 + 0x30) < iVar6) {
    lVar9 = *(long *)(param_1 + 0x28);
  }
  else {
    if (iVar6 == 0) {
      uVar3 = *(uint *)(param_1 + 0x120);
    }
    else {
      uVar3 = iVar6 << 1;
    }
    uVar7 = 0x8000000000000000;
    if (-1 < (int)uVar3) {
      uVar7 = -(ulong)(uVar3 >> 0x1f) & 0xfffffff800000000 | (ulong)uVar3 << 3;
    }
    lVar9 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ff1958,uVar7);
    if (lVar9 == 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: failed to alloc array\n");
      return 0;
    }
    uVar7 = (ulong)*(int *)(param_1 + 0x30);
    if (*(int *)(param_1 + 0x30) != 0) {
      thunk_EXT_FUN_8011000003a61b10(lVar9,*(undefined8 *)(param_1 + 0x28),uVar7 << 3);
      lVar1 = -0x8000000000000000;
      if (-1 < *(int *)(param_1 + 0x34)) {
        lVar1 = (long)*(int *)(param_1 + 0x34) << 3;
      }
      uVar5 = *(undefined8 *)(param_1 + 0x28);
      *(undefined8 *)(param_1 + 0x28) = 0;
      thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ff19a8,uVar5,lVar1);
      uVar7 = (ulong)*(uint *)(param_1 + 0x30);
    }
    *(uint *)(param_1 + 0x34) = uVar3;
    *(long *)(param_1 + 0x28) = lVar9;
  }
  uVar4 = (uVar7 & 0xffffffff) << 3;
  uVar8 = -(uVar7 >> 0x1f & 1) & 0xfffffff800000000 | uVar4;
  iVar6 = (int)uVar4;
  puVar2 = (undefined8 *)(lVar9 + iVar6);
  if (uVar8 != (long)iVar6) {
    puVar2 = (undefined8 *)(lVar9 + uVar8 & 0xffffffffffff | 0x2bad000000000000);
  }
  *(int *)(param_1 + 0x30) = (int)uVar7 + 1;
  *puVar2 = param_2;
  lVar9 = (**(code **)(*param_2 + 0x108))(param_2);
  *(long *)(param_1 + 0x130) = *(long *)(param_1 + 0x130) + lVar9;
  return 1;
}

