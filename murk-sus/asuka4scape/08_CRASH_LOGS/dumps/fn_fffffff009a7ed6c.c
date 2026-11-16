// FUN_fffffff009a7ed6c @ fffffff009a7ed6c size=1708
// CALLERS:
//   fffffff00afe8372 no-fn
//   fffffff009a7ec14 FUN_fffffff009a7ea60@fffffff009a7ea60
//   fffffff009a7ff8c FUN_fffffff009a7fdfc@fffffff009a7fdfc
// CALLEES:
//   fffffff009a7ea60 FUN_fffffff009a7ea60
//   fffffff009a99b60 thunk_FUN_fffffff00a2262a8
//   fffffff009a996cc FUN_fffffff009a996cc
//   fffffff009a9a750 thunk_FUN_fffffff009c2235c
//   fffffff009a9a7d0 thunk_FUN_fffffff009c2a71c
//   fffffff009a99ba0 thunk_FUN_fffffff00a226de0
//   fffffff009a99bc0 thunk_FUN_fffffff00a9029a0
//   fffffff009a7fba4 FUN_fffffff009a7fba4
//   fffffff009a88f34 FUN_fffffff009a88f34
//   fffffff009a99b20 thunk_FUN_fffffff00a22170c
//   fffffff009a9a760 thunk_FUN_fffffff009c223bc
//   fffffff009a9a8a0 thunk_FUN_fffffff00a6de494
//   fffffff009a9a7e0 thunk_FUN_fffffff009c28af0
//   fffffff009a9a450 thunk_FUN_fffffff009c41314
//   fffffff009a9a7b0 thunk_FUN_fffffff009c22264

/* WARNING: Removing unreachable block (ram,0xfffffff009a7f1dc) */
/* WARNING: Removing unreachable block (ram,0xfffffff009a7ef24) */
/* WARNING: Removing unreachable block (ram,0xfffffff009a7f184) */
/* WARNING: Removing unreachable block (ram,0xfffffff009a7f404) */

void FUN_fffffff009a7ed6c
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long *param_7,
               long *param_8,long *param_9,undefined8 *param_10)

