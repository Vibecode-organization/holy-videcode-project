// FUN_fffffff009a75f3c @ fffffff009a75f3c size=1272
// CALLERS:
//   fffffff00afe82ae no-fn
//   fffffff009a75b84 FUN_fffffff009a756f8@fffffff009a756f8
//   fffffff009a7d6e8 FUN_fffffff009a7d52c@fffffff009a7d52c
//   fffffff009a81250 FUN_fffffff009a80844@fffffff009a80844
// CALLEES:
//   fffffff009a9a750 thunk_FUN_fffffff009c2235c
//   fffffff009a99ba0 thunk_FUN_fffffff00a226de0
//   fffffff009a9a650 thunk_FUN_fffffff009c21350
//   fffffff009a99ce0 thunk_FUN_fffffff00a8945fc
//   fffffff009a9a6b0 thunk_FUN_fffffff009c23a14
//   fffffff009a932e4 FUN_fffffff009a932e4
//   fffffff009a9a610 thunk_FUN_fffffff009c25748
//   fffffff009a9a730 thunk_FUN_fffffff009c223e0
//   fffffff009a99b60 thunk_FUN_fffffff00a2262a8
//   fffffff009a9a800 thunk_FUN_fffffff00aa4c590
//   fffffff009a99e20 thunk_FUN_fffffff00a96a264
//   fffffff009a9a690 thunk_FUN_fffffff009c237e8
//   fffffff009a9a000 thunk_FUN_fffffff00a97c8c4
//   fffffff009a9a630 thunk_FUN_fffffff009c257a8
//   fffffff009a9a7b0 thunk_FUN_fffffff009c22264
//   fffffff009a99bc0 thunk_FUN_fffffff00a9029a0

undefined8
FUN_fffffff009a75f3c
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long *param_7,long param_8,
          long *param_9,undefined8 *param_10,undefined8 param_11,ulong param_12,ulong param_13)

