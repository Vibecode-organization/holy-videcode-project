// FUN_fffffff0081c0390 @ fffffff0081c0390 size=236

byte FUN_fffffff0081c0390(long *param_1,uint param_2)

{
  uint uVar1;
  byte bVar2;
  ulong uVar3;
  uint uVar4;
  long lVar5;
  
  uVar1 = *(uint *)(param_1[0x123] + 0x5c9);
  uVar3 = (**(code **)(*param_1 + 0x6d0))();
  uVar4 = (uint)((uVar3 & 0xffffffff) / 100);
  bVar2 = *(byte *)(param_1 + 0x321) & uVar1 == uVar4;
  if ((param_2 & 1) != 0) {
    *(uint *)(param_1[0x123] + 0x5c9) = uVar4;
  }
  lVar5 = param_1[0x50];
  if ((*(byte *)(lVar5 + 0x1ac44) >> 3 & 1) != 0) {
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar5 + 0x1ac48));
    thunk_EXT_FUN_80110000036da494
              (0x85930ca4,2,param_2,bVar2,uVar1 | (int)((uVar3 & 0xffffffff) / 100) << 0x10,0);
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar5 + 0x1ac48));
  }
  return bVar2;
}

