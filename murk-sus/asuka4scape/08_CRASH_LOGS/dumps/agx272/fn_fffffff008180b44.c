// FUN_fffffff008180b44 @ fffffff008180b44 size=324

long * FUN_fffffff008180b44(long param_1)

{
  long *plVar1;
  undefined *local_80;
  undefined8 local_78;
  code *local_70;
  undefined *local_68;
  undefined8 *local_60;
  long lStack_58;
  undefined8 local_50;
  undefined8 *local_48;
  undefined8 local_40;
  code *local_38;
  code *local_30;
  long *local_28;
  
  local_48 = &local_50;
  local_50 = 0;
  local_40 = DAT_fffffff007113ec8;
  local_38 = FUN_fffffff008180c88;
  local_30 = FUN_fffffff008180c9c;
  local_28 = (long *)0x0;
  if ((*(byte *)(param_1 + 0x11119) & 1) == 0) {
    plVar1 = (long *)0x0;
  }
  else {
    local_80 = PTR_DAT_fffffff007ca5f90;
    local_78 = DAT_fffffff007113eb0;
    local_70 = FUN_fffffff008180ce8;
    local_68 = &DAT_fffffff007c92fc8;
    local_60 = local_48;
    lStack_58 = param_1;
    thunk_EXT_FUN_801100000395c120(*(undefined8 *)(param_1 + 0x310),&local_80);
    plVar1 = (long *)local_48[5];
    if (plVar1 != (long *)0x0) {
      (**(code **)(*plVar1 + 0x20))(plVar1);
    }
  }
  thunk_EXT_FUN_80110000038e9dac(&local_50,8);
  if (local_28 != (long *)0x0) {
    (**(code **)(*local_28 + 0x28))();
  }
  return plVar1;
}

