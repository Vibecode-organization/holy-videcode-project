// FUN_fffffff008213830 @ fffffff008213830 size=128

void FUN_fffffff008213830(undefined8 *param_1)

{
  code *pcVar1;
  long *plVar2;
  ulong unaff_x30;
  
  *param_1 = &DAT_fffffff007ca0370;
  plVar2 = (long *)param_1[0x3a];
  if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  param_1[0x3a] = 0;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0082138ac);
    (*pcVar1)();
  }
  thunk_EXT_FUN_80110000029583b8();
  return;
}

