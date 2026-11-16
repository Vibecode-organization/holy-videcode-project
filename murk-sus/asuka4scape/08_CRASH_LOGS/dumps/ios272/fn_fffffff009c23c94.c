// FUN_fffffff009c23c94 @ fffffff009c23c94 size=240

void FUN_fffffff009c23c94(long param_1)

{
  long *plVar1;
  undefined8 uVar2;
  undefined8 local_30;
  long local_28;
  
  local_28 = *(long *)PTR_DAT_fffffff00806ca40;
  plVar1 = *(long **)(param_1 + 0x1a8);
  if (plVar1 != (long *)0x0) {
    uVar2 = (**(code **)(*plVar1 + 0x138))(plVar1,"IOSurfaceName");
    plVar1 = (long *)thunk_EXT_FUN_8011000003890f30(uVar2,*(undefined8 *)PTR_DAT_fffffff00806ca10);
    if (plVar1 != (long *)0x0) {
      local_30 = 0;
      uVar2 = (**(code **)(*plVar1 + 0xa8))();
      thunk_EXT_FUN_80110000036dc388(0x5400008,&local_30,uVar2);
      thunk_EXT_FUN_80110000036dbac4(0x5400008,*(undefined4 *)(param_1 + 0x10),local_30,0,0);
    }
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_28) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590();
  return;
}

