// FUN_fffffff00a6e2494 @ fffffff00a6e2494 size=312
// CALLERS:
//   fffffff00afbc4bc ?
//   fffffff00a6e3614 FUN_fffffff00a6e329c@fffffff00a6e329c
//   fffffff00a6e3620 FUN_fffffff00a6e329c@fffffff00a6e329c
//   fffffff00a6e4be8 FUN_fffffff00a6e49e0@fffffff00a6e49e0
//   fffffff00a6e22a0 FUN_fffffff00a6e20f0@fffffff00a6e20f0
//   fffffff00a6e29c4 FUN_fffffff00a6e2804@fffffff00a6e2804
//   fffffff00a6e2b68 FUN_fffffff00a6e2a9c@fffffff00a6e2a9c
//   fffffff00a6e3d6c FUN_fffffff00a6e3bd0@fffffff00a6e3bd0
//   fffffff00a6e4988 FUN_fffffff00a6e4778@fffffff00a6e4778
//   fffffff00a6e5870 FUN_fffffff00a6e5270@fffffff00a6e5270
//   fffffff00a6e5914 FUN_fffffff00a6e5270@fffffff00a6e5270
//   fffffff00a6e5898 FUN_fffffff00a6e5270@fffffff00a6e5270
//   fffffff00a6e2708 FUN_fffffff00a6e2678@fffffff00a6e2678
//   fffffff00a6e2b80 FUN_fffffff00a6e2a9c@fffffff00a6e2a9c
// CALLS:
//   fffffff00a2261c0 FUN_fffffff00a2261c0
//   fffffff00a2e6e78 FUN_fffffff00a2e6e78
//   fffffff00aa4d114 FUN_fffffff00aa4d114
//   fffffff00a270c78 FUN_fffffff00a270c78
//   fffffff00a29762c FUN_fffffff00a29762c
//   fffffff00aa61ea0 FUN_fffffff00aa61ea0
//   fffffff00a6eaeec FUN_fffffff00a6eaeec

void FUN_fffffff00a6e2494
               (undefined8 *param_1,undefined8 param_2,long param_3,undefined **param_4,
               undefined *param_5)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 extraout_x1;
  undefined8 extraout_x1_00;
  undefined8 uVar3;
  undefined8 extraout_x1_01;
  undefined1 in_q0 [16];
  undefined1 in_q1 [16];
  undefined1 in_q2 [16];
  undefined1 in_q3 [16];
  undefined4 in_s4;
  undefined4 in_s5;
  undefined8 local_28;
  
  iVar1 = *(int *)((long)param_1 + 0x2c);
  *(int *)((long)param_1 + 0x2c) = iVar1 + -1;
  LORelease();
  if (iVar1 != 0) {
    if (iVar1 != 1) {
      return;
    }
    if ((param_1[3] != 0) || (param_1[1] != 0)) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa4d114
                (in_q0,in_q1,in_q2,in_q3,in_s4,in_s5,
                 (byte *)"aio_workq_entry %p being freed while still enqueued @%s:%d");
    }
    if (param_1[0x18] != 0) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa4d114
                (in_q0,in_q1,in_q2,in_q3,in_s4,in_s5,
                 (byte *)"aio_workq_entry %p being freed with knotes still attached @%s:%d");
    }
    FUN_fffffff00a2261c0((undefined4 *)(param_1 + 0x1a),&DAT_fffffff00ad23d44);
    uVar3 = extraout_x1;
    if ((ulong *)param_1[0x17] != (ulong *)0x0) {
      FUN_fffffff00a2e6e78((ulong *)param_1[0x17]);
      uVar3 = extraout_x1_00;
    }
    puVar2 = (undefined8 *)param_1[0x14];
    if (puVar2 != (undefined8 *)0x0) {
      iVar1 = *(int *)(puVar2 + 0x43);
      *(int *)(puVar2 + 0x43) = iVar1 + -1;
      LORelease();
      if (iVar1 == 0) goto LAB_fffffff00a6e2570;
      if (iVar1 == 1) {
        FUN_fffffff00a270c78(puVar2,uVar3,param_3,param_4,param_5);
        uVar3 = extraout_x1_01;
      }
    }
    local_28 = param_1[0x15];
    FUN_fffffff00a6eaeec(&local_28,uVar3,param_3,(ulong *)param_4,param_5);
    param_1[0x15] = local_28;
    FUN_fffffff00a29762c((undefined8 *)&DAT_fffffff007c78010,param_1);
    return;
  }
LAB_fffffff00a6e2570:
                    /* WARNING: Subroutine does not return */
  FUN_fffffff00aa61ea0();
}

