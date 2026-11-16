// FUN_fffffff00997e1ac @ fffffff00997e1ac size=224

undefined8 * FUN_fffffff00997e1ac(undefined8 *param_1,long param_2)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  long *plVar4;
  long lVar5;
  long lVar6;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_2 + 0x28));
  uVar3 = thunk_EXT_FUN_80110000038961f4(*(undefined4 *)(param_2 + 0x18));
  *param_1 = uVar3;
  uVar1 = *(uint *)(param_2 + 0x14);
  if (uVar1 != 0) {
    lVar5 = 0;
    lVar6 = 0;
    do {
      plVar4 = *(long **)(*(long *)(param_2 + 8) + lVar6 * 0x10);
      if ((plVar4 != (long *)0x0) && (iVar2 = FUN_fffffff00994d91c(plVar4), iVar2 != 0)) {
        (**(code **)(*(long *)*param_1 + 0xe8))((long *)*param_1,plVar4);
        (**(code **)(*plVar4 + 0x28))(plVar4);
      }
      lVar6 = lVar6 + 1;
      lVar5 = lVar5 + 0x10;
    } while ((ulong)uVar1 * 0x10 - lVar5 != 0);
  }
  *(undefined4 *)(param_1 + 1) = 0;
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_2 + 0x28));
  return param_1;
}

