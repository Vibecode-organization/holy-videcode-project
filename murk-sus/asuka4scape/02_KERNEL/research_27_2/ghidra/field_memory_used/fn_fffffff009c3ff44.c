// FUN_fffffff009c3ff44 @ fffffff009c3ff44

undefined8
FUN_fffffff009c3ff44
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,long param_8)

{
  long *plVar1;
  long *plVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long *plVar5;
  long *plVar6;
  undefined1 extraout_q0 [16];
  
  plVar1 = thunk_FUN_fffffff00a8a10d8(1);
  if (plVar1 != (long *)0x0) {
    FUN_fffffff009c2c854
              (extraout_q0,param_2,param_3,param_4,param_5,param_6,param_8,plVar1,
               *(int *)(param_7 + 0x28));
    plVar2 = thunk_FUN_fffffff00a8d8814((ulong)*(uint *)(param_7 + 0x2c),0,0);
    if (plVar2 != (long *)0x0) {
      (**(code **)(*plVar2 + 0x80))();
      (**(code **)(*plVar1 + 0x30))(plVar1,plVar2);
      uVar3 = (**(code **)(*plVar2 + 0x78))(plVar2);
      uVar4 = (**(code **)(*plVar2 + 0xb8))(plVar2);
      plVar5 = thunk_FUN_fffffff00a89e264(uVar3,uVar4);
      if (plVar5 != (long *)0x0) {
        plVar6 = *(long **)(*(long *)(*(long *)(param_7 + 0x20) + 8) + 0x28);
        (**(code **)(*plVar6 + 0xe8))(plVar6,plVar5);
        (**(code **)(*plVar5 + 0x28))(plVar5);
      }
      (**(code **)(*plVar2 + 0x28))(plVar2);
    }
    (**(code **)(*plVar1 + 0x28))(plVar1);
  }
  return 0;
}

