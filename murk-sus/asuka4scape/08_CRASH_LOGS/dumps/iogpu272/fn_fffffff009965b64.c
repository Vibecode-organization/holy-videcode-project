// FUN_fffffff009965b64 @ fffffff009965b64 size=188

undefined8 FUN_fffffff009965b64(long param_1,undefined8 param_2,ulong *param_3)

{
  uint uVar1;
  long *plVar2;
  ulong uVar3;
  
  plVar2 = (long *)FUN_fffffff00997fc84(*(undefined8 *)(param_1 + 0x48));
  if (plVar2 != (long *)0x0) {
    uVar1 = thunk_FUN_fffffff009944798(*(undefined8 *)(param_1 + 0x18),plVar2);
    if (uVar1 != 0) {
      uVar3 = plVar2[0x51];
      *param_3 = (ulong)uVar1;
      param_3[1] = uVar3;
      param_3[2] = plVar2[7];
      (**(code **)(*plVar2 + 0x28))(plVar2);
      return 0;
    }
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  *param_3 = 0;
  param_3[1] = 0;
  param_3[2] = 0;
  return 0xe00002bd;
}

