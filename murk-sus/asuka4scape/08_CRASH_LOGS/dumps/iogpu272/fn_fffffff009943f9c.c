// FUN_fffffff009943f9c @ fffffff009943f9c size=100

void FUN_fffffff009943f9c(long param_1,uint param_2)

{
  param_2 = *(uint *)(param_1 + 0x78) | param_2;
  if (param_2 != *(uint *)(param_1 + 0x78)) {
    if (*(int *)(param_1 + 0x24) != 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "Can\'t upgrade IOGPUMemory.protectionOptions while still wired (0x%x->0x%x)\n");
      return;
    }
    *(uint *)(param_1 + 0x78) = param_2;
  }
  return;
}

