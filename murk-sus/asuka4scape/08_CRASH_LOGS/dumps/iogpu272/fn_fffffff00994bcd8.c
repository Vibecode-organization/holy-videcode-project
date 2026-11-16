// FUN_fffffff00994bcd8 @ fffffff00994bcd8 size=632

undefined8 FUN_fffffff00994bcd8(long param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  uint uVar4;
  long lVar5;
  undefined8 local_148;
  undefined8 local_140 [16];
  uint local_c0 [18];
  long local_78;
  
  local_78 = *(long *)PTR_DAT_fffffff007ff2800;
  if (*(int *)(*(long *)(param_1 + 0x10) + 0x2d0) == 0) {
    local_c0[0xd] = 0;
    local_c0[0xe] = 0;
    local_c0[0xc] = 0;
    local_c0[6] = 0;
    local_c0[7] = 0;
    local_c0[4] = 0;
    local_c0[5] = 0;
    local_c0[10] = 0;
    local_c0[0xb] = 0;
    local_c0[8] = 0;
    local_c0[9] = 0;
    local_c0[2] = 0;
    local_c0[3] = 0;
    local_c0[0] = 0;
    local_c0[1] = 0;
    local_140[1] = 0;
    local_140[0] = 0;
    local_140[3] = 0;
    local_140[2] = 0;
    local_140[5] = 0;
    local_140[4] = 0;
    local_140[7] = 0;
    local_140[6] = 0;
    local_140[9] = 0;
    local_140[8] = 0;
    local_140[0xb] = 0;
    local_140[10] = 0;
    local_140[0xd] = 0;
    local_140[0xc] = 0;
    local_140[0xe] = 0;
    uVar3 = thunk_EXT_FUN_801100000390ebc0();
    thunk_EXT_FUN_80110000036da494(0x85090055,0xffffffffffffffff,0xffffffffffffffff,uVar3,0,0);
    uVar4 = (~*param_2 & 0xaaaaaaaa) >> 1 | (~*param_2 & 0x55555555) << 1;
    uVar4 = (uVar4 & 0xcccccccc) >> 2 | (uVar4 & 0x33333333) << 2;
    uVar4 = (uVar4 & 0xf0f0f0f0) >> 4 | (uVar4 & 0xf0f0f0f) << 4;
    uVar4 = (uVar4 & 0xff00ff00) >> 8 | (uVar4 & 0xff00ff) << 8;
    uVar4 = (uint)LZCOUNT(uVar4 >> 0x10 | uVar4 << 0x10);
    if (uVar4 < 0xf) {
      *param_3 = uVar4;
    }
    else {
      lVar5 = 0;
      do {
        uVar1 = param_2[lVar5 + 1] << 0x18;
        uVar4 = param_2[lVar5 + 1] & 0xffffff00;
        local_c0[lVar5] = uVar4;
        if (uVar1 == 0xff000000) {
          *param_3 = (uint)lVar5;
          goto LAB_fffffff00994bf08;
        }
        local_140[lVar5] =
             *(undefined8 *)(*(long *)(param_1 + 0x20) + (long)((int)uVar1 >> 0x18) * 8);
        if (0 < (int)(uVar4 - *(int *)(param_1 + 0x40 +
                                      (((long)((ulong)uVar1 << 0x20) >> 0x38) << 4 | 0xcU)))) {
          FUN_fffffff0099616bc(*(undefined8 *)(*(long *)(param_1 + 0x10) + 0x160),5);
        }
        lVar5 = lVar5 + 1;
      } while (lVar5 != 0xf);
      lVar5 = 0;
      while ((0 < (int)(local_c0[lVar5] - *(int *)local_140[lVar5]) &&
             (*(int *)(*(long *)(param_1 + 0x10) + 0x2d0) == 0))) {
        lVar5 = lVar5 + 1;
        if (lVar5 == 0xf) {
          local_148 = 0;
          thunk_EXT_FUN_8011000003204ed8(1,1000000000,&local_148);
          iVar2 = thunk_EXT_FUN_8011000003243438(param_1,0,local_148);
          lVar5 = 0;
          do {
            if (((int)(local_c0[lVar5] - *(int *)local_140[lVar5]) < 1) ||
               (*(int *)(*(long *)(param_1 + 0x10) + 0x2d0) != 0)) {
              *param_3 = (uint)lVar5;
              thunk_EXT_FUN_8011000003246024(param_1,0,0);
              goto LAB_fffffff00994bee4;
            }
            lVar5 = lVar5 + 1;
          } while (lVar5 != 0xf);
          if (iVar2 == -1) {
            thunk_EXT_FUN_8011000003247bfc(0);
          }
          lVar5 = 0;
        }
      }
      *param_3 = (uint)lVar5;
LAB_fffffff00994bee4:
      uVar3 = thunk_EXT_FUN_801100000390ebc0(*(undefined8 *)(param_1 + 0x10));
      thunk_EXT_FUN_80110000036da494(0x85090056,0xffffffffffffffff,0xffffffffffffffff,uVar3,0,0);
    }
  }
  else {
    *param_3 = 0;
  }
LAB_fffffff00994bf08:
  if (*(long *)PTR_DAT_fffffff007ff2800 == local_78) {
    return 0;
  }
  uVar3 = thunk_EXT_FUN_8011000003a48590();
  return uVar3;
}

