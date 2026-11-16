// FUN_fffffff0081737dc @ fffffff0081737dc size=220

undefined8 FUN_fffffff0081737dc(undefined8 param_1,long *param_2,undefined8 param_3,long param_4)

{
  undefined4 uVar1;
  undefined8 uVar2;
  byte bVar3;
  long lVar4;
  uint local_34;
  
  local_34 = *(byte *)((long)param_2 + 0x5d1) >> 1 & 1;
  uVar2 = thunk_EXT_FUN_80110000037408e4(param_1,&local_34,0);
  if (((int)uVar2 == 0) && (*(long *)(param_4 + 0x30) != 0)) {
    if ((local_34 != 0) == ((*(byte *)((long)param_2 + 0x5d1) & 2) == 0)) {
      bVar3 = 2;
      if (local_34 == 0) {
        bVar3 = 0;
      }
      *(byte *)((long)param_2 + 0x5d1) = *(byte *)((long)param_2 + 0x5d1) & 0xfd | bVar3;
      lVar4 = param_2[0x96];
      uVar1 = 0;
      if (local_34 != 0) {
        uVar1 = (**(code **)(*param_2 + 0xd50))(param_2);
      }
      *(undefined4 *)(*(long *)(lVar4 + 0x348) + 0xe08) = uVar1;
    }
  }
  return uVar2;
}

