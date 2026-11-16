// FUN_fffffff0081c3f74 @ fffffff0081c3f74 size=280

void FUN_fffffff0081c3f74(long param_1,undefined8 param_2)

{
  bool bVar1;
  char *pcVar2;
  code *pcVar3;
  ulong uVar4;
  long lVar5;
  char *pcVar6;
  ulong uVar7;
  ulong uVar8;
  ulong unaff_x30;
  
  FUN_fffffff0081a4fb4();
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 4000));
  uVar4 = *(ulong *)(param_1 + 0xfe8);
  if (uVar4 != 0) {
    uVar7 = 0;
    uVar8 = 1;
    do {
      lVar5 = *(long *)(*(long *)(param_1 + 0xfe0) + uVar7 * 8);
      if (lVar5 != 0) {
        lVar5 = *(long *)(lVar5 + 8);
        pcVar6 = *(char **)(lVar5 + 0x20);
        pcVar2 = "Firmware Scheduler State (per Command Queue) Pool";
        if (pcVar6 != (char *)0x0) {
          pcVar2 = pcVar6;
        }
        thunk_EXT_FUN_8011000002977e48(param_2,*(undefined8 *)(lVar5 + 0x48),pcVar2);
        uVar4 = *(ulong *)(param_1 + 0xfe8);
      }
      bVar1 = uVar8 < uVar4;
      uVar7 = uVar8;
      uVar8 = (ulong)((int)uVar8 + 1);
    } while (bVar1);
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 4000));
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x1058));
  uVar4 = *(ulong *)(param_1 + 0x10a0);
  if (uVar4 != 0) {
    uVar7 = 0;
    uVar8 = 1;
    do {
      lVar5 = *(long *)(*(long *)(param_1 + 0x1098) + uVar7 * 8);
      if (lVar5 != 0) {
        lVar5 = *(long *)(lVar5 + 8);
        pcVar6 = *(char **)(lVar5 + 0x20);
        pcVar2 = "Firmware\'s per-process mse state";
        if (pcVar6 != (char *)0x0) {
          pcVar2 = pcVar6;
        }
        thunk_EXT_FUN_8011000002977e48(param_2,*(undefined8 *)(lVar5 + 0x48),pcVar2);
        uVar4 = *(ulong *)(param_1 + 0x10a0);
      }
      bVar1 = uVar8 < uVar4;
      uVar7 = uVar8;
      uVar8 = (ulong)((int)uVar8 + 1);
    } while (bVar1);
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081c4088);
    (*pcVar3)();
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x1058));
  return;
}

