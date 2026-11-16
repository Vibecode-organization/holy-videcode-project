// FUN_fffffff0082135f4 @ fffffff0082135f4 size=412

void FUN_fffffff0082135f4(long param_1)

{
  int iVar1;
  code *pcVar2;
  long lVar3;
  long *plVar4;
  long *plVar5;
  long lVar6;
  ulong unaff_x30;
  
  if (*(long **)(param_1 + 0x218) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x218) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x218) = 0;
  if (*(long **)(param_1 + 0x220) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x220) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x220) = 0;
  plVar5 = *(long **)(param_1 + 0x228);
  if (plVar5 != (long *)0x0) {
    lVar6 = *(long *)(param_1 + 0xc0);
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar6 + 800));
    iVar1 = (int)plVar5[0x41] + -1;
    *(int *)(plVar5 + 0x41) = iVar1;
    if (iVar1 == 0) {
      lVar3 = plVar5[0x3f];
      if (lVar3 == 0) {
        plVar4 = (long *)plVar5[0x40];
        if ((long *)*plVar4 != plVar5) goto LAB_fffffff008213780;
        *(long **)(lVar6 + 0x330) = plVar4;
      }
      else {
        if (*(long **)(lVar3 + 0x200) != plVar5 + 0x3f) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff008213790);
          (*pcVar2)();
        }
        if (*(long **)plVar5[0x40] != plVar5) {
LAB_fffffff008213780:
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff008213788);
          (*pcVar2)();
        }
        *(long **)(lVar3 + 0x200) = (long *)plVar5[0x40];
        plVar4 = (long *)plVar5[0x40];
      }
      *plVar4 = lVar3;
      (**(code **)(*plVar5 + 0x28))(plVar5);
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar6 + 800));
    if (*(long **)(param_1 + 0x228) != (long *)0x0) {
      (**(code **)(**(long **)(param_1 + 0x228) + 0x28))();
    }
  }
  *(undefined8 *)(param_1 + 0x228) = 0;
  if (*(long **)(param_1 + 0x230) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x230) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x230) = 0;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff008213774);
    (*pcVar2)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff00821377c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff007ca6108 + 0x80))(param_1);
  return;
}

