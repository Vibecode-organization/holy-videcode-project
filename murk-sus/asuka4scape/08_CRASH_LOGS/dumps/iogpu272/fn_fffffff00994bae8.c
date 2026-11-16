// FUN_fffffff00994bae8 @ fffffff00994bae8 size=4

int FUN_fffffff00994bae8(long param_1,uint *param_2,int param_3)

{
  int iVar1;
  undefined8 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  long lVar6;
  long lStack_78;
  long lStack_70;
  undefined8 uStack_68;
  
  uVar4 = *param_2;
  uVar5 = uVar4 | 0x8000;
  uVar4 = (uVar4 & 0xaaaaaaaa | 0x8000) >> 1 | (uVar4 & 0x55555555) << 1;
  uVar4 = (uVar4 & 0xcccccccc) >> 2 | (uVar4 & 0x33333333) << 2;
  uVar4 = (uVar4 & 0xf0f0f0f0) >> 4 | (uVar4 & 0xf0f0f0f) << 4;
  uVar4 = (uVar4 & 0xff00ff00) >> 8 | (uVar4 & 0xff00ff) << 8;
  lVar6 = LZCOUNT(uVar4 >> 0x10 | uVar4 << 0x10);
  if ((int)lVar6 == 0xf) {
    iVar3 = 0;
  }
  else {
    iVar3 = 0;
    do {
      uVar4 = param_2[lVar6 + 1];
      iVar1 = (int)(char)uVar4;
      if (((uVar4 & 0xff) != 0xff && iVar1 != param_3) &&
         (uVar4 = uVar4 & 0xffffff00,
         0 < (int)(uVar4 - **(int **)(*(long *)(param_1 + 0x20) + (long)iVar1 * 8)))) {
        lStack_70 = 0;
        uStack_68 = 0;
        lStack_78 = 0;
        thunk_EXT_FUN_8011000003205048(&lStack_70);
        uVar2 = thunk_EXT_FUN_801100000390ebc0(*(undefined8 *)(param_1 + 0x10));
        thunk_EXT_FUN_80110000036da494(0x85090055,(long)iVar1,uVar4,uVar2,0,0);
        FUN_fffffff00994abdc(param_1,iVar1,uVar4);
        uVar2 = thunk_EXT_FUN_801100000390ebc0(*(undefined8 *)(param_1 + 0x10));
        thunk_EXT_FUN_80110000036da494(0x85090056,(long)iVar1,uVar4,uVar2,0,0);
        thunk_EXT_FUN_8011000003205048(&lStack_78);
        lStack_78 = lStack_78 - lStack_70;
        thunk_EXT_FUN_8011000003398228(lStack_78,&uStack_68);
        iVar3 = iVar3 + (int)uStack_68;
      }
      uVar5 = 1 << (ulong)((uint)lVar6 & 0x1f) ^ uVar5;
      uVar4 = (uVar5 & 0xaaaaaaaa) >> 1 | (uVar5 & 0x55555555) << 1;
      uVar4 = (uVar4 & 0xcccccccc) >> 2 | (uVar4 & 0x33333333) << 2;
      uVar4 = (uVar4 & 0xf0f0f0f0) >> 4 | (uVar4 & 0xf0f0f0f) << 4;
      uVar4 = (uVar4 & 0xff00ff00) >> 8 | (uVar4 & 0xff00ff) << 8;
      lVar6 = LZCOUNT(uVar4 >> 0x10 | uVar4 << 0x10);
    } while ((uint)lVar6 < 0xf);
  }
  return iVar3;
}

