// FUN_fffffff009948074 @ fffffff009948074 size=4

undefined8 FUN_fffffff009948074(long param_1,undefined8 param_2,long param_3)

{
  long *plVar1;
  undefined8 uVar2;
  undefined4 *puVar3;
  uint uStack_34;
  
  puVar3 = *(undefined4 **)(param_3 + 0x30);
  plVar1 = (long *)FUN_fffffff009965da8
                             (*(undefined8 *)(param_1 + 0x120),**(undefined4 **)(param_3 + 0x20));
  uStack_34 = 3;
  if (plVar1 == (long *)0x0) {
    uVar2 = 0xe00002c2;
  }
  else {
    uVar2 = FUN_fffffff009977304(plVar1,*puVar3,puVar3[1],&uStack_34);
    if ((int)uVar2 == 0) {
      **(ulong **)(param_3 + 0x48) = (ulong)uStack_34;
    }
    (**(code **)(*plVar1 + 0x28))(plVar1);
  }
  return uVar2;
}

