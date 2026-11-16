// FUN_fffffff009941348 @ fffffff009941348 size=100

undefined8 FUN_fffffff009941348(long param_1,undefined8 param_2,uint *param_3)

{
  undefined8 uVar1;
  
  uVar1 = 0xe00002c7;
  FUN_fffffff009942d70();
  if (*(int *)(param_1 + 0xa4) == 0) {
    uVar1 = 0xe00002bd;
  }
  else if (param_3 != (uint *)0x0) {
    *param_3 = (uint)*(byte *)(param_1 + 0x35);
  }
  FUN_fffffff009942d7c(param_1);
  return uVar1;
}

