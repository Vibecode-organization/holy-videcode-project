// FUN_fffffff009964fd8 @ fffffff009964fd8 size=648

void FUN_fffffff009964fd8(long param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if (*(long *)(param_1 + 0xe0) != 0) {
    thunk_EXT_FUN_80110000038ff020();
    *(undefined8 *)(param_1 + 0xe0) = 0;
  }
  if (*(long **)(param_1 + 0x110) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x110) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x110) = 0;
  if (*(long **)(param_1 + 0x108) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x108) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x108) = 0;
  if (*(long **)(param_1 + 0x80) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x80) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x80) = 0;
  if (*(long **)(param_1 + 0x18) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x18) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x18) = 0;
  if (*(long **)(param_1 + 0x100) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x100) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x100) = 0;
  if (*(long **)(param_1 + 0x78) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x78) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x78) = 0;
  if (*(long **)(param_1 + 0x88) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x88) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x88) = 0;
  if (*(long **)(param_1 + 0x90) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x90) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x90) = 0;
  if (*(long **)(param_1 + 0x10) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x10) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x10) = 0;
  if (*(long **)(param_1 + 0x30) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x30) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x30) = 0;
  if (*(long *)(param_1 + 0x58) != 0) {
    FUN_fffffff009944a04
              (*(undefined8 *)(*(long *)(param_1 + 0x48) + 0x1d0),
               *(undefined4 *)(*(long *)(param_1 + 0x58) + 0x20));
    FUN_fffffff0099710dc(*(undefined8 *)(param_1 + 0x58),0);
    (**(code **)(**(long **)(param_1 + 0x58) + 0x28))();
    *(undefined8 *)(param_1 + 0x58) = 0;
  }
  if (*(long *)(param_1 + 0x28) != 0) {
    thunk_EXT_FUN_80110000038ff020();
    *(undefined8 *)(param_1 + 0x28) = 0;
  }
  if (*(long *)(param_1 + 0x20) != 0) {
    thunk_EXT_FUN_80110000038ff020();
    *(undefined8 *)(param_1 + 0x20) = 0;
  }
  if (*(long **)(param_1 + 0x68) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x68) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x68) = 0;
  if (*(long *)(param_1 + 0x50) != 0) {
    thunk_EXT_FUN_801100000326c730();
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009965254);
    (*pcVar1)();
  }
  (*DAT_fffffff007feb268)(param_1);
  return;
}

