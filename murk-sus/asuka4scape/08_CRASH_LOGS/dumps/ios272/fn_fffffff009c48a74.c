// FUN_fffffff009c48a74 @ fffffff009c48a74 size=216

long * FUN_fffffff009c48a74(long *param_1,long param_2,undefined1 param_3)

{
  int iVar1;
  long *plVar2;
  
  plVar2 = (long *)(**(code **)(DAT_fffffff00af48548 + 0x68))();
  if (plVar2 != (long *)0x0) {
    iVar1 = (**(code **)(PTR_DAT_fffffff00806ca30 + 0x78))(plVar2);
    if ((param_1 == (long *)0x0) || (iVar1 == 0)) {
      (**(code **)(*plVar2 + 0x28))(plVar2);
      plVar2 = (long *)0x0;
    }
    else {
      (**(code **)(*param_1 + 0x20))(param_1);
      plVar2[3] = (long)param_1;
      plVar2[4] = param_2;
      *(undefined1 *)(plVar2 + 5) = param_3;
    }
  }
  return plVar2;
}

