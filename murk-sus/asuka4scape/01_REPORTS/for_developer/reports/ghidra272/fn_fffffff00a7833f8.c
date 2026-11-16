// FUN_fffffff00a7833f8 @ fffffff00a7833f8 size=408

undefined8 FUN_fffffff00a7833f8(long param_1,uint param_2)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  undefined8 uVar4;
  long lVar5;
  ulong uVar6;
  undefined4 in_wzr;
  
  lVar5 = *(long *)(param_1 + 0x28);
  if (lVar5 == 0) {
    if ((param_2 >> 6 & 1) != 0) goto LAB_fffffff00a7834d8;
    lVar5 = 0;
  }
  else if ((param_2 >> 6 & 1) != 0) {
LAB_fffffff00a7834d8:
    *(ushort *)(param_1 + 0x42) = *(ushort *)(param_1 + 0x42) | 0x8010;
    return 1;
  }
  if (*(long *)(param_1 + 0x18) == -1) {
    uVar4 = 0;
  }
  else {
    uVar6 = (ulong)*(uint *)(lVar5 + 0xbc) & 0xffffff;
    lVar1 = tpidr_el1;
    uVar3 = (ulong)*(uint *)(lVar1 + 0x4e8);
    if (DAT_fffffff00ad94178 != 0) {
      FUN_fffffff00a2262d4(&DAT_fffffff00ad94170,lVar1,0);
      uVar3 = DAT_fffffff00ad94178;
    }
    DAT_fffffff00ad94178 = uVar3;
    uVar3 = DAT_fffffff00ad94178;
    if ((int)uVar6 < DAT_fffffff00add4930) {
      uVar4 = *(undefined8 *)(DAT_fffffff00add4928 + uVar6 * 8);
    }
    else {
      uVar4 = 0;
    }
    iVar2 = (int)DAT_fffffff00ad94178;
    if ((int)DAT_fffffff00ad94178 == *(int *)(lVar1 + 0x4e8)) {
      DAT_fffffff00ad94178 = CONCAT44(DAT_fffffff00ad94178._4_4_,in_wzr);
    }
    if (iVar2 != *(int *)(lVar1 + 0x4e8)) {
      FUN_fffffff00a226e08(&DAT_fffffff00ad94170,lVar1,uVar3 & 0xffffffff);
    }
  }
  uVar4 = FUN_fffffff00a78310c(param_1,0,uVar4,lVar5);
  return uVar4;
}

