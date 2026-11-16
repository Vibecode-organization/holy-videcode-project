// FUN_fffffff009c16670 @ fffffff009c16670 size=120
// CALLERS:
//   fffffff00afebc05 no-fn
//   fffffff009c16638 FUN_fffffff009c165ec@fffffff009c165ec
//   fffffff009c16660 FUN_fffffff009c16654@fffffff009c16654
//   fffffff009c18834 FUN_fffffff009c187cc@fffffff009c187cc
//   fffffff009c188ec FUN_fffffff009c18878@fffffff009c18878
//   fffffff009c189f0 FUN_fffffff009c18984@fffffff009c18984
//   fffffff009c1a9b0 FUN_fffffff009c1a914@fffffff009c1a914
//   fffffff009c1aa6c FUN_fffffff009c1a914@fffffff009c1a914
//   fffffff009c1e1cc FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1f0b4 FUN_fffffff009c1e624@fffffff009c1e624
//   fffffff009c341e8 FUN_fffffff009c34124@fffffff009c34124
//   fffffff009c342e8 FUN_fffffff009c34224@fffffff009c34224
//   fffffff009c20dbc FUN_fffffff009c20b58@fffffff009c20b58
//   fffffff009c212c8 FUN_fffffff009c211dc@fffffff009c211dc
//   fffffff009c21968 FUN_fffffff009c215c4@fffffff009c215c4
//   fffffff009c21b0c FUN_fffffff009c215c4@fffffff009c215c4
//   fffffff009c21c4c FUN_fffffff009c215c4@fffffff009c215c4
//   fffffff009c3f190 FUN_fffffff009c3f130@fffffff009c3f130
//   fffffff009c25308 FUN_fffffff009c251b0@fffffff009c251b0
//   fffffff009c271dc FUN_fffffff009c27118@fffffff009c27118
//   fffffff009c27204 FUN_fffffff009c27118@fffffff009c27118
//   fffffff009c3b178 FUN_fffffff009c3b0bc@fffffff009c3b0bc
//   fffffff009c2a3cc FUN_fffffff009c2a3c4@fffffff009c2a3c4
// CALLEES:

long * FUN_fffffff009c16670(long *param_1,long *param_2)

{
  long *plVar1;
  
  plVar1 = (long *)*param_1;
  *param_1 = (long)param_2;
  if (param_2 != (long *)0x0) {
    (**(code **)(*param_2 + 0x20))(param_2);
  }
  if (plVar1 != (long *)0x0) {
    (**(code **)(*plVar1 + 0x28))(plVar1);
  }
  return param_1;
}

