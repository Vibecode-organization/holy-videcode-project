// FUN_fffffff009c308d8 @ fffffff009c308d8 size=296

bool FUN_fffffff009c308d8(long param_1,long *param_2,long *param_3)

{
  long lVar1;
  undefined8 uVar2;
  long *plVar3;
  long *plVar4;
  
  plVar3 = *(long **)(param_1 + 0x10);
  *(long **)(param_1 + 0x10) = param_2;
  if (param_2 != (long *)0x0) {
    (**(code **)(*param_2 + 0x20))(param_2);
  }
  if (plVar3 != (long *)0x0) {
    (**(code **)(*plVar3 + 0x28))(plVar3);
  }
  lVar1 = thunk_EXT_FUN_80110000038ff010();
  *(long *)(param_1 + 0x18) = lVar1;
  if ((param_3 != (long *)0x0) && (lVar1 != 0)) {
    uVar2 = (**(code **)(*param_3 + 0x138))(param_3,"IOSurfaceMemoryRegion");
    plVar3 = (long *)thunk_EXT_FUN_8011000003890f30(uVar2,*(undefined8 *)PTR_DAT_fffffff00806ca10);
    plVar4 = *(long **)(param_1 + 0x20);
    *(long **)(param_1 + 0x20) = plVar3;
    if (plVar3 != (long *)0x0) {
      (**(code **)(*plVar3 + 0x20))();
    }
    if (plVar4 != (long *)0x0) {
      (**(code **)(*plVar4 + 0x28))(plVar4);
    }
  }
  return lVar1 != 0;
}

