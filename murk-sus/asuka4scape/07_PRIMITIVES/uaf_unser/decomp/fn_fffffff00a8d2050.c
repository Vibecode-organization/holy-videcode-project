// FUN_fffffff00a8d2050 @ fffffff00a8d2050 size=276
// CALLERS:
//   fffffff00a8d9a18 FUN_fffffff00a8d96f4@fffffff00a8d96f4
//   fffffff00a8d2388 FUN_fffffff00a8d2338@fffffff00a8d2338
//   fffffff00a9918e0 FUN_fffffff00a991868@fffffff00a991868
//   fffffff00a991b14 FUN_fffffff00a991868@fffffff00a991868
//   fffffff00a9968d0 FUN_fffffff00a9966bc@fffffff00a9966bc

undefined8 FUN_fffffff00a8d2050(long param_1,long param_2,ulong param_3)

{
  uint uVar1;
  ulong uVar2;
  undefined8 uVar3;
  ulong uVar4;
  long lVar5;
  uint uVar6;
  long lVar7;
  
  uVar3 = 0;
  if ((param_2 != 0) && (param_3 < 0x3fffe)) {
    uVar4 = FUN_fffffff00a1d14a0(param_2,param_3);
    uVar2 = uVar4 & 0xffffffff;
    if (param_3 <= (uVar4 & 0xffffffff)) {
      uVar2 = param_3;
    }
    uVar1 = (int)uVar2 + 1;
    lVar5 = FUN_fffffff00a220c30(&DAT_fffffff007c6afb0,(ulong)uVar1,0x41000,0);
    uVar3 = 0;
    if (lVar5 != 0) {
      FUN_fffffff00aa65b10(lVar5,param_2,uVar2);
      *(undefined1 *)(lVar5 + uVar2) = 0;
      uVar6 = *(uint *)(param_1 + 0xc);
      if ((((uVar6 & 1) == 0) && (lVar7 = *(long *)(param_1 + 0x10), lVar7 != 0)) && (lVar7 != 0)) {
        *(undefined8 *)(param_1 + 0x10) = 0;
        FUN_fffffff00a2212a8(&DAT_fffffff007c6afb0,lVar7,uVar6 >> 0xe);
        uVar6 = *(uint *)(param_1 + 0xc);
        DAT_fffffff00ad97ef0 = DAT_fffffff00ad97ef0 - (ulong)(uVar6 >> 0xe);
      }
      *(long *)(param_1 + 0x10) = lVar5;
      *(uint *)(param_1 + 0xc) = uVar6 & 0x3ffe | uVar1 * 0x4000;
      DAT_fffffff00ad97ef0 = DAT_fffffff00ad97ef0 + (ulong)uVar1;
      uVar3 = 1;
    }
  }
  return uVar3;
}

