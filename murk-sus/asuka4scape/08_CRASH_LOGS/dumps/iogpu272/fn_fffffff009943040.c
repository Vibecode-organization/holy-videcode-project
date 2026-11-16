// FUN_fffffff009943040 @ fffffff009943040 size=228

long * FUN_fffffff009943040(long param_1)

{
  int iVar1;
  long *plVar2;
  long *plVar3;
  long lVar4;
  long lVar5;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x48));
  plVar2 = (long *)thunk_EXT_FUN_80110000038961f4(*(undefined4 *)(param_1 + 0x54));
  if (plVar2 != (long *)0x0) {
    if (*(int *)(param_1 + 0x50) == 2) {
      lVar4 = param_1 + 0x60;
    }
    else {
      lVar4 = *(long *)(param_1 + 0x58);
    }
    if (0 < *(int *)(param_1 + 0x54)) {
      lVar5 = 0;
      do {
        plVar3 = *(long **)(lVar4 + lVar5 * 8);
        iVar1 = FUN_fffffff00994d91c(plVar3);
        if (iVar1 != 0) {
          (**(code **)(*plVar2 + 0xe8))(plVar2,plVar3);
          (**(code **)(*plVar3 + 0x28))(plVar3);
        }
        lVar5 = lVar5 + 1;
      } while (lVar5 < *(int *)(param_1 + 0x54));
    }
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x48));
  return plVar2;
}

