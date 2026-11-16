// FUN_fffffff009c42434 @ fffffff009c42434 size=328
// CALLERS:
//   fffffff00afec199 no-fn
//   fffffff009c44880 FUN_fffffff009c443e0@fffffff009c443e0
// CALLEES:
//   fffffff00a89797c FUN_fffffff00a89797c

undefined8
FUN_fffffff009c42434(long param_1,undefined8 param_2,long *param_3,undefined8 param_4,long *param_5)

{
  long *plVar1;
  
  (**(code **)(PTR_DAT_fffffff00806ca30 + 0x78))();
  plVar1 = *(long **)(param_1 + 0x28);
  *(undefined8 *)(param_1 + 0x20) = param_2;
  *(long **)(param_1 + 0x28) = param_3;
  if (param_3 != (long *)0x0) {
    (**(code **)(*param_3 + 0x20))(param_3);
  }
  if (plVar1 != (long *)0x0) {
    (**(code **)(*plVar1 + 0x28))(plVar1);
  }
  plVar1 = *(long **)(param_1 + 0x18);
  *(undefined8 *)(param_1 + 0x10) = param_4;
  *(long **)(param_1 + 0x18) = param_5;
  if (param_5 != (long *)0x0) {
    (**(code **)(*param_5 + 0x20))(param_5);
  }
  if (plVar1 != (long *)0x0) {
    (**(code **)(*plVar1 + 0x28))(plVar1);
  }
  if (param_5 != (long *)0x0) {
    (**(code **)(*param_5 + 0x28))(param_5);
  }
  if (param_3 != (long *)0x0) {
    (**(code **)(*param_3 + 0x28))(param_3);
  }
  return 1;
}

