// FUN_fffffff009977304 @ fffffff009977304 size=296

undefined8 FUN_fffffff009977304(long param_1,uint param_2,uint param_3,uint *param_4)

{
  undefined8 uVar1;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  long local_48;
  
  local_48 = *(long *)PTR_DAT_fffffff007ff2800;
  uVar1 = 0xe00002c2;
  if ((2 < param_2) && (param_2 != 4)) {
    if (param_2 != 5) goto LAB_fffffff0099773f4;
    if ((*(byte *)(*(long *)(param_1 + 0x488) + 0x118) & 1) == 0) {
      uStack_68 = 0;
      local_70 = 0;
      uStack_58 = 0;
      uStack_60 = 0;
      thunk_EXT_FUN_8011000003722d80(*(undefined4 *)(param_1 + 0x490),&local_70,0x20);
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "Process %s (%d) does not have the entitlement to use MTLGPUPriorityRealTime, using MTLGPUPriorityHigh instead\n"
                );
      param_2 = 0;
    }
    else {
      param_2 = 5;
    }
  }
  if ((param_3 & 0xfffffffe) == 2) {
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x458));
    *(uint *)(param_1 + 0x444) = param_2;
    *(uint *)(param_1 + 0x448) = param_3;
    *param_4 = param_2;
    FUN_fffffff009976f64(param_1);
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x458));
    uVar1 = 0;
  }
LAB_fffffff0099773f4:
  if (*(long *)PTR_DAT_fffffff007ff2800 == local_48) {
    return uVar1;
  }
  uVar1 = thunk_EXT_FUN_8011000003a48590();
  return uVar1;
}

