// FUN_fffffff009c22cc0 @ fffffff009c22cc0 size=168

undefined4 FUN_fffffff009c22cc0(long param_1,uint param_2)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  
  uVar1 = *(ulong *)(param_1 + 0x350);
  if ((uVar1 == 0) || (*(uint *)(param_1 + 0x98) <= param_2)) {
    return 0;
  }
  uVar2 = uVar1 + (ulong)*(uint *)(param_1 + 0x358) * 0x20;
  if (((uVar1 ^ uVar2) & 0xffc0000000000000) != 0) {
    uVar2 = uVar2 & 0xffffffffffff | 0xc8a2000000000000;
  }
  if ((uVar2 < uVar1) || (uVar2 - uVar1 >> 0x20 != 0)) {
    FUN_fffffff009c48f64();
  }
  else if ((ulong)param_2 << 5 == (long)(int)((ulong)param_2 << 5)) {
    if ((((ulong)param_2 & 0x7ffffff) >> 0x1a == 0) &&
       (param_2 = param_2 * 0x20, param_2 + 0x20 <= (uint)(uVar2 - uVar1))) {
      uVar3 = (ulong)CARRY8(uVar1,(ulong)param_2);
      uVar2 = -uVar3;
      if ((uVar2 == uVar3) && (-1 < (long)uVar2)) {
        return *(undefined4 *)(uVar1 + param_2 + 0xc);
      }
                    /* WARNING: Subroutine does not return */
      FUN_fffffff009c48f50();
    }
    goto LAB_fffffff009c22d60;
  }
  FUN_fffffff009c48f3c();
LAB_fffffff009c22d60:
                    /* WARNING: Subroutine does not return */
  FUN_fffffff009c48f28();
}

