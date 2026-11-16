// FUN_fffffff0094c84c4 @ fffffff0094c84c4 size=188
// CALLERS:
//   fffffff00afb80cd ?
//   fffffff0094c8460 FUN_fffffff0094c82cc@fffffff0094c82cc
//   fffffff0094c886c FUN_fffffff0094c8638@fffffff0094c8638
//   fffffff0094c8a08 FUN_fffffff0094c8638@fffffff0094c8638
// CALLS:
//   fffffff0094c519c FUN_fffffff0094c519c

ulong FUN_fffffff0094c84c4(undefined8 param_1,int param_2)

{
  byte *pbVar1;
  code *pcVar2;
  int iVar3;
  ulong uVar4;
  ulong uVar5;
  ulong *puVar6;
  
  pbVar1 = &DAT_fffffff0077705ca;
  if (param_2 == 0) {
    pbVar1 = &DAT_fffffff0077705c9;
  }
  uVar5 = (ulong)*pbVar1;
  if (*pbVar1 != 0) {
    puVar6 = &DAT_fffffff007f5aa70;
    do {
      if ((puVar6 < &DAT_fffffff007f5aa70 || &DAT_fffffff007f5abb0 < puVar6 + 1) ||
          puVar6 + 1 < puVar6) {
LAB_fffffff0094c857c:
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x5519,0xfffffff0094c8580);
        (*pcVar2)();
      }
      uVar4 = *puVar6;
      if (uVar4 + 200 < uVar4 + 0xb8) goto LAB_fffffff0094c857c;
      iVar3 = FUN_fffffff0094c519c(param_1);
      if (iVar3 == 0) {
        if (uVar4 <= uVar4 + 0x130) {
          return uVar4;
        }
        goto LAB_fffffff0094c857c;
      }
      uVar5 = uVar5 - 1;
      puVar6 = puVar6 + 1;
    } while (uVar5 != 0);
  }
  return 0;
}

