// FUN_fffffff00a4b0368 @ fffffff00a4b0368 size=1876

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_fffffff00a4b0368(long *param_1,undefined8 *param_2,ulong param_3)

{
  int iVar1;
  code *pcVar2;
  long lVar3;
  int *piVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined *puVar7;
  undefined *puVar8;
  undefined8 uVar9;
  undefined8 *puVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined8 uVar20;
  undefined8 uVar21;
  undefined8 uVar22;
  undefined8 uVar23;
  undefined8 uVar24;
  
  puVar10 = (undefined8 *)((long)param_2 + param_3);
  if ((((ulong)param_2 ^ (ulong)puVar10) & 0xffc0000000000000) != 0) {
    puVar10 = (undefined8 *)((ulong)puVar10 & 0xffffffffffff | 0xc8a2000000000000);
  }
  if (param_3 < 0xf8) {
    uVar9 = 0x16;
  }
  else {
    puVar7 = (undefined *)*param_1;
    puVar8 = &DAT_fffffff00ad7cc50;
    FUN_fffffff00a228180(&DAT_fffffff00ad7cc50);
    if (_DAT_fffffff00ad14910 == 0) {
      uVar9 = 0x16;
    }
    else {
      lVar3 = _DAT_fffffff00ad14910;
      do {
        if (lVar3 == *param_1) {
          FUN_fffffff00a228d30(&DAT_fffffff00ad7cc50);
          param_2[1] = 0;
          *param_2 = 0;
          param_2[3] = 0;
          param_2[2] = 0;
          param_2[5] = 0;
          param_2[4] = 0;
          param_2[7] = 0;
          param_2[6] = 0;
          param_2[9] = 0;
          param_2[8] = 0;
          param_2[0xb] = 0;
          param_2[10] = 0;
          param_2[0xd] = 0;
          param_2[0xc] = 0;
          param_2[0xf] = 0;
          param_2[0xe] = 0;
          param_2[0x11] = 0;
          param_2[0x10] = 0;
          param_2[0x13] = 0;
          param_2[0x12] = 0;
          param_2[0x15] = 0;
          param_2[0x14] = 0;
          param_2[0x17] = 0;
          param_2[0x16] = 0;
          param_2[0x19] = 0;
          param_2[0x18] = 0;
          param_2[0x1b] = 0;
          param_2[0x1a] = 0;
          param_2[0x1d] = 0;
          param_2[0x1c] = 0;
          param_2[0x1e] = 0;
          FUN_fffffff00a228180(puVar7);
          if (puVar10 < param_2 + 0x1f) {
LAB_fffffff00a4b0ab8:
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(0x5519,0xfffffff00a4b0abc);
            (*pcVar2)();
          }
          FUN_fffffff00a354958((long)param_2 + 0xe4,*(undefined8 *)(puVar7 + 0x20),0x11);
          *(uint *)(param_2 + 1) = (uint)*(ushort *)(puVar7 + 0xcc);
          *param_2 = *(undefined8 *)(puVar7 + 0x8c8);
          *(uint *)(param_2 + 0xc) = (uint)(byte)puVar7[0xf8];
          if (*(uint *)(puVar7 + 0x2c) < 0x80) {
            if (*(uint *)(puVar7 + 0x28) < 0x80) goto LAB_fffffff00a4b0ab8;
            puVar10 = *(undefined8 **)(puVar7 + 0x30);
            uVar11 = puVar10[1];
            uVar9 = *puVar10;
            uVar13 = puVar10[3];
            uVar12 = puVar10[2];
            uVar15 = puVar10[5];
            uVar14 = puVar10[4];
            uVar17 = puVar10[7];
            uVar16 = puVar10[6];
            uVar19 = puVar10[9];
            uVar18 = puVar10[8];
            uVar21 = puVar10[0xb];
            uVar20 = puVar10[10];
            uVar23 = puVar10[0xd];
            uVar22 = puVar10[0xc];
            uVar24 = puVar10[0xe];
            *(undefined8 *)((long)param_2 + 0xdc) = puVar10[0xf];
            *(undefined8 *)((long)param_2 + 0xd4) = uVar24;
            *(undefined8 *)((long)param_2 + 0xcc) = uVar23;
            *(undefined8 *)((long)param_2 + 0xc4) = uVar22;
            *(undefined8 *)((long)param_2 + 0xbc) = uVar21;
            *(undefined8 *)((long)param_2 + 0xb4) = uVar20;
            *(undefined8 *)((long)param_2 + 0xac) = uVar19;
            *(undefined8 *)((long)param_2 + 0xa4) = uVar18;
            *(undefined8 *)((long)param_2 + 0x9c) = uVar17;
            *(undefined8 *)((long)param_2 + 0x94) = uVar16;
            *(undefined8 *)((long)param_2 + 0x8c) = uVar15;
            *(undefined8 *)((long)param_2 + 0x84) = uVar14;
            *(undefined8 *)((long)param_2 + 0x7c) = uVar13;
            *(undefined8 *)((long)param_2 + 0x74) = uVar12;
            *(undefined8 *)((long)param_2 + 0x6c) = uVar11;
            *(undefined8 *)((long)param_2 + 100) = uVar9;
          }
          if (puVar7 + 0xa88 <= puVar7) goto LAB_fffffff00a4b0ab8;
          *(undefined4 *)((long)param_2 + 0xc) = 0;
          FUN_fffffff00a228180(puVar7 + 0x928);
          piVar4 = *(int **)(puVar7 + 0x938);
          if (piVar4 != (int *)0x0) {
            if (puVar7[0xf8] == -1) {
              if (*piVar4 != 1) goto LAB_fffffff00a4b0a78;
              *(undefined4 *)((long)param_2 + 0xc) = 1;
              uVar5 = piVar4[2];
              if ((uVar5 & 1) == 0) {
                if ((uVar5 >> 1 & 1) == 0) goto LAB_fffffff00a4b05a4;
LAB_fffffff00a4b0600:
                *(uint *)(param_2 + 2) = *(uint *)(param_2 + 2) | 2;
                *(int *)(param_2 + 3) = piVar4[4];
                uVar5 = piVar4[2];
                if ((uVar5 >> 2 & 1) != 0) goto LAB_fffffff00a4b061c;
LAB_fffffff00a4b05a8:
                if ((uVar5 >> 3 & 1) == 0) goto LAB_fffffff00a4b05ac;
LAB_fffffff00a4b0638:
                *(uint *)(param_2 + 2) = *(uint *)(param_2 + 2) | 8;
                *(int *)(param_2 + 4) = piVar4[6];
                uVar5 = piVar4[2];
                if ((uVar5 >> 4 & 1) != 0) goto LAB_fffffff00a4b0654;
LAB_fffffff00a4b05b0:
                if ((uVar5 >> 5 & 1) == 0) goto LAB_fffffff00a4b05b4;
LAB_fffffff00a4b0670:
                *(uint *)(param_2 + 2) = *(uint *)(param_2 + 2) | 0x20;
                *(int *)(param_2 + 5) = piVar4[8];
                if (((uint)piVar4[2] >> 6 & 1) != 0) goto LAB_fffffff00a4b068c;
LAB_fffffff00a4b05b8:
                uVar5 = piVar4[2];
              }
              else {
                *(uint *)(param_2 + 2) = *(uint *)(param_2 + 2) | 1;
                *(int *)((long)param_2 + 0x14) = piVar4[3];
                uVar5 = piVar4[2];
                if ((uVar5 >> 1 & 1) != 0) goto LAB_fffffff00a4b0600;
LAB_fffffff00a4b05a4:
                if ((uVar5 >> 2 & 1) == 0) goto LAB_fffffff00a4b05a8;
LAB_fffffff00a4b061c:
                *(uint *)(param_2 + 2) = *(uint *)(param_2 + 2) | 4;
                *(int *)((long)param_2 + 0x1c) = piVar4[5];
                uVar5 = piVar4[2];
                if ((uVar5 >> 3 & 1) != 0) goto LAB_fffffff00a4b0638;
LAB_fffffff00a4b05ac:
                if ((uVar5 >> 4 & 1) == 0) goto LAB_fffffff00a4b05b0;
LAB_fffffff00a4b0654:
                *(uint *)(param_2 + 2) = *(uint *)(param_2 + 2) | 0x10;
                *(int *)((long)param_2 + 0x24) = piVar4[7];
                uVar5 = piVar4[2];
                if ((uVar5 >> 5 & 1) != 0) goto LAB_fffffff00a4b0670;
LAB_fffffff00a4b05b4:
                if ((uVar5 >> 6 & 1) == 0) goto LAB_fffffff00a4b05b8;
LAB_fffffff00a4b068c:
                uVar5 = *(uint *)(param_2 + 2);
                *(uint *)(param_2 + 2) = uVar5 | 0x40;
                iVar1 = piVar4[9];
                if (iVar1 < 3) {
                  if (iVar1 == 1) {
                    uVar6 = 1;
                    goto LAB_fffffff00a4b07e4;
                  }
                  if (iVar1 == 2) {
                    uVar6 = 2;
                    goto LAB_fffffff00a4b07e4;
                  }
LAB_fffffff00a4b07c4:
                  *(uint *)(param_2 + 2) = uVar5 & 0xffffffbf;
                  uVar5 = piVar4[2];
                }
                else {
                  if (iVar1 == 3) {
                    uVar6 = 3;
                  }
                  else {
                    if (iVar1 != 4) goto LAB_fffffff00a4b07c4;
                    uVar6 = 4;
                  }
LAB_fffffff00a4b07e4:
                  *(undefined4 *)((long)param_2 + 0x2c) = uVar6;
                  uVar5 = piVar4[2];
                }
              }
              if ((uVar5 >> 7 & 1) != 0) {
                *(uint *)(param_2 + 2) = *(uint *)(param_2 + 2) | 0x80;
                *(int *)(param_2 + 6) = piVar4[10];
                uVar5 = piVar4[2];
              }
              if ((uVar5 >> 8 & 1) != 0) {
                *(uint *)(param_2 + 2) = *(uint *)(param_2 + 2) | 0x100;
                *(int *)((long)param_2 + 0x34) = piVar4[0xb];
                uVar5 = piVar4[2];
              }
              if ((uVar5 >> 9 & 1) != 0) {
                *(uint *)(param_2 + 2) = *(uint *)(param_2 + 2) | 0x200;
                *(int *)(param_2 + 7) = piVar4[0xc];
                uVar5 = piVar4[2];
              }
              if ((uVar5 >> 10 & 1) != 0) {
                *(uint *)(param_2 + 2) = *(uint *)(param_2 + 2) | 0x400;
                *(int *)((long)param_2 + 0x3c) = piVar4[0xd];
                uVar5 = piVar4[2];
              }
              if ((uVar5 >> 0xb & 1) != 0) {
                *(uint *)(param_2 + 2) = *(uint *)(param_2 + 2) | 0x800;
                *(int *)(param_2 + 8) = piVar4[0xe];
                uVar5 = piVar4[2];
              }
              if ((uVar5 >> 0xc & 1) != 0) {
                *(uint *)(param_2 + 2) = *(uint *)(param_2 + 2) | 0x1000;
                *(int *)((long)param_2 + 0x44) = piVar4[0xf];
                uVar5 = piVar4[2];
              }
              if ((uVar5 >> 0xd & 1) != 0) {
                *(uint *)(param_2 + 2) = *(uint *)(param_2 + 2) | 0x2000;
                *(int *)(param_2 + 9) = piVar4[0x10];
                uVar5 = piVar4[2];
              }
              if ((uVar5 >> 0xe & 1) != 0) {
                *(uint *)(param_2 + 2) = *(uint *)(param_2 + 2) | 0x4000;
                *(int *)((long)param_2 + 0x4c) = piVar4[0x11];
                uVar5 = piVar4[2];
              }
              if ((uVar5 >> 0xf & 1) != 0) {
                *(uint *)(param_2 + 2) = *(uint *)(param_2 + 2) | 0x8000;
                *(short *)(param_2 + 10) = (short)piVar4[0x12];
              }
            }
            else {
              if ((((*(int *)(puVar7 + 0x338) != 2) || (*(int *)(puVar7 + 0x33c) != 3)) &&
                  ((*(int *)(puVar7 + 0x8a4) != 2 || (*(int *)(puVar7 + 0x8a8) != 3)))) ||
                 (*piVar4 != 1)) goto LAB_fffffff00a4b0a78;
              *(undefined4 *)((long)param_2 + 0xc) = 2;
              uVar5 = piVar4[2];
              if ((uVar5 & 1) == 0) {
                if ((uVar5 >> 1 & 1) == 0) goto LAB_fffffff00a4b0538;
LAB_fffffff00a4b06d8:
                *(uint *)(param_2 + 2) = *(uint *)(param_2 + 2) | 2;
                *(int *)(param_2 + 3) = piVar4[4];
                uVar5 = piVar4[2];
                if ((uVar5 >> 2 & 1) != 0) goto LAB_fffffff00a4b06f4;
LAB_fffffff00a4b053c:
                if ((uVar5 >> 3 & 1) == 0) goto LAB_fffffff00a4b0540;
LAB_fffffff00a4b0710:
                *(uint *)(param_2 + 2) = *(uint *)(param_2 + 2) | 8;
                *(int *)(param_2 + 4) = piVar4[6];
                uVar5 = piVar4[2];
                if ((uVar5 >> 4 & 1) != 0) goto LAB_fffffff00a4b072c;
LAB_fffffff00a4b0544:
                if ((uVar5 >> 5 & 1) == 0) goto LAB_fffffff00a4b0548;
LAB_fffffff00a4b0748:
                *(uint *)(param_2 + 2) = *(uint *)(param_2 + 2) | 0x20;
                *(int *)(param_2 + 5) = piVar4[8];
                if (((uint)piVar4[2] >> 6 & 1) != 0) goto LAB_fffffff00a4b0764;
LAB_fffffff00a4b054c:
                uVar5 = piVar4[2];
joined_r0xfffffff00a4b0910:
                if ((uVar5 >> 8 & 1) == 0) goto LAB_fffffff00a4b0554;
LAB_fffffff00a4b0914:
                *(uint *)(param_2 + 2) = *(uint *)(param_2 + 2) | 0x100;
                *(int *)(param_2 + 6) = piVar4[10];
                uVar5 = piVar4[2];
                if ((uVar5 >> 7 & 1) != 0) goto LAB_fffffff00a4b0930;
LAB_fffffff00a4b0558:
                if ((uVar5 >> 9 & 1) == 0) goto LAB_fffffff00a4b055c;
LAB_fffffff00a4b094c:
                *(uint *)(param_2 + 2) = *(uint *)(param_2 + 2) | 0x200;
                *(int *)(param_2 + 7) = piVar4[0xc];
                uVar5 = piVar4[2];
                if ((uVar5 >> 10 & 1) != 0) goto LAB_fffffff00a4b0968;
LAB_fffffff00a4b0560:
                if ((uVar5 >> 0xb & 1) == 0) goto LAB_fffffff00a4b0564;
LAB_fffffff00a4b0984:
                *(uint *)(param_2 + 2) = *(uint *)(param_2 + 2) | 0x800;
                *(int *)(param_2 + 8) = piVar4[0xe];
                uVar5 = piVar4[2];
                if ((uVar5 >> 0xc & 1) != 0) goto LAB_fffffff00a4b09a0;
LAB_fffffff00a4b0568:
                if ((uVar5 >> 0xd & 1) == 0) goto LAB_fffffff00a4b056c;
LAB_fffffff00a4b09bc:
                *(uint *)(param_2 + 2) = *(uint *)(param_2 + 2) | 0x2000;
                *(int *)(param_2 + 9) = piVar4[0x10];
                uVar5 = piVar4[2];
                if ((uVar5 >> 0xe & 1) != 0) goto LAB_fffffff00a4b09d8;
LAB_fffffff00a4b0570:
                if ((uVar5 >> 0xf & 1) == 0) goto LAB_fffffff00a4b0574;
LAB_fffffff00a4b09f4:
                uVar5 = *(uint *)(param_2 + 2);
                *(uint *)(param_2 + 2) = uVar5 | 0x8000;
                if (piVar4[0x12] == 2) {
                  uVar6 = 2;
LAB_fffffff00a4b0a20:
                  *(undefined4 *)(param_2 + 10) = uVar6;
                  uVar5 = piVar4[2];
                }
                else {
                  if (piVar4[0x12] == 1) {
                    uVar6 = 1;
                    goto LAB_fffffff00a4b0a20;
                  }
                  *(uint *)(param_2 + 2) = uVar5 & 0xffff7fff;
                  uVar5 = piVar4[2];
                }
              }
              else {
                *(uint *)(param_2 + 2) = *(uint *)(param_2 + 2) | 1;
                *(int *)((long)param_2 + 0x14) = piVar4[3];
                uVar5 = piVar4[2];
                if ((uVar5 >> 1 & 1) != 0) goto LAB_fffffff00a4b06d8;
LAB_fffffff00a4b0538:
                if ((uVar5 >> 2 & 1) == 0) goto LAB_fffffff00a4b053c;
LAB_fffffff00a4b06f4:
                *(uint *)(param_2 + 2) = *(uint *)(param_2 + 2) | 4;
                *(int *)((long)param_2 + 0x1c) = piVar4[5];
                uVar5 = piVar4[2];
                if ((uVar5 >> 3 & 1) != 0) goto LAB_fffffff00a4b0710;
LAB_fffffff00a4b0540:
                if ((uVar5 >> 4 & 1) == 0) goto LAB_fffffff00a4b0544;
LAB_fffffff00a4b072c:
                *(uint *)(param_2 + 2) = *(uint *)(param_2 + 2) | 0x10;
                *(int *)((long)param_2 + 0x24) = piVar4[7];
                uVar5 = piVar4[2];
                if ((uVar5 >> 5 & 1) != 0) goto LAB_fffffff00a4b0748;
LAB_fffffff00a4b0548:
                if ((uVar5 >> 6 & 1) == 0) goto LAB_fffffff00a4b054c;
LAB_fffffff00a4b0764:
                uVar5 = *(uint *)(param_2 + 2);
                *(uint *)(param_2 + 2) = uVar5 | 0x40;
                iVar1 = piVar4[9];
                if (2 < iVar1) {
                  if (iVar1 == 3) {
                    uVar6 = 3;
                  }
                  else {
                    if (iVar1 != 4) goto LAB_fffffff00a4b08e8;
                    uVar6 = 4;
                  }
LAB_fffffff00a4b0908:
                  *(undefined4 *)((long)param_2 + 0x2c) = uVar6;
                  uVar5 = piVar4[2];
                  goto joined_r0xfffffff00a4b0910;
                }
                if (iVar1 == 1) {
                  uVar6 = 1;
                  goto LAB_fffffff00a4b0908;
                }
                if (iVar1 == 2) {
                  uVar6 = 2;
                  goto LAB_fffffff00a4b0908;
                }
LAB_fffffff00a4b08e8:
                *(uint *)(param_2 + 2) = uVar5 & 0xffffffbf;
                uVar5 = piVar4[2];
                if ((uVar5 >> 8 & 1) != 0) goto LAB_fffffff00a4b0914;
LAB_fffffff00a4b0554:
                if ((uVar5 >> 7 & 1) == 0) goto LAB_fffffff00a4b0558;
LAB_fffffff00a4b0930:
                *(uint *)(param_2 + 2) = *(uint *)(param_2 + 2) | 0x80;
                *(int *)((long)param_2 + 0x34) = piVar4[0xb];
                uVar5 = piVar4[2];
                if ((uVar5 >> 9 & 1) != 0) goto LAB_fffffff00a4b094c;
LAB_fffffff00a4b055c:
                if ((uVar5 >> 10 & 1) == 0) goto LAB_fffffff00a4b0560;
LAB_fffffff00a4b0968:
                *(uint *)(param_2 + 2) = *(uint *)(param_2 + 2) | 0x400;
                *(int *)((long)param_2 + 0x3c) = piVar4[0xd];
                uVar5 = piVar4[2];
                if ((uVar5 >> 0xb & 1) != 0) goto LAB_fffffff00a4b0984;
LAB_fffffff00a4b0564:
                if ((uVar5 >> 0xc & 1) == 0) goto LAB_fffffff00a4b0568;
LAB_fffffff00a4b09a0:
                *(uint *)(param_2 + 2) = *(uint *)(param_2 + 2) | 0x1000;
                *(int *)((long)param_2 + 0x44) = piVar4[0xf];
                uVar5 = piVar4[2];
                if ((uVar5 >> 0xd & 1) != 0) goto LAB_fffffff00a4b09bc;
LAB_fffffff00a4b056c:
                if ((uVar5 >> 0xe & 1) == 0) goto LAB_fffffff00a4b0570;
LAB_fffffff00a4b09d8:
                *(uint *)(param_2 + 2) = *(uint *)(param_2 + 2) | 0x4000;
                *(int *)((long)param_2 + 0x4c) = piVar4[0x11];
                if (((uint)piVar4[2] >> 0xf & 1) != 0) goto LAB_fffffff00a4b09f4;
LAB_fffffff00a4b0574:
                uVar5 = piVar4[2];
              }
              if ((uVar5 >> 0x10 & 1) != 0) {
                *(uint *)(param_2 + 2) = *(uint *)(param_2 + 2) | 0x10000;
                *(int *)((long)param_2 + 0x54) = piVar4[0x13];
                uVar5 = piVar4[2];
              }
              if ((uVar5 >> 0x11 & 1) != 0) {
                *(uint *)(param_2 + 2) = *(uint *)(param_2 + 2) | 0x20000;
                *(int *)(param_2 + 0xb) = piVar4[0x14];
                uVar5 = piVar4[2];
              }
              if ((uVar5 >> 0x12 & 1) != 0) {
                *(uint *)(param_2 + 2) = *(uint *)(param_2 + 2) | 0x40000;
                *(int *)((long)param_2 + 0x5c) = piVar4[0x15];
              }
            }
          }
LAB_fffffff00a4b0a78:
          FUN_fffffff00a228d30(puVar7 + 0x928);
          uVar9 = 0;
          puVar8 = puVar7;
          goto LAB_fffffff00a4b0a84;
        }
        lVar3 = *(long *)(lVar3 + 0x38);
      } while (lVar3 != 0);
      uVar9 = 0x16;
      puVar8 = &DAT_fffffff00ad7cc50;
    }
LAB_fffffff00a4b0a84:
    FUN_fffffff00a228d30(puVar8);
  }
  return uVar9;
}

