// FUN_fffffff009c2a8b4 @ fffffff009c2a8b4 size=244

undefined8
FUN_fffffff009c2a8b4(long param_1,ulong param_2,ulong param_3,ulong *param_4,long param_5)

{
  long *plVar1;
  long lVar2;
  uint uVar3;
  ulong uVar4;
  ulong uVar5;
  undefined8 uVar6;
  
  if ((param_2 < 6) && ((param_3 == 0 || (param_5 != 0)))) {
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x50));
    uVar4 = param_1 + 0x1b0;
    uVar5 = (param_1 + 0x210U) - uVar4;
    if ((param_1 + 0x210U < uVar4) || (uVar5 >> 0x20 != 0)) {
      FUN_fffffff009c48f64();
    }
    else {
      uVar3 = (int)param_2 * 0x10;
      if (uVar3 + 0x10 <= (uint)uVar5) {
        plVar1 = (long *)(uVar4 + uVar3);
        uVar5 = (ulong)CARRY8(uVar4,(ulong)uVar3);
        uVar4 = -uVar5;
        if ((uVar4 == uVar5) && (-1 < (long)uVar4)) {
          uVar6 = 0;
          lVar2 = *plVar1;
          uVar4 = plVar1[1];
          *param_4 = uVar4;
          if (((param_3 != 0) && (lVar2 != 0)) && (uVar4 != 0)) {
            if (param_3 < uVar4) {
              uVar6 = 0xe00002e8;
            }
            else {
              thunk_EXT_FUN_8011000003a61b10(param_5);
              uVar6 = 0;
            }
          }
          thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x50));
          return uVar6;
        }
                    /* WARNING: Subroutine does not return */
        FUN_fffffff009c48f50();
      }
    }
                    /* WARNING: Subroutine does not return */
    FUN_fffffff009c48f28();
  }
  return 0xe00002c2;
}

