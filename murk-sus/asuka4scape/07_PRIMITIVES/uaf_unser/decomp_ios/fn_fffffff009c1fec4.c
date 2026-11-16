// FUN_fffffff009c1fec4 @ fffffff009c1fec4 size=140
// CALLERS:
//   fffffff009c1af70 FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1af9c FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1afc8 FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1aff4 FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1b020 FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1b04c FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1b090 FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1b0bc FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1b0ec FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1b150 FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1b1bc FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1c634 FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1c6d4 FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1c700 FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1c754 FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1e0e4 FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1e110 FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1e174 FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1e1a0 FUN_fffffff009c1af14@fffffff009c1af14

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_fffffff009c1fec4(long *param_1,undefined8 param_2,undefined1 *param_3)

{
  undefined1 uVar1;
  undefined8 uVar2;
  long *plVar3;
  
  uVar2 = (**(code **)(*param_1 + 0x138))();
  plVar3 = (long *)FUN_fffffff009c498d4(uVar2,*_DAT_fffffff00806ca20);
  if (plVar3 != (long *)0x0) {
    uVar1 = (**(code **)(*plVar3 + 0x88))(plVar3);
    *param_3 = uVar1;
  }
  return plVar3 != (long *)0x0;
}

