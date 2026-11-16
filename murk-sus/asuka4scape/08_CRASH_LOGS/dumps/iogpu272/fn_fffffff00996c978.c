// FUN_fffffff00996c978 @ fffffff00996c978 size=204

undefined8 FUN_fffffff00996c978(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long *plVar1;
  long *plVar2;
  undefined8 uVar3;
  
  plVar1 = (long *)thunk_EXT_FUN_8011000003890f30(param_1,&DAT_fffffff00af22628);
  if ((plVar1 == (long *)0x0) ||
     (plVar2 = (long *)thunk_EXT_FUN_801100000389d0d8(1), plVar2 == (long *)0x0)) {
    uVar3 = 0;
  }
  else {
    (**(code **)(*plVar1 + 0x80))(plVar1,plVar2,1);
    uVar3 = (**(code **)(*plVar2 + 0x30))(plVar2,param_3);
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  return uVar3;
}

