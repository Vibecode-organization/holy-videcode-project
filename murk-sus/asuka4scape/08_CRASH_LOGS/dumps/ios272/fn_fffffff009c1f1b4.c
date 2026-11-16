// FUN_fffffff009c1f1b4 @ fffffff009c1f1b4 size=4

void FUN_fffffff009c1f1b4(long *param_1)

{
  long *plVar1;
  undefined8 uStack_30;
  long lStack_28;
  
  lStack_28 = *(long *)PTR_DAT_fffffff00806ca40;
  uStack_30 = 0;
  thunk_EXT_FUN_80110000032db760(param_1[6],&uStack_30);
  thunk_EXT_FUN_80110000036da494(0x85210024,uStack_30,(int)param_1[2],0,0,0);
  plVar1 = (long *)param_1[6];
  if ((plVar1 != (long *)0x0) && ((*(byte *)((long)param_1 + 0x3d1) >> 2 & 1) != 0)) {
    (**(code **)(*plVar1 + 0xe0))(plVar1,0);
  }
  FUN_fffffff009c1f2d4(param_1);
  if ((int)param_1[2] != 0) {
    param_1[0x2f] = 0;
    param_1[0x60] = 0;
    FUN_fffffff009c35dcc(DAT_fffffff00af483b0,param_1);
    *(undefined4 *)(param_1 + 2) = 0;
  }
  if (param_1[0x4c] != 0) {
    param_1[0x4c] = 0;
    thunk_EXT_FUN_80110000038fe270(&DAT_fffffff00806aef0);
    param_1[0x4c] = 0;
  }
  (**(code **)(*param_1 + 0x70))(param_1);
  if (*(long *)PTR_DAT_fffffff00806ca40 == lStack_28) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590();
  return;
}

