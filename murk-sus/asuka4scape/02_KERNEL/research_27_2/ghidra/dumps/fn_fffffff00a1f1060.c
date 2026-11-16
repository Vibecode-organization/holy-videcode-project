// FUN_fffffff00a1f1060 @ fffffff00a1f1060 size=192
// CALLERS:
//   fffffff00afb8294 no-fn
//   fffffff00a1f8020 FUN_fffffff00a1f7f38@fffffff00a1f7f38
//   fffffff00a1f9854 FUN_fffffff00a1f9784@fffffff00a1f9784
//   fffffff00a1f988c FUN_fffffff00a1f9784@fffffff00a1f9784
//   fffffff00a1fee60 FUN_fffffff00a1feb98@fffffff00a1feb98
//   fffffff00a202014 FUN_fffffff00a201c58@fffffff00a201c58
//   fffffff00a202070 FUN_fffffff00a201c58@fffffff00a201c58
// CALLEES:

undefined4 FUN_fffffff00a1f1060(long param_1,undefined8 param_2,uint param_3)

{
  undefined4 uVar1;
  ulong uVar2;
  ulong uVar3;
  code *pcVar4;
  ulong *puVar5;
  undefined4 uVar6;
  ulong uVar7;
  
  uVar7 = *(ulong *)(param_1 + 0x68);
  if ((uVar7 == 0) || (uVar7 == 0)) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0xbffc,0xfffffff00a1f1120);
    (*pcVar4)();
  }
  uVar2 = uVar7 & 0xffffffffffffc000 | 0x4000000000;
  uVar3 = (uVar7 & 0x3fff) << 0xe;
  if ((uVar7 & 0x4000000000) != 0) {
    uVar2 = uVar7 & 0xffffffffffffffe0;
    uVar3 = (uVar7 & 0x10 | 0x20) << (uVar7 & 0xf);
  }
  if ((ulong)param_3 * 0x10 + 0x10 <= uVar3) {
    puVar5 = (ulong *)(uVar2 + (ulong)param_3 * 0x10);
    if (((uVar2 ^ (ulong)puVar5) & 0xffc0000000000000) != 0) {
      puVar5 = (ulong *)((ulong)puVar5 & 0xffffffffffff | 0xc8a2000000000000);
    }
    if (puVar5 != (ulong *)0x0) {
      uVar7 = *puVar5;
      uVar6 = 0xe0000000;
      if ((uVar7 & 1) != 0) {
        uVar6 = 0xc0000000;
      }
      uVar1 = 0x80000000;
      if ((uVar7 & 2) != 0) {
        uVar1 = uVar6;
      }
      uVar6 = 0;
      if (3 < uVar7) {
        uVar6 = uVar1;
      }
      return uVar6;
    }
  }
                    /* WARNING: Does not return */
  pcVar4 = (code *)SoftwareBreakpoint(0xbffc,0xfffffff00a1f1114);
  (*pcVar4)();
}

