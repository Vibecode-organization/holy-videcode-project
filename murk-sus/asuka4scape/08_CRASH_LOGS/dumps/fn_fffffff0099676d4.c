// FUN_fffffff0099676d4 @ fffffff0099676d4 size=1236
// CALLERS:
//   fffffff00afe614d no-fn
//   fffffff00994852c FUN_fffffff0099484d0@fffffff0099484d0
// CALLEES:
//   fffffff00998482c thunk_FUN_fffffff009c2e2f4
//   fffffff00998486c thunk_FUN_fffffff009c2e2a4
//   fffffff00998481c thunk_FUN_fffffff009c2e314
//   fffffff009945040 FUN_fffffff009945040
//   fffffff009956134 FUN_fffffff009956134
//   fffffff00998484c thunk_FUN_fffffff009c2e0d0
//   fffffff009953a34 FUN_fffffff009953a34
//   fffffff009984a9c thunk_FUN_fffffff009c2a3d0
//   fffffff00998463c thunk_FUN_fffffff009c33b68
//   fffffff00998499c thunk_FUN_fffffff00a8cae24
//   fffffff009981d0c FUN_fffffff009981d0c
//   fffffff009984e3c thunk_FUN_fffffff00a76d3ec
//   fffffff009984a8c thunk_FUN_fffffff009c2a65c
//   fffffff0099847ac thunk_FUN_fffffff009c47468
//   fffffff009984aac thunk_FUN_fffffff009c29ee4
//   fffffff009984c0c thunk_FUN_fffffff00aa4c590
//   fffffff0099846cc thunk_FUN_fffffff00a894f30
//   fffffff00998457c thunk_FUN_fffffff00a9a7b30
//   fffffff0099847fc thunk_FUN_fffffff009c2e2d4
//   fffffff0099849cc thunk_FUN_fffffff00a8d2200
//   fffffff0099845cc thunk_FUN_fffffff00a8a10d8
//   fffffff0099845dc thunk_FUN_fffffff00a8a140c
//   fffffff00998485c thunk_FUN_fffffff009c2e294
//   fffffff00998480c thunk_FUN_fffffff009c2e324
//   fffffff00998483c thunk_FUN_fffffff009c2e334

undefined8
FUN_fffffff0099676d4
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,uint param_8,
          ulong param_9,ulong param_10,undefined4 *param_11)

