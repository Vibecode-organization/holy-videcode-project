// FUN_fffffff0081fd134 @ fffffff0081fd134 size=196

undefined8 FUN_fffffff0081fd134(long param_1,undefined8 param_2)

{
  undefined8 uVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x10);
  thunk_EXT_FUN_8011000003224180(*(undefined8 *)(lVar2 + 0x11a70));
  thunk_EXT_FUN_8011000003224180(*(undefined8 *)(lVar2 + 0x11a78));
  if (*(int *)(*(long *)(param_1 + 0x10) + 0x11a68) == 0) {
    uVar1 = thunk_EXT_FUN_801100000396cb64(param_2,*(undefined8 *)(param_1 + 0x28),0,1,0,0);
    lVar2 = *(long *)(param_1 + 0x10);
    thunk_EXT_FUN_8011000003224d30(*(undefined8 *)(lVar2 + 0x11a78));
    thunk_EXT_FUN_8011000003224d30(*(undefined8 *)(lVar2 + 0x11a70));
    return uVar1;
  }
  uVar1 = thunk_EXT_FUN_8011000003a49114
                    ("AGXk: %s:%d:%s: !!! AGXSecureGart::createRestrictedRangeMapping\n");
  return uVar1;
}

