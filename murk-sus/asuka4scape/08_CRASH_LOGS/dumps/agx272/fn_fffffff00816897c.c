// FUN_fffffff00816897c @ fffffff00816897c size=208

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fffffff00816897c(long *param_1)

{
  undefined8 uVar1;
  long lVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = (**(code **)(*param_1 + 0xb80))();
  *(uint *)((long)param_1 + 0x10ddc) = uVar3;
  uVar1 = _DAT_fffffff007113640;
  *(undefined8 *)((long)param_1 + 0x10dec) = _UNK_fffffff007113648;
  *(undefined8 *)((long)param_1 + 0x10de4) = uVar1;
  *(undefined8 *)((long)param_1 + 0x10df4) = DAT_fffffff007113db0;
  uVar1 = _DAT_fffffff007113650;
  uVar4 = 0x7113000;
  *(undefined8 *)((long)param_1 + 0x10e14) = _UNK_fffffff007113658;
  *(undefined8 *)((long)param_1 + 0x10e0c) = uVar1;
  lVar2 = _DAT_fffffff007113660;
  if (uVar3 != 0) {
    uVar4 = 0;
    if (uVar3 != 0) {
      uVar4 = ((uVar3 >> 1) + 0x21) / uVar3;
    }
  }
  param_1[0x21c7] = _UNK_fffffff007113668;
  param_1[0x21c6] = lVar2;
  *(undefined4 *)(param_1 + 0x21c8) = 0x32;
  *(uint *)((long)param_1 + 0x10e44) = uVar4;
  *(undefined4 *)(param_1 + 0x21bc) = 0x578;
  *(int *)((long)param_1 + 0x10e2c) = (int)param_1[0x3288] * 100 + -100;
  uVar1 = _DAT_fffffff007113670;
  *(undefined8 *)((long)param_1 + 0x10e24) = _UNK_fffffff007113678;
  *(undefined8 *)((long)param_1 + 0x10e1c) = uVar1;
  *(undefined4 *)((long)param_1 + 0x10eac) = 0;
  return;
}

