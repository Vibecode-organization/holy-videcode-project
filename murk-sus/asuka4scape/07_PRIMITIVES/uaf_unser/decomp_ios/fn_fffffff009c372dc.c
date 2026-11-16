// FUN_fffffff009c372dc @ fffffff009c372dc size=272
// CALLERS:
//   fffffff009c1eaf8 FUN_fffffff009c1e624@fffffff009c1e624
//   fffffff009c2446c FUN_fffffff009c23d94@fffffff009c23d94
//   fffffff009c37430 FUN_fffffff009c373ec@fffffff009c373ec
//   fffffff009c37480 FUN_fffffff009c373ec@fffffff009c373ec
//   fffffff009c3ad40 FUN_fffffff009c3ab8c@fffffff009c3ab8c
//   fffffff009c3e3e8 FUN_fffffff009c3e388@fffffff009c3e388
//   fffffff009c3e470 FUN_fffffff009c3e388@fffffff009c3e388
//   fffffff009c3ed60 FUN_fffffff009c3eb68@fffffff009c3eb68

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long * FUN_fffffff009c372dc(long param_1)

{
  ulong uVar1;
  long *plVar2;
  
  FUN_fffffff009c495b4(*(undefined8 *)(param_1 + 0x140));
  if (*(long *)(param_1 + 0x218) == 0) {
    plVar2 = (long *)(**(code **)(*_DAT_fffffff00806a5f8 + 0x68))();
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
  FUN_fffffff009c495d4(*(undefined8 *)(param_1 + 0x140));
  plVar2 = *(long **)(param_1 + 0x218);
  if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 0x20))(plVar2);
  }
  return plVar2;
}

