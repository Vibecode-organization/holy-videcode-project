// FUN_fffffff00818af98 @ fffffff00818af98 size=380

void FUN_fffffff00818af98
               (long param_1,uint param_2,undefined8 param_3,long param_4,undefined8 param_5)

{
  long lVar1;
  uint uVar2;
  long lVar3;
  
  if (0x3ff < param_2) {
    thunk_EXT_FUN_8011000003a49114("AGXk: %s:%d:%s: !!! Out-of-range command_stage_mask 0x%x\n");
    return;
  }
  if (param_2 != 0) {
    if (param_4 == 0) {
      do {
        uVar2 = (param_2 & 0xaaaaaaaa) >> 1 | (param_2 & 0x55555555) << 1;
        uVar2 = (uVar2 & 0xcccccccc) >> 2 | (uVar2 & 0x33333333) << 2;
        uVar2 = (uVar2 & 0xf0f0f0f0) >> 4 | (uVar2 & 0xf0f0f0f) << 4;
        uVar2 = (uVar2 & 0xff00ff00) >> 8 | (uVar2 & 0xff00ff) << 8;
        lVar3 = LZCOUNT(uVar2 >> 0x10 | uVar2 << 0x10);
        lVar1 = param_1 + 0xdc0 + lVar3 * 0x40;
        thunk_EXT_FUN_80110000029486ac
                  (*(undefined8 *)(*(long *)(param_1 + 0x18) + 0x148),param_3,lVar1);
        if ((*(byte *)(*(long *)(param_1 + 0x18) + 0x1ac45) & 1) != 0) {
          FUN_fffffff0081a0304
                    (*(undefined8 *)(*(long *)(param_1 + 0x18) + 0x148),0x350,lVar1,param_5);
        }
        param_2 = param_2 & (1 << (ulong)((uint)lVar3 & 0x1f) ^ 0xffffffffU);
      } while (param_2 != 0);
    }
    else {
      do {
        uVar2 = (param_2 & 0xaaaaaaaa) >> 1 | (param_2 & 0x55555555) << 1;
        uVar2 = (uVar2 & 0xcccccccc) >> 2 | (uVar2 & 0x33333333) << 2;
        uVar2 = (uVar2 & 0xf0f0f0f0) >> 4 | (uVar2 & 0xf0f0f0f) << 4;
        uVar2 = (uVar2 & 0xff00ff00) >> 8 | (uVar2 & 0xff00ff) << 8;
        lVar3 = LZCOUNT(uVar2 >> 0x10 | uVar2 << 0x10);
        lVar1 = param_1 + 0xdc0 + lVar3 * 0x40;
        thunk_EXT_FUN_80110000029486ac
                  (*(undefined8 *)(*(long *)(param_1 + 0x18) + 0x148),param_3,lVar1);
        thunk_EXT_FUN_80110000029486ac
                  (*(undefined8 *)(*(long *)(param_1 + 0x18) + 0x148),param_4,
                   param_1 + 0x12c0 + lVar3 * 0x40);
        if ((*(byte *)(*(long *)(param_1 + 0x18) + 0x1ac45) & 1) != 0) {
          FUN_fffffff0081a0304
                    (*(undefined8 *)(*(long *)(param_1 + 0x18) + 0x148),0x350,lVar1,param_5);
        }
        param_2 = param_2 & (1 << (ulong)((uint)lVar3 & 0x1f) ^ 0xffffffffU);
      } while (param_2 != 0);
    }
  }
  return;
}

