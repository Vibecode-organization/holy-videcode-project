// FUN_fffffff009c37054 @ fffffff009c37054 size=4

/* WARNING: Removing unreachable block (ram,0xfffffff009c370d0) */

undefined8 FUN_fffffff009c37054(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  undefined1 *puStack_30;
  long lStack_28;
  
  lStack_28 = *(long *)PTR_DAT_fffffff00806ca40;
  if ((*(byte *)(param_2 + 0x50) & 1) == 0) {
    puStack_30 = &DAT_aaaaaaaaaaaaaaaa;
    thunk_EXT_FUN_8011000003204ed8(1,1000000000,&puStack_30);
    lVar2 = **(long **)(param_1 + 0x1b8);
    iVar1 = (**(code **)(lVar2 + 0x110))
                      (lVar2 + 0x110,*(long **)(param_1 + 0x1b8),param_2,puStack_30,2);
    if (iVar1 != 0) {
      uVar3 = 0xe00002bc;
      if (iVar1 == 1) {
        thunk_EXT_FUN_80110000038fe9a0("IOFence: blocking wait timed out for surface: %d\n");
        uVar3 = 0xe00002d6;
      }
      goto LAB_fffffff009c37128;
    }
  }
  uVar3 = 0;
LAB_fffffff009c37128:
  if (*(long *)PTR_DAT_fffffff00806ca40 != lStack_28) {
    uVar3 = thunk_EXT_FUN_8011000003a48590();
    return uVar3;
  }
  return uVar3;
}