{
  long lVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  uint uVar10;
  undefined4 uVar11;
  long *plVar12;
  long *plVar13;
  long lVar14;
  ulong uVar15;
  long *plVar16;
  long *plVar17;
  long *plVar18;
  long *plVar19;
  long *plVar20;
  long *plVar21;
  undefined8 uVar22;
  undefined8 uVar23;
  long lVar24;
  undefined8 extraout_d0;
  undefined8 extraout_d0_00;
  undefined8 extraout_var;
  undefined8 extraout_var_00;
  undefined4 uVar25;
  undefined1 auVar26 [12];
  undefined4 uVar27;
  undefined1 auVar28 [12];
  long *local_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 uStack_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 uStack_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  long local_70;
  
  uVar27 = param_4._0_4_;
  auVar28 = param_4._4_12_;
  uVar25 = param_3._0_4_;
  auVar26 = param_3._4_12_;
  local_70 = *(long *)PTR_DAT_fffffff007ff2800;
  uVar23 = 0xe00002c2;
  plVar12 = (long *)FUN_fffffff009945040
                              (param_1,param_2,param_3,param_4,param_5,param_6,
                               *(long *)(param_7 + 0x10),param_8);
  uVar22 = uVar23;
  if (plVar12 == (long *)0x0) goto LAB_fffffff009967b60;
  if ((*(byte *)(plVar12 + 2) & 0x7f) == 0) {
    plVar13 = thunk_FUN_fffffff00a894f30((long *)plVar12[5],(long)PTR_DAT_fffffff007fefaf0);
    lVar14 = FUN_fffffff009956134((long)plVar12);
    if (plVar13 != (long *)0x0) {
      plVar13 = FUN_fffffff009981d0c((long)plVar13);
      if (CARRY8(param_9,param_10)) {
        if (plVar13 == (long *)0x0) goto LAB_fffffff009967b40;
      }
      else {
        uVar15 = (**(code **)(*plVar13 + 0xb0))(plVar13);
        if (((param_10 | param_9) >> 0x20 == 0) && (param_9 + param_10 <= uVar15)) {
          plVar16 = thunk_FUN_fffffff00a8a10d8(8);
          uVar22 = 0xe00002bd;
          if (plVar16 != (long *)0x0) {
            uStack_88 = 0;
            local_90 = 0;
            uStack_78 = 0;
            uStack_80 = 0;
            uStack_a8 = 0;
            local_b0 = 0;
            uStack_98 = 0;
            uStack_a0 = 0;
            uStack_c8 = 0;
            local_d0 = 0;
            uStack_b8 = 0;
            uStack_c0 = 0;
            uStack_e8 = 0;
            local_f0 = 0;
            uStack_d8 = 0;
            uStack_e0 = 0;
            thunk_FUN_fffffff00a76d3ec((undefined1 *)&local_f0,0x80,(byte *)"ANE Buffer id 0x%x");
            plVar17 = thunk_FUN_fffffff00a8d2200(&local_f0);
            uVar10 = FUN_fffffff009953a34((long)plVar12);
            plVar18 = thunk_FUN_fffffff00a8cae24((ulong)uVar10,0x40);
            if (plVar17 == (long *)0x0) {
              if (plVar18 != (long *)0x0) {
                uVar23 = 0xe00002bd;
                goto LAB_fffffff009967ad0;
              }
              uVar23 = 0xe00002bd;
            }
            else {
              if (plVar18 == (long *)0x0) {
                uVar23 = 0xe00002bd;
              }
              else {
                uVar22 = *(undefined8 *)PTR_PTR_fffffff007ff2810;
                local_f8 = plVar17;
                (**(code **)(*plVar17 + 0x20))(plVar17);
                thunk_FUN_fffffff00a8a140c(plVar16,uVar22,&local_f8);
                if (local_f8 != (long *)0x0) {
                  (**(code **)(*local_f8 + 0x28))();
                }
                uVar22 = *(undefined8 *)PTR_PTR_fffffff007ff2818;
                local_f8 = plVar18;
                (**(code **)(*plVar18 + 0x20))();
                thunk_FUN_fffffff00a8a140c(plVar16,uVar22,&local_f8);
                if (local_f8 != (long *)0x0) {
                  (**(code **)(*local_f8 + 0x28))();
                }
                lVar1 = *(long *)(param_7 + 0x50);
                lVar24 = *(long *)(*(long *)(param_7 + 0x48) + 0xf8);
                auVar2 = (**(code **)(*plVar16 + 0x20))(plVar16);
                auVar4._4_12_ = auVar26;
                auVar4._0_4_ = uVar25;
                auVar7._4_12_ = auVar28;
                auVar7._0_4_ = uVar27;
                plVar19 = thunk_FUN_fffffff009c33b68
                                    (auVar2,param_2,auVar4,auVar7,param_5,param_6,lVar24,lVar1,
                                     plVar16,(long *)0x0);
                if (plVar19 != (long *)0x0) {
                  plVar20 = thunk_FUN_fffffff009c2e0d0();
                  thunk_FUN_fffffff009c2e314((long)plVar20,(int)param_9);
                  uVar11 = (**(code **)(*plVar13 + 0xb0))(plVar13);
                  thunk_FUN_fffffff009c2e2d4((long)plVar20,uVar11);
                  thunk_FUN_fffffff009c2e294((long)plVar20,(int)param_10);
                  thunk_FUN_fffffff009c2e324((long)plVar20,(int)param_10);
                  thunk_FUN_fffffff009c2e334((long)plVar20,1);
                  thunk_FUN_fffffff009c2e2a4((long)plVar20,1);
                  auVar2 = thunk_FUN_fffffff009c2e2f4((long)plVar20,lVar14 == 0);
                  auVar5._4_12_ = auVar26;
                  auVar5._0_4_ = uVar25;
                  auVar8._4_12_ = auVar28;
                  auVar8._0_4_ = uVar27;
                  thunk_FUN_fffffff009c29ee4
                            (auVar2,param_2,auVar5,auVar8,param_5,param_6,(long)plVar19,
                             (long)plVar20);
                  auVar2._8_8_ = extraout_var;
                  auVar2._0_8_ = extraout_d0;
                  thunk_FUN_fffffff009c2a3d0
                            (auVar2,param_2,uVar25,uVar27,param_5,param_6,(long)plVar19,plVar13);
                  thunk_FUN_fffffff009c2a65c((long)plVar19,1);
                  plVar21 = (long *)thunk_FUN_fffffff009c47468
                                              (*(undefined8 *)(*(long *)(param_7 + 0x48) + 0xf8),
                                               plVar19);
                  if (plVar21 != (long *)0x0) {
                    auVar3._8_8_ = extraout_var_00;
                    auVar3._0_8_ = extraout_d0_00;
                    auVar6._4_12_ = auVar26;
                    auVar6._0_4_ = uVar25;
                    auVar9._4_12_ = auVar28;
                    auVar9._0_4_ = uVar27;
                    uVar23 = thunk_FUN_fffffff00a9a7b30
                                       (auVar3,param_2,auVar6,auVar9,param_5,param_6,
                                        *(long *)(param_7 + 0x50),plVar21,param_11);
                    (**(code **)(*plVar21 + 0x28))(plVar21);
                  }
                  if (plVar20 != (long *)0x0) {
                    (**(code **)(*plVar20 + 0x28))(plVar20);
                  }
                  (**(code **)(*plVar19 + 0x28))(plVar19);
                }
LAB_fffffff009967ad0:
                (**(code **)(*plVar18 + 0x28))();
                if (plVar17 == (long *)0x0) goto LAB_fffffff009967b08;
              }
              (**(code **)(*plVar17 + 0x28))(plVar17);
            }
LAB_fffffff009967b08:
            (**(code **)(*plVar16 + 0x28))(plVar16);
            uVar22 = uVar23;
          }
        }
      }
      (**(code **)(*plVar13 + 0x28))(plVar13);
    }
  }
LAB_fffffff009967b40:
  (**(code **)(*plVar12 + 0x28))(plVar12);
LAB_fffffff009967b60:
  if (*(long *)PTR_DAT_fffffff007ff2800 != local_70) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_fffffff00aa4c590();
  }
  return uVar22;
}

