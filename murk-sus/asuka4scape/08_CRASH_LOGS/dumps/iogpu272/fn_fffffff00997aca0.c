// FUN_fffffff00997aca0 @ fffffff00997aca0 size=8

undefined8 FUN_fffffff00997aca0(long param_1,long param_2,ulong param_3,ulong param_4)

{
  ulong uVar1;
  undefined8 uStack_38;
  
  if (param_2 == 0) {
    return 0;
  }
  uVar1 = thunk_EXT_FUN_8011000002c13500(param_2);
  if (uVar1 < param_3) {
    if ((int)param_4 == -1) {
      param_4 = (ulong)*(uint *)(*(long *)(param_1 + 0x530) + 700);
    }
    uStack_38 = 0;
    thunk_EXT_FUN_8011000003204ed8(param_4,1000000000,&uStack_38);
    uVar1 = thunk_EXT_FUN_8011000002c132ec(param_2,param_3,uStack_38);
    if ((uVar1 & 1) == 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: Post Mapping wait failed\n");
      return 0xe00002d6;
    }
  }
  return 0;
}

