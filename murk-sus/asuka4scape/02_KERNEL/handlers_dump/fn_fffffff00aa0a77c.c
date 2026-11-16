// FUN_fffffff00aa0a77c @ fffffff00aa0a77c size=264 depth=1
// CALLERS:
//   fffffff00afbfd6d ?
//   fffffff00a9e03f8 FUN_fffffff00a9dfff0
// CALLS:
//   fffffff00a9f14b8 FUN_fffffff00a9f14b8

undefined8
FUN_fffffff00aa0a77c
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,long param_7,long param_8,undefined8 param_9,
          undefined8 param_10,undefined *param_11)

{
  int iVar1;
  long *plVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined1 extraout_q0 [16];
  
  uVar4 = 0xe00002bd;
  if (param_8 == 0) {
    return 0xe00002c2;
  }
  plVar2 = (long *)(**(code **)(DAT_fffffff00ad95c48 + 0x68))();
  if (plVar2 == (long *)0x0) {
    return 0xe00002bd;
  }
  iVar1 = (**(code **)(*plVar2 + 0x80))(plVar2,param_8,0xc);
  if (iVar1 != 0) {
    if (*(char *)(param_8 + 9) == '\x01') {
      puVar3 = &DAT_fffffff00add79f0;
    }
    else {
      if (*(char *)(param_8 + 9) != '\x02') {
        uVar4 = 0;
        goto LAB_fffffff00aa0a854;
      }
      puVar3 = &DAT_fffffff00add79f8;
    }
    uVar4 = FUN_fffffff00a9f14b8
                      (extraout_q0,param_2,param_3,param_4,param_5,param_6,param_7,(long *)*puVar3,
                       plVar2,param_10,param_11);
  }
LAB_fffffff00aa0a854:
  (**(code **)(*plVar2 + 0x28))(plVar2);
  return uVar4;
}

