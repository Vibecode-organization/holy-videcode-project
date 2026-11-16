// FUN_fffffff009947658 @ fffffff009947658 size=100

undefined8 FUN_fffffff009947658(undefined8 param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  long lVar2;
  int iVar3;
  long *plVar4;
  
  plVar4 = *(long **)(param_3 + 0x58);
  do {
    lVar2 = DAT_fffffff00af220c0;
    lVar1 = DAT_fffffff00af220c0 + 0x1000000;
    iVar3 = thunk_EXT_FUN_8011000003890594(DAT_fffffff00af220c0,lVar1,&DAT_fffffff00af220c0);
  } while (iVar3 == 0);
  *plVar4 = lVar2;
  plVar4[1] = lVar1;
  return 0;
}

