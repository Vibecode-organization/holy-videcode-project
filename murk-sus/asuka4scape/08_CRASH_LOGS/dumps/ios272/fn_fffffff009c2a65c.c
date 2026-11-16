// FUN_fffffff009c2a65c @ fffffff009c2a65c size=36

void FUN_fffffff009c2a65c(long param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = 0x100;
  if (param_2 == 0) {
    uVar1 = 0;
  }
  *(uint *)(param_1 + 0x3d0) = *(uint *)(param_1 + 0x3d0) & 0xfffffeff | uVar1;
  return;
}

