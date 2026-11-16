// FUN_fffffff00994c110 @ fffffff00994c110 size=152

void FUN_fffffff00994c110(undefined8 param_1,undefined8 param_2,long param_3,int param_4)

{
  code *pcVar1;
  int iVar2;
  ulong unaff_x30;
  undefined1 auStack_34 [4];
  
  do {
    FUN_fffffff00994bcd8(param_1,param_3,auStack_34);
    iVar2 = FUN_fffffff00994c02c(param_1,param_2,param_3);
  } while (iVar2 == 0);
  if (param_4 != 0) {
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00994c190);
      (*pcVar1)();
    }
    FUN_fffffff00994c1a8(param_1,param_2,param_3 + 0x40);
    return;
  }
  return;
}

