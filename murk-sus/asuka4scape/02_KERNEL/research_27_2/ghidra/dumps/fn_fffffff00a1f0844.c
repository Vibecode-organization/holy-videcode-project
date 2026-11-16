// FUN_fffffff00a1f0844 @ fffffff00a1f0844 size=288
// CALLERS:
//   fffffff00afb828e no-fn
//   fffffff00a215b24 FUN_fffffff00a215a5c@fffffff00a215a5c
// CALLEES:
//   fffffff00aa4cc7c FUN_fffffff00aa4cc7c

undefined8 FUN_fffffff00a1f0844(long param_1,long param_2,uint *param_3)

{
  ulong *puVar1;
  uint uVar2;
  ulong uVar3;
  code *pcVar4;
  ulong *puVar5;
  ulong uVar6;
  
  if ((*(byte *)(param_1 + 1) & 7) == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff00aa4cc7c();
  }
  uVar6 = *(ulong *)(param_1 + 0x68);
  if ((uVar6 != 0) && (uVar6 != 0)) {
    puVar1 = (ulong *)(uVar6 & 0xffffffffffffc000 | 0x4000000000);
    uVar3 = (uVar6 & 0x3fff) << 0xe;
    if ((uVar6 & 0x4000000000) != 0) {
      puVar1 = (ulong *)(uVar6 & 0xffffffffffffffe0);
      uVar3 = (uVar6 & 0x10 | 0x20) << (uVar6 & 0xf);
    }
    if ((*puVar1 != 0) && (*puVar1 != 0)) {
      return 0x14;
    }
    uVar2 = (uint)puVar1[1];
    if (uVar2 != 0) {
      if ((ulong)uVar2 * 0x10 + 0x10 <= uVar3) {
        puVar5 = puVar1 + (ulong)uVar2 * 2;
        if ((((ulong)puVar1 ^ (ulong)puVar5) & 0xffc0000000000000) != 0) {
          puVar5 = (ulong *)((ulong)puVar5 & 0xffffffffffff | 0xc8a2000000000000);
        }
        if (puVar5 != (ulong *)0x0) {
          *puVar1 = (ulong)puVar5;
          *(int *)(puVar1 + 1) = (int)puVar5[1];
          if (param_2 == 0) {
            param_2 = 0;
          }
          *puVar5 = param_2;
          *(undefined4 *)(puVar5 + 1) = 0xfffffffe;
          *param_3 = uVar2;
          return 0;
        }
      }
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0xbffc,0xfffffff00a1f0954);
      (*pcVar4)();
    }
  }
  return 3;
}

