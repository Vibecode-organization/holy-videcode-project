// FUN_fffffff00994b57c @ fffffff00994b57c size=308

ulong FUN_fffffff00994b57c(long param_1,ulong param_2)

{
  int *piVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  int iVar4;
  ulong uVar5;
  ulong uVar6;
  long lVar7;
  long local_58;
  long local_50;
  ulong local_48;
  
  lVar7 = (long)(int)param_2;
  uVar5 = lVar7 << 4 | 8;
  piVar1 = (int *)(param_1 + 0x40 + (long)(int)uVar5);
  if (uVar5 != (long)(int)uVar5) {
    piVar1 = (int *)(param_1 + 0x40 + uVar5 & 0xffffffffffff | 0x2bad000000000000);
  }
  uVar5 = (param_2 & 0xffffffff) << 3;
  uVar6 = -(param_2 >> 0x1f & 1) & 0xfffffff800000000 | uVar5;
  iVar4 = (int)uVar5;
  puVar2 = (undefined8 *)(*(long *)(param_1 + 0x20) + (long)iVar4);
  if (uVar6 != (long)iVar4) {
    puVar2 = (undefined8 *)(*(long *)(param_1 + 0x20) + uVar6 & 0xffffffffffff | 0x2bad000000000000)
    ;
  }
  iVar4 = *piVar1;
  if (iVar4 - *(int *)*puVar2 < 1) {
    local_48 = 0;
  }
  else {
    local_50 = 0;
    local_48 = 0;
    local_58 = 0;
    thunk_EXT_FUN_8011000003205048(&local_50);
    uVar3 = thunk_EXT_FUN_801100000390ebc0(*(undefined8 *)(param_1 + 0x10));
    thunk_EXT_FUN_80110000036da494(0x85090055,lVar7,iVar4,uVar3,0,0);
    FUN_fffffff00994abdc(param_1,param_2,iVar4);
    uVar3 = thunk_EXT_FUN_801100000390ebc0(*(undefined8 *)(param_1 + 0x10));
    thunk_EXT_FUN_80110000036da494(0x85090056,lVar7,iVar4,uVar3,0,0);
    thunk_EXT_FUN_8011000003205048(&local_58);
    local_58 = local_58 - local_50;
    thunk_EXT_FUN_8011000003398228(local_58,&local_48);
    local_48 = local_48 & 0xffffffff;
  }
  return local_48;
}

