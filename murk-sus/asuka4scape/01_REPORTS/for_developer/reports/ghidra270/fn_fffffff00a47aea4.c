// FUN_fffffff00a47aea4 @ fffffff00a47aea4 size=512

void FUN_fffffff00a47aea4(undefined8 param_1,long param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 uStack_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  long local_38;
  
  local_38 = DAT_fffffff00acf0000;
  uStack_58 = 0;
  local_60 = 0;
  uStack_48 = 0;
  uStack_50 = 0;
  uStack_78 = 0;
  local_80 = 0;
  uStack_68 = 0;
  uStack_70 = 0;
  uStack_98 = 0;
  local_a0 = 0;
  uStack_88 = 0;
  uStack_90 = 0;
  uStack_b8 = 0;
  local_c0 = 0;
  uStack_a8 = 0;
  uStack_b0 = 0;
  if (param_2 == 0) {
    FUN_fffffff00a89f3b0(&MACH_HEADER,DAT_fffffff00ad55348,0,&DAT_fffffff0070c8b67);
    goto LAB_fffffff00a47b070;
  }
  if ((*(ushort *)(param_2 + 2) & 1) == 0) {
    if ((*(ushort *)(param_2 + 2) >> 1 & 1) != 0) {
      if ((param_2 + 0x30U <= param_2 + 0x20U) ||
         (FUN_fffffff00a89d5dc(0x1e,param_2 + 0x20U,&local_80,0x40),
         param_2 + 0x40U <= param_2 + 0x30U)) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x5519,0xfffffff00a47b0a4);
        (*pcVar1)();
      }
      uVar2 = 0x1e;
      goto LAB_fffffff00a47af7c;
    }
  }
  else {
    FUN_fffffff00a89d5dc(2,param_2 + 0x20,&local_80,0x40);
    uVar2 = 2;
LAB_fffffff00a47af7c:
    FUN_fffffff00a89d5dc(uVar2,param_2 + 0x30,&local_c0,0x40);
  }
  FUN_fffffff00a89f3b0
            (&MACH_HEADER,DAT_fffffff00ad55348,0,
             "%s net_port_info if_index %u arch %s family %s proto %s local %s:%u foreign %s:%u pid: %u epid %u"
            );
LAB_fffffff00a47b070:
  if (DAT_fffffff00acf0000 == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_fffffff00aa0b974();
}

