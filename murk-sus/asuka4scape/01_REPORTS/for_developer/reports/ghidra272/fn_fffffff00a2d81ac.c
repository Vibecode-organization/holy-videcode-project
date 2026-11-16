// FUN_fffffff00a2d81ac @ fffffff00a2d81ac size=252

undefined8 FUN_fffffff00a2d81ac(long param_1,long *param_2)

{
  int iVar1;
  long lVar2;
  uint uVar3;
  uint uVar4;
  
  if (*param_2 != 0) {
    return 1;
  }
  lVar2 = *(long *)(param_1 + 0x38);
  if (lVar2 != 0) {
    uVar3 = 1;
    do {
      iVar1 = FUN_fffffff00a30b88c(lVar2);
      if (iVar1 != 0) {
        *param_2 = lVar2;
        return 1;
      }
      FUN_fffffff00a22aeac(param_1 + 8);
      uVar4 = uVar3;
      if (0x1e < uVar3) {
        uVar4 = 0x1f;
      }
      (&DAT_fffffff00ad33da0)[uVar4] = (&DAT_fffffff00ad33da0)[uVar4] + 1;
      uVar4 = uVar3;
      if (6 < uVar3) {
        uVar4 = 7;
      }
      FUN_fffffff00a246e7c
                (FUN_fffffff00a2271e0,0,*(undefined4 *)(&DAT_fffffff00ad0c410 + (ulong)uVar4 * 4),
                 1000);
      FUN_fffffff00a247a70(0,0,0);
      FUN_fffffff00a3061bc(param_1);
      lVar2 = *(long *)(param_1 + 0x38);
      uVar3 = uVar3 + 1;
    } while (lVar2 != 0);
  }
  return 0;
}

