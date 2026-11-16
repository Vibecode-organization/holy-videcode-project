// FUN_fffffff0099707e0 @ fffffff0099707e0 size=260

undefined8
FUN_fffffff0099707e0(long param_1,undefined8 param_2,undefined8 param_3,uint param_4,long param_5)

{
  undefined8 uVar1;
  undefined8 uVar2;
  long lVar3;
  ulong uVar4;
  long lVar5;
  
  uVar1 = (*DAT_fffffff007feb260)();
  if ((int)uVar1 != 0) {
    *(undefined8 *)(param_1 + 0x10) = param_2;
    uVar2 = thunk_EXT_FUN_80110000038ff134();
    *(undefined8 *)(param_1 + 0x18) = uVar2;
    thunk_EXT_FUN_801100000326c6a4(param_3);
    *(undefined8 *)(param_1 + 0x28) = param_3;
    if (param_4 != 0) {
      lVar5 = 0;
      uVar4 = (ulong)param_4;
      do {
        if ((param_5 != 0) && (lVar3 = *(long *)(param_5 + lVar5 * 8), lVar3 != 0)) {
          *(long *)(param_1 + 0x138 + lVar5 * 8) = lVar3;
          (**(code **)(**(long **)(param_5 + lVar5 * 8) + 0x20))();
          uVar2 = (**(code **)(**(long **)(param_5 + lVar5 * 8) + 0xa8))();
          *(undefined8 *)(param_1 + 0x38 + lVar5 * 8) = uVar2;
        }
        lVar5 = lVar5 + 1;
        uVar4 = uVar4 - 1;
      } while (uVar4 != 0);
    }
    *(undefined8 *)(param_1 + 0x1b8) = 0;
    *(long *)(param_1 + 0x1c0) = param_1 + 0x1b8;
  }
  return uVar1;
}

