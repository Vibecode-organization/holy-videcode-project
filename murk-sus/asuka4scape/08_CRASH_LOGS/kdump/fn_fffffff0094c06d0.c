// FUN_fffffff0094c06d0 @ fffffff0094c06d0 size=2156
// CALLERS:
//   fffffff00afb802a ?
//   fffffff0094c494c FUN_fffffff0094c4848@fffffff0094c4848
//   fffffff0094c0f5c FUN_fffffff0094c0f3c@fffffff0094c0f3c
// CALLS:
//   fffffff0094c9a44 thunk_EXT_FUN_8011000003147660
//   fffffff0094c1f20 FUN_fffffff0094c1f20
//   fffffff0094c9bb4 thunk_EXT_FUN_80110000033502b4
//   fffffff0094c1ff0 FUN_fffffff0094c1ff0
//   fffffff0094c9a24 thunk_EXT_FUN_8011000003142260
//   fffffff0094c9bc4 thunk_EXT_FUN_8011000003a61b10
//   fffffff0094c20ac FUN_fffffff0094c20ac
//   fffffff0094c03ec FUN_fffffff0094c03ec
//   fffffff0094c6eac FUN_fffffff0094c6eac
//   fffffff0094c9a04 thunk_EXT_FUN_8011000003138628
//   fffffff0094c2ebc FUN_fffffff0094c2ebc
//   fffffff0094c9a74 thunk_EXT_FUN_801100000314fbc8
//   fffffff0094c99c4 thunk_EXT_FUN_8011000003a48590
//   fffffff0094c1d04 FUN_fffffff0094c1d04
//   fffffff0094c1b1c FUN_fffffff0094c1b1c
//   fffffff0094c1bd8 FUN_fffffff0094c1bd8
//   fffffff0094c9a84 thunk_EXT_FUN_8011000003150330
//   fffffff0094c9a54 thunk_EXT_FUN_80110000031479ac
//   fffffff0094c9a64 thunk_EXT_FUN_801100000314e898

void FUN_fffffff0094c06d0(ulong param_1,long param_2,long param_3)

