// FUN_fffffff0081e1824 @ fffffff0081e1824 size=396

void FUN_fffffff0081e1824(long param_1)

{
  undefined4 uVar1;
  int iVar2;
  code *pcVar3;
  long lVar4;
  long *plVar5;
  long lVar6;
  ulong unaff_x30;
  
  *(undefined8 *)(param_1 + 0x80) = 0;
  *(undefined8 *)(param_1 + 0x78) = 0;
  *(undefined8 *)(param_1 + 0x58) = 0;
  thunk_EXT_FUN_8011000002946f14(param_1 + 0x18);
  if ((*(byte *)(param_1 + 0xb8) & 1) != 0) {
    lVar6 = *(long *)(param_1 + 0x10);
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar6 + 0x48));
    if ((*(byte *)(param_1 + 0xb8) & 1) != 0) {
      lVar4 = *(long *)(lVar6 + 0x18);
      if ((*(byte *)(lVar4 + 0x1ac44) >> 3 & 1) != 0) {
        uVar1 = *(undefined4 *)(param_1 + 0x80);
        iVar2 = *(int *)(param_1 + 0x84);
        thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar4 + 0x1ac48));
        thunk_EXT_FUN_80110000036da494(0x85930cfc,lVar6,param_1,(long)iVar2,uVar1,0);
        thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar4 + 0x1ac48));
      }
      if ((*(byte *)(param_1 + 0xb9) & 1) != 0) {
        *(int *)(lVar6 + 0x70) = *(int *)(lVar6 + 0x70) + -1;
        *(undefined1 *)(param_1 + 0xb9) = 0;
      }
      lVar4 = *(long *)(param_1 + 0xa8);
      if (lVar4 == 0) {
        plVar5 = *(long **)(param_1 + 0xb0);
        if (*plVar5 != param_1) goto LAB_fffffff0081e19a0;
        *(long **)(lVar6 + 0x40) = plVar5;
      }
      else {
        if (*(long **)(lVar4 + 0xb0) != (long *)(param_1 + 0xa8)) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff0081e19b0);
          (*pcVar3)();
        }
        if (**(long **)(param_1 + 0xb0) != param_1) {
LAB_fffffff0081e19a0:
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff0081e19a8);
          (*pcVar3)();
        }
        *(long **)(lVar4 + 0xb0) = *(long **)(param_1 + 0xb0);
        plVar5 = *(long **)(param_1 + 0xb0);
      }
      *plVar5 = lVar4;
      *(int *)(lVar6 + 0x34) = *(int *)(lVar6 + 0x34) + -1;
      *(undefined1 *)(param_1 + 0xb8) = 0;
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar6 + 0x48));
  }
  if (*(long **)(param_1 + 0x10) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x10) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x10) = 0;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081e1994);
    (*pcVar3)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff0081e199c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff007ca6180 + 0x80))(param_1);
  return;
}

