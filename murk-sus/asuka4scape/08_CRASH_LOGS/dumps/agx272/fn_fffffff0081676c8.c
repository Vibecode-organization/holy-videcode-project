// FUN_fffffff0081676c8 @ fffffff0081676c8 size=268

void FUN_fffffff0081676c8(long *param_1)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  ulong uVar4;
  
  if ((*(byte *)((long)param_1 + 0x1112c) >> 1 & 1) != 0) {
    plVar1 = param_1 + 0x3599;
    thunk_EXT_FUN_80110000038ff020(param_1[0x359c]);
    param_1[0x359c] = 0;
    uVar2 = (**(code **)(*param_1 + 0x778))(param_1);
    uVar4 = -(uVar2 >> 0x1f & 1) & 0xfffffff000000000 | (uVar2 & 0xffffffff) << 4;
    if (0x7fffffff < (uint)uVar2) {
      uVar4 = 0x8000000000000000;
    }
    lVar3 = param_1[0x359d];
    param_1[0x359d] = 0;
    thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ca2bb8,lVar3,uVar4);
    param_1[0x359d] = 0;
    lVar3 = *plVar1;
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar3 + 0x40));
    if (0 < *(long *)(lVar3 + 0x38)) {
      if (*(long *)(lVar3 + 0x50) != 0) {
        thunk_EXT_FUN_801100000297b408();
      }
      if (*(long *)(lVar3 + 0x58) != 0) {
        thunk_EXT_FUN_801100000297b408();
      }
      *(long *)(lVar3 + 0x38) = *(long *)(lVar3 + 0x38) + -1;
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar3 + 0x40));
    if ((long *)*plVar1 != (long *)0x0) {
      (**(code **)(*(long *)*plVar1 + 0x28))();
    }
    *plVar1 = 0;
  }
  return;
}

