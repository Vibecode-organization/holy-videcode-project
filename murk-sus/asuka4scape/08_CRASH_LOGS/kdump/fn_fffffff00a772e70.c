// FUN_fffffff00a772e70 @ fffffff00a772e70 size=1180
// CALLERS:
//   fffffff00afbcf44 ?
//   fffffff007c221a8 ?
//   fffffff00a7755b0 FUN_fffffff00a775598@fffffff00a775598
// CALLS:
//   fffffff00aa35868 FUN_fffffff00aa35868
//   fffffff00a77330c FUN_fffffff00a77330c
//   fffffff00a29762c FUN_fffffff00a29762c
//   fffffff00aa5cec8 FUN_fffffff00aa5cec8
//   fffffff00a6ef66c FUN_fffffff00a6ef66c
//   fffffff00a6ed5a4 FUN_fffffff00a6ed5a4
//   fffffff00a6efe14 FUN_fffffff00a6efe14
//   fffffff00a2261c0 FUN_fffffff00a2261c0
//   fffffff00a29b24c FUN_fffffff00a29b24c
//   fffffff00a226e08 FUN_fffffff00a226e08
//   fffffff00a2262d4 FUN_fffffff00a2262d4
//   fffffff00aa3564c FUN_fffffff00aa3564c
//   fffffff00a773404 FUN_fffffff00a773404
//   fffffff00a2216c4 FUN_fffffff00a2216c4
//   fffffff00a6ef358 FUN_fffffff00a6ef358
//   fffffff00aa61ed0 FUN_fffffff00aa61ed0

ulong FUN_fffffff00a772e70
                (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
                undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,
                undefined ******param_7,long param_8,undefined ********param_9,undefined8 param_10,
                undefined *param_11)

