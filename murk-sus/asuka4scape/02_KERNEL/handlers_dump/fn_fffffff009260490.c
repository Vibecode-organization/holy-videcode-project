// FUN_fffffff009260490 @ fffffff009260490 size=228 depth=0
// CALLERS:
//   fffffff00afdcff3 ?
//   fffffff007ef9dc0 ?
// CALLS:
//   fffffff009245a34 FUN_fffffff009245a34
//   fffffff009245a14 FUN_fffffff009245a14
//   fffffff00923f9c0 FUN_fffffff00923f9c0
//   fffffff009229a70 FUN_fffffff009229a70

undefined8
FUN_fffffff009260490
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,undefined8 param_7,undefined8 param_8,
          undefined8 param_9,long param_10,long *param_11)

{
  uint uVar1;
  code *pcVar2;
  undefined8 uVar3;
  long lVar4;
  long extraout_x8;
  long unaff_x19;
  ulong unaff_x30;
  undefined1 extraout_q0 [16];
  
  uVar3 = FUN_fffffff009229a70();
  uVar3 = FUN_fffffff009245a34
                    (extraout_x8,extraout_q0,param_2,param_3,param_4,param_5,param_6,uVar3,"raw-spi"
                     ,param_9,param_10,param_11);
  if ((int)uVar3 != 0) {
    return uVar3;
  }
  uVar1 = **(uint **)(unaff_x19 + 0x20);
  if (uVar1 < 5) {
    switch(uVar1) {
    default:
      lVar4 = FUN_fffffff009245a14();
      uVar3 = FUN_fffffff00923f9c0(lVar4,0xe1,param_9,param_10,0);
      if ((int)uVar3 != 0) {
        return uVar3;
      }
      if (3 < uVar1 || uVar1 == 1) {
        return 0;
      }
      break;
    case 2:
      break;
    case 4:
      goto code_r0xfffffff009260548;
    }
    lVar4 = FUN_fffffff009245a14();
    uVar3 = FUN_fffffff00923f9c0(lVar4,0xe2,param_9,param_10,0);
    if ((int)uVar3 != 0) {
      return uVar3;
    }
    if (uVar1 == 0) {
code_r0xfffffff009260548:
      lVar4 = FUN_fffffff009245a14();
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009260570);
        (*pcVar2)();
      }
      uVar3 = FUN_fffffff00923f9c0(lVar4,0xe4,param_9,param_10,0);
      return uVar3;
    }
  }
  return 0;
}