{
  uint uVar1;
  ulong uVar2;
  char *pcVar3;
  byte bVar4;
  byte bVar5;
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
  undefined1 auVar21 [16];
  undefined1 auVar22 [16];
  undefined1 auVar23 [16];
  undefined1 auVar24 [16];
  undefined1 auVar25 [16];
  undefined1 auVar26 [16];
  undefined1 auVar27 [16];
  undefined4 uVar28;
  uint uVar29;
  int iVar30;
  uint uVar31;
  uint uVar32;
  undefined4 uVar33;
  long lVar34;
  long lVar35;
  long *extraout_x0;
  long *extraout_x1;
  int *piVar36;
  code *pcVar37;
  long lVar38;
  long *plVar39;
  long lVar40;
  int iVar41;
  ulong uVar42;
  ulong uVar43;
  long lVar44;
  long lVar45;
  long lVar46;
  ulong uVar47;
  ulong unaff_x30;
  undefined8 extraout_d0;
  undefined8 extraout_d0_01;
  undefined8 uVar48;
  undefined8 extraout_d0_02;
  undefined8 extraout_d0_03;
  undefined8 extraout_d0_04;
  undefined8 extraout_d0_00;
  undefined8 extraout_var;
  undefined8 extraout_var_00;
  undefined1 auVar49 [16];
  undefined8 extraout_var_01;
  undefined8 uVar50;
  undefined8 extraout_var_02;
  undefined8 extraout_var_03;
  undefined8 extraout_var_04;
  long lVar51;
  long lVar52;
  undefined1 auVar53 [12];
  undefined4 uVar54;
  undefined1 auVar55 [12];
  long local_a0;
  long lStack_98;
  long local_90;
  long lStack_88;
  long local_80;
  long lStack_78;
  long local_70;
  undefined8 uStack_68;
  
  lVar52 = param_2._8_8_;
  lVar51 = param_2._0_8_;
  uVar54 = param_4._0_4_;
  auVar55 = param_4._4_12_;
  uVar33 = param_3._0_4_;
  auVar53 = param_3._4_12_;
  bVar4 = *(byte *)((long)param_7 + 0x4d22);
  lStack_78 = 0;
  local_80 = 0;
  uStack_68 = 0;
  local_70 = 0;
  lStack_98 = 0;
  local_a0 = 0;
  lStack_88 = 0;
  local_90 = 0;
  plVar39 = param_9;
  piVar36 = (int *)param_10;
  thunk_FUN_fffffff00a2262a8(param_7[0x9a6]);
  auVar49 = thunk_FUN_fffffff00a2262a8(param_7[0x9a5]);
  if (((param_8 == (long *)0x0) || (param_7 == (long *)0x0)) || (param_9 == (long *)0x0)) {
    auVar10._8_8_ = lVar52;
    auVar10._0_8_ = lVar51;
    auVar18._4_12_ = auVar53;
    auVar18._0_4_ = uVar33;
    auVar23._4_12_ = auVar55;
    auVar23._0_4_ = uVar54;
    FUN_fffffff009a996cc(auVar49,auVar10,auVar18,auVar23,param_5,param_6);
    if ((extraout_x0 != (long *)0x0) &&
       (auVar49._8_8_ = extraout_var_04, auVar49._0_8_ = extraout_d0_04, auVar11._8_8_ = lVar52,
       auVar11._0_8_ = lVar51, auVar19._4_12_ = auVar53, auVar19._0_4_ = uVar33,
       auVar24._4_12_ = auVar55, auVar24._0_4_ = uVar54,
       FUN_fffffff009a7ea60
                 (auVar49,auVar11,auVar19,auVar24,param_5,param_6,extraout_x0,extraout_x1,
                  (long)plVar39,piVar36), piVar36 != (int *)0x0)) {
      thunk_FUN_fffffff00a22170c((long *)&DAT_fffffff008021510,(undefined8 *)piVar36);
      return;
    }
    return;
  }
  if (((*(byte *)((long)param_8 + 0x62a) & 1) == 0) || ((*(byte *)(param_7 + 0xb0e) & 1) == 0)) {
    uVar29 = *(uint *)((long)param_8 + 0x3d4);
    uVar43 = (ulong)uVar29;
    bVar5 = *(byte *)(param_8 + 0x183);
    iVar41 = (int)param_10;
    if ((*(uint *)PTR_DAT_fffffff008022368 & 0xfffffff7) != 0) {
      uVar28 = thunk_FUN_fffffff009c2235c((long)param_9);
      auVar6._8_8_ = extraout_var;
      auVar6._0_8_ = extraout_d0;
      auVar12._8_8_ = lVar52;
      auVar12._0_8_ = lVar51;
      thunk_FUN_fffffff00a6de494
                (auVar6,auVar12,uVar33,uVar54,param_5,param_6,0x31800444,uVar43,
                 CONCAT44((int)param_7[0xb1e],uVar28),(long)iVar41,0);
    }
    lVar44 = 0;
    uVar42 = 0;
    uVar1 = (uint)(param_8 != (long *)0x0 & bVar4);
    lVar45 = 0x504;
    do {
      if ((bVar5 & 1) == 0) {
        plVar39 = (long *)param_8[uVar42 + 0x170];
      }
      else {
        plVar39 = (long *)param_8[uVar42 + 0x184];
      }
      if (plVar39 == param_9) {
        if ((*(byte *)(param_8 + 0x183) & 1) == 0) {
          uVar47 = thunk_FUN_fffffff009c2a71c((long)param_9);
          if (uVar47 == 0) {
            uVar47 = (**(code **)(*param_7 + 0x7e8))(param_7);
          }
          uVar2 = param_8[0x79];
          if ((ulong)param_8[0x79] <= uVar47) {
            uVar2 = uVar47;
          }
          param_8[0x79] = uVar2;
          *(undefined1 *)((long)param_8 + uVar42 + 0x626) = 0;
          if (((*(byte *)((long)param_7 + 0x5861) & 1) != 0) &&
             (lVar46 = param_8[(uVar42 & 0xffffffff) + 0x170], lVar46 != 0)) {
            plVar39 = (long *)thunk_FUN_fffffff009c22264(lVar46);
            plVar39 = (long *)(**(code **)(*plVar39 + 0xe8))(plVar39,0);
            if (plVar39 != (long *)0x0) {
              lVar34 = (**(code **)(*plVar39 + 0x78))();
              if ((lVar34 != 0) && (iVar30 = thunk_FUN_fffffff009c223bc(lVar46), iVar30 != 0)) {
                uVar32 = 0;
                uVar48 = extraout_d0_01;
                uVar50 = extraout_var_01;
                do {
                  auVar7._8_8_ = uVar50;
                  auVar7._0_8_ = uVar48;
                  auVar13._8_8_ = lVar52;
                  auVar13._0_8_ = lVar51;
                  auVar20._4_12_ = auVar53;
                  auVar20._0_4_ = uVar33;
                  auVar25._4_12_ = auVar55;
                  auVar25._0_4_ = uVar54;
                  lVar35 = thunk_FUN_fffffff009c28af0
                                     (auVar7,auVar13,auVar20,auVar25,param_5,param_6,lVar46,uVar32);
                  if ((lVar35 != 0) && (*(char *)(lVar35 + 0x20) != '\0')) {
                    lVar38 = 0;
                    lVar35 = lVar34 + (ulong)*(uint *)(lVar35 + 8);
                    lVar40 = 0x10;
                    do {
                      pcVar3 = (char *)(lVar35 + (int)lVar38);
                      if (lVar38 != (int)lVar38) {
                        pcVar3 = (char *)(lVar35 + lVar38 & 0xffffffffffffU | 0x2bad000000000000);
                      }
                      if (*pcVar3 != '\0') goto LAB_fffffff009a7f0c0;
                      lVar38 = lVar38 + 1;
                      lVar40 = lVar40 + -1;
                    } while (lVar40 != 0);
                    thunk_FUN_fffffff009c2235c(lVar46);
                    thunk_FUN_fffffff00a9029a0
                              ((byte *)
                               "IOMFB: [%s] SurfaceID 0x%x GP Decompression Error Debug - Detected 16 bytes of zero values in metadata buffer \n"
                              );
                  }
LAB_fffffff009a7f0c0:
                  uVar32 = uVar32 + 1;
                  uVar31 = thunk_FUN_fffffff009c223bc(lVar46);
                  uVar48 = extraout_d0_02;
                  uVar50 = extraout_var_02;
                } while (uVar32 < uVar31);
              }
              (**(code **)(*plVar39 + 0x28))();
            }
          }
          if (uVar1 != 0) {
            local_a0 = (ulong)*(uint *)((long)param_8 + 0x3d4) << 0x20;
            lStack_98 = param_8[0x74];
            lStack_88 = param_8[0x77];
            local_90 = param_8[0x76];
            lVar52 = param_8[0x79];
            lVar51 = param_8[0x78];
            local_70 = param_8[0x72];
            local_80 = lVar51;
            lStack_78 = lVar52;
          }
          if ((iVar41 == 0) && (*(long *)((long)param_8 + lVar44 + 0xc50) != 0)) {
            uVar32 = thunk_FUN_fffffff009c2235c((long)param_9);
            auVar8._8_8_ = extraout_var_03;
            auVar8._0_8_ = extraout_d0_03;
            auVar14._8_8_ = lVar52;
            auVar14._0_8_ = lVar51;
            thunk_FUN_fffffff00a6de494
                      (auVar8,auVar14,uVar33,uVar54,param_5,param_6,0x31800514,uVar43,(ulong)uVar32,
                       (ulong)*(uint *)((long)param_8 + lVar44 + 0xc60),lVar45);
            uVar33 = thunk_FUN_fffffff009c2235c((long)param_9);
            (**(code **)(*param_7 + 0x888))
                      (*param_7 + 0x888,param_7,0xa5,uVar43,uVar33,
                       *(undefined4 *)((long)param_8 + lVar44 + 0xc60),lVar45);
            uVar33 = thunk_FUN_fffffff009c2235c((long)param_9);
            (**(code **)(*param_7 + 0x888))
                      (*param_7 + 0x888,param_7,0xb0,uVar43,uVar33,
                       *(undefined4 *)((long)param_8 + lVar44 + 0xc60),(int)lVar45 + 3);
            plVar39 = *(long **)((long)param_8 + lVar44 + 0xc50);
            if (plVar39 != (long *)0x0) {
              (**(code **)(*plVar39 + 0x28))();
            }
            *(undefined8 *)((long)param_8 + lVar44 + 0xc50) = 0;
          }
          (**(code **)(*param_8 + 0x28))(param_8);
          bVar4 = *(byte *)(param_7 + 0xb0e);
          thunk_FUN_fffffff00a226de0(param_7[0x9a5]);
          if ((bVar4 & 1) == 0) {
            uVar33 = thunk_FUN_fffffff009c2235c((long)param_9);
            uVar29 = FUN_fffffff009a88f34(param_7,uVar29,uVar33,uVar47,iVar41);
            if (((uVar29 & uVar1) == 1) && (plVar39 = (long *)param_7[0x77], plVar39 != (long *)0x0)
               ) {
              (**(code **)(*plVar39 + 0x80))(plVar39,uVar42,param_9,&local_a0);
            }
          }
          thunk_FUN_fffffff00a226de0(param_7[0x9a6]);
          (**(code **)(*param_9 + 0x28))(param_9);
          return;
        }
        uVar29 = thunk_FUN_fffffff009c2235c((long)param_9);
        uVar47 = uVar42 & 0xffffffff;
        auVar9._8_8_ = extraout_var_00;
        auVar9._0_8_ = extraout_d0_00;
        auVar15._8_8_ = lVar52;
        auVar15._0_8_ = lVar51;
        thunk_FUN_fffffff00a6de494
                  (auVar9,auVar15,uVar33,uVar54,param_5,param_6,0x31800514,uVar43,(ulong)uVar29,
                   (ulong)*(uint *)((long)param_8 + lVar44 + 0xc60),lVar45 + -0x200);
        uVar28 = thunk_FUN_fffffff009c2235c((long)param_9);
        auVar49 = (**(code **)(*param_7 + 0x888))
                            (*param_7 + 0x888,param_7,0xa5,uVar43,uVar28,
                             *(undefined4 *)((long)param_8 + lVar44 + 0xc60),lVar45 + -0x200);
        if (*(int *)((long)param_8 + lVar44 + 0xcd0) == 0) {
          auVar16._8_8_ = lVar52;
          auVar16._0_8_ = lVar51;
          auVar21._4_12_ = auVar53;
          auVar21._0_4_ = uVar33;
          auVar26._4_12_ = auVar55;
          auVar26._0_4_ = uVar54;
          thunk_FUN_fffffff009c41314
                    (auVar49,auVar16,auVar21,auVar26,param_5,param_6,(long *)param_8[uVar47 + 0x16c]
                     ,0xe00002bc);
          (**(code **)(*(long *)param_8[uVar47 + 0x16c] + 0x28))();
          param_8[uVar47 + 0x16c] = 0;
        }
        else {
          auVar17._8_8_ = lVar52;
          auVar17._0_8_ = lVar51;
          auVar22._4_12_ = auVar53;
          auVar22._0_4_ = uVar33;
          auVar27._4_12_ = auVar55;
          auVar27._0_4_ = uVar54;
          FUN_fffffff009a7fba4
                    (auVar49,auVar17,auVar22,auVar27,param_5,param_6,param_7,
                     (long *)((long)param_8 + lVar44 + 0xcc8),param_8[uVar47 + 0x170],
                     (ulong)*(uint *)((long)param_8 + 0x3d4),uVar42,0,0x12);
        }
        param_9 = (long *)param_8[uVar47 + 0x184];
        if (param_9 == (long *)0x0) goto LAB_fffffff009a7f360;
        pcVar37 = *(code **)(*param_9 + 0x28);
        goto LAB_fffffff009a7f358;
      }
      uVar42 = uVar42 + 1;
      lVar45 = lVar45 + 0x10000;
      lVar44 = lVar44 + 0x18;
    } while (lVar45 != 0x40504);
  }
  else {
    pcVar37 = *(code **)(*param_9 + 0x28);
LAB_fffffff009a7f358:
    (*pcVar37)(param_9);
LAB_fffffff009a7f360:
    (**(code **)(*param_8 + 0x28))(param_8);
  }
  thunk_FUN_fffffff00a226de0(param_7[0x9a5]);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
    thunk_FUN_fffffff00a226de0(param_7[0x9a6]);
    return;
  }
                    /* WARNING: Does not return */
  pcVar37 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009a7f3b8);
  (*pcVar37)();
}

