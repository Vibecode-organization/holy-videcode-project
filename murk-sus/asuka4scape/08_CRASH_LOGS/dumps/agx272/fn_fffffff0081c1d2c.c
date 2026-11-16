// FUN_fffffff0081c1d2c @ fffffff0081c1d2c size=112

undefined8 FUN_fffffff0081c1d2c(long param_1)

{
  long lVar1;
  long lVar2;
  float fVar3;
  
  lVar1 = *(long *)(param_1 + 0x280);
  lVar2 = *(long *)(param_1 + 0x348);
  *(undefined4 *)(lVar2 + 0x7cc) = *(undefined4 *)(lVar1 + 0x105d0);
  *(undefined4 *)(lVar2 + 2000) = *(undefined4 *)(lVar1 + 0x105d4);
  *(undefined4 *)(lVar2 + 0x7d4) = *(undefined4 *)(lVar1 + 0x105d8);
  *(undefined4 *)(lVar2 + 0x7d8) = *(undefined4 *)(lVar1 + 0x105dc);
  *(undefined4 *)(lVar2 + 0x7dc) = *(undefined4 *)(lVar1 + 0x105e0);
  *(undefined4 *)(lVar2 + 0x7e0) = *(undefined4 *)(lVar1 + 0x105e4);
  *(undefined4 *)(lVar2 + 0x7e4) = *(undefined4 *)(lVar1 + 0x105e8);
  fVar3 = (float)NEON_ucvtf(*(undefined4 *)(lVar1 + 0x105ec));
  *(int *)(lVar2 + 0x7e8) = (int)fVar3;
  *(undefined4 *)(lVar2 + 0x7c4) = *(undefined4 *)(lVar1 + 0x105c8);
  *(undefined4 *)(lVar2 + 0x7c8) = *(undefined4 *)(lVar1 + 0x105cc);
  return 0;
}

