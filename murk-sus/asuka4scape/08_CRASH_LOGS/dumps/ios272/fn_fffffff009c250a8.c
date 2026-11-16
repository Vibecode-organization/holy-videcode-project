// FUN_fffffff009c250a8 @ fffffff009c250a8 size=264

/* WARNING: Removing unreachable block (ram,0xfffffff009c250e0) */

void FUN_fffffff009c250a8(long param_1,long *param_2,int *param_3)

{
  int iVar1;
  undefined8 *puVar2;
  code *pcVar3;
  ulong uVar4;
  ulong unaff_x30;
  
  iVar1 = (*(uint *)(*(long *)(param_1 + 0x178) + 0x20) | 1) + 2;
  *(int *)(*(long *)(param_1 + 0x178) + 0x20) = iVar1;
  *param_3 = iVar1;
  if (param_2 == (long *)0x0) {
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
      FUN_fffffff009c24830(param_1);
      return;
    }
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c2515c);
    (*pcVar3)();
  }
  if ((*(long *)(param_1 + 0x1a8) != 0) &&
     (uVar4 = (**(code **)(*param_2 + 0xb8))(param_2,"CreationProperties"), (uVar4 & 1) == 0)) {
    puVar2 = (undefined8 *)(**(long **)(param_1 + 0x1a8) + 0x108);
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff009c251ac. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)*puVar2)(*(long **)(param_1 + 0x1a8),param_2,puVar2);
      return;
    }
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c251a4);
    (*pcVar3)();
  }
  return;
}

