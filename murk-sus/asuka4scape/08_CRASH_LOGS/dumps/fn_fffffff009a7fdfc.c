// FUN_fffffff009a7fdfc @ fffffff009a7fdfc size=1204
// CALLERS:
//   fffffff00afe837d no-fn
//   fffffff009a816c8 FUN_fffffff009a80844@fffffff009a80844
// CALLEES:
//   fffffff009a99bc0 thunk_FUN_fffffff00a9029a0
//   fffffff009a7f68c FUN_fffffff009a7f68c
//   fffffff009a802b0 FUN_fffffff009a802b0
//   fffffff009a9a670 thunk_FUN_fffffff009c2771c
//   fffffff009a9a760 thunk_FUN_fffffff009c223bc
//   fffffff009a9a8a0 thunk_FUN_fffffff00a6de494
//   fffffff009a9a7e0 thunk_FUN_fffffff009c28af0
//   fffffff009a99fe0 thunk_FUN_fffffff009c190fc
//   fffffff009a9a750 thunk_FUN_fffffff009c2235c
//   fffffff009a9a7d0 thunk_FUN_fffffff009c2a71c
//   fffffff009a9a7b0 thunk_FUN_fffffff009c22264

undefined4
FUN_fffffff009a7fdfc
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long *param_7,
          undefined8 *param_8,long *param_9,undefined8 *param_10)

