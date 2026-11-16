// FUN_fffffff009c201c4 @ fffffff009c201c4 size=196
// CALLERS:
//   fffffff00afebced no-fn
//   fffffff009c1b324 FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1bbb8 FUN_fffffff009c1af14@fffffff009c1af14
// CALLEES:
//   fffffff009c2b164 FUN_fffffff009c2b164

undefined8
FUN_fffffff009c201c4
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,byte *param_7,long *param_8)

{
  code *pcVar1;
  undefined8 uVar2;
  ulong unaff_x30;
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 extraout_q0_01 [16];
  undefined1 extraout_q0_02 [16];
  
  uVar2 = FUN_fffffff009c2b164
                    (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
                     "IOSurfacePlaneComponentBitDepths",(long)(param_7 + 4));
  if (((((int)uVar2 != 0) &&
       (uVar2 = FUN_fffffff009c2b164
                          (extraout_q0,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
                           "IOSurfacePlaneComponentBitOffsets",(long)(param_7 + 8)), (int)uVar2 != 0
       )) && (uVar2 = FUN_fffffff009c2b164
                                (extraout_q0_00,param_2,param_3,param_4,param_5,param_6,param_7,
                                 param_8,"IOSurfacePlaneComponentNames",(long)(param_7 + 0xc)),
             (int)uVar2 != 0)) &&
     (uVar2 = FUN_fffffff009c2b164
                        (extraout_q0_01,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
                         "IOSurfacePlaneComponentTypes",(long)(param_7 + 0x10)), (int)uVar2 != 0)) {
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c20274);
      (*pcVar1)();
    }
    uVar2 = FUN_fffffff009c2b164
                      (extraout_q0_02,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
                       "IOSurfacePlaneComponentRanges",(long)(param_7 + 0x14));
    return uVar2;
  }
  return 0;
}

