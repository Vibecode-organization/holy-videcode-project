// FUN_fffffff0081ec708 @ fffffff0081ec708 size=244

undefined8 FUN_fffffff0081ec708(long param_1,long *param_2)

{
  undefined8 uVar1;
  int iVar2;
  long lVar3;
  int iVar4;
  
  uVar1 = (**(code **)(PTR_DAT_fffffff007ca6180 + 0x78))();
  if ((int)uVar1 != 0) {
    *(long *)(param_1 + 0xc) = param_2[0x212f];
    lVar3 = param_2[0x22bf];
    if (lVar3 == 0) {
      lVar3 = param_2[0x22bc];
    }
    iVar4 = (int)(lVar3 + 0x1ffffU >> 0x11);
    *(int *)(param_1 + 0x14) = iVar4;
    lVar3 = param_2[0x22c0];
    if (lVar3 == 0) {
      lVar3 = (**(code **)(*param_2 + 0xc10))(param_2,0xc000000);
      iVar4 = *(int *)(param_1 + 0x14);
    }
    iVar2 = (int)(lVar3 + 0x1ffffU >> 0x11);
    *(int *)(param_1 + 0x18) = iVar2;
    *(uint *)(param_1 + 0x1c) = iVar4 + ((uint)(iVar2 - iVar4) >> 1);
    *(byte *)(param_1 + 0x24) = *(byte *)(param_2 + 0x2140) & 1;
    *(uint *)(param_1 + 0x20) = (uint)((int)param_2[0x213f] != 0);
    *(undefined1 *)(param_1 + 0x25) = 0;
  }
  return uVar1;
}

