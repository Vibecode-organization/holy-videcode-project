// FUN_fffffff008182190 @ fffffff008182190 size=260

undefined8 FUN_fffffff008182190(long *param_1,undefined8 param_2,ulong param_3,long *param_4)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
  ulong local_60;
  ulong uStack_58;
  ulong local_50;
  
  lVar1 = (**(code **)(*param_4 + 0x98))(param_4);
  uVar2 = (**(code **)(*param_4 + 0x80))(param_4);
  uStack_58 = uVar2 + lVar1;
  if (((uVar2 ^ uStack_58) & 0xffc0000000000000) != 0) {
    uStack_58 = uStack_58 & 0xffffffffffff | 0xc8a2000000000000;
  }
  local_50 = param_3;
  if (uStack_58 < param_3) {
    uStack_58 = 0;
    local_50 = 0;
  }
  local_60 = local_50;
  uVar3 = (**(code **)(*param_1 + 0x88))(param_1,param_2,&local_60);
  (**(code **)(*param_4 + 0x88))(param_4);
  return uVar3;
}

