// FUN_fffffff008203dbc @ fffffff008203dbc size=424

void FUN_fffffff008203dbc(long param_1,undefined8 param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  code *pcVar6;
  long *plVar7;
  long lVar8;
  uint *puVar9;
  undefined8 *puVar10;
  long lVar11;
  long lVar12;
  ulong unaff_x30;
  
  (**(code **)(PTR_DAT_fffffff007ca6120 + 0x90))();
  plVar7 = *(long **)(*(long *)(param_1 + 0x10) + 0x310);
  puVar10 = (undefined8 *)(*plVar7 + 0xe8);
  (*(code *)*puVar10)(puVar10,plVar7,FUN_fffffff00817eecc,0,0,0,0);
  thunk_EXT_FUN_80110000038ff214(*(undefined8 *)(param_1 + 0x18));
  puVar9 = (uint *)(param_1 + 0x40);
  uVar2 = *(uint *)(param_1 + 0x44);
  uVar1 = *(uint *)(param_1 + 0x4c);
  uVar3 = *(uint *)(param_1 + 0x50);
  if (param_3 != 0) {
    puVar9[0] = 0;
    puVar9[1] = 0;
    *(undefined8 *)(param_1 + 0x48) = 0;
    *(undefined4 *)(param_1 + 0x50) = 0;
  }
  uVar4 = 0;
  if (uVar3 != 0) {
    uVar4 = uVar1 / uVar3;
  }
  uVar1 = 0;
  if (uVar3 != 0) {
    uVar1 = *puVar9 / uVar3;
  }
  uVar5 = 0;
  if (uVar3 != 0) {
    uVar5 = uVar2 / uVar3;
  }
  thunk_EXT_FUN_8011000002968b4c(param_1,param_2,uVar1,"Tiler Utilization %");
  thunk_EXT_FUN_8011000002968b4c(param_1,param_2,uVar5,"Renderer Utilization %");
  thunk_EXT_FUN_8011000002968b4c(param_1,param_2,uVar4,"Device Utilization %");
  thunk_EXT_FUN_8011000002968b4c(param_1,param_2,*(undefined4 *)(param_1 + 0x38),"TiledSceneBytes");
  *(undefined8 *)(param_1 + 0x38) = 0;
  thunk_EXT_FUN_8011000002968b4c(param_1,param_2,*(undefined4 *)(param_1 + 0x30),"SplitSceneCount");
  *(undefined4 *)(param_1 + 0x30) = 0;
  thunk_EXT_FUN_80110000038ff2e0(*(undefined8 *)(param_1 + 0x18));
  lVar12 = *(long *)(param_1 + 0x10);
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar12 + 800));
  lVar8 = *(long *)(lVar12 + 0x328);
  if (lVar8 == 0) {
    lVar11 = 0;
  }
  else {
    lVar11 = 0;
    do {
      lVar11 = *(long *)(lVar8 + 0x128) + lVar11;
      lVar8 = *(long *)(lVar8 + 0x1f8);
    } while (lVar8 != 0);
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar12 + 800));
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
    thunk_EXT_FUN_8011000002968b4c(param_1,param_2,lVar11,"Allocated PB Size");
    return;
  }
                    /* WARNING: Does not return */
  pcVar6 = (code *)SoftwareBreakpoint(0xc471,0xfffffff008203f60);
  (*pcVar6)();
}

