// FUN_fffffff00816a380 @ fffffff00816a380 size=4

/* WARNING: Removing unreachable block (ram,0xfffffff00816a6fc) */

void FUN_fffffff00816a380(long param_1,long *param_2)

{
  int *piVar1;
  code *pcVar2;
  int iVar3;
  long *plVar4;
  undefined8 *puVar5;
  ulong uVar6;
  ulong uVar7;
  long *plVar8;
  long *plVar9;
  long *plVar10;
  char *pcVar11;
  long lVar12;
  ulong uVar13;
  long lVar14;
  long *plVar15;
  long lVar16;
  undefined8 uVar17;
  long lVar18;
  ulong unaff_x30;
  long *plStack_68;
  
  plVar4 = (long *)thunk_EXT_FUN_80110000038943cc(&DAT_fffffff007ca0f08,0x38);
  puVar5 = (undefined8 *)thunk_EXT_FUN_80110000038944ec(plVar4,&DAT_fffffff00ae22210);
  *puVar5 = &DAT_fffffff007c94c10;
  puVar5[4] = 0;
  puVar5[5] = 0;
  puVar5[6] = 0;
  thunk_EXT_FUN_80110000038922a0(&DAT_fffffff00ae22210);
  if ((param_2 == (long *)0x0) || (iVar3 = (**(code **)(*plVar4 + 0x68))(plVar4), iVar3 == 0))
  goto LAB_fffffff00816a910;
  lVar16 = *(long *)(param_1 + 0x148);
  lVar12 = *(long *)(lVar16 + 0x10);
  lVar14 = *(long *)(lVar12 + 0x480);
  lVar18 = *(long *)(lVar12 + 0x488);
  FUN_fffffff00819f584(plVar4,"[Stamps]\n");
  lVar12 = 0;
  do {
    iVar3 = thunk_EXT_FUN_80110000029490c4(lVar16,lVar12);
    if (((iVar3 != 0) || (*(int *)(lVar14 + lVar12 * 4) != 0)) ||
       (*(int *)(lVar18 + lVar12 * 4) != 0)) {
      pcVar11 = "[%3d]=%8u\t%8u\t%8u\n";
      if ((iVar3 == *(int *)(lVar14 + lVar12 * 4)) && (iVar3 == *(int *)(lVar18 + lVar12 * 4))) {
        pcVar11 = "[%3d]=%8u\n";
      }
      FUN_fffffff00819f584(plVar4,pcVar11);
    }
    lVar12 = lVar12 + 1;
  } while (lVar12 != 0x80);
  FUN_fffffff00819f584(plVar4,"[Workqueues]\n");
  FUN_fffffff00819f584(plVar4,"Skipped\n");
  FUN_fffffff00819f584(plVar4,"[Fences]\n");
  uVar17 = *(undefined8 *)(param_1 + 0x11e48);
  iVar3 = thunk_EXT_FUN_8011000003222c9c(uVar17);
  if (iVar3 == 0) {
    thunk_EXT_FUN_80110000038fe968(1);
    iVar3 = thunk_EXT_FUN_8011000003222c9c(uVar17);
    if (iVar3 != 0) goto LAB_fffffff00816a580;
    thunk_EXT_FUN_80110000038fe968(1);
    iVar3 = thunk_EXT_FUN_8011000003222c9c(uVar17);
    if (iVar3 != 0) goto LAB_fffffff00816a580;
    thunk_EXT_FUN_80110000038fe968(1);
    iVar3 = thunk_EXT_FUN_8011000003222c9c(uVar17);
    if (iVar3 != 0) goto LAB_fffffff00816a580;
    thunk_EXT_FUN_80110000038fe968(1);
    iVar3 = thunk_EXT_FUN_8011000003222c9c(uVar17);
    if (iVar3 != 0) goto LAB_fffffff00816a580;
    thunk_EXT_FUN_80110000038fe968(1);
    FUN_fffffff00819f584(plVar4,"Unable to acquire lock\n");
  }
  else {
LAB_fffffff00816a580:
    lVar12 = *(long *)(param_1 + 0x11ed8);
    while (lVar12 != 0) {
      lVar14 = *(long *)(lVar12 + 0x38);
      piVar1 = (int *)(lVar12 + 0x28);
      lVar12 = lVar14;
      if (*piVar1 != 0) {
        FUN_fffffff00819f584(plVar4,"Fences\n");
        FUN_fffffff00819f584(plVar4,"%d %d, %d %d\n");
        FUN_fffffff00819f584(plVar4,"\t[%d]: %d\n");
        FUN_fffffff00819f584(plVar4,"\t[%d]: %d\n");
        FUN_fffffff00819f584(plVar4,"\t[%d]: %d\n");
      }
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x11e48));
  }
  FUN_fffffff00819f584(plVar4,"[SC] %d %llu\n");
  FUN_fffffff00819f584(plVar4,"[SL] %d %d %u %llu %llu\n");
  FUN_fffffff00819f584(plVar4,"[RC] %d %llu\n");
  FUN_fffffff00819f584(plVar4,"[MS] %llu\n");
  lVar12 = **(long **)(param_1 + 0x4b0);
  (**(code **)(lVar12 + 0x640))(lVar12 + 0x640,*(long **)(param_1 + 0x4b0),plVar4);
  lVar16 = plVar4[3];
  lVar18 = *(long *)(lVar16 + 0x10);
  lVar12 = *(long *)(lVar16 + 0x40);
  lVar14 = *(long *)(lVar16 + 0x48);
  uVar6 = (**(code **)(**(long **)(lVar16 + 0x38) + 0x88))();
  if (uVar6 < (ulong)((lVar18 - lVar12) + lVar14)) {
    uVar7 = (**(code **)(**(long **)(lVar16 + 0x38) + 0x88))();
    uVar13 = *(ulong *)(lVar16 + 0x18);
    uVar6 = 0;
    if (uVar13 != 0) {
      uVar6 = (((lVar18 + ~uVar7) - *(long *)(lVar16 + 0x40)) + *(long *)(lVar16 + 0x48) + uVar13) /
              uVar13;
    }
    iVar3 = FUN_fffffff008183128(lVar16,uVar6 * uVar13);
    if (iVar3 != 0) goto LAB_fffffff00816a7a4;
  }
  else {
LAB_fffffff00816a7a4:
    thunk_EXT_FUN_8011000003a61cc0(*(undefined8 *)(lVar16 + 0x48),lVar18);
    uVar6 = *(ulong *)(lVar16 + 0x48) + lVar18;
    if (((*(ulong *)(lVar16 + 0x48) ^ uVar6) & 0xffc0000000000000) != 0) {
      uVar6 = uVar6 & 0xffffffffffff | 0xc8a2000000000000;
    }
    *(ulong *)(lVar16 + 0x48) = uVar6;
  }
  uVar17 = *(undefined8 *)(plVar4[3] + 0x40);
  plVar8 = (long *)thunk_EXT_FUN_801100000389a264(uVar17,*(int *)(plVar4[3] + 0x48) - (int)uVar17);
  uVar17 = thunk_EXT_FUN_8011000003397c88();
  plVar9 = (long *)thunk_EXT_FUN_80110000038c6e24(uVar17,0x40);
  plVar10 = (long *)thunk_EXT_FUN_801100000389d0d8(3);
  if ((plVar8 == (long *)0x0) || (plVar9 == (long *)0x0)) {
    if (plVar10 != (long *)0x0) {
      (**(code **)(*plVar10 + 0x28))(plVar10);
      (**(code **)(*plVar10 + 0x28))(plVar10);
    }
    plVar15 = (long *)0x0;
    plVar10 = (long *)0x0;
    if (plVar9 != (long *)0x0) goto LAB_fffffff00816a8c4;
  }
  else {
    if (plVar10 != (long *)0x0) {
      plStack_68 = plVar8;
      (**(code **)(*plVar8 + 0x20))(plVar8);
      thunk_EXT_FUN_801100000389d40c(plVar10,"logs",&plStack_68);
      if (plStack_68 != (long *)0x0) {
        (**(code **)(*plStack_68 + 0x28))();
      }
      plStack_68 = plVar9;
      (**(code **)(*plVar9 + 0x20))(plVar9);
      thunk_EXT_FUN_801100000389d40c(plVar10,"timestamp",&plStack_68);
      if (plStack_68 != (long *)0x0) {
        (**(code **)(*plStack_68 + 0x28))();
      }
    }
LAB_fffffff00816a8c4:
    plVar15 = plVar10;
    (**(code **)(*plVar9 + 0x28))(plVar9);
  }
  if (plVar8 != (long *)0x0) {
    (**(code **)(*plVar8 + 0x28))(plVar8);
  }
  *param_2 = (long)plVar15;
LAB_fffffff00816a910:
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00816a954);
    (*pcVar2)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff00816a95c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*plVar4 + 0x28))(plVar4,(undefined8 *)(*plVar4 + 0x28));
  return;
}

