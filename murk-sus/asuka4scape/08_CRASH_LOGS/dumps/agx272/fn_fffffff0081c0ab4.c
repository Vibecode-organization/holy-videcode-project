// FUN_fffffff0081c0ab4 @ fffffff0081c0ab4 size=200

void FUN_fffffff0081c0ab4(long param_1)

{
  long lVar1;
  undefined4 uVar2;
  
  if (*(long *)(param_1 + 0x348) != 0) {
    lVar1 = *(long *)(param_1 + 0x280);
    uVar2 = 0;
    if ((*(int *)(lVar1 + 0x10f94) != 0) && (uVar2 = 0, *(int *)(lVar1 + 0x10f9c) != 0)) {
      *(int *)(lVar1 + 0x10fa0) = *(int *)(lVar1 + 0x10f9c) << 2;
      if ((*(int *)(lVar1 + 0x10fa4) == 0) || (*(int *)(lVar1 + 0x10fac) == 0)) {
        uVar2 = 1;
      }
      else {
        *(int *)(lVar1 + 0x10fb0) = *(int *)(lVar1 + 0x10fac) << 2;
        if ((*(int *)(lVar1 + 0x10fb4) == 0) || (*(int *)(lVar1 + 0x10fbc) == 0)) {
          uVar2 = 2;
        }
        else {
          *(int *)(lVar1 + 0x10fc0) = *(int *)(lVar1 + 0x10fbc) << 2;
          if ((*(int *)(lVar1 + 0x10fc4) == 0) || (*(int *)(lVar1 + 0x10fcc) == 0)) {
            uVar2 = 3;
          }
          else {
            *(int *)(lVar1 + 0x10fd0) = *(int *)(lVar1 + 0x10fcc) << 2;
            if ((*(int *)(lVar1 + 0x10fd4) == 0) || (*(int *)(lVar1 + 0x10fdc) == 0)) {
              uVar2 = 4;
            }
            else {
              *(int *)(lVar1 + 0x10fe0) = *(int *)(lVar1 + 0x10fdc) << 2;
              uVar2 = 5;
            }
          }
        }
      }
    }
    *(undefined4 *)(lVar1 + 0x10f84) = uVar2;
    lVar1 = *(long *)(param_1 + 0x918);
    *(undefined4 *)(lVar1 + 0xc) = uVar2;
    *(undefined4 *)(lVar1 + 8) = 1;
  }
  return;
}

