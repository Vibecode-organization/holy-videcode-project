// FUN_fffffff008348530 @ fffffff008348530 size=600
// CALLERS:
// CALLEES:
//   fffffff0083570a4 thunk_FUN_fffffff00a9029a0
//   fffffff008357544 thunk_FUN_fffffff00a894f30
//   fffffff0083571e4 thunk_FUN_fffffff00aa16d84
//   fffffff0083577c4 thunk_FUN_fffffff00a8d2200
//   fffffff008357304 thunk_FUN_fffffff00a8970c0

/* WARNING: Removing unreachable block (ram,0xfffffff00834867c) */
/* WARNING: Removing unreachable block (ram,0xfffffff0083486bc) */
/* WARNING: Removing unreachable block (ram,0xfffffff008348628) */

undefined8
FUN_fffffff008348530
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
          undefined8 param_5,undefined8 *param_6)

{
  int iVar1;
  long *plVar2;
  long *plVar3;
  ulong uVar4;
  code *pcVar5;
  long lVar6;
  char *pcVar7;
  
  iVar1 = thunk_FUN_fffffff00aa16d84((undefined4 *)0x0);
  if (iVar1 == 0) {
    return 0xe00002e2;
  }
  if ((int)param_4 == 1) {
    pcVar7 = "VictimUserClient";
  }
  else {
    if ((int)param_4 != 2) {
      thunk_FUN_fffffff00a9029a0
                ((byte *)
                 "AppleARMSlowAdaptiveClockingManager::newUserClient - ERROR - unsupported UserClient type\n"
                );
      return 0xe00002c7;
    }
    pcVar7 = "AggressorUserClient";
  }
  thunk_FUN_fffffff00a9029a0
            ((byte *)"AppleARMSlowAdaptiveClockingManager::newUserClient - Creating a %s\n");
  plVar2 = thunk_FUN_fffffff00a8d2200(pcVar7);
  plVar3 = (long *)thunk_FUN_fffffff00a8970c0(plVar2);
  (**(code **)(*plVar2 + 0x28))(plVar2);
  if (plVar3 == (long *)0x0) {
    return 0xe00002bd;
  }
  plVar2 = thunk_FUN_fffffff00a894f30(plVar3,*(long *)PTR_PTR_fffffff007ce9bf0);
  lVar6 = *plVar3;
  if (plVar2 != (long *)0x0) {
    uVar4 = (**(code **)(lVar6 + 0x550))(lVar6 + 0x550,plVar3,param_2,param_3,param_4,param_5);
    lVar6 = *plVar3;
    if ((uVar4 & 1) == 0) {
      (**(code **)(lVar6 + 0x28))(plVar3);
      return 0xe00002c2;
    }
    uVar4 = (**(code **)(lVar6 + 0x360))(lVar6 + 0x360,plVar3,param_1);
    lVar6 = *plVar3;
    if ((uVar4 & 1) != 0) {
      uVar4 = (**(code **)(lVar6 + 0x2b0))(lVar6 + 0x2b0,plVar3,param_1);
      if ((uVar4 & 1) != 0) {
        *param_6 = plVar3;
        return 0;
      }
      (**(code **)(*plVar3 + 0x368))(plVar3,param_1);
      pcVar5 = *(code **)(*plVar3 + 0x28);
      goto LAB_fffffff00834870c;
    }
  }
  pcVar5 = *(code **)(lVar6 + 0x28);
LAB_fffffff00834870c:
  (*pcVar5)(plVar3);
  return 0xe00002c7;
}

