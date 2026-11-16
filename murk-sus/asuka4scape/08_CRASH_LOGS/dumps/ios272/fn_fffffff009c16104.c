// FUN_fffffff009c16104 @ fffffff009c16104 size=108

undefined8 FUN_fffffff009c16104(long param_1,long *param_2)

{
  undefined8 uVar1;
  
  uVar1 = (**(code **)(PTR_DAT_fffffff00806ca30 + 0x78))();
  if ((int)uVar1 != 0) {
    *(undefined1 *)(param_1 + 0x40) = 0;
    *(undefined8 *)(param_1 + 0x48) = 0;
    if (*param_2 == 0) {
      uVar1 = 0;
    }
    else {
      thunk_EXT_FUN_80110000039a2344(param_1 + 0x50,*param_2,param_2[1],param_2[2]);
      uVar1 = 1;
    }
  }
  return uVar1;
}

