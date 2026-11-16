// FUN_fffffff00996741c @ fffffff00996741c size=388

undefined8 FUN_fffffff00996741c(long param_1,undefined8 param_2)

{
  long *plVar1;
  long *plVar2;
  undefined8 uVar3;
  undefined *local_58;
  undefined8 local_50;
  code *local_48;
  undefined *local_40;
  long *local_38;
  
  plVar1 = (long *)thunk_EXT_FUN_80110000038961f4(*(undefined4 *)(*(long *)(param_1 + 0x88) + 0x30))
  ;
  if (plVar1 == (long *)0x0) {
    uVar3 = 0;
  }
  else {
    plVar2 = (long *)FUN_fffffff009944a54(*(undefined8 *)(param_1 + 0x88));
    if (plVar2 != (long *)0x0) {
      local_58 = PTR_DAT_fffffff007ff2748;
      local_50 = DAT_fffffff007835cd8;
      local_48 = FUN_fffffff0099675a0;
      local_40 = &DAT_fffffff007fed3f8;
      local_38 = plVar1;
      (**(code **)(*plVar1 + 0x20))(plVar1);
      thunk_EXT_FUN_801100000389794c(plVar2,&local_58);
      if (local_38 != (long *)0x0) {
        (**(code **)(*local_38 + 0x28))();
      }
      local_38 = (long *)0x0;
    }
    uVar3 = (**(code **)(*plVar1 + 0x30))(plVar1,param_2);
    if (plVar2 != (long *)0x0) {
      (**(code **)(*plVar2 + 0x28))(plVar2);
    }
    (**(code **)(*plVar1 + 0x28))(plVar1);
  }
  return uVar3;
}

