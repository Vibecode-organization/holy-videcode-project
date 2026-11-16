// FUN_fffffff009c26c38 @ fffffff009c26c38 size=916

void FUN_fffffff009c26c38(long param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  code *pcVar4;
  long lVar5;
  long lVar6;
  long *plVar7;
  long *plVar8;
  long lVar9;
  long local_80;
  long *local_78;
  undefined8 local_70;
  long local_68;
  
  local_78 = &local_80;
  local_68 = *(long *)PTR_DAT_fffffff00806ca40;
  local_80 = 0;
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x50));
  lVar6 = *(long *)(param_1 + 0x240);
  while (lVar5 = lVar6, lVar5 != 0) {
    plVar7 = (long *)(lVar5 + 0x58);
    lVar6 = *plVar7;
    if (*(int *)(lVar5 + 0x4c) != 0) {
      if (lVar6 == 0) {
        plVar8 = *(long **)(lVar5 + 0x60);
        if (*plVar8 != lVar5) goto LAB_fffffff009c26fa0;
        *(long **)(param_1 + 0x248) = plVar8;
      }
      else {
        if (*(long **)(lVar6 + 0x60) != plVar7) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009c26fb4);
          (*pcVar4)();
        }
        plVar8 = *(long **)(lVar5 + 0x60);
        if (*plVar8 != lVar5) {
LAB_fffffff009c26fa0:
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009c26fa4);
          (*pcVar4)();
        }
        *(long **)(lVar6 + 0x60) = plVar8;
        plVar8 = *(long **)(lVar5 + 0x60);
      }
      *plVar8 = lVar6;
      *plVar7 = 0x1656;
      *(undefined1 **)(lVar5 + 0x60) = &DAT_cafecafe;
    }
  }
  lVar6 = *(long *)(param_1 + 0x250);
  plVar7 = local_78;
  if (lVar6 != 0) {
    do {
      while( true ) {
        lVar5 = *(long *)(lVar6 + 0x58);
        if (*(int *)(lVar6 + 0x4c) != 0) break;
LAB_fffffff009c26d78:
        lVar6 = lVar5;
        if (lVar5 == 0) goto LAB_fffffff009c26d9c;
      }
      if (lVar5 == 0) {
        plVar8 = *(long **)(lVar6 + 0x60);
        if (*plVar8 != lVar6) goto LAB_fffffff009c26fa4;
        *(long **)(param_1 + 600) = plVar8;
      }
      else {
        if (*(long **)(lVar5 + 0x60) != (long *)(lVar6 + 0x58)) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009c26fb8);
          (*pcVar4)();
        }
        if (**(long **)(lVar6 + 0x60) != lVar6) {
LAB_fffffff009c26fa4:
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009c26fa8);
          (*pcVar4)();
        }
        *(long **)(lVar5 + 0x60) = *(long **)(lVar6 + 0x60);
        plVar8 = *(long **)(lVar6 + 0x60);
      }
      *plVar8 = lVar5;
      *(undefined8 *)(lVar6 + 0x58) = 0x165f;
      *(undefined1 **)(lVar6 + 0x60) = &DAT_cafecafe;
      if (*(int *)(lVar6 + 0x48) != 0) goto LAB_fffffff009c26d78;
      plVar8 = (long *)(lVar6 + 0x68);
      *plVar8 = 0;
      *(long **)(lVar6 + 0x70) = plVar7;
      *plVar7 = lVar6;
      lVar6 = lVar5;
      plVar7 = plVar8;
      local_78 = plVar8;
    } while (lVar5 != 0);
