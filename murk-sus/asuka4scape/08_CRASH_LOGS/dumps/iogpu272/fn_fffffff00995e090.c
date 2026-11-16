// FUN_fffffff00995e090 @ fffffff00995e090 size=276

undefined8 FUN_fffffff00995e090(long param_1,long param_2)

{
  uint *puVar1;
  long *plVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  long lVar6;
  undefined8 uVar7;
  
  (**(code **)(PTR_DAT_fffffff007ff27f8 + 0x78))();
  *(undefined8 *)(param_1 + 0x10) = *(undefined8 *)(param_2 + 0xc0);
  puVar1 = (uint *)(param_2 + 0x48);
  *(uint *)(param_1 + 0x18) = *puVar1;
  *(uint *)(param_1 + 0x1c) = *(uint *)(param_2 + 0x4c);
  uVar3 = *(undefined4 *)(param_2 + 0x70);
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_2 + 0x50);
  *(undefined4 *)(param_1 + 0x24) = uVar3;
  *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_2 + 0x68);
  *(byte *)(param_1 + 0xb0) = *(byte *)(param_2 + 0x65) & 1;
  uVar7 = *(undefined8 *)(*(long *)(param_1 + 0x10) + 0x148);
  FUN_fffffff00994af14(param_1 + 0x30);
  FUN_fffffff00994af14(param_1 + 0x70);
  if (*puVar1 != *(uint *)(param_2 + 0x4c)) {
    uVar4 = *(uint *)(param_2 + 0x54);
    uVar5 = 0;
    if (uVar4 != 0) {
      uVar5 = *puVar1 / uVar4;
    }
    lVar6 = (ulong)(*puVar1 - uVar5 * uVar4) * 8;
    plVar2 = (long *)(*(long *)(param_2 + 0x58) + (long)(int)lVar6);
    if (lVar6 != (int)lVar6) {
      plVar2 = (long *)(*(long *)(param_2 + 0x58) + lVar6 & 0xffffffffffffU | 0x2bad000000000000);
    }
    lVar6 = *plVar2;
    if (lVar6 != 0) {
      FUN_fffffff00994c49c(uVar7,lVar6 + 0xc0,param_1 + 0x30);
      FUN_fffffff00994c49c(uVar7,lVar6 + 0x80,param_1 + 0x70);
    }
  }
  return 1;
}

