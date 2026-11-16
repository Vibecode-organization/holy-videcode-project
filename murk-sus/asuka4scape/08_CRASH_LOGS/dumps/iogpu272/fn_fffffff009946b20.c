// FUN_fffffff009946b20 @ fffffff009946b20 size=40

void FUN_fffffff009946b20(undefined8 param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  undefined8 uStack0000000000000000;
  char *pcStack0000000000000008;
  
  pcStack0000000000000008 = "IOGPUMemoryDecriptor.cpp";
  uStack0000000000000000 = param_1;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009946b44);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003a49114("\"gpu_refcnt: overflow (rc=%p)\\n\" @%s:%d");
  return;
}

