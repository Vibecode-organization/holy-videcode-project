// FUN_fffffff0099805d0 @ fffffff0099805d0 size=324

long FUN_fffffff0099805d0(undefined8 param_1,ulong param_2,long param_3)

{
  uint uVar1;
  bool bVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  uint uVar6;
  ulong uVar7;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined4 local_70;
  undefined4 local_64;
  long local_60;
  ulong local_58;
  
  uVar7 = 0;
  local_60 = 0;
  uVar6 = 3;
  local_58 = param_2;
  while( true ) {
    local_64 = 9;
    local_70 = 0;
    uStack_88 = 0;
    local_90 = 0;
    uStack_78 = 0;
    uStack_80 = 0;
    if (local_60 != 0) {
      uVar7 = local_58 + local_60;
      local_60 = 0;
      local_58 = uVar7;
    }
    uVar4 = thunk_EXT_FUN_80110000032977b0(param_1);
    iVar3 = thunk_EXT_FUN_8011000003340acc(uVar4,&local_58,&local_60,9,&local_90,&local_64,0);
    if (iVar3 != 0) {
      return 0;
    }
    bVar2 = local_58 <= param_2;
    if (uVar7 != 0) {
      bVar2 = uVar7 == local_58;
    }
    if (!bVar2) break;
    uVar1 = 2;
    if (((uint)local_90 & local_90._4_4_ & 2) != 0) {
      uVar1 = uVar6;
    }
    uVar6 = uVar1;
    if (param_3 + param_2 <= local_60 + local_58) {
      lVar5 = thunk_EXT_FUN_8011000003976e84(param_2,param_3,uVar1 | 0x110000,param_1);
      if (lVar5 == 0) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                   "%s: failed to get the memory descriptor\n");
        lVar5 = 0;
      }
      return lVar5;
    }
  }
  return 0;
}

