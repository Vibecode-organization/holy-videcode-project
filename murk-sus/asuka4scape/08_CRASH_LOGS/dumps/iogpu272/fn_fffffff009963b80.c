// FUN_fffffff009963b80 @ fffffff009963b80 size=224

void FUN_fffffff009963b80
               (long param_1,undefined8 param_2,undefined8 param_3,long *param_4,long param_5,
               long param_6,undefined8 param_7,undefined4 param_8)

{
  undefined4 uVar1;
  long lVar2;
  undefined1 auStack_54 [4];
  
  thunk_EXT_FUN_801100000326c6a4(param_3);
  *(undefined8 *)(param_1 + 0x18) = param_3;
  *(long **)(param_1 + 0x38) = param_4;
  (**(code **)(*param_4 + 0x20))(param_4);
  *(undefined8 *)(param_1 + 0x10) = param_2;
  lVar2 = thunk_EXT_FUN_80110000032970b4(*(undefined8 *)(param_1 + 0x18));
  if (lVar2 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = thunk_EXT_FUN_8011000003720f30();
  }
  *(ulong *)(param_1 + 0x28) = param_5 + param_6 + 0x3fU & 0xffffffffffffffc0;
  *(undefined8 *)(param_1 + 0x30) = param_7;
  *(undefined4 *)(param_1 + 0x58) = param_8;
  *(undefined4 *)(param_1 + 0x5c) = uVar1;
  FUN_fffffff009963c60(param_1);
  lVar2 = thunk_EXT_FUN_80110000038ff010();
  *(long *)(param_1 + 0x48) = lVar2;
  if (lVar2 != 0) {
    FUN_fffffff009963d30(param_1,auStack_54);
  }
  return;
}

