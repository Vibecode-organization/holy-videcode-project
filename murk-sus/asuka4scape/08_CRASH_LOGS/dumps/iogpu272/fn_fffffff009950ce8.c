// FUN_fffffff009950ce8 @ fffffff009950ce8 size=252

void FUN_fffffff009950ce8(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  long local_38;
  
  if ((int)param_2 == 0) {
    lVar2 = 0;
  }
  else {
    local_38 = 0;
    thunk_EXT_FUN_80110000033982c4(param_2,1000000000,&local_38);
    lVar2 = thunk_EXT_FUN_8011000003397c88();
    lVar2 = lVar2 - local_38;
  }
  if ((int)param_3 == 0) {
    lVar3 = 0;
  }
  else {
    local_38 = 0;
    thunk_EXT_FUN_80110000033982c4(param_3,1000000000,&local_38);
    lVar3 = thunk_EXT_FUN_8011000003397c88();
    lVar3 = lVar3 - local_38;
  }
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x20));
  if (*(int *)(param_1 + 0x70) != 0) {
    lVar1 = *(long *)(param_1 + 0x40);
    while (lVar1 != 0) {
      lVar4 = *(long *)(lVar1 + 0x470);
      FUN_fffffff009950c20(param_1,lVar1 + 0x460,lVar2,lVar3);
      lVar1 = lVar4;
    }
    FUN_fffffff009950c20(param_1,param_1 + 0x50,lVar2,lVar3);
    FUN_fffffff009950c20(param_1,param_1 + 0x60,lVar2,lVar3);
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x20));
  return;
}

