// FUN_fffffff009c43898 @ fffffff009c43898 size=388
// CALLERS:
//   fffffff00afec1cc no-fn
//   fffffff009c3e498 FUN_fffffff009c3e384@fffffff009c3e384
// CALLEES:
//   fffffff009c43ecc FUN_fffffff009c43ecc
//   fffffff009c43a1c FUN_fffffff009c43a1c
//   fffffff009c495f4 thunk_FUN_fffffff00a9029a0

/* WARNING: Removing unreachable block (ram,0xfffffff009c43980) */

long * FUN_fffffff009c43898
                 (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
                 undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long *param_7,
                 long *param_8,long param_9)

{
  long lVar1;
  long *plVar2;
  undefined8 uVar3;
  undefined1 auVar4 [16];
  
  if (param_7[8] == 0) {
    thunk_FUN_fffffff00a9029a0((byte *)"====> %s:%d Memory pool ids exhausted\n");
  }
  else {
    lVar1 = param_7[8];
    param_7[8] = lVar1 + 1;
    plVar2 = (long *)(**(code **)(DAT_fffffff00af484a8 + 0x68))();
    if (plVar2 == (long *)0x0) goto LAB_fffffff009c439dc;
    if (param_8 != (long *)0x0) {
      (**(code **)(*param_8 + 0x20))(param_8);
    }
    auVar4 = (**(code **)(*param_7 + 0x20))(param_7);
    uVar3 = FUN_fffffff009c43a1c
                      (auVar4,param_2,param_3,param_4,param_5,param_6,(long)plVar2,lVar1,param_8,
                       param_9,param_7);
    if ((int)uVar3 != 0) {
      (**(code **)(*plVar2 + 0x20))(plVar2);
      FUN_fffffff009c43ecc((long)param_7,plVar2);
      goto LAB_fffffff009c439dc;
    }
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  plVar2 = (long *)0x0;
LAB_fffffff009c439dc:
  if (param_8 != (long *)0x0) {
    (**(code **)(*param_8 + 0x28))(param_8);
  }
  return plVar2;
}

