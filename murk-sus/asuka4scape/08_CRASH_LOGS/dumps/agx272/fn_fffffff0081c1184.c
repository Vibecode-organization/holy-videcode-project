// FUN_fffffff0081c1184 @ fffffff0081c1184 size=480

void FUN_fffffff0081c1184(long *param_1)

{
  long lVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  
  (**(code **)(*param_1 + 0x7f8))(param_1,param_1[0x101] + 0x30c);
  lVar1 = param_1[0x50];
  uVar4 = (ulong)*(uint *)(lVar1 + 0x3f8);
  uVar3 = (ulong)*(uint *)(lVar1 + 0x3fc);
  uVar2 = (ulong)*(uint *)(lVar1 + 0x400);
  if (*(uint *)(lVar1 + 0x3f8) != 0) {
    do {
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  uVar4 = (ulong)*(uint *)(lVar1 + 0x109e4);
  if (*(uint *)(lVar1 + 0x109e4) != 0) {
    do {
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  if (*(uint *)(lVar1 + 0x3fc) != 0) {
    do {
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
  uVar4 = (ulong)*(uint *)(lVar1 + 0x109e8);
  if (*(uint *)(lVar1 + 0x109e8) != 0) {
    do {
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  if (*(uint *)(lVar1 + 0x400) != 0) {
    do {
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  uVar4 = (ulong)*(uint *)(lVar1 + 0x109ec);
  if (*(uint *)(lVar1 + 0x109ec) != 0) {
    do {
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  if (*(int *)(lVar1 + 0x189d8) != 0) {
    thunk_EXT_FUN_80110000039b575c
              (*(undefined8 *)(*(long *)(lVar1 + 0x1ac50) + 0xb0),0x444d4b494c4c);
  }
  return;
}

