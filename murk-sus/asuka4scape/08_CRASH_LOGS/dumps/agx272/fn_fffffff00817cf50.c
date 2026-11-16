// FUN_fffffff00817cf50 @ fffffff00817cf50 size=4

/* WARNING: Removing unreachable block (ram,0xfffffff00817d04c) */

void FUN_fffffff00817cf50(long *param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  undefined1 uStack_31;
  
  if ((*(byte *)((long)param_1 + 0x65d) & 1) != 0) {
    uStack_31 = 0;
    puVar1 = (undefined8 *)(*(long *)param_1[0x62] + 0xe8);
    (*(code *)*puVar1)(puVar1,(long *)param_1[0x62],FUN_fffffff00817b84c,&uStack_31,0,0,0);
  }
  thunk_EXT_FUN_8011000003397c88();
  if (*(char *)((long)param_1 + 0x115c1) != '\x02') {
    thunk_EXT_FUN_80110000032222a8(param_1[0x234c]);
    (**(code **)(*param_1 + 0x710))(param_1,"",0);
    FUN_fffffff0081796f0(param_1,0);
    (**(code **)(*param_1 + 0x718))(*param_1 + 0x718,param_1,"",0);
    thunk_EXT_FUN_8011000003222de0(param_1[0x234c]);
  }
  puVar1 = (undefined8 *)(*(long *)param_1[0x62] + 0xe8);
  (*(code *)*puVar1)(puVar1,(long *)param_1[0x62],FUN_fffffff00817d0fc,0,0,0,0);
  (**(code **)(PTR_DAT_fffffff007ca6170 + 0x288))(param_1,param_2);
  return;
}

