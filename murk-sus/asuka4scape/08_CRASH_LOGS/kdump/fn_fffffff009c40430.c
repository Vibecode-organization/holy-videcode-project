// FUN_fffffff009c40430 @ fffffff009c40430 size=216
// CALLERS:
//   fffffff00afec132 ?
//   fffffff009c396ec FUN_fffffff009c3968c@fffffff009c3968c
// CALLS:
//   fffffff009c49864 thunk_FUN_fffffff00a8a10d8
//   fffffff009c34d4c FUN_fffffff009c34d4c

undefined4
FUN_fffffff009c40430
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,long param_8,
          long *param_9)

{
  int iVar1;
  long *plVar2;
  undefined4 uVar3;
  undefined1 auVar4 [16];
  
  plVar2 = thunk_FUN_fffffff00a8a10d8(1);
  uVar3 = 0xe00002bd;
  if (plVar2 != (long *)0x0) {
    auVar4 = (**(code **)(*param_9 + 0x80))(param_9);
    FUN_fffffff009c34d4c
              (auVar4,param_2,param_3,param_4,param_5,param_6,*(long **)(param_7 + 0xe8),plVar2,
               (uint)(param_8 != 0));
    iVar1 = (**(code **)(*plVar2 + 0x30))(plVar2,param_9);
    uVar3 = 0;
    if (iVar1 == 0) {
      uVar3 = 0xe00002bd;
    }
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  return uVar3;
}

