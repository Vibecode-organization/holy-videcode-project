// FUN_fffffff009c3b7b0 @ fffffff009c3b7b0 size=584

/* WARNING: Removing unreachable block (ram,0xfffffff009c3b8e0) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c3b910) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c3b818) */

undefined8 FUN_fffffff009c3b7b0(long param_1,undefined8 param_2,undefined8 *param_3)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 extraout_x1;
  long lVar3;
  long lVar4;
  long *plVar5;
  long *local_58;
  undefined1 *local_50;
  long local_48;
  
  local_48 = *(long *)PTR_DAT_fffffff00806ca40;
  local_58 = (long *)0x0;
  lVar3 = *(long *)(param_1 + 0xf8);
  if (lVar3 == 0) {
    lVar3 = 0;
  }
  local_50 = &DAT_aaaaaaaaaaaaaaaa;
  uVar2 = thunk_EXT_FUN_80110000039a3bc0(lVar3,param_2,&local_58);
  if ((int)uVar2 != 0) {
    plVar5 = (long *)0x0;
    goto LAB_fffffff009c3b978;
  }
  uVar2 = 0xe00002bd;
  lVar3 = thunk_EXT_FUN_8011000003890f30(local_58,DAT_fffffff00806a850);
  if (lVar3 == 0) {
    plVar5 = (long *)0x0;
    uVar2 = 0xe00002c2;
    goto LAB_fffffff009c3b978;
  }
  lVar3 = *(long *)(lVar3 + 0x18);
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0xd8));
  iVar1 = FUN_fffffff009c3f044(param_1,*(undefined4 *)(lVar3 + 0x10),&local_50);
  if (iVar1 == 0) {
    if ((*(byte *)(lVar3 + 0x3d2) >> 3 & 1) != 0) {
      lVar4 = *(long *)(lVar3 + 0x170);
      if (lVar4 == 0) {
        lVar4 = 0;
      }
      if (lVar4 != *(long *)(param_1 + 0xf8)) {
        plVar5 = (long *)0x0;
        uVar2 = 0xe00002c2;
        goto LAB_fffffff009c3b970;
      }
    }
    plVar5 = (long *)FUN_fffffff009c2b810(*(undefined8 *)(param_1 + 0x118),lVar3,0);
    if ((plVar5 != (long *)0x0) &&
       (iVar1 = FUN_fffffff009c3f2b0(param_1,plVar5,*(undefined4 *)(lVar3 + 0x10)), iVar1 != 0)) {
      FUN_fffffff009c3f478(param_1,extraout_x1,0);
      FUN_fffffff009c2c18c(plVar5,param_3);
      uVar2 = 0;
    }
  }
  else {
    plVar5 = (long *)0x0;
    uVar2 = 0;
    *param_3 = 0xffffffffffffffff;
    *(undefined4 *)(param_3 + 3) = *(undefined4 *)(local_50 + 0x38);
  }
LAB_fffffff009c3b970:
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0xd8));
LAB_fffffff009c3b978:
  if (local_58 != (long *)0x0) {
    (**(code **)(*local_58 + 0x28))();
  }
  if (plVar5 != (long *)0x0) {
    (**(code **)(*plVar5 + 0x28))(plVar5);
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 != local_48) {
    uVar2 = thunk_EXT_FUN_8011000003a48590();
    return uVar2;
  }
  return uVar2;
}

