// FUN_fffffff009970388 @ fffffff009970388 size=100

undefined8 FUN_fffffff009970388(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  
  uVar1 = (**(code **)(PTR_DAT_fffffff007ff27f8 + 0x78))();
  if ((int)uVar1 != 0) {
    lVar2 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ff19f8,0x80);
    *(long *)(param_1 + 0x18) = lVar2;
    uVar1 = 0;
    if (lVar2 != 0) {
      *(undefined8 *)(param_1 + 0x28) = 0x10;
      uVar1 = 1;
    }
  }
  return uVar1;
}

