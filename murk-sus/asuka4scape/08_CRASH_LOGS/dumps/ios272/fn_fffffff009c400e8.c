// FUN_fffffff009c400e8 @ fffffff009c400e8 size=460

/* WARNING: Removing unreachable block (ram,0xfffffff009c4021c) */

ulong FUN_fffffff009c400e8(long param_1)

{
  uint uVar1;
  uint uVar2;
  ulong uVar3;
  ulong uVar4;
  ulong uVar5;
  ulong uVar6;
  ulong uVar7;
  ulong uVar8;
  ulong uVar9;
  ulong uVar10;
  ulong uVar11;
  ulong uVar12;
  undefined1 auVar13 [16];
  
  uVar1 = *(uint *)(*(long *)(param_1 + 0xe8) + 0xd8);
  uVar11 = *(ulong *)(param_1 + 0x108);
  uVar2 = *(uint *)(param_1 + 0x110);
  uVar12 = (ulong)uVar2;
  uVar3 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff00806c380,(ulong)uVar1 << 3);
  *(ulong *)(param_1 + 0x108) = uVar3;
  *(uint *)(param_1 + 0x110) = uVar1;
  if (uVar3 == 0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x11,"IONewZero failed to alloc handles\n");
    *(ulong *)(param_1 + 0x108) = uVar11;
    *(uint *)(param_1 + 0x110) = uVar2;
  }
  else if (uVar11 != 0) {
    if (uVar2 != 0) {
      uVar5 = uVar3 + (ulong)uVar1 * 8;
      if (((uVar3 ^ uVar5) & 0xffc0000000000000) != 0) {
        uVar5 = uVar5 & 0xffffffffffff | 0xc8a2000000000000;
      }
      uVar6 = uVar11 + uVar12 * 8;
      if (((uVar11 ^ uVar6) & 0xffc0000000000000) != 0) {
        uVar6 = uVar6 & 0xffffffffffff | 0xc8a2000000000000;
      }
      if ((uVar5 < uVar3) || (uVar5 - uVar3 >> 0x20 != 0)) {
        auVar13 = FUN_fffffff009c48f64();
        *(undefined8 *)(auVar13._0_8_ + 0x28) = *(undefined8 *)(auVar13._8_8_ + 0x28);
        *(undefined8 *)(auVar13._8_8_ + 0x28) = 0;
        return auVar13._0_8_;
      }
      uVar8 = 0xffffffff7ffffff8;
      uVar7 = 0;
      uVar9 = uVar12;
      do {
        uVar8 = uVar8 + 8;
        if (uVar8 < 0xffffffff00000000) {
          FUN_fffffff009c48f3c();
LAB_fffffff009c4029c:
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f28();
        }
        if ((long)uVar7 < 0) goto LAB_fffffff009c4029c;
        uVar10 = uVar7 >> 0x20;
        uVar1 = (int)(uVar7 >> 0x20) + 8;
        if ((uint)(uVar5 - uVar3) < uVar1) goto LAB_fffffff009c4029c;
        uVar4 = -(ulong)CARRY8(uVar3,uVar10);
        if ((uVar4 != CARRY8(uVar3,uVar10)) || ((long)uVar4 < 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f50();
        }
        if ((uVar6 - uVar11 & 0xffffffff00000000) != 0 || uVar6 < uVar11) {
          FUN_fffffff009c48f64();
LAB_fffffff009c402a8:
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f28();
        }
        if ((uint)(uVar6 - uVar11) < uVar1) goto LAB_fffffff009c402a8;
        uVar4 = -(ulong)CARRY8(uVar11,uVar10);
        if ((uVar4 != CARRY8(uVar11,uVar10)) || ((long)uVar4 < 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f50();
        }
        uVar7 = uVar7 + 0x800000000;
        *(undefined8 *)(uVar3 + uVar10) = *(undefined8 *)(uVar11 + uVar10);
        uVar1 = (int)uVar9 - 1;
        uVar9 = (ulong)uVar1;
      } while (uVar1 != 0);
    }
    thunk_EXT_FUN_80110000038fe768(&DAT_fffffff00806c3d0,uVar11,uVar12 << 3);
  }
  return (ulong)(uVar3 != 0);
}

