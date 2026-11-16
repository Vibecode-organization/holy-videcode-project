// FUN_fffffff00997a084 @ fffffff00997a084 size=420

void FUN_fffffff00997a084(long param_1,long param_2)

{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 uStack_40;
  undefined8 uStack_38;
  long local_28;
  
  local_28 = *(long *)PTR_DAT_fffffff007ff2800;
  iVar2 = *(int *)(param_2 + 200);
  if (iVar2 - 2U < 2 || iVar2 == 0xb) {
    iVar2 = *(int *)(param_1 + 0x440) + 1;
    *(int *)(param_1 + 0x440) = iVar2;
    if (iVar2 == 2) {
      uStack_48 = 0;
      local_50 = 0;
      uStack_38 = 0;
      uStack_40 = 0;
      uStack_68 = 0;
      local_70 = 0;
      uStack_58 = 0;
      uStack_60 = 0;
      uStack_88 = 0;
      local_90 = 0;
      uStack_78 = 0;
      uStack_80 = 0;
      uStack_a8 = 0;
      local_b0 = 0;
      uStack_98 = 0;
      uStack_a0 = 0;
      thunk_EXT_FUN_8011000003722d80(*(undefined4 *)(param_1 + 0x490),&local_b0,0x80);
      if ((*(long *)(param_1 + 0x488) == 0) || (uVar3 = FUN_fffffff0099658a8(), (uVar3 & 1) == 0)) {
        *(undefined1 *)(param_1 + 0x43a) = 1;
      }
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s: %s app[%s] with %d GPURestarts in %d submissions.\n");
    }
  }
  else if ((((iVar2 == 0) &&
            (uVar1 = *(int *)(param_1 + 0x43c) + 1, *(uint *)(param_1 + 0x43c) = uVar1, 1000 < uVar1
            )) && ((*(byte *)(param_1 + 0x43a) & 1) == 0)) &&
          (*(undefined4 *)(param_1 + 0x43c) = 0, *(int *)(param_1 + 0x440) != 0)) {
    uStack_48 = 0;
    local_50 = 0;
    uStack_38 = 0;
    uStack_40 = 0;
    uStack_68 = 0;
    local_70 = 0;
    uStack_58 = 0;
    uStack_60 = 0;
    uStack_88 = 0;
    local_90 = 0;
    uStack_78 = 0;
    uStack_80 = 0;
    uStack_a8 = 0;
    local_b0 = 0;
    uStack_98 = 0;
    uStack_a0 = 0;
    thunk_EXT_FUN_8011000003722d80(*(undefined4 *)(param_1 + 0x490),&local_b0,0x80);
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
               "%s: Clean slate for app[%s] with %d GPURestarts in %d submissions.\n");
    *(undefined4 *)(param_1 + 0x440) = 0;
  }
  if (*(long *)PTR_DAT_fffffff007ff2800 == local_28) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590();
  return;
}

