// FUN_fffffff009c35560 @ fffffff009c35560 size=416

undefined8 FUN_fffffff009c35560(long param_1,undefined8 param_2)

{
  long *plVar1;
  long *plVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long *plVar5;
  
  plVar1 = (long *)thunk_EXT_FUN_801100000389d0d8(1);
  if (plVar1 != (long *)0x0) {
    FUN_fffffff009c23d94(param_2,plVar1,*(undefined4 *)(param_1 + 0x28),0);
    plVar2 = (long *)thunk_EXT_FUN_80110000038d4814(*(undefined4 *)(param_1 + 0x2c),0,0);
    if (plVar2 != (long *)0x0) {
      (**(code **)(*plVar2 + 0x80))();
      (**(code **)(*plVar1 + 0x30))(plVar1,plVar2);
      uVar3 = (**(code **)(*plVar2 + 0x78))(plVar2);
      uVar4 = (**(code **)(*plVar2 + 0xb8))(plVar2);
      plVar5 = (long *)thunk_EXT_FUN_801100000389a264(uVar3,uVar4);
      if (plVar5 != (long *)0x0) {
        (**(code **)(**(long **)(param_1 + 0x20) + 0xe8))(*(long **)(param_1 + 0x20),plVar5);
        (**(code **)(*plVar5 + 0x28))(plVar5);
      }
      (**(code **)(*plVar2 + 0x28))(plVar2);
    }
    (**(code **)(*plVar1 + 0x28))(plVar1);
  }
  return 0;
}

