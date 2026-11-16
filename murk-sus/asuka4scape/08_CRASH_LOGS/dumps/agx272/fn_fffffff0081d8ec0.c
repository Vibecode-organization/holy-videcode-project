// FUN_fffffff0081d8ec0 @ fffffff0081d8ec0 size=100

undefined8 FUN_fffffff0081d8ec0(void)

{
  int iVar1;
  undefined8 uVar2;
  
  uVar2 = FUN_fffffff0081a1f90();
  if (((DAT_fffffff00ae22cf1 >> 4 & 1) != 0) &&
     ((iVar1 = FUN_fffffff0081d6c4c(), iVar1 == 0x8110 ||
      (iVar1 = FUN_fffffff0081d6c4c(), iVar1 == 0x8112)))) {
    DAT_fffffff00ae22cf1 = DAT_fffffff00ae22cf1 | 2;
  }
  return uVar2;
}

