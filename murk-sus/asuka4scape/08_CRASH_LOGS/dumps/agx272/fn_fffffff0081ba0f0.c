// FUN_fffffff0081ba0f0 @ fffffff0081ba0f0 size=180

undefined8 FUN_fffffff0081ba0f0(long *param_1,undefined8 param_2)

{
  code *pcVar1;
  long *plVar2;
  undefined8 uVar3;
  ulong unaff_x30;
  
  plVar2 = (long *)thunk_EXT_FUN_8011000003890f30(param_2,*(undefined8 *)PTR_DAT_fffffff007ca60a8);
  if (plVar2 == (long *)0x0) {
    return 0xe00002c2;
  }
  uVar3 = (**(code **)(*plVar2 + 0xa8))();
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081ba184);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff0081ba18c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  uVar3 = (**(code **)(*param_1 + 0x970))(param_1,uVar3,(undefined8 *)(*param_1 + 0x970));
  return uVar3;
}

