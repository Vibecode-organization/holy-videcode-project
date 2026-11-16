// FUN_fffffff0081c3d10 @ fffffff0081c3d10 size=372

undefined8 FUN_fffffff0081c3d10(long *param_1,undefined8 param_2,int param_3)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  code *UNRECOVERED_JUMPTABLE;
  ulong unaff_x30;
  
  if (param_3 < 3) {
    if (param_3 == 0) {
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff0081c3de0. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
        uVar1 = (**(code **)(*param_1 + 0x438))(param_1,param_2,(undefined8 *)(*param_1 + 0x438));
        return uVar1;
      }
                    /* WARNING: Does not return */
      UNRECOVERED_JUMPTABLE = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081c3dd8);
      (*UNRECOVERED_JUMPTABLE)();
    }
    if (param_3 == 1) {
      puVar2 = (undefined8 *)(*param_1 + 0x440);
      UNRECOVERED_JUMPTABLE = (code *)*puVar2;
      uVar1 = 0;
LAB_fffffff0081c3e30:
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff0081c3e4c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
        uVar1 = (*UNRECOVERED_JUMPTABLE)(param_1,param_2,uVar1,puVar2);
        return uVar1;
      }
                    /* WARNING: Does not return */
      UNRECOVERED_JUMPTABLE = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081c3e44);
      (*UNRECOVERED_JUMPTABLE)();
    }
    if (param_3 == 2) {
      (**(code **)(*param_1 + 0x448))();
    }
  }
  else {
    if (param_3 == 3) {
      UNRECOVERED_JUMPTABLE = *(code **)(*param_1 + 0x430);
      uVar1 = 1;
    }
    else {
      if (param_3 != 4) {
        if (param_3 != 5) {
          return 0;
        }
        puVar2 = (undefined8 *)(*param_1 + 0x440);
        UNRECOVERED_JUMPTABLE = (code *)*puVar2;
        uVar1 = 1;
        goto LAB_fffffff0081c3e30;
      }
      UNRECOVERED_JUMPTABLE = *(code **)(*param_1 + 0x430);
      uVar1 = 0;
    }
    (*UNRECOVERED_JUMPTABLE)(param_1,param_2,uVar1);
  }
  return 0;
}

