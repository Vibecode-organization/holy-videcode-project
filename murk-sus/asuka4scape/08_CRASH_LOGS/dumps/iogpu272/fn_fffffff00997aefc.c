// FUN_fffffff00997aefc @ fffffff00997aefc size=132

void FUN_fffffff00997aefc(long param_1,long param_2,undefined8 param_3)

{
  code *pcVar1;
  ulong unaff_x30;
  
  FUN_fffffff00994c6ac
            (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),param_1 + 0x4d8,param_1 + 0x498);
  FUN_fffffff00997fef4(param_2,param_1 + 0x498,param_3);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00997af7c);
    (*pcVar1)();
  }
  thunk_EXT_FUN_80110000036da494
            (0x850900c8,*(undefined8 *)(param_1 + 0x550),0,*(undefined8 *)(param_2 + 0x288),param_3,
             0);
  return;
}

