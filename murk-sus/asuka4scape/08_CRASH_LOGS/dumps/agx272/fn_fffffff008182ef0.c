// FUN_fffffff008182ef0 @ fffffff008182ef0 size=248

void FUN_fffffff008182ef0(long param_1)

{
  code *pcVar1;
  long lVar2;
  ulong uVar3;
  ulong unaff_x30;
  
  *(undefined8 *)(param_1 + 0x40) = 0;
  *(undefined8 *)(param_1 + 0x48) = 0;
  if (*(long **)(param_1 + 0x38) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x38) + 0x28))();
    *(undefined8 *)(param_1 + 0x38) = 0;
  }
  lVar2 = *(long *)(param_1 + 0x20);
  if (lVar2 != 0) {
    if (*(long *)(param_1 + 0x30) != 0) {
      uVar3 = 0;
      do {
        (**(code **)(**(long **)(*(long *)(param_1 + 0x20) + uVar3 * 8) + 0x28))();
        uVar3 = uVar3 + 1;
      } while (uVar3 < *(ulong *)(param_1 + 0x30));
      lVar2 = *(long *)(param_1 + 0x20);
    }
    uVar3 = *(ulong *)(param_1 + 0x28) << 3;
    if (0x7fffffffffffffff < uVar3) {
      uVar3 = 0x8000000000000000;
    }
    if (*(ulong *)(param_1 + 0x28) >> 0x3d != 0) {
      uVar3 = 0x8000000000000000;
    }
    *(undefined8 *)(param_1 + 0x20) = 0;
    thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ca2d48,lVar2,uVar3);
    *(undefined8 *)(param_1 + 0x28) = 0;
    *(undefined8 *)(param_1 + 0x30) = 0;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff008182fdc);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff008182fe4. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff007ca6180 + 0x80))(param_1);
  return;
}

