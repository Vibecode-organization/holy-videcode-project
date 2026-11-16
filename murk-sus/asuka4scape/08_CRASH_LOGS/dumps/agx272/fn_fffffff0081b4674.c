// FUN_fffffff0081b4674 @ fffffff0081b4674 size=196

void FUN_fffffff0081b4674
               (long param_1,long param_2,ulong param_3,undefined8 param_4,undefined8 param_5,
               undefined4 param_6,long param_7,undefined4 param_8)

{
  undefined4 uVar1;
  undefined *puVar2;
  undefined8 uVar3;
  long lVar4;
  ulong uVar5;
  
  uVar3 = *(undefined8 *)(param_2 + 0x148);
  *(long *)(param_1 + 8) = param_2;
  *(undefined8 *)(param_1 + 0x10) = uVar3;
  *(undefined8 *)(param_1 + 0xa8) = param_5;
  *(undefined4 *)(param_1 + 0xb0) = param_6;
  if (param_7 == 0) {
    param_7 = thunk_EXT_FUN_8011000002971b4c(param_2);
  }
  uVar3 = *(undefined8 *)PTR_DAT_fffffff007ca61d0;
  *(long *)(param_1 + 0x18) = param_7;
  *(undefined8 *)(param_1 + 0x20) = uVar3;
  *(undefined1 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = param_8;
  puVar2 = PTR_DAT_fffffff007ca5f88;
  *(ulong *)(param_1 + 0x40) = param_3;
  lVar4 = (long)(1 << (ulong)(*(uint *)puVar2 & 0x1f));
  uVar5 = (lVar4 + param_3 * 2) - 1 & -lVar4;
  *(ulong *)(param_1 + 0x50) = uVar5;
  uVar1 = 0;
  if (param_3 != 0) {
    uVar1 = (undefined4)(uVar5 / param_3);
  }
  *(undefined4 *)(param_1 + 0x48) = uVar1;
  thunk_EXT_FUN_80110000037693ec(param_1 + 0x58,0x1e,"%s");
  return;
}

