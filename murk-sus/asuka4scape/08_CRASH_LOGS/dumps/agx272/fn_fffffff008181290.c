// FUN_fffffff008181290 @ fffffff008181290 size=4

long * FUN_fffffff008181290(long param_1)

{
  long *plVar1;
  undefined *puStack_80;
  undefined8 uStack_78;
  code *pcStack_70;
  undefined *puStack_68;
  undefined8 *puStack_60;
  long lStack_58;
  undefined8 uStack_50;
  undefined8 *puStack_48;
  undefined8 uStack_40;
  code *pcStack_38;
  code *pcStack_30;
  long *plStack_28;
  
  puStack_48 = &uStack_50;
  uStack_50 = 0;
  uStack_40 = DAT_fffffff007113ec8;
  pcStack_38 = FUN_fffffff008180c88;
  pcStack_30 = FUN_fffffff008180c9c;
  plStack_28 = (long *)0x0;
  if ((*(byte *)(param_1 + 0x11119) & 1) == 0) {
    plVar1 = (long *)0x0;
  }
  else {
    puStack_80 = PTR_DAT_fffffff007ca5f90;
    uStack_78 = DAT_fffffff007113eb0;
    pcStack_70 = FUN_fffffff0081813d8;
    puStack_68 = &DAT_fffffff007c92ff8;
    puStack_60 = puStack_48;
    lStack_58 = param_1;
    thunk_EXT_FUN_801100000395c120(*(undefined8 *)(param_1 + 0x310),&puStack_80);
    plVar1 = (long *)puStack_48[5];
    if (plVar1 != (long *)0x0) {
      (**(code **)(*plVar1 + 0x20))(plVar1);
    }
  }
  thunk_EXT_FUN_80110000038e9dac(&uStack_50,8);
  if (plStack_28 != (long *)0x0) {
    (**(code **)(*plStack_28 + 0x28))();
  }
  return plVar1;
}

