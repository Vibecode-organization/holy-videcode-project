// FUN_fffffff00996fb54 @ fffffff00996fb54 size=124

undefined8 FUN_fffffff00996fb54(long param_1,ulong param_2)

{
  undefined8 uVar1;
  long lVar2;
  ulong uVar3;
  
  uVar1 = (**(code **)(PTR_DAT_fffffff007ff27f8 + 0x78))();
  if ((int)uVar1 != 0) {
    uVar3 = param_2 << 3;
    if (0x7fffffffffffffff < uVar3) {
      uVar3 = 0x8000000000000000;
    }
    if (param_2 >> 0x3d != 0) {
      uVar3 = 0x8000000000000000;
    }
    lVar2 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ff19f8,uVar3);
    *(long *)(param_1 + 0x18) = lVar2;
    uVar1 = 0;
    if (lVar2 != 0) {
      *(ulong *)(param_1 + 0x28) = param_2;
      uVar1 = 1;
    }
  }
  return uVar1;
}

