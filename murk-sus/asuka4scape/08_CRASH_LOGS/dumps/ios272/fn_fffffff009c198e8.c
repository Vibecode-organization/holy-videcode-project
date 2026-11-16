// FUN_fffffff009c198e8 @ fffffff009c198e8 size=372

/* WARNING: Removing unreachable block (ram,0xfffffff009c19b38) */

long * FUN_fffffff009c198e8(long param_1)

{
  uint uVar1;
  int iVar2;
  long *plVar3;
  ulong uVar4;
  ulong uVar5;
  ulong uVar6;
  long *plVar7;
  ulong uVar8;
  ulong uVar9;
  long lVar10;
  long lVar11;
  undefined1 auVar12 [16];
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x20));
  plVar3 = (long *)thunk_EXT_FUN_80110000038961f4(*(undefined4 *)(param_1 + 0x28));
  if (plVar3 != (long *)0x0) {
    uVar1 = *(uint *)(param_1 + 0x2c);
    if (uVar1 == 4) {
      uVar8 = param_1 + 0x38;
    }
    else {
      if ((int)uVar1 < 0) goto LAB_fffffff009c19a58;
      uVar8 = *(ulong *)(param_1 + 0x30);
    }
    if (0 < *(int *)(param_1 + 0x28)) {
      uVar4 = uVar8 + (ulong)uVar1 * 8;
      if (((uVar8 ^ uVar4) & 0xffc0000000000000) != 0) {
        uVar4 = uVar4 & 0xffffffffffff | 0xc8a2000000000000;
      }
      if ((uVar4 < uVar8) || (uVar4 - uVar8 >> 0x20 != 0)) {
        FUN_fffffff009c48f64();
LAB_fffffff009c19a58:
        auVar12 = FUN_fffffff009c48f14();
        lVar11 = auVar12._0_8_;
        plVar3 = (long *)FUN_fffffff009c37a94(DAT_fffffff00af483b0);
        if (((int)plVar3 != 0) &&
           (plVar3 = (long *)FUN_fffffff009c19b40(lVar11,lVar11,auVar12._8_8_,0),
           ((ulong)plVar3 & 1) == 0)) {
          thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar11 + 0x20));
          plVar3 = *(long **)(lVar11 + 0x18);
          if (plVar3 == (long *)0x0) {
            plVar3 = (long *)thunk_EXT_FUN_80110000038ccc44(1);
            if (*(long **)(lVar11 + 0x18) != (long *)0x0) {
              (**(code **)(**(long **)(lVar11 + 0x18) + 0x28))();
            }
            *(long **)(lVar11 + 0x18) = plVar3;
          }
          (**(code **)(*plVar3 + 0xf0))(plVar3,auVar12._8_8_);
          plVar3 = (long *)thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar11 + 0x20));
          return plVar3;
        }
        return plVar3;
      }
      uVar9 = 0;
      lVar10 = 0x10000000;
      lVar11 = 1;
      do {
        if (((long)uVar9 < 0) || ((uint)(uVar4 - uVar8) < (int)(uVar9 >> 0x20) + 8U)) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f28();
        }
        uVar6 = (ulong)CARRY8(uVar8,uVar9 >> 0x20);
        uVar5 = -uVar6;
        if ((uVar5 != uVar6) || ((long)uVar5 < 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f50();
        }
        plVar7 = *(long **)(uVar8 + (uVar9 >> 0x20));
        iVar2 = FUN_fffffff009c410e8(plVar7);
        if (iVar2 != 0) {
          (**(code **)(*plVar3 + 0xe8))(plVar3,plVar7);
          (**(code **)(*plVar7 + 0x28))(plVar7);
        }
        if (*(int *)(param_1 + 0x28) <= lVar11) goto LAB_fffffff009c19a24;
        lVar11 = lVar11 + 1;
        uVar9 = uVar9 + 0x800000000;
        lVar10 = lVar10 + -1;
      } while (lVar10 != 0);
      FUN_fffffff009c48f3c();
    }
  }
LAB_fffffff009c19a24:
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x20));
  return plVar3;
}

