// FUN_fffffff00a2d5330 @ fffffff00a2d5330 size=8812

/* WARNING: Removing unreachable block (ram,0xfffffff00a2d5b34) */
/* WARNING: Removing unreachable block (ram,0xfffffff00a2d7138) */
/* WARNING: Removing unreachable block (ram,0xfffffff00a2d5bf4) */
/* WARNING: Removing unreachable block (ram,0xfffffff00a2d6fe0) */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 *
FUN_fffffff00a2d5330
          (undefined4 *param_1,ulong param_2,uint param_3,int param_4,int param_5,uint *param_6,
          undefined8 *param_7,undefined8 *param_8,int *param_9,undefined4 *param_10,int param_11,
          int *param_12,undefined8 *param_13)

{
  long *plVar1;
  ulong *puVar2;
  ushort uVar3;
  long *plVar4;
  uint uVar5;
  ushort uVar6;
  long lVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  long lVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  undefined4 *puVar16;
  undefined4 *puVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  byte bVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  ulong uVar24;
  undefined4 *puVar25;
  undefined4 *puVar26;
  byte bVar27;
  undefined4 in_wzr;
  undefined1 auVar28 [16];
  undefined8 local_130;
  int local_124;
  ulong local_100;
  int local_e8;
  uint local_dc;
  undefined4 *local_c8;
  ulong local_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  int local_80;
  int local_7c;
  long local_78;
  undefined4 *local_70 [2];
  
  local_c8 = (undefined4 *)0x0;
  local_130 = 0;
  local_124 = 0;
  bVar10 = false;
  iVar15 = *param_12;
  lVar7 = tpidr_el1;
  uVar3 = *(ushort *)(lVar7 + 200) & 3;
  local_e8 = 4;
  local_78 = 0;
  local_70[0] = (undefined4 *)0x0;
  *(ushort *)(lVar7 + 200) = *(ushort *)(lVar7 + 200) & 0xfffc | (ushort)iVar15 & 3;
  puVar16 = param_1;
  puVar17 = param_1;
  local_dc = param_3;
  local_b8 = param_2;
LAB_fffffff00a2d53d4:
  uVar24 = local_b8 & 0xffffffffffffc000;
  do {
    uVar23 = puVar17[0x1d];
    if ((uVar23 >> 0xf & 1) == 0) {
      FUN_fffffff00a2d759c(puVar17,local_c8);
      *(ushort *)(lVar7 + 200) = *(ushort *)(lVar7 + 200) & 0xfffc | uVar3;
      if (lVar7 == 0) {
        uVar18 = 0;
      }
      else {
        uVar18 = *(undefined8 *)(lVar7 + 0x4e0);
      }
      uVar24 = 0x1000040;
      goto LAB_fffffff00a2d6040;
    }
    uVar21 = puVar17[0x2a];
    if ((uVar21 >> 6 & 1) == 0) {
      if (param_5 != 1) goto LAB_fffffff00a2d55bc;
      param_5 = 0;
      puVar26 = (undefined4 *)*param_7;
    }
    else {
      lVar12 = (ulong)(uint)puVar17[0x1c] + 1;
      puVar17[0x1c] = (int)lVar12;
      if (lVar12 != lVar12 * 0x80000000 >> 0x1f) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa4d114("vm_object_activity_begin(%p): overflow\n @%s:%d");
      }
      uVar6 = *(ushort *)(puVar17 + 0x1b);
      uVar22 = uVar6 - 1;
      *(short *)(puVar17 + 0x1b) = (short)uVar22;
      if (0xffff < uVar22) goto LAB_fffffff00a2d7468;
      uVar22 = uVar22 & 0xffff;
      if (((uVar23 >> 0xc & 1) == 0) &&
         ((((uint)((uint)uVar6 == (uint)DAT_fffffff007bccab0) & uVar21 >> 8) != 0 ||
          (DAT_fffffff007bccab2 == uVar6)))) {
        if ((uVar23 >> 6 & 1) != 0) {
          plVar1 = (long *)(_DAT_fffffff00ad0e458 + (ulong)*(ushort *)(lVar7 + 0x1b0) * 0x4000);
          lVar12 = *plVar1;
          *plVar1 = lVar12 + 1;
          FUN_fffffff00a24a024(lVar12,(long)puVar17 + 6,0,0);
          uVar23 = puVar17[0x1d];
          uVar22 = (uint)*(ushort *)(puVar17 + 0x1b);
        }
        uVar23 = uVar23 & 0xffffffbf;
        puVar17[0x1d] = uVar23;
      }
      if (uVar22 == 0) {
        if ((uVar23 >> 5 & 1) != 0) {
          FUN_fffffff00a24a024((long)puVar17 + 5,0,0);
          uVar23 = puVar17[0x1d];
        }
        uVar22 = uVar23 & 0xffffffdf;
        puVar17[0x1d] = uVar22;
        if (puVar17[0x1c] == 0) {
          if ((uVar23 >> 2 & 1) != 0) {
            FUN_fffffff00a24a024((long)puVar17 + 2,0,0);
            uVar22 = puVar17[0x1d];
          }
          puVar17[0x1d] = uVar22 & 0xfffffffb;
        }
      }
      if ((param_13 != (undefined8 *)0x0) && ((*(byte *)(param_13 + 5) >> 5 & 1) != 0)) {
        FUN_fffffff00a2d3670(param_13[2],&DAT_fffffff00ad18850,6,*param_13,param_13[1]);
      }
      while ((*(byte *)(puVar17 + 0x2a) >> 6 & 1) != 0) {
        *(undefined1 *)(lVar7 + 0x55d) = 0x1b;
        puVar17[0x1d] = puVar17[0x1d] | 0x10;
        auVar28 = FUN_fffffff00a275a88(lVar7);
        FUN_fffffff00a304c14(puVar17 + 2,4,puVar17 + 1,0);
        FUN_fffffff00a275b3c(lVar7,auVar28._0_8_,auVar28._8_8_);
      }
      DAT_fffffff00ad45f90 = DAT_fffffff00ad45f90 + 1;
      uVar6 = *(ushort *)(puVar17 + 0x1b);
      *(short *)(puVar17 + 0x1b) = (short)(uVar6 + 1);
      if (uVar6 + 1 >> 0x10 != 0) goto LAB_fffffff00a2d7448;
      iVar14 = puVar17[0x1c];
      puVar17[0x1c] = iVar14 + -1;
      if (iVar14 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa4d114("vm_object_activity_end(%p): underflow\n @%s:%d");
      }
      param_5 = 0;
LAB_fffffff00a2d55bc:
      puVar26 = (undefined4 *)FUN_fffffff00a32bd34(puVar17,uVar24);
      puVar16 = puVar26;
    }
    local_100 = param_2;
    if (puVar26 == (undefined4 *)0x0) {
      uVar23 = uVar21 >> 1 & 0x10000;
      if (param_4 != 0) {
        puVar26 = (undefined4 *)0x0;
        if ((param_3 == 0) && (puVar17 == &DAT_fffffff00adbb300)) {
          FUN_fffffff00a2d759c(&DAT_fffffff00adbb300,local_c8);
          *(ushort *)(lVar7 + 200) = *(ushort *)(lVar7 + 200) & 0xfffc | uVar3;
          return (undefined4 *)0x5;
        }
LAB_fffffff00a2d5994:
        if (puVar17 != param_1) {
          puVar26 = local_c8;
        }
        puVar25 = *(undefined4 **)(puVar17 + 0x12);
        if (puVar25 != (undefined4 *)0x0) {
          if ((param_4 != 0) || (puVar17 != param_1)) {
            uVar6 = *(ushort *)(puVar17 + 0x1b);
            uVar23 = uVar6 - 1;
            *(short *)(puVar17 + 0x1b) = (short)uVar23;
            if (0xffff < uVar23) goto LAB_fffffff00a2d7468;
            uVar23 = uVar23 & 0xffff;
            uVar21 = puVar17[0x1d];
            if (((uVar21 >> 0xc & 1) == 0) &&
               (((*(byte *)((long)puVar17 + 0xa9) & (uint)uVar6 == (uint)DAT_fffffff007bccab0) != 0
                || (DAT_fffffff007bccab2 == uVar6)))) {
              if ((uVar21 >> 6 & 1) != 0) {
                plVar1 = (long *)(_DAT_fffffff00ad0e458 + (ulong)*(ushort *)(lVar7 + 0x1b0) * 0x4000
                                 );
                lVar12 = *plVar1;
                *plVar1 = lVar12 + 1;
                FUN_fffffff00a24a024(lVar12,(long)puVar17 + 6,0,0);
                uVar21 = puVar17[0x1d];
                uVar23 = (uint)*(ushort *)(puVar17 + 0x1b);
              }
              uVar21 = uVar21 & 0xffffffbf;
              puVar17[0x1d] = uVar21;
            }
            if (uVar23 == 0) {
              if ((uVar21 >> 5 & 1) != 0) {
                FUN_fffffff00a24a024((long)puVar17 + 5,0,0);
                uVar21 = puVar17[0x1d];
              }
              uVar23 = uVar21 & 0xffffffdf;
              puVar17[0x1d] = uVar23;
              if (puVar17[0x1c] == 0) {
                if ((uVar21 >> 2 & 1) != 0) {
                  FUN_fffffff00a24a024((long)puVar17 + 2,0,0);
                  uVar23 = puVar17[0x1d];
                }
                puVar17[0x1d] = uVar23 & 0xfffffffb;
              }
            }
          }
          lVar12 = *(long *)(puVar17 + 0x16);
          *(long *)(param_12 + 6) = *(long *)(param_12 + 6) + lVar12;
          *(long *)(param_12 + 8) = *(long *)(param_12 + 8) + *(long *)(puVar17 + 0x16);
          FUN_fffffff00a3061bc(puVar25);
          puVar16 = (undefined4 *)FUN_fffffff00a22aeac(puVar17 + 2);
          uVar23 = *(ushort *)(puVar25 + 0x1b) + 1;
          *(short *)(puVar25 + 0x1b) = (short)uVar23;
          local_c8 = puVar26;
          goto joined_r0xfffffff00a2d5ae4;
        }
        if (puVar17 != param_1) {
          uVar6 = *(ushort *)(puVar17 + 0x1b);
          uVar21 = uVar6 - 1;
          *(short *)(puVar17 + 0x1b) = (short)uVar21;
          if (0xffff < uVar21) goto LAB_fffffff00a2d7468;
          uVar21 = uVar21 & 0xffff;
          if (((*(byte *)((long)puVar17 + 0x75) >> 4 & 1) == 0) &&
             (((*(byte *)((long)puVar17 + 0xa9) & (uint)uVar6 == (uint)DAT_fffffff007bccab0) != 0 ||
              (DAT_fffffff007bccab2 == uVar6)))) {
            FUN_fffffff00a30c550(puVar17,6);
            uVar21 = (uint)*(ushort *)(puVar17 + 0x1b);
          }
          if ((uVar21 == 0) && (FUN_fffffff00a30c550(puVar17,5), puVar17[0x1c] == 0)) {
            FUN_fffffff00a30c550(puVar17,2);
          }
          FUN_fffffff00a22aeac(puVar17 + 2);
          FUN_fffffff00a3061bc(param_1);
          puVar17 = param_1;
          local_b8 = param_2;
        }
        puVar16 = (undefined4 *)FUN_fffffff00a2d803c(puVar17,puVar26,0,uVar3,param_9 == (int *)0x0);
        if ((int)puVar16 != 0) {
          return puVar16;
        }
        if (puVar26 == (undefined4 *)0x0) {
          uVar21 = 0x10;
          if (param_11 != 0) {
            uVar21 = 0;
          }
          puVar26 = (undefined4 *)FUN_fffffff00a32cd9c(uVar23 | uVar21);
          if (puVar26 == (undefined4 *)0x0) {
            local_c8 = (undefined4 *)0x0;
            goto LAB_fffffff00a2d70e0;
          }
          puVar16 = (undefined4 *)
                    FUN_fffffff00a3297a4(puVar26,puVar17,local_b8 & 0xffffffffffffc000,0,0,0);
LAB_fffffff00a2d64b8:
          bVar27 = 0;
          if (param_11 == 1) {
            bVar27 = *(byte *)(param_12 + 10) >> 5 & 1;
          }
          if (bVar27 == 1) {
            bVar20 = *(byte *)(puVar26 + 0xb) | 8;
            *(byte *)(puVar26 + 0xb) = bVar20;
            *(ushort *)((long)puVar26 + 0x2e) = *(ushort *)((long)puVar26 + 0x2e) & 0xf000;
            *(byte *)((long)puVar26 + 0x2d) = *(byte *)((long)puVar26 + 0x2d) | 0x10;
          }
          else {
            *(ushort *)((long)puVar26 + 0x2e) = *(ushort *)((long)puVar26 + 0x2e) & 0xf000;
            *(byte *)((long)puVar26 + 0x2d) = *(byte *)((long)puVar26 + 0x2d) | 0x10;
            if (param_11 == 0) {
              bVar27 = 0;
              goto LAB_fffffff00a2d66a0;
            }
            bVar20 = *(byte *)(puVar26 + 0xb);
          }
          if (((bVar20 ^ 0xff) & 0xc) != 0) goto LAB_fffffff00a2d66a0;
        }
        else {
          if (param_11 != 0) goto LAB_fffffff00a2d64b8;
          FUN_fffffff00a32db18(puVar26);
          bVar27 = 0;
          *(ushort *)((long)puVar26 + 0x2e) = *(ushort *)((long)puVar26 + 0x2e) & 0xf000;
          *(byte *)((long)puVar26 + 0x2d) = *(byte *)((long)puVar26 + 0x2d) | 0x10;
LAB_fffffff00a2d66a0:
          puVar16 = (undefined4 *)FUN_fffffff00a2d4db0(puVar17,puVar26);
        }
        local_e8 = 5;
        if (param_11 == 0) {
          local_e8 = 1;
        }
        local_c8 = (undefined4 *)0x0;
        goto LAB_fffffff00a2d66c8;
      }
      uVar21 = puVar17[0x1d];
      if ((uVar21 >> 7 & 1) != 0) {
        if ((((uVar21 >> 0xc & 1) != 0) && ((uVar21 >> 0xf & 1) != 0)) &&
           (*(long *)(puVar17 + 0x14) != 0)) {
          iVar14 = FUN_fffffff00a2c5c14
                             (*(long *)(puVar17 + 0x14),*(long *)(puVar17 + 0x18) + local_b8);
          bVar9 = iVar14 != 3;
          goto LAB_fffffff00a2d5870;
        }
        bVar11 = puVar17 == param_1;
        if ((uVar21 >> 9 & 1) != 0) goto LAB_fffffff00a2d5b50;
LAB_fffffff00a2d6fe8:
        local_7c = 0;
        if (puVar17[10] + 0xf0000001 < 0xf0000002) goto LAB_fffffff00a2d7494;
        puVar17[10] = puVar17[10] + 1;
        FUN_fffffff00a2d759c(puVar17,local_c8);
        FUN_fffffff00a3061bc(puVar17);
        if ((*(byte *)((long)puVar17 + 0x75) >> 1 & 1) != 0) goto LAB_fffffff00a2d71bc;
        if ((param_13 != (undefined8 *)0x0) && ((*(byte *)(param_13 + 5) >> 5 & 1) != 0)) {
          FUN_fffffff00a2d3670(param_13[2],&DAT_fffffff00ad18858,7,*param_13,param_13[1]);
        }
        iVar15 = FUN_fffffff00a306fc4(puVar17,1,iVar15,1);
        goto LAB_fffffff00a2d6628;
      }
      bVar9 = false;
LAB_fffffff00a2d5870:
      bVar11 = puVar17 == param_1;
      if ((bVar11) && (!bVar9)) {
        if (*(char *)((long)puVar17 + 0x76) < '\0') {
          bVar11 = true;
          goto LAB_fffffff00a2d5988;
        }
        puVar26 = (undefined4 *)FUN_fffffff00a32cd9c(uVar23);
        if (puVar26 != (undefined4 *)0x0) {
          FUN_fffffff00a3297a4(puVar26,puVar17,uVar24,0,(uint)param_12[10] >> 4 & 4,0);
          goto LAB_fffffff00a2d5994;
        }
LAB_fffffff00a2d65d4:
        FUN_fffffff00a2d759c(puVar17,local_c8);
        uVar6 = *(ushort *)(lVar7 + 200);
        goto LAB_fffffff00a2d70f0;
      }
LAB_fffffff00a2d5988:
      puVar26 = (undefined4 *)0x0;
      if (!bVar9) goto LAB_fffffff00a2d5994;
      uVar21 = puVar17[0x1d];
      if ((uVar21 >> 9 & 1) == 0) goto LAB_fffffff00a2d6fe8;
LAB_fffffff00a2d5b50:
      local_7c = 0;
      if (((uVar21 & 0x801000) == 0) &&
         (uVar6 = *(ushort *)(puVar17 + 0x1b), DAT_fffffff007bccab2 <= uVar6)) {
        uVar5 = *(uint *)(lVar7 + 0x214);
        uVar22 = *(uint *)(lVar7 + 0x4f8) >> 1 & 3;
        uVar21 = uVar22;
        if ((int)uVar5 <= (int)uVar22) {
          uVar21 = uVar5;
        }
        if (uVar5 != 0xffffffff) {
          uVar22 = uVar21;
        }
        lVar12 = (ulong)*(ushort *)(lVar7 + 0x1b0) * 0x4000;
        if ((((uint)puVar17[0x2a] >> 8 & 1) == 0) || (uVar22 != 0)) {
          plVar1 = (long *)&DAT_fffffff00ad0e410;
          if (uVar22 != 0) {
            plVar1 = (long *)&DAT_fffffff00ad0e418;
          }
          plVar4 = (long *)&DAT_fffffff00ad0e408;
          if ((puVar17[0x2a] & 0x100) == 0) {
            plVar4 = plVar1;
          }
          plVar1 = (long *)(lVar12 + *plVar4);
          *plVar1 = *plVar1 + 1;
        }
        else {
          bVar9 = DAT_fffffff007bccab0 <= uVar6;
          plVar1 = (long *)&DAT_fffffff00ad0e400;
          if (bVar9) {
            plVar1 = (long *)&DAT_fffffff00ad0e3f8;
          }
          plVar1 = (long *)(lVar12 + *plVar1);
          *plVar1 = *plVar1 + 1;
          if (!bVar9) {
            uVar21 = puVar17[0x1d];
            goto LAB_fffffff00a2d5be4;
          }
        }
        local_7c = 0;
        if (puVar17[10] + 0xf0000001 < 0xf0000002) goto LAB_fffffff00a2d7494;
        puVar17[10] = puVar17[10] + 1;
        FUN_fffffff00a2d759c(puVar17,local_c8);
        FUN_fffffff00a3061bc(puVar17);
        if ((puVar17[0x1d] & 0x801000) == 0) {
          uVar21 = *(uint *)(lVar7 + 0x4f8) >> 1 & 3;
          uVar22 = *(uint *)(lVar7 + 0x214);
          uVar23 = uVar21;
          if ((int)uVar22 <= (int)uVar21) {
            uVar23 = uVar22;
          }
          if (uVar22 != 0xffffffff) {
            uVar21 = uVar23;
          }
          uVar6 = *(ushort *)(puVar17 + 0x1b);
          if (DAT_fffffff007bccab2 <= uVar6) {
            lVar12 = (ulong)*(ushort *)(lVar7 + 0x1b0) * 0x4000;
            if ((((uint)puVar17[0x2a] >> 8 & 1) == 0) || (uVar21 != 0)) {
              plVar1 = (long *)&DAT_fffffff00ad0e410;
              if (uVar21 != 0) {
                plVar1 = (long *)&DAT_fffffff00ad0e418;
              }
              plVar4 = (long *)&DAT_fffffff00ad0e408;
              if ((puVar17[0x2a] & 0x100) == 0) {
                plVar4 = plVar1;
              }
              plVar1 = (long *)(lVar12 + *plVar4);
              lVar12 = *plVar1;
              *plVar1 = lVar12 + 1;
            }
            else {
              bVar10 = uVar6 < DAT_fffffff007bccab0;
              plVar1 = (long *)&DAT_fffffff00ad0e400;
              if (!bVar10) {
                plVar1 = (long *)&DAT_fffffff00ad0e3f8;
              }
              plVar1 = (long *)(lVar12 + *plVar1);
              lVar12 = *plVar1;
              *plVar1 = lVar12 + 1;
              if (bVar10) goto LAB_fffffff00a2d71bc;
            }
            iVar15 = FUN_fffffff00a310500(lVar12,puVar17,iVar15);
            FUN_fffffff00a22aeac(puVar17 + 2);
            goto LAB_fffffff00a2d6628;
          }
        }
LAB_fffffff00a2d71bc:
        FUN_fffffff00a22aeac(puVar17 + 2);
        FUN_fffffff00a303950(puVar17);
      }
      else {
LAB_fffffff00a2d5be4:
        if ((uVar21 >> 0xc & 1) == 0) {
          local_7c = 2;
          lVar12 = *(long *)(puVar17 + 0x14);
          if (lVar12 == 0) {
            FUN_fffffff00a2d759c(puVar17,local_c8);
            *(ushort *)(lVar7 + 200) = *(ushort *)(lVar7 + 200) & 0xfffc | uVar3;
            if (lVar7 == 0) {
              uVar18 = 0;
            }
            else {
              uVar18 = *(undefined8 *)(lVar7 + 0x4e0);
            }
            uVar24 = ((ulong)*(uint *)(&DAT_fffffff007011480 +
                                      ((ulong)((uint)puVar17[0x1d] >> 0x19) & 7) * 4) & 0x3fff) << 2
                     | 0x1000000;
            goto LAB_fffffff00a2d6040;
          }
          if (((*(byte *)((long)puVar17 + 0xa9) & 1) == 0) &&
             (*(undefined **)(lVar12 + 8) != &DAT_fffffff007bcb438)) {
            bVar8 = false;
          }
          else {
            *(short *)(lVar7 + 0x20e) = *(short *)(lVar7 + 0x20e) + 1;
            bVar8 = true;
            local_78 = lVar7;
          }
          FUN_fffffff00a22aeac(puVar17 + 2);
          if (puVar17[0x1a] != 1) {
            bVar11 = true;
          }
          uVar23 = 0;
          if (!bVar11) {
            uVar23 = 0x10;
          }
          bVar9 = *(undefined4 **)(puVar17 + 0xe) == param_1;
          if (bVar9) {
            FUN_fffffff00a3061bc(param_1);
            FUN_fffffff00a329e50(local_c8);
            FUN_fffffff00a2d7f14(param_1);
            FUN_fffffff00a22aeac(param_1 + 2);
            local_c8 = (undefined4 *)0x0;
            DAT_fffffff00ad45f94 = DAT_fffffff00ad45f94 + 1;
          }
          if (bVar10) {
            local_124 = param_12[4];
            local_130 = *(undefined8 *)(param_12 + 2);
            param_12[4] = 1;
            param_12[2] = 0x4000;
            param_12[3] = 0;
          }
          iVar14 = (**(code **)(*(long *)(lVar12 + 8) + 0x20))
                             (lVar12,*(long *)(puVar17 + 0x18) + uVar24,0x4000,uVar23 | local_dc,
                              param_12);
          if (bVar10) {
            param_12[4] = local_124;
            *(undefined8 *)(param_12 + 2) = local_130;
          }
          puVar16 = (undefined4 *)FUN_fffffff00a3061bc(puVar17);
          if (bVar8) {
            puVar16 = (undefined4 *)FUN_fffffff00a274564(&local_78);
          }
          if (iVar14 != 0) {
            FUN_fffffff00a2d759c(puVar17,local_c8);
            *(ushort *)(lVar7 + 200) = *(ushort *)(lVar7 + 200) & 0xfffc | uVar3;
            if (lVar7 == 0) {
              uVar18 = 0;
            }
            else {
              uVar18 = *(undefined8 *)(lVar7 + 0x4e0);
            }
            FUN_fffffff00a6db8c0(uVar18,0x1000004,0);
            uVar23 = 7;
            if (iVar14 != 0x1e) {
              uVar23 = 5;
            }
            uVar21 = 2;
            if (iVar14 != 0x10000007) {
              uVar21 = uVar23;
            }
            return (undefined4 *)(ulong)uVar21;
          }
          bVar10 = true;
        }
        else {
          local_80 = 0;
          puVar16 = (undefined4 *)FUN_fffffff00a32cd9c(uVar23);
          if (puVar16 == (undefined4 *)0x0) goto LAB_fffffff00a2d65d4;
          uVar23 = param_12[10];
          *(byte *)(puVar16 + 0xb) = *(byte *)(puVar16 + 0xb) | 8;
          uVar18 = FUN_fffffff00a3297a4(puVar16,puVar17,uVar24,0,uVar23 >> 4 & 4,0);
          *(byte *)(puVar16 + 0xb) = *(byte *)(puVar16 + 0xb) | 8;
          lVar12 = *(long *)(puVar17 + 0x14);
          local_90 = 0;
          uStack_a8 = 0;
          local_b0 = 0;
          uStack_98 = 0;
          uStack_a0 = 0;
          FUN_fffffff00a303fe0(uVar18,puVar16,&local_b0);
          FUN_fffffff00a22aeac(puVar17 + 2);
          if ((puVar16 < DAT_fffffff007bf0010) || (DAT_fffffff007bf0008 <= puVar16)) {
            iVar14 = puVar16[0xf];
          }
          else {
            iVar14 = DAT_fffffff007bf0000 +
                     (int)((ulong)((long)puVar16 - (long)DAT_fffffff007bf0010) >> 6);
          }
          iVar14 = FUN_fffffff00a2c58f4
                             (lVar12,*(long *)(puVar17 + 0x18) + local_b8,iVar14,&local_7c,0,
                              &local_80);
          if (((param_9 == (int *)0x0) && (local_7c == 9)) &&
             (iVar13 = FUN_fffffff00a2d7a48(1), iVar13 != 0)) {
            FUN_fffffff00a2d7cf8();
          }
          uVar18 = FUN_fffffff00a3061bc(puVar17);
          if (((lVar12 != 0) && (local_80 != 0)) &&
             (*(undefined **)(lVar12 + 8) == &DAT_fffffff007bca018)) {
            *(int *)(lVar12 + 0x34) = *(int *)(lVar12 + 0x34) + local_80;
          }
          if (iVar14 != 10) {
            if (iVar14 == 9) {
              *(byte *)(puVar16 + 0xb) = *(byte *)(puVar16 + 0xb) & 0xf4 | 1;
            }
            else {
              if (iVar14 != 0) {
                    /* WARNING: Subroutine does not return */
                FUN_fffffff00aa4d114
                          (
                          "vm_fault_page(): unexpected error %d from vm_compressor_pager_get()\n @%s:%d"
                          );
              }
              *(byte *)(puVar16 + 0xb) = *(byte *)(puVar16 + 0xb) & 0xf7;
              *(byte *)((long)puVar16 + 0x2d) = *(byte *)((long)puVar16 + 0x2d) | 1;
              if ((*(char *)((long)puVar17 + 0xa6) == '\x02') ||
                 (*(char *)((long)puVar17 + 0xa6) == -0x80)) {
                *(ushort *)((long)puVar16 + 0x2e) = *(ushort *)((long)puVar16 + 0x2e) | 0x8000;
              }
              else {
                DataSynchronizationBarrier(3,3,0);
              }
              if ((((((puVar17[0x1d] ^ 0xffffffff) & 0x30000) != 0) ||
                   ((*(byte *)((long)puVar17 + 0xaa) & 0x38) != 0)) &&
                  (*(long *)(puVar17 + 0x16) != 0)) && (local_80 != 0)) {
                uVar18 = FUN_fffffff00a322eb0(puVar17,0xffffffff);
              }
            }
          }
          puVar16 = (undefined4 *)FUN_fffffff00a310724(uVar18,puVar16,&local_b0);
          bVar9 = false;
        }
        local_e8 = local_7c;
        if (local_7c == 2) {
          puVar16 = (undefined4 *)FUN_fffffff00a39bcb8(&local_b0,&local_80);
          *(undefined8 *)(lVar7 + 0x468) = local_b0;
          *(undefined4 *)(lVar7 + 0x470) = 0;
        }
        if ((iVar15 != 0) && ((*(byte *)(lVar7 + 0x200) >> 4 & 1) != 0)) {
          FUN_fffffff00a2d759c(puVar17,local_c8);
          *(ushort *)(lVar7 + 200) = *(ushort *)(lVar7 + 200) & 0xfffc | uVar3;
          goto joined_r0xfffffff00a2d6fc8;
        }
        if (!bVar9) {
          if (((uVar21 >> 0xc & 1) != 0) || (-1 < *(char *)((long)puVar17 + 0x76)))
          goto LAB_fffffff00a2d53d4;
          *param_7 = 0;
          *param_8 = local_c8;
          if (lVar7 == 0) {
            uVar18 = 0;
          }
          else {
            uVar18 = *(undefined8 *)(lVar7 + 0x4e0);
          }
          FUN_fffffff00a6db8c0(uVar18,0x1000028,0);
          puVar16 = (undefined4 *)0x6;
          goto LAB_fffffff00a2d6f40;
        }
        FUN_fffffff00a2d759c(puVar17,local_c8);
      }
      uVar6 = *(ushort *)(lVar7 + 200);
      goto LAB_fffffff00a2d71dc;
    }
    if ((*(byte *)(puVar26 + 0xb) >> 2 & 1) == 0) break;
    if ((*(byte *)((long)param_12 + 0x29) >> 4 & 1) != 0) {
      FUN_fffffff00a2d759c(puVar17,local_c8);
      *(ushort *)(lVar7 + 200) = *(ushort *)(lVar7 + 200) & 0xfffc | uVar3;
      return (undefined4 *)0x7;
    }
    if ((param_13 != (undefined8 *)0x0) && ((*(byte *)(param_13 + 5) >> 5 & 1) != 0)) {
      FUN_fffffff00a2d3670(param_13[2],&DAT_fffffff00ad18838,3,*param_13,param_13[1]);
    }
    puVar16 = (undefined4 *)FUN_fffffff00a305a48(puVar17,puVar26,iVar15,0);
    if ((int)puVar16 != 0) {
      FUN_fffffff00a2d759c(puVar17,local_c8);
      *(ushort *)(lVar7 + 200) = *(ushort *)(lVar7 + 200) & 0xfffc | uVar3;
      if ((int)puVar16 == 3) {
        return (undefined4 *)0x1;
      }
      if (lVar7 == 0) {
        uVar18 = 0;
      }
      else {
        uVar18 = *(undefined8 *)(lVar7 + 0x4e0);
      }
      uVar19 = 0x1000034;
      goto LAB_fffffff00a2d6060;
    }
  } while( true );
  if (((*(byte *)((long)puVar26 + 0x2b) >> 1 & 1) != 0) &&
     (*(byte *)((long)puVar26 + 0x2d) = *(byte *)((long)puVar26 + 0x2d) & 0xfb,
     (*(byte *)(puVar26 + 0xb) >> 5 & 1) == 0)) {
    puVar16 = (undefined4 *)FUN_fffffff00a31b0d8(puVar26,0);
  }
  if (((puVar26 < DAT_fffffff007bf0010) || (DAT_fffffff007bf0008 <= puVar26)) &&
     (puVar26[0xf] == -2)) {
    if (param_3 == 0) {
      *(byte *)(puVar26 + 0xb) = *(byte *)(puVar26 + 0xb) | 4;
      *param_7 = puVar26;
      *param_8 = local_c8;
      if (param_9 != (int *)0x0) {
        *param_9 = 6;
      }
      *(ushort *)(lVar7 + 200) = *(ushort *)(lVar7 + 200) & 0xfffc | uVar3;
      return (undefined4 *)0x0;
    }
    FUN_fffffff00a2d759c(puVar17,local_c8);
    *(ushort *)(lVar7 + 200) = *(ushort *)(lVar7 + 200) & 0xfffc | uVar3;
    if (lVar7 == 0) {
      uVar18 = 0;
    }
    else {
      uVar18 = *(undefined8 *)(lVar7 + 0x4e0);
    }
    uVar24 = 0x100002c;
    goto LAB_fffffff00a2d6040;
  }
  bVar20 = *(byte *)(puVar26 + 0xb);
  if ((bVar20 & 3) != 0) {
    if ((bVar20 & 3) == 3) {
      puVar16 = (undefined4 *)0x0;
    }
    else {
      if ((bVar20 & 3) == 2) {
        uVar18 = 0x1000060;
        puVar16 = (undefined4 *)0x1;
      }
      else {
        uVar18 = 0x100005c;
        if (param_10 != (undefined4 *)0x0) {
          *param_10 = 10;
        }
        puVar16 = (undefined4 *)0x5;
      }
      if (lVar7 == 0) {
        uVar19 = 0;
      }
      else {
        uVar19 = *(undefined8 *)(lVar7 + 0x4e0);
      }
      FUN_fffffff00a6db8c0(uVar19,uVar18,0);
    }
    FUN_fffffff00a329e50(puVar26);
    FUN_fffffff00a2d759c(puVar17,local_c8);
    *(ushort *)(lVar7 + 200) = *(ushort *)(lVar7 + 200) & 0xfffc | uVar3;
    return puVar16;
  }
  if ((bVar20 >> 3 & 1) == 0) {
    if ((bVar20 >> 5 & 1) != 0) {
      if (puVar17 == param_1) {
        if (((param_3 >> 1 & 1) != 0) && (*(long *)(puVar17 + 0xe) != 0)) goto LAB_fffffff00a2d637c;
      }
      else if ((param_3 >> 1 & 1) != 0) {
LAB_fffffff00a2d637c:
        if (puVar17[10] + 0xf0000001 < 0xf0000002) {
LAB_fffffff00a2d7494:
                    /* WARNING: Subroutine does not return */
          FUN_fffffff00aa61ed0(puVar17 + 10);
        }
        puVar17[10] = puVar17[10] + 1;
        FUN_fffffff00a2d759c(puVar17);
        FUN_fffffff00a3061bc(puVar17);
        lVar12 = FUN_fffffff00a32bd34(puVar17,uVar24);
        if ((lVar12 == 0) || ((*(byte *)(lVar12 + 0x2c) >> 5 & 1) == 0)) {
          FUN_fffffff00a22aeac(puVar17 + 2);
          FUN_fffffff00a303950(puVar17);
          uVar6 = *(ushort *)(lVar7 + 200);
LAB_fffffff00a2d71dc:
          *(ushort *)(lVar7 + 200) = uVar6 & 0xfffc | uVar3;
          return (undefined4 *)0x1;
        }
        FUN_fffffff00a2d8188(param_13,&DAT_fffffff00ad18840,4);
        iVar15 = FUN_fffffff00a305a48(puVar17,lVar12,iVar15,1);
        goto LAB_fffffff00a2d6628;
      }
    }
    uVar23 = uVar21 >> 1 & 0x10000;
    if (((param_9 == (int *)0x0) && ((*(byte *)((long)puVar26 + 0x2a) & 0xf) == 8)) &&
       ((*(byte *)(param_12 + 10) >> 1 & 1) == 0)) {
      puVar16 = (undefined4 *)FUN_fffffff00a226c24(&DAT_fffffff00ad6d180);
      if ((*(byte *)((long)puVar26 + 0x2a) & 0xf) == 8) {
        puVar16 = (undefined4 *)FUN_fffffff00a32a2ec(puVar26,0);
      }
      if ((int)DAT_fffffff00ad6d188 == *(int *)(lVar7 + 0x4e8)) {
        DAT_fffffff00ad6d188 = CONCAT44(DAT_fffffff00ad6d188._4_4_,in_wzr);
      }
      else {
        puVar16 = (undefined4 *)FUN_fffffff00a226e08(&DAT_fffffff00ad6d180,lVar7);
      }
      bVar20 = *(byte *)(puVar26 + 0xb);
    }
    bVar27 = 0;
    *(byte *)(puVar26 + 0xb) = bVar20 | 4;
LAB_fffffff00a2d66c8:
    if (puVar17 != param_1) {
      if ((param_3 >> 1 & 1) != 0) {
        puVar25 = (undefined4 *)FUN_fffffff00a32cd9c(uVar23);
        if (puVar25 == (undefined4 *)0x0) {
          FUN_fffffff00a30a920(0,puVar26);
          if ((1L << (*(byte *)((long)puVar26 + 0x2a) & 0xf) & 0x3d60U) == 0) {
            FUN_fffffff00a226c24(&DAT_fffffff00ad6d180);
            if ((bVar27 != 0) && ((*(byte *)(puVar26 + 0xb) >> 3 & 1) != 0)) {
              FUN_fffffff00a32db18(puVar26);
              *(byte *)(puVar26 + 0xb) = *(byte *)(puVar26 + 0xb) & 0xf7;
            }
            if ((1L << (*(byte *)((long)puVar26 + 0x2a) & 0xf) & 0x3d60U) == 0) {
              if (DAT_fffffff00ad95104 == 1) {
                FUN_fffffff00a32a12c(puVar26,1);
              }
              else {
                FUN_fffffff00a32c144(puVar26);
              }
            }
            if ((int)DAT_fffffff00ad6d188 == *(int *)(lVar7 + 0x4e8)) {
              DAT_fffffff00ad6d188 = CONCAT44(DAT_fffffff00ad6d188._4_4_,in_wzr);
            }
            else {
              FUN_fffffff00a226e08(&DAT_fffffff00ad6d180,lVar7);
            }
          }
LAB_fffffff00a2d70e0:
          FUN_fffffff00a2d759c(puVar17,local_c8);
          uVar6 = *(ushort *)(lVar7 + 200);
LAB_fffffff00a2d70f0:
          *(ushort *)(lVar7 + 200) = uVar6 & 0xfffc | uVar3;
          return (undefined4 *)0x3;
        }
        uVar18 = FUN_fffffff00a32f138(puVar26,puVar25);
        bVar20 = *(byte *)((long)puVar26 + 0x2d);
        if ((bVar20 >> 4 & 1) != 0) {
          if ((puVar26 < DAT_fffffff007bf0010) || (DAT_fffffff007bf0008 <= puVar26)) {
            iVar14 = puVar26[0xf];
          }
          else {
            iVar14 = DAT_fffffff007bf0000 +
                     (int)((ulong)((long)puVar26 - (long)DAT_fffffff007bf0010) >> 6);
          }
          uVar18 = FUN_fffffff00a37c100(iVar14);
          bVar20 = *(byte *)((long)puVar26 + 0x2d);
        }
        if ((bVar20 >> 3 & 1) != 0) {
          lVar12 = FUN_fffffff00a29bafc(lVar7);
          plVar1 = (long *)(*(long *)(lVar12 + 0x388) + (ulong)*(ushort *)(lVar7 + 0x1b0) * 0x4000);
          *plVar1 = *plVar1 + 1;
          if ((puVar26 < DAT_fffffff007bf0010) || (DAT_fffffff007bf0008 <= puVar26)) {
            iVar14 = puVar26[0xf];
          }
          else {
            iVar14 = DAT_fffffff007bf0000 +
                     (int)((ulong)((long)puVar26 - (long)DAT_fffffff007bf0010) >> 6);
          }
          FUN_fffffff00a37c1d0(iVar14);
          uVar24 = (ulong)*(byte *)((long)puVar26 + 0x2d);
          if ((*(byte *)((long)puVar26 + 0x2d) >> 3 & 1) != 0) {
            lVar12 = 0;
            if (puVar26[7] != 0) {
              lVar12 = (ulong)(uint)puVar26[7] * 0x40 + -0x2400000000;
            }
            *(int *)(lVar12 + 0xa0) = *(int *)(lVar12 + 0xa0) + 1;
            *(byte *)((long)puVar26 + 0x2d) = *(byte *)((long)puVar26 + 0x2d) & 0xf7;
            puVar2 = (ulong *)(_DAT_fffffff00ad188c8 + (ulong)*(ushort *)(lVar7 + 0x1b0) * 0x4000);
            uVar24 = *puVar2;
            *puVar2 = uVar24 + 1;
          }
          uVar18 = FUN_fffffff00a37c37c(uVar24,iVar14);
        }
        FUN_fffffff00a30a920(uVar18,puVar26);
        if ((1L << (*(byte *)((long)puVar26 + 0x2a) & 0xf) & 0x3d60U) == 0) {
          FUN_fffffff00a226c24(&DAT_fffffff00ad6d180);
          if ((bVar27 != 0) && ((*(byte *)(puVar26 + 0xb) >> 3 & 1) != 0)) {
            FUN_fffffff00a32db18(puVar26);
            *(byte *)(puVar26 + 0xb) = *(byte *)(puVar26 + 0xb) & 0xf7;
          }
          if ((1L << (*(byte *)((long)puVar26 + 0x2a) & 0xf) & 0x3d60U) == 0) {
            if (DAT_fffffff00ad95104 == 1) {
              FUN_fffffff00a32a12c(puVar26,1);
            }
            else {
              FUN_fffffff00a32c144(puVar26);
            }
          }
          if ((int)DAT_fffffff00ad6d188 == *(int *)(lVar7 + 0x4e8)) {
            DAT_fffffff00ad6d188 = CONCAT44(DAT_fffffff00ad6d188._4_4_,in_wzr);
            goto LAB_fffffff00a2d697c;
          }
          FUN_fffffff00a226e08(&DAT_fffffff00ad6d180,lVar7);
          bVar27 = *(byte *)((long)puVar17 + 0x75);
        }
        else {
LAB_fffffff00a2d697c:
          bVar27 = *(byte *)((long)puVar17 + 0x75);
        }
        if ((bVar27 >> 4 & 1) == 0) {
          FUN_fffffff00a2d3c78(puVar17,local_b8,param_12[4]);
        }
        uVar6 = *(ushort *)(puVar17 + 0x1b);
        uVar21 = uVar6 - 1;
        *(short *)(puVar17 + 0x1b) = (short)uVar21;
        if (0xffff < uVar21) {
LAB_fffffff00a2d7468:
                    /* WARNING: Subroutine does not return */
          FUN_fffffff00aa4d114("vm_object_paging_end(%p): underflow\n @%s:%d");
        }
        uVar21 = uVar21 & 0xffff;
        if (((*(byte *)((long)puVar17 + 0x75) >> 4 & 1) == 0) &&
           (((*(byte *)((long)puVar17 + 0xa9) & (uint)uVar6 == (uint)DAT_fffffff007bccab0) != 0 ||
            (DAT_fffffff007bccab2 == uVar6)))) {
          FUN_fffffff00a30c550(puVar17,6);
          uVar21 = (uint)*(ushort *)(puVar17 + 0x1b);
        }
        if ((uVar21 == 0) && (FUN_fffffff00a30c550(puVar17,5), puVar17[0x1c] == 0)) {
          FUN_fffffff00a30c550(puVar17,2);
        }
        FUN_fffffff00a22aeac(puVar17 + 2);
        plVar1 = (long *)(_DAT_fffffff00ad0e4a0 + (ulong)*(ushort *)(lVar7 + 0x1b0) * 0x4000);
        lVar12 = *plVar1;
        *plVar1 = lVar12 + 1;
        lVar12 = FUN_fffffff00a29bafc(lVar12,lVar7);
        plVar1 = (long *)(*(long *)(lVar12 + 0x390) + (ulong)*(ushort *)(lVar7 + 0x1b0) * 0x4000);
        lVar12 = *plVar1;
        *plVar1 = lVar12 + 1;
        FUN_fffffff00a3061bc(lVar12,param_1);
        FUN_fffffff00a329e50(local_c8);
        FUN_fffffff00a3297a4(puVar25,param_1,param_2 & 0xffffffffffffc000,0,0,0);
        if ((puVar25 < DAT_fffffff007bf0010) || (DAT_fffffff007bf0008 <= puVar25)) {
          iVar14 = puVar25[0xf];
        }
        else {
          iVar14 = DAT_fffffff007bf0000 +
                   (int)((ulong)((long)puVar25 - (long)DAT_fffffff007bf0010) >> 6);
        }
        FUN_fffffff00a379378(iVar14);
        *(byte *)((long)puVar25 + 0x2d) = *(byte *)((long)puVar25 + 0x2d) | 1;
        uVar6 = *(ushort *)(param_1 + 0x1b);
        uVar21 = uVar6 - 1;
        *(short *)(param_1 + 0x1b) = (short)uVar21;
        if (0xffff < uVar21) goto LAB_fffffff00a2d7468;
        uVar21 = uVar21 & 0xffff;
        if (((*(byte *)((long)param_1 + 0x75) >> 4 & 1) == 0) &&
           (((*(byte *)((long)param_1 + 0xa9) & (uint)uVar6 == (uint)DAT_fffffff007bccab0) != 0 ||
            (DAT_fffffff007bccab2 == uVar6)))) {
          FUN_fffffff00a30c550(param_1,6);
          uVar21 = (uint)*(ushort *)(param_1 + 0x1b);
        }
        if ((uVar21 == 0) && (FUN_fffffff00a30c550(param_1,5), param_1[0x1c] == 0)) {
          FUN_fffffff00a30c550(param_1,2);
        }
        puVar16 = (undefined4 *)FUN_fffffff00a3042e8(param_1,param_2 & 0xffffffffffffc000,1);
        uVar6 = *(ushort *)(param_1 + 0x1b);
        *(short *)(param_1 + 0x1b) = (short)(uVar6 + 1);
        if (uVar6 + 1 >> 0x10 != 0) {
LAB_fffffff00a2d7448:
                    /* WARNING: Subroutine does not return */
          FUN_fffffff00aa4d114("vm_object_paging_begin(%p): overflow\n @%s:%d");
        }
        bVar27 = 0;
        local_c8 = (undefined4 *)0x0;
        local_e8 = 3;
        puVar17 = param_1;
        puVar26 = puVar25;
        goto LAB_fffffff00a2d6b90;
      }
      *param_6 = *param_6 & 0xfffffffd;
    }
    local_100 = local_b8;
  }
  else {
    puVar25 = *(undefined4 **)(puVar17 + 0x12);
    if (puVar25 != (undefined4 *)0x0) {
      if (param_4 == 0) {
        if (puVar17 == param_1) {
          *(byte *)(puVar26 + 0xb) = bVar20 & 0xf7 | 4;
          *(int *)(lVar7 + 0x1c0) = *(int *)(lVar7 + 0x1c0) + 1;
          uVar24 = (ulong)*(uint *)(lVar7 + 0x4e8) | 0x30000000;
          if (DAT_fffffff00ad6d188 != 0) {
            FUN_fffffff00a2262d4(&DAT_fffffff00ad6d180,lVar7,1);
            uVar24 = DAT_fffffff00ad6d188;
          }
          DAT_fffffff00ad6d188 = uVar24;
          FUN_fffffff00a32a2ec(puVar26,0);
          local_c8 = puVar26;
          if ((int)DAT_fffffff00ad6d188 == *(int *)(lVar7 + 0x4e8)) {
            DAT_fffffff00ad6d188 = CONCAT44(DAT_fffffff00ad6d188._4_4_,in_wzr);
          }
          else {
            FUN_fffffff00a226e08(&DAT_fffffff00ad6d180,lVar7);
          }
        }
        else {
          uVar6 = *(ushort *)(puVar17 + 0x1b);
          uVar23 = uVar6 - 1;
          *(short *)(puVar17 + 0x1b) = (short)uVar23;
          if (0xffff < uVar23) goto LAB_fffffff00a2d7468;
          uVar23 = uVar23 & 0xffff;
          if (((*(byte *)((long)puVar17 + 0x75) >> 4 & 1) == 0) &&
             (((*(byte *)((long)puVar17 + 0xa9) & (uint)uVar6 == (uint)DAT_fffffff007bccab0) != 0 ||
              (DAT_fffffff007bccab2 == uVar6)))) {
            FUN_fffffff00a30c550(puVar17,6);
            uVar23 = (uint)*(ushort *)(puVar17 + 0x1b);
          }
          if (uVar23 == 0) {
            uVar23 = puVar17[0x1d];
            if ((uVar23 >> 5 & 1) != 0) {
              FUN_fffffff00a24a024((long)puVar17 + 5,0,0);
              uVar23 = puVar17[0x1d];
            }
            puVar17[0x1d] = uVar23 & 0xffffffdf;
            if (puVar17[0x1c] == 0) {
              FUN_fffffff00a30c550(puVar17,2);
            }
          }
          FUN_fffffff00a329e50(puVar26);
        }
      }
      else {
        uVar6 = *(ushort *)(puVar17 + 0x1b);
        uVar23 = uVar6 - 1;
        *(short *)(puVar17 + 0x1b) = (short)uVar23;
        if (0xffff < uVar23) goto LAB_fffffff00a2d7468;
        uVar23 = uVar23 & 0xffff;
        uVar21 = puVar17[0x1d];
        if (((uVar21 >> 0xc & 1) == 0) &&
           (((*(byte *)((long)puVar17 + 0xa9) & (uint)uVar6 == (uint)DAT_fffffff007bccab0) != 0 ||
            (DAT_fffffff007bccab2 == uVar6)))) {
          if ((uVar21 >> 6 & 1) != 0) {
            plVar1 = (long *)(_DAT_fffffff00ad0e458 + (ulong)*(ushort *)(lVar7 + 0x1b0) * 0x4000);
            lVar12 = *plVar1;
            *plVar1 = lVar12 + 1;
            FUN_fffffff00a24a024(lVar12,(long)puVar17 + 6,0,0);
            uVar21 = puVar17[0x1d];
            uVar23 = (uint)*(ushort *)(puVar17 + 0x1b);
          }
          uVar21 = uVar21 & 0xffffffbf;
          puVar17[0x1d] = uVar21;
        }
        if (uVar23 == 0) {
          if ((uVar21 >> 5 & 1) != 0) {
            FUN_fffffff00a24a024((long)puVar17 + 5,0,0);
            uVar21 = puVar17[0x1d];
          }
          uVar23 = uVar21 & 0xffffffdf;
          puVar17[0x1d] = uVar23;
          if (puVar17[0x1c] == 0) {
            if ((uVar21 >> 2 & 1) != 0) {
              FUN_fffffff00a24a024((long)puVar17 + 2,0,0);
              uVar23 = puVar17[0x1d];
            }
            puVar17[0x1d] = uVar23 & 0xfffffffb;
          }
        }
      }
      lVar12 = *(long *)(puVar17 + 0x16);
      *(long *)(param_12 + 6) = *(long *)(param_12 + 6) + lVar12;
      *(long *)(param_12 + 8) = *(long *)(param_12 + 8) + *(long *)(puVar17 + 0x16);
      FUN_fffffff00a3061bc(puVar25);
      puVar16 = (undefined4 *)FUN_fffffff00a22aeac(puVar17 + 2);
      uVar23 = *(ushort *)(puVar25 + 0x1b) + 1;
      *(short *)(puVar25 + 0x1b) = (short)uVar23;
      local_e8 = 4;
joined_r0xfffffff00a2d5ae4:
      local_dc = 1;
      local_b8 = lVar12 + local_b8;
      puVar17 = puVar25;
      if (uVar23 >> 0x10 == 0) goto LAB_fffffff00a2d53d4;
      goto LAB_fffffff00a2d7448;
    }
    puVar16 = (undefined4 *)
              FUN_fffffff00a2d803c(puVar17,puVar26,local_c8,uVar3,param_9 == (int *)0x0);
    if ((int)puVar16 != 0) {
      return puVar16;
    }
    uVar23 = uVar21 >> 1 & 0x10000;
    if (puVar17 == param_1) {
      *(byte *)(puVar26 + 0xb) = *(byte *)(puVar26 + 0xb) & 0xf7 | 4;
      local_100 = local_b8;
      puVar25 = local_c8;
    }
    else {
      FUN_fffffff00a329e50(puVar26);
      FUN_fffffff00a2d7f14(puVar17);
      FUN_fffffff00a22aeac(puVar17 + 2);
      puVar16 = (undefined4 *)FUN_fffffff00a3061bc(param_1);
      puVar25 = (undefined4 *)0x0;
      puVar17 = param_1;
      puVar26 = local_c8;
    }
    local_c8 = puVar25;
    bVar27 = 0;
    if (param_11 == 1) {
      bVar27 = *(byte *)(param_12 + 10) >> 5 & 1;
    }
    if (bVar27 == 0) {
      if (param_11 != 0) {
        *(ushort *)((long)puVar26 + 0x2e) = *(ushort *)((long)puVar26 + 0x2e) & 0xf000;
        *(byte *)((long)puVar26 + 0x2d) = *(byte *)((long)puVar26 + 0x2d) | 0x10;
        bVar20 = *(byte *)(puVar26 + 0xb);
        goto LAB_fffffff00a2d6578;
      }
      FUN_fffffff00a32db18(puVar26);
      *(ushort *)((long)puVar26 + 0x2e) = *(ushort *)((long)puVar26 + 0x2e) & 0xf000;
      *(byte *)((long)puVar26 + 0x2d) = *(byte *)((long)puVar26 + 0x2d) | 0x10;
      local_e8 = 1;
    }
    else {
      bVar20 = *(byte *)(puVar26 + 0xb) | 8;
      *(byte *)(puVar26 + 0xb) = bVar20;
      *(ushort *)((long)puVar26 + 0x2e) = *(ushort *)((long)puVar26 + 0x2e) & 0xf000;
      *(byte *)((long)puVar26 + 0x2d) = *(byte *)((long)puVar26 + 0x2d) | 0x10;
LAB_fffffff00a2d6578:
      local_e8 = 5;
      if (((bVar20 ^ 0xff) & 0xc) == 0) goto LAB_fffffff00a2d6b90;
    }
    puVar16 = (undefined4 *)FUN_fffffff00a2d4db0(puVar17,puVar26);
  }
