// FUN_fffffff0081e29d4 @ fffffff0081e29d4 size=596

void FUN_fffffff0081e29d4(long param_1)

{
  undefined8 *puVar1;
  long *plVar2;
  undefined8 uVar3;
  long *plVar4;
  undefined1 auVar5 [16];
  code *pcVar6;
  long lVar7;
  long lVar8;
  long *plVar9;
  ulong unaff_x30;
  
  if (*(long *)(param_1 + 0x18) != 0) {
    lVar7 = *(long *)(param_1 + 0x38);
    while (lVar7 != 0) {
      lVar8 = (lVar7 + -1) * 0x18;
      puVar1 = (undefined8 *)(*(long *)(param_1 + 0x28) + (long)(int)lVar8);
      if (lVar8 - (int)lVar8 != 0) {
        puVar1 = (undefined8 *)
                 (*(long *)(param_1 + 0x28) + lVar8 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *(long *)(param_1 + 0x38) = lVar7 + -1;
      plVar2 = (long *)*puVar1;
      plVar4 = (long *)puVar1[1];
      plVar9 = (long *)puVar1[2];
      thunk_EXT_FUN_801100000297b408(plVar9);
      (**(code **)(*plVar9 + 0x28))(plVar9);
      (**(code **)(*plVar2 + 0x28))(plVar2);
      (**(code **)(*plVar4 + 0x28))(plVar4);
      lVar7 = *(long *)(param_1 + 0x38);
    }
    uVar3 = *(undefined8 *)(param_1 + 0x28);
    auVar5._8_8_ = 0;
    auVar5._0_8_ = *(ulong *)(param_1 + 0x30);
    lVar8 = *(ulong *)(param_1 + 0x30) * 0x18;
    lVar7 = -0x8000000000000000;
    if (SUB168(auVar5 * ZEXT816(0x18),8) == 0 && -1 < lVar8) {
      lVar7 = lVar8;
    }
    *(undefined8 *)(param_1 + 0x28) = 0;
    thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ca43c8,uVar3,lVar7);
    *(undefined8 *)(param_1 + 0x28) = 0;
    *(undefined8 *)(param_1 + 0x30) = 0;
    if (*(long **)(param_1 + 0x10) != (long *)0x0) {
      (**(code **)(**(long **)(param_1 + 0x10) + 0x28))();
    }
    *(undefined8 *)(param_1 + 0x10) = 0;
    if (*(long *)(param_1 + 0x40) != 0) {
      thunk_EXT_FUN_80110000038ff020();
    }
    while (*(long *)(param_1 + 0x60) != 0) {
      lVar7 = *(long *)(param_1 + 0x60) + -1;
      lVar8 = lVar7 * 0x20;
      puVar1 = (undefined8 *)(*(long *)(param_1 + 0x50) + (long)(int)lVar8);
      if (lVar8 - (int)lVar8 != 0) {
        puVar1 = (undefined8 *)
                 (*(long *)(param_1 + 0x50) + lVar8 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *(long *)(param_1 + 0x60) = lVar7;
      plVar2 = (long *)*puVar1;
      plVar4 = (long *)puVar1[1];
      plVar9 = (long *)puVar1[2];
      thunk_EXT_FUN_801100000297b408(plVar9);
      (**(code **)(*plVar9 + 0x28))(plVar9);
      (**(code **)(*plVar2 + 0x28))(plVar2);
      (**(code **)(*plVar4 + 0x28))(plVar4);
    }
    uVar3 = *(undefined8 *)(param_1 + 0x50);
    lVar8 = *(ulong *)(param_1 + 0x58) * 0x20;
    lVar7 = -0x8000000000000000;
    if (-1 < lVar8 && (*(ulong *)(param_1 + 0x58) & 0xf800000000000000) == 0) {
      lVar7 = lVar8;
    }
    *(undefined8 *)(param_1 + 0x50) = 0;
    thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ca4468,uVar3,lVar7);
    *(undefined8 *)(param_1 + 0x50) = 0;
    *(undefined8 *)(param_1 + 0x58) = 0;
    if (*(long *)(param_1 + 0x68) != 0) {
      thunk_EXT_FUN_80110000038ff020();
    }
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff0081e2c24. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(PTR_DAT_fffffff007ca6180 + 0x80))(param_1);
    return;
  }
                    /* WARNING: Does not return */
  pcVar6 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081e2c1c);
  (*pcVar6)();
}

