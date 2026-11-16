// FUN_fffffff009954f84 @ fffffff009954f84 size=296

void FUN_fffffff009954f84(long param_1,long param_2,ulong param_3)

{
  uint uVar1;
  undefined4 uVar2;
  code *pcVar3;
  undefined8 uVar4;
  uint uVar5;
  ulong unaff_x30;
  
  uVar1 = *(uint *)(param_1 + 0x10);
  if ((uVar1 & 0xf) == 0) {
    uVar2 = *(undefined4 *)(param_2 + 0x18);
    uVar4 = *(undefined8 *)(*(long *)(param_1 + 0x50) + 0x148);
    uVar5 = (uint)param_3;
    if (((uVar5 >> 1 & 1) == 0) && ((uVar1 >> 0x11 & 1) != 0)) {
      FUN_fffffff00994c2f0(uVar4,uVar2,*(undefined8 *)(param_1 + 0x58),uVar5 & 1);
    }
    else {
      if ((param_3 & 1) != 0) {
        *(uint *)(param_1 + 0x10) = uVar1 | 0x8000;
      }
      FUN_fffffff00994c2f0(uVar4,uVar2,*(undefined8 *)(param_1 + 0x18),uVar5 & 1);
      if ((uVar1 >> 0xe & 1) != 0) {
        if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
          FUN_fffffff009954f28(param_1,param_2,param_3);
          return;
        }
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0099550a8);
        (*pcVar3)();
      }
    }
  }
  else {
    if ((uVar1 & 0xff) == 3) {
      return;
    }
    if ((uVar1 & 0xff) == 0x82) {
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(*(long *)(param_1 + 0x30) + 0x60));
      FUN_fffffff009954f84(*(undefined8 *)(param_1 + 0x30),param_2,param_3);
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(*(long *)(param_1 + 0x30) + 0x60));
    }
  }
  if (DAT_fffffff00af227ec == 0) {
    return;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
    FUN_fffffff009954de0(param_1,param_2,param_3);
    return;
  }
                    /* WARNING: Does not return */
  pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00995506c);
  (*pcVar3)();
}

