// FUN_fffffff00a9e4958 @ fffffff00a9e4958 size=372
// CALLERS:
//   fffffff00afbfb0d no-fn
//   fffffff007ff2340 no-fn
//   fffffff0099847f8 thunk_FUN_fffffff00a9e4958@fffffff0099847ec
//   fffffff00a9e4ad4 FUN_fffffff00a9e4acc@fffffff00a9e4acc
// CALLEES:
//   fffffff00a2211ec FUN_fffffff00a2211ec
//   fffffff00a9e3610 FUN_fffffff00a9e3610
//   fffffff00aa4d114 FUN_fffffff00aa4d114
//   fffffff00a220c30 FUN_fffffff00a220c30

long * FUN_fffffff00a9e4958
                 (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
                 undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,undefined8 param_7,
                 undefined8 param_8,uint param_9)

{
  int iVar1;
  long *plVar2;
  ulong uVar3;
  undefined *puVar4;
  undefined1 extraout_q0 [16];
  undefined1 auVar5 [16];
  
  if ((DAT_fffffff007c7f4fc & 0xfffff0) < 0x70) {
    auVar5 = FUN_fffffff00a220c30
                       (param_1,param_2,param_3,param_4,param_5,param_6,
                        (long *)&DAT_fffffff007c28060,(ulong *)0x70,(ulong *)0x41004,
                        (undefined ********)0x0);
    plVar2 = auVar5._0_8_;
  }
  else {
    plVar2 = (long *)FUN_fffffff00a2211ec((long *)&DAT_fffffff007c7f4d0,4);
  }
  DAT_fffffff00ad97ef8 = DAT_fffffff00ad97ef8 + 0x70;
  *(undefined4 *)(plVar2 + 1) = 1;
  *plVar2 = (long)&PTR_FUN_fffffff007c66a00;
  puVar4 = &DAT_fffffff00ad98460;
  do {
    iVar1 = *(int *)(puVar4 + 0x24);
    *(int *)(puVar4 + 0x24) = iVar1 + 1;
    if (iVar1 != 0) break;
    puVar4 = *(undefined **)(puVar4 + 0x10);
  } while (puVar4 != (undefined *)0x0);
  uVar3 = (**(code **)(*plVar2 + 0x78))(plVar2,param_7,param_8);
  if ((uVar3 & 1) == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff00aa4d114
              (extraout_q0,param_2,param_3,param_4,param_5,param_6,
               (byte *)"could not create IOPerfControlClient @%s:%d");
  }
  if (param_9 < 5) {
    if (*(char *)((long)plVar2 + 0xc) == '\0') {
      *(char *)((long)plVar2 + 0xc) = (char)param_9;
      return plVar2;
    }
                    /* WARNING: Subroutine does not return */
    FUN_fffffff00aa4d114
              (extraout_q0,param_2,param_3,param_4,param_5,param_6,
               (byte *)"deviceType already set to %d @%s:%d");
  }
                    /* WARNING: Subroutine does not return */
  FUN_fffffff00aa4d114
            (extraout_q0,param_2,param_3,param_4,param_5,param_6,
             (byte *)"unknown device type %d @%s:%d");
}

