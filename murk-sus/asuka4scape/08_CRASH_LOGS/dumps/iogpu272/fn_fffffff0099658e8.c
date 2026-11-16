// FUN_fffffff0099658e8 @ fffffff0099658e8 size=96

undefined8 FUN_fffffff0099658e8(undefined8 param_1)

{
  code *pcVar1;
  ulong uVar2;
  undefined8 uVar3;
  ulong unaff_x30;
  
  uVar2 = FUN_fffffff009964e38(param_1,"com.apple.private.gpu-restricted");
  if ((uVar2 & 1) != 0) {
    return 1;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009965944);
    (*pcVar1)();
  }
  uVar3 = FUN_fffffff009964e38(param_1,"com.apple.developer.gpu-restricted");
  return uVar3;
}

