// FUN_fffffff009c32e9c @ fffffff009c32e9c size=104

void FUN_fffffff009c32e9c(long param_1)

{
  uint uVar1;
  undefined8 uVar2;
  
  uVar2 = *(undefined8 *)(param_1 + 0xe8);
  uVar1 = *(uint *)(param_1 + 0xf0);
  thunk_EXT_FUN_80110000038fe768
            (&DAT_fffffff00806c1a0,*(undefined8 *)(param_1 + 0xd0),
             (ulong)*(uint *)(param_1 + 0xd8) << 3);
  thunk_EXT_FUN_80110000038fe6b0(uVar2,(ulong)uVar1 << 3);
  *(undefined8 *)(param_1 + 0xd0) = 0;
  *(undefined4 *)(param_1 + 0xd8) = 0;
  *(undefined8 *)(param_1 + 0xe8) = 0;
  *(undefined4 *)(param_1 + 0xf0) = 0;
  return;
}

