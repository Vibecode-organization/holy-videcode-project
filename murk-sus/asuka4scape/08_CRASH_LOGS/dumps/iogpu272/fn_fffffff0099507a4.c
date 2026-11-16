// FUN_fffffff0099507a4 @ fffffff0099507a4 size=180

uint FUN_fffffff0099507a4(long param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  undefined8 uVar2;
  undefined8 local_38;
  
  local_38 = 0;
  thunk_EXT_FUN_8011000003204ed8
            (*(undefined4 *)(*(long *)(param_1 + 0x10) + 700),1000000000,&local_38);
  uVar2 = thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x20));
  do {
    uVar1 = FUN_fffffff009950738(uVar2,param_2,param_3);
    if (uVar1 == 0) break;
    *(int *)(param_1 + 0x74) = *(int *)(param_1 + 0x74) + 1;
    uVar2 = thunk_EXT_FUN_80110000038ff078(*(undefined8 *)(param_1 + 0x20),param_1,local_38,0);
    *(int *)(param_1 + 0x74) = *(int *)(param_1 + 0x74) + -1;
  } while ((int)uVar2 != 1);
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x20));
  return uVar1 ^ 1;
}

