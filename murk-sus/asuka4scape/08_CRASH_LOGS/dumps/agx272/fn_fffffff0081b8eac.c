// FUN_fffffff0081b8eac @ fffffff0081b8eac size=1048

undefined8 FUN_fffffff0081b8eac(long param_1,long *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  long lVar3;
  long *plVar4;
  long *plVar5;
  long *plVar6;
  long *plVar7;
  ulong uVar8;
  undefined4 *puVar9;
  int iVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  long lVar13;
  undefined8 *puVar14;
  undefined8 uVar15;
  int iVar16;
  undefined4 uVar17;
  ulong local_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 uStack_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  undefined8 uStack_88;
  undefined4 local_78;
  undefined4 local_74;
  
  lVar3 = (**(code **)(*param_2 + 0x138))(param_2,"sensor_indexes");
  if (lVar3 == 0) {
    return 0xe00002c2;
  }
  uVar15 = *(undefined8 *)PTR_DAT_fffffff007ca6098;
  plVar4 = (long *)thunk_EXT_FUN_8011000003890f30(lVar3,uVar15);
  if (plVar4 == (long *)0x0) {
    return 0xe00002c2;
  }
  lVar3 = (**(code **)(*param_2 + 0x138))(param_2,"sensor_offsets");
  if (lVar3 == 0) {
    return 0xe00002c2;
  }
  plVar5 = (long *)thunk_EXT_FUN_8011000003890f30(lVar3,uVar15);
  if (plVar5 == (long *)0x0) {
    return 0xe00002c2;
  }
  lVar3 = (**(code **)(*param_2 + 0x138))(param_2,"sensor_reset_status");
  if (lVar3 == 0) {
    return 0xe00002c2;
  }
  plVar6 = (long *)thunk_EXT_FUN_8011000003890f30(lVar3,uVar15);
  if (plVar6 == (long *)0x0) {
    return 0xe00002c2;
  }
  if (param_3 == 0) {
    lVar3 = 0x2278;
  }
  else {
    if (param_3 != 1) {
      local_c8 = 0;
      goto LAB_fffffff0081b8fe4;
    }
    lVar3 = 0x2f28;
  }
  local_c8 = *(ulong *)(*(long *)(param_1 + 0x2c0) + lVar3);
LAB_fffffff0081b8fe4:
  iVar1 = (**(code **)(*plVar4 + 0x90))(plVar4);
  if (iVar1 != 0) {
    iVar16 = 0;
    uVar15 = *(undefined8 *)PTR_DAT_fffffff007ca60a8;
    uVar11 = *(undefined8 *)PTR_DAT_fffffff007ca6090;
    uVar12 = *(undefined8 *)PTR_DAT_fffffff007ca60c8;
    do {
      lVar3 = (**(code **)(*plVar4 + 0x118))(plVar4,iVar16);
      if (lVar3 == 0) {
        return 0xe00002c2;
      }
      plVar7 = (long *)thunk_EXT_FUN_8011000003890f30(lVar3,uVar15);
      if (plVar7 == (long *)0x0) {
        return 0xe00002c2;
      }
      uVar8 = (**(code **)(*plVar7 + 0xa8))();
      if ((local_c8 >> (uVar8 & 0x3f) & 1) == 0) {
        return 0xe00002c2;
      }
      lVar3 = (**(code **)(*plVar5 + 0x118))(plVar5,iVar16);
      if (lVar3 == 0) {
        return 0xe00002c2;
      }
      plVar7 = (long *)thunk_EXT_FUN_8011000003890f30(lVar3,uVar11);
      if (plVar7 == (long *)0x0) {
        return 0xe00002c2;
      }
      puVar9 = (undefined4 *)(**(code **)(*plVar7 + 0xd8))();
      uVar17 = *puVar9;
      lVar3 = (**(code **)(*plVar6 + 0x118))(plVar6,iVar16);
      if (lVar3 == 0) {
        return 0xe00002c2;
      }
      plVar7 = (long *)thunk_EXT_FUN_8011000003890f30(lVar3,uVar12);
      if (plVar7 == (long *)0x0) {
        return 0xe00002c2;
      }
      iVar2 = (**(code **)(*plVar7 + 0x78))();
      lVar3 = (uVar8 & 0xffffffff) * 4;
      iVar10 = (int)lVar3;
      if (iVar2 != 0) {
        if (param_3 == 0) {
          lVar13 = 0x2320;
        }
        else {
          uVar17 = 0;
          if (param_3 != 1) goto LAB_fffffff0081b91a0;
          lVar13 = 0x2f38;
        }
        lVar13 = *(long *)(param_1 + 0x2c0) + lVar13;
        puVar9 = (undefined4 *)(lVar13 + iVar10);
        if (lVar3 - iVar10 != 0) {
          puVar9 = (undefined4 *)(lVar13 + lVar3 & 0xffffffffffffU | 0x2bad000000000000);
        }
        uVar17 = *puVar9;
      }
LAB_fffffff0081b91a0:
      if (param_3 == 0) {
        lVar13 = 0x2420;
LAB_fffffff0081b91b8:
        lVar13 = *(long *)(param_1 + 0x2c0) + lVar13;
        puVar9 = (undefined4 *)(lVar13 + iVar10);
        if (lVar3 - iVar10 != 0) {
          puVar9 = (undefined4 *)(lVar13 + lVar3 & 0xffffffffffffU | 0x2bad000000000000);
        }
        *puVar9 = uVar17;
      }
      else if (param_3 == 1) {
        lVar13 = 0x3038;
        goto LAB_fffffff0081b91b8;
      }
      iVar16 = iVar16 + 1;
    } while (iVar1 != iVar16);
  }
  DataMemoryBarrier(2,3);
  uStack_98 = 0;
  local_a0 = 0;
  uStack_88 = 0;
  uStack_90 = 0;
  uStack_b8 = 0;
  uStack_a8 = 0;
  uStack_b0 = 0;
  local_c0 = 0xb;
  local_74 = 1;
  uVar15 = (**(code **)(*(long *)(param_1 + 0x848) + 0x30))(param_1 + 0x848);
  local_78 = 0;
  plVar4 = *(long **)(*(long *)(param_1 + 0x280) + 0x310);
  puVar14 = (undefined8 *)(*plVar4 + 0xe8);
  iVar1 = (*(code *)*puVar14)(puVar14,plVar4,FUN_fffffff00817ea94,&local_c0,&local_74,&local_78,0);
  if ((iVar1 == 0) && (((byte)local_74 >> 1 & 1) != 0)) {
    FUN_fffffff0081a43cc(param_1,uVar15,local_78);
  }
  return 0;
}

