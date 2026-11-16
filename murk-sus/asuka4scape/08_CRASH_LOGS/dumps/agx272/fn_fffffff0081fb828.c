// FUN_fffffff0081fb828 @ fffffff0081fb828 size=4

long FUN_fffffff0081fb828(long *param_1)

{
  long lVar1;
  long *plVar2;
  undefined8 uStack_30;
  long lStack_28;
  
  lVar1 = (**(code **)(*param_1 + 0x98))();
  if ((*(byte *)(param_1 + 0xb) & 1) != 0) {
    uStack_30 = 0;
    lStack_28 = 0;
    if ((ulong)*(byte *)((long)param_1 + 0x59) == 1) {
      plVar2 = &lStack_28;
      (**(code **)(*(long *)param_1[4] + 0x140))((long *)param_1[4],&lStack_28,&uStack_30);
    }
    else {
      plVar2 = (long *)(&DAT_fffffff007115148 + (ulong)*(byte *)((long)param_1 + 0x59) * 0x20);
    }
    lVar1 = lVar1 - *plVar2;
  }
  return lVar1;
}

