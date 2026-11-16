// FUN_fffffff009c2aa08 @ fffffff009c2aa08 size=316

/* WARNING: Removing unreachable block (ram,0xfffffff009c2aacc) */

void FUN_fffffff009c2aa08(long param_1,long *param_2)

{
  int iVar1;
  undefined8 uVar2;
  long *local_40;
  long local_38;
  
  local_38 = *(long *)PTR_DAT_fffffff00806ca40;
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x50));
  uVar2 = *(undefined8 *)(param_1 + 0x3c8);
  local_40 = param_2;
  if (param_2 != (long *)0x0) {
    (**(code **)(*param_2 + 0x20))(param_2);
  }
  thunk_EXT_FUN_80110000038963f0(uVar2,&local_40);
  if (local_40 != (long *)0x0) {
    (**(code **)(*local_40 + 0x28))();
  }
  iVar1 = FUN_fffffff009c48d20(param_2);
  if (iVar1 != 0) {
    *(int *)(*(long *)(param_1 + 0x178) + 0xc) = *(int *)(*(long *)(param_1 + 0x178) + 0xc) + 1;
    *(uint *)(param_1 + 0x3d0) = *(uint *)(param_1 + 0x3d0) | 0xc;
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x50));
  if (param_2 != (long *)0x0) {
    (**(code **)(*param_2 + 0x28))(param_2);
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 != local_38) {
    thunk_EXT_FUN_8011000003a48590();
    return;
  }
  return;
}

