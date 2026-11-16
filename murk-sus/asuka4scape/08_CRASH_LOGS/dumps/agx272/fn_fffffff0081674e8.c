// FUN_fffffff0081674e8 @ fffffff0081674e8 size=480

undefined8 FUN_fffffff0081674e8(long *param_1,ulong param_2)

{
  ulong *puVar1;
  ulong *puVar2;
  ulong *puVar3;
  undefined8 uVar4;
  int iVar5;
  ulong uVar6;
  ulong uVar7;
  ulong uVar8;
  uint uVar9;
  long lVar10;
  long lVar11;
  
  if ((*(byte *)((long)param_1 + 0x1112c) >> 1 & 1) == 0) {
    return 1;
  }
  thunk_EXT_FUN_80110000032222a8(param_1[0x359c]);
  uVar6 = (param_2 & 0xffffffff) << 4;
  uVar8 = -(param_2 >> 0x1f & 1) & 0xfffffff000000000 | uVar6;
  iVar5 = (int)uVar6;
  puVar1 = (ulong *)(param_1[0x359d] + (long)iVar5);
  if (uVar8 != (long)iVar5) {
    puVar1 = (ulong *)(param_1[0x359d] + uVar8 & 0xffffffffffff | 0x2bad000000000000);
  }
  uVar6 = *puVar1;
  if (uVar6 == 0) {
    uVar6 = puVar1[1];
    if (uVar6 == 0) goto LAB_fffffff00816769c;
    uVar8 = 0x40;
  }
  else {
    uVar8 = 0;
  }
  uVar6 = (uVar6 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar6 & 0x5555555555555555) << 1;
  uVar6 = (uVar6 & 0xcccccccccccccccc) >> 2 | (uVar6 & 0x3333333333333333) << 2;
  uVar6 = (uVar6 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar6 & 0xf0f0f0f0f0f0f0f) << 4;
  uVar6 = (uVar6 & 0xff00ff00ff00ff00) >> 8 | (uVar6 & 0xff00ff00ff00ff) << 8;
  uVar6 = (uVar6 & 0xffff0000ffff0000) >> 0x10 | (uVar6 & 0xffff0000ffff) << 0x10;
  uVar8 = LZCOUNT(uVar6 >> 0x20 | uVar6 << 0x20) | uVar8;
  lVar11 = (long)(int)param_2 * 0x10;
  while( true ) {
    while( true ) {
      lVar10 = param_1[0x359b];
      uVar4 = (**(code **)(*param_1 + 0x790))(param_1);
      (**(code **)(*param_1 + 0xd90))(param_1,lVar10,uVar8,uVar4);
      uVar6 = param_1[0x359d] + (long)(int)lVar11;
      if (lVar11 - (int)lVar11 != 0) {
        uVar6 = param_1[0x359d] + lVar11 & 0xffffffffffffU | 0x2bad000000000000;
      }
      uVar7 = uVar8 >> 3 & 0x1ffffffffffffff8;
      iVar5 = (int)uVar7;
      puVar2 = (ulong *)(uVar6 + (long)iVar5);
      if (uVar7 != (long)iVar5) {
        puVar2 = (ulong *)(uVar6 + uVar7 & 0xffffffffffff | 0x2bad000000000000);
      }
      puVar3 = (ulong *)((long)puVar1 + (long)iVar5);
      if (uVar7 != (long)iVar5) {
        puVar3 = (ulong *)((long)puVar1 + uVar7 & 0xffffffffffff | 0x2bad000000000000);
      }
      *puVar2 = *puVar2 & (1L << (uVar8 & 0x3f) ^ 0xffffffffffffffffU);
      uVar9 = (uint)uVar8;
      uVar6 = 0;
      if ((uVar9 & 0x3f) != 0x3f) {
        uVar6 = -1L << ((ulong)((uVar9 & 0x3f) + 1) & 0x3f);
      }
      uVar6 = *puVar3 & uVar6;
      uVar8 = (uVar6 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar6 & 0x5555555555555555) << 1;
      uVar8 = (uVar8 & 0xcccccccccccccccc) >> 2 | (uVar8 & 0x3333333333333333) << 2;
      uVar8 = (uVar8 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar8 & 0xf0f0f0f0f0f0f0f) << 4;
      uVar8 = (uVar8 & 0xff00ff00ff00ff00) >> 8 | (uVar8 & 0xff00ff00ff00ff) << 8;
      uVar8 = (uVar8 & 0xffff0000ffff0000) >> 0x10 | (uVar8 & 0xffff0000ffff) << 0x10;
      iVar5 = (int)LZCOUNT(uVar8 >> 0x20 | uVar8 << 0x20);
      if (uVar6 == 0) {
        iVar5 = -1;
      }
      if (iVar5 < 0) break;
      uVar8 = (ulong)(iVar5 + (uVar9 & 0xffffffc0));
    }
    if ((0x3f < uVar9) || (uVar6 = puVar1[1], uVar6 == 0)) break;
    uVar6 = (uVar6 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar6 & 0x5555555555555555) << 1;
    uVar6 = (uVar6 & 0xcccccccccccccccc) >> 2 | (uVar6 & 0x3333333333333333) << 2;
    uVar6 = (uVar6 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar6 & 0xf0f0f0f0f0f0f0f) << 4;
    uVar6 = (uVar6 & 0xff00ff00ff00ff00) >> 8 | (uVar6 & 0xff00ff00ff00ff) << 8;
    uVar6 = (uVar6 & 0xffff0000ffff0000) >> 0x10 | (uVar6 & 0xffff0000ffff) << 0x10;
    uVar8 = (ulong)((uint)LZCOUNT(uVar6 >> 0x20 | uVar6 << 0x20) | 0x40);
  }
LAB_fffffff00816769c:
  thunk_EXT_FUN_8011000003222de0(param_1[0x359c]);
  return 1;
}

