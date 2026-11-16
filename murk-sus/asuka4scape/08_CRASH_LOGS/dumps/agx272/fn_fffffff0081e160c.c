// FUN_fffffff0081e160c @ fffffff0081e160c size=196

void FUN_fffffff0081e160c(long param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  ulong uVar3;
  long lVar4;
  undefined8 uVar5;
  ulong unaff_x30;
  
  uVar3 = thunk_EXT_FUN_8011000002c13500(*(undefined8 *)(*(long *)(param_1 + 0xd0) + 0x28));
  if (uVar3 < *(ulong *)(param_1 + 0xd8)) {
    thunk_EXT_FUN_8011000002c12744(*(undefined8 *)(*(long *)(param_1 + 0xd0) + 0x28));
    lVar4 = *(long *)(param_1 + 0x10);
    if ((*(byte *)(lVar4 + 0x1ac44) >> 3 & 1) != 0) {
      uVar2 = thunk_EXT_FUN_8011000002c13530(*(undefined8 *)(*(long *)(param_1 + 0xd0) + 0x28));
      uVar5 = *(undefined8 *)(param_1 + 0xd8);
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar4 + 0x1ac48));
      thunk_EXT_FUN_80110000036da494(0x85930db0,uVar2,uVar3,uVar5,0,0);
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081e16cc);
        (*pcVar1)();
      }
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar4 + 0x1ac48));
      return;
    }
  }
  return;
}

