// FUN_fffffff00818add4 @ fffffff00818add4 size=452

void FUN_fffffff00818add4
               (long param_1,uint param_2,undefined8 param_3,long param_4,undefined8 param_5)

{
  uint uVar1;
  long lVar2;
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
  
  if (param_2 < 0x400) {
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
    thunk_EXT_FUN_8011000002946f14(&local_a0);
    thunk_EXT_FUN_8011000002946f14(&local_e0);
    lVar2 = *(long *)(param_1 + 0x18);
    if ((*(byte *)(lVar2 + 0x1ac44) >> 3 & 1) != 0) {
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar2 + 0x1ac48));
      thunk_EXT_FUN_80110000036da494(0x85930d7c,param_2,param_5,0,0,0);
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar2 + 0x1ac48));
    }
    if (param_2 != 0) {
      do {
        uVar1 = (param_2 & 0xaaaaaaaa) >> 1 | (param_2 & 0x55555555) << 1;
        uVar1 = (uVar1 & 0xcccccccc) >> 2 | (uVar1 & 0x33333333) << 2;
        uVar1 = (uVar1 & 0xf0f0f0f0) >> 4 | (uVar1 & 0xf0f0f0f) << 4;
        uVar1 = (uVar1 & 0xff00ff00) >> 8 | (uVar1 & 0xff00ff) << 8;
        lVar2 = LZCOUNT(uVar1 >> 0x10 | uVar1 << 0x10);
        thunk_EXT_FUN_80110000029486ac
                  (*(undefined8 *)(*(long *)(param_1 + 0x18) + 0x148),
                   param_1 + 0x1040 + lVar2 * 0x40,&local_a0);
        thunk_EXT_FUN_80110000029486ac
                  (*(undefined8 *)(*(long *)(param_1 + 0x18) + 0x148),
                   param_1 + 0x1540 + lVar2 * 0x40,&local_e0);
        param_2 = param_2 & (1 << (ulong)((uint)lVar2 & 0x1f) ^ 0xffffffffU);
      } while (param_2 != 0);
    }
    thunk_EXT_FUN_80110000029486ac
              (*(undefined8 *)(*(long *)(param_1 + 0x18) + 0x148),&local_a0,param_3);
    if ((*(byte *)(*(long *)(param_1 + 0x18) + 0x1ac45) & 1) != 0) {
      FUN_fffffff0081a0304
                (*(undefined8 *)(*(long *)(param_1 + 0x18) + 0x148),0x815,&local_a0,param_5);
    }
    if (param_4 != 0) {
      thunk_EXT_FUN_80110000029486ac
                (*(undefined8 *)(*(long *)(param_1 + 0x18) + 0x148),&local_e0,param_4);
      if ((*(byte *)(*(long *)(param_1 + 0x18) + 0x1ac45) & 1) != 0) {
        FUN_fffffff0081a0304
                  (*(undefined8 *)(*(long *)(param_1 + 0x18) + 0x148),0x816,&local_e0,param_5);
      }
    }
    return;
  }
  thunk_EXT_FUN_8011000003a49114("AGXk: %s:%d:%s: !!! Out-of-range command_stage_mask 0x%x\n");
  return;
}

