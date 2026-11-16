// FUN_fffffff0094c8580 @ fffffff0094c8580 size=172
// CALLERS:
//   fffffff00afb80cf ?
//   fffffff0094c848c FUN_fffffff0094c82cc@fffffff0094c82cc
//   fffffff0094c8890 FUN_fffffff0094c8638@fffffff0094c8638
// CALLS:
//   fffffff0094c519c FUN_fffffff0094c519c

ulong FUN_fffffff0094c8580(undefined8 param_1)

{
  code *pcVar1;
  int iVar2;
  ulong uVar3;
  ulong uVar4;
  ulong *puVar5;
  
  uVar4 = (ulong)DAT_fffffff00777164a;
  if (uVar4 != 0) {
    puVar5 = &DAT_fffffff007f5b8b8;
    do {
      if ((puVar5 < &DAT_fffffff007f5b8b8 || &DAT_fffffff007f5b8d0 < puVar5 + 1) ||
          puVar5 + 1 < puVar5) {
LAB_fffffff0094c8628:
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x5519,0xfffffff0094c862c);
        (*pcVar1)();
      }
      uVar3 = *puVar5;
      if (uVar3 + 200 < uVar3 + 0xb8) goto LAB_fffffff0094c8628;
      iVar2 = FUN_fffffff0094c519c(param_1);
      if (iVar2 == 0) {
        if (uVar3 <= uVar3 + 0x130) {
          return uVar3;
        }
        goto LAB_fffffff0094c8628;
      }
      uVar4 = uVar4 - 1;
      puVar5 = puVar5 + 1;
    } while (uVar4 != 0);
  }
  return 0;
}

