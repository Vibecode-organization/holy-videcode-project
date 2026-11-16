// FUN_fffffff00820bacc @ fffffff00820bacc size=1040

void FUN_fffffff00820bacc(long param_1,long param_2)

{
  uint uVar1;
  undefined4 uVar2;
  long lVar3;
  long *plVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  
  lVar3 = (**(code **)(**(long **)(*(long *)(param_2 + 0x130) + 0x20) + 0xa0))();
  *(long *)(param_1 + 0xf58) = *(long *)(param_2 + 0x2a8) + lVar3;
  *(undefined4 *)(param_1 + 0xf60) = *(undefined4 *)(param_2 + 0x18);
  lVar3 = 0;
  if (*(long *)(param_2 + 0x1d8) != 0) {
    lVar3 = (**(code **)(**(long **)(*(long *)(param_2 + 0x1c0) + 0x20) + 0xa0))();
    lVar3 = *(long *)(param_2 + 0x218) + lVar3;
  }
  *(long *)(param_1 + 0xf48) = lVar3;
  plVar4 = *(long **)(param_2 + 0x1c0);
  *(long **)(param_1 + 0xc98) = plVar4;
  (**(code **)(*plVar4 + 0x20))();
  *(undefined8 *)(param_1 + 0xca0) = *(undefined8 *)(param_2 + 0x218);
  *(undefined8 *)(param_1 + 0xf68) = *(undefined8 *)(param_2 + 0x1d8);
  *(undefined4 *)(param_1 + 0xf50) = *(undefined4 *)(param_2 + 0x28);
  lVar3 = (**(code **)(**(long **)(*(long *)(param_2 + 0x130) + 0x20) + 0xa0))();
  *(long *)(param_1 + 0xf70) = *(long *)(param_2 + 0x2b0) + lVar3;
  *(undefined4 *)(param_1 + 0xf78) = *(undefined4 *)(param_2 + 0x98);
  lVar3 = (**(code **)(**(long **)(*(long *)(param_2 + 0x130) + 0x20) + 0xa0))();
  *(long *)(param_1 + 0xf80) = *(long *)(param_2 + 0x2b8) + lVar3;
  uVar5 = *(undefined8 *)(param_2 + 0xf0);
  uVar7 = *(undefined8 *)(param_2 + 0x108);
  uVar6 = *(undefined8 *)(param_2 + 0x100);
  *(undefined8 *)(param_1 + 0xff0) = *(undefined8 *)(param_2 + 0xf8);
  *(undefined8 *)(param_1 + 0xfe8) = uVar5;
  *(undefined8 *)(param_1 + 0x1000) = uVar7;
  *(undefined8 *)(param_1 + 0xff8) = uVar6;
  *(undefined4 *)(param_1 + 0x1008) = *(undefined4 *)(param_2 + 0x110);
  uVar5 = *(undefined8 *)(param_2 + 0xd8);
  *(undefined8 *)(param_1 + 0xfd8) = *(undefined8 *)(param_2 + 0xe0);
  *(undefined8 *)(param_1 + 0xfd0) = uVar5;
  *(undefined8 *)(param_1 + 0xfe0) = *(undefined8 *)(param_2 + 0xe8);
  if (1 < *(uint *)(param_2 + 0x3c)) {
    lVar3 = 0;
    if (*(long *)(param_2 + 0x1e0) != 0) {
      lVar3 = (**(code **)(**(long **)(*(long *)(param_2 + 0x1c0) + 0x20) + 0xa0))();
      lVar3 = *(long *)(param_2 + 0x220) + lVar3;
    }
    *(long *)(param_1 + 0xf88) = lVar3;
    lVar3 = 0;
    if (*(long *)(param_2 + 0x1e8) != 0) {
      lVar3 = (**(code **)(**(long **)(*(long *)(param_2 + 0x1c0) + 0x20) + 0xa0))();
      lVar3 = *(long *)(param_2 + 0x228) + lVar3;
    }
    *(long *)(param_1 + 0xf90) = lVar3;
    lVar3 = 0;
    if (*(long *)(param_2 + 0x1f0) != 0) {
      lVar3 = (**(code **)(**(long **)(*(long *)(param_2 + 0x1c0) + 0x20) + 0xa0))();
      lVar3 = *(long *)(param_2 + 0x230) + lVar3;
    }
    *(long *)(param_1 + 0xf98) = lVar3;
    *(undefined4 *)(param_1 + 4000) = *(undefined4 *)(param_2 + 0x2c);
    lVar3 = 0;
    if (*(long *)(param_2 + 0x1f8) != 0) {
      lVar3 = (**(code **)(**(long **)(*(long *)(param_2 + 0x1c0) + 0x20) + 0xa0))();
      lVar3 = *(long *)(param_2 + 0x238) + lVar3;
    }
    *(long *)(param_1 + 0xfa8) = lVar3;
    lVar3 = 0;
    if (*(long *)(param_2 + 0x200) != 0) {
      lVar3 = (**(code **)(**(long **)(*(long *)(param_2 + 0x1c0) + 0x20) + 0xa0))();
      lVar3 = *(long *)(param_2 + 0x240) + lVar3;
    }
    *(long *)(param_1 + 0xfb0) = lVar3;
    lVar3 = 0;
    if (*(long *)(param_2 + 0x208) != 0) {
      lVar3 = (**(code **)(**(long **)(*(long *)(param_2 + 0x1c0) + 0x20) + 0xa0))();
      lVar3 = *(long *)(param_2 + 0x248) + lVar3;
    }
    *(long *)(param_1 + 0xfb8) = lVar3;
    uVar1 = *(uint *)(param_2 + 0x3c);
    *(undefined4 *)(param_1 + 0xfc0) = *(undefined4 *)(param_2 + 0x38);
    if (1 < uVar1) {
      lVar3 = 0;
      if (*(long *)(param_2 + 0x210) != 0) {
        lVar3 = (**(code **)(**(long **)(*(long *)(param_2 + 0x1c0) + 0x20) + 0xa0))();
        lVar3 = *(long *)(param_2 + 0x250) + lVar3;
      }
      *(long *)(param_1 + 0xfc8) = lVar3;
    }
  }
  lVar3 = (**(code **)(**(long **)(*(long *)(param_2 + 0x130) + 0x20) + 0x98))();
  *(long *)(param_1 + 0x848) = *(long *)(param_2 + 0x2a8) + lVar3;
  lVar3 = (**(code **)(**(long **)(*(long *)(param_2 + 0x130) + 0x20) + 0x98))();
  *(long *)(param_1 + 0x850) = *(long *)(param_2 + 0x2b0) + lVar3;
  lVar3 = (**(code **)(**(long **)(*(long *)(param_2 + 0x130) + 0x20) + 0x98))();
  *(long *)(param_1 + 0x858) = *(long *)(param_2 + 0x2b8) + lVar3;
  *(undefined8 *)(param_1 + 0x868) = *(undefined8 *)(param_2 + 0x20);
  uVar2 = *(undefined4 *)(param_2 + 0xbc);
  *(undefined4 *)(param_1 + 0x870) = *(undefined4 *)(param_2 + 0xb8);
  *(undefined8 *)(param_1 + 0x860) = *(undefined8 *)(param_2 + 0xb0);
  *(undefined4 *)(param_1 + 0x878) = uVar2;
  *(undefined4 *)(param_1 + 0x87c) = *(undefined4 *)(param_2 + 0x114);
  *(undefined4 *)(param_1 + 0x880) = *(undefined4 *)(param_2 + 0xc0);
  *(undefined4 *)(param_1 + 0x884) = *(undefined4 *)(param_2 + 0xc4);
  *(undefined4 *)(param_1 + 0x888) = *(undefined4 *)(param_2 + 200);
  *(undefined4 *)(param_1 + 0x88c) = *(undefined4 *)(param_2 + 0xcc);
  *(undefined4 *)(param_1 + 0x890) = *(undefined4 *)(param_2 + 0xd0);
  *(undefined4 *)(param_1 + 0x894) = *(undefined4 *)(param_2 + 0xd4);
  *(undefined4 *)(param_1 + 0x898) = *(undefined4 *)(param_2 + 0x98);
  *(undefined4 *)(param_1 + 0x89c) = *(undefined4 *)(param_2 + 0x18);
  *(undefined4 *)(param_1 + 0x8a0) = *(undefined4 *)(param_2 + 0x118);
  return;
}

