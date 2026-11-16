// FUN_fffffff0099665b4 @ fffffff0099665b4 size=180

undefined8 FUN_fffffff0099665b4(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long *plVar2;
  undefined8 uVar3;
  long local_38;
  
  uVar3 = 0xe00002c2;
  if ((int)param_3 - 1U < 0xfffffffe) {
    plVar2 = (long *)FUN_fffffff009945040(*(undefined8 *)(param_1 + 0x10));
    if (plVar2 != (long *)0x0) {
      local_38 = 0;
      iVar1 = thunk_EXT_FUN_801100000329a6d4(param_3,&local_38);
      if (iVar1 == 0) {
        if (local_38 == 0) {
          uVar3 = 0xe00002c7;
        }
        else {
          uVar3 = FUN_fffffff009956140(plVar2);
          thunk_EXT_FUN_801100000326c730(local_38);
        }
      }
      (**(code **)(*plVar2 + 0x28))(plVar2);
    }
  }
  return uVar3;
}

