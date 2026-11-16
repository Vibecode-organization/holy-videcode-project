// FUN_fffffff00997aab8 @ fffffff00997aab8 size=4

void FUN_fffffff00997aab8(long param_1,undefined8 param_2,ulong param_3,ulong param_4)

{
  ulong uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uStack_48;
  
  uVar1 = thunk_EXT_FUN_8011000002c13500(param_2);
  if (uVar1 < param_3) {
    if ((int)param_4 == -1) {
      param_4 = (ulong)*(uint *)(*(long *)(param_1 + 0x530) + 700);
    }
    uStack_48 = 0;
    thunk_EXT_FUN_8011000003204ed8(param_4,1000000000,&uStack_48);
    uVar3 = *(undefined8 *)(param_1 + 0x550);
    uVar2 = thunk_EXT_FUN_8011000002c134f4(param_2);
    thunk_EXT_FUN_80110000036da494(0x850900d5,uVar3,0,uVar2,param_3,0);
    uVar1 = thunk_EXT_FUN_8011000002c132ec(param_2,param_3,uStack_48);
    if ((uVar1 & 1) == 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s: Shared event wait timed out for value : %llx\n");
      *(undefined4 *)(param_1 + 0x520) = 2;
      if ((*(byte *)(*(long *)(param_1 + 0x530) + 0x1ff) >> 3 & 1) != 0) {
        thunk_EXT_FUN_8011000003a49114
                  (
                  "\"Timeout SharedEvent: %s: Shared event wait timed out for value : %llx\" @%s:%d"
                  );
        return;
      }
    }
    uVar3 = *(undefined8 *)(param_1 + 0x550);
    uVar2 = thunk_EXT_FUN_8011000002c134f4(param_2);
    thunk_EXT_FUN_80110000036da494(0x850900d6,uVar3,0,uVar2,param_3,0);
  }
  return;
}

