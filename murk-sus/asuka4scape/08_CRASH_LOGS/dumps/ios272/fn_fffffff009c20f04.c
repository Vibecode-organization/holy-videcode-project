// FUN_fffffff009c20f04 @ fffffff009c20f04 size=452

/* WARNING: Removing unreachable block (ram,0xfffffff009c21014) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c2105c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c20f78) */

undefined8 FUN_fffffff009c20f04(long param_1,uint param_2,undefined4 *param_3)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_40;
  long local_38;
  
  local_38 = *(long *)PTR_DAT_fffffff00806ca40;
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x50));
  if ((param_2 & 1) == 0) {
    if (*(int *)(param_1 + 0x23c) == 0) {
LAB_fffffff009c21084:
      uVar3 = 0xe00002c2;
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x50));
      goto LAB_fffffff009c21094;
    }
    *(int *)(param_1 + 0x23c) = *(int *)(param_1 + 0x23c) + -1;
    *(int *)(*(long *)(param_1 + 0x178) + 0x10) = *(int *)(*(long *)(param_1 + 0x178) + 0x10) + 1;
    iVar2 = *(int *)(param_1 + 0x9c);
    if (((iVar2 == 0x200) || (iVar2 == 0x400)) || (iVar2 == 0x700)) {
      thunk_EXT_FUN_8011000003390134();
      iVar2 = *(int *)(param_1 + 0x9c);
    }
    uVar1 = iVar2 - 0x100U >> 8;
    if (6 < (uVar1 | iVar2 << 0x18) || (1 << (ulong)(uVar1 & 0x1f) & 0x4bU) == 0) {
      *(uint *)(param_1 + 0x3d0) = *(uint *)(param_1 + 0x3d0) | 0x20;
    }
  }
  else {
    if (*(int *)(param_1 + 0x238) == 0) goto LAB_fffffff009c21084;
    *(int *)(param_1 + 0x238) = *(int *)(param_1 + 0x238) + -1;
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = *(undefined4 *)(*(long *)(param_1 + 0x178) + 0xc);
  }
  local_40 = 0;
  thunk_EXT_FUN_80110000032db760(*(undefined8 *)(param_1 + 0x30),&local_40);
  thunk_EXT_FUN_80110000036da494
            (0x85210014,local_40,*(undefined4 *)(param_1 + 0x10),param_2,
             *(undefined4 *)(*(long *)(param_1 + 0x178) + 0xc),0);
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x50));
  uVar3 = 0;
LAB_fffffff009c21094:
  if (*(long *)PTR_DAT_fffffff00806ca40 != local_38) {
    uVar3 = thunk_EXT_FUN_8011000003a48590();
    return uVar3;
  }
  return uVar3;
}

