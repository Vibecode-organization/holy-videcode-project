// FUN_fffffff008321690 @ fffffff008321690 size=152 depth=1
// CALLERS:
//   fffffff00afc2ef3 ?
//   fffffff008321100 FUN_fffffff0083210b4
// CALLS:
//   fffffff0083570a4 thunk_FUN_fffffff00a9029a0

undefined8 FUN_fffffff008321690(long param_1,uint *param_2,long param_3)

{
  undefined8 *puVar1;
  long lVar2;
  long lVar3;
  uint uVar4;
  undefined8 uVar5;
  ulong uVar6;
  long lVar7;
  
  thunk_FUN_fffffff00a9029a0((byte *)"AggressorUserClient::getFreqList\n");
  uVar4 = *(uint *)(param_1 + 0xf8);
  uVar6 = (ulong)uVar4;
  if (*param_2 >> 4 < uVar4) {
    uVar5 = 0xe00002db;
  }
  else {
    if (uVar4 != 0) {
      lVar7 = 0;
      lVar2 = *(long *)(param_1 + 0xe8);
      lVar3 = *(long *)(param_1 + 0xf0);
      do {
        puVar1 = (undefined8 *)(param_3 + lVar7 * 0x10);
        *puVar1 = *(undefined8 *)(lVar2 + lVar7 * 8);
        *(undefined4 *)(puVar1 + 1) = *(undefined4 *)(lVar3 + lVar7 * 4);
        lVar7 = lVar7 + 1;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
    }
    uVar5 = 0;
    *param_2 = uVar4 << 4;
  }
  return uVar5;
}

