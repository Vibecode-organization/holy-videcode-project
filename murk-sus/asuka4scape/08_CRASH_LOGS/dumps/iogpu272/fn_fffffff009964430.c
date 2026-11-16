// FUN_fffffff009964430 @ fffffff009964430 size=172

void FUN_fffffff009964430(long param_1,uint param_2,long *param_3)

{
  code *pcVar1;
  long *plVar2;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x48));
  plVar2 = *(long **)(param_1 + 0x20);
  while( true ) {
    if (plVar2 == (long *)0x0) {
      thunk_EXT_FUN_8011000003a49114
                (
                "\"IOGPUClientSharedMachine::getClientSharedAddressForId unable to find client map for id %08x\\n\" @%s:%d"
                );
      return;
    }
    if ((ulong)param_2 < (ulong)plVar2[6]) break;
    param_2 = param_2 - (int)plVar2[6];
    plVar2 = (long *)*plVar2;
  }
  *param_3 = plVar2[5] + *(long *)(param_1 + 0x28) * (ulong)param_2;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x48));
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0099644d8);
  (*pcVar1)();
}

