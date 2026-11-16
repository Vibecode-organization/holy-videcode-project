// FUN_fffffff0081e12c4 @ fffffff0081e12c4 size=512
// CALLERS:
//   fffffff00afb8a59 no-fn
//   fffffff008171c30 FUN_fffffff008171bdc@fffffff008171bdc
//   fffffff008171ca8 FUN_fffffff008171bdc@fffffff008171bdc
// CALLEES:
//   fffffff008217030 thunk_EXT_FUN_8011000003a49114
//   fffffff008216f60 thunk_EXT_FUN_80110000036da494
//   fffffff008216a40 thunk_EXT_FUN_8011000002c2371c
//   fffffff0082157b0 thunk_EXT_FUN_80110000032222a8
//   fffffff0082157f0 thunk_EXT_FUN_8011000003222de0

ulong FUN_fffffff0081e12c4
                (long *param_1,undefined8 param_2,long param_3,undefined8 param_4,undefined8 param_5
                )

{
  long *plVar1;
  int *piVar2;
  uint uVar3;
  long lVar4;
  uint uVar5;
  long lVar6;
  ulong uVar7;
  int iVar8;
  ulong uVar9;
  long lVar10;
  undefined8 in_stack_ffffffffffffffa0;
  undefined4 uVar11;
  
  uVar11 = (undefined4)((ulong)in_stack_ffffffffffffffa0 >> 0x20);
  thunk_EXT_FUN_80110000032222a8(param_1[3]);
  uVar5 = thunk_EXT_FUN_8011000002c2371c
                    (param_3,param_5,param_2,param_4,*(undefined4 *)(param_1[2] + 0x100),
                     FUN_fffffff0081e1120,param_1,param_1[6],CONCAT44(uVar11,4));
  if ((uVar5 & 1) != 0) goto LAB_fffffff0081e1424;
  uVar3 = *(uint *)(param_1 + 0x51);
  if (0x20 < uVar3) {
    uVar7 = thunk_EXT_FUN_8011000003a49114("AGXk: %s:%d:%s: !!! Verification failed: %s\n");
    return uVar7;
  }
  uVar7 = 0;
  uVar9 = (ulong)uVar3;
  if (uVar3 == 0) {
LAB_fffffff0081e13a0:
    iVar8 = (int)(uVar7 * 0x10);
    plVar1 = (long *)((long)param_1 + (long)iVar8 + 0x88);
    if (uVar7 * 0x10 - (long)iVar8 != 0) {
      plVar1 = (long *)((ulong)(param_1 + uVar7 * 2 + 0x11) & 0xffffffffffff | 0x2bad000000000000);
    }
    uVar7 = uVar7 << 4 | 8;
    piVar2 = (int *)((long)param_1 + (long)(int)uVar7 + 0x88);
    if (uVar7 != (long)(int)uVar7) {
      piVar2 = (int *)((long)param_1 + uVar7 + 0x88 & 0xffffffffffff | 0x2bad000000000000);
    }
    *plVar1 = param_3;
    *piVar2 = (int)param_4;
    *(uint *)(param_1 + 0x51) = uVar3 + 1;
  }
  else {
    do {
      if ((param_1[uVar7 * 2 + 0x11] == param_3) &&
         ((int)(param_1 + uVar7 * 2 + 0x11)[1] == (int)param_4)) goto LAB_fffffff0081e13f4;
      uVar7 = uVar7 + 1;
      uVar9 = uVar9 - 1;
    } while (uVar9 != 0);
    uVar7 = (ulong)uVar3;
    if (uVar3 != 0x20) goto LAB_fffffff0081e13a0;
  }
  *(int *)((long)param_1 + 0x28c) = *(int *)((long)param_1 + 0x28c) + 1;
LAB_fffffff0081e13f4:
  *(ulong *)((long)param_1 + 0x24) =
       CONCAT44((int)((ulong)*(undefined8 *)((long)param_1 + 0x24) >> 0x20) + 1,
                (int)*(undefined8 *)((long)param_1 + 0x24) + 1);
  (**(code **)(*param_1 + 0x20))(param_1);
LAB_fffffff0081e1424:
  lVar6 = param_1[2];
  if ((*(byte *)(lVar6 + 0x1ac44) >> 3 & 1) != 0) {
    lVar10 = param_1[6];
    lVar4 = param_1[5];
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar6 + 0x1ac48));
    thunk_EXT_FUN_80110000036da494(0x85930c6c,param_1,lVar10,0,uVar5 | (int)lVar4 << 0x10,0);
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar6 + 0x1ac48));
  }
  thunk_EXT_FUN_8011000003222de0(param_1[3]);
  return (ulong)(uVar5 ^ 1);
}

