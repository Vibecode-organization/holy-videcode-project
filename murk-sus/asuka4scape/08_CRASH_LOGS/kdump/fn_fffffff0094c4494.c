// FUN_fffffff0094c4494 @ fffffff0094c4494 size=920
// CALLERS:
//   fffffff00afb807e ?
//   fffffff0094c43bc FUN_fffffff0094c41a4@fffffff0094c41a4
//   fffffff0094c4964 FUN_fffffff0094c4848@fffffff0094c4848
//   fffffff0094c4acc FUN_fffffff0094c49b4@fffffff0094c49b4
//   fffffff0094c5088 FUN_fffffff0094c4eec@fffffff0094c4eec
// CALLS:
//   fffffff0094bfdac FUN_fffffff0094bfdac
//   fffffff0094c99c4 thunk_EXT_FUN_8011000003a48590
//   fffffff0094c6be4 FUN_fffffff0094c6be4
//   fffffff0094bfda0 FUN_fffffff0094bfda0

void FUN_fffffff0094c4494
               (undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4,
               undefined8 *param_5,undefined8 param_6)

{
  long *plVar1;
  ulong *puVar2;
  undefined8 *puVar3;
  ulong uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  code *pcVar7;
  ulong uVar8;
  ulong *puVar9;
  long lVar10;
  undefined8 *puVar11;
  ulong uVar12;
  long *plVar13;
  ulong local_78;
  ulong uStack_70;
  long local_68;
  
  local_68 = *(long *)PTR_DAT_fffffff007f5bb60;
  plVar13 = param_1 + 3;
  *plVar13 = 0;
  plVar1 = param_1 + 4;
  if (plVar1 < plVar13) {
LAB_fffffff0094c4814:
                    /* WARNING: Does not return */
    pcVar7 = (code *)SoftwareBreakpoint(0x5519,0xfffffff0094c4818);
    (*pcVar7)();
  }
  param_1[4] = plVar13;
  *param_1 = 4;
  param_1[1] = param_4;
  *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_5 + 2);
  param_2[0x13] = 0;
  param_2[0x12] = 0;
  param_2[0x15] = 0;
  param_2[0x14] = 0;
  param_2[0xf] = 0;
  param_2[0xe] = 0;
  param_2[0x11] = 0;
  param_2[0x10] = 0;
  param_2[0xb] = 0;
  param_2[10] = 0;
  param_2[0xd] = 0;
  param_2[0xc] = 0;
  param_2[7] = 0;
  param_2[6] = 0;
  param_2[9] = 0;
  param_2[8] = 0;
  param_2[3] = 0;
  param_2[2] = 0;
  param_2[5] = 0;
  param_2[4] = 0;
  param_2[1] = 0;
  *param_2 = 0;
  param_1[7] = param_2;
  param_1[8] = 1;
  *(undefined4 *)(param_2 + 0x15) = 0x50001;
  param_3[1] = 0;
  param_3[2] = 0;
  *param_3 = 0;
  uVar5 = *(undefined4 *)(param_5 + 2);
  *(undefined1 *)(param_3 + 2) = *(undefined1 *)((long)param_5 + 0xa4);
  uVar6 = *(undefined4 *)(param_5 + 3);
  *(undefined4 *)(param_3 + 1) = uVar5;
  *(undefined4 *)((long)param_3 + 0xc) = uVar6;
  uVar8 = FUN_fffffff0094bfda0(*param_5,param_5[1],param_1);
  if ((int)uVar8 == 0) {
    lVar10 = param_1[2];
    param_5[0x17] = lVar10;
    if (param_5[4] != 0) {
      if (lVar10 != 0) {
        uVar8 = 0x50023;
        goto LAB_fffffff0094c4568;
      }
      uVar12 = 0;
      puVar2 = param_5 + 5;
      lVar10 = 0;
      puVar9 = puVar2;
      do {
        uVar8 = lVar10 * 0x130;
        if (lVar10 + 0xff9435e50d79435eU < 0xff286bca1af286bd ||
            ~(ulong)param_4 <= uVar8 && uVar8 - ~(ulong)param_4 != 0) {
LAB_fffffff0094c4824:
                    /* WARNING: Does not return */
          pcVar7 = (code *)SoftwareBreakpoint(0x5513,0xfffffff0094c4828);
          (*pcVar7)();
        }
        puVar3 = param_4 + lVar10 * 0x26;
        if ((param_4 + 0x98 < puVar3 || puVar3 < param_4) || (0xfffffffffffffecf < uVar8 - 0x4c1))
        goto LAB_fffffff0094c4814;
        puVar3[0x23] = 0;
        puVar3[0x22] = 0;
        puVar3[0x25] = 0;
        puVar3[0x24] = 0;
        puVar3[0x1f] = 0;
        puVar3[0x1e] = 0;
        puVar3[0x21] = 0;
        puVar3[0x20] = 0;
        puVar3[0x1b] = 0;
        puVar3[0x1a] = 0;
        puVar3[0x1d] = 0;
        puVar3[0x1c] = 0;
        puVar3[0x17] = 0;
        puVar3[0x16] = 0;
        puVar3[0x19] = 0;
        puVar3[0x18] = 0;
        puVar3[0x13] = 0;
        puVar3[0x12] = 0;
        puVar3[0x15] = 0;
        puVar3[0x14] = 0;
        puVar3[0xf] = 0;
        puVar3[0xe] = 0;
        puVar3[0x11] = 0;
        puVar3[0x10] = 0;
        puVar3[0xb] = 0;
        puVar3[10] = 0;
        puVar3[0xd] = 0;
        puVar3[0xc] = 0;
        puVar3[7] = 0;
        puVar3[6] = 0;
        puVar3[9] = 0;
        puVar3[8] = 0;
        puVar3[3] = 0;
        puVar3[2] = 0;
        puVar3[5] = 0;
        puVar3[4] = 0;
        puVar3[1] = 0;
        *puVar3 = 0;
        if (puVar9 < puVar2) goto LAB_fffffff0094c4814;
        uVar8 = *puVar9;
        if ((param_5 + 0xd < puVar9 + 2) || (puVar9 + 2 < puVar9)) goto LAB_fffffff0094c4814;
        if (CARRY8(uVar8,puVar2[uVar12 * 2 + 1])) goto LAB_fffffff0094c4824;
        uVar4 = uVar8 + puVar2[uVar12 * 2 + 1];
        if (((uVar4 < uVar8) ||
            (local_78 = uVar8, uStack_70 = uVar4, param_4 + 0x98 < puVar3 + 0x26)) ||
           (puVar3 + 0x26 < puVar3)) goto LAB_fffffff0094c4814;
        uVar8 = FUN_fffffff0094c6be4(puVar3,&local_78);
        if ((int)uVar8 != 0) goto LAB_fffffff0094c4568;
        uVar8 = param_1[2];
        if (uVar8 == 0) {
          lVar10 = *plVar13;
          if (lVar10 == 0) {
            puVar3[0x22] = 0;
            if (puVar3 + 0x23 < puVar3 + 0x22) goto LAB_fffffff0094c4814;
            *plVar1 = (long)(puVar3 + 0x22);
          }
          else {
            if (*(long **)(lVar10 + 0x118) != plVar13) {
                    /* WARNING: Does not return */
              pcVar7 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff0094c4820);
              (*pcVar7)();
            }
            puVar3[0x22] = lVar10;
            if (puVar3 + 0x23 < puVar3 + 0x22) goto LAB_fffffff0094c4814;
            *(undefined8 **)(lVar10 + 0x118) = puVar3 + 0x22;
          }
          *plVar13 = (long)puVar3;
          puVar3[0x23] = plVar13;
        }
        else {
          puVar11 = (undefined8 *)*plVar1;
          puVar3[0x22] = 0;
          puVar3[0x23] = puVar11;
          *puVar11 = puVar3;
          *plVar1 = (long)(puVar3 + 0x22);
        }
        lVar10 = uVar8 + 1;
        if (0xfffffffffffffffe < uVar8) {
                    /* WARNING: Does not return */
          pcVar7 = (code *)SoftwareBreakpoint(0x5500,0xfffffff0094c482c);
          (*pcVar7)();
        }
        param_1[2] = lVar10;
        uVar12 = uVar12 + 1;
        puVar9 = puVar9 + 2;
      } while (uVar12 < (ulong)param_5[4]);
    }
    uVar8 = FUN_fffffff0094bfdac(param_1,param_3,param_6);
    if ((int)uVar8 == 0) {
      uVar8 = (ulong)*(uint *)(param_2 + 0x15);
    }
  }
LAB_fffffff0094c4568:
  if (*(long *)PTR_DAT_fffffff007f5bb60 == local_68) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590(uVar8);
  return;
}

