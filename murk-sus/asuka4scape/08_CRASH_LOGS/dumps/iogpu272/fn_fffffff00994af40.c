// FUN_fffffff00994af40 @ fffffff00994af40 size=140

void FUN_fffffff00994af40(long param_1,undefined8 param_2)

{
  uint uVar1;
  uint *puVar2;
  code *pcVar3;
  ulong uVar4;
  ulong unaff_x30;
  
  uVar4 = (long)(int)param_2 << 4 | 8;
  puVar2 = (uint *)(param_1 + 0x40 + (long)(int)uVar4);
  if (uVar4 != (long)(int)uVar4) {
    puVar2 = (uint *)(param_1 + 0x40 + uVar4 & 0xffffffffffff | 0x2bad000000000000);
  }
  uVar1 = *puVar2 + 0x100;
  if ((uVar1 ^ *puVar2) >> 0x1e != 0) {
    FUN_fffffff009975568(*(undefined8 *)(param_1 + 0x10));
  }
  *puVar2 = uVar1;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00994afc8);
    (*pcVar3)();
  }
  FUN_fffffff00994b030(param_1,param_2);
  return;
}

