// FUN_fffffff00996e2f8 @ fffffff00996e2f8 size=124

void FUN_fffffff00996e2f8(long param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  ulong unaff_x30;
  
  if ((DAT_fffffff00af227e8 != 0) && (*(long *)(param_1 + 0x60) != 0)) {
    uVar2 = thunk_EXT_FUN_801100000390ebc0(*(undefined8 *)(param_1 + 0x10));
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00996e364);
      (*pcVar1)();
    }
    thunk_EXT_FUN_80110000036da494
              (0x850900e1,uVar2,*(undefined8 *)(*(long *)(param_1 + 0x50) + 200),
               *(undefined8 *)(param_1 + 0x108),*(undefined8 *)(param_1 + 0x100),0);
    return;
  }
  return;
}

