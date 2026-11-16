// FUN_fffffff009ab0f98 @ fffffff009ab0f98 size=1168
// CALLERS:
//   fffffff00afe8a4b no-fn
//   fffffff009ab0da4 FUN_fffffff009ab0cdc@fffffff009ab0cdc
//   fffffff009ab48f4 FUN_fffffff009ab4738@fffffff009ab4738
// CALLEES:
//   fffffff009abd83c thunk_FUN_fffffff009c29ee4
//   fffffff009abd5ac thunk_FUN_fffffff009c2e614
//   fffffff009abd4ec thunk_FUN_fffffff009c2e324
//   fffffff009abd57c thunk_FUN_fffffff009c2e3f4
//   fffffff009abd5cc thunk_FUN_fffffff009c2e294
//   fffffff009abd53c thunk_FUN_fffffff009c2e4ac
//   fffffff009abd50c thunk_FUN_fffffff009c2e37c
//   fffffff009abd5dc thunk_FUN_fffffff009c2e2a4
//   fffffff009abd59c thunk_FUN_fffffff009c2e59c
//   fffffff009abd4dc thunk_FUN_fffffff009c2e344
//   fffffff009abd4ac thunk_FUN_fffffff009c2e430
//   fffffff009abd4fc thunk_FUN_fffffff009c2e284
//   fffffff009abd48c thunk_FUN_fffffff009c2e2e4
//   fffffff009abd58c thunk_FUN_fffffff009c2e4e8
//   fffffff009abd95c thunk_FUN_fffffff009c22350
//   fffffff009abd55c thunk_FUN_fffffff009c2e3b8
//   fffffff009abd52c thunk_FUN_fffffff009c2e334
//   fffffff009ab45ec FUN_fffffff009ab45ec
//   fffffff009abd54c thunk_FUN_fffffff009c2e0d0
//   fffffff009abd80c thunk_FUN_fffffff009c25e38
//   fffffff009abd5bc thunk_FUN_fffffff009c2e650
//   fffffff009abd56c thunk_FUN_fffffff009c2e560
//   fffffff009abd51c thunk_FUN_fffffff009c2e46c
//   fffffff009abd49c thunk_FUN_fffffff009c2e2d4
//   fffffff009abd9ac thunk_FUN_fffffff009c223d4
//   fffffff009abd4cc thunk_FUN_fffffff009c2e304
//   fffffff009abd4bc thunk_FUN_fffffff009c2e524

ulong FUN_fffffff009ab0f98
                (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
                undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
                ulong param_8,uint param_9,undefined4 *param_10)

