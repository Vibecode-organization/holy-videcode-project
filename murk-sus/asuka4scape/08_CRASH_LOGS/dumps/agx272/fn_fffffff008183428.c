// FUN_fffffff008183428 @ fffffff008183428 size=276

/* WARNING: Removing unreachable block (ram,0xfffffff0081834b0) */

void FUN_fffffff008183428(long param_1)

{
  undefined4 *puVar1;
  long *plVar2;
  undefined8 uVar3;
  long lVar4;
  
  thunk_EXT_FUN_8011000003a61cc0(*(undefined8 *)(param_1 + 0x60),0x2cc0);
  *(undefined8 *)(*(long *)(param_1 + 0x60) + 8) = *(undefined8 *)(param_1 + 0xa8);
  **(undefined8 **)(param_1 + 0x60) = *(undefined8 *)(param_1 + 0xa0);
  *(undefined8 *)(*(long *)(param_1 + 0x60) + 0x10) = *(undefined8 *)(param_1 + 0xb0);
  lVar4 = *(long *)(param_1 + 0x60);
  *(undefined4 *)(lVar4 + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined8 *)(lVar4 + 0x84) = *(undefined8 *)(param_1 + 0x50);
  plVar2 = *(long **)(*(long *)(param_1 + 0x10) + 0x4b0);
  lVar4 = *plVar2;
  uVar3 = (**(code **)(lVar4 + 0x208))(lVar4 + 0x208,plVar2,*(undefined8 *)(param_1 + 0x90),0);
  *(undefined8 *)(*(long *)(param_1 + 0x60) + 0x18) = uVar3;
  lVar4 = *(long *)(param_1 + 0x60);
  *(undefined4 *)(lVar4 + 0x48) = 0xffffffff;
  *(undefined4 *)(lVar4 + 0x50) = 0xffffffff;
  *(undefined4 *)(lVar4 + 0x30) = 4;
  *(undefined8 *)(lVar4 + 0x7c) = *(undefined8 *)(param_1 + 0x110);
  lVar4 = *(long *)(param_1 + 0x60);
  puVar1 = *(undefined4 **)(param_1 + 0x68);
  *(undefined4 *)(lVar4 + 100) = 0;
  puVar1[0x14] = *(undefined4 *)(param_1 + 0x5c);
  *puVar1 = 0;
  puVar1[0x10] = 0;
  puVar1[8] = 0;
  puVar1[0xc] = 0;
  puVar1[4] = 0;
  *(undefined4 *)(param_1 + 0x78) = 0;
  *(undefined4 *)(lVar4 + 0x20) = 0;
  *(undefined4 *)(lVar4 + 0x28) = 0;
  *(undefined4 *)(lVar4 + 0x24) = 0;
  *(undefined4 *)(lVar4 + 0x2c) = 0xffffffff;
  *(undefined8 *)(param_1 + 0xf0) = 0;
  return;
}

