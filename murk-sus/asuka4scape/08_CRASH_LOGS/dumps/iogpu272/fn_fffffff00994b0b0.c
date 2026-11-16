// FUN_fffffff00994b0b0 @ fffffff00994b0b0 size=92

void FUN_fffffff00994b0b0(long *param_1,int param_2,undefined8 param_3,undefined8 param_4)

{
  undefined4 *puVar1;
  ulong uVar2;
  
  uVar2 = (long)param_2 << 4 | 8;
  puVar1 = (undefined4 *)((long)param_1 + (long)(int)uVar2 + 0x40);
  if (uVar2 != (long)(int)uVar2) {
    puVar1 = (undefined4 *)((long)param_1 + uVar2 + 0x40 & 0xffffffffffff | 0x2bad000000000000);
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff00994b108. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x90))(param_1,param_2,param_4,*puVar1,(undefined8 *)(*param_1 + 0x90));
  return;
}

