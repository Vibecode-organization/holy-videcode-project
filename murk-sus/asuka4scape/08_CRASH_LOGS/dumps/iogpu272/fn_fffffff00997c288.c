// FUN_fffffff00997c288 @ fffffff00997c288 size=260

long * FUN_fffffff00997c288(long param_1)

{
  long *plVar1;
  long lVar2;
  long *plVar3;
  
  plVar1 = (long *)thunk_EXT_FUN_80110000038961f4(1000);
  lVar2 = 0;
  do {
    for (plVar3 = *(long **)(param_1 + 0x18 + lVar2 * 8); plVar3 != (long *)0x0;
        plVar3 = (long *)*plVar3) {
      (**(code **)(*plVar1 + 0xe8))(plVar1,plVar3[2]);
    }
    lVar2 = lVar2 + 1;
  } while (lVar2 != 0x80);
  if (*(long *)(param_1 + 0x418) != 0) {
    (**(code **)(*plVar1 + 0xf8))(plVar1);
  }
  if (*(long *)(param_1 + 0x420) != 0) {
    (**(code **)(*plVar1 + 0xf8))(plVar1);
  }
  if (*(long *)(param_1 + 0x428) != 0) {
    (**(code **)(*plVar1 + 0xf8))(plVar1);
  }
  return plVar1;
}

