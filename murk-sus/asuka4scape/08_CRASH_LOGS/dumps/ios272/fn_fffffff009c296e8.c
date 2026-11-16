// FUN_fffffff009c296e8 @ fffffff009c296e8 size=8

undefined1 FUN_fffffff009c296e8(long param_1,uint param_2)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  long lVar4;
  ulong uVar5;
  
  if ((*(uint *)(param_1 + 0x98) <= param_2) || (uVar2 = *(ulong *)(param_1 + 0x308), uVar2 == 0)) {
    return 0;
  }
  uVar3 = uVar2 + (ulong)*(uint *)(param_1 + 0x310) * 0x3c;
  if (((uVar2 ^ uVar3) & 0xffc0000000000000) != 0) {
    uVar3 = uVar3 & 0xffffffffffff | 0xc8a2000000000000;
  }
  if ((uVar3 < uVar2) || (uVar3 - uVar2 >> 0x20 != 0)) {
    FUN_fffffff009c48f64();
  }
  else {
    lVar4 = (ulong)param_2 * 0x40 + (ulong)param_2 * -4;
    if (lVar4 == (int)lVar4) {
      uVar1 = ((ulong)param_2 << 0x26) - ((ulong)param_2 << 0x22);
      if ((-1 < (long)uVar1) && ((int)(uVar1 >> 0x20) + 0x3cU <= (uint)(uVar3 - uVar2))) {
        uVar5 = (ulong)CARRY8(uVar2,uVar1 >> 0x20);
        uVar3 = -uVar5;
        if ((uVar3 == uVar5) && (-1 < (long)uVar3)) {
          return *(undefined1 *)(uVar2 + (uVar1 >> 0x20) + 0x22);
        }
                    /* WARNING: Subroutine does not return */
        FUN_fffffff009c48f50();
      }
      goto LAB_fffffff009c297a0;
    }
  }
  FUN_fffffff009c48f3c();
LAB_fffffff009c297a0:
                    /* WARNING: Subroutine does not return */
  FUN_fffffff009c48f28();
}

