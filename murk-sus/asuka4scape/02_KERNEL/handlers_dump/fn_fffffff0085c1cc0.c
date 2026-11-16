// FUN_fffffff0085c1cc0 @ fffffff0085c1cc0 size=200 depth=0
// CALLERS:
//   fffffff00afc5bbb ?
//   fffffff007d0da58 ?
// CALLS:
//   fffffff0085b5700 FUN_fffffff0085b5700
//   fffffff0085b571c FUN_fffffff0085b571c
//   fffffff0085c5910 thunk_FUN_fffffff00a92d93c

undefined8 FUN_fffffff0085c1cc0(long *param_1,undefined8 param_2,long param_3)

{
  code *pcVar1;
  bool bVar2;
  uint uVar3;
  undefined8 extraout_x1;
  long extraout_x16;
  undefined8 uVar4;
  ulong unaff_x30;
  
  bVar2 = FUN_fffffff0085b571c();
  if (bVar2) {
    uVar4 = 0xe00002d9;
    if ((((param_1 != (long *)0x0) &&
         (uVar3 = thunk_FUN_fffffff00a92d93c(param_1), (uVar3 & 1) == 0)) &&
        (uVar4 = 0xe00002c2, *(long *)(param_3 + 0x58) != 0)) && (*(uint *)(param_3 + 0x60) < 0x22))
    {
      FUN_fffffff0085b5700();
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff0085c1d64. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
        uVar4 = (**(code **)(extraout_x16 + 0x588))
                          (param_1,extraout_x1,(uint *)(param_3 + 0x60),
                           (undefined8 *)(extraout_x16 + 0x588));
        return uVar4;
      }
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0085c1d5c);
      (*pcVar1)();
    }
  }
  else {
    uVar4 = 0xe00002c1;
  }
  return uVar4;
}

