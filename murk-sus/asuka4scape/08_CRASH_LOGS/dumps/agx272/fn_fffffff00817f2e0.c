// FUN_fffffff00817f2e0 @ fffffff00817f2e0 size=236

long * FUN_fffffff00817f2e0(undefined8 param_1,int param_2)

{
  long *plVar1;
  long lVar2;
  undefined8 local_40;
  undefined8 uStack_38;
  
  local_40 = 0;
  uStack_38 = 0;
  thunk_EXT_FUN_801100000295c2dc(&local_40,param_1);
  do {
    plVar1 = (long *)thunk_EXT_FUN_801100000295c384(&local_40);
    if (plVar1 == (long *)0x0) goto LAB_fffffff00817f3ac;
    lVar2 = thunk_EXT_FUN_8011000003890f30(plVar1,&DAT_fffffff00ae25b38);
  } while (((lVar2 == 0) ||
           (((*(long *)(lVar2 + 0x218) == 0 ||
             (*(int *)(*(long *)(lVar2 + 0x218) + 0x18) != param_2)) &&
            ((*(long *)(lVar2 + 0x220) == 0 ||
             (*(int *)(*(long *)(lVar2 + 0x220) + 0x18) != param_2)))))) &&
          (((lVar2 = thunk_EXT_FUN_8011000003890f30(plVar1,&DAT_fffffff00ae25b60), lVar2 == 0 ||
            (*(long *)(lVar2 + 0x218) == 0)) ||
           (*(int *)(*(long *)(lVar2 + 0x218) + 0x18) != param_2))));
  (**(code **)(*plVar1 + 0x20))(plVar1);
LAB_fffffff00817f3ac:
  thunk_EXT_FUN_801100000295c350(&local_40);
  return plVar1;
}

