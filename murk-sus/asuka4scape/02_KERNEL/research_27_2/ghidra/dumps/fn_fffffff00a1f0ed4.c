// FUN_fffffff00a1f0ed4 @ fffffff00a1f0ed4 size=396
// CALLERS:
//   fffffff00afb8292 no-fn
//   fffffff00a1e82b0 FUN_fffffff00a1e7754@fffffff00a1e7754
// CALLEES:
//   fffffff00a1ec7a8 FUN_fffffff00a1ec7a8
//   fffffff00a29bafc FUN_fffffff00a29bafc
//   fffffff00aa4cc7c FUN_fffffff00aa4cc7c

undefined8
FUN_fffffff00a1f0ed4(long param_1,undefined8 param_2,uint param_3,uint param_4,uint param_5)

{
  ulong uVar1;
  ulong uVar2;
  code *pcVar3;
  long lVar4;
  uint uVar5;
  ulong *puVar6;
  ulong uVar7;
  
  if (param_3 == 0) {
    return 0;
  }
  if ((*(byte *)(param_1 + 1) & 7) == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff00aa4cc7c();
  }
  uVar7 = *(ulong *)(param_1 + 0x68);
  if ((uVar7 == 0) || (uVar7 == 0)) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0xbffc,0xfffffff00a1f105c);
    (*pcVar3)();
  }
  uVar1 = uVar7 & 0xffffffffffffc000 | 0x4000000000;
  uVar2 = (uVar7 & 0x3fff) << 0xe;
  if ((uVar7 & 0x4000000000) != 0) {
    uVar1 = uVar7 & 0xffffffffffffffe0;
    uVar2 = (uVar7 & 0x10 | 0x20) << (uVar7 & 0xf);
  }
  if ((ulong)param_3 * 0x10 + 0x10 <= uVar2) {
    puVar6 = (ulong *)(uVar1 + (ulong)param_3 * 0x10);
    if (((uVar1 ^ (ulong)puVar6) & 0xffc0000000000000) != 0) {
      puVar6 = (ulong *)((ulong)puVar6 & 0xffffffffffff | 0xc8a2000000000000);
    }
    if (puVar6 != (ulong *)0x0) {
      if (((uint)*puVar6 >> 1 & 1) == 0) {
        return 0;
      }
      *puVar6 = *puVar6 | 1;
      *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 0x40;
      if ((param_4 >> 5 & 1) != 0) {
        if (((param_5 ^ 0xffffffff) & 0xff) == 0) {
          if ((((param_5 & 0x22000000) != 0) || ((param_5 & 0x3f00) == 0)) ||
             (uVar5 = param_5 >> 8, (uVar5 & 0x3f) == 0)) goto LAB_fffffff00a1f0fe8;
          uVar5 = (uVar5 & 0x2a) >> 1 | (uVar5 & 0x15) << 1;
          uVar5 = (int)LZCOUNT(((uVar5 & 0x33333333) >> 2 |
                               ((uVar5 & 0xcccccccc) >> 2 | (uVar5 & 0x3030303) << 2) << 4) << 0x18)
                  + 1;
        }
        else {
          uVar5 = param_5 >> 0x14 & 0xf;
          if (uVar5 - 7 < 0xfffffffa) goto LAB_fffffff00a1f0fe8;
        }
        FUN_fffffff00a1ec7a8((long *)(param_1 + 0x28),uVar5);
      }
LAB_fffffff00a1f0fe8:
      if (((param_4 >> 0x12 & 1) != 0) || ((*(uint *)(param_1 + 0x10) & 0x180) != 0x100)) {
        return 0;
      }
      if ((param_4 >> 0x13 & 1) == 0) {
        lVar4 = tpidr_el1;
        lVar4 = FUN_fffffff00a29bafc(lVar4);
        lVar4 = *(long *)(lVar4 + 0x470);
        if (lVar4 == 0) {
          return 0;
        }
        if ((*(uint *)(lVar4 + 0x7c) >> 2 & 1) == 0) {
          if ((*(uint *)(lVar4 + 0x7c) & 1) == 0) {
            return 0;
          }
          if (*(int *)(lVar4 + 0x70) == 0) {
            return 0;
          }
        }
      }
      return 1;
    }
  }
                    /* WARNING: Does not return */
  pcVar3 = (code *)SoftwareBreakpoint(0xbffc,0xfffffff00a1f1050);
  (*pcVar3)();
}

