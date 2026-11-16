// FUN_fffffff00a8d4088 @ fffffff00a8d4088 size=220
// CALLERS:
//   fffffff00a8d9e98 FUN_fffffff00a8d96f4@fffffff00a8d96f4
//   fffffff00a90fb88 FUN_fffffff00a90f8d8@fffffff00a90f8d8
//   fffffff00a8b4908 FUN_fffffff00a8b4840@fffffff00a8b4840
//   fffffff00a8b4a58 FUN_fffffff00a8b4990@fffffff00a8b4990
//   fffffff00a8be6f8 FUN_fffffff00a8be5c4@fffffff00a8be5c4
//   fffffff00a8beb8c FUN_fffffff00a8beb5c@fffffff00a8beb5c
//   fffffff00a9239e8 FUN_fffffff00a923870@fffffff00a923870
//   fffffff00a89540c FUN_fffffff00a8953ec@fffffff00a8953ec
//   fffffff00a932f70 FUN_fffffff00a932f4c@fffffff00a932f4c
//   fffffff00a921f8c FUN_fffffff00a92195c@fffffff00a92195c
//   fffffff00a912bfc FUN_fffffff00a912bdc@fffffff00a912bdc
//   fffffff00a923204 FUN_fffffff00a9230a8@fffffff00a9230a8
//   fffffff00a9d2954 FUN_fffffff00a9d230c@fffffff00a9d230c
//   fffffff00a932d00 FUN_fffffff00a932cec@fffffff00a932cec
//   fffffff00a933714 FUN_fffffff00a9336e8@fffffff00a9336e8
//   fffffff00a8970d0 FUN_fffffff00a8970c0@fffffff00a8970c0
//   fffffff00a89717c FUN_fffffff00a897160@fffffff00a897160
//   fffffff00a89f1a0 FUN_fffffff00a89f180@fffffff00a89f180
//   fffffff00a89f958 FUN_fffffff00a89f8dc@fffffff00a89f8dc
//   fffffff00a8b40d0 FUN_fffffff00a8b3edc@fffffff00a8b3edc
//   fffffff00a9ca474 FUN_fffffff00a9ca420@fffffff00a9ca420
//   fffffff00a90ed64 FUN_fffffff00a90ed4c@fffffff00a90ed4c
//   fffffff00a90f51c FUN_fffffff00a90f4fc@fffffff00a90f4fc
//   fffffff00a9134f4 FUN_fffffff00a913350@fffffff00a913350
//   fffffff00a931654 FUN_fffffff00a931630@fffffff00a931630
//   fffffff00a932e08 FUN_fffffff00a932df0@fffffff00a932df0
//   fffffff00a933574 FUN_fffffff00a933550@fffffff00a933550
//   fffffff00aa1050c FUN_fffffff00aa103f0@fffffff00aa103f0
//   fffffff00a991910 FUN_fffffff00a991868@fffffff00a991868
//   fffffff00a9c9728 FUN_fffffff00a9c95d8@fffffff00a9c95d8
//   fffffff00a9d4d24 FUN_fffffff00a9d4a2c@fffffff00a9d4a2c
//   fffffff00a9d9f14 FUN_fffffff00a9d9eec@fffffff00a9d9eec
//   fffffff00a90ef60 FUN_fffffff00a90ef48@fffffff00a90ef48

long * FUN_fffffff00a8d4088(long *param_1)

{
  uint uVar1;
  undefined8 *puVar2;
  long *plVar3;
  
  if (param_1 != (long *)0x0) {
    puVar2 = (undefined8 *)(**(code **)(*param_1 + 0x38))(param_1);
    do {
      if (puVar2 == &DAT_fffffff00ad95eb8) {
        (**(code **)(*param_1 + 0x20))(param_1);
        return param_1;
      }
      puVar2 = (undefined8 *)puVar2[2];
    } while (puVar2 != (undefined8 *)0x0);
  }
  uVar1 = *(uint *)((long)param_1 + 0xc);
  (**(code **)(*param_1 + 0xa8))(param_1);
  if ((uVar1 & 1) != 0) {
    plVar3 = (long *)FUN_fffffff00a8d4164();
    return plVar3;
  }
  plVar3 = (long *)FUN_fffffff00a8d42e4();
  return plVar3;
}

