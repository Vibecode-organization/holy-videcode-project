// FUN_fffffff0081a4fb4 @ fffffff0081a4fb4 size=1104

void FUN_fffffff0081a4fb4(long param_1,undefined8 param_2)

{
  bool bVar1;
  char *pcVar2;
  code *pcVar3;
  ulong uVar4;
  char *pcVar5;
  long lVar6;
  ulong uVar7;
  ulong uVar8;
  ulong unaff_x30;
  
  pcVar5 = *(char **)(*(long *)(param_1 + 0x558) + 0x20);
  pcVar2 = "Firmware/Driver Shared (uncached, read/write)";
  if (pcVar5 != (char *)0x0) {
    pcVar2 = pcVar5;
  }
  thunk_EXT_FUN_8011000002977e48(param_2,*(undefined8 *)(*(long *)(param_1 + 0x558) + 0x48),pcVar2);
  pcVar5 = *(char **)(*(long *)(param_1 + 0x560) + 0x20);
  pcVar2 = "Firmware/Driver Shared (uncached, read-only)";
  if (pcVar5 != (char *)0x0) {
    pcVar2 = pcVar5;
  }
  thunk_EXT_FUN_8011000002977e48(param_2,*(undefined8 *)(*(long *)(param_1 + 0x560) + 0x48),pcVar2);
  pcVar5 = *(char **)(*(long *)(param_1 + 800) + 0x20);
  pcVar2 = "Cached Firmware Private";
  if (pcVar5 != (char *)0x0) {
    pcVar2 = pcVar5;
  }
  thunk_EXT_FUN_8011000002977e48(param_2,*(undefined8 *)(*(long *)(param_1 + 800) + 0x48),pcVar2);
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0xcc0));
  uVar4 = *(ulong *)(param_1 + 0xd08);
  if (uVar4 != 0) {
    uVar7 = 0;
    uVar8 = 1;
    do {
      lVar6 = *(long *)(*(long *)(param_1 + 0xd00) + uVar7 * 8);
      if (lVar6 != 0) {
        lVar6 = *(long *)(lVar6 + 8);
        pcVar5 = *(char **)(lVar6 + 0x20);
        pcVar2 = "Firmware Channel State Pool";
        if (pcVar5 != (char *)0x0) {
          pcVar2 = pcVar5;
        }
        thunk_EXT_FUN_8011000002977e48(param_2,*(undefined8 *)(lVar6 + 0x48),pcVar2);
        uVar4 = *(ulong *)(param_1 + 0xd08);
      }
      bVar1 = uVar8 < uVar4;
      uVar7 = uVar8;
      uVar8 = (ulong)((int)uVar8 + 1);
    } while (bVar1);
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0xcc0));
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0xd78));
  uVar4 = *(ulong *)(param_1 + 0xdc0);
  if (uVar4 != 0) {
    uVar7 = 0;
    uVar8 = 1;
    do {
      lVar6 = *(long *)(*(long *)(param_1 + 0xdb8) + uVar7 * 8);
      if (lVar6 != 0) {
        lVar6 = *(long *)(lVar6 + 8);
        pcVar5 = *(char **)(lVar6 + 0x20);
        pcVar2 = "Firmware Timestamp Queue Pool";
        if (pcVar5 != (char *)0x0) {
          pcVar2 = pcVar5;
        }
        thunk_EXT_FUN_8011000002977e48(param_2,*(undefined8 *)(lVar6 + 0x48),pcVar2);
        uVar4 = *(ulong *)(param_1 + 0xdc0);
      }
      bVar1 = uVar8 < uVar4;
      uVar7 = uVar8;
      uVar8 = (ulong)((int)uVar8 + 1);
    } while (bVar1);
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0xd78));
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0xe30));
  uVar4 = *(ulong *)(param_1 + 0xe78);
  if (uVar4 != 0) {
    uVar7 = 0;
    uVar8 = 1;
    do {
      lVar6 = *(long *)(*(long *)(param_1 + 0xe70) + uVar7 * 8);
      if (lVar6 != 0) {
        lVar6 = *(long *)(lVar6 + 8);
        pcVar5 = *(char **)(lVar6 + 0x20);
        pcVar2 = "Firmware (uncached) channel Pool";
        if (pcVar5 != (char *)0x0) {
          pcVar2 = pcVar5;
        }
        thunk_EXT_FUN_8011000002977e48(param_2,*(undefined8 *)(lVar6 + 0x48),pcVar2);
        uVar4 = *(ulong *)(param_1 + 0xe78);
      }
      bVar1 = uVar8 < uVar4;
      uVar7 = uVar8;
      uVar8 = (ulong)((int)uVar8 + 1);
    } while (bVar1);
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0xe30));
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x1110));
  uVar4 = *(ulong *)(param_1 + 0x1158);
  if (uVar4 != 0) {
    uVar7 = 0;
    uVar8 = 1;
    do {
      lVar6 = *(long *)(*(long *)(param_1 + 0x1150) + uVar7 * 8);
      if (lVar6 != 0) {
        lVar6 = *(long *)(lVar6 + 8);
        pcVar5 = *(char **)(lVar6 + 0x20);
        pcVar2 = "Firmware Event Signal Pool";
        if (pcVar5 != (char *)0x0) {
          pcVar2 = pcVar5;
        }
        thunk_EXT_FUN_8011000002977e48(param_2,*(undefined8 *)(lVar6 + 0x48),pcVar2);
        uVar4 = *(ulong *)(param_1 + 0x1158);
      }
      bVar1 = uVar8 < uVar4;
      uVar7 = uVar8;
      uVar8 = (ulong)((int)uVar8 + 1);
    } while (bVar1);
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x1110));
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0xee8));
  uVar4 = *(ulong *)(param_1 + 0xf30);
  if (uVar4 != 0) {
    uVar7 = 0;
    uVar8 = 1;
    do {
      lVar6 = *(long *)(*(long *)(param_1 + 0xf28) + uVar7 * 8);
      if (lVar6 != 0) {
        lVar6 = *(long *)(lVar6 + 8);
        pcVar5 = *(char **)(lVar6 + 0x20);
        pcVar2 = "Firmware (cached) channel Pool";
        if (pcVar5 != (char *)0x0) {
          pcVar2 = pcVar5;
        }
        thunk_EXT_FUN_8011000002977e48(param_2,*(undefined8 *)(lVar6 + 0x48),pcVar2);
        uVar4 = *(ulong *)(param_1 + 0xf30);
      }
      bVar1 = uVar8 < uVar4;
      uVar7 = uVar8;
      uVar8 = (ulong)((int)uVar8 + 1);
    } while (bVar1);
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0xee8));
  pcVar5 = *(char **)(*(long *)(param_1 + 0x1198) + 0x20);
  pcVar2 = "Firmware VDM Command Pool";
  if (pcVar5 != (char *)0x0) {
    pcVar2 = pcVar5;
  }
  thunk_EXT_FUN_8011000002977e48(param_2,*(undefined8 *)(*(long *)(param_1 + 0x1198) + 0x48),pcVar2)
  ;
  pcVar5 = *(char **)(*(long *)(param_1 + 0x11d8) + 0x20);
  pcVar2 = "Firmware PDM Command Pool";
  if (pcVar5 != (char *)0x0) {
    pcVar2 = pcVar5;
  }
  thunk_EXT_FUN_8011000002977e48(param_2,*(undefined8 *)(*(long *)(param_1 + 0x11d8) + 0x48),pcVar2)
  ;
  pcVar5 = *(char **)(*(long *)(param_1 + 0x1218) + 0x20);
  pcVar2 = "Firmware PDM Blit Command Pool";
  if (pcVar5 != (char *)0x0) {
    pcVar2 = pcVar5;
  }
  thunk_EXT_FUN_8011000002977e48(param_2,*(undefined8 *)(*(long *)(param_1 + 0x1218) + 0x48),pcVar2)
  ;
  pcVar5 = *(char **)(*(long *)(param_1 + 0x1258) + 0x20);
  pcVar2 = "Firmware CDM Command Pool";
  if (pcVar5 != (char *)0x0) {
    pcVar2 = pcVar5;
  }
  thunk_EXT_FUN_8011000002977e48(param_2,*(undefined8 *)(*(long *)(param_1 + 0x1258) + 0x48),pcVar2)
  ;
  pcVar5 = *(char **)(*(long *)(param_1 + 0x1298) + 0x20);
  pcVar2 = "Firmware Barrier Pool";
  if (pcVar5 != (char *)0x0) {
    pcVar2 = pcVar5;
  }
  thunk_EXT_FUN_8011000002977e48(param_2,*(undefined8 *)(*(long *)(param_1 + 0x1298) + 0x48),pcVar2)
  ;
  pcVar5 = *(char **)(*(long *)(param_1 + 0x12d8) + 0x20);
  pcVar2 = "Firmware PM Grow Pool";
  if (pcVar5 != (char *)0x0) {
    pcVar2 = pcVar5;
  }
  thunk_EXT_FUN_8011000002977e48(param_2,*(undefined8 *)(*(long *)(param_1 + 0x12d8) + 0x48),pcVar2)
  ;
  pcVar5 = *(char **)(*(long *)(param_1 + 0x1318) + 0x20);
  pcVar2 = "Firmware PM Rebuild Pool";
  if (pcVar5 != (char *)0x0) {
    pcVar2 = pcVar5;
  }
  thunk_EXT_FUN_8011000002977e48(param_2,*(undefined8 *)(*(long *)(param_1 + 0x1318) + 0x48),pcVar2)
  ;
  pcVar5 = *(char **)(*(long *)(param_1 + 0x1358) + 0x20);
  pcVar2 = "Firmware Remote Node";
  if (pcVar5 != (char *)0x0) {
    pcVar2 = pcVar5;
  }
  thunk_EXT_FUN_8011000002977e48(param_2,*(undefined8 *)(*(long *)(param_1 + 0x1358) + 0x48),pcVar2)
  ;
  pcVar5 = *(char **)(*(long *)(param_1 + 0x1398) + 0x20);
  pcVar2 = "Firmware Shared Event Command Pool";
  if (pcVar5 != (char *)0x0) {
    pcVar2 = pcVar5;
  }
  thunk_EXT_FUN_8011000002977e48(param_2,*(undefined8 *)(*(long *)(param_1 + 0x1398) + 0x48),pcVar2)
  ;
  pcVar5 = *(char **)(*(long *)(param_1 + 0x13d8) + 0x20);
  pcVar2 = "Firmware MSE Grow Pool";
  if (pcVar5 != (char *)0x0) {
    pcVar2 = pcVar5;
  }
  thunk_EXT_FUN_8011000002977e48(param_2,*(undefined8 *)(*(long *)(param_1 + 0x13d8) + 0x48),pcVar2)
  ;
  pcVar5 = *(char **)(*(long *)(param_1 + 0x1418) + 0x20);
  pcVar2 = "Firmware MSE Rebuild command pool";
  if (pcVar5 != (char *)0x0) {
    pcVar2 = pcVar5;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081a5400);
    (*pcVar3)();
  }
  thunk_EXT_FUN_8011000002977e48(param_2,*(undefined8 *)(*(long *)(param_1 + 0x1418) + 0x48),pcVar2)
  ;
  return;
}

