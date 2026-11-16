// FUN_fffffff009c9969c @ fffffff009c9969c

long * FUN_fffffff009c9969c
                 (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
                 undefined1 param_4 [16],undefined4 param_5,undefined4 param_6)

{
  long *plVar1;
  undefined8 *puVar2;
  ulong uVar3;
  long *plVar4;
  
  plVar1 = (long *)thunk_FUN_fffffff00a8983cc
                             (param_1,param_2,param_3,param_4,param_5,param_6,
                              (long *)&DAT_fffffff00807f3f8,(ulong *)&DAT_00000018);
  puVar2 = (undefined8 *)thunk_FUN_fffffff00a8984ec(plVar1);
  *puVar2 = &PTR_thunk_FUN_fffffff00a8982e0_fffffff00807e318;
  thunk_FUN_fffffff00a8962a0(-0xff50b6f28);
  uVar3 = (**(code **)(*plVar1 + 0x68))(plVar1);
  if ((uVar3 & 1) == 0) {
    (**(code **)(*plVar1 + 0x28))(plVar1);
    plVar1 = (long *)0x0;
  }
  else {
    plVar4 = thunk_FUN_fffffff00a89a1f4(8);
    plVar1[2] = (long)plVar4;
  }
  return plVar1;
}

