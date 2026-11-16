// FUN_fffffff0085c2308 @ fffffff0085c2308 size=200 depth=0
// CALLERS:
//   fffffff00afc5bcf ?
//   fffffff007d0db48 ?
// CALLS:
//   fffffff0085b56c8 FUN_fffffff0085b56c8
//   fffffff0085c59d0 thunk_FUN_fffffff00a1d14a0
//   fffffff0085b57a0 FUN_fffffff0085b57a0
//   fffffff0085b571c FUN_fffffff0085b571c
//   fffffff0085c5910 thunk_FUN_fffffff00a92d93c

ulong FUN_fffffff0085c2308(void)

{
  code *pcVar1;
  bool bVar2;
  uint uVar3;
  ulong uVar4;
  long extraout_x16;
  ulong unaff_x19;
  long *unaff_x20;
  long unaff_x21;
  ulong uVar5;
  ulong unaff_x30;
  
  FUN_fffffff0085b56c8();
  bVar2 = FUN_fffffff0085b571c();
  if (bVar2) {
    uVar5 = (ulong)((int)unaff_x19 + 0x17);
    if ((((unaff_x20 != (long *)0x0) &&
         (uVar3 = thunk_FUN_fffffff00a92d93c(unaff_x20), (uVar3 & 1) == 0)) &&
        (uVar5 = unaff_x19, *(ulong *)(unaff_x21 + 0x30) != 0)) &&
       (uVar3 = *(uint *)(unaff_x21 + 0x38),
       uVar4 = thunk_FUN_fffffff00a1d14a0(*(ulong *)(unaff_x21 + 0x30),(ulong)uVar3), uVar4 <= uVar3
       )) {
      FUN_fffffff0085b57a0();
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff0085c23ac. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
        uVar5 = (**(code **)(extraout_x16 + 0x578))();
        return uVar5;
      }
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0085c23a4);
      (*pcVar1)();
    }
  }
  else {
    uVar5 = (ulong)((int)unaff_x19 - 1);
  }
  return uVar5;
}

