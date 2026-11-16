// FUN_fffffff00819d4f0 @ fffffff00819d4f0 size=140

undefined8 FUN_fffffff00819d4f0(long param_1,undefined8 *param_2)

{
  byte bVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  
  lVar2 = *(long *)(param_1 + 0xf8);
  *param_2 = *(undefined8 *)(lVar2 + 0x3b0);
  param_2[1] = *(undefined8 *)(lVar2 + 0x3b8);
  param_2[2] = *(undefined8 *)(lVar2 + 0x3c0);
  param_2[3] = *(undefined8 *)(lVar2 + 0x3c8);
  uVar3 = *(undefined8 *)(lVar2 + 0x43e);
  uVar5 = *(undefined8 *)(lVar2 + 0x438);
  uVar4 = *(undefined8 *)(lVar2 + 0x430);
  uVar7 = *(undefined8 *)(lVar2 + 0x428);
  uVar6 = *(undefined8 *)(lVar2 + 0x420);
  uVar8 = *(undefined8 *)(lVar2 + 0x410);
  param_2[0xd] = *(undefined8 *)(lVar2 + 0x418);
  param_2[0xc] = uVar8;
  param_2[0xf] = uVar7;
  param_2[0xe] = uVar6;
  param_2[0x11] = uVar5;
  param_2[0x10] = uVar4;
  *(undefined8 *)((long)param_2 + 0x8e) = uVar3;
  uVar6 = *(undefined8 *)(lVar2 + 0x3f8);
  uVar5 = *(undefined8 *)(lVar2 + 0x3f0);
  uVar4 = *(undefined8 *)(lVar2 + 0x408);
  uVar3 = *(undefined8 *)(lVar2 + 0x400);
  uVar9 = *(undefined8 *)(lVar2 + 0x3d0);
  uVar8 = *(undefined8 *)(lVar2 + 1000);
  uVar7 = *(undefined8 *)(lVar2 + 0x3e0);
  param_2[5] = *(undefined8 *)(lVar2 + 0x3d8);
  param_2[4] = uVar9;
  param_2[7] = uVar8;
  param_2[6] = uVar7;
  param_2[9] = uVar6;
  param_2[8] = uVar5;
  param_2[0xb] = uVar4;
  param_2[10] = uVar3;
  *(uint *)(param_2 + 0x13) = DAT_fffffff00ae21818 >> 10;
  *(undefined1 *)((long)param_2 + 0x9c) = 0;
  bVar1 = DAT_fffffff00ae22cf1;
  *(byte *)((long)param_2 + 0x9d) = DAT_fffffff00ae22cf1 >> 1 & 1;
  *(byte *)((long)param_2 + 0x9f) = bVar1 >> 3 & 1;
  return 0;
}

