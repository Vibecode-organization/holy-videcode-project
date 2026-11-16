// FUN_fffffff009c24f6c @ fffffff009c24f6c

/* WARNING: Removing unreachable block (ram,0xfffffff009c24fe8) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c24fa8) */

long * FUN_fffffff009c24f6c(long param_1,long param_2,undefined4 *param_3)

{
  long *plVar1;
  long *plVar2;
  code *UNRECOVERED_JUMPTABLE;
  long lVar3;
  undefined8 *puVar4;
  ulong unaff_x30;
  
  *param_3 = *(undefined4 *)(*(long *)(param_1 + 0x178) + 0x20);
  if (*(long *)(param_1 + 0x1a8) == 0) {
    FUN_fffffff009c20460(param_1);
  }
  plVar1 = *(long **)(param_1 + 0x1a8);
  lVar3 = *plVar1;
  if (param_2 == 0) {
    puVar4 = (undefined8 *)(lVar3 + 200);
    UNRECOVERED_JUMPTABLE = (code *)*puVar4;
LAB_fffffff009c25050:
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff009c25074. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
      plVar1 = (long *)(*UNRECOVERED_JUMPTABLE)(plVar1,0,puVar4);
      return plVar1;
    }
                    /* WARNING: Does not return */
    UNRECOVERED_JUMPTABLE = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c2506c);
    (*UNRECOVERED_JUMPTABLE)();
  }
  plVar2 = (long *)(**(code **)(lVar3 + 0x128))(lVar3 + 0x128,plVar1,param_2);
  if (plVar2 != (long *)0x0) {
    plVar1 = thunk_FUN_fffffff00a894f30(plVar2,*(long *)PTR_PTR_fffffff00806c9c0);
    if (plVar1 != (long *)0x0) {
      puVar4 = (undefined8 *)(*plVar1 + 200);
      UNRECOVERED_JUMPTABLE = (code *)*puVar4;
      goto LAB_fffffff009c25050;
    }
    (**(code **)(*plVar2 + 0x20))(plVar2);
  }
  return plVar2;
}

