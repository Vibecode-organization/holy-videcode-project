// FUN_fffffff009c12498 @ fffffff009c12498

undefined8 FUN_fffffff009c12498(long *param_1)

{
  ulong uVar1;
  undefined8 uVar2;
  
  uVar1 = (**(code **)(*param_1 + 0x2d0))(param_1,0);
  if ((uVar1 & 1) == 0) {
    (**(code **)(*(long *)param_1[0x11] + 0xb8))();
    uVar2 = 0;
  }
  else {
    uVar2 = 0xe00002d2;
  }
  return uVar2;
}

