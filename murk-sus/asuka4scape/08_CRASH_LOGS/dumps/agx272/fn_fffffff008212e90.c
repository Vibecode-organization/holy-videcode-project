// FUN_fffffff008212e90 @ fffffff008212e90 size=260

long FUN_fffffff008212e90(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  
  if (*(int *)(*(long *)(param_1 + 0xc0) + 0x189e4) != 0x80) {
    uVar2 = thunk_EXT_FUN_8011000002958c40();
    lVar4 = thunk_EXT_FUN_8011000002949010
                      (uVar2,*(undefined4 *)(*(long *)(param_1 + 0xc0) + 0x189e4));
    lVar3 = thunk_EXT_FUN_8011000003890f30(lVar4,&DAT_fffffff00ae255c0);
    if (lVar4 != 0 && lVar3 == 0) {
      lVar3 = thunk_EXT_FUN_8011000003a49114
                        (
                        "AGXk: %s:%d:%s: !!! getGuiltyChannel: Type confusion - invalid AGXChannel for firmware guilty_stamp_index %d\n"
                        );
      return lVar3;
    }
    goto joined_r0xfffffff008212f28;
  }
  uVar2 = thunk_EXT_FUN_8011000002959a74();
  lVar3 = thunk_EXT_FUN_8011000003890f30(uVar2,&DAT_fffffff00ae256a0);
  if (lVar3 == 0) {
LAB_fffffff008212eec:
    lVar3 = 0x220;
  }
  else {
    uVar2 = thunk_EXT_FUN_8011000002958c40(param_1);
    iVar1 = thunk_EXT_FUN_80110000029474ec(uVar2,lVar3 + 0xc40);
    if (iVar1 != 0) goto LAB_fffffff008212eec;
    lVar3 = 0x218;
  }
  lVar3 = *(long *)(param_1 + lVar3);
joined_r0xfffffff008212f28:
  if (lVar3 == 0) {
    lVar3 = *(long *)(*(long *)(param_1 + 0xc0) + 0x11a50);
  }
  return lVar3;
}

