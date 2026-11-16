// FUN_fffffff009a780fc @ fffffff009a780fc size=184
// CALLERS:
//   fffffff00afe82e2 no-fn
//   fffffff007e742e0 no-fn
//   fffffff009a76760 FUN_fffffff009a7672c@fffffff009a7672c
//   fffffff009a7864c FUN_fffffff009a78620@fffffff009a78620
//   fffffff009a7d6c8 FUN_fffffff009a7d52c@fffffff009a7d52c
//   fffffff009a832d0 FUN_fffffff009a8322c@fffffff009a8322c
//   fffffff008eb8b9c thunk_FUN_fffffff009a780fc@fffffff008eb8b90
// CALLEES:
//   fffffff009a781b4 FUN_fffffff009a781b4
//   fffffff009a932e4 FUN_fffffff009a932e4

undefined8
FUN_fffffff009a780fc
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,long *param_8,
          long *param_9,uint param_10)

{
  int iVar1;
  long *plVar2;
  undefined1 auVar3 [16];
  
  plVar2 = param_9;
  if ((param_10 & 1) == 0) {
    plVar2 = (long *)0x0;
    FUN_fffffff009a932e4
              (param_1,param_2,param_3,param_4,param_5,param_6,*(long **)(param_7 + 0x438),1,0);
  }
  iVar1 = (int)plVar2;
  auVar3 = (**(code **)(*param_8 + 0x90))(param_8,1);
  FUN_fffffff009a781b4(auVar3,param_2,param_3,param_4,param_5,param_6,param_7,0,iVar1);
  auVar3 = (**(code **)(*param_9 + 0x90))(param_9,param_8);
  if ((param_10 & 1) == 0) {
    FUN_fffffff009a932e4
              (auVar3,param_2,param_3,param_4,param_5,param_6,*(long **)(param_7 + 0x438),0,0);
  }
  return 0;
}

