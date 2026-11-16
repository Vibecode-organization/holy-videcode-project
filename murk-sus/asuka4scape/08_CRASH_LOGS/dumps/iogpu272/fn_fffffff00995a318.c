// FUN_fffffff00995a318 @ fffffff00995a318 size=120

void FUN_fffffff00995a318(long param_1,long param_2,uint param_3)

{
  long *plVar1;
  long local_30;
  ulong local_28;
  
  if (param_2 != 0) {
    local_28 = (ulong)param_3;
    local_30 = param_2;
    FUN_fffffff0099830b8(*(undefined8 *)(param_1 + 0x28));
    plVar1 = (long *)FUN_fffffff0099830ac(*(undefined8 *)(param_1 + 0x28));
    (**(code **)(*plVar1 + 0x90))(plVar1,&local_30,0x10);
    FUN_fffffff0099830c4(*(undefined8 *)(param_1 + 0x28));
  }
  return;
}

