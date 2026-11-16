// FUN_fffffff008c280bc @ fffffff008c280bc size=4 depth=0
// CALLERS:
//   fffffff00afd02e1 ?
//   fffffff007e10658 ?
// CALLS:

ulong FUN_fffffff008c280bc(void)

{
  code *pcVar1;
  long lVar2;
  ulong uVar3;
  long extraout_x16;
  long unaff_x19;
  ulong unaff_x20;
  ulong unaff_x30;
  
  FUN_fffffff008c24d0c();
  FUN_fffffff008c24cb4(0x127);
  lVar2 = FUN_fffffff008c24d84();
  if (lVar2 != 0) {
    if (((*(long *)(unaff_x19 + 0x40) != 0) || (*(uint *)(unaff_x19 + 0x38) == 0)) ||
       (FUN_fffffff008c24d20((ulong)*(uint *)(unaff_x19 + 0x38)),
       *(uint *)(unaff_x19 + 0x38) < 0xc4c)) {
      FUN_fffffff008c24d60();
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff008c28170);
        (*pcVar1)();
      }
                    /* WARNING: Could not recover jumptable at 0xfffffff008c28178. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
      uVar3 = (**(code **)(extraout_x16 + 0x608))(lVar2);
      return uVar3;
    }
    unaff_x20 = (ulong)((int)unaff_x20 + 0x2c);
  }
  return unaff_x20;
}

