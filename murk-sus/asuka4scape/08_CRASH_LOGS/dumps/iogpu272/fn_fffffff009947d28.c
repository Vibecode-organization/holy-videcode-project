// FUN_fffffff009947d28 @ fffffff009947d28 size=188

undefined8 FUN_fffffff009947d28(long param_1,undefined8 param_2,long param_3)

{
  undefined4 uVar1;
  long *plVar2;
  long *plVar3;
  undefined8 uVar4;
  
  uVar4 = 0xe00002c2;
  uVar1 = (*(undefined4 **)(param_3 + 0x20))[2];
  plVar2 = (long *)FUN_fffffff009965da8
                             (*(undefined8 *)(param_1 + 0x120),**(undefined4 **)(param_3 + 0x20));
  plVar3 = (long *)FUN_fffffff009965db4(*(undefined8 *)(param_1 + 0x120),uVar1);
  if (plVar2 != (long *)0x0) {
    if (plVar3 != (long *)0x0) {
      uVar4 = FUN_fffffff009976ba0(plVar2,plVar3);
    }
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  if (plVar3 != (long *)0x0) {
    (**(code **)(*plVar3 + 0x28))(plVar3);
  }
  return uVar4;
}

