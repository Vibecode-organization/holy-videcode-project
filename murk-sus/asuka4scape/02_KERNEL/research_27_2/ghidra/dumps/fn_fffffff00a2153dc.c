// FUN_fffffff00a2153dc @ fffffff00a2153dc size=372
// CALLERS:
//   fffffff00afb8563 no-fn
//   fffffff00a259c2c FUN_fffffff00a259900@fffffff00a259900
//   fffffff00a2160f4 FUN_fffffff00a216078@fffffff00a216078
//   fffffff00a216118 FUN_fffffff00a216078@fffffff00a216078
//   fffffff00a2156c0 FUN_fffffff00a215550@fffffff00a215550
// CALLEES:
//   fffffff00aa4d114 FUN_fffffff00aa4d114
//   fffffff00a232c9c FUN_fffffff00a232c9c
//   fffffff00a1f4ae8 FUN_fffffff00a1f4ae8
//   fffffff00a8df19c FUN_fffffff00a8df19c
//   fffffff00a226e08 FUN_fffffff00a226e08
//   fffffff00a2262d4 FUN_fffffff00a2262d4

undefined8
FUN_fffffff00a2153dc
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,ulong param_7,uint param_8,
          long param_9)

{
  long *plVar1;
  uint uVar2;
  long lVar3;
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined8 uVar6;
  undefined8 extraout_x1;
  ulong uVar7;
  byte *pbVar8;
  uint in_wzr;
  undefined1 auVar9 [16];
  undefined4 uVar10;
  undefined1 auVar11 [12];
  undefined4 uVar12;
  undefined1 auVar13 [12];
  
  uVar12 = param_4._0_4_;
  auVar13 = param_4._4_12_;
  uVar10 = param_3._0_4_;
  auVar11 = param_3._4_12_;
  if ((param_8 < 0x25) && (param_8 - 8 < 0xfffffffc)) {
    if (param_8 == 0x1a) {
      uVar6 = 0x2e;
    }
    else {
      lVar3 = tpidr_el1;
      if (*(ulong *)(param_7 + 8) == 0) {
        *(ulong *)(param_7 + 8) = (ulong)*(uint *)(lVar3 + 0x4e8);
      }
      else {
        param_1 = FUN_fffffff00a2262d4(param_7,lVar3,(undefined **)0x0);
      }
      plVar1 = (long *)(param_7 + 0x10 + (ulong)param_8 * 8);
      pbVar8 = (byte *)*plVar1;
      if (pbVar8 == (byte *)0x0) {
        pbVar8 = (byte *)0x0;
      }
      if (param_9 == 0) {
        param_9 = 0;
      }
      *plVar1 = param_9;
      uVar2 = *(uint *)(param_7 + 8);
      if (uVar2 == *(uint *)(lVar3 + 0x4e8)) {
        *(uint *)(param_7 + 8) = in_wzr;
      }
      else {
        param_1 = FUN_fffffff00a226e08(param_7,lVar3,uVar2);
      }
      if ((byte *)0x1 < pbVar8 + 1) {
        param_1 = FUN_fffffff00a1f4ae8(pbVar8);
      }
      if (param_8 == 0x21) {
        uVar7 = 1;
        auVar9 = FUN_fffffff00a8df19c
                           (param_1,param_2,uVar10,uVar12,param_5,param_6,&MACH_HEADER,
                            (short *)&DAT_fffffff00ad98ba0,1,
                            (byte *)"Memory error logging started\n");
        auVar4._4_12_ = auVar11;
        auVar4._0_4_ = uVar10;
        auVar5._4_12_ = auVar13;
        auVar5._0_4_ = uVar12;
        FUN_fffffff00a232c9c
                  (auVar9,param_2,auVar4,auVar5,param_5,param_6,(ushort *)&DAT_fffffff00adc4f30,
                   extraout_x1,uVar7);
      }
      uVar6 = 0;
    }
    return uVar6;
  }
                    /* WARNING: Subroutine does not return */
  FUN_fffffff00aa4d114
            (param_1,param_2,param_3,param_4,param_5,param_6,
             (byte *)"attempted to set invalid special port %d @%s:%d");
}

