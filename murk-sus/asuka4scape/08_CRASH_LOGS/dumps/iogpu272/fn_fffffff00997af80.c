// FUN_fffffff00997af80 @ fffffff00997af80 size=280

void FUN_fffffff00997af80(long param_1,undefined8 param_2,undefined8 param_3,ulong param_4)

{
  ulong uVar1;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  
  if ((int)param_4 == -1) {
    param_4 = (ulong)*(uint *)(*(long *)(param_1 + 0x530) + 700);
  }
  uStack_58 = 0;
  local_60 = 0;
  uStack_48 = 0;
  uStack_50 = 0;
  uStack_78 = 0;
  local_80 = 0;
  uStack_68 = 0;
  uStack_70 = 0;
  FUN_fffffff00994af14(&local_80);
  local_88 = 0;
  thunk_EXT_FUN_8011000003204ed8(param_4,1000000000,&local_88);
  uVar1 = FUN_fffffff00997ffc8
                    (param_2,param_3,&local_80,local_88,*(undefined8 *)(param_1 + 0x550),0);
  if ((uVar1 & 1) == 0) {
    *(undefined4 *)(param_1 + 0x520) = 2;
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
               "Timeout MTLEvent: waiting for signal (%llu) for event (%u) to be scheduled\n");
    if ((*(byte *)(*(long *)(param_1 + 0x530) + 0x1ff) >> 3 & 1) != 0) {
      thunk_EXT_FUN_8011000003a49114
                (
                "\"Timeout MTLEvent: waiting for signal (%llu) for event (%u) to be scheduled\" @%s:%d"
                );
      return;
    }
  }
  else {
    FUN_fffffff00994c6ac
              (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),&local_80,param_1 + 0x4d8);
  }
  return;
}

