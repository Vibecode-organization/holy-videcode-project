// FUN_fffffff009c3dbec @ fffffff009c3dbec size=364

/* WARNING: Removing unreachable block (ram,0xfffffff009c3dc5c) */

ulong FUN_fffffff009c3dbec
                (long param_1,undefined8 param_2,undefined8 *param_3,undefined8 param_4,
                undefined8 *param_5,undefined8 *param_6)

{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  undefined8 uVar4;
  long lVar5;
  undefined8 uVar6;
  long *local_60;
  long local_58;
  
  local_58 = *(long *)PTR_DAT_fffffff00806ca40;
  local_60 = (long *)0x0;
  lVar5 = *(long *)(param_1 + 0xf8);
  if (lVar5 == 0) {
    lVar5 = 0;
  }
  uVar3 = thunk_EXT_FUN_80110000039a3bc0(lVar5,param_2,&local_60);
  if ((int)uVar3 == 0) {
    uVar3 = 0xe00002c2;
    lVar5 = thunk_EXT_FUN_8011000003890f30(local_60,DAT_fffffff0080668c8);
    if (lVar5 != 0) {
      FUN_fffffff009c16750();
      uVar4 = FUN_fffffff009c17500();
      *param_3 = uVar4;
      FUN_fffffff009c16750(lVar5);
      uVar4 = FUN_fffffff009c174f4();
      *param_5 = uVar4;
      FUN_fffffff009c16750(lVar5);
      uVar4 = FUN_fffffff009c17584();
      *param_6 = uVar4;
      uVar6 = *(undefined8 *)(param_1 + 0x118);
      FUN_fffffff009c16750(lVar5);
      uVar4 = FUN_fffffff009c17530();
      iVar2 = FUN_fffffff009c41eec(uVar6,uVar4,param_4);
      uVar1 = 0;
      if (iVar2 == 0) {
        uVar1 = 0xe00002c8;
      }
      uVar3 = (ulong)uVar1;
    }
  }
  if (local_60 != (long *)0x0) {
    (**(code **)(*local_60 + 0x28))();
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_58) {
    return uVar3;
  }
  uVar3 = thunk_EXT_FUN_8011000003a48590();
  return uVar3;
}

