// FUN_fffffff009c22820 @ fffffff009c22820 size=196

undefined1 FUN_fffffff009c22820(long param_1,uint param_2)

{
  ulong uVar1;
  undefined1 uVar2;
  ulong uVar3;
  ulong uVar4;
  long lVar5;
  ulong uVar6;
  
  uVar3 = *(ulong *)(param_1 + 0x180);
  if ((uVar3 == 0) || (*(uint *)(param_1 + 0x98) <= param_2)) {
    if (param_2 == 0) {
      uVar2 = *(undefined1 *)(param_1 + 0x72);
    }
    else {
      uVar2 = 0;
    }
    return uVar2;
  }
  uVar4 = uVar3 + (ulong)*(uint *)(param_1 + 0x188) * 0x38;
  if (((uVar3 ^ uVar4) & 0xffc0000000000000) != 0) {
    uVar4 = uVar4 & 0xffffffffffff | 0xc8a2000000000000;
  }
  if ((uVar4 < uVar3) || (uVar4 - uVar3 >> 0x20 != 0)) {
    FUN_fffffff009c48f64();
  }
  else {
    lVar5 = (ulong)param_2 * 0x40 + (ulong)param_2 * -8;
    if (lVar5 == (int)lVar5) {
      uVar1 = ((ulong)param_2 << 0x26) - ((ulong)param_2 << 0x23);
      if ((-1 < (long)uVar1) && ((int)(uVar1 >> 0x20) + 0x38U <= (uint)(uVar4 - uVar3))) {
        uVar6 = (ulong)CARRY8(uVar3,uVar1 >> 0x20);
        uVar4 = -uVar6;
        if ((uVar4 == uVar6) && (-1 < (long)uVar4)) {
          return *(undefined1 *)(uVar3 + (uVar1 >> 0x20) + 0x34);
        }
                    /* WARNING: Subroutine does not return */
        FUN_fffffff009c48f50();
      }
      goto LAB_fffffff009c228dc;
    }
  }
  FUN_fffffff009c48f3c();
LAB_fffffff009c228dc:
                    /* WARNING: Subroutine does not return */
  FUN_fffffff009c48f28();
}

