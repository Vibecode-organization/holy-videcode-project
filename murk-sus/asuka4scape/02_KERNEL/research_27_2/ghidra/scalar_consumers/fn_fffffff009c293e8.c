// FUN_fffffff009c293e8 @ fffffff009c293e8

undefined2
FUN_fffffff009c293e8
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,uint param_8)

{
  undefined2 uVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  long lVar5;
  ulong uVar6;
  
  uVar2 = (ulong)param_8;
  if ((param_8 < *(uint *)(param_7 + 0x98)) && (uVar3 = *(ulong *)(param_7 + 0x308), uVar3 != 0)) {
    uVar4 = uVar3 + (ulong)*(uint *)(param_7 + 0x310) * 0x3c;
    if (((uVar3 ^ uVar4) & 0xffc0000000000000) != 0) {
      uVar4 = uVar4 & 0xffffffffffff | 0xc8a2000000000000;
    }
    if ((uVar4 < uVar3) || (uVar4 - uVar3 >> 0x20 != 0)) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff009c48f64(param_1,param_2,param_3,param_4,param_5,param_6);
    }
    lVar5 = uVar2 * 0x40 + (ulong)param_8 * -4;
    if (lVar5 != (int)lVar5) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff009c48f3c(param_1,param_2,param_3,param_4,param_5,param_6);
    }
    uVar2 = (uVar2 << 0x26) - (uVar2 << 0x22);
    if (((long)uVar2 < 0) || ((uint)(uVar4 - uVar3) < (int)(uVar2 >> 0x20) + 0x3cU)) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff009c48f28(param_1,param_2,param_3,param_4,param_5,param_6);
    }
    uVar6 = (ulong)CARRY8(uVar3,uVar2 >> 0x20);
    uVar4 = -uVar6;
    if ((uVar4 != uVar6) || ((long)uVar4 < 0)) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff009c48f50(param_1,param_2,param_3,param_4,param_5,param_6);
    }
    uVar1 = *(undefined2 *)(uVar3 + (uVar2 >> 0x20) + 0x26);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

