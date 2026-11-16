// FUN_fffffff009970db8 @ fffffff009970db8 size=4

void FUN_fffffff009970db8(long param_1)

{
  code *pcVar1;
  long *plVar2;
  ulong unaff_x30;
  
  thunk_EXT_FUN_8011000003a132c0("Listing all allocated maps:\n");
  thunk_EXT_FUN_80110000038ff214(*(undefined8 *)(param_1 + 0x18));
  for (plVar2 = *(long **)(param_1 + 0x1b8); plVar2 != (long *)0x0; plVar2 = (long *)plVar2[7]) {
    (**(code **)(*plVar2 + 0x98))(plVar2);
    (**(code **)(*plVar2 + 200))(plVar2);
    thunk_EXT_FUN_8011000003a132c0("\tmapping=%p, address=0x%llx, size=0x%llx\n");
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009970e7c);
    (*pcVar1)();
  }
  thunk_EXT_FUN_80110000038ff2e0(*(undefined8 *)(param_1 + 0x18));
  return;
}

