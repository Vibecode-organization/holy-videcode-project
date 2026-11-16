// FUN_fffffff009c182a4 @ fffffff009c182a4 size=156

bool FUN_fffffff009c182a4(long param_1,uint param_2,long param_3)

{
  long lVar1;
  byte *pbVar2;
  bool bVar3;
  long lVar4;
  
  bVar3 = false;
  if ((param_2 < 4) && (*(long *)(param_1 + 0x58) != 0)) {
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(*(long *)(param_1 + 0x58) + 0x68));
    lVar1 = *(long *)(param_1 + 0x58) + 8;
    lVar4 = (ulong)param_2 * 0x18;
    pbVar2 = (byte *)(lVar1 + (int)lVar4);
    if (lVar4 - (int)lVar4 != 0) {
      pbVar2 = (byte *)(lVar1 + lVar4 & 0xffffffffffffU | 0x2bad000000000000);
    }
    if ((*pbVar2 & 1) == 0) {
      bVar3 = false;
    }
    else {
      bVar3 = *(long *)(pbVar2 + 8) == param_3;
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(*(long *)(param_1 + 0x58) + 0x68));
  }
  return bVar3;
}

