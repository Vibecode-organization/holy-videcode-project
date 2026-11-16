// FUN_fffffff0081d357c @ fffffff0081d357c size=236

void FUN_fffffff0081d357c
               (undefined8 param_1,long *param_2,undefined8 param_3,undefined8 *param_4,
               undefined8 *param_5,undefined8 param_6,undefined8 param_7)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  ulong unaff_x30;
  
  uVar3 = (**(code **)(*param_2 + 0xa8))(param_2);
  iVar2 = thunk_EXT_FUN_80110000031cd5d0(uVar3,"retrieveVMLimits",0x11);
  if (iVar2 == 0) {
    *param_4 = 0;
    *param_5 = 0;
    return;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081d363c);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff0081d3644. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff007ca6178 + 0x3b8))
            (param_1,param_2,param_3,param_4,param_5,param_6,param_7,
             PTR_DAT_fffffff007ca6178 + 0x3b8);
  return;
}

