// FUN_fffffff009c1f834 @ fffffff009c1f834

void FUN_fffffff009c1f834
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
               undefined8 param_8,undefined *param_9,undefined8 param_10,undefined *param_11)

{
  undefined *puVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  code *pcVar5;
  undefined **ppuVar6;
  undefined8 *puVar7;
  undefined *puVar8;
  ulong unaff_x30;
  undefined1 auVar9 [16];
  undefined4 uVar10;
  undefined1 auVar11 [12];
  undefined4 uVar12;
  undefined1 auVar13 [12];
  
  uVar12 = param_4._0_4_;
  auVar13 = param_4._4_12_;
  uVar10 = param_3._0_4_;
  auVar11 = param_3._4_12_;
  if (*(int *)(param_7 + 0x3b0) != 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_fffffff00aa4d114
              (param_1,param_2,param_3,param_4,param_5,param_6,
               (byte *)"\"IOSurface released with non-zero client retain count: %p\" @%s:%d");
  }
  if (*(long *)(param_7 + 0x240) != 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_fffffff00aa4d114
              (param_1,param_2,param_3,param_4,param_5,param_6,
               (byte *)"\"IOFence current queue is not empty for surface: %p\" @%s:%d");
  }
  if (*(long *)(param_7 + 0x250) != 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_fffffff00aa4d114
              (param_1,param_2,param_3,param_4,param_5,param_6,
               (byte *)"\"IOFence wait queue is not empty for surface: %p\" @%s:%d");
  }
  auVar9 = FUN_fffffff009c1fa8c
                     (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                      param_10,param_11);
  if (*(long **)(param_7 + 0x378) != (long *)0x0) {
    auVar9 = (**(code **)(**(long **)(param_7 + 0x378) + 0x28))();
  }
  *(undefined8 *)(param_7 + 0x378) = 0;
  if (*(long *)(param_7 + 0x40) == 0) {
    puVar7 = *(undefined8 **)(param_7 + 0x360);
    if (puVar7 != (undefined8 *)0x0) {
      *(undefined8 *)(param_7 + 0x360) = 0;
      auVar9 = thunk_FUN_fffffff00a22170c((long *)&DAT_fffffff00806af30,puVar7);
      *(undefined8 *)(param_7 + 0x360) = 0;
    }
    auVar9 = FUN_fffffff009c1fb48(auVar9,param_2,uVar10,uVar12,param_5,param_6,param_7);
    ppuVar6 = *(undefined ***)(param_7 + 0x370);
    if (ppuVar6 != (undefined **)0x0) {
      *(undefined8 *)(param_7 + 0x370) = 0;
      auVar9 = thunk_FUN_fffffff00a9026b0
                         (auVar9,param_2,uVar10,uVar12,param_5,param_6,ppuVar6,
                          (undefined *)((ulong)*(uint *)(param_7 + 0x3b4) << 4),param_9,param_10,
                          param_11);
      *(undefined8 *)(param_7 + 0x370) = 0;
    }
    ppuVar6 = *(undefined ***)(param_7 + 0x180);
    if (((ppuVar6 != (undefined **)0x0) && (*(uint *)(param_7 + 0x98) != 0)) &&
       (ppuVar6 != (undefined **)(param_7 + 0xa8))) {
      param_9 = (undefined *)((ulong)*(uint *)(param_7 + 0x98) * 0x38);
      auVar9 = thunk_FUN_fffffff00a902768
                         (auVar9,param_2,uVar10,uVar12,param_5,param_6,0xfffffff00806bca0,ppuVar6,
                          param_9,param_10,param_11);
      *(undefined8 *)(param_7 + 0x180) = 0;
      *(undefined4 *)(param_7 + 0x188) = 0;
    }
    if (*(undefined ***)(param_7 + 0x318) != (undefined **)0x0) {
      auVar2._8_8_ = 0;
      auVar2._0_8_ = *(ulong *)(param_7 + 0x328);
      puVar8 = (undefined *)(*(ulong *)(param_7 + 0x328) * 0x18);
      puVar1 = (undefined *)0x8000000000000000;
      if (SUB168(auVar2 * ZEXT816(0x18),8) == 0 && -1 < (long)puVar8) {
        puVar1 = puVar8;
      }
      auVar9 = thunk_FUN_fffffff00a9026b0
                         (auVar9,param_2,uVar10,uVar12,param_5,param_6,
                          *(undefined ***)(param_7 + 0x318),puVar1,param_9,param_10,param_11);
      *(undefined8 *)(param_7 + 0x318) = 0;
      *(undefined4 *)(param_7 + 800) = 0;
    }
    if (*(undefined ***)(param_7 + 0x350) != (undefined **)0x0) {
      puVar1 = (undefined *)0x8000000000000000;
      if (-1 < (long)*(ulong *)(param_7 + 0x348)) {
        puVar1 = (undefined *)(*(ulong *)(param_7 + 0x348) & 0xffffffffffffffe0);
      }
      auVar9 = thunk_FUN_fffffff00a9026b0
                         (auVar9,param_2,uVar10,uVar12,param_5,param_6,
                          *(undefined ***)(param_7 + 0x350),puVar1,param_9,param_10,param_11);
      *(undefined8 *)(param_7 + 0x350) = 0;
      *(undefined4 *)(param_7 + 0x358) = 0;
    }
    if ((*(undefined ***)(param_7 + 0x308) != (undefined **)0x0) && (*(uint *)(param_7 + 0x98) != 0)
       ) {
      thunk_FUN_fffffff00a9026b0
                (auVar9,param_2,uVar10,uVar12,param_5,param_6,*(undefined ***)(param_7 + 0x308),
                 (undefined *)((ulong)*(uint *)(param_7 + 0x98) * 0x3c),param_9,param_10,param_11);
      *(undefined8 *)(param_7 + 0x308) = 0;
      *(undefined4 *)(param_7 + 0x310) = 0;
      *(undefined4 *)(param_7 + 0x3b8) = 0;
    }
    if (*(int *)(param_7 + 0xa0) != 0) {
      *(undefined4 *)(param_7 + 0xa0) = 0;
    }
    *(undefined8 *)(param_7 + 0x170) = 0;
    if (*(undefined8 **)(param_7 + 0x398) != (undefined8 *)0x0) {
      thunk_FUN_fffffff00a903020(*(undefined8 **)(param_7 + 0x398));
      *(undefined8 *)(param_7 + 0x398) = 0;
    }
    if (*(undefined8 **)(param_7 + 0x50) != (undefined8 *)0x0) {
      thunk_FUN_fffffff00a903020(*(undefined8 **)(param_7 + 0x50));
      *(undefined8 *)(param_7 + 0x50) = 0;
    }
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c1fa00);
      (*pcVar5)();
    }
    (**(code **)(PTR_DAT_fffffff00806ca30 + 0x80))(param_7);
    return;
  }
  auVar3._4_12_ = auVar11;
  auVar3._0_4_ = uVar10;
  auVar4._4_12_ = auVar13;
  auVar4._0_4_ = uVar12;
                    /* WARNING: Subroutine does not return */
  thunk_FUN_fffffff00aa4d114
            (auVar9,param_2,auVar3,auVar4,param_5,param_6,
             (byte *)"\"fDeviceCacheList is not empty for surface: %p\" @%s:%d");
}

