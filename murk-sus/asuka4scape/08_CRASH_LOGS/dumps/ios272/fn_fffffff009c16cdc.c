// FUN_fffffff009c16cdc @ fffffff009c16cdc size=212

/* WARNING: Removing unreachable block (ram,0xfffffff009c16e04) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c16e38) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c16e70) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c16ee0) */

void FUN_fffffff009c16cdc(long param_1,undefined8 param_2,undefined8 param_3)

{
  bool bVar1;
  undefined8 *puVar2;
  code *pcVar3;
  long lVar4;
  ulong uVar5;
  ulong uVar6;
  ulong unaff_x30;
  undefined1 auVar7 [16];
  
  if (*(long *)(param_1 + 0x40) == 0) {
    *(undefined8 *)(param_1 + 0x20) = 0;
    if (*(long *)(param_1 + 0x30) != 0) {
      thunk_EXT_FUN_80110000038ff020();
      *(undefined8 *)(param_1 + 0x30) = 0;
    }
    if (*(long *)(param_1 + 0x60) != 0) {
      thunk_EXT_FUN_80110000038ff020();
      *(undefined8 *)(param_1 + 0x60) = 0;
    }
    lVar4 = *(long *)(param_1 + 0x58);
    if (lVar4 != 0) {
      if (*(long *)(lVar4 + 0x68) != 0) {
        thunk_EXT_FUN_80110000038ff020();
        lVar4 = *(long *)(param_1 + 0x58);
      }
      *(undefined8 *)(param_1 + 0x58) = 0;
      thunk_EXT_FUN_80110000038fe768(&DAT_fffffff00806ba70,lVar4,0x70);
      *(undefined8 *)(param_1 + 0x58) = 0;
    }
    if (*(long **)(param_1 + 0x10) != (long *)0x0) {
      (**(code **)(**(long **)(param_1 + 0x10) + 0x28))();
    }
    *(undefined8 *)(param_1 + 0x10) = 0;
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c16da0);
      (*pcVar3)();
    }
                    /* WARNING: Could not recover jumptable at 0xfffffff009c16da8. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(PTR_DAT_fffffff00806ca30 + 0x80))(param_1);
    return;
  }
  auVar7 = FUN_fffffff009c48e50();
  uVar5 = auVar7._8_8_;
  lVar4 = auVar7._0_8_;
  puVar2 = (undefined8 *)(lVar4 + 0x20);
  if ((*(byte *)(lVar4 + 0x50) & 1) == 0) {
    do {
      uVar6 = *(ulong *)*puVar2;
      bVar1 = uVar5 > uVar6;
      if (uVar5 <= uVar6) goto LAB_fffffff009c16e7c;
    } while (*(ulong *)*puVar2 != uVar6);
    *(ulong *)*puVar2 = uVar5;
  }
  else {
    *(ulong *)*puVar2 = uVar5;
    bVar1 = true;
  }
LAB_fffffff009c16e7c:
  if (uVar5 != 0xffffffffffffffff) {
    thunk_EXT_FUN_80110000036da494(0x85210028,*(undefined8 *)(lVar4 + 0x28),uVar5,0,0,0);
  }
  FUN_fffffff009c16f04(lVar4,uVar5);
  if (bVar1) {
    FUN_fffffff009c37bb0(*(undefined8 *)(lVar4 + 0x10),param_3);
    FUN_fffffff009c16fa0(lVar4,param_3);
    return;
  }
  return;
}

