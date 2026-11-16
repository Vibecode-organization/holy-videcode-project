// FUN_fffffff0099769f4 @ fffffff0099769f4 size=348

void FUN_fffffff0099769f4(long param_1)

{
  code *pcVar1;
  long *plVar2;
  ulong unaff_x30;
  
  plVar2 = *(long **)(param_1 + 0x538);
  if (plVar2 != (long *)0x0) {
    if (-1 < *(int *)(param_1 + 0x424)) {
      FUN_fffffff00996311c(plVar2,param_1);
      *(undefined4 *)(param_1 + 0x424) = 0xffffffff;
      plVar2 = *(long **)(param_1 + 0x538);
    }
    (**(code **)(*plVar2 + 0x28))();
    *(undefined8 *)(param_1 + 0x538) = 0;
  }
  if (*(long **)(param_1 + 0x480) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x480) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x480) = 0;
  if (*(long **)(param_1 + 0x428) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x428) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x428) = 0;
  if (*(long *)(param_1 + 0x528) != 0) {
    thunk_EXT_FUN_80110000038ff020();
    *(undefined8 *)(param_1 + 0x528) = 0;
  }
  if (*(long *)(param_1 + 0x458) != 0) {
    thunk_EXT_FUN_80110000038ff020();
    *(undefined8 *)(param_1 + 0x458) = 0;
  }
  plVar2 = *(long **)(param_1 + 0x430);
  if (plVar2 != (long *)0x0) {
    if (plVar2[0x53] != 0) {
      thunk_EXT_FUN_80110000038ff020();
      plVar2 = *(long **)(param_1 + 0x430);
      plVar2[0x53] = 0;
    }
    if ((long *)*plVar2 != (long *)0x0) {
      (**(code **)(*(long *)*plVar2 + 0x28))();
      plVar2 = *(long **)(param_1 + 0x430);
    }
    *plVar2 = 0;
  }
  *(undefined8 *)(param_1 + 0x430) = 0;
  thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ff1b88,plVar2,0x2a8);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009976b44);
    (*pcVar1)();
  }
  (*DAT_fffffff007feb268)(param_1);
  return;
}

