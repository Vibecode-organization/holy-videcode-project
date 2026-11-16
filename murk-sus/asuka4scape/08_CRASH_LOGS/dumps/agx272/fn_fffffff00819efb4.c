// FUN_fffffff00819efb4 @ fffffff00819efb4 size=632

ulong FUN_fffffff00819efb4(long param_1)

{
  undefined *puVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  undefined8 *puVar5;
  ulong uVar6;
  ulong uVar7;
  long lVar8;
  long lVar9;
  code *pcVar10;
  long lVar11;
  
  pcVar10 = *(code **)(PTR_DAT_fffffff007ca6180 + 0x78);
  uVar3 = (*pcVar10)();
  if ((int)uVar3 == 0) {
    return uVar3;
  }
  *(undefined8 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  lVar4 = thunk_EXT_FUN_80110000038943cc(&DAT_fffffff007ca0c08,0x50);
  puVar5 = (undefined8 *)thunk_EXT_FUN_80110000038944ec(lVar4,&DAT_fffffff00ae21c90);
  *puVar5 = &DAT_fffffff007c934c8;
  thunk_EXT_FUN_80110000038922a0(&DAT_fffffff00ae21c90);
  *(long *)(param_1 + 0x18) = lVar4;
  puVar1 = PTR_DAT_fffffff007ca61e8;
  lVar11 = *(long *)PTR_DAT_fffffff007ca61e8;
  uVar3 = (*pcVar10)(lVar4);
  if ((int)uVar3 == 0) {
    return uVar3;
  }
  uVar3 = lVar11 + -1 + *(long *)puVar1 & -*(long *)puVar1;
  *(undefined8 *)(lVar4 + 0x10) = 1;
  *(ulong *)(lVar4 + 0x18) = uVar3;
  *(undefined8 *)(lVar4 + 0x30) = 0;
  *(undefined8 *)(lVar4 + 0x28) = 0;
  *(undefined8 *)(lVar4 + 0x20) = 0;
  *(undefined8 *)(lVar4 + 0x40) = 0;
  *(undefined8 *)(lVar4 + 0x38) = 0;
  *(undefined8 *)(lVar4 + 0x48) = 0;
  uVar3 = FUN_fffffff008183128(lVar4,lVar11 + -1 + uVar3 & -uVar3);
  if ((int)uVar3 == 0) {
    return uVar3;
  }
  lVar8 = *(long *)(param_1 + 0x18);
  lVar9 = *(long *)(lVar8 + 0x10);
  lVar4 = *(long *)(lVar8 + 0x40);
  lVar11 = *(long *)(lVar8 + 0x48);
  uVar3 = (**(code **)(**(long **)(lVar8 + 0x38) + 0x88))();
  if (uVar3 < (ulong)((lVar9 - lVar4) + lVar11)) {
    uVar6 = (**(code **)(**(long **)(lVar8 + 0x38) + 0x88))();
    uVar7 = *(ulong *)(lVar8 + 0x18);
    uVar3 = 0;
    if (uVar7 != 0) {
      uVar3 = (((lVar9 + ~uVar6) - *(long *)(lVar8 + 0x40)) + *(long *)(lVar8 + 0x48) + uVar7) /
              uVar7;
    }
    iVar2 = FUN_fffffff008183128(lVar8,uVar3 * uVar7);
    if (iVar2 == 0) goto LAB_fffffff00819f164;
  }
  thunk_EXT_FUN_8011000003a61b10(*(undefined8 *)(lVar8 + 0x48),"\n",lVar9);
  uVar3 = *(ulong *)(lVar8 + 0x48) + lVar9;
  if (((*(ulong *)(lVar8 + 0x48) ^ uVar3) & 0xffc0000000000000) != 0) {
    uVar3 = uVar3 & 0xffffffffffff | 0xc8a2000000000000;
  }
  *(ulong *)(lVar8 + 0x48) = uVar3;
LAB_fffffff00819f164:
  lVar4 = thunk_EXT_FUN_801100000389d0d8(5);
  if (*(long **)(param_1 + 0x20) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x20) + 0x28))();
  }
  *(long *)(param_1 + 0x20) = lVar4;
  if (lVar4 != 0) {
    lVar4 = thunk_EXT_FUN_801100000389d0d8(5);
    if (*(long **)(param_1 + 0x28) != (long *)0x0) {
      (**(code **)(**(long **)(param_1 + 0x28) + 0x28))();
    }
    *(long *)(param_1 + 0x28) = lVar4;
    if (lVar4 != 0) {
      lVar4 = thunk_EXT_FUN_801100000389d0d8(5);
      if (*(long **)(param_1 + 0x30) != (long *)0x0) {
        (**(code **)(**(long **)(param_1 + 0x30) + 0x28))();
      }
      *(long *)(param_1 + 0x30) = lVar4;
      return (ulong)(lVar4 != 0);
    }
  }
  return 0;
}

