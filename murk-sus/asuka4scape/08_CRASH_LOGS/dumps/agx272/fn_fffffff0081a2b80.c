// FUN_fffffff0081a2b80 @ fffffff0081a2b80 size=208

undefined8 FUN_fffffff0081a2b80(long param_1,ulong *param_2)

{
  ulong uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  
  uVar1 = param_2[2];
  if (((uVar1 < *param_2) || (0xfffffffffffffb77 < uVar1)) || (param_2[1] < uVar1 + 0x488)) {
    *(undefined8 *)(param_1 + 0x18) = 0;
  }
  else {
    param_2[2] = uVar1 + 0x488;
    *(ulong *)(param_1 + 0x18) = uVar1;
    if (uVar1 != 0) {
      uVar3 = *(undefined8 *)(uVar1 + 0x210);
      uVar2 = *(undefined8 *)(uVar1 + 0x208);
      uVar5 = *(undefined8 *)(uVar1 + 0x220);
      uVar4 = *(undefined8 *)(uVar1 + 0x218);
      uVar6 = *(undefined8 *)(uVar1 + 0x228);
      uVar8 = *(undefined8 *)(uVar1 + 0x240);
      uVar7 = *(undefined8 *)(uVar1 + 0x238);
      *(undefined8 *)(param_1 + 0x48) = *(undefined8 *)(uVar1 + 0x230);
      *(undefined8 *)(param_1 + 0x40) = uVar6;
      *(undefined8 *)(param_1 + 0x58) = uVar8;
      *(undefined8 *)(param_1 + 0x50) = uVar7;
      *(undefined8 *)(param_1 + 0x28) = uVar3;
      *(undefined8 *)(param_1 + 0x20) = uVar2;
      *(undefined8 *)(param_1 + 0x38) = uVar5;
      *(undefined8 *)(param_1 + 0x30) = uVar4;
      uVar3 = *(undefined8 *)(uVar1 + 0x250);
      uVar2 = *(undefined8 *)(uVar1 + 0x248);
      uVar5 = *(undefined8 *)(uVar1 + 0x260);
      uVar4 = *(undefined8 *)(uVar1 + 600);
      uVar7 = *(undefined8 *)(uVar1 + 0x270);
      uVar6 = *(undefined8 *)(uVar1 + 0x268);
      *(undefined8 *)(param_1 + 0x90) = *(undefined8 *)(uVar1 + 0x278);
      *(undefined8 *)(param_1 + 0x78) = uVar5;
      *(undefined8 *)(param_1 + 0x70) = uVar4;
      *(undefined8 *)(param_1 + 0x88) = uVar7;
      *(undefined8 *)(param_1 + 0x80) = uVar6;
      *(undefined8 *)(param_1 + 0x68) = uVar3;
      *(undefined8 *)(param_1 + 0x60) = uVar2;
      uVar2 = *(undefined8 *)(uVar1 + 0x388);
      *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(uVar1 + 0x390);
      *(undefined8 *)(param_1 + 0x98) = uVar2;
      uVar3 = *(undefined8 *)(uVar1 + 0x438);
      uVar2 = *(undefined8 *)(uVar1 + 0x430);
      uVar4 = *(undefined8 *)(uVar1 + 0x420);
      *(undefined8 *)(param_1 + 0xb0) = *(undefined8 *)(uVar1 + 0x428);
      *(undefined8 *)(param_1 + 0xa8) = uVar4;
      *(undefined8 *)(param_1 + 0xc0) = uVar3;
      *(undefined8 *)(param_1 + 0xb8) = uVar2;
      uVar3 = *(undefined8 *)(uVar1 + 0x448);
      uVar2 = *(undefined8 *)(uVar1 + 0x440);
      uVar5 = *(undefined8 *)(uVar1 + 0x458);
      uVar4 = *(undefined8 *)(uVar1 + 0x450);
      uVar7 = *(undefined8 *)(uVar1 + 0x468);
      uVar6 = *(undefined8 *)(uVar1 + 0x460);
      uVar8 = *(undefined8 *)(uVar1 + 0x470);
      *(undefined8 *)(param_1 + 0x100) = *(undefined8 *)(uVar1 + 0x478);
      *(undefined8 *)(param_1 + 0xf8) = uVar8;
      *(undefined8 *)(param_1 + 0xf0) = uVar7;
      *(undefined8 *)(param_1 + 0xe8) = uVar6;
      *(undefined8 *)(param_1 + 0xe0) = uVar5;
      *(undefined8 *)(param_1 + 0xd8) = uVar4;
      *(undefined8 *)(param_1 + 0xd0) = uVar3;
      *(undefined8 *)(param_1 + 200) = uVar2;
      *(byte *)(param_1 + 0x108) = *(byte *)(uVar1 + 0x376) & 1;
      *(undefined1 *)(param_1 + 8) = 1;
      return 1;
    }
  }
  *(undefined4 *)(param_1 + 0xc) = 0x100;
  return 0;
}

