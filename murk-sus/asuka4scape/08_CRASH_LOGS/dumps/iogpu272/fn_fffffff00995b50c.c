// FUN_fffffff00995b50c @ fffffff00995b50c size=316

void FUN_fffffff00995b50c(long param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  undefined8 local_48;
  
  if (*(long *)(param_1 + 0x48) != *(long *)(param_1 + 0x40)) {
    thunk_EXT_FUN_80110000036da494(0x85090105,*(undefined8 *)(param_1 + 0x30),0,0,0,0);
    *(undefined1 *)(param_1 + 0x50) = 1;
    lVar3 = *(long *)(param_1 + 0x48);
    lVar2 = *(long *)(param_1 + 0x40);
    while (lVar2 != lVar3) {
      local_48 = 0;
      thunk_EXT_FUN_8011000003204ed8(100,1000000,&local_48);
      iVar1 = thunk_EXT_FUN_8011000003243438(param_1,1,local_48);
      if (iVar1 == 2) break;
      if (*(long *)(param_1 + 0x40) == *(long *)(param_1 + 0x48)) {
        thunk_EXT_FUN_8011000003246024(param_1,0,0);
        break;
      }
      if ((iVar1 == -1) && (iVar1 = thunk_EXT_FUN_8011000003247bfc(0), iVar1 == 2)) break;
      lVar3 = *(long *)(param_1 + 0x48);
      lVar2 = *(long *)(param_1 + 0x40);
    }
    *(undefined1 *)(param_1 + 0x50) = 0;
    thunk_EXT_FUN_80110000036da494(0x85090106,*(undefined8 *)(param_1 + 0x30),0,0,0,0);
  }
  return;
}

