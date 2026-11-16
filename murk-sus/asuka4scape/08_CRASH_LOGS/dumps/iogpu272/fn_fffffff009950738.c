// FUN_fffffff009950738 @ fffffff009950738 size=108

undefined8 FUN_fffffff009950738(undefined8 param_1,long param_2,long param_3)

{
  long lVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_2 + 0x460);
  while( true ) {
    if (lVar2 == 0) {
      return 0;
    }
    lVar1 = thunk_EXT_FUN_8011000003890f30(lVar2,&DAT_fffffff00af22380);
    if ((lVar1 != 0) && (*(long *)(lVar1 + 0xd0) == param_3)) break;
    lVar2 = *(long *)(lVar2 + 0xb0);
  }
  return 1;
}

