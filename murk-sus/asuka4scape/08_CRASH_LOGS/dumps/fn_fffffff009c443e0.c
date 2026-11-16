// FUN_fffffff009c443e0 @ fffffff009c443e0 size=1656
// CALLERS:
//   fffffff00afec1d8 no-fn
//   fffffff009c440ec FUN_fffffff009c4405c@fffffff009c4405c
//   fffffff009c3749c FUN_fffffff009c373ec@fffffff009c373ec
// CALLEES:
//   fffffff009c4346c FUN_fffffff009c4346c
//   fffffff009c43340 FUN_fffffff009c43340
//   fffffff009c493c8 FUN_fffffff009c493c8
//   fffffff009c499d4 thunk_FUN_fffffff00a97db9c
//   fffffff009c495f4 thunk_FUN_fffffff00a9029a0
//   fffffff009c499a4 thunk_FUN_fffffff00a89ca6c
//   fffffff009c42434 FUN_fffffff009c42434
//   fffffff009c49624 thunk_FUN_fffffff00a902750
//   fffffff009c491c8 FUN_fffffff009c491c8
//   fffffff009c493ac FUN_fffffff009c493ac
//   fffffff009c462d8 FUN_fffffff009c462d8
//   fffffff009c498d4 thunk_FUN_fffffff00a894f30
//   fffffff009c49584 thunk_FUN_fffffff00a902768
//   fffffff009c43f40 FUN_fffffff009c43f40
//   fffffff009c49924 thunk_FUN_fffffff00a97ba94
//   fffffff009c49b64 thunk_FUN_fffffff00aa4c590
//   fffffff009c493e4 FUN_fffffff009c493e4
//   fffffff009c49a54 thunk_FUN_fffffff00a89a1f4

long * FUN_fffffff009c443e0
                 (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
                 undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
                 ulong param_8,ulong param_9,undefined8 param_10,long *param_11,int param_12)

