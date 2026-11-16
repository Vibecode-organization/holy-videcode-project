// FUN_fffffff00a9e0640 @ fffffff00a9e0640 size=568 depth=1
// CALLERS:
//   fffffff00afbfa7b ?
//   fffffff00a9e0368 FUN_fffffff00a9dfff0
// CALLS:
//   fffffff00a29b0b4 FUN_fffffff00a29b0b4
//   fffffff00aa0a5f0 FUN_fffffff00aa0a5f0
//   fffffff00a724f30 FUN_fffffff00a724f30
//   fffffff00a8d8754 FUN_fffffff00a8d8754
//   fffffff00a9029a0 FUN_fffffff00a9029a0
//   fffffff00a9a63f4 FUN_fffffff00a9a63f4

undefined8
FUN_fffffff00a9e0640
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,long param_7,char *param_8,ulong param_9,
          ulong *param_10,undefined8 param_11)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  ulong uVar4;
  undefined ******ppppppuVar5;
  undefined8 *puVar6;
  ulong *puVar7;
  undefined ******ppppppuVar8;
  long *plVar9;
  undefined1 auVar10 [16];
  long *local_48;
  
  uVar4 = param_9;
  puVar7 = param_10;
  iVar1 = FUN_fffffff00a9a63f4
                    (*(undefined8 **)(param_7 + 0xe0),(byte *)"local",param_9,param_10,param_11);
  iVar2 = FUN_fffffff00a9a63f4
                    (*(undefined8 **)(param_7 + 0xe0),&DAT_fffffff0070439ba,uVar4,puVar7,param_11);
  if ((iVar1 == 0 || iVar2 == 0) && (*(long *)(param_7 + 0xd8) != 0)) {
    local_48 = (long *)0x0;
    uVar4 = FUN_fffffff00a29b0b4(*(long *)(param_7 + 0xe0));
    if (uVar4 != 0) {
      plVar9 = *(long **)(param_7 + 0xd8);
      iVar1 = FUN_fffffff00a724f30(uVar4);
      (**(code **)(*plVar9 + 0xe0))(plVar9,"SleepRequestedByPID",(long)iVar1,0x20);
    }
    if (param_8 == (char *)0x0) {
      ppppppuVar8 = (undefined ******)0x0;
    }
    else {
      ppppppuVar5 = FUN_fffffff00a8d8754(param_8,param_9,&local_48);
      ppppppuVar8 = ppppppuVar5;
      if (ppppppuVar5 != (undefined ******)0x0) {
        puVar6 = (undefined8 *)(*(code *)(*ppppppuVar5)[7])(ppppppuVar5);
        do {
          if (puVar6 == &DAT_fffffff00ad95c70) {
            auVar10 = (**(code **)(**(long **)(param_7 + 0xd8) + 200))
                                (*(long **)(param_7 + 0xd8),"Last Sleep Options",ppppppuVar5);
            goto LAB_fffffff00a9e0804;
          }
          puVar6 = (undefined8 *)puVar6[2];
        } while (puVar6 != (undefined8 *)0x0);
      }
      if (local_48 != (long *)0x0) {
        (**(code **)(*local_48 + 0xa8))();
      }
      FUN_fffffff00a9029a0((byte *)"IOPMRootDomain SleepSystem unserialization failure: %s\n");
    }
    auVar10 = (**(code **)(**(long **)(param_7 + 0xd8) + 0x100))
                        (*(long **)(param_7 + 0xd8),"Last Sleep Options");
    ppppppuVar5 = (undefined ******)0x0;
LAB_fffffff00a9e0804:
    uVar3 = FUN_fffffff00aa0a5f0
                      (auVar10,param_2,param_3,param_4,param_5,param_6,*(long *)(param_7 + 0xd8),
                       (long *)ppppppuVar5);
    *(undefined4 *)param_10 = uVar3;
    if (ppppppuVar8 != (undefined ******)0x0) {
      (*(code *)(*ppppppuVar8)[5])(ppppppuVar8);
    }
    if (local_48 != (long *)0x0) {
      (**(code **)(*local_48 + 0x28))();
    }
  }
  else {
    *(undefined4 *)param_10 = 0xe00002c1;
  }
  return 0;
}

