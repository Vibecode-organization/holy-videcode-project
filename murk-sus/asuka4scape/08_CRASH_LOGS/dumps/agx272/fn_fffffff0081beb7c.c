// FUN_fffffff0081beb7c @ fffffff0081beb7c size=224

/* WARNING: Removing unreachable block (ram,0xfffffff0081bec00) */

undefined8 FUN_fffffff0081beb7c(undefined4 param_1,long *param_2,uint param_3)

{
  undefined4 *puVar1;
  int iVar2;
  ulong uVar3;
  undefined4 uVar4;
  
  if ((int)param_3 < 2) {
    uVar3 = -(ulong)(param_3 >> 0x1f) & 0xfffffffc00000000 | (ulong)param_3 << 2;
    iVar2 = (int)((ulong)param_3 << 2);
    puVar1 = (undefined4 *)((long)param_2 + (long)iVar2 + 0x1b49);
    if (uVar3 != (long)iVar2) {
      puVar1 = (undefined4 *)((long)param_2 + uVar3 + 0x1b49 & 0xffffffffffff | 0x2bad000000000000);
    }
    *puVar1 = param_1;
    *(undefined1 *)((long)param_2 + (long)(int)param_3 + 0x1b56) = 1;
    *(undefined1 *)(param_2[0x69] + (long)(int)param_3 + 0xda) = 1;
    uVar4 = (**(code **)(*param_2 + 0x838))(*param_2 + 0x838);
    puVar1 = (undefined4 *)(param_2[0x69] + 0xcd + (long)iVar2);
    if (uVar3 != (long)iVar2) {
      puVar1 = (undefined4 *)(param_2[0x69] + 0xcd + uVar3 & 0xffffffffffff | 0x2bad000000000000);
    }
    *puVar1 = uVar4;
    return 0;
  }
  return 0xe00002c2;
}

