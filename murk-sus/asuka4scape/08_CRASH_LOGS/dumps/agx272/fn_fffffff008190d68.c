// FUN_fffffff008190d68 @ fffffff008190d68 size=212

void FUN_fffffff008190d68(long param_1)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  
  (**(code **)(PTR_DAT_fffffff007ca6130 + 0xc0))();
  iVar2 = *(int *)(param_1 + 0x7ec);
  *(int *)(param_1 + 0x7ec) = *(int *)(param_1 + 0x44c);
  if (*(int *)(param_1 + 0x44c) != iVar2) {
    thunk_EXT_FUN_8011000002947870
              (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),param_1 + 0x498);
    FUN_fffffff00818f15c(param_1);
    uVar3 = *(uint *)(param_1 + 0x7ec);
    if ((5 < uVar3) || ((0x37U >> (ulong)(uVar3 & 0x1f) & 1) == 0)) {
      thunk_EXT_FUN_8011000003a49114
                ("AGXk: %s:%d:%s: !!! Invalid priority level for CommandQueue %d\n");
      return;
    }
    lVar4 = (ulong)uVar3 * 4;
    puVar1 = (undefined4 *)(&DAT_fffffff007115cc0 + (int)lVar4);
    if (lVar4 - (int)lVar4 != 0) {
      puVar1 = (undefined4 *)
               ((ulong)(&DAT_fffffff007115cc0 + lVar4) & 0xffffffffffff | 0x2bad000000000000);
    }
    *(undefined4 *)(param_1 + 0x7f0) = *puVar1;
  }
  return;
}

