// FUN_fffffff00995c7bc @ fffffff00995c7bc size=4

void FUN_fffffff00995c7bc(long param_1)

{
  long *plVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  long lVar5;
  
  thunk_EXT_FUN_8011000003a132c0
            (
            "%s enter: fRingBuffer=%p, fNumRingEntries=%u, fRingGPUFinishedCount=%u, fRingGPUSubmittedCount=%u.\n"
            );
  uVar2 = *(uint *)(param_1 + 0x48);
  if (uVar2 != *(uint *)(param_1 + 0x4c)) {
    do {
      uVar3 = *(uint *)(param_1 + 0x54);
      uVar4 = 0;
      if (uVar3 != 0) {
        uVar4 = uVar2 / uVar3;
      }
      lVar5 = (ulong)(uVar2 - uVar4 * uVar3) * 8;
      plVar1 = (long *)(*(long *)(param_1 + 0x58) + (long)(int)lVar5);
      if (lVar5 != (int)lVar5) {
        plVar1 = (long *)(*(long *)(param_1 + 0x58) + lVar5 & 0xffffffffffffU | 0x2bad000000000000);
      }
      lVar5 = *plVar1;
      if (lVar5 != 0) {
        thunk_EXT_FUN_8011000003a132c0
                  ("\tfRingBuffer[%d]=[ctx:%p, gputask:%p, stamp[idx:%d, stamp:%d]");
        if (*(int *)(lVar5 + 0x88) != 0xff) {
          thunk_EXT_FUN_8011000003a132c0("[idx:%d, stamp:%d]");
        }
        thunk_EXT_FUN_8011000003a132c0("\n");
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 != *(uint *)(param_1 + 0x4c));
  }
  thunk_EXT_FUN_8011000003a132c0("%s exit\n");
  return;
}

