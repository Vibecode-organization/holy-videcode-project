// FUN_fffffff009c43340 @ fffffff009c43340 size=144

void FUN_fffffff009c43340(long param_1,uint param_2)

{
  undefined8 uVar1;
  long *plVar2;
  undefined8 uVar3;
  
  if (((param_2 & 0xf00) == 0) && ((*(byte *)(param_1 + 0xd) & 0xf) != 0)) {
    uVar3 = *(undefined8 *)(param_1 + 0x18);
    uVar1 = thunk_EXT_FUN_801100000325c0a0();
    plVar2 = (long *)thunk_EXT_FUN_801100000396cb64(uVar3,uVar1,0,0x501,0,0);
    if (plVar2 != (long *)0x0) {
      (**(code **)(*plVar2 + 0x28))();
    }
  }
  *(uint *)(param_1 + 0xc) = param_2;
  return;
}

