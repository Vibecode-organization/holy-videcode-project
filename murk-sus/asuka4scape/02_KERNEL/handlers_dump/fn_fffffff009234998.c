// FUN_fffffff009234998 @ fffffff009234998 size=4 depth=0
// CALLERS:
//   fffffff00afdca59 ?
//   fffffff007ef24a0 ?
// CALLS:

undefined8 FUN_fffffff009234998(long *param_1,undefined8 param_2,long param_3)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  int iVar5;
  long *plVar6;
  long *plVar7;
  undefined8 extraout_x0;
  long in_x3;
  long *in_x4;
  undefined8 uVar8;
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 in_q1 [16];
  undefined4 in_s2;
  undefined1 in_register_00005044 [12];
  undefined4 in_s3;
  undefined1 in_register_00005064 [12];
  undefined4 in_s4;
  undefined4 in_s5;
  
  uVar8 = 0xe00002c7;
  plVar6 = thunk_FUN_fffffff00a894f30(param_1,-0xff51205d0);
  if ((((plVar6 != (long *)0x0) && (plVar7 = (long *)plVar6[0x1b], plVar7 != (long *)0x0)) &&
      (iVar5 = (**(code **)(*plVar7 + 0x30))(plVar7,4), iVar5 != 0)) &&
     (uVar8 = FUN_fffffff0092591a8
                        (extraout_q0,in_q1,in_s2,in_s3,in_s4,in_s5,(long)plVar6,"assert",0,in_x3,
                         in_x4), (int)uVar8 == 0)) {
    if ((*(int *)(param_3 + 0x38) != 0) &&
       (*(char *)(*(long *)(param_3 + 0x30) + (ulong)(*(int *)(param_3 + 0x38) - 1)) == '\0')) {
      auVar2._4_12_ = in_register_00005044;
      auVar2._0_4_ = in_s2;
      auVar4._4_12_ = in_register_00005064;
      auVar4._0_4_ = in_s3;
                    /* WARNING: Subroutine does not return */
      thunk_FUN_fffffff00aa4d114
                (extraout_q0_00,in_q1,auVar2,auVar4,in_s4,in_s5,(byte *)"\"%s\" @%s:%d");
    }
    auVar1._4_12_ = in_register_00005044;
    auVar1._0_4_ = in_s2;
    auVar3._4_12_ = in_register_00005064;
    auVar3._0_4_ = in_s3;
    FUN_fffffff009259570(extraout_q0_00,in_q1,auVar1,auVar3,in_s4,in_s5);
    uVar8 = extraout_x0;
  }
  return uVar8;
}

