// FUN_fffffff00830b278 @ fffffff00830b278 size=4 depth=1
// CALLERS:
//   fffffff00afc2c56 ?
//   fffffff00830afec FUN_fffffff00830afa0
// CALLS:

undefined8 FUN_fffffff00830b278(long param_1,uint *param_2,long param_3)

{
  uint uVar1;
  int iVar2;
  long *plVar3;
  char *pcVar4;
  long lVar5;
  long lVar6;
  undefined8 uVar7;
  undefined1 extraout_q0 [16];
  undefined1 auVar8 [16];
  undefined1 in_q1 [16];
  undefined1 in_q2 [16];
  undefined1 in_q3 [16];
  undefined4 in_s4;
  undefined4 in_s5;
  
  uVar7 = 0xe00002bc;
  thunk_FUN_fffffff00a9029a0((byte *)"VictimUserClient::registerVictim - Registering victim!\n");
  uVar1 = *param_2;
  if (uVar1 < 0xc || (uVar1 & 3) != 0) {
    pcVar4 = 
    "VictimUserClient::registerVictim - ERROR - failed to register victim due to incorrect data size\n"
    ;
LAB_fffffff00830b398:
    thunk_FUN_fffffff00a9029a0((byte *)pcVar4);
    uVar7 = 0xe00002c2;
  }
  else {
    lVar5 = (ulong)uVar1 - 4;
    lVar6 = 4;
    do {
      if (9 < (int)*(char *)(param_3 + lVar6) - 0x30U &&
          0x19 < (((int)*(char *)(param_3 + lVar6) & 0xffffffdfU) - 0x41 & 0xff)) {
        pcVar4 = "VictimUserClient::registerVictim - ERROR - invalid character \'%c\'\n";
        goto LAB_fffffff00830b398;
      }
      lVar6 = lVar6 + 1;
      lVar5 = lVar5 + -1;
    } while (lVar5 != 0);
    plVar3 = thunk_FUN_fffffff00a89e264(param_3,(ulong)uVar1);
    iVar2 = (**(code **)(**(long **)(param_1 + 0xd8) + 200))
                      (*(long **)(param_1 + 0xd8),"function-sac",plVar3);
    auVar8 = extraout_q0;
    if (plVar3 != (long *)0x0) {
      auVar8 = (**(code **)(*plVar3 + 0x28))(plVar3);
    }
    if (iVar2 != 0) {
      plVar3 = FUN_fffffff008348cec
                         (auVar8,in_q1,in_q2,in_q3,in_s4,in_s5,*(long **)(param_1 + 0xd8),
                          (byte *)"function-sac");
      *(long **)(param_1 + 0xe0) = plVar3;
      if (plVar3 == (long *)0x0) {
        thunk_FUN_fffffff00a9029a0
                  ((byte *)"VictimUserClient::registerVictim - ERROR - failed to register victim\n")
        ;
      }
      else {
        uVar7 = 0;
      }
    }
  }
  return uVar7;
}

