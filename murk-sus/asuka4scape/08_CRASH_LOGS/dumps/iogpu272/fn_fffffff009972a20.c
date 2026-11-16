// FUN_fffffff009972a20 @ fffffff009972a20 size=244

/* WARNING: Removing unreachable block (ram,0xfffffff009972acc) */

void FUN_fffffff009972a20(long param_1)

{
  undefined4 uVar1;
  ulong uVar2;
  long *plVar3;
  undefined8 uVar4;
  
  uVar2 = thunk_EXT_FUN_80110000038905ac(0,1,&DAT_fffffff00af22960);
  if ((uVar2 & 1) == 0) {
    while (DAT_fffffff00af22960 == (long *)0x1) {
      thunk_EXT_FUN_8011000003247bfc(0);
    }
  }
  else {
    DAT_fffffff00af22960 = (long *)thunk_EXT_FUN_8011000002c331f8(*(undefined8 *)(param_1 + 0xf8));
  }
  plVar3 = (long *)(**(code **)(*DAT_fffffff00af22960 + 0xe8))(DAT_fffffff00af22960,0);
  *(long **)(param_1 + 0x170) = plVar3;
  if (plVar3 == (long *)0x0) {
    *(undefined8 *)(param_1 + 0x178) = 0;
    uVar1 = 0;
  }
  else {
    uVar4 = (**(code **)(*plVar3 + 0x78))();
    *(undefined8 *)(param_1 + 0x178) = uVar4;
    uVar1 = (**(code **)(*DAT_fffffff00af22960 + 0x140))(*DAT_fffffff00af22960 + 0x140);
  }
  *(undefined4 *)(param_1 + 0x180) = uVar1;
  return;
}

