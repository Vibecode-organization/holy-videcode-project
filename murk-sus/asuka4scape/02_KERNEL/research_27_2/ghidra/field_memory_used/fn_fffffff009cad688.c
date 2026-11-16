// FUN_fffffff009cad688 @ fffffff009cad688

void FUN_fffffff009cad688(long param_1)

{
  long *plVar1;
  uint *puVar2;
  ulong uVar3;
  ulong uVar4;
  ulong uVar5;
  ulong uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  long lVar11;
  
  plVar1 = (long *)(**(code **)(**(long **)(param_1 + 0xb8) + 0x118))
                             (*(long **)(param_1 + 0xb8),"eps-dir-bitmap");
  plVar1 = thunk_FUN_fffffff00a894f30(plVar1,*(long *)PTR_PTR_fffffff008081398);
  if (plVar1 == (long *)0x0) {
    uVar7 = 0;
  }
  else {
    puVar2 = (uint *)(**(code **)(*plVar1 + 0xd8))();
    uVar7 = *puVar2;
  }
  uVar8 = 0;
  uVar9 = 0;
  uVar6 = 0;
  uVar3 = 0;
  do {
    uVar10 = uVar7 >> (ulong)(uVar8 & 0x1f) & 3;
    if (uVar10 < 2) {
      uVar5 = uVar6;
      if ((uVar10 == 0) && (uVar6 < 0x10)) {
        *(char *)(param_1 + 0x260d + uVar6) = (char)uVar9;
        uVar5 = uVar6 + 1;
      }
      uVar6 = uVar5;
      if (uVar3 < 0x10) {
        lVar11 = 0x25fd;
        uVar4 = uVar3 + 1;
        uVar6 = uVar3;
        uVar10 = uVar9 | 0xffffff80;
LAB_fffffff009cad788:
        *(char *)(param_1 + lVar11 + uVar6) = (char)uVar10;
        uVar3 = uVar4;
        uVar6 = uVar5;
      }
    }
    else if (uVar10 == 2 && uVar6 < 0x10) {
      uVar5 = uVar6 + 1;
      lVar11 = 0x260d;
      uVar4 = uVar3;
      uVar10 = uVar9;
      goto LAB_fffffff009cad788;
    }
    uVar9 = uVar9 + 1;
    uVar8 = uVar8 + 2;
  } while (uVar9 != 0x10);
  uVar8 = 0;
  uVar9 = 0;
  do {
    uVar10 = uVar7 >> (ulong)(uVar8 & 0x1f) & 3;
    if (uVar10 == 2) {
      if (uVar3 < 0x10) {
        uVar10 = uVar9 | 0xffffff80;
        uVar5 = uVar3 + 1;
        lVar11 = 0x25fd;
        uVar4 = uVar6;
        goto LAB_fffffff009cad7f0;
      }
    }
    else if (uVar10 == 1 && uVar6 < 0x10) {
      lVar11 = 0x260d;
      uVar5 = uVar3;
      uVar4 = uVar6 + 1;
      uVar3 = uVar6;
      uVar10 = uVar9;
LAB_fffffff009cad7f0:
      *(char *)(param_1 + lVar11 + uVar3) = (char)uVar10;
      uVar3 = uVar5;
      uVar6 = uVar4;
    }
    uVar9 = uVar9 + 1;
    uVar8 = uVar8 + 2;
    if (uVar9 == 0x10) {
      if (uVar6 < 0x10) {
        do {
          *(char *)(param_1 + 0x260d + uVar6) = (char)uVar6;
          uVar6 = uVar6 + 1;
        } while ((int)uVar6 != 0x10);
      }
      if (uVar3 < 0x10) {
        do {
          *(char *)(param_1 + 0x25fd + uVar3) = (char)uVar3;
          uVar3 = uVar3 + 1;
        } while ((int)uVar3 != 0x10);
      }
      return;
    }
  } while( true );
}

