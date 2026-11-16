// FUN_fffffff00a1f1120 @ fffffff00a1f1120 size=236
// CALLERS:
//   fffffff00afb8296 no-fn
//   fffffff00a1f8180 FUN_fffffff00a1f80b8@fffffff00a1f80b8
//   fffffff00a215e50 FUN_fffffff00a215dbc@fffffff00a215dbc
//   fffffff00a1f83b4 FUN_fffffff00a1f82d0@fffffff00a1f82d0
//   fffffff00a1f876c FUN_fffffff00a1f8614@fffffff00a1f8614
//   fffffff00a1f89f8 FUN_fffffff00a1f8614@fffffff00a1f8614
//   fffffff00a1f9f38 FUN_fffffff00a1f9b10@fffffff00a1f9b10
//   fffffff00a1f9fac FUN_fffffff00a1f9b10@fffffff00a1f9b10
//   fffffff00a1fa0c8 FUN_fffffff00a1f9b10@fffffff00a1f9b10
//   fffffff00a1f7b2c FUN_fffffff00a1f79e8@fffffff00a1f79e8
//   fffffff00a1f8e20 FUN_fffffff00a202714@fffffff00a202714
//   fffffff00a1f8ff8 FUN_fffffff00a202714@fffffff00a202714
//   fffffff00a1f9194 FUN_fffffff00a202714@fffffff00a202714
//   fffffff00a1f963c FUN_fffffff00a1f9400@fffffff00a1f9400
// CALLEES:
//   fffffff00aa4cc7c FUN_fffffff00aa4cc7c

ulong FUN_fffffff00a1f1120(long param_1,undefined8 param_2,uint param_3)

{
  undefined8 *puVar1;
  ulong uVar2;
  code *pcVar3;
  ulong *puVar4;
  ulong uVar5;
  
  if ((*(byte *)(param_1 + 1) & 7) == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff00aa4cc7c();
  }
  uVar5 = *(ulong *)(param_1 + 0x68);
  if ((uVar5 != 0) && (uVar5 != 0)) {
    puVar1 = (undefined8 *)(uVar5 & 0xffffffffffffc000 | 0x4000000000);
    uVar2 = (uVar5 & 0x3fff) << 0xe;
    if ((uVar5 & 0x4000000000) != 0) {
      puVar1 = (undefined8 *)(uVar5 & 0xffffffffffffffe0);
      uVar2 = (uVar5 & 0x10 | 0x20) << (uVar5 & 0xf);
    }
    if ((ulong)param_3 * 0x10 + 0x10 <= uVar2) {
      puVar4 = puVar1 + (ulong)param_3 * 2;
      if ((((ulong)puVar1 ^ (ulong)puVar4) & 0xffc0000000000000) != 0) {
        puVar4 = (ulong *)((ulong)puVar4 & 0xffffffffffff | 0xc8a2000000000000);
      }
      if (puVar4 != (ulong *)0x0) {
        uVar5 = *puVar4;
        *(undefined4 *)(puVar4 + 1) = *(undefined4 *)(puVar1 + 1);
        *puVar4 = 0;
        if ((ulong *)*puVar1 == puVar4) {
          *puVar1 = 0;
        }
        *(uint *)(puVar1 + 1) = param_3;
        return uVar5 & 0xfffffffffffffffc;
      }
    }
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0xbffc,0xfffffff00a1f11f0);
    (*pcVar3)();
  }
                    /* WARNING: Does not return */
  pcVar3 = (code *)SoftwareBreakpoint(0xbffc,0xfffffff00a1f11fc);
  (*pcVar3)();
}

