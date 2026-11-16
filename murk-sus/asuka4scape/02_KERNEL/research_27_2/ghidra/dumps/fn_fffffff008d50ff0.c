// FUN_fffffff008d50ff0 @ fffffff008d50ff0 size=92
// CALLERS:
//   fffffff00afb95b4 no-fn
//   fffffff008cce2a4 FUN_fffffff008cce23c@fffffff008cce23c
//   fffffff008dbb958 FUN_fffffff008dbb91c@fffffff008dbb91c
//   fffffff008cd2da0 FUN_fffffff008cd2d38@fffffff008cd2d38
//   fffffff008cd43e0 FUN_fffffff008cd4378@fffffff008cd4378
//   fffffff008cd95c4 FUN_fffffff008cd9578@fffffff008cd9578
//   fffffff008dbb27c FUN_fffffff008dbb244@fffffff008dbb244
//   fffffff008cf9b5c FUN_fffffff008cf9af4@fffffff008cf9af4
//   fffffff008cfbbc8 FUN_fffffff008cfbb60@fffffff008cfbb60
//   fffffff008cfef0c FUN_fffffff008cfeea4@fffffff008cfeea4
//   fffffff008d08cbc FUN_fffffff008d08c54@fffffff008d08c54
//   fffffff008dbb0c0 FUN_fffffff008dbb018@fffffff008dbb018
//   fffffff008dbb160 FUN_fffffff008dbb120@fffffff008dbb120
//   fffffff008dbc708 FUN_fffffff008dbc6d0@fffffff008dbc6d0
//   fffffff008dbbdb0 FUN_fffffff008dbbd78@fffffff008dbbd78
//   fffffff008d130a8 FUN_fffffff008d13040@fffffff008d13040
//   fffffff008d1530c FUN_fffffff008d152d0@fffffff008d152d0
//   fffffff008d2084c FUN_fffffff008d207e4@fffffff008d207e4
//   fffffff008d2d644 FUN_fffffff008d2d610@fffffff008d2d610
//   fffffff008d438b8 FUN_fffffff008d43868@fffffff008d43868
//   fffffff008d45654 FUN_fffffff008d455c0@fffffff008d455c0
//   fffffff008d456ac FUN_fffffff008d455c0@fffffff008d455c0
//   fffffff008d457e0 FUN_fffffff008d455c0@fffffff008d455c0
//   fffffff008d463f0 FUN_fffffff008d46388@fffffff008d46388
//   fffffff008d77f80 FUN_fffffff008d77f18@fffffff008d77f18
//   fffffff008d7ef0c FUN_fffffff008d7eea4@fffffff008d7eea4
//   fffffff008d858a4 FUN_fffffff008d8583c@fffffff008d8583c
//   fffffff008da0170 FUN_fffffff008da0108@fffffff008da0108
//   fffffff008db795c FUN_fffffff008db78f4@fffffff008db78f4
//   fffffff008dcdfd4 FUN_fffffff008dcdf6c@fffffff008dcdf6c
//   fffffff008dce7fc FUN_fffffff008dce794@fffffff008dce794
// CALLEES:

undefined8 FUN_fffffff008d50ff0(long param_1,uint param_2)

{
  ulong uVar1;
  long *plVar2;
  long lVar3;
  
  if (param_2 < 8) {
    uVar1 = *(ulong *)(param_1 + 0x1c0);
    if ((uVar1 >> ((ulong)param_2 & 0x3f) & 1) != 0) {
      lVar3 = (ulong)param_2 * 8;
      plVar2 = (long *)(param_1 + 0x150 + (long)(int)lVar3);
      if (lVar3 - (int)lVar3 != 0) {
        plVar2 = (long *)(param_1 + 0x150 + lVar3 & 0xffffffffffffU | 0x2bad000000000000);
      }
      goto LAB_fffffff008d51040;
    }
  }
  else {
    uVar1 = *(ulong *)(param_1 + 0x1c0);
  }
  uVar1 = (uVar1 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar1 & 0x5555555555555555) << 1;
  uVar1 = (uVar1 & 0xcccccccccccccccc) >> 2 | (uVar1 & 0x3333333333333333) << 2;
  uVar1 = (uVar1 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar1 & 0xf0f0f0f0f0f0f0f) << 4;
  uVar1 = (uVar1 & 0xff00ff00ff00ff00) >> 8 | (uVar1 & 0xff00ff00ff00ff) << 8;
  uVar1 = (uVar1 & 0xffff0000ffff0000) >> 0x10 | (uVar1 & 0xffff0000ffff) << 0x10;
  plVar2 = (long *)(param_1 + 0x150 + LZCOUNT(uVar1 >> 0x20 | uVar1 << 0x20) * 8);
LAB_fffffff008d51040:
  return *(undefined8 *)(*plVar2 + 0xb8);
}

