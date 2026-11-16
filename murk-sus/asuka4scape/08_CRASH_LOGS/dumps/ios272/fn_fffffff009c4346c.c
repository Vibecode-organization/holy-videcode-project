// FUN_fffffff009c4346c @ fffffff009c4346c size=132

void FUN_fffffff009c4346c(long param_1)

{
  undefined8 uVar1;
  long *plVar2;
  
  if ((*(byte *)(param_1 + 0x10) & 1) != 0) {
    plVar2 = *(long **)(param_1 + 0x18);
    uVar1 = (**(code **)(*plVar2 + 0xb0))(plVar2);
    (**(code **)(*plVar2 + 0xd0))(plVar2,0,0,uVar1);
    *(undefined1 *)(param_1 + 0x10) = 0;
  }
  return;
}

