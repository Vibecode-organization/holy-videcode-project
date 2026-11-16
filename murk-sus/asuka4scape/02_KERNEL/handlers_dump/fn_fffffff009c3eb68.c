// FUN_fffffff009c3eb68 @ fffffff009c3eb68 size=680 depth=1
// CALLERS:
//   fffffff00afec10a ?
//   fffffff009c39e64 FUN_fffffff009c39e0c
// CALLS:
//   fffffff009c4078c FUN_fffffff009c4078c
//   fffffff009c49bc4 thunk_FUN_fffffff00a2600a0
//   fffffff009c49b74 thunk_FUN_fffffff00a8df19c
//   fffffff009c49b64 thunk_FUN_fffffff00aa4c590
//   fffffff009c49864 thunk_FUN_fffffff00a8a10d8
//   fffffff009c372dc FUN_fffffff009c372dc
//   fffffff009c49824 thunk_FUN_fffffff00a9a7bc0
//   fffffff009c44d30 FUN_fffffff009c44d30

/* WARNING: Removing unreachable block (ram,0xfffffff009c3ecec) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c3ebd8) */

int FUN_fffffff009c3eb68
              (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
              undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
              uint param_8,long *param_9)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  int iVar3;
  long *plVar4;
  long *plVar5;
  long *plVar6;
  ulong uVar7;
  long lVar8;
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 auVar9 [16];
  undefined4 uVar10;
  undefined1 auVar11 [12];
  undefined4 uVar12;
  undefined1 auVar13 [12];
  long *local_50;
  long local_48;
  
  uVar12 = param_4._0_4_;
  auVar13 = param_4._4_12_;
  uVar10 = param_3._0_4_;
  auVar11 = param_3._4_12_;
  local_48 = *(long *)PTR_DAT_fffffff00806ca40;
  plVar4 = thunk_FUN_fffffff00a8a10d8(1);
  local_50 = (long *)0x0;
  lVar8 = *(long *)(param_7 + 0xf8);
  if (lVar8 == 0) {
    lVar8 = 0;
  }
  iVar3 = thunk_FUN_fffffff00a9a7bc0(lVar8,param_8,(long *)&local_50);
  if (iVar3 == 0) {
    if (plVar4 == (long *)0x0) {
      iVar3 = -0x1ffffd43;
    }
    else {
      plVar5 = FUN_fffffff009c4078c(&local_50);
      if (plVar5 == (long *)0x0) {
        thunk_FUN_fffffff00a8df19c
                  (extraout_q0_00,param_2,uVar10,uVar12,param_5,param_6,&MACH_HEADER,
                   (short *)PTR_DAT_fffffff00806ca48,0x10,
                   (byte *)"%s error - invalid memory pool port\n");
        iVar3 = -0x1ffffd3e;
      }
      else {
        lVar8 = thunk_FUN_fffffff00a2600a0();
        if (lVar8 == plVar5[6]) {
          (**(code **)(*param_9 + 0x80))(param_9);
          plVar6 = FUN_fffffff009c372dc(*(long *)(param_7 + 0xe8));
          auVar9 = (**(code **)(*plVar4 + 0x20))(plVar4);
          auVar1._4_12_ = auVar11;
          auVar1._0_4_ = uVar10;
          auVar2._4_12_ = auVar13;
          auVar2._0_4_ = uVar12;
          FUN_fffffff009c44d30
                    (auVar9,param_2,auVar1,auVar2,param_5,param_6,(long)plVar6,plVar4,plVar5[5]);
          if (plVar6 != (long *)0x0) {
            (**(code **)(*plVar6 + 0x28))(plVar6);
          }
          uVar7 = (**(code **)(*plVar4 + 0x30))(plVar4,param_9);
          iVar3 = 0;
          if ((uVar7 & 1) == 0) {
            iVar3 = -0x1ffffd44;
          }
        }
        else {
          iVar3 = -0x1ffffd1e;
        }
        (**(code **)(*plVar5 + 0x28))(plVar5);
      }
    }
  }
  else {
    thunk_FUN_fffffff00a8df19c
              (extraout_q0,param_2,uVar10,uVar12,param_5,param_6,&MACH_HEADER,
               (short *)PTR_DAT_fffffff00806ca48,0x10,
               (byte *)"%s error - copyObjectForPortNameInTask failed\n");
  }
  if (local_50 != (long *)0x0) {
    (**(code **)(*local_50 + 0x28))();
  }
  if (plVar4 != (long *)0x0) {
    (**(code **)(*plVar4 + 0x28))(plVar4);
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 != local_48) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_fffffff00aa4c590();
  }
  return iVar3;
}

