// FUN_fffffff0081ff974 @ fffffff0081ff974 size=144

void FUN_fffffff0081ff974(long param_1,int param_2)

{
  int iVar1;
  ulong *puVar2;
  long lVar3;
  code *pcVar4;
  ulong unaff_x30;
  
  iVar1 = param_2 + 0x3f;
  if (-1 < param_2) {
    iVar1 = param_2;
  }
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x1b0));
  lVar3 = (ulong)(uint)(iVar1 >> 6) * 8;
  puVar2 = (ulong *)(param_1 + 0x1a0 + (long)(int)lVar3);
  if (lVar3 != (int)lVar3) {
    puVar2 = (ulong *)(param_1 + 0x1a0 + lVar3 & 0xffffffffffffU | 0x2bad000000000000);
  }
  *puVar2 = *puVar2 & (1L << ((ulong)(uint)(param_2 % 0x40) & 0x3f) ^ 0xffffffffffffffffU);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081ffa00);
    (*pcVar4)();
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x1b0));
  return;
}

