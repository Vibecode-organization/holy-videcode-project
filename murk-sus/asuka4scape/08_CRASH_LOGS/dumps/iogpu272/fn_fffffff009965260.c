// FUN_fffffff009965260 @ fffffff009965260 size=216

void FUN_fffffff009965260(long param_1)

{
  uint uVar1;
  code *pcVar2;
  long lVar3;
  uint uVar4;
  ulong unaff_x30;
  
  if (*(long *)(param_1 + 0x110) != 0) {
    FUN_fffffff00994463c();
    lVar3 = *(long *)(param_1 + 0x110);
    uVar1 = *(uint *)(lVar3 + 0x28);
    if (1 < uVar1) {
      uVar4 = 1;
      do {
        lVar3 = FUN_fffffff009945214(*(undefined8 *)(param_1 + 0x110),uVar4);
        if (lVar3 != 0) {
          FUN_fffffff00995b2d8();
        }
        uVar4 = uVar4 + 1;
      } while (uVar1 != uVar4);
      lVar3 = *(long *)(param_1 + 0x110);
    }
    FUN_fffffff009944648(lVar3);
  }
  if (*(long *)(param_1 + 0x88) == 0) {
    return;
  }
  FUN_fffffff00994463c();
  lVar3 = *(long *)(param_1 + 0x88);
  uVar1 = *(uint *)(lVar3 + 0x28);
  if (1 < uVar1) {
    uVar4 = 1;
    do {
      lVar3 = FUN_fffffff009945214(*(undefined8 *)(param_1 + 0x88),uVar4);
      if (lVar3 != 0) {
        FUN_fffffff009976810();
      }
      uVar4 = uVar4 + 1;
    } while (uVar1 != uVar4);
    lVar3 = *(long *)(param_1 + 0x88);
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009965324);
    (*pcVar2)();
  }
  FUN_fffffff009944648(lVar3);
  return;
}

