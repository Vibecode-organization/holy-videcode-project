// FUN_fffffff0081f23d0 @ fffffff0081f23d0 size=188

undefined8 FUN_fffffff0081f23d0(long param_1)

{
  int *piVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  
  iVar2 = *(int *)(param_1 + 0x4c);
  if (iVar2 != -1) {
    lVar3 = *(long *)(param_1 + 0x10);
    if (iVar2 < *(int *)(lVar3 + 0x11e00)) {
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar3 + 0x11df8));
      if (iVar2 < *(int *)(lVar3 + 0x11e00)) {
        lVar4 = (long)iVar2 * 4;
        piVar1 = (int *)(*(long *)(lVar3 + 0x11e28) + (long)(int)lVar4);
        if (lVar4 - (int)lVar4 != 0) {
          piVar1 = (int *)(*(long *)(lVar3 + 0x11e28) + lVar4 & 0xffffffffffffU | 0x2bad000000000000
                          );
        }
        if (((*piVar1 == 0) || (iVar2 = *piVar1 + -1, *piVar1 = iVar2, iVar2 == 0)) &&
           ((*(byte *)(lVar3 + 0x11e0c) & 1) != 0)) {
          thunk_EXT_FUN_801100000295c97c(*(undefined8 *)(*(long *)(lVar3 + 0x11df0) + 0x160));
        }
      }
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar3 + 0x11df8));
    }
  }
  *(undefined4 *)(param_1 + 0x4c) = 0xffffffff;
  return 1;
}

