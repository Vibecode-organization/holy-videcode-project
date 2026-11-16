// FUN_fffffff0085c2d88 @ fffffff0085c2d88 size=4
// CALLERS:
//   fffffff00afc5bdc no-fn
//   fffffff007d0dbf0 no-fn
// CALLEES:

ulong FUN_fffffff0085c2d88(void)

{
  undefined1 auVar1 [16];
  code *pcVar2;
  bool bVar3;
  uint uVar4;
  ulong uVar5;
  ulong unaff_x19;
  long *unaff_x20;
  long unaff_x21;
  ulong uVar6;
  ulong uVar7;
  ulong unaff_x30;
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 extraout_q0_01 [16];
  undefined1 extraout_q0_02 [16];
  undefined1 in_q1 [16];
  undefined4 in_s2;
  undefined1 in_register_00005044 [12];
  undefined4 in_s3;
  undefined1 in_register_00005064 [12];
  undefined4 in_s4;
  undefined4 in_s5;
  undefined1 auVar8 [16];
  
  FUN_fffffff0085b56c8();
  bVar3 = FUN_fffffff0085b571c();
  if (bVar3) {
    uVar6 = (ulong)((int)unaff_x19 + 0x17);
    if ((unaff_x20 != (long *)0x0) &&
       (uVar4 = thunk_FUN_fffffff00a92d93c(unaff_x20), (uVar4 & 1) == 0)) {
      uVar7 = *(ulong *)(unaff_x21 + 0x30);
      uVar6 = unaff_x19;
      if (uVar7 == 0) {
        auVar8 = FUN_fffffff0085b5668();
        thunk_FUN_fffffff00a8df19c
                  (extraout_q0_00,in_q1,in_s2,in_s3,in_s4,in_s5,auVar8._0_8_,auVar8._8_8_,0,
                   (byte *)"%s: !structureInput");
      }
      else {
        uVar4 = *(uint *)(unaff_x21 + 0x38);
        if (uVar4 - 0x22 < 0xffffffdf) {
          auVar8 = FUN_fffffff0085b5668();
          thunk_FUN_fffffff00a8df19c
                    (extraout_q0_01,in_q1,in_s2,in_s3,in_s4,in_s5,auVar8._0_8_,auVar8._8_8_,0,
                     (byte *)"%s: size:%d");
        }
        else {
          uVar5 = thunk_FUN_fffffff00a1d14a0(uVar7,(ulong)uVar4);
          if (uVar5 < uVar4) {
            if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
              auVar8._4_12_ = in_register_00005044;
              auVar8._0_4_ = in_s2;
              auVar1._4_12_ = in_register_00005064;
              auVar1._0_4_ = in_s3;
              uVar6 = FUN_fffffff0085b359c
                                (extraout_q0,in_q1,auVar8,auVar1,in_s4,in_s5,unaff_x20,uVar7);
              return uVar6;
            }
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0085c2e18);
            (*pcVar2)();
          }
          auVar8 = FUN_fffffff0085b5668();
          thunk_FUN_fffffff00a8df19c
                    (extraout_q0_02,in_q1,in_s2,in_s3,in_s4,in_s5,auVar8._0_8_,auVar8._8_8_,0,
                     (byte *)"%s: length:%d, size:%d");
        }
      }
    }
  }
  else {
    uVar6 = (ulong)((int)unaff_x19 - 1);
  }
  return uVar6;
}

