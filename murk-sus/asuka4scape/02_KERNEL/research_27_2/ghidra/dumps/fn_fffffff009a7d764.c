// FUN_fffffff009a7d764 @ fffffff009a7d764 size=1764
// CALLERS:
//   fffffff00afe834d no-fn
//   fffffff009a7d62c FUN_fffffff009a7d52c@fffffff009a7d52c
//   fffffff009a7e2b0 FUN_fffffff009a7e020@fffffff009a7e020
// CALLEES:
//   fffffff009a9a1e0 thunk_FUN_fffffff009c2e294
//   fffffff009a9a060 thunk_FUN_fffffff009c2e524
//   fffffff009a9a0e0 thunk_FUN_fffffff009c2e4ac
//   fffffff009a9a0a0 thunk_FUN_fffffff009c2e284
//   fffffff009a9a050 thunk_FUN_fffffff009c2e430
//   fffffff009a9a190 thunk_FUN_fffffff009c2e704
//   fffffff009a9a620 thunk_FUN_fffffff009c25e38
//   fffffff009a9a070 thunk_FUN_fffffff009c2e304
//   fffffff009a7bdb0 FUN_fffffff009a7bdb0
//   fffffff009a99bc0 thunk_FUN_fffffff00a9029a0
//   fffffff009a9a040 thunk_FUN_fffffff009c2e2d4
//   fffffff009a9a030 thunk_FUN_fffffff009c2e2e4
//   fffffff009a9a170 thunk_FUN_fffffff009c2e6c8
//   fffffff009a9a090 thunk_FUN_fffffff009c2e324
//   fffffff009a9a120 thunk_FUN_fffffff009c2e3f4
//   fffffff009a9a160 thunk_FUN_fffffff009c2e68c
//   fffffff009a9a660 thunk_FUN_fffffff009c29ee4
//   fffffff009a9a7a0 thunk_FUN_fffffff009c223d4
//   fffffff009a9a0d0 thunk_FUN_fffffff009c2e334
//   fffffff009a9a080 thunk_FUN_fffffff009c2e344
//   fffffff009a9a110 thunk_FUN_fffffff009c2e560
//   fffffff009a9a780 thunk_FUN_fffffff009c22350
//   fffffff009a9a0c0 thunk_FUN_fffffff009c2e46c
//   fffffff009a9a1c0 thunk_FUN_fffffff009c2e614
//   fffffff009a9a150 thunk_FUN_fffffff009c2e7b8
//   fffffff009a9a130 thunk_FUN_fffffff009c2e4e8
//   fffffff009a9a180 thunk_FUN_fffffff009c2e7f4
//   fffffff009a9a0f0 thunk_FUN_fffffff009c2e0d0
//   fffffff009a9a0b0 thunk_FUN_fffffff009c2e37c
//   fffffff009a9a1d0 thunk_FUN_fffffff009c2e650
//   fffffff009a9a140 thunk_FUN_fffffff009c2e59c
//   fffffff009a9a1a0 thunk_FUN_fffffff009c2e740
//   fffffff009a9a1f0 thunk_FUN_fffffff009c2e2a4
//   fffffff009a9a1b0 thunk_FUN_fffffff009c2e77c
//   fffffff009a9a100 thunk_FUN_fffffff009c2e3b8

