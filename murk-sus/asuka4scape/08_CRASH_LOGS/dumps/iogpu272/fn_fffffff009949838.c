// FUN_fffffff009949838 @ fffffff009949838 size=152

undefined8
FUN_fffffff009949838
          (undefined8 param_1,undefined8 param_2,ulong param_3,undefined8 param_4,ulong param_5,
          undefined8 param_6,undefined8 param_7)

{
  code *pcVar1;
  undefined8 uVar2;
  ulong unaff_x30;
  
  uVar2 = 0xe00002c2;
  if (((param_3 < 0x101) && (param_5 < 0x101)) &&
     (uVar2 = FUN_fffffff009949778(param_1,param_2,param_5,param_6,param_7), (int)uVar2 == 0)) {
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0099498cc);
      (*pcVar1)();
    }
    uVar2 = FUN_fffffff0099496bc(param_1,param_2,param_3,param_4);
    return uVar2;
  }
  return uVar2;
}

