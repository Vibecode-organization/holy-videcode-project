// FUN_fffffff009982a18 @ fffffff009982a18 size=244

long * FUN_fffffff009982a18(long param_1,uint param_2)

{
  long lVar1;
  long *plVar2;
  
  FUN_fffffff009942d70();
  if ((*(long *)(param_1 + 0xe0) == 0) && (*(long *)(param_1 + 0xa8) == 0)) {
    lVar1 = (**(code **)(**(long **)(param_1 + 0x90) + 0xe8))
                      (*(long **)(param_1 + 0x90),param_2 | 1);
    if (*(long **)(param_1 + 0xe0) != (long *)0x0) {
      (**(code **)(**(long **)(param_1 + 0xe0) + 0x28))();
    }
    *(long *)(param_1 + 0xe0) = lVar1;
    if (lVar1 == 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s: failed to map memory for CPU wire mapping\n");
    }
  }
  FUN_fffffff009942d7c(param_1);
  plVar2 = *(long **)(param_1 + 0xe0);
  if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 0x20))(plVar2);
  }
  return plVar2;
}

