// FUN_fffffff0081ff6fc @ fffffff0081ff6fc size=124

undefined8 FUN_fffffff0081ff6fc(long param_1,ulong *param_2)

{
  ushort uVar1;
  ulong uVar2;
  
  uVar2 = param_2[2];
  if (((uVar2 < *param_2) || (0xffffffffffffffbf < uVar2)) || (param_2[1] < uVar2 + 0x40)) {
    *(undefined8 *)(param_1 + 0x10) = 0;
  }
  else {
    param_2[2] = uVar2 + 0x40;
    *(ulong *)(param_1 + 0x10) = uVar2;
    if (uVar2 != 0) {
      uVar1 = *(ushort *)(uVar2 + 0x3e);
      *(ushort *)(param_1 + 0x18) = uVar1;
      if (uVar1 < 7) {
        *(undefined1 *)(param_1 + 8) = 1;
        return 1;
      }
      *(undefined8 *)(param_1 + 0x10) = 0;
      *(undefined2 *)(param_1 + 0x18) = 0;
    }
  }
  *(undefined4 *)(param_1 + 0xc) = 10;
  return 0;
}

