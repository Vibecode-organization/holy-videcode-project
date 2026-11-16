// FUN_fffffff0081d5318 @ fffffff0081d5318 size=636

void FUN_fffffff0081d5318(undefined8 param_1,long param_2,long param_3)

{
  ulong uVar1;
  ulong uVar2;
  uint uVar3;
  byte bVar4;
  ulong uVar5;
  undefined8 uVar6;
  long lVar7;
  undefined8 uVar8;
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  
  uVar1 = 0x2000;
  if (*(int *)(param_3 + 0x49c) != 0x20) {
    uVar1 = 0x1000;
  }
  uVar5 = 0x8000;
  if (*(int *)(param_3 + 0x4a0) != 0x20) {
    uVar5 = 0x4000;
  }
  uVar5 = uVar5 | uVar1;
  if (*(int *)(param_3 + 0x870) == 4) {
    uVar5 = uVar5 | 2;
  }
  else if (*(int *)(param_3 + 0x870) == 2) {
    uVar5 = uVar5 | 1;
  }
  *(ulong *)(param_2 + 0x80) = uVar5;
  *(int *)(param_2 + 0x3c8) = (int)*(undefined8 *)(param_3 + 0x758);
  *(int *)(param_2 + 0x3cc) = (int)*(undefined8 *)(param_3 + 0x760);
  uVar6 = *(undefined8 *)(param_3 + 0x600);
  *(undefined8 *)(param_2 + 0x90) = *(undefined8 *)(param_3 + 0x608);
  *(undefined8 *)(param_2 + 0x88) = uVar6;
  uVar6 = *(undefined8 *)(param_3 + 0x880);
  *(undefined8 *)(param_2 + 0x3d8) = *(undefined8 *)(param_3 + 0x888);
  *(undefined8 *)(param_2 + 0x3d0) = uVar6;
  *(undefined8 *)(param_2 + 0x3e0) = *(undefined8 *)(param_3 + 0x890);
  *(ulong *)(param_2 + 0x1d0) = (ulong)(*(long *)(param_3 + 0x4c0) != 0);
  auVar11 = *(undefined1 (*) [16])(param_3 + 0x4c0);
  auVar9._0_9_ = (unkuint9)auVar11._1_7_ << 8;
  auVar9[9] = auVar11[9];
  auVar9[10] = auVar11[10];
  auVar9[0xb] = auVar11[0xb];
  auVar9[0xc] = auVar11[0xc];
  auVar9[0xd] = auVar11[0xd];
  auVar9[0xe] = auVar11[0xe];
  auVar9[0xf] = auVar11[0xf];
  *(long *)(param_2 + 0x1e0) = auVar9._8_8_;
  *(ulong *)(param_2 + 0x1d8) = (ulong)auVar11._1_7_ << 8;
  *(ulong *)(param_2 + 0x1e8) = *(ulong *)(param_3 + 0x4d0) & 0xffffffffffffff00;
  *(undefined8 *)(param_2 + 0x98) = *(undefined8 *)(param_3 + 0x860);
  *(undefined4 *)(param_2 + 1000) = *(undefined4 *)(param_3 + 0x878);
  *(undefined4 *)(param_2 + 0x3f0) = *(undefined4 *)(param_3 + 0x87c);
  *(ulong *)(param_2 + 0x1a8) = *(ulong *)(param_3 + 0x858) & 0xffffffffffffffc0;
  auVar11 = *(undefined1 (*) [16])(param_3 + 0x4a8);
  auVar10[8] = auVar11[8] & 0xfc;
  auVar10._0_8_ = auVar11._0_8_ & 0xfffffffffffffffc;
  auVar10[9] = auVar11[9];
  auVar10[10] = auVar11[10];
  auVar10[0xb] = auVar11[0xb];
  auVar10[0xc] = auVar11[0xc];
  auVar10[0xd] = auVar11[0xd];
  auVar10[0xe] = auVar11[0xe];
  auVar10[0xf] = auVar11[0xf];
  auVar11 = NEON_ext(auVar10,auVar10,8,1);
  *(long *)(param_2 + 0xa8) = auVar11._8_8_;
  *(long *)(param_2 + 0xa0) = auVar11._0_8_;
  uVar6 = *(undefined8 *)(param_3 + 0x740);
  *(undefined8 *)(param_2 + 0xb8) = *(undefined8 *)(param_3 + 0x748);
  *(undefined8 *)(param_2 + 0xb0) = uVar6;
  uVar6 = *(undefined8 *)(param_3 + 0x750);
  *(int *)(param_2 + 0x3f4) = (int)*(undefined8 *)(param_3 + 0x738);
  uVar8 = *(undefined8 *)(param_3 + 0x658);
  *(undefined8 *)(param_2 + 0xc0) = uVar6;
  *(undefined8 *)(param_2 + 200) = uVar8;
  *(undefined8 *)(param_2 + 0x3f8) = *(undefined8 *)(param_3 + 0x7a0);
  *(ulong *)(param_2 + 0xd0) = *(ulong *)(param_3 + 0x4b8) & 0xfffffffffffffff0;
  uVar6 = *(undefined8 *)(param_3 + 0x640);
  *(undefined8 *)(param_2 + 0xe0) = *(undefined8 *)(param_3 + 0x648);
  *(undefined8 *)(param_2 + 0xd8) = uVar6;
  *(undefined8 *)(param_2 + 0xe8) = *(undefined8 *)(param_3 + 0x650);
  uVar6 = *(undefined8 *)(param_3 + 0x660);
  *(undefined8 *)(param_2 + 0xf8) = *(undefined8 *)(param_3 + 0x668);
  *(undefined8 *)(param_2 + 0xf0) = uVar6;
  uVar6 = *(undefined8 *)(param_3 + 0x678);
  *(undefined8 *)(param_2 + 0x108) = *(undefined8 *)(param_3 + 0x680);
  *(undefined8 *)(param_2 + 0x100) = uVar6;
  uVar6 = *(undefined8 *)(param_3 + 0x690);
  *(undefined8 *)(param_2 + 0x118) = *(undefined8 *)(param_3 + 0x698);
  *(undefined8 *)(param_2 + 0x110) = uVar6;
  uVar6 = *(undefined8 *)(param_3 + 0x6a8);
  *(undefined8 *)(param_2 + 0x128) = *(undefined8 *)(param_3 + 0x6b0);
  *(undefined8 *)(param_2 + 0x120) = uVar6;
  uVar6 = *(undefined8 *)(param_3 + 0x6c0);
  *(undefined8 *)(param_2 + 0x138) = *(undefined8 *)(param_3 + 0x6c8);
  *(undefined8 *)(param_2 + 0x130) = uVar6;
  uVar6 = *(undefined8 *)(param_3 + 0x6d0);
  *(undefined8 *)(param_2 + 0x148) = *(undefined8 *)(param_3 + 0x6d8);
  *(undefined8 *)(param_2 + 0x140) = uVar6;
  uVar6 = *(undefined8 *)(param_3 + 0x6f8);
  *(undefined8 *)(param_2 + 0x150) = *(undefined8 *)(param_3 + 0x6e0);
  *(undefined8 *)(param_2 + 0x158) = uVar6;
  *(undefined8 *)(param_2 + 0x160) = *(undefined8 *)(param_3 + 0x6e8);
  uVar6 = *(undefined8 *)(param_3 + 0x700);
  *(undefined8 *)(param_2 + 0x170) = *(undefined8 *)(param_3 + 0x708);
  *(undefined8 *)(param_2 + 0x168) = uVar6;
  uVar6 = *(undefined8 *)(param_3 + 0x710);
  *(undefined8 *)(param_2 + 0x178) = *(undefined8 *)(param_3 + 0x720);
  *(undefined8 *)(param_2 + 0x180) = uVar6;
  *(undefined8 *)(param_2 + 0x188) = *(undefined8 *)(param_3 + 0x728);
  uVar6 = *(undefined8 *)(param_3 + 0x848);
  *(undefined8 *)(param_2 + 0x198) = *(undefined8 *)(param_3 + 0x850);
  *(undefined8 *)(param_2 + 400) = uVar6;
  *(ulong *)(param_2 + 0x1a0) = (ulong)*(uint *)(param_3 + 0x89c) << 0x1a;
  uVar3 = *(uint *)(param_3 + 0x898);
  bVar4 = *(byte *)(param_3 + 0x835);
  uVar1 = 0x100;
  if (*(char *)(param_3 + 0x8f0) != '\x03') {
    uVar1 = 0x200;
  }
  uVar5 = 0;
  if (*(char *)(param_3 + 0x8f0) != '\x02') {
    uVar5 = uVar1;
  }
  uVar1 = 0x40;
  if (*(char *)(param_3 + 0x8f1) != '\x03') {
    uVar1 = 0x80;
  }
  uVar2 = 0;
  if (*(char *)(param_3 + 0x8f1) != '\x02') {
    uVar2 = uVar1;
  }
  *(undefined4 *)(param_2 + 0x3ec) = 0;
  lVar7 = *(long *)(param_3 + 0x7d8);
  uVar1 = 0;
  if (*(ulong *)(param_3 + 2000) != 0) {
    uVar1 = *(ulong *)(param_3 + 2000) | (ulong)(lVar7 != 0);
  }
  *(ulong *)(param_2 + 0x200) = uVar1;
  *(long *)(param_2 + 0x208) = lVar7;
  *(uint *)(param_2 + 0x408) =
       (*(byte *)(param_3 + 0x7e0) & 1) << 0x18 | *(int *)(param_3 + 0x7cc) << 0x10;
  *(undefined8 *)(param_2 + 0x1c0) = 0;
  *(undefined8 *)(param_2 + 0x1c8) = 0;
  *(undefined8 *)(param_2 + 0x400) = DAT_fffffff007113ec0;
  *(undefined4 *)(param_2 + 0x40c) = *(undefined4 *)(param_3 + 0x8a8);
  uVar6 = 0x8ee0;
  if ((*(byte *)(param_3 + 0x8f2) & 1) == 0) {
    uVar6 = 0x8c60;
  }
  *(undefined8 *)(param_2 + 0x1f0) = 0x1100000000;
  *(undefined8 *)(param_2 + 0x1f8) = uVar6;
  uVar6 = *(undefined8 *)(param_3 + 0x730);
  *(ulong *)(param_2 + 0x1b0) = (ulong)(1 < uVar3) | ((ulong)bVar4 & 1) << 0x10 | uVar5 | uVar2;
  *(undefined8 *)(param_2 + 0x1b8) = uVar6;
  *(ulong *)(param_2 + 0x210) = (ulong)*(uint *)(param_3 + 0xa28) & 0x1f;
  return;
}

