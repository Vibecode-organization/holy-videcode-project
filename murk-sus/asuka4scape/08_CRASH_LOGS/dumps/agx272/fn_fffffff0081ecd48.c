// FUN_fffffff0081ecd48 @ fffffff0081ecd48 size=156

void FUN_fffffff0081ecd48(long param_1)

{
  long lVar1;
  
  FUN_fffffff0081e92c4();
  if (*(long **)(param_1 + 0x240) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x240) + 0x28))();
    *(undefined8 *)(param_1 + 0x240) = 0;
  }
  lVar1 = *(long *)(param_1 + 0x230);
  if (lVar1 != 0) {
    *(undefined8 *)(param_1 + 0x230) = 0;
    thunk_EXT_FUN_80110000038fe768
              (&DAT_fffffff007ca48c8,lVar1,(ulong)*(uint *)(param_1 + 0x138) << 3);
    *(undefined8 *)(param_1 + 0x230) = 0;
  }
  if (*(long **)(param_1 + 0x228) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x228) + 0x28))();
    *(undefined8 *)(param_1 + 0x228) = 0;
  }
  return;
}

