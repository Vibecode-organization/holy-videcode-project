// FUN_fffffff00a1e05f4 @ fffffff00a1e05f4 size=672
// CALLERS:
//   fffffff00afb8183 no-fn
//   fffffff00a1ee454 FUN_fffffff00a1ee41c@fffffff00a1ee41c
//   fffffff00a1f15fc FUN_fffffff00a1f1598@fffffff00a1f1598
//   fffffff00a1f6df4 FUN_fffffff00a1f6da4@fffffff00a1f6da4
// CALLEES:
//   fffffff00a1dfe44 FUN_fffffff00a1dfe44
//   fffffff00a22b850 FUN_fffffff00a22b850
//   fffffff00a22b5a8 FUN_fffffff00a22b5a8
//   fffffff00a36d048 FUN_fffffff00a36d048

undefined8
FUN_fffffff00a1e05f4
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,uint *param_7,uint param_8,
          long *param_9)

{
  code *pcVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
  ulong uVar5;
  ulong uVar6;
  uint uVar7;
  ulong uVar8;
  long lVar9;
  undefined1 extraout_q0 [16];
  
  if (0x20000ff < param_8) {
    return 3;
  }
  if (((param_8 ^ 0xffffffff) & 3) != 0) {
    return 0x12;
  }
  if (param_8 < 0x100) {
    return 5;
  }
  uVar3 = param_8 >> 8;
  lVar9 = tpidr_el1;
  *(int *)(lVar9 + 0x1c0) = *(int *)(lVar9 + 0x1c0) + 1;
  LOAcquire();
  uVar2 = param_7[2];
  param_7[2] = uVar2 + 0x1000000;
  if ((uVar2 >> 0x10 & 0xff) == uVar2 >> 0x18) {
    param_7[3] = *(uint *)(lVar9 + 0x4e8);
  }
  else {
    param_1 = FUN_fffffff00a22b5a8((long)param_7,(ulong)(uVar2 >> 0x18),lVar9);
  }
  do {
    uVar8 = *(ulong *)(param_7 + 0x12);
    if ((uVar8 == 0) || (uVar8 == 0)) {
      FUN_fffffff00a22b850((long)param_7);
      return 0x10;
    }
    uVar8 = *(ulong *)(param_7 + 0x12);
    if (uVar8 == 0) {
LAB_fffffff00a1e06e4:
      uVar8 = 0;
      uVar5 = 0;
LAB_fffffff00a1e06ec:
      lVar9 = 0;
    }
    else {
      if ((uVar8 >> 0x26 & 1) == 0) {
        if (uVar8 == 0) goto LAB_fffffff00a1e06e4;
        uVar5 = (uVar8 & 0x3fff) << 0xe;
        uVar8 = uVar8 & 0xffffffffffffc000 | 0x4000000000;
      }
      else {
        uVar5 = (uVar8 & 0x10 | 0x20) << (uVar8 & 0xf);
        uVar8 = uVar8 & 0xffffffffffffffe0;
      }
      if (uVar5 < (ulong)uVar3 * 0x18 + 0x18) goto LAB_fffffff00a1e06ec;
      lVar9 = uVar8 + (ulong)uVar3 * 0x18;
    }
    if (lVar9 != 0) {
      if ((*(uint *)(lVar9 + 8) & 0x1f0000) != 0) {
        if ((*(uint *)(lVar9 + 8) & 0xfc000000 | 0x3000000) == param_8 * 0x1000000) {
          *param_9 = lVar9;
          return 0;
        }
        FUN_fffffff00a22b850((long)param_7);
        return 5;
      }
      uVar2 = *(uint *)(uVar8 + 0xc);
      if (*(uint *)(uVar8 + 0xc) != uVar3) break;
      *(undefined4 *)(uVar8 + 0xc) = *(undefined4 *)(lVar9 + 0xc);
      param_7[6] = param_7[6] - 1;
      goto LAB_fffffff00a1e0848;
    }
    uVar4 = FUN_fffffff00a1dfe44(param_1,param_2,param_3,param_4,param_5,param_6,param_7,uVar3 + 1);
    param_1 = extraout_q0;
    if ((int)uVar4 != 0) {
      return uVar4;
    }
  } while( true );
LAB_fffffff00a1e07b4:
  uVar7 = uVar2;
  if (uVar5 < (ulong)uVar7 * 0x18 + 0x18) {
LAB_fffffff00a1e07fc:
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xbffc,0xfffffff00a1e0808);
    (*pcVar1)();
  }
  uVar6 = uVar8 + (ulong)uVar7 * 0x18;
  if (((uVar8 ^ uVar6) & 0xffc0000000000000) != 0) {
    uVar6 = uVar6 & 0xffffffffffff | 0xc8a2000000000000;
  }
  if (uVar6 == 0) goto LAB_fffffff00a1e07fc;
  uVar2 = *(uint *)(uVar6 + 0xc);
  if (*(uint *)(uVar6 + 0xc) == uVar3) {
    *(undefined4 *)(uVar6 + 0xc) = *(undefined4 *)(lVar9 + 0xc);
    param_7[6] = param_7[6] - 1;
    if (uVar7 != 0) {
      uVar7 = uVar7 & 0xffffff;
      if (uVar7 < param_7[0x1c]) {
        param_7[0x1c] = uVar7;
      }
      if (param_7[0x1d] < uVar7) {
        param_7[0x1d] = uVar7;
      }
    }
LAB_fffffff00a1e0848:
    uVar3 = FUN_fffffff00a36d048((int *)(param_7 + 8),(long)(param_7 + 7),1,2);
    *(uint *)(lVar9 + 8) = param_8 * 0x1000000 & 0xfc000000 | uVar3 << 0x18;
    *(undefined4 *)(lVar9 + 0xc) = 0;
    *param_9 = lVar9;
    return 0;
  }
  goto LAB_fffffff00a1e07b4;
}

