// FUN_fffffff009961430 @ fffffff009961430 size=220

undefined8 FUN_fffffff009961430(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20);
  if (*(int *)(lVar2 + 0x15c) != 0) {
    FUN_fffffff009975c34(*(undefined8 *)(lVar2 + 0x1a8),0x10000);
    while (*(int *)(lVar2 + 0x15c) != 0) {
      (**(code **)(**(long **)(lVar2 + 0x28) + 0x100))(*(long **)(lVar2 + 0x28),lVar2,0);
    }
    FUN_fffffff009975c44(*(undefined8 *)(lVar2 + 0x1a8),0x10000);
  }
  (**(code **)(**(long **)(param_1 + 0x28) + 0xa0))();
  uVar1 = FUN_fffffff00995cf04(*(undefined8 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x30));
  (**(code **)(**(long **)(param_1 + 0x28) + 0xa8))(*(long **)(param_1 + 0x28),uVar1);
  return uVar1;
}

