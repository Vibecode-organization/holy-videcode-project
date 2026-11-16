// FUN_fffffff0094c82cc @ fffffff0094c82cc size=504
// CALLERS:
//   fffffff00afb80cc ?
//   fffffff0094c2818 FUN_fffffff0094c264c@fffffff0094c264c
//   fffffff0094c8634 FUN_fffffff0094c862c@fffffff0094c862c
// CALLS:
//   fffffff0094c519c FUN_fffffff0094c519c
//   fffffff0094c8220 FUN_fffffff0094c8220
//   fffffff0094c8580 FUN_fffffff0094c8580
//   fffffff0094c84c4 FUN_fffffff0094c84c4

ulong FUN_fffffff0094c82cc(ulong param_1,ulong *param_2,ulong *param_3,int param_4)

{
  ulong *puVar1;
  ulong uVar2;
  uint uVar3;
  code *pcVar4;
  int iVar5;
  ulong uVar6;
  ulong uVar7;
  ulong uVar8;
  ulong *puVar9;
  long lVar10;
  
  if (param_1 == 0) {
    return 0x5000b;
  }
  puVar1 = param_3 + 1;
  if (param_3 <= puVar1) {
    *(undefined8 *)(param_1 + 0x120) = 0;
    if (param_1 + 0x120 <= param_1 + 0x128) {
      uVar6 = param_1 + 0x130;
      *param_3 = param_1;
      param_3[1] = param_1 + 0x120;
      lVar10 = 1;
      *(ulong **)(param_1 + 0x128) = param_3;
      while (uVar8 = param_1 + 0x78,
            (param_1 + 0x130 <= uVar6 && param_1 <= param_1 + 0x130) && uVar8 <= param_1 + 0x88) {
        uVar6 = FUN_fffffff0094c519c(uVar8,param_1 + 0x68);
        if ((int)uVar6 == 0) {
          return uVar6;
        }
        uVar2 = param_1 + 0xa8;
        if (*(long *)(param_1 + 0xb0) == 0) {
LAB_fffffff0094c83b4:
          uVar7 = *param_2;
          while( true ) {
            if (uVar7 == 0) {
              if (uVar2 <= param_1 + 0xb8) {
                lVar10 = FUN_fffffff0094c84c4(uVar2,1);
                if (lVar10 != 0) {
                  return 0;
                }
                lVar10 = FUN_fffffff0094c8580(uVar2);
                uVar3 = 0;
                if (param_4 == 0) {
                  uVar3 = 0x80008;
                }
                if (lVar10 != 0) {
                  uVar3 = 0;
                }
                return (ulong)uVar3;
              }
              goto LAB_fffffff0094c84c0;
            }
            uVar6 = uVar7 + 0x130;
            if ((uVar6 < uVar7) || (uVar7 + 0x78 < uVar7 + 0x68)) goto LAB_fffffff0094c84c0;
            iVar5 = FUN_fffffff0094c519c(uVar8);
            if (iVar5 == 0) break;
            uVar7 = *(ulong *)(uVar7 + 0x110);
          }
        }
        else {
          if (param_1 + 0xb8 < uVar2) break;
          uVar7 = FUN_fffffff0094c8220(param_2,uVar2);
          if (uVar7 == 0) goto LAB_fffffff0094c83b4;
          uVar6 = uVar7 + 0x130;
          if ((uVar6 < uVar7) || (uVar7 + 0x78 < uVar7 + 0x68)) break;
          iVar5 = FUN_fffffff0094c519c(uVar7 + 0x68,uVar8);
          if (iVar5 != 0) goto LAB_fffffff0094c83b4;
        }
        param_1 = uVar7;
        for (uVar8 = *param_3; uVar8 != 0; uVar8 = *(ulong *)(uVar8 + 0x120)) {
          if (uVar8 == param_1) {
            return 0x80009;
          }
        }
        if (uVar6 < param_1 + 0x130) break;
        puVar9 = (ulong *)*puVar1;
        *(undefined8 *)(param_1 + 0x120) = 0;
        *(ulong **)(param_1 + 0x128) = puVar9;
        if (param_1 + 0x130 < param_1) break;
        *puVar9 = param_1;
        *puVar1 = param_1 + 0x120;
        lVar10 = lVar10 + 1;
        if (lVar10 == 0x10) {
          return 0x8000b;
        }
      }
    }
  }
LAB_fffffff0094c84c0:
                    /* WARNING: Does not return */
  pcVar4 = (code *)SoftwareBreakpoint(0x5519,0xfffffff0094c84c4);
  (*pcVar4)();
}

