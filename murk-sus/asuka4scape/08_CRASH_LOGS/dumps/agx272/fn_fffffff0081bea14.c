// FUN_fffffff0081bea14 @ fffffff0081bea14 size=128

/* WARNING: Removing unreachable block (ram,0xfffffff0081bea64) */

undefined8 FUN_fffffff0081bea14(long *param_1,undefined1 param_2)

{
  undefined1 uVar1;
  
  *(undefined1 *)((long)param_1 + 0x1b51) = param_2;
  *(undefined1 *)(param_1 + 0x36b) = 1;
  *(undefined1 *)(param_1[0x69] + 0xdc) = 1;
  uVar1 = (**(code **)(*param_1 + 0x848))(*param_1 + 0x848);
  *(undefined1 *)(param_1[0x69] + 0xd5) = uVar1;
  return 0;
}

