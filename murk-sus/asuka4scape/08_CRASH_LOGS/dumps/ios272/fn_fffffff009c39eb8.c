// FUN_fffffff009c39eb8 @ fffffff009c39eb8 size=52

undefined8 FUN_fffffff009c39eb8(undefined8 param_1,undefined8 param_2,long param_3)

{
  undefined8 uVar1;
  
  if (*(long *)(param_3 + 0x40) != 0) {
    return 0xe00002c2;
  }
  uVar1 = FUN_fffffff009c40588
                    (param_1,**(undefined4 **)(param_3 + 0x20),
                     *(undefined8 *)(*(undefined4 **)(param_3 + 0x20) + 2),
                     *(undefined4 *)(param_3 + 0x38),*(undefined8 *)(param_3 + 0x30));
  return uVar1;
}

