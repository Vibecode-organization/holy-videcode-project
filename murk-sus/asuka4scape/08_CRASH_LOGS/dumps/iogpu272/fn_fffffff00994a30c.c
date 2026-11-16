// FUN_fffffff00994a30c @ fffffff00994a30c size=128

undefined8
FUN_fffffff00994a30c
          (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = thunk_EXT_FUN_8011000003271d1c
                    (*(undefined8 *)(*(long *)(*(long *)(param_1 + 0x120) + 0x48) + 0x2e0));
  uVar2 = FUN_fffffff0099669e0(*(undefined8 *)(param_1 + 0x120),param_2,param_3,param_4,param_5);
  thunk_EXT_FUN_8011000003271d1c(uVar1);
  return uVar2;
}

