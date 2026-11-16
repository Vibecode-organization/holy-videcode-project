// FUN_fffffff008898de8 @ fffffff008898de8 size=4 depth=0
// CALLERS:
//   fffffff00afca911 ?
//   fffffff007d966d8 ?
// CALLS:

undefined8 FUN_fffffff008898de8(long param_1,undefined8 param_2,long param_3)

{
  code *pcVar1;
  undefined8 uVar2;
  char *pcVar3;
  ulong unaff_x30;
  
  if ((param_1 == 0) || (param_3 == 0)) {
    if (DAT_fffffff00ae3add0 == 0) {
      return 0xe00002c2;
    }
    pcVar3 = "TouchEEPROMDriver::%s: Null pointer: target = %p reference = %p arguments = %p\n";
  }
  else {
    if (*(int *)(param_3 + 0x28) == 1) {
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
        uVar2 = FUN_fffffff008899c0c(param_1,0,(ulong)**(byte **)(param_3 + 0x20),param_3);
        return uVar2;
      }
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff008898e40);
      (*pcVar1)();
    }
    if (DAT_fffffff00ae3add0 == 0) {
      return 0xe00002c2;
    }
    pcVar3 = "TouchEEPROMDriver::%s: Bad input count: %u\n\n";
  }
  thunk_FUN_fffffff00a9029a0((byte *)pcVar3);
  return 0xe00002c2;
}

