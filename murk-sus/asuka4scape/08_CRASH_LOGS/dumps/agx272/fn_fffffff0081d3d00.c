// FUN_fffffff0081d3d00 @ fffffff0081d3d00 size=484

void FUN_fffffff0081d3d00(long param_1)

{
  long lVar1;
  undefined1 auVar2 [16];
  code *pcVar3;
  long lVar4;
  ulong uVar5;
  undefined8 *puVar6;
  long lVar7;
  long *plVar8;
  ulong uVar9;
  long *plVar10;
  ulong unaff_x30;
  
  lVar4 = *(long *)(param_1 + 0x20);
  if (lVar4 != 0) {
    uVar5 = *(ulong *)(param_1 + 0x28);
    if (0 < (long)uVar5) {
      lVar4 = 0;
      do {
        uVar9 = *(ulong *)(param_1 + 0x20) + lVar4 * 0x18;
        if (((*(ulong *)(param_1 + 0x20) ^ uVar9) & 0xffc0000000000000) != 0) {
          uVar9 = uVar9 & 0xffffffffffff | 0xc8a2000000000000;
        }
        plVar8 = *(long **)(uVar9 + 8);
        if (*(long **)(uVar9 + 8) != (long *)0x0) {
          do {
            plVar10 = (long *)plVar8[4];
            if (plVar10 == (long *)0x0) {
              puVar6 = (undefined8 *)plVar8[5];
              if ((long *)*puVar6 != plVar8) goto LAB_fffffff0081d3ed4;
              *(undefined8 **)(uVar9 + 0x10) = puVar6;
            }
            else {
              if ((long *)plVar10[5] != plVar8 + 4) {
                    /* WARNING: Does not return */
                pcVar3 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff0081d3ee4);
                (*pcVar3)();
              }
              if (*(long **)plVar8[5] != plVar8) {
LAB_fffffff0081d3ed4:
                    /* WARNING: Does not return */
                pcVar3 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff0081d3edc);
                (*pcVar3)();
              }
              plVar10[5] = (long)plVar8[5];
              puVar6 = (undefined8 *)plVar8[5];
            }
            *puVar6 = plVar10;
            if ((long *)*plVar8 != (long *)0x0) {
              (**(code **)(*(long *)*plVar8 + 0x28))();
            }
            *plVar8 = 0;
            thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ca40a8,plVar8,0x70);
            plVar8 = plVar10;
          } while (plVar10 != (long *)0x0);
          uVar5 = *(ulong *)(param_1 + 0x28);
        }
        lVar4 = lVar4 + 1;
      } while (lVar4 < (long)uVar5);
      lVar4 = *(long *)(param_1 + 0x20);
    }
    auVar2._8_8_ = 0;
    auVar2._0_8_ = uVar5;
    lVar1 = -0x8000000000000000;
    if (SUB168(auVar2 * ZEXT816(0x18),8) == 0 && -1 < (long)(uVar5 * 0x18)) {
      lVar1 = uVar5 * 0x18;
    }
    *(undefined8 *)(param_1 + 0x20) = 0;
    thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ca3fb8,lVar4,lVar1);
    *(undefined8 *)(param_1 + 0x20) = 0;
  }
  lVar4 = *(long *)(param_1 + 0x18);
  if (lVar4 != 0) {
    lVar7 = *(ulong *)(param_1 + 0x28) * 0x20;
    lVar1 = -0x8000000000000000;
    if (-1 < lVar7 && (*(ulong *)(param_1 + 0x28) & 0xf800000000000000) == 0) {
      lVar1 = lVar7;
    }
    *(undefined8 *)(param_1 + 0x18) = 0;
    thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ca4008,lVar4,lVar1);
    *(undefined8 *)(param_1 + 0x18) = 0;
  }
  *(undefined8 *)(param_1 + 0x28) = 0;
  if (*(long *)(param_1 + 0x10) != 0) {
    thunk_EXT_FUN_80110000038ff1d4();
    *(undefined8 *)(param_1 + 0x10) = 0;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081d3ec8);
    (*pcVar3)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff0081d3ed0. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff007ca6180 + 0x80))(param_1);
  return;
}

