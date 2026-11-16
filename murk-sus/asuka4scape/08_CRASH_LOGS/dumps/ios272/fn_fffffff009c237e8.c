// FUN_fffffff009c237e8 @ fffffff009c237e8 size=556

/* WARNING: Removing unreachable block (ram,0xfffffff009c238d8) */

void FUN_fffffff009c237e8(long param_1)

{
  undefined4 uVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  uint uVar5;
  undefined1 local_40 [2];
  undefined1 uStack_3e;
  undefined1 uStack_3d;
  undefined3 uStack_3b;
  long local_38;
  
  local_38 = *(long *)PTR_DAT_fffffff00806ca40;
  if (*(long *)(param_1 + 0x30) == 0) {
    uVar4 = 0xe00002bc;
  }
  else {
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x398));
    iVar2 = thunk_EXT_FUN_80110000038905fc(param_1 + 0x22c);
    if (iVar2 == 0) {
      if (((*(byte *)(param_1 + 0x3d1) >> 2 & 1) == 0) &&
         (iVar2 = FUN_fffffff009c31488(0x120), iVar2 != 0)) {
        iVar2 = (**(code **)(**(long **)(param_1 + 0x30) + 0xd8))(*(long **)(param_1 + 0x30),0);
        uVar5 = (uint)(iVar2 == 0);
      }
      else {
        uVar5 = 1;
      }
      lVar3 = (**(code **)(**(long **)(param_1 + 0x30) + 0xa0))();
      iVar2 = FUN_fffffff009c31488(0x20);
      uVar4 = _local_40;
      if (((iVar2 != 0) && (*(int *)(*(long *)(param_1 + 0x178) + 0x24) == 0)) &&
         (lVar3 != *(long *)(param_1 + 0x388))) {
        uVar1 = *(undefined4 *)(param_1 + 0x80);
        uStack_3b = SUB83(uVar4,5);
        _local_40 = (uint5)CONCAT13((char)uVar1,
                                    CONCAT12((char)((uint)uVar1 >> 8),
                                             CONCAT11((char)((uint)uVar1 >> 0x10),
                                                      (char)((uint)uVar1 >> 0x18))));
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0,"sid %08x prepare(): %s. format: %s\n");
        *(long *)(param_1 + 0x388) = lVar3;
        *(long *)(param_1 + 0x390) = *(long *)(param_1 + 0x390) + 1;
      }
      if ((uVar5 & (*(byte *)(param_1 + 0x3d0) & 0x20) >> 5) == 1) {
        FUN_fffffff009c206fc(param_1);
        *(uint *)(param_1 + 0x3d0) = *(uint *)(param_1 + 0x3d0) & 0xffffffdf;
      }
      if (uVar5 == 0) {
        thunk_EXT_FUN_801100000389060c(param_1 + 0x22c);
      }
      else {
        _local_40 = 0;
        thunk_EXT_FUN_80110000032db760(*(undefined8 *)(param_1 + 0x30),local_40);
        thunk_EXT_FUN_80110000036da494(0x8521001c,_local_40,*(undefined4 *)(param_1 + 0x10),0,0,0);
      }
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x398));
    uVar4 = 0;
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 != local_38) {
    thunk_EXT_FUN_8011000003a48590(uVar4);
    return;
  }
  return;
}

