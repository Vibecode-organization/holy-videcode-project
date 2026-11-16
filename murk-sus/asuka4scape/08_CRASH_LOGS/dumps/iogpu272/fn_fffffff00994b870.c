// FUN_fffffff00994b870 @ fffffff00994b870 size=392

int FUN_fffffff00994b870(long param_1,uint *param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  long lVar7;
  long local_78;
  long local_70;
  undefined8 local_68;
  
  uVar5 = *param_2;
  uVar6 = uVar5 | 0x8000;
  uVar5 = (uVar5 & 0xaaaaaaaa | 0x8000) >> 1 | (uVar5 & 0x55555555) << 1;
  uVar5 = (uVar5 & 0xcccccccc) >> 2 | (uVar5 & 0x33333333) << 2;
  uVar5 = (uVar5 & 0xf0f0f0f0) >> 4 | (uVar5 & 0xf0f0f0f) << 4;
  uVar5 = (uVar5 & 0xff00ff00) >> 8 | (uVar5 & 0xff00ff) << 8;
  lVar7 = LZCOUNT(uVar5 >> 0x10 | uVar5 << 0x10);
  if ((int)lVar7 == 0xf) {
    iVar4 = 0;
  }
  else {
    iVar4 = 0;
    do {
      uVar5 = param_2[lVar7 + 1];
      if ((uVar5 & 0xff) != 0xff) {
        iVar1 = (int)(char)uVar5;
        uVar5 = uVar5 & 0xffffff00;
        if (0 < (int)(uVar5 - **(int **)(*(long *)(param_1 + 0x20) + (long)iVar1 * 8))) {
          local_70 = 0;
          local_68 = 0;
          local_78 = 0;
          thunk_EXT_FUN_8011000003205048(&local_70);
          uVar2 = thunk_EXT_FUN_801100000390ebc0(*(undefined8 *)(param_1 + 0x10));
          thunk_EXT_FUN_80110000036da494(0x85090055,(long)iVar1,uVar5,uVar2,0,0);
          FUN_fffffff00994abdc(param_1,iVar1,uVar5);
          uVar2 = thunk_EXT_FUN_801100000390ebc0(*(undefined8 *)(param_1 + 0x10));
          thunk_EXT_FUN_80110000036da494(0x85090056,(long)iVar1,uVar5,uVar2,0,0);
          thunk_EXT_FUN_8011000003205048(&local_78);
          local_78 = local_78 - local_70;
          thunk_EXT_FUN_8011000003398228(local_78,&local_68);
          iVar4 = iVar4 + (int)local_68;
        }
      }
      uVar6 = 1 << (ulong)((uint)lVar7 & 0x1f) ^ uVar6;
      uVar5 = (uVar6 & 0xaaaaaaaa) >> 1 | (uVar6 & 0x55555555) << 1;
      uVar5 = (uVar5 & 0xcccccccc) >> 2 | (uVar5 & 0x33333333) << 2;
      uVar5 = (uVar5 & 0xf0f0f0f0) >> 4 | (uVar5 & 0xf0f0f0f) << 4;
      uVar5 = (uVar5 & 0xff00ff00) >> 8 | (uVar5 & 0xff00ff) << 8;
      lVar7 = LZCOUNT(uVar5 >> 0x10 | uVar5 << 0x10);
    } while ((uint)lVar7 < 0xf);
  }
  lVar7 = 0;
  *param_2 = 0;
  lVar3 = 0xf;
  do {
    param_2[lVar7 + 1] = 0xff;
    lVar7 = lVar7 + 1;
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  return iVar4;
}

