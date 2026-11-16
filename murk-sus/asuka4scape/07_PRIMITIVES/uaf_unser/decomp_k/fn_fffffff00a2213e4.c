// FUN_fffffff00a2213e4 @ fffffff00a2213e4 size=280
// CALLERS:
//   fffffff00a221338 FUN_fffffff00a2212a8@fffffff00a2212a8
//   fffffff00a221564 FUN_fffffff00a2214fc@fffffff00a2214fc
//   fffffff00a221cac FUN_fffffff00a2217b4@fffffff00a2217b4

void FUN_fffffff00a2213e4
               (long *param_1,undefined8 param_2,undefined8 param_3,long param_4,undefined8 param_5)

{
  uint extraout_w8;
  uint uVar1;
  uint uVar2;
  uint extraout_w10;
  ulong uVar3;
  long lVar4;
  
  if (0x40a < param_4 + 0xff52b3dc0U >> 7) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff00aa55998(param_4);
  }
  if (((ulong)param_1 & 1) != 0) {
    uVar3 = (ulong)param_1 & 0xfffffffffffffffe;
    uVar1 = *(uint *)(uVar3 + 0x48);
    param_1 = (long *)&DAT_fffffff007c28060;
    if ((uVar1 & 0x8000) != 0) {
      param_1 = &DAT_fffffff007bca7f8;
    }
    if ((uVar1 & 8) != 0) {
      param_1 = &DAT_fffffff007c6afb0;
    }
    lVar4 = *(long *)(uVar3 + 8);
    if (lVar4 != 0) goto LAB_fffffff00a22147c;
  }
  lVar4 = *param_1;
LAB_fffffff00a22147c:
  uVar2 = (uint)*(byte *)(param_1 + 2);
  uVar1 = *(uint *)(&DAT_fffffff007bca818 +
                   ((param_4 + 0xff52b3dc0U) * 0x1555556 >> 0x1e & 0x3fffffffc)) >> 8 & 7;
  if (param_1 == &DAT_fffffff007c6afb0) goto LAB_fffffff00a2214b4;
  if (param_1 == (long *)&DAT_fffffff007c2e100) goto LAB_fffffff00a2214b4;
  if (uVar1 != 1 && uVar1 != *(byte *)(param_1 + 2)) {
    do {
      param_1 = (long *)FUN_fffffff00aa4ff24(param_1,param_2);
      uVar1 = extraout_w8;
      uVar2 = extraout_w10;
LAB_fffffff00a2214b4:
    } while (uVar1 != uVar2);
  }
  FUN_fffffff00aa65cc0(param_2,param_5);
  if (lVar4 == 0) {
    lVar4 = *(long *)(param_4 + 8);
  }
  FUN_fffffff00a29223c(param_4,lVar4,param_2,param_5);
  return;
}

