// FUN_fffffff00994e744 @ fffffff00994e744 size=108

undefined8 FUN_fffffff00994e744(long param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  
  uVar1 = (**(code **)(PTR_DAT_fffffff007ff27f8 + 0x78))();
  if ((int)uVar1 != 0) {
    thunk_EXT_FUN_80110000039a2344(param_1 + 0x10,*param_2,param_2[1],param_2[2]);
    *(undefined1 *)(param_1 + 0xc) = 1;
  }
  return uVar1;
}

