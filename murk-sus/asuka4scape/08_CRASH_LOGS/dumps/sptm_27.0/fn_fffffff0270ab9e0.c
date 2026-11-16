// FUN_fffffff0270ab9e0 @ fffffff0270ab9e0 size=620
// CALLERS:
//   fffffff02701c1f0 ?

ulong FUN_fffffff0270ab9e0(byte param_1,undefined8 param_2)

{
  code *pcVar1;
  ulong uVar2;
  char *pcVar3;
  ulong uVar4;
  long lVar5;
  ulong *puVar6;
  ulong uVar7;
  
  if (9 < param_1) {
    pcVar3 = "%s(%s:%d) - %s(%#llx)\n";
    goto LAB_fffffff0270abbf8;
  }
  if (9 < param_1) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(1,0xfffffff0270abc4c);
    (*pcVar1)();
  }
  uVar2 = 0x1000000000;
  switch(param_1) {
  default:
    uVar2 = *(ulong *)(DAT_fffffff0270921b8 + 0x10);
    break;
  case 1:
    if (*(long *)(DAT_fffffff0270921b8 + 0x10) == 0) {
LAB_fffffff0270abb30:
      uVar2 = FUN_fffffff0270d2f50(*(undefined8 *)(DAT_fffffff0270921b8 + 0x18));
      return uVar2;
    }
    goto LAB_fffffff0270abc24;
  case 2:
    if (*(long *)(DAT_fffffff0270921b8 + 0x10) == 1) goto LAB_fffffff0270abb30;
LAB_fffffff0270abc24:
    pcVar3 = "%s(%s:%d) - %s(%#llx), %s(%#llx)\n";
LAB_fffffff0270abbf8:
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f353c(0x400001b,param_2,pcVar3);
  case 3:
    uVar2 = (ulong)*(byte *)(DAT_fffffff0270921b8 + 0x1a1);
    break;
  case 4:
    uVar2 = *(ulong *)(DAT_fffffff0270921b8 + 0x1a8);
    break;
  case 5:
    uVar2 = *(ulong *)(DAT_fffffff0270921b8 + 0x1b0);
    break;
  case 6:
    break;
  case 7:
    uVar2 = 0x7000000000;
    break;
  case 8:
    uVar2 = *(ulong *)(DAT_fffffff0270921b8 + 0x1c0);
    break;
  case 9:
    uVar2 = *(ulong *)(DAT_fffffff0270921b8 + 0x108);
    if (((uint)DAT_fffffff027102040 >> 8 & 1) != 0) {
      uVar4 = (ulong)DAT_fffffff0270fd9f8;
      if (DAT_fffffff0270fd9f8 != 0) {
        lVar5 = 0;
        do {
          puVar6 = &DAT_fffffff0270fda00 + lVar5 * 3;
          if ((((ulong)puVar6 ^ 0xfffffff0270fda00) & 0xffc0000000000000) != 0) {
            puVar6 = (ulong *)((ulong)puVar6 & 0xffffffffffff | 0xc8a2000000000000);
          }
          uVar7 = *puVar6;
          if ((uVar7 <= uVar2) && (uVar2 < uVar7 + (ulong)(uint)puVar6[2] * 0x4000)) {
            return (uVar2 - uVar7) + puVar6[1];
          }
          lVar5 = lVar5 + 1;
          uVar4 = uVar4 - 1;
        } while (uVar4 != 0);
      }
      uVar2 = FUN_fffffff0270debdc();
      return uVar2;
    }
    uVar2 = (uVar2 - DAT_fffffff0270921c8) + DAT_fffffff027090ff0;
  }
  return uVar2;
}

