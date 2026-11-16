// FUN_fffffff009245a34 @ fffffff009245a34 size=24 depth=1
// CALLERS:
//   fffffff00afdcd68 ?
//   fffffff009260438 FUN_fffffff009260414
//   fffffff0092604b4 FUN_fffffff009260490
//   fffffff009260594 FUN_fffffff009260574
//   fffffff0092605f0 FUN_fffffff0092605d0
//   fffffff009260648 FUN_fffffff00926062c
//   fffffff0092606e4 FUN_fffffff0092606c8
// CALLS:
//   fffffff009260860 FUN_fffffff009260860

void FUN_fffffff009245a34
               (long param_1,undefined1 param_2 [16],undefined1 param_3 [16],undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined8 param_8,
               char *param_9,undefined8 param_10,long param_11,long *param_12)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009245a48);
    (*pcVar1)();
  }
  FUN_fffffff009260860
            (param_2,param_3,param_4,param_5,param_6,param_7,param_1,param_9,0,param_11,param_12);
  return;
}