LAB_fffffff009c26d9c:
    lVar6 = *(long *)(param_1 + 0x250);
    while (lVar6 != 0) {
      plVar7 = (long *)(lVar6 + 0x58);
      lVar9 = *plVar7;
      for (lVar5 = *(long *)(param_1 + 0x240); lVar5 != 0; lVar5 = *(long *)(lVar5 + 0x58)) {
        if (((*(int *)(lVar5 + 0x4c) == 0) &&
            ((((*(byte *)(lVar6 + 0x52) & 1) == 0 || (*(int *)(lVar6 + 0x20) == 0)) ||
             (*(int *)(lVar6 + 0x20) != *(int *)(lVar5 + 0x20))))) &&
           ((*(int *)(lVar6 + 0x24) != 1 || (*(int *)(lVar5 + 0x24) != 1))))
        goto LAB_fffffff009c26e84;
      }
      if (lVar9 == 0) {
        plVar8 = *(long **)(lVar6 + 0x60);
        if (*plVar8 != lVar6) goto LAB_fffffff009c26fb8;
        *(long **)(param_1 + 600) = plVar8;
      }
      else {
        if (*(long **)(lVar9 + 0x60) != plVar7) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009c26fc8);
          (*pcVar4)();
        }
        if (**(long **)(lVar6 + 0x60) != lVar6) {
LAB_fffffff009c26fb8:
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009c26fc0);
          (*pcVar4)();
        }
        *(long **)(lVar9 + 0x60) = *(long **)(lVar6 + 0x60);
        plVar8 = *(long **)(lVar6 + 0x60);
      }
      *plVar8 = lVar9;
      *(long *)(lVar6 + 0x68) = 0;
      *(long **)(lVar6 + 0x70) = local_78;
      *local_78 = lVar6;
      plVar8 = *(long **)(param_1 + 0x248);
      *(undefined8 *)(lVar6 + 0x58) = 0;
      *(long **)(lVar6 + 0x60) = plVar8;
      *plVar8 = lVar6;
      *(long **)(param_1 + 0x248) = plVar7;
      *(undefined1 *)(lVar6 + 0x53) = 1;
      local_78 = (long *)(lVar6 + 0x68);
      FUN_fffffff009c26bc4(param_1,lVar6);
      *(undefined1 *)(lVar6 + 0x51) = 1;
      lVar6 = lVar9;
    }
  }
LAB_fffffff009c26e84:
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x50));
  lVar6 = local_80;
  do {
    if (lVar6 == 0) {
      if (*(long *)PTR_DAT_fffffff00806ca40 == local_68) {
        return;
      }
      thunk_EXT_FUN_8011000003a48590();
      return;
    }
    lVar5 = *(long *)(lVar6 + 0x68);
    if (lVar5 == 0) {
      plVar8 = *(long **)(lVar6 + 0x70);
      plVar7 = plVar8;
      if (*plVar8 != lVar6) goto LAB_fffffff009c26f98;
    }
    else {
      if (*(long **)(lVar5 + 0x70) != (long *)(lVar6 + 0x68)) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009c26fb0);
        (*pcVar4)();
      }
      if (**(long **)(lVar6 + 0x70) != lVar6) {
LAB_fffffff009c26f98:
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009c26fa0);
        (*pcVar4)();
      }
      *(long **)(lVar5 + 0x70) = *(long **)(lVar6 + 0x70);
      plVar8 = *(long **)(lVar6 + 0x70);
      plVar7 = local_78;
    }
    local_78 = plVar7;
    *plVar8 = lVar5;
    *(undefined8 *)(lVar6 + 0x68) = 0x168f;
    *(undefined1 **)(lVar6 + 0x70) = &DAT_cafecafe;
    uVar3 = *(undefined4 *)(param_1 + 0x10);
    uVar1 = *(undefined4 *)(lVar6 + 0x20);
    uVar2 = *(undefined4 *)(lVar6 + 0x24);
    local_70 = 0;
    thunk_EXT_FUN_80110000032db760(*(undefined8 *)(param_1 + 0x30),&local_70);
    thunk_EXT_FUN_80110000036da494(0x85210008,uVar1,uVar3,uVar2,local_70,0);
    *(undefined1 *)(lVar6 + 0x50) = 1;
    if (*(code **)(lVar6 + 0x28) == (code *)0x0) {
      FUN_fffffff009c371ac(DAT_fffffff00af483b0,lVar6);
      lVar6 = lVar5;
    }
    else {
      (**(code **)(lVar6 + 0x28))
                (*(undefined8 *)(lVar6 + 0x30),*(undefined8 *)(lVar6 + 0x38),param_1,
                 *(undefined4 *)(lVar6 + 0x48));
      lVar6 = lVar5;
    }
  } while( true );
}