LAB_fffffff00a2d6b90:
  local_70[0] = (undefined4 *)0x0;
  if (*(long *)(param_1 + 0xe) != 0) {
    if ((param_3 >> 1 & 1) == 0) {
      *param_6 = *param_6 & 0xfffffffd;
    }
    else if ((param_4 == 0) &&
            (puVar16 = (undefined4 *)FUN_fffffff00a2d81ac(puVar17,local_70), (int)puVar16 != 0)) {
      local_b0 = 0;
      puVar16 = (undefined4 *)FUN_fffffff00a2d82a8(puVar26,uVar23,&local_b0);
      puVar25 = local_70[0];
      if ((int)puVar16 == 2) {
        FUN_fffffff00a30a920(puVar16,puVar26);
        if ((1L << (*(byte *)((long)puVar26 + 0x2a) & 0xf) & 0x3d60U) == 0) {
          FUN_fffffff00a226c24(&DAT_fffffff00ad6d180);
          if ((bVar27 != 0) && ((*(byte *)(puVar26 + 0xb) >> 3 & 1) != 0)) {
            FUN_fffffff00a32db18(puVar26);
            *(byte *)(puVar26 + 0xb) = *(byte *)(puVar26 + 0xb) & 0xf7;
          }
          if ((1L << (*(byte *)((long)puVar26 + 0x2a) & 0xf) & 0x3d60U) == 0) {
            if (DAT_fffffff00ad95104 == 1) {
              FUN_fffffff00a32a12c(puVar26,1);
            }
            else {
              FUN_fffffff00a32c144(puVar26);
            }
          }
          if ((int)DAT_fffffff00ad6d188 == *(int *)(lVar7 + 0x4e8)) {
            DAT_fffffff00ad6d188 = CONCAT44(DAT_fffffff00ad6d188._4_4_,in_wzr);
          }
          else {
            FUN_fffffff00a226e08(&DAT_fffffff00ad6d180,lVar7);
          }
        }
        FUN_fffffff00a22aeac(local_70[0] + 2);
        FUN_fffffff00a2d759c(puVar17,local_c8);
        puVar16 = (undefined4 *)0x3;
        goto LAB_fffffff00a2d6f40;
      }
      if ((int)puVar16 == 1) {
        FUN_fffffff00a30a920(puVar16,puVar26);
        if ((1L << (*(byte *)((long)puVar26 + 0x2a) & 0xf) & 0x3d60U) == 0) {
          FUN_fffffff00a226c24(&DAT_fffffff00ad6d180);
          if ((bVar27 != 0) && ((*(byte *)(puVar26 + 0xb) >> 3 & 1) != 0)) {
            FUN_fffffff00a32db18(puVar26);
            *(byte *)(puVar26 + 0xb) = *(byte *)(puVar26 + 0xb) & 0xf7;
          }
          if ((1L << (*(byte *)((long)puVar26 + 0x2a) & 0xf) & 0x3d60U) == 0) {
            if (DAT_fffffff00ad95104 == 1) {
              FUN_fffffff00a32a12c(puVar26,1);
            }
            else {
              FUN_fffffff00a32c144(puVar26);
            }
          }
          if ((int)DAT_fffffff00ad6d188 == *(int *)(lVar7 + 0x4e8)) {
            DAT_fffffff00ad6d188 = CONCAT44(DAT_fffffff00ad6d188._4_4_,in_wzr);
          }
          else {
            FUN_fffffff00a226e08(&DAT_fffffff00ad6d180,lVar7);
          }
        }
        if (local_70[0][10] + 0xf0000001 < 0xf0000002) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff00aa61ed0(local_70[0] + 10);
        }
        local_70[0][10] = local_70[0][10] + 1;
        FUN_fffffff00a22aeac(local_70[0] + 2);
        FUN_fffffff00a2d759c(puVar17,local_c8);
        puVar17 = local_70[0];
        FUN_fffffff00a3061bc(local_70[0]);
        lVar12 = FUN_fffffff00a32bd34(puVar17,local_b0);
        if ((lVar12 == 0) || ((*(byte *)(lVar12 + 0x2c) >> 2 & 1) == 0)) {
          FUN_fffffff00a22aeac(puVar17 + 2);
          FUN_fffffff00a303950(puVar17);
          puVar16 = (undefined4 *)0x1;
          goto LAB_fffffff00a2d6f40;
        }
        FUN_fffffff00a2d8188(param_13,&DAT_fffffff00ad18848,5);
        iVar15 = FUN_fffffff00a305a48(puVar17,lVar12,iVar15,1);
LAB_fffffff00a2d6628:
        FUN_fffffff00a303950(puVar17);
        *(ushort *)(lVar7 + 200) = *(ushort *)(lVar7 + 200) & 0xfffc | uVar3;
        if (iVar15 != 2) {
          return (undefined4 *)0x1;
        }
joined_r0xfffffff00a2d6fc8:
        if (lVar7 == 0) {
          uVar18 = 0;
        }
        else {
          uVar18 = *(undefined8 *)(lVar7 + 0x4e0);
        }
        uVar19 = 0x1000024;
LAB_fffffff00a2d6060:
        FUN_fffffff00a6db8c0(uVar18,uVar19,0);
        return (undefined4 *)0x2;
      }
      if (local_70[0] != (undefined4 *)0x0) {
        local_70[0] = (undefined4 *)0x0;
        puVar16 = (undefined4 *)FUN_fffffff00a22aeac(puVar25 + 2);
      }
    }
  }
  *param_7 = puVar26;
  *param_8 = local_c8;
  if (local_e8 == 2) {
    lVar12 = FUN_fffffff00a29bafc(lVar7);
    plVar1 = (long *)(*(long *)(lVar12 + 0x388) + (ulong)*(ushort *)(lVar7 + 0x1b0) * 0x4000);
    *plVar1 = *plVar1 + 1;
    local_e8 = 7;
    if ((puVar17[0x1d] & 0x1000) != 0) {
      local_e8 = 8;
    }
    param_12[10] = param_12[10] | 0x2000;
    FUN_fffffff00a2d3c78(puVar17,local_100,param_12[4]);
    puVar16 = (undefined4 *)FUN_fffffff00a2d8658(puVar17,local_100,param_12);
LAB_fffffff00a2d6da4:
    if (param_9 != (int *)0x0) {
      *param_9 = local_e8;
    }
  }
  else {
    if ((param_9 != (int *)0x0) || (local_e8 != 4)) {
      if (local_e8 - 9U < 2) {
        plVar1 = (long *)(_DAT_fffffff00ad0e498 + (ulong)*(ushort *)(lVar7 + 0x1b0) * 0x4000);
        *plVar1 = *plVar1 + 1;
        *(int *)(lVar7 + 0x560) = *(int *)(lVar7 + 0x560) + 1;
      }
      goto LAB_fffffff00a2d6da4;
    }
    if ((*(byte *)((long)puVar26 + 0x2d) >> 3 & 1) != 0) {
      lVar12 = FUN_fffffff00a29bafc(lVar7);
      plVar1 = (long *)(*(long *)(lVar12 + 0x388) + (ulong)*(ushort *)(lVar7 + 0x1b0) * 0x4000);
      *plVar1 = *plVar1 + 1;
      plVar1 = (long *)(_DAT_fffffff00ad0e428 + (ulong)*(ushort *)(lVar7 + 0x1b0) * 0x4000);
      *plVar1 = *plVar1 + 1;
      plVar1 = (long *)(*(long *)(lVar12 + 0x398) + (ulong)*(ushort *)(lVar7 + 0x1b0) * 0x4000);
      *plVar1 = *plVar1 + 1;
      if ((puVar26 < DAT_fffffff007bf0010) || (DAT_fffffff007bf0008 <= puVar26)) {
        iVar15 = puVar26[0xf];
      }
      else {
        iVar15 = DAT_fffffff007bf0000 +
                 (int)((ulong)((long)puVar26 - (long)DAT_fffffff007bf0010) >> 6);
      }
      FUN_fffffff00a37c1d0(iVar15);
      uVar24 = (ulong)*(byte *)((long)puVar26 + 0x2d);
      if ((*(byte *)((long)puVar26 + 0x2d) >> 3 & 1) != 0) {
        lVar12 = 0;
        if (puVar26[7] != 0) {
          lVar12 = (ulong)(uint)puVar26[7] * 0x40 + -0x2400000000;
        }
        *(int *)(lVar12 + 0xa0) = *(int *)(lVar12 + 0xa0) + 1;
        *(byte *)((long)puVar26 + 0x2d) = *(byte *)((long)puVar26 + 0x2d) & 0xf7;
        puVar2 = (ulong *)(_DAT_fffffff00ad188c8 + (ulong)*(ushort *)(lVar7 + 0x1b0) * 0x4000);
        uVar24 = *puVar2;
        *puVar2 = uVar24 + 1;
      }
      FUN_fffffff00a37c37c(uVar24,iVar15);
      param_12[10] = param_12[10] | 0x2000;
    }
    FUN_fffffff00a2d3c78(puVar17,local_100,param_12[4]);
    puVar16 = (undefined4 *)FUN_fffffff00a328594(puVar26);
    if (((ulong)puVar16 & 1) == 0) {
      puVar16 = (undefined4 *)FUN_fffffff00a2d8658(puVar17,local_100,param_12);
    }
  }
  if ((*(byte *)((long)puVar17 + 0xab) >> 2 & 1) == 0) {
    puVar16 = (undefined4 *)0x0;
    goto LAB_fffffff00a2d6f40;
  }
  if ((param_3 >> 1 & 1) == 0) {
    puVar16 = (undefined4 *)0x0;
    *param_6 = *param_6 & 0xfffffffd;
LAB_fffffff00a2d6f40:
    *(ushort *)(lVar7 + 200) = *(ushort *)(lVar7 + 200) & 0xfffc | uVar3;
    return puVar16;
  }
  FUN_fffffff00a30a920(puVar16,puVar26);
  FUN_fffffff00a2d759c(puVar17,local_c8);
  *(ushort *)(lVar7 + 200) = *(ushort *)(lVar7 + 200) & 0xfffc | uVar3;
  DAT_fffffff00ad94e68 = DAT_fffffff00ad94e68 + 1;
  if (lVar7 == 0) {
    uVar18 = 0;
  }
  else {
    uVar18 = *(undefined8 *)(lVar7 + 0x4e0);
  }
  uVar24 = 0x1000108;
LAB_fffffff00a2d6040:
  FUN_fffffff00a6db8c0(uVar18,uVar24,0);
  return (undefined4 *)0x5;
}

