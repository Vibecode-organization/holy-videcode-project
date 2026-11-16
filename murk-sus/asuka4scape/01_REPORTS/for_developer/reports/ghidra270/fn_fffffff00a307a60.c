// FUN_fffffff00a307a60 @ fffffff00a307a60 size=316

undefined8
FUN_fffffff00a307a60
          (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,uint param_5,
          undefined8 param_6,undefined8 param_7,undefined8 param_8,uint *param_9,uint *param_10,
          undefined4 param_11)

{
  uint uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar2 = 4;
  if ((param_1 != 0) && ((param_5 & 0xffefbf96) == 0)) {
    uVar1 = *param_10;
    if ((*param_9 < 8 && uVar1 < 8) && ((*param_9 & (uVar1 ^ 0xffffffff)) == 0)) {
      if (((uVar1 ^ 0xffffffff) & 6) == 0) {
        uVar2 = 2;
      }
      else {
        if (((int)param_8 == 0) && (1 < uVar1)) {
          uVar2 = 0;
          uVar3 = 0;
        }
        else {
          uVar2 = 1;
          uVar3 = 8;
        }
        uVar3 = FUN_fffffff00a1e14f8(param_6,uVar2,uVar3);
        uVar2 = FUN_fffffff00a2ac7fc
                          (param_1,param_2,param_3,param_4,param_5 & 0x4069 ^ 0x100001,uVar3,param_7
                           ,param_8,param_9,param_10,param_11);
        FUN_fffffff00a2aa648(uVar3);
        if ((int)uVar2 == 0) {
          FUN_fffffff00a1b894c(param_6);
          uVar2 = 0;
        }
      }
    }
  }
  return uVar2;
}

