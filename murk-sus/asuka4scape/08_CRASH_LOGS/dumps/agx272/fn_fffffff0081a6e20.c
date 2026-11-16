// FUN_fffffff0081a6e20 @ fffffff0081a6e20 size=572

/* WARNING: Removing unreachable block (ram,0xfffffff0081a6eec) */

undefined8 FUN_fffffff0081a6e20(long *param_1,uint *param_2,undefined8 param_3,uint *param_4)

{
  long *plVar1;
  undefined8 *puVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  ulong uVar6;
  undefined8 uVar7;
  code *pcVar8;
  long lVar9;
  long *plVar10;
  long lVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  undefined8 local_58;
  
  plVar1 = param_1 + 0x109;
  plVar10 = *(long **)(param_1[0x50] + 0x310);
  iVar4 = (**(code **)(param_1[0x109] + 0x38))(plVar1);
  pcVar8 = *(code **)(param_1[0x109] + 0x30);
  while (uVar5 = (*pcVar8)(plVar1), uVar5 == (iVar4 + 1U & 0xff)) {
    local_58 = 0;
    thunk_EXT_FUN_8011000003204ed8(10,1000000,&local_58);
    lVar9 = *plVar10;
    (**(code **)(lVar9 + 0x110))(lVar9 + 0x110,plVar10,plVar1,local_58,0);
    iVar4 = (**(code **)(*plVar1 + 0x38))(plVar1);
    pcVar8 = *(code **)(*plVar1 + 0x30);
  }
  lVar11 = param_1[0x10c];
  uVar6 = (**(code **)(param_1[0x109] + 0x38))(plVar1);
  lVar9 = (uVar6 & 0xffffffff) * 0x40;
  puVar2 = (undefined8 *)(lVar11 + (int)lVar9);
  if (lVar9 != (int)lVar9) {
    puVar2 = (undefined8 *)(lVar11 + lVar9 & 0xffffffffffffU | 0x2bad000000000000);
  }
  uVar12 = *(undefined8 *)(param_2 + 2);
  uVar7 = *(undefined8 *)param_2;
  uVar14 = *(undefined8 *)(param_2 + 6);
  uVar13 = *(undefined8 *)(param_2 + 4);
  uVar15 = *(undefined8 *)(param_2 + 8);
  uVar17 = *(undefined8 *)(param_2 + 0xe);
  uVar16 = *(undefined8 *)(param_2 + 0xc);
  puVar2[5] = *(undefined8 *)(param_2 + 10);
  puVar2[4] = uVar15;
  puVar2[7] = uVar17;
  puVar2[6] = uVar16;
  puVar2[1] = uVar12;
  *puVar2 = uVar7;
  puVar2[3] = uVar14;
  puVar2[2] = uVar13;
  uVar5 = (uint)((ulong)((long)puVar2 - param_1[0x10c]) >> 6);
  if (0xff < uVar5) {
    uVar7 = thunk_EXT_FUN_8011000003a49114
                      ("AGXk: %s:%d:%s: !!! Attempt to get index (%x) for entry out-of-bounds\n");
    return uVar7;
  }
  *param_4 = uVar5;
  if (((&DAT_fffffff007114030)[*param_2] & 1) != 0) {
    (**(code **)(*param_1 + 0x9f0))(param_1);
  }
  DataMemoryBarrier(2,3);
  cVar3 = (**(code **)(*plVar1 + 0x38))(plVar1);
  (**(code **)(*plVar1 + 0x10))(plVar1,cVar3 + '\x01');
  return 0;
}

