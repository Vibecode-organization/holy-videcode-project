// FUN_fffffff009c3d038 @ fffffff009c3d038 size=308

/* WARNING: Removing unreachable block (ram,0xfffffff009c3d094) */

ulong FUN_fffffff009c3d038(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  undefined8 uVar4;
  long lVar5;
  undefined1 *local_48;
  long *local_40;
  long local_38;
  
  local_38 = *(long *)PTR_DAT_fffffff00806ca40;
  local_40 = (long *)0x0;
  lVar5 = *(long *)(param_1 + 0xf8);
  if (lVar5 == 0) {
    lVar5 = 0;
  }
  uVar3 = thunk_EXT_FUN_80110000039a3bc0(lVar5,param_2,&local_40);
  if ((int)uVar3 == 0) {
    uVar3 = 0xe00002c2;
    lVar5 = thunk_EXT_FUN_8011000003890f30(local_40,DAT_fffffff0080668c8);
    if (lVar5 != 0) {
      local_48 = &DAT_aaaaaaaaaaaaaaaa;
      thunk_EXT_FUN_8011000003204ed8(param_4,1000000,&local_48);
      uVar4 = FUN_fffffff009c16750(lVar5);
      iVar2 = FUN_fffffff009c172ec(uVar4,param_3,local_48);
      uVar1 = 0;
      if (iVar2 == 0) {
        uVar1 = 0xe00002d6;
      }
      uVar3 = (ulong)uVar1;
    }
  }
  if (local_40 != (long *)0x0) {
    (**(code **)(*local_40 + 0x28))();
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_38) {
    return uVar3;
  }
  uVar3 = thunk_EXT_FUN_8011000003a48590();
  return uVar3;
}

