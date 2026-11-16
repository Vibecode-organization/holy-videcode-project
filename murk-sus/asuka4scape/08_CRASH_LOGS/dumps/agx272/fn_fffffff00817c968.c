// FUN_fffffff00817c968 @ fffffff00817c968 size=152

void FUN_fffffff00817c968(long param_1)

{
  int iVar1;
  ulong uVar2;
  
  if ((*(byte *)(param_1 + 0x540) & 1) != 0) {
    uVar2 = (**(code **)(**(long **)(param_1 + 0x4b0) + 0xf8))();
    if (((uVar2 & 1) == 0) &&
       (iVar1 = thunk_EXT_FUN_801100000294780c(*(undefined8 *)(param_1 + 0x148)), iVar1 != 0)) {
      *(undefined1 *)(param_1 + 0x579) = 0;
      (**(code **)(**(long **)(param_1 + 0x310) + 0x108))
                (*(long **)(param_1 + 0x310),param_1 + 0x579,0);
    }
    *(undefined1 *)(param_1 + 0x540) = 0;
  }
  return;
}

