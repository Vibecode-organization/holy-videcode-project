// FUN_fffffff009c363b0 @ fffffff009c363b0 size=272

undefined8 FUN_fffffff009c363b0(long param_1,long param_2,ulong param_3)

{
  long *plVar1;
  char *pcVar2;
  ulong uVar3;
  ulong uVar4;
  long lVar5;
  uint uVar6;
  undefined8 uVar7;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x148));
  uVar6 = (uint)param_3;
  if ((uVar6 != 0) && (uVar6 < *(uint *)(param_1 + 0x110))) {
    uVar3 = *(ulong *)(param_1 + 0x108);
    uVar4 = uVar3 + (ulong)*(uint *)(param_1 + 0x110) * 8;
    if (((uVar3 ^ uVar4) & 0xffc0000000000000) != 0) {
      uVar4 = uVar4 & 0xffffffffffff | 0xc8a2000000000000;
    }
    if ((uVar4 < uVar3) || (uVar4 - uVar3 >> 0x20 != 0)) {
      FUN_fffffff009c48f64();
    }
    else {
      lVar5 = (param_3 & 0xffffffff) * 8;
      if (lVar5 - (int)lVar5 == 0) {
        if (((param_3 & 0x1fffffff) >> 0x1c != 0) ||
           (uVar6 = uVar6 * 8, (uint)(uVar4 - uVar3) < uVar6 + 8)) goto LAB_fffffff009c364b8;
        plVar1 = (long *)(uVar3 + uVar6);
        uVar3 = (ulong)CARRY8(uVar3,(ulong)uVar6);
        uVar4 = -uVar3;
        if ((uVar4 != uVar3) || ((long)uVar4 < 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f50();
        }
        if (*plVar1 == 0) {
          *plVar1 = param_2;
          uVar7 = 1;
          goto LAB_fffffff009c36484;
        }
        pcVar2 = "Entry for shared event handle %d is not NULL (%p)";
        goto LAB_fffffff009c3647c;
      }
    }
    FUN_fffffff009c48f3c();
LAB_fffffff009c364b8:
                    /* WARNING: Subroutine does not return */
    FUN_fffffff009c48f28();
  }
  pcVar2 = "trying to use apparently bogus event handle %d";
LAB_fffffff009c3647c:
  thunk_EXT_FUN_80110000038fe9a0(pcVar2);
  uVar7 = 0;
LAB_fffffff009c36484:
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x148));
  return uVar7;
}

