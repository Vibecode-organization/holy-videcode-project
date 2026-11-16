// FUN_fffffff008d14588 @ fffffff008d14588 size=4
// CALLERS:
//   fffffff00afb8d3d no-fn
//   fffffff008d1435c FUN_fffffff008d142e8@fffffff008d142e8
// CALLEES:

/* WARNING: Removing unreachable block (ram,0xfffffff008d145f8) */
/* WARNING: Removing unreachable block (ram,0xfffffff008d145cc) */

void FUN_fffffff008d14588(undefined8 param_1,code *param_2,undefined8 param_3,undefined8 param_4)

{
  code *pcVar1;
  ulong unaff_x30;
  code *UNRECOVERED_JUMPTABLE;
  
  if ((param_2 == (code *)0x0) || (UNRECOVERED_JUMPTABLE = param_2, param_2 == (code *)0x0)) {
    UNRECOVERED_JUMPTABLE = (code *)0x0;
  }
  FUN_fffffff008cd5a74(0x114,0x262,0,UNRECOVERED_JUMPTABLE,1);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff008d14654);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff008d14658. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_3,param_1,param_4);
  return;
}

