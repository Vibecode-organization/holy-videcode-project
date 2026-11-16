// FUN_fffffff009c39eec @ fffffff009c39eec size=60

undefined8 FUN_fffffff009c39eec(undefined8 param_1,undefined8 param_2,long param_3)

{
  undefined8 uVar1;
  
  if (*(long *)(param_3 + 0x68) != 0) {
    return 0xe00002c2;
  }
  uVar1 = FUN_fffffff009c4060c
                    (param_1,**(undefined4 **)(param_3 + 0x20),
                     *(undefined8 *)(*(undefined4 **)(param_3 + 0x20) + 2),
                     *(undefined4 *)(param_3 + 0x60),*(long *)(param_3 + 0x48),
                     *(long *)(param_3 + 0x48) + 8,(undefined4 *)(param_3 + 0x60),
                     *(undefined8 *)(param_3 + 0x58));
  return uVar1;
}

