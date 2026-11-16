// FUN_fffffff009c32f04 @ fffffff009c32f04 size=668

void FUN_fffffff009c32f04(long param_1)

{
  long *plVar1;
  long lVar2;
  
  plVar1 = (long *)*(long *)(param_1 + 0xf8);
  while (plVar1 != (long *)0x0) {
    lVar2 = *plVar1;
    if ((long *)plVar1[2] != (long *)0x0) {
      (**(code **)(*(long *)plVar1[2] + 0x28))();
    }
    plVar1[2] = 0;
    (**(code **)(*(long *)plVar1[1] + 0xe0))((long *)plVar1[1],0);
    if ((long *)plVar1[1] != (long *)0x0) {
      (**(code **)(*(long *)plVar1[1] + 0x28))();
    }
    plVar1[1] = 0;
    thunk_EXT_FUN_80110000038fe270(&DAT_fffffff00806b3b0,plVar1);
    plVar1 = (long *)lVar2;
  }
  plVar1 = (long *)*(long *)(param_1 + 0x100);
  while (plVar1 != (long *)0x0) {
    lVar2 = *plVar1;
    if ((long *)plVar1[2] != (long *)0x0) {
      (**(code **)(*(long *)plVar1[2] + 0x28))();
    }
    plVar1[2] = 0;
    (**(code **)(*(long *)plVar1[1] + 0xe0))((long *)plVar1[1],0);
    if ((long *)plVar1[1] != (long *)0x0) {
      (**(code **)(*(long *)plVar1[1] + 0x28))();
    }
    plVar1[1] = 0;
    thunk_EXT_FUN_80110000038fe270(&DAT_fffffff00806b3f0,plVar1);
    plVar1 = (long *)lVar2;
  }
  plVar1 = (long *)*(long *)(param_1 + 0x130);
  while (plVar1 != (long *)0x0) {
    lVar2 = *plVar1;
    if ((long *)plVar1[2] != (long *)0x0) {
      (**(code **)(*(long *)plVar1[2] + 0x28))();
    }
    plVar1[2] = 0;
    (**(code **)(*(long *)plVar1[1] + 0xe0))((long *)plVar1[1],0);
    if ((long *)plVar1[1] != (long *)0x0) {
      (**(code **)(*(long *)plVar1[1] + 0x28))();
    }
    plVar1[1] = 0;
    thunk_EXT_FUN_80110000038fe270(&DAT_fffffff00806b430,plVar1);
    plVar1 = (long *)lVar2;
  }
  plVar1 = (long *)*(long *)(param_1 + 0x138);
  while (plVar1 != (long *)0x0) {
    lVar2 = *plVar1;
    if ((long *)plVar1[2] != (long *)0x0) {
      (**(code **)(*(long *)plVar1[2] + 0x28))();
    }
    plVar1[2] = 0;
    (**(code **)(*(long *)plVar1[1] + 0xe0))((long *)plVar1[1],0);
    if ((long *)plVar1[1] != (long *)0x0) {
      (**(code **)(*(long *)plVar1[1] + 0x28))();
    }
    plVar1[1] = 0;
    thunk_EXT_FUN_80110000038fe270(&DAT_fffffff00806b470,plVar1);
    plVar1 = (long *)lVar2;
  }
  return;
}

