// FUN_fffffff009c3906c @ fffffff009c3906c size=40

undefined8 FUN_fffffff009c3906c(long param_1,undefined8 param_2,long param_3)

{
  undefined8 uVar1;
  
  if (*(long *)(param_3 + 0x10) != 0) {
    uVar1 = FUN_fffffff009c35850
                      (*(undefined8 *)(param_1 + 0xe8),*(long *)(param_3 + 0x10),
                       *(undefined8 *)(param_3 + 0x30),param_1);
    return uVar1;
  }
  return 0xe00002c2;
}

