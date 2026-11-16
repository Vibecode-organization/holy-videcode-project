// FUN_fffffff009c2ec2c @ fffffff009c2ec2c size=68

undefined4 FUN_fffffff009c2ec2c(long param_1,uint param_2)

{
  long lVar1;
  long lVar2;
  undefined4 *puVar3;
  
  if (param_2 < 3) {
    lVar1 = *(long *)(param_1 + 0x10) + 0x30;
    lVar2 = (ulong)(param_2 * 0x60) + 0x24;
    puVar3 = (undefined4 *)(lVar1 + (int)lVar2);
    if (lVar2 != (int)lVar2) {
      puVar3 = (undefined4 *)(lVar1 + lVar2 & 0xffffffffffffU | 0x2bad000000000000);
    }
    return *puVar3;
  }
  return 0;
}

