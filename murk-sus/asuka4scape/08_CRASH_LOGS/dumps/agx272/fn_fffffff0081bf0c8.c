// FUN_fffffff0081bf0c8 @ fffffff0081bf0c8 size=428

/* WARNING: Removing unreachable block (ram,0xfffffff0081bf1dc) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081bf188) */

void FUN_fffffff0081bf0c8(long *param_1)

{
  undefined8 uVar1;
  long lVar2;
  
  lVar2 = param_1[0x101];
  *(long *)(lVar2 + 0x254) = param_1[0x5d];
  *(long *)(lVar2 + 0x25c) = param_1[0x5e];
  *(long *)(lVar2 + 0x264) = param_1[0x5f];
  *(long *)(lVar2 + 0x26c) = param_1[0x61];
  if (*(int *)(param_1[0x50] + 0x10934) != 0) {
    uVar1 = (**(code **)(*param_1 + 0x208))(param_1,*(undefined8 *)(param_1[0x50] + 0x11f58),0);
    *(undefined8 *)(lVar2 + 0x2c8) = uVar1;
    uVar1 = (**(code **)(*param_1 + 0x208))
                      (*param_1 + 0x208,param_1,*(undefined8 *)(param_1[0x50] + 0x11f60),0);
    *(undefined8 *)(lVar2 + 0x2d0) = uVar1;
    uVar1 = (**(code **)(*param_1 + 0x208))
                      (*param_1 + 0x208,param_1,*(undefined8 *)(param_1[0x50] + 0x11f68),0);
    *(undefined8 *)(lVar2 + 0x2d8) = uVar1;
  }
  *(undefined8 *)(param_1[0x123] + 0x644) = 0;
  *(long *)(param_1[0x101] + 0x485) = param_1[0x60];
  *(long *)(param_1[0x101] + 0x10) = param_1[99];
  *(long *)(param_1[0x101] + 8) = param_1[0x62];
  *(long *)param_1[0x101] = param_1[0x5c];
  *(long *)(param_1[0x101] + 0x200) = param_1[0x106];
  *(undefined4 *)(param_1[0x101] + 0x250) = 0;
  *(undefined4 *)param_1[0x107] = *(undefined4 *)((long)param_1 + 0x8fc);
  *(undefined4 *)param_1[0x122] = 0;
  return;
}

