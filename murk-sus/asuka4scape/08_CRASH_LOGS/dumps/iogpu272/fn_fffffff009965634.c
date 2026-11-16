// FUN_fffffff009965634 @ fffffff009965634 size=332

void FUN_fffffff009965634(long param_1,undefined8 param_2)

{
  uint uVar1;
  code *pcVar2;
  long lVar3;
  long *plVar4;
  uint uVar5;
  ulong unaff_x30;
  
  FUN_fffffff00994463c(*(undefined8 *)(param_1 + 0x10));
  lVar3 = *(long *)(param_1 + 0x10);
  uVar1 = *(uint *)(lVar3 + 0x28);
  if (1 < uVar1) {
    uVar5 = 1;
    do {
      lVar3 = FUN_fffffff009945214(*(undefined8 *)(param_1 + 0x10),uVar5);
      if (lVar3 != 0) {
        FUN_fffffff0099559c0(lVar3,param_2);
      }
      uVar5 = uVar5 + 1;
    } while (uVar1 != uVar5);
    lVar3 = *(long *)(param_1 + 0x10);
  }
  FUN_fffffff009944648(lVar3);
  FUN_fffffff00994463c(*(undefined8 *)(param_1 + 0x78));
  lVar3 = *(long *)(param_1 + 0x78);
  uVar1 = *(uint *)(lVar3 + 0x28);
  if (1 < uVar1) {
    uVar5 = 1;
    do {
      lVar3 = FUN_fffffff009945214(*(undefined8 *)(param_1 + 0x78),uVar5);
      if (lVar3 != 0) {
        FUN_fffffff0099520b0(lVar3,*(undefined4 *)(param_1 + 0x60),param_2);
      }
      uVar5 = uVar5 + 1;
    } while (uVar1 != uVar5);
    lVar3 = *(long *)(param_1 + 0x78);
  }
  FUN_fffffff009944648(lVar3);
  FUN_fffffff00994463c(*(undefined8 *)(param_1 + 0x88));
  lVar3 = *(long *)(param_1 + 0x88);
  uVar1 = *(uint *)(lVar3 + 0x28);
  if (1 < uVar1) {
    uVar5 = 1;
    do {
      plVar4 = (long *)FUN_fffffff009945214(*(undefined8 *)(param_1 + 0x88),uVar5);
      if (plVar4 != (long *)0x0) {
        FUN_fffffff0099768f4();
        (**(code **)(*plVar4 + 0xf8))(plVar4,param_2);
        FUN_fffffff009976900(plVar4);
      }
      uVar5 = uVar5 + 1;
    } while (uVar1 != uVar5);
    lVar3 = *(long *)(param_1 + 0x88);
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00996577c);
    (*pcVar2)();
  }
  FUN_fffffff009944648(lVar3);
  return;
}

