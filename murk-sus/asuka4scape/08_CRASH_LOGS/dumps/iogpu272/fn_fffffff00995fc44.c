// FUN_fffffff00995fc44 @ fffffff00995fc44 size=216

ulong FUN_fffffff00995fc44(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long *plVar1;
  long *plVar2;
  ulong uVar3;
  
  plVar1 = (long *)thunk_EXT_FUN_8011000003890f30(param_1,&DAT_fffffff00af22560);
  uVar3 = 0;
  if (plVar1 != (long *)0x0) {
    plVar2 = (long *)thunk_EXT_FUN_801100000389d0d8(1);
    if (plVar2 == (long *)0x0) {
      uVar3 = 0;
    }
    else {
      uVar3 = (**(code **)(*plVar1 + 0xb0))(plVar1,plVar2);
      if ((uVar3 & 1) != 0) {
        (**(code **)(*plVar2 + 0x30))(plVar2,param_3);
      }
      (**(code **)(*plVar2 + 0x28))(plVar2);
    }
  }
  return uVar3;
}

