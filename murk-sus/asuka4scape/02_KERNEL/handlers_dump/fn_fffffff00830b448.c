// FUN_fffffff00830b448 @ fffffff00830b448 size=204 depth=1
// CALLERS:
//   fffffff00afc2c5a ?
//   fffffff00830b080 FUN_fffffff00830b034
// CALLS:
//   fffffff0083570a4 thunk_FUN_fffffff00a9029a0
//   fffffff008357ad4 thunk_FUN_fffffff00aa65b10

undefined8 FUN_fffffff00830b448(long param_1,uint *param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  
  thunk_FUN_fffffff00a9029a0((byte *)"VictimUserClient::getFreqList\n");
  if (*param_2 >> 4 < *(uint *)(param_1 + 0xe8)) {
    thunk_FUN_fffffff00a9029a0
              ((byte *)"VictimUserClient::getFreqList -- not enough memory allocated\n");
    thunk_FUN_fffffff00a9029a0
              ((byte *)"(*freqDataSize / sizeof(IOSACVictimFrequency) == %u, _mVictimsCount == %d\n"
              );
    uVar1 = 0xe00002bd;
  }
  else {
    thunk_FUN_fffffff00aa65b10
              (param_3,*(undefined8 **)(param_1 + 0xf0),(ulong)*(uint *)(param_1 + 0xe8) << 4);
    if (param_3 == (undefined8 *)0x0) {
      uVar1 = 0xe00002bc;
      thunk_FUN_fffffff00a9029a0((byte *)"VictimUserClient::getFreqList -- memcpy failed\n");
    }
    else {
      uVar1 = 0;
      *param_2 = *(int *)(param_1 + 0xe8) << 4;
    }
  }
  return uVar1;
}

