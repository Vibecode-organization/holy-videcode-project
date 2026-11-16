// FUN_fffffff0081b9430 @ fffffff0081b9430 size=936

undefined8 FUN_fffffff0081b9430(long param_1,long *param_2,long *param_3,long *param_4,int param_5)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  long lVar6;
  long *plVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  uint uVar10;
  long lVar11;
  uint uVar12;
  int iVar13;
  undefined8 uVar14;
  uint local_6c;
  
  if (param_5 == 1) {
    local_6c = *(uint *)(*(long *)(param_1 + 0x2c0) + 0x2d1c);
  }
  else if (param_5 == 0) {
    local_6c = *(uint *)(*(long *)(param_1 + 0x2c0) + 0x2d18);
  }
  else {
    local_6c = 0;
  }
  iVar2 = (**(code **)(*param_2 + 0x90))(param_2);
  if (iVar2 == 0) {
    uVar9 = 0;
  }
  else {
    iVar13 = 0;
    uVar14 = *(undefined8 *)PTR_DAT_fffffff007ca60a8;
    uVar8 = *(undefined8 *)PTR_DAT_fffffff007ca60c8;
    do {
      lVar6 = (**(code **)(*param_2 + 0x118))(param_2,iVar13);
      if ((lVar6 == 0) ||
         (plVar7 = (long *)thunk_EXT_FUN_8011000003890f30(lVar6,uVar14), plVar7 == (long *)0x0)) {
        return 0xe00002c2;
      }
      uVar3 = (**(code **)(*plVar7 + 0xa8))();
      uVar12 = 1 << (ulong)(uVar3 & 0x1f);
      if ((uVar12 & local_6c) == 0) {
        return 0xe00002c2;
      }
      lVar6 = (**(code **)(*param_3 + 0x118))(param_3,iVar13);
      if (lVar6 == 0) {
        return 0xe00002c2;
      }
      plVar7 = (long *)thunk_EXT_FUN_8011000003890f30(lVar6,uVar14);
      if (plVar7 == (long *)0x0) {
        return 0xe00002c2;
      }
      uVar4 = (**(code **)(*plVar7 + 0xa8))();
      lVar6 = (**(code **)(*param_4 + 0x118))(param_4,iVar13);
      if (lVar6 == 0) {
        return 0xe00002c2;
      }
      plVar7 = (long *)thunk_EXT_FUN_8011000003890f30(lVar6,uVar8);
      if (plVar7 == (long *)0x0) {
        return 0xe00002c2;
      }
      iVar5 = (**(code **)(*plVar7 + 0x78))();
      if (iVar5 == 0) {
        if (param_5 == 1) {
          uVar10 = *(uint *)(*(long *)(param_1 + 0x2c0) + 0x2d1c);
        }
        else if (param_5 == 0) {
          uVar10 = *(uint *)(*(long *)(param_1 + 0x2c0) + 0x2d18);
        }
        else {
          uVar10 = 0;
        }
        uVar9 = 0xe00002c2;
        if ((uVar10 & uVar12) != 0) {
          if (param_5 == 1) {
            lVar11 = *(long *)(param_1 + 0x918);
            lVar6 = (ulong)uVar3 * 4;
            puVar1 = (undefined4 *)(lVar11 + 0xb8 + (long)(int)lVar6);
            if (lVar6 != (int)lVar6) {
              puVar1 = (undefined4 *)(lVar11 + 0xb8 + lVar6 & 0xffffffffffffU | 0x2bad000000000000);
            }
            *puVar1 = uVar4;
            uVar12 = *(uint *)(lVar11 + 0x70) | uVar12;
            goto LAB_fffffff0081b9538;
          }
          if (param_5 == 0) {
            uVar9 = 0;
            lVar11 = *(long *)(param_1 + 0x918);
            lVar6 = (ulong)uVar3 * 4;
            puVar1 = (undefined4 *)(lVar11 + 0x78 + (long)(int)lVar6);
            if (lVar6 != (int)lVar6) {
              puVar1 = (undefined4 *)(lVar11 + 0x78 + lVar6 & 0xffffffffffffU | 0x2bad000000000000);
            }
            *puVar1 = uVar4;
            *(uint *)(lVar11 + 0x6c) = *(uint *)(lVar11 + 0x6c) | uVar12;
          }
        }
      }
      else {
        if (param_5 == 1) {
          uVar10 = *(uint *)(*(long *)(param_1 + 0x2c0) + 0x2d1c);
        }
        else if (param_5 == 0) {
          uVar10 = *(uint *)(*(long *)(param_1 + 0x2c0) + 0x2d18);
        }
        else {
          uVar10 = 0;
        }
        uVar9 = 0xe00002c2;
        if ((uVar10 & uVar12) != 0) {
          if (param_5 == 1) {
            lVar11 = *(long *)(param_1 + 0x918);
            lVar6 = (ulong)uVar3 * 4;
            puVar1 = (undefined4 *)(lVar11 + 0xb8 + (long)(int)lVar6);
            if (lVar6 != (int)lVar6) {
              puVar1 = (undefined4 *)(lVar11 + 0xb8 + lVar6 & 0xffffffffffffU | 0x2bad000000000000);
            }
            *puVar1 = 0;
            uVar12 = *(uint *)(lVar11 + 0x70) & (uVar12 ^ 0xffffffff);
LAB_fffffff0081b9538:
            uVar9 = 0;
            *(uint *)(lVar11 + 0x70) = uVar12;
          }
          else if (param_5 == 0) {
            uVar9 = 0;
            lVar11 = *(long *)(param_1 + 0x918);
            lVar6 = (ulong)uVar3 * 4;
            puVar1 = (undefined4 *)(lVar11 + 0x78 + (long)(int)lVar6);
            if (lVar6 != (int)lVar6) {
              puVar1 = (undefined4 *)(lVar11 + 0x78 + lVar6 & 0xffffffffffffU | 0x2bad000000000000);
            }
            *puVar1 = 0;
            *(uint *)(lVar11 + 0x6c) = *(uint *)(lVar11 + 0x6c) & (uVar12 ^ 0xffffffff);
          }
        }
      }
      iVar13 = iVar13 + 1;
    } while (iVar2 != iVar13);
  }
  DataMemoryBarrier(2,3);
  return uVar9;
}

