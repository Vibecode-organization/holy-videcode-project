// FUN_fffffff009cbc73c @ fffffff009cbc73c

undefined8 FUN_fffffff009cbc73c(long param_1,long *param_2,undefined8 param_3)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  ulong unaff_x30;
  
  iVar2 = (**(code **)(*param_2 + 0xb8))(param_2,"DumpDebug");
  if (iVar2 != 0) {
    FUN_fffffff009cbc7ec(param_1);
    return 0;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009cbc7e0);
    (*pcVar1)();
  }
  uVar3 = (**(code **)(PTR_DAT_fffffff0080813a8 + 0x5a0))
                    (param_1,param_2,param_3,PTR_DAT_fffffff0080813a8 + 0x5a0);
  return uVar3;
}

