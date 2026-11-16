// FUN_fffffff00a97ae84 @ fffffff00a97ae84 size=208 depth=1
// CALLERS:
//   fffffff00afbf1a0 ?
//   fffffff007cf5218 ?
//   fffffff007d2c470 ?
//   fffffff007d366f8 ?
//   fffffff007d55e28 ?
//   fffffff007d5e388 ?
//   fffffff007d5fa20 ?
//   fffffff007db4380 ?
//   fffffff007db55e0 ?
//   fffffff007dde400 ?
//   fffffff007df10c8 ?
//   fffffff007dfd3b0 ?
//   fffffff007e26458 ?
//   fffffff007e60f08 ?
//   fffffff007ec7358 ?
//   fffffff007ed2918 ?
//   fffffff007f001b0 ?
//   fffffff007f81d88 ?
//   fffffff007fd29c8 ?
//   fffffff007ff22f8 ?
//   fffffff007ffd928 ?
//   fffffff00801efe0 ?
//   fffffff008021d40 ?
//   fffffff008029f90 ?
//   fffffff008039c38 ?
//   fffffff008045958 ?
//   fffffff00804bb10 ?
//   fffffff008064848 ?
//   fffffff00806c718 ?
//   fffffff00807f828 ?
//   fffffff008098a78 ?
//   fffffff0080ed0d8 ?
//   fffffff0080fd358 ?
//   fffffff0080fe4d0 ?
//   fffffff00a9df9c0 FUN_fffffff00a9df97c
//   fffffff00a9ae548 FUN_fffffff00a9ae408
//   fffffff00a9aeed0 FUN_fffffff00a9aed20
//   fffffff00a9aef28 FUN_fffffff00a9aed20
//   fffffff00a9aeb0c FUN_fffffff00a9ae990
//   fffffff00a9aeb6c FUN_fffffff00a9ae990
//   fffffff00a909314 FUN_fffffff00a909094
//   fffffff00a96a5e8 FUN_fffffff00a96a53c
//   fffffff00a9e0070 FUN_fffffff00a9dfff0
//   fffffff00a96a52c FUN_fffffff00a96a520
//   fffffff0083c6598 thunk_FUN_fffffff00a97ae84
//   fffffff008657f00 thunk_FUN_fffffff00a97ae84
//   fffffff0086806f8 thunk_FUN_fffffff00a97ae84
//   fffffff0087486b0 thunk_FUN_fffffff00a97ae84
//   fffffff008771130 thunk_FUN_fffffff00a97ae84
//   fffffff008774228 thunk_FUN_fffffff00a97ae84
//   fffffff008908c90 thunk_FUN_fffffff00a97ae84
//   fffffff00890ba58 thunk_FUN_fffffff00a97ae84
//   fffffff008a81980 thunk_FUN_fffffff00a97ae84
//   fffffff008aef670 thunk_FUN_fffffff00a97ae84
//   fffffff008b74cf0 thunk_FUN_fffffff00a97ae84
//   fffffff008c78b40 thunk_FUN_fffffff00a97ae84
//   fffffff008e0007c thunk_FUN_fffffff00a97ae84
//   fffffff009173228 thunk_FUN_fffffff00a97ae84
//   fffffff0091b8a0c thunk_FUN_fffffff00a97ae84
//   fffffff00927a67c thunk_FUN_fffffff00a97ae84
//   fffffff00973a28c thunk_FUN_fffffff00a97ae84
//   fffffff0098ced2c thunk_FUN_fffffff00a97ae84
//   fffffff009984768 thunk_FUN_fffffff00a97ae84
//   fffffff009a6e924 thunk_FUN_fffffff00a97ae84
//   fffffff009a9a01c thunk_FUN_fffffff00a97ae84
//   fffffff009abd458 thunk_FUN_fffffff00a97ae84
//   fffffff009b1ac9c thunk_FUN_fffffff00a97ae84
//   fffffff009b7ac68 thunk_FUN_fffffff00a97ae84
//   fffffff009b96e24 thunk_FUN_fffffff00a97ae84
//   fffffff009c10fc4 thunk_FUN_fffffff00a97ae84
//   fffffff009c49970 thunk_FUN_fffffff00a97ae84
//   fffffff009ca9408 thunk_FUN_fffffff00a97ae84
//   fffffff009dabc5c thunk_FUN_fffffff00a97ae84
//   fffffff00a0fff38 thunk_FUN_fffffff00a97ae84
//   fffffff00a1bb324 thunk_FUN_fffffff00a97ae84
//   fffffff00a1bf8e0 thunk_FUN_fffffff00a97ae84
//   fffffff0099b8c64 thunk_FUN_fffffff00a97ae84
// CALLS:

long * FUN_fffffff00a97ae84(undefined8 param_1,undefined8 param_2,uint param_3,long param_4)

{
  long *plVar1;
  ulong uVar2;
  uint uVar3;
  undefined8 local_30;
  undefined8 uStack_28;
  
  local_30 = param_1;
  uStack_28 = param_2;
  plVar1 = (long *)(**(code **)(DAT_fffffff00ad97200 + 0x68))();
  if (plVar1 != (long *)0x0) {
    uVar3 = 0x20;
    if (param_4 != 0) {
      uVar3 = 0x10;
    }
    uVar2 = (**(code **)(*plVar1 + 0x78))(plVar1,&local_30,1,0,param_4,uVar3 | param_3,0);
    if ((uVar2 & 1) == 0) {
      (**(code **)(*plVar1 + 0x28))(plVar1);
      plVar1 = (long *)0x0;
    }
  }
  return plVar1;
}

