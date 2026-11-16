// FUN_fffffff009c49430 @ fffffff009c49430 size=88
// CALLERS:
//   fffffff00afec2a3 no-fn
//   fffffff009c42858 FUN_fffffff009c42814@fffffff009c42814
//   fffffff009c44dbc FUN_fffffff009c44d30@fffffff009c44d30
//   fffffff009c1f384 FUN_fffffff009c1f34c@fffffff009c1f34c
//   fffffff009c17f5c FUN_fffffff009c17f54@fffffff009c17f54
//   fffffff009c410f0 FUN_fffffff009c410e8@fffffff009c410e8
//   fffffff009c43fbc FUN_fffffff009c43fb4@fffffff009c43fb4
// CALLEES:
//   fffffff009c46fc8 FUN_fffffff009c46fc8

bool FUN_fffffff009c49430
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,uint *param_7)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *param_7;
  do {
    uVar2 = uVar1;
    if (uVar2 == 0) goto LAB_fffffff009c49474;
    param_1 = FUN_fffffff009c46fc8(param_1,param_2,param_3,param_4,param_5,param_6,param_7,uVar2);
    uVar1 = *param_7;
  } while (*param_7 != uVar2);
  *param_7 = uVar2 + 1;
LAB_fffffff009c49474:
  return uVar2 != 0;
}

