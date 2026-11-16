// FUN_fffffff009c19a5c @ fffffff009c19a5c size=228

void FUN_fffffff009c19a5c(long param_1,undefined8 param_2)

{
  code *pcVar1;
  int iVar2;
  ulong uVar3;
  long *plVar4;
  ulong unaff_x30;
  
  iVar2 = FUN_fffffff009c37a94(DAT_fffffff00af483b0);
  if ((iVar2 == 0) || (uVar3 = FUN_fffffff009c19b40(param_1,param_1,param_2,0), (uVar3 & 1) != 0)) {
    return;
  }
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x20));
  plVar4 = *(long **)(param_1 + 0x18);
  if (plVar4 == (long *)0x0) {
    plVar4 = (long *)thunk_EXT_FUN_80110000038ccc44(1);
    if (*(long **)(param_1 + 0x18) != (long *)0x0) {
      (**(code **)(**(long **)(param_1 + 0x18) + 0x28))();
    }
    *(long **)(param_1 + 0x18) = plVar4;
  }
  (**(code **)(*plVar4 + 0xf0))(plVar4,param_2);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c19b3c);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x20));
  return;
}

