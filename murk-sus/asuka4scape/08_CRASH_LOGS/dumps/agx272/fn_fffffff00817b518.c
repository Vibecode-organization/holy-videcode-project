// FUN_fffffff00817b518 @ fffffff00817b518 size=820

/* WARNING: Removing unreachable block (ram,0xfffffff00817b7f0) */
/* WARNING: Removing unreachable block (ram,0xfffffff00817b764) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
FUN_fffffff00817b518
          (undefined8 param_1,undefined8 param_2,int param_3,undefined8 param_4,long param_5)

{
  long *plVar1;
  undefined8 *puVar2;
  long local_50;
  undefined8 uStack_48;
  
  plVar1 = (long *)thunk_EXT_FUN_8011000003890f30(param_1,&DAT_fffffff00ae22348);
  if (plVar1 == (long *)0x0) {
    return 0xe00002c2;
  }
  if (param_3 < -0x1ffffdab) {
    if ((param_3 != -0x1ffffdf0) && (param_3 != -0x1ffffdb0)) {
      return 0;
    }
  }
  else if (param_3 == -0x1ffffdab) {
    thunk_EXT_FUN_8011000003397c88();
    thunk_EXT_FUN_8011000003397c88();
    thunk_EXT_FUN_8011000002971c58(plVar1);
  }
  else if (param_3 != -0x1ffffcf0) {
    if (param_3 != -0x1ffffcc0) {
      return 0;
    }
    if ((*(uint *)(param_5 + 8) & 1) != 0) {
      if ((*(byte *)(param_5 + 0x10) & 1) == 0) {
        return 0;
      }
      if ((*(byte *)(param_5 + 0x14) & 1) != 0) {
        return 0;
      }
      if ((*(byte *)((long)plVar1 + 0x65d) & 1) != 0) {
        local_50 = (ulong)local_50._1_7_ << 8;
        puVar2 = (undefined8 *)(*(long *)plVar1[0x62] + 0xe8);
        (*(code *)*puVar2)(puVar2,(long *)plVar1[0x62],FUN_fffffff00817b84c,&local_50,0,0,0);
      }
      if (*(char *)((long)plVar1 + 0x115c1) != '\x02') {
        thunk_EXT_FUN_80110000032222a8(plVar1[0x234c]);
        (**(code **)(*plVar1 + 0x710))(plVar1,"",0);
        FUN_fffffff0081796f0(plVar1,0);
        (**(code **)(*plVar1 + 0x718))(*plVar1 + 0x718,plVar1,"",0);
        thunk_EXT_FUN_8011000003222de0(plVar1[0x234c]);
      }
      if ((*(byte *)((long)plVar1 + 0x10a72) & 1) != 0) {
        (**(code **)(*plVar1 + 0xd8))(plVar1,"SharedEventAgentSignalEnabled",0);
        uStack_48 = _UNK_fffffff007113708;
        local_50 = _DAT_fffffff007113700;
        (**(code **)(*plVar1 + 0x430))(*plVar1 + 0x430,plVar1,0xe0078101,&local_50,0x10);
      }
      (**(code **)(*(long *)plVar1[0x96] + 0x648))((long *)plVar1[0x96],1);
      return 0;
    }
    if ((*(uint *)(param_5 + 8) >> 1 & 1) == 0) {
      return 0;
    }
    if ((*(byte *)(param_5 + 0x10) & 1) != 0) {
      return 0;
    }
    if ((*(byte *)(param_5 + 0x14) & 1) == 0) {
      return 0;
    }
    if ((*(byte *)((long)plVar1 + 0x65d) & 1) == 0) {
      return 0;
    }
    local_50 = CONCAT71(local_50._1_7_,1);
    puVar2 = (undefined8 *)(*(long *)plVar1[0x62] + 0xe8);
    (*(code *)*puVar2)(puVar2,(long *)plVar1[0x62],FUN_fffffff00817b84c,&local_50,0,0,0);
    return 0;
  }
  thunk_EXT_FUN_8011000003397c88();
  return 0;
}

