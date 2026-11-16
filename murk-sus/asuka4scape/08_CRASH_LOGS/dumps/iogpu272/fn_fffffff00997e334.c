// FUN_fffffff00997e334 @ fffffff00997e334 size=172

undefined8 FUN_fffffff00997e334(undefined8 *param_1)

{
  undefined8 *puVar1;
  uint uVar2;
  int iVar3;
  code *pcVar4;
  uint uVar5;
  undefined8 uVar6;
  ulong unaff_x30;
  
  uVar2 = *(uint *)(param_1 + 1);
  uVar5 = (**(code **)(*(long *)*param_1 + 0x90))();
  if (uVar5 <= uVar2) {
    return 0;
  }
  iVar3 = *(int *)(param_1 + 1);
  *(int *)(param_1 + 1) = iVar3 + 1;
  puVar1 = (undefined8 *)(*(long *)*param_1 + 0x118);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00997e3c4);
    (*pcVar4)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff00997e3cc. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  uVar6 = (*(code *)*puVar1)((long *)*param_1,iVar3,puVar1);
  return uVar6;
}

