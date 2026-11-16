// FUN_fffffff009c48c58 @ fffffff009c48c58 size=164

void FUN_fffffff009c48c58(long param_1,ulong *param_2,undefined8 param_3)

{
  byte bVar1;
  int iVar2;
  ulong uVar3;
  uint local_2c;
  long local_28;
  
  local_28 = *(long *)PTR_DAT_fffffff00806ca40;
  if (param_2 == (ulong *)0x0) {
    FUN_fffffff009c49524();
  }
  else {
    local_2c = 0xaaaaaaaa;
    iVar2 = thunk_EXT_FUN_80110000039a3b30(param_3,*(undefined8 *)(param_1 + 0x18),&local_2c);
    if (iVar2 == 0) {
      uVar3 = *(ulong *)(param_1 + 0x20);
      bVar1 = *(byte *)(param_1 + 0x28);
      *param_2 = (ulong)local_2c;
      param_2[1] = uVar3;
      *(byte *)(param_2 + 2) = bVar1 & 1;
      *(undefined2 *)((long)param_2 + 0x11) = 0;
      *(undefined1 *)((long)param_2 + 0x13) = 0;
    }
    if (*(long *)PTR_DAT_fffffff00806ca40 == local_28) {
      return;
    }
  }
  thunk_EXT_FUN_8011000003a48590();
  return;
}

