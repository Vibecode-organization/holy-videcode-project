// FUN_fffffff00a37a0ac @ fffffff00a37a0ac size=308

void FUN_fffffff00a37a0ac(long *param_1)

{
  long lVar1;
  int iVar2;
  long extraout_x1;
  undefined8 local_40;
  undefined4 local_38;
  undefined4 local_34;
  
  if (param_1[0x18] == 0) {
    local_40 = 0;
    iVar2 = FUN_fffffff00a2a03fc(DAT_fffffff007c5b790,0x4000,0,0x8080,0x1c,0);
    if (iVar2 == 0) {
      local_34 = 3;
      local_38 = 3;
      iVar2 = FUN_fffffff00a2ac7fc
                        (*(undefined8 *)(*param_1 + 0x10),&local_40,0x4000,0,0x1c100008,
                         DAT_fffffff007c5b790,extraout_x1,0,&local_34,&local_38,2);
      if (iVar2 == 0) {
        lVar1 = tpidr_el1;
        *(int *)(lVar1 + 0x1c0) = *(int *)(lVar1 + 0x1c0) + 1;
        param_1[0x18] = extraout_x1;
        *(undefined8 *)(param_1[0x16] + 0x4158) = local_40;
        *(ulong *)(param_1[0x16] + 0x4120) = *(ulong *)(param_1[0x16] + 0x4120) | 0x40000000000000;
        if (*(int *)(lVar1 + 0x1c0) == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff00aa1ba9c();
        }
        iVar2 = *(int *)(lVar1 + 0x1c0) + -1;
        *(int *)(lVar1 + 0x1c0) = iVar2;
        if ((iVar2 == 0) && ((*(byte *)(*(long *)(lVar1 + 0x1b8) + 0x4c) >> 2 & 1) != 0)) {
          FUN_fffffff00a35a8b0();
        }
      }
      else {
        FUN_fffffff00a2a279c(DAT_fffffff007c5b790,extraout_x1,0x4000,0,0);
      }
    }
  }
  *(undefined1 *)(param_1 + 0x17) = 1;
  return;
}