ulong FUN_fffffff009a7d764
                (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
                undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
                uint param_8,uint param_9,undefined4 *param_10,ulong param_11)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined *puVar5;
  bool bVar6;
  bool bVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  long lVar11;
  long *plVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  ulong uVar17;
  uint uVar18;
  ulong uVar19;
  undefined1 auVar20 [16];
  undefined8 local_100;
  undefined8 uStack_f8;
  undefined8 uStack_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 uStack_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 uStack_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  undefined8 uStack_88;
  undefined4 local_80;
  int local_70 [4];
  
  lVar11 = thunk_FUN_fffffff009c223d4(param_7);
  if (lVar11 != 0) {
    plVar12 = (long *)thunk_FUN_fffffff009c223d4(param_7);
    uVar8 = (**(code **)(*plVar12 + 0xb0))();
    puVar5 = PTR_DAT_fffffff008022248;
    uVar14 = (uint)param_11;
    if ((*(byte *)(param_10 + 0x12) & 1) != 0) {
      local_70[0] = 0;
      local_70[1] = 0;
      plVar12 = thunk_FUN_fffffff009c2e0d0();
      thunk_FUN_fffffff009c2e304((long)plVar12,param_10[1]);
      thunk_FUN_fffffff009c2e2e4((long)plVar12,0);
      thunk_FUN_fffffff009c2e294((long)plVar12,param_8);
      thunk_FUN_fffffff009c2e2a4((long)plVar12,param_9);
      thunk_FUN_fffffff009c2e284((long)plVar12,param_10[0x19]);
      thunk_FUN_fffffff009c2e334((long)plVar12,param_10[2]);
      uVar1 = param_8;
      if (param_8 <= param_9) {
        uVar1 = param_9;
      }
      if (param_10[1] == 0) {
        iVar10 = 0;
        uVar17 = 0;
      }
      else {
        uVar19 = 0;
        uVar17 = 0;
        do {
          iVar2 = (param_10 + 2)[uVar19];
          iVar9 = FUN_fffffff009a7bdb0
                            (param_8,param_9,(long)param_10,uVar19,local_70,(uint *)(local_70 + 1));
          iVar16 = (int)uVar17;
          uVar15 = iVar16 + iVar9;
          uVar17 = (ulong)uVar15;
          if (uVar8 < uVar15 || uVar15 < uVar1) {
            (**(code **)(*plVar12 + 0x28))(plVar12);
            return 0;
          }
          uVar13 = (uint)uVar19;
          thunk_FUN_fffffff009c2e344((long)plVar12,uVar13,param_8);
          thunk_FUN_fffffff009c2e37c((long)plVar12,uVar13,param_9);
          iVar10 = local_70[0];
          thunk_FUN_fffffff009c2e4ac((long)plVar12,uVar13,local_70[0]);
          thunk_FUN_fffffff009c2e430((long)plVar12,uVar13,iVar16);
          thunk_FUN_fffffff009c2e46c((long)plVar12,uVar13,iVar16);
          thunk_FUN_fffffff009c2e524((long)plVar12,uVar13,iVar9);
          uVar15 = param_10[uVar19 + 0x13];
          uVar18 = param_10[uVar19 + 0x16];
          thunk_FUN_fffffff009c2e59c((long)plVar12,uVar13,param_10[0x1a]);
          thunk_FUN_fffffff009c2e614((long)plVar12,uVar13,iVar16);
          thunk_FUN_fffffff009c2e650((long)plVar12,uVar13,local_70[1] + iVar16);
          if (param_10[0x1a] == 3) {
            uVar3 = 0;
            if (uVar15 != 0) {
              uVar3 = ((param_8 - 1) + uVar15 & -uVar15) / uVar15;
            }
            iVar2 = uVar15 * iVar2 * uVar18;
            uVar4 = 0;
            if (uVar18 != 0) {
              uVar4 = ((param_9 - 1) + uVar18 & -uVar18) / uVar18;
            }
            thunk_FUN_fffffff009c2e560((long)plVar12,uVar13,5);
            thunk_FUN_fffffff009c2e68c((long)plVar12,uVar13,uVar15);
            thunk_FUN_fffffff009c2e6c8((long)plVar12,uVar13,uVar18);
            thunk_FUN_fffffff009c2e77c((long)plVar12,uVar13,8);
            thunk_FUN_fffffff009c2e704((long)plVar12,uVar13,uVar3);
            thunk_FUN_fffffff009c2e740((long)plVar12,uVar13,uVar4);
            thunk_FUN_fffffff009c2e7b8((long)plVar12,uVar13,iVar2);
            thunk_FUN_fffffff009c2e334((long)plVar12,iVar2);
            thunk_FUN_fffffff009c2e4e8((long)plVar12,uVar13,iVar2);
            thunk_FUN_fffffff009c2e7f4((long)plVar12,uVar13,iVar10);
          }
          else {
            thunk_FUN_fffffff009c2e4e8((long)plVar12,uVar13,iVar2);
            thunk_FUN_fffffff009c2e560((long)plVar12,uVar13,3);
            uVar15 = 1;
            uVar18 = 1;
          }
          thunk_FUN_fffffff009c2e3b8((long)plVar12,uVar13,uVar15);
          thunk_FUN_fffffff009c2e3f4((long)plVar12,uVar13,uVar18);
          uVar19 = uVar19 + 1;
        } while (uVar19 < (uint)param_10[1]);
      }
      thunk_FUN_fffffff009c2e324((long)plVar12,iVar10);
      uVar19 = uVar17;
      if (uVar14 != 0) {
        bVar6 = false;
        bVar7 = false;
        if (uVar14 < uVar8) {
          bVar7 = (uint)uVar17 <= uVar14;
          bVar6 = uVar14 == (uint)uVar17;
        }
        uVar19 = param_11;
        if (!bVar7 || bVar6) {
          thunk_FUN_fffffff00a9029a0
                    ((byte *)
                     "%s: size_override = %d > max = %d, proceeding with default size = %d\n");
          uVar19 = uVar17;
        }
      }
      auVar20 = thunk_FUN_fffffff009c2e2d4((long)plVar12,(int)uVar19);
      thunk_FUN_fffffff009c29ee4
                (auVar20,param_2,param_3,param_4,param_5,param_6,param_7,(long)plVar12);
      (**(code **)(*plVar12 + 0x28))(plVar12);
      iVar10 = thunk_FUN_fffffff009c22350(param_7);
      if ((iVar10 != 0x52476841) &&
         (iVar10 = thunk_FUN_fffffff009c22350(param_7), iVar10 != 0x26526841)) {
        return uVar19;
      }
      local_80 = 0;
      uStack_98 = 0;
      local_a0 = 0;
      uStack_88 = 0;
      uStack_90 = 0;
      uStack_b8 = 0;
      local_c0 = 0;
      uStack_a8 = 0;
      uStack_b0 = 0;
      uStack_d8 = 0;
      local_e0 = 0;
      uStack_d0 = 0;
      uStack_f8 = 0;
      local_100 = 0;
      uStack_e8 = 0;
      uStack_f0 = 0;
      uStack_c8 = 0xd00000000;
      thunk_FUN_fffffff009c25e38(param_7,&local_100,0x80);
      return uVar19;
    }
    uVar1 = param_10[1];
    if (uVar1 != 0) {
      lVar11 = 0;
      uVar18 = 0;
      uVar15 = 0;
      uVar17 = (ulong)uVar1;
      do {
        uVar13 = param_10[lVar11 + 2] * param_8 + 0x7f & 0xffffff80;
        param_10[lVar11 + 5] = uVar13;
        uVar3 = -1 << (ulong)(*(uint *)puVar5 & 0x1f);
        uVar15 = (uVar3 & (uVar3 - uVar13 * param_9 ^ 0xffffffff)) + uVar15;
        uVar18 = uVar13 + uVar18;
        lVar11 = lVar11 + 1;
        uVar17 = uVar17 - 1;
      } while (uVar17 != 0);
      if ((uVar8 < uVar15) && (param_9 = 0, uVar18 != 0)) {
        param_9 = uVar8 / uVar18;
      }
    }
    for (; param_9 != 0; param_9 = param_9 - 1) {
      if (uVar1 == 0) {
        uVar17 = 0;
LAB_fffffff009a7dc0c:
        uVar19 = uVar17;
        if ((uVar14 != 0) && ((uVar8 <= uVar14 || (uVar19 = param_11, uVar14 <= (uint)uVar17)))) {
          thunk_FUN_fffffff00a9029a0
                    ((byte *)
                     "%s: size_override = %d > max = %d, proceeding with default size = %d\n");
          uVar19 = uVar17;
        }
        plVar12 = thunk_FUN_fffffff009c2e0d0();
        thunk_FUN_fffffff009c2e304((long)plVar12,0);
        thunk_FUN_fffffff009c2e2e4((long)plVar12,0);
        thunk_FUN_fffffff009c2e2d4((long)plVar12,(int)uVar19);
        thunk_FUN_fffffff009c2e284((long)plVar12,*param_10);
        thunk_FUN_fffffff009c2e294((long)plVar12,param_8);
        thunk_FUN_fffffff009c2e2a4((long)plVar12,param_9);
        thunk_FUN_fffffff009c2e324((long)plVar12,param_10[5]);
        auVar20 = thunk_FUN_fffffff009c2e334((long)plVar12,param_10[2]);
        if ((1 < (uint)param_10[1]) &&
           (auVar20 = thunk_FUN_fffffff009c2e304((long)plVar12,param_10[1]), param_10[1] != 0)) {
          uVar17 = 0;
          do {
            uVar8 = (uint)uVar17;
            thunk_FUN_fffffff009c2e344((long)plVar12,uVar8,param_8);
            thunk_FUN_fffffff009c2e37c((long)plVar12,uVar8,param_9);
            thunk_FUN_fffffff009c2e430((long)plVar12,uVar8,param_10[uVar17 + 8]);
            thunk_FUN_fffffff009c2e46c((long)plVar12,uVar8,param_10[uVar17 + 8]);
            thunk_FUN_fffffff009c2e4ac((long)plVar12,uVar8,param_10[uVar17 + 5]);
            thunk_FUN_fffffff009c2e524((long)plVar12,uVar8,param_10[uVar17 + 5] * param_9);
            thunk_FUN_fffffff009c2e4e8((long)plVar12,uVar8,(param_10 + 2)[uVar17]);
            thunk_FUN_fffffff009c2e3b8((long)plVar12,uVar8,1);
            auVar20 = thunk_FUN_fffffff009c2e3f4((long)plVar12,uVar8,1);
            uVar17 = uVar17 + 1;
          } while (uVar17 < (uint)param_10[1]);
        }
        thunk_FUN_fffffff009c29ee4
                  (auVar20,param_2,param_3,param_4,param_5,param_6,param_7,(long)plVar12);
        (**(code **)(*plVar12 + 0x28))(plVar12);
        return uVar19;
      }
      lVar11 = 0;
      uVar17 = 0;
      uVar19 = (ulong)uVar1;
      do {
        param_10[lVar11 + 8] = (int)uVar17;
        uVar15 = -1 << (ulong)(*(uint *)puVar5 & 0x1f);
        uVar15 = (uVar15 & (uVar15 - param_10[lVar11 + 5] * param_9 ^ 0xffffffff)) + (int)uVar17;
        uVar17 = (ulong)uVar15;
        lVar11 = lVar11 + 1;
        uVar19 = uVar19 - 1;
      } while (uVar19 != 0);
      if (uVar15 <= uVar8) goto LAB_fffffff009a7dc0c;
    }
  }
  return 0;
}

