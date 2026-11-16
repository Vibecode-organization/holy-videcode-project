// FUN_fffffff00818ac24 @ fffffff00818ac24 size=432

void FUN_fffffff00818ac24(long param_1,uint param_2,uint param_3)

{
  uint uVar1;
  code *pcVar2;
  long lVar3;
  uint uVar4;
  uint uVar5;
  long lVar6;
  ulong unaff_x30;
  
  if (0x3ff < (param_3 | param_2)) {
    thunk_EXT_FUN_8011000003a49114
              (
              "AGXk: %s:%d:%s: !!! Incorrect barrier stage information for CommandBuffer %p fStateIndex %d src_mask %d dst_mask %d\n"
              );
    return;
  }
  if ((param_2 != 0) && (param_3 != 0)) {
    uVar4 = param_2;
    do {
      uVar5 = (uVar4 & 0xaaaaaaaa) >> 1 | (uVar4 & 0x55555555) << 1;
      uVar5 = (uVar5 & 0xcccccccc) >> 2 | (uVar5 & 0x33333333) << 2;
      uVar5 = (uVar5 & 0xf0f0f0f0) >> 4 | (uVar5 & 0xf0f0f0f) << 4;
      uVar5 = (uVar5 & 0xff00ff00) >> 8 | (uVar5 & 0xff00ff) << 8;
      lVar3 = LZCOUNT(uVar5 >> 0x10 | uVar5 << 0x10);
      uVar5 = param_3;
      do {
        uVar1 = (uVar5 & 0xaaaaaaaa) >> 1 | (uVar5 & 0x55555555) << 1;
        uVar1 = (uVar1 & 0xcccccccc) >> 2 | (uVar1 & 0x33333333) << 2;
        uVar1 = (uVar1 & 0xf0f0f0f0) >> 4 | (uVar1 & 0xf0f0f0f) << 4;
        uVar1 = (uVar1 & 0xff00ff00) >> 8 | (uVar1 & 0xff00ff) << 8;
        lVar6 = LZCOUNT(uVar1 >> 0x10 | uVar1 << 0x10);
        thunk_EXT_FUN_80110000029486ac
                  (*(undefined8 *)(*(long *)(param_1 + 0x18) + 0x148),param_1 + 0xdc0 + lVar3 * 0x40
                   ,param_1 + 0x1040 + lVar6 * 0x40);
        thunk_EXT_FUN_80110000029486ac
                  (*(undefined8 *)(*(long *)(param_1 + 0x18) + 0x148),
                   param_1 + 0x12c0 + lVar3 * 0x40,param_1 + 0x1540 + lVar6 * 0x40);
        uVar5 = uVar5 & (1 << (ulong)((uint)lVar6 & 0x1f) ^ 0xffffffffU);
      } while (uVar5 != 0);
      uVar4 = uVar4 & (1 << (ulong)((uint)lVar3 & 0x1f) ^ 0xffffffffU);
    } while (uVar4 != 0);
  }
  lVar3 = *(long *)(param_1 + 0x18);
  if ((*(byte *)(lVar3 + 0x1ac45) & 1) == 0) {
    return;
  }
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar3 + 0x1ac48));
  thunk_EXT_FUN_80110000036da494(0x8598205c,param_2,param_3,0,0,0);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00818ad98);
    (*pcVar2)();
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar3 + 0x1ac48));
  return;
}

