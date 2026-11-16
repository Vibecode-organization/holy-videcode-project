// FUN_fffffff009c45b34 @ fffffff009c45b34 size=1152

/* WARNING: Removing unreachable block (ram,0xfffffff009c45d94) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c45de0) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c45d48) */

bool FUN_fffffff009c45b34(undefined8 param_1,long *param_2)

{
  uint uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  bool bVar5;
  uint uVar6;
  int iVar7;
  undefined8 uVar8;
  long *plVar9;
  long *plVar10;
  undefined8 uVar11;
  long *plVar12;
  long *plVar13;
  long *plVar14;
  long *plVar15;
  long *plVar16;
  ulong uVar17;
  long lVar18;
  undefined8 uVar19;
  undefined8 uVar20;
  long *plVar21;
  undefined8 uVar22;
  
  uVar8 = (**(code **)(*param_2 + 0x138))(param_2,DAT_fffffff008066fd0);
  plVar9 = (long *)thunk_EXT_FUN_8011000003890f30(uVar8,*(undefined8 *)PTR_DAT_fffffff00806c9f0);
  if (plVar9 != (long *)0x0) {
    (**(code **)(*plVar9 + 0x20))(plVar9);
  }
  plVar10 = (long *)thunk_EXT_FUN_8011000003898a6c(plVar9);
  uVar4 = DAT_fffffff008066fb8;
  uVar3 = DAT_fffffff008066f98;
  uVar2 = DAT_fffffff008066ee0;
  uVar8 = DAT_fffffff008066e50;
  if (plVar10 == (long *)0x0) {
    bVar5 = true;
  }
  else {
    uVar19 = *(undefined8 *)PTR_DAT_fffffff00806c9c8;
    uVar22 = *(undefined8 *)PTR_DAT_fffffff00806c9f8;
    uVar20 = *(undefined8 *)PTR_DAT_fffffff00806ca20;
    plVar21 = (long *)0x0;
    do {
      do {
        uVar11 = (**(code **)(*plVar10 + 0x88))(plVar10);
        plVar12 = (long *)thunk_EXT_FUN_8011000003890f30(uVar11,uVar19);
        bVar5 = plVar12 == (long *)0x0;
        if (plVar12 != (long *)0x0) {
          (**(code **)(*plVar12 + 0x20))(plVar12);
        }
        if (plVar21 != (long *)0x0) {
          (**(code **)(*plVar21 + 0x28))(plVar21);
        }
        if (plVar12 == (long *)0x0) goto LAB_fffffff009c45f24;
        uVar11 = (**(code **)(*plVar12 + 0x138))(plVar12,uVar2);
        plVar13 = (long *)thunk_EXT_FUN_8011000003890f30(uVar11,uVar22);
        uVar11 = (**(code **)(*plVar12 + 0x138))(*plVar12 + 0x138,plVar12,uVar8);
        plVar14 = (long *)thunk_EXT_FUN_8011000003890f30(uVar11,uVar22);
        uVar11 = (**(code **)(*plVar12 + 0x138))(*plVar12 + 0x138,plVar12,uVar4);
        plVar15 = (long *)thunk_EXT_FUN_8011000003890f30(uVar11,uVar20);
        uVar11 = (**(code **)(*plVar12 + 0x138))(*plVar12 + 0x138,plVar12,uVar3);
        plVar16 = (long *)thunk_EXT_FUN_8011000003890f30(uVar11,uVar20);
        plVar21 = plVar12;
      } while (plVar13 == (long *)0x0 || plVar14 == (long *)0x0);
      uVar6 = (**(code **)(*plVar13 + 0xa8))(plVar13);
      uVar1 = uVar6 | 0x110023;
      if (plVar15 != (long *)0x0) {
        iVar7 = (**(code **)(*plVar15 + 0x88))(plVar15);
        uVar1 = uVar6 | 0x910023;
        if (iVar7 == 0) {
          uVar1 = uVar6 | 0x110023;
        }
      }
      if ((plVar16 == (long *)0x0) ||
         (uVar17 = (**(code **)(*plVar16 + 0x88))(plVar16), (uVar17 & 1) == 0)) {
        uVar1 = uVar1 | 0x40;
      }
      lVar18 = (**(code **)(*plVar14 + 0xb0))(plVar14);
      uVar17 = (ulong)(uint)~(-1 << (ulong)(*(uint *)PTR_DAT_fffffff00806c9b0 & 0x1f));
      uVar17 = FUN_fffffff009c46b38(param_1,uVar1,lVar18 + uVar17 & (uVar17 ^ 0xffffffffffffffff));
    } while ((uVar17 & 1) != 0);
    (**(code **)(*plVar12 + 0x28))(plVar12);
LAB_fffffff009c45f24:
    (**(code **)(*plVar10 + 0x28))(plVar10);
  }
  if (plVar9 != (long *)0x0) {
    (**(code **)(*plVar9 + 0x28))(plVar9);
  }
  (**(code **)(*param_2 + 0x28))(param_2);
  return bVar5;
}