{
  undefined *****pppppuVar1;
  undefined *****pppppuVar2;
  uint uVar3;
  ulong uVar4;
  long lVar5;
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
  ushort uVar17;
  int iVar18;
  ulong uVar19;
  uint *puVar20;
  undefined *******pppppppuVar21;
  undefined8 extraout_x1;
  undefined8 extraout_x1_00;
  undefined8 uVar22;
  undefined8 extraout_x1_01;
  undefined ********ppppppppuVar23;
  undefined *******pppppppuVar24;
  undefined *******pppppppuVar25;
  undefined ********ppppppppuVar26;
  undefined ********ppppppppuVar27;
  undefined *******pppppppuVar28;
  undefined ******ppppppuVar29;
  uint in_wzr;
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 extraout_q0_01 [16];
  undefined1 extraout_q0_02 [16];
  undefined1 auVar30 [16];
  undefined1 extraout_q0_03 [16];
  undefined1 extraout_q0_04 [16];
  undefined4 uVar31;
  undefined1 auVar32 [12];
  undefined4 uVar33;
  undefined1 auVar34 [12];
  undefined *******local_70;
  undefined *******local_68;
  
  uVar33 = param_4._0_4_;
  auVar34 = param_4._4_12_;
  uVar31 = param_3._0_4_;
  auVar32 = param_3._4_12_;
  ppppppppuVar26 = &local_70;
  if ((*(uint *)(param_8 + 8) & 0xf6fffffb) == 0) {
    local_70 = (undefined *******)0x0;
    local_68 = (undefined *******)0x0;
    ppppppppuVar23 = param_9;
    puVar20 = (uint *)FUN_fffffff00a2216c4((undefined8 *)&DAT_fffffff007c79010,0x8004);
    lVar5 = DAT_fffffff00ad169d8 + 1;
    *(long *)(puVar20 + 0x58) = DAT_fffffff00ad169d8;
    DAT_fffffff00ad169d8 = lVar5;
    uVar3 = DAT_fffffff00ad247f0;
    *puVar20 = DAT_fffffff00ad247f0 & 0xffffff | 0x22000000;
    puVar20[1] = 0;
    puVar20[2] = 0;
    puVar20[3] = 0;
    DAT_fffffff00ad247fc = DAT_fffffff00ad247fc + 1;
    if (((int)uVar3 < 0) &&
       (iVar18 = DAT_fffffff00ad247ec + 1, uVar3 = DAT_fffffff00ad247ec + 0xf0000001,
       DAT_fffffff00ad247ec = iVar18, uVar3 < 0xf0000002)) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa61ed0((uint *)&DAT_fffffff00ad247ec);
    }
    pppppuVar1 = (undefined *****)(puVar20 + 4);
    *(uint **)(puVar20 + 0x1e) = puVar20;
    *(uint **)(puVar20 + 0x48) = puVar20;
    uVar3 = puVar20[7];
    uVar19 = 2;
    if (uVar3 < 0x400) {
      uVar19 = (ulong)(0x1ff < uVar3);
    }
    uVar4 = 3;
    if (uVar3 < 0x800) {
      uVar4 = uVar19;
    }
    uVar19 = 4;
    if (uVar3 < 0x1000) {
      uVar19 = uVar4;
    }
    uVar4 = 5;
    if (uVar3 >> 0xd == 0) {
      uVar4 = uVar19;
    }
    uVar19 = 6;
    if (uVar3 >> 0xe == 0) {
      uVar19 = uVar4;
    }
    auVar30._4_12_ = auVar32;
    auVar30._0_4_ = uVar31;
    auVar11._4_12_ = auVar34;
    auVar11._0_4_ = uVar33;
    uVar19 = FUN_fffffff00a77330c
                       (extraout_q0,param_2,auVar30,auVar11,param_5,param_6,pppppuVar1,
                        *(uint *)(&DAT_fffffff007028144 + uVar19 * 4),ppppppppuVar23,param_10,
                        param_11);
    if ((int)uVar19 == 0) {
      pppppppuVar21 = (undefined *******)FUN_fffffff00a29b24c();
      if ((param_7 != (undefined ******)0x0) && (pppppppuVar21[3] != param_7)) {
        auVar6._4_12_ = auVar32;
        auVar6._0_4_ = uVar31;
        auVar12._4_12_ = auVar34;
        auVar12._0_4_ = uVar33;
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa5cec8(extraout_q0_00,param_2,auVar6,auVar12,param_5,param_6);
      }
      pppppuVar2 = (undefined *****)(puVar20 + 0x2e);
      ppppppuVar29 = pppppppuVar21[2];
      ppppppppuVar23 = &local_68;
      auVar7._4_12_ = auVar32;
      auVar7._0_4_ = uVar31;
      pppppppuVar24 = pppppppuVar21;
      ppppppppuVar27 = param_9;
      auVar13._4_12_ = auVar34;
      auVar13._0_4_ = uVar33;
      uVar19 = FUN_fffffff00a6ef358
                         (extraout_q0_00,param_2,auVar7,auVar13,param_5,param_6,(long)param_7,
                          ppppppuVar29,(long)pppppppuVar21,ppppppppuVar23,param_9,(undefined *)0x0,0
                         );
      pppppppuVar25 = local_68;
      uVar22 = extraout_x1;
      auVar30 = extraout_q0_01;
      if ((int)uVar19 == 0) {
        pppppppuVar24 = local_68 + 2;
        *(undefined4 *)(*pppppppuVar24 + 2) = 1;
        (*pppppppuVar24)[5] = (undefined *****)&DAT_fffffff007c15548;
        (*pppppppuVar24)[7] = pppppuVar1;
        ppppppppuVar27 = (undefined ********)((long)param_9 + 4);
        auVar8._4_12_ = auVar32;
        auVar8._0_4_ = uVar31;
        auVar14._4_12_ = auVar34;
        auVar14._0_4_ = uVar33;
        uVar19 = FUN_fffffff00a6ef358
                           (extraout_q0_01,param_2,auVar8,auVar14,param_5,param_6,(long)param_7,
                            ppppppuVar29,(long)pppppppuVar21,&local_70,ppppppppuVar27,
                            (undefined *)0x0,0);
        if ((int)uVar19 == 0) {
          pppppppuVar28 = local_70 + 2;
          *(undefined4 *)(*pppppppuVar28 + 2) = 2;
          (*pppppppuVar28)[5] = (undefined *****)&DAT_fffffff007c15548;
          (*pppppppuVar28)[7] = pppppuVar2;
          uVar17 = (ushort)((uint)*(undefined4 *)(param_8 + 8) >> 0x1a) & 2 |
                   (byte)((uint)*(undefined4 *)(param_8 + 8) >> 0x18) & 1;
          *(ushort *)(pppppppuVar25 + 1) = *(ushort *)(pppppppuVar25 + 1) | uVar17;
          *(ushort *)(local_70 + 1) = *(ushort *)(local_70 + 1) | uVar17;
          if ((*(byte *)(param_8 + 8) >> 2 & 1) != 0) {
            *(uint *)(*pppppppuVar24 + 2) = *(uint *)(*pppppppuVar24 + 2) | 4;
            *(uint *)(*pppppppuVar28 + 2) = *(uint *)(*pppppppuVar28 + 2) | 4;
          }
          *(undefined ******)(puVar20 + 0x1a) = pppppuVar2;
          *(undefined ******)(puVar20 + 0x44) = pppppuVar1;
          FUN_fffffff00aa3564c((long)pppppuVar1);
          auVar30 = FUN_fffffff00aa35868(pppppppuVar21[1],(long)pppppuVar1);
          *(undefined8 *)(puVar20 + 0x56) = *(undefined8 *)(puVar20 + 0x2c);
          lVar5 = tpidr_el1;
          *(int *)(lVar5 + 0x1c0) = *(int *)(lVar5 + 0x1c0) + 1;
          ppppppuVar29 = param_7 + 0x1b;
          if (*ppppppuVar29 == (undefined *****)0x0) {
            *ppppppuVar29 = (undefined *****)((ulong)*(uint *)(lVar5 + 0x4e8) | 0x30000000);
          }
          else {
            auVar30 = FUN_fffffff00a2262d4((ulong)(param_7 + 0x1a),lVar5,(undefined **)0x1);
          }
          FUN_fffffff00a6ed5a4
                    (auVar30,param_2,uVar31,uVar33,param_5,param_6,(ulong)param_7,*(int *)param_9,0)
          ;
          FUN_fffffff00a6ed5a4
                    (extraout_q0_04,param_2,uVar31,uVar33,param_5,param_6,(ulong)param_7,
                     *(int *)((long)param_9 + 4),0);
          FUN_fffffff00a6efe14((long)param_7,*(uint *)param_9,(int *)local_68,1);
          FUN_fffffff00a6efe14((long)param_7,*(uint *)((long)param_9 + 4),(int *)local_70,1);
          if (*(uint *)ppppppuVar29 != *(uint *)(lVar5 + 0x4e8)) {
            FUN_fffffff00a226e08((ulong)(param_7 + 0x1a),lVar5,*(uint *)ppppppuVar29);
            return 0;
          }
          *(uint *)ppppppuVar29 = in_wzr;
          return 0;
        }
        auVar30 = FUN_fffffff00a6ef66c
                            (extraout_q0_02,param_2,uVar31,uVar33,param_5,param_6,(long)param_7,
                             (ulong)*(uint *)param_9,(int *)pppppppuVar25,(ulong *)ppppppppuVar26,
                             ppppppppuVar27);
        uVar22 = extraout_x1_00;
        pppppppuVar24 = pppppppuVar25;
        ppppppppuVar23 = ppppppppuVar26;
      }
      auVar9._4_12_ = auVar32;
      auVar9._0_4_ = uVar31;
      auVar15._4_12_ = auVar34;
      auVar15._0_4_ = uVar33;
      FUN_fffffff00a773404
                (auVar30,param_2,auVar9,auVar15,param_5,param_6,(uint *)pppppuVar1,uVar22,
                 pppppppuVar24,ppppppppuVar23,(undefined *)ppppppppuVar27);
      auVar10._4_12_ = auVar32;
      auVar10._0_4_ = uVar31;
      auVar16._4_12_ = auVar34;
      auVar16._0_4_ = uVar33;
      FUN_fffffff00a773404
                (extraout_q0_03,param_2,auVar10,auVar16,param_5,param_6,(uint *)pppppuVar2,
                 extraout_x1_01,pppppppuVar24,ppppppppuVar23,(undefined *)ppppppppuVar27);
    }
    else {
      FUN_fffffff00a2261c0(puVar20,&DAT_fffffff00ad247ec);
      FUN_fffffff00a29762c((undefined8 *)&DAT_fffffff007c79010,(undefined8 *)puVar20);
    }
  }
  else {
    uVar19 = 0x16;
  }
  return uVar19;
}

