// FUN_fffffff0081fcfa8 @ fffffff0081fcfa8 size=164

undefined8 FUN_fffffff0081fcfa8(long *param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  ulong unaff_x30;
  
  lVar3 = param_1[0x55];
  if (lVar3 == 0) {
    return 1;
  }
  lVar4 = param_1[0x56];
  uVar2 = thunk_EXT_FUN_8011000003977d8c(lVar3,0);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081fd02c);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff0081fd034. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (**(code **)(*param_1 + 0xd0))
                    (param_1,lVar3,lVar4,uVar2,0,0,(undefined8 *)(*param_1 + 0xd0));
  return uVar2;
}

