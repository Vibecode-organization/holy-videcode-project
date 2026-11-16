// FUN_fffffff0099620e8 @ fffffff0099620e8 size=448

void FUN_fffffff0099620e8(long param_1,undefined8 param_2)

{
  long lVar1;
  long *plVar2;
  undefined *local_78;
  undefined8 local_70;
  code *local_68;
  undefined *local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  
  local_50 = 0;
  uStack_48 = 0;
  thunk_FUN_fffffff00997e1ac(&local_50,param_1 + 0x1b8);
  lVar1 = FUN_fffffff00997e334(&local_50);
  while (lVar1 != 0) {
    FUN_fffffff00997b558(param_2,lVar1);
    lVar1 = FUN_fffffff00997e334(&local_50);
  }
  plVar2 = (long *)thunk_EXT_FUN_80110000038ccc44(0x20);
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x150));
  for (lVar1 = *(long *)(param_1 + 0x130); lVar1 != 0; lVar1 = *(long *)(lVar1 + 0x20)) {
    (**(code **)(*plVar2 + 0xf0))(plVar2,lVar1);
  }
  for (lVar1 = *(long *)(param_1 + 0x140); lVar1 != 0; lVar1 = *(long *)(lVar1 + 0x20)) {
    (**(code **)(*plVar2 + 0xf0))(plVar2,lVar1);
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x150));
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x160));
  for (lVar1 = *(long *)(param_1 + 0x168); lVar1 != 0; lVar1 = *(long *)(lVar1 + 0x30)) {
    (**(code **)(*plVar2 + 0xf0))(plVar2,lVar1);
  }
  local_68 = FUN_fffffff0099622a8;
  local_60 = &DAT_fffffff007fecfe0;
  local_78 = PTR_DAT_fffffff007ff2748;
  local_70 = DAT_fffffff007835cd0;
  uStack_58 = param_2;
  thunk_EXT_FUN_801100000389794c(&local_60,plVar2,&local_78);
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x160));
  if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  FUN_fffffff00997e2e4(&local_50);
  return;
}

