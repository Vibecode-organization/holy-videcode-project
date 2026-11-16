// FUN_fffffff00819fbc4 @ fffffff00819fbc4 size=108

undefined8 FUN_fffffff00819fbc4(long param_1,undefined8 *param_2)

{
  ushort uVar1;
  ushort *puVar2;
  undefined4 uVar3;
  
  puVar2 = (ushort *)param_2[2];
  if (((puVar2 < (ushort *)*param_2) || ((ushort *)0xfffffffffffffffd < puVar2)) ||
     ((ushort *)param_2[1] < puVar2 + 1)) {
    uVar3 = 0x100;
  }
  else {
    uVar1 = *puVar2;
    *(ushort *)(param_1 + 0x10) = uVar1;
    param_2[2] = puVar2 + 1;
    if (uVar1 < 0x100) {
      *(undefined1 *)(param_1 + 8) = 1;
      return 1;
    }
    uVar3 = 0x103;
  }
  *(undefined4 *)(param_1 + 0xc) = uVar3;
  return 0;
}

