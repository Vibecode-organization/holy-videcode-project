// FUN_fffffff00994cca8 @ fffffff00994cca8 size=128

void FUN_fffffff00994cca8(long param_1,long param_2)

{
  code *pcVar1;
  ulong uVar2;
  long lVar3;
  long lVar4;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000038ff214(*(undefined8 *)(param_1 + 0x840));
  uVar2 = (ulong)*(uint *)(param_1 + 0x28);
  if (0 < (int)*(uint *)(param_1 + 0x28)) {
    lVar3 = 0;
    do {
      lVar4 = lVar3 * 0x18 + 8;
      if (*(long *)(param_1 + 0x848 + lVar4) == param_2) {
        *(undefined8 *)(param_1 + 0x848 + lVar4) = 0;
      }
      lVar3 = lVar3 + 1;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00994cd24);
    (*pcVar1)();
  }
  thunk_EXT_FUN_80110000038ff2e0(*(undefined8 *)(param_1 + 0x840));
  return;
}

