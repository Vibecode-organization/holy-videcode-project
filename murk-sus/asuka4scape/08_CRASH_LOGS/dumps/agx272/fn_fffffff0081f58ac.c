// FUN_fffffff0081f58ac @ fffffff0081f58ac size=312

void FUN_fffffff0081f58ac(long param_1)

{
  long lVar1;
  code *pcVar2;
  long lVar3;
  long lVar4;
  ulong unaff_x30;
  
  lVar3 = 0;
  lVar4 = 0x10;
  do {
    lVar1 = param_1 + 0x18 + lVar3 * 0x40;
    if ((*(byte *)(lVar1 + 0x39) & 1) != 0) {
      if (*(long **)(lVar1 + 8) != (long *)0x0) {
        (**(code **)(**(long **)(lVar1 + 8) + 0x28))();
        *(undefined8 *)(lVar1 + 8) = 0;
      }
      if (*(long **)(lVar1 + 0x10) != (long *)0x0) {
        (**(code **)(**(long **)(lVar1 + 0x10) + 0x28))();
        if (*(long **)(lVar1 + 0x10) != (long *)0x0) {
          (**(code **)(**(long **)(lVar1 + 0x10) + 0x28))();
        }
        *(undefined8 *)(lVar1 + 0x10) = 0;
      }
      if (*(long **)(lVar1 + 0x18) != (long *)0x0) {
        (**(code **)(**(long **)(lVar1 + 0x18) + 0x28))();
        *(undefined8 *)(lVar1 + 0x18) = 0;
      }
      *(undefined1 *)(lVar1 + 0x38) = 0;
    }
    lVar3 = lVar3 + 1;
    lVar4 = lVar4 + -1;
  } while (lVar4 != 0);
  if (*(long *)(param_1 + 0x420) != 0) {
    thunk_EXT_FUN_80110000038ff020();
    *(undefined8 *)(param_1 + 0x420) = 0;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081f59d8);
    (*pcVar2)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff0081f59e0. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff007ca6180 + 0x80))(param_1);
  return;
}

