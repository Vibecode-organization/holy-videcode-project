// FUN_fffffff00819c940 @ fffffff00819c940 size=160

undefined8 FUN_fffffff00819c940(long param_1,ulong *param_2)

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
  if (((uVar1 < *param_2) || (0xfffffffffffffd8f < uVar1)) || (param_2[1] < uVar1 + 0x270)) {
    *(undefined8 *)(param_1 + 0x18) = 0;
  }
  else {
    param_2[2] = uVar1 + 0x270;
    *(ulong *)(param_1 + 0x18) = uVar1;
    if (uVar1 != 0) {
      uVar3 = *(undefined8 *)(uVar1 + 0xe8);
      uVar2 = *(undefined8 *)(uVar1 + 0xe0);
      uVar5 = *(undefined8 *)(uVar1 + 0xf8);
      uVar4 = *(undefined8 *)(uVar1 + 0xf0);
      uVar6 = *(undefined8 *)(uVar1 + 0x100);
      uVar8 = *(undefined8 *)(uVar1 + 0x118);
      uVar7 = *(undefined8 *)(uVar1 + 0x110);
      *(undefined8 *)(param_1 + 0x48) = *(undefined8 *)(uVar1 + 0x108);
      *(undefined8 *)(param_1 + 0x40) = uVar6;
      *(undefined8 *)(param_1 + 0x58) = uVar8;
      *(undefined8 *)(param_1 + 0x50) = uVar7;
      *(undefined8 *)(param_1 + 0x28) = uVar3;
      *(undefined8 *)(param_1 + 0x20) = uVar2;
      *(undefined8 *)(param_1 + 0x38) = uVar5;
      *(undefined8 *)(param_1 + 0x30) = uVar4;
      uVar3 = *(undefined8 *)(uVar1 + 0x128);
      uVar2 = *(undefined8 *)(uVar1 + 0x120);
      uVar5 = *(undefined8 *)(uVar1 + 0x138);
      uVar4 = *(undefined8 *)(uVar1 + 0x130);
      uVar7 = *(undefined8 *)(uVar1 + 0x148);
      uVar6 = *(undefined8 *)(uVar1 + 0x140);
      *(undefined8 *)(param_1 + 0x90) = *(undefined8 *)(uVar1 + 0x150);
      *(undefined8 *)(param_1 + 0x78) = uVar5;
      *(undefined8 *)(param_1 + 0x70) = uVar4;
      *(undefined8 *)(param_1 + 0x88) = uVar7;
      *(undefined8 *)(param_1 + 0x80) = uVar6;
      *(undefined8 *)(param_1 + 0x68) = uVar3;
      *(undefined8 *)(param_1 + 0x60) = uVar2;
      uVar2 = *(undefined8 *)(uVar1 + 0x25c);
      *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(uVar1 + 0x264);
      *(undefined8 *)(param_1 + 0x98) = uVar2;
      *(byte *)(param_1 + 0xa4) = *(byte *)(uVar1 + 0x1fd) & 1;
      *(undefined1 *)(param_1 + 8) = 1;
      return 1;
    }
  }
  *(undefined4 *)(param_1 + 0xc) = 0x100;
  return 0;
}

