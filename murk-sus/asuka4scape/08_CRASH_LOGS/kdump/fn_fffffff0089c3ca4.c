// FUN_fffffff0089c3ca4 @ fffffff0089c3ca4 size=400
// CALLERS:
// CALLS:
//   fffffff008a81ed4 thunk_FUN_fffffff00a8df19c
//   fffffff0089bb408 FUN_fffffff0089bb408
//   fffffff0089bf1d4 FUN_fffffff0089bf1d4

undefined8
FUN_fffffff0089c3ca4
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
          undefined8 param_8,long param_9,char *param_10,undefined *param_11)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  undefined8 extraout_x0;
  undefined8 uVar3;
  long lVar4;
  undefined8 *puVar5;
  long lVar6;
  undefined1 extraout_q0 [16];
  undefined4 uVar7;
  undefined1 auVar8 [12];
  undefined4 uVar9;
  undefined1 auVar10 [12];
  
  uVar9 = param_4._0_4_;
  auVar10 = param_4._4_12_;
  uVar7 = param_3._0_4_;
  auVar8 = param_3._4_12_;
  lVar4 = *(long *)(param_7 + 0x10);
  if ((DAT_fffffff00ae430b1 >> 2 & 1) != 0) {
    FUN_fffffff0089bb408(lVar4);
    FUN_fffffff0089bb408(lVar4);
    param_10 = "%s: %s: Device(%p): Memory Map Request [Client: %s, PID: %d]\n";
    param_1 = thunk_FUN_fffffff00a8df19c
                        (extraout_q0,param_2,uVar7,uVar9,param_5,param_6,&MACH_HEADER,
                         (short *)PTR_DAT_fffffff007ddeaa8,0,
                         (byte *)"%s: %s: Device(%p): Memory Map Request [Client: %s, PID: %d]\n");
  }
  puVar5 = *(undefined8 **)(param_9 + 0x30);
  if (puVar5 == (undefined8 *)0x0) {
    thunk_FUN_fffffff00a8df19c
              (param_1,param_2,uVar7,uVar9,param_5,param_6,&MACH_HEADER,
               (short *)PTR_DAT_fffffff007ddeaa8,0x10,
               (byte *)"[ERROR] %s: %s: ERROR: memoryMapParams pointer is NULL\n");
    uVar3 = 0xe00002c2;
  }
  else {
    lVar6 = **(long **)(param_9 + 0x20);
    auVar1._4_12_ = auVar8;
    auVar1._0_4_ = uVar7;
    auVar2._4_12_ = auVar10;
    auVar2._0_4_ = uVar9;
    FUN_fffffff0089bf1d4
              (param_1,param_2,auVar1,auVar2,param_5,param_6,lVar4,puVar5,lVar6 != 0,param_10,
               param_11);
    uVar3 = extraout_x0;
    if (lVar6 != 0 && (int)extraout_x0 == 0) {
      uVar3 = 0;
      **(undefined8 **)(param_9 + 0x48) = puVar5[0x103];
    }
  }
  return uVar3;
}

