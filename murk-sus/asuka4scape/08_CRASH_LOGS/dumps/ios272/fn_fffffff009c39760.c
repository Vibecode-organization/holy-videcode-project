// FUN_fffffff009c39760 @ fffffff009c39760 size=100

undefined8 FUN_fffffff009c39760(long param_1,undefined8 param_2,long param_3)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  
  if (*(long **)(param_1 + 0x138) != (long *)0x0) {
    puVar2 = *(undefined8 **)(param_3 + 0x48);
    uVar1 = (**(code **)(**(long **)(param_1 + 0x138) + 0x78))();
    *puVar2 = uVar1;
    return 0;
  }
  return 0xe00002bd;
}

