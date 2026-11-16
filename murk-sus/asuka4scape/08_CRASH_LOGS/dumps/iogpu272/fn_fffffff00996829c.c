// FUN_fffffff00996829c @ fffffff00996829c size=296

void FUN_fffffff00996829c(long param_1,long *param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  ulong unaff_x30;
  
  if (DAT_fffffff00af227e8 != 0) {
    lVar3 = param_2[0x20];
    uVar2 = thunk_EXT_FUN_801100000390ebc0(*(undefined8 *)(param_1 + 0x48));
    thunk_EXT_FUN_80110000036da494(0x851801b5,lVar3,uVar2,0,0,0);
  }
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0xe0));
  (**(code **)(*param_2 + 0x20))(param_2);
  param_2[0x28] = 0;
  **(long **)(param_1 + 0xf0) = (long)param_2;
  *(long **)(param_1 + 0xf0) = param_2 + 0x28;
  if (*(int *)(param_1 + 0xf8) != 0) {
    thunk_EXT_FUN_80110000038ff08c(*(undefined8 *)(param_1 + 0xe0),param_1,1);
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0xe0));
  if (DAT_fffffff00af227e8 != 0) {
    lVar3 = param_2[0x20];
    uVar2 = thunk_EXT_FUN_801100000390ebc0(*(undefined8 *)(param_1 + 0x48));
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0099683ac);
      (*pcVar1)();
    }
    thunk_EXT_FUN_80110000036da494(0x851801b6,lVar3,uVar2,0,0,0);
    return;
  }
  return;
}

