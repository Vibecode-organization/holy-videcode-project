// FUN_fffffff00997ea10 @ fffffff00997ea10 size=124

undefined8 FUN_fffffff00997ea10(undefined8 param_1,undefined8 param_2,long param_3)

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
      FUN_fffffff009974f3c(*(undefined8 *)(lVar2 + 0xe0),0,*(undefined8 *)(param_3 + 0x58));
      uVar3 = 0;
      *(undefined4 *)(param_3 + 0x60) = 0x70;
    }
  }
  return uVar3;
}

