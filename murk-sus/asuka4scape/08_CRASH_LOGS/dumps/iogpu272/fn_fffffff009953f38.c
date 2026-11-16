// FUN_fffffff009953f38 @ fffffff009953f38 size=152

void FUN_fffffff009953f38(long param_1,long param_2)

{
  code *pcVar1;
  long *plVar2;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x60));
  if ((*(byte *)(param_1 + 0x10) & 0x7f) == 0) {
    FUN_fffffff00994c49c
              (*(undefined8 *)(*(long *)(param_1 + 0x50) + 0x148),*(undefined8 *)(param_1 + 0x18),
               *(undefined8 *)(param_2 + 0x18));
    FUN_fffffff00994c49c
              (*(undefined8 *)(*(long *)(param_1 + 0x50) + 0x148),*(long *)(param_1 + 0x18) + 0x40,
               *(long *)(param_2 + 0x18) + 0x40);
  }
  *(undefined8 *)(param_2 + 0x38) = 0;
  plVar2 = *(long **)(param_1 + 0x40);
  *(long **)(param_2 + 0x40) = plVar2;
  *plVar2 = param_2;
  *(undefined8 **)(param_1 + 0x40) = (undefined8 *)(param_2 + 0x38);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009953fcc);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x60));
  return;
}

