// FUN_fffffff009c28af0 @ fffffff009c28af0

long FUN_fffffff009c28af0
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
               uint param_8)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  long lVar4;
  
  uVar2 = (ulong)param_8;
  if ((param_8 < *(uint *)(param_7 + 0x98)) && (uVar1 = *(ulong *)(param_7 + 0x308), uVar1 != 0)) {
    uVar3 = uVar1 + (ulong)*(uint *)(param_7 + 0x310) * 0x3c;
    if (((uVar1 ^ uVar3) & 0xffc0000000000000) != 0) {
      uVar3 = uVar3 & 0xffffffffffff | 0xc8a2000000000000;
    }
    if ((uVar3 < uVar1) || (uVar3 - uVar1 >> 0x20 != 0)) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff009c48f64(param_1,param_2,param_3,param_4,param_5,param_6);
    }
    lVar4 = uVar2 * 0x40 + (ulong)param_8 * -4;
    if (lVar4 != (int)lVar4) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff009c48f3c(param_1,param_2,param_3,param_4,param_5,param_6);
    }
    uVar2 = (uVar2 << 0x26) - (uVar2 << 0x22);
    if (((long)uVar2 < 0) || ((uint)(uVar3 - uVar1) < (int)(uVar2 >> 0x20) + 0x3cU)) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff009c48f28(param_1,param_2,param_3,param_4,param_5,param_6);
    }
    lVar4 = uVar1 + (uVar2 >> 0x20);
    uVar1 = (ulong)CARRY8(uVar1,uVar2 >> 0x20);
    uVar2 = -uVar1;
    if ((uVar2 != uVar1) || ((long)uVar2 < 0)) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff009c48f50(param_1,param_2,param_3,param_4,param_5,param_6);
    }
  }
  else {
    lVar4 = 0;
  }
  return lVar4;
}

