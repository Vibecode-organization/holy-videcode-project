// FUN_fffffff009c2d694 @ fffffff009c2d694 size=184

undefined8
FUN_fffffff009c2d694
          (long param_1,long *param_2,undefined8 param_3,undefined4 param_4,undefined4 param_5,
          undefined8 param_6,undefined8 param_7,undefined8 param_8)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  
  *(long **)(param_1 + 0x10) = param_2;
  (**(code **)(*param_2 + 0x20))(param_2);
  *(undefined8 *)(param_1 + 0x18) = param_3;
  lVar2 = thunk_EXT_FUN_8011000003890f30(param_3,*(undefined8 *)PTR_DAT_fffffff00806c9d0);
  if (lVar2 != 0) {
    uVar3 = thunk_EXT_FUN_801100000390ebc0();
    *(undefined8 *)(param_1 + 0x60) = uVar3;
  }
  *(undefined8 *)(param_1 + 0x40) = param_8;
  *(undefined8 *)(param_1 + 0x20) = 0;
  *(undefined1 *)(param_1 + 0x58) = 0;
  *(undefined4 *)(param_1 + 0x48) = param_4;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  *(undefined4 *)(param_1 + 0x54) = param_5;
  *(undefined2 *)(param_1 + 0x59) = 0;
  iVar1 = FUN_fffffff009c2a6e0(*(undefined8 *)(param_1 + 0x10));
  *(int *)(param_1 + 0x50) = iVar1 + -1;
  return 1;
}

