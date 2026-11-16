// FUN_fffffff00818ddd4 @ fffffff00818ddd4 size=252

void FUN_fffffff00818ddd4(long param_1,undefined8 param_2)

{
  code *pcVar1;
  long lVar2;
  ulong unaff_x30;
  
  FUN_fffffff00818add4(*(undefined8 *)(*(long *)(param_1 + 0x610) + 0xa8),0x100,param_2,0,0);
  lVar2 = *(long *)(param_1 + 0x530);
  if ((*(byte *)(lVar2 + 0x1ac45) & 1) != 0) {
    FUN_fffffff0081a0304(*(undefined8 *)(lVar2 + 0x148),0x80b,param_1 + 0x4d8,0);
    lVar2 = *(long *)(param_1 + 0x530);
  }
  thunk_EXT_FUN_80110000029486ac(*(undefined8 *)(lVar2 + 0x148),param_1 + 0x4d8,param_2);
  thunk_EXT_FUN_80110000029486ac
            (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),param_1 + 0x5d0,param_2);
  if ((*(byte *)(*(long *)(param_1 + 0x530) + 0x1ac45) & 1) != 0) {
    FUN_fffffff0081a0304
              (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),0x81b,param_1 + 0x5d0,0);
    if ((*(byte *)(*(long *)(param_1 + 0x530) + 0x1ac45) & 1) != 0) {
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00818decc);
        (*pcVar1)();
      }
      FUN_fffffff0081a0304(*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),0x806,param_2,0);
      return;
    }
  }
  return;
}

