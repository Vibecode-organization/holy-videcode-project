// FUN_fffffff00819a734 @ fffffff00819a734 size=188

undefined8 FUN_fffffff00819a734(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x20);
  (**(code **)(**(long **)(lVar1 + 0x928) + 0x138))();
  (**(code **)(**(long **)(lVar1 + 0x930) + 0xa8))
            (*(long **)(lVar1 + 0x930),*(undefined8 *)(lVar1 + 0x928));
  if (*(long **)(lVar1 + 0x928) != (long *)0x0) {
    (**(code **)(**(long **)(lVar1 + 0x928) + 0x28))();
  }
  *(undefined8 *)(lVar1 + 0x928) = 0;
  (**(code **)(**(long **)(lVar1 + 0x938) + 0xb8))();
  return 0;
}

