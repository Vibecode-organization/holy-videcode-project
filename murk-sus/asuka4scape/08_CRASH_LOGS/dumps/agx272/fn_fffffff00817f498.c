// FUN_fffffff00817f498 @ fffffff00817f498 size=308

void FUN_fffffff00817f498(long param_1,undefined8 param_2,uint param_3,int param_4)

{
  int iVar1;
  bool bVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  ulong unaff_x30;
  
  iVar4 = (int)param_2;
  iVar5 = 0;
  if (param_3 != 0 || iVar4 != 0) {
    iVar5 = param_4;
  }
  iVar1 = *(int *)(param_1 + 0x109fc);
  if (((iVar1 == iVar4) && (param_3 == (*(byte *)(param_1 + 0x11181) & 1))) &&
     (*(int *)(param_1 + 0x11184) == iVar5)) {
    return;
  }
  if (iVar1 == 0) {
    if (iVar4 != 0) goto LAB_fffffff00817f514;
LAB_fffffff00817f530:
    bVar2 = false;
  }
  else {
    if (iVar4 == 0) {
      iVar5 = 0;
      param_3 = 1;
    }
    else {
LAB_fffffff00817f514:
      if ((param_3 == (*(byte *)(param_1 + 0x11181) & 1)) && (*(int *)(param_1 + 0x11184) == iVar5))
      goto LAB_fffffff00817f530;
    }
    thunk_EXT_FUN_801100000295c3cc(*(undefined8 *)(param_1 + 0x160));
    thunk_EXT_FUN_80110000029476b0(*(undefined8 *)(param_1 + 0x148));
    *(bool *)(param_1 + 0x11181) = param_3 != 0;
    *(int *)(param_1 + 0x11184) = iVar5;
    bVar2 = true;
  }
  (**(code **)(**(long **)(param_1 + 0x4b0) + 0x2c8))(*(long **)(param_1 + 0x4b0),param_2);
  *(int *)(param_1 + 0x109fc) = iVar4;
  if (!bVar2) {
    return;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
    thunk_EXT_FUN_801100000295c4b0(*(undefined8 *)(param_1 + 0x160));
    return;
  }
                    /* WARNING: Does not return */
  pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00817f5b4);
  (*pcVar3)();
}

