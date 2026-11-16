// FUN_fffffff009956140 @ fffffff009956140 size=132

undefined8 FUN_fffffff009956140(long param_1,undefined8 param_2)

{
  long lVar1;
  undefined8 uVar2;
  
  if (((*(byte *)(param_1 + 0x10) & 0x7f) == 0) &&
     (lVar1 = thunk_EXT_FUN_8011000003890f30(*(undefined8 *)(param_1 + 0x28),DAT_fffffff007fefaf0),
     lVar1 != 0)) {
    FUN_fffffff009942d70();
    uVar2 = FUN_fffffff009981d00(lVar1);
    uVar2 = thunk_EXT_FUN_8011000003977b2c(uVar2,param_2,4,0);
    FUN_fffffff009942d7c(lVar1);
  }
  else {
    uVar2 = 0xe00002c2;
  }
  return uVar2;
}

