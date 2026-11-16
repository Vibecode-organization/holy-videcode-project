// FUN_fffffff009c209b8 @ fffffff009c209b8 size=416

/* WARNING: Removing unreachable block (ram,0xfffffff009c20ac0) */

void FUN_fffffff009c209b8(long param_1,uint param_2,undefined4 *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  int iVar4;
  long lVar5;
  undefined8 local_40;
  long local_38;
  
  local_38 = *(long *)PTR_DAT_fffffff00806ca40;
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x50));
  if (((param_2 >> 1 & 1) == 0) || (*(long *)(param_1 + 0x38) == 0)) {
    if ((param_2 & 1) == 0) {
      iVar4 = *(int *)(param_1 + 0x23c);
      if (iVar4 == 0) {
        thunk_EXT_FUN_8011000003722ec0(param_1 + 0x2b0,0x40);
        iVar4 = *(int *)(param_1 + 0x23c);
      }
      *(int *)(param_1 + 0x23c) = iVar4 + 1;
    }
    else {
      iVar4 = *(int *)(param_1 + 0x238);
      if (iVar4 == 0) {
        thunk_EXT_FUN_8011000003722ec0(param_1 + 0x270,0x40);
        iVar4 = *(int *)(param_1 + 0x238);
      }
      *(int *)(param_1 + 0x238) = iVar4 + 1;
    }
    FUN_fffffff009c20b58(param_1,0,0,(param_2 & 1) == 0);
    if ((*(byte *)(param_1 + 0x3d0) >> 4 & 1) != 0) {
      FUN_fffffff009c206fc(param_1);
      uVar1 = *(uint *)(param_1 + 0x3d0);
      *(uint *)(param_1 + 0x3d0) = uVar1 & 0xffffffef;
      if ((uVar1 >> 5 & 1) != 0) {
        *(uint *)(param_1 + 0x3d0) = uVar1 & 0xffffffcf;
      }
    }
    lVar5 = *(long *)(param_1 + 0x178);
    if ((param_2 & 1) == 0) {
      *(int *)(lVar5 + 0xc) = *(int *)(lVar5 + 0xc) + 1;
      *(uint *)(param_1 + 0x3d0) = *(uint *)(param_1 + 0x3d0) | 0xc;
    }
    uVar2 = *(undefined4 *)(lVar5 + 0xc);
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = uVar2;
    }
    local_40 = 0;
    thunk_EXT_FUN_80110000032db760(*(undefined8 *)(param_1 + 0x30),&local_40);
    thunk_EXT_FUN_80110000036da494
              (0x85210010,local_40,*(undefined4 *)(param_1 + 0x10),param_2,uVar2,0);
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x50));
    uVar3 = 0;
  }
  else {
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x50));
    uVar3 = 0xe00002cc;
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 != local_38) {
    thunk_EXT_FUN_8011000003a48590(uVar3);
    return;
  }
  return;
}

