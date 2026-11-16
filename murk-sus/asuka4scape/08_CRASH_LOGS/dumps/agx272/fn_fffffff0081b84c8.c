// FUN_fffffff0081b84c8 @ fffffff0081b84c8 size=208

/* WARNING: Removing unreachable block (ram,0xfffffff0081b855c) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fffffff0081b84c8(long param_1,undefined8 param_2)

{
  undefined4 uVar1;
  long *plVar2;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined8 uStack_28;
  
  plVar2 = *(long **)(param_1 + 0x280);
  if ((*(byte *)((long)plVar2 + 0x10a72) & 1) != 0) {
    (**(code **)(*plVar2 + 0xd8))(plVar2,"SharedEventAgentSignalEnabled",param_2);
    uVar1 = 1;
    if ((int)param_2 == 0) {
      uVar1 = 2;
    }
    uStack_28 = _UNK_fffffff007113738;
    _local_30 = CONCAT44((int)((ulong)_DAT_fffffff007113730 >> 0x20),uVar1);
    (**(code **)(*plVar2 + 0x430))(*plVar2 + 0x430,plVar2,0xe0078101,&local_30,0x10);
  }
  return;
}

