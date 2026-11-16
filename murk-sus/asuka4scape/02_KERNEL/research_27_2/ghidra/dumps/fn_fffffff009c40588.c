// FUN_fffffff009c40588 @ fffffff009c40588 size=132
// CALLERS:
//   fffffff00afec136 no-fn
//   fffffff009c39ee8 FUN_fffffff009c39eb8@fffffff009c39eb8
// CALLEES:
//   fffffff009c2a76c FUN_fffffff009c2a76c
//   fffffff009c3f1d0 FUN_fffffff009c3f1d0

undefined8
FUN_fffffff009c40588
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,uint param_8,
          ulong param_9,ulong *param_10,undefined8 *param_11)

{
  long *plVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  undefined1 extraout_q0 [16];
  
  puVar3 = param_11;
  plVar1 = FUN_fffffff009c3f1d0(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  if (plVar1 == (long *)0x0) {
    uVar2 = 0xe00002c2;
  }
  else {
    uVar2 = FUN_fffffff009c2a76c
                      (extraout_q0,param_2,param_3,param_4,param_5,param_6,(long)plVar1,param_9,
                       param_10,param_11,(undefined *)puVar3);
    (**(code **)(*plVar1 + 0x28))(plVar1);
  }
  return uVar2;
}

