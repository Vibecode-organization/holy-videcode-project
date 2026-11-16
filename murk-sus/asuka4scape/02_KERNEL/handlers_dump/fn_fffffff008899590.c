// FUN_fffffff008899590 @ fffffff008899590 size=4 depth=0
// CALLERS:
//   fffffff00afca920 ?
//   fffffff007d96798 ?
// CALLS:

ulong FUN_fffffff008899590(long param_1,undefined8 param_2,long param_3)

{
  undefined1 auVar1 [16];
  int iVar2;
  uint uVar3;
  long *plVar4;
  undefined8 *puVar5;
  char *pcVar6;
  ulong uVar7;
  undefined8 extraout_d0;
  undefined8 extraout_var;
  undefined1 in_q1 [16];
  undefined1 in_q2 [16];
  undefined1 in_q3 [16];
  undefined4 in_s4;
  undefined4 in_s5;
  byte bStack_91;
  char acStack_90 [72];
  long lStack_48;
  
  lStack_48 = *(long *)PTR_DAT_fffffff007d96f20;
  bStack_91 = 0;
  if ((param_1 == 0) || (param_3 == 0)) {
    uVar7 = 0xe00002c2;
    if (DAT_fffffff00ae3add0 == 0) goto LAB_fffffff008899744;
    pcVar6 = "TouchEEPROMDriver::%s: Null pointer: target = %p reference = %p arguments = %p\n";
LAB_fffffff008899688:
    uVar7 = 0xe00002c2;
    thunk_FUN_fffffff00a9029a0((byte *)pcVar6);
    goto LAB_fffffff008899744;
  }
  acStack_90[0x28] = '\0';
  acStack_90[0x29] = '\0';
  acStack_90[0x2a] = '\0';
  acStack_90[0x2b] = '\0';
  acStack_90[0x2c] = '\0';
  acStack_90[0x2d] = '\0';
  acStack_90[0x2e] = '\0';
  acStack_90[0x2f] = '\0';
  acStack_90[0x20] = '\0';
  acStack_90[0x21] = '\0';
  acStack_90[0x22] = '\0';
  acStack_90[0x23] = '\0';
  acStack_90[0x24] = '\0';
  acStack_90[0x25] = '\0';
  acStack_90[0x26] = '\0';
  acStack_90[0x27] = '\0';
  acStack_90[0x38] = '\0';
  acStack_90[0x39] = '\0';
  acStack_90[0x3a] = '\0';
  acStack_90[0x3b] = '\0';
  acStack_90[0x3c] = '\0';
  acStack_90[0x3d] = '\0';
  acStack_90[0x3e] = '\0';
  acStack_90[0x3f] = '\0';
  acStack_90[0x30] = '\0';
  acStack_90[0x31] = '\0';
  acStack_90[0x32] = '\0';
  acStack_90[0x33] = '\0';
  acStack_90[0x34] = '\0';
  acStack_90[0x35] = '\0';
  acStack_90[0x36] = '\0';
  acStack_90[0x37] = '\0';
  acStack_90[8] = '\0';
  acStack_90[9] = '\0';
  acStack_90[10] = '\0';
  acStack_90[0xb] = '\0';
  acStack_90[0xc] = '\0';
  acStack_90[0xd] = '\0';
  acStack_90[0xe] = '\0';
  acStack_90[0xf] = '\0';
  acStack_90[0] = '\0';
  acStack_90[1] = '\0';
  acStack_90[2] = '\0';
  acStack_90[3] = '\0';
  acStack_90[4] = '\0';
  acStack_90[5] = '\0';
  acStack_90[6] = '\0';
  acStack_90[7] = '\0';
  acStack_90[0x18] = '\0';
  acStack_90[0x19] = '\0';
  acStack_90[0x1a] = '\0';
  acStack_90[0x1b] = '\0';
  acStack_90[0x1c] = '\0';
  acStack_90[0x1d] = '\0';
  acStack_90[0x1e] = '\0';
  acStack_90[0x1f] = '\0';
  acStack_90[0x10] = '\0';
  acStack_90[0x11] = '\0';
  acStack_90[0x12] = '\0';
  acStack_90[0x13] = '\0';
  acStack_90[0x14] = '\0';
  acStack_90[0x15] = '\0';
  acStack_90[0x16] = '\0';
  acStack_90[0x17] = '\0';
  plVar4 = *(long **)(param_3 + 0x40);
  if (plVar4 == (long *)0x0) {
    plVar4 = (long *)0x0;
    puVar5 = *(undefined8 **)(param_3 + 0x30);
    iVar2 = *(int *)(param_3 + 0x38);
    if (puVar5 == (undefined8 *)0x0) goto LAB_fffffff0088996ec;
LAB_fffffff0088996a0:
    if (iVar2 - 0x40U < 0xffffffc1) goto LAB_fffffff0088996ec;
    thunk_FUN_fffffff00a354958((undefined8 *)acStack_90,puVar5,0x40);
    auVar1._8_8_ = extraout_var;
    auVar1._0_8_ = extraout_d0;
    uVar3 = FUN_fffffff00889bb9c(auVar1,in_q1,in_q2,in_q3,in_s4,in_s5,param_1,acStack_90,&bStack_91)
    ;
    uVar7 = (ulong)uVar3;
    if (uVar3 == 0) {
      **(ulong **)(param_3 + 0x48) = (ulong)bStack_91;
      *(undefined4 *)(param_3 + 0x50) = 1;
    }
  }
  else {
    plVar4 = (long *)(**(code **)(*plVar4 + 0xe8))(plVar4,0x1000);
    if (plVar4 == (long *)0x0) {
      uVar7 = 0xe00002c2;
      if (DAT_fffffff00ae3add0 == 0) goto LAB_fffffff008899744;
      pcVar6 = "TouchEEPROMDriver::%s: map is null.\n";
      goto LAB_fffffff008899688;
    }
    puVar5 = (undefined8 *)(**(code **)(*plVar4 + 0x78))();
    iVar2 = (**(code **)(**(long **)(param_3 + 0x40) + 0xb0))();
    if (puVar5 != (undefined8 *)0x0) goto LAB_fffffff0088996a0;
LAB_fffffff0088996ec:
    uVar7 = 0xe00002c2;
    if (DAT_fffffff00ae3add0 != 0) {
      thunk_FUN_fffffff00a9029a0
                ((byte *)
                 "TouchEEPROMDriver::%s: Invalid EEPROM device name: deviceName = %p, length = %u\n"
                );
    }
  }
  if (plVar4 != (long *)0x0) {
    (**(code **)(*plVar4 + 0x28))(plVar4);
  }
LAB_fffffff008899744:
  if (*(long *)PTR_DAT_fffffff007d96f20 != lStack_48) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_fffffff00aa4c590();
  }
  return uVar7;
}

