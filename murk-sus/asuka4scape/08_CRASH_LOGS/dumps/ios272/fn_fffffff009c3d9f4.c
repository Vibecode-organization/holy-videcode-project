// FUN_fffffff009c3d9f4 @ fffffff009c3d9f4 size=100

undefined8 FUN_fffffff009c3d9f4(long param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  
  if (*(long **)(param_1 + 0x138) != (long *)0x0) {
    uVar1 = (**(code **)(**(long **)(param_1 + 0x138) + 0x78))();
    *param_2 = uVar1;
    return 0;
  }
  return 0xe00002bd;
}

