// FUN_fffffff009c391a4 @ fffffff009c391a4 size=136

undefined8 FUN_fffffff009c391a4(undefined8 param_1,undefined8 param_2,long param_3)

{
  undefined8 uVar1;
  long lVar2;
  undefined4 *puVar3;
  
  if ((*(int *)(*(long *)(param_3 + 0x20) + 8) + 1U < 2) ||
     (lVar2 = thunk_EXT_FUN_8011000003219eb0(), lVar2 == 0)) {
    uVar1 = 0xe00002c2;
  }
  else {
    puVar3 = *(undefined4 **)(param_3 + 0x20);
    uVar1 = FUN_fffffff009c3d408(param_1,*puVar3,lVar2,puVar3[4],puVar3[6]);
    thunk_EXT_FUN_801100000326c730(lVar2);
  }
  return uVar1;
}

