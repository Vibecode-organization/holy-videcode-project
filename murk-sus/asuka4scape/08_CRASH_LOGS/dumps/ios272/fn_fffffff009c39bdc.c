// FUN_fffffff009c39bdc @ fffffff009c39bdc size=280

undefined8 FUN_fffffff009c39bdc(undefined8 param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  long *plVar2;
  long lVar3;
  undefined8 uVar4;
  
  uVar4 = 0xe00002c2;
  plVar2 = *(long **)(param_3 + 0x40);
  if (plVar2 == (long *)0x0) {
    plVar2 = (long *)0x0;
    lVar3 = *(long *)(param_3 + 0x30);
    iVar1 = *(int *)(param_3 + 0x38);
  }
  else {
    plVar2 = (long *)(**(code **)(*plVar2 + 0xe8))(plVar2,0x1000);
    if (plVar2 == (long *)0x0) {
      return 0xe00002c8;
    }
    lVar3 = (**(code **)(*plVar2 + 0x78))();
    iVar1 = (**(code **)(**(long **)(param_3 + 0x40) + 0xb0))();
  }
  if (lVar3 != 0 && iVar1 != 0) {
    uVar4 = FUN_fffffff009c3e570(param_1,**(undefined4 **)(param_3 + 0x20),lVar3);
  }
  if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  return uVar4;
}

