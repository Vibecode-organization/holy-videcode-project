// FUN_fffffff009960538 @ fffffff009960538 size=176

undefined8 FUN_fffffff009960538(long param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x20);
  iVar1 = thunk_EXT_FUN_801100000389060c(lVar3 + 0x15c);
  if (iVar1 != 1) {
    if (iVar1 != 0) {
      return 0;
    }
    FUN_fffffff009983bb0();
  }
  FUN_fffffff00995f52c(lVar3,3,0);
  (**(code **)(**(long **)(lVar3 + 0x28) + 0x108))(*(long **)(lVar3 + 0x28),lVar3,0);
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar3 + 0x248));
  lVar2 = thunk_EXT_FUN_8011000003397c88();
  *(long *)(lVar3 + 0x238) = lVar2 - *(long *)(lVar3 + 0x230);
  thunk_EXT_FUN_80110000038ff08c(*(undefined8 *)(lVar3 + 0x248),lVar3,0);
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar3 + 0x248));
  return 0;
}

