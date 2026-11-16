// FUN_fffffff0081c3efc @ fffffff0081c3efc size=56

undefined8 FUN_fffffff0081c3efc(long param_1,undefined4 param_2,int param_3)

{
  long lVar1;
  
  if (param_3 == 0) {
    lVar1 = 0x1bf4;
  }
  else {
    *(undefined4 *)(param_1 + 0x1bf8) = param_2;
    lVar1 = 0x1bf8;
  }
  *(uint *)(param_1 + 0x1bfc) = (uint)(param_3 != 0);
  *(undefined4 *)(*(long *)(param_1 + 0x348) + 0x9b8) = *(undefined4 *)(param_1 + lVar1);
  return 0;
}

