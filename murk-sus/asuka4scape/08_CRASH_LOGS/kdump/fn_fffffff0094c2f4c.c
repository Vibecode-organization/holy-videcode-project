// FUN_fffffff0094c2f4c @ fffffff0094c2f4c size=124
// CALLERS:
//   fffffff00afb8062 ?
//   fffffff0094c6f8c FUN_fffffff0094c6eac@fffffff0094c6eac
//   fffffff0094c741c FUN_fffffff0094c7388@fffffff0094c7388
// CALLS:
//   fffffff0094c519c FUN_fffffff0094c519c

bool FUN_fffffff0094c2f4c(undefined8 param_1)

{
  byte bVar1;
  byte bVar2;
  code *pcVar3;
  int iVar4;
  long lVar5;
  
  bVar2 = 0;
  lVar5 = 0;
  do {
    if (&UNK_fffffff007f5ae48 + lVar5 * 0x20 < &DAT_fffffff007f5ae38 + lVar5 * 0x20) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x5519,0xfffffff0094c2fc8);
      (*pcVar3)();
    }
    iVar4 = FUN_fffffff0094c519c(&DAT_fffffff007f5ae38 + lVar5 * 0x20,param_1);
    lVar5 = 1;
    bVar1 = bVar2 ^ 1;
    bVar2 = 1;
  } while ((bool)(iVar4 != 0 & bVar1));
  return iVar4 == 0;
}

