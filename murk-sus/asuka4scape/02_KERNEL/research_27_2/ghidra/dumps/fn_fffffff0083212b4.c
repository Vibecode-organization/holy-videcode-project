// FUN_fffffff0083212b4 @ fffffff0083212b4 size=4
// CALLERS:
//   fffffff00afc2eec no-fn
//   fffffff008320f9c FUN_fffffff008320f50@fffffff008320f50
// CALLEES:

undefined4 FUN_fffffff0083212b4(long param_1,int *param_2,long param_3)

{
  int iVar1;
  long *plVar2;
  char *pcVar3;
  long lVar4;
  long lVar5;
  undefined4 uVar6;
  
  thunk_FUN_fffffff00a9029a0((byte *)"AggressorUserClient::setAggressorKey\n");
  if (*param_2 == 0xc) {
    lVar4 = 4;
    lVar5 = 8;
    do {
      if (9 < (int)*(char *)(param_3 + lVar4) - 0x30U &&
          0x19 < (((int)*(char *)(param_3 + lVar4) & 0xffffffdfU) - 0x41 & 0xff)) {
        pcVar3 = "AggressorUserClient::setAggressorKey - ERROR - invalid character \'%c\'\n";
        goto LAB_fffffff0083213bc;
      }
      lVar4 = lVar4 + 1;
      lVar5 = lVar5 + -1;
    } while (lVar5 != 0);
    uVar6 = 0xe00002bc;
    if (*(long *)(param_1 + 0x100) != 0) {
      plVar2 = thunk_FUN_fffffff00a89e264(param_3,0xc);
      iVar1 = (**(code **)(**(long **)(param_1 + 0x100) + 200))
                        (*(long **)(param_1 + 0x100),"function-saca",plVar2);
      uVar6 = 0;
      if (iVar1 == 0) {
        uVar6 = 0xe00002bc;
      }
      if (plVar2 != (long *)0x0) {
        (**(code **)(*plVar2 + 0x28))(plVar2);
      }
    }
  }
  else {
    pcVar3 = 
    "AggressorUserClient::setAggressorKey - ERROR - failed to set aggressor key due to incorrect data size\n"
    ;
LAB_fffffff0083213bc:
    thunk_FUN_fffffff00a9029a0((byte *)pcVar3);
    uVar6 = 0xe00002c2;
  }
  return uVar6;
}

