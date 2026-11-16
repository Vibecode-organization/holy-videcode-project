// FUN_fffffff00a5398b0 @ fffffff00a5398b0 size=1616

void FUN_fffffff00a5398b0
               (undefined8 *param_1,long param_2,uint param_3,long param_4,long param_5,long param_6
               )

{
  uint *puVar1;
  uint uVar2;
  ushort uVar3;
  undefined8 uVar4;
  code *pcVar5;
  int iVar6;
  ushort uVar7;
  long lVar8;
  undefined4 uVar9;
  byte *pbVar10;
  byte *pbVar11;
  long lVar12;
  uint uVar13;
  int *piVar14;
  undefined8 uVar15;
  long lVar16;
  long lVar17;
  byte *pbVar18;
  uint local_b4;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  long local_98;
  long local_90;
  long lStack_88;
  undefined8 uStack_80;
  int local_78;
  undefined4 uStack_74;
  undefined8 local_70;
  long local_68;
  
  local_68 = DAT_fffffff00ad30000;
  local_b0 = 0;
  lStack_88 = 0;
  local_90 = 0;
  local_78 = 0;
  uStack_74 = 0;
  uStack_80 = 0;
  local_70 = 0;
  if (((((int *)*param_1 == (int *)0x0) || (param_2 == 0)) || (*(int *)*param_1 == 0)) ||
     ((param_3 - 3 < 0xfffffffe || (param_4 == 0)))) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff00aa4d114("pf_route: invalid parameters @%s:%d");
  }
  local_b4 = 0;
  uVar7 = *(ushort *)(*(long *)(param_6 + 0xa0) + 6);
  *(ushort *)(*(long *)(param_6 + 0xa0) + 6) = uVar7 + 1;
  if (uVar7 < 4) {
    if (*(char *)(param_2 + 0x3fd) == '\x03') {
      lVar8 = FUN_fffffff00a556224(*param_1);
      uVar4 = uStack_80;
    }
    else {
      if ((*(char *)(param_2 + 0x3fd) == '\x04') != (param_3 != *(byte *)(param_2 + 0x3ed)))
      goto LAB_fffffff00a539a78;
      lVar8 = FUN_fffffff00a555fd4(*param_1,1);
      *param_1 = 0;
      uVar4 = uStack_80;
    }
    local_98 = lVar8;
    uStack_80 = uVar4;
    if (lVar8 != 0) {
      local_a8 = 0;
      uStack_a0 = 0;
      uVar15 = 0x2090002;
      if (*(int *)(lVar8 + 0x18) < 0x14) goto LAB_fffffff00a539a28;
      if ((*(ushort *)(lVar8 + 0x1e) & 1) == 0) {
        pbVar10 = (byte *)(lVar8 + 0xe0);
        pbVar11 = (byte *)(lVar8 + 0x200);
      }
      else {
        pbVar10 = *(byte **)(lVar8 + 0x20);
        pbVar11 = pbVar10 + *(uint *)(lVar8 + 0x30);
      }
      pbVar18 = *(byte **)(lVar8 + 0x10);
      if ((pbVar18 != (byte *)0x0) && ((pbVar11 <= pbVar18 || (pbVar18 < pbVar10))))
      goto LAB_fffffff00a539efc;
      lVar16 = (long)&uStack_80 + 4;
      uStack_80._6_2_ = (undefined2)((ulong)uVar4 >> 0x30);
      uStack_80._0_6_ = CONCAT24(0x210,(int)uVar4);
      local_78 = *(int *)(pbVar18 + 0x10);
      uVar15 = 0x2090004;
      if (*(char *)(param_2 + 0x3fd) == '\x01') {
        FUN_fffffff00a498318(&local_90);
        if (local_90 == 0) {
          DAT_fffffff00ad820e4 = DAT_fffffff00ad820e4 + 1;
          uVar15 = 0x2090003;
        }
        else {
          lVar17 = *(long *)(local_90 + 0x88);
          FUN_fffffff00a49df74(local_90,0);
          *(int *)(local_90 + 0xf4) = *(int *)(local_90 + 0xf4) + 1;
          if ((*(byte *)(local_90 + 0x74) >> 1 & 1) != 0) {
            lVar16 = *(long *)(local_90 + 0x80);
          }
          FUN_fffffff00a49deb4();
joined_r0xfffffff00a539c08:
          if (lVar17 != 0) {
            if (param_4 == lVar17) {
LAB_fffffff00a539c94:
              FUN_fffffff00a5c9fc0
                        (lVar17,lVar8,(*pbVar18 & 0xf) << 2,
                         *(ushort *)(pbVar18 + 2) >> 8 | *(ushort *)(pbVar18 + 2) << 8,&local_b4);
              uVar2 = *(uint *)(lVar17 + 0x100);
              if (((*(byte *)(lVar17 + 0xd5) >> 4 & 1) != 0) ||
                 ((*(long *)(lVar17 + 0x898) != 0 &&
                  ((*(byte *)(*(long *)(lVar17 + 0x898) + 0xd5) >> 4 & 1) != 0)))) {
                lVar12 = *(long *)(lVar17 + 0x920);
                uVar13 = uVar2;
                if ((lVar12 != 0) &&
                   ((*(int *)(lVar12 + 0x228) != 0 &&
                    ((uVar13 = *(uint *)(lVar12 + 0x22c), uVar13 == 0 || (uVar2 <= uVar13)))))) {
                  puVar1 = (uint *)(lVar12 + 0x230);
                  if (uVar2 <= *(uint *)(lVar12 + 0x230) || *(uint *)(lVar12 + 0x230) == 0) {
                    puVar1 = (uint *)(lVar17 + 0x100);
                  }
                  uVar13 = *puVar1;
                }
                uVar2 = uVar13 - 0x14;
              }
              uVar7 = *(ushort *)(pbVar18 + 2);
              if (((int)uVar2 < (int)((uint)(uVar7 >> 8) | (uVar7 & 0xff00ff) << 8)) &&
                 (((*(uint *)(lVar17 + 0x328) >> 0x15 & 1) == 0 ||
                  ((*(byte *)(lVar8 + 0x66) >> 4 & 1) == 0)))) {
                uVar3 = *(ushort *)(pbVar18 + 6);
                if ((uVar3 >> 6 & 1) == 0) {
                  if ((*(uint *)(lVar17 + 0x328) >> 4 & 1) != 0) goto LAB_fffffff00a539db0;
                  if ((*(byte *)(lVar8 + 0x66) >> 4 & 1) == 0) {
                    *(ushort *)(pbVar18 + 6) = uVar3 >> 8 | uVar3 << 8;
                    *(ushort *)(pbVar18 + 2) = uVar7 >> 8 | (ushort)((uVar7 & 0xff00ff) << 8);
                    iVar6 = FUN_fffffff00a5ca1d0(local_98,lVar17,uVar2,local_b4);
                    if (iVar6 == 0) {
                      iVar6 = 0;
                      local_98 = lVar8;
                      do {
                        lVar8 = *(long *)(local_98 + 8);
                        *(undefined8 *)(local_98 + 8) = 0;
                        if (iVar6 == 0) {
                          iVar6 = FUN_fffffff00a47b940(lVar17,2,local_98,local_90,lVar16,0,0);
                        }
                        else {
                          FUN_fffffff00a79337c(local_98,2,0x2090019,0,0);
                        }
                        local_98 = lVar8;
                      } while (lVar8 != 0);
                      local_98 = 0;
                      if (iVar6 == 0) {
                        DAT_fffffff00ad820d4 = DAT_fffffff00ad820d4 + 1;
                      }
                    }
                    goto LAB_fffffff00a539a44;
                  }
                }
                DAT_fffffff00ad820dc = DAT_fffffff00ad820dc + 1;
                if (*(char *)(param_2 + 0x3fd) == '\x03') {
                  uVar15 = 0x2090005;
                  goto joined_r0xfffffff00a539c40;
                }
                FUN_fffffff00a5be244(lVar8,3,4,0);
              }
              else {
LAB_fffffff00a539db0:
                pbVar18[10] = 0;
                pbVar18[0xb] = 0;
                if ((local_b4 & 1) != 0) {
                  uVar7 = FUN_fffffff00a798e5c(lVar8,0,(*pbVar18 & 0xf) << 2);
                  *(ushort *)(pbVar18 + 10) = ~uVar7;
                  local_b4 = local_b4 & 0xfffffffe;
                  *(uint *)(lVar8 + 100) = *(uint *)(lVar8 + 100) & 0xfffffffe;
                }
                FUN_fffffff00a47b940(lVar17,2,lVar8,local_90,lVar16,0,0);
              }
            }
            else {
              iVar6 = FUN_fffffff00a52df50(2,lVar17,&local_98,0,0);
              if (iVar6 == 0) {
                if (local_98 == 0) goto LAB_fffffff00a539a44;
                lVar8 = local_98;
                uVar15 = 0x2090002;
                if (*(int *)(local_98 + 0x18) < 0x14) goto LAB_fffffff00a539a28;
                if ((*(ushort *)(local_98 + 0x1e) & 1) == 0) {
                  pbVar10 = (byte *)(local_98 + 0xe0);
                  pbVar11 = (byte *)(local_98 + 0x200);
                }
                else {
                  pbVar10 = *(byte **)(local_98 + 0x20);
                  pbVar11 = pbVar10 + *(uint *)(local_98 + 0x30);
                }
                pbVar18 = *(byte **)(local_98 + 0x10);
                if ((pbVar18 != (byte *)0x0) && ((pbVar11 <= pbVar18 || (pbVar18 < pbVar10)))) {
LAB_fffffff00a539efc:
                    /* WARNING: Does not return */
                  pcVar5 = (code *)SoftwareBreakpoint(0x5519,0xfffffff00a539f00);
                  (*pcVar5)();
                }
                goto LAB_fffffff00a539c94;
              }
              uVar15 = 0x209000a;
joined_r0xfffffff00a539c40:
              lVar8 = local_98;
              if (local_98 != 0) goto LAB_fffffff00a539a28;
            }
            goto LAB_fffffff00a539a44;
          }
        }
      }
      else if (*(long *)(param_2 + 0x240) == 0) {
        uVar15 = 0x2090003;
      }
      else {
        if (param_5 == 0) {
          FUN_fffffff00a539f00(2,param_2,pbVar18 + 0xc,&local_a8,0,&local_b0);
          if ((int)local_a8 != 0) {
            local_78 = (int)local_a8;
          }
          lVar17 = *(long *)(*(long *)(param_2 + 0x250) + 0x50);
        }
        else {
          if (*(int *)(param_5 + 0xb0) != 0) {
            local_78 = *(int *)(param_5 + 0xb0);
          }
          lVar17 = *(long *)(param_5 + 0xe0);
        }
        if (lVar17 != 0) {
          lVar17 = *(long *)(lVar17 + 0xc0);
          goto joined_r0xfffffff00a539c08;
        }
      }
LAB_fffffff00a539a28:
      uVar9 = 1;
      if (param_3 == 2) {
        uVar9 = 2;
      }
      FUN_fffffff00a79337c(lVar8,uVar9,uVar15,0,0);
    }
  }
  else {
    piVar14 = (int *)*param_1;
    uVar9 = 1;
    if (param_3 == 2) {
      uVar9 = 2;
    }
    if (piVar14 != (int *)0x0) {
      if ((*piVar14 == 1) && (lVar8 = *(long *)(piVar14 + 2), lVar8 != 0)) {
        piVar14[2] = 0;
        piVar14[3] = 0;
        FUN_fffffff00a79337c(lVar8,uVar9,0x2090018,0,0);
      }
      FUN_fffffff00a555f0c(piVar14);
      *param_1 = 0;
    }
  }
LAB_fffffff00a539a44:
  if (local_90 != 0) {
    FUN_fffffff00a498684(local_90,0);
    local_90 = 0;
  }
  if (lStack_88 != 0) {
    piVar14 = (int *)(lStack_88 + 0x10);
    iVar6 = *piVar14;
    *piVar14 = iVar6 + -1;
    if (iVar6 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa61ea0(piVar14);
    }
    if (iVar6 == 1) {
      FUN_fffffff00a467064();
    }
  }
LAB_fffffff00a539a78:
  if (DAT_fffffff00ad30000 == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_fffffff00aa4c590();
}

