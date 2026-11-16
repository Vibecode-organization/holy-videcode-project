// FUN_fffffff00995f744 @ fffffff00995f744 size=364

void FUN_fffffff00995f744(long *param_1)

{
  ulong uVar1;
  ulong uVar2;
  code *pcVar3;
  long lVar4;
  long lVar5;
  undefined8 uVar6;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(param_1[0x18]);
  *(undefined4 *)(param_1 + 0x11) = 0;
  thunk_EXT_FUN_8011000003222de0(param_1[0x18]);
  FUN_fffffff009961f20(param_1);
  lVar4 = FUN_fffffff009974f6c(param_1[0x35],0);
  lVar5 = FUN_fffffff009974f6c(param_1[0x35],1);
  uVar1 = lVar5 + lVar4;
  if (DAT_fffffff00af227e8 != 0) {
    uVar6 = thunk_EXT_FUN_801100000390ebc0(param_1[0x35]);
    thunk_EXT_FUN_80110000036da494(0x85180021,uVar6,uVar1,0,0,0);
  }
  uVar2 = param_1[0x15];
  if (DAT_fffffff00af227b8 != 0) {
    uVar2 = (ulong)DAT_fffffff00af227b8 << 0x14;
  }
  if ((uVar2 < uVar1) && (*(uint *)((long)param_1 + 0x74) <= *(uint *)(param_1 + 0xe))) {
    (**(code **)(*param_1 + 0x78))(param_1);
  }
  lVar4 = FUN_fffffff009974f6c(param_1[0x35],0);
  lVar5 = FUN_fffffff009974f6c(param_1[0x35],1);
  if (DAT_fffffff00af227e8 != 0) {
    uVar6 = thunk_EXT_FUN_801100000390ebc0(param_1[0x35]);
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00995f898);
      (*pcVar3)();
    }
    thunk_EXT_FUN_80110000036da494(0x85180022,uVar6,lVar5 + lVar4,uVar1 - (lVar5 + lVar4),0,0);
    return;
  }
  return;
}

