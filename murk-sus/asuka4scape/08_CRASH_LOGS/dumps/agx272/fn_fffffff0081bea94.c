// FUN_fffffff0081bea94 @ fffffff0081bea94 size=232

/* WARNING: Removing unreachable block (ram,0xfffffff0081beb18) */

undefined8 FUN_fffffff0081bea94(long *param_1,undefined4 param_2,ulong param_3)

{
  undefined4 *puVar1;
  ulong uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  ulong uVar6;
  
  uVar4 = (uint)param_3;
  if ((int)uVar4 < 2) {
    uVar2 = (param_3 & 0xffffffff) << 2;
    uVar6 = -(ulong)(uVar4 >> 0x1f) & 0xfffffffc00000000 | uVar2;
    iVar5 = (int)uVar2;
    puVar1 = (undefined4 *)((long)param_1 + (long)iVar5 + 0x1b39);
    if (uVar6 != (long)iVar5) {
      puVar1 = (undefined4 *)((long)param_1 + uVar6 + 0x1b39 & 0xffffffffffff | 0x2bad000000000000);
    }
    *puVar1 = param_2;
    *(undefined1 *)((long)param_1 + (long)(int)uVar4 + 0x1b52) = 1;
    *(undefined1 *)(param_1[0x69] + (long)(int)uVar4 + 0xd6) = 1;
    uVar3 = (**(code **)(*param_1 + 0x840))(*param_1 + 0x840,param_1,param_3);
    puVar1 = (undefined4 *)(param_1[0x69] + 0xbd + (long)iVar5);
    if (uVar6 != (long)iVar5) {
      puVar1 = (undefined4 *)(param_1[0x69] + 0xbd + uVar6 & 0xffffffffffff | 0x2bad000000000000);
    }
    *puVar1 = uVar3;
    return 0;
  }
  return 0xe00002c2;
}

