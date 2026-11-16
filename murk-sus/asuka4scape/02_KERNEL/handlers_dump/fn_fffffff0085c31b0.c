// FUN_fffffff0085c31b0 @ fffffff0085c31b0 size=4 depth=0
// CALLERS:
//   fffffff00afc5be2 ?
//   fffffff007d0dc38 ?
// CALLS:

/* WARNING: Removing unreachable block (ram,0xfffffff0085c3308) */

ulong FUN_fffffff0085c31b0(void)

{
  bool bVar1;
  uint uVar2;
  long extraout_x16;
  ulong unaff_x19;
  long unaff_x20;
  long *unaff_x21;
  ulong uVar3;
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 extraout_q0_01 [16];
  undefined1 extraout_q0_02 [16];
  undefined1 extraout_q0_03 [16];
  undefined1 in_q1 [16];
  undefined4 in_s2;
  undefined4 in_s3;
  undefined4 in_s4;
  undefined4 in_s5;
  undefined1 auVar4 [16];
  
  FUN_fffffff0085b56dc();
  auVar4 = FUN_fffffff0085b5668();
  thunk_FUN_fffffff00a8df19c
            (extraout_q0,in_q1,in_s2,in_s3,in_s4,in_s5,auVar4._0_8_,auVar4._8_8_,0,
             &DAT_fffffff007384950);
  bVar1 = FUN_fffffff0085b571c();
  if (bVar1) {
    uVar3 = (ulong)((int)unaff_x19 + 0x17);
    if ((unaff_x21 != (long *)0x0) &&
       (uVar2 = thunk_FUN_fffffff00a92d93c(unaff_x21), (uVar2 & 1) == 0)) {
      uVar3 = unaff_x19;
      if (*(long *)(unaff_x20 + 0x30) == 0) {
        auVar4 = FUN_fffffff0085b5668();
        thunk_FUN_fffffff00a8df19c
                  (extraout_q0_00,in_q1,in_s2,in_s3,in_s4,in_s5,auVar4._0_8_,auVar4._8_8_,0,
                   (byte *)"%s: !structureInput");
      }
      else if (*(long *)(unaff_x20 + 0x58) == 0) {
        auVar4 = FUN_fffffff0085b5668();
        thunk_FUN_fffffff00a8df19c
                  (extraout_q0_01,in_q1,in_s2,in_s3,in_s4,in_s5,auVar4._0_8_,auVar4._8_8_,0,
                   (byte *)"%s: !structureOutput");
      }
      else {
        uVar2 = *(uint *)(unaff_x20 + 0x38);
        if (uVar2 == 0) {
          auVar4 = FUN_fffffff0085b5668();
          thunk_FUN_fffffff00a8df19c
                    (extraout_q0_02,in_q1,in_s2,in_s3,in_s4,in_s5,auVar4._0_8_,auVar4._8_8_,uVar2,
                     (byte *)"%s: !structureInputSize");
        }
        else if (*(int *)(unaff_x20 + 0x60) == 0) {
          auVar4 = FUN_fffffff0085b5668();
          thunk_FUN_fffffff00a8df19c
                    (extraout_q0_03,in_q1,in_s2,in_s3,in_s4,in_s5,auVar4._0_8_,auVar4._8_8_,0,
                     (byte *)"%s: !structureOutputSize");
        }
        else {
          FUN_fffffff0085b5700();
          (**(code **)(extraout_x16 + 0x5b8))();
          FUN_fffffff0085b57ac();
        }
      }
    }
  }
  else {
    uVar3 = (ulong)((int)unaff_x19 - 1);
  }
  return uVar3;
}

