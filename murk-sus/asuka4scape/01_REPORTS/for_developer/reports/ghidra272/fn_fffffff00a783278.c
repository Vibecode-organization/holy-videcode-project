// FUN_fffffff00a783278 @ fffffff00a783278 size=384

undefined8 FUN_fffffff00a783278(ulong param_1,long param_2,long param_3)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  undefined8 uVar4;
  long lVar5;
  ulong uVar6;
  undefined4 in_wzr;
  
  lVar5 = *(long *)(param_2 + 0x28);
  if (lVar5 == 0) {
    lVar5 = 0;
  }
  else {
    param_1 = ((long)*(char *)(param_2 + 0x40) & 0xffffU | (ulong)*(byte *)(param_2 + 0x41) << 8) ^
              0x4f71;
  }
  FUN_fffffff00a77c274(param_1,lVar5);
  *(undefined4 *)(param_2 + 0x54) = *(undefined4 *)(param_3 + 0x18);
  *(undefined8 *)(param_2 + 0x58) = *(undefined8 *)(param_3 + 0x20);
  if (*(long *)(param_2 + 0x18) == -1) {
    uVar4 = 0;
  }
  else {
    uVar6 = (ulong)*(uint *)(*(long *)(param_2 + 0x28) + 0xbc) & 0xffffff;
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
  uVar4 = FUN_fffffff00a78310c(param_2,0,uVar4,lVar5);
  FUN_fffffff00a779b78(lVar5);
  return uVar4;
}

