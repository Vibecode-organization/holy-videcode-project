// FUN_fffffff0081ff0d0 @ fffffff0081ff0d0 size=940

/* WARNING: Removing unreachable block (ram,0xfffffff0081ff214) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081ff340) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081ff1a4) */

undefined8 FUN_fffffff0081ff0d0(long *param_1,long *param_2)

{
  ulong uVar1;
  undefined8 *puVar2;
  undefined *puVar3;
  code *pcVar4;
  int iVar5;
  long *plVar6;
  undefined8 uVar7;
  uint *puVar8;
  long lVar9;
  long *plVar10;
  undefined8 *puVar11;
  long lVar12;
  ulong uVar13;
  undefined8 *puVar14;
  undefined8 *puVar15;
  ulong uVar16;
  long lVar17;
  ulong unaff_x30;
  
  iVar5 = (**(code **)(PTR_DAT_fffffff007ca6180 + 0x78))();
  if (iVar5 == 0) {
    return 0;
  }
  lVar12 = param_2[0xb3];
  param_1[8] = (long)param_2;
  param_1[9] = lVar12;
  puVar3 = PTR_DAT_fffffff007ca5f88;
  if (((*(byte *)((long)param_2 + 0x1096c) & 1) != 0) && (lVar12 == 0)) {
    return 0;
  }
  lVar17 = (long)(1 << (ulong)(*(uint *)PTR_DAT_fffffff007ca5f88 & 0x1f));
  plVar6 = (long *)(**(code **)(*param_2 + 0x370))(param_2);
  lVar12 = (**(code **)(*plVar6 + 0x118))(*plVar6 + 0x118,plVar6,"gptbat-ready");
  if (lVar12 == 0) {
    plVar6 = (long *)thunk_EXT_FUN_8011000003962c64
                               (3,lVar17,(long)(1 << (ulong)(*(uint *)puVar3 & 0x1f)));
  }
  else {
    plVar6 = (long *)(**(code **)(*(long *)param_1[8] + 0x370))();
    uVar7 = (**(code **)(*plVar6 + 0x118))(*plVar6 + 0x118,plVar6,"ttbat-phys-addr-base");
    plVar6 = (long *)thunk_EXT_FUN_8011000003890f30(uVar7,*(undefined8 *)PTR_DAT_fffffff007ca6090);
    lVar9 = 0;
    if (plVar6 != (long *)0x0) {
      iVar5 = (**(code **)(*plVar6 + 0xa0))();
      if (iVar5 == 4) {
        puVar8 = (uint *)(**(code **)(*plVar6 + 0xd8))(plVar6);
        lVar9 = (ulong)*puVar8 << 0xe;
      }
      else {
        lVar9 = 0;
      }
    }
    plVar6 = (long *)thunk_EXT_FUN_8011000003976f54(lVar9,lVar17,3);
  }
  if (plVar6 == (long *)0x0) {
    return 0;
  }
  plVar10 = (long *)(**(code **)(*plVar6 + 0xe8))(plVar6,0);
  if (plVar10 == (long *)0x0) {
LAB_fffffff0081ff460:
    (**(code **)(*plVar6 + 0x28))(plVar6);
    return 0;
  }
  iVar5 = (**(code **)(*plVar6 + 0xd8))(plVar6,3);
  if (iVar5 != 0) {
    (**(code **)(*plVar10 + 0x28))(plVar10);
    goto LAB_fffffff0081ff460;
  }
  puVar11 = (undefined8 *)(**(code **)(*plVar10 + 0x78))(plVar10);
  if (lVar12 != 0) {
    param_1[2] = (long)plVar6;
    param_1[3] = (long)plVar10;
    param_1[4] = (long)puVar11;
    goto LAB_fffffff0081ff40c;
  }
  puVar2 = (undefined8 *)((long)puVar11 + lVar17);
  if (puVar11 < puVar2) {
    puVar15 = puVar2;
    if (puVar2 <= puVar11 + 1) {
      puVar15 = puVar11 + 1;
    }
    puVar14 = puVar11;
    if (0x17 < (long)puVar15 + ~(ulong)puVar11) {
      uVar1 = ((long)puVar15 + ~(ulong)puVar11 >> 3) + 1;
      uVar13 = uVar1 & 0x3ffffffffffffffc;
      puVar15 = puVar11 + 2;
      uVar16 = uVar13;
      do {
        puVar15[-1] = 0;
        puVar15[-2] = 0;
        puVar15[1] = 0;
        *puVar15 = 0;
        puVar15 = puVar15 + 4;
        uVar16 = uVar16 - 4;
      } while (uVar16 != 0);
      if (uVar1 == uVar13) goto LAB_fffffff0081ff3dc;
      puVar14 = puVar11 + uVar13;
    }
    do {
      puVar15 = puVar14 + 1;
      *puVar14 = 0;
      puVar14 = puVar15;
    } while (puVar15 < puVar2);
  }
LAB_fffffff0081ff3dc:
  param_1[2] = (long)plVar6;
  param_1[3] = (long)plVar10;
  param_1[4] = (long)puVar11;
  (**(code **)(*param_1 + 200))(param_1);
LAB_fffffff0081ff40c:
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081ff444);
    (*pcVar4)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff0081ff44c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  uVar7 = (**(code **)(*param_1 + 0xe0))(param_1,(undefined8 *)(*param_1 + 0xe0));
  return uVar7;
}

