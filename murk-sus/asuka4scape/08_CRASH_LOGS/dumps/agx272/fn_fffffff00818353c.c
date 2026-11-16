// FUN_fffffff00818353c @ fffffff00818353c size=172

void FUN_fffffff00818353c(long *param_1,undefined4 param_2)

{
  int iVar1;
  long lVar2;
  
  iVar1 = *(int *)(param_1[0xc] + 0x30);
  *(undefined4 *)(param_1 + 0x2f) = param_2;
  (**(code **)(**(long **)(param_1[2] + 0x4b0) + 0x6a8))();
  lVar2 = param_1[0xc];
  if (iVar1 != *(int *)(lVar2 + 0x30)) {
    *(undefined4 *)(lVar2 + 0x48) = 0xffffffff;
    *(undefined4 *)(lVar2 + 0x50) = 0xffffffff;
    (**(code **)(*param_1 + 0x148))(param_1);
  }
  DataMemoryBarrier(2,3);
  return;
}

