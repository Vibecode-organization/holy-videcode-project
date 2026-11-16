// FUN_fffffff009c39f28 @ fffffff009c39f28 size=36

undefined8 FUN_fffffff009c39f28(undefined8 param_1,undefined8 param_2,long param_3)

{
  undefined8 uVar1;
  
  if (*(long *)(param_3 + 0x68) != 0) {
    return 0xe00002c2;
  }
  uVar1 = FUN_fffffff009c40728(param_1,**(undefined4 **)(param_3 + 0x20));
  return uVar1;
}

