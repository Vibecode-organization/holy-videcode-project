// FUN_fffffff0081e68ac @ fffffff0081e68ac size=172

void FUN_fffffff0081e68ac(long param_1,long param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  code *pcVar4;
  long lVar5;
  undefined4 *puVar6;
  ulong unaff_x30;
  
  if ((*(int *)(param_1 + 0x48) != 2) && (*(int *)(param_2 + 0x170) == 1)) {
    *(undefined4 *)(param_1 + 0x48) = 1;
    lVar5 = *(long *)(param_1 + 0x28);
    if ((*(byte *)(lVar5 + 0x1ac44) >> 3 & 1) != 0) {
      puVar6 = *(undefined4 **)(param_1 + 0x1370);
      uVar1 = *puVar6;
      uVar2 = puVar6[1];
      uVar3 = puVar6[2];
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar5 + 0x1ac48));
      thunk_EXT_FUN_80110000036da494(0x85930cf4,0,uVar1,uVar2,uVar3,0);
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081e6954);
        (*pcVar4)();
      }
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar5 + 0x1ac48));
      return;
    }
  }
  return;
}

