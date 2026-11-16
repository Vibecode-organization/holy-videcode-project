// FUN_fffffff0081d5fc0 @ fffffff0081d5fc0 size=124

ulong FUN_fffffff0081d5fc0(long param_1,long param_2)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  
  uVar3 = ((param_2 + 0x101ffffU) / 0x1020000) * 0x1020000;
  uVar1 = ((ulong)(*(long *)(param_1 + 0x2c8) * 5) / 100 + 0x101ffff) / 0x1020000;
  uVar2 = uVar1 * 0x1020000;
  if (uVar3 < uVar2 || uVar3 + uVar1 * -0x1020000 == 0) {
    uVar3 = uVar2;
  }
  return uVar3;
}

