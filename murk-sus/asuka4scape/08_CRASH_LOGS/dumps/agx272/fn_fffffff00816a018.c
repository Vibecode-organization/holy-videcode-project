// FUN_fffffff00816a018 @ fffffff00816a018 size=364

void FUN_fffffff00816a018(long param_1,int param_2)

{
  undefined1 uVar1;
  
  if (param_2 == 0) {
    if ((*(byte *)(param_1 + 0x510) & 1) == 0) {
      return;
    }
    (**(code **)(**(long **)(param_1 + 0x4c0) + 0xb8))();
    (**(code **)(**(long **)(param_1 + 0x398) + 0xb8))();
    if (((*(byte *)(param_1 + 0x645) & 1) != 0) && (*(long **)(param_1 + 0x4d0) != (long *)0x0)) {
      (**(code **)(**(long **)(param_1 + 0x4d0) + 0xb8))();
    }
    (**(code **)(**(long **)(param_1 + 0x4d0 + (ulong)*(byte *)(param_1 + 0x644) * 8) + 0xb8))();
    (**(code **)(**(long **)(param_1 + 0x570) + 0xb8))();
    uVar1 = 0;
  }
  else {
    if ((*(byte *)(param_1 + 0x510) & 1) != 0) {
      return;
    }
    if (((*(byte *)(param_1 + 0x645) & 1) != 0) && (*(long **)(param_1 + 0x4d0) != (long *)0x0)) {
      (**(code **)(**(long **)(param_1 + 0x4d0) + 0xb0))();
    }
    (**(code **)(**(long **)(param_1 + 0x570) + 0xb0))();
    (**(code **)(**(long **)(param_1 + 0x4d0 + (ulong)*(byte *)(param_1 + 0x644) * 8) + 0xb0))();
    uVar1 = 1;
  }
  *(undefined1 *)(param_1 + 0x510) = uVar1;
  return;
}

