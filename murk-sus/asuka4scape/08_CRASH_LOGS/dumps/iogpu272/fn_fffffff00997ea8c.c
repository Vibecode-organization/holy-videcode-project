// FUN_fffffff00997ea8c @ fffffff00997ea8c size=124

undefined8 FUN_fffffff00997ea8c(undefined8 param_1)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  
  uVar3 = 0xe00002c1;
  iVar1 = FUN_fffffff00997eb08();
  if (iVar1 == 0) {
    lVar2 = thunk_EXT_FUN_8011000003890f30(param_1,&DAT_fffffff00af22898);
    if (lVar2 == 0) {
      uVar3 = 0xe00002c2;
    }
    else {
      (**(code **)(**(long **)(*(long *)(lVar2 + 0xe0) + 0x160) + 0x80))();
      uVar3 = 0;
    }
  }
  return uVar3;
}

