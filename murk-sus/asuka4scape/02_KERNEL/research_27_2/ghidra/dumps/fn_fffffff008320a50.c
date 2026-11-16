// FUN_fffffff008320a50 @ fffffff008320a50 size=780
// CALLERS:
// CALLEES:
//   fffffff0083570a4 thunk_FUN_fffffff00a9029a0
//   fffffff00830d218 FUN_fffffff00830d218
//   fffffff008357384 thunk_FUN_fffffff00a9a63f4
//   fffffff0083571e4 thunk_FUN_fffffff00aa16d84
//   fffffff008357394 thunk_FUN_fffffff00a9a6b94
//   fffffff008357844 thunk_FUN_fffffff00a9332f0
//   fffffff00a9a16ec FUN_fffffff00a9a16ec
//   fffffff0083578e4 thunk_FUN_fffffff00a9327bc
//   fffffff00830d22c FUN_fffffff00830d22c

/* WARNING: Removing unreachable block (ram,0xfffffff008320bf8) */

undefined4
FUN_fffffff008320a50
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,long param_8,
          undefined8 param_9,ulong *param_10,undefined8 param_11)

{
  int iVar1;
  long *plVar2;
  long *plVar3;
  ulong uVar4;
  char *pcVar5;
  undefined8 uVar6;
  ulong *puVar7;
  code *pcVar8;
  long *plVar9;
  undefined1 auVar10 [16];
  
  uVar6 = param_9;
  puVar7 = param_10;
  iVar1 = thunk_FUN_fffffff00aa16d84((undefined4 *)0x0);
  if (iVar1 == 0) {
    return 0;
  }
  if (param_8 == 0) {
    pcVar5 = "AggressorUserClient::initWithTask owningTask invalid\n";
LAB_fffffff008320c90:
    thunk_FUN_fffffff00a9029a0((byte *)pcVar5);
  }
  else {
    *(long *)(param_7 + 0x118) = param_8;
    plVar2 = (long *)thunk_FUN_fffffff00a9a6b94(param_8,-0xff8e9d69f);
    if ((plVar2 != (long *)0x0) &&
       (plVar9 = (long *)**(undefined8 **)PTR_PTR_fffffff007ce9db0, (**(code **)(*plVar2 + 0x28))(),
       plVar2 != plVar9)) {
      return 0;
    }
    iVar1 = thunk_FUN_fffffff00a9a63f4
                      (*(undefined8 **)(param_7 + 0x118),&DAT_fffffff00716298a,uVar6,puVar7,param_11
                      );
    if (iVar1 != 0) {
      return 0;
    }
    thunk_FUN_fffffff00a9029a0((byte *)"AggressorUserClient::initWithTask\n");
    plVar2 = thunk_FUN_fffffff00a9332f0((byte *)"arm-io",(long *)0x0);
    iVar1 = (**(code **)(*plVar2 + 0x90))();
    if (iVar1 == 1) {
      plVar9 = thunk_FUN_fffffff00a9327bc(plVar2);
      auVar10 = (**(code **)(*plVar2 + 0x28))(plVar2);
      plVar2 = (long *)FUN_fffffff00830d218
                                 (auVar10,param_2,param_3,param_4,param_5,param_6,(ulong *)0x108);
      plVar3 = FUN_fffffff00830d22c(plVar2);
      uVar4 = (**(code **)(*plVar3 + 0xa8))(plVar3,0);
      if ((uVar4 & 1) == 0) {
        pcVar5 = "AggressorUserClient::start failed to initialize %s\n";
      }
      else {
        (**(code **)(*plVar2 + 0x210))(plVar2,"sac-test-framework-node",0);
        uVar4 = (**(code **)(*plVar2 + 0x1b8))
                          (*plVar2 + 0x1b8,plVar2,plVar9,*(undefined8 *)PTR_DAT_fffffff007ce9d98);
        if ((uVar4 & 1) != 0) {
          *(long **)(param_7 + 0x100) = plVar2;
          (**(code **)(*plVar9 + 0x28))(plVar9);
          uVar4 = (**(code **)(PTR_DAT_fffffff007ce9cb8 + 0x568))(param_7,param_8,param_9,param_10);
          if ((uVar4 & 1) != 0) {
            *(undefined8 *)(param_7 + 0xe8) = 0;
            *(undefined8 *)(param_7 + 0xf0) = 0;
            *(undefined4 *)(param_7 + 0xf8) = 0;
            *(undefined8 *)(param_7 + 0x110) = 0;
            *(undefined4 *)(param_7 + 0xe0) = 1;
            return 1;
          }
          pcVar5 = "AggressorUserClient:initWithTask::super failed\n";
          goto LAB_fffffff008320c90;
        }
        pcVar5 = "AggressorUserClient::start failed to attach %s to arm-io\n";
      }
      thunk_FUN_fffffff00a9029a0((byte *)pcVar5);
      (**(code **)(*plVar9 + 0x28))(plVar9);
      pcVar8 = *(code **)(*plVar2 + 0x28);
    }
    else {
      (**(code **)(*plVar2 + 0x90))(plVar2);
      thunk_FUN_fffffff00a9029a0
                ((byte *)
                 "AggressorUserClient::start found %d nodes with name arm-io, this should not happen\n"
                );
      pcVar8 = *(code **)(*plVar2 + 0x28);
    }
    (*pcVar8)(plVar2);
  }
  return 0;
}

