// FUN_fffffff009c20114 @ fffffff009c20114 size=176

void FUN_fffffff009c20114(undefined8 param_1,undefined8 param_2,undefined1 *param_3)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 *local_30;
  long local_28;
  
  local_28 = *(long *)PTR_DAT_fffffff00806ca40;
  local_30 = &DAT_aaaaaaaaaaaaaaaa;
  iVar1 = FUN_fffffff009c20038(param_1,param_2,&local_30);
  if (iVar1 != 0) {
    if ((undefined1 *)0xff < local_30) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,"IOSurface: %s exceeds maximum value\n")
      ;
      uVar2 = 0;
      goto LAB_fffffff009c20198;
    }
    *param_3 = (char)local_30;
  }
  uVar2 = 1;
LAB_fffffff009c20198:
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_28) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590(uVar2);
  return;
}

