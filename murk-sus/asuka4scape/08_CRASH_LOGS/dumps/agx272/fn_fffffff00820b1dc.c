// FUN_fffffff00820b1dc @ fffffff00820b1dc size=1696

/* WARNING: Removing unreachable block (ram,0xfffffff00820b774) */
/* WARNING: Removing unreachable block (ram,0xfffffff00820b554) */
/* WARNING: Removing unreachable block (ram,0xfffffff00820b4bc) */
/* WARNING: Removing unreachable block (ram,0xfffffff00820b378) */
/* WARNING: Removing unreachable block (ram,0xfffffff00820b508) */
/* WARNING: Removing unreachable block (ram,0xfffffff00820b594) */
/* WARNING: Removing unreachable block (ram,0xfffffff00820b7b8) */
/* WARNING: Removing unreachable block (ram,0xfffffff00820b3f0) */

void FUN_fffffff00820b1dc(long *param_1,long *param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  char cVar5;
  byte bVar6;
  undefined4 uVar7;
  long lVar8;
  ulong uVar9;
  undefined8 uVar10;
  ulong uVar11;
  ulong uVar12;
  long lVar13;
  undefined4 *puVar14;
  long lVar15;
  long local_60;
  long lStack_58;
  undefined8 local_50;
  undefined4 local_48;
  uint uStack_44;
  
  *(undefined8 *)(*(long *)(param_1[2] + 0x4b0) + 0xbf0) = 0;
  FUN_fffffff008183924
            (param_1,(long)param_2 + 0xad4,*(undefined4 *)((long)param_2 + 0x1054),param_2[0x191],
             *(undefined4 *)((long)param_2 + 0xacc),param_2 + 0x196);
  lVar13 = param_1[2];
  lVar8 = (**(code **)(**(long **)(*(long *)(lVar13 + 0x183a8) + 0x50) + 0x98))();
  uVar1 = *(uint *)(lVar13 + 0x4a0);
  lVar15 = param_1[2];
  lVar13 = (**(code **)(**(long **)(*(long *)(lVar15 + 0x183b0) + 0x50) + 0x98))();
  uVar2 = *(uint *)(lVar15 + 0x4a4);
  uVar9 = (**(code **)(**(long **)(param_1[2] + 0x148) + 0x88))
                    (*(long **)(param_1[2] + 0x148),(int)param_2[0x15a]);
  local_60 = lVar8 + (ulong)uVar1 + (uVar9 & 0xffffffff);
  uVar9 = (**(code **)(**(long **)(param_1[2] + 0x148) + 0x88))
                    (*(long **)(param_1[2] + 0x148),(int)param_2[0x15a]);
  lStack_58 = lVar13 + (ulong)uVar2 + (uVar9 & 0xffffffff);
  local_50 = *(undefined8 *)((long)param_2 + 0xacc);
  uVar7 = (undefined4)local_50;
  local_48 = (undefined4)param_1[7];
  uStack_44 = (uint)((int)param_2[9] != 0);
  cVar5 = *(char *)((long)param_2 + 0x1044);
  if (cVar5 == '\x01') {
LAB_fffffff00820b334:
    puVar14 = (undefined4 *)param_2[0x1b9];
    uVar3 = *(undefined4 *)((long)param_2 + 0x1054);
    *puVar14 = 6;
    puVar14[1] = uVar3;
    puVar14[2] = (int)param_2[0x202];
    lVar8 = **(long **)(param_1[2] + 0x4b0);
    uVar10 = (**(code **)(lVar8 + 0x208))
                       (lVar8 + 0x208,*(long **)(param_1[2] + 0x4b0),param_2[0x203],0);
    *(undefined8 *)(puVar14 + 5) = uVar10;
    *(undefined8 *)(puVar14 + 3) = *(undefined8 *)((long)param_2 + 0x103c);
    puVar14[7] = uVar7;
    lVar8 = param_2[0x1ba];
  }
  else {
    if (cVar5 != '\x02') {
      if (cVar5 != '\x03') goto LAB_fffffff00820b440;
      goto LAB_fffffff00820b334;
    }
    puVar14 = (undefined4 *)param_2[0x1bb];
    uVar3 = *(undefined4 *)((long)param_2 + 0x1054);
    *puVar14 = 5;
    puVar14[1] = uVar3;
    puVar14[2] = (int)param_2[0x202];
    lVar8 = **(long **)(param_1[2] + 0x4b0);
    uVar10 = (**(code **)(lVar8 + 0x208))
                       (lVar8 + 0x208,*(long **)(param_1[2] + 0x4b0),param_2[0x203],0);
    *(undefined8 *)(puVar14 + 3) = uVar10;
    puVar14[5] = uVar7;
    lVar8 = param_2[0x1bc];
  }
  (**(code **)(*param_1 + 200))(param_1,lVar8,puVar14,0);
LAB_fffffff00820b440:
  puVar14 = (undefined4 *)param_2[0x1bd];
  *puVar14 = 0;
  lVar8 = thunk_EXT_FUN_8011000003890f30(param_2[0xc],&DAT_fffffff00ae21f50);
  lVar13 = *(long *)(lVar8 + 0x620);
  *(long *)(lVar8 + 0x620) = lVar13 + 1;
  *(long *)(puVar14 + 1) = lVar13;
  puVar14[3] = *(undefined4 *)((long)param_2 + 0x1054);
  *(long *)(puVar14 + 0x181) = param_2[0x20b];
  puVar14[0x16b] = (int)param_2[0x20a];
  lVar8 = param_2[0x207];
  puVar14[6] = (int)param_2[0x202];
  puVar14[7] = (int)lVar8;
  lVar8 = **(long **)(param_1[2] + 0x4b0);
  uVar10 = (**(code **)(lVar8 + 0x208))
                     (lVar8 + 0x208,*(long **)(param_1[2] + 0x4b0),param_2[0x203],0);
  *(undefined8 *)(puVar14 + 8) = uVar10;
  lVar8 = **(long **)(param_1[2] + 0x4b0);
  uVar10 = (**(code **)(lVar8 + 0x208))
                     (lVar8 + 0x208,*(long **)(param_1[2] + 0x4b0),param_2[0x204],0);
  *(undefined8 *)(puVar14 + 10) = uVar10;
  lVar8 = **(long **)(param_1[2] + 0x4b0);
  uVar10 = (**(code **)(lVar8 + 0x208))
                     (lVar8 + 0x208,*(long **)(param_1[2] + 0x4b0),param_2[0x206],0);
  *(undefined8 *)(puVar14 + 0xc) = uVar10;
  (**(code **)(*param_1 + 0x168))(*param_1 + 0x168,param_1,puVar14 + 0x16d,param_2,&local_60);
  puVar14[0x16c] = (uint)((char)param_2[0x11e] == '\x02');
  (**(code **)(*param_2 + 0xe0))(param_2,1);
  *(long *)(puVar14 + 4) = param_2[0x40];
  lVar8 = param_2[0x1ed];
  *(long *)(puVar14 + 0x117) = param_2[0x1e9];
  *(long *)(puVar14 + 0x119) = lVar8;
  *(long *)(puVar14 + 0x11e) = param_2[0x23c];
  *(long *)(puVar14 + 0x121) = param_2[0x1c2];
  *(long *)(puVar14 + 0x123) = param_2[0x1c3];
  *(long *)(puVar14 + 0x129) = param_2[0x1d4];
  lVar8 = param_2[0x1c4];
  *(long *)(puVar14 + 0x127) = param_2[0x1c5];
  *(long *)(puVar14 + 0x125) = lVar8;
  *(undefined8 *)(puVar14 + 0x145) = 0;
  *(undefined8 *)(puVar14 + 0x143) = 0;
  *(undefined8 *)(puVar14 + 0x149) = 0;
  *(undefined8 *)(puVar14 + 0x147) = 0;
  *(undefined8 *)(puVar14 + 0x12d) = 0;
  *(undefined8 *)(puVar14 + 299) = 0;
  *(undefined8 *)(puVar14 + 0x12f) = 0;
  puVar14[0x120] = 0;
  puVar14[0x14e] = *(byte *)(param_2 + 0x102) & 1;
  puVar14[0x14f] = *(undefined4 *)((long)param_2 + 0x814);
  puVar14[0x150] = (int)param_2[0x103];
  puVar14[0x151] = *(undefined4 *)((long)param_2 + 0x81c);
  *(undefined8 *)(puVar14 + 0x154) = 0;
  *(undefined8 *)(puVar14 + 0x152) = 0;
  lVar8 = param_2[0x233];
  *(long *)(puVar14 + 0x17b) = param_2[0x234];
  *(long *)(puVar14 + 0x179) = lVar8;
  *(undefined8 *)(puVar14 + 0x183) = 0;
  *(undefined8 *)(puVar14 + 0x189) = 0;
  *(long *)(puVar14 + 0x17d) = param_2[0x235];
  *(long *)(puVar14 + 0x17f) = param_2[0x236];
  lVar8 = param_1[2];
  if ((*(byte *)(lVar8 + 0x5cd) >> 6 & 1) != 0) {
    *(long *)(puVar14 + 0x156) = param_2[0x11c];
    *(long *)(puVar14 + 0x158) = param_2[0x11d];
  }
  *(long *)(puVar14 + 0x175) = param_2[0x104];
  lVar13 = param_2[0x105];
  if ((lVar13 != 0) && ((*(byte *)((long)param_2 + 0xf42) & 1) == 0)) {
    lVar13 = 0;
  }
  *(long *)(puVar14 + 0x177) = lVar13;
  puVar14[0x15a] = *(byte *)(param_2 + 0x1e7) & 1;
  puVar14[0x15b] = *(byte *)((long)param_2 + 0xf3b) & 1;
  puVar14[0x15c] = *(byte *)((long)param_2 + 0xf3c) & 1;
  bVar6 = *(byte *)((long)param_2 + 0xf3f);
  puVar14[0x15e] = bVar6 & 1;
  puVar14[0x15f] = 0;
  iVar4 = *(int *)(lVar8 + 0x5d8);
  if ((iVar4 != 0) && (((bVar6 & 1) == 0 || (iVar4 == 3)))) {
    puVar14[0x15f] = 1;
  }
  bVar6 = *(byte *)((long)param_2 + 0xf3d);
  *(undefined8 *)(puVar14 + 0x173) = 0;
  *(undefined8 *)(puVar14 + 0x18b) = 0;
  *(undefined8 *)(puVar14 + 0x18d) = 0;
  *(long *)(puVar14 + 399) = param_2[0x39];
  *(long *)(puVar14 + 0x163) = lStack_58;
  *(long *)(puVar14 + 0x161) = local_60;
  *(ulong *)(puVar14 + 0x167) = CONCAT44(uStack_44,local_48);
  *(undefined8 *)(puVar14 + 0x165) = local_50;
  *(long *)(puVar14 + 0x169) = param_2[0x191];
  puVar14[0x15d] = bVar6 & 1;
  (**(code **)(*param_1 + 0x170))(*param_1 + 0x170,param_1,puVar14,param_2);
  (**(code **)(*param_1 + 0x188))
            (*param_1 + 0x188,param_1,puVar14,param_2,param_2[0x1bf],param_2 + 0x10);
  (**(code **)(*param_1 + 200))(param_1,param_2[0x1bf],puVar14,param_2[0x191]);
  if (param_1[0xc] != 0) {
    uVar12 = *(ulong *)(param_1[0xc] + 0x74);
    uVar11 = param_1[0x17];
    uVar9 = -uVar11;
    if (uVar12 < uVar11) {
      uVar9 = ~uVar11;
    }
    if (uVar12 + uVar9 != 0) {
      thunk_EXT_FUN_801100000320d864(1,0,0,((uVar12 + uVar9) * 0x7d) / 3,0);
      param_1[0x17] = uVar12;
    }
  }
  return;
}

