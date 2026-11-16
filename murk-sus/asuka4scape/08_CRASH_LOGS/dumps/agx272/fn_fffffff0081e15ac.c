// FUN_fffffff0081e15ac @ fffffff0081e15ac size=84

undefined8 FUN_fffffff0081e15ac(long param_1,undefined8 *param_2)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)param_2[2];
  if ((((undefined8 *)*param_2 <= puVar1) && (puVar1 < (undefined8 *)0xfffffffffffffff8)) &&
     (puVar1 + 1 <= (undefined8 *)param_2[1])) {
    *(undefined8 *)(param_1 + 0x10) = *puVar1;
    param_2[2] = puVar1 + 1;
    *(undefined1 *)(param_1 + 8) = 1;
    return 1;
  }
  *(undefined4 *)(param_1 + 0xc) = 10;
  return 0;
}

