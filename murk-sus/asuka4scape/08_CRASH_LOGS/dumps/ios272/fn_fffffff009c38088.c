// FUN_fffffff009c38088 @ fffffff009c38088 size=308

void FUN_fffffff009c38088(long param_1,long param_2,long param_3)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  bool bVar3;
  code *pcVar4;
  long *plVar5;
  ulong uVar6;
  ulong uVar7;
  ulong extraout_x9;
  long lVar8;
  ulong uVar9;
  long lVar10;
  bool bVar11;
  long *plVar12;
  ulong unaff_x30;
  undefined8 uVar13;
  undefined1 auVar14 [16];
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 1000));
  uVar7 = *(ulong *)(param_1 + 0x3f0);
  if (uVar7 == 0) goto LAB_fffffff009c380f4;
  uVar6 = 0;
  do {
    uVar9 = *(ulong *)(param_1 + 0x428) + uVar6 * 0x10;
    if (((*(ulong *)(param_1 + 0x428) ^ uVar9) & 0xffc0000000000000) != 0) {
      uVar9 = uVar9 & 0xffffffffffff | 0xc8a2000000000000;
    }
    if (*(long *)(uVar9 + 8) == param_2) goto LAB_fffffff009c380f8;
    uVar6 = uVar6 + 1;
  } while (uVar7 != uVar6);
  do {
    FUN_fffffff009c49290();
    uVar7 = extraout_x9;
LAB_fffffff009c380f4:
    uVar6 = 0;
LAB_fffffff009c380f8:
  } while (uVar6 == uVar7);
  lVar8 = *(long *)(param_1 + 0x428);
  if (*(long *)(lVar8 + uVar6 * 0x10) != param_3) {
    auVar14 = FUN_fffffff009c49260();
    plVar5 = auVar14._8_8_;
    plVar12 = *(long **)(auVar14._0_8_ + 0x430);
    *(long **)(auVar14._0_8_ + 0x430) = plVar5;
    if (plVar5 != (long *)0x0) {
      (**(code **)(*plVar5 + 0x20))(plVar5);
    }
    if (plVar12 != (long *)0x0) {
      (**(code **)(*plVar12 + 0x28))(plVar12);
    }
    if (plVar5 != (long *)0x0) {
      thunk_EXT_FUN_801100000322ffdc("IOSurfaceRoot using IOSurfaceRootParavirtMapperInterface %p");
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0,
                 "IOSurfaceRoot using IOSurfaceRootParavirtMapperInterface\n");
    }
    return;
  }
  lVar10 = 0;
  bVar3 = true;
  do {
    bVar11 = bVar3;
    puVar1 = (undefined8 *)(param_1 + 0x400 + lVar10 * 0x10);
    if (puVar1[1] == param_2) {
      *puVar1 = 0;
      puVar1[1] = 0;
    }
    lVar10 = 1;
    bVar3 = false;
  } while (bVar11);
  uVar7 = uVar7 - 1;
  *(ulong *)(param_1 + 0x3f0) = uVar7;
  if (uVar6 < uVar7) {
    do {
      uVar9 = uVar6 + 1;
      puVar1 = (undefined8 *)(*(long *)(param_1 + 0x428) + uVar9 * 0x10);
      uVar13 = *puVar1;
      puVar2 = (undefined8 *)(*(long *)(param_1 + 0x428) + uVar6 * 0x10);
      puVar2[1] = puVar1[1];
      *puVar2 = uVar13;
      uVar7 = *(ulong *)(param_1 + 0x3f0);
      uVar6 = uVar9;
    } while (uVar9 < uVar7);
    lVar8 = *(long *)(param_1 + 0x428);
  }
  lVar10 = uVar7 * 0x10;
  puVar1 = (undefined8 *)(lVar8 + (int)lVar10);
  if (lVar10 - (int)lVar10 != 0) {
    puVar1 = (undefined8 *)(lVar8 + lVar10 & 0xffffffffffffU | 0x2bad000000000000);
  }
  *puVar1 = 0;
  puVar1[1] = 0;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c381b4);
    (*pcVar4)();
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 1000));
  return;
}

