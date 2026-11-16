// FUN_fffffff009947330 @ fffffff009947330 size=276

/* WARNING: Removing unreachable block (ram,0xfffffff0099473fc) */
/* WARNING: Removing unreachable block (ram,0xfffffff009947398) */

undefined8 FUN_fffffff009947330(long param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  ushort uVar2;
  long *plVar3;
  undefined8 uVar4;
  long lVar5;
  undefined8 uVar6;
  uint *puVar7;
  
  puVar7 = *(uint **)(param_3 + 0x58);
  plVar3 = *(long **)(param_1 + 0xf8);
  uVar1 = *(uint *)(plVar3 + 0x3f);
  *puVar7 = *(uint *)(plVar3 + 0x3e) >> 9 & 0x1000 | *(uint *)(plVar3 + 0x3e) & 0xffff;
  puVar7[1] = uVar1;
  *(long *)(puVar7 + 4) = plVar3[0x41];
  uVar4 = (**(code **)(*plVar3 + 0x540))(*plVar3 + 0x540);
  *(undefined8 *)(puVar7 + 2) = uVar4;
  lVar5 = *(long *)(param_1 + 0xf8);
  puVar7[6] = *(uint *)(lVar5 + 0x100);
  uVar4 = FUN_fffffff0099749b8(lVar5,0);
  *(undefined8 *)(puVar7 + 8) = uVar4;
  plVar3 = *(long **)(param_1 + 0xf8);
  uVar4 = FUN_fffffff0099676a8(*(undefined8 *)(param_1 + 0x120));
  lVar5 = *plVar3;
  uVar4 = (**(code **)(lVar5 + 0x680))(lVar5 + 0x680,plVar3,uVar4);
  lVar5 = *(long *)(param_1 + 0xf8);
  uVar6 = *(undefined8 *)(lVar5 + 600);
  *(undefined8 *)(puVar7 + 10) = uVar4;
  *(undefined8 *)(puVar7 + 0xc) = uVar6;
  uVar2 = *(ushort *)(lVar5 + 0x262);
  puVar7[0xe] = (uint)*(ushort *)(lVar5 + 0x260);
  puVar7[0xf] = (uint)uVar2;
  return 0;
}

