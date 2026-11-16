// FUN_fffffff009c24b28 @ fffffff009c24b28 size=684

/* WARNING: Removing unreachable block (ram,0xfffffff009c24ba8) */

ulong FUN_fffffff009c24b28(long param_1,long *param_2,undefined8 param_3,int *param_4)

{
  byte bVar1;
  undefined1 uVar2;
  int iVar3;
  long lVar4;
  long *plVar5;
  ulong uVar6;
  undefined *local_b0;
  undefined8 local_a8;
  code *local_a0;
  undefined *local_98;
  undefined8 *puStack_90;
  undefined8 *local_88;
  long lStack_80;
  undefined8 local_78;
  undefined8 *local_70;
  undefined8 local_68;
  undefined1 local_60;
  undefined8 local_58;
  undefined8 *local_50;
  undefined8 local_48;
  undefined1 local_40;
  long local_38;
  
  local_38 = *(long *)PTR_DAT_fffffff00806ca40;
  local_50 = &local_58;
  local_58 = 0;
  local_48 = DAT_fffffff0078a1288;
  local_40 = 0;
  local_70 = &local_78;
  local_78 = 0;
  local_68 = DAT_fffffff0078a1288;
  local_60 = 0;
  iVar3 = (*(uint *)(*(long *)(param_1 + 0x178) + 0x20) | 1) + 2;
  *(int *)(*(long *)(param_1 + 0x178) + 0x20) = iVar3;
  *param_4 = iVar3;
  if ((*(long *)(param_1 + 0x1a8) == 0) &&
     (FUN_fffffff009c20460(param_1), *(long *)(param_1 + 0x1a8) == 0)) {
    *(undefined1 *)(local_50 + 3) = 0;
  }
  else if (param_2 == (long *)0x0) {
    lVar4 = thunk_EXT_FUN_8011000003890f30(param_3,*(undefined8 *)PTR_DAT_fffffff00806c9c8);
    if (lVar4 != 0) {
      local_b0 = PTR_DAT_fffffff00806c9b8;
      local_a8 = DAT_fffffff0078a1290;
      local_a0 = FUN_fffffff009c24dd4;
      puStack_90 = &local_58;
      local_98 = &DAT_fffffff008067268;
      local_88 = &local_78;
      lStack_80 = param_1;
      thunk_EXT_FUN_801100000389d600(lVar4,&local_b0);
    }
  }
  else {
    iVar3 = (**(code **)(*param_2 + 0xb8))(param_2,"CreationProperties");
    if (iVar3 == 0) {
      iVar3 = (**(code **)(*param_2 + 0xb8))(param_2,"IOSurfaceName");
      if (iVar3 != 0) {
        *(undefined1 *)(local_70 + 3) = 1;
      }
      uVar2 = (**(code **)(**(long **)(param_1 + 0x1a8) + 0xf0))
                        (*(long **)(param_1 + 0x1a8),param_2,param_3);
      *(undefined1 *)(local_50 + 3) = uVar2;
    }
    else {
      *(undefined1 *)(local_50 + 3) = 1;
    }
  }
  FUN_fffffff009c23c30(param_1,0);
  FUN_fffffff009c23c94(param_1);
  if ((((*(byte *)(local_70 + 3) & 1) != 0) && (*(long *)(param_1 + 0x30) != 0)) &&
     (*(long *)(param_1 + 0x378) == 0)) {
    plVar5 = (long *)FUN_fffffff009c2cf30(param_1);
    thunk_EXT_FUN_8011000003977a94(*(undefined8 *)(param_1 + 0x30),plVar5);
    if (plVar5 != (long *)0x0) {
      (**(code **)(*plVar5 + 0x28))(plVar5);
    }
  }
  bVar1 = *(byte *)(local_50 + 3);
  thunk_EXT_FUN_80110000038e9dac(&local_78,8);
  thunk_EXT_FUN_80110000038e9dac(&local_58,8);
  if (*(long *)PTR_DAT_fffffff00806ca40 != local_38) {
    uVar6 = thunk_EXT_FUN_8011000003a48590();
    return uVar6;
  }
  return (ulong)(bVar1 & 1);
}

