// FUN_fffffff00a4b8148 @ fffffff00a4b8148 size=524

void FUN_fffffff00a4b8148(undefined8 param_1,long param_2)

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
  
  local_38 = DAT_fffffff00ad30000;
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
    FUN_fffffff00a8df19c(&MACH_HEADER,DAT_fffffff00ad95428,0,&DAT_fffffff0070c9368);
    goto LAB_fffffff00a4b8320;
  }
  if ((*(ushort *)(param_2 + 2) & 3) == 1) {
    FUN_fffffff00a8dd3c8(2,param_2 + 0x20,&local_80,0x40);
    uVar2 = 2;
LAB_fffffff00a4b8228:
    FUN_fffffff00a8dd3c8(uVar2,param_2 + 0x30,&local_c0,0x40);
  }
  else if ((*(ushort *)(param_2 + 2) >> 1 & 1) != 0) {
    if ((param_2 + 0x30U <= param_2 + 0x20U) ||
       (FUN_fffffff00a8dd3c8(0x1e,param_2 + 0x20U,&local_80,0x40),
       param_2 + 0x40U <= param_2 + 0x30U)) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x5519,0xfffffff00a4b8354);
      (*pcVar1)();
    }
    uVar2 = 0x1e;
    goto LAB_fffffff00a4b8228;
  }
  FUN_fffffff00a8df19c
            (&MACH_HEADER,DAT_fffffff00ad95428,0,
             "%s net_port_info if_index %u arch %s family %s proto %s local %s:%u foreign %s:%u pid: %u epid %u"
            );
LAB_fffffff00a4b8320:
  if (DAT_fffffff00ad30000 == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_fffffff00aa4c590();
}

