// FUN_fffffff009c29de8 @ fffffff009c29de8 size=252

undefined1 FUN_fffffff009c29de8(long param_1,uint param_2,uint param_3)

{
  long lVar1;
  undefined1 *puVar2;
  uint uVar3;
  ulong uVar4;
  ulong uVar5;
  ulong uVar6;
  
  if ((*(ulong *)(param_1 + 0x328) <= (ulong)param_2) ||
     (uVar3 = FUN_fffffff009c2993c(), uVar3 <= param_3)) {
    return 0;
  }
  uVar4 = *(ulong *)(param_1 + 0x318);
  uVar5 = uVar4 + (ulong)*(uint *)(param_1 + 800) * 0x18;
  if (((uVar4 ^ uVar5) & 0xffc0000000000000) != 0) {
    uVar5 = uVar5 & 0xffffffffffff | 0xc8a2000000000000;
  }
  if ((uVar5 < uVar4) || (uVar5 - uVar4 >> 0x20 != 0)) {
    FUN_fffffff009c48f64();
  }
  else if ((ulong)param_2 * 0x18 - (long)(int)((ulong)param_2 * 0x18) == 0) {
    if ((((ulong)(param_2 * 3) & 0x1fffffff) >> 0x1c == 0) &&
       (param_2 = param_2 * 0x18, param_2 + 0x18 <= (uint)(uVar5 - uVar4))) {
      uVar6 = (ulong)CARRY8(uVar4,(ulong)param_2);
      uVar5 = -uVar6;
      if ((uVar5 == uVar6) && (-1 < (long)uVar5)) {
        lVar1 = uVar4 + param_2 + 0x14;
        puVar2 = (undefined1 *)(lVar1 + (int)param_3);
        if ((ulong)param_3 != (long)(int)param_3) {
          puVar2 = (undefined1 *)(lVar1 + (ulong)param_3 & 0xffffffffffff | 0x2bad000000000000);
        }
        return *puVar2;
      }
                    /* WARNING: Subroutine does not return */
      FUN_fffffff009c48f50();
    }
    goto LAB_fffffff009c29edc;
  }
  FUN_fffffff009c48f3c();
LAB_fffffff009c29edc:
                    /* WARNING: Subroutine does not return */
  FUN_fffffff009c48f28();
}

