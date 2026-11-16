// FUN_fffffff00997a9b4 @ fffffff00997a9b4 size=4

void FUN_fffffff00997a9b4(long param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  long *plVar2;
  ulong unaff_x30;
  
  plVar2 = (long *)FUN_fffffff00994f734(param_2,param_3,*(undefined8 *)(param_1 + 0x530),param_1);
  if (plVar2 == (long *)0x0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
               "%s: Failed to allocate shared event fence\n");
    *(undefined4 *)(param_1 + 0x520) = 8;
    return;
  }
  FUN_fffffff00994c6ac
            (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),param_1 + 0x4d8,param_1 + 0x498);
  FUN_fffffff00994c49c
            (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),param_1 + 0x498,plVar2 + 0xe);
  FUN_fffffff009950614(*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x158),param_1,plVar2);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00997aa68);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff00997aa70. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*plVar2 + 0x28))(plVar2,(undefined8 *)(*plVar2 + 0x28));
  return;
}

