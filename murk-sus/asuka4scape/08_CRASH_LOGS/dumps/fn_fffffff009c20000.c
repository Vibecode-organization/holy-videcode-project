// FUN_fffffff009c20000 @ fffffff009c20000 size=56
// CALLERS:
//   fffffff00afebce8 no-fn
//   fffffff009c1b1ec FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1e3b8 FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c2b198 FUN_fffffff009c2b164@fffffff009c2b164
// CALLEES:
//   fffffff009c498d4 thunk_FUN_fffffff00a894f30
//   fffffff009c2b130 FUN_fffffff009c2b130

void FUN_fffffff009c20000(long *param_1,undefined8 param_2)

{
  code *pcVar1;
  long *plVar2;
  ulong unaff_x30;
  
  plVar2 = (long *)FUN_fffffff009c2b130(param_1,param_2);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c20034);
    (*pcVar1)();
  }
  thunk_FUN_fffffff00a894f30(plVar2,*(long *)PTR_PTR_fffffff00806c9f0);
  return;
}

