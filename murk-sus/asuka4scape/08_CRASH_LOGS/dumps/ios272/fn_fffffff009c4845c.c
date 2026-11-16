// FUN_fffffff009c4845c @ fffffff009c4845c size=108

void FUN_fffffff009c4845c(long param_1,long param_2)

{
  code *pcVar1;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x18));
  (**(code **)(**(long **)(param_1 + 0x30) + 0xc0))
            (*(long **)(param_1 + 0x30),*(undefined8 *)(param_2 + 0x88),
             *(undefined8 *)(param_2 + 0x90));
  *(undefined8 *)(param_2 + 0x88) = 0;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c484c4);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x18));
  return;
}

