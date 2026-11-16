// FUN_fffffff00816a290 @ fffffff00816a290 size=240

bool FUN_fffffff00816a290(undefined8 param_1,undefined8 param_2,long param_3,uint param_4)

{
  bool bVar1;
  long *plVar2;
  long *plVar3;
  long lVar4;
  
  plVar2 = (long *)thunk_EXT_FUN_8011000003976f54(param_2,0x1000,1);
  if (plVar2 == (long *)0x0) {
    bVar1 = false;
  }
  else {
    plVar3 = (long *)thunk_EXT_FUN_801100000396cb64
                               (plVar2,*(undefined8 *)PTR_DAT_fffffff007ca61d0,0,0x1101,0,0);
    if (plVar3 == (long *)0x0) {
      bVar1 = false;
    }
    else {
      lVar4 = (**(code **)(*plVar3 + 0x78))();
      bVar1 = (*(uint *)(lVar4 + param_3) & param_4) != 0;
      (**(code **)(*plVar3 + 0x28))(plVar3);
    }
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  return bVar1;
}

