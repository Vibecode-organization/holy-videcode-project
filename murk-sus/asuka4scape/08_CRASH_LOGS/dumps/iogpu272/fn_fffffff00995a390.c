// FUN_fffffff00995a390 @ fffffff00995a390 size=284

void FUN_fffffff00995a390(long param_1,undefined8 param_2,long param_3,int param_4)

{
  code *pcVar1;
  int iVar2;
  ulong unaff_x30;
  undefined8 local_30;
  undefined1 *puStack_28;
  
  if ((int)param_2 - 1U < 2) {
    *(int *)(param_1 + 0x58) = (int)param_2;
  }
  if (param_3 != 0) {
    FUN_fffffff00995a318(*(undefined8 *)(param_1 + 0x50),param_3,param_2);
  }
  LOAcquire();
  iVar2 = *(int *)(param_1 + 0x30);
  *(int *)(param_1 + 0x30) = iVar2 + 1;
  LORelease();
  iVar2 = iVar2 + 1;
  if (iVar2 == *(int *)(param_1 + 0x28)) {
    iVar2 = *(int *)(param_1 + 0x58);
    if (iVar2 == 0) {
      iVar2 = 3;
      *(undefined4 *)(param_1 + 0x58) = 3;
    }
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00995a434);
      (*pcVar1)();
    }
    FUN_fffffff0099596f0
              (*(undefined8 *)(param_1 + 0x50),*(undefined8 *)(param_1 + 0x20),iVar2,
               *(undefined8 *)(param_1 + 0x38),*(byte *)(param_1 + 0x5e) & 1);
    return;
  }
  if ((param_4 == 0) || (iVar2 != *(int *)(param_1 + 0x34))) {
    if (*(int *)(param_1 + 0x2c) == iVar2) {
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00995a498);
        (*pcVar1)();
      }
      FUN_fffffff00995a4ac(*(undefined8 *)(param_1 + 0x50));
      return;
    }
  }
  else {
    local_30 = 0;
    puStack_28 = (undefined1 *)&local_30;
    FUN_fffffff009959e20(param_1,&local_30);
    FUN_fffffff00995a4ac(*(undefined8 *)(param_1 + 0x50));
  }
  return;
}

