// FUN_fffffff009c2c854 @ fffffff009c2c854 size=408

/* WARNING: Removing unreachable block (ram,0xfffffff009c2c8e8) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c2c944) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c2c898) */

void FUN_fffffff009c2c854(long param_1,long *param_2,undefined8 param_3)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  long lVar4;
  ulong unaff_x30;
  
  lVar4 = *(long *)(param_1 + 0x40);
  if (lVar4 == 0) {
    lVar4 = 0;
  }
  FUN_fffffff009c23d94(lVar4,param_2,param_3,*(undefined8 *)(param_1 + 0x50));
  plVar2 = (long *)thunk_EXT_FUN_80110000038c6e24(*(ulong *)(param_1 + 0x90) & 0xffffffff,0x20);
  (**(code **)(*param_2 + 0x100))(*param_2 + 0x100,param_2,"UseCount",plVar2);
  plVar3 = (long *)thunk_EXT_FUN_80110000038c6e24(*(ulong *)(param_1 + 0x90) >> 0x20,0x20);
  (**(code **)(*param_2 + 0x100))(*param_2 + 0x100,param_2,"UseCount1",plVar3);
  if (plVar3 != (long *)0x0) {
    (**(code **)(*plVar3 + 0x28))(plVar3);
  }
  if (plVar2 != (long *)0x0) {
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c2c9d0);
      (*pcVar1)();
    }
                    /* WARNING: Could not recover jumptable at 0xfffffff009c2c9d8. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*plVar2 + 0x28))(plVar2,(undefined8 *)(*plVar2 + 0x28));
    return;
  }
  return;
}

