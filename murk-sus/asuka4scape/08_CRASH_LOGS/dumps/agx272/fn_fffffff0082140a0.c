// FUN_fffffff0082140a0 @ fffffff0082140a0 size=56

undefined8 FUN_fffffff0082140a0(long param_1,int param_2)

{
  undefined8 uVar1;
  
  if (param_2 == 0x80) {
    return *(undefined8 *)(*(long *)(param_1 + 0x1a8) + 0x11a58);
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff0082140d4. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(PTR_DAT_fffffff007ca6100 + 0x98))();
  return uVar1;
}

