// FUN_fffffff009972d28 @ fffffff009972d28 size=256

/* WARNING: Removing unreachable block (ram,0xfffffff009972db4) */

void FUN_fffffff009972d28(long *param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  ulong unaff_x30;
  
  if (DAT_fffffff00af227e8 != 0) {
    uVar2 = thunk_EXT_FUN_801100000390ebc0(param_1);
    thunk_EXT_FUN_80110000036da494(0x8518006d,uVar2,0,0,0,0);
  }
  thunk_EXT_FUN_80110000032222a8(param_1[0x18]);
  *(undefined1 *)(param_1 + 0x19) = 0;
  thunk_EXT_FUN_8011000003222de0(param_1[0x18]);
  (**(code **)(*param_1 + 0x5c8))(*param_1 + 0x5c8,param_1);
  if (DAT_fffffff00af227e8 != 0) {
    uVar2 = thunk_EXT_FUN_801100000390ebc0(param_1);
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
      thunk_EXT_FUN_80110000036da494(0x8518006e,uVar2,0,0,0,0);
      return;
    }
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009972e14);
    (*pcVar1)();
  }
  return;
}

