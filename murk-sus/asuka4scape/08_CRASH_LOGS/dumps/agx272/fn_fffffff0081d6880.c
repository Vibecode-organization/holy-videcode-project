// FUN_fffffff0081d6880 @ fffffff0081d6880 size=80

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fffffff0081d6880(undefined8 param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  
  param_2[5] = 0xffff0000ffff;
  param_2[4] = 0xffff0000ffff;
  param_2[7] = 0xffff0000ffff;
  param_2[6] = 0xffff0000ffff;
  *(undefined4 *)(param_2 + 8) = 0xffff;
  *(undefined8 *)((long)param_2 + 0xe4) = 0xffffffffffffffff;
  *(undefined8 *)((long)param_2 + 0xdc) = 0xffffffffffffffff;
  *(undefined8 *)((long)param_2 + 0xd4) = 0xffffffffffffffff;
  *(undefined8 *)((long)param_2 + 0xcc) = 0xffffffffffffffff;
  *(undefined8 *)((long)param_2 + 0xfc) = 0xffffffffffffffff;
  *(undefined8 *)((long)param_2 + 0xf4) = 0xffffffffffffffff;
  *(ulong *)((long)param_2 + 0x5d4) =
       *(ulong *)((long)param_2 + 0x5d4) & 0xffffffffffffffe7 | 0xc00007;
  uVar1 = _DAT_fffffff007113ad0;
  param_2[1] = _UNK_fffffff007113ad8;
  *param_2 = uVar1;
  param_2[3] = 0xffff0000ffff;
  param_2[2] = 0xffff0000ffff;
  return;
}

