// FUN_fffffff0081ffbb4 @ fffffff0081ffbb4 size=320

undefined8 FUN_fffffff0081ffbb4(long param_1,ulong *param_2)

{
  uint uVar1;
  long *plVar2;
  ulong uVar3;
  long lVar4;
  undefined8 uVar5;
  
  uVar5 = *(undefined8 *)(param_1 + 0x48);
  plVar2 = (long *)(**(code **)(DAT_fffffff00ae230c8 + 0x68))();
  if (plVar2 != (long *)0x0) {
    uVar3 = FUN_fffffff0081e2424(plVar2,uVar5,0);
    if ((uVar3 & 1) != 0) {
      uVar1 = thunk_EXT_FUN_8011000002940fb0(*(undefined8 *)(param_1 + 0x100),plVar2);
      if (uVar1 == 0) {
        uVar5 = 0xe00002bd;
        *param_2 = 0;
        param_2[1] = 0;
      }
      else {
        *param_2 = (ulong)uVar1;
        uVar3 = plVar2[4];
        param_2[1] = uVar3;
        lVar4 = *(long *)(param_1 + 0x48);
        if ((*(byte *)(lVar4 + 0x1ac44) >> 3 & 1) != 0) {
          thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar4 + 0x1ac48));
          thunk_EXT_FUN_80110000036da494(0x85930ccc,plVar2,(ulong)uVar1,uVar3,0,0);
          thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar4 + 0x1ac48));
        }
        uVar5 = 0;
      }
      (**(code **)(*plVar2 + 0x28))(plVar2);
      return uVar5;
    }
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  *param_2 = 0;
  param_2[1] = 0;
  return 0xe00002bd;
}

