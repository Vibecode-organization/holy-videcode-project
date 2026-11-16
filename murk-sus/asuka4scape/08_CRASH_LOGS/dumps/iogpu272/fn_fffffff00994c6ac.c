// FUN_fffffff00994c6ac @ fffffff00994c6ac size=436

void FUN_fffffff00994c6ac(long param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  code *pcVar7;
  uint uVar8;
  long lVar9;
  long lVar10;
  uint uVar11;
  long lVar12;
  ulong unaff_x30;
  
  uVar2 = *param_2;
  uVar5 = uVar2 | 0x8000;
  uVar2 = (uVar2 & 0xaaaaaaaa | 0x8000) >> 1 | (uVar2 & 0x55555555) << 1;
  uVar2 = (uVar2 & 0xcccccccc) >> 2 | (uVar2 & 0x33333333) << 2;
  uVar2 = (uVar2 & 0xf0f0f0f0) >> 4 | (uVar2 & 0xf0f0f0f) << 4;
  uVar2 = (uVar2 & 0xff00ff00) >> 8 | (uVar2 & 0xff00ff) << 8;
  lVar12 = LZCOUNT(uVar2 >> 0x10 | uVar2 << 0x10);
  if ((int)lVar12 != 0xf) {
    do {
      uVar2 = param_2[lVar12 + 1];
      uVar8 = uVar2 << 0x18;
      if (uVar8 != 0xff000000) {
        uVar1 = uVar2 & 0xffffff00;
        if (0 < (int)(uVar1 - **(int **)(*(long *)(param_1 + 0x20) + (long)((int)uVar8 >> 0x18) * 8)
                     )) {
          if (0 < (int)(uVar1 - *(int *)(param_1 + 0x40 +
                                        (((long)((ulong)uVar8 << 0x20) >> 0x38) << 4 | 8U)))) {
            thunk_EXT_FUN_8011000003a49114("\"Merge from non-scrubbed src event %p\\n\" @%s:%d");
            return;
          }
          uVar3 = *param_3;
          uVar11 = uVar3 | 0x8000;
          do {
            uVar6 = (uVar11 & 0xaaaaaaaa) >> 1 | (uVar11 & 0x55555555) << 1;
            uVar6 = (uVar6 & 0xcccccccc) >> 2 | (uVar6 & 0x33333333) << 2;
            uVar6 = (uVar6 & 0xf0f0f0f0) >> 4 | (uVar6 & 0xf0f0f0f) << 4;
            uVar6 = (uVar6 & 0xff00ff00) >> 8 | (uVar6 & 0xff00ff) << 8;
            lVar10 = LZCOUNT(uVar6 >> 0x10 | uVar6 << 0x10);
            if (0xe < (uint)lVar10) {
              uVar8 = (~uVar3 & 0xaaaaaaaa) >> 1 | (~uVar3 & 0x55555555) << 1;
              uVar8 = (uVar8 & 0xcccccccc) >> 2 | (uVar8 & 0x33333333) << 2;
              uVar8 = (uVar8 & 0xf0f0f0f0) >> 4 | (uVar8 & 0xf0f0f0f) << 4;
              uVar8 = (uVar8 & 0xff00ff00) >> 8 | (uVar8 & 0xff00ff) << 8;
              lVar10 = LZCOUNT(uVar8 >> 0x10 | uVar8 << 0x10);
              uVar8 = (uint)lVar10;
              if (uVar8 < 0xf) {
                *param_3 = 1 << (ulong)(uVar8 & 0x1f) | uVar3;
                param_3[lVar10 + 1] = uVar2;
              }
              else {
                lVar10 = 0;
                lVar9 = 0xf;
                while( true ) {
                  iVar4 = param_3[lVar10 + 1] << 0x18;
                  if ((iVar4 == -0x1000000) ||
                     ((int)((param_3[lVar10 + 1] & 0xffffff00) -
                           **(int **)(*(long *)(param_1 + 0x20) + (long)(iVar4 >> 0x18) * 8)) < 1))
                  break;
                  lVar10 = lVar10 + 1;
                  lVar9 = lVar9 + -1;
                  if (lVar9 == 0) {
                    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                      FUN_fffffff00994c64c();
                      return;
                    }
                    /* WARNING: Does not return */
                    pcVar7 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00994c83c);
                    (*pcVar7)();
                  }
                }
                param_3[lVar10 + 1] = uVar2;
              }
              goto LAB_fffffff00994c7f8;
            }
            uVar11 = 1 << (ulong)((uint)lVar10 & 0x1f) ^ uVar11;
            uVar6 = param_3[lVar10 + 1];
          } while (uVar8 != uVar6 * 0x1000000);
          if (0 < (int)(uVar1 - (uVar6 & 0xffffff00))) {
            param_3[lVar10 + 1] = uVar6 & 0xff | uVar1;
          }
        }
      }
LAB_fffffff00994c7f8:
      uVar5 = 1 << (ulong)((uint)lVar12 & 0x1f) ^ uVar5;
      uVar2 = (uVar5 & 0xaaaaaaaa) >> 1 | (uVar5 & 0x55555555) << 1;
      uVar2 = (uVar2 & 0xcccccccc) >> 2 | (uVar2 & 0x33333333) << 2;
      uVar2 = (uVar2 & 0xf0f0f0f0) >> 4 | (uVar2 & 0xf0f0f0f) << 4;
      uVar2 = (uVar2 & 0xff00ff00) >> 8 | (uVar2 & 0xff00ff) << 8;
      lVar12 = LZCOUNT(uVar2 >> 0x10 | uVar2 << 0x10);
    } while ((uint)lVar12 < 0xf);
  }
  return;
}

