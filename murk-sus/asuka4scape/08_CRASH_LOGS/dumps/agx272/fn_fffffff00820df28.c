// FUN_fffffff00820df28 @ fffffff00820df28 size=4

/* WARNING: Removing unreachable block (ram,0xfffffff00820e0dc) */
/* WARNING: Removing unreachable block (ram,0xfffffff00820e4dc) */
/* WARNING: Removing unreachable block (ram,0xfffffff00820e094) */

void FUN_fffffff00820df28(long param_1,long *param_2)

{
  ulong uVar1;
  ulong uVar2;
  code *pcVar3;
  long *plVar4;
  long *plVar5;
  long *plVar6;
  long *plVar7;
  long *plVar8;
  long *plVar9;
  long *plVar10;
  long *plVar11;
  long lVar12;
  long *plVar13;
  ulong uVar14;
  ulong uVar15;
  char *pcVar16;
  int iVar17;
  long *plVar18;
  long lVar19;
  ulong unaff_x30;
  undefined8 uStack_78;
  undefined8 uStack_70;
  long lStack_68;
  
  lStack_68 = *(long *)PTR_DAT_fffffff007ca61a0;
  if (*(long *)(param_1 + 0x20) == 0) goto LAB_fffffff00820e5d8;
  plVar18 = *(long **)(*(long *)(param_1 + 0x10) + 0x4b0);
  plVar4 = (long *)thunk_EXT_FUN_80110000038ce200("com.apple.agx.ctxswitchlatency");
  plVar5 = (long *)thunk_EXT_FUN_80110000038ce200("dm");
  plVar6 = (long *)thunk_EXT_FUN_80110000038ce200("support_ipad_pro");
  plVar7 = (long *)thunk_EXT_FUN_80110000038970c4(0);
  lVar19 = 0;
  do {
    plVar8 = (long *)thunk_EXT_FUN_801100000389d0d8(10);
    if (plVar8 != (long *)0x0) {
      plVar9 = (long *)thunk_EXT_FUN_80110000038ce200((&DAT_fffffff007c9fc20)[lVar19]);
      (**(code **)(*plVar8 + 0xf8))(plVar8,plVar5,plVar9);
      (**(code **)(*plVar8 + 0xf8))(plVar8,plVar6,plVar7);
      plVar10 = (long *)(**(code **)(*plVar18 + 0x408))(*plVar18 + 0x408,plVar18,lVar19,0);
      plVar11 = (long *)(**(code **)(*plVar18 + 0x408))(*plVar18 + 0x408,plVar18,lVar19,1);
      if (plVar10 == (long *)0x0) {
LAB_fffffff00820e228:
        if (plVar11 != (long *)0x0) {
LAB_fffffff00820e234:
          (**(code **)(*plVar11 + 0x28))(plVar11);
        }
        if (plVar10 != (long *)0x0) goto LAB_fffffff00820e254;
      }
      else {
        if (plVar11 != (long *)0x0) {
          iVar17 = 0;
          do {
            uStack_78 = 0;
            uStack_70 = 0;
            if (iVar17 == 0xb) {
              pcVar16 = "max_us";
            }
            else {
              plVar13 = (long *)(**(code **)(*plVar10 + 0x118))(plVar10,iVar17);
              if (plVar13 == (long *)0x0) goto LAB_fffffff00820e228;
              (**(code **)(*plVar13 + 0xa8))();
              pcVar16 = "%d_%uus";
            }
            thunk_EXT_FUN_80110000037693ec(&uStack_78,0x10,pcVar16);
            lVar12 = (**(code **)(*plVar11 + 0x118))(plVar11,iVar17);
            if (lVar12 == 0) goto LAB_fffffff00820e228;
            (**(code **)(*plVar8 + 0x100))(plVar8,&uStack_78,lVar12);
            iVar17 = iVar17 + 1;
          } while (iVar17 != 0xc);
          if (*(long *)(param_1 + 0x20) == 0) {
            (**(code **)(*plVar4 + 0xa8))();
          }
          else {
            thunk_EXT_FUN_80110000024b8af4(*(long *)(param_1 + 0x20),plVar4,plVar8);
          }
          plVar13 = (long *)(**(code **)(*plVar18 + 0x408))(plVar18,lVar19,2);
          if (plVar13 != (long *)0x0) {
            (**(code **)(*plVar13 + 0x28))();
          }
          goto LAB_fffffff00820e234;
        }
LAB_fffffff00820e254:
        (**(code **)(*plVar10 + 0x28))(plVar10);
      }
      if (plVar9 != (long *)0x0) {
        (**(code **)(*plVar9 + 0x28))(plVar9);
      }
      (**(code **)(*plVar8 + 0x28))(plVar8);
    }
    lVar19 = lVar19 + 1;
  } while (lVar19 != 3);
  if (plVar7 != (long *)0x0) {
    (**(code **)(*plVar7 + 0x28))(plVar7);
  }
  if (plVar6 != (long *)0x0) {
    (**(code **)(*plVar6 + 0x28))(plVar6);
  }
  if (plVar5 != (long *)0x0) {
    (**(code **)(*plVar5 + 0x28))(plVar5);
  }
  if (plVar4 != (long *)0x0) {
    (**(code **)(*plVar4 + 0x28))();
  }
  lVar19 = *(long *)(*(long *)(param_1 + 0x10) + 0x1ac50);
  if (lVar19 == 0) goto LAB_fffffff00820e5d8;
  if (*(long *)(lVar19 + 0x458) == 0) {
    uVar14 = 0;
LAB_fffffff00820e408:
    uVar15 = 0;
  }
  else {
    uVar14 = thunk_EXT_FUN_80110000039b575c(*(long *)(lVar19 + 0x458),0x54484d5f41435456);
    if (*(long *)(lVar19 + 0x458) == 0) goto LAB_fffffff00820e408;
    uVar15 = thunk_EXT_FUN_80110000039b575c(*(long *)(lVar19 + 0x458),0x5346455449455233);
  }
  uVar1 = 0;
  if (*(ulong *)(param_1 + 0x38) <= uVar14) {
    uVar1 = *(ulong *)(param_1 + 0x38);
  }
  uVar2 = 0;
  if (*(ulong *)(param_1 + 0x40) <= uVar15) {
    uVar2 = *(ulong *)(param_1 + 0x40);
  }
  *(ulong *)(param_1 + 0x38) = uVar14;
  *(ulong *)(param_1 + 0x40) = uVar15;
  if ((uVar14 - uVar1 == 0) && (uVar15 == uVar2)) goto LAB_fffffff00820e5d8;
  plVar4 = (long *)thunk_EXT_FUN_80110000038ce200("com.apple.agx.thmcounters");
  plVar5 = (long *)thunk_EXT_FUN_801100000389d0d8(2);
  if (plVar4 == (long *)0x0) {
    if (plVar5 == (long *)0x0) goto LAB_fffffff00820e5d8;
LAB_fffffff00820e594:
    (**(code **)(*plVar5 + 0x28))(plVar5);
    if (plVar4 == (long *)0x0) goto LAB_fffffff00820e5d8;
  }
  else if (plVar5 != (long *)0x0) {
    plVar6 = (long *)thunk_EXT_FUN_80110000038c6e24(uVar14 - uVar1,0x40);
    plVar7 = (long *)thunk_EXT_FUN_80110000038c6e24(uVar15 - uVar2,0x40);
    if (plVar6 == (long *)0x0) {
      if (plVar7 == (long *)0x0) goto LAB_fffffff00820e594;
LAB_fffffff00820e550:
      (**(code **)(*plVar7 + 0x28))(plVar7);
      if (plVar6 == (long *)0x0) goto LAB_fffffff00820e594;
    }
    else if (plVar7 != (long *)0x0) {
      (**(code **)(*plVar5 + 0x100))(plVar5,"thm_activations",plVar6);
      (**(code **)(*plVar5 + 0x100))(*plVar5 + 0x100,plVar5,"sfe_tier3",plVar7);
      if (*(long *)(param_1 + 0x20) == 0) {
        (**(code **)(*plVar4 + 0xa8))(plVar4);
      }
      else {
        thunk_EXT_FUN_80110000024b8af4(*(long *)(param_1 + 0x20),plVar4,plVar5);
      }
      goto LAB_fffffff00820e550;
    }
    (**(code **)(*plVar6 + 0x28))(plVar6);
    goto LAB_fffffff00820e594;
  }
  (**(code **)(*plVar4 + 0x28))(plVar4);
LAB_fffffff00820e5d8:
  if (*(long *)PTR_DAT_fffffff007ca61a0 != lStack_68) {
    thunk_EXT_FUN_8011000003a48590();
    return;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00820e644);
    (*pcVar3)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff00820e64c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_2 + 0xf0))(param_2,3600000,(undefined8 *)(*param_2 + 0xf0));
  return;
}

