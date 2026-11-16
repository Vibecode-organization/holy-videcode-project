// FUN_fffffff008179ef8 @ fffffff008179ef8 size=212

/* WARNING: Removing unreachable block (ram,0xfffffff008179f8c) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fffffff008179ef8(long *param_1,undefined8 param_2)

{
  undefined4 uVar1;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined8 uStack_28;
  
  if ((*(byte *)((long)param_1 + 0x10a72) & 1) != 0) {
    (**(code **)(*param_1 + 0xd8))(param_1,"SharedEventAgentSignalEnabled",param_2);
    uVar1 = 1;
    if ((int)param_2 == 0) {
      uVar1 = 2;
    }
    uStack_28 = _UNK_fffffff007113738;
    _local_30 = CONCAT44((int)((ulong)_DAT_fffffff007113730 >> 0x20),uVar1);
    (**(code **)(*param_1 + 0x430))(*param_1 + 0x430,param_1,0xe0078101,&local_30,0x10);
  }
  return;
}

