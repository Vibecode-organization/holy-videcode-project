// FUN_fffffff009c07174 @ fffffff009c07174

undefined8 FUN_fffffff009c07174(long param_1)

{
  undefined1 auVar1 [16];
  long lVar2;
  undefined8 uVar3;
  uint uVar4;
  
  uVar3 = (**(code **)(PTR_DAT_fffffff008064be0 + 0xb8))();
  lVar2 = DAT_fffffff00af47df8;
  if ((int)uVar3 != 0) {
    uVar3 = 0;
    auVar1._4_4_ = -(uint)(DAT_fffffff00af47df8 == 0);
    auVar1._0_4_ = -(uint)(DAT_fffffff00af47df0 == 0);
    auVar1._8_4_ = -(uint)(DAT_fffffff00af47e08 == 0);
    auVar1._12_4_ = -(uint)(DAT_fffffff00af47e10 == 0);
    uVar4 = NEON_umaxv(auVar1,4);
    if (((uVar4 & 1) == 0) && (DAT_fffffff00af47e00 != -1)) {
      *(long *)(param_1 + 0x90) = DAT_fffffff00af47df0;
      *(long *)(param_1 + 0xa0) = lVar2;
      uVar3 = 1;
    }
  }
  return uVar3;
}

