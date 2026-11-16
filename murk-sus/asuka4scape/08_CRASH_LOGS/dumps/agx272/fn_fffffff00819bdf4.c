// FUN_fffffff00819bdf4 @ fffffff00819bdf4 size=544

undefined8 FUN_fffffff00819bdf4(long *param_1)

{
  byte bVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  
  lVar3 = param_1[0xa6];
  if ((*(byte *)(lVar3 + 0x1ac44) >> 3 & 1) != 0) {
    lVar4 = param_1[0x91];
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar3 + 0x1ac48));
    thunk_EXT_FUN_80110000036da494(0x85930d95,param_1,lVar4,0,0,0);
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar3 + 0x1ac48));
  }
  if ((5 < *(uint *)((long)param_1 + 0x44c) ||
       (1 << (ulong)(*(uint *)((long)param_1 + 0x44c) & 0x1f) & 0x31U) == 0) &&
     (iVar2 = thunk_EXT_FUN_8011000002972b50(param_1), iVar2 != 0)) {
    if (param_1[0xc2] != 0) {
      thunk_EXT_FUN_8011000002972b78(param_1);
      thunk_EXT_FUN_8011000002947a48(*(undefined8 *)(param_1[0xa6] + 0x148),param_1 + 0x93);
      bVar1 = *(byte *)((long)param_1 + 0x526);
      thunk_EXT_FUN_8011000002972b84(param_1);
      if (((bVar1 & 1) == 0) && (iVar2 = (**(code **)(*param_1 + 0x150))(param_1), iVar2 != 0)) {
        if ((*(byte *)(param_1[0xa6] + 0x1ac44) >> 3 & 1) != 0) {
          FUN_fffffff00817dc48(param_1[0xa6],0x365,2,param_1,param_1[0x91],1,0,0);
          if ((*(byte *)(param_1[0xa6] + 0x1ac44) >> 3 & 1) != 0) {
            FUN_fffffff00817dc48(param_1[0xa6],0x364,1,param_1,param_1[0x91],0,0,0);
          }
        }
        if ((long *)param_1[0xc2] != (long *)0x0) {
          (**(code **)(*(long *)param_1[0xc2] + 0x28))();
        }
        param_1[0xc2] = 0;
        if ((*(byte *)(param_1[0xa6] + 0x1ac44) >> 3 & 1) != 0) {
          FUN_fffffff00817dc48(param_1[0xa6],0x364,2,param_1,param_1[0x91],0,0,0);
        }
        thunk_EXT_FUN_8011000002972900(param_1);
        return 1;
      }
    }
    thunk_EXT_FUN_8011000002972900(param_1);
  }
  lVar3 = param_1[0xa6];
  if ((*(byte *)(lVar3 + 0x1ac44) >> 3 & 1) != 0) {
    lVar4 = param_1[0x91];
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar3 + 0x1ac48));
    thunk_EXT_FUN_80110000036da494(0x85930d96,param_1,lVar4,0,0,0);
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar3 + 0x1ac48));
  }
  return 0;
}

