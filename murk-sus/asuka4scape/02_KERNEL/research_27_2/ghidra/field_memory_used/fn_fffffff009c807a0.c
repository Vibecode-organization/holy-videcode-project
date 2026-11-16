// FUN_fffffff009c807a0 @ fffffff009c807a0

/* WARNING: Removing unreachable block (ram,0xfffffff009c8087c) */

void FUN_fffffff009c807a0
               (long *param_1,int param_2,undefined8 param_3,undefined8 param_4,ulong param_5,
               undefined8 param_6,ulong param_7)

{
  uint *puVar1;
  undefined8 uVar2;
  undefined8 local_58;
  long local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  uint local_38;
  int iStack_34;
  undefined1 *local_30;
  long local_28;
  
  local_28 = *(long *)PTR_DAT_fffffff00807faf0;
  FUN_fffffff009ca7480();
  *(int *)(param_1 + 0x17) = param_2;
  local_30 = &DAT_aaaaaaaaaaaaaaaa;
  FUN_fffffff009c80904(param_1,0);
  local_38 = (uint)(param_2 != 1);
  iStack_34 = param_2;
  (**(code **)(*param_1 + 200))(param_1,"IsActive",**(undefined8 **)PTR_PTR_fffffff00807fb18);
  (**(code **)(*param_1 + 0xe0))(param_1,"ActiveSpeed",(long)param_2,0x20);
  puVar1 = &local_38;
  uVar2 = 0x10;
  (**(code **)(*param_1 + 0x430))(*param_1 + 0x430,param_1,0xe3ff8110);
  if (param_1[0x24] != 0) {
    local_58 = DAT_fffffff0078b2b20;
    uStack_40 = 0;
    local_48 = 0;
    local_50 = param_1[0x24];
    thunk_FUN_fffffff00a218790((int *)&local_58,0x20,puVar1,uVar2,param_5,param_6,param_7);
  }
  if (*(long *)PTR_DAT_fffffff00807faf0 != local_28) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_fffffff00aa4c590();
  }
  return;
}

