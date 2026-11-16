// FUN_fffffff009aa0ff8 @ fffffff009aa0ff8 size=72
// CALLERS:
//   fffffff00afb816c no-fn
// CALLEES:
//   fffffff009abd42c thunk_EXT_FUN_80110000039a3888
//   fffffff009abd21c thunk_EXT_FUN_8011000003894430

void FUN_fffffff009aa0ff8(undefined8 param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000039a3888();
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009aa103c);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003894430(&DAT_fffffff0080299e0,param_1,0x958);
  return;
}

