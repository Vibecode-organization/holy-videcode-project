// FUN_fffffff008165384 @ fffffff008165384 size=124

void FUN_fffffff008165384(long param_1)

{
  code *pcVar1;
  long lVar2;
  ulong unaff_x30;
  
  thunk_EXT_FUN_8011000002947a48(*(undefined8 *)(*(long *)(param_1 + 0x10) + 0x148),param_1 + 0x118)
  ;
  if (*(long *)(param_1 + 0x80) == 0) {
    return;
  }
  lVar2 = *(long *)(*(long *)(param_1 + 0x80) + 0x50);
  thunk_EXT_FUN_80110000038ff214(*(undefined8 *)(lVar2 + 0x10));
  FUN_fffffff0081d40e8(lVar2,&DAT_fffffff007c97680,0);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081653f0);
    (*pcVar1)();
  }
  thunk_EXT_FUN_80110000038ff2e0(*(undefined8 *)(lVar2 + 0x10));
  return;
}

