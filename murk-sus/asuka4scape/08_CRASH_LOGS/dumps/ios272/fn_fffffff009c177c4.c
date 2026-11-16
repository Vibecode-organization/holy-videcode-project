// FUN_fffffff009c177c4 @ fffffff009c177c4 size=312

undefined8 FUN_fffffff009c177c4(long param_1,long param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  undefined4 local_3c;
  long local_38;
  
  local_38 = *(long *)PTR_DAT_fffffff00806ca40;
  if ((((*(byte *)(param_1 + 0x50) >> 1 & 1) != 0) &&
      (iVar1 = FUN_fffffff009c31488(0x80000), iVar1 == 0)) &&
     (lVar3 = *(long *)(param_2 + 0x48), lVar3 != 0)) {
    local_3c = 0xaaaaaaaa;
    iVar1 = FUN_fffffff009c178fc(param_1,param_3,&local_3c);
    if (iVar1 != 0) {
      uVar2 = 0xe00002bc;
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                 "%s: failed to assign agent mask slot for value %llu: 0x%x\n");
      goto LAB_fffffff009c17814;
    }
    iVar1 = FUN_fffffff009c17b2c(param_1,param_3,local_3c,lVar3);
    if (iVar1 != 0) {
      uVar2 = 0xe00002bc;
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                 "%s: failed to add agent mask for value %llu: 0x%x\n");
      goto LAB_fffffff009c17814;
    }
  }
  uVar2 = 0;
LAB_fffffff009c17814:
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_38) {
    return uVar2;
  }
  uVar2 = thunk_EXT_FUN_8011000003a48590();
  return uVar2;
}

