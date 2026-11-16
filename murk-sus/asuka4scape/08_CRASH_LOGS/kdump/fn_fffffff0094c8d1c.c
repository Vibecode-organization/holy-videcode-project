// FUN_fffffff0094c8d1c @ fffffff0094c8d1c size=540
// CALLERS:
//   fffffff00afb80d7 ?
//   fffffff0094c87bc FUN_fffffff0094c8638@fffffff0094c8638
// CALLS:
//   fffffff0094c519c FUN_fffffff0094c519c
//   fffffff0094c8f38 FUN_fffffff0094c8f38

void FUN_fffffff0094c8d1c(long param_1,long param_2)

{
  code *pcVar1;
  int iVar2;
  ulong uVar3;
  undefined8 *puVar4;
  long lVar5;
  
  if (param_1 == 0) {
    return;
  }
  if (((*(byte *)(param_1 + 0x10) & 1) != 0) && (uVar3 = (ulong)DAT_fffffff0077705c9, uVar3 != 0)) {
    if (param_2 + 0x68U < param_2 + 0x58U) goto LAB_fffffff0094c8f34;
    puVar4 = &DAT_fffffff007f5abb0;
    do {
      if ((puVar4 < &DAT_fffffff007f5abb0 || &UNK_fffffff007f5acf0 < puVar4 + 1) ||
          puVar4 + 1 < puVar4) goto LAB_fffffff0094c8f34;
      iVar2 = FUN_fffffff0094c519c(param_2 + 0x58U,*puVar4);
      if (iVar2 == 0) {
        *(ulong *)(param_2 + 0xf0) = *(ulong *)(param_2 + 0xf0) | DAT_fffffff0077688e8;
        break;
      }
      uVar3 = uVar3 - 1;
      puVar4 = puVar4 + 1;
    } while (uVar3 != 0);
  }
  if (((uint)*(ulong *)(param_1 + 8) >> 0x18 & 1) == 0) {
    if ((*(ulong *)(param_1 + 8) & 0x1c00000000) != 0) {
      if (param_2 + 0x68U < param_2 + 0x58U) goto LAB_fffffff0094c8f34;
      iVar2 = FUN_fffffff0094c519c(param_2 + 0x58U,&DAT_fffffff007f5b478);
      if (iVar2 != 0) goto LAB_fffffff0094c8e20;
      uVar3 = *(ulong *)(param_2 + 0xf0) | 0x1c00000000;
LAB_fffffff0094c8e40:
      *(ulong *)(param_2 + 0xf0) = uVar3;
    }
  }
  else {
    if (param_2 + 0x68U < param_2 + 0x58U) goto LAB_fffffff0094c8f34;
    iVar2 = FUN_fffffff0094c519c(param_2 + 0x58U,&DAT_fffffff007f5b458);
    if (iVar2 == 0) {
      uVar3 = *(ulong *)(param_2 + 0xf0) | 0x1000000;
      goto LAB_fffffff0094c8e40;
    }
LAB_fffffff0094c8e20:
    if ((*(byte *)(param_1 + 0x11) & 1) != 0) {
      FUN_fffffff0094c8f38(param_1,param_2);
    }
  }
  if (((*(byte *)(param_1 + 0x10) & 1) != 0) && ((*(byte *)(param_1 + 0x11) & 1) != 0)) {
    if (DAT_fffffff0077705c9 < DAT_fffffff0077705ca) {
      if (param_2 + 0x68U < param_2 + 0x58U) goto LAB_fffffff0094c8f34;
      lVar5 = (ulong)DAT_fffffff0077705ca - (ulong)DAT_fffffff0077705c9;
      puVar4 = &DAT_fffffff007f5abb0 + DAT_fffffff0077705c9;
      do {
        if ((puVar4 < &DAT_fffffff007f5abb0 || &UNK_fffffff007f5acf0 < puVar4 + 1) ||
            puVar4 + 1 < puVar4) goto LAB_fffffff0094c8f34;
        iVar2 = FUN_fffffff0094c519c(param_2 + 0x58U,*puVar4);
        if (iVar2 == 0) {
          *(ulong *)(param_2 + 0xf0) = *(ulong *)(param_2 + 0xf0) | DAT_fffffff0077688e8;
          break;
        }
        lVar5 = lVar5 + -1;
        puVar4 = puVar4 + 1;
      } while (lVar5 != 0);
    }
  }
  if (((*(byte *)(param_1 + 0x10) & 1) != 0) && ((*(byte *)(param_1 + 0x11) & 1) != 0)) {
    if (param_2 + 0x68U < param_2 + 0x58U) {
LAB_fffffff0094c8f34:
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x5519,0xfffffff0094c8f38);
      (*pcVar1)();
    }
    iVar2 = FUN_fffffff0094c519c(param_2 + 0x58U,&DAT_fffffff007f59530);
    if (iVar2 == 0) {
      *(ulong *)(param_2 + 0xf0) = *(ulong *)(param_2 + 0xf0) | 0x6400000;
    }
  }
  return;
}

