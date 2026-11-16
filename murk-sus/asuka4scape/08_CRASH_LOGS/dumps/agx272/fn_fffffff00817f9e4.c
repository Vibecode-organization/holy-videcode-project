// FUN_fffffff00817f9e4 @ fffffff00817f9e4 size=80

void FUN_fffffff00817f9e4(long param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  ulong unaff_x30;
  
  uVar2 = (**(code **)(**(long **)(param_1 + 0x4b0) + 0x158))();
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00817fa30);
    (*pcVar1)();
  }
  thunk_EXT_FUN_80110000038c6e24(uVar2,0x20);
  return;
}