{
  ulong uVar1;
  char *pcVar2;
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
  undefined1 auVar21 [16];
  uint uVar22;
  int iVar23;
  uint uVar24;
  long *plVar25;
  undefined8 uVar26;
  ulong uVar27;
  long lVar28;
  long lVar29;
  long lVar30;
  long lVar31;
  ulong uVar32;
  ulong uVar33;
  long lVar34;
  undefined8 extraout_d0;
  undefined8 extraout_d0_00;
  undefined8 extraout_d0_01;
  undefined8 extraout_d0_02;
  undefined8 extraout_d0_03;
  undefined8 extraout_d0_04;
  undefined8 uVar35;
  undefined8 extraout_d0_05;
  undefined8 extraout_var;
  undefined1 auVar36 [16];
  undefined8 extraout_var_00;
  undefined8 extraout_var_01;
  undefined8 extraout_var_02;
  undefined8 extraout_var_03;
  undefined8 extraout_var_04;
  undefined8 uVar37;
  undefined8 extraout_var_05;
  undefined8 uVar38;
  undefined8 uVar39;
  undefined4 uVar40;
  undefined1 auVar41 [12];
  undefined4 uVar42;
  undefined1 auVar43 [12];
  undefined4 local_c4;
  long local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  ulong uStack_78;
  undefined8 local_70;
  undefined8 local_68;
  
  uVar39 = param_2._8_8_;
  uVar38 = param_2._0_8_;
  uVar37 = param_1._8_8_;
  uVar35 = param_1._0_8_;
  uVar42 = param_4._0_4_;
  auVar43 = param_4._4_12_;
  uVar40 = param_3._0_4_;
  auVar41 = param_3._4_12_;
  if ((*(byte *)((long)param_9 + 0x625) & 1) == 0) {
    if ((param_9[0x1a5] == 0) && ((*(byte *)((long)param_8 + 0x34f) & 1) == 0)) {
      plVar25 = thunk_FUN_fffffff009c190fc(param_7);
      param_9[0x1a5] = (long)plVar25;
      uVar35 = extraout_d0;
      uVar37 = extraout_var;
    }
    auVar36._8_8_ = uVar37;
    auVar36._0_8_ = uVar35;
    uVar32 = 0;
    local_c4 = 0;
    do {
      if (param_9[uVar32 + 0x170] == 0) {
        uVar33 = 1L << (uVar32 & 0x3f);
        if ((uVar33 & *(uint *)((long)param_8 + 0x14c)) != 0) {
          *(uint *)(param_8 + 0x2a) = *(uint *)(param_8 + 0x2a) | (uint)uVar33;
        }
      }
      else {
        uVar33 = (ulong)*(uint *)(param_8 + 0x13);
        uVar22 = thunk_FUN_fffffff009c2235c(param_9[uVar32 + 0x170]);
        (**(code **)(*param_9 + 0x20))(param_9);
        auVar36 = (**(code **)(*(long *)param_9[uVar32 + 0x170] + 0x20))();
        if ((int)(param_9 + uVar32 * 3 + 0x18a)[1] == 0) {
          uVar27 = (ulong)uVar22;
          auVar7._8_8_ = uVar39;
          auVar7._0_8_ = uVar38;
          thunk_FUN_fffffff00a6de494
                    (auVar36,auVar7,uVar40,uVar42,param_5,param_6,0x31800308,uVar33,uVar32,uVar27,0)
          ;
          auVar3._8_8_ = extraout_var_01;
          auVar3._0_8_ = extraout_d0_01;
          auVar8._8_8_ = uVar39;
          auVar8._0_8_ = uVar38;
          auVar14._4_12_ = auVar41;
          auVar14._0_4_ = uVar40;
          auVar18._4_12_ = auVar43;
          auVar18._0_4_ = uVar42;
          uVar26 = thunk_FUN_fffffff009c2771c
                             (auVar3,auVar8,auVar14,auVar18,param_5,param_6,
                              (long *)param_9[uVar32 + 0x170],(long *)param_9[0x1a5],
                              param_9 + uVar32 + 0x16c,1,(undefined *)0x0,-0xff6581294,(long)param_7
                              ,(long)param_9,0);
          uVar35 = extraout_d0_02;
          uVar37 = extraout_var_02;
          if ((int)uVar26 == 0) goto LAB_fffffff009a8022c;
          auVar4._8_8_ = extraout_var_02;
          auVar4._0_8_ = extraout_d0_02;
          auVar9._8_8_ = uVar39;
          auVar9._0_8_ = uVar38;
          thunk_FUN_fffffff00a6de494
                    (auVar4,auVar9,uVar40,uVar42,param_5,param_6,0x3180030c,uVar33,uVar32,uVar27,0);
          auVar5._8_8_ = extraout_var_03;
          auVar5._0_8_ = extraout_d0_03;
          auVar10._8_8_ = uVar39;
          auVar10._0_8_ = uVar38;
          thunk_FUN_fffffff00a6de494
                    (auVar5,auVar10,uVar40,uVar42,param_5,param_6,0x31800551,uVar33,uVar32,uVar27,0)
          ;
LAB_fffffff009a7ffec:
          uVar27 = thunk_FUN_fffffff009c2a71c(param_9[uVar32 + 0x170]);
          uVar33 = param_8[6];
          if (uVar33 == 0) {
            uVar33 = (**(code **)(*param_7 + 0x7e8))(param_7);
          }
          uVar1 = uVar27;
          if (uVar33 <= uVar27) {
            uVar1 = uVar33;
          }
          if (uVar27 != 0) {
            uVar33 = uVar1;
          }
          param_8[6] = uVar33;
          uVar27 = param_9[0x79];
          if ((ulong)param_9[0x79] <= uVar33) {
            uVar27 = uVar33;
          }
          param_9[0x79] = uVar27;
          plVar25 = (long *)param_7[0x77];
          if (plVar25 != (long *)0x0) {
            uVar38 = 0;
            uVar39 = 0;
            local_68 = 0;
            local_a0 = (ulong)*(uint *)(param_8 + 0x13) << 0x20;
            local_70 = *param_8;
            uStack_98 = param_8[1];
            uStack_88 = param_8[4];
            local_90 = param_8[3];
            local_80 = param_8[5];
            uStack_78 = uVar33;
            (**(code **)(*plVar25 + 0x80))(plVar25,uVar32,param_9[uVar32 + 0x170],&local_a0);
            *param_10 = local_68;
            local_c4 = 1;
          }
          *(undefined1 *)((long)param_9 + uVar32 + 0x626) = 0;
          if ((*(byte *)((long)param_7 + 0x5861) & 1) != 0) {
            lVar34 = param_9[uVar32 + 0x170];
            plVar25 = (long *)thunk_FUN_fffffff009c22264(lVar34);
            plVar25 = (long *)(**(code **)(*plVar25 + 0xe8))(plVar25,0);
            if (plVar25 != (long *)0x0) {
              lVar28 = (**(code **)(*plVar25 + 0x78))();
              if ((lVar28 != 0) && (iVar23 = thunk_FUN_fffffff009c223bc(lVar34), iVar23 != 0)) {
                uVar22 = 0;
                uVar35 = extraout_d0_04;
                uVar37 = extraout_var_04;
                do {
                  auVar6._8_8_ = uVar37;
                  auVar6._0_8_ = uVar35;
                  auVar12._8_8_ = uVar39;
                  auVar12._0_8_ = uVar38;
                  auVar16._4_12_ = auVar41;
                  auVar16._0_4_ = uVar40;
                  auVar20._4_12_ = auVar43;
                  auVar20._0_4_ = uVar42;
                  lVar29 = thunk_FUN_fffffff009c28af0
                                     (auVar6,auVar12,auVar16,auVar20,param_5,param_6,lVar34,uVar22);
                  if ((lVar29 != 0) && (*(char *)(lVar29 + 0x20) != '\0')) {
                    lVar30 = 0;
                    lVar29 = lVar28 + (ulong)*(uint *)(lVar29 + 8);
                    lVar31 = 0x10;
                    do {
                      pcVar2 = (char *)(lVar29 + (int)lVar30);
                      if (lVar30 != (int)lVar30) {
                        pcVar2 = (char *)(lVar29 + lVar30 & 0xffffffffffffU | 0x2bad000000000000);
                      }
                      if (*pcVar2 != '\0') goto LAB_fffffff009a801a4;
                      lVar30 = lVar30 + 1;
                      lVar31 = lVar31 + -1;
                    } while (lVar31 != 0);
                    thunk_FUN_fffffff009c2235c(lVar34);
                    thunk_FUN_fffffff00a9029a0
                              ((byte *)
                               "IOMFB: [%s] SurfaceID 0x%x GP Decompression Error Debug - Detected 16 bytes of zero values in metadata buffer \n"
                              );
                  }
LAB_fffffff009a801a4:
                  uVar22 = uVar22 + 1;
                  uVar24 = thunk_FUN_fffffff009c223bc(lVar34);
                  uVar35 = extraout_d0_05;
                  uVar37 = extraout_var_05;
                } while (uVar22 < uVar24);
              }
              (**(code **)(*plVar25 + 0x28))(plVar25);
            }
          }
          *(uint *)(param_8 + 0x2a) = *(uint *)(param_8 + 0x2a) | 1 << (ulong)((uint)uVar32 & 0x1f);
          (**(code **)(*(long *)param_9[uVar32 + 0x170] + 0x28))();
          auVar36 = (**(code **)(*param_9 + 0x28))(param_9);
        }
        else {
          auVar11._8_8_ = uVar39;
          auVar11._0_8_ = uVar38;
          auVar15._4_12_ = auVar41;
          auVar15._0_4_ = uVar40;
          auVar19._4_12_ = auVar43;
          auVar19._0_4_ = uVar42;
          uVar33 = FUN_fffffff009a7f68c
                             (auVar36,auVar11,auVar15,auVar19,param_5,param_6,param_7,
                              param_9 + uVar32 * 3 + 0x18a,(undefined *)param_9[uVar32 + 0x170],
                              (undefined *)param_9,(uint)uVar32,1,0,1);
          uVar35 = extraout_d0_00;
          uVar37 = extraout_var_00;
          if ((int)uVar33 != 0) goto LAB_fffffff009a7ffec;
LAB_fffffff009a8022c:
          auVar36._8_8_ = uVar37;
          auVar36._0_8_ = uVar35;
          *(undefined1 *)((long)param_9 + uVar32 + 0x626) = 1;
        }
        *(undefined1 *)((long)param_9 + 0x625) = 1;
      }
      uVar32 = uVar32 + 1;
    } while (uVar32 != 4);
    plVar25 = (long *)param_9[0x1a5];
    if ((*(byte *)((long)param_9 + 0x625) & 1) == 0) {
      if (plVar25 != (long *)0x0) {
        (**(code **)(*plVar25 + 0x28))();
      }
      param_9[0x1a5] = 0;
    }
    else if (plVar25 != (long *)0x0) {
      auVar13._8_8_ = uVar39;
      auVar13._0_8_ = uVar38;
      auVar17._4_12_ = auVar41;
      auVar17._0_4_ = uVar40;
      auVar21._4_12_ = auVar43;
      auVar21._0_4_ = uVar42;
      FUN_fffffff009a802b0(auVar36,auVar13,auVar17,auVar21,param_5,param_6,(long)param_7);
    }
  }
  else {
    local_c4 = 0;
  }
  return local_c4;
}

