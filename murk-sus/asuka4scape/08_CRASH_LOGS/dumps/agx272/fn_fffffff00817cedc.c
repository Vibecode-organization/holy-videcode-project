// FUN_fffffff00817cedc @ fffffff00817cedc size=116

undefined8 FUN_fffffff00817cedc(long param_1)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  ulong uVar4;
  undefined4 uVar5;
  
  plVar1 = (long *)(*(long *)(param_1 + 0x20) + 0x1ac98);
  if (*plVar1 != 0) {
    uVar4 = thunk_EXT_FUN_8011000003397c88();
    lVar3 = *plVar1;
    while (lVar3 != 0) {
      uVar2 = *(ulong *)(lVar3 + 0x58) - uVar4;
      uVar5 = 0;
      if (uVar4 <= *(ulong *)(lVar3 + 0x58) && uVar2 != 0) {
        uVar5 = (undefined4)(uVar2 / 24000);
      }
      *(undefined4 *)(lVar3 + 0x88) = uVar5;
      lVar3 = *(long *)(lVar3 + 0x60);
    }
  }
  return 0;
}

