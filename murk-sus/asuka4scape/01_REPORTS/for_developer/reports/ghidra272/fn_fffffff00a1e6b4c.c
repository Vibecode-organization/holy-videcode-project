// FUN_fffffff00a1e6b4c @ fffffff00a1e6b4c size=752

long FUN_fffffff00a1e6b4c(uint param_1,uint param_2,ulong param_3,uint param_4)

{
  undefined *puVar1;
  long lVar2;
  long lVar3;
  ulong uVar4;
  uint uVar5;
  uint uVar6;
  ulong uVar7;
  long lVar8;
  int iVar9;
  byte bVar10;
  
  if ((param_4 & 1) == 0) {
    uVar4 = param_3 << 2 & 0x3fffffffc;
    uVar7 = param_3 << 2 & 0xfffffffc;
    if (uVar4 != uVar7) {
      return 0;
    }
    if (0xfffffff7 < uVar7) {
      return 0;
    }
    uVar5 = (int)uVar4 + 8;
  }
  else {
    uVar5 = 0;
  }
  uVar6 = uVar5 + param_1 + 0x44;
  if (0xffffffbb < param_1) {
    return 0;
  }
  if (CARRY4(uVar5,param_1 + 0x44)) {
    return 0;
  }
  uVar5 = uVar6 + param_2;
  if (CARRY4(uVar6,param_2)) {
LAB_fffffff00a1e6bd0:
    lVar2 = 0;
  }
  else {
    if (uVar5 < 0xc1) {
      bVar10 = 0;
      iVar9 = 0;
      uVar6 = 0;
    }
    else {
      if ((param_4 >> 2 & 1) != 0) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa4d114("size too large for the fast kmsg zone (%d) @%s:%d");
      }
      if ((param_4 >> 4 & 1) == 0) {
        uVar4 = param_3 << 4 & 0xffffffff0;
        uVar7 = param_3 << 4 & 0xfffffff0;
        if (uVar4 != uVar7) {
          return 0;
        }
        if (0xffffffdb < uVar7) {
          return 0;
        }
        uVar6 = 0xc;
        if ((param_4 & 1) != 0) {
          uVar6 = 0x10;
        }
        uVar7 = (param_3 & 0xffffffff) * (ulong)uVar6;
        if ((uVar7 & 0xffffffff00000000) != 0) {
          return 0;
        }
        uVar6 = (uint)uVar7;
        if (0xffffffdf < uVar6) {
          return 0;
        }
        uVar6 = uVar6 + 0x20;
        iVar9 = uVar5 - uVar6;
        if (uVar5 < uVar6) goto LAB_fffffff00a1e6bd0;
        uVar6 = (int)uVar4 + 0x24;
        bVar10 = 3;
        if (uVar6 < 0xa9) {
          bVar10 = 1;
        }
      }
      else {
        if (param_2 != 0) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff00aa4d114("non-zero aux size for kmsg type IKM_TYPE_KDATA_OOL. @%s:%d");
        }
        iVar9 = 0;
        bVar10 = 2;
      }
    }
    uVar5 = (param_4 & 8) << 0xc | (param_4 >> 1 & 1) << 2;
    if (iVar9 == 0) {
      lVar3 = 0;
    }
    else {
      lVar3 = FUN_fffffff00a220c30(&DAT_fffffff007c6afb0,iVar9,uVar5,0);
      if (((param_4 & 8) == 0) && (lVar3 == 0)) goto LAB_fffffff00a1e6bd0;
    }
    if (bVar10 < 2) {
      lVar8 = 0;
    }
    else {
      if (bVar10 == 3) {
        puVar1 = &DAT_fffffff007c81290;
        uVar4 = (param_3 & 0xffffffff) * 0x10 + 0x24;
      }
      else {
        uVar4 = (ulong)uVar6;
        puVar1 = (undefined *)0xfffffff007c81920;
      }
      lVar8 = FUN_fffffff00a220c30((ulong)puVar1 | 1,uVar4,uVar5,0);
      if (((param_4 & 8) == 0) && (lVar8 == 0)) {
        FUN_fffffff00a2212a8(&DAT_fffffff007c6afb0,lVar3,iVar9);
        return 0;
      }
    }
    lVar2 = FUN_fffffff00a292e20(DAT_fffffff00ad4d440,DAT_fffffff00ad4d448,0x8004);
    *(byte *)(lVar2 + 0x3f) = *(byte *)(lVar2 + 0x3f) & 0x3f | bVar10 << 6;
    *(short *)(lVar2 + 0x30) = (short)param_2;
    if ((param_4 >> 5 & 1) != 0) {
      *(undefined1 *)(lVar2 + 0x32) = 1;
    }
    if (bVar10 != 0) {
      if (bVar10 == 1) {
        *(long *)(lVar2 + 0xe8) = lVar2 + 0x40;
      }
      else if (lVar8 == 0) {
        *(long *)(lVar2 + 0xe8) = 0;
      }
      else {
        *(long *)(lVar2 + 0xe8) = lVar8;
      }
      if (lVar3 == 0) {
        lVar3 = 0;
      }
      *(long *)(lVar2 + 0xf0) = lVar3;
      *(uint *)(lVar2 + 0xf8) = uVar6;
      *(int *)(lVar2 + 0xfc) = iVar9;
    }
  }
  return lVar2;
}

