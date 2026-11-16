// FUN_fffffff00a4fc8e0 @ fffffff00a4fc8e0 size=1792

undefined4 FUN_fffffff00a4fc8e0(int param_1,undefined8 *param_2,long param_3,int param_4)

{
  uint *puVar1;
  long lVar2;
  undefined4 uVar3;
  uint uVar4;
  char cVar5;
  long lVar6;
  code *pcVar7;
  bool bVar8;
  bool bVar9;
  int iVar10;
  ulong uVar11;
  long *plVar12;
  ulong uVar13;
  ulong uVar14;
  uint uVar15;
  ulong uVar16;
  undefined4 uVar17;
  uint *puVar18;
  ulong uVar19;
  ulong uVar20;
  long lVar21;
  long lVar22;
  long *plVar23;
  int in_wzr;
  undefined4 uStack_e4;
  undefined4 local_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
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
  undefined8 local_80;
  long local_70;
  
  local_70 = DAT_fffffff00ad30000;
  FUN_fffffff00a228180(&DAT_fffffff00adcdd78);
  if (DAT_fffffff00adcddd8 != 0) {
    uVar17 = 0;
    lVar6 = tpidr_el1;
    lVar21 = DAT_fffffff00adcddd8;
    do {
      if (*(ulong *)(lVar21 + 0x58) == 0) {
        *(ulong *)(lVar21 + 0x58) = (ulong)*(uint *)(lVar6 + 0x4e8);
      }
      else {
        FUN_fffffff00a2262d4(lVar21 + 0x50,lVar6,0);
      }
      uVar11 = FUN_fffffff00a4fcfe0(lVar21,param_2);
      if (uVar11 == 0) {
        if (*(int *)(lVar21 + 0x58) == *(int *)(lVar6 + 0x4e8)) {
          *(int *)(lVar21 + 0x58) = in_wzr;
        }
        else {
          FUN_fffffff00a226e08(lVar21 + 0x50,lVar6);
        }
      }
      else {
        if (*(ulong *)(uVar11 + 0x38) == 0) {
          *(ulong *)(uVar11 + 0x38) = (ulong)*(uint *)(lVar6 + 0x4e8);
          if (param_1 != 0) goto LAB_fffffff00a4fc9c8;
LAB_fffffff00a4fc9d4:
          bVar8 = uVar11 + 0x5b0 <= uVar11;
          if (param_4 == 0) {
            if (bVar8) goto LAB_fffffff00a4fcf24;
            if ((*(byte *)((long)param_2 + 9) & 1) == 0) {
              lVar22 = *(long *)(uVar11 + 0x4a0);
            }
            else {
              local_80 = 0;
              uStack_98 = 0;
              local_a0 = 0;
              uStack_88 = 0;
              uStack_90 = 0;
              uStack_b8 = 0;
              local_c0 = 0;
              uStack_a8 = 0;
              uStack_b0 = 0;
              uStack_d4 = 0;
              uStack_c8 = 0;
              uStack_d0 = 0;
              uStack_dc = (undefined4)param_2[1];
              uStack_d8 = (undefined4)((ulong)param_2[1] >> 0x20);
              uStack_e4 = (undefined4)*param_2;
              local_e0 = (undefined4)((ulong)*param_2 >> 0x20);
              for (lVar22 = *(long *)(uVar11 + 0x4a0); lVar22 != 0;
                  lVar22 = *(long *)(lVar22 + 0x30)) {
                while (iVar10 = FUN_fffffff00a3542b4(&uStack_e4,lVar22 + 0x5c,0x10), -1 < iVar10) {
                  if ((iVar10 == 0) || (lVar22 = *(long *)(lVar22 + 0x38), lVar22 == 0))
                  goto LAB_fffffff00a4fca98;
                }
              }
            }
LAB_fffffff00a4fca98:
            if (lVar22 == 0) {
              if ((*(long *)(uVar11 + 0x4a0) != 0) || ((*(byte *)((long)param_2 + 9) & 1) != 0)) {
                bVar8 = false;
                cVar5 = *(char *)(uVar11 + 100);
                goto joined_r0xfffffff00a4fcb88;
              }
              lVar22 = FUN_fffffff00a4fd0fc(lVar21,uVar11);
              plVar12 = (long *)FUN_fffffff00a2216c4(&DAT_fffffff007c730d0,0x8004);
              *(ushort *)(plVar12 + 2) = *(ushort *)(plVar12 + 2) | 4;
              plVar12[3] = param_3;
              plVar12[4] = *(long *)(param_3 + 0x1f8);
              DAT_fffffff00adcdd58 = DAT_fffffff00adcdd58 + 1;
              plVar23 = (long *)(lVar22 + 0x90);
              lVar22 = *plVar23;
              if (lVar22 == 0) goto LAB_fffffff00a4fcb90;
              if (*(long **)(lVar22 + 8) != plVar23) {
                    /* WARNING: Does not return */
                pcVar7 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00a4fcfdc);
                (*pcVar7)();
              }
LAB_fffffff00a4fcaf4:
              *plVar12 = lVar22;
              *(long **)(*plVar23 + 8) = plVar12;
            }
            else {
              plVar12 = (long *)FUN_fffffff00a2216c4(&DAT_fffffff007c730d0,0x8004);
              *(ushort *)(plVar12 + 2) = *(ushort *)(plVar12 + 2) | 4;
              plVar12[3] = param_3;
              plVar12[4] = *(long *)(param_3 + 0x1f8);
              DAT_fffffff00adcdd58 = DAT_fffffff00adcdd58 + 1;
              plVar23 = (long *)(lVar22 + 0x90);
              lVar22 = *plVar23;
              if (lVar22 != 0) {
                if (*(long **)(lVar22 + 8) != plVar23) {
                    /* WARNING: Does not return */
                  pcVar7 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00a4fcfd4);
                  (*pcVar7)();
                }
                goto LAB_fffffff00a4fcaf4;
              }
LAB_fffffff00a4fcb90:
              *plVar12 = 0;
            }
            if (plVar12 + 0x16 <= plVar12) goto LAB_fffffff00a4fcf24;
            *plVar23 = (long)plVar12;
            plVar12[1] = (long)plVar23;
            bVar8 = true;
            cVar5 = *(char *)(uVar11 + 100);
          }
          else {
            if (bVar8) goto LAB_fffffff00a4fcf24;
            uVar3 = 0x16;
            if (*(long *)(uVar11 + 0x568) != 0) {
              uVar3 = uVar17;
            }
            cVar5 = *(char *)(uVar11 + 100);
            bVar8 = true;
            uVar17 = uVar3;
          }
joined_r0xfffffff00a4fcb88:
          if (cVar5 < '\0') {
            uVar20 = (ulong)*(uint *)(uVar11 + 0x5a0);
            if (uVar20 < 5) {
              lVar22 = 0;
              uVar13 = 0;
            }
            else {
              uVar19 = 0;
              uVar13 = 0;
              puVar18 = *(uint **)(uVar11 + 0x5a8);
              uVar14 = 5;
              do {
                if (puVar18 == (uint *)0x0) {
                  bVar9 = false;
                  uVar15 = 0;
                }
                else {
                  uVar16 = uVar19 & 0xffffffff;
                  if (uVar16 < uVar20) {
                    if ((uint *)((long)puVar18 + uVar16) < puVar18) goto LAB_fffffff00a4fcf24;
                    bVar9 = (char)*(uint *)((long)puVar18 + uVar16) == -0x35;
                  }
                  else {
                    bVar9 = false;
                  }
                  if (uVar20 < uVar16 + 5) {
                    uVar15 = 0;
                  }
                  else {
                    puVar1 = (uint *)((long)puVar18 + uVar16 + 1);
                    if (puVar1 < puVar18) goto LAB_fffffff00a4fcf24;
                    uVar15 = *puVar1;
                  }
                }
                uVar16 = (ulong)uVar15;
                if (uVar20 - uVar14 < uVar16) {
                  FUN_fffffff00a8df19c
                            (&MACH_HEADER,DAT_fffffff00ad7ce40,0x10,"%s: Invalid TLV length (%u)\n")
                  ;
                  lVar22 = 0;
                  break;
                }
                lVar22 = 0;
                if ((uVar15 != 0) && (puVar18 != (uint *)0x0)) {
                  uVar14 = uVar19 & 0xffffffff;
                  if (uVar20 < uVar14 + 5) {
                    lVar22 = 0;
                  }
                  else {
                    puVar1 = (uint *)((long)puVar18 + uVar14 + 1);
                    if (puVar1 < puVar18) goto LAB_fffffff00a4fcf24;
                    lVar22 = 0;
                    uVar4 = *puVar1;
                    if ((uVar4 != 0) && (uVar14 + 5 + (ulong)uVar4 <= uVar20)) {
                      puVar1 = (uint *)((long)puVar18 + uVar14 + 5);
                      if (puVar1 < puVar18) goto LAB_fffffff00a4fcf24;
                      if ((bool)(puVar1 != (uint *)0x0 & bVar9)) {
                        lVar22 = FUN_fffffff00a220c30(&DAT_fffffff007c6afb0,uVar16,4,0);
                        if (uVar4 < uVar15) goto LAB_fffffff00a4fcf24;
                        FUN_fffffff00aa65b10(lVar22,puVar1,uVar16);
                        uVar13 = uVar16;
                      }
                      else {
                        lVar22 = 0;
                      }
                    }
                  }
                }
                if (lVar22 != 0) break;
                lVar2 = uVar19 + uVar16;
                uVar19 = lVar2 + 5;
                uVar14 = lVar2 + 10;
              } while (uVar14 <= uVar20);
            }
            uVar20 = (ulong)*(uint *)(lVar6 + 0x4e8);
            if (DAT_fffffff00ad7ce38 != 0) {
              FUN_fffffff00a2262d4(&DAT_fffffff00ad7ce30,lVar6,0);
              uVar20 = DAT_fffffff00ad7ce38;
            }
            DAT_fffffff00ad7ce38 = uVar20;
            if (*(long *)(param_3 + 0x208) == 0) {
              *(long *)(param_3 + 0x208) = lVar22;
              *(ulong *)(param_3 + 0x200) = uVar13;
            }
            else {
              FUN_fffffff00a2212a8(&DAT_fffffff007c6afb0,lVar22);
            }
            if ((int)DAT_fffffff00ad7ce38 == *(int *)(lVar6 + 0x4e8)) {
              DAT_fffffff00ad7ce38 = CONCAT44(DAT_fffffff00ad7ce38._4_4_,in_wzr);
            }
            else {
              FUN_fffffff00a226e08(&DAT_fffffff00ad7ce30,lVar6);
            }
          }
        }
        else {
          FUN_fffffff00a2262d4(uVar11 + 0x30,lVar6,0);
          if (param_1 == 0) goto LAB_fffffff00a4fc9d4;
LAB_fffffff00a4fc9c8:
          if (*(int *)(uVar11 + 0x48c) == param_1) goto LAB_fffffff00a4fc9d4;
          bVar8 = false;
        }
        if (uVar11 + 0x5b0 <= uVar11) {
LAB_fffffff00a4fcf24:
                    /* WARNING: Does not return */
          pcVar7 = (code *)SoftwareBreakpoint(0x5519,0xfffffff00a4fcf28);
          (*pcVar7)();
        }
        if (*(int *)(uVar11 + 0x38) == *(int *)(lVar6 + 0x4e8)) {
          *(int *)(uVar11 + 0x38) = in_wzr;
        }
        else {
          FUN_fffffff00a226e08(uVar11 + 0x30,lVar6);
        }
        if (*(int *)(lVar21 + 0x58) == *(int *)(lVar6 + 0x4e8)) {
          *(int *)(lVar21 + 0x58) = in_wzr;
        }
        else {
          FUN_fffffff00a226e08(lVar21 + 0x50,lVar6);
        }
        if (bVar8) {
          FUN_fffffff00a228d30(&DAT_fffffff00adcdd78);
          uVar15 = *(uint *)(*(long *)(param_3 + 0x40) + 0x234);
          if (((uVar15 >> 0x13 & 1) == 0) &&
             (*(uint *)(*(long *)(param_3 + 0x40) + 0x234) = uVar15 | 0x80000,
             DAT_fffffff00ad95500 != 0x7fffffffffffffff)) {
            DAT_fffffff00ad95500 = DAT_fffffff00ad95500 + 1;
          }
          goto LAB_fffffff00a4fcf38;
        }
      }
      lVar21 = *(long *)(lVar21 + 8);
    } while (lVar21 != 0);
  }
  FUN_fffffff00a228d30(&DAT_fffffff00adcdd78);
  uVar17 = 2;
LAB_fffffff00a4fcf38:
  if (DAT_fffffff00ad30000 == local_70) {
    return uVar17;
  }
                    /* WARNING: Subroutine does not return */
  FUN_fffffff00aa4c590();
}

