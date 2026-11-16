// FUN_fffffff0081e7940 @ fffffff0081e7940 size=368

void FUN_fffffff0081e7940(long *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  code *pcVar4;
  int *piVar5;
  ulong uVar6;
  uint uVar7;
  long lVar8;
  int iVar9;
  ulong uVar10;
  ulong uVar11;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(param_1[7]);
  uVar6 = param_1[0x10];
  if (uVar6 != 0) {
    uVar11 = 0;
    lVar8 = param_1[0xf];
    do {
      piVar5 = *(int **)(lVar8 + uVar11 * 8);
      if (piVar5 != (int *)0x0) {
        iVar9 = *piVar5;
        if (*(int *)((long)param_1 + 0x2c) == 1) {
          iVar9 = iVar9 + -1;
          *piVar5 = iVar9;
        }
        if (iVar9 == 0) {
          uVar3 = *(uint *)(param_1 + 9);
          if (uVar3 != 0) {
            uVar7 = 0;
            lVar8 = param_1[0x13];
            do {
              uVar1 = uVar7 + uVar3 * (int)uVar11;
              uVar6 = (ulong)(uVar1 >> 6);
              uVar2 = uVar3 - uVar7;
              if (0x3f < (uVar1 & 0x3f) + (uVar3 - uVar7)) {
                uVar2 = 0x40 - (uVar1 & 0x3f);
              }
              uVar10 = 0xffffffffffffffff;
              if (uVar2 < 0x40) {
                uVar10 = ~(-1L << ((ulong)uVar2 & 0x3f));
              }
              uVar10 = *(ulong *)(lVar8 + uVar6 * 8) &
                       (uVar10 << ((ulong)uVar1 & 0x3f) ^ 0xffffffffffffffff);
              *(ulong *)(lVar8 + uVar6 * 8) = uVar10;
              if (uVar10 == 0) {
                uVar10 = (ulong)(uVar1 >> 9) & 0x7ffff8;
                *(ulong *)((long)param_1 + uVar10 + 0x90) =
                     *(ulong *)((long)param_1 + uVar10 + 0x90) &
                     (1L << (uVar6 & 0x3f) ^ 0xffffffffffffffffU);
              }
              uVar7 = uVar2 + uVar7;
            } while (uVar7 < uVar3);
          }
          (**(code **)(*param_1 + 8))(param_1);
          lVar8 = param_1[0xf];
          uVar6 = param_1[0x10];
          *(undefined8 *)(lVar8 + uVar11 * 8) = 0;
          *(int *)(param_1 + 0x14) = (int)param_1[0x14] + -1;
        }
      }
      uVar11 = (ulong)((int)uVar11 + 1);
    } while (uVar11 < uVar6);
  }
  *(undefined1 *)(param_1 + 5) = 1;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081e7aac);
    (*pcVar4)();
  }
  thunk_EXT_FUN_8011000003222de0(param_1[7]);
  return;
}

