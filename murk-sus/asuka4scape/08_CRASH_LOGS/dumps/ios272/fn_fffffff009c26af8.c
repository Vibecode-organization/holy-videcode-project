// FUN_fffffff009c26af8 @ fffffff009c26af8 size=112

undefined8 FUN_fffffff009c26af8(undefined8 param_1,long param_2,long param_3,int param_4)

{
  if ((((*(int *)(param_3 + 0x4c) == 0) &&
       ((((*(byte *)(param_2 + 0x52) & 1) == 0 || (*(int *)(param_2 + 0x20) == 0)) ||
        (*(int *)(param_2 + 0x20) != *(int *)(param_3 + 0x20))))) &&
      ((((param_4 == 0 || (*(int *)(param_2 + 0x20) == 0)) ||
        (*(int *)(param_2 + 0x20) != *(int *)(param_3 + 0x20))) ||
       ((*(byte *)(param_2 + 0x24) >> 1 & 1) == 0)))) &&
     ((*(int *)(param_2 + 0x24) != 1 || (*(int *)(param_3 + 0x24) != 1)))) {
    return 0;
  }
  return 1;
}

