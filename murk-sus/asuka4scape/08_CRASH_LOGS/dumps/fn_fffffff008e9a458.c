// FUN_fffffff008e9a458 @ fffffff008e9a458 size=556
// CALLERS:
// CALLEES:
//   fffffff008eb9410 thunk_FUN_fffffff009c294a8
//   fffffff008eb88a0 thunk_FUN_fffffff00a9029a0
//   fffffff008eb93d0 thunk_FUN_fffffff009c28c68
//   fffffff008e9a684 FUN_fffffff008e9a684
//   fffffff008eb93b0 thunk_FUN_fffffff009c28ba8
//   fffffff008eb93e0 thunk_FUN_fffffff009c22b48
//   fffffff008eb9480 thunk_FUN_fffffff00aa4c590
//   fffffff008eb9370 thunk_FUN_fffffff009c22350
//   fffffff008e98eac FUN_fffffff008e98eac
//   fffffff008e9b680 FUN_fffffff008e9b680
//   fffffff008eb9350 thunk_FUN_fffffff009c223bc

undefined8 *
FUN_fffffff008e9a458
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
          undefined8 *param_8)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  byte bVar11;
  char cVar12;
  char cVar13;
  char cVar14;
  uint uVar15;
  undefined4 uVar16;
  uint *puVar17;
  ulong uVar18;
  undefined8 uVar19;
  long lVar20;
  undefined8 extraout_d0;
  undefined8 extraout_d0_00;
  undefined8 extraout_d0_01;
  undefined8 extraout_d0_02;
  undefined8 uVar21;
  undefined8 extraout_d0_03;
  undefined8 extraout_d0_04;
  undefined8 extraout_d0_05;
  undefined8 extraout_d0_06;
  undefined8 extraout_d0_07;
  undefined8 extraout_d0_08;
  undefined8 extraout_var;
  undefined8 extraout_var_00;
  undefined8 extraout_var_01;
  undefined8 extraout_var_02;
  undefined8 uVar22;
  undefined8 extraout_var_03;
  undefined8 extraout_var_04;
  undefined8 extraout_var_05;
  undefined8 extraout_var_06;
  undefined8 extraout_var_07;
  undefined8 extraout_var_08;
  undefined1 auStack_a8 [12];
  undefined1 auStack_9c [12];
  undefined1 auStack_90 [12];
  undefined1 auStack_84 [12];
  undefined1 *local_78;
  undefined4 local_70;
  long local_68;
  
  local_68 = *(long *)PTR_DAT_fffffff007e748e0;
  if (param_7 != 0) {
    uVar15 = thunk_FUN_fffffff009c22350(param_7);
    puVar17 = FUN_fffffff008e98eac(uVar15);
    if (puVar17 != (uint *)0x0) {
      local_78 = &DAT_aaaaaaaaaaaaaaaa;
      local_70 = 0xaaaaaaaa;
      uVar18 = FUN_fffffff008e9a684
                         (ZEXT816(0xaaaaaaaaaaaaaaaa),param_2,param_3,param_4,param_5,param_6,
                          param_7,(long)auStack_84,(long)auStack_90,(long)auStack_9c,
                          (long)auStack_a8,(long)&local_78);
      if ((uVar18 & 1) != 0) {
        uVar16 = thunk_FUN_fffffff009c223bc(param_7);
        auVar1._8_8_ = extraout_var;
        auVar1._0_8_ = extraout_d0;
        bVar11 = thunk_FUN_fffffff009c22b48
                           (auVar1,param_2,param_3,param_4,param_5,param_6,param_7,0);
        auVar2._8_8_ = extraout_var_00;
        auVar2._0_8_ = extraout_d0_00;
        cVar12 = thunk_FUN_fffffff009c294a8
                           (auVar2,param_2,param_3,param_4,param_5,param_6,param_7,0);
        auVar3._8_8_ = extraout_var_01;
        auVar3._0_8_ = extraout_d0_01;
        cVar13 = thunk_FUN_fffffff009c294a8
                           (auVar3,param_2,param_3,param_4,param_5,param_6,param_7,1);
        auVar4._8_8_ = extraout_var_02;
        auVar4._0_8_ = extraout_d0_02;
        cVar14 = thunk_FUN_fffffff009c294a8
                           (auVar4,param_2,param_3,param_4,param_5,param_6,param_7,2);
        lVar20 = 0;
        *param_8 = puVar17;
        *(undefined4 *)(param_8 + 2) = 0;
        *(undefined4 *)((long)param_8 + 0x14) = uVar16;
        param_8[1] = 0;
        *(bool *)(param_8 + 3) = (bVar11 & 0xfe) == 2;
        *(bool *)((long)param_8 + 0x19) = cVar12 != '\0';
        *(bool *)((long)param_8 + 0x1a) = cVar13 != '\0';
        *(bool *)((long)param_8 + 0x1b) = cVar14 != '\0';
        uVar21 = 0;
        uVar22 = 0;
        *(undefined8 *)((long)param_8 + 0x24) = 0;
        *(undefined8 *)((long)param_8 + 0x1c) = 0;
        *(undefined8 *)((long)param_8 + 0x34) = 0;
        *(undefined8 *)((long)param_8 + 0x2c) = 0;
        *(undefined4 *)((long)param_8 + 0x3c) = 0;
        do {
          uVar15 = (uint)lVar20;
          auVar5._8_8_ = uVar22;
          auVar5._0_8_ = uVar21;
          cVar12 = thunk_FUN_fffffff009c294a8
                             (auVar5,param_2,param_3,param_4,param_5,param_6,param_7,uVar15);
          if (cVar12 == '\x01') {
            uVar16 = 0;
            uVar21 = extraout_d0_03;
            uVar22 = extraout_var_03;
          }
          else {
            auVar6._8_8_ = extraout_var_03;
            auVar6._0_8_ = extraout_d0_03;
            bVar11 = thunk_FUN_fffffff009c22b48
                               (auVar6,param_2,param_3,param_4,param_5,param_6,param_7,uVar15);
            if ((bVar11 & 0xfe) == 2) {
              uVar16 = 1;
              uVar21 = extraout_d0_04;
              uVar22 = extraout_var_04;
            }
            else {
              auVar7._8_8_ = extraout_var_04;
              auVar7._0_8_ = extraout_d0_04;
              uVar19 = FUN_fffffff008e9b680
                                 (auVar7,param_2,param_3,param_4,param_5,param_6,param_7,uVar15);
              uVar16 = 2;
              uVar21 = extraout_d0_05;
              uVar22 = extraout_var_05;
              if ((int)uVar19 == 0) {
                uVar16 = 3;
              }
            }
          }
          *(undefined4 *)((long)(param_8 + 1) + lVar20 * 4) = uVar16;
          auVar8._8_8_ = uVar22;
          auVar8._0_8_ = uVar21;
          cVar12 = thunk_FUN_fffffff009c294a8
                             (auVar8,param_2,param_3,param_4,param_5,param_6,param_7,uVar15);
          *(bool *)((long)param_8 + 0x19 + lVar20) = cVar12 != '\0';
          *(undefined4 *)((long)param_8 + 0x1c + lVar20 * 4) =
               *(undefined4 *)((long)&local_78 + lVar20 * 4);
          auVar9._8_8_ = extraout_var_06;
          auVar9._0_8_ = extraout_d0_06;
          uVar16 = thunk_FUN_fffffff009c28ba8
                             (auVar9,param_2,param_3,param_4,param_5,param_6,param_7,uVar15);
          *(undefined4 *)((long)param_8 + lVar20 * 4 + 0x28) = uVar16;
          auVar10._8_8_ = extraout_var_07;
          auVar10._0_8_ = extraout_d0_07;
          uVar16 = thunk_FUN_fffffff009c28c68
                             (auVar10,param_2,param_3,param_4,param_5,param_6,param_7,uVar15);
          *(undefined4 *)((long)param_8 + lVar20 * 4 + 0x34) = uVar16;
          lVar20 = lVar20 + 1;
          uVar21 = extraout_d0_08;
          uVar22 = extraout_var_08;
        } while (lVar20 != 3);
        goto LAB_fffffff008e9a644;
      }
      thunk_FUN_fffffff00a9029a0((byte *)"%s: failed to compute stride of surface\n");
    }
  }
  param_8 = (undefined8 *)0x0;
LAB_fffffff008e9a644:
  if (*(long *)PTR_DAT_fffffff007e748e0 != local_68) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_fffffff00aa4c590();
  }
  return param_8;
}

