// FUN_fffffff008199814 @ fffffff008199814 size=228

undefined8 FUN_fffffff008199814(long param_1,undefined8 *param_2,long param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  long lVar5;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  
  if ((*(byte *)(param_2 + 8) & 1) == 0) {
    return 0;
  }
  iVar1 = *(int *)(param_3 + 0x18);
  uStack_88 = param_2[1];
  local_90 = *param_2;
  uStack_78 = param_2[3];
  uStack_80 = param_2[2];
  uStack_68 = param_2[5];
  local_70 = param_2[4];
  uStack_58 = param_2[7];
  uStack_60 = param_2[6];
  uVar4 = (uint)local_90 | 0x8000;
  uVar2 = ((uint)local_90 & 0xaaaaaaaa | 0x8000) >> 1 | ((uint)local_90 & 0x55555555) << 1;
  uVar2 = (uVar2 & 0xcccccccc) >> 2 | (uVar2 & 0x33333333) << 2;
  uVar2 = (uVar2 & 0xf0f0f0f0) >> 4 | (uVar2 & 0xf0f0f0f) << 4;
  uVar2 = (uVar2 & 0xff00ff00) >> 8 | (uVar2 & 0xff00ff) << 8;
  lVar5 = LZCOUNT(uVar2 >> 0x10 | uVar2 << 0x10);
  if ((int)lVar5 != 0xf) {
    do {
      uVar2 = *(uint *)(((ulong)&local_90 | 4) + lVar5 * 4);
      if ((iVar1 == (char)uVar2) &&
         (iVar3 = thunk_EXT_FUN_8011000002947220
                            (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),iVar1),
         (uVar2 & 0xffffff00) == iVar3 - 0x100U)) {
        return 1;
      }
      uVar4 = 1 << (ulong)((uint)lVar5 & 0x1f) ^ uVar4;
      uVar2 = (uVar4 & 0xaaaaaaaa) >> 1 | (uVar4 & 0x55555555) << 1;
      uVar2 = (uVar2 & 0xcccccccc) >> 2 | (uVar2 & 0x33333333) << 2;
      uVar2 = (uVar2 & 0xf0f0f0f0) >> 4 | (uVar2 & 0xf0f0f0f) << 4;
      uVar2 = (uVar2 & 0xff00ff00) >> 8 | (uVar2 & 0xff00ff) << 8;
      lVar5 = LZCOUNT(uVar2 >> 0x10 | uVar2 << 0x10);
    } while ((uint)lVar5 < 0xf);
  }
  return 0;
}

