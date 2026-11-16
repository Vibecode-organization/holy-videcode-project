// FUN_fffffff00817e544 @ fffffff00817e544 size=216

undefined8 FUN_fffffff00817e544(long param_1,long *param_2)

{
  uint uVar1;
  long lVar2;
  long *plVar3;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x11e48));
  if ((int)param_2[5] == 0) {
    FUN_fffffff0081e1178(param_2);
    uVar1 = *(uint *)(param_1 + 0x11ed0);
    if (uVar1 < 0x10) {
      *(uint *)(param_1 + 0x11ed0) = uVar1 + 1;
      lVar2 = (ulong)uVar1 * 8;
      plVar3 = (long *)(param_1 + 0x11e50 + (long)(int)lVar2);
      if (lVar2 - (int)lVar2 != 0) {
        plVar3 = (long *)(param_1 + 0x11e50 + lVar2 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *plVar3 = (long)param_2;
    }
    else {
      (**(code **)(*param_2 + 0x28))(param_2);
    }
  }
  else {
    param_2[7] = 0;
    plVar3 = *(long **)(param_1 + 0x11ee0);
    param_2[8] = (long)plVar3;
    *plVar3 = (long)param_2;
    *(long **)(param_1 + 0x11ee0) = param_2 + 7;
    *(undefined1 *)((long)param_2 + 0xc) = 1;
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x11e48));
  return 0;
}

