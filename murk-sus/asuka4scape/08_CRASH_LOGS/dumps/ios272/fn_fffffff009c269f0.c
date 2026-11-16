// FUN_fffffff009c269f0 @ fffffff009c269f0 size=264

void FUN_fffffff009c269f0(long param_1,long param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  long lVar6;
  undefined8 local_50;
  long local_48;
  
  local_48 = *(long *)PTR_DAT_fffffff00806ca40;
  iVar1 = *(int *)(param_2 + 0x4c);
  if (iVar1 != 0) {
    uVar2 = *(uint *)(param_2 + 0x24);
    goto LAB_fffffff009c26a60;
  }
  uVar5 = thunk_EXT_FUN_8011000003397c88();
  uVar2 = *(uint *)(param_2 + 0x24);
  if ((uVar2 >> 1 & 1) == 0) {
    if ((uVar2 & 1) != 0) {
      lVar6 = 0x330;
      goto LAB_fffffff009c26a54;
    }
  }
  else {
    lVar6 = 0x338;
LAB_fffffff009c26a54:
    *(undefined8 *)(param_1 + lVar6) = uVar5;
  }
  *(undefined4 *)(param_2 + 0x4c) = 1;
LAB_fffffff009c26a60:
  uVar3 = *(undefined4 *)(param_2 + 0x20);
  uVar4 = *(undefined4 *)(param_1 + 0x10);
  local_50 = 0;
  thunk_EXT_FUN_80110000032db760(*(undefined8 *)(param_1 + 0x30),&local_50);
  thunk_EXT_FUN_80110000036da494(0x8521000c,uVar3,uVar4,uVar2,local_50,0);
  if (iVar1 == 0) {
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

