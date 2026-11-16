// FUN_fffffff008180ce8 @ fffffff008180ce8 size=136

undefined8 FUN_fffffff008180ce8(long param_1)

{
  undefined8 uVar1;
  long *plVar2;
  long lVar3;
  
  uVar1 = (**(code **)(**(long **)(*(long *)(param_1 + 0x28) + 0x4b0) + 0x370))();
  lVar3 = *(long *)(*(long *)(param_1 + 0x20) + 8);
  plVar2 = *(long **)(lVar3 + 0x28);
  if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 0x28))();
  }
  *(undefined8 *)(lVar3 + 0x28) = uVar1;
  return 0;
}

