// FUN_fffffff009c3e134 @ fffffff009c3e134 size=248

undefined8 FUN_fffffff009c3e134(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  int iVar4;
  
  uVar3 = 0xe00002c2;
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0xd8));
  iVar1 = (**(code **)(**(long **)(param_1 + 0x100) + 0x90))();
  if (iVar1 != 0) {
    iVar4 = 0;
    do {
      lVar2 = (**(code **)(**(long **)(param_1 + 0x100) + 0x118))(*(long **)(param_1 + 0x100),iVar4)
      ;
      if (*(long *)(lVar2 + 0x60) == param_2) {
        (**(code **)(**(long **)(param_1 + 0x100) + 0x108))(*(long **)(param_1 + 0x100),iVar4);
        uVar3 = 0;
        break;
      }
      iVar4 = iVar4 + 1;
    } while (iVar1 != iVar4);
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0xd8));
  return uVar3;
}

