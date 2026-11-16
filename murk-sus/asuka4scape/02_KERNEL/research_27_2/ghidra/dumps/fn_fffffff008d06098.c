// FUN_fffffff008d06098 @ fffffff008d06098 size=68
// CALLERS:
//   fffffff00afb8ba0 no-fn
//   fffffff008d14a20 FUN_fffffff008d14888@fffffff008d14888
//   fffffff008d14a38 FUN_fffffff008d14888@fffffff008d14888
//   fffffff008d56da8 FUN_fffffff008d56c68@fffffff008d56c68
//   fffffff008d56dc0 FUN_fffffff008d56c68@fffffff008d56c68
//   fffffff008d56dd8 FUN_fffffff008d56c68@fffffff008d56c68
//   fffffff008d56df0 FUN_fffffff008d56c68@fffffff008d56c68
//   fffffff008d56e08 FUN_fffffff008d56c68@fffffff008d56c68
//   fffffff008d56e2c FUN_fffffff008d56c68@fffffff008d56c68
//   fffffff008d66ab8 FUN_fffffff008d66a58@fffffff008d66a58
//   fffffff008d5d518 FUN_fffffff008d5d4ec@fffffff008d5d4ec
//   fffffff008d5d530 FUN_fffffff008d5d4ec@fffffff008d5d4ec
//   fffffff008d5d54c FUN_fffffff008d5d4ec@fffffff008d5d4ec
//   fffffff008d5d564 FUN_fffffff008d5d4ec@fffffff008d5d4ec
// CALLEES:

undefined1  [16] FUN_fffffff008d06098(ulong param_1,int param_2,uint param_3,int param_4)

{
  ulong uVar1;
  double dVar2;
  undefined1 auVar3 [16];
  
  uVar1 = (ulong)-(param_3 + param_2);
  dVar2 = (double)(param_1 & (-1L << ((ulong)(param_3 + param_2) & 0x3f) ^ 0xffffffffffffffffU));
  if (param_4 != 0) {
    dVar2 = (double)((long)(param_1 << (uVar1 & 0x3f)) >> (uVar1 & 0x3f));
  }
  auVar3._0_8_ = dVar2 / (double)(ulong)(1L << ((ulong)param_3 & 0x3f));
  auVar3._8_8_ = 0;
  return auVar3;
}

