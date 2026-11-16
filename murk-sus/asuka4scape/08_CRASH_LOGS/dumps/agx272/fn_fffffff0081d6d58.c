// FUN_fffffff0081d6d58 @ fffffff0081d6d58 size=196

/* WARNING: Removing unreachable block (ram,0xfffffff0081d6dd4) */

void FUN_fffffff0081d6d58(long param_1,long *param_2,undefined8 param_3,undefined8 param_4)

{
  code *pcVar1;
  undefined8 uVar2;
  ulong unaff_x30;
  
  (**(code **)(*param_2 + 0x38))(param_2);
  thunk_EXT_FUN_8011000003891b28();
  uVar2 = thunk_EXT_FUN_80110000038ce200();
  *(undefined8 *)(param_1 + 0x11198) = uVar2;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff0081d6e18. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_2 + 0x590))(param_2,param_3,param_4,param_1 + 0x3b0,0,*param_2 + 0x590);
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081d6e10);
  (*pcVar1)();
}

