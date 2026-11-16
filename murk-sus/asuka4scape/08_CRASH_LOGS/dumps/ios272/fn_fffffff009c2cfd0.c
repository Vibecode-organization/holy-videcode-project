// FUN_fffffff009c2cfd0 @ fffffff009c2cfd0 size=4

undefined8 FUN_fffffff009c2cfd0(long param_1,undefined8 param_2)

{
  long *plVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  long *plVar5;
  long lVar6;
  undefined8 uVar7;
  undefined4 uStack_4c;
  long lStack_48;
  
  lStack_48 = *(long *)PTR_DAT_fffffff00806ca40;
  uVar4 = (**(code **)(PTR_DAT_fffffff00806ca30 + 0x78))();
  if ((int)uVar4 != 0) {
    uVar3 = FUN_fffffff009c22350(param_2);
    *(undefined4 *)(param_1 + 0xc) = uVar3;
    uVar3 = FUN_fffffff009c1f1a8(param_2);
    *(undefined4 *)(param_1 + 0x30) = uVar3;
    uVar2 = FUN_fffffff009c22368(param_2);
    *(undefined2 *)(param_1 + 0x34) = uVar2;
    uVar2 = FUN_fffffff009c22374(param_2);
    *(undefined2 *)(param_1 + 0x36) = uVar2;
    uStack_4c = 0xaaaaaaaa;
    plVar5 = (long *)FUN_fffffff009c259a0(param_2,DAT_fffffff008066f90,&uStack_4c);
    lVar6 = thunk_EXT_FUN_8011000003890f30(plVar5,*(undefined8 *)PTR_DAT_fffffff00806ca10);
    plVar1 = plVar5;
    if (lVar6 != 0) {
      plVar1 = (long *)0x0;
    }
    if (*(long **)(param_1 + 0x20) != (long *)0x0) {
      (**(code **)(**(long **)(param_1 + 0x20) + 0x28))();
    }
    *(long *)(param_1 + 0x20) = lVar6;
    if (plVar1 != (long *)0x0) {
      (**(code **)(*plVar5 + 0x28))(plVar5);
    }
    uVar7 = FUN_fffffff009c22264(param_2);
    *(undefined8 *)(param_1 + 0x28) = uVar7;
    FUN_fffffff009c37ab4(DAT_fffffff00af483b0,param_1);
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 == lStack_48) {
    return uVar4;
  }
  uVar4 = thunk_EXT_FUN_8011000003a48590();
  return uVar4;
}

