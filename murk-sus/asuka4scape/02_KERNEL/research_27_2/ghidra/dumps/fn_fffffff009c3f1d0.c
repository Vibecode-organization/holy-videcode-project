// FUN_fffffff009c3f1d0 @ fffffff009c3f1d0 size=224
// CALLERS:
//   fffffff00afec116 no-fn
//   fffffff009c3f7cc FUN_fffffff009c3f77c@fffffff009c3f77c
//   fffffff009c3ac4c FUN_fffffff009c3ab8c@fffffff009c3ab8c
//   fffffff009c3b5cc FUN_fffffff009c3b58c@fffffff009c3b58c
//   fffffff009c3ba1c FUN_fffffff009c3b9f8@fffffff009c3b9f8
//   fffffff009c3bacc FUN_fffffff009c3bab4@fffffff009c3bab4
//   fffffff009c3c368 FUN_fffffff009c3c354@fffffff009c3c354
//   fffffff009c3c3ec FUN_fffffff009c3c3b8@fffffff009c3c3b8
//   fffffff009c3c57c FUN_fffffff009c3c538@fffffff009c3c538
//   fffffff009c3cac8 FUN_fffffff009c3caa8@fffffff009c3caa8
//   fffffff009c3d2e8 FUN_fffffff009c3d2d0@fffffff009c3d2d0
//   fffffff009c3d3ac FUN_fffffff009c3d38c@fffffff009c3d38c
//   fffffff009c3d42c FUN_fffffff009c3d408@fffffff009c3d408
//   fffffff009c3d4a4 FUN_fffffff009c3d48c@fffffff009c3d48c
//   fffffff009c3d510 FUN_fffffff009c3d4f8@fffffff009c3d4f8
//   fffffff009c3d594 FUN_fffffff009c3d560@fffffff009c3d560
//   fffffff009c3d7e4 FUN_fffffff009c3d7c8@fffffff009c3d7c8
//   fffffff009c3d778 FUN_fffffff009c3d760@fffffff009c3d760
//   fffffff009c3d874 FUN_fffffff009c3d838@fffffff009c3d838
//   fffffff009c3d91c FUN_fffffff009c3d908@fffffff009c3d908
//   fffffff009c3d998 FUN_fffffff009c3d978@fffffff009c3d978
//   fffffff009c3da78 FUN_fffffff009c3da58@fffffff009c3da58
//   fffffff009c3e274 FUN_fffffff009c3e22c@fffffff009c3e22c
//   fffffff009c4052c FUN_fffffff009c40508@fffffff009c40508
//   fffffff009c405ac FUN_fffffff009c40588@fffffff009c40588
//   fffffff009c40658 FUN_fffffff009c4060c@fffffff009c4060c
//   fffffff009c4073c FUN_fffffff009c40728@fffffff009c40728
//   fffffff009c3c918 FUN_fffffff009c3c8d4@fffffff009c3c8d4
//   fffffff009c40834 FUN_fffffff009c407ec@fffffff009c407ec
//   fffffff009c40a00 FUN_fffffff009c409ec@fffffff009c409ec
//   fffffff009c40a8c FUN_fffffff009c40a4c@fffffff009c40a4c
//   fffffff009c3cf9c FUN_fffffff009c3cf68@fffffff009c3cf68
//   fffffff009c3c9f4 FUN_fffffff009c3c9c0@fffffff009c3c9c0
//   fffffff009c3d280 FUN_fffffff009c3d268@fffffff009c3d268
// CALLEES:
//   fffffff009c495d4 thunk_FUN_fffffff00a226de0
//   fffffff009c49b64 thunk_FUN_fffffff00aa4c590
//   fffffff009c3f044 FUN_fffffff009c3f044
//   fffffff009c495b4 thunk_FUN_fffffff00a2262a8

/* WARNING: Removing unreachable block (ram,0xfffffff009c3f244) */

long * FUN_fffffff009c3f1d0
                 (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
                 undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
                 uint param_8)

{
  undefined8 uVar1;
  long *plVar2;
  undefined1 auVar3 [16];
  long local_30;
  long local_28;
  
  local_28 = *(long *)PTR_DAT_fffffff00806ca40;
  auVar3 = thunk_FUN_fffffff00a2262a8(*(ulong *)(param_7 + 0xd8));
  local_30 = 0;
  uVar1 = FUN_fffffff009c3f044
                    (auVar3,param_2,param_3,param_4,param_5,param_6,param_7,param_8,&local_30);
  if (((int)uVar1 == 0) || (plVar2 = *(long **)(local_30 + 0x40), plVar2 == (long *)0x0)) {
    plVar2 = (long *)0x0;
  }
  else if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 0x20))(plVar2);
  }
  thunk_FUN_fffffff00a226de0(*(ulong *)(param_7 + 0xd8));
  if (*(long *)PTR_DAT_fffffff00806ca40 != local_28) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_fffffff00aa4c590();
  }
  return plVar2;
}

