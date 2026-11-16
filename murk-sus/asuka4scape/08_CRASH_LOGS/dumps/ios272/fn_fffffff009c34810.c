// FUN_fffffff009c34810 @ fffffff009c34810 size=136

/* WARNING: Removing unreachable block (ram,0xfffffff009c34860) */

void FUN_fffffff009c34810(long param_1,long param_2)

{
  code *pcVar1;
  long lVar2;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x140));
  for (lVar2 = *(long *)(param_1 + 0x90); lVar2 != 0; lVar2 = *(long *)(lVar2 + 0x18)) {
    if (*(long *)(lVar2 + 0x170) == param_2) {
      *(undefined8 *)(lVar2 + 0x170) = 0;
    }
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c34894);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x140));
  return;
}

