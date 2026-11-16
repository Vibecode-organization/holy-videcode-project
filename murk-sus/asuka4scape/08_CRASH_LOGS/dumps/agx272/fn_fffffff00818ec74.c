// FUN_fffffff00818ec74 @ fffffff00818ec74 size=232

void FUN_fffffff00818ec74(long param_1,long *param_2)

{
  long lVar1;
  
  if (*(uint *)(param_1 + 0x544) < 2) {
    *(long **)(param_1 + 0x910) = param_2;
    (**(code **)(*param_2 + 0x20))(param_2);
    lVar1 = *(long *)(param_1 + 0x910);
    if (*(long **)(lVar1 + 0x70) != (long *)0x0) {
      (**(code **)(**(long **)(lVar1 + 0x70) + 0x28))();
    }
    *(undefined8 *)(lVar1 + 0x70) = 0;
    thunk_EXT_FUN_801100000296c1d8(*(undefined8 *)(lVar1 + 0x10));
    thunk_EXT_FUN_801100000296c1d8(*(undefined8 *)(lVar1 + 0x18));
    thunk_EXT_FUN_801100000296c1d8(*(undefined8 *)(lVar1 + 0x20));
    thunk_EXT_FUN_801100000296c1d8(*(undefined8 *)(lVar1 + 0x28));
    thunk_EXT_FUN_801100000296c1d8(*(undefined8 *)(lVar1 + 0x30));
    thunk_EXT_FUN_801100000296c1d8(*(undefined8 *)(lVar1 + 0x38));
    thunk_EXT_FUN_801100000296c1d8(*(undefined8 *)(lVar1 + 0x40));
    thunk_EXT_FUN_801100000296c1d8(*(undefined8 *)(lVar1 + 0x48));
    thunk_EXT_FUN_801100000296c1d8(*(undefined8 *)(lVar1 + 0x50));
    thunk_EXT_FUN_801100000296c1d8(*(undefined8 *)(lVar1 + 0x58));
    thunk_EXT_FUN_801100000296c1d8(*(undefined8 *)(lVar1 + 0x60));
    thunk_EXT_FUN_801100000296c1d8(*(undefined8 *)(lVar1 + 0x68));
    *(undefined4 *)(lVar1 + 0x8c) = 0;
  }
  return;
}