{
  int iVar1;
  ulong *puVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  undefined1 auVar13 [16];
  undefined1 auVar14 [16];
  undefined1 auVar15 [16];
  undefined1 auVar16 [16];
  undefined1 auVar17 [16];
  undefined1 auVar18 [16];
  undefined1 auVar19 [16];
  undefined1 auVar20 [16];
  undefined *puVar21;
  uint uVar22;
  uint uVar23;
  long *plVar24;
  ulong uVar25;
  undefined **ppuVar26;
  long *plVar27;
  long *plVar28;
  long *plVar29;
  undefined8 uVar30;
  long *plVar31;
  undefined **ppuVar32;
  ulong uVar33;
  ulong uVar34;
  long *plVar35;
  long *plVar36;
  long lVar37;
  ulong uVar38;
  undefined1 auVar39 [16];
  undefined1 auVar40 [16];
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 extraout_q0_01 [16];
  undefined1 extraout_q0_02 [16];
  undefined1 extraout_q0_03 [16];
  undefined1 extraout_q0_04 [16];
  undefined1 extraout_q0_05 [16];
  undefined1 extraout_q0_06 [16];
  undefined1 extraout_q0_07 [16];
  undefined4 uVar41;
  undefined1 auVar42 [12];
  undefined4 uVar43;
  undefined1 auVar44 [12];
  long *local_70;
  long local_68;
  
  uVar43 = param_4._0_4_;
  auVar44 = param_4._4_12_;
  uVar41 = param_3._0_4_;
  auVar42 = param_3._4_12_;
  local_68 = *(long *)PTR_DAT_fffffff00806ca40;
  plVar31 = param_11;
  plVar24 = thunk_FUN_fffffff00a89a1f4(1);
  puVar21 = PTR_DAT_fffffff00806c9b0;
  if (plVar24 == (long *)0x0) {
    plVar31 = (long *)0x0;
  }
  else {
    if (param_8 == 0) {
LAB_fffffff009c44558:
      uVar25 = (**(code **)(*plVar24 + 0x90))(plVar24);
      puVar2 = (ulong *)((uVar25 & 0xffffffff) << 3);
      auVar3._4_12_ = auVar42;
      auVar3._0_4_ = uVar41;
      auVar13._4_12_ = auVar44;
      auVar13._0_4_ = uVar43;
      auVar40 = thunk_FUN_fffffff00a902750
                          (extraout_q0,param_2,auVar3,auVar13,param_5,param_6,0xfffffff00806c470,
                           puVar2);
      ppuVar26 = auVar40._0_8_;
      if (ppuVar26 == (undefined **)0x0) goto LAB_fffffff009c44708;
      plVar27 = thunk_FUN_fffffff00a89ca6c(plVar24);
      auVar40 = extraout_q0_00;
      if (plVar27 != (long *)0x0) {
        uVar38 = 0;
        ppuVar32 = ppuVar26 + (uVar25 & 0xffffffff);
        if ((((ulong)ppuVar26 ^ (ulong)ppuVar32) & 0xffc0000000000000) != 0) {
          ppuVar32 = (undefined **)((ulong)ppuVar32 & 0xffffffffffff | 0xc8a2000000000000);
        }
        lVar37 = 0x10000000;
        plVar35 = (long *)0x0;
        while( true ) {
          plVar28 = (long *)(**(code **)(*plVar27 + 0x88))(plVar27);
          plVar28 = thunk_FUN_fffffff00a894f30(plVar28,-0xff50b7ba8);
          auVar40 = extraout_q0_01;
          if (plVar28 != (long *)0x0) {
            auVar40 = (**(code **)(*plVar28 + 0x20))(plVar28);
          }
          if (plVar35 != (long *)0x0) {
            auVar40 = (**(code **)(*plVar35 + 0x28))(plVar35);
          }
          if (plVar28 == (long *)0x0) {
            auVar40 = (**(code **)(*plVar27 + 0x28))(plVar27);
            goto LAB_fffffff009c447a4;
          }
          plVar35 = (long *)plVar28[3];
          if (plVar35 != (long *)0x0) {
            auVar40 = (**(code **)(*plVar35 + 0x20))(plVar35);
          }
          if (((long)ppuVar32 - (long)ppuVar26 & 0xffffffff00000000U) != 0 || ppuVar32 < ppuVar26)
          break;
          if (lVar37 == 0) goto LAB_fffffff009c44a48;
          if (((long)uVar38 < 0) ||
             ((uint)((long)ppuVar32 - (long)ppuVar26) < (int)(uVar38 >> 0x20) + 8U))
          goto LAB_fffffff009c44a4c;
          uVar34 = (ulong)CARRY8((ulong)ppuVar26,uVar38 >> 0x20);
          uVar33 = -uVar34;
          if ((uVar33 != uVar34) || ((long)uVar33 < 0)) goto LAB_fffffff009c44a50;
          *(long **)((long)ppuVar26 + (uVar38 >> 0x20)) = plVar35;
          if (plVar35 != (long *)0x0) {
            (**(code **)(*plVar35 + 0x28))(plVar35);
          }
          lVar37 = lVar37 + -1;
          uVar38 = uVar38 + 0x800000000;
          plVar35 = plVar28;
        }
        auVar7._4_12_ = auVar42;
        auVar7._0_4_ = uVar41;
        auVar17._4_12_ = auVar44;
        auVar17._0_4_ = uVar43;
        FUN_fffffff009c493e4(auVar40,param_2,auVar7,auVar17,param_5,param_6);
        auVar40 = extraout_q0_05;
LAB_fffffff009c44a48:
        auVar8._4_12_ = auVar42;
        auVar8._0_4_ = uVar41;
        auVar18._4_12_ = auVar44;
        auVar18._0_4_ = uVar43;
        FUN_fffffff009c491c8(auVar40,param_2,auVar8,auVar18,param_5,param_6);
        auVar40 = extraout_q0_06;
LAB_fffffff009c44a4c:
        auVar9._4_12_ = auVar42;
        auVar9._0_4_ = uVar41;
        auVar19._4_12_ = auVar44;
        auVar19._0_4_ = uVar43;
        FUN_fffffff009c493ac(auVar40,param_2,auVar9,auVar19,param_5,param_6);
        auVar40 = extraout_q0_07;
LAB_fffffff009c44a50:
        auVar10._4_12_ = auVar42;
        auVar10._0_4_ = uVar41;
        auVar20._4_12_ = auVar44;
        auVar20._0_4_ = uVar43;
        FUN_fffffff009c493c8(auVar40,param_2,auVar10,auVar20,param_5,param_6);
        goto LAB_fffffff009c44a54;
      }
LAB_fffffff009c447a4:
      uVar23 = (uint)param_9;
      uVar30 = 0;
      auVar4._4_12_ = auVar42;
      auVar4._0_4_ = uVar41;
      auVar14._4_12_ = auVar44;
      auVar14._0_4_ = uVar43;
      plVar27 = thunk_FUN_fffffff00a97db9c
                          (auVar40,param_2,auVar4,auVar14,param_5,param_6,ppuVar26,
                           uVar25 & 0xffffffff,(ulong)(uVar23 & 7),0);
      thunk_FUN_fffffff00a902768
                (extraout_q0_02,param_2,uVar41,uVar43,param_5,param_6,0xfffffff00806c4c0,ppuVar26,
                 (undefined *)puVar2,uVar30,(undefined *)plVar31);
      local_70 = thunk_FUN_fffffff00a894f30(plVar27,*(long *)PTR_PTR_fffffff00806c9e0);
      auVar5._4_12_ = auVar42;
      auVar5._0_4_ = uVar41;
      auVar15._4_12_ = auVar44;
      auVar15._0_4_ = uVar43;
      plVar31 = thunk_FUN_fffffff00a97db9c
                          (extraout_q0_03,param_2,auVar5,auVar15,param_5,param_6,&local_70,1,
                           (ulong)(uVar23 & 7),0);
      plVar35 = (long *)(**(code **)(DAT_fffffff00af48430 + 0x68))();
      (**(code **)(*plVar24 + 0x20))(plVar24);
      uVar30 = *(undefined8 *)(param_7 + 0x28);
      if (param_11 != (long *)0x0) {
        (**(code **)(*param_11 + 0x20))(param_11);
      }
      FUN_fffffff009c42434((long)plVar35,plVar31,plVar24,uVar30,param_11);
      plVar28 = thunk_FUN_fffffff00a894f30(plVar35,*(long *)PTR_PTR_fffffff00806ca08);
      thunk_FUN_fffffff00a97ba94((long)plVar27,(long)plVar28);
      if (plVar35 != (long *)0x0) {
        (**(code **)(*plVar35 + 0x20))(plVar35);
      }
      FUN_fffffff009c43f40((long)param_11,plVar35);
      plVar28 = thunk_FUN_fffffff00a89ca6c(plVar24);
      if (plVar28 != (long *)0x0) {
        plVar36 = (long *)0x0;
        while( true ) {
          plVar29 = (long *)(**(code **)(*plVar28 + 0x88))(plVar28);
          plVar29 = thunk_FUN_fffffff00a894f30(plVar29,-0xff50b7ba8);
          auVar40 = extraout_q0_04;
          if (plVar29 != (long *)0x0) {
            auVar40 = (**(code **)(*plVar29 + 0x20))(plVar29);
          }
          if (plVar36 != (long *)0x0) {
            auVar40 = (**(code **)(*plVar36 + 0x28))(plVar36);
          }
          if (plVar29 == (long *)0x0) break;
          if (param_12 != 0) {
            auVar40 = FUN_fffffff009c4346c((long)plVar29);
          }
          auVar6._4_12_ = auVar42;
          auVar6._0_4_ = uVar41;
          auVar16._4_12_ = auVar44;
          auVar16._0_4_ = uVar43;
          FUN_fffffff009c43340(auVar40,param_2,auVar6,auVar16,param_5,param_6,(long)plVar29,uVar23);
          plVar36 = plVar29;
        }
        (**(code **)(*plVar28 + 0x28))(plVar28);
      }
      if (plVar31 != (long *)0x0) {
        (**(code **)(*plVar31 + 0x20))(plVar31);
      }
      if (plVar35 != (long *)0x0) {
        (**(code **)(*plVar35 + 0x28))(plVar35);
      }
      if (plVar31 != (long *)0x0) {
        (**(code **)(*plVar31 + 0x28))(plVar31);
      }
      if (plVar27 != (long *)0x0) {
        (**(code **)(*plVar27 + 0x28))(plVar27);
      }
    }
    else {
      uVar23 = 9;
      do {
        iVar1 = (1 << (ulong)(*(uint *)puVar21 & 0x1f)) << (ulong)(uVar23 & 0x1f);
        if ((ulong)(long)iVar1 <= param_8) {
          do {
            auVar39 = (**(code **)(*plVar24 + 0x20))(plVar24);
            plVar31 = (long *)0x1;
            auVar40._4_12_ = auVar42;
            auVar40._0_4_ = uVar41;
            auVar11._4_12_ = auVar44;
            auVar11._0_4_ = uVar43;
            uVar22 = FUN_fffffff009c462d8
                               (auVar39,param_2,auVar40,auVar11,param_5,param_6,param_7,uVar23,
                                param_9,plVar24,1);
            if (uVar22 == 0) goto LAB_fffffff009c44708;
            param_8 = param_8 - (long)iVar1;
          } while ((ulong)(long)iVar1 <= param_8);
        }
      } while ((uVar23 != 0) && (uVar23 = uVar23 - 1, param_8 != 0));
      if (param_8 <= (ulong)(long)(1 << (ulong)(*(uint *)puVar21 & 0x1f))) {
        if (param_8 != 0) {
          thunk_FUN_fffffff00a9029a0
                    ((byte *)"====> %s:%d Descriptor length isn\'t rounded to bucket size\n");
          auVar40 = (**(code **)(*plVar24 + 0x20))(plVar24);
          plVar31 = (long *)0x1;
          auVar39._4_12_ = auVar42;
          auVar39._0_4_ = uVar41;
          auVar12._4_12_ = auVar44;
          auVar12._0_4_ = uVar43;
          uVar23 = FUN_fffffff009c462d8
                             (auVar40,param_2,auVar39,auVar12,param_5,param_6,param_7,0,param_9,
                              plVar24,1);
          if (uVar23 == 0) goto LAB_fffffff009c44708;
        }
        goto LAB_fffffff009c44558;
      }
      thunk_FUN_fffffff00a9029a0
                ((byte *)"====> %s:%d Unable to assemble descriptor of the correct length\n");
LAB_fffffff009c44708:
      plVar31 = (long *)0x0;
    }
    (**(code **)(*plVar24 + 0x28))(plVar24);
  }
  if (param_11 != (long *)0x0) {
    (**(code **)(*param_11 + 0x28))(param_11);
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_68) {
    return plVar31;
  }
LAB_fffffff009c44a54:
                    /* WARNING: Subroutine does not return */
  thunk_FUN_fffffff00aa4c590();
}

