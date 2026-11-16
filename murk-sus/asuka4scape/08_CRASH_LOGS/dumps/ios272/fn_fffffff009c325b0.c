// FUN_fffffff009c325b0 @ fffffff009c325b0 size=360

ulong FUN_fffffff009c325b0(long *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  long *plVar5;
  long *plVar6;
  ulong uVar7;
  undefined8 local_40;
  long local_38;
  
  local_38 = *(long *)PTR_DAT_fffffff00806ca40;
  lVar4 = (**(code **)(*param_1 + 0x178))(param_1,*(undefined8 *)PTR_DAT_fffffff00806ca50);
  if (lVar4 != 0) {
    local_40 = 0;
    thunk_EXT_FUN_8011000003904630(lVar4,(long)&local_40 + 4,&local_40);
    if (local_40._4_4_ != 0) {
      plVar5 = (long *)(**(code **)(*param_1 + 0x148))(param_1,"reg");
      plVar6 = (long *)thunk_EXT_FUN_8011000003890f30
                                 (plVar5,*(undefined8 *)PTR_DAT_fffffff00806c9e8);
      if (plVar6 == (long *)0x0) {
        if (plVar5 == (long *)0x0) goto LAB_fffffff009c326e0;
        uVar7 = 0;
      }
      else {
        uVar3 = (**(code **)(*plVar6 + 0xa0))();
        uVar1 = ((int)local_40 + local_40._4_4_) * 4;
        uVar2 = 0;
        if (uVar1 != 0) {
          uVar2 = uVar3 / uVar1;
        }
        uVar7 = (ulong)uVar2;
        plVar5 = plVar6;
      }
      (**(code **)(*plVar5 + 0x28))(plVar5);
      goto LAB_fffffff009c326e4;
    }
  }
LAB_fffffff009c326e0:
  uVar7 = 0;
LAB_fffffff009c326e4:
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_38) {
    return uVar7;
  }
  uVar7 = thunk_EXT_FUN_8011000003a48590();
  return uVar7;
}

