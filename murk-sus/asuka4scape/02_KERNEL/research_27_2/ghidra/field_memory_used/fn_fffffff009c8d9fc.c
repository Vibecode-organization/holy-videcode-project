// FUN_fffffff009c8d9fc @ fffffff009c8d9fc

void FUN_fffffff009c8d9fc(long param_1,undefined8 param_2)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if (*(long **)(param_1 + 0x1a0) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x1a0) + 0x138))();
    (**(code **)(**(long **)(param_1 + 0x1a0) + 0xb8))();
    (**(code **)(**(long **)(param_1 + 0xe8) + 0xa8))
              (*(long **)(param_1 + 0xe8),*(undefined8 *)(param_1 + 0x1a0));
  }
  FUN_fffffff009c800d8(*(long **)(param_1 + 0xd8),param_1);
  if ((*(ulong *)(param_1 + 0x110) != 0) && (*(long *)(param_1 + 0x108) != 0)) {
    thunk_FUN_fffffff00a2262a8(*(ulong *)(param_1 + 0x110));
    (**(code **)(**(long **)(param_1 + 0x108) + 0xb8))();
    thunk_FUN_fffffff00a226de0(*(ulong *)(param_1 + 0x110));
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c8db00);
    (*pcVar1)();
  }
  (**(code **)(PTR_DAT_fffffff00807fad8 + 0x2c8))(param_1,param_2,PTR_DAT_fffffff00807fad8 + 0x2c8);
  return;
}

