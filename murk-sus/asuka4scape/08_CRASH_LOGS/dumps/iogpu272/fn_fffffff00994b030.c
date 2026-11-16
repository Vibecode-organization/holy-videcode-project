// FUN_fffffff00994b030 @ fffffff00994b030 size=128

void FUN_fffffff00994b030(long param_1,int param_2)

{
  long lVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  code *pcVar5;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000038ff214(*(undefined8 *)(param_1 + 0x840));
  iVar4 = *(int *)(param_1 + 0x1448);
  lVar1 = (long)param_2 * 0x18 + 0x10;
  piVar2 = (int *)(param_1 + 0x848 + (long)(int)lVar1);
  if (lVar1 != (int)lVar1) {
    piVar2 = (int *)(param_1 + 0x848 + lVar1 & 0xffffffffffffU | 0x2bad000000000000);
  }
  *piVar2 = iVar4;
  iVar3 = 0;
  if (iVar4 != -2) {
    iVar3 = iVar4 + 1;
  }
  *(int *)(param_1 + 0x1448) = iVar3;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00994b0ac);
    (*pcVar5)();
  }
  thunk_EXT_FUN_80110000038ff2e0(*(undefined8 *)(param_1 + 0x840));
  return;
}

