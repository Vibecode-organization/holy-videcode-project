// FUN_fffffff009c39e0c @ fffffff009c39e0c size=172

undefined8 FUN_fffffff009c39e0c(undefined8 param_1,undefined8 param_2,long param_3)

{
  long *plVar1;
  undefined8 uVar2;
  
  uVar2 = 0xe00002bd;
  if (*(long *)(param_3 + 0x78) == 0) {
    uVar2 = 0xe00002c2;
  }
  else {
    plVar1 = (long *)thunk_EXT_FUN_80110000038d4814(0x100000,0,0);
    if (plVar1 != (long *)0x0) {
      uVar2 = FUN_fffffff009c3eb68(param_1,**(undefined4 **)(param_3 + 0x20),plVar1);
      if ((int)uVar2 == 0) {
        **(long **)(param_3 + 0x78) = (long)plVar1;
      }
      else {
        (**(code **)(*plVar1 + 0x28))(plVar1);
      }
    }
  }
  return uVar2;
}

