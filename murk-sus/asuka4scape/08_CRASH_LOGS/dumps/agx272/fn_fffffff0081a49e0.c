// FUN_fffffff0081a49e0 @ fffffff0081a49e0 size=168

undefined8 FUN_fffffff0081a49e0(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x20);
  (**(code **)(*(long *)(lVar1 + 0x10) + 0x10))();
  (**(code **)(*(long *)(lVar1 + 0x90) + 0x10))((long *)(lVar1 + 0x90));
  (**(code **)(*(long *)(lVar1 + 0x110) + 0x10))(lVar1 + 0x110);
  (**(code **)(*(long *)(lVar1 + 400) + 0x10))(lVar1 + 400);
  return 0;
}

