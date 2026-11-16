// FUN_fffffff0081fbd44 @ fffffff0081fbd44 size=164

undefined8 FUN_fffffff0081fbd44(long param_1,undefined8 param_2,ulong param_3)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  ulong unaff_x30;
  
  if (((*(byte *)(param_1 + 0x2f0) & 1) == 0) ||
     (iVar2 = FUN_fffffff0081fbde8(param_1,param_2,param_3), iVar2 != 0)) {
    if ((((param_3 & 1) != 0) || ((*(byte *)(param_1 + 0x1d8) & 1) != 0)) ||
       (*(long *)(param_1 + 0x28) == *(long *)PTR_DAT_fffffff007ca61d0)) {
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081fbdc8);
        (*pcVar1)();
      }
      uVar3 = FUN_fffffff0081fbfb4(param_1,param_2);
      return uVar3;
    }
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}

