// FUN_fffffff009964010 @ fffffff009964010 size=176

void FUN_fffffff009964010(long param_1,ulong param_2)

{
  code *pcVar1;
  uint uVar2;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x48));
  uVar2 = (uint)param_2;
  if ((uVar2 == 0) || (*(uint *)(param_1 + 0x50) <= uVar2)) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
               "trying to remove apparently bogus texture handle %d\n");
  }
  else {
    if (uVar2 < *(uint *)(param_1 + 0x54)) {
      *(uint *)(param_1 + 0x54) = uVar2;
    }
    *(ulong *)(*(long *)(param_1 + 0x40) + (ulong)(uVar2 >> 6) * 8) =
         *(ulong *)(*(long *)(param_1 + 0x40) + (ulong)(uVar2 >> 6) * 8) &
         (1L << (param_2 & 0x3f) ^ 0xffffffffffffffffU);
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0099640bc);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x48));
  return;
}

