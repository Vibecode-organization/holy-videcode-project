// FUN_fffffff009c36664 @ fffffff009c36664 size=424

void FUN_fffffff009c36664(long param_1,ulong param_2)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  ulong uVar4;
  ulong uVar5;
  long lVar6;
  ulong uVar7;
  long *plVar8;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x148));
  if (*(uint *)(param_1 + 0x110) <= (uint)param_2) {
LAB_fffffff009c367bc:
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c367dc);
      (*pcVar2)();
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x148));
    return;
  }
  uVar4 = *(ulong *)(param_1 + 0x108);
  uVar5 = uVar4 + (ulong)*(uint *)(param_1 + 0x110) * 8;
  if (((uVar4 ^ uVar5) & 0xffc0000000000000) != 0) {
    uVar5 = uVar5 & 0xffffffffffff | 0xc8a2000000000000;
  }
  if ((uVar5 < uVar4) || (uVar5 - uVar4 >> 0x20 != 0)) {
    FUN_fffffff009c48f64();
  }
  else {
    lVar6 = (param_2 & 0xffffffff) * 8;
    if (lVar6 - (int)lVar6 == 0) {
      if ((param_2 & 0x1fffffff) >> 0x1c == 0) {
        uVar1 = (uint)param_2 * 8;
        uVar7 = (ulong)uVar1;
        uVar1 = uVar1 + 8;
        if (uVar1 <= (uint)(uVar5 - uVar4)) {
          uVar5 = -(ulong)CARRY8(uVar4,uVar7);
          if ((uVar5 != CARRY8(uVar4,uVar7)) || ((long)uVar5 < 0)) {
                    /* WARNING: Subroutine does not return */
            FUN_fffffff009c48f50();
          }
          if ((*(long *)(uVar4 + uVar7) != 0) && (iVar3 = FUN_fffffff009c17f54(), iVar3 != 0)) {
            uVar4 = *(ulong *)(param_1 + 0x108);
            uVar5 = uVar4 + (ulong)*(uint *)(param_1 + 0x110) * 8;
            if (((uVar4 ^ uVar5) & 0xffc0000000000000) != 0) {
              uVar5 = uVar5 & 0xffffffffffff | 0xc8a2000000000000;
            }
            if ((uVar5 < uVar4) || (uVar5 - uVar4 >> 0x20 != 0)) {
              FUN_fffffff009c48f64();
            }
            else if (uVar1 <= (uint)(uVar5 - uVar4)) {
              uVar5 = -(ulong)CARRY8(uVar4,uVar7);
              if ((uVar5 != CARRY8(uVar4,uVar7)) || ((long)uVar5 < 0)) {
                    /* WARNING: Subroutine does not return */
                FUN_fffffff009c48f50();
              }
              plVar8 = *(long **)(uVar4 + uVar7);
              thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x148));
              if (plVar8 == (long *)0x0) {
                return;
              }
              FUN_fffffff009c1720c(plVar8);
              if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
                pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c367b0);
                (*pcVar2)();
              }
                    /* WARNING: Could not recover jumptable at 0xfffffff009c367b8. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
              (**(code **)(*plVar8 + 0x28))(plVar8,(undefined8 *)(*plVar8 + 0x28));
              return;
            }
                    /* WARNING: Subroutine does not return */
            FUN_fffffff009c48f28();
          }
          goto LAB_fffffff009c367bc;
        }
      }
      goto LAB_fffffff009c367f8;
    }
  }
  FUN_fffffff009c48f3c();
LAB_fffffff009c367f8:
                    /* WARNING: Subroutine does not return */
  FUN_fffffff009c48f28();
}

