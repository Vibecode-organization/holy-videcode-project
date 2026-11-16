// FUN_fffffff0099504ec @ fffffff0099504ec size=296

void FUN_fffffff0099504ec(long param_1)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  long *plVar5;
  long lVar6;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x20));
  if (*(int *)(param_1 + 0x38) != 0) {
    lVar6 = *(long *)(param_1 + 0x28);
    while (lVar1 = lVar6, lVar1 != 0) {
      lVar6 = *(long *)(lVar1 + 0x50);
      iVar3 = FUN_fffffff00994b4ec(*(undefined8 *)(param_1 + 0x18),lVar1);
      if (iVar3 != 0) {
        thunk_EXT_FUN_8011000002c3d314(*(undefined8 *)(lVar1 + 0x40),*(undefined4 *)(lVar1 + 0x60));
        lVar4 = *(long *)(lVar1 + 0x50);
        if (lVar4 == 0) {
          plVar5 = *(long **)(lVar1 + 0x58);
          if (*plVar5 != lVar1) goto LAB_fffffff009950604;
          *(long **)(param_1 + 0x30) = plVar5;
        }
        else {
          if (*(long **)(lVar4 + 0x58) != (long *)(lVar1 + 0x50)) {
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009950614);
            (*pcVar2)();
          }
          if (**(long **)(lVar1 + 0x58) != lVar1) {
LAB_fffffff009950604:
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00995060c);
            (*pcVar2)();
          }
          *(long **)(lVar4 + 0x58) = *(long **)(lVar1 + 0x58);
          plVar5 = *(long **)(lVar1 + 0x58);
        }
        *plVar5 = lVar4;
        *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + -1;
        (**(code **)(**(long **)(lVar1 + 0x40) + 0x28))();
        *(undefined8 *)(lVar1 + 0x40) = 0;
        thunk_EXT_FUN_80110000038fe270(&DAT_fffffff007ff0368,lVar1);
      }
    }
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x20));
    return;
  }
                    /* WARNING: Does not return */
  pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009950600);
  (*pcVar2)();
}

