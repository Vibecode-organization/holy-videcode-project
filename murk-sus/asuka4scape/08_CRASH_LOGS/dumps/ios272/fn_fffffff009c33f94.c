// FUN_fffffff009c33f94 @ fffffff009c33f94 size=160

void FUN_fffffff009c33f94(long param_1,undefined8 param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  long *plVar3;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x140));
  plVar3 = *(long **)(param_1 + 0x158);
  if (plVar3 != (long *)0x0) {
    uVar2 = FUN_fffffff009c30a78(param_2);
    (**(code **)(*plVar3 + 0xf8))(plVar3,uVar2,param_2);
  }
  *(int *)(param_1 + 0x16c) = *(int *)(param_1 + 0x16c) + 1;
  thunk_EXT_FUN_80110000038ff08c(*(undefined8 *)(param_1 + 0x140),param_1 + 0x16c,0);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c34030);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x140));
  return;
}

