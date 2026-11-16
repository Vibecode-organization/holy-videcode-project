// FUN_fffffff0081b759c @ fffffff0081b759c size=1064

void FUN_fffffff0081b759c(long *param_1)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  long lVar10;
  long lVar11;
  long lVar12;
  long lVar13;
  float fVar14;
  float fVar15;
  undefined8 local_110;
  undefined8 uStack_108;
  undefined8 uStack_100;
  undefined8 uStack_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 uStack_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 uStack_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  undefined8 uStack_88;
  undefined8 local_80;
  
  lVar4 = param_1[0xf2];
  if (lVar4 != 0) {
    uVar1 = *(uint *)param_1[0xf1];
    *(uint *)(param_1 + 0xf3) = uVar1;
    uVar2 = ((uint *)param_1[0xf1])[8];
    *(uint *)((long)param_1 + 0x79c) = uVar2;
    if (((ulong)param_1[0xf5] <= (ulong)uVar1) || ((ulong)param_1[0xf5] <= (ulong)uVar2)) {
      thunk_EXT_FUN_8011000003a49114("AGXk: %s:%d:%s: !!! read_index out of bounds\n");
      return;
    }
    while (lVar4 != 0) {
      if ((int)param_1[0xf3] == *(int *)((long)param_1 + 0x79c)) {
        lVar4 = *(long *)(param_1[0x50] + 0x1ac50);
        uVar3 = (**(code **)(*param_1 + 0x2f8))(param_1);
        thunk_EXT_FUN_80110000039b5574(*(undefined8 *)(lVar4 + 0x58),0x454e45524759,uVar3);
        lVar7 = *(long *)(param_1[0x50] + 0x1ac50);
        lVar4 = param_1[0x58];
        do {
          do {
            uVar1 = *(uint *)(param_1[0x123] + 0x5c4);
            lVar8 = *(long *)(lVar4 + 0x2898);
            lVar9 = *(long *)(lVar4 + 0x28a0);
            lVar10 = *(long *)(lVar4 + 0x28a8);
            lVar11 = *(long *)(lVar4 + 0x28b0);
            lVar12 = *(long *)(lVar4 + 0x28b8);
            lVar13 = *(long *)(lVar4 + 0x28c0);
            lVar6 = *(long *)(lVar4 + 0x28c8);
            lVar5 = *(long *)(lVar4 + 0x28d0);
            fVar15 = *(float *)(lVar4 + 0x28d8);
            fVar14 = *(float *)(lVar4 + 0x28dc);
            DataMemoryBarrier(2,3);
          } while ((uVar1 & 1) != 0);
        } while (uVar1 != *(uint *)(param_1[0x123] + 0x5c4));
        uVar3 = *(undefined8 *)(lVar7 + 0x448);
        thunk_EXT_FUN_80110000039b5664(uVar3,0x4857504900000000,lVar8 - *(long *)(lVar7 + 0x4e8));
        thunk_EXT_FUN_80110000039b5664(uVar3,0x4450450000000000,lVar9 - *(long *)(lVar7 + 0x4f0));
        thunk_EXT_FUN_80110000039b5664(uVar3,0x4d49534300000000,lVar10 - *(long *)(lVar7 + 0x4f8));
        thunk_EXT_FUN_80110000039b5664(uVar3,0x4956444d00000000,lVar11 - *(long *)(lVar7 + 0x500));
        thunk_EXT_FUN_80110000039b5664(uVar3,0x544f54414c000000,lVar12 - *(long *)(lVar7 + 0x508));
        thunk_EXT_FUN_80110000039b5664(uVar3,0x4331505054000000,lVar13 - *(long *)(lVar7 + 0x518));
        thunk_EXT_FUN_80110000039b5664(uVar3,0x4558544153594e43,lVar6 - *(long *)(lVar7 + 0x520));
        thunk_EXT_FUN_80110000039b5664(uVar3,0x5554000000000000,lVar5 - *(long *)(lVar7 + 0x528));
        thunk_EXT_FUN_80110000039b5574(uVar3,0x4956444d5f4d494e,(long)fVar15);
        thunk_EXT_FUN_80110000039b5574(uVar3,0x4956444d5f4d4158,(long)fVar14);
        *(long *)(lVar7 + 0x4e8) = lVar8;
        *(long *)(lVar7 + 0x4f0) = lVar9;
        *(long *)(lVar7 + 0x4f8) = lVar10;
        *(long *)(lVar7 + 0x500) = lVar11;
        *(long *)(lVar7 + 0x508) = lVar12;
        *(long *)(lVar7 + 0x518) = lVar13;
        *(long *)(lVar7 + 0x520) = lVar6;
        *(long *)(lVar7 + 0x528) = lVar5;
        lVar4 = *(long *)(param_1[0x50] + 0x1ac50);
        lVar7 = param_1[0x58];
        lVar5 = param_1[0x123];
        do {
          do {
            uVar1 = *(uint *)(lVar5 + 0x5c4);
            thunk_EXT_FUN_8011000003a61b10(&DAT_fffffff00ae23f78,lVar7 + 0xbff,0x1600);
            DataMemoryBarrier(2,3);
          } while ((uVar1 & 1) != 0);
        } while (uVar1 != *(uint *)(lVar5 + 0x5c4));
        lVar7 = 0;
        do {
          lVar5 = 0;
          do {
            thunk_EXT_FUN_80110000039b8ec8
                      (*(undefined8 *)(lVar4 + 0x460 + lVar7 * 8),lVar5,
                       (&DAT_fffffff00ae23f78)[lVar7 * 0x20 + lVar5],
                       (long)(short)(&DAT_fffffff00ae24f78)[lVar7 * 0x20 + lVar5],
                       (&DAT_fffffff00ae25378)[lVar5 + lVar7 * 0x20],
                       (&DAT_fffffff00ae23f78)[lVar7 * 0x20 + lVar5] * lVar5);
            lVar5 = lVar5 + 1;
          } while (lVar5 != 0x20);
          lVar7 = lVar7 + 1;
        } while (lVar7 != 0x10);
        thunk_EXT_FUN_80110000039b5574
                  (*(undefined8 *)(*(long *)(param_1[0x50] + 0x1ac50) + 0x4e0),0x5057524142525453,
                   *(undefined4 *)(param_1[0x58] + 0x6c11));
        return;
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
      FUN_fffffff0081b7c6c(param_1 + 0xf0,&local_c0);
      uStack_e8 = uStack_98;
      local_f0 = local_a0;
      uStack_d8 = uStack_88;
      uStack_e0 = uStack_90;
      local_d0 = local_80;
      uStack_108 = uStack_b8;
      local_110 = local_c0;
      uStack_f8 = uStack_a8;
      uStack_100 = uStack_b0;
      FUN_fffffff008209548(*(undefined8 *)(param_1[0x50] + 0x1ac50),&local_110);
      lVar4 = param_1[0xf2];
    }
  }
  thunk_EXT_FUN_8011000003a49114("AGXk: %s:%d:%s: !!! Using uninitialized validator class\n");
  return;
}

