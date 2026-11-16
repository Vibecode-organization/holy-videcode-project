// FUN_fffffff009c32e34 @ fffffff009c32e34 size=104

void FUN_fffffff009c32e34(long param_1)

{
  uint uVar1;
  undefined8 uVar2;
  
  uVar2 = *(undefined8 *)(param_1 + 0x118);
  uVar1 = *(uint *)(param_1 + 0x120);
  thunk_EXT_FUN_80110000038fe768
            (&DAT_fffffff00806c290,*(undefined8 *)(param_1 + 0x108),
             (ulong)*(uint *)(param_1 + 0x110) << 3);
  thunk_EXT_FUN_80110000038fe6b0(uVar2,(ulong)uVar1 << 3);
  *(undefined8 *)(param_1 + 0x108) = 0;
  *(undefined4 *)(param_1 + 0x110) = 0;
  *(undefined8 *)(param_1 + 0x118) = 0;
  *(undefined4 *)(param_1 + 0x120) = 0;
  return;
}

