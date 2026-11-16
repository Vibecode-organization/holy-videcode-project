// FUN_fffffff0081c3e94 @ fffffff0081c3e94 size=56

undefined8 FUN_fffffff0081c3e94(long param_1,undefined4 param_2,int param_3)

{
  long lVar1;
  
  if (param_3 == 0) {
    lVar1 = 0x1c0c;
  }
  else {
    *(undefined4 *)(param_1 + 0x1c10) = param_2;
    lVar1 = 0x1c10;
  }
  *(uint *)(param_1 + 0x1c14) = (uint)(param_3 != 0);
  *(undefined4 *)(*(long *)(param_1 + 0x348) + 0x9c0) = *(undefined4 *)(param_1 + lVar1);
  return 0;
}

