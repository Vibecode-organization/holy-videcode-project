// FUN_fffffff0099708e4 @ fffffff0099708e4 size=196

undefined8 FUN_fffffff0099708e4(long param_1)

{
  code *pcVar1;
  int iVar2;
  long *plVar3;
  undefined8 uVar4;
  long lVar5;
  long lVar6;
  ulong unaff_x30;
  
  if (*(int *)(param_1 + 0x20) == 0) {
    if (*(long *)(param_1 + 0x1b8) == 0) {
      lVar5 = 0;
      lVar6 = 0x10;
      do {
        plVar3 = *(long **)(param_1 + 0x138 + lVar5 * 8);
        if (plVar3 != (long *)0x0) {
          (**(code **)(*plVar3 + 0x28))();
          *(undefined8 *)(param_1 + 0x138 + lVar5 * 8) = 0;
        }
        lVar5 = lVar5 + 1;
        lVar6 = lVar6 + -1;
      } while (lVar6 != 0);
      if (*(long *)(param_1 + 0x28) != 0) {
        thunk_EXT_FUN_801100000326c730();
      }
      if (*(long *)(param_1 + 0x18) != 0) {
        thunk_EXT_FUN_80110000038ff1d4();
      }
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009970994);
        (*pcVar1)();
      }
      uVar4 = (*DAT_fffffff007feb268)(param_1);
      return uVar4;
    }
  }
  else {
    FUN_fffffff009983fe4();
  }
  lVar5 = FUN_fffffff009984020();
  thunk_EXT_FUN_80110000038ff214(*(undefined8 *)(lVar5 + 0x18));
  if ((*(long *)(lVar5 + 0x30) == 0) || (iVar2 = FUN_fffffff00994d91c(), iVar2 == 0)) {
    uVar4 = 0;
  }
  else {
    uVar4 = *(undefined8 *)(lVar5 + 0x30);
  }
  thunk_EXT_FUN_80110000038ff2e0(*(undefined8 *)(lVar5 + 0x18));
  return uVar4;
}

