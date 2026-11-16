// FUN_fffffff0081f70c0 @ fffffff0081f70c0 size=408

undefined8 FUN_fffffff0081f70c0(long param_1,ulong *param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  ulong uVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  
  uVar4 = param_2[2];
  if (((uVar4 < *param_2) || (0xfffffffffffff657 < uVar4)) || (param_2[1] < uVar4 + 0x9a8)) {
    *(undefined8 *)(param_1 + 0x18) = 0;
  }
  else {
    param_2[2] = uVar4 + 0x9a8;
    *(ulong *)(param_1 + 0x18) = uVar4;
    if (uVar4 != 0) {
      uVar7 = *(undefined8 *)(uVar4 + 0xd0);
      uVar6 = *(undefined8 *)(uVar4 + 200);
      uVar9 = *(undefined8 *)(uVar4 + 0xe0);
      uVar8 = *(undefined8 *)(uVar4 + 0xd8);
      uVar10 = *(undefined8 *)(uVar4 + 0xe8);
      uVar12 = *(undefined8 *)(uVar4 + 0x100);
      uVar11 = *(undefined8 *)(uVar4 + 0xf8);
      *(undefined8 *)(param_1 + 0x48) = *(undefined8 *)(uVar4 + 0xf0);
      *(undefined8 *)(param_1 + 0x40) = uVar10;
      *(undefined8 *)(param_1 + 0x58) = uVar12;
      *(undefined8 *)(param_1 + 0x50) = uVar11;
      *(undefined8 *)(param_1 + 0x28) = uVar7;
      *(undefined8 *)(param_1 + 0x20) = uVar6;
      *(undefined8 *)(param_1 + 0x38) = uVar9;
      *(undefined8 *)(param_1 + 0x30) = uVar8;
      uVar7 = *(undefined8 *)(uVar4 + 0x110);
      uVar6 = *(undefined8 *)(uVar4 + 0x108);
      uVar9 = *(undefined8 *)(uVar4 + 0x120);
      uVar8 = *(undefined8 *)(uVar4 + 0x118);
      uVar11 = *(undefined8 *)(uVar4 + 0x130);
      uVar10 = *(undefined8 *)(uVar4 + 0x128);
      *(undefined8 *)(param_1 + 0x90) = *(undefined8 *)(uVar4 + 0x138);
      *(undefined8 *)(param_1 + 0x78) = uVar9;
      *(undefined8 *)(param_1 + 0x70) = uVar8;
      *(undefined8 *)(param_1 + 0x88) = uVar11;
      *(undefined8 *)(param_1 + 0x80) = uVar10;
      *(undefined8 *)(param_1 + 0x68) = uVar7;
      *(undefined8 *)(param_1 + 0x60) = uVar6;
      uVar10 = *(undefined8 *)(uVar4 + 0x510);
      uVar9 = *(undefined8 *)(uVar4 + 0x508);
      uVar8 = *(undefined8 *)(uVar4 + 0x520);
      uVar7 = *(undefined8 *)(uVar4 + 0x518);
      uVar6 = *(undefined8 *)(uVar4 + 0x528);
      uVar11 = *(undefined8 *)(uVar4 + 0x4f8);
      *(undefined8 *)(param_1 + 0xe0) = *(undefined8 *)(uVar4 + 0x500);
      *(undefined8 *)(param_1 + 0xd8) = uVar11;
      *(undefined8 *)(param_1 + 0x108) = uVar6;
      *(undefined8 *)(param_1 + 0x100) = uVar8;
      *(undefined8 *)(param_1 + 0xf8) = uVar7;
      *(undefined8 *)(param_1 + 0xf0) = uVar10;
      *(undefined8 *)(param_1 + 0xe8) = uVar9;
      uVar7 = *(undefined8 *)(uVar4 + 0x4c0);
      uVar6 = *(undefined8 *)(uVar4 + 0x4b8);
      uVar9 = *(undefined8 *)(uVar4 + 0x4d0);
      uVar8 = *(undefined8 *)(uVar4 + 0x4c8);
      uVar11 = *(undefined8 *)(uVar4 + 0x4e0);
      uVar10 = *(undefined8 *)(uVar4 + 0x4d8);
      uVar12 = *(undefined8 *)(uVar4 + 0x4e8);
      *(undefined8 *)(param_1 + 0xd0) = *(undefined8 *)(uVar4 + 0x4f0);
      *(undefined8 *)(param_1 + 200) = uVar12;
      *(undefined8 *)(param_1 + 0xc0) = uVar11;
      *(undefined8 *)(param_1 + 0xb8) = uVar10;
      *(undefined8 *)(param_1 + 0xb0) = uVar9;
      *(undefined8 *)(param_1 + 0xa8) = uVar8;
      *(undefined8 *)(param_1 + 0xa0) = uVar7;
      *(undefined8 *)(param_1 + 0x98) = uVar6;
      uVar6 = *(undefined8 *)(uVar4 + 0x24c);
      *(undefined4 *)(param_1 + 0x118) = *(undefined4 *)(uVar4 + 0x254);
      *(undefined8 *)(param_1 + 0x110) = uVar6;
      uVar6 = *(undefined8 *)(uVar4 + 0x638);
      *(undefined4 *)(param_1 + 0x124) = *(undefined4 *)(uVar4 + 0x640);
      *(undefined8 *)(param_1 + 0x11c) = uVar6;
      bVar1 = *(byte *)(uVar4 + 0x240);
      *(byte *)(param_1 + 0x128) = bVar1 & 1;
      *(byte *)(param_1 + 0x129) = *(byte *)(uVar4 + 0x888) & 1;
      *(undefined4 *)(param_1 + 300) = *(undefined4 *)(uVar4 + 0x234);
      *(byte *)(param_1 + 0x130) = *(byte *)(uVar4 + 0x247) & 1;
      *(undefined1 *)(param_1 + 0x148) = *(undefined1 *)(uVar4 + 0x7f9);
      uVar8 = *(undefined8 *)(uVar4 + 0x820);
      uVar7 = *(undefined8 *)(uVar4 + 0x818);
      uVar6 = *(undefined8 *)(uVar4 + 0x828);
      uVar10 = *(undefined8 *)(uVar4 + 0x840);
      uVar9 = *(undefined8 *)(uVar4 + 0x838);
      *(undefined8 *)(param_1 + 0x168) = *(undefined8 *)(uVar4 + 0x830);
      *(undefined8 *)(param_1 + 0x160) = uVar6;
      *(undefined8 *)(param_1 + 0x178) = uVar10;
      *(undefined8 *)(param_1 + 0x170) = uVar9;
      *(undefined8 *)(param_1 + 0x158) = uVar8;
      *(undefined8 *)(param_1 + 0x150) = uVar7;
      uVar9 = *(undefined8 *)(uVar4 + 0x850);
      uVar8 = *(undefined8 *)(uVar4 + 0x848);
      uVar7 = *(undefined8 *)(uVar4 + 0x860);
      uVar6 = *(undefined8 *)(uVar4 + 0x858);
      uVar10 = *(undefined8 *)(uVar4 + 0x868);
      uVar12 = *(undefined8 *)(uVar4 + 0x880);
      uVar11 = *(undefined8 *)(uVar4 + 0x878);
      *(undefined8 *)(param_1 + 0x1a8) = *(undefined8 *)(uVar4 + 0x870);
      *(undefined8 *)(param_1 + 0x1a0) = uVar10;
      *(undefined8 *)(param_1 + 0x1b8) = uVar12;
      *(undefined8 *)(param_1 + 0x1b0) = uVar11;
      *(undefined8 *)(param_1 + 0x188) = uVar9;
      *(undefined8 *)(param_1 + 0x180) = uVar8;
      *(undefined8 *)(param_1 + 0x198) = uVar7;
      *(undefined8 *)(param_1 + 400) = uVar6;
      bVar2 = *(byte *)(uVar4 + 0x23c);
      *(byte *)(param_1 + 0x1c0) = bVar2 & 1;
      bVar3 = *(byte *)(uVar4 + 0x626);
      *(byte *)(param_1 + 0x1c1) = bVar3 & 1;
      *(byte *)(param_1 + 0x1c2) = *(byte *)(uVar4 + 0x248) & 1;
      *(byte *)(param_1 + 0x1c3) = *(byte *)(uVar4 + 0x630) & 1;
      if ((((*(byte *)(uVar4 + 0x7b8) ^ bVar1) & 1) == 0) &&
         (((bVar2 & 1) == 0 || ((bVar3 & 1) != 0)))) {
        *(undefined1 *)(param_1 + 8) = 1;
        return 1;
      }
      uVar5 = 10;
      goto LAB_fffffff0081f70e0;
    }
  }
  uVar5 = 0x100;
LAB_fffffff0081f70e0:
  *(undefined4 *)(param_1 + 0xc) = uVar5;
  return 0;
}

