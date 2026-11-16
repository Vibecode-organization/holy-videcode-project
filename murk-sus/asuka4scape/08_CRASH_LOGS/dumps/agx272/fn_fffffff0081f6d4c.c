// FUN_fffffff0081f6d4c @ fffffff0081f6d4c size=4

void FUN_fffffff0081f6d4c(long param_1)

{
  code *pcVar1;
  long *plVar2;
  undefined8 *puVar3;
  ulong unaff_x30;
  undefined *puStack_50;
  undefined8 uStack_48;
  code *pcStack_40;
  undefined *puStack_38;
  long lStack_30;
  undefined8 uStack_28;
  
  lStack_30 = *(long *)(param_1 + 0x10);
  uStack_28 = *(undefined8 *)(param_1 + 0x240);
  puStack_50 = PTR_DAT_fffffff007ca5f90;
  uStack_48 = DAT_fffffff007113e50;
  pcStack_40 = FUN_fffffff00817f678;
  puStack_38 = &DAT_fffffff007c92f68;
  thunk_EXT_FUN_801100000395c120(*(undefined8 *)(lStack_30 + 0x1ac80),&puStack_50);
  if (*(long **)(param_1 + 0x240) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x240) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x240) = 0;
  if (*(long *)(param_1 + 0x140) != 0) {
    plVar2 = *(long **)(*(long *)(param_1 + 0x10) + 0x310);
    puVar3 = (undefined8 *)(*plVar2 + 0xe8);
    (*(code *)*puVar3)(puVar3,plVar2,FUN_fffffff00817e544,*(long *)(param_1 + 0x140),0,0,0);
    *(undefined8 *)(param_1 + 0x140) = 0;
  }
  if (*(long **)(param_1 + 0x230) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x230) + 0x28))();
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081f6eb0);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff0081f6eb8. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff007ca6160 + 0x80))(param_1);
  return;
}

