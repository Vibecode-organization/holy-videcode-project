// FUN_fffffff009c2a76c @ fffffff009c2a76c size=328

/* WARNING: Removing unreachable block (ram,0xfffffff009c2a868) */

undefined8 FUN_fffffff009c2a76c(long param_1,ulong param_2,ulong param_3,long param_4)

{
  long *plVar1;
  uint uVar2;
  long lVar3;
  ulong uVar4;
  ulong uVar5;
  undefined8 uVar6;
  
  if (((param_2 < 6) && (param_3 < 0x401)) && ((param_3 == 0 || (param_4 != 0)))) {
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x50));
    uVar4 = param_1 + 0x1b0;
    uVar5 = (param_1 + 0x210U) - uVar4;
    if ((param_1 + 0x210U < uVar4) || (uVar5 >> 0x20 != 0)) {
      FUN_fffffff009c48f64();
    }
    else {
      uVar2 = (uint)param_2 * 0x10;
      if (uVar2 + 0x10 <= (uint)uVar5) {
        plVar1 = (long *)(uVar4 + uVar2);
        uVar5 = (ulong)CARRY8(uVar4,(ulong)uVar2);
        uVar4 = -uVar5;
        if ((uVar4 == uVar5) && (-1 < (long)uVar4)) {
          if ((*plVar1 != 0) && (plVar1[1] != 0)) {
            thunk_EXT_FUN_80110000038fe6b0();
            *plVar1 = 0;
            plVar1[1] = 0;
          }
          if (param_3 == 0) {
            uVar6 = 0;
          }
          else {
            lVar3 = thunk_EXT_FUN_80110000038fe580(param_3);
            *plVar1 = lVar3;
            if (lVar3 == 0) {
              uVar6 = 0xe00002bd;
            }
            else {
              plVar1[1] = param_3;
              thunk_EXT_FUN_8011000003a61b10(lVar3,param_4,param_3);
              uVar6 = 0;
              *(byte *)(*(long *)(param_1 + 0x178) + 0x2f) =
                   *(byte *)(*(long *)(param_1 + 0x178) + 0x2f) |
                   (byte)(1 << (ulong)((uint)param_2 & 0x1f));
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

