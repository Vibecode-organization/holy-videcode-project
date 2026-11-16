// FUN_fffffff0081ff778 @ fffffff0081ff778 size=96

undefined8 FUN_fffffff0081ff778(long param_1,ulong *param_2)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)param_2[2];
  if (((((undefined8 *)*param_2 <= puVar1) && (puVar1 < (undefined8 *)0xffffffffffffffe0)) &&
      (puVar1 + 4 <= (undefined8 *)param_2[1])) &&
     (param_2[2] = (ulong)(puVar1 + 4), puVar1 != (undefined8 *)0x0)) {
    *(undefined8 *)(param_1 + 0x10) = *puVar1;
    *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)((long)puVar1 + 0x1c);
    *(undefined1 *)(param_1 + 8) = 1;
    return 1;
  }
  *(undefined4 *)(param_1 + 0xc) = 10;
  return 0;
}

