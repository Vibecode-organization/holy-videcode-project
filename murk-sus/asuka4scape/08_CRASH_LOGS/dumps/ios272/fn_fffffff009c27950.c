// FUN_fffffff009c27950 @ fffffff009c27950 size=4

void FUN_fffffff009c27950(long param_1)

{
  code *pcVar1;
  long lVar2;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x50));
  for (lVar2 = *(long *)(param_1 + 0x240); lVar2 != 0; lVar2 = *(long *)(lVar2 + 0x58)) {
    thunk_EXT_FUN_801100000322ffdc("\tcurrent: %p t: %p\n");
  }
  for (lVar2 = *(long *)(param_1 + 0x250); lVar2 != 0; lVar2 = *(long *)(lVar2 + 0x58)) {
    thunk_EXT_FUN_801100000322ffdc("\twaitQ:   %p t: %p\n");
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c279ec);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x50));
  return;
}

