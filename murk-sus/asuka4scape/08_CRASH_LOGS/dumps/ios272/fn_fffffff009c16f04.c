// FUN_fffffff009c16f04 @ fffffff009c16f04 size=156

undefined8 FUN_fffffff009c16f04(long param_1,ulong param_2)

{
  byte *pbVar1;
  long lVar2;
  long lVar3;
  undefined8 uVar4;
  long *plVar5;
  
  uVar4 = 0xe00002f0;
  plVar5 = *(long **)(param_1 + 0x58);
  if (plVar5 != (long *)0x0) {
    thunk_EXT_FUN_80110000032222a8(plVar5[0xd]);
    lVar2 = 0;
    lVar3 = 0;
    do {
      pbVar1 = (byte *)(plVar5 + lVar3 * 3 + 1);
      if (((*pbVar1 & 1) != 0) && (*(ulong *)(pbVar1 + 8) <= param_2)) {
        uVar4 = 0;
        *pbVar1 = 0;
        pbVar1[8] = 0;
        pbVar1[9] = 0;
        pbVar1[10] = 0;
        pbVar1[0xb] = 0;
        pbVar1[0xc] = 0;
        pbVar1[0xd] = 0;
        pbVar1[0xe] = 0;
        pbVar1[0xf] = 0;
        pbVar1[0x10] = 0;
        pbVar1[0x11] = 0;
        pbVar1[0x12] = 0;
        pbVar1[0x13] = 0;
        pbVar1[0x14] = 0;
        pbVar1[0x15] = 0;
        pbVar1[0x16] = 0;
        pbVar1[0x17] = 0;
        *(undefined8 *)(*plVar5 + lVar3 * 8) = 0;
      }
      lVar3 = lVar3 + 1;
      lVar2 = lVar2 + 8;
    } while (lVar2 != 0x20);
    thunk_EXT_FUN_8011000003222de0(plVar5[0xd]);
  }
  return uVar4;
}

