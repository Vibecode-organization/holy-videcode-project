// FUN_fffffff0082128c0 @ fffffff0082128c0 size=8

undefined8 FUN_fffffff0082128c0(long param_1)

{
  long *plVar1;
  undefined8 *puVar2;
  
  plVar1 = *(long **)(*(long *)(*(long *)(param_1 + 0x20) + 0xc0) + 0x318);
  puVar2 = (undefined8 *)(*plVar1 + 0xe8);
  (*(code *)*puVar2)(puVar2,plVar1,FUN_fffffff00816b838,*(long *)(param_1 + 0x20),0,0,0);
  return 0;
}

