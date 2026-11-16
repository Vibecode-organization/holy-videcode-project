// FUN_fffffff009954f28 @ fffffff009954f28 size=92

void FUN_fffffff009954f28(long param_1,long param_2,uint param_3)

{
  undefined4 uVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x38);
  if (lVar3 != 0) {
    uVar1 = *(undefined4 *)(param_2 + 0x18);
    uVar2 = *(undefined8 *)(*(long *)(param_1 + 0x50) + 0x148);
    do {
      FUN_fffffff00994c2f0(uVar2,uVar1,*(undefined8 *)(lVar3 + 0x18),param_3 & 1);
      lVar3 = *(long *)(lVar3 + 0x38);
    } while (lVar3 != 0);
  }
  return;
}

