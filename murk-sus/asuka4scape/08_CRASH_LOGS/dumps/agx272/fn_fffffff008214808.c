// FUN_fffffff008214808 @ fffffff008214808 size=224

bool FUN_fffffff008214808(long param_1,long *param_2)

{
  long lVar1;
  undefined8 *puVar2;
  long *plVar3;
  long lVar4;
  
  *(long **)(param_1 + 0x228) = param_2;
  if (param_2 == (long *)0x0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ca61a8,0x10,"Failed to share PM\n");
  }
  else {
    (**(code **)(*param_2 + 0x20))(param_2);
    lVar4 = *(long *)(param_1 + 0xc0);
    plVar3 = *(long **)(param_1 + 0x228);
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar4 + 800));
    lVar1 = plVar3[0x41];
    *(int *)(plVar3 + 0x41) = (int)lVar1 + 1;
    if ((int)lVar1 == 0) {
      (**(code **)(*plVar3 + 0x20))(plVar3);
      puVar2 = *(undefined8 **)(lVar4 + 0x330);
      plVar3[0x3f] = 0;
      plVar3[0x40] = (long)puVar2;
      *puVar2 = plVar3;
      *(long **)(lVar4 + 0x330) = plVar3 + 0x3f;
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar4 + 800));
  }
  return param_2 != (long *)0x0;
}

