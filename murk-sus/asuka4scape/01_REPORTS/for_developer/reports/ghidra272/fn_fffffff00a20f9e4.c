// FUN_fffffff00a20f9e4 @ fffffff00a20f9e4 size=1116

void FUN_fffffff00a20f9e4(void)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  ulong uVar5;
  undefined8 uVar6;
  ulong uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  uint uVar11;
  long lVar12;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 uStack_d0;
  undefined8 uStack_c8;
  ulong local_c0 [11];
  long local_68;
  
  local_68 = DAT_fffffff00ad30000;
  local_c0[7] = 0;
  local_c0[6] = 0;
  local_c0[9] = 0;
  local_c0[8] = 0;
  local_c0[3] = 0;
  local_c0[2] = 0;
  local_c0[5] = 0;
  local_c0[4] = 0;
  local_c0[1] = 0;
  local_c0[0] = 0;
  uVar1 = spsel;
  if (((uVar1 & 1) == 0) || (DAT_fffffff00adc4a18 == 0)) {
    FUN_fffffff00a205e48(local_c0,10,0,0);
    lVar12 = 2;
  }
  else {
    local_c0[0] = *(ulong *)(DAT_fffffff00adc4a18 + 0x100);
    uStack_e8 = *(undefined8 *)(DAT_fffffff00adc4a18 + 0xe8);
    uStack_d8 = 0;
    local_e0 = 0;
    uStack_c8 = 0;
    uStack_d0 = 0;
    local_f0 = 0;
    FUN_fffffff00a205e48((ulong)local_c0 | 8,9,&local_f0,0);
    lVar12 = 0;
  }
  uVar5 = DAT_fffffff007c6a380;
  uVar4 = DAT_fffffff007c6a378;
  uVar3 = DAT_fffffff007c6a360;
  uVar2 = DAT_fffffff007c6a358;
  uVar7 = local_c0[lVar12];
  uVar1 = uVar7 & 0x7ffffffffff;
  if ((uVar7 & 0x80000000000000) != 0) {
    uVar1 = uVar7 | 0xffffff8000000000;
  }
  if (((uVar1 < DAT_fffffff007c6a360 && DAT_fffffff007c6a358 <= uVar1) ||
      (DAT_fffffff007c6a378 <= uVar1 && uVar1 < DAT_fffffff007c6a380)) ||
     (DAT_fffffff007c6a3a0 <= uVar1 && uVar1 < DAT_fffffff007c6a3a8)) {
    uVar8 = FUN_fffffff00a396010();
  }
  else {
    uVar8 = 0;
  }
  uVar11 = (uint)lVar12;
  uVar7 = local_c0[uVar11 | 1];
  uVar1 = uVar7 & 0x7ffffffffff;
  if ((uVar7 & 0x80000000000000) != 0) {
    uVar1 = uVar7 | 0xffffff8000000000;
  }
  if (((uVar1 < uVar3 && uVar2 <= uVar1) || (uVar4 <= uVar1 && uVar1 < uVar5)) ||
     ((uVar9 = 0, DAT_fffffff007c6a3a0 <= uVar1 && (uVar1 < DAT_fffffff007c6a3a8)))) {
    uVar9 = FUN_fffffff00a396010();
  }
  uVar7 = local_c0[uVar11 + 2];
  uVar1 = uVar7 & 0x7ffffffffff;
  if ((uVar7 & 0x80000000000000) != 0) {
    uVar1 = uVar7 | 0xffffff8000000000;
  }
  if (((uVar1 < uVar3 && uVar2 <= uVar1) || (uVar4 <= uVar1 && uVar1 < uVar5)) ||
     ((uVar10 = 0, DAT_fffffff007c6a3a0 <= uVar1 && (uVar1 < DAT_fffffff007c6a3a8)))) {
    uVar10 = FUN_fffffff00a396010();
  }
  uVar7 = local_c0[uVar11 + 3];
  uVar1 = uVar7 & 0x7ffffffffff;
  if ((uVar7 & 0x80000000000000) != 0) {
    uVar1 = uVar7 | 0xffffff8000000000;
  }
  if (((uVar1 < uVar3 && uVar2 <= uVar1) || (uVar4 <= uVar1 && uVar1 < uVar5)) ||
     ((uVar6 = 0, DAT_fffffff007c6a3a0 <= uVar1 && (uVar1 < DAT_fffffff007c6a3a8)))) {
    uVar6 = FUN_fffffff00a396010();
  }
  FUN_fffffff00a29ead8(0x61f4024,uVar8,uVar9,uVar10,uVar6);
  uVar5 = DAT_fffffff007c6a380;
  uVar4 = DAT_fffffff007c6a378;
  uVar3 = DAT_fffffff007c6a360;
  uVar2 = DAT_fffffff007c6a358;
  uVar7 = local_c0[uVar11 | 4];
  uVar1 = uVar7 & 0x7ffffffffff;
  if ((uVar7 & 0x80000000000000) != 0) {
    uVar1 = uVar7 | 0xffffff8000000000;
  }
  if (((uVar1 < DAT_fffffff007c6a360 && DAT_fffffff007c6a358 <= uVar1) ||
      (DAT_fffffff007c6a378 <= uVar1 && uVar1 < DAT_fffffff007c6a380)) ||
     ((uVar8 = 0, DAT_fffffff007c6a3a0 <= uVar1 && (uVar1 < DAT_fffffff007c6a3a8)))) {
    uVar8 = FUN_fffffff00a396010();
  }
  uVar7 = local_c0[uVar11 | 5];
  uVar1 = uVar7 & 0x7ffffffffff;
  if ((uVar7 & 0x80000000000000) != 0) {
    uVar1 = uVar7 | 0xffffff8000000000;
  }
  if (((uVar1 < uVar3 && uVar2 <= uVar1) || (uVar4 <= uVar1 && uVar1 < uVar5)) ||
     ((uVar9 = 0, DAT_fffffff007c6a3a0 <= uVar1 && (uVar1 < DAT_fffffff007c6a3a8)))) {
    uVar9 = FUN_fffffff00a396010();
  }
  uVar7 = local_c0[uVar11 + 6];
  uVar1 = uVar7 & 0x7ffffffffff;
  if ((uVar7 & 0x80000000000000) != 0) {
    uVar1 = uVar7 | 0xffffff8000000000;
  }
  if (((uVar1 < uVar3 && uVar2 <= uVar1) || (uVar4 <= uVar1 && uVar1 < uVar5)) ||
     ((uVar10 = 0, DAT_fffffff007c6a3a0 <= uVar1 && (uVar1 < DAT_fffffff007c6a3a8)))) {
    uVar10 = FUN_fffffff00a396010();
  }
  uVar7 = local_c0[uVar11 + 7];
  uVar1 = uVar7 & 0x7ffffffffff;
  if ((uVar7 & 0x80000000000000) != 0) {
    uVar1 = uVar7 | 0xffffff8000000000;
  }
  if (((uVar1 < uVar3 && uVar2 <= uVar1) || (uVar4 <= uVar1 && uVar1 < uVar5)) ||
     ((uVar6 = 0, DAT_fffffff007c6a3a0 <= uVar1 && (uVar1 < DAT_fffffff007c6a3a8)))) {
    uVar6 = FUN_fffffff00a396010();
  }
  FUN_fffffff00a29ead8(0x61f4024,uVar8,uVar9,uVar10,uVar6);
  if (DAT_fffffff00ad30000 == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_fffffff00aa4c590();
}

