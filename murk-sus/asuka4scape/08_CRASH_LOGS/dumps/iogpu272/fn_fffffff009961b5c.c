// FUN_fffffff009961b5c @ fffffff009961b5c size=124

void FUN_fffffff009961b5c(long param_1)

{
  ulong uVar1;
  ulong uVar2;
  long lVar3;
  ulong uVar4;
  
  lVar3 = thunk_EXT_FUN_8011000002c339b0(*(undefined8 *)(*(long *)(param_1 + 0x1a8) + 0xf8));
  uVar4 = *(ulong *)(*(long *)(param_1 + 0x1a8) + 0x2c8);
  uVar2 = lVar3 * 3;
  if (uVar4 / 6 <= (ulong)(lVar3 * 3)) {
    uVar2 = uVar4 / 6;
  }
  uVar1 = lVar3 * 6;
  if (uVar4 >> 4 <= (ulong)(lVar3 * 6)) {
    uVar1 = uVar4 >> 4;
  }
  if (uVar2 <= uVar1) {
    uVar2 = uVar1;
  }
  if (uVar2 < 0x2000001) {
    uVar2 = 0x2000000;
  }
  *(ulong *)(param_1 + 0xa8) = uVar2;
  return;
}

