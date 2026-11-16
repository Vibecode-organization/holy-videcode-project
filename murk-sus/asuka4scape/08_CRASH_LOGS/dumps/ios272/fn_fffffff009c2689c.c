// FUN_fffffff009c2689c @ fffffff009c2689c size=268

void FUN_fffffff009c2689c(long param_1,long param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  long lVar6;
  undefined8 local_50;
  long local_48;
  
  local_48 = *(long *)PTR_DAT_fffffff00806ca40;
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x50));
  iVar3 = *(int *)(param_2 + 0x4c);
  if (iVar3 != 0) goto LAB_fffffff009c2690c;
  uVar5 = thunk_EXT_FUN_8011000003397c88();
  if ((*(uint *)(param_2 + 0x24) >> 1 & 1) == 0) {
    if ((*(uint *)(param_2 + 0x24) & 1) != 0) {
      lVar6 = 0x330;
      goto LAB_fffffff009c26900;
    }
  }
  else {
    lVar6 = 0x338;
LAB_fffffff009c26900:
    *(undefined8 *)(param_1 + lVar6) = uVar5;
  }
  *(undefined4 *)(param_2 + 0x4c) = 1;
LAB_fffffff009c2690c:
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x50));
  uVar4 = *(undefined4 *)(param_1 + 0x10);
  uVar1 = *(undefined4 *)(param_2 + 0x20);
  uVar2 = *(undefined4 *)(param_2 + 0x24);
  local_50 = 0;
  thunk_EXT_FUN_80110000032db760(*(undefined8 *)(param_1 + 0x30),&local_50);
  thunk_EXT_FUN_80110000036da494(0x8521000c,uVar1,uVar4,uVar2,local_50,0);
  if (iVar3 == 0) {
    if ((*(byte *)(param_1 + 0x3d2) >> 5 & 1) == 0) {
      FUN_fffffff009c2302c(param_1,0);
    }
    FUN_fffffff009c36fa0(DAT_fffffff00af483b0,param_2);
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_48) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590();
  return;
}

