// FUN_fffffff009c34898 @ fffffff009c34898 size=4

void FUN_fffffff009c34898(long param_1,undefined8 param_2)

{
  long *plVar1;
  code *pcVar2;
  ulong uVar3;
  bool bVar4;
  long *plVar5;
  long *plVar6;
  long lVar7;
  long lVar8;
  int iVar9;
  long lStack_48;
  long *plStack_40;
  long lStack_38;
  
  lStack_38 = *(long *)PTR_DAT_fffffff00806ca40;
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x140));
  iVar9 = 0;
  plStack_40 = &lStack_48;
  lStack_48 = 0;
  do {
    for (lVar8 = *(long *)(param_1 + 0x90); lVar8 != 0; lVar8 = *(long *)(lVar8 + 0x18)) {
      uVar3 = FUN_fffffff009c2360c(lVar8,param_2,&lStack_48);
      if ((uVar3 & 1) == 0) {
        thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x140));
        thunk_EXT_FUN_80110000038fe968(0xfa);
        thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x140));
        bVar4 = false;
        goto LAB_fffffff009c34928;
      }
    }
    bVar4 = true;
LAB_fffffff009c34928:
    if (iVar9 == 0xf0) {
      FUN_fffffff009c491f4();
      goto LAB_fffffff009c34a08;
    }
    iVar9 = iVar9 + 1;
  } while (!bVar4);
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x140));
  lVar8 = lStack_48;
  do {
    if (lVar8 == 0) {
      if (*(long *)PTR_DAT_fffffff00806ca40 == lStack_38) {
        return;
      }
LAB_fffffff009c34a08:
      thunk_EXT_FUN_8011000003a48590();
      return;
    }
    lVar7 = *(long *)(lVar8 + 0x30);
    plVar6 = *(long **)(lVar8 + 0x10);
    if (lVar7 == 0) {
      plVar5 = *(long **)(lVar8 + 0x38);
      plVar1 = plVar5;
      if (*plVar5 != lVar8) goto LAB_fffffff009c349f4;
    }
    else {
      if (*(long **)(lVar7 + 0x38) != (long *)(lVar8 + 0x30)) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009c34a04);
        (*pcVar2)();
      }
      if (**(long **)(lVar8 + 0x38) != lVar8) {
LAB_fffffff009c349f4:
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009c349fc);
        (*pcVar2)();
      }
      *(long **)(lVar7 + 0x38) = *(long **)(lVar8 + 0x38);
      plVar5 = *(long **)(lVar8 + 0x38);
      plVar1 = plStack_40;
    }
    plStack_40 = plVar1;
    *plVar5 = lVar7;
    FUN_fffffff009c2da10();
    lVar8 = lVar7;
    if (plVar6 != (long *)0x0) {
      (**(code **)(*plVar6 + 0x28))(plVar6);
    }
  } while( true );
}

