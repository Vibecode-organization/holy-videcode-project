// FUN_fffffff00818dc84 @ fffffff00818dc84 size=336

void FUN_fffffff00818dc84(long param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  long lVar2;
  long lVar3;
  ulong uVar4;
  ulong unaff_x30;
  
  if ((*(byte *)(param_1 + 0x7f5) & 1) == 0) {
    thunk_EXT_FUN_8011000002946f14(param_3);
    lVar2 = *(long *)(param_1 + 0x610);
    if (lVar2 != 0) {
      if (*(int *)(lVar2 + 0x98) != 0) {
        uVar4 = 0;
        do {
          lVar3 = *(long *)(lVar2 + 0x28 + uVar4 * 8);
          if ((*(long *)(lVar3 + 0x218) != 0) && (*(int *)(*(long *)(lVar3 + 0x218) + 0x18) != 0x80)
             ) {
            thunk_EXT_FUN_8011000002949418
                      (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),param_2,param_3);
            lVar2 = *(long *)(param_1 + 0x610);
            lVar3 = *(long *)(lVar2 + 0x28 + uVar4 * 8);
          }
          if (*(int *)(*(long *)(lVar3 + 0x220) + 0x18) != 0x80) {
            thunk_EXT_FUN_8011000002949418
                      (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),param_2,param_3);
            lVar2 = *(long *)(param_1 + 0x610);
          }
          uVar4 = uVar4 + 1;
        } while (uVar4 < *(uint *)(lVar2 + 0x98));
      }
      if (*(int *)(lVar2 + 0x9c) != 0) {
        uVar4 = 0;
        do {
          if (*(int *)(*(long *)(*(long *)(lVar2 + 0x48 + uVar4 * 8) + 0x218) + 0x18) != 0x80) {
            thunk_EXT_FUN_8011000002949418
                      (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),param_2,param_3);
            lVar2 = *(long *)(param_1 + 0x610);
          }
          uVar4 = uVar4 + 1;
        } while (uVar4 < *(uint *)(lVar2 + 0x9c));
      }
    }
    return;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00818dca4);
    (*pcVar1)();
  }
  thunk_EXT_FUN_801100000294849c(*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148));
  return;
}

