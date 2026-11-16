// FUN_fffffff0081fced8 @ fffffff0081fced8 size=208

void FUN_fffffff0081fced8(long *param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  ulong unaff_x30;
  
  lVar3 = param_1[0x55];
  if (lVar3 != 0) {
    lVar4 = param_1[0x56];
    uVar2 = thunk_EXT_FUN_8011000003977d8c(lVar3,0);
    (**(code **)(*param_1 + 0xd8))(param_1,lVar3,lVar4,uVar2,0);
  }
  if (param_1[0x57] != 0) {
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081fcf8c);
      (*pcVar1)();
    }
                    /* WARNING: Could not recover jumptable at 0xfffffff0081fcf94. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0xd8))
              (param_1,param_1[0x57],0x1300000000,0x100000000,0,(undefined8 *)(*param_1 + 0xd8));
    return;
  }
  return;
}

