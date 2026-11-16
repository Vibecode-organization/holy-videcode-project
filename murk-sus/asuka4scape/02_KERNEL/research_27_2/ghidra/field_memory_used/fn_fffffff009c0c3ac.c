// FUN_fffffff009c0c3ac @ fffffff009c0c3ac

ulong FUN_fffffff009c0c3ac(long *param_1,long *param_2)

{
  ulong uVar1;
  long *plVar2;
  
  uVar1 = (*(code *)PTR_FUN_fffffff008063790)();
  if ((int)uVar1 != 0) {
    *(undefined4 *)(param_1 + 0x13) = 0;
    plVar2 = thunk_FUN_fffffff00a8d0c44(0x10);
    param_1[0x14] = (long)plVar2;
    plVar2 = thunk_FUN_fffffff00a8d0c44(0x10);
    param_1[0x15] = (long)plVar2;
    uVar1 = (ulong)(param_1[0x14] != 0 && plVar2 != (long *)0x0);
  }
  return uVar1;
}

