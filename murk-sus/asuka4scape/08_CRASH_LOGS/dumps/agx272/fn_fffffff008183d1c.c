// FUN_fffffff008183d1c @ fffffff008183d1c size=256

undefined8 FUN_fffffff008183d1c(long param_1)

{
  int iVar1;
  long lVar2;
  long *plVar3;
  
  if ((*(long *)(param_1 + 0x160) == 0) || (iVar1 = FUN_fffffff0081e0b20(), iVar1 == 0)) {
    plVar3 = (long *)(param_1 + 200);
    iVar1 = FUN_fffffff0081e0b20(*plVar3);
    if (iVar1 == 0) {
      iVar1 = FUN_fffffff0081e0b20(*(long *)(param_1 + 0xd0));
      if (iVar1 == 0) {
        iVar1 = FUN_fffffff0081e0b20(*(undefined8 *)(param_1 + 0xd8));
        if (iVar1 == 0) {
          return 1;
        }
        lVar2 = *plVar3;
        thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar2 + 0x40));
        if (0 < *(long *)(lVar2 + 0x38)) {
          if (*(long *)(lVar2 + 0x50) != 0) {
            thunk_EXT_FUN_801100000297b408();
          }
          if (*(long *)(lVar2 + 0x58) != 0) {
            thunk_EXT_FUN_801100000297b408();
          }
          *(long *)(lVar2 + 0x38) = *(long *)(lVar2 + 0x38) + -1;
        }
        thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar2 + 0x40));
        plVar3 = (long *)(param_1 + 0xd0);
      }
      lVar2 = *plVar3;
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar2 + 0x40));
      if (0 < *(long *)(lVar2 + 0x38)) {
        if (*(long *)(lVar2 + 0x50) != 0) {
          thunk_EXT_FUN_801100000297b408();
        }
        if (*(long *)(lVar2 + 0x58) != 0) {
          thunk_EXT_FUN_801100000297b408();
        }
        *(long *)(lVar2 + 0x38) = *(long *)(lVar2 + 0x38) + -1;
      }
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar2 + 0x40));
    }
  }
  return 0;
}

