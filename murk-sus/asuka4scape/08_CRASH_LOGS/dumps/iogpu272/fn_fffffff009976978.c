// FUN_fffffff009976978 @ fffffff009976978 size=124

void FUN_fffffff009976978(long param_1)

{
  long *plVar1;
  long lVar2;
  ulong uVar3;
  
  lVar2 = *(long *)(param_1 + 0x430);
  if (*(int *)(lVar2 + 0x290) != 0) {
    uVar3 = 0;
    do {
      plVar1 = *(long **)(lVar2 + 0x150 + uVar3 * 8);
      if (plVar1 != (long *)0x0) {
        (**(code **)(*plVar1 + 0x28))();
        lVar2 = *(long *)(param_1 + 0x430);
      }
      *(undefined8 *)(lVar2 + 0x150 + uVar3 * 8) = 0;
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)(lVar2 + 0x290));
  }
  *(undefined4 *)(lVar2 + 0x290) = 0;
  return;
}

