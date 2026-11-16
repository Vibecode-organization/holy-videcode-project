// FUN_fffffff00818f098 @ fffffff00818f098 size=196

void FUN_fffffff00818f098(long param_1)

{
  long lVar1;
  ulong uVar2;
  long lVar3;
  
  if (*(long *)(param_1 + 0x610) != 0) {
    FUN_fffffff00818f15c();
    (**(code **)(**(long **)(*(long *)(param_1 + 0x610) + 0xb0) + 0x88))();
    lVar1 = *(long *)(param_1 + 0x610);
    if (*(int *)(lVar1 + 0x98) != 0) {
      uVar2 = 0;
      do {
        lVar3 = *(long *)(*(long *)(lVar1 + 0x28 + uVar2 * 8) + 0x230);
        if (lVar3 != 0) {
          if (*(long *)(lVar3 + 0x1c0) != 0) {
            FUN_fffffff0081fa144(*(long *)(lVar3 + 0x1c0),0,*(undefined8 *)(lVar3 + 0x1d0));
            lVar1 = *(long *)(param_1 + 0x610);
          }
          *(undefined8 *)(lVar3 + 0x148) = 0;
          *(undefined8 *)(lVar3 + 0x140) = 0;
          *(undefined8 *)(lVar3 + 0x158) = 0;
          *(undefined8 *)(lVar3 + 0x150) = 0;
          *(undefined8 *)(lVar3 + 0x188) = 0;
          *(undefined8 *)(lVar3 + 0x180) = 0;
          *(undefined8 *)(lVar3 + 0x198) = 0;
          *(undefined8 *)(lVar3 + 400) = 0;
          *(undefined8 *)(lVar3 + 0x168) = 0;
          *(undefined8 *)(lVar3 + 0x160) = 0;
          *(undefined8 *)(lVar3 + 0x178) = 0;
          *(undefined8 *)(lVar3 + 0x170) = 0;
          *(undefined8 *)(lVar3 + 0x1a8) = 0;
          *(undefined8 *)(lVar3 + 0x1a0) = 0;
          *(undefined8 *)(lVar3 + 0x1b8) = 0;
          *(undefined8 *)(lVar3 + 0x1b0) = 0;
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 < *(uint *)(lVar1 + 0x98));
    }
  }
  return;
}

