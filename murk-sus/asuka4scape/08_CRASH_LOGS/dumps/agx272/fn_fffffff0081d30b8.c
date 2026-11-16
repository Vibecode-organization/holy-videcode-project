// FUN_fffffff0081d30b8 @ fffffff0081d30b8 size=192

void FUN_fffffff0081d30b8(long param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  long *plVar4;
  undefined8 local_40;
  undefined8 local_38;
  
  lVar2 = thunk_EXT_FUN_801100000320503c();
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0xd8));
  plVar4 = (long *)(param_1 + 0xe0);
  lVar3 = *plVar4;
  while (lVar3 == 0) {
    local_38 = 0;
    thunk_EXT_FUN_8011000003204ed8(0x14,1000000000,&local_38);
    iVar1 = thunk_EXT_FUN_80110000038ff078(*(undefined8 *)(param_1 + 0xd8),plVar4,local_38,0);
    if (iVar1 == 1) {
      local_40 = 0;
      lVar3 = thunk_EXT_FUN_801100000320503c();
      thunk_EXT_FUN_8011000003398228(lVar3 - lVar2,&local_40);
    }
    lVar3 = *plVar4;
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0xd8));
  lVar3 = thunk_EXT_FUN_801100000320503c();
  local_38 = 0;
  thunk_EXT_FUN_8011000003398228(lVar3 - lVar2,&local_38);
  return;
}

