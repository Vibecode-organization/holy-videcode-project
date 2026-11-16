// FUN_fffffff0099627fc @ fffffff0099627fc size=240

long FUN_fffffff0099627fc(long param_1)

{
  long lVar1;
  long *plVar2;
  long lVar3;
  long *local_38;
  
  lVar1 = thunk_EXT_FUN_80110000038961f4(0x10);
  if (lVar1 != 0) {
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x160));
    for (lVar3 = *(long *)(param_1 + 0x168); lVar3 != 0; lVar3 = *(long *)(lVar3 + 0x30)) {
      plVar2 = (long *)FUN_fffffff00995dd08(lVar3);
      local_38 = plVar2;
      if (plVar2 != (long *)0x0) {
        (**(code **)(*plVar2 + 0x20))(plVar2);
      }
      thunk_EXT_FUN_80110000038963f0(lVar1,&local_38);
      if (local_38 != (long *)0x0) {
        (**(code **)(*local_38 + 0x28))();
      }
      if (plVar2 != (long *)0x0) {
        (**(code **)(*plVar2 + 0x28))(plVar2);
      }
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x160));
  }
  return lVar1;
}

