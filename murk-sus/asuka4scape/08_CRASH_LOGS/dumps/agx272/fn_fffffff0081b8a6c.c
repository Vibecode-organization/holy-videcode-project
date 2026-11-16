// FUN_fffffff0081b8a6c @ fffffff0081b8a6c size=164

void FUN_fffffff0081b8a6c(long param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  long lVar4;
  long lVar5;
  ulong unaff_x30;
  
  *(int *)(param_1 + 0x18ec) = param_2;
  iVar1 = param_2;
  if (*(int *)(param_1 + 0x1900) != 0) {
    iVar1 = *(int *)(param_1 + 0x1900);
  }
  lVar4 = *(long *)(param_1 + 0x348);
  *(int *)(lVar4 + 0xe4) = iVar1;
  lVar5 = *(long *)(param_1 + 0x280);
  if ((*(byte *)(lVar5 + 0x1ac44) >> 2 & 1) == 0) {
    return;
  }
  uVar2 = *(undefined4 *)(lVar4 + 0xe4);
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar5 + 0x1ac48));
  thunk_EXT_FUN_80110000036da494(0x85920870,uVar2,param_2,0,0,0);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081b8b0c);
    (*pcVar3)();
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar5 + 0x1ac48));
  return;
}

