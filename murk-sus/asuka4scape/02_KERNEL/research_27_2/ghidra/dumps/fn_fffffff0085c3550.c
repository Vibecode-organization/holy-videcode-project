// FUN_fffffff0085c3550 @ fffffff0085c3550 size=4
// CALLERS:
//   fffffff00afc5be8 no-fn
//   fffffff007d0dc80 no-fn
// CALLEES:

ulong FUN_fffffff0085c3550(void)

{
  code *pcVar1;
  bool bVar2;
  uint uVar3;
  ulong unaff_x19;
  long *unaff_x20;
  long unaff_x21;
  ulong uVar4;
  ulong unaff_x30;
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 extraout_q0_01 [16];
  undefined1 extraout_q0_02 [16];
  undefined1 in_q1 [16];
  undefined4 in_s2;
  undefined4 in_s3;
  undefined4 in_s4;
  undefined4 in_s5;
  undefined1 auVar5 [16];
  
  FUN_fffffff0085b56c8();
  auVar5 = FUN_fffffff0085b5668();
  thunk_FUN_fffffff00a8df19c
            (extraout_q0,in_q1,in_s2,in_s3,in_s4,in_s5,auVar5._0_8_,auVar5._8_8_,0,
             &DAT_fffffff007384e2b);
  bVar2 = FUN_fffffff0085b571c();
  if (bVar2) {
    uVar4 = (ulong)((int)unaff_x19 + 0x17);
    if ((unaff_x20 != (long *)0x0) &&
       (uVar3 = thunk_FUN_fffffff00a92d93c(unaff_x20), (uVar3 & 1) == 0)) {
      uVar4 = unaff_x19;
      if (*(long *)(unaff_x21 + 0x30) == 0) {
        auVar5 = FUN_fffffff0085b5668();
        thunk_FUN_fffffff00a8df19c
                  (extraout_q0_01,in_q1,in_s2,in_s3,in_s4,in_s5,auVar5._0_8_,auVar5._8_8_,0,
                   (byte *)"%s: !structureInput");
      }
      else {
        if (*(uint *)(unaff_x21 + 0x38) < 0xc01) {
          if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
            uVar4 = FUN_fffffff0085b3fd0
                              (extraout_q0_00,in_q1,in_s2,in_s3,in_s4,in_s5,unaff_x20,
                               *(long *)(unaff_x21 + 0x30),(ulong)*(uint *)(unaff_x21 + 0x38));
            return uVar4;
          }
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0085c35ec);
          (*pcVar1)();
        }
        auVar5 = FUN_fffffff0085b5668();
        thunk_FUN_fffffff00a8df19c
                  (extraout_q0_02,in_q1,in_s2,in_s3,in_s4,in_s5,auVar5._0_8_,auVar5._8_8_,0,
                   (byte *)"%s: unexpected structureInputSize=%d");
      }
    }
  }
  else {
    uVar4 = (ulong)((int)unaff_x19 - 1);
  }
  return uVar4;
}

