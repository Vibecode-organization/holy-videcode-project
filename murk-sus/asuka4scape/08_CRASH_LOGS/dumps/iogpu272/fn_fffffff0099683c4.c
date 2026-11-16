// FUN_fffffff0099683c4 @ fffffff0099683c4 size=228

undefined8 FUN_fffffff0099683c4(long param_1)

{
  long *plVar1;
  int iVar2;
  long lVar3;
  long *plVar4;
  
  if ((*(byte *)(param_1 + 0xfc) & 1) == 0) {
    plVar1 = (long *)(param_1 + 0xe8);
    do {
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0xe0));
      while (plVar4 = (long *)*plVar1, plVar4 == (long *)0x0) {
        *(int *)(param_1 + 0xf8) = *(int *)(param_1 + 0xf8) + 1;
        iVar2 = thunk_EXT_FUN_80110000038ff064(*(undefined8 *)(param_1 + 0xe0),param_1,1);
        *(int *)(param_1 + 0xf8) = *(int *)(param_1 + 0xf8) + -1;
        if ((iVar2 == 2) || ((*(byte *)(param_1 + 0xfc) & 1) != 0)) {
          thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0xe0));
          return 0xe00002eb;
        }
      }
      lVar3 = plVar4[0x28];
      *plVar1 = lVar3;
      if (lVar3 == 0) {
        *(long **)(param_1 + 0xf0) = plVar1;
      }
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0xe0));
      FUN_fffffff00996f47c(plVar4);
      (**(code **)(*plVar4 + 0x28))(plVar4);
    } while ((*(byte *)(param_1 + 0xfc) & 1) == 0);
  }
  return 0xe00002eb;
}

