/* ==== _cmap_convert @ 183ed71a4 size=1072 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong _cmap_convert(long param_1,ushort *param_2,ulong param_3,ushort *param_4,ulong *param_5)

{
  bool bVar1;
  int iVar2;
  long lVar3;
  byte *pbVar4;
  byte *pbVar5;
  long lVar6;
  ulong uVar7;
  ulong uVar8;
  ulong uVar9;
  byte bVar10;
  uint uVar11;
  ulong uVar12;
  long lVar13;
  uint uVar14;
  ulong uVar15;
  ulong uVar16;
  byte *pbVar17;
  ushort uVar18;
  uint uVar19;
  long lVar20;
  byte *pbVar21;
  ushort *local_c0;
  ulong *local_b8;
  undefined8 local_a0;
  uint local_98;
  ulong local_90 [4];
  ushort local_70 [4];
  long local_68;
  
  local_68 = *_DAT_1e0186220;
  if (*(char *)(param_1 + 0x28) == '\x01') {
    uVar16 = param_3 >> 1;
    uVar9 = uVar16;
    if (1 < param_3) {
      do {
        *param_4 = *param_2 >> 8 | *param_2 << 8;
        *param_5 = 2;
        uVar9 = uVar9 - 1;
        param_4 = param_4 + 1;
        param_5 = param_5 + 1;
        param_2 = param_2 + 1;
      } while (uVar9 != 0);
    }
  }
  else {
    if (param_3 != 0) {
      uVar16 = 0;
      pbVar17 = *(byte **)(param_1 + 0x30);
      lVar6 = *(long *)(param_1 + 0x20);
      local_c0 = param_4;
      local_b8 = param_5;
LAB_183ed7248:
      uVar9 = param_3;
      if (pbVar17 != (byte *)0x0) {
        local_98 = 0;
        local_a0 = 0;
        lVar3 = func_0x0001881404e0(*(undefined8 *)(pbVar17 + 8));
        uVar15 = (ulong)*pbVar17;
        if (lVar3 != 0) {
          uVar7 = (ulong)pbVar17[1];
          uVar8 = param_3;
          if (uVar7 <= param_3) {
            uVar8 = uVar7;
          }
          if (uVar15 <= uVar8) {
LAB_183ed73b0:
            lVar20 = 0;
            uVar19 = ((uint)uVar15 & 0xff) * 8 - 8;
LAB_183ed73c8:
            pbVar5 = (byte *)func_0x000188140510(*(undefined8 *)(pbVar17 + 8),lVar20);
            bVar10 = *pbVar5;
            if (uVar15 != bVar10) goto LAB_183ed7470;
            uVar7 = 0;
            if (uVar15 != 0) {
              uVar11 = *(uint *)(pbVar5 + 4);
              uVar12 = uVar15 & 0xff;
              uVar14 = uVar19;
              do {
                *(char *)((long)local_90 + uVar7) = (char)(uVar11 >> (ulong)(uVar14 & 0x1f));
                uVar7 = uVar7 + 1;
                uVar14 = uVar14 - 8;
                uVar12 = uVar12 - 1;
              } while (uVar12 != 0);
              lVar13 = 0;
              uVar11 = *(uint *)(pbVar5 + 8);
              uVar7 = uVar15 & 0xff;
              uVar14 = uVar19;
              do {
                *(char *)((long)local_70 + lVar13) = (char)(uVar11 >> (ulong)(uVar14 & 0x1f));
                lVar13 = lVar13 + 1;
                uVar14 = uVar14 - 8;
                uVar7 = uVar7 - 1;
              } while (uVar7 != 0);
              uVar7 = 0;
              while ((*(byte *)((long)local_90 + uVar7) <= *(byte *)((long)param_2 + uVar7) &&
                     (*(byte *)((long)param_2 + uVar7) <= *(byte *)((long)local_70 + uVar7)))) {
                uVar7 = uVar7 + 1;
                if (uVar15 == uVar7) goto LAB_183ed7498;
              }
            }
            if (uVar7 != uVar15) goto LAB_183ed7470;
LAB_183ed7498:
            uVar19 = 0;
            if (bVar10 != 0) {
              lVar3 = 0;
              do {
                uVar19 = (uint)*(byte *)((long)param_2 + lVar3) | uVar19 << 8;
                lVar3 = lVar3 + 1;
                uVar15 = uVar15 - 1;
              } while (uVar15 != 0);
            }
            iVar2 = _cmap_cid_set_find_matching_range
                              (*(undefined8 *)(pbVar5 + 0x10),uVar19,&local_a0);
            if (iVar2 == 0) {
              iVar2 = _cmap_cid_set_find_matching_range
                                (*(undefined8 *)(pbVar5 + 0x18),uVar19,&local_a0);
              if (iVar2 != 0) {
                uVar19 = local_98 & 0xffff;
                goto LAB_183ed755c;
              }
              if (lVar6 == 0) goto LAB_183ed755c;
              bVar10 = *pbVar5;
              if (3 < bVar10) {
                bVar10 = 4;
              }
              lVar3 = _cmap_convert(lVar6,param_2,bVar10,local_70,local_90);
              uVar9 = local_90[0];
              uVar18 = local_70[0];
              if (lVar3 != 1) {
                _pdf_log(
                        "CG-SEC-187882136: used-cmap codespace-dimension mismatch contained (decoded %zu codes from a %zu-byte code); falling back to identity."
                        );
                goto LAB_183ed755c;
              }
            }
            else {
              uVar19 = (uVar19 + (local_98 & 0xffff)) - (int)local_a0;
LAB_183ed755c:
              uVar9 = (ulong)*pbVar5;
              uVar18 = (ushort)uVar19;
            }
            *local_c0 = uVar18;
            *local_b8 = uVar9;
            uVar16 = uVar16 + 1;
            local_c0 = local_c0 + 1;
            local_b8 = local_b8 + 1;
            goto LAB_183ed757c;
          }
        }
        goto LAB_183ed727c;
      }
      goto LAB_183ed757c;
    }
    uVar16 = 0;
  }
LAB_183ed7594:
  if (*_DAT_1e0186220 != local_68) {
    uVar16 = func_0x000188138130();
    return uVar16;
  }
  return uVar16;
LAB_183ed7470:
  lVar20 = lVar20 + 1;
  if (lVar20 == lVar3) goto code_r0x000183ed747c;
  goto LAB_183ed73c8;
code_r0x000183ed747c:
  bVar1 = uVar15 == uVar8;
  uVar15 = uVar15 + 1;
  if (bVar1) goto code_r0x000183ed748c;
  goto LAB_183ed73b0;
code_r0x000183ed748c:
  uVar15 = (ulong)*pbVar17;
LAB_183ed727c:
  if (uVar15 <= param_3) {
    lVar3 = func_0x0001881404e0(*(undefined8 *)(pbVar17 + 8));
    pbVar5 = (byte *)0x0;
    if (lVar3 != 0) {
      lVar20 = 0;
      uVar9 = 0;
      pbVar21 = (byte *)0x0;
      do {
        pbVar4 = (byte *)func_0x000188140510(*(undefined8 *)(pbVar17 + 8),lVar20);
        bVar10 = *pbVar4;
        uVar8 = (ulong)bVar10;
        pbVar5 = pbVar21;
        uVar15 = uVar9;
        if (uVar8 <= param_3) {
          if (bVar10 == 0) {
            uVar7 = 0;
          }
          else {
            lVar13 = 0;
            uVar19 = *(uint *)(pbVar4 + 4);
            uVar11 = (uint)bVar10 * 8 - 8;
            uVar7 = uVar8;
            uVar14 = uVar11;
            do {
              *(char *)((long)local_90 + lVar13) = (char)(uVar19 >> (ulong)(uVar14 & 0x1f));
              lVar13 = lVar13 + 1;
              uVar14 = uVar14 - 8;
              uVar7 = uVar7 - 1;
            } while (uVar7 != 0);
            lVar13 = 0;
            uVar19 = *(uint *)(pbVar4 + 8);
            uVar7 = uVar8;
            do {
              *(char *)((long)local_70 + lVar13) = (char)(uVar19 >> (ulong)(uVar11 & 0x1f));
              lVar13 = lVar13 + 1;
              uVar11 = uVar11 - 8;
              uVar7 = uVar7 - 1;
            } while (uVar7 != 0);
            uVar12 = 0;
            do {
              uVar7 = uVar12;
              if ((*(byte *)((long)param_2 + uVar12) < *(byte *)((long)local_90 + uVar12)) ||
                 (*(byte *)((long)local_70 + uVar12) < *(byte *)((long)param_2 + uVar12))) break;
              uVar12 = uVar12 + 1;
              uVar7 = uVar8;
            } while (uVar8 != uVar12);
          }
          if ((((uVar9 <= uVar7) && (pbVar5 = pbVar4, uVar15 = uVar7, uVar7 == uVar9)) &&
              (uVar15 = uVar9, pbVar21 != (byte *)0x0)) && (pbVar5 = pbVar21, bVar10 < *pbVar21)) {
            pbVar5 = pbVar4;
          }
        }
        lVar20 = lVar20 + 1;
        uVar9 = uVar15;
        pbVar21 = pbVar5;
      } while (lVar20 != lVar3);
    }
    pbVar21 = pbVar17 + 1;
    if (pbVar5 != (byte *)0x0) {
      pbVar21 = pbVar5;
    }
    uVar9 = (ulong)*pbVar21;
  }
LAB_183ed757c:
  param_2 = (ushort *)((long)param_2 + uVar9);
  param_3 = param_3 - uVar9;
  if (param_3 == 0) goto LAB_183ed7594;
  goto LAB_183ed7248;
}



/* ==== ___get_cid_table_block_invoke @ 183fe6060 size=48 ==== */

void ___get_cid_table_block_invoke(void)

{
  DAT_1eb058530 = func_0x000188140c00(0,0,0,0);
  return;
}



