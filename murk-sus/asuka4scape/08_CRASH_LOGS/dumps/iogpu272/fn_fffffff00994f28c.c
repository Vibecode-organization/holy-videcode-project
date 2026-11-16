// FUN_fffffff00994f28c @ fffffff00994f28c size=300

bool FUN_fffffff00994f28c(void)

{
  uint uVar1;
  long *plVar2;
  long lVar3;
  undefined1 auVar4 [16];
  undefined8 local_1080;
  long local_1078;
  undefined8 local_1070;
  undefined8 uStack_1068;
  undefined8 uStack_1060;
  undefined8 uStack_1058;
  long local_1050;
  undefined1 auStack_1048 [4096];
  undefined4 local_48;
  uint local_44;
  long local_40;
  long local_38;
  
  auVar4 = (*DAT_fffffff007ff2840)();
  plVar2 = auVar4._0_8_;
  lVar3 = plVar2[0x1e];
  if (auVar4._8_8_ == lVar3) {
    local_40 = 0;
    local_38 = 0;
    (**(code **)(*plVar2 + 0x98))(plVar2,&local_38,&local_40);
    if (local_40 == 0) {
      local_38 = plVar2[4];
      local_40 = plVar2[5];
    }
    uStack_1068 = 0;
    local_1070 = 0;
    uStack_1058 = 0;
    uStack_1060 = 0;
    local_1080 = DAT_fffffff007835cc8;
    local_1078 = local_40;
    local_1050 = local_38;
    thunk_EXT_FUN_8011000003a61b10(auStack_1048,plVar2[0x1f],0x1000);
    local_48 = (undefined4)plVar2[0x20];
    uVar1 = *(int *)((long)plVar2 + 0xcc) + (int)plVar2[0x1a];
    if (uVar1 == 0) {
      local_44 = 0;
    }
    else {
      local_44 = 0;
      if (uVar1 != 0) {
        local_44 = (uint)(*(int *)((long)plVar2 + 0xcc) * 100) / uVar1;
      }
    }
    if ((*(byte *)((long)plVar2 + 0x104) & 1) != 0) {
      if (plVar2[0x1e] != 0) {
        FUN_fffffff009975758(plVar2[2],plVar2[0x1e],&local_1080,1);
      }
      *(undefined1 *)((long)plVar2 + 0x104) = 0;
      plVar2[0x1e] = 0;
    }
  }
  return auVar4._8_8_ == lVar3;
}

