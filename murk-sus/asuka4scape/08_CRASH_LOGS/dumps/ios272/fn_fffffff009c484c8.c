// FUN_fffffff009c484c8 @ fffffff009c484c8 size=100

undefined8 FUN_fffffff009c484c8(long param_1,long param_2)

{
  undefined8 uVar1;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x18));
  uVar1 = (**(code **)(**(long **)(param_1 + 0x30) + 0xb8))
                    (*(long **)(param_1 + 0x30),*(undefined8 *)(param_2 + 0x88),
                     *(undefined8 *)(param_2 + 0x90));
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x18));
  return uVar1;
}

