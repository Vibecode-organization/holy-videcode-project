// FUN_fffffff0085c2eb0 @ fffffff0085c2eb0 size=4 depth=0
// CALLERS:
//   fffffff00afc5bde ?
//   fffffff007d0dc08 ?
// CALLS:

ulong FUN_fffffff0085c2eb0(void)

{
  bool bVar1;
  uint uVar2;
  ulong uVar3;
  long extraout_x16;
  int iVar4;
  ulong unaff_x19;
  long unaff_x20;
  long *unaff_x21;
  ulong uVar5;
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 extraout_q0_01 [16];
  undefined1 extraout_q0_02 [16];
  undefined1 extraout_q0_03 [16];
  undefined1 extraout_q0_04 [16];
  undefined1 extraout_q0_05 [16];
  undefined1 extraout_q0_06 [16];
  undefined1 extraout_q0_07 [16];
  undefined1 in_q1 [16];
  undefined4 in_s2;
  undefined4 in_s3;
  undefined4 in_s4;
  undefined4 in_s5;
  undefined1 auVar6 [16];
  
  FUN_fffffff0085b56dc();
  auVar6 = FUN_fffffff0085b5668();
  thunk_FUN_fffffff00a8df19c
            (extraout_q0,in_q1,in_s2,in_s3,in_s4,in_s5,auVar6._0_8_,auVar6._8_8_,0,
             &DAT_fffffff007384a43);
  bVar1 = FUN_fffffff0085b571c();
  iVar4 = (int)unaff_x19;
  if (bVar1) {
    uVar5 = (ulong)(iVar4 + 0x17);
    if ((unaff_x21 != (long *)0x0) &&
       (uVar2 = thunk_FUN_fffffff00a92d93c(unaff_x21), (uVar2 & 1) == 0)) {
      uVar5 = unaff_x19;
      if (*(int *)(unaff_x20 + 0x28) == 3) {
        if (*(int *)(unaff_x20 + 0x50) == 1) {
          if (*(long *)(unaff_x20 + 0x30) == 0) {
            auVar6 = FUN_fffffff0085b5668();
            thunk_FUN_fffffff00a8df19c
                      (extraout_q0_02,in_q1,in_s2,in_s3,in_s4,in_s5,auVar6._0_8_,auVar6._8_8_,0,
                       (byte *)"%s: !structureInput");
          }
          else if (*(long *)(unaff_x20 + 0x58) == 0) {
            auVar6 = FUN_fffffff0085b5668();
            thunk_FUN_fffffff00a8df19c
                      (extraout_q0_03,in_q1,in_s2,in_s3,in_s4,in_s5,auVar6._0_8_,auVar6._8_8_,0,
                       (byte *)"%s: !structureOutput");
          }
          else if (*(uint *)(unaff_x20 + 0x38) < 0x21) {
            if (*(int *)(unaff_x20 + 0x60) == 0x80) {
              if ((ulong)*(uint *)(unaff_x20 + 0x38) < *(ulong *)(*(long *)(unaff_x20 + 0x20) + 8))
              {
                auVar6 = FUN_fffffff0085b5668();
                thunk_FUN_fffffff00a8df19c
                          (extraout_q0_06,in_q1,in_s2,in_s3,in_s4,in_s5,auVar6._0_8_,auVar6._8_8_,0,
                           (byte *)"%s: unexpected inCmdLen:%llu");
              }
              else {
                uVar3 = *(ulong *)(*(long *)(unaff_x20 + 0x20) + 0x10);
                if (uVar3 < 0x81) {
                  FUN_fffffff0085b5700();
                  (**(code **)(extraout_x16 + 0x548))();
                  if (uVar3 >> 0x20 == 0) {
                    FUN_fffffff0085b57ac();
                  }
                  else {
                    uVar5 = (ulong)(iVar4 - 6);
                  }
                }
                else {
                  auVar6 = FUN_fffffff0085b5668();
                  thunk_FUN_fffffff00a8df19c
                            (extraout_q0_07,in_q1,in_s2,in_s3,in_s4,in_s5,auVar6._0_8_,auVar6._8_8_,
                             0,(byte *)"%s: unexpected outRspLen:%llu");
                }
              }
            }
            else {
              auVar6 = FUN_fffffff0085b5668();
              thunk_FUN_fffffff00a8df19c
                        (extraout_q0_05,in_q1,in_s2,in_s3,in_s4,in_s5,auVar6._0_8_,auVar6._8_8_,0,
                         (byte *)"%s: unexpected structureOutputSize:%u");
            }
          }
          else {
            auVar6 = FUN_fffffff0085b5668();
            thunk_FUN_fffffff00a8df19c
                      (extraout_q0_04,in_q1,in_s2,in_s3,in_s4,in_s5,auVar6._0_8_,auVar6._8_8_,0,
                       (byte *)"%s: unexpected structureInputSize:%u");
          }
        }
        else {
          auVar6 = FUN_fffffff0085b5668();
          thunk_FUN_fffffff00a8df19c
                    (extraout_q0_01,in_q1,in_s2,in_s3,in_s4,in_s5,auVar6._0_8_,auVar6._8_8_,0,
                     (byte *)"%s: unexpected scalarOutputCount:%u");
        }
      }
      else {
        auVar6 = FUN_fffffff0085b5668();
        thunk_FUN_fffffff00a8df19c
                  (extraout_q0_00,in_q1,in_s2,in_s3,in_s4,in_s5,auVar6._0_8_,auVar6._8_8_,0,
                   (byte *)"%s: unexpected scalarInputCount:%u");
      }
    }
  }
  else {
    uVar5 = (ulong)(iVar4 - 1);
  }
  return uVar5;
}

