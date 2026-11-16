// FUN_fffffff009c3e86c @ fffffff009c3e86c size=764
// CALLERS:
//   fffffff00afec108 no-fn
//   fffffff009c39dc0 FUN_fffffff009c39cf4@fffffff009c39cf4
// CALLEES:
//   fffffff009c46a90 FUN_fffffff009c46a90
//   fffffff009c49824 thunk_FUN_fffffff00a9a7bc0
//   fffffff009c49b74 thunk_FUN_fffffff00a8df19c
//   fffffff009c4078c FUN_fffffff009c4078c
//   fffffff009c49bc4 thunk_FUN_fffffff00a2600a0
//   fffffff009c498d4 thunk_FUN_fffffff00a894f30
//   fffffff009c49764 thunk_FUN_fffffff00a8d8754
//   fffffff009c49b64 thunk_FUN_fffffff00aa4c590

/* WARNING: Removing unreachable block (ram,0xfffffff009c3e9e0) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c3e8f4) */

int FUN_fffffff009c3e86c
              (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,undefined4 param_4
              ,undefined4 param_5,undefined4 param_6,long param_7,uint param_8,char *param_9,
              ulong param_10)

{
  int iVar1;
  undefined ******ppppppuVar2;
  long *plVar3;
  long *plVar4;
  ulong uVar5;
  long lVar6;
  undefined1 extraout_q0 [16];
  undefined1 auVar7 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 extraout_q0_01 [16];
  undefined1 extraout_q0_02 [16];
  undefined1 extraout_q0_03 [16];
  long *local_40;
  long local_38;
  
  local_38 = *(long *)PTR_DAT_fffffff00806ca40;
  ppppppuVar2 = thunk_FUN_fffffff00a8d8754(param_9,param_10 & 0xffffffff,(undefined8 *)0x0);
  plVar3 = thunk_FUN_fffffff00a894f30((long *)ppppppuVar2,*(long *)PTR_PTR_fffffff00806c9c8);
  if (plVar3 == (long *)0x0) {
    auVar7 = extraout_q0;
    if (ppppppuVar2 != (undefined ******)0x0) {
      auVar7 = (*(code *)(*ppppppuVar2)[5])(ppppppuVar2);
    }
    iVar1 = -0x1ffffd3e;
    thunk_FUN_fffffff00a8df19c
              (auVar7,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,
               (short *)PTR_DAT_fffffff00806ca48,0x10,(byte *)"%s error - invalid args\n");
  }
  else {
    local_40 = (long *)0x0;
    lVar6 = *(long *)(param_7 + 0xf8);
    if (lVar6 == 0) {
      lVar6 = 0;
    }
    iVar1 = thunk_FUN_fffffff00a9a7bc0(lVar6,param_8,(long *)&local_40);
    if (iVar1 == 0) {
      plVar4 = FUN_fffffff009c4078c(&local_40);
      if (plVar4 == (long *)0x0) {
        iVar1 = -0x1ffffd3e;
        thunk_FUN_fffffff00a8df19c
                  (extraout_q0_01,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,
                   (short *)PTR_DAT_fffffff00806ca48,0x10,
                   (byte *)"%s error - invalid memory pool port\n");
      }
      else {
        lVar6 = thunk_FUN_fffffff00a2600a0();
        if (lVar6 == plVar4[6]) {
          (**(code **)(*plVar3 + 0x20))(plVar3);
          uVar5 = FUN_fffffff009c46a90((long)plVar4,plVar3);
          if ((uVar5 & 1) == 0) {
            thunk_FUN_fffffff00a8df19c
                      (extraout_q0_03,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,
                       (short *)PTR_DAT_fffffff00806ca48,0x10,(byte *)"%s error - flush failed\n");
            iVar1 = -0x1ffffd44;
          }
          else {
            iVar1 = 0;
          }
        }
        else {
          thunk_FUN_fffffff00a8df19c
                    (extraout_q0_02,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,
                     (short *)PTR_DAT_fffffff00806ca48,0x10,
                     (byte *)"%s error - task does not own memory pool\n");
          iVar1 = -0x1ffffd1e;
        }
        (**(code **)(*plVar4 + 0x28))(plVar4);
      }
    }
    else {
      thunk_FUN_fffffff00a8df19c
                (extraout_q0_00,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,
                 (short *)PTR_DAT_fffffff00806ca48,0x10,
                 (byte *)"%s error - copyObjectForPortNameInTask failed\n");
    }
    if (local_40 != (long *)0x0) {
      (**(code **)(*local_40 + 0x28))();
    }
    (**(code **)(*plVar3 + 0x28))(plVar3);
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 != local_38) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_fffffff00aa4c590();
  }
  return iVar1;
}

