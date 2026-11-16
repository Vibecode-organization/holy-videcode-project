// FUN_fffffff00817ea94 @ fffffff00817ea94 size=196

void FUN_fffffff00817ea94(long *param_1,undefined8 param_2,undefined4 *param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  code *pcVar2;
  undefined4 uVar3;
  ulong unaff_x30;
  
  if ((*(byte *)((long)param_1 + 0x57a) & 1) != 0) {
    (**(code **)(*param_1 + 0xbc0))(param_1,0);
  }
  if (param_3 == (undefined4 *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = *param_3;
  }
  puVar1 = (undefined8 *)(*(long *)param_1[0x96] + 0x1b0);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00817eb4c);
    (*pcVar2)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff00817eb54. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*puVar1)((long *)param_1[0x96],param_2,uVar3,param_4,puVar1);
  return;
}

