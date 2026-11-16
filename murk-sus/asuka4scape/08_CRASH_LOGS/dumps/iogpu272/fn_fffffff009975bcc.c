// FUN_fffffff009975bcc @ fffffff009975bcc size=104

void FUN_fffffff009975bcc(long param_1)

{
  int iVar1;
  code *pcVar2;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x2c0));
  iVar1 = *(int *)(param_1 + 0xd8) + -1;
  *(int *)(param_1 + 0xd8) = iVar1;
  if ((iVar1 == 0) && (*(char *)(param_1 + 0x1e0) < '\0')) {
    thunk_EXT_FUN_80110000038ff08c(*(undefined8 *)(param_1 + 0x2c0),param_1,0);
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009975c30);
    (*pcVar2)();
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x2c0));
  return;
}

