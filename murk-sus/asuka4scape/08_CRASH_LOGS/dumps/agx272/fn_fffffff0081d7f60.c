// FUN_fffffff0081d7f60 @ fffffff0081d7f60 size=2884

/* WARNING: Removing unreachable block (ram,0xfffffff0081d85dc) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081d8560) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081d84e0) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081d8454) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081d8220) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081d81d4) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081d840c) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081d849c) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081d8520) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081d85a0) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081d8a40) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081d8194) */

void FUN_fffffff0081d7f60(long *param_1)

{
  bool bVar1;
  ushort uVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  ulong uVar6;
  long lVar7;
  ulong uVar8;
  ulong uVar9;
  uint uVar10;
  ulong uVar11;
  long lVar12;
  ulong uVar13;
  ulong uVar14;
  uint uVar15;
  ulong uVar16;
  uint uVar17;
  ulong uVar18;
  ulong uVar19;
  ulong uVar20;
  long lVar21;
  ulong uVar22;
  ulong local_d0;
  ulong uStack_c8;
  ulong local_c0 [6];
  undefined2 local_8a;
  ulong local_88;
  ulong uStack_80;
  ulong local_78 [3];
  
  lVar4 = thunk_EXT_FUN_8011000003890f30(param_1[0x29],&DAT_fffffff00ae222c8);
  if (lVar4 != 0) {
    lVar4 = 0;
    lVar21 = param_1[0x29];
    do {
      thunk_EXT_FUN_80110000029490c4(lVar21,lVar4);
      lVar4 = lVar4 + 1;
    } while (lVar4 != 0x80);
  }
  iVar3 = (**(code **)(*(long *)param_1[0x96] + 0x2a0))();
  if (iVar3 != 0) {
    lVar4 = 0;
    do {
      for (uVar17 = (&DAT_fffffff007114150)[lVar4 * 2];
          uVar17 <= (uint)(&DAT_fffffff007114154)[lVar4 * 2]; uVar17 = uVar17 + 0x40) {
      }
      lVar4 = lVar4 + 1;
    } while (lVar4 != 0xa3);
    lVar4 = 0;
    do {
      lVar12 = lVar4 * 0xd;
      uVar20 = (ulong)*(uint *)((long)&DAT_fffffff007114670 + lVar12);
      uVar5 = (**(code **)(*param_1 + 0x958))(param_1,uVar20);
      lVar21 = (**(code **)(*param_1 + 0x948))(*param_1 + 0x948,param_1,uVar20);
      (**(code **)(*param_1 + 0x950))(*param_1 + 0x950,param_1,uVar20);
      uVar22 = lVar21 << (uVar5 & 0x3f);
      local_c0[4] = local_c0[4] & 0xffffffffffffff00;
      local_d0 = 0;
      uStack_c8 = 0;
      uVar6 = (**(code **)(*param_1 + 0x940))
                        (*param_1 + 0x940,param_1,(&DAT_fffffff007114674)[lVar12],local_c0 + 4,
                         &local_d0);
      if (uVar22 != 0) {
        uVar13 = 0;
LAB_fffffff0081d826c:
        uVar18 = 0;
        uStack_80 = uVar6;
        local_88 = local_c0[4] & 1;
        local_78[1] = uStack_c8;
        local_78[0] = local_d0;
        do {
          if ((local_c0[4] & 1) == 0) {
            if (uVar6 <= uVar18) goto LAB_fffffff0081d8260;
            uVar17 = (uint)uVar18;
            uVar18 = (ulong)(uVar17 + 1);
          }
          else {
            if (local_78[1] == 0 && local_78[0] == 0) goto LAB_fffffff0081d8260;
            uVar17 = 0x40;
            uVar16 = local_78[1];
            if (local_78[0] != 0) {
              uVar17 = 0;
              uVar16 = local_78[0];
            }
            uVar16 = (uVar16 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar16 & 0x5555555555555555) << 1;
            uVar16 = (uVar16 & 0xcccccccccccccccc) >> 2 | (uVar16 & 0x3333333333333333) << 2;
            uVar16 = (uVar16 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar16 & 0xf0f0f0f0f0f0f0f) << 4;
            uVar16 = (uVar16 & 0xff00ff00ff00ff00) >> 8 | (uVar16 & 0xff00ff00ff00ff) << 8;
            uVar16 = (uVar16 & 0xffff0000ffff0000) >> 0x10 | (uVar16 & 0xffff0000ffff) << 0x10;
            uVar17 = uVar17 | (uint)LZCOUNT(uVar16 >> 0x20 | uVar16 << 0x20);
            if (local_78[0] == 0 && local_78[1] == 0) {
              uVar17 = 0xffffffff;
            }
            uVar16 = (ulong)(uVar17 >> 3) & 0x1ffffff8;
            *(ulong *)((long)local_78 + uVar16) =
                 *(ulong *)((long)local_78 + uVar16) &
                 (1L << ((ulong)uVar17 & 0x3f) ^ 0xffffffffffffffffU);
          }
          *(uint *)(param_1[0x61] + uVar20) = uVar17 | (uint)uVar13;
          for (uVar17 = *(uint *)((long)&DAT_fffffff007114668 + lVar12);
              uVar17 <= *(uint *)((long)&DAT_fffffff00711466c + lVar12); uVar17 = uVar17 + 0x40) {
          }
        } while( true );
      }
LAB_fffffff0081d812c:
      lVar4 = lVar4 + 1;
    } while (lVar4 != 0x81);
    lVar4 = 0;
    do {
      lVar21 = lVar4 * 0x12;
      local_8a = 0;
      local_c0[4] = 0;
      local_c0[5] = 0;
      local_c0[2] = 0;
      local_c0[3] = 0;
      uVar5 = (**(code **)(*param_1 + 0x940))
                        (*param_1 + 0x940,param_1,(&DAT_fffffff007114d01)[lVar21],
                         (long)&local_8a + 1,local_c0 + 4);
      uVar6 = (**(code **)(*param_1 + 0x940))
                        (*param_1 + 0x940,param_1,(&DAT_fffffff007114d06)[lVar21],&local_8a,
                         local_c0 + 2);
      uVar18 = (ulong)*(uint *)((long)&DAT_fffffff007114cfd + lVar21);
      uVar20 = (**(code **)(*param_1 + 0x958))(*param_1 + 0x958,param_1,uVar18);
      uVar16 = (ulong)*(uint *)((long)&DAT_fffffff007114d02 + lVar21);
      uVar22 = (**(code **)(*param_1 + 0x958))(*param_1 + 0x958,param_1,uVar16);
      lVar12 = (**(code **)(*param_1 + 0x948))(*param_1 + 0x948,param_1,uVar18);
      lVar7 = (**(code **)(*param_1 + 0x948))(*param_1 + 0x948,param_1,uVar16);
      (**(code **)(*param_1 + 0x950))(*param_1 + 0x950,param_1,uVar18);
      (**(code **)(*param_1 + 0x950))(*param_1 + 0x950,param_1,uVar16);
      uVar2 = local_8a;
      uVar13 = lVar12 << (uVar20 & 0x3f);
      if (uVar13 != 0) {
        uVar14 = lVar7 << (uVar22 & 0x3f);
        lVar12 = (long)(1 << (ulong)((uint)uVar20 & 0x1f));
        if (uVar14 != 0) {
          uVar20 = 0;
LAB_fffffff0081d8640:
          uVar19 = 0;
          local_78[1] = local_c0[5];
          local_78[0] = local_c0[4];
LAB_fffffff0081d8654:
          uVar17 = (uint)uVar19;
          if ((uVar2 & 0x100) == 0) {
            if (uVar5 <= uVar19) goto LAB_fffffff0081d8634;
            uVar19 = (ulong)(uVar17 + 1);
          }
          else {
            if (local_78[1] == 0 && local_78[0] == 0) goto LAB_fffffff0081d8634;
            uVar8 = local_78[1];
            uVar17 = 0x40;
            if (local_78[0] != 0) {
              uVar17 = 0;
              uVar8 = local_78[0];
            }
            uVar8 = (uVar8 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar8 & 0x5555555555555555) << 1;
            uVar8 = (uVar8 & 0xcccccccccccccccc) >> 2 | (uVar8 & 0x3333333333333333) << 2;
            uVar8 = (uVar8 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar8 & 0xf0f0f0f0f0f0f0f) << 4;
            uVar8 = (uVar8 & 0xff00ff00ff00ff00) >> 8 | (uVar8 & 0xff00ff00ff00ff) << 8;
            uVar8 = (uVar8 & 0xffff0000ffff0000) >> 0x10 | (uVar8 & 0xffff0000ffff) << 0x10;
            uVar17 = uVar17 | (uint)LZCOUNT(uVar8 >> 0x20 | uVar8 << 0x20);
            if (local_78[0] == 0 && local_78[1] == 0) {
              uVar17 = 0xffffffff;
            }
            uVar8 = (ulong)(uVar17 >> 3) & 0x1ffffff8;
            *(ulong *)((long)local_78 + uVar8) =
                 *(ulong *)((long)local_78 + uVar8) &
                 (1L << ((ulong)uVar17 & 0x3f) ^ 0xffffffffffffffffU);
          }
          uVar8 = 0;
LAB_fffffff0081d86d0:
          uVar11 = 0;
          local_c0[1] = local_c0[3];
          local_c0[0] = local_c0[2];
          do {
            if ((uVar2 & 1) == 0) {
              if (uVar6 <= uVar11) goto LAB_fffffff0081d86c4;
              uVar10 = (uint)uVar11;
              uVar11 = (ulong)(uVar10 + 1);
            }
            else {
              if (local_c0[1] == 0 && local_c0[0] == 0) goto LAB_fffffff0081d86c4;
              uVar9 = local_c0[1];
              uVar10 = 0x40;
              if (local_c0[0] != 0) {
                uVar10 = 0;
                uVar9 = local_c0[0];
              }
              uVar9 = (uVar9 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar9 & 0x5555555555555555) << 1;
              uVar9 = (uVar9 & 0xcccccccccccccccc) >> 2 | (uVar9 & 0x3333333333333333) << 2;
              uVar9 = (uVar9 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar9 & 0xf0f0f0f0f0f0f0f) << 4;
              uVar9 = (uVar9 & 0xff00ff00ff00ff00) >> 8 | (uVar9 & 0xff00ff00ff00ff) << 8;
              uVar9 = (uVar9 & 0xffff0000ffff0000) >> 0x10 | (uVar9 & 0xffff0000ffff) << 0x10;
              uVar10 = uVar10 | (uint)LZCOUNT(uVar9 >> 0x20 | uVar9 << 0x20);
              if (local_c0[0] == 0 && local_c0[1] == 0) {
                uVar10 = 0xffffffff;
              }
              uVar9 = (ulong)(uVar10 >> 3) & 0x1ffffff8;
              *(ulong *)((long)local_c0 + uVar9) =
                   *(ulong *)((long)local_c0 + uVar9) &
                   (1L << ((ulong)uVar10 & 0x3f) ^ 0xffffffffffffffffU);
            }
            lVar7 = param_1[0x61];
            *(uint *)(lVar7 + uVar18) = uVar17 | (uint)uVar20;
            *(uint *)(uVar16 + lVar7) = uVar10 | (uint)uVar8;
            for (uVar10 = *(uint *)((long)&DAT_fffffff007114cf5 + lVar21);
                uVar10 <= *(uint *)((long)&DAT_fffffff007114cf9 + lVar21); uVar10 = uVar10 + 0x40) {
            }
          } while( true );
        }
        if ((local_8a & 0x100) != 0) {
          uVar5 = 0;
          do {
            local_78[0] = local_c0[4];
            local_78[1] = local_c0[5];
            if (local_c0[5] != 0 || local_c0[4] != 0) {
              do {
                if (local_78[0] == 0) {
                  if (local_78[1] != 0) {
                    uVar20 = 0x40;
                    uVar6 = local_78[1];
                    goto LAB_fffffff0081d8838;
                  }
                  uVar20 = 0xffffffff;
                }
                else {
                  uVar20 = 0;
                  uVar6 = local_78[0];
LAB_fffffff0081d8838:
                  uVar6 = (uVar6 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar6 & 0x5555555555555555) << 1;
                  uVar6 = (uVar6 & 0xcccccccccccccccc) >> 2 | (uVar6 & 0x3333333333333333) << 2;
                  uVar6 = (uVar6 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar6 & 0xf0f0f0f0f0f0f0f) << 4;
                  uVar6 = (uVar6 & 0xff00ff00ff00ff00) >> 8 | (uVar6 & 0xff00ff00ff00ff) << 8;
                  uVar6 = (uVar6 & 0xffff0000ffff0000) >> 0x10 | (uVar6 & 0xffff0000ffff) << 0x10;
                  uVar20 = uVar20 | LZCOUNT(uVar6 >> 0x20 | uVar6 << 0x20);
                }
                uVar6 = uVar20 >> 3 & 0x1ffffff8;
                *(ulong *)((long)local_78 + uVar6) =
                     *(ulong *)((long)local_78 + uVar6) &
                     (1L << (uVar20 & 0x3f) ^ 0xffffffffffffffffU);
              } while (local_78[1] != 0 || local_78[0] != 0);
            }
            uVar5 = uVar5 + lVar12;
          } while (uVar5 < uVar13);
        }
      }
LAB_fffffff0081d83b4:
      lVar4 = lVar4 + 1;
    } while (lVar4 != 0x12);
    local_78[0] = param_1[0x76];
    uVar5 = param_1[0x77];
    bVar1 = local_78[0] == 0;
    if (uVar5 == 0 && local_78[0] == 0) {
      local_78[0] = 0;
      uVar17 = *(uint *)(param_1 + 0x7c);
    }
    else {
      uVar17 = 0;
    }
    uVar10 = 0;
    local_78[1] = uVar5;
    do {
      if (uVar5 == 0 && bVar1) {
        if (uVar17 <= uVar10) goto LAB_fffffff0081d8950;
        uVar15 = uVar10;
        uVar10 = uVar10 + 1;
      }
      else {
        if (local_78[1] == 0 && local_78[0] == 0) goto LAB_fffffff0081d8950;
        if (local_78[0] == 0) {
          if (local_78[1] != 0) {
            uVar15 = 0x40;
            uVar6 = local_78[1];
            goto LAB_fffffff0081d88d0;
          }
          uVar15 = 0xffffffff;
        }
        else {
          uVar15 = 0;
          uVar6 = local_78[0];
LAB_fffffff0081d88d0:
          uVar6 = (uVar6 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar6 & 0x5555555555555555) << 1;
          uVar6 = (uVar6 & 0xcccccccccccccccc) >> 2 | (uVar6 & 0x3333333333333333) << 2;
          uVar6 = (uVar6 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar6 & 0xf0f0f0f0f0f0f0f) << 4;
          uVar6 = (uVar6 & 0xff00ff00ff00ff00) >> 8 | (uVar6 & 0xff00ff00ff00ff) << 8;
          uVar6 = (uVar6 & 0xffff0000ffff0000) >> 0x10 | (uVar6 & 0xffff0000ffff) << 0x10;
          uVar15 = uVar15 | (uint)LZCOUNT(uVar6 >> 0x20 | uVar6 << 0x20);
        }
        uVar6 = (ulong)(uVar15 >> 3) & 0x1ffffff8;
        *(ulong *)((long)local_78 + uVar6) =
             *(ulong *)((long)local_78 + uVar6) &
             (1L << ((ulong)uVar15 & 0x3f) ^ 0xffffffffffffffffU);
      }
      *(uint *)(param_1[0x61] + 0x11000) = uVar15;
    } while( true );
  }
LAB_fffffff0081d8a5c:
  (**(code **)(*(long *)param_1[0x96] + 0x270))();
  return;
LAB_fffffff0081d8260:
  uVar13 = uVar13 + (long)(1 << (ulong)((uint)uVar5 & 0x1f));
  if (uVar22 <= uVar13) goto LAB_fffffff0081d812c;
  goto LAB_fffffff0081d826c;
LAB_fffffff0081d8634:
  uVar20 = uVar20 + lVar12;
  if (uVar13 <= uVar20) goto LAB_fffffff0081d83b4;
  goto LAB_fffffff0081d8640;
LAB_fffffff0081d86c4:
  uVar8 = uVar8 + (long)(1 << (ulong)((uint)uVar22 & 0x1f));
  if (uVar14 <= uVar8) goto LAB_fffffff0081d8654;
  goto LAB_fffffff0081d86d0;
LAB_fffffff0081d8950:
  (**(code **)(*param_1 + 2000))(param_1);
  lVar4 = param_1[0x61];
  if ((int)param_1[0x7f] != 0) {
    uVar17 = 0;
    do {
      *(uint *)(lVar4 + 0x100e8) = uVar17;
      uVar17 = uVar17 + 1;
    } while (uVar17 < *(uint *)(param_1 + 0x7f));
  }
  if (*(int *)((long)param_1 + 0x3fc) != 0) {
    uVar17 = 0;
    do {
      *(uint *)(lVar4 + 0x100e0) = uVar17;
      uVar17 = uVar17 + 1;
    } while (uVar17 < *(uint *)((long)param_1 + 0x3fc));
  }
  if ((int)param_1[0x80] != 0) {
    uVar17 = 0;
    do {
      *(uint *)(lVar4 + 0x100f0) = uVar17;
      uVar17 = uVar17 + 1;
    } while (uVar17 < *(uint *)(param_1 + 0x80));
  }
  (**(code **)(*param_1 + 0x7b0))(param_1);
  lVar4 = *(long *)param_1[0x96];
  (**(code **)(lVar4 + 0x268))(lVar4 + 0x268,(long *)param_1[0x96],0);
  goto LAB_fffffff0081d8a5c;
}

