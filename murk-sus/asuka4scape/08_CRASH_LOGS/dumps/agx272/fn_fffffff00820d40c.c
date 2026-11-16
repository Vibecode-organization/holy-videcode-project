// FUN_fffffff00820d40c @ fffffff00820d40c size=240

void FUN_fffffff00820d40c(long param_1)

{
  code *pcVar1;
  long *plVar2;
  undefined8 *puVar3;
  ulong unaff_x30;
  
  if (*(long **)(param_1 + 0xbe8) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0xbe8) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0xbe8) = 0;
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
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00820d4f0);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff00820d4f8. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff007ca6160 + 0x80))(param_1);
  return;
}

