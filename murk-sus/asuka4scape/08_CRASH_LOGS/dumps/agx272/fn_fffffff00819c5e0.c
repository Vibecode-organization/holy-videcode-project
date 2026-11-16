// FUN_fffffff00819c5e0 @ fffffff00819c5e0 size=4

void FUN_fffffff00819c5e0(long *param_1,undefined8 param_2,ulong param_3,undefined8 param_4)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  undefined *puVar4;
  code *pcVar5;
  bool bVar6;
  bool bVar7;
  long lVar8;
  long lVar9;
  long lVar10;
  uint uVar11;
  ulong unaff_x30;
  float fVar12;
  float fVar13;
  
  if ((*(byte *)((long)param_1 + 0x1ac44) >> 3 & 1) != 0) {
    thunk_EXT_FUN_80110000032222a8(param_1[0x3589]);
    thunk_EXT_FUN_80110000036da494(0x85930d85,param_4,param_2,param_3,0,0);
    thunk_EXT_FUN_8011000003222de0(param_1[0x3589]);
  }
  lVar8 = thunk_EXT_FUN_8011000002971b4c(param_1);
  bVar3 = *(byte *)(param_1 + 0x3598);
  thunk_EXT_FUN_801100000296c9fc();
  thunk_EXT_FUN_80110000032222a8(DAT_fffffff00ae23bd0);
  *(undefined1 *)(lVar8 + 0x2a0) = 1;
  lVar9 = (**(code **)(**(long **)(lVar8 + 0x238) + 0xa8))();
  puVar4 = PTR_DAT_fffffff007ca5f88;
  uVar11 = *(uint *)PTR_DAT_fffffff007ca5f88;
  if ((*(byte *)(lVar8 + 0x2a0) & 1) != 0) {
    *(undefined1 *)(lVar8 + 0x2a0) = 0;
    thunk_EXT_FUN_8011000003222de0(DAT_fffffff00ae23bd0);
  }
  thunk_EXT_FUN_80110000032222a8(DAT_fffffff00ae23bd0);
  *(undefined1 *)(lVar8 + 0x2a0) = 1;
  lVar10 = (**(code **)(**(long **)(lVar8 + 0x230) + 0xa8))();
  uVar2 = *(uint *)puVar4;
  if ((*(byte *)(lVar8 + 0x2a0) & 1) != 0) {
    *(undefined1 *)(lVar8 + 0x2a0) = 0;
    thunk_EXT_FUN_8011000003222de0(DAT_fffffff00ae23bd0);
  }
  thunk_EXT_FUN_801100000296ca08(lVar8);
  uVar1 = 0x60000000;
  if ((bVar3 & 1) == 0) {
    uVar1 = 0x3f5c2900;
  }
  bVar6 = false;
  bVar7 = true;
  if (uVar1 <= (uint)(lVar9 << ((ulong)uVar11 & 0x3f))) {
    uVar11 = (uint)(lVar10 << ((ulong)uVar2 & 0x3f));
    bVar7 = uVar11 <= uVar1;
    bVar6 = uVar1 == uVar11;
  }
  fVar12 = 0.5;
  if ((*(byte *)(param_1 + 0x3598) & 1) == 0) {
    fVar12 = 0.6;
  }
  fVar13 = (float)(0x60000000 - DAT_fffffff00ae22f48) / 1.6106127e+09;
  if ((((param_3 & 1) != 0) || (bVar7 && !bVar6)) || (fVar13 < fVar12)) {
    *(undefined1 *)(param_1 + 0x3598) = 1;
    (**(code **)(*param_1 + 0xd60))(param_1,param_2,param_4);
    bVar3 = *(byte *)((long)param_1 + 0x1ac44);
  }
  else {
    *(undefined1 *)(param_1 + 0x3598) = 0;
    bVar3 = *(byte *)((long)param_1 + 0x1ac44);
  }
  if ((bVar3 >> 3 & 1) != 0) {
    bVar3 = 2;
    if (fVar12 <= fVar13) {
      bVar3 = 0;
    }
    thunk_EXT_FUN_80110000032222a8(param_1[0x3589]);
    thunk_EXT_FUN_80110000036da494(0x85930d86,param_4,param_2,param_3,bVar3 | (bVar7 && !bVar6),0);
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
      thunk_EXT_FUN_8011000003222de0(param_1[0x3589]);
      return;
    }
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00819c808);
    (*pcVar5)();
  }
  return;
}

