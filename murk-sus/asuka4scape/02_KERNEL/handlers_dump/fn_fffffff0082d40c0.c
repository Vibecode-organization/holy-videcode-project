// FUN_fffffff0082d40c0 @ fffffff0082d40c0 size=4 depth=0
// CALLERS:
//   fffffff00afc2748 ?
//   fffffff007cccba0 ?
// CALLS:

undefined8 FUN_fffffff0082d40c0(long *param_1,undefined8 param_2,long param_3)

{
  long *plVar1;
  undefined8 uVar2;
  undefined1 in_q0 [16];
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 auVar3 [16];
  undefined1 in_q1 [16];
  undefined4 in_s2;
  undefined4 in_s3;
  undefined4 in_s4;
  undefined4 in_s5;
  
  if (*(uint *)(param_3 + 0x60) < 0xa0) {
    uVar2 = 0xe00002c2;
    auVar3 = FUN_fffffff0082ce0e8
                       (in_q0,in_q1,in_s2,in_s3,in_s4,in_s5,
                        (byte *)"condition \"%s\" failed, %s() line %d, status: 0x%x\n");
    thunk_FUN_fffffff00a8df19c
              (auVar3,in_q1,in_s2,in_s3,in_s4,in_s5,&MACH_HEADER,(short *)PTR_DAT_fffffff007cccee0,
               0x10,(byte *)"condition \"%s\" failed, %s() line %d, status: 0x%x\n");
  }
  else {
    plVar1 = thunk_FUN_fffffff00a894f30(param_1,-0xff51d5a78);
    if (plVar1 == (long *)0x0) {
      uVar2 = 0xe00002c2;
      auVar3 = FUN_fffffff0082ce0e8
                         (extraout_q0,in_q1,in_s2,in_s3,in_s4,in_s5,
                          (byte *)
                          "pointer \"%s\" is null, cannot continue, %s(), line %d, status: 0x%x\n");
      thunk_FUN_fffffff00a8df19c
                (auVar3,in_q1,in_s2,in_s3,in_s4,in_s5,&MACH_HEADER,(short *)PTR_DAT_fffffff007cccee0
                 ,0x10,(byte *)
                       "pointer \"%s\" is null, cannot continue, %s(), line %d, status: 0x%x\n");
    }
    else if (plVar1[0x1b] == 0) {
      uVar2 = 0xe00002d9;
      auVar3 = FUN_fffffff0082ce0e8
                         (extraout_q0,in_q1,in_s2,in_s3,in_s4,in_s5,
                          (byte *)
                          "pointer \"%s\" is null, cannot continue, %s(), line %d, status: 0x%x\n");
      thunk_FUN_fffffff00a8df19c
                (auVar3,in_q1,in_s2,in_s3,in_s4,in_s5,&MACH_HEADER,(short *)PTR_DAT_fffffff007cccee0
                 ,0x10,(byte *)
                       "pointer \"%s\" is null, cannot continue, %s(), line %d, status: 0x%x\n");
    }
    else {
      uVar2 = FUN_fffffff0082d1a0c(plVar1[0x1b],*(undefined8 **)(param_3 + 0x58));
      if ((int)uVar2 == 0) {
        *(undefined4 *)(param_3 + 0x60) = 0xa0;
      }
      else {
        auVar3 = FUN_fffffff0082ce0e8
                           (extraout_q0_00,in_q1,in_s2,in_s3,in_s4,in_s5,
                            (byte *)"expression \"%s\" failed, %s(), line %d, status: 0x%x\n");
        thunk_FUN_fffffff00a8df19c
                  (auVar3,in_q1,in_s2,in_s3,in_s4,in_s5,&MACH_HEADER,
                   (short *)PTR_DAT_fffffff007cccee0,0x10,
                   (byte *)"expression \"%s\" failed, %s(), line %d, status: 0x%x\n");
      }
    }
  }
  return uVar2;
}

