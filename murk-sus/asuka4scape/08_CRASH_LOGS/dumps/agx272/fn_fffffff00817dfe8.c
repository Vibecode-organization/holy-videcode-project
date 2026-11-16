// FUN_fffffff00817dfe8 @ fffffff00817dfe8 size=372

void FUN_fffffff00817dfe8(long *param_1,ulong param_2,int param_3,ulong param_4)

{
  undefined8 *puVar1;
  code *pcVar2;
  undefined4 uVar3;
  ulong unaff_x30;
  
  if ((*(byte *)((long)param_1 + 0x57a) & 1) != 0) {
    (**(code **)(*param_1 + 0xbc0))(param_1,0);
    uVar3 = 7;
    if (param_3 == 0) {
      uVar3 = 3;
    }
    if ((*(byte *)((long)param_1 + 0x1ac44) >> 3 & 1) != 0) {
      thunk_EXT_FUN_80110000032222a8(param_1[0x3589]);
      thunk_EXT_FUN_80110000036da494
                (0x85930da8,uVar3,param_2 & 0xffffffff,param_3,param_4 & 0xffffffff,0);
      thunk_EXT_FUN_8011000003222de0(param_1[0x3589]);
    }
    puVar1 = (undefined8 *)(*(long *)param_1[0x96] + 0x198);
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00817e0fc);
      (*pcVar2)();
    }
                    /* WARNING: Could not recover jumptable at 0xfffffff00817e104. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)*puVar1)((long *)param_1[0x96],param_2,uVar3,param_4,puVar1);
    return;
  }
  if (param_3 == 0) {
    return;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00817e140);
    (*pcVar2)();
  }
  thunk_EXT_FUN_801100000389061c(0,*(long *)(param_1[0x96] + 0x918) + 0x690);
  return;
}

