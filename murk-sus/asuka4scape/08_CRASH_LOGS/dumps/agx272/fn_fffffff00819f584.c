// FUN_fffffff00819f584 @ fffffff00819f584 size=352

void FUN_fffffff00819f584(long param_1,undefined8 param_2)

{
  long lVar1;
  long lVar2;
  int iVar3;
  ulong uVar4;
  ulong uVar5;
  ulong uVar6;
  long lVar7;
  long lVar8;
  undefined8 local_140;
  undefined8 uStack_138;
  undefined8 uStack_130;
  undefined8 uStack_128;
  undefined8 local_120;
  undefined8 uStack_118;
  undefined8 uStack_110;
  undefined8 uStack_108;
  undefined8 local_100;
  undefined8 uStack_f8;
  undefined8 uStack_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 uStack_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 uStack_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  long local_38;
  
  local_38 = *(long *)PTR_DAT_fffffff007ca61a0;
  lVar7 = *(long *)(param_1 + 0x18);
  uStack_58 = 0;
  local_60 = 0;
  uStack_48 = 0;
  uStack_50 = 0;
  uStack_78 = 0;
  local_80 = 0;
  uStack_68 = 0;
  uStack_70 = 0;
  uStack_98 = 0;
  local_a0 = 0;
  uStack_88 = 0;
  uStack_90 = 0;
  uStack_b8 = 0;
  local_c0 = 0;
  uStack_a8 = 0;
  uStack_b0 = 0;
  uStack_d8 = 0;
  local_e0 = 0;
  uStack_c8 = 0;
  uStack_d0 = 0;
  uStack_f8 = 0;
  local_100 = 0;
  uStack_e8 = 0;
  uStack_f0 = 0;
  uStack_118 = 0;
  local_120 = 0;
  uStack_108 = 0;
  uStack_110 = 0;
  uStack_138 = 0;
  local_140 = 0;
  uStack_128 = 0;
  uStack_130 = 0;
  iVar3 = thunk_EXT_FUN_8011000003769480(&local_140,0x100,param_2,&stack0x00000000);
  lVar8 = *(long *)(lVar7 + 0x10) * (long)iVar3;
  lVar1 = *(long *)(lVar7 + 0x40);
  lVar2 = *(long *)(lVar7 + 0x48);
  uVar4 = (**(code **)(**(long **)(lVar7 + 0x38) + 0x88))();
  if (uVar4 < (ulong)((lVar8 - lVar1) + lVar2)) {
    uVar5 = (**(code **)(**(long **)(lVar7 + 0x38) + 0x88))();
    uVar6 = *(ulong *)(lVar7 + 0x18);
    uVar4 = 0;
    if (uVar6 != 0) {
      uVar4 = (((lVar8 + ~uVar5) - *(long *)(lVar7 + 0x40)) + *(long *)(lVar7 + 0x48) + uVar6) /
              uVar6;
    }
    iVar3 = FUN_fffffff008183128(lVar7,uVar4 * uVar6);
    if (iVar3 == 0) goto LAB_fffffff00819f6b4;
  }
  thunk_EXT_FUN_8011000003a61b10(*(undefined8 *)(lVar7 + 0x48),&local_140,lVar8);
  uVar4 = *(ulong *)(lVar7 + 0x48) + lVar8;
  if (((*(ulong *)(lVar7 + 0x48) ^ uVar4) & 0xffc0000000000000) != 0) {
    uVar4 = uVar4 & 0xffffffffffff | 0xc8a2000000000000;
  }
  *(ulong *)(lVar7 + 0x48) = uVar4;
LAB_fffffff00819f6b4:
  if (*(long *)PTR_DAT_fffffff007ca61a0 == local_38) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590();
  return;
}

