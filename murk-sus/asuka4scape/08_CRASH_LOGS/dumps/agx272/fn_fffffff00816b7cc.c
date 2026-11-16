// FUN_fffffff00816b7cc @ fffffff00816b7cc size=108

undefined8 FUN_fffffff00816b7cc(long param_1)

{
  long *plVar1;
  undefined8 *puVar2;
  
  plVar1 = *(long **)(*(long *)(param_1 + 0x20) + 0x318);
  puVar2 = (undefined8 *)(*plVar1 + 0xe8);
  (*(code *)*puVar2)(puVar2,plVar1,FUN_fffffff00816b838,
                     *(undefined8 *)(*(long *)(param_1 + 0x20) + 0x11a58),0,0,0);
  return 0;
}

