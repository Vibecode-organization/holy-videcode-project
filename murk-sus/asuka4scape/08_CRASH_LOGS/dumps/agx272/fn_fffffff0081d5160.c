// FUN_fffffff0081d5160 @ fffffff0081d5160 size=440

void FUN_fffffff0081d5160(undefined8 param_1,long param_2,long param_3)

{
  ulong uVar1;
  undefined8 uVar2;
  ulong uVar3;
  long lVar4;
  undefined8 uVar5;
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  
  uVar1 = 0x2000;
  if (*(int *)(param_3 + 0x49c) != 0x20) {
    uVar1 = 0x1000;
  }
  uVar3 = 0x8000;
  if (*(int *)(param_3 + 0x4a0) != 0x20) {
    uVar3 = 0x4000;
  }
  uVar3 = uVar3 | uVar1;
  if (*(int *)(param_3 + 0x870) == 4) {
    uVar3 = uVar3 | 2;
  }
  else if (*(int *)(param_3 + 0x870) == 2) {
    uVar3 = uVar3 | 1;
  }
  *(ulong *)(param_2 + 0x18) = uVar3;
  *(int *)(param_2 + 0x360) = (int)*(undefined8 *)(param_3 + 0x758);
  *(int *)(param_2 + 0x364) = (int)*(undefined8 *)(param_3 + 0x760);
  uVar5 = *(undefined8 *)(param_3 + 0x600);
  *(undefined8 *)(param_2 + 0x28) = *(undefined8 *)(param_3 + 0x608);
  *(undefined8 *)(param_2 + 0x20) = uVar5;
  uVar5 = *(undefined8 *)(param_3 + 0x880);
  *(undefined8 *)(param_2 + 0x370) = *(undefined8 *)(param_3 + 0x888);
  *(undefined8 *)(param_2 + 0x368) = uVar5;
  *(undefined8 *)(param_2 + 0x378) = *(undefined8 *)(param_3 + 0x890);
  *(undefined8 *)(param_2 + 0x30) = *(undefined8 *)(param_3 + 0x860);
  *(undefined4 *)(param_2 + 0x380) = *(undefined4 *)(param_3 + 0x878);
  auVar7 = *(undefined1 (*) [16])(param_3 + 0x4a8);
  auVar6[8] = auVar7[8] & 0xfc;
  auVar6._0_8_ = auVar7._0_8_ & 0xfffffffffffffffc;
  auVar6[9] = auVar7[9];
  auVar6[10] = auVar7[10];
  auVar6[0xb] = auVar7[0xb];
  auVar6[0xc] = auVar7[0xc];
  auVar6[0xd] = auVar7[0xd];
  auVar6[0xe] = auVar7[0xe];
  auVar6[0xf] = auVar7[0xf];
  auVar7 = NEON_ext(auVar6,auVar6,8,1);
  *(long *)(param_2 + 0x40) = auVar7._8_8_;
  *(long *)(param_2 + 0x38) = auVar7._0_8_;
  *(undefined4 *)(param_2 + 900) = *(undefined4 *)(param_3 + 0x874);
  lVar4 = *(long *)(param_3 + 0x800);
  *(long *)(param_2 + 0x120) = lVar4;
  uVar5 = *(undefined8 *)(param_3 + 0x740);
  *(undefined8 *)(param_2 + 0x50) = *(undefined8 *)(param_3 + 0x748);
  *(undefined8 *)(param_2 + 0x48) = uVar5;
  *(int *)(param_2 + 0x388) = (int)*(undefined8 *)(param_3 + 0x738);
  uVar5 = *(undefined8 *)(param_3 + 0x658);
  *(undefined8 *)(param_2 + 0x38c) = *(undefined8 *)(param_3 + 0x7a0);
  *(undefined8 *)(param_2 + 0x58) = uVar5;
  *(undefined8 *)(param_2 + 0x60) = 0;
  uVar5 = *(undefined8 *)(param_3 + 0x640);
  *(undefined8 *)(param_2 + 0x70) = *(undefined8 *)(param_3 + 0x648);
  *(undefined8 *)(param_2 + 0x68) = uVar5;
  *(undefined8 *)(param_2 + 0x78) = *(undefined8 *)(param_3 + 0x650);
  uVar5 = *(undefined8 *)(param_3 + 0x660);
  *(undefined8 *)(param_2 + 0x88) = *(undefined8 *)(param_3 + 0x668);
  *(undefined8 *)(param_2 + 0x80) = uVar5;
  uVar5 = *(undefined8 *)(param_3 + 0x678);
  *(undefined8 *)(param_2 + 0x98) = *(undefined8 *)(param_3 + 0x680);
  *(undefined8 *)(param_2 + 0x90) = uVar5;
  uVar5 = *(undefined8 *)(param_3 + 0x690);
  *(undefined8 *)(param_2 + 0xa8) = *(undefined8 *)(param_3 + 0x698);
  *(undefined8 *)(param_2 + 0xa0) = uVar5;
  uVar5 = *(undefined8 *)(param_3 + 0x6a8);
  *(undefined8 *)(param_2 + 0xb8) = *(undefined8 *)(param_3 + 0x6b0);
  *(undefined8 *)(param_2 + 0xb0) = uVar5;
  uVar5 = *(undefined8 *)(param_3 + 0x6c0);
  *(undefined8 *)(param_2 + 200) = *(undefined8 *)(param_3 + 0x6c8);
  *(undefined8 *)(param_2 + 0xc0) = uVar5;
  uVar5 = *(undefined8 *)(param_3 + 0x6d0);
  *(undefined8 *)(param_2 + 0xd8) = *(undefined8 *)(param_3 + 0x6d8);
  *(undefined8 *)(param_2 + 0xd0) = uVar5;
  uVar5 = *(undefined8 *)(param_3 + 0x6f8);
  *(undefined8 *)(param_2 + 0xe0) = *(undefined8 *)(param_3 + 0x6e0);
  *(undefined8 *)(param_2 + 0xe8) = uVar5;
  *(undefined8 *)(param_2 + 0xf0) = *(undefined8 *)(param_3 + 0x6e8);
  uVar5 = *(undefined8 *)(param_3 + 0x700);
  *(undefined8 *)(param_2 + 0x100) = *(undefined8 *)(param_3 + 0x708);
  *(undefined8 *)(param_2 + 0xf8) = uVar5;
  uVar5 = *(undefined8 *)(param_3 + 0x710);
  *(undefined8 *)(param_2 + 0x108) = *(undefined8 *)(param_3 + 0x720);
  *(undefined8 *)(param_2 + 0x110) = uVar5;
  *(undefined8 *)(param_2 + 0x118) = *(undefined8 *)(param_3 + 0x728);
  uVar5 = 0x10082;
  if (lVar4 == 0) {
    uVar5 = 0x10083;
  }
  lVar4 = *(long *)(param_3 + 0x7d8);
  uVar1 = 0;
  if (*(ulong *)(param_3 + 2000) != 0) {
    uVar1 = *(ulong *)(param_3 + 2000) | (ulong)(lVar4 != 0);
  }
  *(ulong *)(param_2 + 0x148) = uVar1;
  *(long *)(param_2 + 0x150) = lVar4;
  *(int *)(param_2 + 0x39c) = *(int *)(param_3 + 0x7cc) << 0x10;
  *(undefined8 *)(param_2 + 0x394) = 0;
  uVar2 = 0x8ee0;
  if ((*(byte *)(param_3 + 0x8f2) & 1) == 0) {
    uVar2 = 0x8c60;
  }
  *(undefined8 *)(param_2 + 0x138) = 0x1100000000;
  *(undefined8 *)(param_2 + 0x140) = uVar2;
  uVar2 = *(undefined8 *)(param_3 + 0x730);
  *(undefined8 *)(param_2 + 0x128) = uVar5;
  *(undefined8 *)(param_2 + 0x130) = uVar2;
  return;
}

