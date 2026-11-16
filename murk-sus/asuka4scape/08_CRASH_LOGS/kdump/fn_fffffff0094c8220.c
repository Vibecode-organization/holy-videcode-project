// FUN_fffffff0094c8220 @ fffffff0094c8220 size=108
// CALLERS:
//   fffffff00afb80c9 ?
//   fffffff0094c8380 FUN_fffffff0094c82cc@fffffff0094c82cc
//   fffffff0094c05cc FUN_fffffff0094c03ec@fffffff0094c03ec
// CALLS:
//   fffffff0094c519c FUN_fffffff0094c519c

ulong FUN_fffffff0094c8220(ulong *param_1,undefined8 param_2)

{
  code *pcVar1;
  int iVar2;
  ulong uVar3;
  
  uVar3 = *param_1;
  do {
    if (uVar3 == 0) {
      return 0;
    }
    if (*(long *)(uVar3 + 0xc0) != 0) {
      if ((uVar3 + 0x130 < uVar3) || (uVar3 + 200 < uVar3 + 0xb8)) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x5519,0xfffffff0094c828c);
        (*pcVar1)();
      }
      iVar2 = FUN_fffffff0094c519c(param_2);
      if (iVar2 == 0) {
        return uVar3;
      }
    }
    uVar3 = *(ulong *)(uVar3 + 0x110);
  } while( true );
}

