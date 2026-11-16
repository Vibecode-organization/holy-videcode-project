// FUN_fffffff0081db98c @ fffffff0081db98c size=540

void FUN_fffffff0081db98c(long param_1,long param_2,long param_3)

{
  undefined8 uVar1;
  ushort uVar2;
  uint uVar3;
  long lVar4;
  uint uVar5;
  undefined8 uVar6;
  long lVar7;
  ulong uVar8;
  
  uVar6 = 0x100;
  if (*(char *)(param_3 + 0x8f0) != '\x03') {
    uVar6 = 0x200;
  }
  uVar1 = 0;
  if (*(char *)(param_3 + 0x8f0) != '\x02') {
    uVar1 = uVar6;
  }
  *(undefined8 *)(param_2 + 0x38) = uVar1;
  *(undefined8 *)(param_2 + 0x40) = 0x1e3ce5081e3ce508;
  uVar6 = *(undefined8 *)(param_3 + 0xf48);
  *(undefined8 *)(param_2 + 0x48) = *(undefined8 *)(param_3 + 0xf58);
  *(undefined8 *)(param_2 + 0x50) = uVar6;
  lVar4 = *(long *)(param_1 + 0x10);
  *(ulong *)(param_2 + 0x58) =
       (*(long *)(lVar4 + 0x5c8) << 0x2b ^ 0xffffffffffffffffU) & 0x8000000000000000 |
       *(ulong *)(param_3 + 0xf80) & 0xffffffffffffffc0;
  uVar2 = *(ushort *)(param_3 + 0xee8);
  *(undefined8 *)(param_2 + 0x60) = *(undefined8 *)(param_3 + 0xee0);
  *(ulong *)(param_2 + 0x68) = (ulong)uVar2;
  uVar6 = *(undefined8 *)(param_3 + 0xfe8);
  *(undefined8 *)(param_2 + 0x78) = *(undefined8 *)(param_3 + 0xff0);
  *(undefined8 *)(param_2 + 0x70) = uVar6;
  uVar6 = *(undefined8 *)(param_3 + 0xea0);
  *(undefined8 *)(param_2 + 0x90) = *(undefined8 *)(param_3 + 0xea8);
  *(undefined8 *)(param_2 + 0x88) = uVar6;
  uVar5 = *(uint *)(param_3 + 0xe68);
  uVar8 = *(ulong *)(param_3 + 0xe60);
  *(undefined8 *)(param_2 + 0x98) = 1;
  *(ulong *)(param_2 + 0xa0) = uVar8 & 0xffffffffffffffe0 | (ulong)uVar5 << 0x32;
  *(undefined8 *)(param_2 + 0x100) = 0;
  uVar8 = *(ulong *)(param_3 + 0xe00);
  *(undefined8 *)(param_2 + 0x80) = *(undefined8 *)(param_3 + 0xf70);
  *(ulong *)(param_2 + 0xa8) = uVar8 & 0xfffffffffffffffc;
  *(undefined8 *)(param_2 + 0xb0) = 0;
  uVar8 = *(ulong *)(param_3 + 0xe30);
  if (uVar8 != 0) {
    *(ulong *)(param_2 + 0xb0) = *(long *)(param_3 + 0xe58) << 8 | 1;
  }
  *(ulong *)(param_2 + 0xb8) = uVar8 & 0xffffffffffffff00;
  uVar8 = *(ulong *)(param_3 + 0xe38);
  *(ulong *)(param_2 + 200) = *(ulong *)(param_3 + 0xe40) & 0xffffffffffffff00;
  *(ulong *)(param_2 + 0xc0) = uVar8 & 0xffffffffffffff00;
  uVar8 = *(ulong *)(param_3 + 0xe48);
  *(ulong *)(param_2 + 0xd8) = *(ulong *)(param_3 + 0xe50) & 0xffffffffffffff00;
  *(ulong *)(param_2 + 0xd0) = uVar8 & 0xffffffffffffff00;
  lVar7 = *(long *)(param_3 + 0xf18);
  uVar8 = 0;
  if (*(ulong *)(param_3 + 0xf10) != 0) {
    uVar8 = *(ulong *)(param_3 + 0xf10) | (ulong)(lVar7 != 0);
  }
  *(ulong *)(param_2 + 0xf0) = uVar8;
  *(long *)(param_2 + 0xf8) = lVar7;
  *(int *)(param_2 + 1000) = *(int *)(param_3 + 0xf20) << 0x18 | *(int *)(param_3 + 0xf0c) << 0x10;
  uVar6 = 0x8ee0;
  if ((*(byte *)(param_3 + 0x1064) & 1) == 0) {
    uVar6 = 0x8c60;
  }
  *(undefined8 *)(param_2 + 0xe0) = 0x1100000000;
  *(undefined8 *)(param_2 + 0xe8) = uVar6;
  *(undefined4 *)(param_2 + 0x3ec) = *(undefined4 *)(param_3 + 0x1010);
  *(undefined4 *)(param_2 + 0x3bc) = *(undefined4 *)(param_3 + 0xf60);
  *(undefined4 *)(param_2 + 0x3c0) = 0x88;
  if ((*(byte *)(param_3 + 0xf3a) & 1) == 0) {
    uVar5 = 2;
  }
  else {
    uVar5 = 0x600e;
  }
  uVar5 = uVar5 | *(byte *)(param_3 + 0xf40) & 1 | *(uint *)(lVar4 + 0x5c8) >> 7 & 0x200;
  if (((*(byte *)(*(long *)(lVar4 + 0x111b0) + 0x54) & 1) != 0) &&
     ((*(int *)(param_3 + 0x818) != 0 || (*(int *)(param_3 + 0x81c) != -1)))) {
    uVar5 = uVar5 | 0x800;
  }
  *(uint *)(param_2 + 0x3c4) = uVar5;
  uVar6 = *(undefined8 *)(param_3 + 0xff8);
  *(undefined8 *)(param_2 + 0x3d0) = *(undefined8 *)(param_3 + 0x1000);
  *(undefined8 *)(param_2 + 0x3c8) = uVar6;
  *(undefined4 *)(param_2 + 0x3d8) = *(undefined4 *)(param_3 + 0x1008);
  *(undefined4 *)(param_2 + 0x3dc) = *(undefined4 *)(param_3 + 0xf50);
  *(undefined4 *)(param_2 + 0x3e0) = 0x100;
  uVar5 = *(uint *)(param_3 + 0xf78) - 1;
  if (*(uint *)(param_3 + 0xf78) < 2) {
    uVar5 = uVar5 | 0x8000;
  }
  else {
    uVar3 = 0x2000;
    if ((*(byte *)(param_3 + 0xf3e) & 1) == 0) {
      uVar3 = 0x1000;
    }
    uVar5 = uVar5 | uVar3 | 0xc000;
  }
  *(uint *)(param_2 + 0x3e4) = uVar5;
  *(ulong *)(param_2 + 0x108) = (ulong)*(uint *)(param_3 + 0x1190) & 0x1f;
  return;
}

