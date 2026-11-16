// FUN_fffffff009c3888c @ fffffff009c3888c size=4
// CALLERS:
//   fffffff00afec050 ?
//   fffffff008068b90 ?
//   fffffff0080694f0 ?
// CALLS:

undefined8 FUN_fffffff009c3888c(long param_1,undefined8 param_2,long param_3)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  long *plVar3;
  char *pcVar4;
  ulong uVar5;
  ulong uVar6;
  undefined8 uVar7;
  undefined1 in_q0 [16];
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 in_q1 [16];
  undefined4 in_s2;
  undefined1 in_register_00005044 [12];
  undefined4 in_s3;
  undefined1 in_register_00005064 [12];
  undefined4 in_s4;
  undefined4 in_s5;
  
  uVar6 = **(ulong **)(param_3 + 0x20);
  if (uVar6 >> 0x20 == 0) {
    plVar3 = *(long **)(param_3 + 0x40);
    if (plVar3 == (long *)0x0) {
      plVar3 = (long *)0x0;
      uVar5 = (ulong)*(uint *)(param_3 + 0x38);
      pcVar4 = *(char **)(param_3 + 0x30);
    }
    else {
      plVar3 = (long *)(**(code **)(*plVar3 + 0xe8))(plVar3,0x1000);
      if (plVar3 == (long *)0x0) {
        thunk_FUN_fffffff00a8df19c
                  (extraout_q0,in_q1,in_s2,in_s3,in_s4,in_s5,&MACH_HEADER,
                   (short *)PTR_DAT_fffffff00806ca48,0x10,(byte *)"%s error - failed to map shmem\n"
                  );
        return 0xe00002c8;
      }
      pcVar4 = (char *)(**(code **)(*plVar3 + 0x78))();
      uVar5 = (**(code **)(**(long **)(param_3 + 0x40) + 0xb0))();
      in_q0 = extraout_q0_00;
    }
    if (pcVar4 == (char *)0x0 || (int)uVar5 == 0) {
      uVar7 = 0xe00002c2;
      thunk_FUN_fffffff00a8df19c
                (in_q0,in_q1,in_s2,in_s3,in_s4,in_s5,&MACH_HEADER,(short *)PTR_DAT_fffffff00806ca48,
                 0x10,(byte *)"%s error - no args\n");
    }
    else {
      auVar1._4_12_ = in_register_00005044;
      auVar1._0_4_ = in_s2;
      auVar2._4_12_ = in_register_00005064;
      auVar2._0_4_ = in_s3;
      uVar7 = FUN_fffffff009c3ab8c
                        (in_q0,in_q1,auVar1,auVar2,in_s4,in_s5,param_1,pcVar4,(uint)uVar6,
                         *(undefined8 **)(param_3 + 0x58),uVar5);
    }
    if (plVar3 != (long *)0x0) {
      (**(code **)(*plVar3 + 0x28))(plVar3);
    }
  }
  else {
    uVar7 = 0xe00002c2;
    thunk_FUN_fffffff00a8df19c
              (in_q0,in_q1,in_s2,in_s3,in_s4,in_s5,&MACH_HEADER,(short *)PTR_DAT_fffffff00806ca48,
               0x10,(byte *)"%s error - invalid parentID (0x%llx)\n");
  }
  return uVar7;
}

