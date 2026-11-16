// FUN_fffffff009950858 @ fffffff009950858 size=332

long * FUN_fffffff009950858(long param_1,long param_2,long param_3)

{
  long *plVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x20));
  if (*(int *)(param_1 + 0x70) == 0) {
LAB_fffffff009950958:
    plVar1 = (long *)0x0;
    goto LAB_fffffff009950980;
  }
  lVar2 = *(long *)(param_1 + 0x40);
  while (lVar2 != 0) {
    plVar1 = (long *)(lVar2 + 0x460);
    lVar2 = *(long *)(lVar2 + 0x470);
    lVar3 = *plVar1;
    while (lVar3 != 0) {
      lVar4 = *(long *)(lVar3 + 0xb0);
      plVar1 = (long *)thunk_EXT_FUN_8011000003890f30(lVar3,&DAT_fffffff00af22380);
      lVar3 = lVar4;
      if ((plVar1 != (long *)0x0) && (plVar1[0x1a] == param_2 && param_3 == plVar1[0x1b]))
      goto LAB_fffffff009950960;
    }
  }
  lVar2 = *(long *)(param_1 + 0x60);
  do {
    if (lVar2 == 0) {
      lVar2 = *(long *)(param_1 + 0x50);
      goto joined_r0xfffffff009950920;
    }
    lVar3 = *(long *)(lVar2 + 0xb0);
    plVar1 = (long *)thunk_EXT_FUN_8011000003890f30(lVar2,&DAT_fffffff00af22380);
    lVar2 = lVar3;
  } while ((plVar1 == (long *)0x0) || (plVar1[0x1a] != param_2 || param_3 != plVar1[0x1b]));
  goto LAB_fffffff009950960;
  while( true ) {
    lVar3 = *(long *)(lVar2 + 0xb0);
    plVar1 = (long *)thunk_EXT_FUN_8011000003890f30(lVar2,&DAT_fffffff00af22380);
    lVar2 = lVar3;
    if ((plVar1 != (long *)0x0) && (plVar1[0x1a] == param_2 && param_3 == plVar1[0x1b])) break;
joined_r0xfffffff009950920:
    if (lVar2 == 0) goto LAB_fffffff009950958;
  }
LAB_fffffff009950960:
  (**(code **)(*plVar1 + 0x20))(plVar1);
LAB_fffffff009950980:
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x20));
  return plVar1;
}

