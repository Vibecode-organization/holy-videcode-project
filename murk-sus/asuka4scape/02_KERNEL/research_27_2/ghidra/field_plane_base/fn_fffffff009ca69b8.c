// FUN_fffffff009ca69b8 @ fffffff009ca69b8

long * FUN_fffffff009ca69b8
                 (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
                 undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,undefined8 param_7,
                 undefined8 param_8,undefined8 param_9,undefined8 param_10,undefined8 param_11,
                 undefined8 param_12,undefined8 param_13,undefined8 param_14)

{
  long *plVar1;
  undefined8 *puVar2;
  ulong uVar3;
  
  plVar1 = (long *)thunk_FUN_fffffff00a8983cc
                             (param_1,param_2,param_3,param_4,param_5,param_6,
                              (long *)&DAT_fffffff00807f4f8,(ulong *)0x90);
  puVar2 = (undefined8 *)thunk_FUN_fffffff00a969de8(plVar1);
  *puVar2 = &PTR_thunk_FUN_fffffff00a969e48_fffffff00807ece8;
  thunk_FUN_fffffff00a8962a0(-0xff50b6e88);
  uVar3 = (**(code **)(*plVar1 + 0x80))
                    (plVar1,param_7,param_8,param_9,param_10,param_11,param_12,param_13,param_14);
  if ((uVar3 & 1) == 0) {
    (**(code **)(*plVar1 + 0x28))(plVar1);
    plVar1 = (long *)0x0;
  }
  return plVar1;
}

