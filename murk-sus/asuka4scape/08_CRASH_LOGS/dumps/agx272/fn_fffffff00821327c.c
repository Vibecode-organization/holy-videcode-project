// FUN_fffffff00821327c @ fffffff00821327c size=776

undefined8 FUN_fffffff00821327c(long param_1)

{
  int iVar1;
  undefined1 *puVar2;
  undefined8 *puVar3;
  long *plVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  byte bVar9;
  byte bVar10;
  long lVar11;
  uint uVar12;
  bool bVar13;
  int iVar14;
  undefined8 uVar15;
  long lVar16;
  long lVar17;
  long *plVar18;
  ulong uVar19;
  long lVar20;
  undefined4 local_6c;
  int iStack_68;
  undefined4 local_64;
  
  lVar17 = *(long *)(param_1 + 0x20);
  plVar4 = *(long **)(param_1 + 0x28);
  lVar16 = *(long *)(param_1 + 0x30);
  bVar9 = *(byte *)(param_1 + 0x38);
  lVar20 = *(long *)(lVar16 + 0x140);
  bVar10 = *(byte *)(lVar16 + 0x4c);
  uVar5 = *(uint *)(plVar4 + 0x1c);
  uVar19 = (ulong)uVar5;
  if (((bVar10 & 1) == 0) || ((*(byte *)(*(long *)(lVar17 + 0xc0) + 0x239) & 1) != 0)) {
    uVar6 = *(uint *)((long)plVar4 + 0xf4);
    uVar7 = *(uint *)(plVar4 + 0xb);
    uVar12 = 0;
    if (uVar7 != 0) {
      uVar12 = uVar6 / uVar7;
    }
    lVar11 = (ulong)(uVar6 - uVar12 * uVar7) * 8;
    puVar3 = (undefined8 *)(plVar4[0x1d] + (long)(int)lVar11);
    if (lVar11 != (int)lVar11) {
      puVar3 = (undefined8 *)(plVar4[0x1d] + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
    }
    *puVar3 = *(undefined8 *)(lVar16 + 0x68);
    iStack_68 = uVar6 + 1;
    *(int *)((long)plVar4 + 0xf4) = iStack_68;
  }
  else {
    iStack_68 = *(int *)((long)plVar4 + 0xf4);
  }
  uVar8 = *(undefined4 *)(plVar4[0xd] + 0x40);
  local_64 = (undefined4)plVar4[0x21];
  local_6c = uVar8;
  if (lVar20 == 0) {
    bVar13 = false;
  }
  else {
    iVar14 = 0;
    if (*(int *)(lVar20 + 0x28) != 0) {
      lVar16 = uVar19 * 0xc;
      puVar3 = (undefined8 *)(lVar20 + 0x4c + (long)(int)lVar16);
      if (lVar16 - (int)lVar16 != 0) {
        puVar3 = (undefined8 *)(lVar20 + 0x4c + lVar16 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *(undefined4 *)(puVar3 + 1) = local_64;
      *puVar3 = CONCAT44(iStack_68,uVar8);
      puVar2 = (undefined1 *)(lVar20 + 0x48 + (long)(int)uVar5);
      if (uVar19 != (long)(int)uVar5) {
        puVar2 = (undefined1 *)(lVar20 + 0x48 + uVar19 & 0xffffffffffff | 0x2bad000000000000);
      }
      *puVar2 = 1;
      uVar15 = thunk_EXT_FUN_8011000003397c88();
      *(undefined8 *)(lVar20 + 0x290) = uVar15;
      iVar14 = *(int *)(lVar20 + 0x28);
    }
    iVar1 = *(int *)(lVar20 + 0x20) + 1;
    *(int *)(lVar20 + 0x20) = iVar1;
    lVar16 = *(long *)(lVar20 + 0x10);
    if ((*(byte *)(lVar16 + 0x1ac44) >> 3 & 1) != 0) {
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar16 + 0x1ac48));
      thunk_EXT_FUN_80110000036da494(0x85930c74,lVar20,iVar1,plVar4,iVar14,0);
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar16 + 0x1ac48));
      iVar14 = *(int *)(lVar20 + 0x28);
    }
    bVar13 = iVar14 != 0;
    *(long *)(lVar20 + 0x70) = lVar17;
    if ((iVar14 != 0) && (uVar5 != 0)) {
      *(undefined8 *)(lVar20 + 0x78) = 0;
      plVar18 = *(long **)(lVar17 + 0xe0);
      *(long **)(lVar20 + 0x80) = plVar18;
      *plVar18 = lVar20;
      *(undefined8 **)(lVar17 + 0xe0) = (undefined8 *)(lVar20 + 0x78);
      bVar13 = true;
    }
  }
  lVar16 = *(long *)(lVar17 + 0xd8);
  lVar20 = *(long *)(lVar17 + 0xc0);
  if ((*(byte *)(lVar20 + 0x1ac44) >> 3 & 1) != 0) {
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar20 + 0x1ac48));
    thunk_EXT_FUN_80110000036da494(0x85930c88,uVar19,lVar17,lVar16 == 0,bVar10 & 1,0);
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar20 + 0x1ac48));
  }
  if ((lVar16 == 0 & (bVar10 ^ 1)) == 0) {
    lVar16 = *(long *)(lVar17 + 0xc0);
    if ((*(byte *)(lVar16 + 0x1ac44) >> 3 & 1) != 0) {
      lVar20 = plVar4[0x13];
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar16 + 0x1ac48));
      thunk_EXT_FUN_80110000036da494(0x85930c80,uVar19,lVar17,lVar20,uVar8,0);
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar16 + 0x1ac48));
    }
    if ((!bVar13) && (lVar17 = **(long **)(*(long *)(lVar17 + 0xe0) + 8), lVar17 != 0)) {
      lVar17 = lVar17 + 0x4c;
      lVar16 = uVar19 * 0xc;
      puVar3 = (undefined8 *)(lVar17 + (int)lVar16);
      if (lVar16 - (int)lVar16 != 0) {
        puVar3 = (undefined8 *)(lVar17 + lVar16 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *(undefined4 *)(puVar3 + 1) = local_64;
      *puVar3 = CONCAT44(iStack_68,local_6c);
    }
  }
  else {
    iVar14 = (**(code **)(&DAT_fffffff007c93658 + (ulong)*(uint *)(plVar4 + 0x1c) * 0x10))
                       (*(undefined8 *)(lVar17 + 0xc0),plVar4,&local_6c,bVar9 & 1);
    if (iVar14 != 0) {
      (**(code **)(*plVar4 + 0x140))(plVar4);
    }
  }
  return 0;
}

