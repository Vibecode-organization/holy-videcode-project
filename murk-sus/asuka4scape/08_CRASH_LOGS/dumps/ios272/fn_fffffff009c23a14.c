// FUN_fffffff009c23a14 @ fffffff009c23a14 size=540

/* WARNING: Removing unreachable block (ram,0xfffffff009c23b34) */

undefined8 FUN_fffffff009c23a14(long param_1)

{
  undefined4 uVar1;
  int iVar2;
  long *plVar3;
  undefined8 uVar4;
  undefined1 local_30 [2];
  undefined1 uStack_2e;
  undefined1 uStack_2d;
  undefined3 uStack_2b;
  long local_28;
  
  local_28 = *(long *)PTR_DAT_fffffff00806ca40;
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x398));
  iVar2 = thunk_EXT_FUN_801100000389060c(param_1 + 0x22c);
  if (iVar2 == 1) {
    iVar2 = FUN_fffffff009c31488(0x100);
    if (iVar2 == 0) {
      iVar2 = FUN_fffffff009c31488(0x20);
      if (iVar2 == 0) {
        iVar2 = FUN_fffffff009c31488(0x40);
        uVar4 = _local_30;
        if ((iVar2 != 0) && (*(int *)(*(long *)(param_1 + 0x178) + 0x24) == 0)) {
          uVar1 = *(undefined4 *)(param_1 + 0x80);
          uStack_2b = SUB83(uVar4,5);
          _local_30 = (uint5)CONCAT13((char)uVar1,
                                      CONCAT12((char)((uint)uVar1 >> 8),
                                               CONCAT11((char)((uint)uVar1 >> 0x10),
                                                        (char)((uint)uVar1 >> 0x18))));
          plVar3 = *(long **)(param_1 + 0x1a8);
          if (plVar3 == (long *)0x0) {
            thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x50));
            FUN_fffffff009c20460(param_1);
            thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x50));
            plVar3 = *(long **)(param_1 + 0x1a8);
          }
          uVar4 = (**(code **)(*plVar3 + 0x138))(plVar3,"IOSurfaceName");
          plVar3 = (long *)thunk_EXT_FUN_8011000003890f30
                                     (uVar4,*(undefined8 *)PTR_DAT_fffffff00806ca10);
          if (plVar3 != (long *)0x0) {
            (**(code **)(*plVar3 + 0xa8))();
          }
          thunk_EXT_FUN_80110000038db19c
                    (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0,
                     "sid %08x complete() without assertion. dims: %llux%llu, fmt: %s, name: %s\n");
        }
      }
      else {
        (**(code **)(**(long **)(param_1 + 0x30) + 0xe0))(*(long **)(param_1 + 0x30),0);
      }
    }
    else {
      *(uint *)(param_1 + 0x3d0) = *(uint *)(param_1 + 0x3d0) | 0x400;
    }
    _local_30 = 0;
    thunk_EXT_FUN_80110000032db760(*(undefined8 *)(param_1 + 0x30),local_30);
    thunk_EXT_FUN_80110000036da494(0x85210020,_local_30,*(undefined4 *)(param_1 + 0x10),0,0,0);
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x398));
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_28) {
    return 0;
  }
  uVar4 = thunk_EXT_FUN_8011000003a48590();
  return uVar4;
}