{
  undefined8 *puVar1;
  undefined8 ****ppppuVar2;
  uint uVar3;
  int iVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  undefined8 ***pppuVar9;
  code *pcVar10;
  bool bVar11;
  int iVar12;
  long lVar13;
  ulong *puVar14;
  undefined8 uVar15;
  ulong uVar16;
  ulong uVar17;
  undefined4 uVar18;
  undefined8 ****ppppuVar19;
  undefined1 *puVar20;
  long extraout_x8;
  undefined8 *puVar21;
  undefined8 *puVar22;
  undefined8 *puVar23;
  ulong extraout_x12;
  long extraout_x13;
  ulong extraout_x14;
  uint uVar24;
  ulong uVar25;
  undefined8 *puVar26;
  undefined8 uStack_120;
  undefined4 local_118;
  uint local_114;
  undefined8 local_110;
  uint local_104;
  undefined8 *local_100;
  ulong uStack_f8;
  undefined8 ***local_f0;
  undefined8 ***local_e8;
  undefined1 *local_e0;
  undefined1 *local_d8;
  undefined8 ***local_d0 [2];
  undefined4 local_c0;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  long local_70;
  
  local_70 = *(long *)PTR_DAT_fffffff007f5bb60;
  puVar1 = (undefined8 *)(param_3 + 0x18);
  if ((undefined8 *)(param_3 + 0x28) < puVar1) goto LAB_fffffff0094c0f10;
  lVar13 = FUN_fffffff0094c2ebc(puVar1);
  if (lVar13 == 0) {
    uVar25 = 0x50002;
  }
  else {
    puVar14 = (ulong *)(**(code **)(lVar13 + 0x18))();
    uStack_88 = 0;
    local_90 = 0;
    uStack_78 = 0;
    uStack_80 = 0;
    uStack_a8 = 0;
    local_b0 = 0;
    uStack_98 = 0;
    uStack_a0 = 0;
    puVar23 = *(undefined8 **)(param_2 + 0x68);
    uVar25 = *(ulong *)(param_2 + 0x70);
    if ((uVar25 == 0) || (puVar23 == (undefined8 *)0x0)) {
      if ((*(long *)(param_2 + 0x50) == 0) || (*(long *)(param_2 + 0x48) == 0)) {
        if (puVar23 != (undefined8 *)0x0) goto LAB_fffffff0094c079c;
        goto LAB_fffffff0094c0ba4;
      }
      puVar23 = &local_b0;
      uVar15 = thunk_EXT_FUN_801100000314e898
                         (puVar14,*(long *)(param_2 + 0x50),*(long *)(param_2 + 0x48),&local_b0);
      uVar25 = *puVar14;
      if (0x40 < uVar25) goto LAB_fffffff0094c0f10;
    }
    else {
LAB_fffffff0094c079c:
      if (*puVar14 != uVar25) {
LAB_fffffff0094c0ba4:
        *(undefined4 *)(param_3 + 0xa8) = 0x5001e;
        uVar25 = 0x5001e;
        goto LAB_fffffff0094c0ed8;
      }
      if (0x40 < uVar25) goto LAB_fffffff0094c0f10;
      uVar15 = thunk_EXT_FUN_8011000003a61b10(&local_b0,puVar23,uVar25);
    }
    *(undefined8 **)(param_3 + 0x80) = puVar23;
    *(ulong *)(param_3 + 0x88) = uVar25;
    uVar25 = *(ulong *)(param_3 + 0x30);
    if (uVar25 == 0) {
LAB_fffffff0094c0da0:
      if (param_1 + 0x18 <= param_1) goto LAB_fffffff0094c0f10;
      uVar25 = FUN_fffffff0094c03ec(uVar15,param_2,param_3);
      iVar12 = (int)uVar25;
      if (iVar12 < 0x80007) {
        if (iVar12 != 0) {
          if (iVar12 != 0x80005) goto LAB_fffffff0094c0ec4;
          goto LAB_fffffff0094c0e1c;
        }
      }
      else {
        if (iVar12 == 0x80007) {
LAB_fffffff0094c0e1c:
          *(int *)(param_3 + 0xa8) = iVar12;
          uVar25 = 0;
          goto LAB_fffffff0094c0ed8;
        }
        if (iVar12 == 0x80009) {
          uVar18 = 0x80009;
        }
        else {
          if (iVar12 != 0x80008) goto LAB_fffffff0094c0ec4;
          if (*(int *)(param_3 + 0xa8) != 0x70001) goto LAB_fffffff0094c0e34;
          uVar18 = 0x80008;
        }
        *(undefined4 *)(param_3 + 0xa8) = uVar18;
      }
LAB_fffffff0094c0e34:
      uVar25 = *puVar14;
      if (0x40 < uVar25) {
LAB_fffffff0094c0f10:
                    /* WARNING: Does not return */
        pcVar10 = (code *)SoftwareBreakpoint(0x5519,0xfffffff0094c0f14);
        (*pcVar10)();
      }
      local_100 = &local_b0;
      uVar16 = *(ulong *)(param_3 + 0x98);
      uStack_f8 = uVar25;
      if (uVar16 + 0x130 < uVar16) goto LAB_fffffff0094c0f10;
      uVar25 = FUN_fffffff0094c6eac
                         (0x1d,*(undefined4 *)(param_1 + 0xc),uVar16,&local_100,puVar1,
                          param_3 + 0x58);
      iVar12 = (int)uVar25;
      if (((iVar12 == 0) || (iVar12 == 0xa0120)) || (iVar12 == 0xa0110)) {
        iVar4 = *(int *)(param_3 + 0xa8);
        if (((iVar4 == 0) || (iVar4 == 0x70001)) || (iVar4 == 0x50001)) {
          *(int *)(param_3 + 0xa8) = iVar12;
        }
        uVar25 = 0;
      }
    }
    else {
      if (param_1 + 0x18 < param_1) goto LAB_fffffff0094c0f10;
      ppppuVar19 = *(undefined8 *****)(param_3 + 0x28);
      if (CARRY8((ulong)ppppuVar19,uVar25)) goto LAB_fffffff0094c0f20;
      ppppuVar2 = (undefined8 ****)((long)ppppuVar19 + uVar25);
      if (ppppuVar2 < ppppuVar19) goto LAB_fffffff0094c0f10;
      local_e0 = &DAT_aaaaaaaaaaaaaaaa;
      local_d0[0] = ppppuVar19;
      local_d0[1] = ppppuVar2;
      if (ppppuVar19 < ppppuVar2) {
        uVar24 = 0;
        bVar8 = false;
        bVar7 = false;
        bVar6 = false;
        bVar5 = false;
        bVar11 = false;
        local_118 = 0x40002;
        uStack_120._4_4_ = 0x40005;
        local_104 = 0x40003;
        local_114 = 0x40004;
        local_110 = 0x2000000000000010;
        do {
          iVar12 = thunk_EXT_FUN_8011000003138628(local_d0,local_110,&local_e0);
          if (iVar12 == 0) {
            uVar25 = 0x40001;
            goto LAB_fffffff0094c0ec4;
          }
          if (CARRY8((ulong)local_d0[0],(ulong)local_e0)) goto LAB_fffffff0094c0f20;
          ppppuVar19 = (undefined8 ****)((long)local_d0[0] + (long)local_e0);
          if (ppppuVar19 < local_d0[0] || local_d0[1] < ppppuVar19) goto LAB_fffffff0094c0f10;
          local_f0 = local_d0[0];
          local_e8 = ppppuVar19;
          iVar12 = thunk_EXT_FUN_8011000003138628(&local_f0,6,&local_e0);
          pppuVar9 = local_f0;
          if (iVar12 == 0) {
            puVar20 = &stack0xffffffffffffffe8;
LAB_fffffff0094c0bd0:
            uVar25 = (ulong)*(uint *)(puVar20 + -0x100);
            goto LAB_fffffff0094c0ec4;
          }
          if (CARRY8((ulong)local_f0,(ulong)local_e0)) goto LAB_fffffff0094c0f20;
          ppppuVar2 = (undefined8 ****)((long)local_f0 + (long)local_e0);
          if ((local_e8 < ppppuVar2) || (ppppuVar2 < local_f0)) goto LAB_fffffff0094c0f10;
          if (local_e0 != (undefined1 *)0x9) {
LAB_fffffff0094c0bd8:
            local_f0 = ppppuVar2;
            uVar25 = 0x40006;
            goto LAB_fffffff0094c0ec4;
          }
          uVar25 = (long)local_e8 - (long)local_f0;
          local_f0 = ppppuVar2;
          if (uVar25 < 9) goto LAB_fffffff0094c0f10;
          iVar12 = thunk_EXT_FUN_80110000033502b4(pppuVar9,&DAT_fffffff0077688a4,9);
          if (iVar12 != 0) {
            ppppuVar2 = (undefined8 ****)local_f0;
            if (local_e0 == (undefined1 *)0x9) {
              iVar12 = thunk_EXT_FUN_80110000033502b4(pppuVar9,&DAT_fffffff0077688ad,9);
              if (iVar12 == 0) {
                if (uVar24 >> 1 != 0) goto LAB_fffffff0094c0be4;
                local_d8 = &DAT_aaaaaaaaaaaaaaaa;
                iVar12 = thunk_EXT_FUN_8011000003138628(&local_f0,0x2000000000000011,&local_d8);
                uVar3 = local_104;
                if (iVar12 != 0) {
                  iVar12 = FUN_fffffff0094c1bd8(&local_f0);
                  uVar3 = 0;
                  if (iVar12 == 0) {
                    uVar3 = local_114;
                  }
                }
                uVar25 = (ulong)uVar3;
                uVar24 = uVar24 | 2;
                goto LAB_fffffff0094c0b68;
              }
              ppppuVar2 = (undefined8 ****)local_f0;
              if (local_e0 != (undefined1 *)0x9) goto LAB_fffffff0094c0bd8;
              iVar12 = thunk_EXT_FUN_80110000033502b4(pppuVar9,&DAT_fffffff0077688da,9);
              if (iVar12 == 0) {
                if (bVar11) goto LAB_fffffff0094c0be4;
                bVar11 = true;
                uVar25 = FUN_fffffff0094c1d04(&local_f0,param_3,param_1);
                goto LAB_fffffff0094c0b68;
              }
              ppppuVar2 = (undefined8 ****)local_f0;
              if (local_e0 != (undefined1 *)0x9) goto LAB_fffffff0094c0bd8;
              iVar12 = thunk_EXT_FUN_80110000033502b4(pppuVar9,&DAT_fffffff0077688b6,9);
              if (iVar12 == 0) {
                if (bVar5) goto LAB_fffffff0094c0be4;
                local_d8 = &DAT_aaaaaaaaaaaaaaaa;
                iVar12 = thunk_EXT_FUN_8011000003138628(&local_f0,0x2000000000000011,&local_d8);
                uVar3 = local_104;
                if (iVar12 != 0) {
                  iVar12 = FUN_fffffff0094c1f20(&local_f0);
                  uVar3 = 0;
                  if (iVar12 == 0) {
                    uVar3 = local_114;
                  }
                }
                uVar25 = (ulong)uVar3;
                bVar5 = true;
                goto LAB_fffffff0094c0b68;
              }
              ppppuVar2 = (undefined8 ****)local_f0;
              if (local_e0 != (undefined1 *)0x9) goto LAB_fffffff0094c0bd8;
              iVar12 = thunk_EXT_FUN_80110000033502b4(pppuVar9,&DAT_fffffff0077688d1,9);
              if (iVar12 == 0) {
                if (bVar6) goto LAB_fffffff0094c0be4;
                local_d8 = &DAT_aaaaaaaaaaaaaaaa;
                iVar12 = thunk_EXT_FUN_8011000003138628(&local_f0,0x2000000000000011,&local_d8);
                uVar3 = local_104;
                if (iVar12 != 0) {
                  iVar12 = FUN_fffffff0094c1ff0(&local_f0);
                  uVar3 = 0;
                  if (iVar12 == 0) {
                    uVar3 = local_114;
                  }
                }
                uVar25 = (ulong)uVar3;
                bVar6 = true;
                goto LAB_fffffff0094c0b68;
              }
              ppppuVar2 = (undefined8 ****)local_f0;
              if (local_e0 != (undefined1 *)0x9) goto LAB_fffffff0094c0bd8;
              iVar12 = thunk_EXT_FUN_80110000033502b4(pppuVar9,&DAT_fffffff0077688bf,9);
              if (iVar12 == 0) {
                if (!bVar7) {
                  bVar7 = true;
                  goto LAB_fffffff0094c0b6c;
                }
              }
              else {
                ppppuVar2 = (undefined8 ****)local_f0;
                if ((local_e0 != (undefined1 *)0x9) ||
                   (iVar12 = thunk_EXT_FUN_80110000033502b4(pppuVar9,&DAT_fffffff0077688c8,9),
                   ppppuVar2 = (undefined8 ****)local_f0, iVar12 != 0)) goto LAB_fffffff0094c0bd8;
                if (!bVar8) {
                  local_d8 = &DAT_aaaaaaaaaaaaaaaa;
                  iVar12 = thunk_EXT_FUN_8011000003138628(&local_f0,0x2000000000000011,&local_d8);
                  uVar3 = local_104;
                  if (iVar12 != 0) {
                    iVar12 = FUN_fffffff0094c20ac(&local_f0);
                    uVar3 = 0;
                    if (iVar12 == 0) {
                      uVar3 = local_114;
                    }
                  }
                  uVar25 = (ulong)uVar3;
                  bVar8 = true;
                  goto LAB_fffffff0094c0b68;
                }
              }
LAB_fffffff0094c0be4:
              puVar20 = &stack0xffffffffffffffe4;
              goto LAB_fffffff0094c0bd0;
            }
            goto LAB_fffffff0094c0bd8;
          }
          if ((uVar24 & 1) != 0) goto LAB_fffffff0094c0be4;
          local_d8 = &DAT_aaaaaaaaaaaaaaaa;
          iVar12 = thunk_EXT_FUN_8011000003138628(&local_f0,0x2000000000000011,&local_d8);
          uVar3 = local_104;
          if (iVar12 != 0) {
            iVar12 = FUN_fffffff0094c1b1c(&local_f0);
            uVar3 = 0;
            if (iVar12 == 0) {
              uVar3 = local_114;
            }
          }
          uVar25 = (ulong)uVar3;
          uVar24 = uVar24 | 1;
LAB_fffffff0094c0b68:
          if ((int)uVar25 != 0) goto LAB_fffffff0094c0ec4;
LAB_fffffff0094c0b6c:
          if ((local_d0[1] < ppppuVar19) || (ppppuVar19 < local_d0[0])) goto LAB_fffffff0094c0f10;
          local_d0[0] = ppppuVar19;
        } while (ppppuVar19 < local_d0[1]);
        if (((uVar24 ^ 0xffffffff) & 3) == 0) {
          uVar16 = thunk_EXT_FUN_80110000031479ac(0x2000000000000011);
          uVar15 = *(undefined8 *)(param_3 + 0x30);
          uVar17 = thunk_EXT_FUN_8011000003147660(uVar15);
          uVar25 = uVar16 + uVar17;
          if (CARRY8(uVar16,uVar17)) {
                    /* WARNING: Does not return */
            pcVar10 = (code *)SoftwareBreakpoint(0x5500,0xfffffff0094c0f2c);
            (*pcVar10)();
          }
          if (uVar25 < 0x15) {
            local_d0[1] = (undefined8 ***)&DAT_aaaaaaaaaaaaaaaa;
            local_d0[0] = (undefined8 ***)&DAT_aaaaaaaaaaaaaaaa;
            local_c0 = 0xaaaaaaaa;
            if (CARRY8((ulong)local_d0,uVar25)) goto LAB_fffffff0094c0f20;
            local_e8 = (undefined8 ***)((long)local_d0 + uVar25);
            local_f0 = local_d0;
            iVar12 = thunk_EXT_FUN_8011000003142260(&local_f0,0x2000000000000011,uVar15);
            if (iVar12 != 0) {
              uVar16 = puVar14[1] + 8;
              if (0xfffffffffffffff7 < puVar14[1]) {
                    /* WARNING: Does not return */
                pcVar10 = (code *)SoftwareBreakpoint(0x5500,0xfffffff0094c0f30);
                (*pcVar10)();
              }
              uVar17 = uVar16 + puVar14[2];
              if (CARRY8(uVar16,puVar14[2])) {
                    /* WARNING: Does not return */
                pcVar10 = (code *)SoftwareBreakpoint(0x5500,0xfffffff0094c0f34);
                (*pcVar10)();
              }
              if (0xfffffffffffffffb < uVar17) {
                    /* WARNING: Does not return */
                pcVar10 = (code *)SoftwareBreakpoint(0x5500,0xfffffff0094c0f38);
                (*pcVar10)();
              }
              if (0xfffffffffffffff7 < uVar17 + 4) {
                    /* WARNING: Does not return */
                pcVar10 = (code *)SoftwareBreakpoint(0x5500,0xfffffff0094c0f3c);
                (*pcVar10)();
              }
              (*DAT_fffffff007f5bb68)(uVar17 + 0xb & 0xfffffffffffffff8);
              lVar13 = -(extraout_x8 + 0xfU & 0xfffffffffffffff0);
              puVar26 = (undefined8 *)((long)&uStack_120 + lVar13);
              uVar16 = 0;
              puVar23 = (undefined8 *)((long)puVar26 + extraout_x14);
              puVar21 = puVar26;
              uVar17 = extraout_x12;
              if ((((ulong)puVar26 ^ (ulong)puVar23) & 0xffc0000000000000) != 0) {
                puVar23 = (undefined8 *)((ulong)puVar23 & 0xffffffffffff | 0xc8a2000000000000);
              }
              do {
                if ((((long)uVar16 < 0) || (extraout_x14 < uVar16)) ||
                   (bVar11 = uVar17 < 8, uVar17 = uVar17 - 8, bVar11)) {
                    /* WARNING: Does not return */
                  pcVar10 = (code *)SoftwareBreakpoint(0x556f,0xfffffff0094c0f28);
                  (*pcVar10)();
                }
                puVar22 = puVar21 + 1;
                *puVar21 = &DAT_aaaaaaaaaaaaaaaa;
                uVar16 = uVar16 + 8;
                puVar21 = puVar22;
              } while (puVar22 != puVar23);
              puVar23 = puVar26 + extraout_x13;
              if ((((ulong)puVar26 ^ (ulong)puVar23) & 0xffc0000000000000) != 0) {
                puVar23 = (undefined8 *)((ulong)puVar23 & 0xffffffffffff | 0xc8a2000000000000);
              }
              puVar21 = (undefined8 *)((long)&local_118 + lVar13);
              if ((puVar23 < puVar21) || (puVar21 < puVar26)) goto LAB_fffffff0094c0f10;
              thunk_EXT_FUN_801100000314fbc8(puVar14,puVar26);
              thunk_EXT_FUN_8011000003150330(puVar14,puVar26,uVar25,local_d0);
              if ((*(long *)(param_3 + 0x30) == 0) && (*(long *)(param_3 + 0x28) != 0))
              goto LAB_fffffff0094c0f10;
              thunk_EXT_FUN_8011000003150330(puVar14,puVar26);
              uVar15 = (*(code *)puVar14[7])(puVar14,puVar26,&local_b0);
              goto LAB_fffffff0094c0da0;
            }
            uVar25 = 0x50008;
          }
          else {
            uVar25 = 0x50009;
          }
        }
        else {
          uVar25 = 0x4000c;
        }
      }
      else {
        uVar25 = 0x4000c;
      }
    }
LAB_fffffff0094c0ec4:
    if (*(undefined8 **)(param_3 + 0x80) == &local_b0) {
      *(undefined8 *)(param_3 + 0x80) = 0;
      *(undefined8 *)(param_3 + 0x88) = 0;
    }
  }
LAB_fffffff0094c0ed8:
  if (*(long *)PTR_DAT_fffffff007f5bb60 == local_70) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590(uVar25);
LAB_fffffff0094c0f20:
                    /* WARNING: Does not return */
  pcVar10 = (code *)SoftwareBreakpoint(0x5513,0xfffffff0094c0f24);
  (*pcVar10)();
}

