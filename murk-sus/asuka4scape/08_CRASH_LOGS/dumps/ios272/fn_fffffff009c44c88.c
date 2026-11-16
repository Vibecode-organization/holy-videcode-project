// FUN_fffffff009c44c88 @ fffffff009c44c88 size=168

undefined8 FUN_fffffff009c44c88(undefined8 param_1,long *param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  ulong unaff_x30;
  
  if (param_2 != (long *)0x0) {
    (**(code **)(*param_2 + 0x20))(param_2);
    uVar2 = FUN_fffffff009c44d30(param_1,param_2,0);
    (**(code **)(*param_2 + 0x28))(param_2);
    return uVar2;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c44d2c);
    (*pcVar1)();
  }
  uVar2 = FUN_fffffff009c44d30(param_1,0,0);
  return uVar2;
}

