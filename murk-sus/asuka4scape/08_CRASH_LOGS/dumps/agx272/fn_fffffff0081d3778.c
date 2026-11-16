// FUN_fffffff0081d3778 @ fffffff0081d3778 size=296

undefined8 FUN_fffffff0081d3778(long *param_1,long *param_2)

{
  undefined8 uVar1;
  long lVar2;
  
  uVar1 = (**(code **)(PTR_DAT_fffffff007ca6178 + 0x2c0))();
  if ((int)uVar1 != 0) {
    param_1[0x1a] = (long)param_2;
    (**(code **)(*param_2 + 0x20))(param_2);
    param_1[0x1c] = 0;
    lVar2 = thunk_EXT_FUN_80110000038ff010();
    param_1[0x1b] = lVar2;
    if (lVar2 == 0) {
      if ((long *)param_1[0x1a] != (long *)0x0) {
        (**(code **)(*(long *)param_1[0x1a] + 0x28))();
      }
      uVar1 = 0;
      param_1[0x1a] = 0;
    }
    else {
      param_1[0x1e] = 0;
      param_1[0x1f] = (long)(param_1 + 0x1e);
      lVar2 = thunk_EXT_FUN_80110000038ff010();
      param_1[0x1d] = lVar2;
      if (lVar2 == 0) {
        thunk_EXT_FUN_80110000038ff020(param_1[0x1b]);
        if ((long *)param_1[0x1a] != (long *)0x0) {
          (**(code **)(*(long *)param_1[0x1a] + 0x28))();
        }
        param_1[0x1a] = 0;
      }
      (**(code **)(*param_1 + 0x2a0))(param_1,0);
      uVar1 = 1;
    }
  }
  return uVar1;
}

