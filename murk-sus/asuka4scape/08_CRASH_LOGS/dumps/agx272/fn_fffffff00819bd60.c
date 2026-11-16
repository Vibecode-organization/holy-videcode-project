// FUN_fffffff00819bd60 @ fffffff00819bd60 size=148

bool FUN_fffffff00819bd60(long param_1)

{
  bool bVar1;
  ulong uVar2;
  long lVar3;
  long lVar4;
  ulong local_28;
  
  uVar2 = thunk_EXT_FUN_80110000029474ec
                    (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),param_1 + 0x498);
  if ((uVar2 & 1) == 0) {
    bVar1 = false;
    *(undefined8 *)(*(long *)(param_1 + 0x610) + 0x20) = 0;
  }
  else {
    lVar4 = *(long *)(*(long *)(param_1 + 0x610) + 0x20);
    lVar3 = thunk_EXT_FUN_8011000003397c88();
    if (lVar4 == 0) {
      bVar1 = false;
      *(long *)(*(long *)(param_1 + 0x610) + 0x20) = lVar3;
    }
    else {
      local_28 = 0;
      thunk_EXT_FUN_8011000003398228(lVar3 - *(long *)(*(long *)(param_1 + 0x610) + 0x20),&local_28)
      ;
      bVar1 = 999999999 < local_28;
    }
  }
  return bVar1;
}

