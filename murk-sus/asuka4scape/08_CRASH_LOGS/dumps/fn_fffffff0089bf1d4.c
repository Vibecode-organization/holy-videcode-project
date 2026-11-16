// FUN_fffffff0089bf1d4 @ fffffff0089bf1d4 size=236
// CALLERS:
//   fffffff00afcc85e no-fn
//   fffffff0089c3d84 FUN_fffffff0089c3ca4@fffffff0089c3ca4
// CALLEES:
//   fffffff008a81ed4 thunk_FUN_fffffff00a8df19c
//   fffffff0089d1e2c FUN_fffffff0089d1e2c

void FUN_fffffff0089bf1d4
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
               undefined8 *param_8,undefined1 param_9,char *param_10,undefined *param_11)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  code *pcVar3;
  ulong unaff_x30;
  undefined4 uVar4;
  undefined1 auVar5 [12];
  undefined4 uVar6;
  undefined1 auVar7 [12];
  
  uVar6 = param_4._0_4_;
  auVar7 = param_4._4_12_;
  uVar4 = param_3._0_4_;
  auVar5 = param_3._4_12_;
  if ((DAT_fffffff00ae430b1 >> 2 & 1) != 0) {
    param_10 = "%s: %s: ClientDevice(%p): Memory Map Request [Client: %s, PID: %d]\n";
    param_1 = thunk_FUN_fffffff00a8df19c
                        (param_1,param_2,uVar4,uVar6,param_5,param_6,&MACH_HEADER,
                         (short *)PTR_DAT_fffffff007ddeaa8,0,
                         (byte *)
                         "%s: %s: ClientDevice(%p): Memory Map Request [Client: %s, PID: %d]\n");
  }
  param_8[0x100] = param_7;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
    auVar1._4_12_ = auVar5;
    auVar1._0_4_ = uVar4;
    auVar2._4_12_ = auVar7;
    auVar2._0_4_ = uVar6;
    FUN_fffffff0089d1e2c
              (param_1,param_2,auVar1,auVar2,param_5,param_6,*(long *)(param_7 + 0x20),param_8,
               param_9,param_10,param_11);
    return;
  }
                    /* WARNING: Does not return */
  pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0089bf2bc);
  (*pcVar3)();
}

