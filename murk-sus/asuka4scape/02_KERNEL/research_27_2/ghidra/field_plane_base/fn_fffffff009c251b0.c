// FUN_fffffff009c251b0 @ fffffff009c251b0

/* WARNING: Removing unreachable block (ram,0xfffffff009c2532c) */

void FUN_fffffff009c251b0(long param_1,long param_2,int *param_3)

{
  int iVar1;
  undefined *local_d0;
  undefined8 local_c8;
  code *local_c0;
  undefined *local_b8;
  undefined8 *puStack_b0;
  undefined8 *local_a8;
  long lStack_a0;
  undefined8 local_98;
  undefined8 *local_90;
  undefined8 local_88;
  undefined1 *local_80;
  code *local_78;
  long *local_70;
  undefined8 local_68;
  undefined8 *local_60;
  undefined8 local_58;
  undefined1 local_50;
  long local_48;
  
  local_48 = *(long *)PTR_DAT_fffffff00806ca40;
  if (((param_2 != 0) && (param_3 != (int *)0x0)) && (*(long *)(param_1 + 0x1a8) != 0)) {
    local_68 = 0;
    local_58 = DAT_fffffff0078a1288;
    local_50 = 0;
    local_98 = 0;
    local_88 = DAT_fffffff0078a1298;
    local_80 = &LAB_fffffff009c253b4;
    local_78 = FUN_fffffff009c253c8;
    local_70 = (long *)&DAT_aaaaaaaaaaaaaaaa;
    local_90 = &local_98;
    local_60 = &local_68;
    local_70 = thunk_FUN_fffffff00a8a10d8(4);
    local_d0 = PTR_DAT_fffffff00806c9b8;
    local_c8 = DAT_fffffff0078a1290;
    local_c0 = FUN_fffffff009c25414;
    local_b8 = &DAT_fffffff0080672c8;
    puStack_b0 = &local_68;
    local_a8 = &local_98;
    lStack_a0 = param_2;
    thunk_FUN_fffffff00a8a1600(*(long *)(param_1 + 0x1a8),(long)&local_d0);
    if ((*(byte *)(local_60 + 3) & 1) != 0) {
      if (*(long **)(param_1 + 0x1a8) != (long *)0x0) {
        (**(code **)(**(long **)(param_1 + 0x1a8) + 0x28))();
      }
      *(undefined8 *)(param_1 + 0x1a8) = 0;
      FUN_fffffff009c16670((long *)(param_1 + 0x1a8),(long *)local_90[5]);
      iVar1 = (*(uint *)(*(long *)(param_1 + 0x178) + 0x20) | 1) + 2;
      *(int *)(*(long *)(param_1 + 0x178) + 0x20) = iVar1;
      *param_3 = iVar1;
    }
    thunk_FUN_fffffff00a8eddac((long)&local_98,8);
    if (local_70 != (long *)0x0) {
      (**(code **)(*local_70 + 0x28))();
    }
    thunk_FUN_fffffff00a8eddac((long)&local_68,8);
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 != local_48) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_fffffff00aa4c590();
  }
  return;
}

