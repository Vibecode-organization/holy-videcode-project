// FUN_fffffff009c3f044 @ fffffff009c3f044 size=236

/* WARNING: Removing unreachable block (ram,0xfffffff009c3f0ec) */

undefined8 FUN_fffffff009c3f044(long param_1,ulong param_2,long *param_3)

{
  int iVar1;
  undefined8 uVar2;
  uint uVar3;
  ulong uVar4;
  ulong uVar5;
  ulong uVar6;
  long lVar7;
  undefined1 auVar8 [16];
  undefined1 *puStack_48;
  undefined8 uStack_40;
  long lStack_38;
  
  uVar3 = (uint)param_2;
  if ((uVar3 == 0) || (*(uint *)(param_1 + 0x110) <= uVar3)) {
    return 0;
  }
  uVar4 = *(ulong *)(param_1 + 0x108);
  uVar6 = uVar4 + (ulong)*(uint *)(param_1 + 0x110) * 8;
  if (((uVar4 ^ uVar6) & 0xffc0000000000000) != 0) {
    uVar6 = uVar6 & 0xffffffffffff | 0xc8a2000000000000;
  }
  if ((uVar6 < uVar4) || (uVar6 - uVar4 >> 0x20 != 0)) {
    FUN_fffffff009c48f64();
  }
  else {
    lVar7 = (param_2 & 0xffffffff) * 8;
    if (lVar7 - (int)lVar7 == 0) {
      if (((param_2 & 0x1fffffff) >> 0x1c == 0) &&
         (uVar3 = uVar3 * 8, uVar3 + 8 <= (uint)(uVar6 - uVar4))) {
        uVar5 = (ulong)CARRY8(uVar4,(ulong)uVar3);
        uVar6 = -uVar5;
        if ((uVar6 != uVar5) || ((long)uVar6 < 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f50();
        }
        lVar7 = *(long *)(uVar4 + uVar3);
        if (lVar7 == 0) {
          return 0;
        }
        if (lVar7 == 0) {
          return 0;
        }
        if (*(long *)(lVar7 + 0x10) == *(long *)(param_1 + 0x118)) {
          *param_3 = lVar7;
          return 1;
        }
        auVar8 = FUN_fffffff009c492c0();
        lVar7 = auVar8._0_8_;
        lStack_38 = *(long *)PTR_DAT_fffffff00806ca40;
        puStack_48 = &DAT_aaaaaaaaaaaaaaaa;
        uStack_40 = 0;
        thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar7 + 0xd8));
        iVar1 = FUN_fffffff009c3f044(lVar7,auVar8._8_8_,&puStack_48);
        uVar2 = 0;
        if (iVar1 != 0) {
          FUN_fffffff009c16670(&uStack_40,puStack_48);
          uVar2 = uStack_40;
        }
        thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar7 + 0xd8));
        if (*(long *)PTR_DAT_fffffff00806ca40 != lStack_38) {
          uVar2 = thunk_EXT_FUN_8011000003a48590();
          return uVar2;
        }
        return uVar2;
      }
      goto LAB_fffffff009c3f124;
    }
  }
  FUN_fffffff009c48f3c();
LAB_fffffff009c3f124:
                    /* WARNING: Subroutine does not return */
  FUN_fffffff009c48f28();
}

