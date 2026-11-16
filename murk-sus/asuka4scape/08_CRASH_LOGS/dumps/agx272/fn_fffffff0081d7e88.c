// FUN_fffffff0081d7e88 @ fffffff0081d7e88 size=200

undefined8 FUN_fffffff0081d7e88(long *param_1,int param_2,undefined8 *param_3)

{
  uint uVar1;
  uint uVar2;
  ulong uVar3;
  undefined8 uVar4;
  ulong uVar5;
  undefined8 uVar6;
  
  if (param_2 != 0) {
    return 0;
  }
  uVar3 = (**(code **)(*param_1 + 0xdc8))();
  uVar2 = (uint)uVar3;
  if ((uVar3 & 1) == 0) {
    uVar4 = 0;
  }
  else {
    uVar1 = uVar2 >> 9 & 0xff;
    *(uint *)(param_3 + 2) = uVar2 >> 0x11 & 0x3f;
    *(uint *)((long)param_3 + 0x14) = uVar1;
    *(uint *)(param_3 + 3) = uVar2 >> 0x17 & 0x7f;
    uVar4 = *(undefined8 *)(&DAT_fffffff007c979d0 + (ulong)uVar1 * 0x10);
    *(byte *)(param_3 + 4) = (byte)(uVar2 >> 7) & 3;
    *(byte *)((long)param_3 + 0x21) = (byte)(uVar2 >> 4) & 1;
    uVar5 = uVar3 >> 1 & 7;
    if (4 < uVar5) {
      uVar5 = 5;
    }
    uVar6 = *(undefined8 *)(&DAT_fffffff007c989d0 + uVar5 * 8);
    *param_3 = uVar4;
    param_3[1] = uVar6;
    param_3[5] = uVar3 >> 0x18 & 0xffffffffc0;
    uVar4 = 1;
  }
  return uVar4;
}

