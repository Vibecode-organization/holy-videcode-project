// FUN_fffffff0081963b0 @ fffffff0081963b0 size=184

void FUN_fffffff0081963b0(long param_1)

{
  ulong uVar1;
  
  if (*(long *)(param_1 + 0xa8) == 0) {
    if (*(char *)(param_1 + 0x10) == -0x7e) {
      uVar1 = 0;
      if (*(long *)(param_1 + 0x30) != 0) {
        uVar1 = thunk_EXT_FUN_8011000002c1e35c
                          (*(undefined8 *)(*(long *)(*(long *)(param_1 + 0x30) + 0x30) + 0x10));
        uVar1 = uVar1 & 0xffffffff;
      }
    }
    else {
      uVar1 = *(ulong *)(param_1 + 0x70);
    }
    *(ulong *)(param_1 + 0xa8) = uVar1;
  }
  thunk_EXT_FUN_80110000038db19c
            (&MACH_HEADER,PTR_DAT_fffffff007ca61a8,0x10,
             "Protection violation: trace id: 0x%016llx rsrc id: 0x%08x type: 0x%02x internal: %d size: 0x%012llx rsrcProt: 0x%08llx cmdqProt: 0x%08llx %s"
            );
  return;
}

