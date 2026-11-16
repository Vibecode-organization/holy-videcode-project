// FUN_fffffff00994396c @ fffffff00994396c size=296

long FUN_fffffff00994396c(long *param_1)

{
  uint *puVar1;
  uint uVar2;
  long lVar3;
  long in_xzr;
  
  thunk_EXT_FUN_80110000032222a8(param_1[9]);
  uVar2 = *(uint *)((long)param_1 + 0x24);
  if (uVar2 < 4) {
    if (uVar2 != 0) {
      puVar1 = (uint *)((long)param_1 + 0x24);
      if (*puVar1 != uVar2) goto LAB_fffffff009943a44;
      *puVar1 = 2;
      FUN_fffffff0099438ec(param_1,param_1[5]);
      (**(code **)(*param_1 + 0xd0))(param_1);
      param_1[8] = 0;
      param_1[5] = in_xzr;
      LORelease();
      *puVar1 = *puVar1 & 0xfffffffd;
      LORelease();
    }
    *(uint *)(param_1 + 6) = *(uint *)(param_1 + 6) | 0x10;
    if (3 < *(uint *)((long)param_1 + 0x24)) {
      lVar3 = FUN_fffffff0099833f4();
      *(uint *)(lVar3 + 0x30) = *(uint *)(lVar3 + 0x30) & 0xffffffef;
      return lVar3;
    }
    lVar3 = 0;
  }
  else {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: Resource still busy\n");
LAB_fffffff009943a44:
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: Failed to evict for detach\n");
    lVar3 = 0xe00002d5;
  }
  thunk_EXT_FUN_8011000003222de0(param_1[9]);
  return lVar3;
}

