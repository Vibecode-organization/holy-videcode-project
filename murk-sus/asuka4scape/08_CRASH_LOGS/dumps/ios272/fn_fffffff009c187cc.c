// FUN_fffffff009c187cc @ fffffff009c187cc size=172

undefined8
FUN_fffffff009c187cc
          (long param_1,long param_2,long param_3,undefined8 param_4,undefined8 param_5,
          undefined8 param_6)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (((param_2 != 0) && (param_3 != 0)) &&
     (uVar1 = (**(code **)(PTR_DAT_fffffff00806ca30 + 0x78))(param_1), (int)uVar1 != 0)) {
    FUN_fffffff009c16670(param_1 + 0x38,param_2);
    FUN_fffffff009c18a40(param_1 + 0x40,param_3);
    *(long *)(param_1 + 0x48) = param_3;
    *(undefined8 *)(param_1 + 0x10) = param_4;
    *(undefined8 *)(param_1 + 0x18) = param_5;
    *(undefined8 *)(param_1 + 0x20) = param_6;
    *(byte *)(param_1 + 0x68) = *(byte *)(*(long *)(param_1 + 0x40) + 0x40) & 1;
    uVar1 = 1;
  }
  return uVar1;
}

