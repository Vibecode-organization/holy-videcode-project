// FUN_fffffff009980480 @ fffffff009980480 size=336

void FUN_fffffff009980480(long param_1)

{
  long lVar1;
  uint uVar2;
  code *pcVar3;
  long lVar4;
  long *plVar5;
  long lVar6;
  long lVar7;
  ulong uVar8;
  long lVar9;
  ulong uVar10;
  ulong unaff_x30;
  
  if (*(long **)(param_1 + 0xe0) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0xe0) + 0x28))();
  }
  lVar9 = 0;
  *(undefined8 *)(param_1 + 0xe0) = 0;
  lVar4 = param_1 + 0xb0;
  lVar1 = param_1 + 200;
  do {
    lVar6 = *(long *)(lVar4 + lVar9 * 8);
    if (lVar6 != 0) {
      uVar2 = *(uint *)(lVar1 + lVar9 * 4);
      uVar8 = (ulong)uVar2;
      if (uVar2 == 0) {
        lVar7 = 0;
      }
      else {
        uVar10 = 0;
        do {
          plVar5 = *(long **)(lVar6 + uVar10 * 8);
          if (plVar5 != (long *)0x0) {
            (**(code **)(*plVar5 + 0x28))();
            lVar6 = *(long *)(lVar4 + lVar9 * 8);
            uVar8 = (ulong)*(uint *)(lVar1 + lVar9 * 4);
          }
          *(undefined8 *)(lVar6 + uVar10 * 8) = 0;
          uVar10 = uVar10 + 1;
        } while (uVar10 < uVar8);
        lVar7 = uVar8 << 3;
      }
      *(undefined8 *)(lVar4 + lVar9 * 8) = 0;
      thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ff1d18,lVar6,lVar7);
      *(undefined8 *)(lVar4 + lVar9 * 8) = 0;
      *(undefined4 *)(lVar1 + lVar9 * 4) = 0;
    }
    lVar9 = lVar9 + 1;
  } while (lVar9 != 3);
  if (*(long **)(param_1 + 0x90) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x90) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x90) = 0;
  plVar5 = (long *)(*(long *)(param_1 + 0x10) + 0x110);
  lVar4 = *plVar5;
  *plVar5 = lVar4 - *(long *)(param_1 + 0x38);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0099805c4);
    (*pcVar3)();
  }
  (*DAT_fffffff007fe9080)(lVar4,param_1);
  return;
}

