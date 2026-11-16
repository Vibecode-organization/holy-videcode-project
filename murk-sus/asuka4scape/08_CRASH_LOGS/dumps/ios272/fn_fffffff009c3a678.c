// FUN_fffffff009c3a678 @ fffffff009c3a678 size=580

/* WARNING: Removing unreachable block (ram,0xfffffff009c3a830) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c3a73c) */

void FUN_fffffff009c3a678(long param_1)

{
  uint uVar1;
  code *pcVar2;
  ulong uVar3;
  long lVar4;
  ulong uVar5;
  ulong uVar6;
  long *plVar7;
  ulong uVar8;
  ulong uVar9;
  ulong uVar10;
  ulong uVar11;
  ulong unaff_x30;
  
  uVar5 = (ulong)*(uint *)(param_1 + 0x110);
  uVar3 = *(ulong *)(param_1 + 0x108);
  if (*(uint *)(param_1 + 0x110) == 0) {
    lVar4 = 0;
  }
  else {
    uVar8 = 0;
    uVar9 = 0;
    uVar10 = 0xffffffff7ffffff8;
    do {
      uVar6 = uVar3 + uVar5 * 8;
      if (((uVar3 ^ uVar6) & 0xffc0000000000000) != 0) {
        uVar6 = uVar6 & 0xffffffffffff | 0xc8a2000000000000;
      }
      if ((uVar6 < uVar3) || (uVar6 - uVar3 >> 0x20 != 0)) {
        FUN_fffffff009c48f64();
LAB_fffffff009c3a8a4:
        FUN_fffffff009c48f3c();
LAB_fffffff009c3a8a8:
                    /* WARNING: Subroutine does not return */
        FUN_fffffff009c48f28();
      }
      uVar10 = uVar10 + 8;
      if (uVar10 < 0xffffffff00000000) goto LAB_fffffff009c3a8a4;
      if ((long)uVar8 < 0) goto LAB_fffffff009c3a8a8;
      uVar11 = uVar8 >> 0x20;
      uVar1 = (int)(uVar8 >> 0x20) + 8;
      if ((uint)(uVar6 - uVar3) < uVar1) goto LAB_fffffff009c3a8a8;
      uVar6 = -(ulong)CARRY8(uVar3,uVar11);
      if ((uVar6 != CARRY8(uVar3,uVar11)) || ((long)uVar6 < 0)) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff009c48f50();
      }
      plVar7 = *(long **)(uVar3 + uVar11);
      if ((plVar7 != (long *)0x0) && (plVar7 != (long *)0x0)) {
        (**(code **)(*plVar7 + 0x28))(plVar7);
        uVar3 = *(ulong *)(param_1 + 0x108);
        uVar5 = (ulong)*(uint *)(param_1 + 0x110);
        uVar6 = uVar3 + uVar5 * 8;
        if (((uVar3 ^ uVar6) & 0xffc0000000000000) != 0) {
          uVar6 = uVar6 & 0xffffffffffff | 0xc8a2000000000000;
        }
        if ((uVar6 < uVar3) || (uVar6 - uVar3 >> 0x20 != 0)) {
          FUN_fffffff009c48f64();
LAB_fffffff009c3a8b4:
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f28();
        }
        if ((uint)(uVar6 - uVar3) < uVar1) goto LAB_fffffff009c3a8b4;
        uVar6 = -(ulong)CARRY8(uVar3,uVar11);
        if ((uVar6 != CARRY8(uVar3,uVar11)) || ((long)uVar6 < 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f50();
        }
        *(undefined8 *)(uVar3 + uVar11) = 0;
      }
      uVar8 = uVar8 + 0x800000000;
      uVar9 = uVar9 + 1;
    } while (uVar9 < uVar5);
    lVar4 = uVar5 << 3;
  }
  thunk_EXT_FUN_80110000038fe768(&DAT_fffffff00806c420,uVar3,lVar4);
  *(undefined8 *)(param_1 + 0x108) = 0;
  *(undefined4 *)(param_1 + 0x110) = 0;
  if (*(long **)(param_1 + 0x140) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x140) + 0x28))();
  }
  lVar4 = *(long *)(param_1 + 0xf8);
  *(undefined8 *)(param_1 + 0x140) = 0;
  if ((lVar4 != 0) && (lVar4 != 0)) {
    thunk_EXT_FUN_801100000326c730(lVar4);
  }
  if (*(long *)(param_1 + 0xd8) != 0) {
    thunk_EXT_FUN_80110000038ff020();
    *(undefined8 *)(param_1 + 0xd8) = 0;
  }
  if (*(long *)(param_1 + 0xe0) != 0) {
    thunk_EXT_FUN_80110000038ff474();
    *(undefined8 *)(param_1 + 0xe0) = 0;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff009c3a89c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(PTR_DAT_fffffff00806ca28 + 0x80))(param_1);
    return;
  }
                    /* WARNING: Does not return */
  pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c3a894);
  (*pcVar2)();
}