{
  uint uVar1;
  uint uVar2;
  undefined *puVar3;
  uint uVar4;
  int iVar5;
  long *plVar6;
  ulong uVar7;
  uint uVar8;
  long lVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  ulong uVar13;
  undefined1 auVar14 [16];
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
  undefined4 local_70;
  int local_68;
  uint local_64;
  
  plVar6 = (long *)thunk_FUN_fffffff009c223d4(param_7);
  uVar4 = (**(code **)(*plVar6 + 0xb0))();
  puVar3 = PTR_DAT_fffffff00802a388;
  uVar12 = (uint)param_8;
  if ((*(byte *)(param_10 + 0x12) & 1) == 0) {
    uVar11 = param_10[1];
    if (uVar11 != 0) {
      lVar9 = 0;
      uVar8 = 0;
      uVar10 = 0;
      uVar7 = (ulong)uVar11;
      do {
        uVar1 = param_10[lVar9 + 2] * uVar12 + 0x7f & 0xffffff80;
        param_10[lVar9 + 5] = uVar1;
        uVar2 = -1 << (ulong)(*(uint *)puVar3 & 0x1f);
        uVar10 = (uVar2 & (uVar2 - uVar1 * param_9 ^ 0xffffffff)) + uVar10;
        uVar8 = uVar1 + uVar8;
        lVar9 = lVar9 + 1;
        uVar7 = uVar7 - 1;
      } while (uVar7 != 0);
      if ((uVar4 < uVar10) && (param_9 = 0, uVar8 != 0)) {
        param_9 = uVar4 / uVar8;
      }
    }
    for (; param_9 != 0; param_9 = param_9 - 1) {
      if (uVar11 == 0) {
        uVar7 = 0;
LAB_fffffff009ab12ac:
        plVar6 = thunk_FUN_fffffff009c2e0d0();
        thunk_FUN_fffffff009c2e304((long)plVar6,0);
        thunk_FUN_fffffff009c2e2e4((long)plVar6,0);
        thunk_FUN_fffffff009c2e2d4((long)plVar6,(int)uVar7);
        thunk_FUN_fffffff009c2e284((long)plVar6,*param_10);
        thunk_FUN_fffffff009c2e294((long)plVar6,uVar12);
        thunk_FUN_fffffff009c2e2a4((long)plVar6,param_9);
        thunk_FUN_fffffff009c2e324((long)plVar6,param_10[5]);
        auVar14 = thunk_FUN_fffffff009c2e334((long)plVar6,param_10[2]);
        if ((1 < (uint)param_10[1]) &&
           (auVar14 = thunk_FUN_fffffff009c2e304((long)plVar6,param_10[1]), param_10[1] != 0)) {
          uVar13 = 0;
          do {
            uVar4 = (uint)uVar13;
            thunk_FUN_fffffff009c2e344((long)plVar6,uVar4,uVar12);
            thunk_FUN_fffffff009c2e37c((long)plVar6,uVar4,param_9);
            thunk_FUN_fffffff009c2e430((long)plVar6,uVar4,param_10[uVar13 + 8]);
            thunk_FUN_fffffff009c2e46c((long)plVar6,uVar4,param_10[uVar13 + 8]);
            thunk_FUN_fffffff009c2e4ac((long)plVar6,uVar4,param_10[uVar13 + 5]);
            thunk_FUN_fffffff009c2e524((long)plVar6,uVar4,param_10[uVar13 + 5] * param_9);
            thunk_FUN_fffffff009c2e4e8((long)plVar6,uVar4,(param_10 + 2)[uVar13]);
            thunk_FUN_fffffff009c2e3b8((long)plVar6,uVar4,1);
            auVar14 = thunk_FUN_fffffff009c2e3f4((long)plVar6,uVar4,1);
            uVar13 = uVar13 + 1;
          } while (uVar13 < (uint)param_10[1]);
        }
        thunk_FUN_fffffff009c29ee4
                  (auVar14,param_2,param_3,param_4,param_5,param_6,param_7,(long)plVar6);
        (**(code **)(*plVar6 + 0x28))(plVar6);
        return uVar7;
      }
      lVar9 = 0;
      uVar7 = 0;
      uVar13 = (ulong)uVar11;
      do {
        param_10[lVar9 + 8] = (int)uVar7;
        uVar10 = -1 << (ulong)(*(uint *)puVar3 & 0x1f);
        uVar10 = (uVar10 & (uVar10 - param_10[lVar9 + 5] * param_9 ^ 0xffffffff)) + (int)uVar7;
        uVar7 = (ulong)uVar10;
        lVar9 = lVar9 + 1;
        uVar13 = uVar13 - 1;
      } while (uVar13 != 0);
      if (uVar10 <= uVar4) goto LAB_fffffff009ab12ac;
    }
  }
  else {
    local_68 = -0x55555556;
    local_64 = 0xaaaaaaaa;
    uVar7 = FUN_fffffff009ab45ec(param_8,param_9,(long)param_10,&local_68,&local_64);
    uVar11 = (uint)uVar7;
    if ((uVar11 <= uVar4 && uVar12 <= uVar11) && param_9 <= uVar11) {
      plVar6 = thunk_FUN_fffffff009c2e0d0();
      thunk_FUN_fffffff009c2e304((long)plVar6,1);
      thunk_FUN_fffffff009c2e2e4((long)plVar6,0);
      thunk_FUN_fffffff009c2e2d4((long)plVar6,uVar11);
      thunk_FUN_fffffff009c2e294((long)plVar6,uVar12);
      thunk_FUN_fffffff009c2e2a4((long)plVar6,param_9);
      iVar5 = local_68;
      thunk_FUN_fffffff009c2e324((long)plVar6,local_68);
      thunk_FUN_fffffff009c2e334((long)plVar6,param_10[2]);
      thunk_FUN_fffffff009c2e284((long)plVar6,param_10[0x13]);
      thunk_FUN_fffffff009c2e344((long)plVar6,0,uVar12);
      thunk_FUN_fffffff009c2e37c((long)plVar6,0,param_9);
      thunk_FUN_fffffff009c2e430((long)plVar6,0,0);
      thunk_FUN_fffffff009c2e46c((long)plVar6,0,0);
      thunk_FUN_fffffff009c2e4ac((long)plVar6,0,iVar5);
      thunk_FUN_fffffff009c2e524((long)plVar6,0,uVar11);
      thunk_FUN_fffffff009c2e560((long)plVar6,0,3);
      thunk_FUN_fffffff009c2e4e8((long)plVar6,0,param_10[2]);
      thunk_FUN_fffffff009c2e59c((long)plVar6,0,2);
      thunk_FUN_fffffff009c2e614((long)plVar6,0,0);
      auVar14 = thunk_FUN_fffffff009c2e650((long)plVar6,0,local_64);
      thunk_FUN_fffffff009c29ee4
                (auVar14,param_2,param_3,param_4,param_5,param_6,param_7,(long)plVar6);
      (**(code **)(*plVar6 + 0x28))(plVar6);
      iVar5 = thunk_FUN_fffffff009c22350(param_7);
      if ((iVar5 != 0x52476841) &&
         (iVar5 = thunk_FUN_fffffff009c22350(param_7), iVar5 != 0x26526841)) {
        return uVar7;
      }
      local_70 = 0;
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
      uStack_c0 = 0;
      uStack_e8 = 0;
      local_f0 = 0;
      uStack_d8 = 0;
      uStack_e0 = 0;
      uStack_b8 = 0xd00000000;
      thunk_FUN_fffffff009c25e38(param_7,&local_f0,0x80);
      return uVar7;
    }
  }
  return 0;
}

