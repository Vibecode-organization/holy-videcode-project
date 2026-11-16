// FUN_fffffff0099454d8 @ fffffff0099454d8 size=128

undefined8 FUN_fffffff0099454d8(long param_1,long param_2,undefined4 param_3)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  if ((param_2 == 0) || (iVar1 = (**(code **)(PTR_DAT_fffffff007ff27f8 + 0x78))(), iVar1 == 0)) {
    uVar3 = 0;
  }
  else {
    *(long *)(param_1 + 0x10) = param_2;
    *(undefined4 *)(param_1 + 0x18) = param_3;
    uVar3 = 1;
    uVar2 = thunk_EXT_FUN_80110000038905f0(1,&DAT_fffffff00af220c0);
    *(undefined8 *)(param_1 + 0x30) = uVar2;
  }
  return uVar3;
}

