// FUN_fffffff0081ea690 @ fffffff0081ea690 size=416

/* WARNING: Removing unreachable block (ram,0xfffffff0081ea7f4) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081ea724) */

void FUN_fffffff0081ea690(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  undefined4 *puVar4;
  long lVar5;
  long *plVar6;
  
  lVar3 = *(long *)(param_1 + 0x98);
  lVar5 = *(long *)(param_1 + 0x48);
  *(undefined4 *)(lVar5 + 0x30) = *(undefined4 *)(lVar3 + 0x138);
  *(undefined8 *)(lVar5 + 0x34) = 0;
  *(undefined8 *)(lVar5 + 0x3c) = *(undefined8 *)(lVar3 + 0xb0);
  *(undefined8 *)(*(long *)(param_1 + 0x48) + 0x44) =
       *(undefined8 *)(*(long *)(param_1 + 0x98) + 0xb8);
  plVar6 = *(long **)(*(long *)(param_1 + 0x18) + 0x4b0);
  uVar2 = (**(code **)(**(long **)(param_1 + 0x28) + 0x98))();
  lVar3 = *plVar6;
  uVar2 = (**(code **)(lVar3 + 0x208))(lVar3 + 0x208,plVar6,uVar2,0);
  *(undefined8 *)(*(long *)(param_1 + 0x48) + 0x18) = uVar2;
  uVar2 = (**(code **)(**(long **)(*(long *)(param_1 + 0x20) + 0x20) + 0x98))();
  lVar3 = *(long *)(param_1 + 0x48);
  *(undefined8 *)(lVar3 + 0x20) = uVar2;
  *(int *)(lVar3 + 0x28) = (int)*(undefined8 *)(*(long *)(param_1 + 0x20) + 0x78);
  *(undefined4 *)(lVar3 + 0x2c) = 0;
  *(undefined8 *)(lVar3 + 0x54) = 0;
  uVar2 = *(undefined8 *)(*(long *)(param_1 + 0x98) + 0x60);
  *(undefined4 *)(lVar3 + 0x4c) = 0xffffffff;
  *(int *)(lVar3 + 0x50) = (int)uVar2;
  *(undefined8 *)(lVar3 + 0x5c) = *(undefined8 *)(param_1 + 0x60);
  puVar4 = *(undefined4 **)(param_1 + 0x48);
  *puVar4 = 0;
  puVar4[4] = 0;
  *(undefined8 *)(puVar4 + 0x1b) = 0;
  *(undefined8 *)(puVar4 + 0x19) = 0;
  puVar4[0x21] = 0;
  *(undefined8 *)(param_1 + 0x3c) = 0;
  *(undefined8 *)(param_1 + 0x34) = 0;
  plVar6 = *(long **)(param_1 + 0x98);
  iVar1 = *(int *)((long)plVar6 + 0x144);
  puVar4[0x1d] = *(int *)((long)plVar6 + 0x14c) << 2;
  puVar4[0x1e] = iVar1 << 2;
  uVar2 = (**(code **)(*plVar6 + 0x130))(*plVar6 + 0x130);
  lVar3 = *(long *)(param_1 + 0x48);
  puVar4 = *(undefined4 **)(param_1 + 0x50);
  *(undefined8 *)(lVar3 + 0x7c) = uVar2;
  *puVar4 = 0;
  *(undefined4 *)(lVar3 + 0xc) = *(undefined4 *)(*(long *)(param_1 + 0x98) + 0x1c4);
  return;
}

