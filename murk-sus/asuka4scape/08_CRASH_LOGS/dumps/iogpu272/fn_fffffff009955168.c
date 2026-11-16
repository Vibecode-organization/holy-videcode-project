// FUN_fffffff009955168 @ fffffff009955168 size=48

void FUN_fffffff009955168(long param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x10);
  if ((uVar1 & 0xff) == 0x82) {
    FUN_fffffff0099550c0();
    return;
  }
  if ((uVar1 & 0x800) == 0 && (uVar1 & 0xf) == 0) {
    *(uint *)(param_1 + 0x10) = uVar1 | 0x80000;
  }
  return;
}

