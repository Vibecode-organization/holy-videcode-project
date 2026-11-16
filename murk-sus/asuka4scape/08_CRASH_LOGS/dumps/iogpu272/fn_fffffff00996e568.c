// FUN_fffffff00996e568 @ fffffff00996e568 size=116

undefined8 FUN_fffffff00996e568(long *param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0xe00002eb;
  if ((*(char *)((long)param_1 + 0x4d) != '\x02') &&
     (uVar1 = (**(code **)(*param_1 + 0xc0))(), (int)uVar1 == -0x1ffffd15)) {
    *(undefined1 *)((long)param_1 + 0x4d) = 2;
    uVar1 = 0xe00002eb;
  }
  return uVar1;
}

