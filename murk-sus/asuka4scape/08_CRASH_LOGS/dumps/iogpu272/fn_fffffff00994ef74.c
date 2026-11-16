// FUN_fffffff00994ef74 @ fffffff00994ef74 size=436

void FUN_fffffff00994ef74(void)

{
  uint uVar1;
  long *plVar2;
  ulong local_10c0;
  ulong uStack_10b8;
  undefined8 local_10b0;
  long local_10a8;
  undefined8 local_10a0;
  undefined8 uStack_1098;
  undefined8 uStack_1090;
  undefined8 uStack_1088;
  long local_1080;
  undefined1 auStack_1078 [4096];
  undefined4 local_78;
  uint local_74;
  long local_70;
  long local_68;
  long local_60;
  long lStack_58;
  ulong local_50;
  ulong uStack_48;
  ulong local_40;
  ulong uStack_38;
  ulong local_30;
  long local_28;
  
  plVar2 = (long *)(*DAT_fffffff007ff2840)();
  local_28 = *(long *)PTR_DAT_fffffff007ff2800;
  local_70 = 0;
  local_68 = 0;
  (**(code **)(*plVar2 + 0x98))(plVar2,&local_68,&local_70);
  if (local_70 == 0) {
    local_68 = plVar2[4];
    local_70 = plVar2[5];
  }
  uStack_1098 = 0;
  local_10a0 = 0;
  uStack_1088 = 0;
  uStack_1090 = 0;
  local_10b0 = DAT_fffffff007835cc8;
  uVar1 = *(int *)((long)plVar2 + 0xcc) + (int)plVar2[0x1a];
  if (uVar1 == 0) {
    local_74 = 0;
  }
  else {
    local_74 = 0;
    if (uVar1 != 0) {
      local_74 = (uint)(*(int *)((long)plVar2 + 0xcc) * 100) / uVar1;
    }
  }
  local_10a8 = local_70;
  local_1080 = local_68;
  thunk_EXT_FUN_8011000003a61b10(auStack_1078,plVar2[0x1f],0x1000);
  local_78 = (undefined4)plVar2[0x20];
  if ((*(byte *)((long)plVar2 + 0x104) & 1) != 0) {
    if (plVar2[0x1e] != 0) {
      FUN_fffffff009975758(plVar2[2],plVar2[0x1e],&local_10b0,1);
    }
    *(undefined1 *)((long)plVar2 + 0x104) = 0;
    plVar2[0x1e] = 0;
  }
  if (*(long *)(plVar2[0x1d] + 0x50) == 0) {
    local_10c0 = 0;
    uStack_10b8 = 0;
    thunk_EXT_FUN_8011000003398228(local_68,&uStack_10b8);
    thunk_EXT_FUN_8011000003398228(local_70,&local_10c0);
    lStack_58 = plVar2[0x1c];
    local_60 = plVar2[0x1b];
    uStack_48 = uStack_10b8 >> 0x20;
    local_50 = uStack_10b8;
    uStack_38 = local_10c0 >> 0x20;
    local_40 = local_10c0;
    local_30 = (ulong)*(uint *)(plVar2 + 0x19);
    thunk_EXT_FUN_80110000039a40ec(plVar2[0x1d] + 0x10,0,&local_60,7);
  }
  else {
    FUN_fffffff00994f180
              (*(long *)(plVar2[0x1d] + 0x50),plVar2[0x1b],local_68,local_70,(int)plVar2[0x19],
               plVar2[0x21]);
  }
  if (*(long *)PTR_DAT_fffffff007ff2800 != local_28) {
    thunk_EXT_FUN_8011000003a48590();
    return;
  }
  return;
}

