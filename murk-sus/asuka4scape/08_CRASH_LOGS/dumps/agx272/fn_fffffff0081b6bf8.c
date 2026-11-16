// FUN_fffffff0081b6bf8 @ fffffff0081b6bf8 size=296

long * FUN_fffffff0081b6bf8(long param_1,undefined8 param_2,int param_3,uint param_4)

{
  ulong uVar1;
  ulong uVar2;
  long *plVar3;
  long *plVar4;
  long *plVar5;
  
  plVar3 = (long *)thunk_EXT_FUN_801100000297d1cc(*(undefined8 *)(param_1 + 0x280),0,param_2);
  if (plVar3 == (long *)0x0) {
    plVar5 = (long *)0x0;
  }
  else {
    uVar1 = 0x20900000000;
    if (param_4 != 9) {
      uVar1 = (ulong)param_4 << 0x20;
    }
    uVar2 = 7;
    if (param_3 == 0) {
      uVar2 = 0x10000000005;
    }
    plVar4 = (long *)(**(code **)(*plVar3 + 0x90))
                               (plVar3,*(undefined8 *)(*(long *)(param_1 + 0x280) + 0x11da0),
                                uVar2 | uVar1);
    plVar5 = (long *)thunk_EXT_FUN_8011000003890f30(plVar4,&DAT_fffffff00ae23a70);
    if (plVar5 != (long *)0x0) {
      (**(code **)(*plVar5 + 0x20))(plVar5);
    }
    if (plVar4 != (long *)0x0) {
      (**(code **)(*plVar4 + 0x28))(plVar4);
    }
    (**(code **)(*plVar3 + 0x28))(plVar3);
  }
  return plVar5;
}

