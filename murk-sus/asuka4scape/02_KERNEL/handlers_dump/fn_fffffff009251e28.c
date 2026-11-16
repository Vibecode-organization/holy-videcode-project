// FUN_fffffff009251e28 @ fffffff009251e28 size=128 depth=0
// CALLERS:
//   fffffff00afdceb5 ?
//   fffffff007eedcd0 ?
// CALLS:
//   fffffff009229af0 FUN_fffffff009229af0
//   fffffff00921c208 FUN_fffffff00921c208
//   fffffff009229a70 FUN_fffffff009229a70

undefined8
FUN_fffffff009251e28
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,undefined8 param_7,undefined8 param_8,long param_9)

{
  uint uVar1;
  code *pcVar2;
  undefined8 uVar3;
  long *extraout_x8;
  long unaff_x19;
  long unaff_x20;
  ulong unaff_x30;
  undefined1 auVar4 [16];
  
  auVar4 = FUN_fffffff009229a70();
  uVar1 = *(uint *)(param_9 + 0x38);
  uVar3 = FUN_fffffff009229af0(extraout_x8,auVar4,param_2,param_3,param_4,param_5,param_6);
  if ((int)uVar3 == 0) {
    if (*(uint *)(unaff_x19 + 0x38) % 0x34 == 0) {
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
        uVar3 = FUN_fffffff00921c208(unaff_x20,*(undefined8 *)(unaff_x19 + 0x30),uVar1 / 0x34);
        return uVar3;
      }
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009251e8c);
      (*pcVar2)();
    }
    uVar3 = 0xe00002c2;
  }
  return uVar3;
}

