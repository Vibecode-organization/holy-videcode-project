// FUN_fffffff0081df088 @ fffffff0081df088 size=484

void FUN_fffffff0081df088(long param_1,ulong *param_2,ulong *param_3)

{
  ulong uVar1;
  ulong uVar2;
  int iVar3;
  uint uVar4;
  ulong uVar5;
  uint uVar6;
  
  *param_2 = *param_2 & 0xffffffffc000 | *param_2 & 0x3f | ((ulong)DAT_fffffff00ae22cd0 & 0xff) << 6
             | 0xfeed000000000000;
  param_2[1] = DAT_fffffff00ae22cd8 + *(long *)(param_1 + 0x10);
  uVar1 = *(ulong *)(param_1 + 0x18);
  iVar3 = 0;
  if (*param_3 <= uVar1) {
    iVar3 = (int)*param_3;
  }
  *param_3 = uVar1;
  uVar5 = *(ulong *)(param_1 + 8);
  uVar2 = *param_2 & 0xffffffffffff3ff0;
  *(int *)(param_2 + 2) = (int)uVar1 - iVar3;
  *(undefined4 *)((long)param_2 + 0x14) = 0xffffffff;
  *param_2 = uVar2 | 0xffffffffc000;
  param_2[3] = 0;
  uVar4 = (uint)uVar5;
  if ((uVar5 & 0x7e00000000) == 0) {
    if ((uVar5 >> 0x20 & 1) == 0) {
      if (((byte)DAT_fffffff00ae22cd4 & 1) != 0) {
        *(undefined4 *)((long)param_2 + 0x14) = *(undefined4 *)(param_1 + 0x24);
      }
      return;
    }
    if ((uVar5 & 1) == 0) {
      *param_2 = uVar2 | 0xffffffffc004;
      return;
    }
    *param_2 = uVar2 | 0xffffffffc005;
    return;
  }
  if ((uVar5 & 0x5400000000) == 0) {
    if ((uVar5 >> 0x21 & 1) != 0) {
      uVar2 = uVar2 | 0xffffffff0002;
      *param_2 = uVar2;
      uVar6 = uVar4 >> 5 & 1;
      uVar4 = uVar4 >> 5 & 1 | 4;
      goto LAB_fffffff0081df24c;
    }
    if ((uVar5 >> 0x23 & 1) == 0) {
      uVar2 = uVar2 | 0xffffffff8002;
      *param_2 = uVar2;
      uVar4 = uVar4 >> 0x13;
      uVar5 = uVar5 & 0x40000;
      goto LAB_fffffff0081df244;
    }
    uVar2 = uVar2 | 0xffffffff4002;
    *param_2 = uVar2;
    uVar4 = uVar4 >> 10;
    uVar5 = uVar5 & 0x200;
  }
  else {
    if ((uVar5 & 0x600000000) != 0) {
      uVar2 = uVar2 | 0xffffffff0001;
      *param_2 = uVar2;
      uVar6 = uVar4 >> 4 & 1;
      uVar4 = uVar4 >> 4 & 1 | 4;
      goto LAB_fffffff0081df24c;
    }
    if ((uVar5 & 0x1800000000) == 0) {
      uVar2 = uVar2 | 0xffffffff8001;
      *param_2 = uVar2;
      uVar4 = uVar4 >> 0x12;
      uVar5 = uVar5 & 0x20000;
LAB_fffffff0081df244:
      uVar6 = uVar4 & 2;
      if (uVar5 != 0) {
        uVar6 = 1;
      }
      uVar4 = uVar6 + 9;
      goto LAB_fffffff0081df24c;
    }
    uVar2 = uVar2 | 0xffffffff4001;
    *param_2 = uVar2;
    uVar4 = uVar4 >> 9;
    uVar5 = uVar5 & 0x100;
  }
  uVar6 = uVar4 & 2;
  if (uVar5 != 0) {
    uVar6 = 1;
  }
  uVar4 = uVar6 + 6;
LAB_fffffff0081df24c:
  uVar1 = *(ulong *)(param_1 + (ulong)uVar4 * 8);
  *(int *)((long)param_2 + 0x14) = (int)(uVar1 >> 0x20);
  *param_2 = uVar2 & 0xffff000000000000 | uVar2 & 0xffff | (uVar1 & 0xffffffff) << 0x10;
  param_2[3] = (ulong)uVar6;
  return;
}

