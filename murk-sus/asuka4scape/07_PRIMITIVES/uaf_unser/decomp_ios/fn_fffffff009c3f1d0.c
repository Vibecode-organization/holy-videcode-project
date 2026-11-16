// FUN_fffffff009c3f1d0 @ fffffff009c3f1d0 size=224
// CALLERS:
//   fffffff009c3f7cc FUN_fffffff009c3f77c@fffffff009c3f77c
//   fffffff009c3ac4c FUN_fffffff009c3ab8c@fffffff009c3ab8c
//   fffffff009c3b5cc FUN_fffffff009c3b58c@fffffff009c3b58c
//   fffffff009c3ba1c FUN_fffffff009c3b9f8@fffffff009c3b9f8
//   fffffff009c3bacc FUN_fffffff009c3bab4@fffffff009c3bab4
//   fffffff009c3c368 FUN_fffffff009c3c354@fffffff009c3c354
//   fffffff009c3c3ec FUN_fffffff009c3c3bc@fffffff009c3c3bc
//   fffffff009c3c57c FUN_fffffff009c3c538@fffffff009c3c538
//   fffffff009c3cac8 FUN_fffffff009c3caa8@fffffff009c3caa8
//   fffffff009c3d2e8 FUN_fffffff009c3d2d0@fffffff009c3d2d0
//   fffffff009c3d3ac FUN_fffffff009c3d38c@fffffff009c3d38c
//   fffffff009c3d42c FUN_fffffff009c3d408@fffffff009c3d408
//   fffffff009c3d4a4 FUN_fffffff009c3d48c@fffffff009c3d48c
//   fffffff009c3d510 FUN_fffffff009c3d4f8@fffffff009c3d4f8
//   fffffff009c3d594 FUN_fffffff009c3d564@fffffff009c3d564
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

/* WARNING: Removing unreachable block (ram,0xfffffff009c3f244) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long * FUN_fffffff009c3f1d0(long param_1,undefined8 param_2)

{
  int iVar1;
  long *plVar2;
  long local_30;
  long local_28;
  
  local_28 = *_DAT_fffffff00806ca40;
  FUN_fffffff009c495b4(*(undefined8 *)(param_1 + 0xd8));
  local_30 = 0;
  iVar1 = FUN_fffffff009c3f044(param_1,param_2,&local_30);
  if ((iVar1 == 0) || (plVar2 = *(long **)(local_30 + 0x40), plVar2 == (long *)0x0)) {
    plVar2 = (long *)0x0;
  }
  else if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 0x20))(plVar2);
  }
  FUN_fffffff009c495d4(*(undefined8 *)(param_1 + 0xd8));
  if (*_DAT_fffffff00806ca40 != local_28) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff009c49b64();
  }
  return plVar2;
}

