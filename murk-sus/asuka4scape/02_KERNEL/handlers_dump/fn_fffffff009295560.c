// FUN_fffffff009295560 @ fffffff009295560 size=4 depth=0
// CALLERS:
//   fffffff00afdd62a ?
//   fffffff007f053f8 ?
// CALLS:

undefined8 FUN_fffffff009295560(undefined8 param_1,long *param_2,long param_3)

{
  code *pcVar1;
  long *plVar2;
  char *pcVar3;
  undefined8 uVar4;
  ulong unaff_x30;
  
  plVar2 = thunk_FUN_fffffff00a894f30(param_2,-0xff511ecd0);
  if (plVar2 == (long *)0x0) {
    pcVar3 = "AppleGasGaugeBeadsUpdateUserClient ERROR: no self\n";
  }
  else if (*(long *)(param_3 + 0x58) == 0) {
    pcVar3 = "AppleGasGaugeBeadsUpdateUserClient ERROR: no output buffer for getStatus\n";
  }
  else {
    if (1 < *(uint *)(param_3 + 0x60)) {
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00929561c);
        (*pcVar1)();
      }
      uVar4 = FUN_fffffff00928c0c0(plVar2[0x1b],*(long *)(param_3 + 0x58));
      return uVar4;
    }
    pcVar3 = 
    "AppleGasGaugeBeadsUpdateUserClient ERROR: output buffer too small for getStatus: %u < %zu\n";
  }
  thunk_FUN_fffffff00a9029a0((byte *)pcVar3);
  return 0xe00002c2;
}

