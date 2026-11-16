// FUN_fffffff009c4405c @ fffffff009c4405c size=276

undefined8
FUN_fffffff009c4405c
          (long *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5
          )

{
  long *plVar1;
  ulong uVar2;
  undefined8 uVar3;
  
  plVar1 = (long *)FUN_fffffff009c42814(param_1,param_4);
  if (plVar1 == (long *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar2 = FUN_fffffff009c44170(plVar1,param_5);
    if ((uVar2 & 1) == 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,"%s pool off limits for poolId 0x%llX\n"
                );
      uVar3 = 0;
    }
    else {
      if (param_1 != (long *)0x0) {
        (**(code **)(*param_1 + 0x20))(param_1);
      }
      uVar3 = FUN_fffffff009c443e0(plVar1,param_2,param_3);
    }
    (**(code **)(*plVar1 + 0x28))(plVar1);
  }
  return uVar3;
}

