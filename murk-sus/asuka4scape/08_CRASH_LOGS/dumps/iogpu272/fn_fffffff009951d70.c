// FUN_fffffff009951d70 @ fffffff009951d70 size=204

long * FUN_fffffff009951d70
                 (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long *plVar1;
  undefined8 *puVar2;
  ulong uVar3;
  
  plVar1 = (long *)thunk_EXT_FUN_80110000038943cc(&DAT_fffffff007ff03e8,0x68);
  puVar2 = (undefined8 *)FUN_fffffff00994d73c(plVar1,&DAT_fffffff00af22420);
  *puVar2 = &DAT_fffffff007fec318;
  thunk_EXT_FUN_80110000038922a0(&DAT_fffffff00af22420);
  uVar3 = FUN_fffffff009951e3c(plVar1,param_1,param_2,param_3,param_4);
  if ((uVar3 & 1) == 0) {
    (**(code **)(*plVar1 + 0x28))(plVar1);
    plVar1 = (long *)0x0;
  }
  return plVar1;
}

