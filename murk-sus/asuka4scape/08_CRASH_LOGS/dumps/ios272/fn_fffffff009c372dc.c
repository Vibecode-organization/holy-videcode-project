// FUN_fffffff009c372dc @ fffffff009c372dc size=272

long * FUN_fffffff009c372dc(long param_1)

{
  ulong uVar1;
  long *plVar2;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x140));
  if (*(long *)(param_1 + 0x218) == 0) {
    plVar2 = (long *)(**(code **)(*DAT_fffffff00806a5f8 + 0x68))();
    if (*(long **)(param_1 + 0x218) != (long *)0x0) {
      (**(code **)(**(long **)(param_1 + 0x218) + 0x28))();
    }
    *(long **)(param_1 + 0x218) = plVar2;
    if ((plVar2 != (long *)0x0) && (uVar1 = (**(code **)(*plVar2 + 0x68))(plVar2), (uVar1 & 1) == 0)
       ) {
      if (*(long **)(param_1 + 0x218) != (long *)0x0) {
        (**(code **)(**(long **)(param_1 + 0x218) + 0x28))();
      }
      *(undefined8 *)(param_1 + 0x218) = 0;
    }
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x140));
  plVar2 = *(long **)(param_1 + 0x218);
  if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 0x20))(plVar2);
  }
  return plVar2;
}

