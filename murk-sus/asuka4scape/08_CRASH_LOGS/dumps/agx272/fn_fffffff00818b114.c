// FUN_fffffff00818b114 @ fffffff00818b114 size=204

undefined8 FUN_fffffff00818b114(long param_1,undefined8 param_2)

{
  int iVar1;
  long *plVar2;
  undefined8 uVar3;
  
  if (*(long *)(param_1 + 0x610) != 0) {
    return 1;
  }
  plVar2 = (long *)(**(code **)(DAT_fffffff00ae21f78 + 0x68))();
  uVar3 = 0;
  if (plVar2 != (long *)0x0) {
    iVar1 = (**(code **)(*plVar2 + 0x78))(plVar2,*(undefined8 *)(param_1 + 0x530),param_1,param_2);
    if (iVar1 == 0) {
      (**(code **)(*plVar2 + 0x28))(plVar2);
      uVar3 = 0;
    }
    else {
      *(long **)(param_1 + 0x610) = plVar2;
      uVar3 = 1;
    }
  }
  return uVar3;
}