{
  uint *puVar1;
  bool bVar2;
  uint uVar3;
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  bool bVar10;
  byte bVar11;
  byte bVar12;
  undefined1 auVar13 [16];
  int iVar14;
  uint uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  undefined8 extraout_x0;
  long *plVar18;
  ulong uVar19;
  long *plVar20;
  long lVar21;
  ulong uVar22;
  bool bVar23;
  undefined8 extraout_d0;
  undefined8 extraout_d0_04;
  undefined8 extraout_d0_05;
  undefined8 extraout_d0_06;
  undefined8 extraout_d0_07;
  undefined8 extraout_d0_08;
  undefined8 extraout_d0_09;
  undefined8 extraout_d0_10;
  undefined8 extraout_d0_11;
  undefined8 extraout_d0_12;
  undefined8 extraout_d0_00;
  undefined8 extraout_d0_01;
  undefined8 extraout_d0_02;
  undefined8 extraout_d0_03;
  undefined8 extraout_var;
  undefined8 extraout_var_00;
  undefined8 extraout_var_01;
  undefined8 extraout_var_02;
  undefined8 extraout_var_03;
  undefined1 auVar24 [16];
  undefined8 extraout_var_04;
  undefined8 extraout_var_05;
  undefined8 extraout_var_06;
  undefined8 extraout_var_07;
  undefined8 extraout_var_08;
  undefined8 extraout_var_09;
  undefined8 extraout_var_10;
  undefined8 extraout_var_11;
  undefined8 uVar25;
  undefined8 extraout_var_12;
  undefined4 uVar26;
  undefined1 auVar27 [12];
  undefined4 uVar28;
  undefined1 auVar29 [12];
  undefined4 local_9c;
  undefined1 *local_98;
  undefined8 local_90;
  ulong uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  long local_68;
  
  uVar28 = param_4._0_4_;
  auVar29 = param_4._4_12_;
  uVar26 = param_3._0_4_;
  auVar27 = param_3._4_12_;
  local_68 = *(long *)PTR_DAT_fffffff008022300;
  *param_9 = 0;
  *param_10 = 0;
  uVar16 = thunk_FUN_fffffff009c25748(param_1,param_2,uVar26,uVar28,param_5,param_6,param_8);
  if ((int)uVar16 == 0) {
    iVar14 = thunk_FUN_fffffff009c223e0(param_8);
    if (iVar14 != 0x700) {
      uVar16 = 0xe00002d1;
      uVar17 = extraout_d0;
      uVar25 = extraout_var;
      if ((*(byte *)((long)param_7 + 0x5861) & 1) != 0) {
        thunk_FUN_fffffff009c2235c(param_8);
        thunk_FUN_fffffff009c223e0(param_8);
        thunk_FUN_fffffff00a9029a0
                  ((byte *)
                   "IOMFB: Surface %d has cacheMode 0x%x, needs to be 0x%x for display RT fetch\n");
        uVar17 = extraout_d0_01;
        uVar25 = extraout_var_01;
      }
LAB_fffffff009a76020:
      plVar20 = (long *)0x0;
      bVar23 = false;
      bVar11 = 0;
      bVar12 = 0;
      bVar10 = false;
LAB_fffffff009a76034:
      if (param_8 != 0) {
        thunk_FUN_fffffff009c257a8(param_8,1);
        uVar17 = extraout_d0_02;
        uVar25 = extraout_var_02;
      }
      auVar24._8_8_ = uVar25;
      auVar24._0_8_ = uVar17;
      bVar2 = (bool)(bVar11 ^ 1);
      if (plVar20 == (long *)0x0) {
        bVar2 = true;
      }
      if (!bVar2) {
        auVar24 = (**(code **)(*plVar20 + 0xe0))(plVar20,0);
      }
      bVar2 = (bool)(bVar12 ^ 1);
      if (param_8 == 0) {
        bVar2 = true;
      }
      if (!bVar2) {
        thunk_FUN_fffffff009c23a14(auVar24,param_2,uVar26,uVar28,param_5,param_6,param_8);
        auVar24._8_8_ = extraout_var_03;
        auVar24._0_8_ = extraout_d0_03;
      }
      plVar20 = (long *)*param_9;
      if (plVar20 != (long *)0x0) {
        if (bVar10) {
          (**(code **)(*plVar20 + 0x90))(plVar20,1);
          plVar20 = (long *)*param_9;
        }
        goto LAB_fffffff009a760c4;
      }
      goto joined_r0xfffffff009a7613c;
    }
    auVar4._8_8_ = extraout_var;
    auVar4._0_8_ = extraout_d0;
    uVar16 = thunk_FUN_fffffff009c237e8(auVar4,param_2,uVar26,uVar28,param_5,param_6,param_8);
    uVar17 = extraout_d0_00;
    uVar25 = extraout_var_00;
    if ((int)uVar16 != 0) goto LAB_fffffff009a76020;
    uVar16 = 0xe00002be;
    plVar20 = (long *)thunk_FUN_fffffff009c22264(param_8);
    if (plVar20 == (long *)0x0) {
      bVar23 = false;
      bVar11 = 0;
      bVar10 = false;
      uVar16 = 0xe00002bd;
      uVar17 = extraout_d0_04;
      uVar25 = extraout_var_04;
LAB_fffffff009a76418:
      bVar12 = 1;
      goto LAB_fffffff009a76034;
    }
    uVar17 = (**(code **)(*plVar20 + 0xd8))(plVar20,0);
    if ((int)uVar17 != 0) {
      bVar23 = false;
      bVar11 = 0;
      bVar10 = false;
      bVar12 = 1;
      uVar16 = uVar17;
      uVar17 = extraout_d0_05;
      uVar25 = extraout_var_05;
      goto LAB_fffffff009a76034;
    }
    bVar11 = 1;
    auVar5._8_8_ = extraout_var_05;
    auVar5._0_8_ = extraout_d0_05;
    auVar6._4_12_ = auVar27;
    auVar6._0_4_ = uVar26;
    auVar8._4_12_ = auVar29;
    auVar8._0_4_ = uVar28;
    FUN_fffffff009a932e4(auVar5,param_2,auVar6,auVar8,param_5,param_6,(long *)param_7[0x87],1,0);
    if ((int)extraout_x0 != 0) {
      bVar23 = false;
      bVar10 = false;
      uVar16 = extraout_x0;
      uVar17 = extraout_d0_06;
      uVar25 = extraout_var_06;
      goto LAB_fffffff009a76418;
    }
    plVar18 = (long *)param_7[0x26];
    uVar17 = extraout_d0_06;
    uVar25 = extraout_var_06;
    if (plVar18 != (long *)0x0) {
      local_98 = &DAT_aaaaaaaaaaaaaaaa;
      uStack_88 = 0;
      local_90 = 0;
      uStack_78 = 0;
      uStack_80 = 0;
      plVar18 = (long *)(**(code **)(*plVar18 + 0x88))(plVar18,0);
      *param_9 = (long)plVar18;
      if (plVar18 == (long *)0x0) {
        plVar18 = thunk_FUN_fffffff00a96a264(PTR_FUN_fffffff008022250,0x40,0,0,0,1,param_7[0x27],0);
        *param_9 = (long)plVar18;
        if (plVar18 != (long *)0x0) goto LAB_fffffff009a76254;
        bVar10 = false;
        uVar17 = extraout_d0_07;
        uVar25 = extraout_var_07;
      }
      else {
LAB_fffffff009a76254:
        if (((param_12 & 1) == 0) && ((*(byte *)((long)param_7 + 0x5df1) & 1) != 0)) {
          thunk_FUN_fffffff00a97c8c4((long)plVar20,0x10);
          plVar18 = (long *)*param_9;
        }
        uVar17 = (**(code **)(*plVar18 + 0x88))(plVar18,plVar20,1);
        if ((int)uVar17 == 0) {
          local_98 = (undefined1 *)0x0;
          local_9c = 1;
          (**(code **)(*(long *)*param_9 + 0xb8))((long *)*param_9,&local_98,&local_90,&local_9c);
          uVar22 = uStack_88;
          *param_10 = local_90;
          uVar19 = (**(code **)(*plVar20 + 0xb0))(plVar20);
          if (uVar19 <= uVar22) {
            uVar17 = extraout_d0_09;
            uVar25 = extraout_var_09;
            if (param_7[0x27] != 0) {
              thunk_FUN_fffffff00a8945fc((int *)(param_7 + 0x4c));
              uVar17 = extraout_d0_11;
              uVar25 = extraout_var_11;
            }
            goto LAB_fffffff009a76364;
          }
          (**(code **)(*plVar20 + 0xb0))(plVar20);
          thunk_FUN_fffffff00a9029a0
                    ((byte *)"segData[0].fLength (%d) < pBuffMD[i]->getLength() (%d)\n");
          bVar10 = true;
          uVar17 = extraout_d0_10;
          uVar25 = extraout_var_10;
        }
        else {
          thunk_FUN_fffffff00a9029a0
                    ((byte *)
                     " * IOMFB: Could not set the memory descriptor for theDMA command (error:%d)\n"
                    );
          bVar10 = false;
          uVar16 = uVar17;
          uVar17 = extraout_d0_08;
          uVar25 = extraout_var_08;
        }
      }
      bVar23 = true;
      goto LAB_fffffff009a76418;
    }
LAB_fffffff009a76364:
    auVar13._8_8_ = uVar25;
    auVar13._0_8_ = uVar17;
    auVar24._8_8_ = uVar25;
    auVar24._0_8_ = uVar17;
    if (((param_13 & 1) == 0) && (auVar24 = auVar13, param_7[0x4d] != 0)) {
      uVar15 = thunk_FUN_fffffff009c2235c(param_8);
      thunk_FUN_fffffff00a2262a8(param_7[0x4d]);
      uVar3 = *(uint *)(param_7 + 0x6e);
      if (uVar3 != 0) {
        lVar21 = 0;
        uVar22 = (ulong)uVar3;
        do {
          if (*(uint *)((long)param_7 + lVar21 * 4 + 0x270) == uVar15) goto LAB_fffffff009a76420;
          lVar21 = lVar21 + 1;
          uVar22 = uVar22 - 1;
        } while (uVar22 != 0);
        if (0x3f < uVar3) {
LAB_fffffff009a76420:
          auVar24 = thunk_FUN_fffffff00a226de0(param_7[0x4d]);
          goto LAB_fffffff009a76428;
        }
      }
      *(uint *)(param_7 + 0x6e) = uVar3 + 1;
      lVar21 = (ulong)uVar3 * 4;
      puVar1 = (uint *)((long)param_7 + (long)(int)lVar21 + 0x270);
      if (lVar21 - (int)lVar21 != 0) {
        puVar1 = (uint *)((long)param_7 + lVar21 + 0x270 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar1 = uVar15;
      thunk_FUN_fffffff00a226de0(param_7[0x4d]);
      thunk_FUN_fffffff009c21350(param_8,(ulong)uVar15,param_7,-0xff6587e0c);
      auVar24._8_8_ = extraout_var_12;
      auVar24._0_8_ = extraout_d0_12;
    }
LAB_fffffff009a76428:
    uVar16 = 0;
  }
  else {
    plVar20 = (long *)*param_9;
    if (plVar20 == (long *)0x0) goto LAB_fffffff009a76100;
    bVar23 = false;
LAB_fffffff009a760c4:
    auVar24 = (**(code **)(*(long *)param_7[0x26] + 0x90))((long *)param_7[0x26],plVar20);
    *param_9 = 0;
    *param_10 = 0;
joined_r0xfffffff009a7613c:
    if (!bVar23) goto LAB_fffffff009a76100;
  }
  auVar7._4_12_ = auVar27;
  auVar7._0_4_ = uVar26;
  auVar9._4_12_ = auVar29;
  auVar9._0_4_ = uVar28;
  FUN_fffffff009a932e4(auVar24,param_2,auVar7,auVar9,param_5,param_6,(long *)param_7[0x87],0,0);
LAB_fffffff009a76100:
  if (*(long *)PTR_DAT_fffffff008022300 != local_68) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_fffffff00aa4c590();
  }
  return uVar16;
}

