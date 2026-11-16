// FUN_fffffff00997142c @ fffffff00997142c size=200

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fffffff00997142c(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  int iVar7;
  
  *(undefined4 *)(param_1 + 0x200) = 1;
  *(undefined8 *)(param_1 + 0x208) = 0;
  *(undefined8 *)(param_1 + 0x210) = 0x100000001;
  *(undefined4 *)(param_1 + 0x218) = 0x10001000;
  uVar4 = _UNK_fffffff007835cf8;
  uVar3 = _DAT_fffffff007835cf0;
  uVar2 = _UNK_fffffff007835ce8;
  uVar1 = _DAT_fffffff007835ce0;
  *(undefined4 *)(param_1 + 0x250) = 50000;
  uVar5 = _DAT_fffffff007835d00;
  *(undefined8 *)(param_1 + 0x2b4) = _UNK_fffffff007835d08;
  *(undefined8 *)(param_1 + 0x2ac) = uVar5;
  uVar6 = _UNK_fffffff007835d18;
  uVar5 = _DAT_fffffff007835d10;
  *(undefined8 *)(param_1 + 0x228) = uVar2;
  *(undefined8 *)(param_1 + 0x220) = uVar1;
  *(undefined8 *)(param_1 + 0x238) = uVar6;
  *(undefined8 *)(param_1 + 0x230) = uVar5;
  *(undefined8 *)(param_1 + 0x248) = uVar4;
  *(undefined8 *)(param_1 + 0x240) = uVar3;
  *(undefined4 *)(param_1 + 0x268) = 0x30;
  iVar7 = thunk_EXT_FUN_8011000003a12d84(0);
  if (iVar7 != 0) {
    *(undefined4 *)(param_1 + 0x26c) = 0x3c;
  }
  *(int *)(param_1 + 0x274) = 1 << (ulong)(*(uint *)PTR_DAT_fffffff007ff2740 & 0x1f);
  *(undefined4 *)(param_1 + 0x278) = 0x408;
  *(undefined4 *)(param_1 + 700) = 5;
  *(undefined8 *)(param_1 + 0x284) = 0;
  *(undefined8 *)(param_1 + 0x27c) = 0;
  *(undefined8 *)(param_1 + 0x294) = 0;
  *(undefined8 *)(param_1 + 0x28c) = 0;
  *(undefined8 *)(param_1 + 0x2a4) = 0;
  *(undefined8 *)(param_1 + 0x29c) = 0;
  return;
}

