// FUN_fffffff00a8d96f4 @ fffffff00a8d96f4 size=3336
// CALLERS:
//   fffffff00a8d8700 FUN_fffffff00a8d8678@fffffff00a8d8678
//   fffffff00a8d87c8 FUN_fffffff00a8d8754@fffffff00a8d8754

/* WARNING: Type propagation algorithm not settling */

long * FUN_fffffff00a8d96f4
                 (char *param_1,ulong param_2,code *param_3,undefined8 param_4,ulong param_5,
                 undefined8 *param_6)

{
  long *plVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  int iVar7;
  uint uVar8;
  undefined8 *puVar9;
  ulong uVar10;
  long *plVar11;
  long lVar12;
  uint uVar13;
  code *pcVar14;
  long *plVar15;
  long *plVar16;
  long *plVar17;
  double dVar18;
  uint uVar19;
  uint uVar20;
  ulong uVar21;
  uint *puVar22;
  uint uVar23;
  uint *puVar24;
  ulong uVar25;
  ulong uVar26;
  undefined1 auVar27 [16];
  long *local_100;
  uint local_f4;
  long local_f0;
  long *local_c0;
  long *local_b0;
  long *local_a8;
  long *local_a0;
  long *local_98;
  long local_90;
  long *local_80;
  uint local_74;
  
  if (param_6 != (undefined8 *)0x0) {
    *param_6 = 0;
  }
  if ((param_2 < 4) ||
     (((bVar4 = *param_1 == -0x2c, !bVar4 &&
       (iVar7 = FUN_fffffff00aa7451c(&DAT_fffffff007043a08,param_1), iVar7 != 0)) ||
      (((ulong)param_1 & 3) != 0)))) {
    plVar15 = (long *)0x0;
  }
  else {
    uVar23 = 0;
    local_74 = 0;
    local_f4 = 0;
    local_90 = 0;
    local_f0 = 0;
    puVar22 = (uint *)(param_1 + 4);
    bVar5 = param_3 != (code *)0x0;
    uVar25 = 4;
    plVar16 = (long *)0x0;
    plVar15 = (long *)0x0;
    uVar19 = 0;
    local_80 = (long *)0x0;
    local_b0 = (long *)0x0;
    local_c0 = (long *)0x0;
    local_100 = (long *)0x0;
LAB_fffffff00a8d9838:
    uVar10 = uVar25 + 4;
    if (uVar10 <= param_2) {
      puVar24 = puVar22 + 1;
      uVar13 = *puVar22;
      uVar21 = (ulong)uVar13 & 0xffffff;
      uVar8 = (uVar13 & 0x7f000000) - 0x1000000 >> 0x18;
      uVar20 = (uint)uVar21;
      if (uVar8 < 7) {
        bVar3 = bVar4;
        if (uVar8 < 2) {
          if (uVar8 == 0) {
            plVar17 = (long *)(**(code **)(DAT_fffffff00ad95c70 + 0x68))();
            if ((plVar17 != (long *)0x0) &&
               (uVar25 = (**(code **)(*plVar17 + 0xd0))(plVar17,uVar21), (uVar25 & 1) == 0)) {
              (**(code **)(*plVar17 + 0x28))(plVar17);
              plVar17 = (long *)0x0;
            }
            bVar2 = false;
            local_a0 = (long *)0x0;
            local_98 = (long *)0x0;
            bVar6 = uVar20 != 0;
            puVar22 = puVar24;
            uVar25 = uVar10;
            local_a8 = plVar17;
          }
          else {
            if (uVar8 != 1) goto LAB_fffffff00a8da31c;
            plVar17 = (long *)(**(code **)(DAT_fffffff00ad95bd0 + 0x68))();
            if ((plVar17 != (long *)0x0) &&
               (uVar25 = (**(code **)(*plVar17 + 0xd0))(plVar17,uVar21), (uVar25 & 1) == 0)) {
              (**(code **)(*plVar17 + 0x28))(plVar17);
              plVar17 = (long *)0x0;
            }
            bVar2 = false;
            local_98 = (long *)0x0;
            local_a8 = (long *)0x0;
            bVar6 = uVar20 != 0;
            puVar22 = puVar24;
            uVar25 = uVar10;
            local_a0 = plVar17;
          }
        }
        else if (uVar8 == 2) {
          plVar17 = (long *)(**(code **)(DAT_fffffff00ad95e68 + 0x68))();
          if ((plVar17 != (long *)0x0) &&
             (uVar25 = (**(code **)(*plVar17 + 0xd0))(plVar17,uVar21), (uVar25 & 1) == 0)) {
            (**(code **)(*plVar17 + 0x28))(plVar17);
            plVar17 = (long *)0x0;
          }
          bVar2 = false;
          local_a8 = (long *)0x0;
          local_a0 = (long *)0x0;
          bVar6 = uVar20 != 0;
          puVar22 = puVar24;
          uVar25 = uVar10;
          local_98 = plVar17;
        }
        else {
          if ((uVar8 != 3) || (param_2 < uVar25 + 0xc)) goto LAB_fffffff00a8da31c;
          plVar17 = (long *)0x0;
          dVar18 = *(double *)(puVar22 + 1);
          if (uVar20 < 0x20) {
            if ((uVar20 == 8) || (uVar20 == 0x10)) goto LAB_fffffff00a8da0bc;
            if (uVar20 == 0x1f) {
              plVar17 = (long *)FUN_fffffff00a8cafcc((float)dVar18);
            }
          }
          else if (uVar20 < 0x3f) {
            if (uVar20 == 0x20) {
LAB_fffffff00a8da0bc:
              plVar17 = (long *)(**(code **)(DAT_fffffff00ad95dc8 + 0x68))();
              if ((plVar17 != (long *)0x0) &&
                 (uVar10 = (**(code **)(*plVar17 + 0x78))(plVar17,dVar18,uVar21), (uVar10 & 1) == 0)
                 ) {
                (**(code **)(*plVar17 + 0x28))(plVar17);
                plVar17 = (long *)0x0;
              }
            }
            else if (uVar20 == 0x3e) {
              plVar17 = (long *)FUN_fffffff00a8cb020(dVar18);
            }
          }
          else {
            if (uVar20 == 0x40) goto LAB_fffffff00a8da0bc;
            if (uVar20 == 0x3f) {
              plVar17 = (long *)FUN_fffffff00a8caf7c(dVar18);
            }
          }
          bVar6 = false;
          bVar2 = false;
          local_a0 = (long *)0x0;
          local_98 = (long *)0x0;
          local_a8 = (long *)0x0;
          puVar22 = puVar22 + 3;
          uVar25 = uVar25 + 0xc;
          bVar3 = false;
        }
      }
      else {
        uVar26 = (ulong)(uVar20 + 3 >> 2);
        if (uVar8 < 9) {
          if (uVar8 != 7) {
            if ((uVar8 == 8) && (uVar25 = uVar10 + uVar26 * 4, uVar25 <= param_2)) {
              plVar17 = (long *)(**(code **)(DAT_fffffff00ad95ee0 + 0x68))();
              if ((plVar17 != (long *)0x0) &&
                 (uVar10 = FUN_fffffff00a8d2050(plVar17,puVar24,uVar21), (uVar10 & 1) == 0)) {
                pcVar14 = *(code **)(*plVar17 + 0x28);
                goto LAB_fffffff00a8d9c0c;
              }
              goto LAB_fffffff00a8d9c1c;
            }
            goto LAB_fffffff00a8da31c;
          }
          if (((uVar20 == 0) || (uVar25 = uVar10 + uVar26 * 4, param_2 < uVar25)) ||
             (*(char *)((long)puVar24 + (ulong)(uVar20 - 1)) != '\0')) goto LAB_fffffff00a8da31c;
          plVar17 = (long *)FUN_fffffff00a8d42e4(puVar24);
          bVar6 = false;
          bVar2 = false;
          local_a0 = (long *)0x0;
          local_98 = (long *)0x0;
          local_a8 = (long *)0x0;
          puVar22 = puVar24 + uVar26;
          bVar3 = false;
        }
        else if (uVar8 == 9) {
          uVar25 = uVar10 + uVar26 * 4;
          if (param_2 < uVar25) goto LAB_fffffff00a8da31c;
          plVar17 = (long *)(**(code **)(DAT_fffffff00ad95c48 + 0x68))();
          if ((plVar17 != (long *)0x0) &&
             (uVar10 = (**(code **)(*plVar17 + 0x80))(plVar17,puVar24,uVar21), (uVar10 & 1) == 0)) {
            pcVar14 = *(code **)(*plVar17 + 0x28);
LAB_fffffff00a8d9c0c:
            (*pcVar14)(plVar17);
            plVar17 = (long *)0x0;
          }
LAB_fffffff00a8d9c1c:
          bVar6 = false;
          bVar2 = false;
          local_a0 = (long *)0x0;
          local_98 = (long *)0x0;
          local_a8 = (long *)0x0;
          puVar22 = puVar24 + uVar26;
          bVar3 = false;
        }
        else if (uVar8 == 10) {
          bVar6 = false;
          bVar2 = false;
          local_a0 = (long *)0x0;
          local_98 = (long *)0x0;
          local_a8 = (long *)0x0;
          plVar17 = &DAT_fffffff00add6e60;
          if (uVar20 != 0) {
            plVar17 = &DAT_fffffff00add6e58;
          }
          plVar17 = (long *)*plVar17;
          puVar22 = puVar24;
          uVar25 = uVar10;
          bVar3 = false;
        }
        else {
          if ((uVar8 != 0xb) || (local_74 <= uVar20)) goto LAB_fffffff00a8da31c;
          bVar6 = false;
          local_a0 = (long *)0x0;
          local_98 = (long *)0x0;
          local_a8 = (long *)0x0;
          bVar2 = true;
          plVar17 = *(long **)(local_90 + uVar21 * 8);
          puVar22 = puVar24;
          uVar25 = uVar10;
          bVar3 = false;
        }
      }
      if (plVar17 == (long *)0x0) goto LAB_fffffff00a8da31c;
      if (bVar3) {
        uVar25 = uVar25 + 4;
        if (uVar25 <= param_2) {
          puVar22 = puVar22 + 1;
          goto joined_r0xfffffff00a8d9cbc;
        }
        goto LAB_fffffff00a8da32c;
      }
joined_r0xfffffff00a8d9cbc:
      if (!bVar2) {
        if (((uVar23 & 0xff000000) == 0) && (uVar23 <= local_74)) {
          auVar27 = FUN_fffffff00a2217b4
                              (&DAT_fffffff007c875a1,local_90,uVar23 * 8,uVar23 * 8 + 0x200,0x41244,
                               0);
          lVar12 = auVar27._0_8_;
          uVar8 = (uint)(auVar27._8_8_ >> 3);
          if (0x7fffffff7 < auVar27._8_8_) {
            uVar8 = 0xffffffff;
          }
          if (lVar12 == 0) {
LAB_fffffff00a8da32c:
            (**(code **)(*plVar17 + 0x28))(plVar17);
LAB_fffffff00a8da34c:
            plVar15 = (long *)0x0;
            goto LAB_fffffff00a8da358;
          }
        }
        else {
          lVar12 = local_90;
          uVar8 = uVar23;
          if (uVar23 <= local_74) goto LAB_fffffff00a8da32c;
        }
        *(long **)(lVar12 + (ulong)local_74 * 8) = plVar17;
        local_74 = local_74 + 1;
        local_90 = lVar12;
        uVar23 = uVar8;
      }
      plVar1 = plVar15;
      if (local_80 == (long *)0x0) {
        plVar11 = plVar16;
        if (local_b0 == (long *)0x0) {
          if (local_c0 == (long *)0x0) {
            plVar1 = plVar17;
            if (plVar15 == (long *)0x0) goto LAB_fffffff00a8da078;
            goto LAB_fffffff00a8da31c;
          }
          if ((param_5 & 4) != 0 && bVar5) {
            plVar15 = (long *)(*param_3)(param_4,local_c0,0,plVar17);
            uVar10 = (**(code **)(*local_c0 + 0xf0))(local_c0,plVar15);
            goto LAB_fffffff00a8da04c;
          }
          uVar10 = (**(code **)(*local_c0 + 0xf0))(local_c0,plVar17);
        }
        else if ((param_5 & 2) != 0 && bVar5) {
          plVar15 = (long *)(*param_3)(param_4,local_b0,0,plVar17);
          uVar10 = (**(code **)(*local_b0 + 0xe8))(local_b0,plVar15);
LAB_fffffff00a8da04c:
          (**(code **)(*plVar15 + 0x28))(plVar15);
        }
        else {
          uVar10 = (**(code **)(*local_b0 + 0xe8))(local_b0,plVar17);
        }
        if ((uVar10 & 1) == 0) goto LAB_fffffff00a8da31c;
      }
      else {
        plVar11 = plVar17;
        if (plVar16 != (long *)0x0) {
          puVar9 = (undefined8 *)(**(code **)(*plVar16 + 0x38))(plVar16);
          do {
            plVar15 = plVar16;
            if (puVar9 == &DAT_fffffff00ad95eb8) goto LAB_fffffff00a8d9ea4;
            puVar9 = (undefined8 *)puVar9[2];
          } while (puVar9 != (undefined8 *)0x0);
          puVar9 = (undefined8 *)(**(code **)(*plVar16 + 0x38))(plVar16);
          do {
            if (puVar9 == &DAT_fffffff00ad95ee0) {
              plVar15 = (long *)FUN_fffffff00a8d4088(plVar16);
              if (plVar15 != (long *)0x0) goto LAB_fffffff00a8d9ea4;
              goto LAB_fffffff00a8da34c;
            }
            puVar9 = (undefined8 *)puVar9[2];
          } while (puVar9 != (undefined8 *)0x0);
          plVar16 = (long *)0x0;
          plVar15 = (long *)0x0;
LAB_fffffff00a8d9ea4:
          if (plVar17 == local_80) {
            if ((plVar15 != (long *)0x0) && (plVar15 != plVar16)) {
              uVar8 = 1;
              goto LAB_fffffff00a8d9f78;
            }
            plVar11 = (long *)0x0;
          }
          else {
            if ((param_5 & 1) != 0 && bVar5) {
              plVar11 = (long *)(*param_3)(param_4,local_80,plVar15,plVar17);
              uVar8 = (**(code **)(*local_80 + 0xf0))(local_80,plVar15,plVar11);
              (**(code **)(*plVar11 + 0x28))(plVar11);
            }
            else {
              uVar8 = (**(code **)(*local_80 + 0xf0))(local_80,plVar15,plVar17);
            }
            if ((plVar15 != (long *)0x0) && (plVar15 != plVar16)) {
LAB_fffffff00a8d9f78:
              (**(code **)(*plVar15 + 0x28))(plVar15);
              uVar8 = uVar8 & 1;
            }
            plVar15 = (long *)0x0;
            plVar11 = plVar15;
            if (uVar8 == 0) goto LAB_fffffff00a8da358;
          }
        }
      }
LAB_fffffff00a8da078:
      plVar15 = plVar1;
      plVar16 = plVar11;
      if (bVar6) {
        plVar1 = (long *)0x0;
        if (-1 < (int)uVar13) {
          plVar1 = local_100;
        }
        local_f4 = local_f4 + 1;
        if ((0x3f < uVar19) || (local_f4 < uVar19)) {
          lVar12 = local_f0;
          uVar13 = uVar19;
          if (local_f4 < uVar19) goto LAB_fffffff00a8da304;
LAB_fffffff00a8da3dc:
          plVar15 = (long *)0x0;
          goto LAB_fffffff00a8da358;
        }
        auVar27 = FUN_fffffff00a2217b4
                            (&DAT_fffffff007c875f1,local_f0,uVar19 << 3,uVar19 << 3 | 0x200,0x41244,
                             0);
        lVar12 = auVar27._0_8_;
        uVar13 = (uint)(auVar27._8_8_ >> 3);
        if (0x7fffffff7 < auVar27._8_8_) {
          uVar13 = 0xffffffff;
        }
        if (lVar12 == 0) goto LAB_fffffff00a8da3dc;
LAB_fffffff00a8da304:
        *(long **)(lVar12 + (ulong)local_f4 * 8) = plVar1;
        uVar19 = uVar13;
        local_f0 = lVar12;
        local_80 = local_a8;
        local_b0 = local_a0;
        local_c0 = local_98;
        local_100 = plVar17;
      }
      else if ((int)uVar13 < 0) {
        if (local_f4 == 0) goto LAB_fffffff00a8da358;
        do {
          local_100 = *(long **)(local_f0 + (ulong)local_f4 * 8);
          bVar6 = local_f4 != 1;
          local_f4 = local_f4 - 1;
        } while (local_100 == (long *)0x0 && bVar6);
        if (local_100 == (long *)0x0) goto LAB_fffffff00a8da358;
        puVar9 = (undefined8 *)(**(code **)(*local_100 + 0x38))(local_100);
        do {
          if (puVar9 == &DAT_fffffff00ad95c70) {
            local_b0 = (long *)0x0;
            local_c0 = (long *)0x0;
            local_80 = local_100;
            goto LAB_fffffff00a8d9838;
          }
          puVar9 = (undefined8 *)puVar9[2];
        } while (puVar9 != (undefined8 *)0x0);
        puVar9 = (undefined8 *)(**(code **)(*local_100 + 0x38))(local_100);
        do {
          if (puVar9 == &DAT_fffffff00ad95bd0) {
            local_80 = (long *)0x0;
            local_c0 = (long *)0x0;
            local_b0 = local_100;
            goto LAB_fffffff00a8d9838;
          }
          puVar9 = (undefined8 *)puVar9[2];
        } while (puVar9 != (undefined8 *)0x0);
        puVar9 = (undefined8 *)(**(code **)(*local_100 + 0x38))(local_100);
        while (puVar9 != &DAT_fffffff00ad95e68) {
          puVar9 = (undefined8 *)puVar9[2];
          if (puVar9 == (undefined8 *)0x0) goto LAB_fffffff00a8da3dc;
        }
        local_80 = (long *)0x0;
        local_b0 = (long *)0x0;
        local_c0 = local_100;
      }
      goto LAB_fffffff00a8d9838;
    }
LAB_fffffff00a8da31c:
    plVar15 = (long *)0x0;
LAB_fffffff00a8da358:
    if (uVar23 != 0) {
      iVar7 = local_74 - (plVar15 != (long *)0x0);
      if ((plVar15 != (long *)0x0) <= local_74 && iVar7 != 0) {
        uVar25 = (ulong)(plVar15 != (long *)0x0);
        do {
          (**(code **)(**(long **)(local_90 + uVar25 * 8) + 0x28))();
          uVar25 = uVar25 + 1;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
      }
      FUN_fffffff00a2212a8(&DAT_fffffff007c87641,local_90,(ulong)uVar23 << 3);
    }
    if (uVar19 != 0) {
      FUN_fffffff00a2212a8(&DAT_fffffff007c87691,local_f0,(ulong)uVar19 << 3);
    }
  }
  return plVar15;
}

