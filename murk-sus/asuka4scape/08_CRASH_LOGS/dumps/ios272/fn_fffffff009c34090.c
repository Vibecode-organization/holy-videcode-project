// FUN_fffffff009c34090 @ fffffff009c34090 size=148

void FUN_fffffff009c34090(long param_1,undefined8 param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  long *plVar3;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x140));
  plVar3 = *(long **)(param_1 + 0x158);
  if (plVar3 != (long *)0x0) {
    uVar2 = FUN_fffffff009c30a78(param_2);
    (**(code **)(*plVar3 + 0x110))(plVar3,uVar2);
  }
  *(int *)(param_1 + 0x16c) = *(int *)(param_1 + 0x16c) + -1;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c34120);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x140));
  return;
}

