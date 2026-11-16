// FUN_fffffff009c2993c @ fffffff009c2993c size=188

undefined1 FUN_fffffff009c2993c(long param_1,uint param_2)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  
  if ((*(ulong *)(param_1 + 0x328) <= (ulong)param_2) ||
     (uVar1 = *(ulong *)(param_1 + 0x318), uVar1 == 0)) {
    return 0;
  }
  uVar2 = uVar1 + (ulong)*(uint *)(param_1 + 800) * 0x18;
  if (((uVar1 ^ uVar2) & 0xffc0000000000000) != 0) {
    uVar2 = uVar2 & 0xffffffffffff | 0xc8a2000000000000;
  }
  if ((uVar2 < uVar1) || (uVar2 - uVar1 >> 0x20 != 0)) {
    FUN_fffffff009c48f64();
  }
  else if ((ulong)param_2 * 0x18 - (long)(int)((ulong)param_2 * 0x18) == 0) {
    if ((((ulong)(param_2 * 3) & 0x1fffffff) >> 0x1c == 0) &&
       (param_2 = param_2 * 0x18, param_2 + 0x18 <= (uint)(uVar2 - uVar1))) {
      uVar3 = (ulong)CARRY8(uVar1,(ulong)param_2);
      uVar2 = -uVar3;
      if ((uVar2 == uVar3) && (-1 < (long)uVar2)) {
        return *(undefined1 *)(uVar1 + param_2);
      }
                    /* WARNING: Subroutine does not return */
      FUN_fffffff009c48f50();
    }
    goto LAB_fffffff009c299f0;
  }
  FUN_fffffff009c48f3c();
LAB_fffffff009c299f0:
                    /* WARNING: Subroutine does not return */
  FUN_fffffff009c48f28();
}

