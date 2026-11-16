// FUN_fffffff00994566c @ fffffff00994566c size=168

void FUN_fffffff00994566c(long *param_1,undefined8 param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  ulong unaff_x30;
  
  lVar3 = param_1[2];
  while (uVar2 = (**(code **)(**(long **)(lVar3 + 0x148) + 0xb0))
                           (*(long **)(lVar3 + 0x148),param_1,param_2), (int)uVar2 == -1) {
    thunk_EXT_FUN_80110000038fe968(100);
    lVar3 = param_1[2];
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009945708);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff009945710. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x80))(param_1,uVar2,(undefined8 *)(*param_1 + 0x80));
  return;
}

