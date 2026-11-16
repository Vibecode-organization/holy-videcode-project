// FUN_fffffff00994811c @ fffffff00994811c size=164

undefined8 FUN_fffffff00994811c(long param_1,undefined8 param_2,long param_3)

{
  long *plVar1;
  undefined8 uVar2;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(param_3 + 0x30);
  plVar1 = (long *)FUN_fffffff009965da8
                             (*(undefined8 *)(param_1 + 0x120),**(undefined4 **)(param_3 + 0x20));
  if (plVar1 == (long *)0x0) {
    uVar2 = 0xe00002c2;
  }
  else {
    uVar2 = FUN_fffffff0099767f8(plVar1,*puVar3);
    if ((int)uVar2 == 0) {
      FUN_fffffff0099768f4(plVar1);
      uVar2 = FUN_fffffff00997742c(plVar1,*puVar3);
      FUN_fffffff009976900(plVar1);
    }
    (**(code **)(*plVar1 + 0x28))(plVar1);
  }
  return uVar2;
}

