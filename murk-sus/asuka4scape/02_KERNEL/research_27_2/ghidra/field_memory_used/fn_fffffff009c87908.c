// FUN_fffffff009c87908 @ fffffff009c87908

void FUN_fffffff009c87908(long param_1)

{
  code *pcVar1;
  long *plVar2;
  undefined8 *puVar3;
  ulong unaff_x30;
  
  plVar2 = *(long **)(param_1 + 0x28);
  *(undefined8 *)(param_1 + 0x18) = 0;
  *(undefined8 *)(param_1 + 0x20) = 0;
  if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 0x28))();
  }
  if (*(long **)(param_1 + 0x40) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x40) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x40) = 0;
  *(undefined8 *)(param_1 + 0x48) = 0;
  *(undefined8 *)(param_1 + 0x10) = 0;
  *(undefined8 *)(param_1 + 0x30) = 0;
  *(undefined8 *)(param_1 + 0x38) = 0;
  *(long *)(param_1 + 0x28) = 0;
  *(undefined8 *)(param_1 + 0x50) = 0;
  *(undefined8 *)(param_1 + 0x58) = 0;
  puVar3 = (undefined8 *)(**(long **)(param_1 + 0x80) + 0xb8);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c879bc);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff009c879c4. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*puVar3)(*(long **)(param_1 + 0x80),puVar3);
  return;
}

