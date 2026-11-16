// FUN_fffffff009c1720c @ fffffff009c1720c size=192

/* WARNING: Removing unreachable block (ram,0xfffffff009c1728c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c1724c) */

void FUN_fffffff009c1720c(long param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000036da494
            (0x85210028,*(undefined8 *)(param_1 + 0x28),**(undefined8 **)(param_1 + 0x20),0,0,0);
  FUN_fffffff009c16f04(param_1,**(undefined8 **)(param_1 + 0x20));
  FUN_fffffff009c37bb0(*(undefined8 *)(param_1 + 0x10),1);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
    FUN_fffffff009c16fa0(param_1,1);
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c172c8);
  (*pcVar1)();
}

