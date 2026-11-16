// FUN_fffffff0081b87f8 @ fffffff0081b87f8 size=260

void FUN_fffffff0081b87f8(long param_1,undefined1 param_2)

{
  long lVar1;
  byte bVar2;
  code *pcVar3;
  undefined8 uVar4;
  ulong uVar5;
  long lVar6;
  ulong unaff_x30;
  
  lVar6 = *(long *)(param_1 + 0x280);
  *(undefined1 *)(lVar6 + 0x5a0) = param_2;
  *(int *)(lVar6 + 0x5a4) = *(int *)(lVar6 + 0x5a4) + 1;
  bVar2 = *(byte *)(lVar6 + 0x5a0);
  uVar4 = thunk_EXT_FUN_8011000003397c88();
  lVar1 = 0x5a8;
  if ((bVar2 & 1) == 0) {
    lVar1 = 0x5b0;
  }
  *(undefined8 *)(lVar6 + lVar1) = uVar4;
  if ((*(byte *)(lVar6 + 0x5a0) & 1) == 0) {
    if ((((*(byte *)(lVar6 + 0x5b8) & 1) == 0) && ((*(byte *)(lVar6 + 0x5a0) & 1) == 0)) &&
       (uVar5 = thunk_EXT_FUN_801100000294780c(*(undefined8 *)(lVar6 + 0x148)), (uVar5 & 1) == 0)) {
      (**(code **)(**(long **)(lVar6 + 0x4b0) + 0x3b8))();
      *(undefined1 *)(lVar6 + 0x5b8) = 1;
      thunk_EXT_FUN_8011000003204ed8(*(undefined4 *)(lVar6 + 0x23c),1000000000,lVar6 + 0x5c0);
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081b88f8);
        (*pcVar3)();
      }
      thunk_EXT_FUN_801100000295f33c(*(undefined8 *)(lVar6 + 0x160),*(undefined8 *)(lVar6 + 0x5c0));
      return;
    }
  }
  else if ((*(byte *)(lVar6 + 0x5b8) & 1) != 0) {
    *(undefined1 *)(lVar6 + 0x5b8) = 0;
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081b886c);
      (*pcVar3)();
    }
    thunk_EXT_FUN_801100000295f3b0(*(undefined8 *)(lVar6 + 0x160));
    return;
  }
  return;
}

